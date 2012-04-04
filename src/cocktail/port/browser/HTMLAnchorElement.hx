/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;

import cocktail.core.html.AbstractHTMLAnchorElement;
import cocktail.core.dom.DOMData;

/**
 * This is the browser implementation of the 
 * HTMLAnchorElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLAnchorElement extends AbstractHTMLAnchorElement
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOCUMENT LINK SETTER/GETTER
	// Override setters to set the corresponding
	// attributes of the native HTML <a> element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_href(value:String):String
	{
		untyped _nativeElement.href = value;
	
		super.set_href(value);
		return value;
	}
	
	override private function set_target(value:String):String
	{
		untyped _nativeElement.target = value;
		
		super.set_target(value);
		return value;
	}
	
}