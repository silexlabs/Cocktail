/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.formatter;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
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
 * In a block formatting, the DOMElements are placed on top of each
 * other, in an inline, they are placed next to each other.
 * 
 * Those classes also are also in charge of placing floated DOMElement
 * in the document and keeping a reference to each of the floated
 * DOMElement's position.
 * 
 * A formatting happens in 2 phases : 
 * - first all the elements (DOMElement, text, control charachter...)
 * are inserted into the formatting context
 * - when all the elements participating in the formatting context
 * have been inserted, a call to the 'format' actually format them, storing
 * for each element its x/y position and dimensions relative to the containing DOMElement
 * which started the formatting context. Those boxes data are stored
 * and used when the document is rendered
 * 
 * @author Yannick DOMINGUEZ
 */
class FormattingContext 
{
	/**
	 * A reference to the DOMElement which started the
	 * formatting context (the containing block which 
	 * started the formatting context)
	 */ 
	private var _formattingContextRoot:BlockBoxRenderer;
	
	/**
	 * The width of the DOMElement starting the formatting context,
	 * representing the maximum width of a line.
	 * 
	 * TODO : check if still necessary
	 */
	private var _formattingContextRootWidth:Int;
	
	/**
	 * An instance of the class managing the floated DOMElements.
	 * During formatting, determine the position of the floats.
	 */
	private var _floatsManager:FloatsManager;
	
	/**
	 * Contains the data necessary to place the DOMElements in flow, 
	 * such as the coordinates where to insert the next DOMElement
	 */
	private var _formattingContextData:FormattingContextData;
	public var formattingContextData(getFormattingContextData, never):FormattingContextData;
	
	/**
	 * Holds a reference to each of the box elements formatted by this
	 * formatting context. The corresponding box data are generated
	 * when the 'format' method is called
	 */
	private var _elementsInFormattingContext:Array<ElementRenderer>;
	
	/**
	 * a reference to the last inserted element in the line, used for 
	 * instance when a space is inserted to checkk if the previous
	 * element was also a space and if it should be collapsed
	 */
	private var _lastInsertedElement:ElementRenderer;
	
	private var _layOutLastLine:Bool;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 * @param	domElement the containing DOMElement which starts the formatting context
	 * (the containing block)
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		//store a reference to the DOMElement starting the formatting context
		_formattingContextRoot = formattingContextRoot;
		_formattingContextRootWidth = _formattingContextRoot.domElement.style.computedStyle.width;
		
		//will store the data of the floated DOMElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		
		_layOutLastLine = false;
		
		_formattingContextData = initFormattingContextData();
		_elementsInFormattingContext = new Array<ElementRenderer>();
	}
	
	/**
	 * Init/reset the flow data using the containing DOMElement's
	 * properties
	 */
	private function initFormattingContextData():FormattingContextData
	{
		var flowY:Int = 0;
		var flowX:Int = 0;
		
		return {
			x : flowX,
			y : flowY,
			maxHeight : 0,
			maxWidth:0
		};
	}

	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	

	public function dispose():Void
	{
		_elementsInFormattingContext = null;
		_formattingContextData = null;
		_lastInsertedElement = null;
		
		_floatsManager.dispose();
		_floatsManager = null;
		_formattingContextRoot = null;
	}
	
	public function insertElement(element:ElementRenderer):Void
	{
		_elementsInFormattingContext.push(element);
	}
	
	//TODO : static position is wrong in inline formatting context, buf with layOutLastLine ?
	public function getStaticPosition(element:ElementRenderer):PointData
	{
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
	
	public function format(layOutLastLine:Bool = false):Void
	{	
		_layOutLastLine = layOutLastLine;
		doFormat(_elementsInFormattingContext);
	}
	
	private function doFormat(elementsInFormattingContext:Array<ElementRenderer>):Void
	{
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		_formattingContextData = initFormattingContextData();
		
		
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
			if (element.domElement.style.establishesNewFormattingContext() == true)
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
	
	//TODO : add a method getChildrenWidth for shrink-to-fit ?
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
			var elementRenderers:Array<ElementRenderer> = getParentElementRenderers(elementRenderer);
			for (i in 0...elementRenderers.length)
			{
				//TODO : float can still account in max height if it overflows
				if (elementRenderers[i].isFloat() == false)
				{
					height += Math.round(elementRenderers[i].bounds.height);
				}
				
			}
		}
	
		
		return height;
	}
	

	private function getParentElementRenderers(elementRenderer:FlowBoxRenderer):Array<ElementRenderer>
	{	
		return doGetParentElementRenderers(elementRenderer, _elementsInFormattingContext);
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	private function doGetParentElementRenderers(elementRenderer:FlowBoxRenderer, targetElementRenderers:Array<ElementRenderer>):Array<ElementRenderer>
	{
		var elementRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...targetElementRenderers.length)
		{
			if (targetElementRenderers[i].parent == elementRenderer)
			{
				elementRenderers.push(targetElementRenderers[i]);
			}
		}
		
		if (elementRenderers.length == 0)
		{
			targetElementRenderers.push(elementRenderer);
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
		_floatsManager.clearFloat(clear, formattingContextData);
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
	
	private function getFormattingContextData():FormattingContextData
	{
		return _formattingContextData;
	}
}