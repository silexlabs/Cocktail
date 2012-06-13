/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.event.TransitionEvent;
import cocktail.core.FontManager;
import cocktail.core.geom.Matrix;
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
import cocktail.core.style.transition.Transition;
import cocktail.core.style.transition.TransitionManager;
import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import haxe.Log;
import haxe.Timer;
import cocktail.core.style.ComputedStyle;
import cocktail.core.renderer.RendererData;

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
	
	/**
	 * transition styles
	 */
	private var _transitionProperty:TransitionProperty;
	public var transitionProperty(getTransitionProperty, setTransitionProperty):TransitionProperty;
	
	private var _transitionDuration:TransitionDuration;
	public var transitionDuration(getTransitionDuration, setTransitionDuration):TransitionDuration;
	
	private var _transitionDelay:TransitionDelay;
	public var transitionDelay(getTransitionDelay, setTransitionDelay):TransitionDelay;
	
	private var _transitionTimingFunction:TransitionTimingFunction;
	public var transitionTimingFunction(getTransitionTimingFunction, setTransitionTimingFunction):TransitionTimingFunction;
	
	////////////////////////////////
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	private var _computedStyle:ComputedStyle;
	public var computedStyle(get_computedStyle, set_computedStyle):ComputedStyle;
		
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
		_computedStyle = new ComputedStyle(this);
		initComputedStyles();
		
		_width = getWidthDefaultValue();
		_height = getHeightDefaultValue();
		
		_minWidth = getMinWidthDefaultValue();
		_maxWidth = getMaxWidthDefaultValue();
		_minHeight = getMinHeightDefaultValue();
		_maxHeight = getMaxHeightDefaultValue();
		
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
		
		_transitionDelay = [TimeValue.seconds(0)];
		_transitionDuration = [TimeValue.seconds(0)];
		_transitionProperty = TransitionProperty.all;
		_transitionTimingFunction = [TransitionTimingFunctionValue.ease];
		
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
		_computedStyle.init();
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
	 * TODO 5 : This method should eventually be removed when a StyleManager
	 * is introduced which will prevent those styles from being hard-coded
	 * 
	 * TODO 4 : use HTMLConstants
	 */
	private function applyDefaultHTMLStyles(tagName:String):Void
	{
		switch (tagName.toLowerCase())
		{
			case "html", "adress",
			"dd", "div", "dl", "dt", "fieldset",
			"form", "frame", "frameset", "noframes", "ol",
			"center", "dir", "hr", "menu" :
				_display = Display.block;
				
			//TODO 5 : should be replaced by list-item once implemented	
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
	// PUBLIC STATIC DEFAULT STYLES METHODS
	// Those methods returns the default value for each CSS style
	//////////////////////////////////////////////////////////////////////////////////////////

	//TODO 2 : need to complete this and complete default styles in UnitManager
	
	public static function getBackgroundColorDefaultValue():BackgroundColor
	{
		return BackgroundColor.transparent;
	}
	
	public static function getDisplayDefaultValue():Display
	{
		return Display.cssInline;
	}
	
	public static function getPositionDefaultValue():Position
	{
		return Position.cssStatic;
	}
	
	public static function getWidthDefaultValue():Dimension
	{
		return Dimension.cssAuto;
	}
	
	public static function getHeightDefaultValue():Dimension
	{
		return Dimension.cssAuto;
	}
	
	public static function getMinHeightDefaultValue():ConstrainedDimension
	{
		return ConstrainedDimension.length(px(0));
	}
	
	public static function getMinWidthDefaultValue():ConstrainedDimension
	{
		return ConstrainedDimension.length(px(0));
	}
	
	public static function getMaxWidthDefaultValue():ConstrainedDimension
	{
		return ConstrainedDimension.none;
	}
	
	public static function getMaxHeightDefaultValue():ConstrainedDimension
	{
		return ConstrainedDimension.none;
	}
	
	public static function getMarginDefaultValue():Margin
	{
		return Margin.length(px(0));
	}
	
	public static function getPaddingDefaultValue():Padding
	{
		return Padding.length(px(0));
	}
	
	public static function getLineHeightDefaultValue():LineHeight
	{
		return LineHeight.normal;
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
	 * Compute the visual effect styles (opacity, visibility, transformations, transition)
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
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when a style necesiting invalidation of the
	 * layout of the HTMLElement is changed
	 */
	private function invalidate(invalidationReason:InvalidationReason):Void
	{
		_htmlElement.invalidate(invalidationReason);
	}
	
	/**
	 * Same as above for display
	 */
	private function invalidateDisplay():Void
	{
		_htmlElement.invalidateDisplay();
	}
	
	/////////////////////////////////
	// TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * When the specified value of a style changes, starts
	 * a transition for the proeprty if needed using the
	 * TransitionManager
	 * 
	 * @param	propertyName the name of the property whose
	 * value changed
	 */
	private function startTransitionIfNeeded(propertyName:String):Void
	{	
		//will store the index of the property in the TransitionPorperty
		//array, so that its duration, delay, and timing function can be found
		//at the same index
		var propertyIndex:Int = 0;
		
		//check if the changed property is supposed to be transitioned
		switch (computedStyle.transitionProperty)
		{
			//if none, the method returns here as no property
			//of this style should be transitioned
			case TransitionProperty.none:
				return;
			
			//here, check in the list of transitionable property
			//for a match
			case TransitionProperty.list(value):
				var foundFlag:Bool = false;
				
				for (i in 0...value.length)
				{
					//if there is a match, store the index
					//of the match
					if (value[i] == propertyName)
					{
						propertyIndex = i;
						foundFlag = true;
						break;
					}
				}
				
				//if there is no match, the method stops
				//here
				if (foundFlag == false)
				{
					return;
				}
				
			//here all property can transition. The index
			//will stay at 0
			case TransitionProperty.all:	
		}
		
		//return if transition style have not yet been computed
		//
		//TODO 2 : not supposed to happen, should be computed by this point
		if (computedStyle.transitionDelay.length == 0 || computedStyle.transitionDuration.length == 0)
		{
			return;
		}
		
		//the combined duration is the combined duration
		//and delay of the transition, 
		var combinedDuration:Float = 0.0;
		
		//get  the delay and duration of the transition in their respective array
		//using the same index as the one in the transitionproperty array
		var transitionDelay:Float = computedStyle.transitionDelay[getRepeatedIndex(propertyIndex, computedStyle.transitionDelay.length)];
		var transitionDuration:Float = computedStyle.transitionDuration[getRepeatedIndex(propertyIndex, computedStyle.transitionDuration.length)];
		combinedDuration = transitionDuration + transitionDelay;
		
		//if the combined duration is not superior to
		//0, then there is no transition
		if (combinedDuration <= 0)
		{
			return;
		}
		
		//get the transition timing function
		var transitionTimingFunction:TransitionTimingFunctionValue = computedStyle.transitionTimingFunction[getRepeatedIndex(propertyIndex,computedStyle.transitionTimingFunction.length)];
		
		//check if a transition is already in progress for the same property
		var transition:Transition = TransitionManager.getInstance().getTransition(propertyName, computedStyle);
		
		//if the transition is not null, then a transition is already
		//in progress, so it must first be stopped
		if (transition != null)
		{
			//TODO 1 : add the reverse transition case
			
			TransitionManager.getInstance().stopTransition(transition);
		}
		
		//get the starting value for the transition which is he current computed value of the 
		//style
		var startValue:Float = Reflect.getProperty(computedStyle, propertyName);
		
		//start an immediate invalidation, so that the the new specified value
		//of the style gets immediately computed, this value will be the end value
		//for the transition
		invalidate(InvalidationReason.needsImmediateLayout);
		var endValue:Float = Reflect.getProperty(computedStyle, propertyName);
		
		//start a transition using the TransitionManager
		TransitionManager.getInstance().startTransition(computedStyle, propertyName, startValue, endValue, 
		transitionDuration, transitionDelay, transitionTimingFunction, onTransitionComplete, onTransitionUpdate);
	}
	
	/**
	 * Utils method, which return, given
	 * an index and the length of an array, the 
	 * actual index to use by looping in the length
	 * if the length is inferior to the index
	 * 
	 * @example if the length is 2 and the index is 3,
	 * the returned index will be 0, as by looping in the length,
	 * the index will be 0,1,0
	 */
	private function getRepeatedIndex(index:Int, length:Int):Int
	{
		if (index < length)
		{
			return index;
		}
		
		return length % index;
	}
	
	/**
	 * When a transition is complete, invalidate the HTMLElement,
	 * then dispatch a transition end event
	 */
	private function onTransitionComplete(transition:Transition):Void
	{
		invalidate(InvalidationReason.other);
		var transitionEvent:TransitionEvent = new TransitionEvent();
		transitionEvent.initTransitionEvent(TransitionEvent.TRANSITION_END, true, true, transition.propertyName, transition.transitionDuration, "");
		_htmlElement.dispatchEvent(transitionEvent);
		
	}
	
	/**
	 * When a transition is updated, invalidate the HTMLElement
	 * to repaint the rendering tree
	 */
	private function onTransitionUpdate(transition:Transition):Void
	{
		invalidate(InvalidationReason.other);
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////

	private function get_computedStyle():ComputedStyle
	{
		return _computedStyle;
	}
	
	private function set_computedStyle(value:ComputedStyle):ComputedStyle
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
		//TODO 1 : if transition is successful, should invalidate still be called ?
		startTransitionIfNeeded(CSSConstants.WIDTH_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.WIDTH_STYLE_NAME));
		return value;
	}
	
	private function setMarginLeft(value:Margin):Margin 
	{
		_marginLeft = value;
		startTransitionIfNeeded(CSSConstants.MARGIN_LEFT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MARGIN_LEFT_STYLE_NAME));
		return value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		_marginRight = value;
		startTransitionIfNeeded(CSSConstants.MARGIN_RIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MARGIN_RIGHT_STYLE_NAME));
		return value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		_marginTop = value;
		startTransitionIfNeeded(CSSConstants.MARGIN_TOP_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MARGIN_TOP_STYLE_NAME));
		return value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		_marginBottom = value;
		startTransitionIfNeeded(CSSConstants.MARGIN_BOTTOM_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MARGIN_BOTTOM_STYLE_NAME));
		return value;
	}
	
	private function setPaddingLeft(value:Padding):Padding 
	{
		_paddingLeft = value;
		startTransitionIfNeeded(CSSConstants.PADDING_LEFT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.PADDING_LEFT_STYLE_NAME));
		return value;
	}
	
	private function setPaddingRight(value:Padding):Padding 
	{
		_paddingRight = value;
		startTransitionIfNeeded(CSSConstants.PADDING_RIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.PADDING_RIGHT_STYLE_NAME));
		return value;
	}
	
	private function setPaddingTop(value:Padding):Padding 
	{
		_paddingTop = value;
		startTransitionIfNeeded(CSSConstants.PADDING_TOP_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.PADDING_TOP_STYLE_NAME));
		return value;
	}
	
	private function setPaddingBottom(value:Padding):Padding 
	{
		_paddingBottom = value;
		startTransitionIfNeeded(CSSConstants.PADDING_BOTTOM_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.PADDING_BOTTOM_STYLE_NAME));
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
		_computedStyle.position = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.POSITION_STYLE_NAME));
		return value;
	}
	
	private function setHeight(value:Dimension):Dimension 
	{
		_height = value;
		startTransitionIfNeeded(CSSConstants.HEIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.HEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		_minHeight = value;
		startTransitionIfNeeded(CSSConstants.MIN_HEIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MIN_HEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		_maxHeight = value;
		startTransitionIfNeeded(CSSConstants.MAX_HEIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MAX_HEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		_minWidth = value;
		startTransitionIfNeeded(CSSConstants.MIN_WIDTH_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MIN_WIDTH_STYLE_NAME));
		return value;
	}
	
	private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		_maxWidth = value;
		startTransitionIfNeeded(CSSConstants.MAX_WIDTH_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.MAX_WIDTH_STYLE_NAME));
		return value;
	}
	
	private function setTop(value:PositionOffset):PositionOffset 
	{
		_top = value;
		startTransitionIfNeeded(CSSConstants.TOP_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.TOP_STYLE_NAME));
		return value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		_left = value;
		startTransitionIfNeeded(CSSConstants.LEFT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.LEFT_STYLE_NAME));
		return value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		_bottom = value;
		startTransitionIfNeeded(CSSConstants.BOTTOM_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.BOTTOM_STYLE_NAME));
		return value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		_right = value;
		startTransitionIfNeeded(CSSConstants.RIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.RIGHT_STYLE_NAME));
		return value;
	}
	
	private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		_cssFloat = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FLOAT_STYLE_NAME));
		return value;
	}
	
	private function setClear(value:Clear):Clear 
	{
		_clear = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.CLEAR_STYLE_NAME));
		return value;
	}
	
	private function setZIndex(value:ZIndex):ZIndex 
	{
		_zIndex = value;
		_computedStyle.zIndex = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.Z_INDEX_STYLE_NAME));
		return value;
	}
	
	private function setFontSize(value:FontSize):FontSize
	{
		_fontSize = value;
		startTransitionIfNeeded(CSSConstants.FONT_SIZE_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_SIZE_STYLE_NAME));
		return value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		_fontWeight = value;
		_computedStyle.fontWeight = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_WEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		_fontStyle = value;
		_computedStyle.fontStyle = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_STYLE_STYLE_NAME));
		return value;
	}
	
	private function setFontFamily(value:Array<String>):Array<String>
	{
		_fontFamily = value;
		_computedStyle.fontFamily = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_FAMILY_STYLE_NAME));
		return value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		_fontVariant = value;
		_computedStyle.fontVariant = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_VARIANT_STYLE_NAME));
		return value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		_textTransform = value;
		_computedStyle.textTransform = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TEXT_TRANSFORM_STYLE_NAME));
		return value;
	}
	
	private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		_letterSpacing = value;
		startTransitionIfNeeded(CSSConstants.LETTER_SPACING_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.LETTER_SPACING_STYLE_NAME));
		return value;
	}
	
	private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		_wordSpacing = value;
		startTransitionIfNeeded(CSSConstants.WORD_SPACING_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.WORD_SPACING_STYLE_NAME));
		return value;
	}
	
	private function setLineHeight(value:LineHeight):LineHeight
	{
		_lineHeight = value;
		startTransitionIfNeeded(CSSConstants.LINE_HEIGHT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.LINE_HEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setColor(value:Color):Color
	{
		_color = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.COLOR_STYLE_NAME));
		return value;
	}
	
	private function setVerticalAlign(value:VerticalAlign):VerticalAlign
	{
		_verticalAlign = value;
		startTransitionIfNeeded(CSSConstants.VERTICAL_ALIGN_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.VERTICAL_ALIGN_STYLE_NAME));
		return value;
	}
	
	private function setTextIndent(value:TextIndent):TextIndent
	{
		_textIndent = value;
		startTransitionIfNeeded(CSSConstants.TEXT_INDENT_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.TEXT_INDENT_STYLE_NAME));
		return value;
	}
	
	private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		_whiteSpace = value;
		_computedStyle.whiteSpace = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.WHITE_SPACE_STYLE_NAME));
		return value;
	}
	
	private function setTextAlign(value:TextAlign):TextAlign
	{
		_textAlign = value;
		_computedStyle.textAlign = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TEXT_ALIGN_STYLE_NAME));
		return value;
	}
	
	private function setOpacity(value:Opacity):Opacity
	{
		_opacity = value;
		_computedStyle.opacity = value;
		startTransitionIfNeeded(CSSConstants.OPACITY_STYLE_NAME);
		invalidate(InvalidationReason.styleChanged(CSSConstants.OPACITY_STYLE_NAME));
		return _opacity;
	}
	
	private function setVisibility(value:Visibility):Visibility
	{
		_visibility = value;
		_computedStyle.visibility = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.VISIBILITY_STYLE_NAME));
		return _visibility;
	}
	
	private function setTransformOrigin(value:TransformOrigin):TransformOrigin
	{
		_transformOrigin = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setTransform(value:Transform):Transform
	{
		_transform = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setOverflowX(value:Overflow):Overflow
	{
		_overflowX = value;
		_computedStyle.overflowX = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.OVERFLOW_X_STYLE_NAME));
		return value;
	}
	
	private function setOverflowY(value:Overflow):Overflow
	{
		_overflowY = value;
		_computedStyle.overflowY = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.OVERFLOW_Y_STYLE_NAME));
		return value;
	}
	
	private function setTransitionProperty(value:TransitionProperty):TransitionProperty
	{
		return _transitionProperty = value;
	}
	
	private function setTransitionDuration(value:TransitionDuration):TransitionDuration
	{
		return _transitionDuration = value;
	}
	
	private function setTransitionDelay(value:TransitionDelay):TransitionDelay
	{
		return _transitionDelay = value;
	}
	
	private function setTransitionTimingFunction(value:TransitionTimingFunction):TransitionTimingFunction
	{
		return _transitionTimingFunction = value;
	}
	
	private function setBackgroundColor(value:BackgroundColor):BackgroundColor
	{
		_backgroundColor = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		_backgroundImage = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		_backgroundSize = value;
		_computedStyle.backgroundSize = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		_backgroundClip = value;
		_computedStyle.backgroundClip = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		_backgroundPosition = value;
		_computedStyle.backgroundPosition = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		_backgroundRepeat = value;
		_computedStyle.backgroundRepeat = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		_backgroundOrigin = value;
		_computedStyle.backgroundOrigin = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setCursor(value:Cursor):Cursor
	{
		return _cursor = value;
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
	
	private function getBackgroundColor():BackgroundColor
	{
		return _backgroundColor;
	}
	
	private function getBackgroundImage():Array<BackgroundImage>
	{
		return _backgroundImage;
	}
	
	private function getBackgroundRepeat():Array<BackgroundRepeat>
	{
		return _backgroundRepeat;
	}
	
	private function getBackgroundSize():Array<BackgroundSize>
	{
		return _backgroundSize;
	}
	
	private function getBackgroundClip():Array<BackgroundClip>
	{
		return _backgroundClip;
	}
	
	private function getBackgroundPosition():Array<BackgroundPosition>
	{
		return _backgroundPosition;
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
	
	private function getCursor():Cursor
	{
		return _cursor;
	}
	
	private function getTransitionProperty():TransitionProperty
	{
		return _transitionProperty;
	}
	
	private function getTransitionDuration():TransitionDuration
	{
		return _transitionDuration;
	}
	
	private function getTransitionDelay():TransitionDelay
	{
		return _transitionDelay;
	}
	
	private function getTransitionTimingFunction():TransitionTimingFunction
	{
		return _transitionTimingFunction;
	}
}