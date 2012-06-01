/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.NativeElement;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import flash.display.DisplayObjectContainer;
import haxe.Log;

/**
 * Base class for embedded element
 * such as a picture.
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBoxRenderer extends BoxRenderer
{
	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to also render the embedded asset, for instance a picture for
	 * an image renderer
	 */
	override public function render(parentGraphicContext:NativeElement, parentRelativeOffset:PointData):Void
	{
		super.render(_graphicsContext, parentRelativeOffset);
		var relativeOffset:PointData = getConcatenatedRelativeOffset(parentRelativeOffset);
		renderEmbeddedAsset(_graphicsContext, relativeOffset);
		
		//draws the graphic context of this block box on the one of its
		//parent
		#if (flash9 || nme)
		var containerGraphicContext:DisplayObjectContainer = cast(parentGraphicContext);
		containerGraphicContext.addChild(_graphicsContext);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	override public function isReplaced():Bool
	{
		return true;
	}

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Renders an embedded asset using the graphic context as canvas
	 */
	private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		//abstract
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 4 : messy
	override private function get_bounds():RectangleData
	{
		_bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		_bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
		return _bounds;
	}
}