/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.background;

import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.geom.Matrix;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.resource.ResourceManager;
import cocktail.port.DrawingManager;
import cocktail.port.GraphicsContext;
import cocktail.port.Resource;
import cocktail.port.NativeElement;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitData;
import cocktail.core.geom.GeomData;
import cocktail.core.resource.ImageLoader;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.unit.UnitManager;
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
	public static function render(graphicContext:GraphicsContext, backgroundBox:RectangleData, style:CoreStyle, elementRenderer:ElementRenderer):Void
	{
		//no need to draw the background if it has no width or height
		if (Math.round(backgroundBox.width) <= 0 || Math.round(backgroundBox.height) <= 0 )
		{
			return ;
		}
		
		if (style.backgroundColor != BackgroundColor.transparent)
		{
			graphicContext.fillRect(backgroundBox, style.computedStyle.backgroundColor);
		}
		
		//loop in all the background images style of the HTMLElement. It is expected
		//that each array of background styles (such as background origin, background size...)
		//has the same length
		var length:Int = style.backgroundImage.length;
		for (i in 0...length)
		{
			switch (style.backgroundImage[i])
			{
				//don't render anything in that case
				case BackgroundImage.none:
				
				case BackgroundImage.image(value):
					
					switch (value)
					{
						//the background image is loaded from an external url
						case ImageValue.url(value):
							
							//wrapped in an image declaration so that in can be treated the same
							//way than a list of urls
							var imageDeclaration:ImageDeclarationData = {
								urls:[value],
								fallbackColor:Color.transparent
							}
							
							//draw the background image and store the resulting nativeElement
							drawBackgroundImage(graphicContext, imageDeclaration, style, backgroundBox,
							style.backgroundPosition[i], style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i],
							style.backgroundRepeat[i], style.backgroundImage[i], elementRenderer);
						
						//same as url but multiple urls are defined, to be used as fallback, with a defined
						//fallback color if all urls are invalid
						case ImageValue.imageList(value):
							
							drawBackgroundImage(graphicContext, value, style, backgroundBox,
							style.backgroundPosition[i], style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i],
							style.backgroundRepeat[i], style.backgroundImage[i], elementRenderer);
						
						//draw a gradient and store it	
						case ImageValue.gradient(value):
							
							drawBackgroundGradient(graphicContext, style, value, backgroundBox, style.backgroundPosition[i],
							style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i], style.backgroundRepeat[i], style.backgroundImage[i]);
					}
			}
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
	private static function drawBackgroundImage(graphicContext:GraphicsContext, imageDeclaration:ImageDeclarationData, style:CoreStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPosition, backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin,
	backgroundClip:BackgroundClip, backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage, elementRenderer:ElementRenderer):Void
	{
		var foundResource:Bool = false;
		
		for (i in 0...imageDeclaration.urls.length)
		{
			var resource:Resource = ResourceManager.getResource(imageDeclaration.urls[i]);
			
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
					computedGradientStyles.backgroundRepeat);
					
				foundResource = true;	
				break;
			}
			else if (resource.loadedWithError == false)
			{
				resource.addEventListener(UIEvent.LOAD, function(e) {
					elementRenderer.invalidate(InvalidationReason.backgroundImageLoaded);
				});
				
				resource.addEventListener(UIEvent.ERROR, function(e) {
					elementRenderer.invalidate(InvalidationReason.backgroundImageLoaded);
				});
				
				foundResource = true;
				break;
			}
		}
		
		
		if (foundResource == false)
		{
			
			var backgroundColor:ColorData = UnitManager.getColorDataFromCSSColor(imageDeclaration.fallbackColor);
			graphicContext.fillRect(backgroundBox, backgroundColor);
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
	public static function doDrawBackgroundImage(backgroundBox:RectangleData, graphicContext:GraphicsContext, resource:Resource,
	backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData, intrinsicWidth:Float,
	intrinsicHeight:Float, intrinsicRatio:Float, computedBackgroundSize:DimensionData,
	computedBackgroundPosition:PointData, backgroundRepeat:BackgroundRepeat):Void
	{	
		var totalWidth:Float = computedBackgroundPosition.x + backgroundPositioningBox.x;
		var maxWidth:Float =  backgroundPaintingBox.x + backgroundPaintingBox.width;
		var imageWidth:Float = computedBackgroundSize.width;
		
		switch (backgroundRepeat.x)
		{
			case BackgroundRepeatValue.noRepeat:
				maxWidth = totalWidth + imageWidth;
				
			case BackgroundRepeatValue.repeat:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case BackgroundRepeatValue.space:
				imageWidth = Math.round(backgroundPositioningBox.width / computedBackgroundSize.width);
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				
			case BackgroundRepeatValue.round:
				while (totalWidth > backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
		}
		var initialWidth:Float = totalWidth;
		
		var totalHeight:Float = computedBackgroundPosition.y + Math.round(backgroundPositioningBox.y);
		var maxHeight:Float = backgroundPaintingBox.y + backgroundPaintingBox.height;
		var imageHeight:Float = computedBackgroundSize.height;
		
		switch (backgroundRepeat.y)
		{
			case BackgroundRepeatValue.noRepeat:
				maxHeight = totalHeight + imageHeight;
				
			case BackgroundRepeatValue.repeat:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case BackgroundRepeatValue.space:
				imageHeight = backgroundPositioningBox.height / computedBackgroundSize.height;
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				
			case BackgroundRepeatValue.round:
				while (totalHeight > backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
		}
		
		var initialHeight:Float = totalHeight;
		//TODO 3 : doc + separate in 2 methods
		if ((imageWidth / intrinsicWidth == 1) && (imageHeight / intrinsicHeight == 1))
		{
			var destinationPoint:PointData = {
				x:totalWidth + backgroundBox.x,
				y:totalHeight + backgroundBox.y
			}
			
			var intWidth:Float = intrinsicWidth;
			var intHeight:Float = intrinsicHeight;
			
			var box:RectangleData = {
				x:0.0,
				y:0.0,
				width:intWidth,
				height:intHeight
			}
			
			while (totalHeight < maxHeight)
			{
				graphicContext.copyPixels(resource.nativeResource, box, destinationPoint );
				
				totalWidth += imageWidth;
				
				if (totalWidth >= maxWidth)
				{
					totalWidth = initialWidth;
					totalHeight += imageHeight;
				}
				
				destinationPoint.x = totalWidth + backgroundBox.x;
				destinationPoint.y = totalHeight + backgroundBox.y;
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
				
				graphicContext.drawImage(resource.nativeResource, matrix, backgroundPaintingBox);
				
				totalWidth += imageWidth;
				
				if (totalWidth >= maxWidth)
				{
					totalWidth = initialWidth;
					totalHeight += imageHeight;
				}
			}
		}
	}
	
	/**
	 * Draw a gradient on a nativeElement and returns it
	 * 
	 * @param	style
	 * @param	gradientValue
	 * @param	backgroundBox
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 * @return
	 */
	private static function drawBackgroundGradient(graphicContext:GraphicsContext, style:CoreStyle, gradientValue:GradientValue, backgroundBox:RectangleData, backgroundPosition:BackgroundPosition,
	backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin, backgroundClip:BackgroundClip,
	backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):Void
	{
		var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
		
		
			
	}
	
}