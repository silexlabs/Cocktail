package cocktail.style.floats;

import cocktail.domElement.DOMElement;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FloatsManager 
{

	private var _floats:FloatsData;
	public var floats(getFloats, never):FloatsData;
	
	public function new() 
	{
		var floatsLeft:Array<FloatData> = new Array<FloatData>();
		var floatsRight:Array<FloatData> = new Array<FloatData>();
	
		_floats = {
			left:floatsLeft,
			right:floatsRight
		}
	}
	
	public function addLeftFloats(parentFormattingContext:FormattingContext, formattingContext:FormattingContext):Void
	{
		for (i in 0...parentFormattingContext.floatsManager.floats.left.length)
		{	
			_floats.left.push(globalTolocal(parentFormattingContext.floatsManager.floats.left[i], parentFormattingContext.flowData));		
		}
	}
	
	public function addRightFloats(parentFormattingContext:FormattingContext, formattingContext:FormattingContext):Void
	{
		for (i in 0...parentFormattingContext.floatsManager.floats.right.length)
		{	
			_floats.right.push(globalTolocal(parentFormattingContext.floatsManager.floats.right[i], parentFormattingContext.flowData));		
		}
	}
	
	public function removeFloats(yFlow:Int):Void
	{
		var leftFloats:Array<FloatData> = _floats.left;
		var newLeftFloats:Array<FloatData> = new Array<FloatData>();
		
		for (i in 0...leftFloats.length)
		{
			if (leftFloats[i].y + leftFloats[i].height > yFlow)
			{
				newLeftFloats.push(leftFloats[i]);
			}
		}
		
		_floats.left = newLeftFloats;
		
		var rightFloats:Array<FloatData> = _floats.right;
		var newRightFloat:Array<FloatData> = new Array<FloatData>();
		
		for (i in 0...rightFloats.length)
		{
			if (rightFloats[i].y + rightFloats[i].height > yFlow)
			{
				newRightFloat.push(rightFloats[i]);
			}
		}
		
		_floats.right = newRightFloat;
	}
	
	public function retrieveFloats(childrenFormattingContext:FormattingContext, formattingContext:FormattingContext):Void
	{
		if (childrenFormattingContext != null)
		{
			for (i in 0...childrenFormattingContext.floatsManager.floats.left.length)
			{
				_floats.left.push(localToGlobal(childrenFormattingContext.floatsManager.floats.left[i], formattingContext.flowData));
			}
			
			for (i in 0...childrenFormattingContext.floatsManager.floats.right.length)
			{
				_floats.right.push(localToGlobal(childrenFormattingContext.floatsManager.floats.right[i], formattingContext.flowData));
			}
		}
		
	}
	
	private function localToGlobal(floatData:FloatData, flowData:FlowData):FloatData
	{

		var floatX:Int = floatData.x + flowData.x;
		
		var floatY:Int = floatData.y ;
		
		var floatHeight:Int = floatData.height;
		
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
		var floatY:Int = floatData.y - flowData.y;

		var floatHeight:Int = floatData.height;
		
		floatHeight = floatData.height;
	
		var floatWidth:Int = floatData.width;
		
		var convertedFloatData:FloatData = {
			x: floatX,
			y: floatY,
			width: floatWidth,
			height: floatHeight
		}
		
		
		return convertedFloatData;
	}
	
	public function clearFloat(clear:ClearStyleValue, flowData:FlowData):Int
	{
		var ret:Int;
		
		switch(clear)
		{
			case left:
				ret = clearLeft(flowData);
				_floats.left = new Array<FloatData>();
				
			case right:
				ret = clearRight(flowData);
				_floats.right = new Array<FloatData>();
				
			case both:	
				ret = clearBoth(flowData);
				_floats.right = new Array<FloatData>();
				_floats.left = new Array<FloatData>();
			
			case none:
				ret = flowData.y;
		}
		
		return ret;
	}
	
	private function clearLeft(flowData:FlowData):Int
	{
		return doClearFloat(flowData, _floats.left);
	}
	
	private function doClearFloat(flowData:FlowData, floats:Array<FloatData>):Int
	{
		if (floats.length > 0)
		{
			var highestFloat:FloatData = floats[0];
			
			for (i in 0...floats.length)
			{
				if (floats[i].y + floats[i].height > highestFloat.y + highestFloat.height)
				{
					highestFloat = floats[i];
				}
			}
			
			return highestFloat.y + highestFloat.height;
			
		}
		else
		{
			return flowData.y;
		}
	}
	
	private function clearRight(flowData:FlowData):Int
	{
		return doClearFloat(flowData, _floats.right);
	}
	
	private function clearBoth(flowData:FlowData):Int
	{
		var leftY:Int = doClearFloat(flowData, _floats.left);
		var rightY:Int = doClearFloat(flowData, _floats.right);
		
		if (leftY > rightY)
		{
			return leftY;
		}
		else
		{
			return rightY;
		}
	}
	
	public function computeFloatData(domElement:DOMElement, flowData:FlowData):FloatData
	{
		var ret:FloatData;
		
		switch (domElement.style.computedStyle.float)
		{
			case left:
				ret = getLeftFloatData(domElement, flowData);
				_floats.left.push(ret);
				
			case right:
				ret = getRightFloatData(domElement, flowData);
				_floats.right.push(ret);
				
			default:
				ret = null;
		}
		
		return ret;
	}
	
	
	public function getNextClear(flowData:FlowData):ClearStyleValue
	{
		var leftY:Int = 100000;
		
		for (i in 0..._floats.left.length)
		{
			if (_floats.left[i].y < flowData.y && _floats.left[i].y + _floats.left[i].height > flowData.y)
			{
				if (_floats.left[i].y + _floats.left[i].height - flowData.y < leftY)
				{
					leftY = _floats.left[i].y + _floats.left[i].height - flowData.y;
				}
			}
		}
		
		var rightY:Int = 100000;
		
		for (i in 0..._floats.right.length)
		{
			if (_floats.right[i].y < flowData.y && _floats.right[i].y + _floats.right[i].height > flowData.y)
			{
				if (_floats.right[i].y + _floats.right[i].height - flowData.y < rightY)
				{
					rightY = _floats.right[i].y + _floats.right[i].height - flowData.y;
				}
			}
		}
		
		if (leftY < rightY)
		{
			return ClearStyleValue.left;
		}
		else
		{
			return ClearStyleValue.right;
		}
		
	}
	
	private function getLeftFloatData(domElement:DOMElement, flowData:FlowData):FloatData
	{
		

		
		var floatWidth:Int = domElement.offsetWidth;
		var floatHeight:Int = domElement.offsetHeight;
	
		var floatY:Int = getFirstAvailableY(flowData, floatWidth);
		var floatX:Int = flowData.firstLineX + getLeftFloatOffset(floatY);
		
		return {
			x: floatX,
			y: floatY,
			width:floatWidth,
			height:floatHeight
		}
	}
	
	private function getFirstAvailableY(flowData:FlowData, floatWidth:Int, rightFloat:Bool = false):Int
	{
		var retY:Int = flowData.y;
		
		while (getLeftFloatOffset(retY) + getRightFloatOffset(retY, flowData.containingBlockWidth) + floatWidth > flowData.containingBlockWidth)
		{
			
			var afterFloats:Array<FloatData> = new Array<FloatData>();
			for (i in 0..._floats.left.length)
			{
				if (_floats.left[i].y <= retY && _floats.left[i].height + _floats.left[i].y > retY)
				{
					afterFloats.push(_floats.left[i]);
				}
			}
			for (i in 0..._floats.right.length)
			{
				if (_floats.right[i].y <= retY && _floats.right[i].height + _floats.right[i].y > retY)
				{
					afterFloats.push(_floats.right[i]);
				}
			}
			
			
			if (afterFloats.length == 0)
			{
				break;
			}
			else
			{
				var nextY:Int = 100000;
				
				for (i in 0...afterFloats.length)
				{
					if (afterFloats[i].y + afterFloats[i].height - retY < nextY)
					{
						nextY = afterFloats[i].y + afterFloats[i].height - retY;
					}
				}
				
				retY += nextY;
				
				/**
				var highestXOffsetFloat:FloatData = afterFloats[0];
				for (i in 0...afterFloats.length)
				{
					if (rightFloat == false)
					{
						if (afterFloats[i].x > highestXOffsetFloat.x)
						{
							highestXOffsetFloat = afterFloats[i];
						}
					}
					else
					{
						if (afterFloats[i].x < highestXOffsetFloat.x)
						{
							highestXOffsetFloat = afterFloats[i];
						}
					}
					
				}
				
				retY = highestXOffsetFloat.y + highestXOffsetFloat.height;
				*/
			}
		}
		
		return retY;
	}
	
	private function getStartLine(flowData:FlowData, rightFloat:Bool):Int
	{
		var startLine:Int = flowData.y;
		
		if (rightFloat == true)
		{
			for (i in 0..._floats.left.length)
			{
				if (_floats.left[i].y > startLine)
				{
					startLine = _floats.left[i].y;
				}
			}
			
		}
		else
		{
			for (i in 0..._floats.left.length)
			{
				if (_floats.left[i].y > startLine)
				{
					startLine = _floats.left[i].y;
				}
			}
		}
		
		return startLine;
	}
	
	private function getRightFloatData(domElement:DOMElement, flowData:FlowData):FloatData
	{
		
		var floatWidth:Int = domElement.offsetWidth;
		var floatHeight:Int = domElement.offsetHeight;
	
		var floatY:Int = getFirstAvailableY(flowData, floatWidth, true);
		
		var floatX:Int = flowData.containingBlockWidth - floatWidth - getRightFloatOffset(floatY, flowData.containingBlockWidth) + flowData.firstLineX;
		
		return {
			x: floatX,
			y: floatY,
			width:floatWidth,
			height:floatHeight
		}
	}
	
	
	public function getRightFloatOffset(y:Int, containingWidth:Int):Int
	{
		var rightFloatOffset:Int = 0;
		
		for (i in 0..._floats.right.length)
		{
			if (_floats.right[i].y + _floats.right[i].height > y &&
			_floats.right[i].y <= y)
			{
				if (containingWidth - _floats.right[i].x > rightFloatOffset)
				{
					rightFloatOffset = containingWidth - _floats.right[i].x;
				}
			}
		}
		
		return rightFloatOffset;
	}
	
	public function getLeftFloatOffset(y:Int):Int
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
	
	private function getFloats():FloatsData
	{
		return _floats;
	}
}