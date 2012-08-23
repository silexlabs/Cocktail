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
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.port.GraphicsContext;
import cocktail.port.ImageResource;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.port.NativeVideo;
import cocktail.port.platform.nativeMedia.NativeMedia;

/**
 * Renders an embedded video asset or its poster frame
 * 
 * Inherits from ImageRenderer as if a poster frame its
 * displayed, the behaviour is similar
 * 
 * @author Yannick DOMINGUEZ
 */
class VideoRenderer extends ImageRenderer
{
	/**
	 * class constructor
	 */
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * video always establishes a new stacking context as video rendering
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
	 * Render the embedded video asset or the video poster frame.
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext)
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
	 * 
	 * TODO 3 : alpha of video no longer managed
	 */
	private function renderVideo(htmlVideoElement:HTMLVideoElement, graphicContext:GraphicsContext):Void
	{
		//get the bounds for the video so that it takes the maximum space and is centered
		var videoBounds:RectangleData = getAssetBounds(coreStyle.usedValues.width,
		coreStyle.usedValues.height, htmlVideoElement.videoWidth, htmlVideoElement.videoHeight);
		
		var globalBounds:RectangleData = this.globalBounds;
		
		var nativeVideo:NativeMedia = htmlVideoElement.nativeMedia;
		
		//set the position and size of the native video, relative
		//to the Window
		nativeVideo.viewport = {
			x: globalBounds.x + coreStyle.usedValues.paddingLeft + videoBounds.x - scrollOffset.x,
			y: globalBounds.y + coreStyle.usedValues.paddingTop + videoBounds.y - scrollOffset.y,
			width: videoBounds.width,
			height: videoBounds.height
		}
		
		nativeVideo.attach(graphicContext);
	}
	
	/**
	 * Render the poster frame of the video if the video is not
	 * yet loaded or has not started playing yet
	 */
	private function renderPosterFrame(htmlVideoElement:HTMLVideoElement, graphicContext:GraphicsContext):Void
	{
		var resource:AbstractResource = ResourceManager.getImageResource(domNode.getAttribute(HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME));

		//the poster frame is not loaded or there was an error while loading it
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		var posterBounds:RectangleData = getAssetBounds(coreStyle.usedValues.width,
		coreStyle.usedValues.height, resource.intrinsicWidth, resource.intrinsicHeight);
		
		var paintBounds:RectangleData = {
			x:globalBounds.x + coreStyle.usedValues.paddingLeft + posterBounds.x - scrollOffset.x,
			y:globalBounds.y + coreStyle.usedValues.paddingTop + posterBounds.y - scrollOffset.y,
			width:posterBounds.width,
			height:posterBounds.height
		}
		
		paintResource(graphicContext, resource.nativeResource, paintBounds, resource.intrinsicWidth, resource.intrinsicHeight);
	}
}