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
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * An ElementRenderer displaying an object (plugin)
 * to the screen
 * 
 * TODO 1 : whole class is messy, should be implemented as a plugin, 
 * not here as "object" can render other plugins than flash  
 * 
 * @author Yannick DOMINGUEZ
 */
class ObjectRenderer extends EmbeddedBoxRenderer
{
	private static inline var NO_SCALE:String = "noscale";
	
	private static inline var SHOW_ALL:String = "showall";
	
	private static inline var EXACT_FIT:String = "exactfit";
	
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Object always establishes a new stacking context as plugin rendering
	 * is typically done outside of classic display lists
	 */
	override public function establishesNewStackingContext():Bool
	{
		return true;
	}
	
	//TODO 1 : doc
	override private function createLayer(parentLayer:LayerRenderer):Void
	{
		layerRenderer = new CompositingLayerRenderer(this);
		parentLayer.appendChild(layerRenderer);
		_hasOwnLayer = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendered, attach the plugin object to the native display list
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext):Void
	{
		//TODO 1 : should be removed
		#if macro
		
		#elseif (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext.nativeLayer);
	
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
		
		var assetBounds:RectangleData = getAssetBounds(coreStyle.usedValues.width, coreStyle.usedValues.height,
		width, height);

		var scaleMode:String = getScaleMode();
		
		switch (scaleMode)
		{
			case NO_SCALE:
				asset.x = globalBounds.x + coreStyle.usedValues.paddingLeft;
				asset.y = globalBounds.y + coreStyle.usedValues.paddingTop;
				
			case EXACT_FIT:
				asset.x = globalBounds.x + coreStyle.usedValues.paddingLeft;
				asset.y = globalBounds.y + coreStyle.usedValues.paddingTop;
				asset.scaleX = coreStyle.usedValues.width / width;
				asset.scaleY = coreStyle.usedValues.height / height;

			default:
				asset.x = globalBounds.x + coreStyle.usedValues.paddingLeft + assetBounds.x;
				asset.y = globalBounds.y + coreStyle.usedValues.paddingTop + assetBounds.y;
				asset.scaleX = assetBounds.width / width;
				asset.scaleY = assetBounds.height / height;
		}
		
		//mask the sprite so that it doesn't overflow
		var mask = new flash.display.Sprite();
		mask.graphics.beginFill(0xFF0000, 0.0);
		mask.graphics.drawRect( 
		globalBounds.x + coreStyle.usedValues.paddingLeft, globalBounds.y + coreStyle.usedValues.paddingTop,
		coreStyle.usedValues.width, coreStyle.usedValues.height);
		mask.graphics.endFill();
		asset.mask = mask;
		
		containerGraphicContext.addChild(asset);
		
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getScaleMode():String
	{
		var scaleMode:String = SHOW_ALL;
		for (i in 0...domNode.childNodes.length)
		{
			var child:HTMLElement = domNode.childNodes[i];
			
			if (child.tagName == HTMLConstants.HTML_PARAM_TAG_NAME)
			{
				if (child.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) != null)
				{
					if (child.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) == "scale")
					{
						if (child.getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME) != null)
						{
							scaleMode = child.getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
						}
					}
				}
			}
		}
		
		return scaleMode;
	}
	
}