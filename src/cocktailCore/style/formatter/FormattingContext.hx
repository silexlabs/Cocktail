/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.formatter;

import core.dom.HTMLElement;
import cocktailCore.style.floats.FloatsManager;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import cocktailCore.style.renderer.BlockBoxRenderer;
import cocktailCore.style.renderer.ElementRenderer;
import cocktailCore.style.renderer.FlowBoxRenderer;
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
	 * An instance of the class managing the floated DOMElements.
	 * During formatting, determine the position of the floats.
	 */
	private var _floatsManager:FloatsManager;
	
	/**
	 * Contains the data necessary to place the ElementRenderer in flow, 
	 * such as the coordinates where to insert the next ElementRenderer
	 */
	private var _formattingContextData:FormattingContextData;
	
	/**
	 * Holds a reference to each of the ElementRenderer formatted by this
	 * formatting context.
	 */
	private var _elementsInFormattingContext:Array<ElementRenderer>;
	
	/**
	 * a reference to the last inserted element renderer during 
	 * a formatting
	 */
	private var _lastInsertedElement:ElementRenderer;
	
	/**
	 * get the width of the largest line in the formatting context
	 */
	public var maxWidth(getMaxWidth, never):Int;
	
	private var _layOutLastLine:Bool;
	
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
		//will store the data of the floated DOMElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		initFormattingContextData();
		_elementsInFormattingContext = new Array<ElementRenderer>();
	}
	
	/**
	 * Init/reset the flow data using the containing block box
	 * properties
	 */
	private function initFormattingContextData():Void
	{
		_formattingContextData = {
			x : 0,
			y : 0,
			maxHeight : 0,
			maxWidth:0
		};
	}
	
	/**
	 * clean up class attributes
	 */
	public function dispose():Void
	{
		_elementsInFormattingContext = null;
		_formattingContextData = null;
		_lastInsertedElement = null;
		
		_floatsManager.dispose();
		_floatsManager = null;
		_formattingContextRoot = null;
	}

	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	
	/**
	 * inert an ElementRenderer in the formatting context
	 */
	public function insertElement(element:ElementRenderer):Void
	{
		_elementsInFormattingContext.push(element);
	}

	/**
	 * starts a formatting
	 */
	public function format():Void
	{	
		_layOutLastLine = true;
		doFormat(_elementsInFormattingContext);
	}
	
	/**
	 * Return the static position of an element renderer, the position it 
	 * would have had if it were in flow
	 * 
	 * TODO : static position is wrong in inline formatting context, buf with layOutLastLine ?
	 */
	public function getStaticPosition(element:ElementRenderer):PointData
	{
		_layOutLastLine = true;
		var elementsToFormat:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0..._elementsInFormattingContext.length)
		{
			elementsToFormat.push(_elementsInFormattingContext[i]);
		}
		
		elementsToFormat.push(element);
		
		doFormat(elementsToFormat);
		
		var x:Float = element.bounds.x;
		var y:Float = element.bounds.y;
		
		return {x:x, y:y};
	}
	
	/**
	 * Return the added height of the children of an ElementRenderer
	 * in this formatting context. Used by ElementRenderer with 
	 * an auto height to determine its height
	 * 
	 * TODO : add a method getChildrenWidth for shrink-to-fit ?
	 * 
	 * TODO : adding height isn't enough, get height of the bounds of children instead ?
	 * (to account for margin and paddings ?) -> should not margin into account in the getBounds
	 * method
	 */
	public function getChildrenHeight(elementRenderer:FlowBoxRenderer):Int
	{
		var height:Int = 0;
		
		if (elementRenderer == _formattingContextRoot)
		{
			height = _formattingContextData.maxHeight;
		}
		else
		{
			//add all the DOMElement boxesData's height
			var elementRenderers:Array<ElementRenderer> = getChildElementRenderers(elementRenderer);
			height = Math.round(getBounds(elementRenderers).height);
			/**
			for (i in 0...elementRenderers.length)
			{
				TODO : float can still account in max height if it overflows
				if (elementRenderers[i].isFloat() == false)
				{
					height += Math.round(elementRenderers[i].bounds.height);
				}
			}*/
		}
		
		//Log.trace(
		return height;
	}

	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
		private function getBounds(elements:Array<ElementRenderer>):RectangleData
	{

		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		
		for (i in 0...elements.length)
		{
			if (elements[i].bounds.x < left)
			{
				left = elements[i].bounds.x;
			}
			if (elements[i].bounds.y < top)
			{
				if (elements[i].isText() == false)
				{
					top = elements[i].bounds.y;
				}
				else
				{
					
					var htmlElementAscent:Float = elements[i].style.fontMetrics.ascent;
					var htmlElementDescent:Float = elements[i].style.fontMetrics.descent;	
			
				//the leading is an extra height to apply equally to the ascent
				//and the descent when laying out lines of text
				var leading:Float = elements[i].style.computedStyle.lineHeight - (htmlElementAscent + htmlElementDescent);
		
				//apply leading to the ascent and descent
				htmlElementAscent = Math.round((htmlElementAscent + leading / 2));
				htmlElementDescent = Math.round((htmlElementDescent + leading / 2));
					
					top = elements[i].bounds.y - htmlElementAscent;
				}
				
			}
			if (elements[i].bounds.x + elements[i].bounds.width > right)
			{
				right = elements[i].bounds.x + elements[i].bounds.width;
			}
			if (elements[i].bounds.y + elements[i].bounds.height  > bottom)
			{
				if (elements[i].isText() == false)
				{
					bottom = elements[i].bounds.y + elements[i].bounds.height;
				}
				else
				{
					
					
					
					var htmlElementAscent:Float = elements[i].style.fontMetrics.ascent;
				var htmlElementDescent:Float = elements[i].style.fontMetrics.descent;	
			
				//the leading is an extra height to apply equally to the ascent
				//and the descent when laying out lines of text
				var leading:Float = elements[i].style.computedStyle.lineHeight - (htmlElementAscent + htmlElementDescent);
		
				//apply leading to the ascent and descent
				htmlElementAscent = Math.round((htmlElementAscent + leading / 2));
				htmlElementDescent = Math.round((htmlElementDescent + leading / 2));
					
					bottom = elements[i].bounds.y - htmlElementAscent + elements[i].bounds.height;
				}
			}
		}
			
		bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
				
				
		return bounds;
		
	}
	
	private function doFormat(elementsInFormattingContext:Array<ElementRenderer>):Void
	{
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		initFormattingContextData();
		
		//format all the box element in order
		for (i in 0...elementsInFormattingContext.length)
		{
			doInsertElement(elementsInFormattingContext[i], isNextElementALineFeed(elementsInFormattingContext, i));
		}
	}

	private function doInsertElement(element:ElementRenderer, isNextElementALineFeed:Bool):Void
	{
		if (element.isFloat() == true)
		{
			insertFloat(element);
		}
		else if (element.canHaveChildren() == true)
		{
			if (element.style.establishesNewFormattingContext() == true)
			{
				insertFormattingContextRootElement(element);
			}
			else
			{
				insertContainerElement(element);
			}
		}
		else
		{
			if (element.isText() == true)
			{
				if (element.isSpace() == true)
				{
					insertSpace(element, isNextElementALineFeed);
				}
				else
				{
					insertText(element);
				}
				
			}
			else
			{
				insertEmbeddedElement(element);
			}
		}
	}
	
	private function getChildElementRenderers(elementRenderer:FlowBoxRenderer):Array<ElementRenderer>
	{
		var elementRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0..._elementsInFormattingContext.length)
		{
			if (_elementsInFormattingContext[i].parent == elementRenderer)
			{
				elementRenderers.push(_elementsInFormattingContext[i]);
			}
		}

		return elementRenderers;
	}
	
	private function insertEmbeddedElement(element:ElementRenderer):Void
	{ 
		//abstract
	}
	

	private function insertFormattingContextRootElement(element:ElementRenderer):Void
	{
		//abstract
	}
	
	private function insertContainerElement(element:ElementRenderer):Void
	{
		//abstract
	}

	/**
	 * Insert a text. overriden by sub-classes
	 */
	private function insertText(element:ElementRenderer):Void
	{
		//abstract
	}
	
	/**
	 * Insert a space. overriden by sub-classes
	 */
	private function insertSpace(element:ElementRenderer, isNextElementALineFeed:Bool):Void
	{
		//abstract	
	}
	
	/**
	 * Insert an horizontal offset. overriden by sub-classes
	 */
	private function insertHorizontalOffset(element:ElementRenderer):Void
	{
		//abstract
	}
	
	/**
	 * Insert a tab. overriden by sub-classes
	 */
	private function insertTab(element:ElementRenderer, isNextElementALineFeed:Bool):Void
	{
		//abstract
	}
	
	/**
	 * Insert a linefeed. overriden by sub-classes
	 */
	private function insertLineFeed(element:ElementRenderer):Void
	{
		//abstract
	}
	
	/**
	 * Insert a floated DOMElement. overriden by sub-classes
	 * 
	 * TODO : re-implement floats
	 */
	private function insertFloat(element:ElementRenderer):Void
	{
		//abstract
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
	private function clearFloat(clear:ClearStyleValue):Void
	{
		_floatsManager.clearFloat(clear, _formattingContextData);
	}
	
	/**
	 * Removed the floats which don't influence the 
	 * flow anymore. A float don't influence the flow
	 * anymore once the flow place DOMElement's below it
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
		var isNextElementALineFeed:Bool;
		
		//here the current element is the last in the array
		if (currentIndex + 1 >= elementsInFormattingContext.length)
		{
			isNextElementALineFeed = false;
		}
		//else check if the next element is indeed a line feed
		else
		{
			isNextElementALineFeed = elementsInFormattingContext[currentIndex + 1].isLineFeed();
		}
		
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