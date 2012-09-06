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
import cocktail.core.geom.Matrix;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.css.CSSData;
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
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * When rendered, renders the embedded picture using the
	 * graphicContext as canvas
	 */
	override private function renderEmbeddedAsset(graphicContext:GraphicsContext):Void
	{
		var resource:AbstractResource = ResourceManager.getImageResource(domNode.getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME));

		//don't paint anything is the image is not loaded or there was an error
		//while loading
		if (resource.loaded == false || resource.loadedWithError == true)
		{
			return;
		}
		
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		
		var x:Float = globalBounds.x + usedValues.paddingLeft - scrollOffset.x;
		var y:Float = globalBounds.y + usedValues.paddingTop - scrollOffset.y;
		var width:Float = usedValues.width;
		var height:Float = usedValues.height;
		var paintBounds:RectangleVO = new RectangleVO(x, y, width, height);
		
		paintResource(graphicContext, resource.nativeResource, paintBounds, resource.intrinsicWidth, resource.intrinsicHeight);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually paint the resource's bitmap data on the graphic context.
	 */
	private function paintResource(graphicContext:GraphicsContext, nativeBitmapData:NativeBitmapData, bounds:RectangleVO, intrinsicWidth:Float, intrinsicHeight:Float):Void
	{
		//check if a tranformaton should be applied to the picture, for instance if the picture
		//should be rescaled when painted, as if it does not, it can use a faster drawing
		//routine
		if (intrinsicWidth != bounds.width || intrinsicHeight != bounds.height)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.translate(bounds.x, bounds.y);
			matrix.scale(bounds.width / intrinsicWidth , bounds.height / intrinsicHeight );
		
			var sourceRect:RectangleVO = new RectangleVO(bounds.x, bounds.y, bounds.width, bounds.height);
			
			graphicContext.drawImage(nativeBitmapData, matrix, sourceRect);
		}
		//here a faster drawing routine is used, the picture is drawn 
		//untransformed at a certain point
		else
		{
			var width:Float = intrinsicWidth;
			var height:Float = intrinsicHeight;
			
			//the rectangle from the source image that will be painted
			//it is always the full picture
			var sourceRect:RectangleVO = new RectangleVO(0.0, 0.0, width, height);
			
			//the coordinates of the top left corner where the picture
			//will be painted
			var destPoint:PointVO = new PointVO(bounds.x, bounds.y);
			
			graphicContext.copyPixels(nativeBitmapData, sourceRect, destPoint);
		}
	}
	
}