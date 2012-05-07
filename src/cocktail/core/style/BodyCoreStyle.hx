/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.FontManager;
import cocktail.core.HTMLDocument;
import cocktail.core.NativeElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.font.FontData;
import haxe.Log;

/**
 * This is the style implementation for HTMLBodyElement.
 * It inherits from ContainerCoreStyle and implement behaviours
 * specific to the root of the DOM where appropriate
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyCoreStyle extends ContainerCoreStyle
{
	
	/**
	 * class constructor
	 * @param	htmlElement
	 */
	public function new() 
	{
		super();
	}
	
	
}