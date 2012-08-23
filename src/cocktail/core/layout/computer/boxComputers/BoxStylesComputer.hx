/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.computer.boxComputers;


import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
import haxe.Log;

/**
 * This is the base class for all classes computing a HTMLElement's box model. 
 * The box model is determined by a combination of styles such as the display of
 * an element, its width, its margins, paddings...
 * 
 * This class use the defined styles value and compute a value for them that will
 * actually be used. 
 * For example, if a width is determined as a percentage, this class compute
 * a pixel width value from it.
 * 
 * In this base class it is assumed that the HTMLElement is a block, non-replaced
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
	 * Takes the styles of a htmlElement and measure each of its box model properties from 
	 * them (paddings, margins, width, height...)
	 * 
	 * Stores all the style computed value in its computed style structure
	 * 
	 * @param	style contains each of a HTMLElement styles, a reference to the HTMLElement and a structure to
	 * hold computed styles.
	 * @param	containingBlockData the width and height dimensions of the containing block of this 
	 * HTMLElement, used when computing styles determined as percent or "auto"
	 */
	public function measure(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//measure paddings
		measureHorizontalPaddings(style, containingBlockData);
		measureVerticalPaddings(style, containingBlockData);
		
		//The next step is to compute the dimensions
		//constraint style (max-width, min-height...)
		//which will be applied each time the computed height
		//or width ae set
		measureDimensionsConstraints(style, containingBlockData);
		
		//measure width, height and margins at the same time, as margins can influence or be
		//influenced by the width and height of the HTMLElement
		measureDimensionsAndMargins(style, containingBlockData);
		
		//measure the top, left, right and bottom offsets
		//used when the HTMLElement is 'positioned' (any position style
		//but 'static')
		measurePositionOffsets(style, containingBlockData);
		
		//At this point, all the dimensions of the HTMLElement are known maybe except the
		//content height if it was set to 'auto' and thus depends on its content's height.
		//Those dimensions are now enough to layout each of the HTMLElement's children.
		//If the parent's height of this HTMLElement is set to 'auto', it will use the
		//computed dimensions of this HTMLElement to compute its own height.
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
	private function measureDimensionsConstraints(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//max height
		style.usedValues.maxHeight = getComputedConstrainedDimension(style.maxHeight, containingBlockData.height, containingBlockData.isHeightAuto);
		
		//min height
		style.usedValues.minHeight = getComputedConstrainedDimension(style.minHeight, containingBlockData.height, containingBlockData.isHeightAuto, true);
		
		//max width
		style.usedValues.maxWidth  = getComputedConstrainedDimension(style.maxWidth, containingBlockData.width, containingBlockData.isWidthAuto);
		
		//min width
		style.usedValues.minWidth = getComputedConstrainedDimension(style.minWidth, containingBlockData.width, containingBlockData.isWidthAuto, true);
	}
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right, used if the HTMLElement
	 * is 'positioned' (position style other than 'static')
	 */
	private function measurePositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//left
		style.usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
		
		//right
		style.usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
		
		//top
		style.usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
		
		//bottom
		style.usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
	}
	
	/**
	 * Compute dimensions (width and height) and margins
	 * styles
	 */
	private function measureDimensionsAndMargins(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//compute the margins and the constrained width and height
		style.usedValues.width = constrainWidth(style, measureWidthAndHorizontalMargins(style, containingBlockData));

		style.usedValues.height = constrainHeight(style, measureHeightAndVerticalMargins(style, containingBlockData));
	}
	

	// PADDINGS
	/////////////////////////////////
	
	/**
	 * Compute the top and bottom paddings of
	 * the HTMLElement's box model
	 */
	private function measureVerticalPaddings(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//top
		style.usedValues.paddingTop = getComputedPadding(style.paddingTop, containingBlockData.width);
		
		//bottom
		style.usedValues.paddingBottom = getComputedPadding(style.paddingBottom, containingBlockData.width);
	}
	
	/**
	 * Compute the left and right paddings of
	 * the HTMLElement's box model
	 */
	private function measureHorizontalPaddings(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		//left
		style.usedValues.paddingLeft = getComputedPadding(style.paddingLeft, containingBlockData.width);
		
		//right
		style.usedValues.paddingRight = getComputedPadding(style.paddingRight, containingBlockData.width);
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the width and the horizontal margins
	 * of the HTMLElement
	 */
	private function measureWidthAndHorizontalMargins(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		if (style.isAuto(style.width) == true)
		{
			return measureAutoWidth(style, containingBlockData);
		}
		else
		{	
			return measureWidth(style, containingBlockData);
		}
	}
	
	/**
	 * Measure the width and the horizontal margins
	 * of the HTMLElement in the case where the 'width'
	 * is set as 'auto' and thus depends on the size of the 
	 * margins.
	 * 
	 * An auto width is equal to the containing HTMLElement width minus
	 * horizontal paddings and margins.
	 */
	private function measureAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		//the width is first set to 0, 
		//it will be computed once the margins are computed
		var usedWidth:Float = 0.0;	
		
		//left margin
		style.usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
		//right margin
		style.usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);

		//the width is computed now that the sizes of the margins are computed
		return getComputedAutoWidth(style, containingBlockData);
	}
	
	/**
	 * Measure the width when it is not 'auto'.
	 * It might be a percentage of its containing 
	 * HTMLElement width or a length value defined
	 * in pixels or any other length unit
	 */
	private function measureWidth(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		//get the content width (width without margins and paddings)
		var computedWidth:Float = getComputedWidth(style, containingBlockData);
		
		//left margin
		style.usedValues.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData);
		//right margin
		style.usedValues.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData);

		return computedWidth;
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the height and
	 * vertical margins of the 
	 * HTMLElement
	 */
	private function measureHeightAndVerticalMargins(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		//get the content height (height without margins and paddings)
		//the height might be null at this point if it must take the content size
		//it will be set once all its children HTMLElements have been laid out
		
		if (style.isAuto(style.height) == true)
		{
			return measureAutoHeight(style, containingBlockData);
		}
		else
		{
			return measureHeight(style, containingBlockData);
		}
	}
	
	/**
	 * Measure the height and the vertical margins
	 * of the HTMLElement in the case where the 'height' style
	 * is set as 'auto' and thus depends on the total height
	 * of its content
	 * 
	 * An auto height can't be determined until all of its children
	 * height are computed. The auto height of a HTMLElement
	 * is the addition of all of the offset heights (margin + padding + content height)
	 * of its children.
	 */
	private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		//the auto height is set to 0 by default
		var computedHeight:Float = getComputedAutoHeight(style, containingBlockData);
		
		//left margin
		style.usedValues.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData);
		//right margin
		style.usedValues.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData);
		
		return computedHeight;
	}
	
	/**
	 * Measure the height and the vertical margins
	 * of the HTMLElement in the case where the height is
	 * either a percentage of the containing HTMLElement height
	 * or a length value exprimend in a supported unit, such
	 * as pixel
	 */
	private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		//get the computed height in pixel
		var computedHeight:Float = getComputedHeight(style, containingBlockData);
		
		//left margin
		style.usedValues.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData);
		//right margin
		style.usedValues.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData);
		
		return computedHeight;
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
	private function getComputedWidth(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		return getComputedDimension(style.width, containingBlockData.width, containingBlockData.isWidthAuto);
	}
	
	/**
	 * Compute the size of the width when 'auto' and return it as pixels. It is equal to
	 * the remaining width of the containing HTMLElement once the margins and paddings width have been
	 * removed
	 */
	private function getComputedAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		return containingBlockData.width - style.usedValues.paddingLeft - style.usedValues.paddingRight - style.usedValues.marginLeft - style.usedValues.marginRight;
	}
	
		
		// HEIGHT
	/////////////////////////////////
	
	/**
	 * Get the computed height of the HTMLElement when not 'auto' and returns it as pixels
	 */ 
	private function getComputedHeight(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{		
		return getComputedDimension(style.height, containingBlockData.height, containingBlockData.isHeightAuto);
	}
	
	/**
	 * Get the computed height of the HTMLElement when 'auto' and returns it as pixels. Default for 'auto' is 0
	 * as its children total height is not known yet, it will be set once all its children have been
	 * laid out
	 */ 
	private function getComputedAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		return 0;
	}
	
		// MARGINS
	/////////////////////////////////
	
	/**
	 * Compute the size of the left margin and return it as pixels
	 */
	private function getComputedMarginLeft(style:CoreStyle, computedWidth:Float, containingBlockData:ContainingBlockData):Float
	{
		return getComputedMargin(style.marginLeft, style.marginRight, containingBlockData.width, computedWidth, style.isAuto(style.width), style.usedValues.paddingRight + style.usedValues.paddingLeft, true );
	}
	
	/**
	 * Compute the size of the right margin and return it as pixels
	 */
	private function getComputedMarginRight(style:CoreStyle, computedWidth:Float, containingBlockData:ContainingBlockData):Float
	{
		return getComputedMargin(style.marginRight, style.marginLeft, containingBlockData.width, computedWidth, style.isAuto(style.width), style.usedValues.paddingRight + style.usedValues.paddingLeft, true  );
	}
	 
	/**
	 * Compute the size of the top margin and return it as pixels
	 */
	private function getComputedMarginTop(style:CoreStyle, computedHeight:Float, containingBlockData:ContainingBlockData):Float
	{
		return getComputedMargin(style.marginTop, style.marginBottom, containingBlockData.height, computedHeight, style.isAuto(style.height), style.usedValues.paddingTop + style.usedValues.paddingBottom, false  );
	}
	
	/**
	 * Compute the size of the bottom margin and return it as pixels
	 */
	private function getComputedMarginBottom(style:CoreStyle, computedHeight:Float, containingBlockData:ContainingBlockData):Float
	{
		return getComputedMargin(style.marginBottom, style.marginTop, containingBlockData.height, computedHeight, style.isAuto(style.height), style.usedValues.paddingTop + style.usedValues.paddingBottom, false  );
	}
	
	/**
	 * Compute the value of a margin thickness from a 
	 * margin style value
	 * @param	marginStyleValue contains the value of the computed margin as a unit, percentage or defined as auto
	 * @param	opositeMargin the complementary margin from the computed margin. For example for the left margin, it
	 * is the right margin
	 * @param	containingHTMLElementDimension the width and height of the HTMLElement containing the current HTMLElement, used for
	 * computing percentage values
	 * @param	computedDimension a computed dimension (width or height) of the content of the current HTMLElement
	 * @param isDimensionAuto wether the reference dimensions is auto, meaning its computed width id not set yet
	 * @param	computedPaddingsDimension the computed dimensions of both horizontal or vertical paddings, depending if the computed
	 * margin is horizontal or vertical
	 * @param	isHorizontalMargin true if the margin is horizontal (left or right)
	 * @return the computed thickness of the margin
	 */
	private function getComputedMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsDimension:Float, isHorizontalMargin:Bool):Float
	{
		//the return value
		var usedMargin:Float;
		
		//check which type of value is defined
		switch (marginStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case ABSOLUTE_LENGTH(value):
				usedMargin = value;
			
			//It's a percentage, compute it from the containing dimension
			case PERCENTAGE(value): 
				
				//margin default to 0 if containing dimension is undefined
				if (isDimensionAuto == true)
				{
					usedMargin = 0.0;
				}
				else
				{
					usedMargin = UnitManager.getPixelFromPercent(value, containingHTMLElementDimension);
				}
			
			//auto margins take the remaining place left after
			//paddings, other margin and dimension are set
			case KEYWORD(value):
				if (value != AUTO)
				{
					throw 'Illegal keyword value for margin style';
				}
				usedMargin = getComputedAutoMargin(marginStyleValue, opositeMargin, containingHTMLElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension, isHorizontalMargin);
			
			default:
				throw 'Illegal value for margin style';
				
		}
		
		return usedMargin;
	}
	
	/**
	 * Return the width of an auto margin
	 */
	private function getComputedAutoMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsDimension:Float, isHorizontalMargin:Bool):Float
	{
		var computedMargin:Float;
		
		//if the containing dimension is set to auto,
		//margin default to 0. Top and bottom margin also default to 0 with
		//an auto value
		if (isHorizontalMargin == false || isDimensionAuto == true)
		{
			computedMargin = 0.0;
		}
		//if the margin is either left or right the containing width is defined
		else
		{
			//check if the oposite margin is set to auto too
			switch (opositeMargin)
			{
				//if it is, then both margin have the same thickness and share the place left by the content and paddings
				case KEYWORD(value):
					if (value != AUTO)
					{
						throw 'Illegal keyword value for margin';
					}
					
					computedMargin = (containingHTMLElementDimension - computedDimension - computedPaddingsDimension) / 2;
				
				//else the oposite margin thickness is computed and the computed margin is deduced from the remaining space	
				default:
					var opositeComputedMargin:Float = getComputedMargin(opositeMargin, marginStyleValue, containingHTMLElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension, isHorizontalMargin);
					computedMargin = containingHTMLElementDimension - computedDimension - computedPaddingsDimension - opositeComputedMargin; 
			}
		}
		
		return computedMargin;
	}
	
	/**
	 * Compute a contrain dimensions (max-height, min-width...)
	 * from a contrain style value
	 * @param	constrainedDimension can be defined as a unit, a percentage
	 * or to "none" if no constraint must be applied
	 * @param	containingHTMLElementDimension the dimension of the HTMLElement into which 
	 * the current HTMLElement must fit
	 * @param  isContainingDimensionAuto wether the containinHTMLElementDimension is defined as 'auto'
	 * @param	isMinConstraint true if min-width or min-height is computed
	 * @return a computed contraint dimensions in pixels
	 */
	private function getComputedConstrainedDimension(constrainedDimension:CSSPropertyValue, containingHTMLElementDimension:Float, isContainingDimensionAuto:Bool, isMinConstraint:Bool = false):Float
	{
		var computedConstraintDimension:Float;
		
		//check which type of value is defined
		switch (constrainedDimension)
		{
			//it's a length (an absolute value
			//with a unit)
			case ABSOLUTE_LENGTH(value):
				computedConstraintDimension = value;
			
			//It's a percentage, compute it from the containing dimension	
			case PERCENTAGE(value):
				//if the containing HTMLElement dimension is not defined,
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
						computedConstraintDimension = Math.POSITIVE_INFINITY;
					}
				}
				else
				{
					computedConstraintDimension = UnitManager.getPixelFromPercent(value, containingHTMLElementDimension);
				}
				
			//here no constraint are applied,
			//defaults are set
			case KEYWORD(value):
				if (value != CSSKeywordValue.NONE)
				{
					throw 'Illegal keyword value for dimension constraints style';
				}
				
				if (isMinConstraint == true)
				{
					computedConstraintDimension = 0.0;
				}
				else 
				{
					computedConstraintDimension = Math.POSITIVE_INFINITY;
				}
				
			default:
				throw 'Illegal value for dimension constraints style';
		}
		
		return computedConstraintDimension;
	}
	
	/**
	 * Compute a position offset style (left, right, bottom and top) in pixel
	 * from a position offset style value
	 * 
	 * @param positionOffsetStyleValue might be set to 'auto', an absolute value
	 * or a percent value
	 * @param containingHTMLElementDimension, dimension to use as reference to compute 
	 * from a percent value
	 */
	private function getComputedPositionOffset(positionOffsetStyleValue:CSSPropertyValue, containingHTMLElementDimension:Float):Float
	{
		var computedPositionOffset:Float = 0.0;
		
		switch(positionOffsetStyleValue)
		{
			case ABSOLUTE_LENGTH(value):
				computedPositionOffset = value;
				
			case PERCENTAGE(value):
				computedPositionOffset = UnitManager.getPixelFromPercent(value, containingHTMLElementDimension);
				
			default:	
		}
		
		return computedPositionOffset;
	}
	
	/**
	 * Compute the content dimension (width or height) of a HTMLElement
	 * @param	dimensionStyleValue can be defined as a unit, a percent or auto
	 * @param	containingHTMLElementDimension the dimension of the HTMLElement into which 
	 * the current HTMLElement must fit
	 * @param  isContainingDimensionAuto wether the containinHTMLElementDimension is defined as 'auto'
	 * @return a computed dimension in pixel
	 */
	private function getComputedDimension(dimensionStyleValue:CSSPropertyValue, containingHTMLElementDimension:Float, isContainingDimensionAuto:Bool):Float
	{
		var computedDimensions:Float;
		
		//check which type of value is defined
		switch (dimensionStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case ABSOLUTE_LENGTH(value):
				computedDimensions = value;
			
			//It's a percentage, compute it from the containing dimension	
			case PERCENTAGE(value):
				computedDimensions = UnitManager.getPixelFromPercent(value, containingHTMLElementDimension);

			case KEYWORD(value):
				if (value == AUTO)
				{
					//Dealt with in the measureAutoHeight and measureAutoWidth
					//methods
					computedDimensions = 0;
				}
				else
				{
					throw 'Illegal keyword value for width or height';
				}
				
			default:
				throw 'Illegal value for width or height';
		}
		
		return computedDimensions;
	}
	
	/**
	 * Compute a padding's thickness from a padding style value
	 * @param	paddingStyleValue can be defined as a unit (px, em...) or a percentage
	 * @param	containingHTMLElementDimension the dimensions of the HTMLElement into which 
	 * the current HTMLElement must fit
	 * @return a computed padding in pixel
	 */
	private function getComputedPadding(paddingStyleValue:CSSPropertyValue, containingHTMLElementDimension:Float):Float
	{
		var computedPaddingValue:Float;
		
		//check which type of value is defined
		switch (paddingStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case ABSOLUTE_LENGTH(value):
				computedPaddingValue = value;
			
			//It's a percentage, compute it from the containing dimension		
			case PERCENTAGE(value):
				computedPaddingValue = UnitManager.getPixelFromPercent(value, containingHTMLElementDimension);
				
			default:
				throw 'Illegal value for padding';
		}
		
		return computedPaddingValue;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE DIMENSIONS CONSTRAINTS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Constrain computed width if it is above/below max/min width
	 */
	private function constrainWidth(style:CoreStyle, usedWidth:Float):Float
	{
		var usedValues:UsedValuesData = style.usedValues;
		
		//check that the computedWidth is not 
		//superior to max width. The max width
		//can be defined as "none" if there are 
		//no width limit on this HTMLElement
		if (style.isNone(style.maxWidth) == false)
		{
			if (usedWidth > usedValues.maxWidth)
			{
				usedWidth = usedValues.maxWidth;
			}
		}
		
		//check that width is superior to min width
		if (usedWidth < usedValues.minWidth)
		{
			usedWidth = usedValues.minWidth;
		}
		
		return usedWidth;
	}
	
	/**
	 * Constrain computed height if it is above/below max/min height
	 */
	private function constrainHeight(style:CoreStyle, usedHeight:Float):Float
	{
		var usedValues:UsedValuesData = style.usedValues;
	
		//check that height is within authorised range
		if (style.isNone(style.maxHeight) == false)
		{
			if (usedHeight > usedValues.maxHeight)
			{
				usedHeight = usedValues.maxHeight;
			}
		}
		
		//check that height is superior to min height
		if (usedHeight < usedValues.minHeight)
		{
			usedHeight = usedValues.minHeight;
		}
		
		return usedHeight;
	}
}