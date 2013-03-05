/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

using cocktail.core.utils.Utils;
import cocktail.core.config.Config;
import cocktail.core.css.CSSData;
import cocktail.core.event.EventConstants;
import cocktail.core.event.TransitionEvent;
import cocktail.core.font.FontData;
import cocktail.core.font.FontManager;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.layout.computer.BackgroundStylesComputer;
import cocktail.core.renderer.InvalidatingElementRenderer;
import cocktail.core.css.CSSConstants;
import cocktail.core.animation.Animator;
import cocktail.core.animation.Transition;
import cocktail.core.animation.TransitionManager;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.renderer.RendererData;
import cocktail.core.geom.GeomData;
import cocktail.core.resource.ResourceManager;
import cocktail.Lib;

/**
 * This class has 3 main purposes :
 *
 * It is in charge of the cascade, that is
 * for each supported style it selects the right
 * value for its HTMLElement based on the priority
 * of the style declaration.For instance, a style
 * declared inline on an HTMLElement has a higher
 * priority than a style declared in a style sheet.
 * 
 * For a given style, once its specified value has been
 * determined through cascading, derive a computed 
 * value from it which is the value used for inheritance
 * 
 * This class is also in charge of starting
 * transition/animation when the computed value
 * of an animatable property changes
 * 
 * @author Yannick DOMINGUEZ
 */

class CoreStyle
{	
	/**
	 * display styles
	 */
	public var display(get_display, null):CSSPropertyValue;
	public var position(get_position, null):CSSPropertyValue;
	public var cssFloat(get_cssFloat, null):CSSPropertyValue;
	public var clear(get_clear, null):CSSPropertyValue;
	public var zIndex(get_zIndex, null):CSSPropertyValue;
	
	/**
	 * box model styles
	 */
	public var marginLeft(get_marginLeft, null):CSSPropertyValue;
	public var marginRight(get_marginRight, null):CSSPropertyValue;
	public var marginTop(get_marginTop, null):CSSPropertyValue;
	public var marginBottom(get_marginBottom, null):CSSPropertyValue;
	
	public var paddingLeft(get_paddingLeft, null):CSSPropertyValue;
	public var paddingRight(get_paddingRight, null):CSSPropertyValue;
	public var paddingTop(get_paddingTop, null):CSSPropertyValue;
	public var paddingBottom(get_paddingBottom, null):CSSPropertyValue;

	public var width(get_width, null):CSSPropertyValue;
	public var height(get_height, null):CSSPropertyValue;
	
	public var minHeight(get_minHeight, null):CSSPropertyValue;
	public var maxHeight(get_maxHeight, null):CSSPropertyValue;
	public var minWidth(get_minWidth, null):CSSPropertyValue;
	public var maxWidth(get_maxWidth, null):CSSPropertyValue;

	public var top(get_top, null):CSSPropertyValue;
	public var left(get_left, null):CSSPropertyValue;
	public var bottom(get_bottom, null):CSSPropertyValue;
	public var right(get_right, null):CSSPropertyValue;
	
	/**
	 * background styles
	 */
	public var backgroundColor(get_backgroundColor, null):CSSPropertyValue;
	public var backgroundImage(get_backgroundImage, null):CSSPropertyValue;
	public var backgroundRepeat(get_backgroundRepeat, null):CSSPropertyValue;
	public var backgroundOrigin(get_backgroundOrigin, null):CSSPropertyValue;
	public var backgroundSize(get_backgroundSize, null):CSSPropertyValue;
	public var backgroundPosition(get_backgroundPosition, null):CSSPropertyValue;
	public var backgroundClip(get_backgroundClip, null):CSSPropertyValue;
	public var backgroundAttachment(get_backgroundAttachment, null):CSSPropertyValue;
	
	/**
	 * font styles
	 */
	public var fontSize(get_fontSize, null):CSSPropertyValue;
	public var fontWeight(get_fontWeight, null):CSSPropertyValue;
	public var fontStyle(get_fontStyle, null):CSSPropertyValue;
	public var fontFamily(get_fontFamily, null):CSSPropertyValue;
	public var fontVariant(get_fontVariant,null):CSSPropertyValue;
	public var color(get_color, null):CSSPropertyValue;
	
	/**
	 * text styles
	 */
	public var lineHeight(get_lineHeight, null):CSSPropertyValue;
	public var textTransform(get_textTransform, null):CSSPropertyValue;
	public var letterSpacing(get_letterSpacing, null):CSSPropertyValue;
	public var wordSpacing(get_wordSpacing, null):CSSPropertyValue;
	public var whiteSpace(get_whiteSpace, null):CSSPropertyValue;
	public var textAlign(get_textAlign, null):CSSPropertyValue;
	public var textIndent(get_textIndent, null):CSSPropertyValue;
	public var verticalAlign(get_verticalAlign, null):CSSPropertyValue;
	
	/**
	 * visual effect styles
	 */
	public var opacity(get_opacity, null):CSSPropertyValue;
	public var visibility(get_visibility, null):CSSPropertyValue;
	public var overflowX(get_overflowX, null):CSSPropertyValue;
	public var overflowY(get_overflowY, null):CSSPropertyValue;
	public var transformOrigin(get_transformOrigin, null):CSSPropertyValue;
	public var transform(get_transform, null):CSSPropertyValue;
	
	/**
	 * user interface styles
	 */
	public var cursor(get_cursor, null):CSSPropertyValue;
	
	/**
	 * transition styles
	 */
	public var transitionProperty(get_transitionProperty, null):CSSPropertyValue;
	public var transitionDuration(get_transitionDuration, null):CSSPropertyValue;
	public var transitionDelay(get_transitionDelay, null):CSSPropertyValue;
	public var transitionTimingFunction(get_transitionTimingFunction, null):CSSPropertyValue;
	
	/**
	 * Contains the specified values for the HTMLElement which for
	 * each style can come from a style sheet, an inline
	 * style declaration or inherited through the parent
	 */
	public var specifiedValues:CSSStyleDeclaration;
	
	/**
	 * Contains the computed values for the HTMLElement.
	 * There is a computed value for each specified style.
	 * This is the value used for inheritance. Each style
	 * computes diffferently. For instance if for a given
	 * the specified value is a Length (for instance '10px')
	 * , the computed value will be an absolute length in pixel
	 * (for instance 10)
	 * 
	 * Specified values can always be converted to 
	 * computed values during cascade
	 */
	public var computedValues:CSSStyleDeclaration;
	
	/**
	 * This structures holds values of style actually
	 * used during layout. Not all styles used values
	 * can be determined during cascade. For instance
	 * a 'width' defined as '100%' must wait layout
	 * to determine its used value. This structure
	 * will hold the actual used value of 'width'
	 * during layout
	 */
	public var usedValues:UsedValuesVO;
	
	/**
	 * An instance of the class
	 * managing this HTMLElement transitions
	 */
	private var _animator:Animator;
	
	/**
	 * A reference to the TransitionManager singleton
	 */
	private var _transitionManager:TransitionManager;
	
	/**
	 * Once a transition is complete, the transition end
	 * event is not immediately dispatached, it is stored in this
	 * array and dispatched on the next layout.
	 * 
	 * This prevent the event from being dispatched before the 
	 * layout was updated to reflect the end of the transition
	 */
	private var _pendingTransitionEndEvents:Array<TransitionEvent>;
	
	/**
	 * While a transition is in progress, if the computed value
	 * of its property changes, it is stored here and applied 
	 * at the end of the transition, most likely triggering another
	 * transition.
	 * 
	 * Eac index in this array represents the css property with
	 * the corresponding index, the index return null if there
	 * are no pending computed values
	 */
	private var _pendingComputedValues:Array<TypedPropertyVO>;
	
	/**
	 * Returns font metrics for the current style values.
	 * Font metrics depends on the computed values of
	 * the 'font-size' and 'font-family' properties
	 * 
	 */
	public var fontMetrics(default, null):FontMetricsVO;
	
	/**
	 * An instance of fontmanager used to get the font metrics
	 */
	private var _fontManager:FontManager;
	
	/**
	 * During cascade, holds the index of 
	 * all the properties whose value changed
	 */
	private var _changedProperties:Array<Int>;
	
	/**
	 * True while the first cascade did not occur,
	 * for the first cascade, all styles need to
	 * be cascaded
	 */
	private var _isFirstCascade:Bool;
	
	/**
	 * The owning HTMLElement
	 */
	public var htmlElement:HTMLElement;
	
	/**
	 * a reference to an object containing all
	 * the default CSS style defintions
	 */
	private var _initialStyleDeclaration:InitialStyleDeclaration;
	
