package cocktail.style.js;
import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractStyle;
import haxe.Log;

import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	private function getMarginValue(value:MarginStyleValue):String
	{
		var marginValue:String;
		
		switch(value)
		{
			case length(unit):
			switch unit
			{
				case pixel(pixelValue):
					marginValue = Std.string(pixelValue) + "px";
			}
			
			case percent(percentValue):
				marginValue = Std.string(percentValue) + "%";
				
			case auto:
				marginValue = "auto";
		}
		
		return marginValue;
	}
	
	private function getPaddingValue(value:PaddingStyleValue):String
	{
		var paddingValue:String;
		
		switch(value)
		{
			case length(unit):
			switch unit
			{
				case pixel(pixelValue):
					paddingValue = Std.string(pixelValue) + "px";
			}
			
			case percent(percentValue):
				paddingValue = Std.string(percentValue) + "%";
		}
		
		return paddingValue;
	}
	
	private function getDimensionValue(value:DimensionStyleValue):String
	{
		var dimensionValue:String;
		
		switch (value)
		{
			case DimensionStyleValue.length(unit):
				switch (unit)
				{
					case pixel(pixelValue):
						dimensionValue = Std.string(pixelValue) + "px";
				}
				
			case DimensionStyleValue.percent(percentValue):
				dimensionValue = Std.string(percentValue) + "%";
				
			case DimensionStyleValue.auto:
				dimensionValue = "auto";
		}
		
		return dimensionValue;
	}
	
	private function getPositionOffsetStyleValue(value:PositionOffsetStyleValue):String
	{
		var positionOffsetValue:String;
		
		switch (value)
		{
			case length(unit):
			switch unit
			{
				case pixel(pixelValue):
					positionOffsetValue = Std.string(pixelValue) + "px";
			}
			
			case percent(percentValue):
				positionOffsetValue = Std.string(percentValue) + "%";
				
			case auto:
				positionOffsetValue = "auto";
		}
		
		return positionOffsetValue;
	}
	
	private function getConstrainedDimensionValue(value:ConstrainedDimensionStyleValue):String
	{
		var constrainedValue:String;
		
		switch (value)
		{
			case length(unit):
			switch (unit)
			{
				case pixel(pixelValue):
					constrainedValue = Std.string(pixelValue) + "px";
			}
			
			case percent(percentValue):
				constrainedValue = Std.string(percentValue) + "%";
				
			case none:	
				constrainedValue = "none";
		}
		
		return constrainedValue;
		
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	
	
	override private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginLeft = getMarginValue(value);
		return _marginLeft = value;
	}
	
	override private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginRight = getMarginValue(value);
		return _marginRight = value;
	}
	
	override private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginTop = getMarginValue(value);
		return _marginTop = value;
	}
	
	override private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginBottom = getMarginValue(value);
		return _marginBottom = value;
	}
	
	override private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingLeft = getPaddingValue(value);
		return _paddingLeft = value;
	}
	
	override private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingRight = getPaddingValue(value);
		return _paddingRight = value;
	}
	
	override private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingTop = getPaddingValue(value);
		return _paddingTop = value;
	}
	
	override private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingBottom = getPaddingValue(value);
		return _paddingBottom = value;
	}
	
	override private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		var displayValue:String;
		
		switch (value)
		{
			case block:
				displayValue = "block";
			
			case _inline:
				displayValue = "inline";
			
			case inlineBlock:
				displayValue = "inline-block";
				
			case DisplayStyleValue.none:
				displayValue = "none";
		}
		this._domElement.nativeElement.style.display = displayValue;
		
		return _display = value;
	}
	
	override private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		var positionValue:String;
		
		switch (value)
		{
			case _static:
				positionValue = "static";
			
			case relative:
				positionValue = "relative";
			
			case absolute:
				positionValue = "absolute";
				
			case fixed:
				positionValue = "fixed";
		}
		
		this._domElement.nativeElement.style.position = positionValue;
		
		return _position = value;
	}
	
	override private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.width = getDimensionValue(value);
		
		return _width = value;
	}
	
	override private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.height = getDimensionValue(value);
		
		return _height = value;
	}
	
	override private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minHeight = getConstrainedDimensionValue(value);
		return _minHeight = value;
	}
	
	override private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxHeight = getConstrainedDimensionValue(value);
		return _maxHeight = value;
	}
	
	override private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minWidth = getConstrainedDimensionValue(value);
		return _minWidth = value;
	}
	
	override private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxWidth = getConstrainedDimensionValue(value);
		return _maxWidth = value;
	}
	
	override private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.top = getPositionOffsetStyleValue(value);
		return _top = value;
	}
	
	override private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.left = getPositionOffsetStyleValue(value);
		return _left = value;
	}
	
	override private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.bottom = getPositionOffsetStyleValue(value);
		return _bottom = value;
	}
	
	override private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.right = getPositionOffsetStyleValue(value);
		return _right = value;
	}
	
	override private function setFloat(value:FloatStyleValue):FloatStyleValue 
	{
		var floatValue:String;
		
		switch (value)
		{
			case FloatStyleValue.left:
				floatValue = "left";
				
			case FloatStyleValue.right:
				floatValue = "right";
				
			case FloatStyleValue.none:
				floatValue = "none";
		}
		
		this._domElement.nativeElement.style.styleFloat = floatValue;
		
		return _float = value;
	}
	
	override private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		var clearValue:String;
		
		switch (value)
		{
			case ClearStyleValue.left:
				clearValue = "left";
				
			case ClearStyleValue.right:
				clearValue = "right";
				
			case ClearStyleValue.both:
				clearValue = "both";
				
			case ClearStyleValue.none:
				clearValue = "none";
		}
		
		this._domElement.nativeElement.style.clear = clearValue;
		
		return _clear = value;
	}
}