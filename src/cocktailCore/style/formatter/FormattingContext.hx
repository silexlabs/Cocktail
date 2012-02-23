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
	private var _containingDOMElement:DOMElement;
	public var containingDOMElement(getContainingDOMElement, never):DOMElement;
	
	/**
	 * The width of the DOMElement starting the formatting context,
	 * representing the maximum width of a line.
	 */
	private var _containingDOMElementWidth:Int;
	
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
	 * An array of the box created by the formatted elements of this formatting context.
	 * There are as many boxes as they are container DOMElements in this formatting context.
	 * For each box, its position and dimensions are stored (relative to the containing DOMElement)
	 * and all of the children of the box.
	 */
	private var _formattingBoxesData:Array<BoxData>;
	
	/**
	 * Holds a reference to each of the box elements formatted by this
	 * formatting context. The corresponding box data are generated
	 * when the 'format' method is called
	 */
	private var _elementsInFormattingContext:Array<BoxElementValue>;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 * @param	domElement the containing DOMElement which starts the formatting context
	 * (the containing block)
	 */
	public function new(domElement:DOMElement) 
	{
		//store a reference to the DOMElement starting the formatting context
		_containingDOMElement = domElement;
		_containingDOMElementWidth = _containingDOMElement.style.computedStyle.width;
		
		//will store the data of the floated DOMElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		_formattingBoxesData = new Array<BoxData>();
		_elementsInFormattingContext = new Array<BoxElementValue>();
	}
	
	/**
	 * Init/reset the flow data using the containing DOMElement's
	 * properties
	 */
	private function initFormattingContextData(domElement:DOMElement):FormattingContextData
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
	
	/**
	 * Store the inserted box element in the right formatting order
	 * @param	insertedElement
	 */
	public function insertElement(insertedElement:BoxElementValue):Void
	{
		_elementsInFormattingContext.push(insertedElement);
	}
	
	/**
	 * Called by the containing DOMElement once each of its children
	 * has been inserted in the formatting context to start the formatting.
	 */
	public function format():Void
	{
		//init/reset the boxes data of the formatting context
		_formattingBoxesData = new Array<BoxData>();
		
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		
		//format all the box element in order
		for (i in 0..._elementsInFormattingContext.length)
		{
			doInsertElement(_elementsInFormattingContext[i], isNextElementALineFeed(_elementsInFormattingContext, i));
		}
	}
	
	/**
	 * return the added height of the children of a DOMElement.
	 * Must be called after a call to the 'format' method, else
	 * always return 0
	 */
	public function getChildrenHeight(parentDOMElement:DOMElement):Int
	{
		var height:Int = 0;
		
		//add all the DOMElement boxesData's height
		var boxesData:Array<BoxData> = getParentBoxesData(parentDOMElement);
		for (i in 0...boxesData.length)
		{
			height += Math.round(boxesData[i].bounds.height);
		}
		
		return height;
	}
	
	public function getBoxesData():Array<BoxData>
	{
		for (i in 0..._formattingBoxesData.length)
		{
			getBounds(_formattingBoxesData[i]);
		}
		
		return _formattingBoxesData;
	}
	
	/**
	 * For a given parent DOMElement, retrieve all the 
	 * boxes that were created by the formatting context
	 * to format it. Must be called after a call to the 
	 * 'format' method, else the returned array is always
	 * empty
	 */
	private function getParentBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{	
		return doGetBoxesData(parentDOMElement, _formattingBoxesData);
	}
	
	/**
	 * same as getBoxesData but for each box, suppress their relative positioned
	 * children as they are only use for formatting but they will be rendered as 
	 * positionied DOMElement. Not returning them here prevent them from being
	 * rendered twice.
	 * 
	 * TODO: return all but relative positioned DOMElements.
	 * Find a better way to exclude relative DOMElements ? add a 'stub' box element, only used
	 * for formatting but not stored in  formatting boxes data ?
	 */ 
	public function getRenderedBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{
		return doGetBoxesData(parentDOMElement, _formattingBoxesData);
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	/**
	 * do insert an element using different methods based on its type
	 * @param element
	 * @param nexElementIsLineFeed wheter the next element in the tree of formattable elements
	 * is a line feed, which may influence the white space processing of an inline formatting context
	 */
	private function doInsertElement(element:BoxElementValue, nexElementIsLineFeed:Bool):Void
	{
		switch (element)
		{
			case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				insertEmbeddedDOMElement(element);
				
			case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				insertContainerDOMElement(element);
				
			case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
				insertContainingBlockDOMElement(element);
				
			case BoxElementValue.text(domElement, parentDOMElement):
				insertText(element);
				
			case BoxElementValue.offset(value, parentDOMElement):
				insertHorizontalOffset(element);
				
			case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				insertSpace(element, nexElementIsLineFeed);
				
			case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
				insertTab(element, nexElementIsLineFeed);
				
			case BoxElementValue.floatDOMElement(domElement, parentDOMElement):
				insertFloat(element);
				
			case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
				insertLineFeed(element);
		}
	}
	
	/**
	 * Actually retrieve the boxes data belonging to the 
	 * provided parentDOMElement
	 * @param	parentDOMElement all the return box data are boxes generated for this DOMElement
	 * @param	targetBoxesData the array of box data among which the parentDOMElement's box data are 
	 * sought
	 */
	private function doGetBoxesData(parentDOMElement:DOMElement, targetBoxesData:Array<BoxData>):Array<BoxData>
	{
		var boxesData:Array<BoxData> = new Array<BoxData>();
		
		//store each box data with the right parentDOMeElement
		for (i in 0...targetBoxesData.length)
		{
			if (targetBoxesData[i].parentDOMElement == parentDOMElement)
			{
				//set the bounds of the box before returning it
				targetBoxesData[i].bounds = getBounds(targetBoxesData[i]);
				boxesData.push(targetBoxesData[i]);
			}
		}
		
		//if their are none, create the first box data for the given
		//parent, all the subsequent children will be added to it
		if (boxesData.length == 0)
		{
			var boxData:BoxData = {
				parentDOMElement:parentDOMElement,
				children:new Array<BoxElementData>(),
				bounds: { x:0.0, y:0.0, width:0.0, height:0.0 },
				textDecorations:new Array<TextDecorationData>()
			}
			
			targetBoxesData.push(boxData);
			boxesData.push(boxData);
		}
		
		return boxesData;
	}
	
	/**
	 * Get the bounds formed by all the children
	 * of a box data. The bounds are relative to 
	 * the containing block which started this
	 * formatting context
	 * 
	 * TODO : for bodyDOMElement, should return the viewport
	 * dimensions, add a construct for rootContainingBlock ?
	 */
	private function getBounds(boxData:BoxData):RectangleData
	{
		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		
		for (i in 0...boxData.children.length)
		{
			var doPosition:Bool;
			
			doPosition = doPositionElement(boxData.children[i].element);
			
			if (doPosition == true)
			{
				if (boxData.children[i].x < left)
				{
					left = boxData.children[i].x;
				}
				if (boxData.children[i].y < top)
				{
					//TODO : probably won't be robust enough + messy but offset should only be used for left and right
					switch (boxData.children[i].element)
					{
						case BoxElementValue.offset(offsetWidth, parentDOMElement):
							
						case BoxElementValue.text(domElement, parentDOMElement):
							top = boxData.children[i].y - domElement.style.fontMetrics.ascent - domElement.style.fontMetrics.descent;
							
						default:
							top = boxData.children[i].y;
					}
				
				}
				if (boxData.children[i].x + boxData.children[i].width > right)
				{
					right = boxData.children[i].x + boxData.children[i].width;
				}
				if (boxData.children[i].y + boxData.children[i].height > bottom)
				{
					switch (boxData.children[i].element)
					{
						case BoxElementValue.offset(offsetWidth, parentDOMElement):
					
						case BoxElementValue.text(domElement, parentDOMElement):
							bottom = boxData.children[i].y + boxData.children[i].height -  domElement.style.fontMetrics.ascent - domElement.style.fontMetrics.descent;
							
						default:	
							bottom = boxData.children[i].y + boxData.children[i].height;
					}
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
	
	private function doPositionElement(element:BoxElementValue):Bool
	{
		return true;
	}
	
	/**
	 * Insert an embedded DOMElement. overriden by sub-classes
	 */
	private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{ 
		//abstract
	}
	
	/**
	 * Insert a containing block DOMElement (a ContainerDOMElement which establishes a 
	 * formatting context). overriden by sub-classes
	 */
	private function insertContainingBlockDOMElement(element:BoxElementValue):Void
	{
		//abstract
	}
	
	/**
	 * Insert a container DOMElement (a ContainerDOMElement which doesn't
	 * establishes a formatting context). overriden by sub-classes
	 */
	private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		//abstract
	}

	/**
	 * Insert a text. overriden by sub-classes
	 */
	private function insertText(element:BoxElementValue):Void
	{
		//abstract
	}
	
	/**
	 * Insert a space. overriden by sub-classes
	 */
	private function insertSpace(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{
		//abstract	
	}
	
	/**
	 * Insert an horizontal offset. overriden by sub-classes
	 */
	private function insertHorizontalOffset(element:BoxElementValue):Void
	{
		//abstract
	}
	
	/**
	 * Insert a tab. overriden by sub-classes
	 */
	private function insertTab(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{
		//abstract
	}
	
	/**
	 * Insert a linefeed. overriden by sub-classes
	 */
	private function insertLineFeed(element:BoxElementValue):Void
	{
		//abstract
	}
	
	/**
	 * Insert a floated DOMElement. overriden by sub-classes
	 * 
	 * TODO : re-implement floats
	 */
	private function insertFloat(element:BoxElementValue):Void
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
	 * return the width of an element
	 */
	private function getElementWidth(element:BoxElementValue):Int
	{
		var elementWidth:Int;
		
		switch (element)
			{
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;
				
				case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;	
					
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;
					
				case BoxElementValue.text(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;
					
				case BoxElementValue.offset(value, parentDOMElement):
					elementWidth = value;
					
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
					elementWidth = spaceWidth;
					
				case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
					elementWidth = tabWidth;
					
				case BoxElementValue.floatDOMElement(domElement, parentDOMElement):
					elementWidth = 0;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementWidth = 0;
			}
			
		return 	elementWidth;
	}
	
	/**
	 * return the height of an element
	 */
	private function getElementHeight(element:BoxElementValue):Int
	{
		var elementHeight:Int;
		
		switch (element)
			{
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
					elementHeight = domElement.offsetHeight;
				
				case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
					elementHeight = domElement.offsetHeight;	
					
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
					elementHeight = domElement.offsetHeight;
					
				case BoxElementValue.text(domElement, parentDOMElement):
					elementHeight = domElement.offsetHeight;
					
				case BoxElementValue.offset(value, parentDOMElement):
					elementHeight = 0;
					
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
					elementHeight = 0;
					
				case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
					elementHeight = 0;
					
				case BoxElementValue.floatDOMElement(domElement, parentDOMElement):
					elementHeight = 0;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementHeight = 0;
			}
			
		return 	elementHeight;
	}
	
	/**
	 * return the parent DOMElement of a box element
	 */
	private function getElementParent(element:BoxElementValue):DOMElement
	{
		var elementParent:DOMElement;
		
		switch (element)
			{
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
					elementParent = parentDOMElement;	
					
				case BoxElementValue.text(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.offset(value, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.floatDOMElement(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementParent = parentDOMElement;
			}
			
		return 	elementParent;
	}
	
	/**
	 * return the white space value of an element, or null if it 
	 * doesn't have one
	 */
	private function getElementWhiteSpace(element:BoxElementValue):WhiteSpaceStyleValue
	{
		var elementWhiteSpace:WhiteSpaceStyleValue;
		
		switch (element)
		{
			case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			default:
				elementWhiteSpace = null;
		}
		
		return elementWhiteSpace;
	}
	
	/**
	 * Determine wheter the next element in the formattable elements array is a linefeed
	 */
	private function isNextElementALineFeed(elementsInFormattingContext:Array<BoxElementValue>, currentIndex:Int):Bool
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
			switch (elementsInFormattingContext[currentIndex + 1])
			{
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					isNextElementALineFeed = true;
					
				default:
					isNextElementALineFeed = false;
			}
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
	
	private function getContainingDOMElement():DOMElement
	{
		return _containingDOMElement;
	}
	
}