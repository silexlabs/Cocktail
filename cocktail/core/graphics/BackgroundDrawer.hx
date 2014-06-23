/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.graphics;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.geom.GeomUtils;
import cocktail.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.base.ResourceBase;
import cocktail.port.Bindings;
import cocktail.core.layout.LayoutData;
import cocktail.geom.GeomData;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.computer.BackgroundStylesComputer;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.parser.ParserData;
import cocktail.css.CSSStyleData;

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
class BackgroundDrawer
{
	/**
	 * Represents the background box, reused
	 * for each background
	 */
	private static var _box:RectangleVO = new RectangleVO();
	
	/**
	 * Same as above for destination point
	 */
	private static var _destinationPoint:PointVO = new PointVO(0.0, 0.0);
	
	/**
	 * Those bounds are used to determine if the painted background
	 * intersect with the clip rect, if it doesn't it won't
	 * be displayed on screen
	 */
	private static var _intersectionBounds:RectangleVO = new RectangleVO();
	
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
			_intersectionBounds.x = backgroundBox.x;
			_intersectionBounds.y = backgroundBox.y;
			_intersectionBounds.width = backgroundBox.width;
			_intersectionBounds.height = backgroundBox.height;
			
			//determine wether the background box intersect with the clipped rect
			GeomUtils.intersectBounds(_intersectionBounds, clipRect, _intersectionBounds);
			if (_intersectionBounds.width == 0 || _intersectionBounds.height == 0)
			{
				return;
			}
			
			graphicContext.nativeLayer.graphics.fillRect(backgroundBox, style.usedValues.backgroundColor, clipRect);
		}
		//if the element has no background image to draw,
		//early return
		if (style.hasBackgroundImage == false)
		{
			return;
		}
		
		_intersectionBounds.x = backgroundBox.x;
		_intersectionBounds.y = backgroundBox.y;
		_intersectionBounds.width = backgroundBox.width;
		_intersectionBounds.height = backgroundBox.height;
		
		//determine wether the background box intersect with the clipped rect
		GeomUtils.intersectBounds(_intersectionBounds, clipRect, _intersectionBounds);
		if (_intersectionBounds.width == 0 || _intersectionBounds.height == 0)
		{
			return;
		}
		
		var backgroundImages:Array<CSSPropertyValue> = getAsArray(style.backgroundImage);
		
		var backgroundPositions:Array<CSSPropertyValue> = getAsArray(style.backgroundPosition);
		
		var backgroundOrigins:Array<CSSPropertyValue> = getAsArray(style.backgroundOrigin);
		var backgroundClips:Array<CSSPropertyValue> = getAsArray(style.backgroundClip);
		var backgroundSizes:Array<CSSPropertyValue> = getAsArray(style.backgroundSize);
		var backgroundRepeats:Array<CSSPropertyValue> = getAsArray(style.backgroundRepeat);

		//loop in all the background images style of the HTMLElement. Loop in reverse order, first
		//declarted image should appear on top
		var i:Int = backgroundImages.length - 1;
		while(i >= 0)
		{
			var backgroundImage:CSSPropertyValue = backgroundImages[i];
			switch (backgroundImage)
			{
				case KEYWORD(value):
				
				case URL(value):
					drawBackgroundImage(graphicContext, value, style, backgroundBox,
					backgroundPositions[getRepeatedIndex(i, backgroundPositions.length)],
					backgroundSizes[getRepeatedIndex(i, backgroundSizes.length)],
					backgroundOrigins[getRepeatedIndex(i, backgroundOrigins.length)],
					backgroundClips[getRepeatedIndex(i, backgroundClips.length)],
					backgroundRepeats[getRepeatedIndex(i, backgroundRepeats.length)], 
					backgroundImages[i], 
					elementRenderer, clipRect);
					
				default:	
			}
			
			i--;
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
				
			case CSS_LIST(value):
				var arr:Array<CSSPropertyValue> = [];
				for (i in 0...value.length)
				{
					arr.push(value[i]);
				}
				return arr;
				
			default:
				return null;
		}
	}
	
	/**
	 * Utils method, which return, given
	 * an index and the length of an array, the 
	 * actual index to use by looping in the length
	 * if the length is inferior to the index
	 * 
	 * @example if the length is 2 and the index is 3,
	 * the returned index will be 0, as by looping in the length,
	 * the index will be 0,1,0
	 */
	private static function getRepeatedIndex(index:Int, length:Int):Int
	{
		if (index < length)
		{
			return index;
		}
		else if (length == 1)
		{
			return 0;
		}
		
		//TODO : probably wrong
		return length % index;
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
		
		var htmlDocument:HTMLDocument = cast(elementRenderer.domNode.ownerDocument);
		var resource:ResourceBase = htmlDocument.resourceManager.getImageResource(url);
		
		if (resource.loaded == true)
		{
				_intersectionBounds.x = backgroundBox.x;
				_intersectionBounds.y = backgroundBox.y;
				_intersectionBounds.width = backgroundBox.width;
				_intersectionBounds.height = backgroundBox.height;
		
				//determine the clip rect for the background image, which is the intersection
				//between the bounds of the element and its clip rect
				//
				//TODO 2 : can use hit testing bounds instead ?
				GeomUtils.intersectBounds(_intersectionBounds, clipRect, _intersectionBounds);
			
				var computedGradientStyles:ComputedBackgroundStyleVO = BackgroundStylesComputer.computeIndividualBackground(
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
				computedGradientStyles.backgroundRepeat, _intersectionBounds);
				
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
	public static function doDrawBackgroundImage(backgroundBox:RectangleVO, graphicContext:GraphicsContext, resource:ResourceBase,
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
			_destinationPoint.x = totalWidth + backgroundBox.x - computedBackgroundPosition.x;
			_destinationPoint.y = totalHeight + backgroundBox.y - computedBackgroundPosition.y;
				
			var intWidth:Float = intrinsicWidth;
			var intHeight:Float = intrinsicHeight;
			
			_box.x = backgroundPaintingBox.x - computedBackgroundPosition.x;
			_box.y = backgroundPaintingBox.y - computedBackgroundPosition.y;
			_box.width = backgroundPaintingBox.width;
			_box.height = backgroundPaintingBox.height;
			
			while (totalHeight < maxHeight)
			{
				graphicContext.nativeLayer.graphics.copyPixels(resource.nativeResource, _box, _destinationPoint, clipRect );
				
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
			
			backgroundPaintingBox.x += backgroundBox.x + computedBackgroundPosition.x;
			backgroundPaintingBox.y += backgroundBox.y + computedBackgroundPosition.y;
			
			while (totalHeight < maxHeight)
			{
				
				matrix.identity();
				
				matrix.translate(totalWidth+backgroundBox.x, totalHeight+backgroundBox.y);
				
				matrix.scale(imageWidth / intrinsicWidth ,  imageHeight / intrinsicHeight);
				
				graphicContext.nativeLayer.graphics.drawImage(resource.nativeResource, matrix, backgroundPaintingBox, clipRect);
				
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
