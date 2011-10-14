package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockEmbeddedBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.InlineEmbeddedBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.Style;
import cocktail.style.StyleData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractEmbeddedStyle extends Style
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		flow(containingDOMElementDimensions, null);
		positionElement(lastPositionedDOMElement, rootDOMElement);
	}
	
	override public function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions):ComputedStyleData
	{
		var boxComputer:BoxComputer;
		
		switch(this._computedStyle.display)
		{
			case block, inlineBlock:
				boxComputer = new BlocEmbeddedBoxComputer();
			
			case none:
				boxComputer = new NoneBoxComputer();
			
			case _inline:
				boxComputer = new InlineEmbeddedBoxComputer();
		}
		
		return boxComputer.measure(this._domElement, containingDOMElementDimensions);
	}
	
}