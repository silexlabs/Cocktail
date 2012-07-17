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
import cocktail.core.resource.ResourceManager;
import cocktail.core.style.ComputedStyle;
import cocktail.port.DrawingManager;
import cocktail.port.Resource;
import cocktail.port.NativeElement;
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
	override private function renderEmbeddedAsset(graphicContext:DrawingManager):Void
	{
		var resource:Resource = ResourceManager.getResource(domNode.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME));

		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		var computedStyle:ComputedStyle = coreStyle.computedStyle;
		
		var width:Float = resource.intrinsicWidth;
		var height:Float = resource.intrinsicHeight;
		
		var sourceRect:RectangleData = {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		}
		//TODO 2 : doc
		//TODO 2 : also use scrollOffset.x
	
		var destPoint:PointData = {
			x:globalBounds.x + computedStyle.paddingLeft,
			y:globalBounds.y + computedStyle.paddingTop
		}
		
		if (resource.intrinsicWidth != computedStyle.width || resource.intrinsicHeight != computedStyle.height)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.translate(globalBounds.x + computedStyle.paddingLeft, globalBounds.y + computedStyle.paddingTop - scrollOffset.y);
			matrix.scale(computedStyle.width / resource.intrinsicWidth , computedStyle.height / resource.intrinsicHeight );
		
				
			sourceRect.x = globalBounds.x + computedStyle.paddingLeft;
			sourceRect.y = globalBounds.y + computedStyle.paddingTop - scrollOffset.y;
			sourceRect.width = computedStyle.width;
			sourceRect.height = computedStyle.height;
			
			graphicContext.drawImage(resource.nativeResource, matrix, sourceRect);
		}
		else
		{
			destPoint.y = globalBounds.y + computedStyle.paddingTop - scrollOffset.y;
			graphicContext.copyPixels(resource.nativeResource, sourceRect, destPoint);
		}
	}
	
}