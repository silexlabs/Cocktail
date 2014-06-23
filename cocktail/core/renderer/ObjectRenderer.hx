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
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLObjectElement;
import cocktail.core.layer.CompositingLayerRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.layer.PluginLayerRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.geom.GeomData;

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
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Object always establishes create a new layer as plugin rendering
	 * is typically done outside of classic display lists
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}
	
	/**
	 * Instantitate its own compositing layer, which
	 * is a subclass dedicated to plugin rendering
	 */
	override private function doCreateLayer():Void
	{
		layerRenderer = new PluginLayerRenderer(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendering, update the viewport
	 * of the plugin, so that the plugin
	 * can update its display
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var htmlObjectElement:HTMLObjectElement = cast(domNode);
		htmlObjectElement.plugin.updateViewport(globalBounds.x + coreStyle.usedValues.paddingLeft + coreStyle.usedValues.borderLeftWidth, globalBounds.y + coreStyle.usedValues.paddingTop + coreStyle.usedValues.borderTopWidth, globalBounds.width, globalBounds.height);
	}
}
