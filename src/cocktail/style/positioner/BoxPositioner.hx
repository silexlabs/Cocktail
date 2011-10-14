package cocktail.style.positioner;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BoxPositioner 
{

	public function new() 
	{
		
	}
	
	public function position(domElement:DOMElement, containingDOMElement:DOMElement):Void
	{
		var referenceGlobalX:Int = containingDOMElement.globalX;
	
		var referenceGlobalY:Int = containingDOMElement.globalY;
		
		domElement.globalX = referenceGlobalX;
		domElement.globalY = referenceGlobalY;
		
		var containingDOMElementDimensions:ContainingDOMElementDimensions = {
			width : containingDOMElement.style.computedStyle.width,
			height : containingDOMElement.style.computedStyle.height
		}
		
		applyOffset(domElement, containingDOMElementDimensions);
	}
	
	private function applyOffset(domElement:DOMElement, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		if (domElement.style.computedStyle.left != 0)
		{
			domElement.x += domElement.style.computedStyle.left;
		}
		else if (domElement.style.computedStyle.right != 0)
		{
			domElement.x = containingDOMElementDimensions.width - domElement.style.computedStyle.width;
			domElement.x -= domElement.style.computedStyle.right;
		}
		
		if (domElement.style.computedStyle.top != 0)
		{
			domElement.y += domElement.style.computedStyle.top;
		}
		else if (domElement.style.computedStyle.bottom != 0)
		{
			domElement.y = containingDOMElementDimensions.height - domElement.style.computedStyle.height;
			domElement.y -= domElement.style.computedStyle.bottom;
		}
	}
	
}