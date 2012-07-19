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
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.resource.ImageLoader;
import cocktail.core.resource.ResourceManager;
import cocktail.port.DrawingManager;
import cocktail.port.Resource;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * An ElementRenderer displaying an object (plugin)
 * to the screen
 * 
 * @author Yannick DOMINGUEZ
 */
class ObjectRenderer extends EmbeddedBoxRenderer
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
	 * When rendered, attach the plugin object to the native display list
	 * 
	 * TODO 1 : obsolete implementation, should work like video
	 */
	override private function renderEmbeddedAsset(graphicContext:DrawingManager):Void
	{
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext.nativeElement);
	
		var htmlObjectElement:HTMLObjectElement = cast(domNode);
		var asset:flash.display.Loader = cast(htmlObjectElement.embeddedAsset);
		
		var globalBounds:RectangleData = globalBounds;
		asset.transform.matrix = new flash.geom.Matrix();
		
		var width:Float = 0.0;
		var height:Float = 0.0;
		
		//get the intrinsic width and height of the sprite
		try {
			width = asset.contentLoaderInfo.width;
			height = asset.contentLoaderInfo.height;
		}
		catch (e:Dynamic)
		{
			
		}
		
		var assetBounds:RectangleData = getAssetBounds(coreStyle.computedStyle.width, coreStyle.computedStyle.height,
		width, height);
		
		asset.x = globalBounds.x + coreStyle.computedStyle.paddingLeft + assetBounds.x;
		asset.y = globalBounds.y + coreStyle.computedStyle.paddingTop + assetBounds.y;
		asset.scaleX = assetBounds.width / width;
		asset.scaleY = assetBounds.height / height;
		
		//mask the sprite so that it doesn't overflow
		var mask = new flash.display.Sprite();
		mask.graphics.beginFill(0xFF0000, 0.0);
		mask.graphics.drawRect( 
		globalBounds.x + coreStyle.computedStyle.paddingLeft, globalBounds.y + coreStyle.computedStyle.paddingTop,
		coreStyle.computedStyle.width, coreStyle.computedStyle.height);
		mask.graphics.endFill();
		asset.mask = mask;
		
		containerGraphicContext.addChild(asset);
		
		#end
	}
}