	/**
	 * a reference to an object containing all
	 * the default CSS style definition for
	 * computed properties
	 */
	private var _initialComputedStyleDeclaration:CSSStyleDeclaration;
	
	///////////////////////////////////
	// STYLE FLAGS
	//////////////////////////////////
	// Those flag define aspects of an element
	// like wether it is floated or positioned.
	// Those flags are used for info requested
	// extensively during layout and rendering,
	// storing those flag prevents from computing
	// the same info multiple time during layout
	// and rendering
	
	/**
	 * Wether the element with this core style is left
	 * or right floated
	 */
	public var isFloat:Bool;
	
	/**
	 * Wether the element is inline or block level
	 */
	public var isInlineLevel:Bool;
	
	/**
	 * Wether the element has a display computed value
	 * of inline-block
	 */
	public var isInlineBlock:Bool;
	
	/**
	 * Wether the element has a display computed value
	 * of inline
	 */
	public var isInline:Bool;
	
	/**
	 * Wether the element has a display computed value
	 * of block
	 */
	public var isBlock:Bool;
	
	/**
	 * Wether the element is visible, it still 
	 * influence layout even if hidden
	 */
	public var isVisible:Bool;
	
	/**
	 * Wether the element has a position style 
	 * different from 'static'
	 */
	public var isPositioned:Bool;
	
	/**
	 * Wether the element has a position style
	 * of 'relative'
	 */
	public var isRelativePositioned:Bool;
	
	/**
	 * Wether the element has a position style
	 * of 'fixed'
	 */
	public var isFixedPositioned:Bool;
	
	/**
	 * Wether the element has a position style
	 * of 'fixed' or 'absolute'
	 */
	public var isAbsolutelyPositioned:Bool;
	
	/**
	 * Wether the element has both an overflow-x
	 * and overflow-y of 'visible'
	 */
	public var canAlwaysOverflow:Bool;
	
	/**
	 * Wether the element have 'hidden' or 'scroll'
	 * for overflow-x value
	 */
	public var hasHiddenOrScrollOverflowX:Bool;

	/**
	 * Wether the element have 'hidden' or 'scroll'
	 * for overflow-y value
	 */
	public var hasHiddenOrScrollOverflowY:Bool;
	
	/**
	 * Wether the element is transformed via the
	 * transform style or with a relative positioning
	 */
	public var isTransformed:Bool;
	
	/**
	 * Wether the element has value of 'transform'
	 * which is not 'none'
	 */
	public var hasCSSTransform:Bool;
	
	/**
	 * Wether the element has an opacity
	 * different from 1.0
	 */
	public var isTransparent:Bool;
	
	/**
	 * Wether the element has a non 'none'
	 * value for background image
	 */
	public var hasBackgroundImage:Bool;
	
	/**
	 * Wether the background color is not 
	 * 'transparent'
	 */
	public var hasBackgroundColor:Bool;
	
	/**
	 * Wether the element's vertical align
	 * style is top
	 */
	public var isTopAligned:Bool;
	
	/**
	 * Wether the element's vertical align
	 * style is bottom
	 */
	public var isBottomAligned:Bool;
	
	/**
	 * Wether the element's vertical align
	 * style is baseline
	 */
	public var isBaselineAligned:Bool;
	
	/**
	 * Wether the element has not 'none'
	 * for clear style
	 */
	public var canHaveClearance:Bool;
	
	/**
	 * Wether the white space style is 
	 * 'pre'
	 */
	public var hasPreWhiteSpace:Bool;
	
	/**
	 * Wether the white space style is 
	 * 'no-wrap'
	 */
	public var hasNoWrapWhiteSpace:Bool;
	
	/**
	 * Wether the white space style is 
	 * 'pre-line'
	 */
	public var hasPreLineWhiteSpace:Bool;
	
	/**
	 * Wether the white space style is 
	 * 'pre-wrap'
	 */
	public var hasPreWrapWhiteSpace:Bool;
	
	/**
	 * Wether the white space style is 
	 * 'normal'
	 */
	public var hasNormalWhiteSpace:Bool;
	
	/**
	 * Wether the width style has a 'auto' value
	 */
	public var hasAutoWidth:Bool;
	
	/**
	 * Wether the height style has a 'auto' value
	 */
	public var hasAutoHeight:Bool;
	
	/**
	 * Wether the max-width style has a value
	 * other than none
	 */
	public var hasMaxWidth:Bool;
	
	/**
	 * Wether the max-height style has a value
	 * other than none
	 */
	public var hasMaxHeight:Bool;
	
	/**
	 * Wether 'text-align' has a 'left' value
	 */
	public var isLeftAligned:Bool;
	
	/**
	 * Wether 'top' has 'auto' value
	 */
	public var hasAutoTop:Bool;
	
	/**
	 * same for bottom
	 */
	public var hasAutoBottom:Bool;
	
	/**
	 * same for left
	 */
	public var hasAutoLeft:Bool;
	
	/**
	 * same for right
	 */
	public var hasAutoRight:Bool;
	
	/**
	 * Wether 'margin-left' is 'auto'
	 */
	public var hasAutoMarginLeft:Bool;
	
	/**
	 * same for 'margin-right'
	 */
	public var hasAutoMarginRight:Bool;
	
	/**
	 * same for 'margin-top'
	 */
	public var hasAutoMarginTop:Bool;
	
	/**
	 * same for 'margin-bottom'
	 */
	public var hasAutoMarginBottom:Bool;
	
	/**
	 * Wether at least one style can be transitioned, as
	 * defined by the value of the 'transition-property'
	 * style. If it is none, there can't be any transition
	 * for this element
	 */
	public var hasTransitionnableProperties:Bool;
	
	/**
	 * Class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		this.htmlElement = htmlElement;
		
		_isFirstCascade = true;
		
		hasTransitionnableProperties = false;
		isFloat = false;
		isInlineLevel = false;
		isInlineBlock = false;
		isBlock = false;
		isVisible = false;
		isPositioned = false;
		isRelativePositioned = false;
		isFixedPositioned = false;
		canAlwaysOverflow = false;
		isTransformed = false;
		isTransparent = false;
		hasBackgroundImage = false;
		isTopAligned = false;
		isBottomAligned = false;
		isBaselineAligned = false;
		canHaveClearance = false;
		hasPreWhiteSpace = false;
		hasNoWrapWhiteSpace = false;
		hasNormalWhiteSpace = false;
		hasPreLineWhiteSpace = false;
		hasPreWrapWhiteSpace = false;
		hasAutoHeight = false;
		hasAutoWidth = false;
		hasMaxHeight = false;
		hasMaxWidth = false;
		isInline = false;
		isLeftAligned = false;
		hasAutoTop = false;
		hasAutoBottom = false;
		hasAutoLeft = false;
		hasAutoRight = false;
		hasAutoMarginTop = false;
		hasAutoMarginBottom = false;
		hasAutoMarginLeft = false;
		hasAutoMarginRight = false;
		isAbsolutelyPositioned = false;
		hasBackgroundColor = false;
		hasCSSTransform = false;
		hasHiddenOrScrollOverflowX = false;
		hasHiddenOrScrollOverflowY = false;
		
		_initialStyleDeclaration = InitialStyleDeclaration.getInstance();
		_initialComputedStyleDeclaration = _initialStyleDeclaration.initialComputedStyleDeclaration;
		
		init();
	}
	
	/**
	 * Init class attributes
	 */
	private function init():Void
	{
		computedValues = new CSSStyleDeclaration();
		specifiedValues = new CSSStyleDeclaration();
		
		_changedProperties = new Array<Int>();
		
		_fontManager = FontManager.getInstance();
		//TODO 3 : messy
		fontMetrics = _fontManager.getFontMetrics(Config.getInstance().defaultFont, Config.getInstance().mediumFontSize);
		
		_transitionManager = TransitionManager.getInstance();
		
		initUsedValues();
	}
	
	/**
	 * init each index used to store pending 
	 * computed valus when needed. Init one
	 * index per style
	 */
	private function initPendingComputedValues():Void
	{
		_pendingComputedValues = new Array<TypedPropertyVO>();
		for (i in 0...CSSConstants.SUPPORTED_STYLES_NUMBER)
		{
			_pendingComputedValues[i] = null;
		}
	}
	
	/**
	 * Init animator. Called first time
	 * used instead of in constructor, as
	 * most node are not animated at all
	 */
	private function initAnimator():Void
	{
		_animator = new Animator();
		_animator.onTransitionCompleteCallback = onTransitionComplete;
		_animator.onTransitionUpdateCallback = onTransitionUpdate;
	}
	
