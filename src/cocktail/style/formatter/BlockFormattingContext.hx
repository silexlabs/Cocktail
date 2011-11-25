/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.formatter;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
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
		domElement.x = _flowData.x + domElement.style.computedStyle.marginLeft;
		domElement.y = _flowData.y + domElement.style.computedStyle.marginTop ;
	
		_flowData.y += domElement.offsetHeight ;
		
		
		_flowData.totalHeight = _flowData.y  ;
		
	}
	

	override private function placeFloat(domElement:DOMElement, floatData:FloatData):Void
	{
		domElement.x = floatData.x + domElement.style.computedStyle.marginLeft ;
		domElement.y = floatData.y + domElement.style.computedStyle.marginTop ;
		

		_flowData.y = floatData.y;

		
	}

	override public function clearFloat(clear:ClearStyleValue):Void
	{
		_flowData.y = _floatsManager.clearFloat(clear, _flowData);
		
	}
	
	
	
	

	
}