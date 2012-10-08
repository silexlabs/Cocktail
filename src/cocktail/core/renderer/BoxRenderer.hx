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
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.formatter.InlineFormattingContext;
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
	 * class constructor
	 */
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
		_containerBlockData = new ContainingBlockVO(0.0, false, 0.0, false);
		_windowData = new ContainingBlockVO(0.0, false, 0.0, false);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to render elements specific to a box (background, border...)
	 * TODO 4 : apply visibility
	 * 
	 * TODO 2 : code clean up
	 */
	override public function render(parentGraphicContext:GraphicsContext):Void
	{	
		//only render self if visible
		//however children can still be rendered
		//if they are explicitely visible
		if (isVisible() == true)
		{
			renderSelf(parentGraphicContext);
		}
		
		renderChildren(parentGraphicContext);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function renderSelf(graphicContext:GraphicsContext):Void
	{
		renderBackground(graphicContext);
	}
	
	/**
	 * Render the background of the box using the provided graphic context
	 */
	private function renderBackground(graphicContext:GraphicsContext):Void
	{
		var backgroundBounds:RectangleVO = getBackgroundBounds();
		
		//TODO 3 : should only pass dimensions instead of bounds
		BackgroundManager.render(graphicContext, backgroundBounds, coreStyle, this);
	}
	
	/**
	 * Render the children of the box
	 */
	private function renderChildren(graphicContext:GraphicsContext):Void
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
	 * meanng its must compute its dimensions
	 */
	private function layoutSelf():Void
	{
		//get the dimensions and font metrics of the containing block of this 
		//element which are necesseray to compute the styles of this ElementRenderer
		//into usable value. For instance, a with defined as a percentage will compute
		//to a percentage of the containing block width
		var containingBlockData:ContainingBlockVO = _containingBlock.getContainerBlockData();
		
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
		if (containingBlockData.isHeightAuto == true && _containingBlock.domNode.tagName != HTMLConstants.HTML_BODY_TAG_NAME)
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
			if (_containingBlock.isBlockContainer() == true)
			{
				var containingBlockUsedValues:UsedValuesVO = _containingBlock.coreStyle.usedValues;
				containingBlockData.height += containingBlockUsedValues.paddingTop + containingBlockUsedValues.paddingBottom;
				containingBlockData.width += containingBlockUsedValues.paddingLeft + containingBlockUsedValues.paddingRight;
			}
		}
		
		//compute the font style (font-size, line-height...)
		FontAndTextStylesComputer.compute(coreStyle, containingBlockData);
		
		//compute the box styles (width, height, margins, paddings...)
		computeBoxModelStyles(containingBlockData);
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
		//it is transformaed if at least one transform
		//function is applied to it
		if (coreStyle.isNone(coreStyle.transform) == false)
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
	private function getBackgroundBounds():RectangleVO
	{
		globalBounds.x -= scrollOffset.x;
		globalBounds.y -= scrollOffset.y;
		return globalBounds;
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