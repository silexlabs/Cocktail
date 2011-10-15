package cocktail.style.computer;
import cocktail.style.StyleData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class InlineEmbeddedBoxComputer extends BoxComputer
{
	private static var NULL:Int = -1;

	public function new() 
	{
		super();
	}
	/**
	override private function getComputedMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, isHorizontalMargin:Bool = false ):Int
	{
		//the return value
		var computedMargin:Int;
		
		//check which type of value is defined
		switch (marginStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedMargin = getValueFromLength(value);
			
			//It's a percentage, compute it from the containing dimension
			case percent(value): 
				
				//margin default to 0 if containing dimension is undefined
				if (containingDOMElementDimension == NULL)
				{
					computedMargin = 0;
				}
				else
				{
					computedMargin = getValueFromPercent(value, containingDOMElementDimension);
				}
			
			case auto:	
				computedMargin = 0;
		}
		
		return computedMargin;
	}
	*/
}