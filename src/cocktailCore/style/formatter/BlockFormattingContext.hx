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
import cocktailCore.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class BlockFormattingContext extends FormattingContext
{

	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		super(domElement, previousFormattingContext);
	}
	
	override private function place(domElement:DOMElement):Void
	{
		super.place(domElement);
		
		var leftFloatOffset:Int = 0;
		
		if (domElement.style.isEmbedded() == true)
		{
			_flowData.y = _floatsManager.getFirstAvailableY(flowData, domElement.offsetWidth, _containingDOMElementWidth);
			leftFloatOffset = _floatsManager.getLeftFloatOffset(_flowData.y  + domElement.style.computedStyle.marginTop);
		}
			
		
		_flowData.x = _flowData.xOffset + leftFloatOffset;
	
		domElement.style.applyComputedX(domElement, _flowData.x + domElement.style.computedStyle.marginLeft);
		domElement.style.applyComputedY(domElement, _flowData.y + domElement.style.computedStyle.marginTop);
		
		_flowData.y += domElement.offsetHeight ;
		_flowData.totalHeight = _flowData.y  ;
		
		if (_flowData.x + domElement.offsetWidth + domElement.style.computedStyle.marginLeft > _flowData.maxWidth)
		{
			_flowData.maxWidth = _flowData.x + domElement.offsetWidth + domElement.style.computedStyle.marginLeft;
		}
		
	
		
		
	}

	override public function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		_flowData.y = _floatsManager.clearFloat(clear, _flowData);
		
	}
	
	
	
	

	
}