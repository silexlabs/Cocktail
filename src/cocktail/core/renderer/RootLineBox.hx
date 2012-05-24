/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.style.CoreStyle;
import cocktail.core.geom.GeomData;

/**
 * A special kind of line box which represents
 * the start of a line in an inline formatting context.
 * 
 * Each line is stored as a tree of line boxes started
 * by a RootLineBox
 * 
 * @author Yannick DOMINGUEZ
 */
class RootLineBox extends LineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The bounds of a root line box is the bounds
	 * of all of its child line boxes
	 */
	override private function get_bounds():RectangleData
	{
		return getChildrenBounds(getLineBoxesBounds(this));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 4 : those method are already on ElementRenderer, share a common class ? interface ?
	//add an helper class ?
	
	/**
	 * Retrieve all the bounds of the child line box
	 */
	private function getLineBoxesBounds(lineBox:LineBox):Array<RectangleData>
	{
		var lineBoxesBounds:Array<RectangleData> = new Array<RectangleData>();
		
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			lineBoxesBounds.push(child.bounds);


			if (child.hasChildNodes() == true)
			{
				var childrenBounds:Array<RectangleData> = getLineBoxesBounds(child);
				for (j in 0...childrenBounds.length)
				{
					lineBoxesBounds.push(childrenBounds[j]);
				}
			}
		}
		
		return lineBoxesBounds;
	}
	
	/**
	 * Get the bounds of all of the child line boxes bounds
	 */
	private function getChildrenBounds(childrenBounds:Array<RectangleData>):RectangleData
	{

		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		
		for (i in 0...childrenBounds.length)
		{
			if (childrenBounds[i].x < left)
			{
				left = childrenBounds[i].x;
			}
			if (childrenBounds[i].y < top)
			{
				top = childrenBounds[i].y;
			}
			if (childrenBounds[i].x + childrenBounds[i].width > right)
			{
				right = childrenBounds[i].x + childrenBounds[i].width;
			}
			if (childrenBounds[i].y + childrenBounds[i].height  > bottom)
			{
				bottom = childrenBounds[i].y + childrenBounds[i].height;
			}
		}
			
		bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
		
		//need to implement better fix,
		//sould not be negative
		if (bounds.width < 0)
		{
			bounds.width = 0;
		}
		if (bounds.height < 0)
		{
			bounds.height = 0;
		}
				
		return bounds;
		
	}
	
}