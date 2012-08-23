 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.geom.Matrix;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;

/**
 * An ElementRenderer displaying a bitmap picture
 * to the screen
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageRenderer extends EmbeddedBoxRenderer
{
	/**
	 * class constructor
	 */
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext):Void
	{
		var resource:AbstractResource = ResourceManager.getImageResource(domNode.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME));

		//don't paint anything is the image is not loaded or there was an error
		//while loading
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		var usedValues:UsedValuesData = coreStyle.usedValues;
		
		var paintBounds:RectangleData = { 
			x:globalBounds.x + usedValues.paddingLeft - scrollOffset.x,
			y:globalBounds.y + usedValues.paddingTop - scrollOffset.y,
			width:usedValues.width,
			height:usedValues.height
		}
		
		paintResource(graphicContext, resource.nativeResource, paintBounds, resource.intrinsicWidth, resource.intrinsicHeight);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually paint the resource's bitmap data on the graphic context.
	 */
	private function paintResource(graphicContext:GraphicsContext, nativeBitmapData:NativeBitmapData, bounds:RectangleData, intrinsicWidth:Float, intrinsicHeight:Float):Void
	{
		//check if a tranformaton should be applied to the picture, for instance if the picture
		//should be rescaled when painted, as if it does not, it can use a faster drawing
		//routine
		if (intrinsicWidth != bounds.width || intrinsicHeight != bounds.height)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.translate(bounds.x, bounds.y);
			matrix.scale(bounds.width / intrinsicWidth , bounds.height / intrinsicHeight );
		
			var sourceRect:RectangleData = {
				x:bounds.x,
				y:bounds.y,
				width:bounds.width,
				height:bounds.height
			}
			
			graphicContext.drawImage(nativeBitmapData, matrix, sourceRect);
		}
		//here a faster drawing routine is used, the picture is drawn 
		//untransformed at a certain point
		else
		{
			var width:Float = intrinsicWidth;
			var height:Float = intrinsicHeight;
			
			//the rectangle from the source image that will be painted
			//it is always the full picture
			var sourceRect:RectangleData = {
				x:0.0,
				y:0.0,
				width:width,
				height:height
			}
			
			//the coordinates of the top left corner where the picture
			//will be painted
			var destPoint:PointData = {
				x:bounds.x,
				y:bounds.y
			}
			
			graphicContext.copyPixels(nativeBitmapData, sourceRect, destPoint);
		}
	}
	
}