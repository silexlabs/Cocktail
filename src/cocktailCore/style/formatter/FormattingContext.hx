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
	public var floatsManager(getFloatsManager, never):FloatsManager;
	
	/**
	 * Contains the data necessary to place the DOMElements in flow, 
	 * such as the coordinates where to insert the next DOMElement
	 */
	private var _flowData:FlowData;
	public var flowData(getFlowData, never):FlowData;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 * @param	domElement the containing DOMElement which starts the formatting context
	 * @param	previousFormatingContext the previous formatting context, used to retrieve
	 * floated DOMElement which still applies to the new formatting context
	 */
	public function new(domElement:DOMElement, previousFormatingContext:FormattingContext = null) 
	{
		//store a reference to the DOMElement starting the formatting context
		_containingDOMElement = domElement;
		_containingDOMElementWidth = _containingDOMElement.style.computedStyle.width;
		
		//will store the data of the floated DOMElement of this
		//formatting context
		_floatsManager = new FloatsManager();
		
		//retrieve the floats inserted in a previous formatting
		//context that still apply to this formatting context
		if (previousFormatingContext != null)
		{	
			_floatsManager.addFloats(previousFormatingContext);
		}
		
		//init the flow data to place the first inserted
		//DOMElement in the right position
		_flowData = initFlowData(_containingDOMElement);
		
	}
	
	/**
	 * Init the flow data using the containing DOMElement's
	 * properties
	 */
	private function initFlowData(domElement:DOMElement):FlowData
	{
		var flowY:Int = domElement.style.computedStyle.paddingTop;
		
		var flowX:Int;
		
		if (domElement.style.computedStyle.paddingLeft > _floatsManager.getLeftFloatOffset(flowY))
		{
			flowX = domElement.style.computedStyle.paddingLeft;
		}
		else
		{
			flowX = _floatsManager.getLeftFloatOffset(flowY);
		}
		
		return {
			x : flowX,
			y : flowY,
			xOffset : domElement.style.computedStyle.paddingLeft,
			yOffset : domElement.style.computedStyle.paddingTop,
			totalHeight : 0,
			maxWidth:0
		};
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	/////////////////////////////////
	
	/**
	 * Insert a DOMElement in the formatting context's
	 * flow
	 */
	public function insert(domElement:DOMElement):Void
	{
		doInsert(domElement);
	}
	
	/**
	 * Insert a space character, wrapped in a DOMElement
	 * in the formatting context
	 */
	public function insertSpace(domElement:DOMElement):Void
	{
		doInsert(domElement);
	}
	
	/**
	 * Insert a tab character, wrapped in a DOMElement
	 * in the formatting context
	 */
	public function insertTab(domElement:DOMElement):Void
	{
		doInsert(domElement);
	}
	
	/**
	 * Start a new line by inserting a new line
	 * control character
	 */
	public function insertLineFeed():Void
	{
		startNewLine(0);
	}
	
	/**
	 * Insert a floated DOMElement in the formatting
	 * context's flow
	 */
	public function insertFloat(domElement:DOMElement):Void
	{
		//get the float data (x,y, width and height) from the 
		//floats manager
		var floatData:FloatData = _floatsManager.computeFloatData(domElement, _flowData, _containingDOMElementWidth);
		//actually place the floated DOMElement
		placeFloat(domElement, floatData);
	}
	
	/**
	 * Clear all the current left, or right or both floats.
	 * When floats are cleared, the flow y attribute is placed
	 * at the bottom of the last cleared float
	 */
	public function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		//abstract
	}
	
	/**
	 * Retrieve the floats from another formatting context
	 * which applies to this formatting context
	 */
	public function retrieveFloats(formattingContext:FormattingContext):Void
	{
		_floatsManager.retrieveFloats(formattingContext);
	}
	
	/**
	 * Called by a new formatting context
	 * to perform clean up before this
	 * formatting context gets destroyed
	 */
	public function destroy():Void
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
	private function doInsert(domElement:DOMElement):Void
	{
		//actually place the DOMElement by computing
		//its place in the flow than updating its
		//position attributes
		place(domElement);
		
		//remove all the floats that the insertion
		//of the DOMElement made obsolote
		removeFloats();
	}
	
	/**
	 * Return the width remaining in the current line
	 * of the formatting context
	 */
	private function getRemainingLineWidth():Int
	{
		return _containingDOMElementWidth - _flowData.x + _flowData.xOffset - _floatsManager.getRightFloatOffset(_flowData.y, _containingDOMElementWidth);
	}
	
	/**
	 * Place a DOMElement is the flow according to 
	 * a block or inline formatting scheme
	 */
	private function place(domElement:DOMElement):Void
	{
		//abstract
	}
	
	/**
	 * Place a floated DOMElement in the containing
	 * DOMElement. The position of the floated DOMElement
	 * change based on tht type of formatting context
	 * (block or inline)
	 */
	private function placeFloat(domElement:DOMElement, floatData:FloatData):Void
	{
		domElement.style.setNativeX(domElement, floatData.x + domElement.style.computedStyle.marginLeft);
		domElement.style.setNativeY(domElement, floatData.y + domElement.style.computedStyle.marginTop);
	}
	
	/**
	 * Removed the floats which don't influence the 
	 * flow anymore. A float don't influence the flow
	 * anymore once the flow place DOMElement's below it
	 */
	private function removeFloats():Void
	{
		_floatsManager.removeFloats(_flowData.y);
	}
	
	
	/////////////////////////////////
	// GETTERS/SETTERS
	/////////////////////////////////
	
	private function getFloatsManager():FloatsManager
	{
		return _floatsManager;
	}
	
	private function getFlowData():FlowData
	{
		return _flowData;
	}
	
	private function getContainingDOMElement():DOMElement
	{
		return _containingDOMElement;
	}
	
}