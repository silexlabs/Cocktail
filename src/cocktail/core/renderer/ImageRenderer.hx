 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.resource.ResourceManager;
import cocktail.port.Resource;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * An ElementRenderer displaying a bitmap picture
 * to the screen
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageRenderer extends EmbeddedBoxRenderer
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
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement):Void
	{
		var resource:Resource = ResourceManager.getResource(node.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME));

		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		var bitmap:flash.display.Bitmap = new flash.display.Bitmap(resource.nativeResource, flash.display.PixelSnapping.AUTO, true);
		containerGraphicContext.addChild(bitmap);
		
		var globalBounds:RectangleData = globalBounds;
		bitmap.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		bitmap.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;
		bitmap.width = _coreStyle.computedStyle.width;
		bitmap.height = _coreStyle.computedStyle.height;
		#end
	}
	
}