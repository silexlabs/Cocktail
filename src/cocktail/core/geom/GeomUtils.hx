/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.geom;
import cocktail.core.geom.GeomData;

/**
 * This class contains various geometry
 * related methods
 * 
 * @author Yannick DOMINGUEZ
 */
class GeomUtils 
{
	/**
	 * class constructor. Private,
	 * this is a static class
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Add bounds to another to get
	 * the bounds encompassing both
	 * 
	 * @param	addedBounds the bounds that will be added
	 * @param	bounds the bounds that will be updated to include the added bounds
	 * @param	getHorizontalBounds wether to add horizontal bounds
	 * @param	getVerticalBounds wether to add vertical bounds
	 */
	public inline static function addBounds(addedBounds:RectangleVO, bounds:RectangleVO, getHorizontalBounds:Bool = true, getVerticalBounds:Bool = true ):Void
	{
		//add horizontal bounds if needed
		if (getHorizontalBounds == true)
		{
			if (addedBounds.x < bounds.x)
			{
				bounds.x = addedBounds.x;
			}
			if (addedBounds.x + addedBounds.width > bounds.x + bounds.width)
			{
				bounds.width = addedBounds.x + addedBounds.width - bounds.x;
			}
		}
		
		//add vertical bounds if needed
		if (getVerticalBounds == true)
		{
			if (addedBounds.y < bounds.y)
			{
				bounds.y = addedBounds.y;
			}
			
			if (addedBounds.y + addedBounds.height  > bounds.y + bounds.height)
			{
				bounds.height = addedBounds.y + addedBounds.height - bounds.y;
			}
		}
	}
	
	/**
	 * Get the intersecting bounds of 2 bounds
	 * (the area they share) and store it in the result
	 * bounds
	 * 
	 * @param	bounds1 first bounds to intersect
	 * @param	bounds2 second bounds to intersec
	 * @param	resultBounds store the intersecting bounds of the 2 bounds
	 */
	public static function intersectBounds(bounds1:RectangleVO, bounds2:RectangleVO, resultBounds:RectangleVO):Void
	{
		var left:Float = 0;
		var right:Float = 0;
		var top:Float = 0;
		var bottom:Float =  0;
		
		//early return if the 2 bounds don't intersect at all
		if (bounds1.x + bounds1.width < bounds2.x
		|| bounds2.x + bounds2.width < bounds1.x
		|| bounds1.y + bounds1.height < bounds2.y
		|| bounds2.y + bounds2.height < bounds1.y)
		{
			//as there is no intersections, bounds are 0
			resultBounds.x = 0;
			resultBounds.y = 0;
			resultBounds.height = 0;
			resultBounds.width = 0;
			return;
		}
		
		if (bounds1.x < bounds2.x)
		{
			left = bounds2.x;
		}
		else
		{
			left = bounds1.x;
		}
		
		if (bounds1.x + bounds1.width < bounds2.x + bounds2.width)
		{
			right = bounds1.x + bounds1.width;
		}
		else
		{
			right = bounds2.x + bounds2.width;
		}
		
		if (bounds1.y < bounds2.y)
		{
			top = bounds2.y;
		}
		else
		{
			top = bounds1.y;
		}
		
		if (bounds1.y + bounds1.height < bounds2.y + bounds2.height)
		{
			bottom = bounds1.y + bounds1.height;
		}
		else
		{
			bottom = bounds2.y + bounds2.height;
		}
		
		//apply resulting bounds
		resultBounds.x = left;
		resultBounds.y = top;
		resultBounds.width = right - left;
		resultBounds.height = bottom - top;
	}
	
	/**
	 * For a given maximum width and height, and a
	 * given bounds width and height, find the rect 
	 * representing the max width and height that 
	 * the bounds can take while preserving proporitions.
	 * This rect is also centered vertically and horizontally.
	 * 
	 * This method was originally created to scale and
	 * center video and picture in a container
	 * 
	 * @param	maximumWidth the maximum width available
	 * @param	maximumHeight the maximum height available
	 * @param	boundsWidth the width which should be scaled to take maximum space
	 * @param	boundsHeight the height which should be scaled to take maximum space
	 * @param	resultBounds the bounds which will store the resulting rect
	 */
	public static function getCenteredBounds(maximumWidth:Float, maximumHeight:Float, boundsWidth:Float, boundsHeight:Float, resultBounds:RectangleVO):Void
	{
		//those will hold the actual value used for
		//dimensions, with the kept aspect ratio
		var width:Float;
		var height:Float;

		if (maximumWidth > maximumHeight)
		{
			//get the ratio between the bounds width and the maximum width it can use
			var ratio:Float = boundsHeight / maximumHeight;
			
			//check that the bounds width isn't wider than the maximum width
			if ((boundsWidth / ratio) < maximumWidth)
			{
				//reduce the width if wider than max width
				width =  boundsWidth / ratio ;
				height = maximumHeight;
			}
			//else reduce the height instead of the width
			else
			{
				ratio = boundsWidth / maximumWidth;
				width = maximumWidth;
				height = boundsHeight / ratio;
			}
		}
		//same as above but inverted
		else
		{
			var ratio:Float = boundsWidth / maximumWidth;
			
			if ((boundsHeight / ratio) < maximumHeight)
			{
				height = boundsHeight / ratio;
				width = maximumWidth;
			}
			else
			{
				ratio = boundsHeight / maximumHeight;
				width =  boundsWidth / ratio ;
				height = maximumHeight;
			}
		}
		
		//center the bounds
		var xOffset:Float = (maximumWidth - width) / 2;
		var yOffset:Float = (maximumHeight - height) / 2;
		
		resultBounds.x = xOffset;
		resultBounds.y = yOffset;
		resultBounds.width = width;
		resultBounds.height = height;
	}
	
}