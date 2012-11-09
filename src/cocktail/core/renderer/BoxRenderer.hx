 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.css.CSSConstants;
import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.linebox.InlineBox;

import cocktail.core.layout.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.window.Window;
import cocktail.Lib;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.background.BackgroundManager;
import cocktail.core.layout.computer.BackgroundStylesComputer;
import cocktail.core.layout.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.BoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.layout.computer.FontAndTextStylesComputer;
import cocktail.core.layout.computer.VisualEffectStylesComputer;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * Base class for box renderers. A box renderer
 * is a visual element which conforms to the
 * CSS box model. This base class is used by
 * both replaced box (image...) and container box
 * (block box, inline box)
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxRenderer extends InvalidatingElementRenderer
{
	/**
	 * Holds the dimensions of this box
	 * renderer, use by its children for layout
	 */
	private var _containerBlockData:ContainingBlockVO;
	
	/**
	 * Holds the current dimensions of the window
	 * 
	 * TODO 2 : should be held by the window object, just a
	 * DimensionVO ?
	 */
	private var _windowData:ContainingBlockVO;
	
	/**
	 * Holds the dimensions and position of the background
	 * of this box renderer, in viewport bounds
	 */
	private var _backgroundBounds:RectangleVO;
	
	/**
	 * class constructor
	 */
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
		_containerBlockData = new ContainingBlockVO(0.0, false, 0.0, false);
		_windowData = new ContainingBlockVO(0.0, false, 0.0, false);
		_backgroundBounds = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as box might generate one
	 * inline box if they are inline level
	 */
	override public function updateInlineBoxes():Void
	{
		inlineBoxes = new Array<InlineBox>();
		
		//non-positioned box create embedded box, it can represent
		//an embedded element llike a picture or an inline-block block
		//box
		var inlineBox:InlineBox = new InlineBox(this);
		inlineBoxes.push(inlineBox);
		
			
		super.updateInlineBoxes();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to render elements specific to a box (background, border...)
	 */
	override public function render(parentGraphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{	
		//only render self if visible
		//however children can still be rendered
		//if they are explicitely visible
		if (isVisible() == true)
		{
			renderSelf(parentGraphicContext, clipRect, scrollOffset);
		}
		
		renderChildren(parentGraphicContext, clipRect, scrollOffset);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function renderSelf(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		renderBackground(graphicContext, clipRect, scrollOffset);
	}
	
	/**
	 * Render the background of the box using the provided graphic context
	 */
	private function renderBackground(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var backgroundBounds:RectangleVO = getBackgroundBounds(scrollOffset);
		
		//TODO 3 : should only pass dimensions instead of bounds
		BackgroundManager.render(graphicContext, backgroundBounds, coreStyle, this, clipRect);
	}
	
	/**
	 * Render the children of the box
	 */
	private function renderChildren(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is in charge of laying out an ElementRenderer which consist 
	 * in computing its styles (box model, font, text...) into usable values and determining its 
	 * bounds in the space of the containing block which started its formatting context.
	 */
	override public function layout(forceLayout:Bool):Void
	{	
		if (_needsLayout == true || forceLayout == true)
		{
			layoutSelf();
			_needsLayout = false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the ElementRenderer needs to lays itself out,
	 * meaning its must compute its dimensions
	 */
	private function layoutSelf():Void
	{
		//get the dimensions of the containing block of this 
		//element which are necesseray to compute the styles of this ElementRenderer
		//into usable value. For instance, a with defined as a percentage will compute
		//to a percentage of the containing block width
		var containingBlockData:ContainingBlockVO = containingBlock.getContainerBlockData();
		
		//special case for element with percent height, from the CSS 2.1 spec : 
		// If the height of the containing block is not specified explicitly (i.e., it depends on content height),
		//and this element is not absolutely positioned, the value computes to 'auto'
		//
		//This doesn't apply if the containing block is the elementRenderer of the HTML Body tag, in which
		//case, if the body height is auto, it will use the height of the viewport
		//
		//TODO 3 : is it the right place for this check ? Might be either in BoxComputer or in CoreStyle, there
		//are caveats for both. In CoreStyle, hard to find containing block, in BoxComputer hard to call method
		//as if height was auto without modifying computedValues
		//
		//TODO 4 : the way to test for the body element is a bit hackish
		if (containingBlockData.isHeightAuto == true && containingBlock.domNode.tagName != HTMLConstants.HTML_BODY_TAG_NAME)
		{
			if (isPositioned() == false || isRelativePositioned() == true)
			{
				switch(coreStyle.height)
				{
					case PERCENTAGE(value):
						coreStyle.computedValues.height = CSSConstants.AUTO;
						
					default:	
				}
			}
		}
		
		//another special case for absolutely positioned element, from the CSS 2.1 spec : 
		//
		//For absolutely positioned elements whose containing block is based on a block 
		//container element, the percentage is calculated with respect to the width of the
		//padding box of that element. This is a change from CSS1, where the percentage width
		//was always calculated with respect to the content box of the parent element. 
		//
		//the same rule exist for the height
		//so if the element is absolutely positioned, the height and width of its
		//containing block is updated to include its paddings
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			//only apply if the containing block is a block box (not inline, might happen with
			//relative positioning)
			if (containingBlock.isBlockContainer() == true)
			{
				var containingBlockUsedValues:UsedValuesVO = containingBlock.coreStyle.usedValues;
				containingBlockData.height += containingBlockUsedValues.paddingTop + containingBlockUsedValues.paddingBottom;
				containingBlockData.width += containingBlockUsedValues.paddingLeft + containingBlockUsedValues.paddingRight;
			}
		}
		
		//compute the font style (font-size, line-height...)
		FontAndTextStylesComputer.compute(coreStyle, containingBlockData);
		
		//compute the box styles (width, height, margins, paddings...)
		computeBoxModelStyles(containingBlockData);
		
		//now that the used values for layout are computed, they can be used
		//for the width and height of the bounds of this box. Width and height
		//might be computed again, for instance if it depends on children height
		var usedValues:UsedValuesVO = coreStyle.usedValues;
		bounds.width = usedValues.width + usedValues.paddingLeft + usedValues.paddingRight;
		bounds.height = usedValues.height + usedValues.paddingTop + usedValues.paddingBottom;
	}
	
		
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the ElementRenderer, based on
	 * its positioning scheme
	 */ 
	private function computeBoxModelStyles(containingBlockDimensions:ContainingBlockVO):Void
	{
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		var boxComputer:BoxStylesComputer = htmlDocument.layoutManager.getBoxStylesComputer(this);
		
		//do compute the box model styles
		boxComputer.measure(coreStyle, containingBlockDimensions);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC MARGIN COLLAPSING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the result of collapsing the top margin od this box
	 * will all adjoining margins. Returns the used top margin
	 * if it doesn't collapse with any margin
	 * 
	 * If the top margin do collapse, a non 0 value is only returned
	 * for the first adjoining margin so that when laying out, only
	 * the first box with collapsed margin is offset on the y axis.
	 * 
	 * For instance if a block box top margin collapse with the 
	 * top margin of its first child, when this method is called
	 * on the parent, it will return the width of the collapsed margin
	 * and it will return 0 when called on the first child
	 */
	override public function getCollapsedTopMargin():Float
	{
		//if the top margin is collapsed with the parent's top
		//margin, return 0 as the collapsed margin will be applied
		//to the parent instead
		if (collapseTopMarginWithParentTopMargin() == true)
		{
			return 0;
		}
		//same if collapsing with the previous sibling bottom margin
		else if (collapseTopMarginWithPreviousSiblingBottomMargin() == true)
		{
			return 0;
		}
		
		//if top margin collapse with top margin of first child, retrieve
		//the width of all the adjoining margin which collapse, and retrieve
		//the collapsed value from them
		if (collapseTopMarginWithFirstChildTopMargin() == true)
		{
			var adjoiningMargins:Array<Float> = new Array<Float>();
			adjoiningMargins.push(coreStyle.usedValues.marginTop);
			firstChild.getAdjoiningTopMargins(adjoiningMargins);
			return getCollapsedMargin(adjoiningMargins);
		}
		//same if the top margin collapse with own bottom margin
		else if (collapseTopMarginWithBottomMargin() == true)
		{
			var adjoiningMargins:Array<Float> = new Array<Float>();
			adjoiningMargins.push(coreStyle.usedValues.marginBottom);
			//var firstChildCollapsedTopMargin:Float = firstChild.getAdjoiningTopMargins(adjoiningMargins);
			return getCollapsedMargin(adjoiningMargins);
		}
		
		//if the top margin doesn't collapse, return its used value
		return coreStyle.usedValues.marginTop;
	}
	
	/**
	 * When called on an element, store all its adjoining top margin
	 * which collapse with its top margin so that it can determine
	 * its collapsed margin width
	 */
	override public function getAdjoiningTopMargins(adjoiningMargins:Array<Float>):Void
	{
		//if the current element top margin collapses, store its used width
		if (collapseTopMarginWithParentTopMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginTop);
		}
		else if (collapseTopMarginWithPreviousSiblingBottomMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginTop);
		}
		
		//if the current element also collapse with its first child top margin,
		//the first child top margin must also be used when computing collapsed margin
		//width
		if (collapseTopMarginWithFirstChildTopMargin() == true)
		{
			firstChild.getAdjoiningTopMargins(adjoiningMargins);
		}
		//same if current element collapse with own bottom margin
		else if (collapseTopMarginWithBottomMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginBottom);
			//next sibling might collapse with bottom margin
			if (nextSibling != null)
			{
				nextSibling.getAdjoiningTopMargins(adjoiningMargins);
			}
		}
	}
	
	/**
	 * same as getCollapsedTopMargin for bottom margins
	 */
	override public function getCollapsedBottomMargin():Float
	{
		if (collapseBottomMarginWithParentBottomMargin() == true)
		{
			return 0;
		}
		else if (collapseBottomMarginWithNextSiblingTopMargin() == true)
		{
			return 0;
		}
		
		if (collapseBottomMarginWithLastChildBottomMargin() == true)
		{
			var adjoiningMargins:Array<Float> = new Array<Float>();
			adjoiningMargins.push(coreStyle.usedValues.marginBottom);
			lastChild.getAdjoiningBottomMargins(adjoiningMargins);
			return getCollapsedMargin(adjoiningMargins);
		}
		else if (collapseTopMarginWithBottomMargin() == true)
		{
			var adjoiningMargins:Array<Float> = new Array<Float>();
			adjoiningMargins.push(coreStyle.usedValues.marginTop);
			//var firstChildCollapsedTopMargin:Float = firstChild.getAdjoiningTopMargins(adjoiningMargins);
			return getCollapsedMargin(adjoiningMargins);
		}
		
		return coreStyle.usedValues.marginBottom;
	}
	
	/**
	 * same as getAdjoiningTopMargins for bottom margins
	 */
	override public function getAdjoiningBottomMargins(adjoiningMargins:Array<Float>):Void
	{
		if (collapseBottomMarginWithParentBottomMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginBottom);
		}
		else if (collapseBottomMarginWithNextSiblingTopMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginBottom);
		}
		
		if (collapseBottomMarginWithLastChildBottomMargin() == true)
		{
			lastChild.getAdjoiningBottomMargins(adjoiningMargins);
		}
		else if (collapseTopMarginWithBottomMargin() == true)
		{
			adjoiningMargins.push(coreStyle.usedValues.marginTop);
			if (previousSibling != null)
			{
				previousSibling.getAdjoiningBottomMargins(adjoiningMargins);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE MARGIN COLLAPSING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * for a given list of adjoining margins width,
	 * determine the width to use as collapsed width and
	 * return it
	 */
	private function getCollapsedMargin(adjoiningMargins:Array<Float>):Float
	{
		//positive and negative margin are stored separately
		var maximumPositiveMargin:Float = 0.0;
		var maximumNegativeMargin:Float = 0.0;
		
		//loop in all adjoining margins width to find the
		//most positive and the most negative ones
		var length:Int = adjoiningMargins.length;
		for (i in 0...length)
		{
			var adjoiningMargin:Float = adjoiningMargins[i];
			if (adjoiningMargin > maximumPositiveMargin)
			{
				maximumPositiveMargin = adjoiningMargin;
			}
			else if (adjoiningMargin < maximumNegativeMargin)
			{
				maximumNegativeMargin = adjoiningMargin;
			}
		}
		
		//the collapsed value is the difference between the most positive
		//margin width and the absolute value of the most negative one
		return maximumPositiveMargin - Math.abs(maximumNegativeMargin);
	}
	
	/**
	 * Return wether the top margin of this box should
	 * collapse with the top margin of its parent
	 * 
	 * TODO : if this box has clearance, it should not collapse
	 */
	private function collapseTopMarginWithParentTopMargin():Bool
	{
		//if the box as no parent, it is the initial
		//container block and don't collapse
		if (parentNode == null)
		{
			return false;
		}
		
		//TODO : firstChild might actually be positioned or floated,
		//it should be first noram flow block level child
		//if this box is not the first child of its parent it won't collapse
		//with its top margin
		if (parentNode.firstChild != this)
		{
			return false;
		}
		
		//the root of block formatting (a float, an absolutely positioned element...)
		//don't collapse its margin with its children margin
		if (parentNode.establishesNewBlockFormattingContext() == true)
		{
			return false;
		}
		
		//if a padding separate the parent top margin and this box 
		//top margin, they don't collapse
		if (parentNode.coreStyle.usedValues.paddingTop != 0)
		{
			return false;
		}
		
		//in all other cases, margins collapse
		return true;
	}
	
	/**
	 * same as collapseTopMarginWithParentTopMargin for bottom
	 * margin
	 */
	private function collapseBottomMarginWithParentBottomMargin():Bool
	{
		if (parentNode == null)
		{
			return false;
		}
		
		//TODO : lastChild might actually be positioned or floated,
		//it should be last noram flow block level child
		if (parentNode.lastChild != this)
		{
			return false;
		}
		
		if (parentNode.establishesNewBlockFormattingContext() == true)
		{
			return false;
		}
		
		if (parentNode.coreStyle.usedValues.paddingBottom != 0)
		{
			return false;
		}

		return true;
	}
	
	/**
	 * Return wether the top margin should
	 * collapse with the previous sibling's
	 * bottom margin
	 */
	private function collapseTopMarginWithPreviousSiblingBottomMargin():Bool
	{
		//TODO : should be first normal flow previous sibling
		//if no previous sibling, then this box is first
		//child of its parent
		if (previousSibling == null)
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * same as collapseTopMarginWithPreviousSiblingBottomMargin
	 * for bottom margin
	 */
	private function collapseBottomMarginWithNextSiblingTopMargin():Bool
	{
		//TODO : should be first normal flow previous sibling
		if (previousSibling == null)
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * Wether the top margin of this collapse with the top margin
	 * of its first child. False by default, as only applies to block
	 * box
	 */
	private function collapseTopMarginWithFirstChildTopMargin():Bool
	{ 
		return false;
	}
	
	/**
	 * same as collapseTopMarginWithFirstChildTopMargin
	 * for bottom margin
	 */
	private function collapseBottomMarginWithLastChildBottomMargin():Bool
	{ 
		return false;
	}
	
	/**
	 * Return wether the top and bottom margin of this 
	 * box should collapse
	 */
	private function collapseTopMarginWithBottomMargin():Bool
	{
		if (firstChild != null)
		{
			//TODO : check that all combined children have a 0 height
			//or all of their margin collapse
		}
		
		//if the box has vertical padding, then the margins are not adjoining
		if (coreStyle.usedValues.paddingTop != 0 || coreStyle.usedValues.paddingBottom != 0)
		{
			return false;
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine if the ElementRenderer is a floated
	 * ElementRenderer. A floated ElementRenderer is first
	 * placed in the flow then moved to the
	 * left-most or right-most of its containing block.
	 * Any subsequent line box flows
	 * around its margin box until a new line 
	 * starts below the float or if it is cleared
	 * by another ElementRenderer.
	 * 
	 * An ElementRenderer is floated if it declares either
	 * a left or right float
	 */
	override public function isFloat():Bool
	{
		return coreStyle.isNone(coreStyle.cssFloat) == false;
	}
	
	/**
	 * Determine wether the ElementRenderer can clear, left floats,
	 * right floats or both which are declared before it in the
	 * block formatting context into which it participates.
	 * 
	 * If it does, it will positioned below any previous left, right
	 * or both floats. When it does, it is said to have clearance
	 */
	override public function canHaveClearance():Bool
	{	
		return coreStyle.isNone(coreStyle.clear) == false;
	}
	
	/**
	 * A positioned element is one that 
	 * is positioned outside of the normal
	 * flow.
	 * 
	 * The 'relative', 'absolute' and'fixed'
	 * values of the 'position' style makes
	 * an ElementRenderer 'positioned'. 
	 * 
	 * The 'absolute' and 'fixed' value make
	 * an ElementRenderer an 'absolutely positioned'
	 * ElementRenderer. This kind of ElementRenderer
	 * doesn't affect the normal flow (it is
	 * treated as if it doesn't exist). It
	 * uses as origin its first ancestor
	 * which is also positioned
	 * 
	 * See below for the 'relative' value
	 */
	override public function isPositioned():Bool
	{
		return coreStyle.getKeyword(coreStyle.position) != STATIC;
	}
	
	/**
	 * Determine wether an ElementRenderer has
	 * the 'position' value 'relative'.
	 * 
	 * A 'relative' ElementRenderer is first placed
	 * normally in the flow then an offset is 
	 * applied to it with the top, left, right
	 * and bottom computed styles.
	 * 
	 * It is used as origin for any 'absolute'
	 * or 'fixed' positioned children and 
	 * grand-children until another positioned
	 * ElementRenderer is found
	 */
	override public function isRelativePositioned():Bool
	{
		return coreStyle.getKeyword(coreStyle.position) == RELATIVE;
	}
	
	/**
	 * An inline-level ElementRenderer is one that is
	 * laid out on a line. Its line boxes will be placed
	 * either next to the preceding ElementRenderer's line boxes
	 * or on new lines if the current line
	 * is too short to host them.
	 * 
	 * Wheter an element is inline-level is determined
	 * by its display style
	 */
	override public function isInlineLevel():Bool
	{
		var ret:Bool = false;
		
		switch (coreStyle.getKeyword(coreStyle.display)) 
		{
			case INLINE, INLINE_BLOCK:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Overriden as BoxRenderer might create a new layer, for
	 * instance if they are positioned.
	 */
	override public function createOwnLayer():Bool
	{
		//positioned box also always create a new layer
		if (isPositioned() == true)
		{
			return true;
		}
		//transparent ElementRenderer always have their own
		//layer for rendering purpose so that they can be
		//rendered offscreen then composited
		else if (isTransparent() == true)
		{
			return true;
		}
		//transformed box always create new layer
		else if (isTransformed() == true)
		{
			return true;
		}
		
		//in all other cases, no new layer is created
		return false;
	}
	
	/**
	 * Determine wheter the ElementRenderer has transformations (translation,
	 * scaling, rotation or skewing) that should be applied to it when rendered.
	 * 
	 * If it does, it needs to have its own LayerRenderer, as each LayerRenderer
	 * must represents a single space coordinate
	 */
	override public function isTransformed():Bool
	{
		//it is transformed if at least one transform
		//function is applied to it
		if (coreStyle.isNone(coreStyle.transform) == false)
		{
			return true;
		}
		//relative positioning is considered as a transformation
		else if (isRelativePositioned() == true)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Determine whether this ElementRenderer should render
	 * itself. It still influence layout event if not
	 * visible.
	 * 
	 * If one of its children is visible, it is rendered
	 */
	override public function isVisible():Bool
	{
		return coreStyle.getKeyword(coreStyle.visibility) != HIDDEN;
	}
	
	/**
	 * Determine wheter the ElementRenderer is transparent
	 * when rendered, as defined by its opacity style
	 */
	override public function isTransparent():Bool
	{
		switch(coreStyle.opacity)
		{
			case CSSPropertyValue.NUMBER(value):
				return value != 1.0;
				
			case CSSPropertyValue.ABSOLUTE_LENGTH(value):
				return value != 1.0;
				
			default:
				return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the ElementRenderer introduces
	 * 'clearance', which as the effect of placing
	 * the ElementRenderer below any preceding floated
	 * ElementRenderer. An ElementRenderer introduces clearance
	 * if he clears either left floats, right floats
	 * or both
	 */
	private function isClear():Bool
	{
		switch(coreStyle.getKeyword(coreStyle.clear))
		{
			case LEFT, RIGHT, BOTH:
			return true;
						
			default:	
		}
		
		return false;
	}
	
	/**
	 * Helper method returning the bounds to 
	 * be used to draw the background. Meant
	 * to be overriden as for instance the HTMLBodyElement's
	 * ElementRenderer uses the viewport bounds for its background
	 * instead of its own
	 */
	private function getBackgroundBounds(scrollOffset:PointVO):RectangleVO
	{
		_backgroundBounds.x = globalBounds.x - scrollOffset.x;
		_backgroundBounds.y = globalBounds.y - scrollOffset.y;
		_backgroundBounds.width = globalBounds.width;
		_backgroundBounds.height = globalBounds.height;
		
		return _backgroundBounds;
	}
	
	/**
	 * Return the dimensions data
	 * of the ElementRenderer
	 */
	public function getContainerBlockData():ContainingBlockVO
	{
		_containerBlockData.width = coreStyle.usedValues.width;
		_containerBlockData.isWidthAuto = coreStyle.isAuto(coreStyle.width);
		_containerBlockData.height = coreStyle.usedValues.height;
		_containerBlockData.isHeightAuto = coreStyle.isAuto(coreStyle.height);
		return _containerBlockData;
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingBlockVO
	{	
		var window:Window = Lib.window;
		var width:Float = window.innerWidth;
		var height:Float = window.innerHeight;
		
		_windowData.width = window.innerWidth;
		_windowData.height = window.innerHeight;
		_windowData.isHeightAuto = false;
		_windowData.isWidthAuto = false;
		
		return _windowData;
	}
}