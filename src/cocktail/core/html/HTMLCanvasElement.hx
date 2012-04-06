package cocktail.core.html;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;
import cocktail.core.drawing.DrawingManager;

/**
 * ...
 * 
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLCanvasElement extends EmbeddedElement
{
	private static inline var CANVAS_INTRINSIC_HEIGHT:Int = 150;
	
	private static inline var CANVAS_INTRINSIC_WIDTH:Int = 300;
	
	/**
	 * the html tag name of an image
	 */
	private static inline var HTML_CANVAS_TAG_NAME:String = "canvas";
	
	private static inline var CANVAS_2D_CONTEXT:String = "2d";
	
	
	/**
	 * A reference to the manager used to 
	 * draw on the NativeElement
	 */
	private var _drawingManager:DrawingManager;
	
	public function new() 
	{
		super(HTML_CANVAS_TAG_NAME);
		
		_intrinsicHeight = CANVAS_INTRINSIC_HEIGHT;
		_intrinsicWidth = CANVAS_INTRINSIC_WIDTH;
		_intrinsicRatio = _intrinsicWidth / _intrinsicHeight;
		
		
	}
	
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _nativeElement;
	}
	
	public function getContext(contextID:String):DrawingManager
	{	
		if (contextID == CANVAS_2D_CONTEXT)
		{
			if (_drawingManager == null)
			{
				_drawingManager = new DrawingManager(_nativeElement, _intrinsicHeight, _intrinsicWidth );
			}
			return _drawingManager;
		}
		else
		{
			return null;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_width(value:Int):Int
	{
		_drawingManager.width = value;
		return _width = value;
	}
	
	override private function set_height(value:Int):Int
	{
		_drawingManager.height = value;
		return _height = value;
	}
}