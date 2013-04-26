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
import cocktail.core.renderer.ElementRenderer;

/**
 * A special kind of compositing layer, dedicated to plugin.
 * When the graphic context of this layer is attached or detached, 
 * call methods on the plugin to allow it
 * to detach / attach itself from / to the graphic context
 * 
 * @author Yannick DOMINGUEZ
 */
class PluginLayerRenderer extends CompositingLayerRenderer
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
	 * plugin to attch itself to the display list
	 */
	override public function attachGraphicsContext():Void
	{
		super.attachGraphicsContext();
		var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
		htmlObjectElement.plugin.attach(graphicsContext);
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
			var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
			htmlObjectElement.plugin.detach(graphicsContext);
		}
		super.detachGraphicsContext();
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	////////////////////////////////
	
	/**
	 * A plugin layer is composited if its plugin 
	 * requires it
	 */
	override public function isCompositingLayer():Bool
	{
		var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
		return htmlObjectElement.plugin.isCompositedPlugin();
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * For composited plugin, they
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