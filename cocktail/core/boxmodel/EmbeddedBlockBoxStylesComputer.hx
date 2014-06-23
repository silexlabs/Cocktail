/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.boxmodel;

import cocktail.core.html.EmbeddedElement;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.css.CSSStyleData;
import cocktail.core.css.CSSCascadeData;

/**
 * This is the box computer implementation for an
 * embedded block HTMLElement.
 * 
 * It add special treatement for dimensions
 * computation, as an embedded HTMLElement has intrinsic
 * dimensions
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBlockBoxStylesComputer extends BoxStylesComputer
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Overriden, as dimensions constraints are applied differently
	 * for embedded block
	 */
	override private function measureDimensionsAndMargins(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var usedWidth:Float = measureWidthAndHorizontalMargins(style, containingBlockData);
		var usedHeight:Float = measureHeightAndVerticalMargins(style, containingBlockData);
				
		if (style.hasAutoWidth == true && style.hasAutoHeight == true)
		{
			//apply a constrain algorithm specific to embedded elements
			constrainDimensions(style, usedWidth, usedHeight);
		}
		else
		{
			//apply regular constrain algorithm
			usedValues.width = constrainWidth(style, usedWidth);
			usedValues.height = constrainHeight(style, usedHeight);
		}
		
	}
	
	/**
	 * Constrain the width and height of the embedded HTMLElement,
	 * this method is an implementation of the following table :
	 * http://www.w3.org/TR/CSS2/visudet.html#min-max-widths
	 * 
	 * For embedded elements, min/max width/height might be linked, for instance,
	 * applying a max height can also constrain the width to keep aspect ratio
	 */
	private function constrainDimensions(style:CoreStyle, usedWidth:Float, usedHeight:Float):Void
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var maxHeight:Float = usedValues.maxHeight;
		var minHeight:Float = usedValues.minHeight;
		var maxWidth:Float = usedValues.maxWidth;
		var minWidth:Float = usedValues.minWidth;
		
		//set flag for each contrain type
		var widthSuperiorToMaxWidth:Bool = false;
		if (style.hasMaxWidth == true)
		{
			widthSuperiorToMaxWidth = usedWidth > maxWidth;
		}
		
		var heightSuperiorToMaxHeight:Bool = false;
		if (style.hasMaxHeight == true)
		{
			heightSuperiorToMaxHeight = usedHeight > maxHeight;
		}
		
		var widthInferiorToMinWidth:Bool = usedWidth < minWidth;
		var heightInferiorToMinHeight:Bool = usedHeight < minHeight;
		
		//apply the dimensions constrained
		//this alghorithm is not very elegant, but this is a straight
		//adaption from the min/max table of constraints of CSS
		if (widthSuperiorToMaxWidth == true)
		{
			if (heightSuperiorToMaxHeight == true)
			{
				if ((maxWidth / usedWidth) <= (maxHeight / usedHeight))
				{
					if (minHeight > maxWidth * (usedHeight / usedWidth))
					{
						usedHeight = minHeight;
					}
					else
					{
						usedHeight = maxWidth * (usedHeight / usedWidth);
					}
					usedWidth = maxWidth;
				}
			}
			else if (heightInferiorToMinHeight == true)
			{
				usedWidth = maxWidth;
				usedHeight = minHeight;
			}
			else
			{
				if (maxWidth * (usedHeight / usedWidth) > minHeight)
				{
					usedHeight = maxWidth * (usedHeight / usedWidth);
				}
				else
				{
					usedHeight = minHeight;
				}
				usedWidth = maxWidth;
			}
		}
		else if (widthInferiorToMinWidth == true)
		{
			if (heightInferiorToMinHeight == true)
			{
				if (minWidth / usedWidth <= minHeight / usedHeight)
				{
					if (maxWidth < minHeight * (usedWidth / usedHeight))
					{
						usedWidth = maxWidth;
					}
					else
					{
						usedWidth = minHeight * (usedWidth / usedHeight);
					}
					usedHeight = minHeight;
				}
				else
				{
					if (maxHeight < minWidth * (usedHeight / usedWidth))
					{
						usedHeight = maxHeight;
					}
					else
					{
						usedHeight = minWidth * (usedHeight / usedWidth);
					}
					usedWidth = minWidth;
				}
			}
			else if (heightSuperiorToMaxHeight == true)
			{
				usedWidth = minWidth;
				usedHeight = maxHeight;
			}
			else
			{
				if (minWidth * (usedHeight / usedWidth) < maxHeight)
				{
					usedHeight = minWidth * (usedHeight / usedWidth);
				}
				else
				{
					usedHeight = maxHeight;
				}
				usedWidth = minWidth;
			}
		}
		else if (heightSuperiorToMaxHeight == true)
		{
			if (maxHeight * (usedWidth / usedHeight) > minWidth)
			{
				usedWidth = maxHeight * (usedWidth / usedHeight);
			}
			else
			{
				usedWidth = minWidth;
			}
			usedHeight = maxHeight;
		}
		else if (heightInferiorToMinHeight == true)
		{
			if (minHeight * (usedWidth / usedHeight) < minHeight)
			{
				usedWidth = minHeight * (usedWidth / usedHeight);
			}
			else
			{
				usedWidth = minHeight;
			}
			usedHeight = minHeight;
		}
		
		usedValues.width = usedWidth;
		usedValues.height = usedHeight;
	}
	
	
	/**
	 * Overriden to process width before margins. For an embedded element a
	 * width can always be computed even when width is auto
	 */
	override private function measureAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		//width
		var usedWidth:Float = getComputedAutoWidth(style, containingBlockData);
			
		//left margin
		usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
		//right margin
		usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);
		
		return usedWidth;
	}
	
	/**
	 * Override the way a value of 'auto' for the width style
	 * is computed, as an embedded HTMLElement may have an intrinsic width
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var usedWidth:Float = 0.0;
		
		var embeddedHTMLElement:EmbeddedElement = cast(style.htmlElement);
		
		//first try to use the HTML width attribute if it was specified
		//for the embedded HTMLElement
		//TODO 1 : this is not how it is supposed to work, should only try HTML width attribute
		//if width style is not specified. Must correct once cascading is implemented
		if (embeddedHTMLElement.getAttributeNode("width") != null)
		{
			usedWidth = embeddedHTMLElement.width;
		}
		//if the 'height' style also is defined as 'auto'
		else if (style.hasAutoHeight == true)
		{
			//first try to use the intrinsic width of the embedded
			//HTMLElement if it exist (it might for instance be a
			//picture width for an ImageHTMLElement)
			
			if (embeddedHTMLElement.intrinsicWidth != null)
			{
				usedWidth = embeddedHTMLElement.intrinsicWidth;
			}
			//else deduce the intrinsic width from the intrinsic height and ratio
			else if (embeddedHTMLElement.intrinsicHeight != null && embeddedHTMLElement.intrinsicRatio != null)
			{
				usedWidth = embeddedHTMLElement.intrinsicHeight * embeddedHTMLElement.intrinsicRatio;
			}
			else if (embeddedHTMLElement.intrinsicRatio != null)
			{
				//If 'height' and 'width' both have computed values of 'auto' 
				//and the element has an intrinsic ratio but no intrinsic height
				//or width, then the used value of 'width' is undefined in CSS 2.1.
				//However, it is suggested that, if the containing block's width
				//does not itself depend on the replaced element's width,
				//then the used value of 'width' is calculated from the
				//constraint equation used for block-level, non-replaced elements in normal flow. 
				if (containingBlockData.isWidthAuto == false)
				{
					usedWidth = containingBlockData.width - usedValues.marginLeft - usedValues.marginRight - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth;
				}
				else
				{
					usedWidth = 0.0;
				}
			}
			
		}
		
		//if the 'height' style is not auto
		else
		{
			//compute the used height
			var usedHeight:Float = constrainHeight(style, getComputedDimension(style.height, containingBlockData.height, containingBlockData.isHeightAuto));
			
			//deduce the width from the intrinsic ratio and the computed height
			if (embeddedHTMLElement.intrinsicRatio != null)
			{
				usedWidth = usedHeight / embeddedHTMLElement.intrinsicRatio;
			}
			//else use the intrinsic width if defined
			else if (embeddedHTMLElement.intrinsicWidth != null)
			{
				usedWidth = embeddedHTMLElement.intrinsicWidth;
			}
			else
			{
				//Otherwise, if 'width' has a computed value of 'auto',
				//but none of the conditions above are met, then the used 
				//value of 'width' becomes 300px.
				usedWidth = 300;
			}
			
		}
		
		return usedWidth;
	}
	
	/**
	 * Override the way a value of 'auto' for the height style
	 * is computed, as an embedded HTMLElement may have an intrinsic height
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var usedHeight:Float = 0.0;
		
		//TODO 4 : should style have a reference to the HTMLElement ? Should they be
		//applied to multiple HTMLElement ?
		var embeddedHTMLElement:EmbeddedElement = cast(style.htmlElement);
		
		//first try to use the HTML height attribute if it was specified
		//for the embedded HTMLElement
		//TODO 1 : this is not how it is supposed to work, should only try HTML height attribute
		//if height style is not specified. Must correct once cascading is implemented
		if (embeddedHTMLElement.getAttributeNode("height") != null)
		{
			usedHeight = embeddedHTMLElement.height;
		}
		//if the 'width' style is also set to 'auto'
		else if (style.hasAutoWidth == true)
		{
			//try to use the intrinsic height of the embedded
			//HTMLElement if it exist (it might for instance be a
			//picture width for an ImageHTMLElement)
			if (embeddedHTMLElement.intrinsicHeight != null)
			{
				usedHeight = embeddedHTMLElement.intrinsicHeight;
			}
			//else deduce the intrinsic height from the intrinsic width and ratio
			else if (embeddedHTMLElement.intrinsicWidth != null && embeddedHTMLElement.intrinsicRatio != null)
			{
				usedHeight = embeddedHTMLElement.intrinsicWidth * embeddedHTMLElement.intrinsicRatio;
			}
			//TODO 3 : check what must happen here
			else if (embeddedHTMLElement.intrinsicRatio != null)
			{
				
			}
		}
		//else if 'width' is not 'auto'
		else
		{
			//deduce the height from the computed width and the intrinsic ratio if it is defined
			if (embeddedHTMLElement.intrinsicRatio != null)
			{
				//compute the used value of 'width'
				var usedWidth:Float = constrainWidth(style, getComputedDimension(style.width, containingBlockData.width, containingBlockData.isWidthAuto));
				
				usedHeight = usedWidth * embeddedHTMLElement.intrinsicRatio;
			}
			//else if an intrinsic height exists, use it
			else if (embeddedHTMLElement.intrinsicHeight != null)
			{
				usedHeight = embeddedHTMLElement.intrinsicHeight;
			}
			else
			{
				//Otherwise, if 'height' has a computed value of 'auto',
				//but none of the conditions above are met, then the used value of 'height'
				//is 150px
				usedHeight = 150;
			}
		}
		
		return usedHeight;
	}
	
	/**
	 * for block embedded HTMLElement, an 'auto' for vertical margin compute to 0, 
	 * horizontal margin are computed like for non-embedded block HTMLElements
	 */
	override private function getComputedAutoMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsAndBordersDimension:Float, isHorizontalMargin:Bool):Float
	{
		var usedMargin:Float;
	
		if (isHorizontalMargin == false)
		{
			usedMargin = 0.0;
		}
		else
		{
			//the "isDimensionAuto" flag is set to false, as for embedded element, there is always a computed width 
			//at this point
			usedMargin = super.getComputedAutoMargin(marginStyleValue, opositeMargin, containingHTMLElementDimension, computedDimension, false, computedPaddingsAndBordersDimension, isHorizontalMargin );
		}
		
		return usedMargin;
	}
	
}
