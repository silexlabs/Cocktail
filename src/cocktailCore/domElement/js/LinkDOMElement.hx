/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktailCore.domElement.abstract.AbstractLinkDOMElement;
import core.mouseMouseData;
import cocktailCore.domElement.DOMElementData;

/**
 * This is the JavaScript implementation of the 
 * LinkDOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class LinkDOMElement extends AbstractLinkDOMElement
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN FOCUS SETTER/GETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For element focusable by default such as the
	 * LinkDOMElement, the tabIndex must be set to 
	 * a negative value to prevent the DOMElement
	 * from being focused with TAB
	 */
	override private function setTabEnabled(value:Bool):Bool
	{
		if (value == true)
		{
			untyped _nativeElement.tabIndex = tabIndex;
		}
		else
		{
			untyped _nativeElement.tabIndex = -1;
		}
		
		return _tabEnabled = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN LINK SETTER/GETTER
	// Override setters to set the corresponding
	// attributes of the native HTML <a> element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setHref(value:String):String
	{
		untyped _nativeElement.href = value;
	
		super.setHref(value);
		return value;
	}
	
	override private function setTarget(value:LinkTargetValue):LinkTargetValue
	{
		untyped _nativeElement.target = getTargetAsString(value);
		
		super.setTarget(value);
		return value;
	}
	
}