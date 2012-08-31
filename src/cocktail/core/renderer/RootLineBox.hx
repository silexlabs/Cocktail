/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
		
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			//absolutely positioned line box are not used to compute the
			//bounds of the root line box
			if (child.isAbsolutelyPositioned() == false)
			{
				lineBoxesBounds.push(child.bounds);
				
				if (child.hasChildNodes() == true)
				{
					var childrenBounds:Array<RectangleData> = getLineBoxesBounds(child);
					var childLength:Int = childrenBounds.length;
					for (j in 0...childLength)
					{
						lineBoxesBounds.push(childrenBounds[j]);
					}
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
		
		var length:Int = childrenBounds.length;
		for (i in 0...length)
		{
			var childBounds:RectangleData = childrenBounds[i];
			if (childBounds.x < left)
			{
				left = childBounds.x;
			}
			if (childBounds.y < top)
			{
				top = childBounds.y;
			}
			if (childBounds.x + childBounds.width > right)
			{
				right = childBounds.x + childBounds.width;
			}
			if (childBounds.y + childBounds.height  > bottom)
			{
				bottom = childBounds.y + childBounds.height;
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