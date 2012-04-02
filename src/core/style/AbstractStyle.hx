/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style;

import core.geom.Matrix;
import core.NativeElement;
import core.background.BackgroundManager;
import core.HTMLElement;
import core.style.computer.BackgroundStylesComputer;
import core.style.computer.BackgroundStylesComputer;
import core.style.computer.boxComputers.BlockBoxStylesComputer;
import core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import core.style.computer.boxComputers.FloatBoxStylesComputer;
import core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import core.style.computer.boxComputers.InLineBoxStylesComputer;
import core.style.computer.boxComputers.PositionedBoxStylesComputer;
import core.style.computer.boxComputers.BoxStylesComputer;
import core.style.computer.DisplayStylesComputer;
import core.style.computer.FontAndTextStylesComputer;
import core.style.computer.VisualEffectStylesComputer;
import core.ContainerStyle;
import core.style.formatter.FormattingContext;
import core.style.positioner.AbsolutePositioner;
import core.style.positioner.BoxPositioner;
import core.style.positioner.FixedPositioner;
import core.style.positioner.RelativePositioner;
import core.unit.UnitData;
import core.style.StyleData;
import core.geom.GeomData;
import core.renderer.ElementRenderer;
import core.renderer.EmbeddedBoxRenderer;
import core.renderer.FlowBoxRenderer;
import core.renderer.LayerRenderer;
import core.Window;
import haxe.Log;
import haxe.Timer;

