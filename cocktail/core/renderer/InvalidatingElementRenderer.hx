/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.parser.ParserData;
import cocktail.css.CSSConstants;


/**
 * This class implements the invalidation behaviour
 * of the rendering, aiming at optimising the layout
 * and rendering of the rendering tree
 * 
 * @author Yannick DOMINGUEZ
 */
class InvalidatingElementRenderer extends ElementRenderer 
{
	/**
	 * Wether this ElementRenderer needs to layout itself
	 */
	private var _needsLayout:Bool;
	
	/**
	 * Wheter the inflow children (not positioned or floated)
	 * need to be re-layout
	 */
	private var _childrenNeedLayout:Bool;
	
	/**
	 * Wether the positioned children needs to be re-layout
	 */
	private var _positionedChildrenNeedLayout:Bool;
	
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
	
		_needsLayout = true;
		_childrenNeedLayout = true;
		_positionedChildrenNeedLayout = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * when added to the rendering tree, 
	 * this element needs a layout
	 */
	override public function addedToRenderingTree():Void
	{
		super.addedToRenderingTree();
		invalidateLayout();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * TODO 1 : invalidation must be revised
	 */
	override public function invalidate():Void
	{
		_childrenNeedLayout = true;
		_positionedChildrenNeedLayout = true;
		invalidateLayoutAndRendering();
	}
	
	/**
	 * schedule a rendering
	 */
	override public function invalidateRendering():Void
	{
		//invalidate the layer associated with
		//this ElementRenderer
		if (layerRenderer != null)
		{
			layerRenderer.invalidateRendering();
		}
	}
	
	/**
	 * When a style changed, determine wether a layout
	 * and rendering is needed for this element and for
	 * its containing block
	 */
	override public function invalidateStyle(styleIndex:Int):Void
	{
		switch (styleIndex)
		{
			//if one of the position style (left, right,top, bottom) was changed,
			//a layout and rendering is only needed for positioned child
			case CSSConstants.LEFT, CSSConstants.RIGHT,
			CSSConstants.TOP, CSSConstants.BOTTOM:
				
				if (isAbsolutelyPositioned() == true)
				{
					invalidateLayoutAndRendering();
					invalidateContainingBlock(styleIndex);
				}
				//if the child is relatively positioned, it only needs a rendering, as its
				//layout is not affected by those styles
				else
				{
					invalidateRendering();
				}
				
			//those style invalidate the child TextRenderer of this ElementRenderer	
			case CSSConstants.COLOR, CSSConstants.FONT_FAMILY, CSSConstants.FONT_SIZE,
			CSSConstants.FONT_VARIANT, CSSConstants.FONT_STYLE, CSSConstants.FONT_WEIGHT,
			CSSConstants.LETTER_SPACING, CSSConstants.TEXT_TRANSFORM, CSSConstants.WHITE_SPACE:
				invalidateText();
				invalidateLayoutAndRendering();
				invalidateContainingBlock(styleIndex);
			
			//when opacity or visibility changes, only rendering
			//needs to be updated
			case CSSConstants.OPACITY, CSSConstants.VISIBILITY:
				invalidateRendering();
				
			//a background style change only requires a re-rendering, as backgrounds never
			//affects layout
			case CSSConstants.BACKGROUND_COLOR, CSSConstants.BACKGROUND_CLIP,
			CSSConstants.BACKGROUND_IMAGE, CSSConstants.BACKGROUND_POSITION,
			CSSConstants.BACKGROUND_ORIGIN, CSSConstants.BACKGROUND_REPEAT,
			CSSConstants.BACKGROUND_SIZE:
				invalidateRendering();
				
			//for any other style change,invalidate layout, rendering and 
			//the containing block
			default:
				invalidateLayoutAndRendering();
				invalidateContainingBlock(styleIndex);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when an in flow child was invalidated
	 */
	public function childInvalidated():Void
	{
		invalidate();
	}
	
	/**
	 * Called when a positioned child was invalidated
	 */
	public function positionedChildInvalidated():Void
	{
		invalidate();
	}
	
	/**
	 * Invalidate the containing block of the ElementRenderer,
	 * which might be the parent, the first positioned ancestor
	 * or the initial block renderer
	 */
	private function invalidateContainingBlock(styleIndex:Int):Void
	{
		//TODO 1 : not supposed to happen
		if (containingBlock == null)
		{
			return;
		}
		
		//call different invalidation method for positioned and
		//in flow block container
		//
		//TODO 2 : might be redundant with the invalidationreason change ?
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			containingBlock.invalidatedChildStyle(styleIndex);
		}
		else
		{
			containingBlock.invalidatedPositionedChildStyle(styleIndex);
		}
	}
	
	/**
	 * Called when a style change if this ElementRenderer
	 * caused the invalidation
	 */
	private function invalidatedStyle(styleIndex:Int):Void
	{
		switch (styleIndex)
		{
			//if one of the position style (left, right,top, bottom) was changed,
			//a layout and rendering is only needed for positioned child
			case CSSConstants.LEFT, CSSConstants.RIGHT,
			CSSConstants.TOP, CSSConstants.BOTTOM:
				
				if (isPositioned() == true && isRelativePositioned() == false)
				{
					invalidateLayoutAndRendering();
					invalidateContainingBlock(styleIndex);
				}
				//if the child is relatively positioned, it only needs a rendering, as its
				//layout is not affected by those styles
				else
				{
					invalidateRendering();
				}
				
			//those style invalidate the child TextRenderer of this ElementRenderer	
			case CSSConstants.COLOR, CSSConstants.FONT_FAMILY, CSSConstants.FONT_SIZE,
			CSSConstants.FONT_VARIANT, CSSConstants.FONT_STYLE, CSSConstants.FONT_WEIGHT,
			CSSConstants.LETTER_SPACING, CSSConstants.TEXT_TRANSFORM, CSSConstants.WHITE_SPACE:
				invalidateText();
				invalidateLayoutAndRendering();
				invalidateContainingBlock(styleIndex);
			
			//when opacity or visibility changes, only rendering
			//needs to be updated
			case CSSConstants.OPACITY, CSSConstants.VISIBILITY:
				invalidateRendering();
				
			//a background style change only requires a re-rendering, as backgrounds never
			//affects layout
			case CSSConstants.BACKGROUND_COLOR, CSSConstants.BACKGROUND_CLIP,
			CSSConstants.BACKGROUND_IMAGE, CSSConstants.BACKGROUND_POSITION,
			CSSConstants.BACKGROUND_ORIGIN, CSSConstants.BACKGROUND_REPEAT,
			CSSConstants.BACKGROUND_SIZE:
				invalidateRendering();
				
			//for any other style change,invalidate layout, rendering and 
			//the containing block
			default:
				invalidateLayout();
				invalidateContainingBlock(styleIndex);
		}
	}
	
	/**
	 * Called when an inflow child style was changed
	 */
	public function invalidatedChildStyle(styleIndex:Int):Void
	{
		switch (styleIndex)
		{
			//TODO 2 : not supposed to be called anyway
			case CSSConstants.BACKGROUND_COLOR, CSSConstants.BACKGROUND_CLIP,
			CSSConstants.BACKGROUND_IMAGE, CSSConstants.BACKGROUND_POSITION,
			CSSConstants.BACKGROUND_ORIGIN, CSSConstants.BACKGROUND_REPEAT,
			CSSConstants.BACKGROUND_SIZE:
			
			//by default, set a relayout of this containing block and
			//a rendering of all its children
			default:
				_childrenNeedLayout = true;
		}
	}
	
	/**
	 * Called when a positioned children style was changed
	 */
	public function invalidatedPositionedChildStyle(styleIndex:Int):Void
	{
		switch (styleIndex)
		{
			case CSSConstants.BACKGROUND_COLOR, CSSConstants.BACKGROUND_CLIP,
			CSSConstants.BACKGROUND_IMAGE, CSSConstants.BACKGROUND_POSITION,
			CSSConstants.BACKGROUND_ORIGIN, CSSConstants.BACKGROUND_REPEAT,
			CSSConstants.BACKGROUND_SIZE:	
			
			default:
				_positionedChildrenNeedLayout = true;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * schedule a layout with the HTMLDocument
	 */
	private function invalidateLayout():Void
	{
		_needsLayout = true;
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		if (htmlDocument != null)
		{
			htmlDocument.invalidationManager.invalidateLayout(false);
		}
	}
	
	/**
	 * schedule a layout and rendering
	 */
	private function invalidateLayoutAndRendering():Void
	{
		_needsLayout = true;
		
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		htmlDocument.invalidationManager.invalidateLayout(false);
		
		//invalidate the layer associated with
		//this ElementRenderer
		if (layerRenderer != null)
		{
			layerRenderer.invalidateRendering();
		}
	}
	
	/**
	 * Invalidate the TextRenderer children
	 */
	private function invalidateText():Void
	{
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			if (child.isText == true)
			{
				child.invalidate();
			}
			child = child.nextSibling;
		}
	}
	
}
