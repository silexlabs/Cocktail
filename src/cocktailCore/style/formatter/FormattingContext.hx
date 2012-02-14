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
 * Those classes also are in charge of placing floated DOMElement
 * in the document and keeping a reference to each of the floated
 * DOMElement's position.
 * 
 * A formatting happens in 2 phases : 
 * - first all the elements (DOMElement, text, control charachter...)
 * are inserted into the formatting context
 * - when all the elements participating in the formatting context
 * have been inserted, a call to the 'format' actually format, storing
 * for each element its x/y position relative to the containing DOMElement
 * which started the current formatting context. Those data are stored
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
	 * Holds the box element of the containing DOMElement of this formatting
	 * context and each of its children, forming a tree structure containing
	 * all the elements in this formatting context
	 */
	private var _rootFormattableElement:FormattableElementValue;
	
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
		
		//init the flow data to place the first inserted
		//DOMElement in the right position
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		
		_formattingBoxesData = new Array<BoxData>();
		
		//init the tree of formattable element with the containing DOMElement
		_rootFormattableElement = FormattableElementValue.container(BoxElementValue.containerDOMElement(_containingDOMElement, _containingDOMElement.parent), []);
		
	}
	
	/**
	 * Init the flow data using the containing DOMElement's
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
	// PUBLIC FORMATTABLE ELEMENT TREE METHODS
	// methods used to build and traverse the formattable elements tree
	/////////////////////////////////
	
	/**
	 * insert a formattable element in the formatting context. Might be
	 * an embedded DOMElement, a Container DOMElement, a floated DOMElement...
	 * 
	 * TODO : seems a bit clumsy to traverse the whole formattable elements
	 * tree to retrieve the parent each time.
	 */
	public function insertElement(insertedElement:BoxElementValue):Void
	{
		//retrive the parent of the inserted element in the tree of 
		//formattable element to push it in its children array
		var searchedParent:DOMElement = getElementParent(insertedElement);
		var parentFormattableElement:FormattableElementValue = getParentFormattableElement(searchedParent);

		switch (parentFormattableElement)
		{
			case FormattableElementValue.container(element, children):
				children.push(getFormattableElementFromBoxElement(insertedElement));
			
			case FormattableElementValue.child(element):
		}
	}
	
	/////////////////////////////////
	// PRIVATE FORMATTABLE ELEMENT TREE METHODS
	/////////////////////////////////
	
	/**
	 * Call a recursive method retrieving the parent formattable element
	 * of a box element by traversing the formattable element tree, using
	 * the box element's parent DOMElement
	 */
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
		
		//start recursion
		doGetParentFormattableElement(searchedParent, rootChildren, parentFormattableElement);
		
		return parentFormattableElement;
	}
	
	/**
	 * recursive method actually retrieving the parent formattable element
	 * 
	 * TODO : duplicated code
	 */
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
	
	/////////////////////////////////
	// PUBLIC FORMATTING METOHDS
	// format the formattable elements tree and access
	// to the created boxes data
	/////////////////////////////////
	
	/**
	 * Called by the containing DOMElement once each of its children
	 * has been inserted ibn the formatting context to start the formatting.
	 */
	public function format():Void
	{
		var rootChildren:Array<FormattableElementValue> = new Array<FormattableElementValue>();
		
		//retrive the children of the containing block, which is itself
		//always a container
		switch (_rootFormattableElement)
		{
			case FormattableElementValue.container(element, children):
				rootChildren = children;
				
			case FormattableElementValue.child(element):
		}
		
		//call recursive method
		doFormat(rootChildren);
	}
	
	/**
	 * For a given parent DOMElement, retrive all the 
	 * boxes that were created by the formatting context
	 * to format it. Must be called after a call to the 
	 * 'format' method, else the returned array is always
	 * empty
	 */
	public function getBoxesData(parentDOMElement:DOMElement):Array<BoxData>
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
	 * Find a better way to exclude relative DOMElements ?
	 */ 
	public function getRenderedBoxesData(parentDOMElement:DOMElement):Array<BoxData>
	{
		return doGetBoxesData(parentDOMElement, _formattingBoxesData);
	}
	
	/////////////////////////////////
	// PRIVATE FORMATTING METOHDS
	/////////////////////////////////
	
	
	/**
	 * Recursive method traversing all the  tree of elements in the formatting method
	 * and inserting each of those
	 */
	private function doFormat(formattableElements:Array<FormattableElementValue>):Void
	{
		for (i in 0...formattableElements.length)
		{
			switch (formattableElements[i])
			{
				case container(element, children):
					doInsertElement(element, isNextElementALineFeed(formattableElements, i));
					//call the method recursively if the element is a container
					doFormat(children);
					
				case child(element):
					doInsertElement(element, isNextElementALineFeed(formattableElements, i));
			}
		}		
	}
	
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
	 * 
	 * TODO : rename insertHorizontalOffset ?
	 */
	private function insertOffset(element:BoxElementValue):Void
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
					
				case BoxElementValue.float(domElement, parentDOMElement):
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
					
				case BoxElementValue.float(domElement, parentDOMElement):
					elementParent = parentDOMElement;
					
				case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
					elementParent = parentDOMElement;
			}
			
		return 	elementParent;
	}
	
	/**
	 * Wrap a box element into either a container or a child formattable element
	 * based on the type of box element
	 */
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
	
	/**
	 * Determine wheter the next element in the formattable elements array is a linefeed
	 * 
	 * TODO : if the current element is the last of the array, must check the next
	 * in the tree instead of returning false
	 */
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