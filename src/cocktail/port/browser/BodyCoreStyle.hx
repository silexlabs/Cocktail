/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;

import cocktail.core.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.style.AbstractBodyCoreStyle;
import cocktail.core.style.StyleData;

/**
 * This is the JavaScript implementation of the BodyStyle
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyCoreStyle extends AbstractBodyCoreStyle
{
	/**
	 * class constructor
	 * @param	htmlElement
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as the browser deals with the rendering in JS
	 */
	override public function render(nativeElement:NativeElement):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as in JS, the browser takes care of the layout
	 */
	override public function layout(containingHTMLElementData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{	
		
	}
	
}