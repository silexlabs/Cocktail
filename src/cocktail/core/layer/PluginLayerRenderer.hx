/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	override public function attach():Void
	{
		super.attach();
		var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
		htmlObjectElement.plugin.attach(graphicsContext);
	}
	
	/**
	 * When detached, gives an opportunity to
	 * the plugin to detach itself from
	 * the display list
	 */
	override public function detach():Void
	{
		//TODO 2 : when the layer is first created
		//it has no graphics context yet, should
		//not happen ?
		if (hasOwnGraphicsContext == true)
		{
			var htmlObjectElement:HTMLObjectElement = cast(rootElementRenderer.domNode);
			htmlObjectElement.plugin.detach(graphicsContext);
		}
		super.detach();
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	////////////////////////////////
	
	/**
	 * override to prevent updating the bitmap
	 * data, plugin don't need bitmap data
	 * 
	 * TODO 2 : might actually be useful to draw background, borders...
	 * should use graphic context of parent
	 */
	override private function initBitmapData(width:Int, height:Int):Void
	{
		
	}
	
	/**
	 * No need to clear, its not suposed to have
	 * bitmap
	 */
	override private function clear():Void
	{
	
	}
	
}