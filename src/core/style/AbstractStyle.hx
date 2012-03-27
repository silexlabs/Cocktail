/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style;

import core.geom.Matrix;
import core.nativeElement.NativeElement;
import core.background.BackgroundManager;
import core.HTMLElement;
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
import core.style.computer.boxComputers.NoneBoxStylesComputer;
import core.style.computer.boxComputers.PositionedBoxStylesComputer;
import core.style.computer.BoxStylesComputer;
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
 * are in charge of storing the style value for a DOMElement
 * and applying them.
 * 
 * This class holds a reference to the styled DOMElement.
 * 
 * During the layout, a rendering tree, paralleling the DOM tree
 * is built. The rendering tree contains objects of type
 * ElementRenderer. For instance, a ContainerStyle with TextElement
 * children will build a tree containing TextRenderer and BlockBoxRenderer
 * or InlineBoxRenderer.
 * Those objects know how to render themselves.
 * 
 * Styling is done in 2 phases : 
 * - first the styles of the DOMElement are computed into
 * usable values, for instance values defined as percentage
 * are converted to absolute values. During this phase, an
 * abstract rendering tree of the element is built, containing
 * an array of all its children (background, border, other DOMElements...)
 * ordered by z-index
 * - once all the styles are computed and the rendering tree is ready, it
 * renders itself
 * 
 * This class implements the default behaviour of an embedded DOMElement
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
	
	private var _color:ColorValue;
	public var color(getColor, setColor):ColorValue;
	
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
	 * determine wether the DOMElement and its chidlren must
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
	 * Class constructor. Stores the target DOMElement.
	 * Init the class attributes
	 * 
	 * The style is invalid by default and will be updated
	 * when the DOMElement is added to the DOM.
	 */
	public function new(htmlElement:HTMLElement) 
	{
		this._htmlElement = htmlElement;
		this._isDirty = true;
		
		initDefaultStyleValues();
	}
	
	/**
	 * Init the standard default value for styles
	 */
	private function initDefaultStyleValues():Void
	{
		initComputedStyles();
		
		this.width = Dimension.cssAuto;
		this.height = Dimension.cssAuto;
		
		this.minWidth = ConstrainedDimension.length(px(0));
		this.maxWidth = ConstrainedDimension.none;
		this.minHeight = ConstrainedDimension.length(px(0));
		this.maxHeight = ConstrainedDimension.none;
		
		this.marginTop = Margin.length(px(0));
		this.marginBottom = Margin.length(px(0));
		this.marginLeft = Margin.length(px(0));
		this.marginRight = Margin.length(px(0));
		
		this.paddingTop = Padding.length(px(0));
		this.paddingBottom = Padding.length(px(0));
		this.paddingLeft = Padding.length(px(0));
		this.paddingRight = Padding.length(px(0));
		
		this.lineHeight = LineHeight.normal;
		this.verticalAlign = VerticalAlign.baseline;
		
		this.display = Display.inlineStyle;
		this.position = Position.staticStyle;
		
		this.top = PositionOffset.cssAuto;
		this.bottom = PositionOffset.cssAuto;
		this.left = PositionOffset.cssAuto;
		this.right = PositionOffset.cssAuto;
		
		this.cssFloat = CSSFloat.none;
		this.clear = Clear.none;
		
		this.backgroundColor = ColorValue.transparent;
		this.backgroundImage = [BackgroundImage.none];
		this.backgroundRepeat = [{
			x:BackgroundRepeatValue.repeat,
			y:BackgroundRepeatValue.repeat
		}];
		this.backgroundPosition = [{
			x:BackgroundPositionX.percent(0),
			y:BackgroundPositionY.percent(0)
		}];
		this.backgroundOrigin = [BackgroundOrigin.paddingBox];
		this.backgroundSize = [
			BackgroundSize.dimensions({
				x:BackgroundSizeDimension.cssAuto,
				y:BackgroundSizeDimension.cssAuto
			})];
		this.backgroundClip = [BackgroundClip.borderBox];	
		
		this.fontStyle = FontStyle.normal;
		this.fontVariant = FontVariant.normal;
		this.fontWeight = FontWeight.normal;
		this.fontSize = FontSize.absoluteSize(FontSizeAbsoluteSize.medium);
		
		this.textIndent = TextIndent.length(px(0));
		this.textAlign = TextAlign.left;
		this.letterSpacing = LetterSpacing.normal;
		this.wordSpacing = WordSpacing.normal;
		this.textTransform = TextTransform.none;
		this.whiteSpace = WhiteSpace.normal;
		
		this.visibility = Visibility.visible;
		this.opacity = 1.0;
		this.overflowX = Overflow.visible;
		this.overflowY = Overflow.visible;
		
		this.transformOrigin = {
			x:TransformOriginX.center,
			y:TransformOriginY.center
		}
		
		this.transform = Transform.none;
		
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
			clear : Clear.none,
			cssFloat : CSSFloat.none,
			display : Display.block,
			position: Position.staticStyle,
			verticalAlign : 0.0,
			fontSize:12.0,
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
			backgroundRepeat:[]
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
			color:ColorValue.keyword(ColorKeyword.black)
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
		
		parentElementRenderer.addChild(elementRenderer);
		
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
	 * @param	containingDOMElementData the dimensions of the parent DOMElement into which 
	 * this DOMElement must be laid out
	 * @param	lastPositionedDOMElementData the dimensions of the first ancestor DOMElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' style other than 'static'. When positioning an absolutely positioned DOMElement (a DOMElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned DOMElement
	 * (a DOMElement with a 'position' of 'fixed'), it is used as origin
	 * @param containingDOMElementFontMetricsData contains font metrics of the parent DOMElement, used for instance
	 * to layout children in an inline formatting context
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
	 * The DOMElement first compute its own styles (box model, font, text...), then insert its ElementRenderer into the document based 
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
	 * @param	formattingContext can be an inline or block formatting context. "In-flow" DOMElements insert themselves into the 
	 * formattingContext to be placed in the document flow
	 * @param parentElementRenderer the parent node in the rendering tree
	 */
	public function flow(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext, parentElementRenderer:FlowBoxRenderer):Void
	{		
		if (_elementRenderer != null && parentElementRenderer != null)
		{
			parentElementRenderer.removeChild(_elementRenderer);
		}
		
		//do nothing if the DOMElement must not be displayed, i.e, added
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
		
		//compute all the styles of a DOMElement
		computeDOMElementStyles(containingDOMElementData, viewportData, lastPositionedDOMElementData.data, containingDOMElementFontMetricsData);
		
		//the DOMElement creates its own ElementRenderer
		_elementRenderer = createElementRenderer(parentElementRenderer);
		
		//flow all the children of the DOMElement if it has any
		flowChildren(containingDOMElementData, viewportData, lastPositionedDOMElementData, containingDOMElementFontMetricsData, formattingContext);
		
		//when all the dimensions of the domElement are known, compute the 
		//visual effects to apply (visibility, opacity, transform)
		//it is necessary to wait for all dimensions to be known because for
		//instance the transform style use the height and width of the DOMElement
		//to determine the transformation center
		computeVisualEffectStyles();
		
		//some text and font styles needs to be re-computed now that all the dimension
		//of the DOMElement are known, for instance some values of the VerticalAlign style
		//might need those dimensions to compute the right values
		computeTextAndFontStyles(containingDOMElementData, containingDOMElementFontMetricsData);
		
		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		computeBackgroundStyles();
		
		//insert the DOMElement in its parent's formatting context based on its positioning scheme
		insertDOMElement(formattingContext, lastPositionedDOMElementData, viewportData);
		
		//The DOMElement has been laid out and is now valid
		this._isDirty = false;
	}
	
	/**
	 * Place a positioned DOMElement (a DOMElement with a position style of 'relative', 'absolute', or 'fixed') using either the normal
	 * flow, the last positioned DOMElement or the viewport of the document, then apply an offset defined by the 'top',
	 * 'left', 'bottom' and 'right' computed styles values
	 * 
	 * @param lastPositionedDOMElementData
	 * @param viewportData
	 * @param staticPosition the x,y position that the DOMElement would have had if it were 'in-flow'
	 */
	public function positionElement(lastPositionedDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, staticPosition:PointData):ElementRenderer
	{
		//instantiate the right positioner
		//class based on the value of the 'position' style
		var positioner:BoxPositioner;
		
		switch (this._htmlElement.style.computedStyle.position)
		{
			//positioned 'relative' DOMElement
			case relative:
				positioner = new RelativePositioner();
				_elementRenderer = positioner.position(_elementRenderer, lastPositionedDOMElementData, staticPosition);
			
			//positioned 'fixed' DOMElement, use the viewport
			case fixed:
				positioner = new FixedPositioner();
				_elementRenderer = positioner.position(_elementRenderer, viewportData, staticPosition);
				
			//positioned 'absolute' DOMElement	
			case absolute:
				positioner = new AbsolutePositioner();
				_elementRenderer = positioner.position(_elementRenderer, lastPositionedDOMElementData, staticPosition);
				
			default:
		}
		
		//update the bounds of the ElementRenderer
		_elementRenderer.bounds.width = _htmlElement.offsetWidth;
		_elementRenderer.bounds.height = _htmlElement.offsetHeight;
		
		return _elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a timer to trigger a layout of the DOMElement asynchronously. this method is used by the invalidation
	 * mechanism. Setting a timer to execute the layout ensure that the layout only happen once when a series of style
	 * values are set instead of happening for every change.
	 */
	private function scheduleLayout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		var layoutDelegate:ContainingDOMElementData->LastPositionedDOMElementData->ContainingDOMElementData->FontMetricsData->Void = layout;
		
		Timer.delay(function () { 
			layoutDelegate(containingDOMElementData, lastPositionedDOMElementData, viewportData, null);
		}, 1);
	}
	
	/**
	 * Flow all the children of a DOMElement if it has any
	 */
	private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		
	}
	
	/**
	 * Insert the DOMElement in the document, in or out of the flow.
	 * 
	 * @param	formattingContext the formatting context into which the DOMElement insert itself if it
	 * is 'in flow'
	 * @param	lastPositionedDOMElementData
	 * @param	viewportData
	 */
	private function insertDOMElement(formattingContext:FormattingContext, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		//insert in the flow
		if (isPositioned() == false)
		{
			formattingContext.insertElement(_elementRenderer);
		}
		//else the DOMElement is positioned
		else
		{
			
			//retrieve the static position (the position of the DOMElement
			//if its position style were 'static')
			var staticPosition:PointData = formattingContext.getStaticPosition(_elementRenderer);
			//a relative DOMElement is both inserted in the flow
			//and positioned
			//
			//TODO : relative element are not placed correctly when a margin is applied to the formatting
			//context root
			if (isRelativePositioned() == true)
			{
				formattingContext.insertElement(_elementRenderer);
			}
			
			//insert as a positioned DOMElement.
			//an absolutely positioned DOMElement is not positioned right away, it must
			//wait for its first positioned ancestor to be laid out. The reason is that
			//if the positioned ancestor height is 'auto', the height of the positioned
			//ancestor is not yet determined and so this DOMElement can't be positioned
			//using the bottom or right style yet. Once the first ancestor is laid out, it
			//calls the positionElement method on all the stored positioned children
			//
			//relative positioned DOMElement are also stored in that array
			//
			var positionedDOMElementData:PositionedDOMElementData = {
				staticPosition:staticPosition,
				style:this
			}
			
			//store the DOMElement to be positioned later
			lastPositionedDOMElementData.children.push(positionedDOMElementData);
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
	 * An invalidated DOMElement will in turn invalidate its
	 * parent and so on until the root DOMElement (most likely
	 * a BodyDOMElement) is invalidated.
	 * The root DOMElement will then layout itself, laying out
	 * at the same time all its invalidated children.
	 * 
	 * In some cases, only a partial re-layout of the DOM tree
	 * is required, thus increasing performance
	 */
	public function invalidate():Void
	{
		//only invalidate the parent if it isn't
		//done already
		if (this._isDirty == false)
		{
			//set the dirty flag to prevent multiple
			//layout of the DOMElement in a row
			//The DOMElement will be able to be invalidated
			//again once it has been laid out
			this._isDirty = true;
			
			//if the DOMElement doesn't have a parent, then it
			//is not currently added to the DOM and doesn't require
			//a layout
			if (this._htmlElement.parentNode != null)
			{
				//dirties its parent if it must
				if (isParentDirty() == true)
				{
					var parent:HTMLElement = cast(_htmlElement.parentNode);
					parent.style.invalidate();	
				}
				//else schedule a layout for this DOMElement
				else
				{
					var parent:HTMLElement = cast(_htmlElement.parentNode);
					//retrieve its parent and the viewport dimension
					var parentStyle:ContainerStyle = cast(parent.style);
					var containingDOMElementData:ContainingDOMElementData = parentStyle.getContainerDOMElementData();
					
					var viewPortData:ContainingDOMElementData = getWindowData();
					
					//get the data of the first positioned ancestor of this styled DOMElement
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
	// PRIVATE INVALIDATION METHODS
	// Those method allow for
	// the re-layout of only a part of the DOM tree
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a position offset style changes (top, left, 
	 * right, bottom), it only requires a layout if the
	 * DOMElement is positioned (not static).
	 */
	private function invalidatePositionOffset():Void
	{
		if (isPositioned() == false)
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
	 * to be dirtied too. 
	 * 
	 * TODO : implement this method
	 */
	private function isParentDirty():Bool
	{
		var ret:Bool = true;
		
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method computes the styles determing
	 * the DOMElement's layout scheme :
	 * position, display, float and clear.
	 * 
	 * It is public as it may be called by the
	 * ContainerStyle of the parent DOMElement
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
	 * color, images... of a DOMElement
	 */
	private function computeBackgroundStyles():Void
	{
		BackgroundStylesComputer.compute(this);
	}
	
	/**
	 * Compute first the styles determining the DOMElement's
	 * positioning scheme (position, float, clear...),
	 * the style detemining font and text display,
	 * then the styles determining its box model (width, height, margins
	 * paddings...) which are computed last because they may use
	 * some font metrics to compute the box model, for instance
	 * when a dimension is defined with an 'em' unit
	 */
	private function computeDOMElementStyles(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{
		computeDisplayStyles();
		computeTextAndFontStyles(containingDOMElementData, containingDOMElementFontMetricsData);
		computeBoxModelStyles(containingDOMElementData, viewportData, lastPositionedDOMElementData);
	}
	
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
				
				case none:
					boxComputer = new NoneBoxStylesComputer();
				
				case inlineStyle:
					boxComputer = new EmbeddedInlineBoxStylesComputer();
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
					width:lastPositionedDOMElementData.width,
					height:lastPositionedDOMElementData.height,
					isHeightAuto:lastPositionedDOMElementData.isHeightAuto,
					isWidthAuto:lastPositionedDOMElementData.isWidthAuto};
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
	 * Determine if the DOMElement is a floated
	 * DOMElement. A floated DOMElement is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its container.
	 * Any subsequent DOMElement flows
	 * around the float until a new line 
	 * starts below the float or if it is cleared
	 * by another DOMElement.
	 * 
	 * A DOMElement is float if he declares either
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
	public function isRelativePositioned():Bool
	{
		return this._computedStyle.position == relative;
	}
	
	/**
	 * Determine if all the children of the 
	 * DOMElement are inline-level. 
	 * Default is false when the DOMElement
	 * can't have children
	 */
	public function childrenInline():Bool
	{
		return false;
	}
	
	/**
	 * An inline-level DOMElement is one that is
	 * laid out on a line. It will be placed
	 * either next to the preceding DOMElement
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
			case inlineStyle, inlineBlock:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Wheter this DOMElement starts a new
	 * formatting context for its children.
	 * Default is false as only ContainerDOMElements
	 * can start new formatting context
	 */
	public function establishesNewFormattingContext():Bool
	{
		return false;
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
			case Clear.left, Clear.right, Clear.both:
				ret = true;
			
			case Clear.none:
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
		return this._computedStyle.display == Display.none;
	}
	
	/**
	 * Get the dimensions of the first ancestor
	 * of the styled DOMElement which is positioned
	 */
	private function getFirstPositionedAncestorData():ContainingDOMElementData
	{
		var firstPositionedAncestorData:ContainingDOMElementData;
		var parent:HTMLElement = cast(_htmlElement.parentNode);
		
		//if the domElement has a parent
		if (parent != null)
		{
			//loop in all the parents until a positioned or a null parent is found
			var isPositioned:Bool = parent.style.isPositioned();
			while (isPositioned == false)
			{
				if (parent.parentNode != null)
				{
					parent = cast(parent.parentNode);
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
			firstPositionedAncestorData = getWindowData();
		}
		
		return firstPositionedAncestorData;
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingDOMElementData
	{
		var window:Window = new Window();
					
		var windowData:ContainingDOMElementData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:window.innerWidth,
			height:window.innerHeight
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
		invalidateMargin();
		return _marginLeft = value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		invalidateMargin();
		return _marginRight = value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		invalidateMargin();
		return _marginTop = value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		invalidateMargin();
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
		invalidatePositionOffset();
		return _top = value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		invalidatePositionOffset();
		return _left = value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		invalidatePositionOffset();
		return _bottom = value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		invalidatePositionOffset();
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
	
	private function setColor(value:ColorValue):ColorValue
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
	
	private function getColor():ColorValue
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
}