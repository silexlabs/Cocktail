/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.focus.js;

import cocktailCore.focus.abstract.AbstractFocusManagerImpl;
import core.dom.HTMLBodyElement;
import core.dom.HTMLElement;

/**
 * This is the JavaScript implementation of the 
 * focus manager. Prevents the default behaviour
 * as the focus in JS relies on the browser
 * 
 * @author Yannick DOMINGUEZ
 */
class FocusManagerImpl extends AbstractFocusManagerImpl
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * don't listen to keyboard, as it is managed by the browser
	 */
	override private function initKeyboardListeners():Void
	{
		
	}
	
	/**
	 * only store the value
	 */
	override private function setActiveElement(value:HTMLElement):HTMLElement
	{
		return _activeElement = value;
	}
	
	/**
	 * only store the value
	 */
	override private function setBodyElement(value:HTMLBodyElement):HTMLBodyElement
	{
		return _bodyElement = value;
	}
	
}