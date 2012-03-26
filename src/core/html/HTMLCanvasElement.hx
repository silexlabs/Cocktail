package core.html;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.drawing.DrawingManager;

/**
 * ...
 * 
 * TODO : override get_tagName as embedded element always match one element
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
	
	
	/**
	 * A reference to the manager used to 
	 * draw on the NativeElement
	 */
	private var _drawingManager:DrawingManager;
	
	public function new() 
	{
		_nativeElement = NativeElementManager.createNativeElement(graphic);
		
		super();
		
		_intrinsicHeight = CANVAS_INTRINSIC_HEIGHT;
		_intrinsicWidth = CANVAS_INTRINSIC_WIDTH;
		_intrinsicRatio = _intrinsicWidth / _intrinsicHeight;
		
		_drawingManager = new DrawingManager(_nativeElement, _intrinsicHeight, _intrinsicWidth );
	}
	
	
	
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _nativeElement;
	}
	
	public function getContext(contextID:String):DrawingManager
	{	
		return _drawingManager;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * always return an html canvas tag
	 */ 
	override private function get_tagName():String
	{
		return HTML_CANVAS_TAG_NAME;
	}
	
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