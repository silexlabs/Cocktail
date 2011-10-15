package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockEmbeddedBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.FloatEmbeddedBoxComputer;
import cocktail.style.computer.InlineBlockEmbeddedBoxComputer;
import cocktail.style.computer.InlineEmbeddedBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.computer.PositionedEmbeddedBoxComputer;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.Style;
import cocktail.style.StyleData;
import haxe.Log;
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
	
	
	
	override public function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		var boxComputer:BoxComputer;
		
		if (isFloat() == true)
		{
			boxComputer = new FloatEmbeddedBoxComputer();
		}
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new PositionedEmbeddedBoxComputer();
		}
		switch(this._computedStyle.display)
		{
			case block:
				boxComputer = new BlocEmbeddedBoxComputer();
				
			case inlineBlock:
				boxComputer = new InlineBlockEmbeddedBoxComputer();	
			
			case none:
				boxComputer = new NoneBoxComputer();
			
			case _inline:
				boxComputer = new InlineEmbeddedBoxComputer();
		}
		
		boxComputer.measure(this, containingDOMElementDimensions);
	}
	
}