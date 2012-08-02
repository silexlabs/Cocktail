package cocktail.core.drawing;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ImageData 
{
	private var _width:Int;
	public var width(get_width, never):Int;
	
	private var _height:Int;
	public var height(get_height, never):Int;
	
	private var _data:CanvasPixelArray;
	public var data(get_data, never):CanvasPixelArray;

	public function new(width:Int, height:Int, data:CanvasPixelArray) 
	{
		_width = width;
		_height = height;
		_data = data;
	}
	
	private function get_data():CanvasPixelArray 
	{
		return _data;
	}
	
	private function get_width():Int 
	{
		return _width;
	}
	
	private function get_height():Int 
	{
		return _height;
	}
	
	
}