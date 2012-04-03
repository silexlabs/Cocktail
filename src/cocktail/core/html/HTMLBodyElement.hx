/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.event.Event;
import cocktail.core.nativeElement.NativeElementManager;


#if (flash9 || nme)
import cocktail.port.flash_player.HTMLElement;
import cocktail.port.flash_player.BodyCoreStyle;

#elseif js
import cocktail.port.browser.HTMLElement;
import cocktail.core.style.AbstractBodyCoreStyle;

#end

/**
 * The HTML document body. This element is always present
 * in the DOM API, even if the tags are not present in the source document.
 * 
 * TODO : override in JS to listen to keyboard on document. Or use ownerDocument
 * or add keydown, keyup callbacks on HTMLDocument
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLBodyElement extends HTMLElement
{
	/**
	 * the html tag name for the body
	 */
	private static inline var HTML_BODY_TAG_NAME:String = "body";
	
	/**
	 * class constructor.
	 */
	public function new() 
	{	
		super(HTML_BODY_TAG_NAME);
	}
	
	/**
	 * overriden to use the root of the runtime
	 */
	override private function initNativeElement():Void
	{
		_nativeElement = NativeElementManager.getRoot();
	}
	
	/**
	 * Instantiate a Style specific to this
	 * HTMLElement
	 */
	override private function initStyle():Void
	{
		_coreStyle = new BodyCoreStyle(this);
	}
}