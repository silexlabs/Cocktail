package cocktailCore.background;
import cocktail.geom.Matrix;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktailCore.drawing.DrawingManager;
import cocktail.geom.GeomData;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktailCore.resource.ImageLoader;
import cocktail.domElement.DOMElementData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BackgroundDrawingManager extends DrawingManager
{

	private var _backgroundPositioningBox:RectangleData;
	
	private var _backgroundPaintingBox:RectangleData;
	
	private var _imageLoader:ImageLoader;
	
	public function new(backgroundBox:RectangleData, backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData) 
	{
		_backgroundPositioningBox = backgroundPositioningBox;
		_backgroundPaintingBox = backgroundPaintingBox;
		
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.graphic), Math.round(backgroundBox.width), Math.round(backgroundBox.height));
	}
	
	public function drawBackgroundImage(nativeImage:NativeElement, intrinsicWidth:Int, intrinsicHeight:Int, intrinsicRatio:Float, computedBackgroundSize:DimensionData, computedBackgroundPosition:PointData , backgroundRepeat:BackgroundRepeatStyleData):Void
	{
		
		var totalWidth:Float;
		var maxWidth:Float;
		var imageWidth:Float;
		var initialWidth:Float;
		
		switch (backgroundRepeat.x)
		{
			case BackgroundRepeatStyleValue.noRepeat:
				imageWidth = computedBackgroundSize.width;
				totalWidth = computedBackgroundPosition.x;
				initialWidth = totalWidth;
				maxWidth = totalWidth + imageWidth;
				
			case BackgroundRepeatStyleValue.repeat:
				imageWidth = computedBackgroundSize.width;
				totalWidth = computedBackgroundPosition.x;
				while (totalWidth > _backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				initialWidth = totalWidth;
				maxWidth = _backgroundPaintingBox.x + _backgroundPaintingBox.width;
				
			case BackgroundRepeatStyleValue.space:
				imageWidth = _backgroundPositioningBox.width / computedBackgroundSize.width;
				totalWidth = computedBackgroundPosition.x;
				while (totalWidth > _backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				initialWidth = totalWidth;
				maxWidth = _backgroundPaintingBox.x + _backgroundPaintingBox.width;
				
			case BackgroundRepeatStyleValue.round:
				imageWidth = computedBackgroundSize.width;
				totalWidth = computedBackgroundPosition.x;
				while (totalWidth > _backgroundPaintingBox.x)
				{
					totalWidth -= imageWidth;
				}
				initialWidth = totalWidth;
				maxWidth = _backgroundPaintingBox.x + _backgroundPaintingBox.width;
		}
		
		var totalHeight:Float;
		var maxHeight:Float;
		var imageHeight:Float;
		var initialHeight:Float;
		
		switch (backgroundRepeat.y)
		{
			case BackgroundRepeatStyleValue.noRepeat:
				imageHeight = computedBackgroundSize.height;
				totalHeight = computedBackgroundPosition.y;
				initialHeight = totalHeight;
				maxHeight = totalWidth + totalHeight;
				
			case BackgroundRepeatStyleValue.repeat:
				imageHeight = computedBackgroundSize.height;
				totalHeight = computedBackgroundPosition.y;
				while (totalHeight > _backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				initialHeight = totalHeight;
				maxHeight = _backgroundPaintingBox.y + _backgroundPaintingBox.height;
				
			case BackgroundRepeatStyleValue.space:
				imageHeight = _backgroundPositioningBox.height / computedBackgroundSize.height;
				totalHeight = computedBackgroundPosition.y;
				while (totalHeight > _backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				initialHeight = totalHeight;
				maxHeight = _backgroundPaintingBox.y + _backgroundPaintingBox.height;
				
			case BackgroundRepeatStyleValue.round:
				imageHeight = computedBackgroundSize.height;
				totalHeight = computedBackgroundPosition.y;
				while (totalHeight > _backgroundPaintingBox.y)
				{
					totalHeight -= imageHeight;
				}
				initialHeight = totalHeight;
				maxHeight = _backgroundPaintingBox.y + _backgroundPaintingBox.height;
		}
		
		while (totalHeight < maxHeight)
		{
			var matrix:Matrix = new Matrix();
		
			matrix.scale(intrinsicWidth / computedBackgroundSize.width, intrinsicHeight / computedBackgroundSize.height, { x:0.0, y:0.0 } );
			
			matrix.translate(totalWidth, totalHeight);
			
			drawImage(nativeImage, matrix);
			
			totalWidth += imageWidth;
			
			if (totalWidth > maxWidth)
			{
				totalWidth = initialWidth;
				totalHeight += imageHeight;
			}
		}
		
	
	}
	
	public function drawBackgroundColor(color:ColorData):Void
	{
		var fillStyle:FillStyleValue = FillStyleValue.monochrome( color );
		var lineStyle:LineStyleValue = LineStyleValue.none;
		Log.trace(color);
		beginFill(fillStyle, lineStyle);
		
		drawRect(Math.round(_backgroundPaintingBox.x), Math.round(_backgroundPaintingBox.y), Math.round(_backgroundPaintingBox.width), Math.round(_backgroundPaintingBox.height));
		
		endFill();
	}
	
	public function drawBackgroundGradient(gradient:GradientValue, computedBackgroundSize:DimensionData, computedBackgroundPosition:PointData, backgroundRepeat:BackgroundRepeatStyleData):Void
	{
		
	}
	
}