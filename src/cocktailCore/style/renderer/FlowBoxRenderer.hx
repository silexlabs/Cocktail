package cocktailCore.style.renderer;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FlowBoxRenderer extends BoxRenderer
{

	private var _children:Array<ElementRenderer>;
	public var children(getChildren, never):Array<ElementRenderer>;
	
	private var lineBoxeRenderers:Array<LineBoxRenderer>;
	
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_children = new Array<ElementRenderer>();
	}
	
	public function addChild(elementRenderer:ElementRenderer):Void
	{
		_children.push(elementRenderer);
	}
	
	public function removeChild(elementRenderer:ElementRenderer):Void
	{
		_children.remove(elementRenderer);
	}
	
	override public function canHaveChildren():Bool
	{
		return true;
	}
	
	private function getChildren():Array<ElementRenderer>
	{
		return _children;
	}
	
	
}