/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.background;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktail.geom.GeomData;
import cocktailCore.resource.ImageLoader;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.computer.BackgroundStylesComputer;
import cocktailCore.unit.UnitManager;
import haxe.Log;

/**
 * This class manages the instantation and drawing of the
 * background "layers" of a DOMElement. A DOMElement can have
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
	 * Background Properties
	 */
	private var _backgroundColor:BackgroundColorStyleValue;
	public var backgroundColor(getBackgroundColor, setBackgroundColor):BackgroundColorStyleValue;
	
	private var _backgroundImage:Array<BackgroundImageStyleValue>;
	public var backgroundImage(getBackgroundImage, setBackgroundImage):Array<BackgroundImageStyleValue>;
	 
	private var _backgroundRepeat:Array<BackgroundRepeatStyleData>;
	public var backgroundRepeat(getBackgroundRepeat, setBackgroundRepeat):Array<BackgroundRepeatStyleData>;
	
	private var _backgroundOrigin:Array<BackgroundOriginStyleValue>;
	public var backgroundOrigin(getBackgroundOrigin, setBackgroundOrigin):Array<BackgroundOriginStyleValue>;
	
	private var _backgroundSize:Array<BackgroundSizeStyleValue>;
	public var backgroundSize(getBackgroundSize, setBackgroundSize):Array<BackgroundSizeStyleValue>;
	
	private var _backgroundPosition:Array<BackgroundPositionStyleData>;
	public var backgroundPosition(getBackgroundPosition, setBackgroundPosition):Array<BackgroundPositionStyleData>;
	
	private var _backgroundClip:Array<BackgroundClipStyleValue>;
	public var backgroundClip(getBackgroundClip, setBackgroundClip):Array<BackgroundClipStyleValue>;
	
	/**
	 * an array of each of the background managers instantiated by this class.
	 * One background drawing manager must be instantiated for each layer of background.
	 * for instance, for a DOMElement with a background color and one background image,
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
	 * Render the different layers of the background of a DOMElement using the backgroundBox
	 * dimensions for each layer, then return an array containing each of the rendered layer.
	 * 
	 * It is called for each rendered box of a DOMElement. For instance, an inline level container DOMElement
	 * can be split into multiple line. This method will be called for each line
	 * 
	 * @param	backgroundBox the dimensions and position of a box of a DOMElement
	 * @param	style
	 * @return
	 */
	public function render(backgroundBox:RectangleData, style:AbstractStyle):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		//no need to draw the background if it has no width or height
		if (backgroundBox.width <= 0 || backgroundBox.height <= 0)
		{
			return nativeElements;
		}
		
		//loop in all the background images style of the DOMElement. It is expected
		//that each array of background styles (such as background origin, background size...)
		//has the same length
		for (i in 0..._backgroundImage.length)
		{
			switch (_backgroundImage[i])
			{
				//don't render anything in that case
				case BackgroundImageStyleValue.none:
				
				case BackgroundImageStyleValue.image(value):
					
					switch (value)
					{
						//the background image is loaded from an external url
						case ImageValue.url(value):
							
							//wrapped in an image declaration so that in can be treated the same
							//way than a list of urls
							var imageDeclaration:ImageDeclarationData = {
								urls:[value],
								fallbackColor:ColorValue.transparent
							}
							
							//draw the background image and store the resulting nativeElement
							var imageNativeElement:NativeElement = drawBackgroundImage(imageDeclaration, style, backgroundBox,
							_backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i],
							_backgroundRepeat[i], _backgroundImage[i]);
							
							nativeElements.push(imageNativeElement);
						
						//same as url but multiple urls are defined, to be used as fallback, with a defined
						//fallback color if all urls are invalid
						case ImageValue.imageList(value):
							
							var imageNativeElement:NativeElement = drawBackgroundImage(value, style, backgroundBox,
							_backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i],
							_backgroundRepeat[i], _backgroundImage[i]);
							
							nativeElements.push(imageNativeElement);
						
						//draw a gradient and store it	
						case ImageValue.gradient(value):
							
							var gradientNativeElement:NativeElement = drawBackgroundGradient(style, value, backgroundBox, _backgroundPosition[i],
							_backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);

							nativeElements.push(gradientNativeElement);
					}
			}
			
			//when the last of the background image property is rendered, render
			//the background color which use the same property as the last background image
			if (i == _backgroundImage.length - 1)
			{
				var backgroundColorNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
				drawBackgroundColor(style, style.computedStyle.backgroundColor, backgroundColorNativeElement, backgroundBox, _backgroundPosition[i],
				_backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);
				
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
	private function drawBackgroundImage(imageDeclaration:ImageDeclarationData, style:AbstractStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPositionStyleData, backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue,
	backgroundClip:BackgroundClipStyleValue, backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):NativeElement
	{
		var backgroundImageNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
		
		var imageLoader:ImageLoader = new ImageLoader();
		
		var onBackgroundImageLoadedDelegate:NativeElement->NativeElement->ImageLoader->AbstractStyle->RectangleData->BackgroundPositionStyleData->
		BackgroundSizeStyleValue->BackgroundOriginStyleValue-> BackgroundClipStyleValue-> BackgroundRepeatStyleData->
		BackgroundImageStyleValue->Void = onBackgroundImageLoaded;
		
		var onBackgroundImageLoadErrorDelegate:String->ColorValue->NativeElement->AbstractStyle->RectangleData->BackgroundPositionStyleData->
		BackgroundSizeStyleValue->BackgroundOriginStyleValue-> BackgroundClipStyleValue-> BackgroundRepeatStyleData->
		BackgroundImageStyleValue->Void = onBackgroundImageLoadError;
		
		//try to load the picture, and set the callbacks
		imageLoader.load(imageDeclaration.urls,
		function(loadedImage:NativeElement) {
			onBackgroundImageLoadedDelegate(backgroundImageNativeElement, loadedImage, imageLoader, style, backgroundBox, backgroundPosition, backgroundSize, 
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
	private function onBackgroundImageLoaded(backgroundImageNativeElement:NativeElement, loadedBackgroundImage:NativeElement, imageLoader:ImageLoader, style:AbstractStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPositionStyleData, backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue,
	backgroundClip:BackgroundClipStyleValue, backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):Void
	{
			var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, imageLoader.intrinsicWidth, imageLoader.intrinsicHeight, imageLoader.intrinsicRatio, backgroundPosition,
			backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
			
			var backgroundImageDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundImageNativeElement,
			backgroundBox);
			
			backgroundImageDrawingManager.drawBackgroundImage(
			loadedBackgroundImage, 
			computedGradientStyles.backgroundOrigin,
			computedGradientStyles.backgroundClip,
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
	private function onBackgroundImageLoadError(error:String, backgroundColor:ColorValue, backgroundImageNativeElement:NativeElement, style:AbstractStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPositionStyleData, backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue,
	backgroundClip:BackgroundClipStyleValue, backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):Void
	{
		drawBackgroundColor(style, UnitManager.getColorDataFromColorValue(backgroundColor), backgroundImageNativeElement, backgroundBox, backgroundPosition,
				backgroundSize, backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
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
	private function drawBackgroundColor(style:AbstractStyle, backgroundColor:ColorData, backgroundColorNativeElement:NativeElement, backgroundBox:RectangleData, backgroundPosition:BackgroundPositionStyleData,
	backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue, backgroundClip:BackgroundClipStyleValue, 
	backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):Void
	{
		var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
			
		var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundColorNativeElement,
		backgroundBox);
		backgroundColorDrawingManager.drawBackgroundColor(backgroundColor, computedBackgroundStyles.backgroundClip);
		//TODO : don't do that here
		#if flash9
		backgroundColorNativeElement.x = backgroundBox.x;
		backgroundColorNativeElement.y = backgroundBox.y;
		#end
		_backgroundDrawingManagers.push(backgroundColorDrawingManager);
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
	private function drawBackgroundGradient(style:AbstractStyle, gradientValue:GradientValue, backgroundBox:RectangleData, backgroundPosition:BackgroundPositionStyleData,
	backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue, backgroundClip:BackgroundClipStyleValue,
	backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):NativeElement
	{
		var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
							

			var gradientNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
		
			var backgroundGradientDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(gradientNativeElement,
			backgroundBox );
			backgroundGradientDrawingManager.drawBackgroundGradient(
			gradientValue,
			computedGradientStyles.backgroundOrigin,
			computedGradientStyles.backgroundClip,
			computedGradientStyles.backgroundSize,
			computedGradientStyles.backgroundPosition, 
			computedGradientStyles.backgroundRepeat);
			
		return gradientNativeElement;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setBackgroundColor(value:BackgroundColorStyleValue):BackgroundColorStyleValue
	{
		return _backgroundColor = value;
	}
	
	private function getBackgroundColor():BackgroundColorStyleValue
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImageStyleValue>):Array<BackgroundImageStyleValue>
	{
		return _backgroundImage = value;
	}
	
	private function getBackgroundImage():Array<BackgroundImageStyleValue>
	{
		return _backgroundImage;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeatStyleData>):Array<BackgroundRepeatStyleData>
	{
		return _backgroundRepeat = value;
	}
	
	private function getBackgroundRepeat():Array<BackgroundRepeatStyleData>
	{
		return _backgroundRepeat;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSizeStyleValue>):Array<BackgroundSizeStyleValue>
	{
		return _backgroundSize = value;
	}
	
	private function getBackgroundSize():Array<BackgroundSizeStyleValue>
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClipStyleValue>):Array<BackgroundClipStyleValue>
	{
		return _backgroundClip = value;
	}
	
	private function getBackgroundClip():Array<BackgroundClipStyleValue>
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPositionStyleData>):Array<BackgroundPositionStyleData>
	{
		return _backgroundPosition = value;
	}
	
	private function getBackgroundPosition():Array<BackgroundPositionStyleData>
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOriginStyleValue>):Array<BackgroundOriginStyleValue>
	{
		return _backgroundOrigin = value;
	}
	
	private function getBackgroundOrigin():Array<BackgroundOriginStyleValue>
	{
		return _backgroundOrigin;
	}
	
	
	
}