	/**
	 * The used values are given a default
	 * value
	 */
	private function initUsedValues():Void
	{
		usedValues = new UsedValuesVO();
		usedValues.minHeight = 0.0;
		usedValues.maxHeight = 0.0;
		usedValues.minWidth = 0.0;
		usedValues.maxWidth = 0.0;
		usedValues.width = 0.0;
		usedValues.height = 0.0;
		usedValues.marginLeft = 0.0;
		usedValues.marginRight = 0.0;
		usedValues.marginTop = 0.0;
		usedValues.marginBottom = 0.0;
		usedValues.paddingLeft = 0.0;
		usedValues.paddingRight = 0.0;
		usedValues.paddingTop = 0.0;
		usedValues.paddingBottom = 0.0;
		usedValues.left = 0.0;
		usedValues.right = 0.0;
		usedValues.top = 0.0;
		usedValues.bottom = 0.0;
		usedValues.textIndent = 0;
		usedValues.lineHeight = 0.0;
		usedValues.letterSpacing = 0.0;
		usedValues.color = new ColorVO(0, 1.0);
		usedValues.transformOrigin = new PointVO(0.0, 0.0);
		usedValues.transform = new Matrix();
		usedValues.backgroundColor = new ColorVO(0, 0.0);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The main cascading function. For each supported CSS style,
	 * get the right specified style for the CoreStyle's HTMLElement.
	 * The specified style for each property can come for multiple 
	 * source, this method manages the priority among those sources
	 * 
	 * @param cascadeManager contain the names of the properties to update and info about the current
	 * cascade
	 * @param	initialStyleDeclaration contains the initial value for each of the supported CSS styles.
	 * Used last if a value for a given style is not provided from other sources
	 * @param	styleSheetDeclaration	contains all the style values applying to the HTMLElement which
	 * comes from the CSS style sheet defined in the document or linked
	 * @param	inlineStyleDeclaration contains all the styles defined inline on the HTMLElement, using
	 * its "style" HTML attribute
	 * @param	parentStyleDeclaration contains the definition of all of the computed styles from the direct
	 * parent of the HTMLElement, used for inherithance
	 * @param	parentFontSize parent node's computed font size
	 * @param	parentXHeight parent node's computed x height
	 * @param programmaticChange wether the triggering of the cascade is the result of a programmatic (scripted) change
	 * as opposed to a declarative one
	 * @return an array containing the names of all the properties whose specified values changed during cascading
	 */
	public function cascade(cascadeManager:CascadeManager, initialStyleDeclaration:InitialStyleDeclaration, styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration, parentFontSize:Float, parentXHeight:Float, programmaticChange:Bool):Void
	{
		//no need to cascade if no styles need to be
		//updated on this HTMLElement
		if (cascadeManager.hasPropertiesToCascade == false)
		{
			return;
		}
		
		//will store all the properties which value
		//change during cascading
		_changedProperties = _changedProperties.clear();
				
		//flag to prevent checking stylesheet with no styles
		var hasInlineStyle:Bool = inlineStyleDeclaration.length > 0;
		var hasStyleSheetStyle:Bool = styleSheetDeclaration.length > 0;
		
		//color of parent might be used to inherit it for some color styles with
		//the currentColor value
		var parentColor:CSSColorValue = getColor(parentStyleDeclaration.getTypedProperty(CSSConstants.COLOR).typedValue);
		
		//if the style defining which transition can be transitionned must be cascaded,
		//cascade first to know if other properties will need to start transition during 
		//cascade
		if (cascadeManager.hasTransitionProperty == true || cascadeManager.cascadeAll == true)
		{
			cascadeProperty(CSSConstants.TRANSITION_PROPERTY, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentColor, parentFontSize, parentXHeight, 0, 0, programmaticChange, hasInlineStyle, hasStyleSheetStyle);
			
			//store wether there are properties which can be transitioned. When other
			//properties are computed, they can bypass the start transition step if
			//no property should be transitioned
			hasTransitionnableProperties = isNone(transitionProperty) == false;
			
			//remove so that it isn't cascaded twice
			cascadeManager.removePropertyToCascade(CSSConstants.TRANSITION_PROPERTY);
		}
		
		if (cascadeManager.hasFontSize == true || cascadeManager.hasFontFamily == true || cascadeManager.cascadeAll == true)
		{
			//when the value of font-size and/or font-family is cascaded,
			//they must be cascaded first, as their
			//computed values is used to compute some length.
			//For instance if 'width' is defined as '2em', for
			//the computed absolute length to be correct, font-size
			//and font-family must have been previously computed
			//so that the right font metrics is used for the computation
			var fontSizeDidChange:Bool = cascadeProperty(CSSConstants.FONT_SIZE, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentColor, parentFontSize, parentXHeight, 0, 0, programmaticChange, hasInlineStyle, hasStyleSheetStyle);
			var fontFamilyDidChange:Bool = cascadeProperty(CSSConstants.FONT_FAMILY, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentColor, parentFontSize, parentXHeight, 0, 0, programmaticChange, hasInlineStyle, hasStyleSheetStyle);
			
			//if font-size or font-family changed, all the properties which may depends
			//on font metrics (because they are for instance Length with 'em' unit) need to be cascaded
			if (fontSizeDidChange == true || fontFamilyDidChange == true)
			{
				var lengthCSSProperties:Array<Int> = initialStyleDeclaration.lengthCSSProperties;
				var length:Int = lengthCSSProperties.length;
				for (i in 0...length)
				{
					cascadeManager.addPropertyToCascade(lengthCSSProperties[i]);
				}
				
				//refresh the font metrics when either font family or font size hanges
				if (computedValues.fontFamily != null)
				{
					fontMetrics = _fontManager.getFontMetrics(computedValues.fontFamily, getAbsoluteLength(fontSize));
				}
				else
				{
					fontMetrics = _fontManager.getFontMetrics(initialStyleDeclaration.initialComputedStyleDeclaration.fontFamily, getAbsoluteLength(fontSize));
				}
			}
			
			//prevent from being cascaded twice
			cascadeManager.removePropertyToCascade(CSSConstants.FONT_SIZE);
			cascadeManager.removePropertyToCascade(CSSConstants.FONT_FAMILY);
		}
		
		//when the value of the color style changes, all the style
		//which value might be a color value must be cascaded, as
		//if they use the currentColor keyword, their value will be
		//the same as the one of the color style value
		if (cascadeManager.hasColor == true)
		{
			var colorDidChange:Bool = cascadeProperty(CSSConstants.COLOR, initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration, parentColor, parentFontSize, parentXHeight, 0, 0, programmaticChange, hasInlineStyle, hasStyleSheetStyle);
			
			
			//only cascade color propery if value actually changed
			if (colorDidChange == true)
			{
				//make sure to mark the color style as changed, so that its
				//used value get re-computed after cascade
				_changedProperties.push(CSSConstants.COLOR);
				
				var colorCSSProperties:Array<Int> = initialStyleDeclaration.colorCSSProperties;
				var length:Int = colorCSSProperties.length;
				for (i in 0...length)
				{
					cascadeManager.addPropertyToCascade(colorCSSProperties[i]);
				}
			}
			
			//prevent color from being cascaded twice
			cascadeManager.removePropertyToCascade(CSSConstants.COLOR);
		}
		
		var fontSize:Float = fontMetrics.fontSize;
		var xHeight:Float = fontMetrics.xHeight;
		
		//holds the properties which will get cascaded
		var propertiesToCascade:Array<Int> = null;
		
		//if all properties must be cascaded, retrieve the
		//name of the all the supprted properties
		if (cascadeManager.cascadeAll == true)
		{
			propertiesToCascade = initialStyleDeclaration.supportedCSSProperties;
		}
		else
		{
			//add the name of all properties flagged as needing cascade
			propertiesToCascade = new Array<Int>();
			
			var flaggedProperties:Array<Bool> = cascadeManager.propertiesToCascade;
			var flaggedPropertiesLength:Int = flaggedProperties.length;
			for (i in 0...flaggedPropertiesLength)
			{
				if (flaggedProperties[i] == true)
				{
					propertiesToCascade.push(i);
				}
			}
		}
		
		var length:Int = propertiesToCascade.length;
		for (i in 0...length)
		{
			//cascade the property, returns a flag of wether the cascade changed
			//the specified value of the property. Useful to know if children
			//also need to cascade this property
			var didChangeSpecifiedValue:Bool = cascadeProperty(propertiesToCascade[i], initialStyleDeclaration, styleSheetDeclaration, inlineStyleDeclaration, parentStyleDeclaration,  parentColor, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange, hasInlineStyle, hasStyleSheetStyle);
	
			if (didChangeSpecifiedValue == true)
			{
				_changedProperties.push(propertiesToCascade[i]);
			}
		}
		
		//now that all properties where cascaded, 
		//reset the list
		cascadeManager.reset();
		
		//add the list of properties which value changed
		//during cascading to be cascaded, so that when the
		//next child is cascaded it knows all the styles
		//which changed on its parent
		var length:Int = _changedProperties.length;
		for (i in 0...length)
		{
			cascadeManager.addPropertyToCascade(_changedProperties[i]);
		}
		
		//apply special computing relationship between
		//display, float and position property
		applyPositionFloatAndDisplayRelationship();
		
		//if the background color property was changed, computes
		//its used value immediately, as for color, there is no need
		//to wait for layout for used values
		if (cascadeManager.hasBackgroundColor == true)
		{
			CSSValueConverter.getColorVOFromCSSColor(getColor(backgroundColor), usedValues.backgroundColor);
			
			//if the background color is transparent, it is considered
			//to not have background color for rendering purpose
			hasBackgroundColor = usedValues.backgroundColor.alpha != 0.0;
		}
		//same as above for the color style
		if (cascadeManager.hasColor == true)
		{
			CSSValueConverter.getColorVOFromCSSColor(getColor(color), usedValues.color);
		}
		
		//same as above for line height
		//if (cascadeManager.hasLineHeight == true)
		//{
		
		//TODO 3 : shouldn't update each time but for some reason, sometimes
		//line height set wrong which causes text on same line to be misaligned
		
			switch (lineHeight)
			{
				case ABSOLUTE_LENGTH(value):
					usedValues.lineHeight = value;
					
				case KEYWORD(value):
					usedValues.lineHeight = fontSize * 1.2;
					
				case NUMBER(value):
					usedValues.lineHeight = fontSize * value;
					
				default:	
			}
		//}
		
		//same as above for letter spacing
		if (cascadeManager.hasLetterSpacing == true)
		{
			switch(letterSpacing)
			{
				case ABSOLUTE_LENGTH(value):
					usedValues.letterSpacing = value;
					
				case KEYWORD(value):
					usedValues.letterSpacing = 0.0;
					
				default:	
			}
		}
		
		//update property flags which need it
		updateCoreStyleAttribute(cascadeManager, _isFirstCascade);
		
		
		//unset flag now that first cascade is done
		if (_isFirstCascade == true)
		{
			_isFirstCascade = false;
		}
	}
	
	/**
	 * update core style flags, always update all for first cascade, as 
	 * all styles are cascaded
	 */
	private function updateCoreStyleAttribute(cascadeManager:CascadeManager, isFirstCascade:Bool):Void
	{
		if (cascadeManager.hasFloat == true || isFirstCascade == true)
		{
			isFloat = isNone(cssFloat) == false;
		}
		
		if (cascadeManager.hasDisplay == true || cascadeManager.hasPosition == true 
		|| cascadeManager.hasFloat == true || isFirstCascade == true)
		{
			isInlineLevel = false;
			isInlineBlock = false;
			isBlock = false;
			isInline = false;
			
			switch (getKeyword(display)) 
			{
				case INLINE:
					isInlineLevel = true;
					isInline = true;
				
				case INLINE_BLOCK:
					isInlineLevel = true;
					isInlineBlock = true;
					
				case BLOCK:	
					isBlock = true;
				
				default:
			}
		}
		
		if (cascadeManager.hasVisible == true || isFirstCascade == true)
		{
			isVisible = getKeyword(visibility) != HIDDEN;
		}
		
		if (cascadeManager.hasPosition == true || isFirstCascade == true)
		{
			isPositioned = false;
			isRelativePositioned = false;
			isFixedPositioned = false;
			isAbsolutelyPositioned = false;
			
			switch (getKeyword(position))
			{
				case STATIC:
					
				case ABSOLUTE:
					isPositioned = true;
					isAbsolutelyPositioned = true;
				
				case FIXED:	
					isPositioned = true;
					isFixedPositioned = true;
					isAbsolutelyPositioned = true;
					
				case RELATIVE:
					isPositioned = true;
					isRelativePositioned = true;
					
				default:	
			}
		}
		
		if (cascadeManager.hasOverflowX || cascadeManager.hasOverflowY || isFirstCascade == true)
		{
			canAlwaysOverflow = true;
			hasHiddenOrScrollOverflowX = false;
			
			switch (getKeyword(overflowX))
			{
				case VISIBLE:
					
				case HIDDEN, SCROLL:
					hasHiddenOrScrollOverflowX = true;
					canAlwaysOverflow = false;
					
				default:
					canAlwaysOverflow = false;
			}
			
			switch (getKeyword(overflowY))
			{
				case VISIBLE:
					
				case HIDDEN, SCROLL:
					hasHiddenOrScrollOverflowY = true;
					canAlwaysOverflow = false;
					
				default:
					canAlwaysOverflow = false;
			}
		}
		
		if (cascadeManager.hasTransform || cascadeManager.hasPosition || isFirstCascade == true)
		{
			isTransformed = false;
			hasCSSTransform = false;
			
			if (isRelativePositioned == true)
			{
				isTransformed = true;
			}
			else if (isNone(transform) == false)
			{
				isTransformed = true;
				hasCSSTransform = true;
			}
		}
		
		if (cascadeManager.hasOpacity == true || isFirstCascade == true)
		{
			isTransparent = false;
			switch(opacity)
			{
				case CSSPropertyValue.NUMBER(value):
					isTransparent = value != 1.0;
					
				case CSSPropertyValue.ABSOLUTE_LENGTH(value):
					isTransparent = value != 1.0;
					
				default:
			}
		}
		
		if (cascadeManager.hasMarginTop == true || isFirstCascade == true)
		{
			hasAutoMarginTop = isAuto(marginTop);
		}
		
		if (cascadeManager.hasMarginBottom == true || isFirstCascade == true)
		{
			hasAutoMarginBottom = isAuto(marginBottom);
		}
		
		if (cascadeManager.hasMarginLeft == true || isFirstCascade == true)
		{
			hasAutoMarginLeft = isAuto(marginLeft);
		}
		
		if (cascadeManager.hasMarginRight == true || isFirstCascade == true)
		{
			hasAutoMarginRight = isAuto(marginRight);
		}
		
		//for background image, if an url is provided, 
		//start loading the image
		if (cascadeManager.hasBackgroundImage == true || isFirstCascade == true)
		{
			hasBackgroundImage = false;
			if (isNone(backgroundImage) == false)
			{
				hasBackgroundImage = true;
				
				switch (backgroundImage)
				{
					case URL(value):
						ResourceManager.getImageResource(value);
						
					default:	
				}
			}
		}
		
		if (cascadeManager.hasVerticalAlign == true || isFirstCascade == true)
		{
			isTopAligned = false;
			isBottomAligned = false;
			isBaselineAligned = false;
			
			switch(verticalAlign)
			{
				case KEYWORD(value):
					switch(value)
					{
						case TOP:	
							isTopAligned = true;
							
						case BOTTOM:
							isBottomAligned = true;
							
						case BASELINE:
							isBaselineAligned = true;
							
						default:	
					}
					
				default:	
			}
		}
		
		if (cascadeManager.hasClear == true || isFirstCascade == true)
		{
			canHaveClearance = isNone(clear) == false;
		}
		
		if (cascadeManager.hasWhiteSpace == true || isFirstCascade == true)
		{
			hasPreLineWhiteSpace = false;
			hasPreWhiteSpace = false;
			hasNoWrapWhiteSpace = false;
			hasNormalWhiteSpace = false;
			hasPreWrapWhiteSpace = false;
			
			switch(getKeyword(whiteSpace))
			{
				case PRE:
					hasPreWhiteSpace = true;
					
				case PRE_LINE:
					hasPreLineWhiteSpace = true;
					
				case PRE_WRAP:
					hasPreWrapWhiteSpace = true;
					
				case NO_WRAP:
					hasNoWrapWhiteSpace = true;
					
				case NORMAL:
					hasNormalWhiteSpace = true;
					
				default:	
			}
		}
		
		if (cascadeManager.hasWidth == true || isFirstCascade == true)
		{
			hasAutoWidth = isAuto(width);
		}
		
		if (cascadeManager.hasHeight == true || isFirstCascade == true)
		{
			hasAutoHeight = isAuto(height);
		}
		
		if (cascadeManager.hasMaxHeight == true || isFirstCascade == true)
		{
			hasMaxHeight = isNone(maxHeight) == false;
		}
		
		if (cascadeManager.hasMaxWidth == true || isFirstCascade == true)
		{
			hasMaxWidth = isNone(maxWidth) == false;
		}
		
		if (cascadeManager.hasTextAlign == true || isFirstCascade == true)
		{
			isLeftAligned = false;
			switch(getKeyword(textAlign))
			{
				case LEFT:
					isLeftAligned = true;
					
				default:	
			}
		}
		
		if (cascadeManager.hasTop == true || isFirstCascade == true)
		{
			hasAutoTop = isAuto(top);
		}
		
		if (cascadeManager.hasBottom == true || isFirstCascade == true)
		{
			hasAutoBottom = isAuto(bottom);
		}
		
		if (cascadeManager.hasLeft == true || isFirstCascade == true)
		{
			hasAutoLeft = isAuto(left);
		}
		
		if (cascadeManager.hasRight == true || isFirstCascade == true)
		{
			hasAutoRight = isAuto(right);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	
	/**
	 * Actually cascade a property
	 */
	private function cascadeProperty(propertyIndex:Int, initialStyleDeclaration:CSSStyleDeclaration, styleSheetDeclaration:CSSStyleDeclaration, inlineStyleDeclaration:CSSStyleDeclaration, parentStyleDeclaration:CSSStyleDeclaration, parentColor:CSSColorValue, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float, programmaticChange:Bool, hasInlineStyle:Bool, hasStyleSheetStyle:Bool):Bool
	{
		//first check if this property is defined inline which always has the
		//highest priority
		if (hasInlineStyle == true)
		{
			var typedProperty:TypedPropertyVO = inlineStyleDeclaration.getTypedProperty(propertyIndex);
			if (typedProperty != null)
			{
				return setProperty(propertyIndex, typedProperty, parentStyleDeclaration, initialStyleDeclaration,  parentColor, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange, false, false);
			}
		}
		
		//else check if a value for this style for this HTMLElement was defined in the document's style sheet
		if (hasStyleSheetStyle == true)
		{
			var typedProperty:TypedPropertyVO = styleSheetDeclaration.getTypedProperty(propertyIndex);
			if (typedProperty != null)
			{
				return setProperty(propertyIndex, typedProperty, parentStyleDeclaration, initialStyleDeclaration, parentColor, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange, false, false);
			}
		}
		
		//else if the property is inherithed (for instance 'font-family'),
		//use the value from the parent
		if (isInherited(propertyIndex) == true)
		{
			if (parentStyleDeclaration.getTypedProperty(propertyIndex) != null)
			{
				return setProperty(propertyIndex, parentStyleDeclaration.getTypedProperty(propertyIndex), parentStyleDeclaration, initialStyleDeclaration,  parentColor, parentFontSize, parentXHeight, fontSize, xHeight, programmaticChange, true, false);
			}
			//if the parent has no defined property for this style, it
			//means that it uses the initial property value
			else
			{
				return setInitialProperty(propertyIndex);
			}
		}
		
		//else at last use the initial value of the property
		return setInitialProperty(propertyIndex);
	}
	
	/**
	 * This method is a special case used when the initial
	 * value of a CSS property should be used. For this case,
	 * no new typed property object is created as it will only
	 * copy the initial CSS property value. Instead the value
	 * for this property remains null, which means it uses
	 * the initial value for the CSS style
	 */
	private function setInitialProperty(propertyIndex:Int):Bool
	{
		//check if the property has currently a value other than 
		//the initial value, in which case the current value must
		//be set to null
		if (specifiedValues.getTypedProperty(propertyIndex) != null)
		{
			//TODO 2 : should check if start animation
			
			specifiedValues.removeProperty(propertyIndex);
			computedValues.removeProperty(propertyIndex);
			htmlElement.invalidateStyle(propertyIndex);
			//signal that the property value changed
			return true;
		}
		//border case : the computed values might be set while specified value is
		//null, for instance when applying position, float and display relationship.
		//
		//For instance, an inline element with an 'absolute' position will have a computed
		//display value of 'block'. The value is reset but is it not considered that the
		//calue changed
		else if (computedValues.getTypedProperty(propertyIndex) != null)
		{
			computedValues.removeProperty(propertyIndex);
		}
		
		
		return false;
	}
	
	/**
	 * cascade a property by updating its specified value
	 * and computing its value if necessary
	 * 
	 * @param propertyIndex the index of the cascaded property
	 * @param cascadedProperty the property used as reference
	 * for the cascading, might come from a style sheet 
	 * delcaration, inline declaration, might be inherited or
	 * might be the initial value for this property
	 * 
	 * @return wether the specified value of the property did change
	 */
	private function setProperty(propertyIndex:Int, cascadedProperty:TypedPropertyVO, parentStyleDeclaration:CSSStyleDeclaration, initialStyleDeclaration:CSSStyleDeclaration, parentColor:CSSColorValue, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float, programmaticChange:Bool, isInherited:Bool, isInitial:Bool):Bool
	{
		var property:CSSPropertyValue = cascadedProperty.typedValue;
		
		//get the property with the same name from the specified properties of this CoreStyle
		var specifiedProperty:TypedPropertyVO = specifiedValues.getTypedProperty(propertyIndex);
		
		//check that the new property has a different value from
		//the current one. If it doesn't, cascading is over
		if (specifiedProperty != null)
		{
			if (property == specifiedProperty.typedValue)
			{
				return false;
			}
		}
		
		if (specifiedProperty != null)
		{
			//update the specified property
			specifiedValues.setTypedProperty(propertyIndex, property, cascadedProperty.important);
		}
		else
		{
			//same as above but faster
			specifiedValues.setTypedPropertyInitial(propertyIndex, property, cascadedProperty.important);
		}
		
		
		//update the computed property
		var computedProperty:CSSPropertyValue = null;
		
		//if the value to apply is the not
		//the initial style value
		if (isInitial == false)
		{
			switch(property)
			{
				//for a specified value of inherit, the 
				//computed value is always the one of the parent
				case INHERIT:
					computedProperty = parentStyleDeclaration.getTypedProperty(propertyIndex).typedValue;
					//set the inherited flag to make sure that no animation is started as the 
					//result of this property change
					isInherited = true;
				
				//for a specified value of initial, 
				//the computed value is the initial one 
				//
				//TODO 2 : doesn't make sense ? for instance for font-size whose specified value is medium,
				//computed value shouldn't be medium. Should Initial and inherit instead affect specified value ?
				case INITIAL:
					computedProperty = initialStyleDeclaration.getTypedProperty(propertyIndex).typedValue;
					
				default:	
					computedProperty = getComputedProperty(propertyIndex, property, parentFontSize, parentXHeight, fontSize, xHeight, parentColor);
			}
		}
		//when initial value applied it is 
		//sure that it won't be 'inherit' or 'initial'
		else
		{
			computedProperty =  getComputedProperty(propertyIndex, property, parentFontSize, parentXHeight, fontSize, xHeight, parentColor);
		}
		
		//try to start a transition on the property
		
		//wether to update the computed property,
		//it not updated if a transition is currently happening
		var registerPengingComputedProperty:Bool = false;

		//non need if no property are declared to be transitioned
		if (hasTransitionnableProperties == true)
		{
			//if property is inherited or style was not programmatic, don't start transition
			if (programmaticChange == true && isInherited == false)
			{
				if (isAnimatable(propertyIndex))
				{
					
					if (_animator == null)
					{
						initAnimator();
					}
					
					var transition:Transition = _transitionManager.getTransition(propertyIndex, this);
					//check wether this property is currently transitioning
					if (transition != null)
					{
						registerPengingComputedProperty = true;
						
						//TODO 2 : current limitation for revert is that
						//only css property value which computes to absolute length
						//wihout layout are supported.
						//
						//Should instead register a transition revert for next frame.
						//Should have a used value for animation and one used value for
						//actual value ?
						switch (computedProperty)
						{
							case ABSOLUTE_LENGTH(value):
								//check if new computed property revert the animation
								var didRevert:Bool = _animator.revertTransitionIfNeeded(transition,  value, this);
								
								//if did revert, then don't store computed property
								//as the transiton now has a different end value
								if (didRevert == true)
								{
									registerPengingComputedProperty = false;
								}
								
							default:
						}
					}
					//only try to start if not currently transitionning
					else
					{
						_animator.registerPendingAnimation(propertyIndex, getAnimatablePropertyValue(propertyIndex));
						var htmlDocument:HTMLDocument = cast(htmlElement.ownerDocument);
						htmlDocument.invalidationManager.invalidatePendingAnimations();
					}
				}
			}
		}
		
		if (specifiedProperty != null)
		{
			if (registerPengingComputedProperty == false)
			{
				computedValues.setTypedProperty(propertyIndex, computedProperty, cascadedProperty.important);
			}
			//if property is transitioning, store the computed value, it will be apply
			//at the en d of the transition and might trigger a new transition
			else
			{
				if (_pendingComputedValues == null)
				{
					initPendingComputedValues();
				}
				var typedComputedProperty:TypedPropertyVO = new TypedPropertyVO();
				typedComputedProperty.important = cascadedProperty.important;
				typedComputedProperty.index = propertyIndex;
				typedComputedProperty.typedValue = computedProperty;
				
				_pendingComputedValues[propertyIndex] = typedComputedProperty;
			}
		}
		else
		{
			if (registerPengingComputedProperty == false)
			{
				computedValues.setTypedPropertyInitial(propertyIndex, computedProperty, cascadedProperty.important);
			}
		}
		
		
		htmlElement.invalidateStyle(propertyIndex);
		
		return true;
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STYLES COMPUTING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given specified property value, 
	 * return its computed value, which is
	 * the value which will be used for 
	 * inheritance.
	 * 
	 * For instance, when a value is defined
	 * as a Length (like '10px'), it will
	 * always be computed into an absolute
	 * length ('10px' becomes '10')
	 * 
	 * If a property is not present in this method
	 * or one of its value does'nt appear, it means
	 * that the computed value is the same as the
	 * specified value and so it doesn't need any
	 * further treatement
	 */
	private function getComputedProperty(propertyIndex:Int, property:CSSPropertyValue, parentFontSize:Float, parentXHeight:Float, fontSize:Float, xHeight:Float, parentColor:CSSColorValue):CSSPropertyValue
	{
		switch(propertyIndex)
		{
			case CSSConstants.MIN_WIDTH, CSSConstants.MIN_HEIGHT, CSSConstants.MAX_HEIGHT, CSSConstants.MAX_WIDTH,
			CSSConstants.LEFT, CSSConstants.RIGHT, CSSConstants.TOP, CSSConstants.BOTTOM,
			CSSConstants.PADDING_LEFT, CSSConstants.PADDING_RIGHT, CSSConstants.PADDING_TOP, CSSConstants.PADDING_BOTTOM,
			CSSConstants.MARGIN_TOP, CSSConstants.MARGIN_LEFT, CSSConstants.MARGIN_BOTTOM, CSSConstants.MARGIN_RIGHT,
			CSSConstants.WIDTH, CSSConstants.HEIGHT:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					case INTEGER(value):
						return ABSOLUTE_LENGTH(value);
						
					default:	
				}
				
			//for transition property, "left" "right, "top" and "bottom"
			//value are parsed as CSS keywords (they are used for 
			//float style for instance), but should actually be  computed as
			//identifier for this property, as they refer to the top, left, right, bottom
			//CSS styles
			case CSSConstants.TRANSITION_PROPERTY:
				switch(property)
				{
					case KEYWORD(value):
						switch(value)
						{
							case LEFT:
								return IDENTIFIER(CSSConstants.LEFT_IDENT);
								
							case RIGHT:
								return IDENTIFIER(CSSConstants.RIGHT_IDENT);
								
							case TOP:	
								return IDENTIFIER(CSSConstants.TOP_IDENT);
								
							case BOTTOM:
								return IDENTIFIER(CSSConstants.BOTTOM_IDENT);
								
							default:	
						}
						
					case CSS_LIST(value):
						var length:Int = value.length;
						for (i in 0...length)
						{
							switch (value[i])
							{
								case KEYWORD(keyword):
									switch(keyword)
									{
										case LEFT:
											value[i] = IDENTIFIER(CSSConstants.LEFT_IDENT);
											
										case RIGHT:
											value[i] = IDENTIFIER(CSSConstants.RIGHT_IDENT);
											
										case TOP:	
											return IDENTIFIER(CSSConstants.TOP_IDENT);
								
										case BOTTOM:	
											return IDENTIFIER(CSSConstants.BOTTOM_IDENT);		
											
										default:	
									}
									
								default:	
							}
						}
						
					default:	
				}
				
			case CSSConstants.OPACITY:
				switch(property)
				{
					case NUMBER(value):
						if (value > 1)
						{
							return NUMBER(1);
						}
						if (value < 0)
						{
							return NUMBER(0);
						}
						
					case INTEGER(value):
						if (value < 0)
						{
							return NUMBER(0);
						}
						if (value > 1)
						{
							return NUMBER(1);
						}
						return NUMBER(value);
						
					default:	
				}
				
			case CSSConstants.FONT_SIZE:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, parentFontSize, parentXHeight));
						
					case PERCENTAGE(value):	
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromPercent(value, parentFontSize));
						
					case KEYWORD(value):
						switch(value)
						{
							case XX_SMALL, X_SMALL, SMALL, MEDIUM, LARGE, X_LARGE, XX_LARGE:
								return ABSOLUTE_LENGTH(CSSValueConverter.getFontSizeFromAbsoluteSizeValue(value));
								
							case LARGER, SMALLER:
								return ABSOLUTE_LENGTH(CSSValueConverter.getFontSizeFromRelativeSizeValue(value, parentFontSize));
								
							default:	
						}
						
					default:	
				}	
				
			case CSSConstants.TRANSFORM:
				switch(property)
				{
					//TODO : manage transform function to turn values
					//into absolutes length
					case KEYWORD(value):
						
					default:	
				}
				
			case CSSConstants.FONT_WEIGHT:
				switch(property)
				{
					//TODO : manage bolder and lighter with parent font-weight
					case KEYWORD(value):
						
						
					default:	
				}
				
			case CSSConstants.VERTICAL_ALIGN:
				switch(property)
				{
					case INTEGER(value):
						return ABSOLUTE_LENGTH(0);
						
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					default:	
				}	
				
			case CSSConstants.CURSOR:
				switch(property)
				{
					//TODO 1: should compute into absolute url
					case URL(value):
						
						
					default:	
				}	
				
			case CSSConstants.LINE_HEIGHT:
				switch(property)
				{
					case NUMBER(value):
						return ABSOLUTE_LENGTH(value * fontSize);
						
					case INTEGER(value):
						return ABSOLUTE_LENGTH(value * fontSize);
					
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					case PERCENTAGE(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromPercent(value, fontSize));
						
					default:	
				}
				
			case CSSConstants.TEXT_INDENT:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
	
					case INTEGER(value):
						return ABSOLUTE_LENGTH(value);
						
					default:	
				}
				
