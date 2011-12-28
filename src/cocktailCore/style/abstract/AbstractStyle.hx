/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.geom.Matrix;
import cocktail.viewport.Viewport;
import cocktailCore.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.computer.DisplayStylesComputer;
import cocktailCore.style.computer.FontAndTextStylesComputer;
import cocktailCore.style.computer.VisualEffectStylesComputer;
import cocktailCore.style.ContainerStyle;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.positioner.AbsolutePositioner;
import cocktailCore.style.positioner.BoxPositioner;
import cocktailCore.style.positioner.FixedPositioner;
import cocktailCore.style.positioner.RelativePositioner;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
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
	 * display styles
	 */
	private var _display:DisplayStyleValue;
	public var display(getDisplay, setDisplay):DisplayStyleValue;
	
	private var _position:PositionStyleValue;
	public var position(getPosition, setPosition):PositionStyleValue;
	
	private var _floatValue:FloatStyleValue;
	public var floatValue(getFloatValue, setFloatValue):FloatStyleValue;
	
	private var _clear:ClearStyleValue;
	public var clear(getClear, setClear):ClearStyleValue;
	
	private var _opacity:OpacityStyleValue;
	public var opacity(getOpacity, setOpacity):OpacityStyleValue;
	
	private var _visibility:VisibilityStyleValue;
	public var visibility(getVisibility, setVisibility):VisibilityStyleValue;
	
	private var _tranformOrigin:TransformOriginStyleData;
	public var transformOrigin(getTransformOrigin, setTransformOrigin):TransformOriginStyleData;
	
	private var _transform:TransformStyleValue;
	public var transform(getTransform, setTransform):TransformStyleValue;
	
	/**
	 * box model styles
	 */
	private var _marginLeft:MarginStyleValue;
	public var marginLeft(getMarginLeft, setMarginLeft):MarginStyleValue;
	private var _marginRight:MarginStyleValue;
	public var marginRight(getMarginRight, setMarginRight):MarginStyleValue;
	private var _marginTop:MarginStyleValue;
	public var marginTop(getMarginTop, setMarginTop):MarginStyleValue;
	private var _marginBottom:MarginStyleValue;
	public var marginBottom(getMarginBottom, setMarginBottom):MarginStyleValue;
	
	private var _paddingLeft:PaddingStyleValue;
	public var paddingLeft(getPaddingLeft, setPaddingLeft):PaddingStyleValue;
	private var _paddingRight:PaddingStyleValue;
	public var paddingRight(getPaddingRight, setPaddingRight):PaddingStyleValue;
	private var _paddingTop:PaddingStyleValue;
	public var paddingTop(getPaddingTop, setPaddingTop):PaddingStyleValue;
	private var _paddingBottom:PaddingStyleValue;
	public var paddingBottom(getPaddingBottom, setPaddingBottom):PaddingStyleValue;

	private var _width:DimensionStyleValue;
	public var width(getWidth, setWidth):DimensionStyleValue;
	private var _height:DimensionStyleValue;
	public var height(getHeight, setHeight):DimensionStyleValue;
	
	private var _minHeight:ConstrainedDimensionStyleValue;
	public var minHeight(getMinHeight, setMinHeight):ConstrainedDimensionStyleValue;
	private var _maxHeight:ConstrainedDimensionStyleValue;
	public var maxHeight(getMaxHeight, setMaxHeight):ConstrainedDimensionStyleValue;
	private var _minWidth:ConstrainedDimensionStyleValue;
	public var minWidth(getMinWidth, setMinWidth):ConstrainedDimensionStyleValue;
	private var _maxWidth:ConstrainedDimensionStyleValue;
	public var maxWidth(getMaxWidth, setMaxWidth):ConstrainedDimensionStyleValue;

	private var _top:PositionOffsetStyleValue;
	public var top(getTop, setTop):PositionOffsetStyleValue;
	private var _left:PositionOffsetStyleValue;
	public var left(getLeft, setLeft):PositionOffsetStyleValue;
	private var _bottom:PositionOffsetStyleValue;
	public var bottom(getBottom, setBottom):PositionOffsetStyleValue;
	private var _right:PositionOffsetStyleValue;
	public var right(getRight, setRight):PositionOffsetStyleValue;
	
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
		
	private var _verticalAlign:VerticalAlignStyleValue;
	public var verticalAlign(getVerticalAlign, setVerticalAlign):VerticalAlignStyleValue;
	
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
	 * Store the x position of the NativeElement
	 * relative to its parent
	 */
	private var _nativeX:Int;
	
	/**
	 * Store the y position of the NativeElement
	 * relative to its parent
	 */
	private var _nativeY:Int;
	
	/**
	 * Store the width of the NativeElement
	 */
	private var _nativeWidth:Int;
	
	/**
	 * Store the height of the NativeElement
	 */
	private var _nativeHeight:Int;
	
	/**
	 * Store the x scale of the NativeElement
	 */
	private var _nativeScaleX:Float;
	
	/**
	 * Store the y scale of the NativeElement
	 */
	private var _nativeScaleY:Float;
	
	/**
	 * Store the rotation of the NativeElement
	 */
	private var _nativeRotation:Float;
	
	/**
	 * Store the opacity of the NativeElement
	 */
	private var _nativeOpacity:Float;
	
	/**
	 * Store the visibility of the NativeElement
	 */
	private var _nativeVisibility:Bool;
	
	/**
	 * Store the current transform matrix of the NativeElement
	 */
	private var _nativeMatrix:Matrix;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Class constructor. Stores the target DOMElement.
	 * 
	 * The style is invalid by default and will be updated
	 * when the DOMElement is added to the DOM.
	 */
	public function new(domElement:DOMElement) 
	{
		this._domElement = domElement;
		this._isInvalid = true;
		initDefaultStyleValues();
	}
	
	/**
	 * Init the standard default value for styles
	 */
	private function initDefaultStyleValues():Void
	{
		initComputedStyles();
		initNativeProperties();
		
		this.width = DimensionStyleValue.autoValue;
		this.height = DimensionStyleValue.autoValue;
		
		this.minWidth = ConstrainedDimensionStyleValue.length(px(0));
		this.maxWidth = ConstrainedDimensionStyleValue.none;
		this.minHeight = ConstrainedDimensionStyleValue.length(px(0));
		this.maxHeight = ConstrainedDimensionStyleValue.none;
		
		this.marginTop = MarginStyleValue.length(px(0));
		this.marginBottom = MarginStyleValue.length(px(0));
		this.marginLeft = MarginStyleValue.length(px(0));
		this.marginRight = MarginStyleValue.length(px(0));
		
		this.paddingTop = PaddingStyleValue.length(px(0));
		this.paddingBottom = PaddingStyleValue.length(px(0));
		this.paddingLeft = PaddingStyleValue.length(px(0));
		this.paddingRight = PaddingStyleValue.length(px(0));
		
		this.lineHeight = LineHeightStyleValue.normal;
		this.verticalAlign = VerticalAlignStyleValue.baseline;
		
		this.display = DisplayStyleValue.inlineStyle;
		this.position = PositionStyleValue.staticStyle;
		
		this.top = PositionOffsetStyleValue.autoValue;
		this.bottom = PositionOffsetStyleValue.autoValue;
		this.left = PositionOffsetStyleValue.autoValue;
		this.right = PositionOffsetStyleValue.autoValue;
		
		this.floatValue = FloatStyleValue.none;
		this.clear = ClearStyleValue.none;
		
		this.fontStyle = FontStyleStyleValue.normal;
		this.fontVariant = FontVariantStyleValue.normal;
		this.fontWeight = FontWeightStyleValue.normal;
		this.fontSize = FontSizeStyleValue.absoluteSize(FontSizeAbsoluteSizeValue.medium);
		
		this.textIndent = TextIndentStyleValue.length(px(0));
		this.textAlign = TextAlignStyleValue.left;
		this.letterSpacing = LetterSpacingStyleValue.normal;
		this.wordSpacing = WordSpacingStyleValue.normal;
		this.textTransform = TextTransformStyleValue.none;
		this.whiteSpace = WhiteSpaceStyleValue.normal;
		
		this.visibility = VisibilityStyleValue.visible;
		this.opacity = OpacityStyleValue.number(1.0);
		
		this.transformOrigin = {
			x:TransformOriginXStyleValue.center,
			y:TransformOriginYStyleValue.center
		}
		
		this.transform = TransformStyleValue.none;
		
		var defaultStyles:DefaultStylesData = getDefaultStyle();
		this.fontFamily = defaultStyles.fontFamily;
		this.color = defaultStyles.color;
	}
	
	/**
	 * reset/init the computed style structures
	 */
	private function initComputedStyles():Void
	{
		 _computedStyle = {
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
			floatValue : FloatStyleValue.none,
			display : DisplayStyleValue.block,
			position: PositionStyleValue.staticStyle,
			verticalAlign : 0.0,
			fontSize:12.0,
			lineHeight:14.0,
			fontWeight:FontWeightStyleValue.normal,
			fontStyle:FontStyleStyleValue.normal,
			fontFamily:[FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.serif)],
			fontVariant:FontVariantStyleValue.normal,
			textTransform:TextTransformStyleValue.none,
			letterSpacing:0,
			wordSpacing:0,
			textIndent:0,
			whiteSpace:WhiteSpaceStyleValue.normal,
			textAlign:TextAlignStyleValue.left,
			color:0,
			visibility:true,
			opacity:1.0,
			transformOrigin: { x:0.0, y:0.0 },
			transform:new Matrix()
		};
	}
	
	/**
	 * init the values representing NativeElements attributes
	 */
	private function initNativeProperties():Void
	{
		_nativeHeight = 0;
		_nativeOpacity = 1.0;
		_nativeRotation = 0.0;
		_nativeScaleX = 1.0;
		_nativeScaleY = 1.0;
		_nativeVisibility = true;
		_nativeWidth = 0;
		_nativeX = 0;
		_nativeY = 0;
	}
	
	/**
	 * Return default value for style defined by the User Agent
	 * in a browser, those styles are hard coded for other
	 * runtimes
	 */
	private static function getDefaultStyle():DefaultStylesData
	{
		return {
			fontFamily:[FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.serif)],
			color:ColorValue.keyword(ColorKeywordValue.black)
		}
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
	 * @param	lastPositionedDOMElementData the dimensions of the first ancestor DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' style other than 'static'. When positioning an absolutelty positioned DOMElement (a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 * @param containingDOMElementFontMetricsData contains font metrics used to layout children in an inline formatting context
	 */
	public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
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
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 * @param	lastPositionedDOMElementData the dimensions of the first ancestor DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' other than 'static'. When laying out an absolutelty positioned DOMElement ( a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin. It also contains a reference to each absolutely positioned AbstractStyle using it as origin
	 * to position their DOMElement
	 * @param   containingDOMElementFontMetricsData contains font metrics used to layout children in an inline formatting context
	 * @param	formatingContext can be an inline or block formatting context. "In-flow" DOMElements insert themselves into the 
	 * formatingContext to be placed in the document flow
	 */
	public function flow(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
	{
		//do nothing if the DOMElement must not be displayed
		if (isNotDisplayed() == true)
		{
			//hide the DOMElement
			setNativeVisibility(false);
			return;
		}
		else
		{
			setNativeVisibility(true);
		}
		
		//clear preceding left floats, right floats
		//or both
		if (isClear() == true)
		{
			formatingContext.clearFloat(this._computedStyle.clear, isFloat());
		}

		//compute all the styles of a DOMElement
		computeDOMElement(containingDOMElementData, viewportData, lastPositionedDOMElementData.data, containingDOMElementFontMetricsData);
		
		//flow all the children of the DOMElement if it has any, then insert the DOMElement in the document
		flowChildren(containingDOMElementData, viewportData, lastPositionedDOMElementData, containingDOMElementFontMetricsData, formatingContext);
		
		//apply the computed dimensions to the DOMElement
		setNativeHeight(this._computedStyle.height);
		setNativeWidth(this._computedStyle.width);
		
		//when all the dimensions of the domElement are known, compute the 
		//visual effects to apply (visibility, opacity, transform)
		computeVisualEffectStyles();

		//apply the computed visual effects on the DOMElement
		setNativeMatrix(this._computedStyle.transform);
		setNativeOpacity(this._computedStyle.opacity);
		setNativeVisibility(this._computedStyle.visibility);
		
		//The DOMElement has been laid out and is now valid
		this._isInvalid = false;
	}
	
	/**
	 * Place a positioned DOMElement (with a position of 'relative', 'absolute', or 'fixed') using either the normal
	 * flow, the last positioned DOMElement or the viewport of the document, then apply an offset defined by the 'top',
	 * 'left', 'bottom' and 'right' computed styles values
	 */
	public function positionElement(lastPositionedDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, staticPosition:PointData):Void
	{
		//instantiate the right positioner
		//class based on the value of the 'position' style
		var positioner:BoxPositioner;
		
		//'relative' positioned DOMElement
		if (this.isRelativePositioned() == true)
		{
			positioner = new RelativePositioner();
			positioner.position(this._domElement, lastPositionedDOMElementData, staticPosition);
		}
		else
		{
			switch (this._domElement.style.computedStyle.position)
			{
				//positioned 'fixed' DOMElement
				case fixed:
					positioner = new FixedPositioner();
					positioner.position(this._domElement, viewportData, staticPosition);
					
				//positioned 'absolute' DOMElement	
				case absolute:
					positioner = new AbsolutePositioner();
					positioner.position(this._domElement, lastPositionedDOMElementData, staticPosition);
					
				default:	
					positioner = new AbsolutePositioner();
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a timer to trigger a layout of the DOMElement asynchronously. this method is used by the invalidation
	 * mechanism. Setting a timer to execute the layout ensure that the layout only happen once when a series of style
	 * value are set instead of happening for each changes.
	 */
	private function scheduleLayout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		var layoutDelegate:ContainingDOMElementData->LastPositionedDOMElementData->ContainingDOMElementData->FontMetricsData->Void = layout;
		
		Timer.delay(function () { 
			layoutDelegate(containingDOMElementData, lastPositionedDOMElementData, viewportData, null);
		}, 1);
	}
	
	/**
	 * Flow all the children of a DOMElement if it has any, then insert the DOMElement.
	 */
	private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null ):Void
	{
		//insert the DOMElement in the document based on its positioning scheme
		insertDOMElement(formatingContext, lastPositionedDOMElementData, viewportData);
	}
	
	/**
	 * Insert the DOMElement in the document, in or out of the flow.
	 * Might clear preceding floats
	 * 
	 * @param	formatingContext
	 * @param	lastPositionedDOMElementData
	 * @param	viewportData
	 */
	private function insertDOMElement(formattingContext:FormattingContext, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
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
		//else the DOMElement is positioned
		else
		{
			//retrieve the static position (the position of the DOMElement
			//if its position style was 'static'
			var x:Float = formattingContext.flowData.x;
			var y:Float = formattingContext.flowData.y;
			
			var staticPosition:PointData = {
				x:x,
				y:y
			}
			
			//insert in the flow, then apply an offset to it
			if (isRelativePositioned() == true)
			{
				insertInFlowDOMElement(formattingContext);
				positionElement(lastPositionedDOMElementData.data, viewportData, staticPosition);
			}
			//insert as an absolutely positioned DOMElement
			//an absolutely positioned DOMElement is not positioned right away, it must
			//wait for its first positioned ancestor to be laid out. The reason is that
			//if the positioned ancestor height is 'auto', the height of the positioned
			//ancestor is not yet determined and so this DOMElement can't be positioned
			//using the bottom style yet. Once the first ancestor is laid out, it
			//calls the positionElement method on all the stored children
			else
			{ 
			
				var positionedDOMElementData:PositionedDOMElementData = {
					staticPosition:staticPosition,
					style:this
				}
				lastPositionedDOMElementData.children.push(positionedDOMElementData);
			}
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
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the value of a style that require
	 * a layout (such as width, height, display...) is
	 * changed.
	 * 
	 * An invalidated DOMElement will in turn invalidate its
	 * parent and so on until the root DOMElement is invalidated.
	 * The root DOMElement will then layout itself, laying out
	 * at the same time all its invalidated children.
	 */
	public function invalidate():Void
	{
		//only invalidate the parent if it isn't
		//done already
		if (this._isInvalid == false)
		{
			//set the invalid flag to prevent multiple
			//invalidation of the DOMElement in a row
			//The DOMElement will be be able to be invalidated
			//again once it is laid out
			this._isInvalid = true;
			
			//if the DOMElement doesn't have a parent, then it
			//is not currently added to the DOM and doesn't require
			//a layout
			if (this._domElement.parent != null)
			{
				//invalidate its parent if it must
				if (isParentInvalid() == true)
				{
					this._domElement.parent.style.invalidate();	
				}
				//else schedule a layout for this DOMElement
				else
				{
					//retrieve its parent and the viewport dimension
					var parentStyle:ContainerStyle = cast(this._domElement.parent.style);
					var containingDOMElementData:ContainingDOMElementData = parentStyle.getContainerDOMElementData();
					
					var viewPortData:ContainingDOMElementData = getViewportData();
					
					//get the data of the first positinned ancestor of this styled DOMElement
					var lastPositionedDOMElementData:LastPositionedDOMElementData = {
						children: new Array<PositionedDOMElementData>(),
						data:getFirstPositionedAncestorData()
					}
					
					//schedule an asynchronous layout
					scheduleLayout(containingDOMElementData, lastPositionedDOMElementData, viewPortData);
				}
				
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	// Those method allow for
	// the re-layout of only a part of the DOM tree
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a style invalidating the text is called
	 * (font size, font weight...), the font metrics
	 * structure must be reseted so that it is re-created
	 * with updated values on next layout
	 */
	private function invalidateText():Void
	{
		_fontMetrics = null;
		invalidate();
	}
	
	/**
	 * When a position offset style changes (top, left, 
	 * right, bottom), it only requires a layout if the
	 * DOMElement is positioned (not static).
	 */
	private function invalidatePositionOffset():Void
	{
		if (this.position != staticStyle)
		{
			invalidate();
		}
	}
	
	/**
	 * When the margin style changes, if the DOMElement
	 * is absolutely positioned, there is no need for a layout
	 */
	private function invalidateMargin():Void
	{
		if (this.position == relative || this.position == staticStyle)
		{
			invalidate();
		}
	}
	
	/**
	 * Determine wheter the parent of the DOMElement needs
	 * to be invalidated too. In some caes, for instance
	 * if the DOMElement is absolutely positioned, invalidating
	 * its parent isn't necessary
	 */
	private function isParentInvalid():Bool
	{
		var ret:Bool = true;
		
		if (this.isPositioned() == true && this.isRelativePositioned() == false)
		{
			ret = false;
		}
		
		return ret;
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
	public function computeDOMElement(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		//reset the computed styles, useful for instance to
		//reset an auto height to 0 if a layout has already
		//occured which might create bugs in the computation of
		//font and text styles which use the computed height value
		initComputedStyles();
		
		computeDisplayStyles();
		computeTextAndFontStyles(containingDOMElementData, containingDOMElementFontMetricsData);
		computeBoxModelStyles(containingDOMElementData, viewportData, lastPositionedDOMElementData);
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
	 * Compute the visual effect styles (opacity, visibility, transformations)
	 */
	private function computeVisualEffectStyles():Void
	{
		VisualEffectStylesComputer.compute(this);
	}
	
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
	private function computeBoxModelStyles(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:ContainingDOMElementData):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//get the right containing dimensions. For example,
		//for a DOMElement with a 'position' style of 'absolute',
		//it is the last positioned DOMElement
		var containingBlockDimensions:ContainingDOMElementData = getContainingDOMElementData(containingDOMElementData, viewportData, lastPositionedDOMElementData );
		
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
	private function getContainingDOMElementData(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:ContainingDOMElementData):ContainingDOMElementData
	{
		var containingBlockDimensions:ContainingDOMElementData;
		
		//for 'positioned' DOMElement
		if (isPositioned() == true)
		{
			//for 'fixed' DOMElement, takes the viewport (the 'window' through which the document is viewed)
			if (this._computedStyle.position == PositionStyleValue.fixed)
			{
				containingBlockDimensions = {
					width:viewportData.width,
					height:viewportData.height,
					isHeightAuto:viewportData.isHeightAuto,
					isWidthAuto:viewportData.isWidthAuto,
					globalX:viewportData.globalX,
					globalY:viewportData.globalY};
			}
			//for 'absolute' takes the first positioned ancestor
			else if (this._computedStyle.position == PositionStyleValue.absolute)
			{
				containingBlockDimensions = {
					width:lastPositionedDOMElementData.width,
					height:lastPositionedDOMElementData.height,
					isHeightAuto:lastPositionedDOMElementData.isHeightAuto,
					isWidthAuto:lastPositionedDOMElementData.isWidthAuto,
					globalX:lastPositionedDOMElementData.globalX,
					globalY:lastPositionedDOMElementData.globalY};
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
		
		switch (this._computedStyle.floatValue) 
		{
			case FloatStyleValue.left, FloatStyleValue.right:
				ret = true;
			
			case FloatStyleValue.none:
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
			
			case staticStyle:
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
	
	/**
	 * Get the data (dimensions and positions) of the first ancestor
	 * of the styled DOMElement which is positioned
	 */
	private function getFirstPositionedAncestorData():ContainingDOMElementData
	{
		var firstPositionedAncestorData:ContainingDOMElementData;
		var parent:ContainerDOMElement = _domElement.parent;
		
		//if the domElement has a parent
		if (parent != null)
		{
			//loop in all the parents until a positioned or a null parent is found
			var isPositioned:Bool = parent.style.isPositioned();
			while (isPositioned == false)
			{
				if (parent.parent != null)
				{
					parent = parent.parent;
					isPositioned = parent.style.isPositioned();
				}
				//break the loop if the current parent has no parent
				else
				{
					isPositioned = true;
				}
				
			}
			//get the data of the parent
			var parentStyle:ContainerStyle = cast(parent.style);
			firstPositionedAncestorData = parentStyle.getContainerDOMElementData();
		}
		//if the DOMElement has no parent, return the viewport data
		else
		{
			firstPositionedAncestorData = getViewportData();
		}
		
		return firstPositionedAncestorData;
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * position is always to the top left of the window
	 */
	private function getViewportData():ContainingDOMElementData
	{
		var viewPort:Viewport = new Viewport();
					
		var viewPortData:ContainingDOMElementData = {
			globalX:0,
			globalY:0,
			isHeightAuto:false,
			isWidthAuto:false,
			width:viewPort.width,
			height:viewPort.height
		}
		
		return viewPortData;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// NATIVE SETTER/GETTER
	// Those method actually apply a processed value to 
	// the NativeElement of a target DOMElement.
	// They also store the applied value when it is set on the DOMElement
	// wrapped by this Style object. For instance, a ContainerStyle object not
	// only wraps a ContainerDOMElement but also every generated TextFragmentDOMElement.
	// The applied dimension or position is only stored when applied to the
	// ContainerDOMElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the x of the NativeElement of the
	 * target DOMElement
	 */
	public function setNativeX(domElement:DOMElement, x:Int):Void
	{
		if (domElement == this._domElement)
		{
			this._nativeX = x;
		}
	}
	
	/**
	 * Return the x of the NativeElement of the
	 * DOMElement
	 */
	public function getNativeX():Int
	{
		return this._nativeX;
	}
	
	/**
	 * Set the y of the NativeElement of the
	 * target DOMElement
	 */
	public function setNativeY(domElement:DOMElement, y:Int):Void
	{
		if (domElement == this._domElement)
		{
			this._nativeY = y;
		}
	}
	
	/**
	 * Return the y of the NativeElement of the
	 * DOMElement
	 */
	public function getNativeY():Int
	{
		return this._nativeY;
	}
	
	/**
	 * Set the width of the NativeElement of the
	 * target DOMElement
	 */
	public function setNativeWidth(width:Int):Void
	{
		this._nativeWidth = width;
	}
	
	/**
	 * Return the width of the NativeElement of the
	 * DOMElement
	 */
	public function getNativeWidth():Int
	{
		return this._nativeWidth;
	}	
	
	/**
	 * Set the height of the NativeElement of the
	 * target DOMElement
	 */
	public function setNativeHeight(height:Int):Void
	{
		this._nativeHeight = height;
	}
	
	/**
	 * Return the height of the NativeElement of the
	 * DOMElement
	 */
	public function getNativeHeight():Int
	{
		return this._nativeHeight;
	}
	
	/**
	 * Set the x scale of the NativeElement
	 */
	public function setNativeScaleX(scaleX:Float):Void
	{
		this._nativeScaleX = scaleX;
	}
	
	/**
	 * return the x scale of the NativeElement
	 */
	public function getNativeScaleX():Float
	{
		return this._nativeScaleX;
	}
	
	/**
	 * Set the y scale of the NativeElement
	 */
	public function setNativeScaleY(scaleY:Float):Void
	{
		this._nativeScaleY = scaleY;
	}
	
	/**
	 * return the y scale of the NativeElement
	 */
	public function getNativeScaleY():Float
	{
		return this._nativeScaleY;
	}
	
	/**
	 * Set the rotation of the NativeElement in rad
	 */
	public function setNativeRotation(rotation:Float):Void
	{
		this._nativeRotation = rotation;
	}
	
	/**
	 * return the rotation of the NativeElement in rad
	 */
	public function getNativeRotation():Float
	{
		return this._nativeRotation;
	}
	
	/**
	 * Set the transformation matrix on the DOMElement. Overriden
	 * to apply it to the NativeElement
	 */
	public function setNativeMatrix(matrix:Matrix):Void
	{
		this._nativeMatrix = matrix;
	}
	
	/**
	 * Get the matrix of the DOMElement
	 */
	public function getNativeMatrix():Matrix
	{
		return _nativeMatrix;
	}
	
	/**
	 * Set the alpha of the NativeElement
	 */
	public function setNativeOpacity(opacity:Float):Void
	{
		this._nativeOpacity = opacity;
	}
	
	/**
	 * Get the alpha of the NativeElement
	 */
	public function getNativeOpacity():Float
	{
		return this._nativeOpacity;
	}
	
	/**
	 * Set the visibility of the NativeElement
	 */
	public function setNativeVisibility(visible:Bool):Void
	{
		this._nativeVisibility = visible;
	}
	
	/**
	 * Get the visibility of the NativeElement
	 */
	public function getNativeVisibility():Bool
	{
		return this._nativeVisibility;
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
	
	private function setFloatValue(value:FloatStyleValue):FloatStyleValue 
	{
		invalidate();
		return _floatValue = value;
	}
	
	private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		invalidate();
		return _clear = value;
	}
	
	private function setFontSize(value:FontSizeStyleValue):FontSizeStyleValue
	{
		invalidateText();
		return _fontSize = value;
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
	
	private function setColor(value:ColorValue):ColorValue
	{
		invalidateText();
		return _color = value;
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
	
	private function setOpacity(value:OpacityStyleValue):OpacityStyleValue
	{
		_opacity = value;
		invalidate();
		return _opacity;
	}
	
	private function setVisibility(value:VisibilityStyleValue):VisibilityStyleValue
	{
		_visibility = value;
		invalidate();
		return _visibility;
	}
	
	private function setTransformOrigin(value:TransformOriginStyleData):TransformOriginStyleData
	{
		invalidate();
		return _tranformOrigin = value;
	}
	
	private function setTransform(value:TransformStyleValue):TransformStyleValue
	{
		invalidate();
		return _transform = value;
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function getOpacity():OpacityStyleValue
	{
		return _opacity;
	}
	
	private function getVisibility():VisibilityStyleValue
	{
		return _visibility;
	}
	
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
	
	private function getFloatValue():FloatStyleValue 
	{
		return _floatValue;
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
	
	private function getTransform():TransformStyleValue
	{
		return _transform;
	}
	
	private function getTransformOrigin():TransformOriginStyleData
	{
		return _tranformOrigin;
	}
}