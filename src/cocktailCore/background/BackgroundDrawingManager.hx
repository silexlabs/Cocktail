package cocktailCore.background;
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
	
	public function drawBackgroundImage(nativeImage:NativeElement, computedBackgroundSize:DimensionData, computedBackgroundPosition:PointData , backgroundRepeat:BackgroundRepeatStyleData):Void
	{
		
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