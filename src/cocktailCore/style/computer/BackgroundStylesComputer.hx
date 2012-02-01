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
		
		style.computedStyle.backgroundPosition = getComputedBackgroundPosition(style);

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
		var computedBackgroundPosition:Array<PointData> = new Array<PointData>();
		
		for (i in 0...style.backgroundPosition.length)
		{
			var backgroundPositioningArea:DimensionData = getBackgroundPositioningArea(style, style.computedStyle.backgroundClip[i]);
			computedBackgroundPosition.push(doGetComputedBackgroundPosition(style.backgroundPosition[i], backgroundPositioningArea, style.computedStyle.fontSize, style.fontMetrics.xHeight));
		}
		
		return computedBackgroundPosition;
	}
	
	private static function doGetComputedBackgroundPosition(backgroundSize:BackgroundPositionStyleData, backgroundPositioningArea:DimensionData, emReference:Float, exReference:Float):PointData
	{
		var computedBackgroundPosition:PointData = {
			x:doGetComputedBackgroundXPosition(backgroundSize.x, backgroundPositioningArea.width,
		};
		
		
	}
	
	private static function getComputedBackgroundSize(style:AbstractStyle):Array<DimensionData>
	{
		var computedBackgroundSize:Array<DimensionData> = new Array<DimensionData>();
		
		for (i in 0...style.backgroundSize.length)
		{
			var backgroundPositioningArea:DimensionData = getBackgroundPositioningArea(style, style.computedStyle.backgroundClip[i]);
			computedBackgroundSize.push(doGetComputedBackgroundSize(style.backgroundSize[i], backgroundPositioningArea, style.computedStyle.fontSize, style.fontMetrics.xHeight));
		}
		
		return computedBackgroundSize;
	}
	
	private static function doGetComputedBackgroundSize(backgroundSize:BackgroundSizeStyleValue, backgroundPositioningArea:DimensionData, emReference:Float, exReference:Float):DimensionData
	{
		var computedBackgroundSize:DimensionData;
		
		switch (backgroundSize)
		{
			case BackgroundSizeStyleValue.contain:
				computedBackgroundSize = {
					width:0,
					height:0
				}
				
			case BackgroundSizeStyleValue.dimensions(value):
				computedBackgroundSize = {
					width:getBackgroundSizeStyleDimensionData(value.x, backgroundPositioningArea.width, emReference, exReference),
					height:getBackgroundSizeStyleDimensionData(value.y, backgroundPositioningArea.height, emReference, exReference)
				}
				
			case BackgroundSizeStyleValue.cover:
				computedBackgroundSize = {
					width:0,
					height:0
				}
		}
		
		return computedBackgroundSize;
	}
	
	private static function getBackgroundSizeStyleDimensionData(value:BackgroundSizeStyleDimensionValue, backgroundPositioningAreaDimension:Int, emReference:Float, exReference:Float):Int
	{
		var backgroundSizeStyleDimension:Int;
		
		switch (value)
		{
			case BackgroundSizeStyleDimensionValue.length(value):
				backgroundSizeStyleDimension = UnitManager.getPixelFromLengthValue(value, emReference, exReference);
				
			case BackgroundSizeStyleDimensionValue.percent(value):
				backgroundSizeStyleDimension = Math.round(UnitManager.getPixelFromPercent(value, backgroundPositioningAreaDimension));
			
			case BackgroundSizeStyleDimensionValue.auto:
				backgroundSizeStyleDimension = 0;
		}
		
		return backgroundSizeStyleDimension;
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