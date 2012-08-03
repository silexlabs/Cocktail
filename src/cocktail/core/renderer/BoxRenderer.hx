 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.window.Window;
import cocktail.Lib;
import cocktail.port.DrawingManager;
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.background.BackgroundManager;
import cocktail.core.style.computer.BackgroundStylesComputer;
import cocktail.core.style.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.style.computer.DisplayStylesComputer;
import cocktail.core.style.computer.FontAndTextStylesComputer;
import cocktail.core.style.computer.VisualEffectStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.formatter.InlineFormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import cocktail.core.unit.UnitManager;
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
	 * class constructor
	 */
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
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
		renderSelf(parentGraphicContext);
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

		//compute the background styles which can be computed at this time,
		//such as the background color, most of the background styles will be computed
		//during the rendering
		//
		//TODO 4 : update doc for this
		coreStyle.computeBackgroundStyles();
		
		var backgroundBounds:RectangleData = getBackgroundBounds();
		
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
		//TODO 1 : messy to compute here, but if immediately computed
		//when set, won't work for transitions
		coreStyle.computedStyle.opacity = coreStyle.opacity;
		
		//TODO 1 : same as above, where to compute this ?
		coreStyle.computeTransitionStyles();
		
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
		var containingBlockData:ContainingBlockData = _containingBlock.getContainerBlockData();
		var containingBlockFontMetricsData:FontMetricsData = _containingBlock.coreStyle.fontMetrics;

		//compute the font style (font-size, line-height...)
		coreStyle.computeTextAndFontStyles(containingBlockData, containingBlockFontMetricsData);

		//compute the box styles (width, height, margins, paddings...)
		computeBoxModelStyles(containingBlockData);
	}
	
		
	/**
	 * Compute the box model styles (width, height, paddings, margins...) of the ElementRenderer, based on
	 * its positioning scheme
	 */ 
	private function computeBoxModelStyles(containingBlockDimensions:ContainingBlockData):Void
	{
		var boxComputer:BoxStylesComputer = getBoxStylesComputer();
		
		//do compute the box model styles
		boxComputer.measure(coreStyle, containingBlockDimensions);
	}
	
	/**
	 * Return the right class used to compute the box model
	 * styles
	 */
	private function getBoxStylesComputer():BoxStylesComputer
	{
		//abstract
		return null;
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
		return coreStyle.computedStyle.cssFloat != CSSFloat.none;
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
		return this.coreStyle.computedStyle.position != Position.cssStatic;
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
		return this.coreStyle.computedStyle.position == relative;
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
		
		switch (this.coreStyle.computedStyle.display) 
		{
			case cssInline, inlineBlock:
				ret = true;
			
			default:
				ret = false;
		}
		
		return ret;
	}
	
	/**
	 * Overriden as BoxRenderer might create new stacking context, for
	 * instance if they are positioned.
	 */
	override public function establishesNewStackingContext():Bool
	{
		//transformed box always create new stacking context
		if (isTransformed() == true)
		{
			return true;
		}
		//positioned box also always create a new stacking context
		else if (isPositioned() == true)
		{
			return true;
		}
		//transparent ElementRenderer always have their own
		//LayerRenderer for rendering purpose
		else if (isTransparent() == true)
		{
			return true;
		}
		
		//in all other cases, no new stacking context is created
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
		if (coreStyle.transform != Transform.none)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Determine wheter the ElementRenderer is transparent
	 * when rendered, as defined by its opacity style
	 */
	override public function isTransparent():Bool
	{
		if (coreStyle.opacity != 1.0)
		{
			return true;
		}
			
		return false;
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
		return coreStyle.computedStyle.clear != Clear.none;
	}
	
	/**
	 * Helper method returning the bounds to 
	 * be used to draw the background. Meant
	 * to be overriden as for instance the HTMLBodyElement's
	 * ElementRenderer uses the viewport bounds for its background
	 * instead of its own
	 */
	private function getBackgroundBounds():RectangleData
	{
		var globalBounds:RectangleData = get_globalBounds();
		globalBounds.x -= scrollOffset.x;
		globalBounds.y -= scrollOffset.y;
		return globalBounds;
	}
	
	/**
	 * Return the dimensions data
	 * of the ElementRenderer
	 */
	public function getContainerBlockData():ContainingBlockData
	{
		return {
			width:this.coreStyle.computedStyle.width,
			isWidthAuto:this.coreStyle.width == Dimension.cssAuto,
			height:this.coreStyle.computedStyle.height,
			isHeightAuto:this.coreStyle.height == Dimension.cssAuto
		};
	}
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	private function getWindowData():ContainingBlockData
	{	
		var window:Window = Lib.window;
		var width:Float = window.innerWidth;
		var height:Float = window.innerHeight;
		
		var windowData:ContainingBlockData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:width,
			height:height
		}
		
		return windowData;
	}
}