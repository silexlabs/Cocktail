/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.computer;

import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.Style;
import cocktail.style.StyleData;
import haxe.Log;


/**
 * This is the base class for all classes computing a DOMElement's box model. 
 * The box model is determined by a combination of styles such as the display of
 * an element, its width, its margins, paddings...
 * 
 * This class use the defined styles value and compute a used value for them. 
 * For example, if a width is determined as a percentage, this class compute
 * a pixel width value from it.
 * 
 * In this base class it is assumed that the DOMElement is a block, non-replaced
 * element, each deriving case as its own inherithing class
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxComputer 
{

	/**
	 * TO DO : replace this
	 * with NULL<Int> Haxe construct
	 */
	private static var NULL:Int = -1;
	
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
	 * @param	containingDOMElementDimensions the width and height dimensions of the containing block of this 
	 * DOMElement, used when computing styles determined as percent or "auto"
	 */
	public function measure(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//measure paddings
		measureHorizontalPaddings(style, containingDOMElementDimensions);
		measureVerticalPaddings(style, containingDOMElementDimensions);
		
		//measure width, height and margins at the same time, as margins can influence or be
		//influenced by the width and height of the DOMElement
		measureWidthAndHorizontalMargins(style, containingDOMElementDimensions);
		measureHeightAndVerticalMargins(style, containingDOMElementDimensions);
		
		//measure the top, left, right and bottom offsets
		//used when the DOMElement is 'positioned' (any position style
		//but static)
		measurePositionOffsets(style, containingDOMElementDimensions);
		
		//The next step is to compute the dimensions
		//constraint style (max-width, min-height...)
		//and check that the computed height and width
		//enforce those constraint
		measureDimensionsConstraints(style, containingDOMElementDimensions);
		
		//apply the dimensions constraints (min-width, max-height...)
		//to the computed width and height dimensions
		constrainDimensions(style.computedStyle);
		
		 //At this point, all the dimensions of the DOMElement are known maybe except the
		 //content height if it was set to 'auto' and thus depends on its content's height.
		 //Those dimensions are now enough to layout each of the DOMElement's children.
		 //If the parent's height of this DOMElement is set to 'auto', it will use the
		 //computed dimensions of this DOMElement to compute its own height.
		 
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
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right, used if the DOMElement
	 * is 'positioned' (position style other than 'static')
	 */
	private function measurePositionOffsets(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//left
		style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementDimensions.width);
		
		//right
		style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementDimensions.width);
		
		//top
		style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementDimensions.height);
		
		//bottom
		style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementDimensions.height);
	}
	

	// PADDINGS
	/////////////////////////////////
	
	/**
	 * Compute the top and bottom paddings of
	 * the DOMElement's box model
	 */
	private function measureVerticalPaddings(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//top
		style.computedStyle.paddingTop = getComputedPadding(style.paddingTop, containingDOMElementDimensions.height);
		
		//bottom
		style.computedStyle.paddingBottom = getComputedPadding(style.paddingBottom, containingDOMElementDimensions.height);
	}
	
	/**
	 * Compute the left and right paddings of
	 * the DOMElement's box model
	 */
	private function measureHorizontalPaddings(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//left
		style.computedStyle.paddingLeft = getComputedPadding(style.paddingLeft, containingDOMElementDimensions.width);
		
		//right
		style.computedStyle.paddingRight = getComputedPadding(style.paddingRight, containingDOMElementDimensions.width);
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the width and the horizontal margins
	 * of the DOMElement
	 */
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
	
	/**
	 * Measure the width and the horizontal margins
	 * of the DOMElement in the case where the 'width'
	 * is set as 'auto' and thus depends on the size of the 
	 * margins.
	 * 
	 * An auto width is equal to the containing DOMElement width minus
	 * horizontal paddings and margins.
	 */
	private function measureAutoWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//the width is first set to null, 
		//it will be computed once the margins are computed
		style.computedStyle.width = NULL;
			
		//left margin
		style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementDimensions);
		//right margin
		style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementDimensions);
		
		//the width is computed now that the sizes of the margins are computed
		style.computedStyle.width = getComputedAutoWidth(style, containingDOMElementDimensions);
	}
	
	/**
	 * Measure the width when it is not 'auto'.
	 * It might be a percentage of its containing 
	 * DOMElement width or an absolute value in pixel
	 * or any other supported unit
	 */
	private function measureWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//get the content width (width without margins and paddings)
		style.computedStyle.width = getComputedWidth(style, containingDOMElementDimensions);
			
		//left margin
		style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementDimensions);
		//right margin
		style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementDimensions);
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * Measure the height and
	 * vertical margins of the 
	 * DOMElement
	 */ 
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
	private function measureAutoHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//the height is set to null by default
		style.computedStyle.height = getComputedAutoHeight(style, containingDOMElementDimensions);
		
		//left margin
		style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementDimensions);
		//right margin
		style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementDimensions);
	
	}
	
	/**
	 * Measure the height and the vertical margins
	 * of the DOMElement in the case where the height is
	 * either a percentage of the containing DOMElement height
	 * or an absolute value exprimend in a supported unit, such
	 * as pixel
	 */
	private function measureHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		//get the computed height in pixel
		style.computedStyle.height = getComputedHeight(style, containingDOMElementDimensions);
		
		//left margin
		style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementDimensions);
		//right margin
		style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementDimensions);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE DIMENSIONS CONSTRAINTS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply the dimensions constraints, such as 
	 * max-height to the computed width and height
	 * values
	 */
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
	private function getComputedWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedDimension(style.width, containingDOMElementDimensions.width);
	}
	
	/**
	 * Compute the size of the width when 'auto' and return it as pixels
	 */
	private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return containingDOMElementDimensions.width - style.computedStyle.paddingLeft - style.computedStyle.paddingRight - style.computedStyle.marginLeft - style.computedStyle.marginRight;
	}
	
		
		// HEIGHT
	/////////////////////////////////
	
	/**
	 * Get the computed height of the DOMElement when not 'auto' and returns it as pixels
	 */ 
	private function getComputedHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedDimension(style.height, containingDOMElementDimensions.height);
	}
	
	/**
	 * Get the computed height of the DOMElement when 'auto' and returns it as pixels. Default for 'auto' is null
	 * as its children total height is not known yet
	 */ 
	private function getComputedAutoHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return NULL;
	}
	
		// MARGINS
	/////////////////////////////////
	
	/**
	 * Compute the size of the left margin and return it as pixels
	 */
	private function getComputedMarginLeft(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedMargin(style.marginLeft, style.marginRight, containingDOMElementDimensions.width, style.computedStyle.width, style.width == DimensionStyleValue.auto, style.computedStyle.paddingRight + style.computedStyle.paddingLeft  );
	}
	
	/**
	 * Compute the size of the right margin and return it as pixels
	 */
	private function getComputedMarginRight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedMargin(style.marginRight, style.marginLeft, containingDOMElementDimensions.width, style.computedStyle.width, style.width == DimensionStyleValue.auto, style.computedStyle.paddingRight + style.computedStyle.paddingLeft  );
	}
	
	/**
	 * Compute the size of the top margin and return it as pixels
	 */
	private function getComputedMarginTop(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedMargin(style.marginTop, style.marginBottom, containingDOMElementDimensions.height, style.computedStyle.height, style.height == DimensionStyleValue.auto, style.computedStyle.paddingTop + style.computedStyle.paddingBottom  );
	}
	
	/**
	 * Compute the size of the bottom margin and return it as pixels
	 */
	private function getComputedMarginBottom(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		return getComputedMargin(style.marginBottom, style.marginTop, containingDOMElementDimensions.height, style.computedStyle.height, style.height == DimensionStyleValue.auto, style.computedStyle.paddingTop + style.computedStyle.paddingBottom  );
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
	
	/**
	 * Compute a position offset style (left, right, bottom and top) in pixel
	 * from a position offset style value
	 * 
	 * @param positionOffsetStyleValue might be set to 'auto', an absolute value
	 * or a percent value
	 * @param containingDOMElementDimension, dimension to use as reference to compute 
	 * from a percent value
	 */
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
				//Dealt with in the measureAutoHeight and measureAutoWidth
				//methods
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CONVERSIONS METHODS
	// For unit and percent based values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get a value in pixel 
	 * from a unit value
	 * (px, em, cm...)
	 * @param	length contains the unit type and the value
	 * @return returns the computed value as pixel with rounded
	 * values
	 */ 
	private function getValueFromLength(length:LengthValue):Int
	{
		var lengthValue:Float;
		
		switch (length)
		{
			case px(value):
				lengthValue = value;
				
			case mm(value):
				lengthValue = (value * ((72 * (1 / 0.75)) / 2.54)) / 10;
				
			case cm(value):
				lengthValue = value * ((72 * (1/0.75)) / 2.54);
				
			case pt(value):
				lengthValue = value * 1/0.75;	
				
			case _in(value):
				lengthValue = value * (72 * (1/0.75));
				
			case pc(value):
				lengthValue = value * (12 * (1/0.75));	
		}
		
		return Math.round(lengthValue);
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