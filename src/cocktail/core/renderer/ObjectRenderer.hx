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
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement):Void
	{
		
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
	
		var htmlObjectElement:HTMLObjectElement = cast(node);
		var asset:NativeElement = htmlObjectElement.embeddedAsset;
		
		var globalBounds:RectangleData = globalBounds;
		asset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		asset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;
		asset.width = _coreStyle.computedStyle.width;
		asset.height = _coreStyle.computedStyle.height;
		containerGraphicContext.addChild(asset);
		#end
	}
	
}