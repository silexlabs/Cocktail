/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.core.html.HTMLObjectElement;
import cocktail.core.html.HTMLVideoElement;
import cocktail.core.renderer.ElementRenderer;

/**
 * A special kind of compositing layer, dedicated to video.
 * When the graphic context of this layer is attached or detached, 
 * call methods on the native video to allow it
 * to detach / attach itself from / to the graphic context
 * 
 * @author Yannick DOMINGUEZ
 */
class VideoLayerRenderer extends CompositingLayerRenderer
{
	/**
	 * class constructor
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super(rootElementRenderer);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING TREE METHODS
	////////////////////////////////
	
	/**
	 * When attached, gives an opportunity to the
	 * video to attch itself to the display list
	 */
	override public function attachGraphicsContext():Void
	{
		super.attachGraphicsContext();
		var htmlVideoElement:HTMLVideoElement = cast(rootElementRenderer.domNode);
		htmlVideoElement.nativeMedia.attach(graphicsContext);
	}
	
	/**
	 * When detached, gives an opportunity to
	 * the plugin to detach itself from
	 * the display list
	 */
	override public function detachGraphicsContext():Void
	{
		//TODO 2 : when the layer is first created
		//it has no graphics context yet, should
		//not happen ?
		if (graphicsContext != null)
		{
			var htmlVideoElement:HTMLVideoElement = cast(rootElementRenderer.domNode);
			htmlVideoElement.nativeMedia.detach(graphicsContext);
		}
		super.detachGraphicsContext();
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * For composited video, they
	 * use the bitmap of their parent
	 * if they need to render border,
	 * background...
	 */
	override public function needsBitmap():Bool
	{
		return false;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	////////////////////////////////
	
	/**
	 * No need to clear, its not suposed to have
	 * bitmap
	 */
	override private function doClear(x:Float, y:Float, width:Float, height:Float):Void
	{
	
	}
	
}