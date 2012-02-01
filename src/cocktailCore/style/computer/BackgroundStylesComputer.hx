package cocktailCore.style.computer;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import cocktailCore.unit.UnitManager;
import cocktail.geom.GeomData;
import cocktail.unit.UnitData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BackgroundStylesComputer 
{

	private function new() 
	{
		
	}

	public static function compute(style:AbstractStyle):Void
	{
		
		style.computedStyle.backgroundColor = getComputedBackgroundColor(style);
		style.computedStyle.backgroundRepeat = style.backgroundRepeat;
		
		style.computedStyle.backgroundClip = style.backgroundClip;
		
		
		style.computedStyle.backgroundSize = getComputedBackgroundSize(style);
		
		style.computedStyle.backgroundPosition = style.backgroundPosition;

		style.computedStyle.backgroundOrigin = style.backgroundOrigin;
		style.computedStyle.backgroundImage = style.backgroundImage;

	}
	
	private static function getComputedBackgroundColor(style:AbstractStyle):Int
	{
		var color:Int;
		
		switch (style.backgroundColor)
		{
			case BackgroundColorStyleValue.colorValue(value):
				color = UnitManager.getColorFromColorValue(value);
		}
		
		return color;
	}
	
	private static function getComputedBackgroundPosition(style:AbstractStyle):Array<PointData>
	{
		return [];
	}
	
	private static function getComputedBackgroundSize(style:AbstractStyle):Array<DimensionData>
	{
		var computedBackgroundSize:Array<DimensionData> = new Array<DimensionData>();
		
		for (i in 0...style.backgroundSize.length)
		{
			var backgroundPositioningArea:DimensionData = getBackgroundPositioningArea(style, style.computedStyle.backgroundClip[i]);
			computedBackgroundSize.push(doGetComputedBackgroundSize(style.backgroundSize[i], backgroundPositioningArea));
		}
		
		return computedBackgroundSize;
	}
	
	private static function doGetComputedBackgroundSize(backgroundSize:BackgroundSizeStyleValue, backgroundImage:BackgroundImageStyleValue, backgroundPositioningArea:DimensionData):DimensionData
	{
		var computedBackgroundSize:DimensionData;
		
		switch (backgroundSize)
		{
			case BackgroundSizeStyleValue.contain:
				switch (backgroundImage)
				{
					case BackgroundImageStyleValue.none:
						computedBackgroundSize = {
							width:0,
							height:0
						}
						
					case BackgroundImageStyleValue.image(value)
					{
						case ImageValue.url(value),
						ImageValue.imageList(value):
							computedBackgroundSize = {
							width:0,
							height:0
						}
						
						case ImageValue.gradient(value):
							computedBackgroundSize = {
							width:backgroundPositioningArea.width,
							height:backgroundPositioningArea.height
						}
					}
				}
		}
		
		return computedBackgroundSize;
	}
	
	
	private static function getBackgroundPositioningArea(style:AbstractStyle, backgroundClip:BackgroundClipStyleValue):DimensionData
	{
		var backgroundPositioningArea:DimensionData;
		
		switch (backgroundClip)
		{
			case BackgroundClipStyleValue.borderBox:
				backgroundPositioningArea = {
					height:style.computedStyle.height + style.computedStyle.paddingTop + style.computedStyle.paddingBottom,
					width:style.computedStyle.width + style.computedStyle.paddingLeft + style.computedStyle.paddingRight
				}
				
			case BackgroundClipStyleValue.paddingBox:
				backgroundPositioningArea = {
					height:style.computedStyle.height + style.computedStyle.paddingTop + style.computedStyle.paddingBottom,
					width:style.computedStyle.width + style.computedStyle.paddingLeft + style.computedStyle.paddingRight
				}
				
			case BackgroundClipStyleValue.contentBox:
				backgroundPositioningArea = {
					height:style.computedStyle.height,
					width:style.computedStyle.width
				}
		}
		
		return backgroundPositioningArea;
	}
}