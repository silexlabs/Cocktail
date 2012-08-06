/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.event.TransitionEvent;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.style.computer.TransitionStylesComputer;
import cocktail.Lib;
import cocktail.core.font.FontManager;
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
import cocktail.core.layer.LayerRenderer;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import haxe.Log;
import haxe.Stack;
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
	
	/**
	 * An instance of fontmanager used to get the font metrics
	 */
	private var _fontManager:FontManager;
	
	/**
	 * An array holding the data necessary to start all pending
	 * animations on next layout
	 */
	private var _pendingAnimations:Array<PendingAnimationData>;
	
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
		_fontManager = FontManager.getInstance();
		_pendingAnimations = new Array<PendingAnimationData>();
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
	 */
	private function applyDefaultHTMLStyles(tagName:String):Void
	{
		switch (tagName.toUpperCase())
		{
			case HTMLConstants.HTML_HTML_TAG_NAME,
			HTMLConstants.HTML_ADRESS_TAG_NAME,
			HTMLConstants.HTML_DD_TAG_NAME,
			HTMLConstants.HTML_DIV_TAG_NAME,
			HTMLConstants.HTML_DL_TAG_NAME,
			HTMLConstants.HTML_DT_TAG_NAME,
			HTMLConstants.HTML_FIELDSET_TAG_NAME,
			HTMLConstants.HTML_FORM_TAG_NAME,
			HTMLConstants.HTML_FRAME_TAG_NAME,
			HTMLConstants.HTML_FRAMESET_TAG_NAME,
			HTMLConstants.HTML_NOFRAMES_TAG_NAME,
			HTMLConstants.HTML_OL_TAG_NAME,
			HTMLConstants.HTML_CENTER_TAG_NAME,
			HTMLConstants.HTML_DIR_TAG_NAME,
			HTMLConstants.HTML_HR_TAG_NAME,
			HTMLConstants.HTML_MENU_TAG_NAME :
				display = Display.block;
				
			//TODO 5 : should be replaced by list-item once implemented	
			case HTMLConstants.HTML_LI_TAG_NAME :
				display = Display.block;
			
			//TODO 5 : should be instead for :link pseudo style once
			//implmented
			case HTMLConstants.HTML_ANCHOR_TAG_NAME :
				cursor = Cursor.pointer;
				
			case HTMLConstants.HTML_UL_TAG_NAME :
				display = Display.block;
				marginTop = marginBottom = Margin.length(em(1.12));
				marginLeft = Margin.length(px(40));
				
			case HTMLConstants.HTML_HEAD_TAG_NAME :	
				display = Display.none;
				
			case HTMLConstants.HTML_BODY_TAG_NAME : 
				display = Display.block;
				marginLeft = marginRight = marginTop = marginBottom = Margin.length(px(8));
				
			case HTMLConstants.HTML_H1_TAG_NAME : 
				display = Display.block;
				fontSize = FontSize.length(em(2));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.67));
				
			case HTMLConstants.HTML_H2_TAG_NAME : 
				display = Display.block;
				fontSize = FontSize.length(em(1.5));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.75));	
			
			case HTMLConstants.HTML_H3_TAG_NAME : 
				display = Display.block;
				fontSize = FontSize.length(em(1.17));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(0.83));
			
			case HTMLConstants.HTML_H4_TAG_NAME :	
				display = Display.block;
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.12));
			
			case HTMLConstants.HTML_H5_TAG_NAME : 
				display = Display.block;
				fontSize = FontSize.length(em(0.83));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.5));	
				
			case HTMLConstants.HTML_H6_TAG_NAME : 
				display = Display.block;
				fontSize = FontSize.length(em(0.75));
				fontWeight = FontWeight.bolder;
				marginTop = marginBottom = Margin.length(em(1.67));		
				
			case HTMLConstants.HTML_P_TAG_NAME :
				display = Display.block;
				marginTop = marginBottom = Margin.length(em(1));	
				
			case HTMLConstants.HTML_PRE_TAG_NAME : 
				display = Display.block;
				whiteSpace = WhiteSpace.pre;
				fontFamily = ["monospace"];
				
			case HTMLConstants.HTML_CODE_TAG_NAME :
				fontFamily = ["monospace"];
				
			case HTMLConstants.HTML_I_TAG_NAME,
			HTMLConstants.HTML_CITE_TAG_NAME,
			HTMLConstants.HTML_EM_TAG_NAME,
			HTMLConstants.HTML_VAR_TAG_NAME :
				fontStyle = FontStyle.italic;
				
			case HTMLConstants.HTML_INPUT_TAG_NAME : 
				display = inlineBlock;
				
			case HTMLConstants.HTML_BLOCKQUOTE_TAG_NAME : 
				display = block;
				marginTop = marginBottom = Margin.length(em(1.12));
				marginLeft = marginRight = Margin.length(px(40));
				
			case HTMLConstants.HTML_STRONG_TAG_NAME : 
				fontWeight = FontWeight.bolder;
				
			case HTMLConstants.HTML_BIG_TAG_NAME : 
				fontSize = FontSize.length(em(1.17));
				
			case HTMLConstants.HTML_SMALL_TAG_NAME :
				fontSize = FontSize.length(em(0.83));
				
			case HTMLConstants.HTML_SUB_TAG_NAME : 
				fontSize = FontSize.length(em(0.83));
				verticalAlign = VerticalAlign.sub;
				
			case HTMLConstants.HTML_SUP_TAG_NAME :
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE COMPUTING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the transition styles needing it,
	 * like transition duration
	 */
	public function computeTransitionStyles():Void
	{
		TransitionStylesComputer.compute(this);
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
	// PUBLIC TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * Tries to start each of the stored pending animations
	 * 
	 * @return wether at least one animation did start
	 */
	public function startPendingAnimations():Bool
	{
		var atLeastOneAnimationStarted:Bool = false;
		
		for (i in 0..._pendingAnimations.length)
		{
			var animationStarted:Bool = startTransitionIfNeeded(_pendingAnimations[i]);
			if (animationStarted == true)
			{
				atLeastOneAnimationStarted = true;
			}
		}
		
		//clear the pending animation to prevent from being started
		//for each layout
		_pendingAnimations = new Array<PendingAnimationData>();
		
		return atLeastOneAnimationStarted;
	}
	
	/////////////////////////////////
	// PRIVATE TRANSITION METHODS
	////////////////////////////////
	
	/**
	 * Register a pending animation that will tries to start on next layout.
	 * A pending animation is registered when the specified value of an
	 * animatable property is changed
	 * 
	 * @param	propertyName the name of the property to animate
	 * @param	invalidationReason the invalidation reason caused by the property change
	 * @param	startValue the current computed value of the animatable property, used as
	 * starting value if the animation actually starts
	 */
	private function registerPendingAnimation(propertyName:String, invalidationReason:InvalidationReason, startValue:Float):Void
	{
		_pendingAnimations.push( {
			propertyName:propertyName,
			invalidationReason:invalidationReason,
			startValue:startValue
		});
	}
	
	/**
	 * When the specified value of a style changes, starts
	 * a transition for the proeprty if needed using the
	 * TransitionManager
	 * 
	 * @param pendingAnimation the data of the animation which might
	 * start
	 * @return wheter the animation did start
	 */
	private function startTransitionIfNeeded(pendingAnimation:PendingAnimationData):Bool
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
				return false;
			
			//here, check in the list of transitionable property
			//for a match
			case TransitionProperty.list(value):
				var foundFlag:Bool = false;
				
				for (i in 0...value.length)
				{
					//if there is a match, store the index
					//of the match
					if (value[i] == pendingAnimation.propertyName)
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
					return false;
				}
				
			//here all property can transition. The index
			//will stay at 0
			case TransitionProperty.all:	
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
			return false;
		}
		
		//get the transition timing function
		var transitionTimingFunction:TransitionTimingFunctionValue = computedStyle.transitionTimingFunction[getRepeatedIndex(propertyIndex,computedStyle.transitionTimingFunction.length)];
		
		var transitionManager:TransitionManager = TransitionManager.getInstance();
		
		//check if a transition is already in progress for the same property
		var transition:Transition = transitionManager.getTransition(pendingAnimation.propertyName, computedStyle);
		
		//if the transition is not null, then a transition for the property is already
		//in progress and no new transition must start
		if (transition != null)
		{
			//TODO 1 : in the spec, transition are not supposed to be interrupted
			//unless transitionProperty change or transition should reverse
			//transitionManager.stopTransition(transition);
			//TODO 1 : add the reverse transition case
			return false;
		}
		
		//get the current value of the property to animate. Since the ElementRenderer was laid out
		//after the pending animation was registered, the current computed value of the property
		//is now the end value of the transition
		var endValue:Float = Reflect.getProperty(computedStyle, pendingAnimation.propertyName);
		
		//start a transition using the TransitionManager
		transitionManager.startTransition(computedStyle, pendingAnimation.propertyName, pendingAnimation.startValue, endValue, 
		transitionDuration, transitionDelay, transitionTimingFunction, onTransitionComplete, onTransitionUpdate, pendingAnimation.invalidationReason);
	
		//the transition did in fact start
		return true;
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
		return _fontManager.getFontMetrics(UnitManager.getCSSFontFamily(computedStyle.fontFamily), computedStyle.fontSize);
	}
	
	/////////////////////////////////
	// INVALIDATING STYLES SETTERS
	// setting one of those style will 
	// cause a re-layout
	////////////////////////////////
	
	private function setWidth(value:Dimension):Dimension 
	{
		width = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.WIDTH_STYLE_NAME);
		registerPendingAnimation(CSSConstants.WIDTH_STYLE_NAME, invalidationReason, computedStyle.width);
		invalidate(invalidationReason);
		return value;
	}
	
	//TODO 1 : should use the "JavaScript" name instead of CSS to register.
	//i.e : marginLeft instead of margin-left
	private function setMarginLeft(value:Margin):Margin 
	{
		marginLeft = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_LEFT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MARGIN_LEFT_STYLE_NAME, invalidationReason, computedStyle.marginLeft);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginRight(value:Margin):Margin 
	{
		marginRight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_RIGHT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MARGIN_RIGHT_STYLE_NAME, invalidationReason, computedStyle.marginRight);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginTop(value:Margin):Margin 
	{
		marginTop = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_TOP_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MARGIN_TOP_STYLE_NAME, invalidationReason, computedStyle.marginTop);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMarginBottom(value:Margin):Margin 
	{
		marginBottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MARGIN_BOTTOM_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MARGIN_BOTTOM_STYLE_NAME, invalidationReason, computedStyle.marginBottom);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingLeft(value:Padding):Padding 
	{
		paddingLeft = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_LEFT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.PADDING_LEFT_STYLE_NAME, invalidationReason, computedStyle.paddingLeft);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingRight(value:Padding):Padding 
	{
		paddingRight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_RIGHT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.PADDING_RIGHT_STYLE_NAME, invalidationReason, computedStyle.paddingRight);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingTop(value:Padding):Padding 
	{
		paddingTop = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_TOP_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.PADDING_TOP_STYLE_NAME, invalidationReason, computedStyle.paddingTop);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setPaddingBottom(value:Padding):Padding 
	{
		paddingBottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.PADDING_BOTTOM_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.PADDING_BOTTOM_STYLE_NAME, invalidationReason, computedStyle.paddingBottom);
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
		registerPendingAnimation(CSSConstants.HEIGHT_STYLE_NAME, invalidationReason, computedStyle.height);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		minHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MIN_HEIGHT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MIN_HEIGHT_STYLE_NAME, invalidationReason, computedStyle.minHeight);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		maxHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MAX_HEIGHT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MAX_HEIGHT_STYLE_NAME, invalidationReason, computedStyle.maxHeight);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		minWidth = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MIN_WIDTH_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MIN_WIDTH_STYLE_NAME, invalidationReason, computedStyle.minWidth);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		maxWidth = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.MAX_WIDTH_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.MAX_WIDTH_STYLE_NAME, invalidationReason, computedStyle.maxWidth);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setTop(value:PositionOffset):PositionOffset 
	{
		top = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.TOP_STYLE_NAME);
		registerPendingAnimation(CSSConstants.TOP_STYLE_NAME, invalidationReason, computedStyle.top);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setLeft(value:PositionOffset):PositionOffset 
	{
		left = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.LEFT_STYLE_NAME);
		registerPendingAnimation(CSSConstants.LEFT_STYLE_NAME, invalidationReason, computedStyle.left);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setBottom(value:PositionOffset):PositionOffset 
	{
		bottom = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.BOTTOM_STYLE_NAME);
		registerPendingAnimation(CSSConstants.BOTTOM_STYLE_NAME, invalidationReason, computedStyle.bottom);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setRight(value:PositionOffset):PositionOffset 
	{
		right = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.RIGHT_STYLE_NAME);
		registerPendingAnimation(CSSConstants.RIGHT_STYLE_NAME, invalidationReason, computedStyle.right);
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
		//registerPendingAnimation(CSSConstants.FONT_SIZE_STYLE_NAME, invalidationReason, computedStyle.fontSize);
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
		//registerPendingAnimation(CSSConstants.LETTER_SPACING_STYLE_NAME, invalidationReason, computedStyle.letterSpacing);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		wordSpacing = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.WORD_SPACING_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.WORD_SPACING_STYLE_NAME, invalidationReason, computedStyle.wordSpacing );
		invalidate(invalidationReason);
		return value;
	}
	
	private function setLineHeight(value:LineHeight):LineHeight
	{
		lineHeight = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.LINE_HEIGHT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.LINE_HEIGHT_STYLE_NAME, invalidationReason, computedStyle.lineHeight);
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
		//registerPendingAnimation(CSSConstants.VERTICAL_ALIGN_STYLE_NAME, invalidationReason, computedStyle.verticalAlign);
		invalidate(invalidationReason);
		return value;
	}
	
	private function setTextIndent(value:TextIndent):TextIndent
	{
		textIndent = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.TEXT_INDENT_STYLE_NAME);
		//registerPendingAnimation(CSSConstants.TEXT_INDENT_STYLE_NAME, invalidationReason, computedStyle.textIndent);
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
	
	//TODO 1 : opacity change might need to create a new LayerRenderer
	private function setOpacity(value:Opacity):Opacity
	{
		opacity = value;
		var invalidationReason:InvalidationReason = InvalidationReason.styleChanged(CSSConstants.OPACITY_STYLE_NAME);
		registerPendingAnimation(CSSConstants.OPACITY_STYLE_NAME, invalidationReason, computedStyle.opacity);
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
		invalidate(InvalidationReason.styleChanged(CSSConstants.TRANSFORM_ORIGIN_STYLE_NAME));
		return value;
	}
	
	private function setTransform(value:Transform):Transform
	{
		transform = value;
		invalidatePositioningScheme();
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
		invalidate(InvalidationReason.styleChanged(CSSConstants.TRANSITION_PROPERTY_STYLE_NAME));
		return value;
	}
	
	private function setTransitionDuration(value:TransitionDuration):TransitionDuration
	{
		transitionDuration = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TRANSITION_DURATION_STYLE_NAME));
		return value;
	}
	
	private function setTransitionDelay(value:TransitionDelay):TransitionDelay
	{
		transitionDelay = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TRANSITION_DELAY_STYLE_NAME));
		return value;
	}
	
	private function setTransitionTimingFunction(value:TransitionTimingFunction):TransitionTimingFunction
	{
		transitionTimingFunction = value;
		computedStyle.transitionTimingFunction = value;
		invalidate(InvalidationReason.styleChanged(CSSConstants.TRANSITION_TIMING_FUNCTION_STYLE_NAME));
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