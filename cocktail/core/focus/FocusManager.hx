/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.focus;

import cocktail.core.dom.DOMConstants;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.FocusEvent;
import cocktail.core.html.HTMLBodyElement;
import cocktail.core.html.HTMLElement;

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
	 * The activeElement set/get the element
	 * in the document which is focused.
	 * If no element in the Document is focused, this returns the body element. 
	 */
	public var activeElement(default, null):HTMLElement;
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		activeElement = null;
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
			if (htmlElement.childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
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

	/////////////////////////////////
	// ACTIVE ELEMENT METHOD
	/////////////////////////////////
	
	/**
	 * When a new activeElement is set, call 
	 * the focus out (blur) method on the previous
	 * one and then call the focus in on the 
	 * new one
	 */
	public function setActiveElement(newActiveElement:HTMLElement, body:HTMLBodyElement):HTMLElement
	{			
		//if the activeHTMLElement is set to null, do nothing
		if (newActiveElement == null)
		{
			return activeElement;
		}
		
		//the first time this setter is called, the activeElement
		//is null and it is set to the body element
		if (activeElement == null)
		{
			return activeElement = newActiveElement;
		}
		
		//do nothing if the new activeHTMLElement is the same
		//as the current one
		if (newActiveElement != activeElement)
		{
			//else dispatch a serie of FocusEvent on the element losing
			//focus and on the one gaining it
			
			//dispatch pre-focus shift focus event which bubbles in the document
			
			var focusOutEvent:FocusEvent = new FocusEvent();
			focusOutEvent.initFocusEvent(EventConstants.FOCUS_OUT, true, false, null, 0.0, newActiveElement);
			activeElement.dispatchEvent(focusOutEvent);
			
			var focusInEvent:FocusEvent = new FocusEvent();
			focusInEvent.initFocusEvent(EventConstants.FOCUS_IN, true, false, null, 0.0, activeElement);
			newActiveElement.dispatchEvent(focusInEvent);
			
			//store the new active element before dispatching focus and blur event
			var oldActiveElement:HTMLElement = activeElement;
			
			//refresh the styles of the old focused element, as
			//:focus styles don't apply to it anymore
			oldActiveElement.invalidateStyleDeclaration(false);
			
			//if the new activeElement is not focusable, the focus
			//is instead given to the HTMLBodyElement
			if (newActiveElement.isFocusable() == true)
			{
				activeElement = newActiveElement;
			}
			else
			{
				activeElement = body;
			}
			
			
			//update the styles of the focus element,
			//as :focus pseudo-class styles might now apply
			//to it
			activeElement.invalidateStyleDeclaration(false);
			
			//dispatch post-focus event which don't bubbles through the document
			
			var blurEvent:FocusEvent = new FocusEvent();
			blurEvent.initFocusEvent(EventConstants.BLUR, false, false, null, 0.0, null);
			oldActiveElement.dispatchEvent(blurEvent);
			
			var focusEvent:FocusEvent = new FocusEvent();
			focusEvent.initFocusEvent(EventConstants.FOCUS, false, false, null, 0.0, null);
			newActiveElement.dispatchEvent(focusEvent);
			
			if (activeElement.onfocus != null)
			{
				var focusEvent:FocusEvent = new FocusEvent();
				focusEvent.initFocusEvent(EventConstants.FOCUS, true, false, null, 0.0, null);
				
				activeElement.onfocus(focusEvent);
			}
		}
		
		return activeElement;
	}
}
