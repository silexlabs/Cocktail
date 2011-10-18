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
 
class FormattingContext 
{

	private var _rootDOMElement:DOMElement;
	
	private var _formatedElements:Array<DOMElement>;
	
	private var _floats:FloatsData;
	public var floats(getFloats, never):FloatsData;
	
	private var _flowData:FlowData;
	public var flowData(getFlowData, never):FlowData;
	
	
	public function new(domElement:DOMElement, previousFormatingContext:FormattingContext = null) 
	{
		
		_rootDOMElement = domElement;
		
		_formatedElements = new Array<DOMElement>();
		
		_floats = retrieveFloats(previousFormatingContext);
		
		
		_flowData = initFlowData(domElement);
		
		
		startNewLine();
		
	}
	
	private function initFlowData(domElement:DOMElement):FlowData
	{
		return {
			x : domElement.style.computedStyle.paddingLeft,
			y : domElement.style.computedStyle.paddingTop,
			firstLineX : domElement.style.computedStyle.paddingLeft,
			firstLineY : domElement.style.computedStyle.paddingTop,
			maxLineWidth : domElement.style.computedStyle.width,
			maxWidth : domElement.style.computedStyle.width,
			totalHeight : 0,
			maxLineHeight : 0
		};
	}
	
	public static function getFormatingContext(domElement:ContainerDOMElement, previousFormatingContext:FormattingContext = null):FormattingContext
	{
		var ret:FormattingContext;
		
		switch (domElement.style.computedStyle.display)
		{
			case block, inlineBlock:
				if (childrenInline(domElement) == true)
				{
					ret = new InlineFormattingContext(domElement, previousFormatingContext);
				}
				else
				{
					ret = new BlockFormattingContext(domElement, previousFormatingContext);
				}
				
			default:
				ret = new InlineFormattingContext(domElement, previousFormatingContext);
		}
		
		return ret;
	}
	
	public static function childrenInline(domElement:ContainerDOMElement):Bool
	{
		var ret:Bool = false;
		for (i in 0...domElement.children.length)
		{
			if (domElement.children[i].style.computedStyle.display == _inline ||
			domElement.children[i].style.computedStyle.display == inlineBlock)
			{
				ret = true;
			}
		}
		
		return ret;
		
	}
	
	public function insert(domElement:DOMElement):Void
	{
		_formatedElements.push(domElement);
		place(domElement);
	}
	
	private function place(domElement:DOMElement):Void
	{
		
	}
	
	public function insertFloat(domElement:DOMElement):Void
	{
		var floatData:FloatData = getFloatData(domElement);
		
		switch (domElement.style.computedStyle.float)
		{
			case left:
				_floats.left.push(floatData);
			
			case right:
				_floats.right.push(floatData);
			
			case none:	
		}
		
		_flowData = initFlowData(_rootDOMElement);
		startNewLine();
		
		for (i in 0..._formatedElements.length)
		{
			
		//	place(_formatedElements[i]);
		}
	}
	
	public function clearFloat(clear:ClearStyleValue):Void
	{

	}
	
	
	private function removeFloat():Void
	{
		
	}
	
	private function retrieveFloats(formattingContext:FormattingContext):FloatsData
	{
		var leftFloats:Array<FloatData> = new Array<FloatData>();
		var rightFloats:Array<FloatData> = new Array<FloatData>();
		
		if (formattingContext != null)
		{
			for (i in 0...formattingContext.floats.left.length)
			{
				if (isWithinBounds(formattingContext.floats.left[i], formattingContext.flowData.totalHeight) ==  true)
				{
					leftFloats.push(formattingContext.floats.left[i]);
				}
			}
			
			for (i in 0...formattingContext.floats.right.length)
			{
				if (isWithinBounds(formattingContext.floats.right[i], formattingContext.flowData.totalHeight) ==  true)
				{
					rightFloats.push(formattingContext.floats.right[i]);
				}
			}
		}
		
	
		
		return { left:leftFloats, right:rightFloats };
	}
	
	private function isWithinBounds(floatData:FloatData, totalHeight:Int):Bool
	{
		var ret:Bool = false;
		
		if (floatData.height + floatData.y > totalHeight)
		{
			ret = true;
		}
		
		return ret;
	}
	
	private function getFloatData(domElement:DOMElement):FloatData
	{
		var ret:FloatData;
		
		switch (domElement.style.computedStyle.float)
		{
			case left:
				ret = getLeftFloatData(domElement);
				
			case right:
				ret = getRightFloatData(domElement);
				
			default:
				ret = null;
		}
		
		domElement.x = ret.x;
		domElement.y = ret.y;
		
		return ret;
	}
	
	private function getLeftFloatData(domElement:DOMElement):FloatData
	{
		var floatX:Int = _flowData.firstLineX;
		var floatY:Int = _flowData.firstLineY;
		
		if (_floats.left.length > 0)
		{
			floatX = _floats.left[_floats.left.length - 1].x + _floats.left[_floats.left.length - 1].width;
			
			if (floatX > _flowData.maxWidth)
			{
				floatX = _flowData.firstLineX;
				
				var highestFloatValue:Int = 0;
				
				for (i in 0..._floats.left.length)
				{
					if ((_floats.left[i].y + _floats.left[i].height) > highestFloatValue)
					{
						highestFloatValue = (_floats.left[i].y + _floats.left[i].height);
					}
				}
				
				floatY = highestFloatValue; 
			}
			else
			{
				floatY = _floats.left[_floats.left.length - 1].y;
			}
		}
		
		
		
		return {
			x: floatX,
			y: floatY,
			width:domElement.offsetWidth,
			height:domElement.offsetHeight
		}
	}
	
	private function getRightFloatData(domElement:DOMElement):FloatData
	{
		return {
			x: 0,
			y: 0,
			width:domElement.offsetWidth,
			height:domElement.offsetHeight
		}
	}
	
	public function beginNewFormattingContext(domElement:ContainerDOMElement):Bool
	{
		return true;
	}
	
	private function startNewLine():Void
	{
		
	}
	
	public function getFloats():FloatsData
	{
		return _floats;
	}
	
	public function getFlowData():FlowData
	{
		return _flowData;
	}
	
}