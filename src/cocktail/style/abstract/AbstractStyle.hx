package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.InLineBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.computer.PositionComputer;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class AbstractStyle 
{

	/////////////////////////////////
	// STYLES attributes
	////////////////////////////////
	
    /**
    * margins
	*/
	private var _marginLeft:MarginStyleValue;
	public var marginLeft(getMarginLeft, setMarginLeft):MarginStyleValue;
	private var _marginRight:MarginStyleValue;
	public var marginRight(getMarginRight, setMarginRight):MarginStyleValue;
	private var _marginTop:MarginStyleValue;
	public var marginTop(getMarginTop, setMarginTop):MarginStyleValue;
	private var _marginBottom:MarginStyleValue;
	public var marginBottom(getMarginBottom, setMarginBottom):MarginStyleValue;
	
	/**
	* paddings
	*/
	private var _paddingLeft:PaddingStyleValue;
	public var paddingLeft(getPaddingLeft, setPaddingLeft):PaddingStyleValue;
	private var _paddingRight:PaddingStyleValue;
	public var paddingRight(getPaddingRight, setPaddingRight):PaddingStyleValue;
	private var _paddingTop:PaddingStyleValue;
	public var paddingTop(getPaddingTop, setPaddingTop):PaddingStyleValue;
	private var _paddingBottom:PaddingStyleValue;
	public var paddingBottom(getPaddingBottom, setPaddingBottom):PaddingStyleValue;
	
	/**
	* The way a DOMElement flows in a document
	*/
	private var _display:DisplayStyleValue;
	public var display(getDisplay, setDisplay):DisplayStyleValue;
	
	/**
	* The way a DOMElement position himself
	* relative to a parent
	*/
	private var _position:PositionStyleValue;
	public var position(getPosition, setPosition):PositionStyleValue;
	
	/**
	* dimensions of the content area of a DOMElement
	* (the domElement size without paddings, border and margins)
	*/
	private var _width:DimensionStyleValue;
	public var width(getWidth, setWidth):DimensionStyleValue;
	private var _height:DimensionStyleValue;
	public var height(getHeight, setHeight):DimensionStyleValue;
	
	/**
	* dimensions constraint of a DOMElement
	*/
	private var _minHeight:ConstrainedDimensionStyleValue;
	public var minHeight(getMinHeight, setMinHeight):ConstrainedDimensionStyleValue;
	private var _maxHeight:ConstrainedDimensionStyleValue;
	public var maxHeight(getMaxHeight, setMaxHeight):ConstrainedDimensionStyleValue;
	private var _minWidth:ConstrainedDimensionStyleValue;
	public var minWidth(getMinWidth, setMinWidth):ConstrainedDimensionStyleValue;
	private var _maxWidth:ConstrainedDimensionStyleValue;
	public var maxWidth(getMaxWidth, setMaxWidth):ConstrainedDimensionStyleValue;
	
	/**
	* offsets of a DOMElement
	*/
	private var _top:PositionOffsetStyleValue;
	public var top(getTop, setTop):PositionOffsetStyleValue;
	private var _left:PositionOffsetStyleValue;
	public var left(getLeft, setLeft):PositionOffsetStyleValue;
	private var _bottom:PositionOffsetStyleValue;
	public var bottom(getBottom, setBottom):PositionOffsetStyleValue;
	private var _right:PositionOffsetStyleValue;
	public var right(getRight, setRight):PositionOffsetStyleValue;
	
	/**
	 * float positioning styles. A floated element is placed to 
	 * the further left or right of its container
	 */
	private var _float:FloatStyleValue;
	public var float(getFloat, setFloat):FloatStyleValue;
	private var _clear:ClearStyleValue;
	public var clear(getClear, setClear):ClearStyleValue;
	
	////////////////////////////////
	
	/**
	 * Stores all of the actual value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	private var _computedStyle:ComputedStyleData;
	public var computedStyle(getComputedStyle, never):ComputedStyleData;
	
	/**
	 * A reference to the DOMElement to which these styles
	 * apply
	 */
	private var _domElement:DOMElement;
	
	public function new(domElement:DOMElement) 
	{
		this._domElement = domElement;
		
		this._computedStyle = {
			width : 0,
			height : 0,
			minHeight : 0,
			maxHeight : 0,
			minWidth : 0,
			maxWidth : 0,
			offsetWidth : 0,
			offsetHeight : 0,
			marginLeft : 0,
			marginRight : 0,
			marginTop : 0,
			marginBottom : 0,
			paddingLeft : 0,
			paddingRight : 0,
			paddingTop : 0,
			paddingBottom : 0,
			left: 0,
			right: 0,
			top: 0,
			bottom : 0,
			clear : ClearStyleValue.none,
			float : FloatStyleValue.none,
			display : DisplayStyleValue.block,
			position: PositionStyleValue._static
		}
	}
	
	public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		
	}
	
	public function flow(containingDOMElementDimensions:ContainingDOMElementDimensions, formatingContext:FormattingContext = null, initialContainer:Bool = false):Void
	{
	
		computePositionStyle();
		
		this._computedStyle = computeBoxModelStyle(containingDOMElementDimensions);
		
		if (this._computedStyle.display == DisplayStyleValue.none)
		{
			this._domElement.isVisible = false;
			return;
		}
		
		this._domElement.width = this._computedStyle.width;
		this._domElement.height = this._computedStyle.height;
		
		if (isPositioned() == false)
		{
			formatingContext.insert(this._domElement);
		}
	}
	
	public function computePositionStyle():Void
	{
		this._computedStyle = PositionComputer.compute(this);
	}
	
	public function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions):ComputedStyleData
	{
		var boxComputer:BoxComputer;
		
		switch(this._computedStyle.display)
		{
			case block, inlineBlock:
				boxComputer = new BlockBoxComputer();
			
			case none:
				boxComputer = new NoneBoxComputer();
			
			case _inline:
				boxComputer = new InLineBoxComputer();
		}
		
		return boxComputer.measure(this._domElement, containingDOMElementDimensions);
	}
	
	public function positionElement(lastPositionnedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		
	}
	
	public function isClear():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.clear) 
		{
			case ClearStyleValue.left, ClearStyleValue.right, ClearStyleValue.both:
				ret = true;
			
			case ClearStyleValue.none:
				ret = false;
		}
		
		return ret;
	}
	
	public function isFloat():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.float) 
		{
			case FloatStyleValue.left, FloatStyleValue.right:
				ret = true;
			
			case FloatStyleValue.none:
				ret = false;
		}
		
		return ret;
	}
	
	public function isInline():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.display) 
		{
			case _inline, inlineBlock:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	public function isPositioned():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.position) 
		{
			case relative, absolute, fixed:
				ret = true;
			
			case _static:
				ret = false;
		}
		
		return ret;
	}
	
	public function isRelativePositioned():Bool
	{
		return this._computedStyle.position == relative;
	}
	
	public function getComputedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
	public function setComputedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _computedStyle = value;
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function getMarginLeft():MarginStyleValue 
	{
		return _marginLeft;
	}
	
	private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		return _marginLeft = value;
	}
	
	
	private function getMarginRight():MarginStyleValue 
	{
		return _marginRight;
	}
	
	private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		return _marginRight = value;
	}
	
	
	private function getMarginTop():MarginStyleValue 
	{
		return _marginTop;
	}
	
	private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		return _marginTop = value;
	}
	
	
	private function getMarginBottom():MarginStyleValue 
	{
		return _marginBottom;
	}
	
	private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		return _marginBottom = value;
	}
	
	
	private function getPaddingLeft():PaddingStyleValue 
	{
		return _paddingLeft;
	}
	
	private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		return _paddingLeft = value;
	}
	
	private function getPaddingRight():PaddingStyleValue 
	{
		return _paddingRight;
	}
	
	private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		return _paddingRight = value;
	}
	
	private function getPaddingTop():PaddingStyleValue 
	{
		return _paddingTop;
	}
	
	private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		return _paddingTop = value;
	}
	
	private function getPaddingBottom():PaddingStyleValue 
	{
		return _paddingBottom;
	}
	
	private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		return _paddingBottom = value;
	}
	
		private function getDisplay():DisplayStyleValue 
	{
		return _display;
	}
	
	private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		return _display = value;
	}
	
	private function getPosition():PositionStyleValue 
	{
		return _position;
	}
	
	private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		return _position = value;
	}
	
	
	private function getWidth():DimensionStyleValue 
	{
		return _width;
	}
	
	private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		return _width = value;
	}
	
	
	private function getHeight():DimensionStyleValue 
	{
		return _height;
	}
	
	private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		return _height = value;
	}
	
	
	private function getMinHeight():ConstrainedDimensionStyleValue 
	{
		return _minHeight;
	}
	
	private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		return _minHeight = value;
	}
	
	
	private function getMaxHeight():ConstrainedDimensionStyleValue 
	{
		return _maxHeight;
	}
	
	private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		return _maxHeight = value;
	}
	
	
	private function getMinWidth():ConstrainedDimensionStyleValue 
	{
		return _minWidth;
	}
	
	private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		return _minWidth = value;
	}
	
	
	private function getMaxWidth():ConstrainedDimensionStyleValue 
	{
		return _maxWidth;
	}
	
	private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		return _maxWidth = value;
	}
	
		private function getTop():PositionOffsetStyleValue 
	{
		return _top;
	}
	
	private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		return _top = value;
	}
	
	
	private function getLeft():PositionOffsetStyleValue 
	{
		return _left;
	}
	
	private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		return _left = value;
	}
	
	private function getBottom():PositionOffsetStyleValue 
	{
		return _bottom;
	}
	
	private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		return _bottom = value;
	}
	
	private function getRight():PositionOffsetStyleValue 
	{
		return _right;
	}
	
	private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		return _right = value;
	}
	
	private function getFloat():FloatStyleValue 
	{
		return _float;
	}
	
	private function setFloat(value:FloatStyleValue):FloatStyleValue 
	{
		return _float = value;
	}
	
	private function getClear():ClearStyleValue 
	{
		return _clear;
	}
	
	private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		return _clear = value;
	}
}