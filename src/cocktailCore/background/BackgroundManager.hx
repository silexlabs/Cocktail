package cocktailCore.background;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktail.geom.GeomData;

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
		
	}
	
	public function render(width:Int, height:Int, computedStyle:ComputedStyleData):Array<NativeElement>
	{
		var paddedBackgroundRepeat:Array<BackgroundRepeatStyleData> = cast(getPaddedBackgroundStyle(_backgroundImage, _backgroundRepeat));
		var paddedBackgroundSize:Array<BackgroundSizeStyleValue> = cast(getPaddedBackgroundStyle(_backgroundImage, _backgroundSize));
		var paddedBackgroundPosition:Array<BackgroundPositionStyleData> = cast(getPaddedBackgroundStyle(_backgroundImage, _backgroundPosition));
		var paddedBackgroundClip:Array<BackgroundClipStyleValue> = cast(getPaddedBackgroundStyle(_backgroundImage, _backgroundClip));
		var paddedBackgroundOrigin:Array<BackgroundOriginStyleValue> = cast(getPaddedBackgroundStyle(_backgroundImage, _backgroundOrigin));
		
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();
		
		
		
		var backgroundColorValue:ColorValue;
		
		switch (_backgroundColor)
		{
			case colorValue(value):
				backgroundColorValue = value;
		}
		var concatenatedImages:Array<BackgroundImageStyleValue> = new Array<BackgroundImageStyleValue>();
		//concatenatedImages.push(BackgroundImageStyleValue.image(ImageValue.imageList([ImageDeclarationValue.color(ColorValue.(backgroundColorValue))]));
		
		for (i in 0..._backgroundImage.length)
		{
			concatenatedImages.push(_backgroundImage[i]);
		}
		
		for (i in 0...concatenatedImages.length)
		{
			
			
			switch (concatenatedImages[i])
			{
				case BackgroundImageStyleValue.none:
					
				case BackgroundImageStyleValue.image(value):
					
			}
			
			
		}
		
		 return null;
	}
	
	private function getBackgroundDrawingManager(marginBox:RectangleData, backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData,
	imageValue:ImageValue, backgroundSize:BackgroundSizeStyleValue, 
	backgroundPosition:BackgroundPositionStyleData, backgroundRepeat:BackgroundRepeatStyleData):BackgroundDrawingManager
	{
		var backgroundDrawingManager:BackgroundDrawingManager = new BackgroundDrawingManager(
		Math.round(marginBox.width),
		Math.round(marginBox.height),
		backgroundPositioningBox,
		backgroundPaintingBox);
		
		backgroundDrawingManager.drawBackgroundImage(imageValue, backgroundSize, backgroundPosition, backgroundRepeat);
		
		return backgroundDrawingManager;
	}
	
	private function getPaddedBackgroundStyle(backgroundImage:Array<BackgroundImageStyleValue>, backgroundStyle:Array<Dynamic>):Array<Dynamic>
	{
		var backgroundStyleLength:Int = backgroundStyle.length;
		var backgroundStyleIdx:Int = 0;
		
		while (backgroundStyle.length < backgroundImage.length)
		{
			backgroundStyle.push(backgroundStyle[backgroundStyleIdx]);
			backgroundStyleIdx++;
			if (backgroundStyleIdx > backgroundStyleLength - 1)
			{
				backgroundStyleIdx = 0;
			}
		}
		
		return backgroundStyle;
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