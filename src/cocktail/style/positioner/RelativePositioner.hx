package cocktail.style.positioner;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class RelativePositioner extends BoxPositioner
{

	public function new() 
	{
		super();
	}
	
	override public function position(domElement:DOMElement, containingDOMElement:DOMElement):Void
	{

		var containingDOMElementDimensions:ContainingDOMElementDimensions = {
			width : containingDOMElement.style.computedStyle.width,
			height : containingDOMElement.style.computedStyle.height
		}
		
		applyOffset(domElement, containingDOMElementDimensions);
	}
	
}