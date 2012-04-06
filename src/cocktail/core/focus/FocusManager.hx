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
import cocktail.core.HTMLElement;
import cocktail.core.event.MouseEvent;
import cocktail.core.Keyboard;
import cocktail.core.mouse.MouseData;
import cocktail.core.dom.DOMData;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.dom.DOMData;

/**
 * The Focus Manager determine which HTMLElement in the 
 * Document has focus, meaning that it will receive keyboard
 * events. Focus can be given by clicking on a HTMLElement
 * which can receive the focus, by using the TAB key on
 * the keyboard or it can be set programatically
 * 
 * @author Yannick DOMINGUEZ
 */
class FocusManager
{
	/**
	 * Holds a list of all the focusable
	 * HTMLElements in the DOM, ordered in the
	 * right focus order
	 */
	private var _tabList:Array<HTMLElement>;
	
	/**
	 * The index of the currently active HTMLElement
	 * in the tabList
	 */
	private var _tabListIndex:Int;
	
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
	 * reset the tabList, so that it is re-build
	 * on next tab focus
	 */
	public function invalidate():Void
	{
		_tabList == null;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	/**
	 * determine the next
	 * HTMLElement in the _tabList array which
	 * must be focused
	 * 
	 * @param	reverse when Shift is also pressed,
	 * focus the previous focusable HTMLElement in
	 * the _tabList array
	 */
	public function getNextFocusedElement(reverse:Bool, rootElement:HTMLElement, activeElement:HTMLElement):HTMLElement
	{
		//build the tab list if it the first
		//tab focus or if it was invalidated
		if (_tabList == null)
		{
			_tabList = buildTabList(rootElement);
		}
		
		//search the next valid index for the tab list
		//by incrementing or decrementing the tab list index.
		//As the tab focus loop, the tab list index might be reseted
		//or set to the last element
		if (activeElement != rootElement)
		{
			if (reverse == false)
			{
				if (_tabListIndex == _tabList.length - 1)
				{
					_tabListIndex = 0;
				}
				else
				{
					_tabListIndex++;
				}
			}
			else
			{
				if (_tabListIndex == 0)
				{
					_tabListIndex = _tabList.length - 1;
				}
				else
				{
					_tabListIndex--;
				}
			}
		}
		//if the currently activeHTMLElement is the body, it means
		//no HTMLElement is actually focused and there is no need
		//to increment/decrement
		else
		{
			if (reverse == false)
			{
				_tabListIndex = 0;
			}
			else
			{
				_tabListIndex = _tabList.length - 1;
			}
		}
		
		//set the activeHTMLElement with the found tab list index
		return _tabList[_tabListIndex];
	}
	
	/**
	 * Traverse all the DOM once to build a flat list of all the focusable
	 * HTMLElements in the DOM.
	 * 
	 * The list is first composed of all the focusable HTMLElement with a tabIndex
	 * superior to 0, ordered form smaller to bigger then the list contains all the
	 * focusable HTMLElement with a tabIndex of 0, ordered in DOM order starting from
	 * the BodyHTMLElement
	 */
	private function buildTabList(rootElement:HTMLElement):Array<HTMLElement>
	{
		//each time the list is rebuild, the tab list index is
		//reseted so that the first item of the list is selected when
		//the user press tab
		_tabListIndex = 0;
		
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
				if (canReceiveFocus(child) == true)
				{
					//if it can and has a 0 tabIndex, push it
					//the DOM order array
					if (child.tabIndex == 0)
					{
						orderedTabList.push(child);
					}
					//else if it has a defined tabIndex
					else if (child.tabIndex > 0)
					{
						//find where to insert it in the 
						//indexed HTMLElement array which is
						//ordered starting from the DOMelement
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
							//tabIndex than all the other DOMelements in the
							//array
							if (foundSpotFlag == false)
							{
								indexedTabList.push(child);
							}
						}
					}
					//note : HTMLElements which are tabEnabled but with a negative
					//tabIndex can't be selected with tab focus
				}
			}
		}
		
	}
	
	private function canReceiveFocus(htmlElement:HTMLElement):Bool
	{
		var canReceiveFocus:Bool = false;
		if (htmlElement.isDefaultFocusable() == true)
		{
			canReceiveFocus = true;
		}
		else if (htmlElement.tabIndex != null)
		{
			if (htmlElement.tabIndex > 0)
			{
				canReceiveFocus = true;
			}
		}
		return canReceiveFocus;
	}
	
}