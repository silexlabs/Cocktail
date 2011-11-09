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
		
		if (getRemainingLineWidth() - domElement.offsetWidth < 0)
		{	
			
			startNewLine();
		}
		
		domElement.x = _flowData.x + domElement.style.computedStyle.marginLeft ;
		domElement.y = _flowData.y + domElement.style.computedStyle.marginTop ;
		
		_flowData.x += domElement.offsetWidth;

		if (domElement.offsetHeight > _flowData.maxLineHeight)
		{
			var oldMaxLineHeight:Int = _flowData.maxLineHeight;
			_flowData.maxLineHeight = domElement.offsetHeight;
			//_flowData.totalHeight += _flowData.maxLineHeight - oldMaxLineHeight;
			
		}
		
	}
	
	override public function startNewLine():Void
	{
			computeLineBox();
		
			_flowData.y += _flowData.maxLineHeight;
			_flowData.totalHeight += _flowData.maxLineHeight;
			_flowData.maxLineHeight = 0;
			
			if (_floatsManager.getLeftFloatOffset(_flowData.y) > _flowData.xOffset)
			{
				
				flowData.x =  _floatsManager.getLeftFloatOffset(_flowData.y);
			}
			else
			{
				_flowData.x = _flowData.xOffset;
			}
	}
	
	private function computeLineBox():Void
	{
		/**
		var lineBoxTop:Int;
		var lineBoxBottom:Int;
		
		for (i in 0...domElementInLineBox.length)
		{
			var baselineOffset:Int;
			
			switch(domElementInLineBox[i].style.computedStyle.verticalAlign)
			{
				case baseline:
					baselineOffset = 0;
					
				case middle:
					baselineOffset = domElementInLineBox[i].offsetHeight / 2 + _containingDOMElement.fontMetrics.xHeight / 2;
					
				case sub:
					baselineOffset = domElementInLineBox[i].fontMetrics.subscriptOffset;
					
				case _super:
					baselineOffset = domElementInLineBox[i].fontMetrics.supercriptOffset;
					
				case textTop:
					baselineOffset
					
					
			}
			
			if (domElement[i].fontMetrics != null)
			{
				
				
				if (domElement[i].fontMetrics.ascent > lineBoxTop)
				{
					lineBoxTop = domElement[i].fontMetrics.ascent;
				}
			}
		}*/
	}
	
	

	
	
}