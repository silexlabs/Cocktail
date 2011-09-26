package cocktail.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.domElement.DOMElementData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class StyledDOMElement extends AbstractDOMElement
{

	private var _style:StyleData;
	public var style(getStyle, setStyle):StyleData;
	
	private var _computedStyle:ComputedStyleData;
	public var computedStyle(getComputedStyle, never):ComputedStyleData;
	
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public layout method
	// main entry point for layout algorithm
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function applyStyle(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElement:StyledDOMElement):Void
	{
		layout(containingDOMElementDimensions);
		position(rootDOMElement, rootDOMElement);
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
	public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions):ComputedStyleData
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
		
		//margin top
		var computedMarginTop:Int = getComputedMargin(this.style.marginTop, this.style.marginBottom, containingDOMElementDimensions.height, computedHeight, computedPaddingTop + computedPaddingBottom, true);
		
		//margin bottom
		var computedMarginBottom:Int = getComputedMargin(this.style.marginBottom, this.style.marginTop, containingDOMElementDimensions.height, computedHeight, computedPaddingTop + computedPaddingBottom, true);
		
		/**
		* The next step is to compute the dimensions
		* constraint style (max-width, min-height...)
		* and check that the computed height and width
		* enforce those constraint
		*/
		
		//max height
		var computedMaxHeight:Int  = getComputedConstrainedDimension(this.style.maxHeight, containingDOMElementDimensions.height);
		
		//min height
		var computedMinHeight:Int = getComputedConstrainedDimension(this.style.minHeight, containingDOMElementDimensions.height, true);
		
		//max width
		var computedMaxWidth:Int  = getComputedConstrainedDimension(this.style.maxWidth, containingDOMElementDimensions.width);
		
		//min width
		var computedMinWidth:Int = getComputedConstrainedDimension(this.style.minWidth, containingDOMElementDimensions.width, true);
		
		
		var computedLeft:Int = getComputedPositionOffset(this.style.left, containingDOMElementDimensions.width);
		
		var computedRight:Int = getComputedPositionOffset(this.style.right, containingDOMElementDimensions.width);
		
		var computedTop:Int = getComputedPositionOffset(this.style.top, containingDOMElementDimensions.height);
		
		var computedBottom:Int = getComputedPositionOffset(this.style.bottom, containingDOMElementDimensions.height);
		
		
		//check that the computedWidth is not 
		//superior to max width. The max width
		//can be defined as "null" if there are 
		//no width limit on this DOMElement
		if (computedMaxWidth != NULL)
		{
			if (computedWidth > computedMaxWidth)
			{
				computedWidth = computedMaxWidth;
			}
		}
		
		//check that width is superior to min width
		if (computedWidth < computedMinWidth)
		{
			computedWidth = computedMinWidth;
		}
		
		//at this point the computed height might still
		//be null if no fixed height was defined for this
		//DOMElement, in this case, the max height will
		//be checked again once the height of the DOMElement
		//has been defined
		if (computedHeight != NULL)
		{
			//check that height is within authorised range
			if (computedMaxHeight != NULL)
			{
				if (computedHeight > computedMaxHeight)
				{
					computedHeight = computedMaxHeight;
				}
			}
			
			//check that height is superior to min height
			if (computedHeight < computedMinHeight)
			{
				computedHeight = computedMinHeight;
			}
		}
		
		/**
		 * At this point, all the dimensions of the DOMElement are known maybe except the
		 * content height. Those dimensions are now enough to position each of the DOMElement's
		 * children
		 */
		
		 if (this.style.width == DimensionStyleValue.auto)
		 {
			 if (computedLeft != 0 && computedRight != 0)
			 {
				 this.width = containingDOMElementDimensions.width - computedLeft - computedRight;
			 }
		 }
		 
		 if (this.style.height == DimensionStyleValue.auto)
		 {
			 if (computedTop != 0 && computedBottom != 0)
			 {
				 this.height = containingDOMElementDimensions.height - computedTop - computedBottom;
			 }
		 }
		 
		
		var flowData:FlowData = {
			x : computedPaddingLeft,
			y : computedPaddingTop,
			totalHeight : 0,
			maxLineHeight : 0
		}
		
	
		
		var domElementDimensions:ContainingDOMElementDimensions = {
			width: computedWidth,
			height: computedHeight
		}
		
		
		
		
		for (i in 0...this._children.length)
		{
			var childDOMElement:StyledDOMElement = cast(this._children[i]);
			
			var computedStyleData:ComputedStyleData = childDOMElement.layout(domElementDimensions);
			
			switch (childDOMElement.style.display)
			{
				case none:
					continue;
				
				case block:
					switch (childDOMElement.style.position)
					{
						case _static:
		
							flowData = applyBlockFlow(flowData, computedPaddingLeft, childDOMElement, computedStyleData);
							
						case relative:
							
							flowData = applyBlockFlow(flowData, computedPaddingLeft, childDOMElement, computedStyleData);
							
							applyOffset(childDOMElement, computedStyleData, containingDOMElementDimensions);
							
						case absolute:
							
							//applyPosition(childDOMElement, lastPositionedDOMElement, computedStyleData);
							
						case fixed:
							
							//applyPosition(childDOMElement, rootDOMElement, computedStyleData);
							
					}
					
				case _inline:
					//TO DO
					
				case inlineBlock:
					switch (childDOMElement.style.position)
					{
						case _static:
							
							flowData = applyBlockInlineFlow(flowData, computedPaddingLeft, childDOMElement, computedStyleData, containingDOMElementDimensions);
							
						case relative:
							
							flowData = applyBlockInlineFlow(flowData, computedPaddingLeft, childDOMElement, computedStyleData, containingDOMElementDimensions);
							
							applyOffset(childDOMElement, computedStyleData, containingDOMElementDimensions);
							
						case absolute:
							
							//applyPosition(childDOMElement, lastPositionedDOMElement, computedStyleData);
							
						case fixed:
							
							//applyPosition(childDOMElement, rootDOMElement, computedStyleData);
					}
			}
			
			
		}
		
		if (computedHeight == NULL)
		{
			computedHeight = flowData.totalHeight;
			
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
		
		//this.width = computedWidth;
		//this.height = computedHeight;
		
		var computedStyleData:ComputedStyleData = {
			width : computedWidth,
			height : computedHeight,
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
			bottom : computedBottom
		}
		
		this._computedStyle = computedStyleData;
		
		return computedStyleData;
	}
	
	public function position(lastPositionedDOMElement:StyledDOMElement, rootDOMElement:StyledDOMElement):Void
	{
		switch (this.style.position)
		{
			case relative, absolute, fixed :
				lastPositionedDOMElement = this;
				
			default:	
		}
		
		
		for (i in 0...this._children.length)
		{
			var childDOMElement:StyledDOMElement = cast(this._children[i]);
			
			childDOMElement.position(lastPositionedDOMElement, rootDOMElement);
			switch (childDOMElement.style.position)
			{
				case absolute:
						
					applyPosition(childDOMElement, lastPositionedDOMElement);
						
				case fixed:
						
					applyPosition(childDOMElement, rootDOMElement);
					
				default:
			}
			
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private layout methods
	// Utilities method to help the main layout method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function applyBlockInlineFlow(flowData:FlowData, computedPaddingLeft:Int, domElement:StyledDOMElement, computedStyleData:ComputedStyleData, containingDOMElementDimensions:ContainingDOMElementDimensions):FlowData
	{
		if (flowData.x + computedStyleData.offsetWidth <= containingDOMElementDimensions.width)
		{
			return applyInlineFlow(flowData, domElement, computedStyleData, containingDOMElementDimensions);
		}
		else
		{
			return applyBlockFlow(flowData, computedPaddingLeft, domElement, computedStyleData);
		}
	}
	
	private function applyBlockFlow(flowData:FlowData, computedPaddingLeft:Int, domElement:StyledDOMElement, computedStyleData:ComputedStyleData):FlowData
	{
		flowData.x = computedPaddingLeft;
						
		domElement.x = flowData.x + computedStyleData.marginLeft + computedStyleData.paddingLeft;
		domElement.y = flowData.y + flowData.maxLineHeight + computedStyleData.marginTop + computedStyleData.paddingTop;
		
		flowData.y += computedStyleData.height + computedStyleData.marginTop + 
		computedStyleData.paddingTop + computedStyleData.paddingBottom + computedStyleData.marginBottom;
		
		flowData.maxLineHeight = 0;
		
		return flowData;
	}
	
	private function applyInlineFlow(flowData:FlowData, domElement:StyledDOMElement, computedStyleData:ComputedStyleData, containingDOMElementDimensions:ContainingDOMElementDimensions ):FlowData
	{			
		
		domElement.x = flowData.x + computedStyleData.marginLeft + computedStyleData.paddingLeft;
		domElement.y = flowData.y + computedStyleData.marginTop + computedStyleData.paddingTop;
				
		flowData.x += computedStyleData.offsetWidth;
					
		if (computedStyleData.offsetHeight > flowData.maxLineHeight)
		{
			flowData.maxLineHeight = computedStyleData.offsetHeight;
		}
			
		return flowData;
	}
	
	private function applyOffset(domElement:StyledDOMElement, computedStyleData:ComputedStyleData, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		if (computedStyleData.left != 0)
		{
			domElement.x += computedStyleData.left;
		}
		else if (computedStyleData.right != 0)
		{
			domElement.x = containingDOMElementDimensions.width - computedStyleData.width;
			domElement.x -= computedStyleData.right;
		}
		
		if (computedStyleData.top != 0)
		{
			domElement.y += computedStyleData.top;
		}
		else if (computedStyleData.bottom != 0)
		{
			domElement.y = containingDOMElementDimensions.height - computedStyleData.height;
			domElement.y -= computedStyleData.bottom;
		}
	}
	
	private function applyPosition(domElement:StyledDOMElement, containingDOMElement:StyledDOMElement):Void
	{
		var referenceGlobalX:Int = containingDOMElement.globalX;
	
		var referenceGlobalY:Int = containingDOMElement.globalY;
		
		domElement.globalX = referenceGlobalX;
		domElement.globalY = referenceGlobalY;
		
		var containingDOMElementDimensions:ContainingDOMElementDimensions = {
			width : containingDOMElement.computedStyle.width,
			height : containingDOMElement.computedStyle.height
		}
		
		applyOffset(domElement, domElement.computedStyle, containingDOMElementDimensions);
		
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
	 * @param	computedPaddingsDimension the computed dimensions of both horizontal or vertical paddings, depending if the computed
	 * margin is horizontal or vertical
	 * @param	isHorizontalMargin true if the margin is horizontal (left or right)
	 * @return the computed thickness of the margin
	 */
	private function getComputedMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, computedPaddingsDimension:Int, isHorizontalMargin:Bool = false ):Int
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
				//if the containing dimension (most likely height) is undefined,
				//margin default to 0. Top and bottom margin also default to 0 with
				//an auto value
				if (containingDOMElementDimension == NULL || isHorizontalMargin == true)
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
							var opositeComputedMargin = getComputedMargin(opositeMarginStyleValue, marginStyleValue, containingDOMElementDimension, computedDimension, computedPaddingsDimension);
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	public function getComputedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
}