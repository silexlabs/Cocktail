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

class InlineFormattingContext extends FormattingContext
{

	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		super(domElement, previousFormattingContext);
	}
	
	override private function place(domElement:DOMElement):Void
	{
		super.place(domElement);
		
		if (_flowData.x + domElement.offsetWidth + _floatsManager.getLeftFloatOffset(_flowData.y) + _floatsManager.getRightFloatOffset(flowData.y) > _flowData.maxLineWidth)
		{
			startNewLine();
		}
		
		domElement.x = _flowData.x + domElement.style.computedStyle.marginLeft + domElement.style.computedStyle.paddingLeft;
		domElement.y = _flowData.y + domElement.style.computedStyle.marginTop + domElement.style.computedStyle.paddingTop;
		_flowData.x += domElement.offsetWidth;
					
		if (domElement.offsetHeight > flowData.maxLineHeight)
		{
			var oldMaxLineHeight:Int = _flowData.maxLineHeight;
			_flowData.maxLineHeight = domElement.offsetHeight;
			_flowData.totalHeight += _flowData.maxLineHeight - oldMaxLineHeight;
			
		}
		
	}
	
	
	override private function startNewLine():Void
	{
		_flowData.y += _flowData.maxLineHeight;
		_flowData.totalHeight += _flowData.maxLineHeight;
		_flowData.maxLineHeight = 0;
		
		_flowData.x = _flowData.firstLineX + _floatsManager.getLeftFloatOffset(_flowData.y);
		_flowData.maxLineWidth = _flowData.containingBlockWidth - _floatsManager.getRightFloatOffset(_flowData.y) - _floatsManager.getLeftFloatOffset(_flowData.y);
		
	}
	
	

	
	
}