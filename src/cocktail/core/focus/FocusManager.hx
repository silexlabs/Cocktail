/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.focus;

import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.html.HTMLBodyElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.event.MouseEvent;
import cocktail.core.Keyboard;
import cocktail.core.mouse.MouseData;
import cocktail.core.dom.DOMData;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.dom.DOMData;

/**
 * The Focus Manager determine which HTMLElements in 
 * the Document can receive focus and manage
 * sequential focus navigation which is triggered
 * in most cases by pressing the TAB key on a keyboard
 * 
 * @author Yannick DOMINGUEZ
 */
class FocusManager
{	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	
	/**
	 * determine the next
	 * HTMLElement in the tabList array which
	 * must be focused
	 * 
	 * @param	reverse if true,
	 * focus the previous focusable HTMLElement in
	 * the tabList array
	 * @param rootElement the root element of the Document, 
	 * in an HTMLDocument, it is the HTMLBodyElement
	 * @param activeElement the element which currently
	 * has focus
	 */
	public function getNextFocusedElement(reverse:Bool, rootElement:HTMLElement, activeElement:HTMLElement):HTMLElement
	{
		//build the list of focusable elements
		var tabList:Array<HTMLElement> = buildTabList(rootElement);
		
		//will hold the index of the currently focused
		//element and will be incremented/decremented to 
		//match the index of the next focused element
		var tabListIndex:Int;
		
		//if the currently activeHTMLElement is the body, it means
		//no HTMLElement is actually focused and there is no need
		//to increment/decrement
		if (activeElement == rootElement)
		{
			//init the index to 0 or the index of the last focusable
			//element if the focus is in reverse order
			if (reverse == false)
			{
				tabListIndex = 0;
			}
			else
			{
				tabListIndex = tabList.length - 1;
			}
		}
		//if any other element than the body has currently the focus
		else
		{
			//retrive the index of the activeElement
			tabListIndex = getElementTabListIndex(activeElement, tabList);
			
			//then increment or decrement its index to find the index of 
			//the next focusable element
			if (reverse == false)
			{
				tabListIndex++;
			}
			else
			{
				tabListIndex--;
			}
		}
		
		//if the incremented tab list index is greater than the 
		//elements in the tab list, it means a full loop has been done
		//and the focus is set back to the first focusable element in the list
		if (tabListIndex == tabList.length)
		{
			tabListIndex = 0;
		}
		//same for the decremented tab list index
		else if (tabListIndex == -1)
		{
			tabListIndex = tabList.length - 1;
		}
		
		//return the element add the new tab list index
		return tabList[tabListIndex];
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	/**
	 * Return the index of an element in the 
	 * tabList array
	 */
	private function getElementTabListIndex(element:HTMLElement, tabList:Array<HTMLElement>):Int
	{
		for (i in 0...tabList.length)
		{
			if (tabList[i] == element)
			{
				return i;
			}
		}
		//TODO : throw exception ?
		return -1;
	}
	
	/**
	 * Traverse all the DOM once to build a flat list of all the focusable
	 * HTMLElements in the DOM.
	 * 
	 * The list is first composed of all the focusable HTMLElement with a tabIndex
	 * superior to 0, ordered form smaller to bigger, then the list contains all the
	 * focusable HTMLElement with a tabIndex of 0, ordered in DOM order starting from
	 * the HTMLBodyElement
	 */
	private function buildTabList(rootElement:HTMLElement):Array<HTMLElement>
	{		
		//contains the HTMLElement with a 0 tabIndex
		var orderedTabList:Array<HTMLElement> = new Array<HTMLElement>();
		
		//contains the HTMLElement with a tabIndex > 0
		var indexedTabList:Array<HTMLElement> = new Array<HTMLElement>();
		
		//build the list
		doBuildTabList(rootElement, orderedTabList, indexedTabList);
		
		//concatenate the 2 arrays
		for (i in 0...orderedTabList.length)
		{
			indexedTabList.push(orderedTabList[i]);
		}
		
		return indexedTabList;
	}
	
	/**
	 * Recursive method traversing all the DOM and filling
	 * the reference to the arrays which must contain
	 * the ordered focusable HTMLElements
	 */
	private function doBuildTabList(htmlElement:HTMLElement, orderedTabList:Array<HTMLElement>, indexedTabList:Array<HTMLElement>):Void
	{
		//loop in all children
		for (i in 0...htmlElement.childNodes.length)
		{
			//only element node can be focused
			if (htmlElement.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var child:HTMLElement = cast(htmlElement.childNodes[i]);
				
				//if the child also has children, call the doBuildTabList
				//recursively
				if (child.hasChildNodes() == true)
				{
					doBuildTabList(child, orderedTabList, indexedTabList);
				}
				
				//check if the child can be focused
				if (child.isFocusable() == true)
				{
					//if it can and has a 0 tabIndex or no defined tabIndex, push it
					//the DOM order array
					//TODO : should tabIndex be null Int ?
					if (child.tabIndex == 0 || child.tabIndex == null)
					{
						orderedTabList.push(child);
					}
					//else if it has a defined tabIndex
					else if (child.tabIndex > 0)
					{
						//find where to insert it in the 
						//indexed HTMLElement array which is
						//ordered starting from the HTMLElement
						//with the smallest tabIndex to the
						//biggest
						if (indexedTabList.length == 0)
						{
							indexedTabList.push(child);
						}
						else
						{
							var foundSpotFlag:Bool = false;
							for (j in 0...indexedTabList.length)
							{
								if (child.tabIndex < indexedTabList[j].tabIndex)
								{
									indexedTabList.insert(j, child);
									foundSpotFlag = true;
								}
							}
							//push to the end of the array if it has a biggest
							//tabIndex than all the other HTMLElements in the
							//array
							if (foundSpotFlag == false)
							{
								indexedTabList.push(child);
							}
						}
					}
				}
			}
		}
	}
}