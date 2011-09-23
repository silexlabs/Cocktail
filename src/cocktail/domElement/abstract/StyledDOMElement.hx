package cocktail.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.domElement.DOMElementData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StyledDOMElement extends AbstractDOMElement
{

	private var _style:StyleData;
	public var style(getStyle, setStyle):StyleData;
	
	private var _isDirty:Bool;
	
	private static inline var NULL:Int = -1;
	
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
		_isDirty = false;
	}
	
	public function invalidate():Void
	{
		
	}
	
	public function redraw():Void
	{
		
	}
	
	/**
	 * Main layout method, compute the dimensions of a DOMElement then layout and
	 * place its children recursively
	 * @param	containingDOMElementDimensions the dimensions (width and height) of the DOMElement
	 * into which the current DOMElement must be placed
	 * @param	lastPositionedDOMElement a reference to the last positioned DOMElement, i.e with a "position" 
	 * style different from "static". It is used as origin to place the "absolute" positioned DOMElement
	 * @param	rootDOMElement a reference to the DOMElement at the top of the hierarchy, it is use as origin
	 * to place the "fixed" positioned DOMElements
	 * @return returns the offset dimensions (width and height) of the laid out DOMElement. Those dimensions include
	 * paddings and margins
	 */
	public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:StyledDOMElement, rootDOMElement:StyledDOMElement):OffsetDOMElementDimensions
	{
		/**
		* First, start by computing each value constituting 
		* the DOMElements dimensions : content width and height,
		* paddings and margins. Each of those value is converted
		* into pixel value from percent (relative to the containing
		* DOMElement's dimensions) or unit values (pixel, em, cm...).
		* There are also special value depending on styles such as
		* "none" or "auto"
		*/
		
		/**
		* The width of the DOMElement is retrieved first. As The document flows
		* vertically by default, the width of the containing DOMElement, used
		* to retrive value defined as percentage, is always defined, wheread
		* the containing height might be undefined if all children of the
		* containing DOMElement have not be laid out yet
		*/
		 
		/**
		* WIDTH
		*/ 
		  
		//get the left padding thickness in pixel 
		var computedPaddingLeft:Int = getComputedPadding(this.style.paddingLeft, containingDOMElementDimensions.width);
		
		//right padding
		var computedPaddingRight:Int = getComputedPadding(this.style.paddingRight, containingDOMElementDimensions.width);
		
		//get the content width (width without margins and paddings)
		var computedWidth:Int = getComputedDimension(this.style.width, containingDOMElementDimensions.width);
		
		//left margin
		var computedMarginLeft:Int = getComputedMargin(this.style.marginLeft, this.style.marginRight, containingDOMElementDimensions.width, computedWidth, computedPaddingRight + computedPaddingLeft);
		
		//right margin
		var computedMarginRight:Int = getComputedMargin(this.style.marginRight, this.style.marginLeft, containingDOMElementDimensions.width, computedWidth, computedPaddingRight + computedPaddingLeft);
		
		/**
		 * HEIGHT
		 */
		
		//top padding
		var computedPaddingTop:Int = getComputedPadding(this.style.paddingTop, containingDOMElementDimensions.height);
		
		//bottom padding
		var computedPaddingBottom:Int = getComputedPadding(this.style.paddingBottom, containingDOMElementDimensions.height);
		
		//get the content height (height without margins and paddings)
		//the height might be null at this point if must take the content size
		//it will be set once all the children DOMElement have been laid out
		var computedHeight:Int = getComputedDimension(this.style.height, containingDOMElementDimensions.height);
		
		var computedMarginTop:Int = getComputedMargin(this.style.marginTop, this.style.marginBottom, containingDOMElementDimensions.height, computedHeight, computedPaddingTop + computedPaddingBottom, true);
		
		var computedMarginBottom:Int = getComputedMargin(this.style.marginBottom, this.style.marginTop, containingDOMElementDimensions.height, computedHeight, computedPaddingTop + computedPaddingBottom, true);
		
		var computedMaxHeight:Int  = getComputedConstrainedDimension(this.style.maxHeight, containingDOMElementDimensions.height);
		
		var computedMinHeight:Int = getComputedConstrainedDimension(this.style.minHeight, containingDOMElementDimensions.height, true);
		
		var computedMaxWidth:Int  = getComputedConstrainedDimension(this.style.maxWidth, containingDOMElementDimensions.width);
		
		var computedMinWidth:Int = getComputedConstrainedDimension(this.style.minWidth, containingDOMElementDimensions.width, true);
		
		if (computedMaxWidth != NULL)
		{
			if (computedWidth > computedMaxWidth)
			{
				computedWidth = computedMaxWidth;
			}
		}
		
		if (computedWidth < computedMinWidth)
		{
			computedWidth = computedMinWidth;
		}
		
		if (computedHeight != NULL)
		{
			if (computedMaxHeight != NULL)
			{
				if (computedHeight > computedMaxHeight)
				{
					computedHeight = computedMaxHeight;
				}
			}
			
			if (computedHeight < computedMinHeight)
			{
				computedHeight = computedMinHeight;
			}
		}
		
		
		var flowX:Int = computedMarginLeft + computedPaddingLeft;
		
		var flowY:Int = computedMarginTop + computedPaddingTop;
		
		var totalChildrenHeight:Int = 0;
		
		var maxLineHeight:Int = 0;
		
		var domElementDimensions:ContainingDOMElementDimensions = {
			width: computedWidth,
			height: computedHeight
		}
		
		
		for (i in 0...this._children.length)
		{
			var childDOMElement:StyledDOMElement = cast(this._children[i]);
			
			var childrenOffsetDimensions:OffsetDOMElementDimensions = childDOMElement.layout(domElementDimensions, lastPositionedDOMElement, rootDOMElement);
			
			switch (childDOMElement.style.display)
			{
				case none:
					continue;
				
				case block:
					switch (childDOMElement.style.position)
					{
						case _static:
							
							if (childrenOffsetDimensions.height > maxLineHeight)
							{
								maxLineHeight = childrenOffsetDimensions.height;
							}
							
							flowX = computedMarginLeft + computedPaddingLeft;
							flowY += maxLineHeight;
							
							maxLineHeight = 0;
							
							childDOMElement.x = flowX;
							childDOMElement.y = flowY;
							
						case relative:
							if (childrenOffsetDimensions.height > maxLineHeight)
							{
								maxLineHeight = childrenOffsetDimensions.height;
							}
							
							flowX = computedMarginLeft + computedPaddingLeft;
							flowY += maxLineHeight;
							
							maxLineHeight = 0;
							
							childDOMElement.x = flowX;
							childDOMElement.y = flowY;
							
							var childLeft:PositionOffsetStyleValue = childDOMElement.style.left;
							var childRight:PositionOffsetStyleValue = childDOMElement.style.right;
							var childTop:PositionOffsetStyleValue = childDOMElement.style.top;
							var childBottom:PositionOffsetStyleValue = childDOMElement.style.bottom;
							
							/**
							if (childDOMElement.style.right == 0 || childDOMElement.style.right == null)
							{
								//TO DO
							}*/
							
						case absolute:
							
							var childLeft:PositionOffsetStyleValue = childDOMElement.style.left;
							var childRight:PositionOffsetStyleValue = childDOMElement.style.right;
							var childTop:PositionOffsetStyleValue = childDOMElement.style.top;
							var childBottom:PositionOffsetStyleValue = childDOMElement.style.bottom;
							
						case fixed:
							
							var childLeft:PositionOffsetStyleValue = childDOMElement.style.left;
							var childRight:PositionOffsetStyleValue = childDOMElement.style.right;
							var childTop:PositionOffsetStyleValue = childDOMElement.style.top;
							var childBottom:PositionOffsetStyleValue = childDOMElement.style.bottom;
							
							
							
					}
					
				case _inline:
					//TO DO
					
				case inlineBlock:
					switch (childDOMElement.style.position)
					{
						case _static:
							
						case relative:
							
						case absolute:
							
						case fixed:	
					}
			}
			
			
		}
		
		if (computedHeight == NULL)
		{
			computedHeight = totalChildrenHeight;
			
			if (computedMaxHeight != NULL)
			{
				if (computedHeight > computedMaxHeight)
				{
					computedHeight = computedMaxHeight;
				}
			}
			
			if (computedHeight < computedMinHeight)
			{
				computedHeight = computedMinHeight;
			}
		}
		
		var offsetDOMElementDimensions:OffsetDOMElementDimensions = {
			width : computedMarginLeft + computedPaddingLeft + computedWidth + computedPaddingRight + computedMarginRight,
			height : computedMarginTop + computedPaddingTop + computedHeight + computedPaddingBottom + computedMarginBottom
		}
		
		return offsetDOMElementDimensions;
	}
	
	private function getComputedMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, computedPaddingsDimension:Int, isHorizontalMargin:Bool = false ):Int
	{
		var computedMargin:Int;
		
		switch (marginStyleValue)
		{
			case length(value):
				computedMargin = getValueFromLength(value);
				
			case percent(value): 
				computedMargin = getValueFromPercent(value, containingDOMElementDimension);
				
			case auto:	
				if (containingDOMElementDimension == NULL || isHorizontalMargin == true)
				{
					computedMargin = 0;
				}
				else
				{
					switch (opositeMarginStyleValue)
					{
						case auto:
							computedMargin = Math.round((containingDOMElementDimension - computedDimension - computedPaddingsDimension) / 2);
							
						default:
							var opositeComputedMargin = getComputedMargin(opositeMarginStyleValue, marginStyleValue, containingDOMElementDimension, computedDimension, computedPaddingsDimension);
							computedMargin = containingDOMElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin; 
					}
						
				}
		}
		
		return computedMargin;
	}
	
	private function getComputedConstrainedDimension(constrainedDimensionStyleValue:ConstrainedDimensionStyleValue, containingDOMElementDimension:Int, isMinConstraint:Bool = false):Int
	{
		var computedConstraintDimension:Int;
		
		switch (constrainedDimensionStyleValue)
		{
			case length(value):
				computedConstraintDimension = getValueFromLength(value);
				
			case percent(value):
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
	
	private function getComputedDimension(dimensionStyleValue:DimensionStyleValue, containingDOMElementDimension:Int):Int
	{
		var computedDimensions:Int;
		
		switch (dimensionStyleValue)
		{
			case length(value):
				computedDimensions = getValueFromLength(value);
				
			case percent(value):
				computedDimensions = getValueFromPercent(value, containingDOMElementDimension);
				
			case auto:
				computedDimensions = NULL;
		}
		
		return computedDimensions;
	}
	
	private function getComputedPadding(paddingStyleValue:PaddingStyleValue, containingDOMElementDimension:Int):Int
	{
		var computedPaddingValue:Int;
		
		switch (paddingStyleValue)
		{
			case length(value):
				computedPaddingValue = getValueFromLength(value);
				
			case percent(value):
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
	
	private function getValueFromPercent(percent:Int, reference:Int):Int
	{
		return Math.round(reference * (percent * 0.01));
	}
	
	public function getStyle():StyleData
	{
		return this._style;
	}
	
	public function setStyle(value:StyleData):StyleData
	{
		this._style = value;
		invalidate();
		return this._style;
	}
	
}