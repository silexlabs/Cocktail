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
	
	private var _marginLeft:Int;
	public var marginLeft(get_marginLeft, set_marginLeft):Int;
	
	private var _marginRight:Int;
	public var marginRight(get_marginRight, set_marginRight):Int;
	
	private var _paddingLeft:Int;
	public var paddingLeft(get_paddingLeft, set_paddingLeft):Int;
	
	private var _paddingRight:Int;
	public var paddingRight(get_paddingRight, set_paddingRight):Int;
	
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
	
	private function get_paddingRight():Int 
	{
		return _paddingRight;
	}
	
	private function set_paddingRight(value:Int):Int 
	{
		return _paddingRight = value;
	}
	
	private function get_paddingLeft():Int 
	{
		return _paddingLeft;
	}
	
	private function set_paddingLeft(value:Int):Int 
	{
		return _paddingLeft = value;
	}
	
	public function get_marginRight():Int
	{
		return _marginRight;
	}
	
	public function get_marginLeft():Int
	{
		return _marginLeft;
	}
	
	public function set_marginLeft(value:Int):Int
	{
		return _marginLeft = value;
	}
	
	public function set_marginRight(value:Int):Int
	{
		return _marginRight = value;
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