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

	private var _domElementInLineBox:Array<DOMElement>;
	
	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		super(domElement, previousFormattingContext);
		
		_domElementInLineBox = new Array<DOMElement>();
	}
	

	override public function insert(domElement:DOMElement):Void
	{
		_domElementInLineBox.push(domElement);
		
		super.insert(domElement);
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
		if (_domElementInLineBox.length > 0)
		{
			
			var lineBoxHeight:Int = computeLineBoxHeight();
			
			_domElementInLineBox = new Array<DOMElement>();
			
			_flowData.y += lineBoxHeight;
			_flowData.totalHeight += lineBoxHeight;
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
			
			
			
			
	}
	
	private function computeLineBoxHeight():Int
	{
		//get ascent and descent of the strut
		var lineBoxAscent:Float = _containingDOMElement.style.fontMetrics.ascent;
		var lineBoxDescent:Float = _containingDOMElement.style.fontMetrics.descent;
		
		
		for (i in 0..._domElementInLineBox.length)
		{
			
			//! warning only works if all domElement in line are aligned to the baseline of the strut or are direct children
			//of the block container
			if (_domElementInLineBox[i].style.fontMetrics.ascent - _domElementInLineBox[i].style.computedStyle.verticalAlign > lineBoxAscent)
			{
				lineBoxAscent = _domElementInLineBox[i].style.fontMetrics.ascent - _domElementInLineBox[i].style.computedStyle.verticalAlign;
			}
			
			if (_domElementInLineBox[i].style.fontMetrics.descent + _domElementInLineBox[i].style.computedStyle.verticalAlign > lineBoxDescent)
			{
				lineBoxDescent = _domElementInLineBox[i].style.fontMetrics.descent + _domElementInLineBox[i].style.computedStyle.verticalAlign;
			}
			
		}
		
		var lineBoxHeight:Float = lineBoxAscent + lineBoxDescent;
		
		//Log.trace(lineBoxHeight);
		//Log.trace(lineBoxAscent);
		//Log.trace(lineBoxDescent);
		
		for (i in 0..._domElementInLineBox.length)
		{
			if (_domElementInLineBox[i].style.isEmbedded() == false)
			{
				_domElementInLineBox[i].y += Math.round(lineBoxAscent) ;
			}
			
			
		}
		
	//	Log.trace(lineBoxHeight);
		return Math.round(lineBoxHeight);
	}
	
	

	
	
}