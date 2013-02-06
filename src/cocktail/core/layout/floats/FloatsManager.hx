/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.floats;

using cocktail.core.utils.Utils;
import cocktail.core.css.CoreStyle;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.html.HTMLElement;

import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import haxe.Log;

/**
 * For a given block box, keep track
 * of the floated element affecting
 * its layout and exposes method to
 * find the position of elements
 * afffected by those floated element
 * 
 * Also used by floated elements to register
 * themselves and get their bounds
 * 
 * The bounds of the stored floated
 * element are always defined in the
 * space of their first block formatting
 * root ancestor
 * 
 * @author Yannick DOMINGUEZ
 */
class FloatsManager 
{

	/**
	 * Holds a reference to each of the current left and right
	 * floats, in the current block formatting context
	 */
	public var floats(default, set_floats):FloatsVO;
	
	/**
	 * Holds a reference to each element whit clearance
	 * in the current block formatting context
	 */
	public var childrenWithClearance:Array<ElementRenderer>;
	
	/**
	 * Holds wether this float manager has any registered float
	 */
	public var hasFloats:Bool;
	
	/**
	 * Class constructor, init the structure holding
	 * the floats data
	 */
	public function new() 
	{
		var floatsLeft:Array<FloatVO> = new Array<FloatVO>();
		var floatsRight:Array<FloatVO> = new Array<FloatVO>();
		childrenWithClearance = new Array<ElementRenderer>();
		floats = new FloatsVO(floatsLeft, floatsRight);
		hasFloats = false;
	}
	
	/**
	 * init/reset the class attributes
	 */
	public function init():Void
	{
		if (floats.left.length > 0 || floats.right.length > 0)
		{
			floats.left = floats.left.clear();
			floats.right = floats.right.clear();
			hasFloats = false;
		}
		childrenWithClearance = new Array<ElementRenderer>();
	}
	
