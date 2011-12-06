/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.domElement.DOMElement;
import cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.computer.DisplayStylesComputer;
import cocktailCore.style.computer.FontAndTextStylesComputer;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.positioner.AbsolutePositioner;
import cocktailCore.style.positioner.BoxPositioner;
import cocktailCore.style.positioner.FixedPositioner;
import cocktailCore.style.positioner.RelativePositioner;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import haxe.Log;
import haxe.Timer;

/**
 * This is the base class for all Style classes. Style classes
 * are in charge of storing the style value for a DOMElement
 * and applying them when neccessary.
 * 
 * This class holds a reference to the styled DOMElement
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
	* The way a DOMElement is laid out in a document (as block,
	* inline...)
	*/
	private var _display:DisplayStyleValue;
	public var display(getDisplay, setDisplay):DisplayStyleValue;
	
	/**
	* The way a DOMElement is positionned
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
	 * The way an element is aligned vertically in an 
	 * inline formatting context
	 */
	private var _verticalAlign:VerticalAlignStyleValue;
	public var verticalAlign(getVerticalAlign, setVerticalAlign):VerticalAlignStyleValue;
	
	/**
	 * float positioning styles. A floated element is placed to 
	 * the further left or right inside its container
	 */
	private var _float:FloatStyleValue;
	public var float(getFloat, setFloat):FloatStyleValue;
	private var _clear:ClearStyleValue;
	public var clear(getClear, setClear):ClearStyleValue;
	
	/**
	 * font styles
	 */
	private var _fontSize:FontSizeStyleValue;
	public var fontSize(getFontSize, setFontSize):FontSizeStyleValue;
	
	private var _fontWeight:FontWeightStyleValue;
	public var fontWeight(getFontWeight, setFontWeight):FontWeightStyleValue;
	
	private var _fontStyle:FontStyleStyleValue;
	public var fontStyle(getFontStyle, setFontStyle):FontStyleStyleValue;
	
	private var _fontFamily:Array<FontFamilyStyleValue>;
	public var fontFamily(getFontFamily, setFontFamily ):Array<FontFamilyStyleValue>;
	
	private var _fontVariant:FontVariantStyleValue;
	public var fontVariant(getFontVariant, setFontVariant):FontVariantStyleValue;
	
	private var _color:ColorValue;
	public var color(getColor, setColor):ColorValue;
	
	/**
	 * text styles
	 */
	private var _lineHeight:LineHeightStyleValue;
	public var lineHeight(getLineHeight, setLineHeight):LineHeightStyleValue;
	
	private var _textTransform:TextTransformStyleValue;
	public var textTransform(getTextTransform, setTextTransform):TextTransformStyleValue;
	
	private var _letterSpacing:LetterSpacingStyleValue;
	public var letterSpacing(getLetterSpacing, setLetterSpacing):LetterSpacingStyleValue;
	
	private var _wordSpacing:WordSpacingStyleValue;
	public var wordSpacing(getWordSpacing, setWordSpacing):WordSpacingStyleValue;
	
	private var _whiteSpace:WhiteSpaceStyleValue;
	public var whiteSpace(getWhiteSpace, setWhiteSpace):WhiteSpaceStyleValue;
	
	private var _textAlign:TextAlignStyleValue;
	public var textAlign(getTextAlign, setTextAlign):TextAlignStyleValue;
	
	private var _textIndent:TextIndentStyleValue;
	public var textIndent(getTextIndent, setTextIndent):TextIndentStyleValue;
	
	////////////////////////////////
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	private var _computedStyle:ComputedStyleData;
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyleData;
	
	/**
	 * A reference to the DOMElement to which these styles
	 * apply
	 */
	private var _domElement:DOMElement;
	public var domElement(getDOMElement, never):DOMElement;
	
	/**
	 * Returns metrics info for the currently defined
	 * font and font size. Uused in inline formatting context
	 * to determine lineBoxes sizes and text vertical
	 * alignement
	 */
	private var _fontMetrics:FontMetricsData;
	public var fontMetrics(getFontMetricsData, never):FontMetricsData;
	
	/**
	 * determine wether the DOMElement and its chidlren must
	 * be laid out again
	 */
	private var _isInvalid:Bool;
	
	/**
	 * Class constructor. Stores the target DOMElement.
	 */
	public function new(domElement:DOMElement) 
	{
		this._domElement = domElement;
		this._isInvalid = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The main layout method. When called, the DOMElement's styles (width, height, margins, paddings...)
	 * are computed, the DOMElement layout its children if it has any then add himself
	 * to the layout.
	 * 
	 * @param	containingDOMElementData the dimensions of the parent DOMElement into which 
	 * this DOMElement must be layout
	 * @param	lastPositionedDOMElementDimensions the dimensions of the first ancestor DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' style other than 'static'. When positioning an absolutelty positioned DOMElement (a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	rootDOMElementDimensions a reference to the DOMElement at the top of the hierarchy. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 * @param containingDOMElementFontMetricsData contains font metrics used to layout children in an inline formatting context
	 */
	public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		//abstract
	}
	
	/**
	 * This method is in charge of placing "in-flow" DOMElements (DOMElement with a 'position' style of 'static' or 'relative') into
	 * its parent flow and "positioned" DOMElement (with a 'position' style of 'absolute' or 'fixed') relatively to its first positioned
	 * ancestor.
	 * 
	 * The DOMElement first compute its own styles (box model, font, text...), then insert itself into the document based 
	 * on its positioning scheme.
	 * 
	 * This method is called recursively on every children of the DOMElement if it has any
	 * 
	 * @param	containingDOMElementData the dimensions of the parent DOMElement into which 
	 * this DOMElement must be laid out
	 * @param	rootDOMElementDimensions a reference to the DOMElement at the top of the hierarchy. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 * @param	lastPositionedDOMElementDimensions the dimensions of the first ancestor DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' other than 'static'. When laying out an absolutelty positioned DOMElement ( a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param   containingDOMElementFontMetricsData contains font metrics used to layout children in an inline formatting context
	 * @param	formatingContext can be an inline or block formatting context. "In-flow" DOMElements insert themselves into the 
	 * formatingContext to be placed in the document flow
	 */
	public function flow(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
	{
		//do nothing if the DOMElement must not be displayed
		if (isNotDisplayed() == true)
		{
			//hide the DOMElement
			this._domElement.isVisible = false;
			return;
		}
		else
		{
			this._domElement.isVisible = true;
		}
		
		//clear preceding left floats, right floats
		//or both
		if (isClear() == true)
		{
			formatingContext.clearFloat(this._computedStyle.clear, isFloat());
		}
		
		//compute all the styles of a DOMElement
		computeDOMElement(containingDOMElementData, rootDOMElementDimensions, lastPositionedDOMElementDimensions, containingDOMElementFontMetricsData);
		
		//flow all the children of the DOMElement if it has any, then insert the DOMElement in the document
		flowChildren(containingDOMElementData, rootDOMElementDimensions, lastPositionedDOMElementDimensions, containingDOMElementFontMetricsData, formatingContext);
		
		//apply the computed dimensions to the DOMElement
		applyComputedHeight(this._domElement, this._computedStyle.height);
		applyComputedWidth(this._domElement, this._computedStyle.width);
		
		this._isInvalid = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC DIMENSION AND POSITION METHODS
	// Those method actually apply a processed dimension or position value to 
	// the NativeElement of a target DOMElement.
	// they are runtime specific
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function applyComputedX(domElement:DOMElement, x:Int):Void
	{
		//abstract
	}
	
	public function applyComputedY(domElement:DOMElement, y:Int):Void
	{
		//abstract
	}
	
	public function applyComputedWidth(domElement:DOMElement, width:Int):Void
	{
		//abstract
	}
	
	public function applyComputedHeight(domElement:DOMElement, height:Int):Void
	{
		//abstract
	}
	
	/**
	 * Return the x of the NativeElement of the
	 * target DOMElement
	 */
	public function getComputedX(domElement:DOMElement):Int
	{
		return 0;
	}
	
	/**
	 * Return the y of the NativeElement of the
	 * target DOMElement
	 */
	public function getComputedY(domElement:DOMElement):Int
	{
		return 0;
	}
	
	/**
	 * Return the width of the NativeElement of the
	 * target DOMElement
	 */
	public function getComputedWidth(domElement:DOMElement):Int
	{
		return 0;
	}
	
	/**
	 * Return the height of the NativeElement of the
	 * target DOMElement
	 */
	public function getComputedHeight(domElement:DOMElement):Int
	{
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function invalidate():Void
	{
		if (this._isInvalid == false)
		{
			this._isInvalid = true;
			
			if (this._domElement.parent != null)
			{
				this._domElement.parent.style.invalidate();	
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function invalidateText():Void
	{
		_fontMetrics = null;
		invalidate();
	}
	
	private function invalidatePositionOffset():Void
	{
		/**if (this.position != staticStyle)
		{
			invalidate();
		}*/
		invalidate();
	}
	
	private function invalidateMargin():Void
	{
		/**if (this.position == relative || this.position == staticStyle)
		{
			invalidate();
		}*/
		invalidate();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Flow all the children of a DOMElement if it has any, then insert the DOMElement.
	 */
	private function flowChildren(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null ):Void
	{
		//insert the DOMElement in the document based on its positioning scheme
		insertDOMElement(formatingContext, lastPositionedDOMElementDimensions, rootDOMElementDimensions);
	}
	
	/**
	 * Place a positioned DOMElement (with a position of 'relative', 'absolute', or 'fixed') using either the normal
	 * flow, the last positioned DOMElement or the root of the document, then apply an offset defined by the 'top',
	 * 'left', 'bottom' and 'right' computed styles values
	 */
	private function positionElement(lastPositionedDOMElementDimensions:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData):Void
	{
		//instantiate the right positioner
		//class based on the value of the 'position' style
		var positioner:BoxPositioner;
		
		//'relative' positioned DOMElement
		if (this.isRelativePositioned() == true)
		{
			positioner = new RelativePositioner();
			positioner.position(this._domElement, lastPositionedDOMElementDimensions);
		}
		else
		{
			switch (this._domElement.style.computedStyle.position)
			{
				//positioned 'fixed' DOMElement
				case fixed:
					positioner = new FixedPositioner();
					
					/**
					 * TO DO : remove the x and y scroll from the root dom element dimensions
					 * so that it seems to stay at the same place in the window
					 */
					var scrolledRootDOMElementDimensions:ContainingDOMElementData = rootDOMElementDimensions;
					
					positioner.position(this._domElement, scrolledRootDOMElementDimensions);
					
				//positioned 'absolute' DOMElement	
				case absolute:
					positioner = new AbsolutePositioner();
					positioner.position(this._domElement, lastPositionedDOMElementDimensions);
					
				default:	
					positioner = new AbsolutePositioner();
			}
		}
	}
	
	/**
	 * Insert the DOMElement in the document, in or out of the flow.
	 * Might clear preceding floats
	 * 
	 * @param	formatingContext
	 * @param	lastPositionedDOMElementDimensions
	 * @param	rootDOMElementDimensions
	 */
	private function insertDOMElement(formattingContext:FormattingContext, lastPositionedDOMElementDimensions:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData):Void
	{
		//insert as a float
		if (isFloat() == true)
		{
			formattingContext.insertFloat(this._domElement);
		}
		//insert in the flow
		else if (isPositioned() == false)
		{
			insertInFlowDOMElement(formattingContext);
			
		}
		//insert in the flow, then apply an offset to it
		else if (isRelativePositioned() == true)
		{
			insertInFlowDOMElement(formattingContext);
			positionElement(lastPositionedDOMElementDimensions, rootDOMElementDimensions);
		}
		//insert as an absolutely positioned DOMElement
		else
		{ 
			positionElement(lastPositionedDOMElementDimensions, rootDOMElementDimensions);
		}
	}
	
	/**
	 * Do insert an inflow DOMElement into the document. Method added to allow
	 * overriding for some inherithing class
	 */
	private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{
		formattingContext.insert(this._domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute first the styles determining the DOMElement's
	 * positioning scheme (position, float, clear...),
	 * the styles determining its box model (width, height, margins
	 * paddings...), and the styles styling the DOMElement text and
	 * font style
	 */
	public function computeDOMElement(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		computeDisplayStyles();
		computeTextAndFontStyles(containingDOMElementData, containingDOMElementFontMetricsData);
		computeBoxModelStyles(containingDOMElementData, rootDOMElementDimensions, lastPositionedDOMElementDimensions);
		
	}
	
	/**
	 * This method computes the styles determing
	 * the DOMElement's layout scheme :
	 * position, display, float and clear
	 */
	public function computeDisplayStyles():Void
	{
		DisplayStylesComputer.compute(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Computes the DOMElement font and text styles (font size, font name, text color...)
	 */
	private function computeTextAndFontStyles(containingDOMElementData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		FontAndTextStylesComputer.compute(this, containingDOMElementData, containingDOMElementFontMetricsData);
	}
	
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the DOMElement, based on
	 * its positioning scheme
	 */ 
	private function computeBoxModelStyles(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//get the right containing dimensions. For example,
		//for a DOMElement with a 'position' style of 'absolute',
		//it is the last positioned DOMElement
		var containingBlockDimensions:ContainingDOMElementData = getContainingDOMElementData(containingDOMElementData, rootDOMElementDimensions, lastPositionedDOMElementDimensions );
		
		//do compute the box model styles
		boxComputer.measure(this, containingBlockDimensions);
	}
	
	/**
	 * instantiate the right box computer class
	 *	based on the DOMElement's positioning
	 *	scheme
	 */
	private function getBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
				
		//get the box computer for float
		if (isFloat() == true)
		{
			boxComputer = new FloatBoxStylesComputer();
		}
		
		//get it for DOMElement with 'position' value of 'absolute' or 'fixed'
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new PositionedBoxStylesComputer();
		}
		
		//else get the box computer based on the display style
		else
		{
			switch(this._computedStyle.display)
			{
				case block:
					boxComputer = new BlockBoxStylesComputer();
					
				case inlineBlock:
					boxComputer = new InlineBlockBoxStylesComputer();
				
				case none:
					boxComputer = new NoneBoxStylesComputer();
				
				case inlineStyle:
					boxComputer = new InLineBoxStylesComputer();
			}
		}
		
		return boxComputer;
	}
	
	/**
	 * Get the right containing parent dimensions for a DOMElement
	 * based on its position style value
	 */
	private function getContainingDOMElementData(containingDOMElementData:ContainingDOMElementData, rootDOMElementDimensions:ContainingDOMElementData, lastPositionedDOMElementDimensions:ContainingDOMElementData):ContainingDOMElementData
	{
		var containingBlockDimensions:ContainingDOMElementData;
		
		//for 'positioned' DOMElement
		if (isPositioned() == true)
		{
			//for 'fixed' DOMElement, takes the root DOMElement (the first DOMElement in the hierarchy)
			if (this._computedStyle.position == PositionStyleValue.fixed)
			{
				containingBlockDimensions = {
					width:rootDOMElementDimensions.width,
					height:rootDOMElementDimensions.height,
					isHeightAuto:rootDOMElementDimensions.isHeightAuto,
					isWidthAuto:rootDOMElementDimensions.isWidthAuto,
					globalX:rootDOMElementDimensions.globalX,
					globalY:rootDOMElementDimensions.globalY};
			}
			//for 'absolute' takes the first positioned ancestor
			else if (this._computedStyle.position == PositionStyleValue.absolute)
			{
				containingBlockDimensions = {
					width:lastPositionedDOMElementDimensions.width,
					height:lastPositionedDOMElementDimensions.height,
					isHeightAuto:lastPositionedDOMElementDimensions.isHeightAuto,
					isWidthAuto:lastPositionedDOMElementDimensions.isWidthAuto,
					globalX:lastPositionedDOMElementDimensions.globalX,
					globalY:lastPositionedDOMElementDimensions.globalY};
			}
			//else for 'relative', takes the parent as 'relative' are "in-flow" DOMElements
			else
			{
				containingBlockDimensions = containingDOMElementData;
			}
		}
		//else, for not 'positioned' DOMElement, takes the containing DOMElement dimensions which is the parent
		else
		{
			containingBlockDimensions = containingDOMElementData;
		}
		
		return containingBlockDimensions;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine if the DOMElement is an embeded (replaced)
	 * DOMElement. For example an ImageDOMElement is an
	 * embedded DOMElement as it embeds a picture in the
	 * document
	 */
	public function isEmbedded():Bool
	{
		return false;
	}
	
	/**
	 * Determine if the DOMElement is a floated
	 * DOMElement. A floated DOMElement is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its container.
	 * Any subsequent DOMElement flows
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the DOMElement introduces
	 * 'clearance', which as the effect of placing
	 * the DOMElement below any preceding floated
	 * DOMElement. A DOMElement introduces clearance
	 * if he clears either left floats, right floats
	 * or both
	 */
	private function isClear():Bool
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
	 * Determine wether the DOMElement is added
	 * to the document
	 */
	private function isNotDisplayed():Bool
	{
		return this._computedStyle.display == DisplayStyleValue.none;
	}
	
	/**
	 * An inline DOMElement is one that is
	 * laid out on a line. It will be placed
	 * either next to the preceding DOMElement
	 * or on a new line if the current line
	 * is too short to host it.
	 * 
	 * Wheter an element is inline is determined
	 * by the display style
	 */
	private function isInline():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.display) 
		{
			case inlineStyle, inlineBlock:
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
	private function isPositioned():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.position) 
		{
			case relative, absolute, fixed:
				ret = true;
			
			case staticStyle:
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
	 * and bottom computed styles.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * DOMElement is found
	 */
	private function isRelativePositioned():Bool
	{
		return this._computedStyle.position == relative;
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	private function getFontMetricsData():FontMetricsData
	{
		return _fontMetrics;
	}
	
	private function getComputedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
	private function setComputedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _computedStyle = value;
	}
	
	private function getDOMElement():DOMElement
	{
		return this._domElement;
	}
	
	/////////////////////////////////
	// INVALIDATING STYLES SETTERS
	// setting one of those style will 
	// cause a layout
	////////////////////////////////
	
	private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		invalidate();
		return _width = value;
	}
	
	private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		invalidateMargin();
		return _marginLeft = value;
	}
	
	private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		invalidateMargin();
		return _marginRight = value;
	}
	
	private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		invalidateMargin();
		return _marginTop = value;
	}
	
	private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		invalidateMargin();
		return _marginBottom = value;
	}
	
	private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		invalidate();
		return _paddingLeft = value;
	}
	
	private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		invalidate();
		return _paddingRight = value;
	}
	
	private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		invalidate();
		return _paddingTop = value;
	}
	
	private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		invalidate();
		return _paddingBottom = value;
	}
	
	private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		invalidate();
		return _display = value;
	}
	
	private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		invalidate();
		return _position = value;
	}
	
	private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		invalidate();
		return _height = value;
	}
	
	private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		invalidate();
		return _minHeight = value;
	}
	
	private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		invalidate();
		return _maxHeight = value;
	}
	
	private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		invalidate();
		return _minWidth = value;
	}
	
	private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		invalidate();
		return _maxWidth = value;
	}
	
	private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		invalidatePositionOffset();
		return _top = value;
	}
	
	private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		invalidatePositionOffset();
		return _left = value;
	}
	
	private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		invalidatePositionOffset();
		return _bottom = value;
	}
	
	private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		invalidatePositionOffset();
		return _right = value;
	}
	
	private function setFloat(value:FloatStyleValue):FloatStyleValue 
	{
		invalidate();
		return _float = value;
	}
	
	private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		invalidate();
		return _clear = value;
	}
	
	private function setFontSize(value:FontSizeStyleValue):FontSizeStyleValue
	{
		_fontSize = value;
		invalidateText();
		return _fontSize;
	}
	
	private function setFontWeight(value:FontWeightStyleValue):FontWeightStyleValue
	{
		invalidateText();
		return _fontWeight = value;
	}
	
	private function setFontStyle(value:FontStyleStyleValue):FontStyleStyleValue
	{
		invalidateText();
		return _fontStyle = value;
	}
	
	private function setFontFamily(value:Array<FontFamilyStyleValue>):Array<FontFamilyStyleValue>
	{
		invalidateText();
		return _fontFamily = value;
	}
	
	private function setFontVariant(value:FontVariantStyleValue):FontVariantStyleValue
	{
		invalidateText();
		return _fontVariant = value;
	}
	
	private function setTextTransform(value:TextTransformStyleValue):TextTransformStyleValue
	{
		invalidateText();
		return _textTransform = value;
	}
	
	private function setLetterSpacing(value:LetterSpacingStyleValue):LetterSpacingStyleValue
	{
		invalidateText();
		return _letterSpacing = value;
	}
	
	private function setWordSpacing(value:WordSpacingStyleValue):WordSpacingStyleValue
	{
		invalidate();
		return _wordSpacing = value;
	}
	
	private function setLineHeight(value:LineHeightStyleValue):LineHeightStyleValue
	{
		invalidate();
		return _lineHeight = value;
	}
	
	private function setVerticalAlign(value:VerticalAlignStyleValue):VerticalAlignStyleValue
	{
		invalidate();
		return _verticalAlign = value;
	}
	
	private function setTextIndent(value:TextIndentStyleValue):TextIndentStyleValue
	{
		invalidate();
		return _textIndent = value;
	}
	
	private function setWhiteSpace(value:WhiteSpaceStyleValue):WhiteSpaceStyleValue
	{
		invalidate();
		return _whiteSpace = value;
	}
	
	private function setTextAlign(value:TextAlignStyleValue):TextAlignStyleValue
	{
		invalidate();
		return _textAlign = value;
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function getMarginLeft():MarginStyleValue 
	{
		return _marginLeft;
	}
	
	private function getMarginRight():MarginStyleValue 
	{
		return _marginRight;
	}
	
	private function getMarginTop():MarginStyleValue 
	{
		return _marginTop;
	}
	
	private function getMarginBottom():MarginStyleValue 
	{
		return _marginBottom;
	}
	
	private function getPaddingLeft():PaddingStyleValue 
	{
		return _paddingLeft;
	}
	
	private function getPaddingRight():PaddingStyleValue 
	{
		return _paddingRight;
	}
	
	private function getPaddingTop():PaddingStyleValue 
	{
		return _paddingTop;
	}
	
	private function getPaddingBottom():PaddingStyleValue 
	{
		return _paddingBottom;
	}
	
	private function getDisplay():DisplayStyleValue 
	{
		return _display;
	}
	
	private function getPosition():PositionStyleValue 
	{
		return _position;
	}
	
	private function getWidth():DimensionStyleValue 
	{
		return _width;
	}
	
	private function getHeight():DimensionStyleValue 
	{
		return _height;
	}
	
	private function getMinHeight():ConstrainedDimensionStyleValue 
	{
		return _minHeight;
	}
	
	private function getMaxHeight():ConstrainedDimensionStyleValue 
	{
		return _maxHeight;
	}
	
	private function getMinWidth():ConstrainedDimensionStyleValue 
	{
		return _minWidth;
	}
	
	private function getMaxWidth():ConstrainedDimensionStyleValue 
	{
		return _maxWidth;
	}
	
	private function getTop():PositionOffsetStyleValue 
	{
		return _top;
	}
	
	private function getLeft():PositionOffsetStyleValue 
	{
		return _left;
	}
	
	private function getBottom():PositionOffsetStyleValue 
	{
		return _bottom;
	}
	
	private function getRight():PositionOffsetStyleValue 
	{
		return _right;
	}
	
	private function getFloat():FloatStyleValue 
	{
		return _float;
	}
	
	private function getClear():ClearStyleValue 
	{
		return _clear;
	}
	
	private function getFontSize():FontSizeStyleValue
	{
		return _fontSize;
	}
	
	private function getFontWeight():FontWeightStyleValue
	{
		return _fontWeight;
	}
	
	private function getFontStyle():FontStyleStyleValue
	{
		return _fontStyle;
	}
	
	private function getFontFamily():Array<FontFamilyStyleValue>
	{
		return _fontFamily;
	}
	
	private function getFontVariant():FontVariantStyleValue
	{
		return _fontVariant;
	}
	
	private function getTextTransform():TextTransformStyleValue
	{
		return _textTransform;
	}
	
	private function getLetterSpacing():LetterSpacingStyleValue
	{
		return _letterSpacing;
	}
	
	private function setColor(value:ColorValue):ColorValue
	{
		return _color = value;
	}
	
	private function getColor():ColorValue
	{
		return _color;
	}
	
	private function getWordSpacing():WordSpacingStyleValue
	{
		return _wordSpacing;
	}
	
	private function getLineHeight():LineHeightStyleValue
	{
		return _lineHeight;
	}
	
	private function getVerticalAlign():VerticalAlignStyleValue
	{
		return _verticalAlign;
	}
	
	private function getTextIndent():TextIndentStyleValue
	{
		return _textIndent;
	}
	
	private function getWhiteSpace():WhiteSpaceStyleValue
	{
		return _whiteSpace;
	}
	
	private function getTextAlign():TextAlignStyleValue
	{
		return _textAlign;
	}
}