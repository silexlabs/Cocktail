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

	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		
		super(domElement, previousFormattingContext);
	}
	
	/**
	 * Place the DOMElement below the preceding DOMElement
	 */
	override private function place(domElement:DOMElement, parentDOMElement:DOMElement, position:Bool, render:Bool):Void
	{
		super.place(domElement, parentDOMElement, position, render);
		
		//add the left float offset if the element is embedded
		//(for instance an image), for non-embedded DOMElement
		//(like a container), the left float offset isn't used
		var leftFloatOffset:Int = 0;
		if (domElement.style.isEmbedded() == true)
		{
			_formattingContextData.y = _floatsManager.getFirstAvailableY(formattingContextData, domElement.offsetWidth, _containingDOMElementWidth);
			leftFloatOffset = _floatsManager.getLeftFloatOffset(_formattingContextData.y);
		}
			
		//apply the new x and y position to the DOMElement and formattingContextData
		_formattingContextData.x =  leftFloatOffset;
		
		
	
		var childTemporaryPositionData:ChildTemporaryPositionData = getChildTemporaryPositionData(domElement, _formattingContextData.x, _formattingContextData.y, 0, position, render);
		
		getChildrenTemporaryPositionData(parentDOMElement).push(childTemporaryPositionData);
		
		domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
		domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
		
		if (position == true)
		{
			_formattingContextData.y += domElement.offsetHeight;
			
		}
		else
		{
			_formattingContextData.y += domElement.offsetHeight - domElement.style.computedStyle.height;
		}
		_formattingContextData.maxHeight = _formattingContextData.y ;
		
		//check if the offsetWidth of the DOMElement is the largest thus far. This metrics is used when the width
		//of a container is set as 'shrink-to-fit' (takes its content width)
		if (_formattingContextData.x + domElement.offsetWidth > _formattingContextData.maxWidth)
		{
			_formattingContextData.maxWidth = _formattingContextData.x + domElement.offsetWidth;
		}
		
	}

	/**
	 * clear left, right or both floats and set the y of the formattingContextData below
	 * the last cleared float
	 */
	override public function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		_formattingContextData.y = _floatsManager.clearFloat(clear, _formattingContextData);
	}
	
	
	
	

	
}