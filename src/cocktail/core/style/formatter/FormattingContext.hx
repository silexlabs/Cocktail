/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;

import cocktail.core.html.HTMLElement;
import cocktail.core.style.floats.FloatsManager;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
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
	
	/**
	 * get the width of the largest line in the formatting context
	 */
	public var maxWidth(getMaxWidth, never):Int;
	
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
			//TODO : x and y still used by inline formatting context, bu shouldn't be necessary anymore,
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
		doFormat();
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

	/////////////////////////////////
	// PRIVATE UTILS METHODS
	/////////////////////////////////
	
	/**
	 * Clear all the current left, or right or both floats.
	 * When floats are cleared, the flow y attribute is placed
	 * at the bottom of the last cleared float
	 * 
	 * TODO : re-implement float
	 */
	private function clearFloat(clear:Clear):Void
	{
		_floatsManager.clearFloat(clear, _formattingContextData);
	}
	
	/**
	 * Removed the floats which don't influence the 
	 * flow anymore. A float don't influence the flow
	 * anymore once the flow place HTMLElement's below it
	 * 
	 * TODO : re-implement floats
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
	
	/////////////////////////////////
	// GETTERS/SETTERS
	/////////////////////////////////
	
	private function getMaxWidth():Int
	{
		return _formattingContextData.maxWidth;
	}
	
}