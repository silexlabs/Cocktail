/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.background;

import cocktail.core.NativeElement;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitData;
import cocktail.core.geom.GeomData;
import cocktail.core.resource.ImageLoader;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.unit.UnitManager;
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
 * @author Yannick DOMINGUEZ
 */
class BackgroundManager 
{
	/**
	 * an array of each of the background managers instantiated by this class.
	 * One background drawing manager must be instantiated for each layer of background.
	 * for instance, for a HTMLElement with a background color and one background image,
	 * 2 background drawing manager will be instantiated and stored
	 */
	private var _backgroundDrawingManagers:Array<BackgroundDrawingManager>;
	
	/**
	 * class constructor. init class atribute
	 */
	public function new()
	{
		_backgroundDrawingManagers = new Array<BackgroundDrawingManager>();
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
	public function render(backgroundBox:RectangleData, style:CoreStyle):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		//no need to draw the background if it has no width or height
		if (backgroundBox.width <= 0 || backgroundBox.height <= 0)
		{
			return nativeElements;
		}
		
		//loop in all the background images style of the HTMLElement. It is expected
		//that each array of background styles (such as background origin, background size...)
		//has the same length
		for (i in 0...style.backgroundImage.length)
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
							style.backgroundRepeat[i], style.backgroundImage[i]);
							
							nativeElements.push(imageNativeElement);
						
						//same as url but multiple urls are defined, to be used as fallback, with a defined
						//fallback color if all urls are invalid
						case ImageValue.imageList(value):
							
							var imageNativeElement:NativeElement = drawBackgroundImage(value, style, backgroundBox,
							style.backgroundPosition[i], style.backgroundSize[i], style.backgroundOrigin[i], style.backgroundClip[i],
							style.backgroundRepeat[i], style.backgroundImage[i]);
							
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
			if (i == style.backgroundImage.length - 1)
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
	private function drawBackgroundImage(imageDeclaration:ImageDeclarationData, style:CoreStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPosition, backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin,
	backgroundClip:BackgroundClip, backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):NativeElement
	{
		
		var imageLoader:ImageLoader = new ImageLoader();
		
		var backgroundImageDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(
		backgroundBox);
		
		var backgroundImageNativeElement:NativeElement = backgroundImageDrawingManager.nativeElement;
		
		//TODO : should retrieve image if already loaded, else start loading and call an invalidate() method when it is in fact loaded
		var onBackgroundImageLoadedDelegate:BackgroundDrawingManager->NativeElement->ImageLoader->CoreStyle->RectangleData->BackgroundPosition->
		BackgroundSize->BackgroundOrigin-> BackgroundClip-> BackgroundRepeat->
		BackgroundImage->Void = onBackgroundImageLoaded;
		
		var onBackgroundImageLoadErrorDelegate:String->Color->NativeElement->CoreStyle->RectangleData->BackgroundPosition->
		BackgroundSize->BackgroundOrigin-> BackgroundClip-> BackgroundRepeat->
		BackgroundImage->Void = onBackgroundImageLoadError;
		
		//try to load the picture, and set the callbacks
		imageLoader.load(imageDeclaration.urls,
		function(loadedImage:NativeElement) {
			onBackgroundImageLoadedDelegate(backgroundImageDrawingManager, loadedImage, imageLoader, style, backgroundBox, backgroundPosition, backgroundSize, 
			backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
		}, function(error:String) {
			onBackgroundImageLoadErrorDelegate(error, imageDeclaration.fallbackColor, backgroundImageNativeElement, style, backgroundBox, backgroundPosition, backgroundSize, 
		backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
		});
		
		return backgroundImageNativeElement;
	}
	
	/**
	 * Called when the bitmap was successfully loaded. Draw
	 * the loaded bitmap onto a nativeElement
	 * 
	 * @param	backgroundImageNativeElement
	 * @param	loadedBackgroundImage
	 * @param	imageLoader
	 * @param	style
	 * @param	backgroundBox
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 */
	private function onBackgroundImageLoaded(backgroundImageDrawingManager:BackgroundDrawingManager, loadedBackgroundImage:NativeElement, imageLoader:ImageLoader, style:CoreStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPosition, backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin,
	backgroundClip:BackgroundClip, backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):Void
	{
			var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, imageLoader.intrinsicWidth, imageLoader.intrinsicHeight, imageLoader.intrinsicRatio, backgroundPosition,
			backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
			
			
			
			backgroundImageDrawingManager.drawBackgroundImage(
			loadedBackgroundImage, 
			getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),
			getBackgroundPaintingBox(computedGradientStyles.backgroundClip),
			imageLoader.intrinsicWidth,
			imageLoader.intrinsicHeight,
			imageLoader.intrinsicRatio,
			computedGradientStyles.backgroundSize,
			computedGradientStyles.backgroundPosition,
			computedGradientStyles.backgroundRepeat);
			
			_backgroundDrawingManagers.push(backgroundImageDrawingManager);
	}
	
	/**
	 * When the external bitmap can't be loaded, draw a fallback background color
	 * layer
	 * 
	 * @param	error
	 * @param	backgroundColor
	 * @param	backgroundImageNativeElement
	 * @param	style
	 * @param	backgroundBox
	 * @param	backgroundPosition
	 * @param	backgroundSize
	 * @param	backgroundOrigin
	 * @param	backgroundClip
	 * @param	backgroundRepeat
	 * @param	backgroundImage
	 */
	private function onBackgroundImageLoadError(error:String, backgroundColor:CSSColor, backgroundImageNativeElement:NativeElement, style:CoreStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPosition, backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin,
	backgroundClip:BackgroundClip, backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):Void
	{
		//TODO : re-implement
		/**drawBackgroundColor(style, UnitManager.getColorDataFromCSSColor(backgroundColor), backgroundImageNativeElement, backgroundBox, backgroundPosition,
				backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);*/
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
	private function drawBackgroundColor(style:CoreStyle, backgroundColor:ColorData, backgroundBox:RectangleData, backgroundPosition:BackgroundPosition,
	backgroundSize:BackgroundSize, backgroundOrigin:BackgroundOrigin, backgroundClip:BackgroundClip, 
	backgroundRepeat:BackgroundRepeat, backgroundImage:BackgroundImage):NativeElement
	{
		var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
			
		var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(
		backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor, getBackgroundPaintingBox(computedBackgroundStyles.backgroundClip));

		_backgroundDrawingManagers.push(backgroundColorDrawingManager);
		
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
	private function drawBackgroundGradient(style:CoreStyle, gradientValue:GradientValue, backgroundBox:RectangleData, backgroundPosition:BackgroundPosition,
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
			getBackgroundPositioningBox(computedGradientStyles.backgroundOrigin),
			getBackgroundPaintingBox(computedGradientStyles.backgroundClip),
			computedGradientStyles.backgroundSize,
			computedGradientStyles.backgroundPosition, 
			computedGradientStyles.backgroundRepeat);
			
		return backgroundGradientDrawingManager.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the right painting box. Used as a hook
	 * to be overriden
	 */
	private function getBackgroundPaintingBox(computedBackgroundBox:RectangleData):RectangleData
	{
		return computedBackgroundBox;
	}
	
	/**
	 * return the right positioning box. Used as a hook
	 * to be overriden
	 */
	private function getBackgroundPositioningBox(computedPositioningBox:RectangleData):RectangleData
	{
		return computedPositioningBox;
	}
	
}