	public function registerClear(elementRenderer:ElementRenderer):Void
	{
		childrenWithClearance.push(elementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CLEARANCE METHODS
	// used to clear current floats
	//////////////////////////////////////////////////////////////////////////////////////////
	

	public function getClearance(target:ElementRenderer, currentY:Float):Float
	{
		var clearance:Float = 0;
		
		switch(target.coreStyle.getKeyword(target.coreStyle.clear))
		{
			
			case LEFT:
				clearance = doGetClearance(target, currentY, floats.left);
				
			case RIGHT:	
				clearance = doGetClearance(target, currentY, floats.right);
				
			case BOTH:	
				clearance = clearBoth(target, currentY);
				
			default:
		}
		
		return clearance;
	}
	
	public function hasClearance(target:ElementRenderer, currentY:Float):Bool
	{
		var hasClearance:Bool = false;
		
		switch(target.coreStyle.getKeyword(target.coreStyle.clear))
		{
			
			case LEFT:
				hasClearance = doGetHasClearance(target, currentY, floats.left);
				
			case RIGHT:	
				hasClearance = doGetHasClearance(target, currentY, floats.right);
				
			case BOTH:	
				hasClearance = hasClearanceBoth(target, currentY);
				
			default:
		}
		
		return hasClearance;
	}
	
	/**
	 * Clear right and left floats
	 */
	private function clearBoth(target:ElementRenderer, currentY:Float):Float
	{
		var leftClearance:Float = doGetClearance(target, currentY, floats.left);
		var rightClearance:Float = doGetClearance(target, currentY, floats.right);
		
		//the higher clearance between right and left float is the 
		//used one
		if (leftClearance > rightClearance)
		{
			return leftClearance;
		}
		else
		{
			return rightClearance;
		}
	}
	
	private function hasClearanceBoth(target:ElementRenderer, currentY:Float):Bool
	{
		var hasLeftClearance:Bool = doGetHasClearance(target, currentY, floats.left);
		
		if (hasLeftClearance == true)
		{
			return true;
		}
		
		return doGetHasClearance(target, currentY, floats.right); 
	}
	
	private function doGetClearance(target:ElementRenderer, currentY:Float, floats:Array<FloatVO>):Float
	{
		var clearance:Float = 0;
		
		var maxY:Float = currentY;
		
		var length:Int = floats.length;
		for (i in 0...length)
		{
			var floatBounds:RectangleVO = floats[i].bounds;
			if (floatBounds.y + floatBounds.height >= maxY
			|| floatBounds.y <= maxY  && floatBounds.y + floatBounds.height > maxY)
			{
				maxY = floatBounds.y + floatBounds.height;
			}
		}
		
		return maxY - currentY;
	}
	
	private function doGetHasClearance(target:ElementRenderer, currentY:Float, floats:Array<FloatVO>):Bool
	{
		var length:Int = floats.length;
		for (i in 0...length)
		{
			var floatBounds:RectangleVO = floats[i].bounds;
			if (floatBounds.y + floatBounds.height >= currentY
			|| floatBounds.y <= currentY  && floatBounds.y + floatBounds.height > currentY)
			{
				return true;
			}
		}
		
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FLOAT CREATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * register a floated element, set its bounds in the block formatting root space,
	 * and return those bounds
	 */
	public function registerFloat(elementRenderer:ElementRenderer, floatY:Float, containingBlockWidth:Float, containingBlockXOffset:Float):RectangleVO
	{
		switch (elementRenderer.coreStyle.getKeyword(elementRenderer.coreStyle.cssFloat))
		{
			case LEFT:
				var floatBounds:RectangleVO = getLeftFloatBounds(elementRenderer, floatY, containingBlockWidth, containingBlockXOffset);
				floats.left.push(new FloatVO(elementRenderer, floatBounds));
				hasFloats = true;
				return floatBounds;

			case RIGHT:
				var floatBounds:RectangleVO = getRightFloatBounds(elementRenderer, floatY, containingBlockWidth, containingBlockXOffset);
				floats.right.push(new FloatVO(elementRenderer, floatBounds));
				hasFloats = true;
				return floatBounds;
				
			default:
				throw 'Illegal value for float style';
		}
	}
	
	/**
	 * Get the bounds for a left floated element taking previous floated
	 * elements into account
	 */
	private function getLeftFloatBounds(elementRenderer:ElementRenderer, floatY:Float, containingBlockWidth:Float, containingBlockXOffset:Float):RectangleVO
	{
		//get float bounds except for x position
		var floatBounds:RectangleVO = getFloatBounds(elementRenderer, floatY, containingBlockWidth, containingBlockXOffset);

		//a left float is placed to right of all the preceding left float
		//which are on the same line as this one
		floatBounds.x = getLeftFloatOffset(floatBounds.y, floatBounds.height, containingBlockXOffset);
		
		return floatBounds;
	}
	
	/**
	 * Get the bounds for a right floated element taking previous floated
	 * elements into account
	 */
	private function getRightFloatBounds(elementRenderer:ElementRenderer, floatY:Float, containingBlockWidth:Float, containingBlockXOffset:Float):RectangleVO
	{
		//get float bounds except for x position
		var floatBounds:RectangleVO = getFloatBounds(elementRenderer, floatY, containingBlockWidth, containingBlockXOffset);

		//a right float is placed to the left of all the preceding right float which
		//are on the same line
		floatBounds.x = getRightFloatOffset(floatBounds.y, floatBounds.height, floatBounds.width, containingBlockXOffset, containingBlockWidth) - floatBounds.width;
		
		return floatBounds;
	}
	
	/**
	 * Get the bounds for a floated element, in the space of its first
	 * block formatting root ancestor
	 */
	private function getFloatBounds(elementRenderer:ElementRenderer, floatY:Float, containingBlockWidth:Float, containingBlockXOffset:Float):RectangleVO
	{
		//a float width and height use the margin box of the element
		
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		var floatWidth:Float = elementRenderer.bounds.width + usedValues.marginLeft + usedValues.marginRight;
		var floatHeight:Float = elementRenderer.bounds.height + usedValues.marginTop + usedValues.marginBottom;
	
		//get the first y position where the float can be placed
		var floatY:Float = getFirstAvailableYPosition(floatY, floatHeight, floatWidth, containingBlockWidth, containingBlockXOffset);
		
		//the x position of the float vary for left and right float
		var floatX:Float = 0.0;
	
		var rect:RectangleVO = new RectangleVO();
		rect.x  = floatX;
		rect.y = floatY;
		rect.width = floatWidth;
		rect.height = floatHeight;
		return rect;
	}
	
	/**
	 * Get the first y position in the current flow where an element
	 * (floated or not) with a width equal to elementWidth can be inserted
	 * without overlapping floats or other elements
	 * @param	currentYPosition the current y position where the children will be inserted if it can fit, in block formatting root space
	 * @param	elementHeight the height of the element which must be inserted
	 * @param	elementWidth the width of the element that must be inserted
	 * @param	containingBlockWidth the maximum available width in the current line
	 * @param	containingBlockXOffset the x  of the containing blokc relative to its first block formatting ancestor.
	 * Used when inserting floated element to convert from the containing block space to the block formatting context root space. 
	 * 
	 * @return  the y position where the element can be inserted, in block formatting root space
	 */
	public function getFirstAvailableYPosition(currentYPosition:Float, elementHeight:Float, elementWidth:Float, containingBlockWidth:Float, containingBlockXOffset:Float):Float
	{
		//the y position default to the current y position
		//in the case where the element can be immediately inserted
		//in the flow
		var retY:Float = currentYPosition;
		
		//loop while there isn't enough horizontal space at the current y position to insert the
		//element
		while (canFitElementAtY(retY, elementHeight, elementWidth, containingBlockWidth, containingBlockXOffset) == false)
		{
			//stores all the floats situated at the same height or after
			//the current y position and/or at the same height or after the current
			//y position + height of the element to insert
			var afterFloats:Array<RectangleVO> = new Array<RectangleVO>();
			
			//stores the relevant left floats
			var leftFloatLength:Int = floats.left.length;
			for (i in 0...leftFloatLength)
			{
				var floatBounds:RectangleVO = floats.left[i].bounds;
				if (floatBounds.y <= retY && floatBounds.height + floatBounds.y > retY
				|| floatBounds.y <= (retY + elementHeight) && floatBounds.y > retY)
				{
					afterFloats.push(floatBounds);
				}
			}
			
			//stores the relevant right floats
			var rightFloatLength:Int = floats.right.length;
			for (i in 0...rightFloatLength)
			{
				var floatBounds:RectangleVO = floats.right[i].bounds;
				if (floatBounds.y <= retY && floatBounds.height + floatBounds.y > retY
				|| floatBounds.y <= (retY + elementHeight) && floatBounds.y > retY)
				{
					afterFloats.push(floatBounds);
				}
			}
			
			//if there are no floats past the y position, 
			//then it is a safe position to insert the element
			//so the loop is broken
			if (afterFloats.length == 0)
			{
				break;
			}
			//else the next float is found. The next float
			//is the one whose bottom is the closest to the
			//current y position + element height (forming the
			//bottom position of the element) while being equal or below
			//the y position
			else
			{
				//start with an "infinite" number, that will store
				//the offset between the bottom of the closest float
				//and the current y position
				var nextY:Float = 1000000;
				//and loop in all the floats to find the
				//one closest to the current y position
				for (i in 0...afterFloats.length)
				{
					if (afterFloats[i].y + afterFloats[i].height - retY < nextY)
					{
						nextY = afterFloats[i].y + afterFloats[i].height - retY;
					}
				}
				
				//once the offset is found, it is added to the current y position
				//so that the y position is now placed art the bottom of the next float.
				//the loop then starts again and test if there is enough horizontal
				//space in the new y position to insert the element
				retY += nextY;
			}
		}
		
		//at this point the y position to insert the element is found
		return retY;
	}
	
	/**
	 * Returns wether the element can be fitted at the y position,
	 * given its bounds and the available width
	 */
	private function canFitElementAtY(y:Float, elementHeight:Float, elementWidth:Float, containingBlockWidth:Float, containingBlockXOffset:Float):Bool
	{
		//test if top y position of element can fit
		if (getRightFloatOffset(y, elementHeight, elementWidth, containingBlockXOffset, containingBlockWidth) - getLeftFloatOffset(y, elementHeight, containingBlockXOffset) < elementWidth)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FLOAT UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the left float offset intersecting with the line between y and y + elementHeight. The left
	 * float offset is the distance from the left edge of the content area of the block formatting root
	 * to either the right edge of the right-most left floated element or the x offset of the containing
	 * block whichever is bigger
	 */
	public function getLeftFloatOffset(y:Float, elementHeight:Float, containingBlockXOffset:Float):Float
	{
		var leftFloatOffset:Float = containingBlockXOffset;
		
		//loop in all left floats
		var length:Int = floats.left.length;
		
		for (i in 0...length)
		{
			var floatBounds:RectangleVO = floats.left[i].bounds;
			
			//determine if the float intersects the line
			if (floatBounds.y + floatBounds.height > y && floatBounds.y <= y
			|| floatBounds.y <= (y + elementHeight) && floatBounds.y > y)
			{
				//if it does, if its offset from the left border of the block formatting root
				//is superior to the current stored left offset, use it
				if (floatBounds.x + floatBounds.width > leftFloatOffset)
				{
					leftFloatOffset = floatBounds.x + floatBounds.width;
				}
			}
		}
		
		return leftFloatOffset;
	}
	
	/**
	 * same as above for right float offset
	 * 
	 * The right float offset is the distance from the left edge of the
	 * content area of the block formatting root to the right edge of the right
	 * most right floated element or the right edge of the containing block,
	 * whichever is bigger
	 */
	public function getRightFloatOffset(y:Float, elementHeight:Float, elementWidth:Float, containingBlockXOffset:Float, containingBlockWidth:Float):Float
	{
		var rightFloatOffset:Float = containingBlockXOffset + containingBlockWidth;
		
		var length:Int = floats.right.length;
		for (i in 0...length)
		{
			var floatBounds:RectangleVO = floats.right[i].bounds;
			if (floatBounds.y + floatBounds.height > y && floatBounds.y <= y
			|| floatBounds.y <= (y + elementHeight) && floatBounds.y > y)
			{
				if (floatBounds.x < rightFloatOffset)
				{
					rightFloatOffset = floatBounds.x;
				}
			}
		}
		
		return rightFloatOffset;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTER METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set when floated elements are
	 * retrieved from the block formatting
	 * root, evaluate wether there are any floats
	 * on the block formatting root
	 */
	private function set_floats(value:FloatsVO):FloatsVO
	{
		floats = value;
		
		if (value.left.length > 0 || value.right.length > 0)
		{
			hasFloats = true;
		}
		else
		{
			hasFloats = false;
		}
		
		return value;
	}
}