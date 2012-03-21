/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.floats;

import core.renderer.ElementRenderer;
import core.HTMLElement;
import core.style.formatter.FormattingContext;
import core.style.StyleData;
import haxe.Log;

/**
 * This class is in charge of keeping track of the 
 * floats currently affecting layout and exposes
 * method to help the formatting context to apply
 * floats to the layout.
 * 
 * @author Yannick DOMINGUEZ
 */
class FloatsManager 
{

	/**
	 * Holds a reference to each of the current left and right
	 * floats coordinates
	 */
	private var _floats:FloatsData;
	public var floats(getFloats, never):FloatsData;
	
	/**
	 * Class constructor, init the structure holding
	 * the floats data
	 */
	public function new() 
	{
		var floatsLeft:Array<FloatData> = new Array<FloatData>();
		var floatsRight:Array<FloatData> = new Array<FloatData>();
	
		_floats = {
			left:floatsLeft,
			right:floatsRight
		}
	}
	
	public function dispose():Void
	{
		_floats.left = null;
		_floats.right = null;
		_floats = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CLEARANCE METHODS
	// used to clear current floats
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Clears the left, right or both floats and return the new y position of
	 * the flow, the one below the cleared floats.
	 * 
	 * Empties the cleared floats array(s)
	 * 
	 * @param	clear the type of clearance (left, right or both)
	 * @param	formattingContextData used to compute the new formattingContextData y position
	 * @return  the new formattingContextData y position
	 */
	public function clearFloat(clear:Clear, formattingContextData:FormattingContextData):Int
	{
		var ret:Int;
		
		switch(clear)
		{
			case left:
				ret = clearLeft(formattingContextData);
				_floats.left = new Array<FloatData>();
				
			case right:
				ret = clearRight(formattingContextData);
				_floats.right = new Array<FloatData>();
				
			case both:	
				ret = clearBoth(formattingContextData);
				_floats.right = new Array<FloatData>();
				_floats.left = new Array<FloatData>();
			
			case none:
				ret = formattingContextData.y;
		}
		
		return ret;
	}
	
	/**
	 * Clear left floats
	 */
	private function clearLeft(formattingContextData:FormattingContextData):Int
	{
		return doClearFloat(formattingContextData, _floats.left);
	}
	
	/**
	 * Clear right floats
	 */
	private function clearRight(formattingContextData:FormattingContextData):Int
	{
		return doClearFloat(formattingContextData, _floats.right);
	}
	
	/**
	 * Clear right and left floats
	 */
	private function clearBoth(formattingContextData:FormattingContextData):Int
	{
		var leftY:Int = doClearFloat(formattingContextData, _floats.left);
		var rightY:Int = doClearFloat(formattingContextData, _floats.right);
		
		if (leftY > rightY)
		{
			return leftY;
		}
		else
		{
			return rightY;
		}
	}
	
	/**
	 * Actually clears a set of float (right or left). Finds the highest
	 * float among the cleared float and return its height + y as the new
	 * formattingContextData y position
	 * 
	 * @param formattingContextData the current formattingContextData, its y value is returned if there are no 
	 * floats to clear
	 * @param floats an array of floats to clear (right or left)
	 */
	private function doClearFloat(formattingContextData:FormattingContextData, floats:Array<FloatData>):Int
	{
		//if there are floats in the array, finds the highest one
		//and return its value
		if (floats.length > 0)
		{
			var highestFloat:FloatData = floats[0];
			
			for (i in 0...floats.length)
			{
				if (floats[i].y + floats[i].height > highestFloat.y + highestFloat.height)
				{
					highestFloat = floats[i];
				}
			}
			
			return highestFloat.y + highestFloat.height;
			
		}
		//else use the current formattingContextData y position as it doesn't change if
		//no floats are cleared
		else
		{
			return formattingContextData.y;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FLOAT CREATION METHODS
	// used to create structure to hold floats data from a 
	// floated DOMElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create and store a float data structure from a floated DOMElement
	 * @param	domElement the floated DOMElement
	 * @param	formattingContextData the flow data of the formatting context placing the floated
	 * DOMElement
	 * 
	 * TODO : shouldn't need a ref to HTMLElement
	 */
	public function computeFloatData(elementRenderer:ElementRenderer, formattingContextData:FormattingContextData, containingBlockWidth:Int):FloatData
	{
		var ret:FloatData;
		
		switch (elementRenderer.style.computedStyle.floatValue)
		{
			case left:
				ret = getLeftFloatData(elementRenderer, formattingContextData, containingBlockWidth);
				_floats.left.push(ret);
				
			case right:
				ret = getRightFloatData(elementRenderer, formattingContextData, containingBlockWidth);
				_floats.right.push(ret);
				
			default:
				ret = null;
		}
		
		return ret;
	}
	
	/**
	 * Create a float data structure for a left float
	 * 
	 * TODO : shouldn't need ref to html element
	 */
	private function getLeftFloatData(elementRenderer:ElementRenderer, formattingContextData:FormattingContextData, containingBlockWidth:Int):FloatData
	{
		//get float data except for x position
		var floatData:FloatData = getFloatData(elementRenderer, formattingContextData, containingBlockWidth);
		
		//a left float is placed to right of all the preceding left float
		//which are on the same line as this one
		floatData.x = getLeftFloatOffset(floatData.y);
		
		return floatData;
	}
	
	/**
	 * Create a float data structure for a right float
	 */
	private function getRightFloatData(elementRenderer:ElementRenderer, formattingContextData:FormattingContextData, containingBlockWidth:Int):FloatData
	{
		//get float data except for x position
		var floatData:FloatData = getFloatData(elementRenderer, formattingContextData, containingBlockWidth);
		
		//a right float is placed to the left of all the preceding right float which
		//are on the same line
		floatData.x = containingBlockWidth - floatData.width - getRightFloatOffset(floatData.y, containingBlockWidth);
		
		return floatData;
	}
	
	/**
	 * Create a generic float data structure which can be applied to both
	 * left and right float
	 */
	private function getFloatData(elementRenderer:ElementRenderer, formattingContextData:FormattingContextData, containingBlockWidth:Int):FloatData
	{
		//a float width and height use the margin box of a
		//DOMElement
		var floatWidth:Int = elementRenderer.style.htmlElement.offsetWidth;
		var floatHeight:Int = elementRenderer.style.htmlElement.offsetHeight;
	
		//get the first y position where the float can be placed
		var floatY:Int = getFirstAvailableY(formattingContextData, floatWidth, containingBlockWidth);
		
		//the x position of the float vary for left and right float
		var floatX:Int = 0;
	
		return {
			x: floatX,
			y: floatY,
			width:floatWidth,
			height:floatHeight
		}
	}
	
	/**
	 * Get the first y position in the current flow where an element
	 * (float or DOMElement) with a width equal to elementWidth can be inserted
	 * without overlapping floats or other DOMElements
	 * @param	formattingContextData the current formattingContextData
	 * @param	elementWidth the width of the element that must be inserted
	 * @param	containingBlockWidth the maximum available width in a line
	 * @return  the y position where the element can be inserted
	 */
	public function getFirstAvailableY(formattingContextData:FormattingContextData, elementWidth:Int, containingBlockWidth:Int):Int
	{
		//the y position default to the current y position
		//in the case where the element can be immediately inserted
		//in the flow
		var retY:Int = formattingContextData.y;
		
		//loop while there isn't enough horizontal space at the current y position to insert the
		//element
		while (getLeftFloatOffset(retY) + getRightFloatOffset(retY, containingBlockWidth) + elementWidth > containingBlockWidth)
		{
			//stores all the floats situated at the same height or after
			//the current y position
			var afterFloats:Array<FloatData> = new Array<FloatData>();
			
			//stores the relevant left floats
			for (i in 0..._floats.left.length)
			{
				if (_floats.left[i].y <= retY && _floats.left[i].height + _floats.left[i].y > retY)
				{
					afterFloats.push(_floats.left[i]);
				}
			}
			
			//stores the relevant right floats
			for (i in 0..._floats.right.length)
			{
				if (_floats.right[i].y <= retY && _floats.right[i].height + _floats.right[i].y > retY)
				{
					afterFloats.push(_floats.right[i]);
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
			//current y position while being equal or below
			//the y position
			else
			{
				//start with an "infinite" number, that will store
				//the offset between the bottom of the closest float
				//and the current y position
				var nextY:Int = 1000000;
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FLOAT REMOVAL METHODS
	// a float is removed from the list once the documents flow is below it,
	// which can happen after a DOMElement is placed or after the floats are cleared
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Removes the float that are above the current flow
	 * @param	flowY the y position of the current flow
	 */
	public function removeFloats(flowY:Int):Void
	{
		_floats.left = doRemoveFloat(_floats.left, flowY);
		_floats.right = doRemoveFloat(_floats.right, flowY);
	}
	
	/**
	 * Do removes the floats among an array of floats (left or right)
	 * which are above the current y flow
	 */
	private function doRemoveFloat(floats:Array<FloatData>, flowY:Int):Array<FloatData>
	{
		var newFloats:Array<FloatData> = new Array<FloatData>();
		
		for (i in 0...floats.length)
		{
			//if a floats y position + its height is superior to the flow,
			//then it is kept
			if (floats[i].y + floats[i].height > flowY)
			{
				newFloats.push(floats[i]);
			}
		}
		
		return newFloats;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FLOAT UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the right float offset at a y position. The right float offset is
	 * the added width of all the right floats which would be intersected if an horizontal
	 * line was drawn at the y position.
	 * 
	 */
	public function getRightFloatOffset(y:Int, containingWidth:Int):Int
	{
		var rightFloatOffset:Int = 0;
		
		//loop in all right floats
		for (i in 0..._floats.right.length)
		{
			//determine if the float intersects the line at y
			if (_floats.right[i].y + _floats.right[i].height > y &&
			_floats.right[i].y <= y)
			{
				//if it does, if its offset form the right border of the containing
				//block is superior to the current stored right offset, it becomes
				//the right offset
				if (containingWidth - _floats.right[i].x > rightFloatOffset)
				{
					rightFloatOffset = containingWidth - _floats.right[i].x;
				}
			}
		}
		
		return rightFloatOffset;
	}
	
	/**
	 * Return the left float offset at a y position. The left float offset is
	 * the added width of all the left floats which would be intersected if an horizontal
	 * line was drawn at the y position.
	 * 
	 */
	public function getLeftFloatOffset(y:Int):Int
	{
		var leftFloatOffset:Int = 0;
		
		//loop in all left floats
		for (i in 0..._floats.left.length)
		{
			//determine if the float intersects the line at y
			if (_floats.left[i].y + _floats.left[i].height > y &&
			_floats.left[i].y <= y)
			{
				//if it does, if its offset form the left border of the containing
				//block is superior to the current stored left offset, it becomes
				//the left offset
				if (_floats.left[i].x + _floats.left[i].width > leftFloatOffset)
				{
					leftFloatOffset = _floats.left[i].x + _floats.left[i].width;
				}
			}
		}
		
		return leftFloatOffset;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getFloats():FloatsData
	{
		return _floats;
	}
}