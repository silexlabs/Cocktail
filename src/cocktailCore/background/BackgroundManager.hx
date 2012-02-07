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
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BackgroundManager 
{

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
	
	private var _backgroundDrawingManagers:Array<BackgroundDrawingManager>;
	
	public function new()
	{
		_backgroundDrawingManagers = new Array<BackgroundDrawingManager>();
	}
	
	public function render(backgroundBox:RectangleData, style:AbstractStyle):Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		if (backgroundBox.width <= 0 || backgroundBox.height <= 0)
		{
			return nativeElements;
		}
		
		for (i in 0..._backgroundImage.length)
		{
			
			switch (_backgroundImage[i])
			{
				case BackgroundImageStyleValue.none:
					
				case BackgroundImageStyleValue.image(value):
					
					switch (value)
					{
						case ImageValue.url(value):
							
							var imageNativeElement:NativeElement = drawBackgroundImage([value], style, backgroundBox,
							_backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i],
							_backgroundRepeat[i], _backgroundImage[i]);
							
							nativeElements.push(imageNativeElement);
							
						case ImageValue.imageList(value):
							/**
							var imageNativeElement:NativeElement = drawBackgroundImage(value, style, backgroundBox,
							_backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i],
							_backgroundRepeat[i], _backgroundImage[i]);
							
							nativeElements.push(imageNativeElement);*/
							
						case ImageValue.gradient(value):
							
							var gradientNativeElement:NativeElement = drawBackgroundGradient(style, value, backgroundBox, _backgroundPosition[i],
							_backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);

							nativeElements.push(gradientNativeElement);
					}
			}
			
			//to remember : use the bottom most data, see CSS3 spec
			if (i == _backgroundImage.length - 1)
			{
				var backgroundColorNativeElement:NativeElement = drawBackgroundColor(style, backgroundBox, _backgroundPosition[i],
				_backgroundSize[i], _backgroundOrigin[i], _backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);
				
				nativeElements.reverse();
				nativeElements.unshift(backgroundColorNativeElement);
			}
			
		}
		
		return nativeElements;
	}
	
	
	
	private function drawBackgroundImage(urls:Array<String>, style:AbstractStyle, backgroundBox:RectangleData,
	backgroundPosition:BackgroundPositionStyleData, backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue,
	backgroundClip:BackgroundClipStyleValue, backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):NativeElement
	{
		var backgroundImageNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
		
		var imageLoader:ImageLoader = new ImageLoader();
		
		var onBackgroundImageLoadedDelegate:NativeElement->NativeElement->ImageLoader->AbstractStyle->RectangleData->BackgroundPositionStyleData->
		BackgroundSizeStyleValue->BackgroundOriginStyleValue-> BackgroundClipStyleValue-> BackgroundRepeatStyleData->
		BackgroundImageStyleValue->Void = onBackgroundImageLoaded;
		
		imageLoader.load(urls,
		function(loadedImage) {
			onBackgroundImageLoadedDelegate(backgroundImageNativeElement, loadedImage, imageLoader, style, backgroundBox, backgroundPosition, backgroundSize, 
			backgroundOrigin, backgroundClip, backgroundRepeat, backgroundImage);
		}, onBackgroundImageLoadError);
		
		return backgroundImageNativeElement;
	}
	
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
	
	private function onBackgroundImageLoadError(error:String):Void
	{
		Log.trace(error);
	}
	
	private function drawBackgroundColor(style:AbstractStyle, backgroundBox:RectangleData, backgroundPosition:BackgroundPositionStyleData,
	backgroundSize:BackgroundSizeStyleValue, backgroundOrigin:BackgroundOriginStyleValue, backgroundClip:BackgroundClipStyleValue, 
	backgroundRepeat:BackgroundRepeatStyleData, backgroundImage:BackgroundImageStyleValue):NativeElement
	{
		var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
			style, backgroundBox, null, null, null, backgroundPosition, backgroundSize, backgroundOrigin,
			backgroundClip, backgroundRepeat, backgroundImage);
			
			var backgroundColorNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
			var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundColorNativeElement,
			backgroundBox);
			backgroundColorDrawingManager.drawBackgroundColor(style.computedStyle.backgroundColor, computedBackgroundStyles.backgroundClip);
			//TODO : don't do that here
			#if flash9
			backgroundColorNativeElement.x = backgroundBox.x;
			backgroundColorNativeElement.y = backgroundBox.y;
			#end
			_backgroundDrawingManagers.push(backgroundColorDrawingManager);
		
		return backgroundColorNativeElement;
	}
	
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