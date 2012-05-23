 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;

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
	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 2 : test opacity
	/**
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement, relativeOffset:PointData)
	{
		var htmlImageElement:HTMLImageElement = cast(_node);
		
		graphicContext.addChild(htmlImageElement.embeddedAsset);
	
		#if (flash9 || nme)
		htmlImageElement.embeddedAsset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		htmlImageElement.embeddedAsset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;
		htmlImageElement.embeddedAsset.alpha = computedStyle.opacity;
		htmlImageElement.embeddedAsset.width = _coreStyle.computedStyle.width;
		htmlImageElement.embeddedAsset.height = _coreStyle.computedStyle.height;
		
		//have to try/catch because of potential cross-domain security error
		try {
			var loader:Loader = cast(htmlImageElement.embeddedAsset);
			var bitmap:Bitmap = cast(loader.content);
			if (bitmap != null)
			{
				bitmap.smoothing = true;
			}
		}
		catch(e:Dynamic) {
				
			}
		
		#end
	}
	
}