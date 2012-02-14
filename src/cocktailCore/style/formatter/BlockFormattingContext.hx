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
	private var _embeddedAndContainerY:Int;

	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_embeddedAndContainerY = 0;
		
	}
	

	override private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{
		
		var boxElementData:BoxElementData = {
				element:element,
				x:_formattingContextData.x, 
				y:_embeddedAndContainerY,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			_embeddedAndContainerY += getElementHeight(element);
			
			getBoxesData(getElementParent(element))[0].children.push(boxElementData);
			
	}
	

	override private function insertContainingBlockDOMElement(element:BoxElementValue):Void
	{
		
		
		var boxElementData:BoxElementData = {
				element:element,
				x:_formattingContextData.x, 
				y:_embeddedAndContainerY,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			//TODO : gérer le cas de height = auto ?
			_embeddedAndContainerY += getElementHeight(element);
			_formattingContextData.y += getElementHeight(element);
			
			getBoxesData(getElementParent(element))[0].children.push(boxElementData);
	}
	

	override private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		var boxElementData:BoxElementData = {
				element:element,
				x:_formattingContextData.x, 
				y:_formattingContextData.y,
				width:getElementWidth(element),
				height:getElementHeight(element)
			}
			
			Log.trace(getElementHeight(element));
			
			_formattingContextData.y += getElementHeight(element) ;
			_embeddedAndContainerY = _formattingContextData.y;
			
			getBoxesData(getElementParent(element))[0].children.push(boxElementData);
	}

	
	
	
	

	
}