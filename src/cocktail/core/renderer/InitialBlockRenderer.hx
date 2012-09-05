/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.layer.InitialLayerRenderer;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CoreStyle;
import haxe.Log;
import cocktail.core.renderer.RendererData;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.font.FontData;

/**
 * This is the root ElementRenderer of the rendering
 * tree, generated by the HTMLHTMLElement, which is the root
 * of the DOM tree
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialBlockRenderer extends BlockBoxRenderer
{
	/**
	 * class constructor.
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		
		//call the attachement method itself as it is 
		//supposed to be called by parent ElementRenderer
		//otherwise
		attach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as initial block renderer always create
	 * a new intitial layer renderer
	 */
	override private function attachLayer():Void
	{
		layerRenderer = new InitialLayerRenderer(this);
	}
	
	/**
	 * Overriden as initial block renderer always delete
	 * its own layer
	 */
	override private function detachLayer():Void
	{
		layerRenderer = null;
	}
	
	/**
	 * never register with containing block as it has
	 * none
	 */
	override private function registerWithContaininingBlock():Void
	{
		
	}
	
	/**
	 * same as above for detach
	 */
	override private function unregisterWithContainingBlock():Void
	{
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * As the initial block renderer has no containing block,
	 * invalidate the document instead
	 */
	override private function invalidateContainingBlock(invalidationReason:InvalidationReason):Void
	{
		invalidateDocumentLayoutAndRendering();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The initial block renderer is always considered positioned,
	 * as it always lays out the positioned children for whom it is
	 * the first positioned ancestor
	 */
	override public function isPositioned():Bool
	{
		return true;
	}
	
	/**
	 * The initial block container always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
	/**
	 * Overriden as initial block container alwyas establishes
	 * creates the root LayerRenderer of the
	 * LayerRenderer tree
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as the scontaining dimensionsn for the scrollbars
	 * appearing for the initial containing block are the viewport's
	 */
	override private function getScrollbarContainerBlock():ContainingBlockVO
	{
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		return new ContainingBlockVO(width, false, height, false);
	}
	
	/**
	 * When dispatched on the HTMLHTMLElement,
	 * the scroll event must bubble to be dispatched
	 * on the Document and Window objects
	 */
	override private function mustBubbleScrollEvent():Bool
	{
		return true;
	}
	
	/**
	 * A computed value of visible for the overflow on the initial
	 * block renderer is the same as auto, as it is likely that
	 * scrollbar must be displayed to scroll through the document
	 */
	override private function treatVisibleOverflowAsAuto():Bool
	{
		return true;
	}
	
	/**
	 * Retrieve the dimension of the Window
	 */
	override private function getWindowData():ContainingBlockVO
	{	
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		//scrollbars dimension are removed from the Window dimension
		//if displayed to return the actual available space
		
		if (_verticalScrollBar != null)
		{
			width -= _verticalScrollBar.coreStyle.usedValues.width;
		}
		
		if (_horizontalScrollBar != null)
		{
			height -= _horizontalScrollBar.coreStyle.usedValues.height;
		}
		
		return new ContainingBlockVO(width, false, height, false);
	}
	
	/**
	 * The dimensions of the initial
	 * block renderer are always the same as the Window's
	 */
	override public function getContainerBlockData():ContainingBlockVO
	{
		return getWindowData();
	}
	
	/**
	 * Returns itself as containing block, which is used
	 * during layout
	 */
	override private function getContainingBlock():FlowBoxRenderer
	{	
		return this;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as the bounds of the initial block container
	 * are always those of the Window (minus scrollbars dimensions
	 * if displayed)
	 */
	override private function get_bounds():RectangleVO
	{
		var containerBlockData:ContainingBlockVO = getContainerBlockData();
		
		var width:Float = containerBlockData.width;
		var height:Float = containerBlockData.height;
		
		return new RectangleVO(0.0, 0.0, width, height);
	}
	
	/**
	 * For the initial container, the bounds and
	 * global bounds are the same
	 */
	override private function get_globalBounds():RectangleVO
	{
		return bounds;
	}
	
}