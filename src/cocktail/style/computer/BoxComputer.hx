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
	
	
	public function measure(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		measureHorizontalPaddings(style, containingDOMElementDimensions);
		
		measureWidthAndHorizontalMargins(style, containingDOMElementDimensions);

		
		measureVerticalPaddings(style, containingDOMElementDimensions);
		
		measureHeightAndVerticalMargins(style, containingDOMElementDimensions);
		
		
		/**
		* The next step is to compute the dimensions
		* constraint style (max-width, min-height...)
		* and check that the computed height and width
		* enforce those constraint
		*/
		measureDimensionsConstraints(style, containingDOMElementDimensions);
		
		measurePositionOffsets(style, containingDOMElementDimensions);
		
		
		constrainDimensions(style.computedStyle);
		/**
		 * At this point, all the dimensions of the DOMElement are known maybe except the
		 * content height. Those dimensions are now enough to position each of the DOMElement's
		 * children
		 */
	}
	
	private function measureDimensionsConstraints(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//max height
		style.computedStyle.maxHeight = getComputedConstrainedDimension(style.maxHeight, containingDOMElementDimensions.height);
		
		//min height
		style.computedStyle.minHeight = getComputedConstrainedDimension(style.minHeight, containingDOMElementDimensions.height, true);
		
		//max width
		style.computedStyle.maxWidth  = getComputedConstrainedDimension(style.maxWidth, containingDOMElementDimensions.width);
		
		//min width
		style.computedStyle.minWidth = getComputedConstrainedDimension(style.minWidth, containingDOMElementDimensions.width, true);
	}
	
	private function measurePositionOffsets(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementDimensions.width);
		
		style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementDimensions.width);
		
		style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementDimensions.height);
		
		style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementDimensions.height);
	}
	
	private function measureHorizontalPaddings(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//get the left padding thickness in pixel 
		style.computedStyle.paddingLeft = getComputedPadding(style.paddingLeft, containingDOMElementDimensions.width);
		
		//right padding
		style.computedStyle.paddingRight = getComputedPadding(style.paddingRight, containingDOMElementDimensions.width);
	}
	
	private function measureVerticalPaddings(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		style.computedStyle.paddingTop = getComputedPadding(style.paddingTop, containingDOMElementDimensions.height);
		
		style.computedStyle.paddingBottom = getComputedPadding(style.paddingBottom, containingDOMElementDimensions.height);
	}
	
	private function measureWidthAndHorizontalMargins(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		
		if (style.width == DimensionStyleValue.auto)
		{
			measureAutoWidth(style, containingDOMElementDimensions);
		}
		else
		{
			measureWidth(style, containingDOMElementDimensions);
		}
	}
	
	private function measureAutoWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		style.computedStyle.width = NULL;
			
		//left margin
		style.computedStyle.marginLeft = getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementDimensions.width, style.computedStyle.width, true, style.computedStyle.paddingRight + style.computedStyle.paddingLeft);
		
		//right margin
		style.computedStyle.marginRight = getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementDimensions.width, style.computedStyle.width, true, style.computedStyle.paddingRight + style.computedStyle.paddingLeft);
		
		style.computedStyle.width = containingDOMElementDimensions.width - style.computedStyle.paddingLeft - style.computedStyle.paddingRight - style.computedStyle.marginLeft - style.computedStyle.marginRight;
	}
	
	private function measureWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//get the content width (width without margins and paddings)
		style.computedStyle.width = getComputedWidth(style.width, containingDOMElementDimensions.width);
			
		//left margin
		style.computedStyle.marginLeft = getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementDimensions.width, style.computedStyle.width, false, style.computedStyle.paddingRight + style.computedStyle.paddingLeft);
		
		//right margin
		style.computedStyle.marginRight = getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementDimensions.width, style.computedStyle.width, false, style.computedStyle.paddingLeft + style.computedStyle.paddingRight);
	}
	
	private function getComputedWidth(dimensionStyleValue:DimensionStyleValue, containingDOMElementDimension:Int):Int
	{
		return getComputedDimension(dimensionStyleValue, containingDOMElementDimension);
	}
	
	private function measureHeightAndVerticalMargins(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		
		//get the content height (height without margins and paddings)
		//the height might be null at this point if must take the content size
		//it will be set once all the children DOMElement have been laid out
		
		if (style.height == DimensionStyleValue.auto)
		{
			measureAutoHeight(style, containingDOMElementDimensions);
		}
		else
		{
			measureHeight(style, containingDOMElementDimensions);
		}
	}
	

	private function measureAutoHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		style.computedStyle.height = NULL;
			
		style.computedStyle.marginTop = getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementDimensions.height, style.computedStyle.height, true, style.computedStyle.paddingTop + style.computedStyle.paddingBottom);
		
		style.computedStyle.marginBottom = getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementDimensions.height, style.computedStyle.height, true, style.computedStyle.paddingTop + style.computedStyle.paddingBottom);
	}
	
	private function measureHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		style.computedStyle.height = getComputedHeight(style.height, containingDOMElementDimensions.height);
		
		style.computedStyle.marginTop = getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementDimensions.height, style.computedStyle.height, false, style.computedStyle.paddingTop + style.computedStyle.paddingBottom);
	
		style.computedStyle.marginBottom = getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementDimensions.height, style.computedStyle.height, false, style.computedStyle.paddingTop + style.computedStyle.paddingBottom);
	}
	
	private function getComputedHeight(dimensionStyleValue:DimensionStyleValue, containingDOMElementDimension:Int):Int
	{
		return getComputedDimension(dimensionStyleValue, containingDOMElementDimension);
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
	
	private function constrainDimensions(computedStyle:ComputedStyleData):Void
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