/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.FontManager;
import cocktail.core.geom.Matrix;
import cocktail.core.NativeElement;
import cocktail.core.background.BackgroundManager;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.DisplayStylesComputer;
import cocktail.core.style.computer.FontAndTextStylesComputer;
import cocktail.core.style.computer.VisualEffectStylesComputer;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.EmbeddedBoxRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import haxe.Log;
import haxe.Timer;

/**
 * This is the base class for all Style classes. Style classes
 * are in charge of storing the style value for an HTMLElement
 * and computing them into usable values. For instance values
 * defined as percentage are converted to absolute pixel values.
 * 
 * @author Yannick DOMINGUEZ
 */
class CoreStyle 
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
	
	private var _zIndex:ZIndex;
	public var zIndex(getZIndex, setZIndex):ZIndex;
	
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
	
	private var _fontFamily:Array<String>;
	public var fontFamily(getFontFamily, setFontFamily ):Array<String>;
	
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
	public var computedStyle(get_computedStyle, set_computedStyle):ComputedStyleData;
		
	/**
	 * Returns metrics info for the currently defined
	 * font and font size. Used in inline formatting context
	 * to determine lineBoxes sizes and text vertical and horizontal
	 * position
	 */
	private var _fontMetrics:FontMetricsData;
	public var fontMetrics(get_fontMetricsData, never):FontMetricsData;
	
	/**
	 * Store a reference to the styled HTMLElement
	 */
	private var _htmlElement:HTMLElement;
	public var htmlElement(get_htmlElement, never):HTMLElement;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Class constructor. Set default values
	 * for styles
	 */
	public function new(htmlElement:HTMLElement) 
	{
		_htmlElement = htmlElement;
		initDefaultStyleValues(htmlElement.tagName);
	}
	
	/**
	 * Init the standard default value for styles,
	 * using the tag name of the styled HTMLElement
	 */
	private function initDefaultStyleValues(tagName:String):Void
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
		
		_zIndex = ZIndex.cssAuto;
		
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
		
		applyDefaultHTMLStyles(tagName);
	}
	
	/**
	 * reset/init the computed style structures
	 */
	public function initComputedStyles():Void
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
			fontFamily:["serif"],
			fontVariant:FontVariant.normal,
			textTransform:TextTransform.none,
			letterSpacing:0,
			wordSpacing:0,
			textIndent:0,
			whiteSpace:WhiteSpace.normal,
			textAlign:TextAlign.left,
			color:{color:0, alpha:1.0},
			visibility:true,
			zIndex:ZIndex.cssAuto,
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
			fontFamily:["serif"],
			color:Color.keyword(ColorKeyword.black)
		}
	}
	
	/**
	 * Apply the standard default CSS value according to this
	 * document : http://www.w3.org/TR/CSS21/sample.html
	 * 
	 * TODO : This method should eventually be removed when a StyleManager
	 * is introduced which will prevent those styles from being hard-coded
	 */
	private function applyDefaultHTMLStyles(tagName:String):Void
	{
		switch (tagName)
		{
			case "html", "adress",
			"dd", "div", "dl", "dt", "fieldset",
			"form", "frame", "frameset", "noframes", "ol",
			"center", "dir", "hr", "menu" :
				_display = Display.block;
				
			//TODO : should be replaced by list-item once implemented	
			case "li" :
				_display = Display.block;
				
			case "ul":
				_display = Display.block;
				_marginTop = _marginBottom = Margin.length(em(1.12));
				_marginLeft = Margin.length(px(40));
				
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
				_marginTop = _marginBottom = Margin.length(em(1));	
				
			case "pre" : 
				_display = Display.block;
				_whiteSpace = WhiteSpace.pre;
				_fontFamily = ["monospace"];
				
			case "code" :
				_fontFamily = ["monospace"];
				
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
	// PUBLIC COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method computes the styles determing
	 * the HTMLElement's layout scheme :
	 * position, display, float and clear.
	 */
	public function computeDisplayStyles():Void
	{
		DisplayStylesComputer.compute(this);
	}
	
	/**
	 * Computes the styles determining the background
	 * color, images... of an HTMLElement
	 */
	public function computeBackgroundStyles():Void
	{
		BackgroundStylesComputer.compute(this);
	}
	
	/**
	 * Compute the visual effect styles (opacity, visibility, transformations)
	 */
	public function computeVisualEffectStyles():Void
	{
		VisualEffectStylesComputer.compute(this);
	}
	
	/**
	 * Computes the HTMLElement font and text styles (font size, font name, text color...)
	 */
	public function computeTextAndFontStyles(containingBlockData:ContainingBlockData, containingBlockFontMetricsData:FontMetricsData):Void
	{
		FontAndTextStylesComputer.compute(this, containingBlockData, containingBlockFontMetricsData);
	}
	
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the HTMLElement, based on
	 * its positioning scheme
	 */ 
	public function computeBoxModelStyles(containingBlockDimensions:ContainingBlockData, isReplaced:Bool):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer(isReplaced);
		
		//do compute the box model styles
		boxComputer.measure(this, containingBlockDimensions);
	}
	
	/**
	 * In most cases, when the height of a HTMLElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	childrenHeight the total height of the children once laid out
	 */
	public function applyContentHeightIfNeeded(containingBlockDimensions:ContainingBlockData, childrenHeight:Int, isReplaced:Bool):Int
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer(isReplaced);		
		return boxComputer.applyContentHeight(this, containingBlockDimensions, childrenHeight);
	}
	
	/**
	 * In certain cases, when the width of the HTMLElement is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this HTMLElement is indeed shrinked, all
	 * its children are laid out again
	 * 
	 * @param	containingBlockData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this HTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	public function shrinkToFitIfNeeded(containingBlockData:ContainingBlockData, minimumWidth:Int, isReplaced:Bool):Int
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer(isReplaced);
		return boxComputer.shrinkToFit(this, containingBlockData, minimumWidth);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE COMPUTING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the right class used to compute the box model
	 * styles
	 * @param	isReplaced wether the HTMLElement whose styles are computed
	 * is replaced
	 */
	private function getBoxStylesComputer(isReplaced:Bool):BoxStylesComputer
	{
		if (isReplaced == true)
		{
			return getReplacedBoxStylesComputer();
		}
		else
		{
			return getFlowBoxStylesComputer();
		}
	}
		
	/**
	 * Return box style computer for container box
	 */
	private function getFlowBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
				
		//get the box computer for float
		if (_computedStyle.cssFloat == CSSFloat.left || _computedStyle.cssFloat == CSSFloat.right)
		{
			boxComputer = new FloatBoxStylesComputer();
		}
		
		//get it for HTMLElement with 'position' value of 'absolute' or 'fixed'
		else if (_computedStyle.position == fixed || _computedStyle.position == absolute)
		{
			boxComputer = new PositionedBoxStylesComputer();
		}
		
		//else get the box computer based on the display style
		else
		{
			switch(this.computedStyle.display)
			{
				case block:
					boxComputer = new BlockBoxStylesComputer();
					
				case inlineBlock:
					boxComputer = new InlineBlockBoxStylesComputer();
				
				//not supposed to happen
				case none:
					
					boxComputer = null;
				
				case cssInline:
					boxComputer = new InLineBoxStylesComputer();
			}
		}
		
		return boxComputer;
	}
	
	/**
	 * Return box style computer for replaced box
	 */
	private function getReplacedBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
		
		//get the embedded box computers based on
		//the positioning scheme
		if (_computedStyle.cssFloat == CSSFloat.left || _computedStyle.cssFloat == CSSFloat.right)
		{
			boxComputer = new EmbeddedFloatBoxStylesComputer();
		}
		else if (_computedStyle.position == fixed || _computedStyle.position == absolute)
		{
			boxComputer = new EmbeddedPositionedBoxStylesComputer();
		}
		else
		{
			switch(this.computedStyle.display)
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
	 * TODO : what to do when the value of a style changes ?
	 * Invalidate the HTMLElement which in turn invalidate
	 * ElementRenderer or set _coreStyle on ElementRenderer ?
	 * 
	 * TODO : should always be called AFTER style is set, it
	 * only works for now because of the timer
	 */
	private function invalidate():Void
	{
		_htmlElement.invalidateLayout();
	}
	
	private function invalidateDisplay():Void
	{
		_htmlElement.invalidateDisplay();
	}
	
	private function invalidateLayer():Void
	{
		_htmlElement.invalidateLayer();
	}
	
	private function invalidateText():Void
	{
		_htmlElement.invalidateText();
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////

	private function get_computedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
	private function set_computedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _computedStyle = value;
	}

	private function get_fontMetricsData():FontMetricsData
	{
		var fontManager:FontManager = new FontManager();
		_fontMetrics = fontManager.getFontMetrics(UnitManager.getCSSFontFamily(computedStyle.fontFamily), computedStyle.fontSize);
	
		return _fontMetrics;
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
		_width = value;
		invalidate();
		return value;
	}
	
	private function setMarginLeft(value:Margin):Margin 
	{
		_marginLeft = value;
		invalidate();
		return value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		_marginRight = value;
		invalidate();
		return value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		_marginTop = value;
		invalidate();
		return value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		_marginBottom = value;
		invalidate();
		return value;
	}
	
	private function setPaddingLeft(value:Padding):Padding 
	{
		_paddingLeft = value;
		invalidate();
		return value;
	}
	
	private function setPaddingRight(value:Padding):Padding 
	{
		_paddingRight = value;
		invalidate();
		return value;
	}
	
	private function setPaddingTop(value:Padding):Padding 
	{
		_paddingTop = value;
		invalidate();
		return value;
	}
	
	private function setPaddingBottom(value:Padding):Padding 
	{
		_paddingBottom = value;
		invalidate();
		return value;
	}
	
	private function setDisplay(value:Display):Display 
	{
		_display = value;
		invalidateDisplay();
		return value;
	}
	
	private function setPosition(value:Position):Position 
	{
		_position = value;
		invalidateLayer();
		return value;
	}
	
	private function setHeight(value:Dimension):Dimension 
	{
		_height = value;
		invalidate();
		return value;
	}
	
	private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		_minHeight = value;
		invalidate();
		return value;
	}
	
	private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		_maxHeight = value;
		invalidate();
		return value;
	}
	
	private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		_minWidth = value;
		invalidate();
		return value;
	}
	
	private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		_maxWidth = value;
		invalidate();
		return value;
	}
	
	private function setTop(value:PositionOffset):PositionOffset 
	{
		_top = value;
		invalidate();
		return value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		_left = value;
		invalidate();
		return value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		_bottom = value;
		invalidate();
		return value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		_right = value;
		invalidate();
		return value;
	}
	
	private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		_cssFloat = value;
		invalidate();
		return value;
	}
	
	private function setClear(value:Clear):Clear 
	{
		_clear = value;
		invalidate();
		return value;
	}
	
	private function setZIndex(value:ZIndex):ZIndex 
	{
		_zIndex = value;
		invalidateLayer();
		return value;
	}
	
	private function setFontSize(value:FontSize):FontSize
	{
		_fontSize = value;
		invalidateText();
		return value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		_fontWeight = value;
		invalidateText();
		return value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		_fontStyle = value;
		invalidateText();
		return value;
	}
	
	private function setFontFamily(value:Array<String>):Array<String>
	{
		_fontFamily = value;
		invalidateText();
		return value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		_fontVariant = value;
		invalidateText();
		return value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		_textTransform = value;
		invalidateText();
		return value;
	}
	
	private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		_letterSpacing = value;
		invalidateText();
		return value;
	}
	
	private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		_wordSpacing = value;
		invalidateText();
		return value;
	}
	
	private function setLineHeight(value:LineHeight):LineHeight
	{
		_lineHeight = value;
		invalidate();
		return value;
	}
	
	private function setColor(value:Color):Color
	{
		_color = value;
		invalidateText();
		return value;
	}
	
	private function setVerticalAlign(value:VerticalAlign):VerticalAlign
	{
		_verticalAlign = value;
		invalidate();
		return value;
	}
	
	private function setTextIndent(value:TextIndent):TextIndent
	{
		_textIndent = value;
		invalidate();
		return value;
	}
	
	private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		_whiteSpace = value;
		invalidate();
		return value;
	}
	
	private function setTextAlign(value:TextAlign):TextAlign
	{
		 _textAlign = value;
		invalidate();
		return value;
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
		_transformOrigin = value;
		invalidate();
		return value;
	}
	
	private function setTransform(value:Transform):Transform
	{
		_transform = value;
		invalidate();
		return value;
	}
	
	private function setOverflowX(value:Overflow):Overflow
	{
		_overflowX = value;
		invalidateLayer();
		return value;
	}
	
	private function setOverflowY(value:Overflow):Overflow
	{
		_overflowY = value;
		invalidateLayer();
		return value;
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
	
	private function getZIndex():ZIndex 
	{
		return _zIndex;
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
	
	private function getFontFamily():Array<String>
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
		_backgroundColor = value;
		invalidate();
		return value;
	}
	
	private function getBackgroundColor():BackgroundColor
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		_backgroundImage = value;
		invalidate();
		return value;
	}
	
	private function getBackgroundImage():Array<BackgroundImage>
	{
		return _backgroundImage;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		invalidate();
		return _backgroundRepeat = value;
	}
	
	private function getBackgroundRepeat():Array<BackgroundRepeat>
	{
		return _backgroundRepeat;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		_backgroundSize = value;
		invalidate();
		return value;
	}
	
	private function getBackgroundSize():Array<BackgroundSize>
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		_backgroundClip = value;
		invalidate();
		return value;
	}
	
	private function getBackgroundClip():Array<BackgroundClip>
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		_backgroundPosition = value;
		invalidate();
		return value;
	}
	
	private function getBackgroundPosition():Array<BackgroundPosition>
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		_backgroundOrigin = value;
		invalidate();
		return value;
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