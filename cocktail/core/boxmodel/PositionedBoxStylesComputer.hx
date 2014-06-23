/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.boxmodel;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSCascadeData;

/**
 * This is the box computer for non-replaced
 * absolutely positioned HTMLElement, such as
 * an absolutely positioned ContainerHTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class PositionedBoxStylesComputer extends BoxStylesComputer
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE MEASURE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to prevent computing left, right,
	 * top and bottom which in this case are computed in the 
	 * width and height methods
	 */
	override private function measurePositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
	{
		
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also left, right and the horizontal margins when an
	 * auto width is computed. Left and right might be computed in the shrink-to-fit
	 * method if they are defined as auto
	 */ 
	override private function measureAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var usedWidth:Float = 0.0;
		
		//first, any auto value for margins are computed to 0
		if (style.hasAutoMarginLeft == true)
		{
			usedValues.marginLeft = 0;
		}
		else
		{
			usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
		}
		
		if (style.hasAutoMarginRight == true)
		{
			usedValues.marginRight = 0;
		}
		else
		{
			usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);
		}
		
		//if neither left or right are auto but width is
		if (style.hasAutoLeft == false && style.hasAutoRight == false)
		{
			//left and right are computed as they are defined either as length or percentage
			usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
			usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
			
			//the computed width is deduced from all the other computed horizontal values. It is the remaining space when all the other value
			//are substracted from the containing HTMLElement width
			usedWidth = containingBlockData.width - usedValues.marginLeft - usedValues.left - usedValues.right - usedValues.marginRight - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth;
		}
		//if width is auto and left, right or both are auto, then the width will be "shrinked-to-fit" once all the children have been laid out,
		//so the width is first set to 0 and the shrink-to-fit width will be found during layout
		else
		{
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			if (style.hasAutoLeft == true)
			{
				usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
			}
			//same for right
			else if(style.hasAutoRight == true)
			{
				usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
			}
			
			usedWidth = 0;
		}
		
		return usedWidth;
	}
	
	/**
	 * overriden to also compute left and right style
	 */
	override private function measureWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		//compute the width which is either defined as a length or a percentage
		var usedWidth:Float = getComputedWidth(style, containingBlockData);

		//if neither left nor right are defined as auto
		if (style.hasAutoLeft == false && style.hasAutoRight == false)
		{
			//compute left and right defined either as length or percentage
			usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
			usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
			
			//if both margin are auto, they will take the same size
			if (style.hasAutoMarginLeft == true && style.hasAutoMarginRight == true)
			{
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, border, width, offset) are removed
				var usedMargin:Float = (containingBlockData.width - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right) / 2;

				if (usedMargin >= 0)
				{
					usedValues.marginLeft = usedMargin;
					usedValues.marginRight = usedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					usedValues.marginLeft = 0;
					usedValues.marginRight = containingBlockData.width - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right;
				}
			
			}
			//if only margin left is auto
			else if (style.hasAutoMarginLeft == true)
			{
				//compute margin right then deduce margin left from the remaining horizontal
				//space
				usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);
				usedValues.marginLeft = containingBlockData.width - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right - usedValues.marginRight;
			}
			//same if only margin right is auto
			else if (style.hasAutoMarginRight == true)
			{
				usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
				usedValues.marginRight = containingBlockData.width - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right - usedValues.marginLeft;
			}
			//else if no margins are auto, compute them
			else
			{
				usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
				usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);
			}
		}
		//if either left or right is auto
		else
		{
			//any auto margin computes to 0
			if (style.hasAutoMarginLeft == true)
			{
				usedValues.marginLeft = 0;
			}
			else
			{
				usedValues.marginLeft = getComputedMarginLeft(style, usedWidth, containingBlockData);
			}
			
			if (style.hasAutoMarginRight == true)
			{
				usedValues.marginRight = 0;
			}
			else
			{
				usedValues.marginRight = getComputedMarginRight(style, usedWidth, containingBlockData);
			}
			
			//if left and right are both auto, the statc position of left is used, then right is computed
			if (style.hasAutoLeft == true && style.hasAutoRight == true)
			{
				usedValues.left = getComputedStaticLeft(style, containingBlockData);
				usedValues.right = containingBlockData.width - usedValues.marginLeft - usedValues.marginRight - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left;
			}
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			else if (style.hasAutoLeft == true)
			{
				usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
				usedValues.left = containingBlockData.width - usedValues.marginLeft - usedValues.marginRight - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.right;
			}
			//same for right
			else if(style.hasAutoRight == true)
			{
				usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
				usedValues.right = containingBlockData.width - usedValues.marginLeft - usedValues.marginRight - usedWidth - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left;
			}
		}
		
		return usedWidth;
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also top, bottom and the vertical margins when an
	 * auto height is computed.
	 */ 
	override private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		var usedHeight:Float = 0.0;
		
		//first, any auto value for margins are computed to 0
		if (style.hasAutoMarginTop == true)
		{
			usedValues.marginTop = 0;
		}
		else
		{
			usedValues.marginTop = getComputedMarginTop(style, usedHeight, containingBlockData);
		}
		
		if (style.hasAutoMarginBottom == true)
		{
			usedValues.marginBottom = 0;
		}
		else
		{
			usedValues.marginBottom = getComputedMarginBottom(style, usedHeight, containingBlockData);
		}
		
		//if neither top or bottom are auto but height is
		if (style.hasAutoTop == false && style.hasAutoBottom == false)
		{
			//top and bottom are computed as they are defined either as length or percentage
			usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
			usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
			
			//the computed height is deduced from all the other computed vertical values. It is the remaining space when all the other value
			//are substracted from the containing HTMLElement height
			usedHeight = containingBlockData.height - usedValues.marginTop - usedValues.top - usedValues.bottom - usedValues.marginBottom - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth;
		}
		//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
		else if (style.hasAutoBottom == true)
		{
			usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
			usedValues.bottom = containingBlockData.height - usedValues.marginTop - usedValues.marginBottom - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top;
		}
		//same for top
		else if(style.hasAutoTop == true)
		{
			usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
			usedValues.top = containingBlockData.height - usedValues.marginTop - usedValues.marginBottom - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.bottom;
		}

		//if top or bottom are auto, then the height will be computed once the layout
		//of the HTMLElement children is done
		return usedHeight;
	}
	
	/**
	 * overriden to also compute top and bottom style
	 */
	override private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		//compute the height which is either defined as a length or a percentage
		var usedHeight:Float = getComputedHeight(style, containingBlockData);
		
		//if neither top nor bottom are defined as auto
		if (style.hasAutoTop == false && style.hasAutoBottom == false)
		{
			//compute top and bottom defined either as length or percentage
			usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
			usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
			
			//if both margin are auto, they will take the same size
			if (style.hasAutoMarginTop == true && style.hasAutoMarginBottom == true)
			{
				//compute the size of one of the margin, which is half the remaining vertical space
				//once all other values (padding, width, offset) are removed
				var usedMargin:Float = (containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom) / 2;
				
				if (usedMargin >= 0)
				{
					usedValues.marginTop = usedMargin;
					usedValues.marginBottom = usedMargin;
				}
				//if the margin height is negative, it is recomputed
				else
				{
					usedValues.marginBottom = 0;
					usedValues.marginTop = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.bottom - usedValues.top;
				}
			
			}
			//if only margin top is auto
			else if (style.hasAutoMarginTop == true)
			{
				//compute margin top then deduce margin bottom from the remaining vertical
				//space
				usedValues.marginBottom = getComputedMarginBottom(style, usedHeight, containingBlockData);
				usedValues.marginTop = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom - usedValues.marginBottom;
			}
			//same if only margin bottom is auto
			else if (style.hasAutoMarginBottom == true)
			{
				usedValues.marginTop = getComputedMarginTop(style, usedHeight, containingBlockData);
				usedValues.marginBottom = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom - usedValues.marginTop;
			}
			//else if no margins are auto, compute them
			else
			{
				usedValues.marginTop = getComputedMarginTop(style, usedHeight, containingBlockData);
				usedValues.marginBottom = getComputedMarginBottom(style, usedHeight, containingBlockData);
			}
		}
		//if either top or bottom is auto
		else
		{
			//any auto margin computes to 0
			if (style.hasAutoMarginTop == true)
			{
				usedValues.marginTop = 0;
			}
			else
			{
				usedValues.marginTop = getComputedMarginTop(style, usedHeight, containingBlockData);
			}
			
			if (style.hasAutoMarginBottom == true)
			{
				usedValues.marginBottom = 0;
			}
			else
			{
				usedValues.marginBottom = getComputedMarginBottom(style, usedHeight, containingBlockData);
			}
		
			//if top and bottom are both auto, the static position of top is used, then bottom is computed
			if (style.hasAutoTop == true && style.hasAutoBottom == true)
			{
				usedValues.top = getComputedStaticTop(style, containingBlockData);
				usedValues.bottom = containingBlockData.height - usedValues.marginTop - usedValues.marginBottom - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top;
			}
			//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
			else if (style.hasAutoBottom == true)
			{
				usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
				usedValues.bottom = containingBlockData.height - usedValues.marginTop - usedValues.marginBottom - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top;
			}
			//same for top
			else if(style.hasAutoTop == true)
			{
				usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
				usedValues.top = containingBlockData.height - usedValues.marginTop - usedValues.marginBottom - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.bottom;
			}
		}
		
		return usedHeight;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the HTMLElement to the left edge of its containing HTMLElement
	 */
	private function getComputedStaticLeft(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return style.usedValues.marginLeft;
	}
	
	/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the HTMLElement to the top edge of its containing HTMLElement
	 */
	private function getComputedStaticTop(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return style.usedValues.marginTop;
	}
}
