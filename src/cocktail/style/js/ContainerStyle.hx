package cocktail.style.js;
import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractContainerStyle;
import cocktail.style.StyleData;


/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		
	}
}