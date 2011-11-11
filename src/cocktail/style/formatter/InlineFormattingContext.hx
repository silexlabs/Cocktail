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
		//get ascent and descent of the strut
		var lineBoxAscent:Int = _containingDOMElement.fontMetrics.ascent;
		var lineBoxDescent:Int = _containingDOMElement.fontMetrics.descent;
		
		for (i in 0...domElementInLineBox.length)
		{
			//TO DO : baselineOffset should actually be computed vertical align which is a value
			//relative to the strut baseline
			var baselineOffset:Int;
			
			//To DO : move this to the box computer, will need to add either a ref to the containing dom element
			//or to its font metrics
			switch(domElementInLineBox[i].style.computedStyle.verticalAlign)
			{
				case baseline:
					baselineOffset = 0;
					
				case middle:
					//! warning : containing dom element must be either an inline parent or the block which started inline context
					baselineOffset = domElementInLineBox[i].offsetHeight / 2 + _containingDOMElement.fontMetrics.xHeight / 2;
					
				case sub:
					baselineOffset = _containingDOMElement.fontMetrics.subscriptOffset;
					
				case _super:
					baselineOffset = _containingDOMElement.fontMetrics.supercriptOffset;
					
				case textTop:
					baselineOffset = 0;
					//TO DO : Align the top of the box with the top of the parent's content area
					
				case textBottom:
					baselineOffset = 0;
					//TO DO : Align the bottom of the box with the bottom of the parent's content area 
					
				case percent(value):
					baselineOffset = domElementInLineBox[i].style.computedStyle.lineHeight * (value * 0.01);
					
				case length(value):
					baselineOffset = getValueFromLength(value);
					
				case top:
					baselineOffset = 0;
					//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
				case bottom:	
					baselineOffset = 0;
					//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
			}
			
			//! warning only works if all domElement in line are aligned to the baseline of the strut or are direct children
			//of the block container
			if (domElementInLineBox[i].fontMetrics.ascent - baselineOffset > lineBoxAscent)
			{
				lineBoxAscent = domElementInLineBox[i].fontMetrics.ascent - baselineOffset;
			}
			
			if (domElementInLineBox[i].fontMetrics.descent + baselineOffset > lineBoxDescent)
			{
				lineBoxDescent = domElementInLineBox[i].fontMetrics.descent + baselineOffset;
			}
			
		}
		
		var lineBoxHeight:Int = lineBoxAscent + lineBoxDescent;
	}
	
	

	
	
}