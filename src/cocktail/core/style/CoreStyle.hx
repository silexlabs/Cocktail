/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.event.TransitionEvent;
import cocktail.port.FontManager;
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
	public var display(default, setDisplay):Display;
	public var position(default, setPosition):Position;
	public var cssFloat(default, setCSSFloat):CSSFloat;
	public var clear(default, setClear):Clear;
	public var zIndex(default, setZIndex):ZIndex;
	
	/**
	 * box model styles
	 */
	public var marginLeft(default, setMarginLeft):Margin;
	public var marginRight(default, setMarginRight):Margin;
	public var marginTop(default, setMarginTop):Margin;
	public var marginBottom(default, setMarginBottom):Margin;
	
	public var paddingLeft(default, setPaddingLeft):Padding;
	public var paddingRight(default, setPaddingRight):Padding;
	public var paddingTop(default, setPaddingTop):Padding;
	public var paddingBottom(default, setPaddingBottom):Padding;

	public var width(default, setWidth):Dimension;
	public var height(default, setHeight):Dimension;
	
	public var minHeight(default, setMinHeight):ConstrainedDimension;
	public var maxHeight(default, setMaxHeight):ConstrainedDimension;
	public var minWidth(default, setMinWidth):ConstrainedDimension;
	public var maxWidth(default, setMaxWidth):ConstrainedDimension;

	public var top(default, setTop):PositionOffset;
	public var left(default, setLeft):PositionOffset;
	public var bottom(default, setBottom):PositionOffset;
	public var right(default, setRight):PositionOffset;
	
	/**
	 * background styles
	 */
	public var backgroundColor(default, setBackgroundColor):BackgroundColor;
	public var backgroundImage(default, setBackgroundImage):Array<BackgroundImage>;
	public var backgroundRepeat(default, setBackgroundRepeat):Array<BackgroundRepeat>;
	public var backgroundOrigin(default, setBackgroundOrigin):Array<BackgroundOrigin>;
	public var backgroundSize(default, setBackgroundSize):Array<BackgroundSize>;
	public var backgroundPosition(default, setBackgroundPosition):Array<BackgroundPosition>;
	public var backgroundClip(default, setBackgroundClip):Array<BackgroundClip>;
	
	/**
	 * font styles
	 */
	public var fontSize(default, setFontSize):FontSize;
	public var fontWeight(default, setFontWeight):FontWeight;
	public var fontStyle(default, setFontStyle):FontStyle;
	public var fontFamily(default, setFontFamily ):Array<String>;
	public var fontVariant(default, setFontVariant):FontVariant;
	public var color(default, setColor):Color;
	
	/**
	 * text styles
	 */
	public var lineHeight(default, setLineHeight):LineHeight;
	public var textTransform(default, setTextTransform):TextTransform;
	public var letterSpacing(default, setLetterSpacing):LetterSpacing;
	public var wordSpacing(default, setWordSpacing):WordSpacing;
	public var whiteSpace(default, setWhiteSpace):WhiteSpace;
	public var textAlign(default, setTextAlign):TextAlign;
	public var textIndent(default, setTextIndent):TextIndent;
	public var verticalAlign(default, setVerticalAlign):VerticalAlign;
	
	/**
	 * visual effect styles
	 */
	public var opacity(default, setOpacity):Opacity;
	public var visibility(default, setVisibility):Visibility;
	public var overflowX(default,  setOverflowX):Overflow;
	public var overflowY(default,  setOverflowY):Overflow;
	public var transformOrigin(default, setTransformOrigin):TransformOrigin;
	public var transform(default, setTransform):Transform;
	
	/**
	 * user interface styles
	 */
	public var cursor(default, setCursor):Cursor;
	
	/**
	 * transition styles
	 */
	public var transitionProperty(default, setTransitionProperty):TransitionProperty;
	public var transitionDuration(default, setTransitionDuration):TransitionDuration;
	public var transitionDelay(default, setTransitionDelay):TransitionDelay;
	public var transitionTimingFunction(default, setTransitionTimingFunction):TransitionTimingFunction;
	
	////////////////////////////////
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	public var computedStyle:ComputedStyle;
		
	/**
	 * Returns metrics info for the currently defined
	 * font and font size. Used in inline formatting context
	 * to determine lineBoxes sizes and text vertical and horizontal
	 * position
	 */
	public var fontMetrics(get_fontMetricsData, null):FontMetricsData;
	
	/**
	 * Store a reference to the styled HTMLElement
	 */
	public var htmlElement(default, null):HTMLElement;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Class constructor. Set default values
	 * for styles
	 */
	public function new(htmlElement:HTMLElement) 
	{
		this.htmlElement = htmlElement;
		initDefaultStyleValues(htmlElement.tagName);
	}
	
	/**
	 * Init the standard default value for styles,
	 * using the tag name of the styled HTMLElement
	 */
	private function initDefaultStyleValues(tagName:String):Void
	{
		computedStyle = new ComputedStyle(this);
		initComputedStyles();
		
		width = getWidthDefaultValue();
		height = getHeightDefaultValue();
		
		minWidth = getMinWidthDefaultValue();
		maxWidth = getMaxWidthDefaultValue();
		minHeight = getMinHeightDefaultValue();
		maxHeight = getMaxHeightDefaultValue();
		
		marginTop = Margin.length(px(0));
		marginBottom = Margin.length(px(0));
		marginLeft = Margin.length(px(0));
		marginRight = Margin.length(px(0));
		
		paddingTop = Padding.length(px(0));
		paddingBottom = Padding.length(px(0));
		paddingLeft = Padding.length(px(0));
		paddingRight = Padding.length(px(0));
		
		lineHeight = LineHeight.normal;
		verticalAlign = VerticalAlign.baseline;
		
		display = Display.cssInline;
		position = Position.cssStatic;
		
		zIndex = ZIndex.cssAuto;
		
		top = PositionOffset.cssAuto;
		bottom = PositionOffset.cssAuto;
		left = PositionOffset.cssAuto;
		right = PositionOffset.cssAuto;
		
		cssFloat = CSSFloat.none;
		clear = Clear.none;
		
		backgroundColor = Color.transparent;
		backgroundImage = [BackgroundImage.none];
		backgroundRepeat = [{
			x:BackgroundRepeatValue.repeat,
			y:BackgroundRepeatValue.repeat
		}];
		backgroundPosition = getBackgroundPositionDefaultValue();
		backgroundOrigin = [BackgroundOrigin.paddingBox];
		backgroundSize = [
			BackgroundSize.dimensions({
				x:BackgroundSizeDimension.cssAuto,
				y:BackgroundSizeDimension.cssAuto
			})];
		backgroundClip = [BackgroundClip.borderBox];	
		
		fontStyle = FontStyle.normal;
		fontVariant = FontVariant.normal;
		fontWeight = FontWeight.normal;
		fontSize = FontSize.absoluteSize(FontSizeAbsoluteSize.medium);
		
		textIndent = TextIndent.length(px(0));
		textAlign = TextAlign.left;
		letterSpacing = LetterSpacing.normal;
		wordSpacing = WordSpacing.normal;
		textTransform = TextTransform.none;
		whiteSpace = WhiteSpace.normal;
		
		visibility = Visibility.visible;
		opacity = 1.0;
		overflowX = Overflow.visible;
		overflowY = Overflow.visible;
		
		transitionDelay = [TimeValue.seconds(0)];
		transitionDuration = [TimeValue.seconds(0)];
		transitionProperty = TransitionProperty.all;
		transitionTimingFunction = [TransitionTimingFunctionValue.ease];
		
		transformOrigin = {
			x:TransformOriginX.center,
			y:TransformOriginY.center
		}
		
		transform = Transform.none;
		
		cursor = Cursor.cssAuto;
		
		var defaultStyles:DefaultStylesData = getDefaultStyle();
		fontFamily = defaultStyles.fontFamily;
		color = defaultStyles.color;
		
		applyDefaultHTMLStyles(tagName);
	}
	
	/**
	 * reset/init the computed style structures
	 */
	public function initComputedStyles():Void
	{
		computedStyle.init();
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
			color:getColorDefaultValue()
		}
	}
	
	/**
	 * Apply the standard default CSS value according to this
	 * document : http://www.w3.org/TR/CSS21/sample.html
	 * 
	 * TODO 5 : This method should eventually be removed when a StyleManager
	 * is introduced which will prevent those styles from being hard-coded
	 * 
	 * TODO 4 : use HTMLConstants and uppercase 
	 */
	private function applyDefaultHTMLStyles(tagName:String):Void
	{
		switch (tagName.toLowerCase())
		{
			case "html", "adress",
			"dd", "div", "dl", "dt", "fieldset",
			"form", "frame", "frameset", "noframes", "ol",
			"center", "dir", "hr", "menu" :
				display = Display.block;
				
			//TODO 5 : should be replaced by list-item once implemented	
			case "li" :
				display = Display.block;
			
			//TODO 5 : should be instead for :link pseudo style once
			//implmented
			case "a":
				cursor = Cursor.pointer;
				
			case "ul":
				display = Display.block;
				marginTop = marginBottom = Margin.length(em(1.12));
				marginLeft = Margin.length(px(40));
				
			case "head" :	
				display = Display.none;
				
			case "body" : 
				display = Display.block;
				marginLeft = marginRight = marginTop = marginBottom = Margin.length(px(8));
				
			case "h1" : 
				display = Display.block;
				fontSize = FontSize.length(em(2));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.67));
				
			case "h2" : 
				display = Display.block;
				fontSize = FontSize.length(em(1.5));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.75));	
			
			case "h3" : 
				display = Display.block;
				fontSize = FontSize.length(em(1.17));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.83));
			
			case "h4" :	
				display = Display.block;
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.12));
			
			case "h5" : 
				display = Display.block;
				fontSize = FontSize.length(em(0.83));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.5));	
				
			case "h6" : 
				display = Display.block;
				fontSize = FontSize.length(em(0.75));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.67));		
				
			case "p" :
				display = Display.block;
				marginTop = marginBottom = Margin.length(em(1));	
				
			case "pre" : 
				display = Display.block;
				whiteSpace = WhiteSpace.pre;
				fontFamily = ["monospace"];
				
			case "code" :
				fontFamily = ["monospace"];
				
			case "i", "cite", "em", "var" :
				fontStyle = FontStyle.italic;
				
			case "input" : 
				display = inlineBlock;
				
			case "blockquote" : 
				display = block;
				marginTop = marginBottom = Margin.length(em(1.12));
				marginLeft = marginRight = Margin.length(px(40));
				
			case "strong" : 
				fontWeight = FontWeight.bolder;
				
			case "big" : 
				fontSize = FontSize.length(em(1.17));
				
			case "small" :
				fontSize = FontSize.length(em(0.83));
				
			case "sub" : 
				fontSize = FontSize.length(em(0.83));
				verticalAlign = VerticalAlign.sub;
				
			case "sup" :
				fontSize = FontSize.length(em(0.83));
				verticalAlign = VerticalAlign.cssSuper;
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
	
	public static function getBackgroundPositionDefaultValue():Array<BackgroundPosition>
	{
		return [{
			x:BackgroundPositionX.percent(0),
			y:BackgroundPositionY.percent(0)
		}];
	}
	
	public static function getColorDefaultValue():CSSColor
	{
		return Color.keyword(ColorKeyword.black);
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
		if (computedStyle.cssFloat == CSSFloat.left || computedStyle.cssFloat == CSSFloat.right)
		{
			boxComputer = new FloatBoxStylesComputer();
		}
		
		//get it for HTMLElement with 'position' value of 'absolute' or 'fixed'
		else if (computedStyle.position == fixed || computedStyle.position == absolute)
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
		if (computedStyle.cssFloat == CSSFloat.left || computedStyle.cssFloat == CSSFloat.right)
		{
			boxComputer = new EmbeddedFloatBoxStylesComputer();
		}
		else if (computedStyle.position == fixed || computedStyle.position == absolute)
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
		htmlElement.invalidate(invalidationReason);
	}
	
	/**
	 * Same as above for positionining scheme styles (display, position...)
	 */
	private function invalidatePositioningScheme():Void
	{
		htmlElement.invalidatePositioningScheme();
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
	private function startTransitionIfNeeded(propertyName:String, invalidationReason:InvalidationReason):Void
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
		//TODO 2 : not supposed to happen, should be computed at this point
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
		transitionDuration, transitionDelay, transitionTimingFunction, onTransitionComplete, onTransitionUpdate, invalidationReason);
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
		invalidate(transition.invalidationReason);
		var transitionEvent:TransitionEvent = new TransitionEvent();
		transitionEvent.initTransitionEvent(TransitionEvent.TRANSITION_END, true, true, transition.propertyName, transition.transitionDuration, "");
		htmlElement.dispatchEvent(transitionEvent);
		
	}
	
	/**
	 * When a transition is updated, invalidate the HTMLElement
	 * to repaint the rendering tree
	 */
	private function onTransitionUpdate(transition:Transition):Void
	{
		invalidate(transition.invalidationReason);
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////

	private function get_fontMetricsData():FontMetricsData
	{
		var fontManager:FontManager = new FontManager();
		fontMetrics = fontManager.getFontMetrics(UnitManager.getCSSFontFamily(computedStyle.fontFamily), computedStyle.fontSize);
	
		return fontMetrics;
	}
	
	/////////////////////////////////
	// INVALIDATING STYLES SETTERS
	// setting one of those style will 
	// cause a re-layout
	////////////////////////////////
	
	private function setWidth(value:Dimension):Dimension 
	{
		width = value;
		//TODO 1 : if transition is successful, should invalidate still be called ?
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.WIDTH_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.WIDTH_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginLeft(value:Margin):Margin 
	{
		marginLeft = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_LEFT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MARGIN_LEFT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		marginRight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_RIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MARGIN_RIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		marginTop = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_TOP_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MARGIN_TOP_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		marginBottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_BOTTOM_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MARGIN_BOTTOM_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingLeft(value:Padding):Padding 
	{
		paddingLeft = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_LEFT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.PADDING_LEFT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingRight(value:Padding):Padding 
	{
		paddingRight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_RIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.PADDING_RIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingTop(value:Padding):Padding 
	{
		paddingTop = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_TOP_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.PADDING_TOP_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingBottom(value:Padding):Padding 
	{
		paddingBottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_BOTTOM_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.PADDING_BOTTOM_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setDisplay(value:Display):Display 
	{
		display = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setPosition(value:Position):Position 
	{
		position = value;
		computedStyle.position = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setHeight(value:Dimension):Dimension 
	{
		height = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.HEIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.HEIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		minHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MIN_HEIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MIN_HEIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		maxHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MAX_HEIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MAX_HEIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		minWidth = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MIN_WIDTH_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MIN_WIDTH_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		maxWidth = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MAX_WIDTH_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.MAX_WIDTH_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setTop(value:PositionOffset):PositionOffset 
	{
		top = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.TOP_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.TOP_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		left = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.LEFT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.LEFT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		bottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.BOTTOM_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.BOTTOM_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		right = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.RIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.RIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		cssFloat = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setClear(value:Clear):Clear 
	{
		clear = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.CLEAR_STYLE_NAME));
		return value;
	}
	
	private function setZIndex(value:ZIndex):ZIndex 
	{
		zIndex = value;
		computedStyle.zIndex = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setFontSize(value:FontSize):FontSize
	{
		fontSize = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.FONT_SIZE_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.FONT_SIZE_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		fontWeight = value;
		computedStyle.fontWeight = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_WEIGHT_STYLE_NAME));
		return value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		fontStyle = value;
		computedStyle.fontStyle = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_STYLE_STYLE_NAME));
		return value;
	}
	
	private function setFontFamily(value:Array<String>):Array<String>
	{
		fontFamily = value;
		computedStyle.fontFamily = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_FAMILY_STYLE_NAME));
		return value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		fontVariant = value;
		computedStyle.fontVariant = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.FONT_VARIANT_STYLE_NAME));
		return value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		textTransform = value;
		computedStyle.textTransform = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TEXT_TRANSFORM_STYLE_NAME));
		return value;
	}
	
	private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		letterSpacing = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.LETTER_SPACING_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.LETTER_SPACING_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		wordSpacing = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.WORD_SPACING_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.WORD_SPACING_STYLE_NAME, invalidationReason );
		invalidate(invalidationReason);
		return value;
	}
	
	private function setLineHeight(value:LineHeight):LineHeight
	{
		lineHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.LINE_HEIGHT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.LINE_HEIGHT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setColor(value:Color):Color
	{
		color = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.COLOR_STYLE_NAME));
		return value;
	}
	
	private function setVerticalAlign(value:VerticalAlign):VerticalAlign
	{
		verticalAlign = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.VERTICAL_ALIGN_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.VERTICAL_ALIGN_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setTextIndent(value:TextIndent):TextIndent
	{
		textIndent = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.TEXT_INDENT_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.TEXT_INDENT_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		whiteSpace = value;
		computedStyle.whiteSpace = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.WHITE_SPACE_STYLE_NAME));
		return value;
	}
	
	private function setTextAlign(value:TextAlign):TextAlign
	{
		textAlign = value;
		computedStyle.textAlign = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TEXT_ALIGN_STYLE_NAME));
		return value;
	}
	
	private function setOpacity(value:Opacity):Opacity
	{
		opacity = value;
		computedStyle.opacity = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.OPACITY_STYLE_NAME);
		startTransitionIfNeeded(CSSConstants.OPACITY_STYLE_NAME, invalidationReason);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setVisibility(value:Visibility):Visibility
	{
		visibility = value;
		computedStyle.visibility = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.VISIBILITY_STYLE_NAME));
		return value;
	}
	
	private function setTransformOrigin(value:TransformOrigin):TransformOrigin
	{
		transformOrigin = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setTransform(value:Transform):Transform
	{
		transform = value;
		invalidate(InvalidationReason.other);
		return value;
	}
	
	private function setOverflowX(value:Overflow):Overflow
	{
		overflowX = value;
		computedStyle.overflowX = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setOverflowY(value:Overflow):Overflow
	{
		overflowY = value;
		computedStyle.overflowY = value;
		invalidatePositioningScheme();
		return value;
	}
	
	private function setTransitionProperty(value:TransitionProperty):TransitionProperty
	{
		transitionProperty = value;
		computedStyle.transitionProperty = value;
		return value;
	}
	
	private function setTransitionDuration(value:TransitionDuration):TransitionDuration
	{
		transitionDuration = value;
		return value;
	}
	
	private function setTransitionDelay(value:TransitionDelay):TransitionDelay
	{
		transitionDelay = value;
		return value;
	}
	
	private function setTransitionTimingFunction(value:TransitionTimingFunction):TransitionTimingFunction
	{
		transitionTimingFunction = value;
		computedStyle.transitionTimingFunction = value;
		return value;
	}
	
	private function setBackgroundColor(value:BackgroundColor):BackgroundColor
	{
		backgroundColor = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_COLOR_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		backgroundImage = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_IMAGE_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		backgroundSize = value;
		//TODO 2 : should computed style be set here for this style ?
		computedStyle.backgroundSize = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_SIZE_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		backgroundClip = value;
		computedStyle.backgroundClip = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_CLIP_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		backgroundPosition = value;
		computedStyle.backgroundPosition = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_POSITION_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		backgroundRepeat = value;
		computedStyle.backgroundRepeat = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_REPEAT_STYLE_NAME));
		return value;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		backgroundOrigin = value;
		computedStyle.backgroundOrigin = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME));
		return value;
	}
	
	private function setCursor(value:Cursor):Cursor
	{
		cursor = value;
		computedStyle.cursor = value;
		return value;
	}
}