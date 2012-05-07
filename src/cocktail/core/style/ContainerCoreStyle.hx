/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.dom.Text;
import cocktail.core.FontManager;
import cocktail.core.NativeElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.dom.Node;
import cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.formatter.InlineFormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.dom.DOMData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
import haxe.Timer;

import haxe.Log;

/**
 * This is the style implementation for HTMLElements which are also
 * containers.
 * 
 * This HTMLElement can have children, and when laid out,
 * also starts the layout on each of its children using
 * either a block or inline formatting
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerCoreStyle extends CoreStyle
{
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super();
	}
	
}