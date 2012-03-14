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
	
	private var _lineBoxes:Array<Array<ElementRenderer>>;
	public var lineBoxes(getLineBoxes, never):Array<Array<ElementRenderer>>;
	
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_children = new Array<ElementRenderer>();
		_lineBoxes = new Array<Array<ElementRenderer>>();
	}
	
	public function addChild(elementRenderer:ElementRenderer):Void
	{
		_children.push(elementRenderer);
		elementRenderer.parent = this;
	}
	
	override public function establishesNewFormattingContext():Bool
	{
		return _domElement.style.establishesNewFormattingContext();
	}
	
	public function addLineBox(lineBoxElements:Array<ElementRenderer>):Void
	{
		_lineBoxes.push(lineBoxElements);
	}
	
	public function removeLineBoxes():Void
	{
		_lineBoxes = new Array<Array<ElementRenderer>>();
	}
	
	public function removeChild(elementRenderer:ElementRenderer):Void
	{
		var newChildren:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0..._children.length)
		{
			if (_children[i] != elementRenderer)
			{
				newChildren.push(_children[i]);
			}
		}
		
		_children = newChildren;
	}
	
	override public function isEmbedded():Bool
	{
		return false;
	}
	
	override public function canHaveChildren():Bool
	{
		return true;
	}
	
	private function getChildren():Array<ElementRenderer>
	{
		return _children;
	}
	
	private function getLineBoxes():Array<Array<ElementRenderer>>
	{
		return _lineBoxes;
	}
	
	
}