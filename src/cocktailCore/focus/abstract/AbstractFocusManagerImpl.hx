/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.focus.abstract;

import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import core.event.MouseEvent;
import cocktailCore.keyboard.abstract.AbstractKeyboard;
import cocktailCore.keyboard.Keyboard;
import cocktail.keyboard.KeyboardData;
import core.mouse.MouseData;
import cocktailCore.domElement.DOMElementData;
import cocktail.nativeElement.NativeElementManager;
import core.event.KeyboardEvent;

/**
 * The abstract implementation of the focus
 * manager. Listens for TAB and ENTER/SPACE
 * event on keyboard to either switch the 
 * focused DOMElement or trigger a simulated
 * click event on it
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractFocusManagerImpl 
{
	/**
	 * set/get the reference to the BodyDOMElement use as 
	 * starting point when traversing the DOM looking 
	 * for focusable DOMElements
	 */
	private var _bodyDOMElement:BodyDOMElement;
	public var bodyDOMElement(getBodyDOMElement, setBodyDOMElement):BodyDOMElement;
	
	/**
	 * set/get the currently focused DOMElement
	 */
	private var _activeDOMElement:DOMElement;
	public var activeDOMElement(getActiveDOMElement, setActiveDOMElement):DOMElement;
	
	/**
	 * Holds a list of all the focusable
	 * DOMElements in the DOM, ordered in the
	 * right focus order
	 */
	private var _tabList:Array<DOMElement>;
	
	/**
	 * The index of the currently active DOMElement
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
		//listens for event on the root of the runtime
		var keyboard:Keyboard = new Keyboard(NativeElementManager.getRoot());
		keyboard.onKeyDown = onKeyDown;
		keyboard.onKeyUp = onKeyUp;
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
	 * DOMElement
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
				if (activeDOMElement.onKeyDown != null)
				{
					activeDOMElement.onKeyDown(keyEventData);
				}
		}*/
	}
	
	/**
	 * When a key up event happens, redirect to the
	 * currently active DOMElement
	 */
	private function onKeyUp(keyEventData:KeyboardEvent):Void
	{
		if (_activeDOMElement.onKeyUp != null)
		{
			_activeDOMElement.onKeyUp(keyEventData);
		}
	}
	
	/**
	 * When TAB is pressed, determine the next
	 * DOMElement in the _tabList array which
	 * must be focused
	 * 
	 * @param	reverse when Shift is also pressed,
	 * focus the previous focusable DOMElement in
	 * the _tabList array
	 */
	private function doTabFocus(reverse:Bool):Void
	{
		//build the tab list if it the first
		//tab focus or if it was invalidated
		if (_tabList == null)
		{
			_tabList = buildTabList(_bodyDOMElement);
		}
		
		//search the next valid index for the tab list
		//by incrementing or decrementing the tab list index.
		//As the tab focus loop, the tab list index might be reseted
		//or set to the last element
		if (activeDOMElement != _bodyDOMElement)
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
		//if the currently activeDOMElement is the body, it means
		//no DOMElement is actually focused and there is no need
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
		
		//set the activeDOMElement with the found tab list index
		activeDOMElement = _tabList[_tabListIndex];
	}
	
	/**
	 * Traverse all the DOM once to build a flat list of all the focusable
	 * DOMElements in the DOM.
	 * 
	 * The list is first composed of all the focusable DOMElement with a tabIndex
	 * superior to 0, ordered form smaller to bigger then the list contains all the
	 * focusable DOMElement with a tabIndex of 0, ordered in DOM order starting from
	 * the BodyDOMElement
	 */
	private function buildTabList(containerDOMElement:ContainerDOMElement):Array<DOMElement>
	{
		//each time the list is rebuild, the tab list index is
		//reseted so that the first item of the list is selected when
		//the user press tab
		_tabListIndex = 0;
		
		//contains the DOMElement with a 0 tabIndex
		var orderedTabList:Array<DOMElement> = new Array<DOMElement>();
		
		//contains the DOMElement with a tabIndex > 0
		var indexedTabList:Array<DOMElement> = new Array<DOMElement>();
		
		//build the list
		doBuildTabList(containerDOMElement, orderedTabList, indexedTabList);
		
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
	 * the ordered focusable DOMElements
	 */
	private function doBuildTabList(containerDOMElement:ContainerDOMElement, orderedTabList:Array<DOMElement>, indexedTabList:Array<DOMElement>):Void
	{
		//loop in all children
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].type == ContainerDOMElementChildValue.domElement)
			{
				var child:DOMElement = containerDOMElement.children[i].child;
				
				//if the child is also a ContainerDOMElement, call the doBuildTabList
				//recursively
				if (Std.is(child, ContainerDOMElement) == true)
				{
					var containerChild:ContainerDOMElement = cast(child);
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
						//indexed DOMElement array which is
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
					//note : DOMElements which are tabEnabled but with a negative
					//tabIndex can't be selected with tab focus
				}
			}
		}
	}
	
	/**
	 * When a simulated mouse click must happen on the 
	 * active DOMElement, create all the necessary
	 * element such as a fake mouse position, and
	 * cal the active DOMElement's mouse down callback
	 * if it exists
	 */
	private function simulateMouseClick(keyEventData:KeyboardEvent):Void
	{
		if (activeDOMElement.onMouseDown != null)
		{
			//TODO : replace mouse click event + add right coordinate
			var mouseEvent:MouseEvent = new MouseEvent(MouseEvent.MOUSE_DOWN,
			0.0, 0.0, 0.0, 0.0, false, false, false);
			
			activeDOMElement.onMouseDown(mouseEvent);
		}
	
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	/////////////////////////////////
	
	/**
	 * When a new activeDOMElement is set, call 
	 * the focus out (blur) method on the previous
	 * one and then call the focus in on the 
	 * new one
	 */
	private function setActiveDOMElement(value:DOMElement):DOMElement
	{
		//only call if there is a previous activeDOMElement
		if (_activeDOMElement != null)
		{
			if (_activeDOMElement.onFocusOut != null)
			{
				_activeDOMElement.onFocusOut();
			}
		}
		
		//if the activeDOMElement is set to null, it defaults
		//to the BodyDOMElement
		if (value == null)
		{
			value = _bodyDOMElement;
		}
		
		//do nothing if the new avctiveDOMElement is the same
		//as the current one
		if (value != _activeDOMElement)
		{
			_activeDOMElement = value;
			if (_activeDOMElement.onFocusIn != null)
			{
				_activeDOMElement.onFocusIn();
			}
		}
		
		return _activeDOMElement;
	}
	
	private function getActiveDOMElement():DOMElement
	{
		return _activeDOMElement;
	}
	
	/**
	 * when the bodyDOMelement is defined for the FocusManager,
	 * reset the activeDOMElement and the tab list
	 */
	private function setBodyDOMElement(value:BodyDOMElement):BodyDOMElement
	{
		_bodyDOMElement = value;
		activeDOMElement = null;
		
		invalidate();

		
		return _bodyDOMElement;
	}
	
	private function getBodyDOMElement():BodyDOMElement
	{
		return _bodyDOMElement;
	}
	
}