/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.NativeElement;
import cocktail.core.style.CoreStyle;
import flash.display.DisplayObjectContainer;
import haxe.Log;
import cocktail.core.geom.GeomData;

/**
 * An Inline Box renderer is an element which participates
 * in an inline formatting context and which does not establishes
 * a formatting context.
 * 
 * It generates a line box for each line into which one of its children
 * participates
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{
	/**
	 * class constructor
	 */
	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as rendering an inline box renderer consist in rendering all of the 
	 * line boxes it generated
	 */
	override public function render(parentGraphicContext:NativeElement, parentRelativeOffset:PointData):Void
	{
		//first clear the graphics context
		clear();
		
		var relativeOffset:PointData = getConcatenatedRelativeOffset(parentRelativeOffset);
		
		//render negative z-index LayerRenderer
		if (establishesNewStackingContext() == true)
		{
			_layerRenderer.renderNegativeChildElementRenderers(_graphicsContext, relativeOffset);
		}
		
		//render all the child line boxes which belong to the same
		//stacking context as this InlineBoxRenderer
		renderChildLineBoxes(_graphicsContext, relativeOffset);
		
		if (establishesNewStackingContext() == true)
		{	
			_layerRenderer.renderZeroAndAutoChildElementRenderers(_graphicsContext, relativeOffset);
			_layerRenderer.renderPositiveChildElementRenderers(_graphicsContext, relativeOffset);
		}
		
		#if (flash9 || nme)
		var containerGraphicContext:DisplayObjectContainer = cast(parentGraphicContext);
		containerGraphicContext.addChild(_graphicsContext);
		#end
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually render the child line boxes
	 */
	private function renderChildLineBoxes(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		for (i in 0..._lineBoxes.length)
		{
			var childLineBoxes:Array<LineBox> = getLineBoxesInLine(_lineBoxes[i]);
			
			for (j in 0...childLineBoxes.length)
			{
				if (childLineBoxes[j].layerRenderer == _layerRenderer)
				{
					childLineBoxes[j].render(graphicContext, relativeOffset);
				}
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as the bounds of an inline box renderer is formed
	 * by the bounds of all of the line boxes it creates during
	 * formatting
	 */
	override private function get_bounds():RectangleData
	{
		var lineBoxesBounds:Array<RectangleData> = new Array<RectangleData>();
		for (i in 0..._lineBoxes.length)
		{
			lineBoxesBounds.push(_lineBoxes[i].bounds);
		}
		
		return getChildrenBounds(lineBoxesBounds);
	}
}