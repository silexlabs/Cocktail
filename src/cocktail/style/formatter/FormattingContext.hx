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
		
		_flowData = initFlowData(domElement);
		
		var floatsLeft:Array<FloatData> = new Array<FloatData>();
		var floatsRight:Array<FloatData> = new Array<FloatData>();
	
		_floats = {
			left:floatsLeft,
			right:floatsRight
		}
		
		
		_formatedElements = new Array<DOMElement>();
		
		if (previousFormatingContext != null)
		{
				//_floats = previousFormatingContext.floats;
				if (domElement.style.isFloat() == false)
				{
					for (i in 0...previousFormatingContext.floats.left.length)
					{
						/**_floats.left.push( { x:previousFormatingContext.floats.left[i].x,
						y:previousFormatingContext.floats.left[i].y,
						width:previousFormatingContext.floats.left[i].width,
						height:previousFormatingContext.floats.left[i].height } );*/
						
						_floats.left.push(globalTolocal(previousFormatingContext.floats.left[i], previousFormatingContext.flowData));
					}
				}
				
				
			//_floats = previousFormatingContext.floats;
			
			if (previousFormatingContext.floats.left.length > 0)
			{
				//Log.trace(previousFormatingContext.flowData);
				//Log.trace(previousFormatingContext.floats.left);
			}
			
		//	retrieveFloats(previousFormatingContext);
			//Log.trace(_floats.left);
		}
		
		
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
			containingBlockWidth : domElement.style.computedStyle.width,
			containingBlockHeight : domElement.style.computedStyle.height,
			totalHeight : 0,
			maxLineHeight : 0
		};
	}
	
	public function insert(domElement:DOMElement):Void
	{
		_formatedElements.push(domElement);
		place(domElement);
		removeFloats();
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
		
		placeFloat(domElement, floatData);
	}
	
	public function clearFloat(clear:ClearStyleValue):Void
	{

	}
	
	private function placeFloat(domElement:DOMElement, floatData:FloatData):Void
	{
		
	}
	
	private function removeFloats():Void
	{
		var leftFloats:Array<FloatData> = _floats.left;
		var newLeftFloats:Array <FloatData> = new Array<FloatData>();
		
		for (i in 0...leftFloats.length)
		{
			if (leftFloats[i].y + leftFloats[i].height > _flowData.y)
			{
				newLeftFloats.push(leftFloats[i]);
			}
		}
		
		_floats.left = newLeftFloats;
		
		for (i in 0..._floats.right.length)
		{
			if (_floats.right[i].y + _floats.right[i].height <= _flowData.y)
			{
				_floats.right.remove(_floats.right[i]);
			}
		}
	}
	
	
	public function retrieveFloats(formattingContext:FormattingContext):Void
	{
		if (formattingContext != null)
		{
			for (i in 0...formattingContext.floats.left.length)
			{
				if (formattingContext.flowData.containingBlockHeight != -1)
				{
					if (isFloatOverflowing(formattingContext.floats.left[i], formattingContext.flowData.containingBlockHeight) ==  true)
					{
						_floats.left.push(localToGlobal(formattingContext.floats.left[i], formattingContext.flowData,formattingContext.getRootDOMElement()));
					}
				}
				
			}
			
			for (i in 0...formattingContext.floats.right.length)
			{
				if (isFloatOverflowing(formattingContext.floats.right[i], formattingContext.flowData.containingBlockHeight) ==  true)
				{
					_floats.right.push(localToGlobal(formattingContext.floats.right[i], formattingContext.flowData, formattingContext.getRootDOMElement()));
				}
			}
		}
		
	}
	
	private function isFloatOverflowing(floatData:FloatData, totalHeight:Int):Bool
	{
		var ret:Bool = false;
		
		if (floatData.height + floatData.y > totalHeight)
		{
			ret = true;
		}
		
		return ret;
	}
	
	private function localToGlobal(floatData:FloatData, flowData:FlowData, containingBlock:DOMElement):FloatData
	{

		var floatX:Int = floatData.x;
		var floatY:Int = 0;

		var floatHeight:Int = floatData.height + floatData.y - containingBlock.style.computedStyle.height - containingBlock.style.computedStyle.marginBottom -containingBlock.style.computedStyle.paddingTop - containingBlock.style.computedStyle.paddingBottom;
		
		
		var floatWidth:Int = floatData.width;
		
		var convertedFloatData:FloatData = {
			x: floatX,
			y: floatY,
			width: floatWidth,
			height: floatHeight
		}
		
		return convertedFloatData;
	}
	
	private function globalTolocal(floatData:FloatData, flowData:FlowData):FloatData
	{
		var floatX:Int = floatData.x;
		var floatY:Int = 0;

		
		var floatHeight:Int = floatData.height - flowData.containingBlockHeight;
		
		if (flowData.containingBlockHeight == -1)
		{
			floatHeight = floatData.height;
		}
	
		
		var floatWidth:Int = floatData.width;
		
		var convertedFloatData:FloatData = {
			x: floatX,
			y: floatY,
			width: floatWidth,
			height: floatHeight
		}
		
		return convertedFloatData;
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
		
		return ret;
	}
	
	private function getLeftFloatData(domElement:DOMElement):FloatData
	{
		var floatX:Int = _flowData.firstLineX + getLeftFloatOffset(_flowData.y);
		var floatY:Int = _flowData.y;
		var floatWidth:Int = domElement.offsetWidth;
		var floatHeight:Int = domElement.offsetHeight;
		
		//Log.trace(floatY);
		
		/**while (getLeftFloatOffset(floatY) + floatWidth > _flowData.containingBlockWidth)
		{
			floatY += 1;
		}*/
		/**
		if (_floats.left.length > 0)
		{
			floatX = _floats.left[_floats.left.length - 1].x + _floats.left[_floats.left.length - 1].width;
			
			if (floatX > _flowData.containingBlockWidth)
			{
				floatX = _flowData.firstLineX;
				
				var highestFloatValue:Int = floatY;
				
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
		*/
		
		return {
			x: floatX,
			y: floatY,
			width:floatWidth,
			height:floatHeight
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
	
	
	private function getRightFloatOffset(y:Int):Int
	{
		return 0;
	}
	
	private function getLeftFloatOffset(y:Int):Int
	{
		var leftFloatOffset:Int = 0;
		
		
		for (i in 0..._floats.left.length)
		{
			if (_floats.left[i].y + _floats.left[i].height > y &&
			_floats.left[i].y <= y)
			{
				if (_floats.left[i].x + _floats.left[i].width > leftFloatOffset)
				{
					leftFloatOffset = _floats.left[i].x + _floats.left[i].width;
				}
			}
		}
		
		return leftFloatOffset;
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
	
	public function getRootDOMElement():DOMElement
	{
		return _rootDOMElement;
	}
	
}