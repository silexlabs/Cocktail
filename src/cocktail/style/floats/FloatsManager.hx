package cocktail.style.floats;

import cocktail.domElement.DOMElement;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.StyleData;

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
	
	public function addLeftFloats(formattingContext:FormattingContext):Void
	{
		for (i in 0...formattingContext.floatsManager.floats.left.length)
		{	
						
			_floats.left.push(globalTolocal(formattingContext.floatsManager.floats.left[i], formattingContext.flowData));		
		}
	}
	
	public function removeFloats(yFlow:Int):Void
	{
		var leftFloats:Array<FloatData> = _floats.left;
		var newLeftFloats:Array <FloatData> = new Array<FloatData>();
		
		for (i in 0...leftFloats.length)
		{
			if (leftFloats[i].y + leftFloats[i].height > yFlow)
			{
				newLeftFloats.push(leftFloats[i]);
			}
		}
		
		_floats.left = newLeftFloats;
		
		for (i in 0..._floats.right.length)
		{
			if (_floats.right[i].y + _floats.right[i].height <= yFlow)
			{
				_floats.right.remove(_floats.right[i]);
			}
		}
	}
	
	public function retrieveFloats(formattingContext:FormattingContext):Void
	{
		if (formattingContext != null)
		{
			for (i in 0...formattingContext.floatsManager.floats.left.length)
			{
				if (formattingContext.flowData.containingBlockHeight != -1)
				{
					if (isFloatOverflowing(formattingContext.floatsManager.floats.left[i], formattingContext.flowData.containingBlockHeight) ==  true)
					{
						_floats.left.push(localToGlobal(formattingContext.floatsManager.floats.left[i], formattingContext.flowData,formattingContext.getRootDOMElement()));
					}
				}
				
			}
			
			for (i in 0...formattingContext.floatsManager.floats.right.length)
			{
				if (isFloatOverflowing(formattingContext.floatsManager.floats.right[i], formattingContext.flowData.containingBlockHeight) ==  true)
				{
					_floats.right.push(localToGlobal(formattingContext.floatsManager.floats.right[i], formattingContext.flowData, formattingContext.getRootDOMElement()));
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
		var floatX:Int = flowData.firstLineX + getLeftFloatOffset(flowData.y);
		var floatY:Int = flowData.y;
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