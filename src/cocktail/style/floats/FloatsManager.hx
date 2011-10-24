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
	}
	
	public function retrieveFloats(childrenFormattingContext:FormattingContext, formattingContext:FormattingContext):Void
	{
		if (childrenFormattingContext != null)
		{
			for (i in 0...childrenFormattingContext.floatsManager.floats.left.length)
			{
				_floats.left.push(localToGlobal(childrenFormattingContext.floatsManager.floats.left[i], formattingContext.flowData));
			}
			
			for (i in 0...formattingContext.floatsManager.floats.right.length)
			{
				_floats.right.push(localToGlobal(formattingContext.floatsManager.floats.right[i], formattingContext.flowData));
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
	
	public function clearFloat(clear:ClearStyleValue):Void
	{

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
	
	private function getFirstAvailableY(flowData:FlowData, floatWidth:Int):Int
	{
		var retY:Int = flowData.y;
		
		while (getLeftFloatOffset(retY) + getRightFloatOffset(retY) + floatWidth > flowData.containingBlockWidth)
		{
			var afterLeftFloats:Array<FloatData> = new Array<FloatData>();
			for (i in 0..._floats.left.length)
			{
				if (_floats.left[i].y < retY && _floats.left[i].height + _floats.left[i].y >= retY)
				{
					afterLeftFloats.push(_floats.left[i]);
				}
			}
			
			if (afterLeftFloats.length == 0)
			{
				break;
			}
			else
			{
				var highestXOffsetFloat:FloatData = afterLeftFloats[0];
				
				for (i in 0...afterLeftFloats.length)
				{
					if (afterLeftFloats[i].x > highestXOffsetFloat.x)
					{
						highestXOffsetFloat = afterLeftFloats[i];
					}
				}
				
				retY = highestXOffsetFloat.y + highestXOffsetFloat.height;
			}
		}
		
		return retY;
	}
	
	private function getRightFloatData(domElement:DOMElement, flowData:FlowData):FloatData
	{
		return {
			x: 0,
			y: 0,
			width:domElement.offsetWidth,
			height:domElement.offsetHeight
		}
	}
	
	
	public function getRightFloatOffset(y:Int):Int
	{
		return 0;
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