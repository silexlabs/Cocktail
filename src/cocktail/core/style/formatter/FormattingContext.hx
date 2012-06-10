/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;

import cocktail.core.html.HTMLElement;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.floats.FloatsManager;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import haxe.Log;

/**
 * This is the base class for formatting context. The formatting context
 * classes are in charge of placing in-flow elements in the document.
 * 
 * They can be placed following a block or inline formatting context.
 * In a block formatting, the ElementRenderer are placed on top of each
 * other, in an inline, they are placed next to each other.
 * 
 * Those classes also are also in charge of placing floated ElementRenderer
 * in the document and keeping a reference to each of the floated
 * ElementRenderer's position.
 * 
 * A formatting happens in 2 phases : 
 * - first all the elements renderer (block box, inline box, text...)
 * are inserted into the formatting context
 * - when all the elements participating in the formatting context
 * have been inserted, a call to the 'format' method actually format them, updating
 * for each ElemenRenderer the x/y position of its bounds relative to the formatting 
 * context root.
 * 
 * @author Yannick DOMINGUEZ
 */
class FormattingContext 
{
	/**
	 * A reference to the block box which started the
	 * formatting context
	 */ 
	private var _formattingContextRoot:BlockBoxRenderer;
	
	/**
	 * An instance of the class managing the floated HTMLElements.
	 * During formatting, determine the position of the floats.
	 */
	private var _floatsManager:FloatsManager;
	
	/**
	 * Contains the data necessary to place the ElementRenderer in flow, 
	 * such as the coordinates where to insert the next ElementRenderer
	 */
	private var _formattingContextData:FormattingContextData;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT/DISPOSE
	/////////////////////////////////
	
	/**
	 * Class constructor
	 * @param	formattingContextRoot the block box which establishes
	 * the formating context
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		_formattingContextRoot = formattingContextRoot;
		//will store the data of the floated HTMLElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		initFormattingContextData();
	}
	
	/**
	 * Init/reset the flow data using the containing block box
	 * properties
	 */
	private function initFormattingContextData():Void
	{
		_formattingContextData = {
			//TODO 4 : x and y still used by inline formatting context, bu shouldn't be necessary anymore,
			//use instead local var in recursive method, like for block formatting context
			x : _formattingContextRoot.coreStyle.computedStyle.paddingLeft,
			y : _formattingContextRoot.coreStyle.computedStyle.paddingTop,
			maxHeight : 0,
			maxWidth:0
		};
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	
	/**
	 * starts a formatting
	 */
	public function format():Void
	{	
		_floatsManager = new FloatsManager();
		doFormat();
		applyShrinkToFitIfNeeded(_formattingContextRoot, _formattingContextData.maxWidth);
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	private function doFormat(staticPositionedElement:ElementRenderer = null):Void
	{
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		initFormattingContextData();
	}

	private function applyShrinkToFitIfNeeded(elementRenderer:ElementRenderer, minimumWidth:Float):Void
	{
		var shrinkedWidth:Float = elementRenderer.coreStyle.computedStyle.width;
		
		if (elementRenderer.coreStyle.width == Dimension.cssAuto)
		{
			if (elementRenderer.isFloat() == true || elementRenderer.coreStyle.computedStyle.display == inlineBlock)
			{
				shrinkedWidth = minimumWidth;
			}
			else if (elementRenderer.isPositioned() == true && elementRenderer.isRelativePositioned() == false)
			{
				var style:CoreStyle = elementRenderer.coreStyle;
				
				//shrink-to-fit only happen if either left or right is auto
				if (style.left == PositionOffset.cssAuto || style.right == PositionOffset.cssAuto)
				{
					var computedStyle:ComputedStyle = style.computedStyle;
					//compute the shrinked width
					shrinkedWidth = minimumWidth;
					/**
					//if both right and left are auto, use left static position, then deduce right
					if (style.left == PositionOffset.cssAuto && style.right == PositionOffset.cssAuto)
					{
						style.computedStyle.left = getComputedStaticLeft(style, containingBlockData);
						style.computedStyle.right = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
					}
					//if only right is auto, compute left then deduce right
					else if (style.right == PositionOffset.cssAuto)
					{
						style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
						style.computedStyle.right = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
					}
					//same for left
					else if (style.left == PositionOffset.cssAuto)
					{
						style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
						style.computedStyle.left = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
					}
					*/
				}
			}
		}
		//here the width is not shrinked
		else
		{
			shrinkedWidth = elementRenderer.coreStyle.computedStyle.width;
		}
		
		elementRenderer.coreStyle.computedStyle.width = Math.round(shrinkedWidth);
	}
	
	/////////////////////////////////
	// PRIVATE UTILS METHODS
	/////////////////////////////////
	
	/**
	 * Clear all the current left, or right or both floats.
	 * When floats are cleared, the flow y attribute is placed
	 * at the bottom of the last cleared float
	 * 
	 * TODO 5 : re-implement float
	 */
	private function clearFloat(clear:Clear):Void
	{
		_floatsManager.clearFloat(clear, _formattingContextData.y);
	}
	
	/**
	 * Removed the floats which don't influence the 
	 * flow anymore. A float don't influence the flow
	 * anymore once the flow place HTMLElement's below it
	 * 
	 * TODO 5 : re-implement floats
	 */
	private function removeFloats():Void
	{
		_floatsManager.removeFloats(_formattingContextData.y);
	}
	
	/**
	 * Determine wheter the next element in the formattable elements array is a linefeed
	 */
	private function isNextElementALineFeed(elementsInFormattingContext:Array<ElementRenderer>, currentIndex:Int):Bool
	{
		var isNextElementALineFeed:Bool = false;
		//
		//here the current element is the last in the array
		//if (currentIndex + 1 >= elementsInFormattingContext.length)
		//{
			//isNextElementALineFeed = false;
		//}
		//else check if the next element is indeed a line feed
		//else
		//{
			//isNextElementALineFeed = elementsInFormattingContext[currentIndex + 1].isLineFeed();
		//}
		
		return isNextElementALineFeed;
	}
	
}