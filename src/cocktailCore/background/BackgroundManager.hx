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
		var backgroundColorNativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
		for (i in 0..._backgroundImage.length)
		{
			if (i == 0)
			{
				var computedBackgroundStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
				style, backgroundBox, null, null, null, _backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i],
				_backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);
				
				if (backgroundBox.width > 0 && backgroundBox.height > 0)
				{
					var backgroundColorDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(backgroundColorNativeElement,
					backgroundBox, computedBackgroundStyles.backgroundOrigin, computedBackgroundStyles.backgroundClip);
					backgroundColorDrawingManager.drawBackgroundColor(style.computedStyle.backgroundColor);
					_backgroundDrawingManagers.push(backgroundColorDrawingManager);
				}
			}
			
			switch (_backgroundImage[i])
			{
				case BackgroundImageStyleValue.none:
					
				case BackgroundImageStyleValue.image(value):
					switch (value)
					{
						case ImageValue.url(value):
							var nativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
							var imageLoader:ImageLoader = new ImageLoader();
							imageLoader.load([value], function(image) {
								var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
								style, backgroundBox, imageLoader.intrinsicWidth, imageLoader.intrinsicHeight, imageLoader.intrinsicRatio, _backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i],
								_backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);
								
								if (backgroundBox.width > 0 && backgroundBox.height > 0)
								{
									var backgroundImageDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(nativeElement,
									backgroundBox, computedGradientStyles.backgroundOrigin, computedGradientStyles.backgroundClip);
									backgroundImageDrawingManager.drawBackgroundImage(
									image, imageLoader.intrinsicWidth, imageLoader.intrinsicHeight, imageLoader.intrinsicRatio,
									computedGradientStyles.backgroundSize,
									computedGradientStyles.backgroundPosition, 
									computedGradientStyles.backgroundRepeat);
									_backgroundDrawingManagers.push(backgroundImageDrawingManager);
									
								}
								
							}, function(error) { Log.trace(error); } );
							nativeElements.push(nativeElement);
							
						case ImageValue.imageList(value):
							
						case ImageValue.gradient(value):
							var computedGradientStyles:ComputedBackgroundStyleData = BackgroundStylesComputer.computeIndividualBackground(
							style, backgroundBox, null, null, null, _backgroundPosition[i], _backgroundSize[i], _backgroundOrigin[i],
							_backgroundClip[i], _backgroundRepeat[i], _backgroundImage[i]);
							
							if (backgroundBox.width > 0 && backgroundBox.height > 0)
							{
								var nativeElement:NativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.graphic);
							
								var backgroundGradientDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(nativeElement,
								backgroundBox, computedGradientStyles.backgroundOrigin, computedGradientStyles.backgroundClip);
								backgroundGradientDrawingManager.drawBackgroundGradient(
								value,
								computedGradientStyles.backgroundSize,
								computedGradientStyles.backgroundPosition, 
								computedGradientStyles.backgroundRepeat);
								_backgroundDrawingManagers.push(backgroundGradientDrawingManager);
								nativeElements.push(backgroundGradientDrawingManager.nativeElement);
							}
					}
			}
			
		}
		
		nativeElements.reverse();
		nativeElements.unshift(backgroundColorNativeElement);
		
		 return nativeElements;
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