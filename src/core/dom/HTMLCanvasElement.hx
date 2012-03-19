package core.dom;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.drawing.DrawingManager;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class HTMLCanvasElement extends HTMLElement
{
	/**
	 * Set/get the height of the EmbeddedDOMElement.
	 */
	private var _height:Int;
	public var height(get_height, set_height):Int;
		
	/**
	 * Set/get the width of the EmbeddedDOMElement.
	 */
	private var _width:Int;
	public var width(get_width, set_width):Int;
	
	/**
	 * A reference to the manager used to 
	 * draw on the NativeElement
	 */
	private var _drawingManager:DrawingManager;
	
	public function new() 
	{
		_nativeElement = NativeElementManager.createNativeElement(graphic);
		
		super();
		
		_drawingManager = new DrawingManager(nativeElement, 150, 300 );
	}
	
	//TODO : add context id
	public function getContext():DrawingManager
	{
		return _drawingManager;
	}
	
	private function set_width(value:Int):Int
	{
		return _width = value;
	}
	
	private function get_width():Int
	{
		return _width;
	}
	
	private function set_height(value:Int):Int
	{
		return _height = value;
	}
	
	private function get_height():Int
	{
		return _height;
	}
	
}