/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.focus;

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
 * The abstract implementation of the focus
 * manager. Listens for TAB and ENTER/SPACE
 * event on keyboard to either switch the 
 * focused HTMLElement or trigger a simulated
 * click event on it
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractFocusManagerImpl 
{
	/**
	 * set/get the reference to the BodyHTMLElement use as 
	 * starting point when traversing the DOM looking 
	 * for focusable HTMLElements
	 */
	private var _bodyElement:HTMLBodyElement;
	public var bodyElement(getBodyElement, setBodyElement):HTMLBodyElement;
	
	/**
	 * set/get the currently focused HTMLElement
	 * 
	 * TODO : move to Document
	 */
	private var _activeElement:HTMLElement;
	public var activeElement(getActiveElement, setActiveElement):HTMLElement;
	
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
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor. Starts listening to global
	 * keyboard events
	 */
	public function new() 
	{
		initKeyboardListeners();
	}
	
	/**
	 * init keyboard listeners
	 */
	private function initKeyboardListeners():Void
	{
		//TODO : should be initialised with Document or Body
		
		//listens for event on the root of the runtime
	//	var keyboard:Keyboard = new Keyboard(NativeElementManager.getRoot());
	//	keyboard.onKeyDown = onKeyDown;
	//	keyboard.onKeyUp = onKeyUp;
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
	 * When a key is pressed, detect if a tab
	 * focus or a simulated click must happen.
	 * 
	 * If it is any other key, redirect the 
	 * key down event to the currently active
	 * HTMLElement
	 */
	private function onKeyDown(keyboardEvent:KeyboardEvent):Void
	{
		//TODO : re-implement
		/**
		switch (keyboardEvent.key)
		{
			case AbstractKeyboard.TAB:
				doTabFocus(keyEventData.shiftKey);
				
			case AbstractKeyboard.ENTER, AbstractKeyboard.SPACE:
				simulateMouseClick(keyEventData);
				
			default:
				if (activeHTMLElement.onKeyDown != null)
				{
					activeHTMLElement.onKeyDown(keyEventData);
				}
		}*/
	}
	
	/**
	 * When a key up event happens, redirect to the
	 * currently active HTMLElement
	 */
	private function onKeyUp(keyEventData:KeyboardEvent):Void
	{
		if (_activeElement.onkeyup != null)
		{
			_activeElement.onkeyup(keyEventData);
		}
	}
	
	/**
	 * When TAB is pressed, determine the next
	 * HTMLElement in the _tabList array which
	 * must be focused
	 * 
	 * @param	reverse when Shift is also pressed,
	 * focus the previous focusable HTMLElement in
	 * the _tabList array
	 */
	private function doTabFocus(reverse:Bool):Void
	{
		//build the tab list if it the first
		//tab focus or if it was invalidated
		if (_tabList == null)
		{
			_tabList = buildTabList(_bodyElement);
		}
		
		//search the next valid index for the tab list
		//by incrementing or decrementing the tab list index.
		//As the tab focus loop, the tab list index might be reseted
		//or set to the last element
		if (activeElement != _bodyElement)
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
		activeElement = _tabList[_tabListIndex];
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
	private function buildTabList(htmlElement:HTMLElement):Array<HTMLElement>
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
		doBuildTabList(htmlElement, orderedTabList, indexedTabList);
		
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
		//TODO : re implement
		
		/**
		//loop in all children
		for (i in 0...htmlElement.childNodes.length)
		{
			if (htmlElement.childNodes[i].nodeType == NodeType.ELEMENT_NODE)
			{
				var child:HTMLElement = htmlElement.childNodes[i];
				
				//if the child is also a ContainerHTMLElement, call the doBuildTabList
				//recursively
				if (Std.is(child, ContainerHTMLElement) == true)
				{
					var containerChild:ContainerHTMLElement = cast(child);
					doBuildTabList(containerChild, orderedTabList, indexedTabList);
				}
				//check if the child can be focused
				if (child.tabEnabled == true)
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
		*/
	}
	
	/**
	 * When a simulated mouse click must happen on the 
	 * active HTMLElement, create all the necessary
	 * element such as a fake mouse position, and
	 * cal the active HTMLElement's mouse down callback
	 * if it exists
	 */
	private function simulateMouseClick(keyEventData:KeyboardEvent):Void
	{
		if (activeElement.onmousedown != null)
		{
			//TODO : replace mouse click event + add right coordinate
			var mouseEvent:MouseEvent = new MouseEvent(MouseEvent.MOUSE_DOWN, _activeElement, 0.0,
			0.0, 0.0, 0.0, 0.0, false, false, false);
			
			activeElement.onmousedown(mouseEvent);
		}
	
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	/////////////////////////////////
	
	/**
	 * When a new activeHTMLElement is set, call 
	 * the focus out (blur) method on the previous
	 * one and then call the focus in on the 
	 * new one
	 */
	private function setActiveElement(value:HTMLElement):HTMLElement
	{
		//only call if there is a previous activeHTMLElement
		if (_activeElement != null)
		{
			if (_activeElement.onblur != null)
			{
				_activeElement.onblur(new Event(Event.BLUR, _activeElement));
			}
		}
		
		//if the activeHTMLElement is set to null, it defaults
		//to the BodyHTMLElement
		if (value == null)
		{
			value = _bodyElement;
		}
		
		//do nothing if the new avctiveHTMLElement is the same
		//as the current one
		if (value != _activeElement)
		{
			_activeElement = value;
			if (_activeElement.onfocus != null)
			{
				_activeElement.onfocus(new Event(Event.FOCUS, _activeElement));
			}
		}
		
		return _activeElement;
	}
	
	private function getActiveElement():HTMLElement
	{
		return _activeElement;
	}
	
	/**
	 * when the bodyDOMelement is defined for the FocusManager,
	 * reset the activeHTMLElement and the tab list
	 */
	private function setBodyElement(value:HTMLBodyElement):HTMLBodyElement
	{
		_bodyElement = value;
		activeElement = null;
		
		invalidate();

		
		return _bodyElement;
	}
	
	private function getBodyElement():HTMLBodyElement
	{
		return _bodyElement;
	}
	
}