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
import cocktail.core.Window;
import cocktail.core.font.FontData;
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
 * ElementRenderer. For instance, a ContainerCoreStyle with Text node
 * children will build a tree containing TextRenderer and BlockBoxRenderer
 * or InlineBoxRenderer.
 * Those objects know how to render themselves.
 * 
 * Styling is done in 2 phases : 
 * - first the styles of the HTMLElement are computed into
 * usable values, for instance values defined as percentage
 * are converted to absolute values. During this phase, an
 * abstract rendering tree of the element is built
 * - once all the styles are computed and the rendering tree is ready, it
 * renders itself
 * 
 * This class implements the default behaviour of an embedded HTMLElement
 * 
 * TODO IMPORTANT : eventually, this class and its subclasses should be merged
 * with the classes of the renderer package as there is a lot of common code
 * between the 2. This way, we can follow the same pattern as webkit with :
	 * A DOM tree with the HTMLElement who ows the rendering tree
	 * A rendering tree with the ElementRender classes merged with the CoreStyle classes, in
	 * charge of the layout and of rendering themselves
	 * A layer tree, in charge of rendering each layer of the rendering tree in the right order
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
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyleData;
	
		
	/**
	 * Returns metrics info for the currently defined
	 * font and font size. Used in inline formatting context
	 * to determine lineBoxes sizes and text vertical and horizontal
	 * position
	 */
	private var _fontMetrics:FontMetricsData;
	public var fontMetrics(getFontMetricsData, never):FontMetricsData;
	
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
	public function new(tagName:String) 
	{
		initDefaultStyleValues(tagName);
	}
	
	/**
	 * Init the standard default value for styles
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
		
		//TODO : get tag name
		applyDefaultHTMLStyles(tagName);
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
	 * 
	 * It is public as it may be called by the
	 * ContainerCoreStyle of the parent HTMLElement
	 * which may need to known the display style of its
	 * children to determine which type of formatting context
	 * to establish for its children
	 */
	public function computeDisplayStyles():Void
	{
		DisplayStylesComputer.compute(this);
	}
	
	/**
	 * Computes the styles determining the background
	 * color, images... of a HTMLElement
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
	public function computeTextAndFontStyles(containingHTMLElementData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{
		FontAndTextStylesComputer.compute(this, containingHTMLElementData, containingHTMLElementFontMetricsData);
	}
	
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the HTMLElement, based on
	 * its positioning scheme
	 */ 
	public function computeBoxModelStyles(containingBlockDimensions:ContainingHTMLElementData):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//do compute the box model styles
		boxComputer.measure(this, containingBlockDimensions);
	}
	
		
	/**
	 * overriden to use box computer specific to 
	 * container HTMLElement instead of the embedded one
	 */
	private function getBoxStylesComputer():BoxStylesComputer
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
 * TODO : re-implement
	override private function getBoxStylesComputer():BoxStylesComputer
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
	}*/
	
		/**
	 * In most cases, when the height of a HTMLElement
	 * is 'auto', its computed height become the total height
	 * of its in flow children, computed once all its
	 * children have been laid out 
	 * 
	 * @param	childrenHeight the total height of the children once laid out
	 */
	public function applyContentHeightIfNeeded(containingBlockDimensions:ContainingHTMLElementData, childrenHeight:Int):Int
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();		
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
	 * @param	containingHTMLElementData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this HTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	public function shrinkToFitIfNeeded(containingHTMLElementData:ContainingHTMLElementData, minimumWidth:Int):Int
	{		
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		return boxComputer.shrinkToFit(this, containingHTMLElementData, minimumWidth);
	}
	
	
	private function getFontMetricsData():FontMetricsData
	{
		var fontManager:FontManager = new FontManager();
		_fontMetrics = fontManager.getFontMetrics(UnitManager.getCSSFontFamily(computedStyle.fontFamily), computedStyle.fontSize);
	
		return _fontMetrics;
	}
	
	private function invalidate():Void
	{
		//TODO
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////

	private function getComputedStyle():ComputedStyleData
	{
		return _computedStyle;
	}
	
	private function setComputedStyle(value:ComputedStyleData):ComputedStyleData
	{
		return _computedStyle = value;
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
		invalidate();
		return _fontSize = value;
	}
	
	private function setFontWeight(value:FontWeight):FontWeight
	{
		invalidate();
		return _fontWeight = value;
	}
	
	private function setFontStyle(value:FontStyle):FontStyle
	{
		invalidate();
		return _fontStyle = value;
	}
	
	private function setFontFamily(value:Array<String>):Array<String>
	{
		invalidate();
		return _fontFamily = value;
	}
	
	private function setFontVariant(value:FontVariant):FontVariant
	{
		invalidate();
		return _fontVariant = value;
	}
	
	private function setTextTransform(value:TextTransform):TextTransform
	{
		invalidate();
		return _textTransform = value;
	}
	
	private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		invalidate();
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
		invalidate();
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
		invalidate();
		return _backgroundColor = value;
	}
	
	private function getBackgroundColor():BackgroundColor
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		invalidate();
		return _backgroundImage = value;
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
		invalidate();
		return _backgroundSize = value;
	}
	
	private function getBackgroundSize():Array<BackgroundSize>
	{
		return _backgroundSize;
	}
	
	private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		invalidate();
		return _backgroundClip = value;
	}
	
	private function getBackgroundClip():Array<BackgroundClip>
	{
		return _backgroundClip;
	}
	
	private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		invalidate();
		return _backgroundPosition = value;
	}
	
	private function getBackgroundPosition():Array<BackgroundPosition>
	{
		return _backgroundPosition;
	}
	
	private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		invalidate();
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