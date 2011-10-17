package cocktail.style.computer;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class PositionedBoxComputer extends BoxComputer
{

	public function new() 
	{
		super();
	}
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right, used if the DOMElement
	 * is 'positioned' (position style other than 'static')
	 */
	override private function measurePositionOffsets(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		super.measurePositionOffsets(style, containingDOMElementDimensions);
		
		if (style.width == DimensionStyleValue.auto)
		{
			
			if (style.left != PositionOffsetStyleValue.auto && style.right != PositionOffsetStyleValue.auto)
			{
				
				var computedStyle:ComputedStyleData = style.computedStyle;
				style.computedStyle.width = containingDOMElementDimensions.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.marginLeft - computedStyle.marginRight; 

			}
		}
		
		if (style.height == DimensionStyleValue.auto)
		{
			if (style.top != PositionOffsetStyleValue.auto && style.bottom != PositionOffsetStyleValue.auto)
			{
				var computedStyle:ComputedStyleData = style.computedStyle;
				style.computedStyle.height = containingDOMElementDimensions.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;

			}
		}
		
	}
	
}