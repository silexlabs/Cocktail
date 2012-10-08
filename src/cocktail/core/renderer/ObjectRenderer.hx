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
import cocktail.core.layer.PluginLayerRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
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
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext):Void
	{
		var htmlObjectElement:HTMLObjectElement = cast(domNode);
		htmlObjectElement.plugin.updateViewport(globalBounds.x + coreStyle.usedValues.paddingLeft, globalBounds.y + coreStyle.usedValues.paddingTop, globalBounds.width, globalBounds.height);
	}
}