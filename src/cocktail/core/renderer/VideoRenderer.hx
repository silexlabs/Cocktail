 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLVideoElement;
import cocktail.core.resource.ResourceManager;
import cocktail.port.DrawingManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.port.Resource;

/**
 * Renders an embedded video asset or its poster frame
 * 
 * @author Yannick DOMINGUEZ
 */
class VideoRenderer extends EmbeddedBoxRenderer
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
	 * Render the embedded video asset or the video poster frame.
	 */
	override private function renderEmbeddedAsset(graphicContext:DrawingManager)
	{
		var htmlVideoElement:HTMLVideoElement = cast(domNode);
		
		//determine wether to render video or poster frame
		if (htmlVideoElement.shouldRenderPosterFrame() == true)
		{
			renderPosterFrame(htmlVideoElement, graphicContext);
		}
		else
		{
			renderVideo(htmlVideoElement, graphicContext);
		}
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually render the video
	 * 
	 * Video intrinsic aspect ratio is always preserved, so the
	 * video might be letterboxed to fit in the available bounds,
	 * the video always takes the maximum amount of space available
	 * while keeping its aspect ratio
	 */
	private function renderVideo(htmlVideoElement:HTMLVideoElement, graphicContext:DrawingManager):Void
	{
		//get the bounds for the video so that it takes the maximum space and is centered
		var videoBounds:RectangleData = getAssetBounds(coreStyle.computedStyle.width,
		coreStyle.computedStyle.height, htmlVideoElement.videoWidth, htmlVideoElement.videoHeight);
		
		#if (flash9 || nme)
		
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		containerGraphicContext.addChild(htmlVideoElement.embeddedAsset);

		//add the x and y offset for the video
		htmlVideoElement.embeddedAsset.x = globalBounds.x + coreStyle.computedStyle.paddingLeft + videoBounds.x;
		htmlVideoElement.embeddedAsset.y = globalBounds.y + coreStyle.computedStyle.paddingTop + videoBounds.y;

		//use the actual video width and height
		htmlVideoElement.embeddedAsset.width = videoBounds.width;
		htmlVideoElement.embeddedAsset.height = videoBounds.height;
		
		htmlVideoElement.embeddedAsset.alpha = coreStyle.computedStyle.opacity;
		
		#end
	}
	
	/**
	 * Render the poster frame of the video if the video is not
	 * yet loaded or has not started playing yet
	 */
	private function renderPosterFrame(htmlVideoElement:HTMLVideoElement, graphicContext:DrawingManager):Void
	{
		var resource:Resource = ResourceManager.getResource(domNode.getAttribute(HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME));

		//the poster frame is not loaded or there was an erro while loading it
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		var posterBounds:RectangleData = getAssetBounds(coreStyle.computedStyle.width,
		coreStyle.computedStyle.height, resource.intrinsicWidth, resource.intrinsicHeight);
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		var bitmap:flash.display.Bitmap = new flash.display.Bitmap(resource.nativeResource, flash.display.PixelSnapping.AUTO, true);
		containerGraphicContext.addChild(bitmap);
		
		var globalBounds:RectangleData = globalBounds;
		bitmap.x = globalBounds.x + coreStyle.computedStyle.paddingLeft + posterBounds.x;
		bitmap.y = globalBounds.y + coreStyle.computedStyle.paddingTop + posterBounds.y;
		bitmap.width = posterBounds.width;
		bitmap.height = posterBounds.height;
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method returning the right rectangle so that
	 * the video or poster frame can take the maximum available width
	 * and height while preserving their aspect ratio and also be 
	 * centered in the available space
	 * 
	 * @param	availableWidth the maximum width available for the poster frame or video
	 * @param	availableHeight the maximum height available for the poster frame or video
	 * @param	assetWidth the intrinsic width of the video or poster frame
	 * @param	assetHeight the intrinsic height of the video or poster frame
	 * @return	the bounds of the asset
	 */
	private function getAssetBounds(availableWidth:Float, availableHeight:Float, assetWidth:Float, assetHeight:Float):RectangleData
	{
		//those will hold the actual value used for the video or poster 
		//dimensions, with the kept aspect ratio
		var width:Float;
		var height:Float;

		if (availableWidth > availableHeight)
		{
			//get the ratio between the intrinsic asset width and the width it must be displayed at
			var ratio:Float = assetHeight / availableHeight;
			
			//check that the asset isn't wider than the available width
			if ((assetWidth / ratio) < availableWidth)
			{
				//the asset width use the computed width while the height apply the ratio
				//to the asset height, so that the ratio is kept while displaying the asset
				//as big as possible
				width =  assetWidth / ratio ;
				height = availableHeight;
			}
			//else reduce the height instead of the width
			else
			{
				ratio = assetWidth / availableWidth;
				
				width = availableWidth;
				height = assetHeight / ratio;
			}
		}
		//same as above but inverted
		else
		{
			var ratio:Float = assetWidth / availableWidth;
			
			if ((assetHeight / ratio) < availableHeight)
			{
				height = assetHeight / ratio;
				width = availableWidth;
			}
			else
			{
				ratio = assetHeight / availableHeight;
				width =  assetWidth / ratio ;
				height = availableHeight;
			}
		}
		
		//the asset must be centered in the ElementRenderer, so deduce the offsets
		//to apply to the x and y direction
		var xOffset:Float = (availableWidth - width) / 2;
		var yOffset:Float = (availableHeight - height) /2;
		
		return {
			width:width,
			height:height,
			x:xOffset,
			y:yOffset
		}
	}
}