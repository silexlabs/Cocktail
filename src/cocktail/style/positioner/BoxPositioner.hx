package cocktail.style.positioner;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BoxPositioner 
{

	public function new() 
	{
		
	}
	
	public function position(domElement:DOMElement, containingDOMElement:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		var referenceGlobalX:Int = containingDOMElement.globalX;
		Log.trace(referenceGlobalX);
		var referenceGlobalY:Int = containingDOMElement.globalY;
		
		domElement.globalX = referenceGlobalX;
		domElement.globalY = referenceGlobalY;
		
		var containingDOMElementDimensions:ContainingDOMElementDimensions = {
			width : containingDOMElement.width,
			height : containingDOMElement.height
		}
		
		applyOffset(domElement, containingDOMElementDimensions);
	}
	
	private function applyOffset(domElement:DOMElement, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		if (domElement.style.left != PositionOffsetStyleValue.auto)
		{
			//Log.trace(domElement.style.computedStyle.left);
			domElement.x += domElement.style.computedStyle.left;
		}
		else if (domElement.style.right != PositionOffsetStyleValue.auto)
		{
			domElement.x = containingDOMElementDimensions.width - domElement.style.computedStyle.width;
			domElement.x -= domElement.style.computedStyle.right;
		}
		
		if (domElement.style.top != PositionOffsetStyleValue.auto)
		{
			domElement.y += domElement.style.computedStyle.top;
		}
		else if (domElement.style.bottom != PositionOffsetStyleValue.auto)
		{
			domElement.y = containingDOMElementDimensions.height - domElement.style.computedStyle.height;
			domElement.y -= domElement.style.computedStyle.bottom;
		}
	}
	
}