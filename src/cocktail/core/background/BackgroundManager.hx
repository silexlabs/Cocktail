/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.background;

import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.UIEvent;
import cocktail.core.geom.Matrix;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.ImageResource;
import cocktail.port.NativeElement;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.computer.BackgroundStylesComputer;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.css.CSSData;
import cocktail.core.renderer.RendererData;
import haxe.Log;

/**
 * This class manages the instantation and drawing of the
 * background "layers" of a HTMLElement. A HTMLElement can have
 * one background color, and one or more background images
 * which can either be external bitmaps or programmatically
 * drawn gradients. 
 * 
 * This class renders and return all those backgrounds elements
 * 
 * TODO 1 : way too complicated, too many parameters in functions
 * 
 * @author Yannick DOMINGUEZ
 */
class BackgroundManager 
{
	/**
	 * Represents the background box, reused
	 * for each background
	 */
	private static var _box:RectangleVO;
	
	/**
	 * Same as above for destination point
	 */
	private static var _destinationPoint:PointVO;
	
	/**
	 * class constructor.
	 */
	private function new()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the different layers of the background of a HTMLElement using the backgroundBox
	 * dimensions for each layer, then return an array containing each of the rendered layer.
	 * 
	 * It is called for each rendered box of a HTMLElement. For instance, an inline level container HTMLElement
	 * can be split into multiple line. This method will be called for each line
	 * 
	 * @param	backgroundBox the dimensions and position of a box of a HTMLElement
	 * @param	style
	 * @return
	 */
	public static function render(graphicContext:GraphicsContext, backgroundBox:RectangleVO, style:CoreStyle, elementRenderer:ElementRenderer, clipRect:RectangleVO):Void
	{
		//no need to draw the background if it has no width or height
		if (Math.round(backgroundBox.width) <= 0 || Math.round(backgroundBox.height) <= 0 )
		{
			return ;
		}
		
		//no need to draw a background color if it is
		//completely transparent
		if (style.usedValues.backgroundColor.alpha != 0.0)
		{
			graphicContext.graphics.fillRect(backgroundBox, style.usedValues.backgroundColor, clipRect);
		}
		
		var backgroundImages:Array<CSSPropertyValue> = getAsArray(style.backgroundImage);
		
		var backgroundPositions:Array<CSSPropertyValue> = getAsArray(style.backgroundPosition);
		
		var backgroundOrigins:Array<CSSPropertyValue> = getAsArray(style.backgroundOrigin);
		var backgroundClips:Array<CSSPropertyValue> = getAsArray(style.backgroundClip);
		var backgroundSizes:Array<CSSPropertyValue> = getAsArray(style.backgroundSize);
		var backgroundRepeats:Array<CSSPropertyValue> = getAsArray(style.backgroundRepeat);

		
		//loop in all the background images style of the HTMLElement. It is expected
		//that each array of background styles (such as background origin, background size...)
		//has the same length
		var length:Int = backgroundImages.length;
		for (i in 0...length)
		{
			var backgroundImage:CSSPropertyValue = backgroundImages[i];
			switch (backgroundImage)
			{
				case KEYWORD(value):
				
				case URL(value):
					drawBackgroundImage(graphicContext, value, style, backgroundBox,
					backgroundPositions[i], backgroundSizes[i], backgroundOrigins[i], backgroundClips[i],
					backgroundRepeats[i], backgroundImages[i], elementRenderer, clipRect);
					
				default:	
			}
		}
		
	}
	
	private static function getAsArray(cssProperty:CSSPropertyValue):Array<CSSPropertyValue>
	{
		switch (cssProperty)
		{
			case KEYWORD(value):
				return [cssProperty];
			
			case LENGTH(value):
				return [cssProperty];
				
			case PERCENTAGE(value):
				return [cssProperty];
				
			case GROUP(value):	
				return [cssProperty];
				
			case URL(value):
				return [cssProperty];
				
			default:
				return null;
		}
	}
		
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw an external bitmap onto a nativeElement and returns it. The external bitmap is 
	 * first loaded, then on load complete, it is drawn on the nativeElement using the
	 * corresponding background styles, such as background repeat.
	 * 
	 * If the external bitmap can't be loaded, a fallback background color is drawn instead
	 * 
	 * 
	 * @param	imageDeclaration
	 * @param	style
	 * @param	backgroundBox
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 * @return
	 */
	private static function drawBackgroundImage(graphicContext:GraphicsContext, url:String, style:CoreStyle, backgroundBox:RectangleVO,
	backgroundPosition:CSSPropertyValue, backgroundSize:CSSPropertyValue, backgroundOrigin:CSSPropertyValue,
	backgroundClip:CSSPropertyValue, backgroundRepeat:CSSPropertyValue, backgroundImage:CSSPropertyValue, elementRenderer:ElementRenderer, clipRect:RectangleVO):Void
	{
		var foundResource:Bool = false;
		
		var resource:AbstractResource = ResourceManager.getImageResource(url);
		
		if (resource.loaded == true)
		{
				var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
				style, backgroundBox, resource.intrinsicWidth, resource.intrinsicHeight, resource.intrinsicRatio, backgroundPosition,
				backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
				
				doDrawBackgroundImage(
				backgroundBox,
				graphicContext,
				resource,
				computedGradientStyles.backgroundOrigin,
				computedGradientStyles.backgroundClip,
				resource.intrinsicWidth,
				resource.intrinsicHeight,
				resource.intrinsicRatio,
				computedGradientStyles.backgroundSize,
				computedGradientStyles.backgroundPosition,
				computedGradientStyles.backgroundRepeat, clipRect);
				
			foundResource = true;
		}
		else if (resource.loadedWithError == false)
		{
			resource.addEventListener(EventConstants.LOAD, function(e) {
				elementRenderer.invalidateRendering();
			});
			
			resource.addEventListener(EventConstants.ERROR, function(e) {
				elementRenderer.invalidateRendering();
			});
			
			foundResource = true;
		}
		
		
		if (foundResource == false)
		{
			//TODO 1 : re-implement fallback color
			//var backgroundColor:ColorVO = CSSValueConverter.getColorVOFromCSSColor(imageDeclaration.fallbackColor);
			//graphicContext.fillRect(backgroundBox, backgroundColor);
		}

	}
	
