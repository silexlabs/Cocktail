/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
	private var _formattingContextData:RectangleData;

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
	}

	/**
	 * Init/reset the flow data using the containing block box
	 * properties
	 */
	private function initFormattingContextData():Void
	{
		var x:Float = _formattingContextRoot.coreStyle.computedStyle.paddingLeft;
		var y:Float = _formattingContextRoot.coreStyle.computedStyle.paddingTop;

		_formattingContextData = {
			x : x,
			y : y,
			height : 0.0,
			width:0.0
		};
	}

	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////

	/**
	 * starts a formatting
	 */
	public function format(floatsManager:FloatsManager):Void
	{	
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
				}
			}
		}
		//here the width is not shrinked
		else
		{
			shrinkedWidth = elementRenderer.coreStyle.computedStyle.width;
		}



		elementRenderer.coreStyle.computedStyle.width = shrinkedWidth;
	}


}