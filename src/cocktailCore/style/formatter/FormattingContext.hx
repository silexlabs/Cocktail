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
 * classes are in charge of placing in-flow DOMElements in the document.
 * 
 * They can be placed following a block or inline formatting context.
 * In a block formatting, the DOMElements are placed on top of each
 * other, in an inline, they are placed next to each other.
 * 
 * Those classes also are in charge of placing floated DOMElement
 * in the document and keeping a reference to each of the floated
 * DOMElement's position.
 * 
 * @author Yannick DOMINGUEZ
 */
class FormattingContext 
{
	/**
	 * A reference to the DOMElement which started the
	 * formatting context.
	 */ 
	private var _containingDOMElement:DOMElement;
	public var containingDOMElement(getContainingDOMElement, never):DOMElement;
	
	/**
	 * The width of the DOMElement starting the formatting context,
	 * represeting the maximum width of a line
	 */
	private var _containingDOMElementWidth:Int;
	
	/**
	 * An instance of the class managing the floated DOMElements.
	 */
	private var _floatsManager:FloatsManager;
	
	/**
	 * Contains the data necessary to place the DOMElements in flow, 
	 * such as the coordinates where to insert the next DOMElement
	 */
	private var _formattingContextData:FormattingContextData;
	public var formattingContextData(getFormattingContextData, never):FormattingContextData;

	private var _formattingBoxesData:Array<BoxData>;
	
	private var _currentBoxesData:Array<BoxData>;
	
	private var _rootFormattableElement:FormattableElementValue;
	

	
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 * @param	domElement the containing DOMElement which starts the formatting context
	 */
	public function new(domElement:DOMElement) 
	{
		//store a reference to the DOMElement starting the formatting context
		_containingDOMElement = domElement;
		_containingDOMElementWidth = _containingDOMElement.style.computedStyle.width;
		
		//will store the data of the floated DOMElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		
		//init the flow data to place the first inserted
		//DOMElement in the right position
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		
		_formattingBoxesData = new Array<BoxData>();
		_currentBoxesData = new Array<BoxData>();
		
		_rootFormattableElement = FormattableElementValue.container(BoxElementValue.containerDOMElement(_containingDOMElement, _containingDOMElement.parent), []);
		
	}
	
	/**
	 * Init the flow data using the containing DOMElement's
	 * properties
	 */
	private function initFormattingContextData(domElement:DOMElement):FormattingContextData
	{
		var flowY:Int = 0;
		
		var flowX:Int = _floatsManager.getLeftFloatOffset(flowY);
		
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
	
	public function format():Void
	{
		var rootChildren:Array<FormattableElementValue> = new Array<FormattableElementValue>();
		
		doFormat(_rootFormattableElement);
		
	}
	
	private function doFormat(formattableElement:FormattableElementValue):Void
	{
		
		switch (formattableElement)
		{
			case FormattableElementValue.container(element, formattableElements):
				for (i in 0...formattableElements.length)
				{
					switch (formattableElements[i])
					{
						case container(element, children):
							doInsertElement(element, isNextElementALineFeed(formattableElements, i));
							doFormat(formattableElements[i]);
							
						case child(element):
							doInsertElement(element, isNextElementALineFeed(formattableElements, i));
					}
				}
				
			case FormattableElementValue.child(element):
				
		}
		
	
	}


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
					elementWidth = 0;
					
				case BoxElementValue.text(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;
					
				case BoxElementValue.offset(value, parentDOMElement):
					elementWidth = value;
					
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
					elementWidth = spaceWidth;
					
				case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
					elementWidth = tabWidth;
					
				case BoxElementValue.float(domElement, parentDOMElement):
					elementWidth = 0;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementWidth = 0;
			}
			
		return 	elementWidth;
	}
	
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
					
