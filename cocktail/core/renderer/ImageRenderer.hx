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
import cocktail.geom.Matrix;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.base.ResourceBase;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.core.css.CSSCascadeData;

/**
 * An ElementRenderer displaying a bitmap picture
 * to the screen
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageRenderer extends EmbeddedBoxRenderer
{
	/**
	 * Store the bounds of the image to paint
	 */
	private var _paintBounds:RectangleVO;
	
	/**
	 * Store the destinaton point used by the fast
	 * graphic routine
	 */
	private var _destinationPoint:PointVO;
	
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		
		_paintBounds = new RectangleVO();
		_destinationPoint = new PointVO(0.0, 0.0);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		//get source of picture
		var htmlElement:HTMLElement = cast(domNode);
		var src:String = htmlElement.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME);
		
		//early return if image has no picture yet
		if (src == null)
		{
			return;
		}
		
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		var resource:ResourceBase = htmlDocument.resourceManager.getImageResource(src);
		
		//don't paint anything is the image is not loaded or there was an error
		//while loading
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		
		_paintBounds.x = globalBounds.x + usedValues.paddingLeft + usedValues.borderLeftWidth - scrollOffset.x;
		_paintBounds.y = globalBounds.y + usedValues.paddingTop + usedValues.borderTopWidth - scrollOffset.y;
		_paintBounds.width = usedValues.width;
		_paintBounds.height = usedValues.height;
		
		paintResource(graphicContext, resource.nativeResource, _paintBounds, resource.intrinsicWidth, resource.intrinsicHeight, clipRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually paint the resource's bitmap data on the graphic context.
	 */
	private function paintResource(graphicContext:GraphicsContext, nativeBitmapData:NativeBitmapData, bounds:RectangleVO, intrinsicWidth:Float, intrinsicHeight:Float, clipRect:RectangleVO):Void
	{
		//check if a tranformaton should be applied to the picture, for instance if the picture
		//should be rescaled when painted, as if it does not, it can use a faster drawing
		//routine
		if (intrinsicWidth != bounds.width || intrinsicHeight != bounds.height)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.translate(bounds.x, bounds.y);
			matrix.scale(bounds.width / intrinsicWidth , bounds.height / intrinsicHeight );
			
			graphicContext.nativeLayer.graphics.drawImage(nativeBitmapData, matrix, bounds, clipRect);
		}
		//here a faster drawing routine is used, the picture is drawn 
		//untransformed at a certain point
		else
		{
			var width:Float = intrinsicWidth;
			var height:Float = intrinsicHeight;
			
			//update the coordinates of the top left corner where the picture
			//will be painted
			_destinationPoint.x = bounds.x;
			_destinationPoint.y = bounds.y;
			
			//update the rectangle from the source image that will be painted
			//it is always the full picture
			bounds.width = width;
			bounds.height = height;
			bounds.x = 0.0;
			bounds.y = 0.0;
			
			graphicContext.nativeLayer.graphics.copyPixels(nativeBitmapData, bounds, _destinationPoint, clipRect);
		}
	}
	
}
