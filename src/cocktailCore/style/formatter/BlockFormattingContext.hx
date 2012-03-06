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
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import haxe.Log;

/**
 * This formatting context layout DOMElement below each other
 * generally following the formattable tree order.
 * 
 * There might be exception, for instance if a container DOMElement
 * with a fixed has overflowing children, its siblings will use
 * the height of the container to be positioned below, not the
 * added height of its children.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockFormattingContext extends FormattingContext
{
	
	private var _currentAddedSiblingsHeight:Int;
	
	private var _lastInsertedElement:BoxElementValue;
	
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		_currentAddedSiblingsHeight = 0;
		super(domElement);
	}
	
	/**
	 * Called by the containing DOMElement once each of its children
	 * has been inserted in the formatting context to start the formatting.
	 * 
	 * TODO : implement margin collapsing
	 */
	override public function format():Void
	{
		//init/reset the boxes data of the formatting context
		_formattingBoxesData = new Array<BoxData>();
		
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		
		_lastInsertedElement = BoxElementValue.containingBlockDOMElement(_containingDOMElement, _containingDOMElement.parent);
		
		//format all the box element in order
		for (i in 0..._elementsInFormattingContext.length)
		{
	
				
			if (isSiblingOfLastInsertedElement(_elementsInFormattingContext[i]))
			{
				
			}
			else if (isParentOfLastInsertedElement(_elementsInFormattingContext[i]))
			{
				_formattingContextData.y -= _currentAddedSiblingsHeight;
				_currentAddedSiblingsHeight = 0;
					
			}
			else
			{
				_currentAddedSiblingsHeight = 0;	
			}
					
			_lastInsertedElement = _elementsInFormattingContext[i];
			doInsertElement(_elementsInFormattingContext[i], isNextElementALineFeed(_elementsInFormattingContext, i));
		}
		
	}
	
	
	
	
	private function isParentOfLastInsertedElement(element:BoxElementValue):Bool
	{
		var parentOfLastInsertedDOMElement:DOMElement = getElementParent(_lastInsertedElement);
		
		var ret:Bool;
		
		switch (element)
		{
			case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				ret = domElement == parentOfLastInsertedDOMElement;
				
			default:
				ret = false;
			
		}
		
		return ret;
	}
	
	private function isSiblingOfLastInsertedElement(element:BoxElementValue):Bool
	{
		return getElementParent(element) == getElementParent(_lastInsertedElement);
	}

	override private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{
		var boxElementData:BoxElementData = {
				element:element,
				x:_formattingContextData.x, 
				y:_formattingContextData.y ,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			var x:Float = _formattingContextData.x;
			var y:Float = _formattingContextData.y;
			var width:Float = getElementWidth(element);

			var height:Float = getElementHeight(element);
			getElementRenderer(element).bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
			
			
		if (getElementWidth(element) > _formattingContextData.maxWidth)
			{
				_formattingContextData.maxWidth = getElementWidth(element);
			}	
			
			
		_formattingContextData.y += getElementHeight(element);
		_currentAddedSiblingsHeight += getElementHeight(element);
		
		
			getParentBoxesData(getElementParent(element))[0].children.push(boxElementData);
			
	}
	

	override private function insertContainingBlockDOMElement(element:BoxElementValue):Void
	{
		
		var boxElementData:BoxElementData = {
				element:element,
				x:_formattingContextData.x, 
				y:_formattingContextData.y ,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			var x:Float = _formattingContextData.x;
			var y:Float = _formattingContextData.y;
			var width:Float = getElementWidth(element);
			var height:Float = getElementHeight(element);
			getElementRenderer(element).bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
			
if (getElementWidth(element) > _formattingContextData.maxWidth)
			{
				_formattingContextData.maxWidth = getElementWidth(element);
			}	
		
			_formattingContextData.y += getElementHeight(element);
			
			_currentAddedSiblingsHeight += getElementHeight(element);
			
			getParentBoxesData(getElementParent(element))[0].children.push(boxElementData);
	}
	

	override private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		
		var boxElementData:BoxElementData = {
				element:element,
				x:0, 
				y:_formattingContextData.y,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			var x:Float = 0.0;
			var y:Float = _formattingContextData.y;
			var width:Float = getElementWidth(element);
			var height:Float = getElementHeight(element);
			getElementRenderer(element).bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
			
if (getElementWidth(element) > _formattingContextData.maxWidth)
			{
				_formattingContextData.maxWidth = getElementWidth(element);
			}	
			
			_formattingContextData.y += getElementHeight(element);
			_currentAddedSiblingsHeight += getElementHeight(element);
			
			
			
			getParentBoxesData(getElementParent(element))[0].children.push(boxElementData);
	}

	
	
	
	
	
	

	
}