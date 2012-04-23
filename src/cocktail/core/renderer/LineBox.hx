package cocktail.core.renderer;
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
	}
	
	public function render():Array<NativeElement>
	{
		return [];
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
}