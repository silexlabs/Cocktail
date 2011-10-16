package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.FloatBoxComputer;
import cocktail.style.computer.InlineBlockBoxComputer;
import cocktail.style.computer.InLineBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.computer.PositionComputer;
import cocktail.style.computer.PositionedBoxComputer;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * This is the base class for all Style classes. Style classes
 * are in charge of storing the style value for a DOMElement
 * and applying them when neccessary.
 * 
 * This class holds a reference to the targeted DOMElement
 * 
 * 
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
	public var domElement(getDOMElement, never):DOMElement;
	
	/**
	 * Class constructor. Stores the target DOMElement and init
	 * the computed styles structure with default values
	 */
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The main layout method. When called, the DOMElement's box
	 * model styles (width, height, margins, paddings...) are computed
	 * and the DOMElement layout its children if it has any.
	 * 
	 * @param	containingDOMElementDimensions the dimensions of the parent DOMElement into which 
	 * this DOMElement must be layout
	 * @param	lastPositionedDOMElement a reference to the last DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' other than 'static'. When positioning an absolutelty positioned DOMElement ( a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	rootDOMElement a reference to the DOMElement at the top of the hierarchy. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 */
	public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		//abstract
	}
	
	/**
	 * This method is in charge of placing "in-flow" DOMElements (DOMElement with a 'position' style of 'static' or 'relative') into
	 * its parent flow. The flow may be a block flow, in which each DOMElement is placed below the preceding DOMElement or an
	 * inline flow where the DOMElement are arranged in lines, and placed either next to the preceding DOMElement or on a
	 * new line below.
	 * 
	 * This method is called recursively if the DOMElement has children
	 * 
	 * 
	 * @param	containingDOMElementDimensions the dimensions of the parent DOMElement into which 
	 * this DOMElement must be layout
	 * @param	formatingContext
	 * @param	initialContainer
	 */
	public function flow(containingDOMElementDimensions:ContainingDOMElementDimensions, formatingContext:FormattingContext = null, initialContainer:Bool = false):Void
	{
	
		computePositionStyle();
		
		computeBoxModelStyle(containingDOMElementDimensions);
		
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
	
	
	/**
	 * This method computes the styles determing
	 * the DOMElement's layout scheme :
	 * position, display, float, clear
	 */
	public function computePositionStyle():Void
	{
		this._computedStyle = PositionComputer.compute(this);
	}
	
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of this
	 * DOMElement by instantiating the right box model computer class
	 */ 
	public function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		var boxComputer:BoxComputer;
		
		if (isFloat() == true)
		{
			boxComputer = new FloatBoxComputer();
		}
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new PositionedBoxComputer();
		}
		else
		{
			switch(this._computedStyle.display)
			{
				case block:
					boxComputer = new BlockBoxComputer();
					
				case inlineBlock:
					boxComputer = new InlineBlockBoxComputer();
				
				case none:
					boxComputer = new NoneBoxComputer();
				
				case _inline:
					boxComputer = new InLineBoxComputer();
			}
		}
		
		//compute the styles, the results are stored in the computed styles
		//structure
		boxComputer.measure(this, containingDOMElementDimensions);
	}
	
	public function positionElement(lastPositionnedDOMElement:DOMElement, rootDOMElement:DOMElement):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the DOMElement introduces
	 * 'clearance', which as the effect of placing
	 * the DOMElement below any preceding floated
	 * DOMElement. A DOMElement introduces clearance
	 * if he clears either left or right floats
	 * or both
	 */
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
	
	/**
	 * Determine if the DOMElement is a floated
	 * DOMElement. A floated DOMElement is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its container.
	 * Any subsequent inline DOMElement flows
	 * around on the float until a new line 
	 * starts below the float or if it is cleared
	 * by another DOMElement.
	 * 
	 * A DOMElement is float if he declares either
	 * a left or right float
	 */
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
	
	/**
	 * An inline DOMElement is one that is
	 * layout on a line. It will be placed
	 * either next to the precending DOMElement
	 * or on a new line if the current line
	 * is too short to host it.
	 * 
	 * Wheter an element is inline is determined
	 * by the display style
	 */
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
	
	/**
	 * A positioned element is one that 
	 * is positioned outside of the normal
	 * flow.
	 * 
	 * The 'relative', 'absolute' and'fixed'
	 * values of the 'position' style makes
	 * a DOMElement 'positioned'. 
	 * 
	 * The 'absolute' and 'fixed' value make
	 * a DOMElement an 'absolutely positioned'
	 * DOMElement. This kind of DOMElement
	 * doesn't affect the normal flow (it is
	 * treated as if it doesn't exist). It
	 * uses as origin its first ancestor
	 * which is also positioned
	 * 
	 * See below for the 'relative' value
	 */
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
	
	/**
	 * Determine wether a DOMElement has
	 * the 'position' value 'relative'.
	 * 
	 * A 'relative' DOMElement is first placed
	 * normally in the flow then an offset is 
	 * applied to it with the top, left, right
	 * and bottom style.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * DOMElement is found
	 */
	public function isRelativePositioned():Bool
	{
		return this._computedStyle.position == relative;
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	public function getComputedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
	public function getDOMElement():DOMElement
	{
		return this._domElement;
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