				case BoxElementValue.float(domElement, parentDOMElement):
					elementHeight = 0;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementHeight = 0;
			}
			
		return 	elementHeight;
	}
	
	private function isNextElementALineFeed(formattableElements:Array<FormattableElementValue>, currentIndex:Int):Bool
	{
		var isNextElementALineFeed:Bool;
		
		//here the current element is the last in the array
		if (currentIndex + 1 >= formattableElements.length)
		{
			isNextElementALineFeed = false;
		}
		//else check if the next element is indeed a line feed
		else
		{
			switch (formattableElements[currentIndex + 1])
			{
				case container(element, children):
					isNextElementALineFeed = false;
					
				case child(element):
					switch (element)
					{
						case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
							isNextElementALineFeed = true;
							
						default:
							isNextElementALineFeed = false;
					}
			}
		}
		
		return isNextElementALineFeed;
	}
	
	private function doInsertElement(element:BoxElementValue, nexElementIsLineFeed:Bool):Void
	{
		switch (element)
		{
			case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				insertEmbeddedDOMElement(element);
				
			case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				insertNonLaidOutContainerDOMElement(element);
				
			case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
				insertContainerDOMElement(element);
				
			case BoxElementValue.text(domElement, parentDOMElement):
				insertText(element);
				
			case BoxElementValue.offset(value, parentDOMElement):
				insertOffset(element);
				
			case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				insertSpace(element, nexElementIsLineFeed);
				
			case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
				insertTab(element, nexElementIsLineFeed);
				
			case BoxElementValue.float(domElement, parentDOMElement):
				insertFloat(element);
				
			case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
				insertLineFeed(element);
		}
	}
	
	private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{
		
	}
	

	private function insertNonLaidOutContainerDOMElement(element:BoxElementValue):Void
	{

	}
	
	private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		
	}

	 private function insertText(element:BoxElementValue):Void
	{
		
	}
	
	private function insertSpace(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{

	}
	
	private function insertOffset(element:BoxElementValue):Void
	{
	
	}
	
	private function insertTab(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{

	}
	

	private function insertLineFeed(element:BoxElementValue):Void
	{
		
	}
	
	public function getBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{
		return doGetBoxesData(parentDOMElement, _formattingBoxesData);
	
	}
	
	//TODO: return all but relative positioned DOMElements
	public function getRenderedBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{
		return doGetBoxesData(parentDOMElement, _formattingBoxesData);
	}
	
	private function getCurrentBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{
		return doGetBoxesData(parentDOMElement, _currentBoxesData);
	}
	
	private function doGetBoxesData(parentDOMElement:DOMElement, targetBoxesData:Array<BoxData>):Array<BoxData>
	{
		var boxesData:Array<BoxData> = new Array<BoxData>();
		
		for (i in 0...targetBoxesData.length)
		{
			if (targetBoxesData[i].parentDOMElement == parentDOMElement)
			{
				boxesData.push(targetBoxesData[i]);
			}
		}
		
		if (boxesData.length == 0)
		{
			var boxData:BoxData = {
				parentDOMElement:parentDOMElement,
				children:new Array<ChildTemporaryPositionData>(),
				bounds: { x:0.0, y:0.0, width:0.0, height:0.0 },
				textDecorations:new Array<TextDecorationData>()
			}
			
			targetBoxesData.push(boxData);
			boxesData.push(boxData);
		}
		
		return boxesData;
	}
	

	public function insertElement(insertedElement:BoxElementValue):Void
	{
		var searchedParent:DOMElement = getElementParent(insertedElement);
		
		var parentFormattableElement:FormattableElementValue = getParentFormattableElement(searchedParent);

		switch (parentFormattableElement)
		{
			case FormattableElementValue.container(element, children):
				children.push(getFormattableElementFromBoxElement(insertedElement));
			
			case FormattableElementValue.child(element):
		}
	}
	
	private function getFormattableElementFromBoxElement(element:BoxElementValue):FormattableElementValue
	{
		var formattableElement:FormattableElementValue;
		
		switch (element)
		{
			case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				formattableElement = FormattableElementValue.container(element,[]);
				
			case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
				formattableElement = FormattableElementValue.container(element,[]);
				
			case BoxElementValue.text(domElement, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.offset(value, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.float(domElement, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
				
			case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
				formattableElement = FormattableElementValue.child(element);
		}
			
		return formattableElement;	
	}
	
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
					
				case BoxElementValue.float(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementParent = parentDOMElement;
			}
			
		return 	elementParent;
	}
	
	private function getParentFormattableElement(searchedParent:DOMElement): FormattableElementValue
	{
		var parentFormattableElement:FormattableElementValue = _rootFormattableElement;
		
		var rootChildren:Array<FormattableElementValue> = new Array<FormattableElementValue>();
		
		switch (_rootFormattableElement)
		{
			case FormattableElementValue.container(element, children):
				rootChildren = children;
				
			case FormattableElementValue.child(element):
				
		}
		
		doGetParentFormattableElement(searchedParent, rootChildren, parentFormattableElement);
		
		return parentFormattableElement;
	}
	
	private function doGetParentFormattableElement(searchedParent:DOMElement, formattableElements:Array<FormattableElementValue>, parentFormattableElement:FormattableElementValue):Void
	{
		for (i in 0...formattableElements.length)
		{
			switch (formattableElements[i])
			{
				case FormattableElementValue.container(element, children):
					switch (element)
					{
						case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
							if (searchedParent == domElement)
							{
								parentFormattableElement = formattableElements[i];
							}
							
						case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
							if (searchedParent == domElement)
							{
								parentFormattableElement = formattableElements[i];
							}
							
						default:	
					}
					
					doGetParentFormattableElement(searchedParent, children, parentFormattableElement);
					
				case FormattableElementValue.child(element):
					switch (element)
					{
						case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
							if (searchedParent == domElement)
							{
								parentFormattableElement = formattableElements[i];
							}
							
						case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
							if (searchedParent == domElement)
							{
								parentFormattableElement = formattableElements[i];
							}
							
						default:	
					}
			}
		}
		
	}
	

	/**
	 * Insert a floated DOMElement in the formatting
	 * context's flow
	 */
	private function insertFloat(element:BoxElementValue):Void
	{
		//get the float data (x,y, width and height) from the 
		//floats manager
		//var floatData:FloatData = _floatsManager.computeFloatData(domElement, _formattingContextData, parentDOMElement.style.computedStyle.width);
		//actually place the floated DOMElement
		//placeFloat(domElement, parentDOMElement, floatData);
	}
	
	/**
	 * Clear all the current left, or right or both floats.
	 * When floats are cleared, the flow y attribute is placed
	 * at the bottom of the last cleared float
	 */
	private function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		//abstract
	}
	
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	
	/**
	 * Start a new line in the formatting context. Lay out
	 * the current line before starting a new
	 * @param	domElementWidth the width of the DOMElement that triggered the new line,
	 * it is used to find the first y position in the flow with enough space to fit and
	 * thus start a new line
	 * @param	isLastLine wether the current line is the last line. If it is, the
	 * current line is laid out but no new line is actually started
	 */
	private function startNewLine(domElementWidth:Int, isLastLine:Bool = false):Void
	{
		//abstract
	}
	
	/**
	 * Actually insert a DOMElement in the
	 * formatting context
	 */
	private function doInsert(domElement:DOMElement, parentDOMElement:DOMElement, position:Bool):Void
	{
		//actually place the DOMElement by computing
		//its place in the flow than updating its
		//position attributes
		place(domElement, parentDOMElement, position);
		
		//remove all the floats that the insertion
		//of the DOMElement made obsolote
		
		//TODO : for inline formatting context, should happen when starting new line
		//instead of on insertion
		removeFloats();
	}
	
	/**
	 * Return the width remaining in the current line
	 * of the formatting context
	 */
	private function getRemainingLineWidth():Int
	{
		return _containingDOMElementWidth - _formattingContextData.x - _floatsManager.getRightFloatOffset(_formattingContextData.y, _containingDOMElementWidth);
	}
	
	/**
	 * Place a DOMElement is the flow according to 
	 * a block or inline formatting scheme
	 */
	private function place(domElement:DOMElement, parentDOMElement:DOMElement, position:Bool):Void
	{
		//abstract
	}
	
	/**
	 * Place a floated DOMElement in the containing
	 * DOMElement. The position of the floated DOMElement
	 * change based on tht type of formatting context
	 * (block or inline)
	 */
	private function placeFloat(domElement:DOMElement, parentDOMElement:DOMElement, floatData:FloatData):Void
	{
		//getBoxesData(parentDOMElement).push(getChildTemporaryPositionData(domElement, floatData.x, floatData.y, 0, true, render ));
		
	}
	
	/**
	 * Removed the floats which don't influence the 
	 * flow anymore. A float don't influence the flow
	 * anymore once the flow place DOMElement's below it
	 */
	private function removeFloats():Void
	{
		_floatsManager.removeFloats(_formattingContextData.y);
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