/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.formatter;

import cocktail.core.html.HTMLElement;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.css.CSSData;
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
	private var _formattingContextData:RectangleVO;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT/DISPOSE
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new() 
	{
		
	}
	
	/**
	 * Init/reset the flow data using the containing block box
	 * properties
	 */
	private function initFormattingContextData():Void
	{
		var x:Float = _formattingContextRoot.coreStyle.usedValues.paddingLeft;
		var y:Float = _formattingContextRoot.coreStyle.usedValues.paddingTop;
		
		_formattingContextData = new RectangleVO(x, y, 0.0, 0.0);
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	
	/**
	 * starts a formatting
	 * @param	formattingContextRoot the block box which establishes
	 * the formating context
	 */
	public function format(formattingContextRoot:BlockBoxRenderer, floatsManager:FloatsManager):Void
	{	
		_formattingContextRoot = formattingContextRoot;
		_floatsManager = floatsManager;
		initFormattingContextData();
		startFormatting();
		applyShrinkToFitIfNeeded(_formattingContextRoot, _formattingContextData.width);
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	private function startFormatting():Void
	{
		//abstract
	}

	private function applyShrinkToFitIfNeeded(elementRenderer:ElementRenderer, minimumWidth:Float):Void
	{
		var style:CoreStyle = elementRenderer.coreStyle;
		
		var shrinkedWidth:Float = style.usedValues.width;
		
		if (style.isAuto(style.width) == true)
		{
			if (elementRenderer.isFloat() == true || style.getKeyword(style.display) == INLINE_BLOCK)
			{
				shrinkedWidth = minimumWidth;
			}
			else if (elementRenderer.isPositioned() == true && elementRenderer.isRelativePositioned() == false)
			{
				//shrink-to-fit only happen if either left or right is auto
				if (style.isAuto(style.left) == true || style.isAuto(style.right) == true)
				{
					//compute the shrinked width
					shrinkedWidth = minimumWidth;
				}
			}
		}
		//here the width is not shrinked
		else
		{
			shrinkedWidth = style.usedValues.width;
		}
		
		style.usedValues.width = shrinkedWidth;
	}
	
	
}