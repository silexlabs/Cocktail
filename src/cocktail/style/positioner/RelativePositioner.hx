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
	
	override public function position(domElement:DOMElement, containingDOMElement:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{

		var containingDOMElementDimensions:ContainingDOMElementDimensions = {
			width : containingDOMElement.width,
			height : containingDOMElement.height
		}
		
		applyOffset(domElement, containingDOMElementDimensions);
	}
	
}