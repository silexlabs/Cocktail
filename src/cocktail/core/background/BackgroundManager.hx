/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.background;

import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.resource.ResourceManager;
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
	public static function render(backgroundBox:RectangleData, style:CoreStyle, elementRenderer:ElementRenderer):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		//no need to draw the background if it has no width or height
		if (Math.round(backgroundBox.width) <= 0 || Math.round(backgroundBox.height) <= 0 )
		{
			return nativeElements;
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
							var imageNativeElement:NativeElement = drawBackgroundImage(imageDeclaration, style, backgroundBox,
							style.backgroundPosition[i], style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i],
							style.backgroundRepeat[i], style.backgroundImage[i], elementRenderer);
							
							nativeElements.push(imageNativeElement);
						
						//same as url but multiple urls are defined, to be used as fallback, with a defined
						//fallback color if all urls are invalid
						case ImageValue.imageList(value):
							
							var imageNativeElement:NativeElement = drawBackgroundImage(value, style, backgroundBox,
							style.backgroundPosition[i], style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i],
							style.backgroundRepeat[i], style.backgroundImage[i], elementRenderer);
							
							nativeElements.push(imageNativeElement);
						
						//draw a gradient and store it	
						case ImageValue.gradient(value):
							
							var gradientNativeElement:NativeElement = drawBackgroundGradient(style, value, backgroundBox, style.backgroundPosition[i],
							style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i], style.backgroundRepeat[i], style.backgroundImage[i]);

							nativeElements.push(gradientNativeElement);
					}
			}
			
			//when the last of the background image property is rendered, render
			//the background color which use the same property as the last background image
			if (i == length - 1)
			{
				if (style.backgroundColor != BackgroundColor.transparent)
				{
					var backgroundColorNativeElement:NativeElement = drawBackgroundColor(style, style.computedStyle.backgroundColor, backgroundBox, style.backgroundPosition[i],
					style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i], style.backgroundRepeat[i], style.backgroundImage[i]);

					//at this point the array contain only background image, reverse the array
					//so that the background image declared first is on top of all the other
					//background image
					nativeElements.reverse();
					
					//then insert the background color so that it is under all the 
					//background image
					nativeElements.unshift(backgroundColorNativeElement);
				}
			}
		}
		
		return nativeElements;
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
	private static function drawBackgroundImage(imageDeclaration:ImageDeclarationData, style:CoreStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPosition, backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin,
	backgroundClip:BackgroundClip, backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage, elementRenderer:ElementRenderer):NativeElement
	{
		var backgroundImageDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(
		backgroundBox);
		
		var backgroundImageNativeElement:NativeElement = backgroundImageDrawingManager.nativeElement;
		
		var foundResource:Bool = false;
		
		for (i in 0...imageDeclaration.urls.length)
		{
			var resource:Resource = ResourceManager.getResource(imageDeclaration.urls[i]);
			
			if (resource.loaded == true)
			{
					var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
					style, backgroundBox, resource.intrinsicWidth, resource.intrinsicHeight, resource.intrinsicRatio, backgroundPosition,
					backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
					
					#if (flash9 || nme)
					var bitmap:flash.display.Bitmap = new flash.display.Bitmap(resource.nativeResource,  flash.display.PixelSnapping.AUTO, true);
					
					backgroundImageDrawingManager.drawBackgroundImage(
					bitmap, resource,
					computedGradientStyles.backgroundOrigin,
					computedGradientStyles.backgroundClip,
					resource.intrinsicWidth,
					resource.intrinsicHeight,
					resource.intrinsicRatio,
					computedGradientStyles.backgroundSize,
					computedGradientStyles.backgroundPosition,
					computedGradientStyles.backgroundRepeat);
					#end
					
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
			var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
			
			var backgroundColor:ColorData = UnitManager.getColorDataFromCSSColor(imageDeclaration.fallbackColor);
			
			var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundBox);
			backgroundColorDrawingManager.drawBackgroundColor(backgroundColor, computedBackgroundStyles.backgroundClip);
			
			backgroundImageNativeElement = backgroundColorDrawingManager.nativeElement;
		}
		
		return backgroundImageNativeElement;
	}
	
	/**
	 * Draw a background color layer on the provided nativeElement
	 * 
	 * @param	style
	 * @param	backgroundColor
	 * @param	backgroundColorNativeElement
	 * @param	backgroundBox
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 */
	private static function drawBackgroundColor(style:CoreStyle, backgroundColor:ColorData, backgroundBox:RectangleData, backgroundPosition:BackgroundPosition,
	backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin, backgroundClip:BackgroundClip, 
	backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):NativeElement
	{
		var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);

		var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor, computedBackgroundStyles.backgroundClip);
		
		return backgroundColorDrawingManager.nativeElement;
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
	private static function drawBackgroundGradient(style:CoreStyle, gradientValue:GradientValue, backgroundBox:RectangleData, backgroundPosition:BackgroundPosition,
	backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin, backgroundClip:BackgroundClip,
	backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):NativeElement
	{
		var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
		
			var backgroundGradientDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(
			backgroundBox );
			backgroundGradientDrawingManager.drawBackgroundGradient(
			gradientValue,
			computedGradientStyles.backgroundOrigin,
			computedGradientStyles.backgroundClip,
			computedGradientStyles.backgroundSize,
			computedGradientStyles.backgroundPosition, 
			computedGradientStyles.backgroundRepeat);
			
		return backgroundGradientDrawingManager.nativeElement;
	}
	
}