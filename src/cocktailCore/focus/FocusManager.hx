/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.focus;

import core.dom.HTMLBodyElement;
import core.HTMLElement;
import core.keyboard.Keyboard;
import core.keyboard.KeyboardData;
import core.mouse.MouseData;
import cocktailCore.domElement.DOMElementData;
import haxe.Log;

//import the right runtime implementations
#if (flash9 || cpp || nme)
import cocktailCore.focus.as3.FocusManagerImpl;

#elseif js
import cocktailCore.focus.js.FocusManagerImpl;

#elseif doc
class FocusManagerImpl extends cocktailCore.focus.abstract.AbstractFocusManagerImpl { }

#end

/**
 * The Focus Manager determine which DOMElement in the 
 * DOM has focus, meaning that it will receive keyboard
 * events. Focus can be given by clicking on a DOMElement
 * which can receive the focus or by using the TAB key on
 * the keyboard
 * 
 * This class is a singleton forwarding method to
 * actual implementation, differing for each runtime
 * 
 * @author Yannick DOMINGUEZ
 */
class FocusManager 
{
	/**
	 * The singleton instance
	 */
	private static var _instance:FocusManager;
	
	/**
	 * get/set the bodyDOMElement at the top of the DOM
	 */
	public var bodyElement(getBodyElement, setBodyElement):HTMLBodyElement;
	
	/**
	 * get/set the currently active (focused) DOMElement
	 */
	public var activeElement(getActiveElement, setActiveElement):HTMLElement;
	
	/**
	 * an instance of the actual implementation of the
	 * focus manager
	 */
	private var _focusManagerImpl:FocusManagerImpl;
	
	/**
	 * class constructor. Instantiate the focus
	 * manager implementation. Private as it is
	 * a Singleton
	 */
	private function new() 
	{
		_focusManagerImpl = new FocusManagerImpl();
	}
	
	/**
	 * Singleton initialisation method
	 */
	public static function getInstance():FocusManager
	{
		if (_instance == null)
		{
			_instance = new FocusManager();
		}
		return _instance;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Invalidate the focus manager order of 
	 * DOMElement to focus when using the TAB
	 * key
	 */
	public function invalidate():Void
	{
		_focusManagerImpl.invalidate();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	// forward to the focus manager implementation
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setActiveElement(value:HTMLElement):HTMLElement
	{
		return _focusManagerImpl.activeElement = value;
	}
	
	private function getActiveElement():HTMLElement
	{
		return _focusManagerImpl.activeElement;
	}
	
	private function setBodyElement(value:HTMLBodyElement):HTMLBodyElement
	{
		return _focusManagerImpl.bodyElement = value;
	}
	
	private function getBodyElement():HTMLBodyElement
	{
		return _focusManagerImpl.bodyElement;
	}
}