	/**
	 * Draw a background image form a nativeImage source.
	 * The nativeImage source is repeated and transformed
	 * as necessary to match the computed background
	 * styles
	 * 
	 * @param	nativeImage
	 * @param	backgroundPositioningBox
	 * @param	backgroundPaintingBox
	 * @param	intrinsicWidth
	 * @param	intrinsicHeight
	 * @param	intrinsicRatio
	 * @param	computedBackgroundSize
	 * @param	computedBackgroundPosition
	 * @param	backgroundRepeat
	 */
	public static function doDrawBackgroundImage(backgroundBox:RectangleVO, graphicContext:GraphicsContext, resource:AbstractResource,
	backgroundPositioningBox:RectangleVO, backgroundPaintingBox:RectangleVO, intrinsicWidth:Float,
	intrinsicHeight:Float, intrinsicRatio:Float, computedBackgroundSize:DimensionVO,
	computedBackgroundPosition:PointVO, backgroundRepeat:CSSPropertyValue, clipRect:RectangleVO):Void
	{	

		var backgroundRepeatX:CSSKeywordValue =  null;
		var backgroundRepeatY:CSSKeywordValue = null;
		
		switch(backgroundRepeat)
		{
			case GROUP(value):
				switch(value[0])
				{
					case KEYWORD(value):
						backgroundRepeatX = value;
						
					default:	
				}
				
				switch(value[1])
				{
					case KEYWORD(value):
						backgroundRepeatY = value;
						
					default:	
				}
			
			default:
		}
		
		var totalWidth:Float = computedBackgroundPosition.x + backgroundPositioningBox.x;
		var maxWidth:Float =  backgroundPaintingBox.x + backgroundPaintingBox.width;
		var imageWidth:Float = computedBackgroundSize.width;
		
		switch (backgroundRepeatX)
		{
			case NO_REPEAT:
				maxWidth = totalWidth + imageWidth;
				
			case REPEAT:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case SPACE:
				imageWidth = Math.round(backgroundPositioningBox.width / computedBackgroundSize.width);
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case ROUND:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			default:	
		}
		var initialWidth:Float = totalWidth;
		
		var totalHeight:Float = computedBackgroundPosition.y + Math.round(backgroundPositioningBox.y);
		var maxHeight:Float = backgroundPaintingBox.y + backgroundPaintingBox.height;
		var imageHeight:Float = computedBackgroundSize.height;
		
		switch (backgroundRepeatY)
		{
			case NO_REPEAT:
				maxHeight = totalHeight + imageHeight;
				
			case REPEAT:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case SPACE:
				imageHeight = backgroundPositioningBox.height / computedBackgroundSize.height;
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case ROUND:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			default:	
		}
		
		var initialHeight:Float = totalHeight;
		//TODO 3 : doc + separate in 2 methods
		if ((imageWidth / intrinsicWidth == 1) && (imageHeight / intrinsicHeight == 1))
		{
			if (_destinationPoint == null)
			{
				_destinationPoint = new PointVO(0.0, 0.0);
			}
			
			_destinationPoint.x = totalWidth + backgroundBox.x - computedBackgroundPosition.x;
			_destinationPoint.y = totalHeight + backgroundBox.y - computedBackgroundPosition.y;
				
			var intWidth:Float = intrinsicWidth;
			var intHeight:Float = intrinsicHeight;
			
			if (_box == null)
			{
				_box = new RectangleVO();
			}
			
			_box.x = backgroundPaintingBox.x - computedBackgroundPosition.x;
			_box.y = backgroundPaintingBox.y - computedBackgroundPosition.y;
			_box.width = backgroundPaintingBox.width;
			_box.height = backgroundPaintingBox.height;
			
			while (totalHeight < maxHeight)
			{
				graphicContext.graphics.copyPixels(resource.nativeResource, _box, _destinationPoint, clipRect );
				
				totalWidth += imageWidth;
				
				if (totalWidth >= maxWidth)
				{
					totalWidth = initialWidth;
					totalHeight += imageHeight;
				}
				
				_destinationPoint.x = totalWidth + backgroundBox.x - computedBackgroundPosition.x;
				_destinationPoint.y = totalHeight + backgroundBox.y - computedBackgroundPosition.y;
			}
		}
		else
		{
			var matrix:Matrix = new Matrix();
			
			backgroundPaintingBox.x += backgroundBox.x;
			backgroundPaintingBox.y += backgroundBox.y;

			while (totalHeight < maxHeight)
			{
				
				matrix.identity();
				
				matrix.translate(totalWidth+backgroundBox.x, totalHeight+backgroundBox.y);
				
				matrix.scale(imageWidth / intrinsicWidth ,  imageHeight / intrinsicHeight);
				
				graphicContext.graphics.drawImage(resource.nativeResource, matrix, backgroundPaintingBox, clipRect);
				
				totalWidth += imageWidth;
				
				if (totalWidth >= maxWidth)
				{
					totalWidth = initialWidth;
					totalHeight += imageHeight;
				}
			}
		}
	}
}