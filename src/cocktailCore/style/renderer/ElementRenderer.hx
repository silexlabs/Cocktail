package cocktailCore.style.renderer;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.drawing.DrawingManager;
import cocktail.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ElementRenderer 
{

	private var _bounds:RectangleData;
	public var bounds(getBounds, setBounds):RectangleData;
	
	
	private var _domElement:DOMElement;
	public var domElement(getDOMElement, never):DOMElement;
	
	private var _parent:FlowBoxRenderer;
	public var parent(getParent, setParent):FlowBoxRenderer;
	
	private var _layerRenderer:LayerRenderer;
	public var layerRenderer(getLayerRenderer, setLayerRenderer):LayerRenderer;
	
	public function new(domElement:DOMElement) 
	{
		_domElement = domElement;
		
		//create/set bounds in Style instead ?
		_bounds = {
			x:0.0,
			y:0.0,
			width:0.0,
			height:0.0
		}
	}
	
	public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	public function canHaveChildren():Bool
	{
		return false;
	}
	
	public function isFloat():Bool
	{
		return _domElement.style.isFloat();
	}
	
	public function isPositioned():Bool
	{
		return _domElement.style.isPositioned();
	}
	
	public function isText():Bool
	{
		return false;
	}
	
	public function isSpace():Bool
	{
		return false;
	}
	
	public function isLineFeed():Bool
	{
		return false;
	}
	
	
	public function render():Array<NativeElement>
	{
		return [];
	}
	
	public function renderBackground():Array<NativeElement>
	{
		return [];
	}
	
	private function setLayerRenderer(value:LayerRenderer):LayerRenderer
	{
		return _layerRenderer = value;
	}
	
	private function getLayerRenderer():LayerRenderer
	{
		return _layerRenderer;
	}
	
	private function getDOMElement():DOMElement
	{
		return _domElement;
	}
	
	private function getParent():FlowBoxRenderer
	{
		return _parent;
	}
	
	private function setParent(value:FlowBoxRenderer):FlowBoxRenderer
	{
		return _parent = value;
	}
	
	private function getBounds():RectangleData
	{
		return _bounds;
	}
	
	private function setBounds(value:RectangleData):RectangleData
	{
		return _bounds = value;
	}
	
}