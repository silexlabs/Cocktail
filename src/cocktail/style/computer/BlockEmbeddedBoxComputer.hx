package cocktail.style.computer;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BlockEmbeddedBoxComputer extends BoxComputer
{

	public function new() 
	{
		super();
	}
	
	override private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		var ret:Int = 0;
		
		var embeddedDOMElement:EmbeddedDOMElement = cast(style.domElement);
		
		if (style.height == DimensionStyleValue.auto)
		{
			if (embeddedDOMElement.intrinsicWidth != null)
			{
				ret = embeddedDOMElement.intrinsicWidth;
			}
			else if (embeddedDOMElement.intrinsicHeight != null && embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(embeddedDOMElement.intrinsicHeight * embeddedDOMElement.intrinsicRatio);
			}
			else if (embeddedDOMElement.intrinsicRatio != null)
			{
				//TO DO : 
				//If 'height' and 'width' both have computed values of 'auto' 
				//and the element has an intrinsic ratio but no intrinsic height
				//or width, then the used value of 'width' is undefined in CSS 2.1.
				//However, it is suggested that, if the containing block's width
				//does not itself depend on the replaced element's width,
				//then the used value of 'width' is calculated from the
				//constraint equation used for block-level, non-replaced elements in normal flow. 
				ret = 0;
			}
		}
		else
		{
			var computedHeight:Int = getComputedDimension(style.height, containingDOMElementDimensions.height);
			
			if (embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(computedHeight * embeddedDOMElement.intrinsicRatio);
			}
			else if (embeddedDOMElement.intrinsicWidth != null)
			{
				ret = embeddedDOMElement.intrinsicWidth;
			}
			else
			{
				//TO DO :
				//Otherwise, if 'width' has a computed value of 'auto',
				//but none of the conditions above are met, then the used 
				//value of 'width' becomes 300px. If 300px is too wide to fit the device,
				//UAs should use the width of the largest rectangle that has a 2:1 ratio
				//and fits the device instead. 	
				ret = 0;
			}
		}
		
		return ret;
	}
	
	override private function getComputedAutoHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		var embeddedDOMElement:EmbeddedDOMElement = cast(style.domElement);
		
		var ret:Int = 0;
		
		if (style.width == DimensionStyleValue.auto)
		{
			if (embeddedDOMElement.intrinsicHeight != null)
			{
				ret = embeddedDOMElement.intrinsicHeight;
			}
		}
		else
		{
			var computedWidth:Int = getComputedDimension(style.width, containingDOMElementDimensions.height);
			
			if (embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(computedWidth * embeddedDOMElement.intrinsicRatio);
			}
			else
			{
				//TO DO : 
				//Otherwise, if 'height' has a computed value of 'auto',
				//but none of the conditions above are met, then the used value of 'height'
				//must be set to the height of the largest rectangle that has a 2:1 ratio, has a
				//height not greater than 150px, and has a width not greater than the device width. 
			}
		}
		
		return ret;
	}
	
}