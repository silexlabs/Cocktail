 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
import cocktail.geom.GeomUtils;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLVideoElement;
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.layer.VideoLayerRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.base.ResourceBase;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.port.base.NativeMedia;

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
	 * Holds the bounds of the poster frame of the
	 * video
	 */
	private var _posterBounds:RectangleVO;
	
	/**
	 * Holds the bounds of the video
	 */
	private var _videoBounds:RectangleVO;
	
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		_posterBounds = new RectangleVO();
		_videoBounds = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * video always establishes a new layer as video rendering
	 * is typically done outside of classic display lists
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}
	
	/**
	 * Instantiate its own layer which is
	 * a compositing layer for the video
	 */
	override private function doCreateLayer():Void
	{
		layerRenderer = new VideoLayerRenderer(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the embedded video asset or the video poster frame.
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO)
	{
		var htmlVideoElement:HTMLVideoElement = cast(domNode);
		
		//determine wether to render video or poster frame
		if (htmlVideoElement.shouldRenderPosterFrame() == true)
		{
			renderPosterFrame(htmlVideoElement, graphicContext, clipRect, scrollOffset);
		}
		else
		{
			renderVideo(htmlVideoElement, graphicContext, scrollOffset);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Rendering the video consists in updating its viewport, matrix and alpha
	 * 
	 * Video intrinsic aspect ratio is always preserved, so the
	 * video might be letterboxed to fit in the available bounds,
	 * the video always takes the maximum amount of space available
	 * while keeping its aspect ratio
	 */
	private function renderVideo(htmlVideoElement:HTMLVideoElement, graphicContext:GraphicsContext, scrollOffset:PointVO):Void
	{
		//get the bounds for the video so that it takes the maximum space and is centered
		GeomUtils.getCenteredBounds(coreStyle.usedValues.width,
		coreStyle.usedValues.height, htmlVideoElement.videoWidth, htmlVideoElement.videoHeight, _videoBounds);
		
		var nativeVideo:NativeMedia = htmlVideoElement.nativeMedia;
		
		//set the position and size of the native video, relative
		//to the Window
		var videoViewport:RectangleVO = nativeVideo.viewport;
		videoViewport.x =  globalBounds.x + coreStyle.usedValues.paddingLeft + coreStyle.usedValues.borderLeftWidth + _videoBounds.x - scrollOffset.x;
		videoViewport.y =  globalBounds.y + coreStyle.usedValues.paddingTop + coreStyle.usedValues.borderTopWidth + _videoBounds.y - scrollOffset.y;
		videoViewport.width =  _videoBounds.width;
		videoViewport.height =  _videoBounds.height;
		
		nativeVideo.alpha = layerRenderer.alpha;
		nativeVideo.matrix = layerRenderer.matrix;
		nativeVideo.viewport = videoViewport;
	}
	
	/**
	 * Render the poster frame of the video if the video is not
	 * yet loaded or has not started playing yet
	 */
	private function renderPosterFrame(htmlVideoElement:HTMLVideoElement, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		var htmlElement:HTMLElement = cast(domNode);
		var resource:ResourceBase = htmlDocument.resourceManager.getImageResource(htmlElement.getAttribute(HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME));

		//the poster frame is not loaded or there was an error while loading it
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		//update the bounds of the poster frame
		GeomUtils.getCenteredBounds(coreStyle.usedValues.width,
		coreStyle.usedValues.height, resource.intrinsicWidth, resource.intrinsicHeight, _posterBounds);
		
		var x:Float = globalBounds.x + coreStyle.usedValues.paddingLeft + coreStyle.usedValues.borderLeftWidth + _posterBounds.x - scrollOffset.x;
		var y:Float = globalBounds.y + coreStyle.usedValues.paddingTop + coreStyle.usedValues.borderTopWidth + _posterBounds.y - scrollOffset.y;
		var width:Float = _posterBounds.width;
		var height:Float = _posterBounds.height;
		
		var paintBounds:RectangleVO = new RectangleVO();
		paintBounds.x = x;
		paintBounds.y = y;
		paintBounds.width = width;
		paintBounds.height = height;
		
		paintResource(graphicContext, resource.nativeResource, paintBounds, resource.intrinsicWidth, resource.intrinsicHeight, clipRect);
	}
}