			case CSSConstants.LETTER_SPACING:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					default:	
				}
				
			case CSSConstants.WORD_SPACING:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					case KEYWORD(value):
						return ABSOLUTE_LENGTH(0);
						
					default:	
				}	
				
			case CSSConstants.COLOR:
				switch(property)
				{
					case COLOR(value):
						return COLOR(CSSValueConverter.getComputedCSSColorFromCSSColor(value, parentColor));
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_COLOR:
				switch(property)
				{
					case COLOR(value):
						return COLOR(CSSValueConverter.getComputedCSSColorFromCSSColor(value, getColor(color)));
						
					default:	
				}	
			
			//TODO : add support for list of item	
			case CSSConstants.BACKGROUND_IMAGE:
				switch(property)
				{
					case KEYWORD(value):
						
					case URL(value):
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_POSITION:
				switch(property)
				{
					case KEYWORD(value):
						switch(value)
						{
							case LEFT, RIGHT:
								return GROUP([KEYWORD(value), KEYWORD(CENTER)]);
								
							case TOP, BOTTOM:	
								return GROUP([KEYWORD(CENTER), KEYWORD(value)]);
								
							default:
								return GROUP([KEYWORD(value), KEYWORD(CENTER)]);
						}
						
					
					case LENGTH(value):
						return GROUP([ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight)), KEYWORD(CENTER)]);
						
					case PERCENTAGE(value):
						return GROUP([PERCENTAGE(value), KEYWORD(CENTER)]);
						
					case GROUP(value):
						var backgroundPositionX:CSSPropertyValue = null;
						var backgroundPostionY:CSSPropertyValue = null;
						switch(value[0])
						{
							case LENGTH(value):
								backgroundPositionX = ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundPositionX = value[0];
						}
						
						switch(value[1])
						{
							case LENGTH(value):
								backgroundPostionY = ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundPostionY = value[1];
						}
						
						return GROUP([backgroundPositionX, backgroundPostionY]);
					
					default:	
				}
				
			case CSSConstants.BACKGROUND_REPEAT:
				switch(property)
				{
					case KEYWORD(value):
						switch(value)
						{
							case REPEAT:
								return GROUP([KEYWORD(REPEAT), KEYWORD(REPEAT)]);
								
							case NO_REPEAT:
								return  GROUP([KEYWORD(NO_REPEAT), KEYWORD(NO_REPEAT)]);
								
							case ROUND:
								return GROUP([KEYWORD(ROUND), KEYWORD(ROUND)]);	
								
							case SPACE:
								return GROUP([KEYWORD(SPACE), KEYWORD(SPACE)]);		
								
							case REPEAT_X:
								return GROUP([KEYWORD(REPEAT), KEYWORD(NO_REPEAT)]);		
								
							case REPEAT_Y:
								return GROUP([KEYWORD(NO_REPEAT), KEYWORD(REPEAT)]);			
								
							default:					
						}
						
					//TODO	
					case GROUP(value):
						
					default:	
				}
				
			case CSSConstants.BACKGROUND_SIZE:
				switch(property)
				{
					case LENGTH(value):
						return ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
						
					//TODO	
					case GROUP(value):
						var backgroundSizeX:CSSPropertyValue = null;
						var backgroundSizeY:CSSPropertyValue = null;
						
						switch(value[0])
						{
							case LENGTH(value):
								backgroundSizeX = ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundSizeX = value[0];
						}
						
						switch(value[1])
						{
							case LENGTH(value):
								backgroundSizeY = ABSOLUTE_LENGTH(CSSValueConverter.getPixelFromLength(value, fontSize, xHeight));
								
							default:	
								backgroundSizeY = value[1];
						}
						
						return GROUP([backgroundSizeX, backgroundSizeY]);
						
					default:	
				}	
		}
		
		return property;
	}
	
	/**
	 * Special computing relationship exists between position, 
	 * float and display. For instance if position is absolute,
	 * a dispaly value of 'inline' will compute to 'block' as
	 * absolutely positioned element should always be displayed
	 * as blocks
	 */
	private function applyPositionFloatAndDisplayRelationship():Void
	{
		switch(getKeyword(position))
		{
			case ABSOLUTE, FIXED:
				switch(getKeyword(display))
				{
					//if position is absolute, inline display
					//must become block
					case INLINE, INLINE_BLOCK:
						computedValues.setTypedProperty(CSSConstants.DISPLAY, KEYWORD(BLOCK), false);
					
					default:	
				}
				
				switch(getKeyword(cssFloat))
				{
					//if position is absolute, the element
					//can't be floated
					case LEFT, RIGHT:
						computedValues.setTypedProperty(CSSConstants.FLOAT, KEYWORD(NONE), false);
						
					default:	
				}
				
			default:	
				
				//check if the element is floated
				switch(getKeyword(cssFloat))
				{
					case LEFT, RIGHT:
						switch (getKeyword(display))
						{
							//if the element is floated, it must be a block
							case INLINE, INLINE_BLOCK:
							computedValues.setTypedProperty(CSSConstants.DISPLAY, KEYWORD(BLOCK), false);
							
							default:
						}
						
					default:	
				}
				
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Start pending animations on the animator
	 */
	public function startPendingAnimations():Bool
	{
		//if the animator was not instantiated yet
		//then no animation were registered for this
		//node yet
		if (_animator == null)
		{
			return false;
		}
		
		return _animator.startPendingAnimations(this);
	}
	
	/**
	 * When called, the layout is up-to-date, the
	 * pending transition end event can now
	 * be dispatched
	 */
	public function endPendingAnimation():Void
	{
		//if null, no transition were started on this core style
		if (_pendingTransitionEndEvents == null)
		{
			return;
		}
		
		var length:Int = _pendingTransitionEndEvents.length;
		if (length == 0)
		{
			return;
		}
		
		for (i in 0...length)
		{
			htmlElement.dispatchEvent(_pendingTransitionEndEvents[i]);
		}
		//reset the array, each event must be dispatched only once
		_pendingTransitionEndEvents = _pendingTransitionEndEvents.clear();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a transition is complete, invalidate the HTMLElement,
	 * create and store a transition end event, it must not be dispatched
	 * before the layout is updated
	 */
	private function onTransitionComplete(transition:Transition):Void
	{
		htmlElement.invalidateStyle(transition.propertyIndex);
		
		//schedule an update of the pending animations
		var htmlDocument:HTMLDocument = cast(htmlElement.ownerDocument);
		htmlDocument.invalidationManager.invalidatePendingAnimations();
		
		var transitionEvent:TransitionEvent = new TransitionEvent();
		transitionEvent.initTransitionEvent(EventConstants.TRANSITION_END, true, true, CSSConstants.getPropertyNameFromIndex(transition.propertyIndex), transition.transitionDuration, "");
		
		//init on first use
		if (_pendingTransitionEndEvents == null)
		{
			_pendingTransitionEndEvents = new Array<TransitionEvent>();
		}
		
		_pendingTransitionEndEvents.push(transitionEvent);
		
		//check wether the computed value of the transitioned property change
		//during the transition
		if (_pendingComputedValues != null)
		{
			//if a pending computed property was registered for this property
			if (_pendingComputedValues[transition.propertyIndex] != null)
			{
				//start a transition with the new current computed value
				_animator.registerPendingAnimation(transition.propertyIndex, getAnimatablePropertyValue(transition.propertyIndex));
				
				htmlDocument.invalidationManager.invalidatePendingAnimations();
				
				//update the computed value to get the right value for the end of the transition
				var pendingComputedProperty:TypedPropertyVO = _pendingComputedValues[transition.propertyIndex];
				computedValues.setTypedProperty(pendingComputedProperty.index, pendingComputedProperty.typedValue, pendingComputedProperty.important);
			
				_pendingComputedValues[transition.propertyIndex] = null;
			}
		}
		
	}
	
	/**
	 * When a transition is updated, invalidate the HTMLElement
	 * to schedule a repaint and relayout of the rendering tree
	 */
	private function onTransitionUpdate(transition:Transition):Void
	{
		htmlElement.invalidateStyle(transition.propertyIndex);
	}
	
	/**
	 * Utils method to return the value of a property which can be transitioned
	 * If the property is currently being transitioned, return the current value
	 * of the transition, else return the computed value of the property
	 * @param	propertyIndex the index of the property whose value is returned
	 */
	private inline function getTransitionablePropertyValue(properyIndex:Int):CSSPropertyValue
	{
		//sortcut if this style object has no transitionable property
		if (hasTransitionnableProperties == false)
		{
			return getComputedOrInitialProperty(properyIndex).typedValue;
		}
		//shortcut if there are not any transitions in progress
		else if (_transitionManager.hasTransitionsInProgress == false)
		{
			return getComputedOrInitialProperty(properyIndex).typedValue;
		}
		else
		{
			//try to get a transition for the property
			var transition:Transition = _transitionManager.getTransition(properyIndex, this);
			//if there actually is a transition in progress for this property,
			//return its current value
			if (transition != null)
			{
				return ABSOLUTE_LENGTH(transition.currentValue);
			}
			//else return the computed value for the given property
			else
			{
				return getComputedOrInitialProperty(properyIndex).typedValue;
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given CSS property, return its computed value for this style object.
	 * It can either come from the computed style declaration of this style object
	 * or if null for this style object, it means that it uses the initial computed
	 * style value
	 */
	private function getComputedOrInitialProperty(propertyIndex:Int):TypedPropertyVO
	{
		var typedProperty:TypedPropertyVO = computedValues.getTypedProperty(propertyIndex);
		
		if (typedProperty == null)
		{
			typedProperty = _initialComputedStyleDeclaration.getTypedProperty(propertyIndex);
		}
		
		return typedProperty;
		
	}
	
	/**
	 * Return the IDL name of the property, i.e
	 * the name used for scripting. For instance,
	 * min-width will become camel-case minWidth
	 * 
	 * TODO 1 : complete
	 */
	private function getIDLName(propertyIndex:Int):String
	{
		switch(propertyIndex)
		{
			case CSSConstants.MIN_HEIGHT:
				return CSSConstants.HEIGHT_IDL_NAME;
				
			case CSSConstants.MAX_HEIGHT:
				return CSSConstants.MAX_HEIGHT_IDL_NAME;
				
			case CSSConstants.MIN_WIDTH:
				return CSSConstants.MIN_WIDTH_IDL_NAME;
				
			case CSSConstants.MAX_WIDTH:
				return CSSConstants.MAX_WIDTH_IDL_NAME;
			
			default:
				return CSSConstants.getPropertyNameFromIndex(propertyIndex);
		}
	}
	
	/**
	 * Return wether a given CSS property can
	 * be animated/transitioned
	 * 
	 * TODO 1 : complete
	 */
	private function isAnimatable(propertyIndex:Int):Bool
	{
		switch(propertyIndex)
		{
			case CSSConstants.WIDTH, CSSConstants.HEIGHT, CSSConstants.TOP, CSSConstants.BOTTOM,
			CSSConstants.LEFT, CSSConstants.RIGHT, CSSConstants.OPACITY:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * For a given animatable property, return its current value as a float,
	 * so that it can be used to animate
	 */
	private function getAnimatablePropertyValue(propertyIndex:Int):Float
	{
		switch(propertyIndex)
		{
			case CSSConstants.OPACITY:
				switch(opacity)
				{
					case NUMBER(value):
						return value;
					
					case ABSOLUTE_LENGTH(value):
						return value;
						
					default: 
						return 0;
				}
				
			//for values which are actually determined
			//during layout, such as width and height, use the used value
			default:
				return Reflect.field(usedValues, getIDLName(propertyIndex));
		}
	}
	
	/**
	 * Return wether a given CSS property is inherithed,
	 * meaning the an HTMLElement inherits its property
	 * from its value from its parent node if the 
	 * property has no explicit value defined for it.
	 * 
	 * For instance 'font-family' is inherited, if it is
	 * set on the root HTML element, its values will be
	 * used by each node in the document unless another
	 * value is explicitely used
	 */
	private inline function isInherited(propertyIndex:Int):Bool
	{
		switch(propertyIndex)
		{
			case CSSConstants.COLOR, CSSConstants.CURSOR, CSSConstants.FONT_FAMILY,
			CSSConstants.FONT_SIZE, CSSConstants.FONT_STYLE, CSSConstants.FONT_VARIANT,
			CSSConstants.FONT_WEIGHT, CSSConstants.LETTER_SPACING, CSSConstants.LINE_HEIGHT,
			CSSConstants.TEXT_ALIGN, CSSConstants.TEXT_INDENT, CSSConstants.TEXT_TRANSFORM,
			CSSConstants.VISIBILITY, CSSConstants.WHITE_SPACE, CSSConstants.WORD_SPACING:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Return the keyword from a CSS property,
	 * or throw an exception if it doesn't wrap a
	 * keyword
	 */
	public function getKeyword(value:CSSPropertyValue):CSSKeywordValue
	{	
		switch(value)
		{
			case KEYWORD(value):
				return value;
				
			default:
				throw 'not a keyword value';
		}
	}
	
	/**
	 * Same as above for number
	 */
	public function getNumber(value:CSSPropertyValue):Float
	{
		switch(value)
		{
			case NUMBER(value):
				return value;
				
			default:
				throw'not a number value';
		}
	}
	
	/**
	 * Same as above for list
	 */
	public function getList(value:CSSPropertyValue):Array<CSSPropertyValue>
	{
		switch (value)
		{
			case CSS_LIST(value):
				return value;
				
			default:
				throw'not a list value';
		}
	}
	
	/**
	 * Same as above for absolute length
	 */
	public function getAbsoluteLength(value:CSSPropertyValue):Float
	{
		switch (value)
		{
			case ABSOLUTE_LENGTH(value):
				return value;
				
			default:
				throw'not an absolute length value';
		}
	}
	
	/**
	 * Same as above for color
	 */
	public function getColor(value:CSSPropertyValue):CSSColorValue
	{
		switch(value)
		{
			case COLOR(value):
				return value;
				
			default:
				throw'not a color value';
		}
	}
	
	/**
	 * Utils method returning wether a given
	 * style's value is the CSS 'auto'
	 * keyword
	 */
	public function isAuto(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				switch(value)
				{
					case AUTO:
						return true;
						
					default:
						return false;
				}
				
			default:
				return false;
		}
	}
	
	/**
	 * Same as above for the 'none' CSS keyword
	 */
	public function isNone(property:CSSPropertyValue):Bool
	{
		switch(property)
		{
			case KEYWORD(value):
				switch(value)
				{
					case NONE:
						return true;
						
					default:
						return false;
				}
				
			default:
				return false;
		}
	}
	
	/////////////////////////////////
	// STYLE GETTERS
	// For each, return the
	// computed value of the style
	////////////////////////////////
	
	private inline  function get_opacity():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.OPACITY);
	}
	
	private inline  function get_marginLeft():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_LEFT);
	}
	
	private inline function get_marginRight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_RIGHT);
	}
	
	private inline function get_marginTop():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_TOP);
	}
	
	private inline function get_marginBottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MARGIN_BOTTOM);
	}
	
	private inline function get_paddingLeft():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_LEFT);
	}
	
	private inline function get_paddingRight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_RIGHT);
	}
	
	private inline function get_paddingTop():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_TOP);
	}
	
	private inline function get_paddingBottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.PADDING_BOTTOM);
	}
	
	private inline function get_width():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.WIDTH);
	}
	
	private inline function get_height():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.HEIGHT);
	}
	
	private inline function get_minHeight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_HEIGHT);
	}
	
	private inline function get_maxHeight():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_HEIGHT);
	}
	
	private inline  function get_minWidth():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MIN_WIDTH);
	}
	
	private inline function get_maxWidth():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.MAX_WIDTH);
	}
	
	private inline function get_top():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.TOP);
	}
	
	private inline function get_left():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.LEFT);
	}
	
	private inline function get_bottom():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.BOTTOM);
	}
	
	private inline function get_right():CSSPropertyValue 
	{
		return getTransitionablePropertyValue(CSSConstants.RIGHT);
	}
	
	private inline function get_fontSize():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.FONT_SIZE);
	}
	
	private inline function get_display():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.DISPLAY).typedValue;
	}
	
	private inline inline function get_position():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.POSITION).typedValue;
	}
	
	private inline function get_cssFloat():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.FLOAT).typedValue;
	}
	
	private inline function get_clear():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.CLEAR).typedValue;
	}
	
	private inline function get_zIndex():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.Z_INDEX).typedValue;
	}
	
	private inline function get_backgroundColor():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_COLOR).typedValue;
	}
	
	private inline function get_backgroundImage():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_IMAGE).typedValue;
	}

	private inline function get_backgroundOrigin():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_ORIGIN).typedValue;
	}
	
	private inline function get_backgroundClip():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_CLIP).typedValue;
	}
	
	private inline function get_backgroundAttachment():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_ATTACHMENT).typedValue;
	}
	
	private inline function get_backgroundRepeat():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_REPEAT).typedValue;
	}
	
	private inline function get_backgroundSize():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_SIZE).typedValue;
	}
	
	private inline function get_backgroundPosition():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.BACKGROUND_POSITION).typedValue;
	}
	
	private inline function get_fontWeight():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.FONT_WEIGHT).typedValue;
	}
	
	private inline function get_fontStyle():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.FONT_STYLE).typedValue;
	}
	
	private inline function get_fontFamily():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.FONT_FAMILY).typedValue;
	}
	
	private inline function get_fontVariant():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.FONT_VARIANT).typedValue;
	}
	
	private inline function get_color():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.COLOR).typedValue;
	}
	
	private inline function get_lineHeight():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.LINE_HEIGHT);
	}
	
	private inline function get_textTransform():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TEXT_TRANSFORM).typedValue;
	}
	
	private inline function get_letterSpacing():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.LETTER_SPACING);
	}
	
	private inline function get_wordSpacing():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.WORD_SPACING);
	}
	
	private inline function get_whiteSpace():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.WHITE_SPACE).typedValue;
	}
	
	private inline function get_textAlign():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TEXT_ALIGN).typedValue;
	}
	
	private inline function get_textIndent():CSSPropertyValue
	{
		return getTransitionablePropertyValue(CSSConstants.TEXT_INDENT);
	}
	
	private inline function get_verticalAlign():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.VERTICAL_ALIGN).typedValue;
	}
	
	private inline function get_visibility():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.VISIBILITY).typedValue;
	}
	
	private inline function get_overflowX():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.OVERFLOW_X).typedValue;
	}
	
	private inline function get_overflowY():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.OVERFLOW_Y).typedValue;
	}
	
	private inline function get_transformOrigin():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSFORM_ORIGIN).typedValue;
	}
	
	private inline function get_transform():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSFORM).typedValue;
	}
	
	private inline function get_cursor():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.CURSOR).typedValue;
	}
	
	private inline function get_transitionProperty():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSITION_PROPERTY).typedValue;
	}
	
	private inline function get_transitionDuration():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSITION_DURATION).typedValue;
	}
	
	private inline function get_transitionTimingFunction():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSITION_TIMING_FUNCTION).typedValue;
	}
	
	private inline function get_transitionDelay():CSSPropertyValue
	{
		return getComputedOrInitialProperty(CSSConstants.TRANSITION_DELAY).typedValue;
	}
}