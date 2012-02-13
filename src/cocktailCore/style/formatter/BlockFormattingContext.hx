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
import haxe.Log;

/**
 * This formatting context layout DOMElement below each other
 * following the DOM tree order.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockFormattingContext extends FormattingContext
{
	private var _embeddedAndContainerY:Int;

	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_embeddedAndContainerY = 0;
		
	}
	
	override private function doFormat(formattableElement:FormattableElementValue):Void
	{
		switch (formattableElement)
		{
			
			
			case FormattableElementValue.container(element, formattableElements):
				
				
				
				for (i in 0...formattableElements.length)
				{
					switch (formattableElements[i])
					{
						case container(element, children):
							doFormat(formattableElements[i]);
							doInsertElement(element, isNextElementALineFeed(formattableElements, i));
							
							
						case child(element):
							doInsertElement(element, isNextElementALineFeed(formattableElements, i));
					}
				}
				
				
				
			case FormattableElementValue.child(element):
				
		}
		
		
	}
	

	override private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{
		
		var childTemporaryPositionData:ChildTemporaryPositionData = {
				element:element,
				x:_formattingContextData.x, 
				y:_embeddedAndContainerY,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			_embeddedAndContainerY += getElementHeight(element);
			
			getBoxesData(getElementParent(element))[0].children.push(childTemporaryPositionData);
			
	}
	

	override private function insertContainingBlockDOMElement(element:BoxElementValue):Void
	{
		
		
		var childTemporaryPositionData:ChildTemporaryPositionData = {
				element:element,
				x:_formattingContextData.x, 
				y:_embeddedAndContainerY,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			//TODO : gérer le cas de height = auto ?
			_embeddedAndContainerY += getElementHeight(element);
			_formattingContextData.y += getElementHeight(element);
			
			getBoxesData(getElementParent(element))[0].children.push(childTemporaryPositionData);
	}
	

	override private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		var childTemporaryPositionData:ChildTemporaryPositionData = {
				element:element,
				x:_formattingContextData.x, 
				y:_formattingContextData.y,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			Log.trace(getElementHeight(element));
			
			_formattingContextData.y += getElementHeight(element) ;
			_embeddedAndContainerY = _formattingContextData.y;
			
			getBoxesData(getElementParent(element))[0].children.push(childTemporaryPositionData);
	}

	
	
	
	

	
}