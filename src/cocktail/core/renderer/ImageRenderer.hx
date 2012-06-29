 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.resource.ResourceManager;
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
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement):Void
	{
		var resource:Resource = ResourceManager.getResource(node.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME));

		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		var bitmap:flash.display.Bitmap = new flash.display.Bitmap(resource.nativeResource, flash.display.PixelSnapping.AUTO, true);
		containerGraphicContext.addChild(bitmap);
		
		var globalBounds:RectangleData = globalBounds;
		bitmap.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		bitmap.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;
		bitmap.width = _coreStyle.computedStyle.width;
		bitmap.height = _coreStyle.computedStyle.height;
		#end
	}
	
}