/**
 * This is the base class for all Style classes. Style classes
 * are in charge of storing the style value for a HTMLElement
 * and applying them.
 * 
 * This class holds a reference to the styled HTMLElement.
 * 
 * During the layout, a rendering tree, paralleling the DOM tree
 * is built. The rendering tree contains objects of type
 * ElementRenderer. For instance, a ContainerStyle with TextElement
 * children will build a tree containing TextRenderer and BlockBoxRenderer
 * or InlineBoxRenderer.
 * Those objects know how to render themselves.
 * 
 * Styling is done in 2 phases : 
 * - first the styles of the HTMLElement are computed into
 * usable values, for instance values defined as percentage
 * are converted to absolute values. During this phase, an
 * abstract rendering tree of the element is built, containing
 * an array of all its children (background, border, other HTMLElements...)
 * ordered by z-index
 * - once all the styles are computed and the rendering tree is ready, it
 * renders itself
 * 
 * This class implements the default behaviour of an embedded HTMLElement
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
	private var _display:Display;
	public var display(getDisplay, setDisplay):Display;
	
	private var _position:Position;
	public var position(getPosition, setPosition):Position;
	
	private var _cssFloat:CSSFloat;
	public var cssFloat(getCSSFloat, setCSSFloat):CSSFloat;
	
	private var _clear:Clear;
	public var clear(getClear, setClear):Clear;
	
	private var _transformOrigin:TransformOrigin;
	public var transformOrigin(getTransformOrigin, setTransformOrigin):TransformOrigin;
	
	private var _transform:Transform;
	public var transform(getTransform, setTransform):Transform;
	
	/**
	 * box model styles
	 */
	private var _marginLeft:Margin;
	public var marginLeft(getMarginLeft, setMarginLeft):Margin;
	private var _marginRight:Margin;
	public var marginRight(getMarginRight, setMarginRight):Margin;
	private var _marginTop:Margin;
	public var marginTop(getMarginTop, setMarginTop):Margin;
	private var _marginBottom:Margin;
	public var marginBottom(getMarginBottom, setMarginBottom):Margin;
	
	private var _paddingLeft:Padding;
	public var paddingLeft(getPaddingLeft, setPaddingLeft):Padding;
	private var _paddingRight:Padding;
	public var paddingRight(getPaddingRight, setPaddingRight):Padding;
	private var _paddingTop:Padding;
	public var paddingTop(getPaddingTop, setPaddingTop):Padding;
	private var _paddingBottom:Padding;
	public var paddingBottom(getPaddingBottom, setPaddingBottom):Padding;

	private var _width:Dimension;
	public var width(getWidth, setWidth):Dimension;
	private var _height:Dimension;
	public var height(getHeight, setHeight):Dimension;
	
	private var _minHeight:ConstrainedDimension;
	public var minHeight(getMinHeight, setMinHeight):ConstrainedDimension;
	private var _maxHeight:ConstrainedDimension;
	public var maxHeight(getMaxHeight, setMaxHeight):ConstrainedDimension;
	private var _minWidth:ConstrainedDimension;
	public var minWidth(getMinWidth, setMinWidth):ConstrainedDimension;
	private var _maxWidth:ConstrainedDimension;
	public var maxWidth(getMaxWidth, setMaxWidth):ConstrainedDimension;

	private var _top:PositionOffset;
	public var top(getTop, setTop):PositionOffset;
	private var _left:PositionOffset;
	public var left(getLeft, setLeft):PositionOffset;
	private var _bottom:PositionOffset;
	public var bottom(getBottom, setBottom):PositionOffset;
	private var _right:PositionOffset;
	public var right(getRight, setRight):PositionOffset;
	
	/**
	 * background styles
	 */
	private var _backgroundColor:BackgroundColor;
	public var backgroundColor(getBackgroundColor, setBackgroundColor):BackgroundColor;
	
	private var _backgroundImage:Array<BackgroundImage>;
	public var backgroundImage(getBackgroundImage, setBackgroundImage):Array<BackgroundImage>;
	
	private var _backgroundRepeat:Array<BackgroundRepeat>;
	public var backgroundRepeat(getBackgroundRepeat, setBackgroundRepeat):Array<BackgroundRepeat>;
	
	private var _backgroundOrigin:Array<BackgroundOrigin>;
	public var backgroundOrigin(getBackgroundOrigin, setBackgroundOrigin):Array<BackgroundOrigin>;
	
	private var _backgroundSize:Array<BackgroundSize>;
	public var backgroundSize(getBackgroundSize, setBackgroundSize):Array<BackgroundSize>;
	
	private var _backgroundPosition:Array<BackgroundPosition>;
	public var backgroundPosition(getBackgroundPosition, setBackgroundPosition):Array<BackgroundPosition>;
	
	private var _backgroundClip:Array<BackgroundClip>;
	public var backgroundClip(getBackgroundClip, setBackgroundClip):Array<BackgroundClip>;
	
	/**
	 * font styles
	 */
	private var _fontSize:FontSize;
	public var fontSize(getFontSize, setFontSize):FontSize;
	
	private var _fontWeight:FontWeight;
	public var fontWeight(getFontWeight, setFontWeight):FontWeight;
	
	private var _fontStyle:FontStyle;
	public var fontStyle(getFontStyle, setFontStyle):FontStyle;
	
	private var _fontFamily:Array<FontFamily>;
	public var fontFamily(getFontFamily, setFontFamily ):Array<FontFamily>;
	
	private var _fontVariant:FontVariant;
	public var fontVariant(getFontVariant, setFontVariant):FontVariant;
	
	private var _color:Color;
	public var color(getColor, setColor):Color;
	
	/**
	 * text styles
	 */
	private var _lineHeight:LineHeight;
	public var lineHeight(getLineHeight, setLineHeight):LineHeight;
	
	private var _textTransform:TextTransform;
	public var textTransform(getTextTransform, setTextTransform):TextTransform;
	
	private var _letterSpacing:LetterSpacing;
	public var letterSpacing(getLetterSpacing, setLetterSpacing):LetterSpacing;
	
	private var _wordSpacing:WordSpacing;
	public var wordSpacing(getWordSpacing, setWordSpacing):WordSpacing;
	
	private var _whiteSpace:WhiteSpace;
	public var whiteSpace(getWhiteSpace, setWhiteSpace):WhiteSpace;
	
	private var _textAlign:TextAlign;
	public var textAlign(getTextAlign, setTextAlign):TextAlign;
	
	private var _textIndent:TextIndent;
	public var textIndent(getTextIndent, setTextIndent):TextIndent;
		
	private var _verticalAlign:VerticalAlign;
	public var verticalAlign(getVerticalAlign, setVerticalAlign):VerticalAlign;
	
	/**
	 * visual effect styles
	 */
	private var _opacity:Opacity;
	public var opacity(getOpacity, setOpacity):Opacity;
	
	private var _visibility:Visibility;
	public var visibility(getVisibility, setVisibility):Visibility;
	
	private var _overflowX:Overflow;
	public var overflowX(getOverflowX,  setOverflowX):Overflow;
	
	private var _overflowY:Overflow;
	public var overflowY(getOverflowY,  setOverflowY):Overflow;
	
	/**
	 * user interface styles
	 */
	private var _cursor:Cursor;
	public var cursor(getCursor, setCursor):Cursor;
	
	////////////////////////////////
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	private var _computedStyle:ComputedStyleData;
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyleData;
	
	/**
	 * A reference to the HTMLElement to which these styles
	 * apply
	 */
	private var _htmlElement:HTMLElement;
	public var htmlElement(get_htmlElement, never):HTMLElement;
	
	/**
	 * Returns metrics info for the currently defined
	 * font and font size. Used in inline formatting context
	 * to determine lineBoxes sizes and text vertical and horizontal
	 * position
	 */
	private var _fontMetrics:FontMetricsData;
	public var fontMetrics(getFontMetricsData, never):FontMetricsData;
	
	/**
	 * determine wether the HTMLElement and its chidlren must
	 * be laid out again
	 */
	private var _isDirty:Bool;
	
	/**
	 * A reference to the rendering tree node created by this
	 * DOM tree node
	 */
	private var _elementRenderer:ElementRenderer;
	public var elementRenderer(getElementRenderer, never):ElementRenderer;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Class constructor. Stores the target HTMLElement.
	 * Init the class attributes
	 * 
	 * The style is invalid by default and will be updated
	 * when the HTMLElement is added to the DOM.
	 */
	public function new(htmlElement:HTMLElement) 
	{
		this._htmlElement = htmlElement;
		this._isDirty = false;
		
		initDefaultStyleValues();
	}
	
	/**
	 * Init the standard default value for styles
	 */
	private function initDefaultStyleValues():Void
	{
		initComputedStyles();
		
		_width = Dimension.cssAuto;
		_height = Dimension.cssAuto;
		
		_minWidth = ConstrainedDimension.length(px(0));
		_maxWidth = ConstrainedDimension.none;
		_minHeight = ConstrainedDimension.length(px(0));
		_maxHeight = ConstrainedDimension.none;
		
		_marginTop = Margin.length(px(0));
		_marginBottom = Margin.length(px(0));
		_marginLeft = Margin.length(px(0));
		_marginRight = Margin.length(px(0));
		
		_paddingTop = Padding.length(px(0));
		_paddingBottom = Padding.length(px(0));
		_paddingLeft = Padding.length(px(0));
		_paddingRight = Padding.length(px(0));
		
		_lineHeight = LineHeight.normal;
		_verticalAlign = VerticalAlign.baseline;
		
		_display = Display.cssInline;
		_position = Position.cssStatic;
		
		_top = PositionOffset.cssAuto;
		_bottom = PositionOffset.cssAuto;
		_left = PositionOffset.cssAuto;
		_right = PositionOffset.cssAuto;
		
		_cssFloat = CSSFloat.none;
		_clear = Clear.none;
		
		_backgroundColor = Color.transparent;
		_backgroundImage = [BackgroundImage.none];
		_backgroundRepeat = [{
			x:BackgroundRepeatValue.repeat,
			y:BackgroundRepeatValue.repeat
		}];
		_backgroundPosition = [{
			x:BackgroundPositionX.percent(0),
			y:BackgroundPositionY.percent(0)
		}];
		_backgroundOrigin = [BackgroundOrigin.paddingBox];
		_backgroundSize = [
			BackgroundSize.dimensions({
				x:BackgroundSizeDimension.cssAuto,
				y:BackgroundSizeDimension.cssAuto
			})];
		_backgroundClip = [BackgroundClip.borderBox];	
		
		_fontStyle = FontStyle.normal;
		_fontVariant = FontVariant.normal;
		_fontWeight = FontWeight.normal;
		_fontSize = FontSize.absoluteSize(FontSizeAbsoluteSize.medium);
		
		_textIndent = TextIndent.length(px(0));
		_textAlign = TextAlign.left;
		_letterSpacing = LetterSpacing.normal;
		_wordSpacing = WordSpacing.normal;
		_textTransform = TextTransform.none;
		_whiteSpace = WhiteSpace.normal;
		
		_visibility = Visibility.visible;
		_opacity = 1.0;
		_overflowX = Overflow.visible;
		_overflowY = Overflow.visible;
		
		_transformOrigin = {
			x:TransformOriginX.center,
			y:TransformOriginY.center
		}
		
		_transform = Transform.none;
		
		_cursor = Cursor.cssDefault;
		
		var defaultStyles:DefaultStylesData = getDefaultStyle();
		_fontFamily = defaultStyles.fontFamily;
		_color = defaultStyles.color;
		
		applyDefaultHTMLStyles();
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
			clear : Clear.none,
			cssFloat : CSSFloat.none,
			display : Display.block,
			position: Position.cssStatic,
			verticalAlign : 0.0,
			fontSize:16.0,
			lineHeight:14.0,
			fontWeight:FontWeight.normal,
			fontStyle:FontStyle.normal,
			fontFamily:[FontFamily.genericFamily(GenericFontFamily.serif)],
			fontVariant:FontVariant.normal,
			textTransform:TextTransform.none,
			letterSpacing:0,
			wordSpacing:0,
			textIndent:0,
			whiteSpace:WhiteSpace.normal,
			textAlign:TextAlign.left,
			color:{color:0, alpha:1.0},
			visibility:true,
			opacity:1.0,
			overflowX: Overflow.visible,
			overflowY: Overflow.visible,
			transformOrigin: { x:0.0, y:0.0 },
			transform:new Matrix(),
			backgroundColor:{color:0, alpha:1.0},
			backgroundSize:[],
			backgroundOrigin:[],
			backgroundImage:[],
			backgroundClip:[],
			backgroundPosition:[],
			backgroundRepeat:[],
			cursor:Cursor.cssDefault
		};
	}
	
	/**
	 * Return default value for style defined by the User Agent
	 * in a browser, those styles are hard coded for other
	 * runtimes
	 */
	private static function getDefaultStyle():DefaultStylesData
	{
		return {
			fontFamily:[FontFamily.genericFamily(GenericFontFamily.serif)],
			color:Color.keyword(ColorKeyword.black)
		}
	}
	
	/**
	 * Apply the standard default CSS value according to this
	 * document : http://www.w3.org/TR/CSS21/sample.html
	 * 
	 * This method should eventually be removed when a StyleManager
	 * is introduced which will prevent those styles from being hard-coded
	 */
	private function applyDefaultHTMLStyles():Void
	{
		switch (_htmlElement.tagName)
		{
			case "html", "adress",
			"dd", "div", "dl", "dt", "fieldset",
			"form", "frame", "frameset", "noframes", "ol", "ul",
			"center", "dir", "hr", "menu" :
				_display = Display.block;
				
			case "head" :	
				_display = Display.none;
				
			case "body" : 
				_display = Display.block;
				_marginLeft = _marginRight = _marginTop = _marginBottom = Margin.length(px(8));
				
			case "h1" : 
				_display = Display.block;
				_fontSize = FontSize.length(em(2));
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(0.67));
				
			case "h2" : 
				_display = Display.block;
				_fontSize = FontSize.length(em(1.5));
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(0.75));	
			
			case "h3" : 
				_display = Display.block;
				_fontSize = FontSize.length(em(1.17));
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(0.83));
			
			case "h4" :	
				_display = Display.block;
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(1.12));
			
			case "h5" : 
				_display = Display.block;
				_fontSize = FontSize.length(em(0.83));
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(1.5));	
				
			case "h6" : 
				_display = Display.block;
				_fontSize = FontSize.length(em(0.75));
				_fontWeight = FontWeight.bolder;
				_marginTop = _marginBottom = Margin.length(em(1.67));		
				
			case "p" :
				_display = Display.block;
				_marginTop = _marginBottom = Margin.length(em(1.67));	
				
			case "pre" : 
				_display = Display.block;
				_whiteSpace = WhiteSpace.pre;
				_fontFamily = [FontFamily.genericFamily(GenericFontFamily.monospace)];
				
			case "code" : 
				_fontFamily = [FontFamily.genericFamily(GenericFontFamily.monospace)];
				
			case "i", "cite", "em", "var" :
				_fontStyle = FontStyle.italic;
				
			case "input" : 
				_display = inlineBlock;
				
			case "blockquote" : 
				_display = block;
				_marginTop = _marginBottom = Margin.length(em(1.12));
				_marginLeft = _marginRight = Margin.length(px(40));
				
			case "strong" : 
				_fontWeight = FontWeight.bolder;
				
			case "big" : 
				_fontSize = FontSize.length(em(1.17));
				
			case "small" :
				_fontSize = FontSize.length(em(0.83));
				
			case "sub" : 
				_fontSize = FontSize.length(em(0.83));
				_verticalAlign = VerticalAlign.sub;
				
			case "sup" :
				_fontSize = FontSize.length(em(0.83));
				_verticalAlign = VerticalAlign.cssSuper;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create and return the right ElementRenderer for this HTMLElement
	 */
	private function createElementRenderer(parentElementRenderer:FlowBoxRenderer):ElementRenderer
	{
		var elementRenderer:ElementRenderer = new EmbeddedBoxRenderer(cast(this));
		elementRenderer.layerRenderer = getLayerRenderer(elementRenderer, parentElementRenderer);
		
		parentElementRenderer.appendChild(elementRenderer);
		
		return elementRenderer;
	}
	
	/**
	 * An ElementRenderer can either create a new layer to render its children or
	 * use the one of its parent. 
	 */
	private function getLayerRenderer(elementRenderer:ElementRenderer, parentElementRenderer:ElementRenderer):LayerRenderer
	{
		var layerRenderer:LayerRenderer;
		
		//positioned elements always create a new layer
		if (isPositioned() == true)
		{
			layerRenderer = new LayerRenderer(elementRenderer);
		}
		else
		{
			layerRenderer = parentElementRenderer.layerRenderer;
		}
		
		return layerRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The main layout method. When called, the HTMLElement's styles (width, height, margins, paddings...)
	 * are computed into actual values, the HTMLElement layout its children if it has any then add itself
	 * to the layout.
	 * 
	 * @param	containingHTMLElementData the dimensions of the parent HTMLElement into which 
	 * this HTMLElement must be laid out
	 * @param	lastPositionedHTMLElementData the dimensions of the first ancestor HTMLElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' style other than 'static'. When positioning an absolutely positioned HTMLElement (a HTMLElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned HTMLElement
	 * (a HTMLElement with a 'position' of 'fixed'), it is used as origin
	 * @param containingHTMLElementFontMetricsData contains font metrics of the parent HTMLElement, used for instance
	 * to layout children in an inline formatting context
	 */
	public function layout(containingHTMLElementData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{
		//abstract
	}
	
	/**
	 * This method is in charge of placing "in-flow" HTMLElements (HTMLElement with a 'position' style of 'static' or 'relative') into
	 * its parent flow and "positioned" HTMLElement (with a 'position' style of 'absolute' or 'fixed') relatively to its first positioned
	 * ancestor.
	 * 
	 * The HTMLElement first compute its own styles (box model, font, text...), then insert its ElementRenderer into the document based 
	 * on its positioning scheme.
	 * 
	 * This method is called recursively on every children of the HTMLElement if it has any
	 * 
	 * @param	containingHTMLElementData the dimensions of the parent HTMLElement into which 
	 * this HTMLElement must be laid out
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned HTMLElement
	 * (a HTMLElement with a 'position' of 'fixed'), it is used as origin
	 * @param	lastPositionedHTMLElementData the dimensions of the first ancestor HTMLElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' other than 'static'. When laying out an absolutelty positioned HTMLElement ( a HTMLElement with a 'position' style
	 * of 'absolute'), it it used as origin. It also contains a reference to each absolutely positioned AbstractStyle using it as origin
	 * to position their HTMLElement
	 * @param   containingHTMLElementFontMetricsData contains font metrics used to layout children in an inline formatting context
	 * @param	formattingContext can be an inline or block formatting context. "In-flow" HTMLElements insert themselves into the 
	 * formattingContext to be placed in the document flow
	 * @param parentElementRenderer the parent node in the rendering tree
	 */
	public function flow(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext, parentElementRenderer:FlowBoxRenderer):Void
	{		
		if (_elementRenderer != null && parentElementRenderer != null)
		{
			parentElementRenderer.removeChild(_elementRenderer);
		}
		
		//do nothing if the HTMLElement must not be displayed, i.e, added
		//to the display list
		if (isNotDisplayed() == true)
		{
			return;
		}

		//reset the computed styles, useful for instance to
		//reset an auto height to 0 if a layout has already
		//occured which might create bugs in the computation of
		//font and text styles which use the computed height value
		initComputedStyles();
		
		//compute all the styles of a HTMLElement
		computeHTMLElementStyles(containingHTMLElementData, viewportData, lastPositionedHTMLElementData.data, containingHTMLElementFontMetricsData);
		
		//the HTMLElement creates its own ElementRenderer
		_elementRenderer = createElementRenderer(parentElementRenderer);
		
		//flow all the children of the HTMLElement if it has any
		flowChildren(containingHTMLElementData, viewportData, lastPositionedHTMLElementData, containingHTMLElementFontMetricsData, formattingContext);
		
		//when all the dimensions of the htmlElement are known, compute the 
		//visual effects to apply (visibility, opacity, transform)
		//it is necessary to wait for all dimensions to be known because for
		//instance the transform style use the height and width of the HTMLElement
		//to determine the transformation center
		computeVisualEffectStyles();
		
		//some text and font styles needs to be re-computed now that all the dimension
		//of the HTMLElement are known, for instance some values of the VerticalAlign style
		//might need those dimensions to compute the right values
		computeTextAndFontStyles(containingHTMLElementData, containingHTMLElementFontMetricsData);
		
		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		computeBackgroundStyles();
		
		//insert the HTMLElement in its parent's formatting context based on its positioning scheme
		insertHTMLElement(formattingContext, lastPositionedHTMLElementData, viewportData);
		
		//The HTMLElement has been laid out and is now valid
		this._isDirty = false;
	}
	
	/**
	 * Place a positioned HTMLElement (a HTMLElement with a position style of 'relative', 'absolute', or 'fixed') using either the normal
	 * flow, the last positioned HTMLElement or the viewport of the document, then apply an offset defined by the 'top',
	 * 'left', 'bottom' and 'right' computed styles values
	 * 
	 * @param lastPositionedHTMLElementData
	 * @param viewportData
	 * @param staticPosition the x,y position that the HTMLElement would have had if it were 'in-flow'
	 */
	public function positionElement(lastPositionedHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, staticPosition:PointData):ElementRenderer
	{
		//instantiate the right positioner
		//class based on the value of the 'position' style
		var positioner:BoxPositioner;
		
		switch (this._htmlElement.style.computedStyle.position)
		{
			//positioned 'relative' HTMLElement
			case relative:
				positioner = new RelativePositioner();
				_elementRenderer = positioner.position(_elementRenderer, lastPositionedHTMLElementData, staticPosition);
			
			//positioned 'fixed' HTMLElement, use the viewport
			case fixed:
				positioner = new FixedPositioner();
				_elementRenderer = positioner.position(_elementRenderer, viewportData, staticPosition);
				
			//positioned 'absolute' HTMLElement	
			case absolute:
				positioner = new AbsolutePositioner();
				_elementRenderer = positioner.position(_elementRenderer, lastPositionedHTMLElementData, staticPosition);
				
			default:
		}
		
		//update the bounds of the ElementRenderer
		_elementRenderer.bounds.width = _computedStyle.width + _computedStyle.paddingLeft + _computedStyle.paddingRight;
		_elementRenderer.bounds.height = _computedStyle.height + _computedStyle.paddingTop + _computedStyle.paddingBottom;
		
		return _elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a timer to trigger a layout of the HTMLElement asynchronously. this method is used by the invalidation
	 * mechanism. Setting a timer to execute the layout ensure that the layout only happen once when a series of style
	 * values are set instead of happening for every change.
	 */
	private function scheduleLayout(containingHTMLElementData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		var layoutDelegate:ContainingHTMLElementData->LastPositionedHTMLElementData->ContainingHTMLElementData->FontMetricsData->Void = layout;
		
		Timer.delay(function () { 
			layoutDelegate(containingHTMLElementData, lastPositionedHTMLElementData, viewportData, null);
		}, 1);
	}
	
	/**
	 * Flow all the children of a HTMLElement if it has any
	 */
	private function flowChildren(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		
	}
	
	/**
	 * Insert the HTMLElement in the document, in or out of the flow.
	 * 
	 * @param	formattingContext the formatting context into which the HTMLElement insert itself if it
	 * is 'in flow'
	 * @param	lastPositionedHTMLElementData
	 * @param	viewportData
	 */
	private function insertHTMLElement(formattingContext:FormattingContext, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		//insert in the flow
		if (isPositioned() == false)
		{
			formattingContext.insertElement(_elementRenderer);
		}
		//else the HTMLElement is positioned
		else
		{
			
			//retrieve the static position (the position of the HTMLElement
			//if its position style were 'static')
			var staticPosition:PointData = formattingContext.getStaticPosition(_elementRenderer);
			//a relative HTMLElement is both inserted in the flow
			//and positioned
			//
			if (isRelativePositioned() == true)
			{
				formattingContext.insertElement(_elementRenderer);
			}
			
			//insert as a positioned HTMLElement.
			//an absolutely positioned HTMLElement is not positioned right away, it must
			//wait for its first positioned ancestor to be laid out. The reason is that
			//if the positioned ancestor height is 'auto', the height of the positioned
			//ancestor is not yet determined and so this HTMLElement can't be positioned
			//using the bottom or right style yet. Once the first ancestor is laid out, it
			//calls the positionElement method on all the stored positioned children
			//
			//relative positioned HTMLElement are also stored in that array
			//
			var positionedHTMLElementData:PositionedHTMLElementData = {
				staticPosition:staticPosition,
				style:this
			}
			
			//store the HTMLElement to be positioned later
			lastPositionedHTMLElementData.children.push(positionedHTMLElementData);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the value of a style that require
	 * a re-layout (such as width, height, display...) is
	 * changed.
	 * 
	 * An invalidated HTMLElement will in turn invalidate its
	 * parent and so on until the root HTMLBodyElement is invalidated.
	 * The root HTMLBodyElement will then layout itself, laying out
	 * at the same time all its invalidated children.
	 * 
	 * A layout can be immediate or scheduled asynchronously, which
	 * increase preformance when many style value are set in a 
	 * row as the layout only happen once
	 */
	public function invalidate(immediate:Bool = false):Void
	{
		//only invalidate the parent if it isn't
		//done already or if an immediate layout is required
		if (this._isDirty == false || immediate == true)
		{
			//set the dirty flag to prevent multiple
			//layout of the HTMLElement in a row
			//The HTMLElement will be able to be invalidated
			//again once it has been laid out
			this._isDirty = true;
			
			//if the HTMLElement doesn't have a parent, then it
			//is not currently added to the DOM and doesn't require
			//a layout
			if (this._htmlElement.parentNode != null)
			{
				var parent:HTMLElement = cast(_htmlElement.parentNode);
				parent.style.invalidate(immediate);	
			}
		}
	}
	
	/**
	 * When a style invalidating the text is called
	 * (font size, font weight...), the font metrics
	 * structure must be reseted so that it is re-created
	 * with updating values on next layout
	 * 
	 * TODO : no more text cache system, need to re-implement
	 */
	public function invalidateText():Void
	{
		_fontMetrics = null;
		invalidate();
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method computes the styles determing
	 * the HTMLElement's layout scheme :
	 * position, display, float and clear.
	 * 
	 * It is public as it may be called by the
	 * ContainerStyle of the parent HTMLElement
	 * which may need to known the display style of its
	 * children to determine which type of formatting context
	 * to establish for its children
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
	 * Computes the styles determining the background
	 * color, images... of a HTMLElement
	 */
	private function computeBackgroundStyles():Void
	{
		BackgroundStylesComputer.compute(this);
	}
	
	/**
	 * Compute first the styles determining the HTMLElement's
	 * positioning scheme (position, float, clear...),
	 * the style detemining font and text display,
	 * then the styles determining its box model (width, height, margins
	 * paddings...) which are computed last because they may use
	 * some font metrics to compute the box model, for instance
	 * when a dimension is defined with an 'em' unit
	 */
	private function computeHTMLElementStyles(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{
		computeDisplayStyles();
		computeTextAndFontStyles(containingHTMLElementData, containingHTMLElementFontMetricsData);
		computeBoxModelStyles(containingHTMLElementData, viewportData, lastPositionedHTMLElementData);
	}
	
	/**
	 * Compute the visual effect styles (opacity, visibility, transformations)
	 */
	private function computeVisualEffectStyles():Void
	{
		VisualEffectStylesComputer.compute(this);
	}
	
	/**
	 * Computes the HTMLElement font and text styles (font size, font name, text color...)
	 */
	private function computeTextAndFontStyles(containingHTMLElementData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{
		FontAndTextStylesComputer.compute(this, containingHTMLElementData, containingHTMLElementFontMetricsData);
	}
	
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the HTMLElement, based on
	 * its positioning scheme
	 */ 
	private function computeBoxModelStyles(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:ContainingHTMLElementData):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//get the right containing dimensions. For example,
		//for a HTMLElement with a 'position' style of 'absolute',
		//it is the last positioned HTMLElement
		var containingBlockDimensions:ContainingHTMLElementData = getContainingHTMLElementData(containingHTMLElementData, viewportData, lastPositionedHTMLElementData );
		
		//do compute the box model styles
		boxComputer.measure(this, containingBlockDimensions);
	}
	
	/**
	 * instantiate the right box computer class
	 *	based on the HTMLElement's positioning
	 *	scheme
	 */
	private function getBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
		
		//get the embedded box computers based on
		//the positioning scheme
		if (isFloat() == true)
		{
			boxComputer = new EmbeddedFloatBoxStylesComputer();
		}
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new EmbeddedPositionedBoxStylesComputer();
		}
		else
		{
			switch(this._computedStyle.display)
			{
				case block:
					boxComputer = new EmbeddedBlockBoxStylesComputer();
					
				case inlineBlock:
					boxComputer = new EmbeddedInlineBlockBoxStylesComputer();	
				
				//not supposed to happen
				case none:
					boxComputer = null;
				
				case cssInline:
					boxComputer = new EmbeddedInlineBoxStylesComputer();
			}
		}
		
		return boxComputer;
	}
	
	/**
	 * Get the right containing parent dimensions for a HTMLElement
	 * based on its position style value
	 */
	private function getContainingHTMLElementData(containingHTMLElementData:ContainingHTMLElementData, viewportData:ContainingHTMLElementData, lastPositionedHTMLElementData:ContainingHTMLElementData):ContainingHTMLElementData
	{
		var containingBlockDimensions:ContainingHTMLElementData;
		
		//for 'positioned' HTMLElement
		if (isPositioned() == true)
		{
			//for 'fixed' HTMLElement, takes the viewport (the 'window' through which the document is viewed)
			if (this._computedStyle.position == Position.fixed)
			{
				containingBlockDimensions = {
					width:viewportData.width,
					height:viewportData.height,
					isHeightAuto:viewportData.isHeightAuto,
					isWidthAuto:viewportData.isWidthAuto};
			}
			//for 'absolute' takes the first positioned ancestor
			else if (this._computedStyle.position == Position.absolute)
			{
				containingBlockDimensions = {
					width:lastPositionedHTMLElementData.width,
					height:lastPositionedHTMLElementData.height,
					isHeightAuto:lastPositionedHTMLElementData.isHeightAuto,
					isWidthAuto:lastPositionedHTMLElementData.isWidthAuto};
			}
			//else for 'relative', takes the parent as 'relative' are "in-flow" HTMLElements
			else
			{
				containingBlockDimensions = containingHTMLElementData;
			}
		}
		//else, for not 'positioned' HTMLElement, takes the containing HTMLElement dimensions which is the parent
		else
		{
			containingBlockDimensions = containingHTMLElementData;
		}
		
		return containingBlockDimensions;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine if the HTMLElement is a floated
	 * HTMLElement. A floated HTMLElement is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its container.
	 * Any subsequent HTMLElement flows
	 * around the float until a new line 
	 * starts below the float or if it is cleared
	 * by another HTMLElement.
	 * 
	 * A HTMLElement is float if he declares either
	 * a left or right float
	 */
	public function isFloat():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.cssFloat) 
		{
			case CSSFloat.left, CSSFloat.right:
				ret = true;
			
			case CSSFloat.none:
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
	 * a HTMLElement 'positioned'. 
	 * 
	 * The 'absolute' and 'fixed' value make
	 * a HTMLElement an 'absolutely positioned'
	 * HTMLElement. This kind of HTMLElement
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
			
			case cssStatic:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Determine wether a HTMLElement has
	 * the 'position' value 'relative'.
	 * 
	 * A 'relative' HTMLElement is first placed
	 * normally in the flow then an offset is 
	 * applied to it with the top, left, right
	 * and bottom computed styles.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * HTMLElement is found
	 */
	public function isRelativePositioned():Bool
	{
		return this._computedStyle.position == relative;
	}
	
	/**
	 * Determine if all the children of the 
	 * HTMLElement are inline-level. 
	 * Default is false when the HTMLElement
	 * can't have children
	 */
	public function childrenInline():Bool
	{
		return false;
	}
	
	/**
	 * An inline-level HTMLElement is one that is
	 * laid out on a line. It will be placed
	 * either next to the preceding HTMLElement
	 * or on a new line if the current line
	 * is too short to host it.
	 * 
	 * Wheter an element is inline-level is determined
	 * by its display style
	 */
	public function isInlineLevel():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.display) 
		{
			case cssInline, inlineBlock:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Wheter this HTMLElement starts a new
	 * formatting context for its children.
	 * Default is false as only ContainerHTMLElements
	 * can start new formatting context
	 */
	public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	/**
	 * Get the first parent HTMLElement which is positioned
	 * or null if the HTMLElement has no parent (it is
	 * not attached to the DOM or is the HTMLBodyElement)
	 * 
	 * TODO : bug, if the first positioned ancestor is
	 * the body, it returns the root html element instead.
	 * Can't be fixed by changing isPositioned on HTML body
	 */
	public function getFirstPositionedAncestor():HTMLElement
	{
		//here it is either the HTMLBodyElement
		//or not attached to the DOM
		if (_htmlElement.parentNode == null)
		{
			return null;
		}
		
		var parent:HTMLElement = cast(_htmlElement.parentNode);
		
		//loop in all the parents until a positioned or a null parent is found
		var isOffsetParent:Bool = parent.style.isOffsetParent();
		
		while (isOffsetParent == false)
		{
			if (parent.parentNode != null)
			{
				parent = cast(parent.parentNode);
				isOffsetParent = parent.style.isOffsetParent();
			}
			//break the loop if the current parent has no parent
			else
			{
				isOffsetParent = true;
			}
		}
		
		return parent;
	}
	
	/**
	 * Return wether this Style is the 
	 * offset parent for its children
	 */
	public function isOffsetParent():Bool
	{
		return isPositioned();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the HTMLElement introduces
	 * 'clearance', which as the effect of placing
	 * the HTMLElement below any preceding floated
	 * HTMLElement. A HTMLElement introduces clearance
	 * if he clears either left floats, right floats
	 * or both
	 */
	private function isClear():Bool
	{
		var ret:Bool = false;
		
		switch (this._computedStyle.clear) 
		{
			case Clear.left, Clear.right, Clear.both:
				ret = true;
			
			case Clear.none:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Determine wether the HTMLElement is added
	 * to the document
	 */
	private function isNotDisplayed():Bool
	{
		return this._computedStyle.display == Display.none;
	}
	
	/**
	 * Get the dimensions of the first ancestor
	 * of the styled HTMLElement which is positioned
	 * or of the HTMLBodyElement
	 */
	private function getFirstPositionedAncestorData():ContainingHTMLElementData
	{
		var firstPositionedAncestorData:ContainingHTMLElementData;
		var firstPositionedAncestor:HTMLElement = getFirstPositionedAncestor();
		
		//if the htmlElement has a parent
		if (firstPositionedAncestor != null)
		{
			var firstPositionedAncestorStyle:ContainerStyle = cast(firstPositionedAncestor.style);
			firstPositionedAncestorData = firstPositionedAncestorStyle.getContainerHTMLElementData();
		}
		//if the HTMLElement has no parent, return the Window data
		else
		{
			firstPositionedAncestorData = getWindowData();
		}
		
		return firstPositionedAncestorData;
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingHTMLElementData
	{	
		var windowData:ContainingHTMLElementData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:cocktail.Lib.window.innerWidth,
			height:cocktail.Lib.window.innerHeight
		}
		
		return windowData;
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	private function getElementRenderer():ElementRenderer
	{
		return _elementRenderer;
	}
	
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
	
	private function get_htmlElement():HTMLElement
	{
		return _htmlElement;
	}
	
	/////////////////////////////////
	// INVALIDATING STYLES SETTERS
	// setting one of those style will 
	// cause a re-layout
	////////////////////////////////
	
	private function setWidth(value:Dimension):Dimension 
	{
		invalidate();
		return _width = value;
	}
	
	private function setMarginLeft(value:Margin):Margin 
	{
		invalidate();
		return _marginLeft = value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		invalidate();
		return _marginRight = value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		invalidate();
		return _marginTop = value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		invalidate();
		return _marginBottom = value;
	}
	
	private function setPaddingLeft(value:Padding):Padding 
	{
		invalidate();
		return _paddingLeft = value;
	}
	
	private function setPaddingRight(value:Padding):Padding 
	{
		invalidate();
		return _paddingRight = value;
	}
	
	private function setPaddingTop(value:Padding):Padding 
	{
		invalidate();
		return _paddingTop = value;
	}
	
	private function setPaddingBottom(value:Padding):Padding 
	{
		invalidate();
		return _paddingBottom = value;
	}
	
	private function setDisplay(value:Display):Display 
	{
		invalidate();
		return _display = value;
	}
	
	private function setPosition(value:Position):Position 
	{
		invalidate();
		return _position = value;
	}
	
	private function setHeight(value:Dimension):Dimension 
	{
		invalidate();
		return _height = value;
	}
	
	private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		invalidate();
		return _minHeight = value;
	}
	
	private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		invalidate();
		return _maxHeight = value;
	}
	
	private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		invalidate();
		return _minWidth = value;
	}
	
	private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		invalidate();
		return _maxWidth = value;
	}
	
	private function setTop(value:PositionOffset):PositionOffset 
	{
		invalidate();
		return _top = value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		invalidate();
		return _left = value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		invalidate();
		return _bottom = value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		invalidate();
		return _right = value;
	}
	
	private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		invalidate();
		return _cssFloat = value;
	}
	
	private function setClear(value:Clear):Clear 
	{
		invalidate();
		return _clear = value;
	}
	
	private function setFontSize(value:FontSize):FontSize
	{
		invalidateText();
		return _fontSize = value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		invalidateText();
		return _fontWeight = value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		invalidateText();
		return _fontStyle = value;
	}
	
	private function setFontFamily(value:Array<FontFamily>):Array<FontFamily>
	{
		invalidateText();
		return _fontFamily = value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		invalidateText();
		return _fontVariant = value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		invalidateText();
		return _textTransform = value;
	}
	
	private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		invalidateText();
		return _letterSpacing = value;
	}
	
	private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		invalidate();
		return _wordSpacing = value;
	}
	
	private function setLineHeight(value:LineHeight):LineHeight
	{
		invalidate();
		return _lineHeight = value;
	}
	
	private function setColor(value:Color):Color
	{
		invalidateText();
		return _color = value;
	}
	
	private function setVerticalAlign(value:VerticalAlign):VerticalAlign
	{
		invalidate();
		return _verticalAlign = value;
	}
	
	private function setTextIndent(value:TextIndent):TextIndent
	{
		invalidate();
		return _textIndent = value;
	}
	
	private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		invalidate();
		return _whiteSpace = value;
	}
	
	private function setTextAlign(value:TextAlign):TextAlign
	{
		invalidate();
		return _textAlign = value;
	}
	
	private function setOpacity(value:Opacity):Opacity
	{
		_opacity = value;
		invalidate();
		return _opacity;
	}
	
	private function setVisibility(value:Visibility):Visibility
	{
		_visibility = value;
		invalidate();
		return _visibility;
	}
	
	private function setTransformOrigin(value:TransformOrigin):TransformOrigin
	{
		invalidate();
		return _transformOrigin = value;
	}
	
	private function setTransform(value:Transform):Transform
	{
		invalidate();
		return _transform = value;
	}
	
	private function setOverflowX(value:Overflow):Overflow
	{
		invalidate();
		return _overflowX = value;
	}
	
	private function setOverflowY(value:Overflow):Overflow
	{
		invalidate();
		return _overflowY = value;
	}
	
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function getOpacity():Opacity
	{
		return _opacity;
	}
	
	private function getVisibility():Visibility
	{
		return _visibility;
	}
	
	private function getMarginLeft():Margin 
	{
		return _marginLeft;
	}
	
	private function getMarginRight():Margin 
	{
		return _marginRight;
	}
	
	private function getMarginTop():Margin 
	{
		return _marginTop;
	}
	
	private function getMarginBottom():Margin 
	{
		return _marginBottom;
	}
	
	private function getPaddingLeft():Padding 
	{
		return _paddingLeft;
	}
	
	private function getPaddingRight():Padding 
	{
		return _paddingRight;
	}
	
	private function getPaddingTop():Padding 
	{
		return _paddingTop;
	}
	
	private function getPaddingBottom():Padding 
	{
		return _paddingBottom;
	}
	
	private function getDisplay():Display 
	{
		return _display;
	}
	
	private function getPosition():Position 
	{
		return _position;
	}
	
	private function getWidth():Dimension 
	{
		return _width;
	}
	
	private function getHeight():Dimension 
	{
		return _height;
	}
	
	private function getMinHeight():ConstrainedDimension 
	{
		return _minHeight;
	}
	
	private function getMaxHeight():ConstrainedDimension 
	{
		return _maxHeight;
	}
	
	private function getMinWidth():ConstrainedDimension 
	{
		return _minWidth;
	}
	
	private function getMaxWidth():ConstrainedDimension 
	{
		return _maxWidth;
	}
	
	private function getTop():PositionOffset 
	{
		return _top;
	}
	
	private function getLeft():PositionOffset 
	{
		return _left;
	}
	
	private function getBottom():PositionOffset 
	{
		return _bottom;
	}
	
	private function getRight():PositionOffset 
	{
		return _right;
	}
	
	private function getCSSFloat():CSSFloat 
	{
		return _cssFloat;
	}
	
	private function getClear():Clear 
	{
		return _clear;
	}
	
	private function getFontSize():FontSize
	{
		return _fontSize;
	}
	
	private function getFontWeight():FontWeight
	{
		return _fontWeight;
	}
	
	private function getFontStyle():FontStyle
	{
		return _fontStyle;
	}
	
	private function getFontFamily():Array<FontFamily>
	{
		return _fontFamily;
	}
	
	private function getFontVariant():FontVariant
	{
		return _fontVariant;
	}
	
	private function getTextTransform():TextTransform
	{
		return _textTransform;
	}
	
	private function getLetterSpacing():LetterSpacing
	{
		return _letterSpacing;
	}
	
	private function getColor():Color
	{
		return _color;
	}
	
	private function getWordSpacing():WordSpacing
	{
		return _wordSpacing;
	}
	
	private function getLineHeight():LineHeight
	{
		return _lineHeight;
	}
	
	private function getVerticalAlign():VerticalAlign
	{
		return _verticalAlign;
	}
	
	private function getTextIndent():TextIndent
	{
		return _textIndent;
	}
	
	private function getWhiteSpace():WhiteSpace
	{
		return _whiteSpace;
	}
	
	private function getTextAlign():TextAlign
	{
		return _textAlign;
	}
	
	private function getTransform():Transform
	{
		return _transform;
	}
	
	private function getTransformOrigin():TransformOrigin
	{
		return _transformOrigin;
	}
	
	private function setBackgroundColor(value:BackgroundColor):BackgroundColor
	{
		return _backgroundColor = value;
	}
	
	private function getBackgroundColor():BackgroundColor
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		return _backgroundImage = value;
	}
	
	private function getBackgroundImage():Array<BackgroundImage>
	{
		return _backgroundImage;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		return _backgroundRepeat = value;
	}
	
	private function getBackgroundRepeat():Array<BackgroundRepeat>
	{
		return _backgroundRepeat;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		return _backgroundSize = value;
	}
	
	private function getBackgroundSize():Array<BackgroundSize>
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		return _backgroundClip = value;
	}
	
	private function getBackgroundClip():Array<BackgroundClip>
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		return _backgroundPosition = value;
	}
	
	private function getBackgroundPosition():Array<BackgroundPosition>
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		return _backgroundOrigin = value;
	}
	
	private function getBackgroundOrigin():Array<BackgroundOrigin>
	{
		return _backgroundOrigin;
	}
	
	private function getOverflowX():Overflow
	{
		return _overflowX;
	}
	
	private function getOverflowY():Overflow
	{
		return _overflowY;
	}
	
	private function setCursor(value:Cursor):Cursor
	{
		return _cursor = value;
	}
	
	private function getCursor():Cursor
	{
		return _cursor;
	}
}