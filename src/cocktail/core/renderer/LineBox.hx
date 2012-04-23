package cocktail.core.renderer;
import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.geom.GeomData;
import cocktail.core.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LineBox extends Node
{

	private var _elementRenderer:ElementRenderer;
	
	private var _bounds:RectangleData;
	public var bounds(get_bounds, set_bounds):RectangleData;
	
	private var _nativeElement:NativeElement;
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	private var _leadedAscent:Float;
	public var leadedAscent(get_leadedAscent, set_leadedAscent):Float;
	
	private var _leadedDescent:Float;
	public var leadedDescent(get_leadedDescent, set_leadedDescent):Float;
	
	public var verticalAlign(get_verticalAlign, never):Float;
	
	private var _leftOffset:Int;
	public var leftOffset(get_leftOffset, set_leftOffset):Int;
	
	private var _rightOffset:Int;
	public var rightOffset(get_rightOffset, set_rightOffset):Int;
	
	private var	_backgroundManager:BackgroundManager;
	
	public function new(elementRenderer:ElementRenderer) 
	{
		super();
			_bounds = {
			x:0.0,
			y:0.0,
			width:0.0,
			height:0.0
		}
		_elementRenderer = elementRenderer;
		
		_leadedAscent = 0;
		_leadedDescent = 0;
		
		_backgroundManager = new BackgroundManager();
		
	}
	
	public function get_rightOffset():Int
	{
		return _rightOffset;
	}
	
	public function get_leftOffset():Int
	{
		return _leftOffset;
	}
	
	public function set_leftOffset(value:Int):Int
	{
		return _leftOffset = value;
	}
	
	public function set_rightOffset(value:Int):Int
	{
		return _rightOffset = value;
	}
	
	public function isSpace():Bool
	{
		return false;
	}
	
	public function render():Array<NativeElement>
	{
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _elementRenderer.coreStyle);
		
		for (i in 0...backgrounds.length)
		{
			#if (flash9 || nme)
			backgrounds[i].x = _bounds.x;
			backgrounds[i].y = _bounds.y;
			#end
		}
		return backgrounds;
	}
	
	private function get_nativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function get_bounds():RectangleData
	{
		return _bounds;
	}
	
	private function set_bounds(value:RectangleData):RectangleData
	{
		return _bounds = value;
	}
	
	private function get_leadedAscent():Float 
	{
		return _leadedAscent;
	}
	
	private function get_verticalAlign():Float
	{
		return _elementRenderer.coreStyle.computedStyle.verticalAlign;
	}
	
	private function set_leadedAscent(value:Float):Float 
	{
		return _leadedAscent = value;
	}
	
	private function get_leadedDescent():Float 
	{
		return _leadedDescent;
	}
	
	private function set_leadedDescent(value:Float):Float 
	{
		return _leadedDescent = value;
	}
}