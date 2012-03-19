/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer;

import cocktail.domElement.DOMElement;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.Style;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktailCore.unit.UnitManager;
import haxe.Log;


/**
 * This is the base class for all classes computing a DOMElement's box model. 
 * The box model is determined by a combination of styles such as the display of
 * an element, its width, its margins, paddings...
 * 
 * This class use the defined styles value and compute a value for them that will
 * actually be used. 
 * For example, if a width is determined as a percentage, this class compute
 * a pixel width value from it.
 * 
 * In this base class it is assumed that the DOMElement is a block, non-replaced
 * element, each deriving case as its own inherithing class
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxStylesComputer 
{
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	// Public entry point of this class
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Takes the styles of a domElement and measure each of its box model properties from 
	 * them (paddings, margins, width, height...)
	 * 
	 * Stores all the style computed value in its computed style structure
	 * 
	 * @param	style contains each of a DOMElement styles, a reference to the DOMElement and a structure to
	 * hold computed styles.
	 * @param	containingDOMElementData the width and height dimensions of the containing block of this 
	 * DOMElement, used when computing styles determined as percent or "auto"
	 */
	public function measure(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//measure paddings
		measureHorizontalPaddings(style, containingDOMElementData);
		measureVerticalPaddings(style, containingDOMElementData);
		
		//The next step is to compute the dimensions
		//constraint style (max-width, min-height...)
		//which will be applied each time the computed height
		//or width ae set
		measureDimensionsConstraints(style, containingDOMElementData);
		
		//measure width, height and margins at the same time, as margins can influence or be
		//influenced by the width and height of the DOMElement
		measureWidthAndHorizontalMargins(style, containingDOMElementData);
		measureHeightAndVerticalMargins(style, containingDOMElementData);
		
		//measure the top, left, right and bottom offsets
		//used when the DOMElement is 'positioned' (any position style
		//but 'static')
		measurePositionOffsets(style, containingDOMElementData);
		
		//At this point, all the dimensions of the DOMElement are known maybe except the
		//content height if it was set to 'auto' and thus depends on its content's height.
		//Those dimensions are now enough to layout each of the DOMElement's children.
		//If the parent's height of this DOMElement is set to 'auto', it will use the
		//computed dimensions of this DOMElement to compute its own height.
		 
	}
	
	/**
	 * Shrink the width a DOMElement to fit its content. Doesn't apply to a
	 * non-replaced block so return the current width
	 * @param	style
	 * @param	containingDOMElementData
	 * @param	minimumWidth the minimum width of the DOMElement if shrinked, corresponding 
	 * to its content width
	 * @return
	 */
	public function shrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		return style.computedStyle.width;
	}
	
	/**
	 * Return the height that should be used when the 'height' of a ContainerDOMElement is specified
	 * as 'auto'. The default behaviour is to use the total height of its children
	 * @param	style
	 * @param	cotainingDOMElementData
	 * @param	childrenHeight
	 * @return
	 */
	public function applyContentHeight(style:AbstractStyle, cotainingDOMElementData:ContainingDOMElementData, childrenHeight:Int):Int
	{
		return childrenHeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE MEASURE METHODS
	// Measure the box model and determine
	// the computed styles using the
	// computing methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'dimensions constraints' styles :
	 * min-height, max-height, min-width and max-width
	 */
	private function measureDimensionsConstraints(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//max height
		style.computedStyle.maxHeight = getComputedConstrainedDimension(style.maxHeight, containingDOMElementData.height, containingDOMElementData.isHeightAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//min height
		style.computedStyle.minHeight = getComputedConstrainedDimension(style.minHeight, containingDOMElementData.height, containingDOMElementData.isHeightAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight, true);
		
		//max width
		style.computedStyle.maxWidth  = getComputedConstrainedDimension(style.maxWidth, containingDOMElementData.width, containingDOMElementData.isWidthAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//min width
		style.computedStyle.minWidth = getComputedConstrainedDimension(style.minWidth, containingDOMElementData.width, containingDOMElementData.isWidthAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight, true);
	}
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right, used if the DOMElement
	 * is 'positioned' (position style other than 'static')
	 */
	private function measurePositionOffsets(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//left
		style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//right
		style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//top
		style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//bottom
		style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	

	// PADDINGS
	/////////////////////////////////
	
	/**
	 * Compute the top and bottom paddings of
	 * the DOMElement's box model
	 */
	private function measureVerticalPaddings(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//top
		style.computedStyle.paddingTop = getComputedPadding(style.paddingTop, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//bottom
		style.computedStyle.paddingBottom = getComputedPadding(style.paddingBottom, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	
	/**
	 * Compute the left and right paddings of
	 * the DOMElement's box model
	 */
	private function measureHorizontalPaddings(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//left
		style.computedStyle.paddingLeft = getComputedPadding(style.paddingLeft, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//right
		style.computedStyle.paddingRight = getComputedPadding(style.paddingRight, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the width and the horizontal margins
	 * of the DOMElement
	 */
	private function measureWidthAndHorizontalMargins(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		if (style.width == Dimension.autoValue)
		{
			measureAutoWidth(style, containingDOMElementData);
		}
		else
		{
			measureWidth(style, containingDOMElementData);
		}
	}
	
	/**
	 * Measure the width and the horizontal margins
	 * of the DOMElement in the case where the 'width'
	 * is set as 'auto' and thus depends on the size of the 
	 * margins.
	 * 
	 * An auto width is equal to the containing DOMElement width minus
	 * horizontal paddings and margins.
	 */
	private function measureAutoWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//the width is first set to 0, 
		//it will be computed once the margins are computed
		setComputedWidth(style, 0);
			
		//left margin
		style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
		//right margin
		style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
		
		//the width is computed now that the sizes of the margins are computed
		setComputedWidth(style, getComputedAutoWidth(style, containingDOMElementData));
	}
	
	/**
	 * Measure the width when it is not 'auto'.
	 * It might be a percentage of its containing 
	 * DOMElement width or a length value defined
	 * in pixels or any other length unit
	 */
	private function measureWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//get the content width (width without margins and paddings)
		setComputedWidth(style, getComputedWidth(style, containingDOMElementData));
			
		//left margin
		style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
		//right margin
		style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the height and
	 * vertical margins of the 
	 * DOMElement
	 */
	private function measureHeightAndVerticalMargins(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//get the content height (height without margins and paddings)
		//the height might be null at this point if it must take the content size
		//it will be set once all its children DOMElements have been laid out
		
		if (style.height == Dimension.autoValue)
		{
			measureAutoHeight(style, containingDOMElementData);
		}
		else
		{
			measureHeight(style, containingDOMElementData);
		}
	}
	
	/**
	 * Measure the height and the vertical margins
	 * of the DOMElement in the case where the 'height' style
	 * is set as 'auto' and thus depends on the total height
	 * of its content
	 * 
	 * An auto height can't be determined until all of its children
	 * height are computed. The auto height of a DOMElement
	 * is the addition of all of the offset heights (margin + padding + content height)
	 * of its children.
	 */
	private function measureAutoHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//the height is set to null by default
		setComputedHeight(style, getComputedAutoHeight(style, containingDOMElementData));
		
		//left margin
		style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
		//right margin
		style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
	
	}
	
	/**
	 * Measure the height and the vertical margins
	 * of the DOMElement in the case where the height is
	 * either a percentage of the containing DOMElement height
	 * or a length value exprimend in a supported unit, such
	 * as pixel
	 */
	private function measureHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		//get the computed height in pixel
		setComputedHeight(style, getComputedHeight(style, containingDOMElementData));
		//left margin
		style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
		//right margin
		style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE DIMENSIONS CONSTRAINTS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Constrain computed width if it is above/below max/min width
	 */
	private function constrainWidth(style:AbstractStyle, computedWidth:Int):Int
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//check that the computedWidth is not 
		//superior to max width. The max width
		//can be defined as "none" if there are 
		//no width limit on this DOMElement
		if (style.maxWidth != ConstrainedDimension.none)
		{
			if (computedWidth > computedStyle.maxWidth)
			{
				computedWidth = computedStyle.maxWidth;
			}
		}
		
		//check that width is superior to min width
		if (computedWidth < computedStyle.minWidth)
		{
			computedWidth = computedStyle.minWidth;
		}
		
		return computedWidth;
	}
	
	/**
	 * Constrain computed height if it is above/below max/min height
	 */
	private function constrainHeight(style:AbstractStyle, computedHeight:Int):Int
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
	
		//check that height is within authorised range
		if (style.maxHeight != ConstrainedDimension.none)
		{
			if (computedHeight > computedStyle.maxHeight)
			{
				computedHeight = computedStyle.maxHeight;
			}
		}
		
		//check that height is superior to min height
		if (computedHeight < computedStyle.minHeight)
		{
			computedHeight = computedStyle.minHeight;
		}
		
		return computedHeight;
	}
	
	/**
	 * Utils method to insure that height is constrained each time
	 * it is set
	 */
	private function setComputedHeight(style:AbstractStyle, computedHeight:Int):Void
	{
		style.computedStyle.height = constrainHeight(style, computedHeight);
	}
	
	/**
	 * Utils method to insure that width is constrained each time
	 * it is set
	 */
	private function setComputedWidth(style:AbstractStyle, computedWidth:Int):Void
	{
		style.computedStyle.width = constrainWidth(style, computedWidth);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE COMPUTING METHODS
	// These methods actually take a style
	// value and return a computed style value
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// WIDTH
	/////////////////////////////////
	
	/**
	 * Compute the size of the width when not 'auto' and return it as pixels
	 */
	private function getComputedWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return getComputedDimension(style.width, containingDOMElementData.width, containingDOMElementData.isWidthAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	
	/**
	 * Compute the size of the width when 'auto' and return it as pixels. It is equal to
	 * the remaining width of the containing DOMElement once the margins and paddings width have been
	 * removed
	 */
	private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return containingDOMElementData.width - style.computedStyle.paddingLeft - style.computedStyle.paddingRight - style.computedStyle.marginLeft - style.computedStyle.marginRight;
	}
	
		
		// HEIGHT
	/////////////////////////////////
	
	/**
	 * Get the computed height of the DOMElement when not 'auto' and returns it as pixels
	 */ 
	private function getComputedHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{		
		return getComputedDimension(style.height, containingDOMElementData.height, containingDOMElementData.isHeightAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	
	/**
	 * Get the computed height of the DOMElement when 'auto' and returns it as pixels. Default for 'auto' is 0
	 * as its children total height is not known yet, it will be set once all its children have been
	 * laid out
	 */ 
	private function getComputedAutoHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return 0;
	}
	
		// MARGINS
	/////////////////////////////////
	
	/**
	 * Compute the size of the left margin and return it as pixels
	 */
	private function getComputedMarginLeft(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementData.width, style.computedStyle.width, style.width == Dimension.autoValue, style.computedStyle.paddingRight + style.computedStyle.paddingLeft, style.fontMetrics.fontSize, style.fontMetrics.xHeight, true  );
	}
	
	/**
	 * Compute the size of the right margin and return it as pixels
	 */
	private function getComputedMarginRight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementData.width, style.computedStyle.width, style.width == Dimension.autoValue, style.computedStyle.paddingRight + style.computedStyle.paddingLeft, style.fontMetrics.fontSize, style.fontMetrics.xHeight, true  );
	}
	
	/**
	 * Compute the size of the top margin and return it as pixels
	 */
	private function getComputedMarginTop(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementData.height, style.computedStyle.height, style.height == Dimension.autoValue, style.computedStyle.paddingTop + style.computedStyle.paddingBottom, style.fontMetrics.fontSize, style.fontMetrics.xHeight, false  );
	}
	
	/**
	 * Compute the size of the bottom margin and return it as pixels
	 */
	private function getComputedMarginBottom(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementData.height, style.computedStyle.height, style.height == Dimension.autoValue, style.computedStyle.paddingTop + style.computedStyle.paddingBottom, style.fontMetrics.fontSize, style.fontMetrics.xHeight, false  );
	}
	
	/**
	 * Compute the value of a margin thickness from a 
	 * margin style value
	 * @param	marginStyleValue contains the value of the computed margin as a unit, percentage or defined as auto
	 * @param	opositeMargin the complementary margin from the computed margin. For example for the left margin, it
	 * is the right margin
	 * @param	containingDOMElementDimension the width and height of the DOMElement containing the current DOMElement, used for
	 * computing percentage values
	 * @param	computedDimension a computed dimension (width or height) of the content of the current DOMElement
	 * @param isDimensionAuto wether the reference dimensions is auto, meaning its computed width id not set yet
	 * @param	computedPaddingsDimension the computed dimensions of both horizontal or vertical paddings, depending if the computed
	 * margin is horizontal or vertical
	 * @param  fontSize the computed font size of the containing DOMElement, used to compute the marginStyleValue if it is a length value
	 * defined in 'em'
	 * @param  xHeight the computed x height of the containing DOMElement, used to compute the marginStyleValue if it is a length value
	 * defined in 'ex'
	 * @param	isHorizontalMargin true if the margin is horizontal (left or right)
	 * @return the computed thickness of the margin
	 */
	private function getComputedMargin(marginStyleValue:Margin, opositeMargin:Margin, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Int
	{
		//the return value
		var computedMargin:Int;
		
		//check which type of value is defined
		switch (marginStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedMargin = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
			
			//It's a percentage, compute it from the containing dimension
			case percent(value): 
				
				//margin default to 0 if containing dimension is undefined
				if (isDimensionAuto == true)
				{
					computedMargin = 0;
				}
				else
				{
					computedMargin = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
				}
			
			//auto margins take the remaining place left after
			//paddings, other margin and dimension are set
			case autoValue:	
				computedMargin = getComputedAutoMargin(opositeMargin, marginStyleValue, containingDOMElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension, fontSize, xHeight, isHorizontalMargin);
		}
		
		return computedMargin;
	}
	
	/**
	 * Return the width of an auto margin
	 */
	private function getComputedAutoMargin(marginStyleValue:Margin, opositeMargin:Margin, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Int
	{
		var computedMargin:Int;
		
		//if the containing dimension is set to auto,
		//margin default to 0. Top and bottom margin also default to 0 with
		//an auto value
		if (isHorizontalMargin == false || isDimensionAuto == true)
		{
			computedMargin = 0;
		}
		//if the margin is either left or right the containing width is defined
		else
		{
			//check if the oposite margin is set to auto too
			switch (opositeMargin)
			{
				//if it is, then both margin have the same thickness and share the place left by the content and paddings
				case autoValue:
					computedMargin = Math.round((containingDOMElementDimension - computedDimension - computedPaddingsDimension) / 2);
				
				//else the oposite margin thickness is computed and the computed margin is deduced from the remaining space	
				default:
					var opositeComputedMargin = getComputedMargin(opositeMargin, marginStyleValue, containingDOMElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension, fontSize, xHeight, isHorizontalMargin);
					computedMargin = containingDOMElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin; 
			}
		}
		
		return computedMargin;
	}
	
	/**
	 * Compute a contrain dimensions (max-height, min-width...)
	 * from a contrain style value
	 * @param	constrainedDimension can be defined as a unit, a percentage
	 * or to "none" if no constraint must be applied
	 * @param	containingDOMElementDimension the dimension of the DOMElement into which 
	 * the current DOMElement must fit
	 * @param  isContainingDimensionAuto wether the containinDOMElementDimension is defined as 'auto'
	 * @param  fontSize the computed font size of the containing DOMElement, used to compute the constrainedDimension if it is a length value
	 * defined in 'em'
	 * @param  xHeight the computed x height of the containing DOMElement, used to compute the constrainedDimension if it is a length value
	 * defined in 'ex'
	 * @param	isMinConstraint true if min-width or min-height is computed
	 * @return a computed contraint dimensions in pixels
	 */
	private function getComputedConstrainedDimension(constrainedDimension:ConstrainedDimension, containingDOMElementDimension:Int, isContainingDimensionAuto:Bool, fontSize:Float, xHeight:Float, isMinConstraint:Bool = false):Int
	{
		var computedConstraintDimension:Int;
		
		//check which type of value is defined
		switch (constrainedDimension)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedConstraintDimension = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
			
			//It's a percentage, compute it from the containing dimension	
			case percent(value):
				//if the containing DOMElement dimension is not defined,
				//min value default to 0, for max value,
				//default to infinity (no constraints)
				if (isContainingDimensionAuto == true)
				{
					if (isMinConstraint == true)
					{
						computedConstraintDimension = 0;
					}
					else
					{
						computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
					}
				}
				else
				{
					computedConstraintDimension = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
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
					computedConstraintDimension = Math.round(Math.POSITIVE_INFINITY);
				}
		}
		
		return computedConstraintDimension;
	}
	
	/**
	 * Compute a position offset style (left, right, bottom and top) in pixel
	 * from a position offset style value
	 * 
	 * @param positionOffsetStyleValue might be set to 'auto', an absolute value
	 * or a percent value
	 * @param containingDOMElementDimension, dimension to use as reference to compute 
	 * from a percent value
	 * @param  fontSize the computed font size of the containing DOMElement, used to compute the PositionOffset if it is a length value
	 * defined in 'em'
	 * @param  xHeight the computed x height of the containing DOMElement, used to compute the PositionOffset if it is a length value
	 * defined in 'ex'
	 */
	private function getComputedPositionOffset(positionOffsetStyleValue:PositionOffset, containingDOMElementDimension:Int, fontSize:Float, xHeight:Float):Int
	{
		var computedPositionOffset:Int;
		
		switch(positionOffsetStyleValue)
		{
			case length(value):
				computedPositionOffset = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
				
			case percent(value):
				computedPositionOffset = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
				
			case autoValue:
				computedPositionOffset = 0;
		}
		
		return computedPositionOffset;
	}
	
	/**
	 * Compute the content dimension (width or height) of a DOMElement
	 * @param	dimensionStyleValue can be defined as a unit, a percent or auto
	 * @param	containingDOMElementDimension the dimension of the DOMElement into which 
	 * the current DOMElement must fit
	 * @param  isContainingDimensionAuto wether the containinDOMElementDimension is defined as 'auto'
	 * @param  fontSize the computed font size of the containing DOMElement, used to compute the Dimension if it is a length value
	 * defined in 'em'
	 * @param  xHeight the computed x height of the containing DOMElement, used to compute the Dimension if it is a length value
	 * defined in 'ex'
	 * @return a computed dimension in pixel
	 */
	private function getComputedDimension(dimensionStyleValue:Dimension, containingDOMElementDimension:Int, isContainingDimensionAuto:Bool, fontSize:Float, xHeight:Float):Int
	{
		var computedDimensions:Int;
		
		//check which type of value is defined
		switch (dimensionStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedDimensions = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
			
			//It's a percentage, compute it from the containing dimension	
			case percent(value):
				
				computedDimensions = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
				
			case autoValue:
				//Dealt with in the measureAutoHeight and measureAutoWidth
				//methods
				computedDimensions = 0;
		}
		
		return computedDimensions;
	}
	
	/**
	 * Compute a padding's thickness from a padding style value
	 * @param	paddingStyleValue can be defined as a unit (px, em...) or a percentage
	 * @param	containingDOMElementDimension the dimensions of the DOMElement into which 
	 * the current DOMElement must fit
	 * @param  fontSize the computed font size of the containing DOMElement, used to compute the Padding if it is a length value
	 * defined in 'em'
	 * @param  xHeight the computed x height of the containing DOMElement, used to compute the Padding if it is a length value
	 * defined in 'ex'
	 * @return a computed padding in pixel
	 */
	private function getComputedPadding(paddingStyleValue:Padding, containingDOMElementDimension:Int, fontSize:Float, xHeight:Float):Int
	{
		var computedPaddingValue:Int;
		
		//check which type of value is defined
		switch (paddingStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedPaddingValue = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
			
			//It's a percentage, compute it from the containing dimension		
			case percent(value):
				computedPaddingValue = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
				
		}
		
		return computedPaddingValue;
	}
	
	
}