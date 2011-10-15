package cocktail.style.computer;
import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.Style;
import cocktail.style.StyleData;
import haxe.Log;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BoxComputer 
{

	private static var NULL:Int = -1;
	
	public function new() 
	{
		
	}
	
	
	public function measure(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):ComputedStyleData
	{
		
		//get the left padding thickness in pixel 
		var computedPaddingLeft:Int = getComputedPadding(style.paddingLeft, containingDOMElementDimensions.width);
		
		
		//right padding
		var computedPaddingRight:Int = getComputedPadding(style.paddingRight, containingDOMElementDimensions.width);
		

		var isWidthAuto:Bool = style.width == DimensionStyleValue.auto;
		
		var computedWidth:Int;
		var computedMarginLeft:Int;
		var computedMarginRight:Int;
		
		if (isWidthAuto == true)
		{
			computedWidth = NULL;
			
			//left margin
			computedMarginLeft = getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementDimensions.width, computedWidth, isWidthAuto, computedPaddingRight + computedPaddingLeft);
		
			//right margin
			computedMarginRight = getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementDimensions.width, computedWidth, isWidthAuto, computedPaddingRight + computedPaddingLeft);
		
			computedWidth = containingDOMElementDimensions.width - computedPaddingLeft - computedPaddingRight - computedMarginLeft - computedMarginRight;
		}
		else
		{
			//get the content width (width without margins and paddings)
			computedWidth = getComputedDimension(style.width, containingDOMElementDimensions.width);
			
			//left margin
			computedMarginLeft = getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementDimensions.width, computedWidth, isWidthAuto, computedPaddingRight + computedPaddingLeft);
		
			//right margin
			computedMarginRight = getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementDimensions.width, computedWidth, isWidthAuto, computedPaddingRight + computedPaddingLeft);
		
		}
		
		
		/**
		 * HEIGHT
		 */
		
		//top padding
		var computedPaddingTop:Int = getComputedPadding(style.paddingTop, containingDOMElementDimensions.height);
		
		//bottom padding
		var computedPaddingBottom:Int = getComputedPadding(style.paddingBottom, containingDOMElementDimensions.height);
		
		//get the content height (height without margins and paddings)
		//the height might be null at this point if must take the content size
		//it will be set once all the children DOMElement have been laid out
		//var computedHeight:Int = getComputedDimension(styleData.height, containingDOMElementDimensions.height);
		
		var isHeightAuto:Bool = style.height == DimensionStyleValue.auto;
		
		var computedHeight:Int;
		var computedMarginTop:Int;
		var computedMarginBottom:Int;
		
		if (isHeightAuto == true)
		{
			computedHeight = NULL;
			
			//left margin
			computedMarginTop = getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementDimensions.height, computedHeight, isHeightAuto, computedPaddingTop + computedPaddingBottom);
		
			//right margin
			computedMarginBottom = getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementDimensions.height, computedHeight, isHeightAuto, computedPaddingTop + computedPaddingBottom);
		
			
		}
		else
		{
			//get the content width (width without margins and paddings)
			computedHeight = getComputedDimension(style.height, containingDOMElementDimensions.height);
			
			//left margin
			computedMarginTop = getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementDimensions.height, computedHeight, isHeightAuto, computedPaddingTop + computedPaddingBottom);
		
			//right margin
			computedMarginBottom = getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementDimensions.height, computedHeight, isHeightAuto, computedPaddingTop + computedPaddingBottom);
		
		}
		
		/**
		* The next step is to compute the dimensions
		* constraint style (max-width, min-height...)
		* and check that the computed height and width
		* enforce those constraint
		*/
		
		//max height
		var computedMaxHeight:Int  = getComputedConstrainedDimension(style.maxHeight, containingDOMElementDimensions.height);
		
		//min height
		var computedMinHeight:Int = getComputedConstrainedDimension(style.minHeight, containingDOMElementDimensions.height, true);
		
		//max width
		var computedMaxWidth:Int  = getComputedConstrainedDimension(style.maxWidth, containingDOMElementDimensions.width);
		
		//min width
		var computedMinWidth:Int = getComputedConstrainedDimension(style.minWidth, containingDOMElementDimensions.width, true);
		
		
		var computedLeft:Int = getComputedPositionOffset(style.left, containingDOMElementDimensions.width);
		
		var computedRight:Int = getComputedPositionOffset(style.right, containingDOMElementDimensions.width);
		
		var computedTop:Int = getComputedPositionOffset(style.top, containingDOMElementDimensions.height);
		
		var computedBottom:Int = getComputedPositionOffset(style.bottom, containingDOMElementDimensions.height);
		
		
		
		var computedDisplay:DisplayStyleValue = style.computedStyle.display;
		
		var computedFloat:FloatStyleValue = style.computedStyle.float;
		
		var computedClear:ClearStyleValue = style.computedStyle.clear;
		
		var computedPosition:PositionStyleValue = style.computedStyle.position;
		
		var computedStyleData:ComputedStyleData = {
			width : computedWidth,
			height : computedHeight,
			minHeight : computedMinHeight,
			maxHeight : computedMaxHeight,
			minWidth : computedMinWidth,
			maxWidth : computedMaxWidth,
			offsetWidth : computedWidth + computedMarginLeft + computedPaddingLeft + computedMarginRight + computedPaddingRight,
			offsetHeight : computedHeight + computedMarginTop + computedPaddingTop + computedMarginBottom + computedPaddingBottom,
			marginLeft : computedMarginLeft,
			marginRight : computedMarginRight,
			marginTop : computedMarginTop,
			marginBottom : computedMarginBottom,
			paddingLeft : computedPaddingLeft,
			paddingRight : computedPaddingRight,
			paddingTop : computedPaddingTop,
			paddingBottom : computedPaddingBottom,
			left: computedLeft,
			right: computedRight,
			top: computedTop,
			bottom : computedBottom,
			clear : computedClear,
			float : computedFloat,
			display : computedDisplay,
			position:computedPosition
		}
		
		computedStyleData = constrainDimensions(computedStyleData);
		
		/**
		 * At this point, all the dimensions of the DOMElement are known maybe except the
		 * content height. Those dimensions are now enough to position each of the DOMElement's
		 * children
		 */
		
		return computedStyleData;
	}
	
	private function applyOffsetDimensions(styleData:Style, computedStyle:ComputedStyleData):Void
	{
		//Should it be here ?
		
		/** if (styleData.width == DimensionStyleValue.auto)
		 {
			 if (computedStyle.left != 0 && computedStyle.right != 0)
			 {
				 this.width = containingDOMElementDimensions.width - computedLeft - computedRight;
			 }
		 }
		 
		 if (styleData.height == DimensionStyleValue.auto)
		 {
			 if (computedTop != 0 && computedBottom != 0)
			 {
				 this.height = containingDOMElementDimensions.height - computedTop - computedBottom;
			 }
		 }*/
	}
	
	private function constrainDimensions(computedStyle:ComputedStyleData):ComputedStyleData
	{
		//check that the computedWidth is not 
		//superior to max width. The max width
		//can be defined as "null" if there are 
		//no width limit on this DOMElement
		if (computedStyle.maxWidth != NULL)
		{
			if (computedStyle.width > computedStyle.maxWidth)
			{
				computedStyle.width = computedStyle.maxWidth;
			}
		}
		
		//check that width is superior to min width
		if (computedStyle.width < computedStyle.minWidth)
		{
			computedStyle.width = computedStyle.minWidth;
		}
		
		//at this point the computed height might still
		//be null if no fixed height was defined for this
		//DOMElement, in this case, the max height will
		//be checked again once the height of the DOMElement
		//has been defined
		if (computedStyle.height != NULL)
		{
			//check that height is within authorised range
			if (computedStyle.maxHeight != NULL)
			{
				if (computedStyle.height > computedStyle.maxHeight)
				{
					computedStyle.height = computedStyle.maxHeight;
				}
			}
			
			//check that height is superior to min height
			if (computedStyle.height < computedStyle.minHeight)
			{
				computedStyle.height = computedStyle.minHeight;
			}
		}
		
		return computedStyle;
	}
	
	/**
	 * Compute the value of a margin thickness from a 
	 * margin style value
	 * @param	marginStyleValue contains the value of the computed margin as a unit, percentage or defined as auto
	 * @param	opositeMarginStyleValue the complementary margin from the computed margin. For example for the left margin, it
	 * is the right margin
	 * @param	containingDOMElementDimension the width and height of the DOMElement containing the current DOMElement, used for
	 * computing percentage values
	 * @param	computedDimension a computed dimension (width or height) of the content of the current DOMElement
	 * @param isDimensionAuto wether the reference dimensions is auto, meaning its computed width id not set yet
	 * @param	computedPaddingsDimension the computed dimensions of both horizontal or vertical paddings, depending if the computed
	 * margin is horizontal or vertical
	 * @param	isHorizontalMargin true if the margin is horizontal (left or right)
	 * @return the computed thickness of the margin
	 */
	private function getComputedMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, isHorizontalMargin:Bool = false ):Int
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
			
			//auto margins take the remaining place left after
			//paddings, other margin and dimension are set
			case auto:	
				//if the containing dimension (most likely height) is undefined or if it is set to auto,
				//margin default to 0. Top and bottom margin also default to 0 with
				//an auto value
				if (containingDOMElementDimension == NULL || isHorizontalMargin == true || isDimensionAuto == true)
				{
					computedMargin = 0;
				}
				//if the margin is either left or right the containing width is defined
				else
				{
					//check if the oposite margin is set to auto too
					switch (opositeMarginStyleValue)
					{
						//if it is, then both margin have the same thickness and share the place left by the content and paddings
						case auto:
							computedMargin = Math.round((containingDOMElementDimension - computedDimension - computedPaddingsDimension) / 2);
						
						//else the oposite margin thickness is computed and the computed margin is deduced from the remaining space	
						default:
							var opositeComputedMargin = getComputedMargin(opositeMarginStyleValue, marginStyleValue, containingDOMElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension);
							computedMargin = containingDOMElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin; 
					}
				}
		}
		
		return computedMargin;
	}
	
	/**
	 * Compute a contrain dimensions (max-height, min-width...)
	 * from a contrain style value
	 * @param	constrainedDimensionStyleValue can be defined as a unit, a percentage
	 * or to "none" if no constraint must be applied
	 * @param	containingDOMElementDimension the dimension of the DOMElement into which 
	 * the current DOMElement must fit
	 * @param	isMinConstraint true if min-width or min-height is computed
	 * @return a computed contraint dimensions in pixels
	 */
	private function getComputedConstrainedDimension(constrainedDimensionStyleValue:ConstrainedDimensionStyleValue, containingDOMElementDimension:Int, isMinConstraint:Bool = false):Int
	{
		var computedConstraintDimension:Int;
		
		//check which type of value is defined
		switch (constrainedDimensionStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedConstraintDimension = getValueFromLength(value);
			
			//It's a percentage, compute it from the containing dimension	
			case percent(value):
				//if the containing DOMElement is not defined,
				//for min value default to 0, for max value,
				//default to "null" (no constraints)
				if (containingDOMElementDimension == NULL)
				{
					if (isMinConstraint == true)
					{
						computedConstraintDimension = 0;
					}
					else
					{
						computedConstraintDimension = NULL;
					}
				}
				else
				{
					computedConstraintDimension = getValueFromPercent(value, containingDOMElementDimension);
				}
				
			//here no constraint are applied,
			//defaults are set
			case none:
				if (isMinConstraint == true)
				{
					computedConstraintDimension = 0;
				}
				else 
				{
					computedConstraintDimension = NULL;
				}
		}
		
		return computedConstraintDimension;
	}
	
	private function getComputedPositionOffset(positionOffsetStyleValue:PositionOffsetStyleValue, containingDOMElementDimension:Int):Int
	{
		var computedPositionOffset:Int;
		
		switch(positionOffsetStyleValue)
		{
			case length(value):
				computedPositionOffset = getValueFromLength(value);
				
			case percent(value):
				computedPositionOffset = getValueFromPercent(value, containingDOMElementDimension);
				
			case auto:
				computedPositionOffset = 0;
		}
		
		return computedPositionOffset;
	}
	
	/**
	 * Compute the content dimension (width or height) of a DOMElement
	 * @param	dimensionStyleValue can be defined as a unit, a percent or auto
	 * @param	containingDOMElementDimension the dimension of the DOMElement into which 
	 * the current DOMElement must fit
	 * @return a computed dimension in pixel
	 */
	private function getComputedDimension(dimensionStyleValue:DimensionStyleValue, containingDOMElementDimension:Int):Int
	{
		var computedDimensions:Int;
		
		//check which type of value is defined
		switch (dimensionStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedDimensions = getValueFromLength(value);
			
			//It's a percentage, compute it from the containing dimension	
			case percent(value):
				
				if (containingDOMElementDimension == NULL)
				{
					//TO DO
					computedDimensions = 0;
				}
				else
				{
					computedDimensions = getValueFromPercent(value, containingDOMElementDimension);
				}
				
			case auto:
				//TO DO
				computedDimensions = NULL;
		}
		
		return computedDimensions;
	}
	
	/**
	 * Compute a padding's thickness from a padding style value
	 * @param	paddingStyleValue can be defined as a unit (px, em...) or a percentage
	 * @param	containingDOMElementDimension the dimensions of the DOMElement into which 
	 * the current DOMElement must fit
	 * @return a computed padding in pixel
	 */
	private function getComputedPadding(paddingStyleValue:PaddingStyleValue, containingDOMElementDimension:Int):Int
	{
		var computedPaddingValue:Int;
		
		//check which type of value is defined
		switch (paddingStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedPaddingValue = getValueFromLength(value);
			
			//It's a percentage, compute it from the containing dimension		
			case percent(value):
				//if containing dimension is not defined, padding defaults
				//to 0
				if (containingDOMElementDimension == NULL)
				{
					computedPaddingValue = 0;
				}
				else
				{
					computedPaddingValue = getValueFromPercent(value, containingDOMElementDimension);
				}
				
		}
		
		return computedPaddingValue;
	}
	
	/**
	 * Get a value in pixel 
	 * from a unit value
	 * (px, em, cm...)
	 * @param	length contains the unit type and the value
	 */
	private function getValueFromLength(length:LengthValue):Int
	{
		var lengthValue:Int;
		
		switch (length)
		{
			case pixel(value):
				lengthValue = value;
		}
		
		return lengthValue;
	}
	
	/**
	 * Get a percentage of a reference value
	 * @param	percent form 0 to 100
	 * @param	reference the reference value
	 * @return a percentage of the reference value
	 */
	private function getValueFromPercent(percent:Int, reference:Int):Int
	{
		return Math.round(reference * (percent * 0.01));
	}
	
}