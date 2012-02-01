package cocktailCore.background;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktailCore.drawing.DrawingManager;
import cocktail.geom.GeomData;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktailCore.resource.ImageLoader;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BackgroundDrawingManager extends DrawingManager
{

	private var _backgroundPositioningBox:RectangleData;
	
	private var _backgroundPaintingBox:RectangleData;
	
	private var _imageLoader:ImageLoader;
	
	public function new(width:Int, height:Int, backgroundPositioningBox:RectangleData, backgroundPaintingBox:RectangleData) 
	{
		_backgroundPositioningBox = backgroundPositioningBox;
		_backgroundPaintingBox = backgroundPaintingBox;
		
		super(NativeElementManager.createNativeElement(NativeElementTypeValue.graphic), width, height);
	}
	
	public function drawBackgroundImage(imageValue:ImageValue, backgroundSize:BackgroundSizeStyleValue, backgroundPosition:BackgroundPositionStyleData , backgroundRepeat:BackgroundRepeatStyleData):Void
	{
		switch (imageValue)
		{
			case ImageValue.url(value):
				
			case ImageValue.gradient(value):
				
			case ImageValue.imageList(value):
				
		}
	}
	
	private function drawBackgroundGradient(gradient:GradientValue, backgroundSize:BackgroundSizeStyleValue, backgroundPosition:BackgroundPositionStyleData, backgroundRepeat:BackgroundRepeatStyleData):Void
	{
		/**
		var gradientWidth:Int;
		var gradientHeight:Int;
		
		switch (backgroundSize)
		{
			case BackgroundSizeStyleValue.contain,
			BackgroundSizeStyleValue.cover:
				gradientWidth = _backgroundPositioningBox.width;
				gradientHeight = _backgroundPositioningBox.height;
				
			case BackgroundSizeStyleValue.dimensions(value):
				switch (value.x)
				{
					case BackgroundSizeStyleData.
				}
		}*/
	}
	
}