 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.RendererData;
import cocktail.core.style.CSSConstants;

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
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
	
		_needsLayout = true;
		_childrenNeedLayout = true;
		_positionedChildrenNeedLayout = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Main invalidation method. Switch the invalidation reason
	 * to determine the steps to take
	 */
	override public function invalidate(invalidationReason:InvalidationReason):Void
	{
		switch(invalidationReason)
		{
			case InvalidationReason.styleChanged(styleName):
				invalidatedStyle(styleName, invalidationReason);
			
			case InvalidationReason.childStyleChanged(styleName):
				invalidatedChildStyle(styleName, invalidationReason);
				
			case InvalidationReason.positionedChildStyleChanged(styleName):
				invalidatedPositionedChildStyle(styleName, invalidationReason);
				
			case InvalidationReason.needsImmediateLayout:
				//TODO 1 : should probably also set global origin
				layout(true);
				
			case InvalidationReason.windowResize:
				_needsLayout = true;
				_childrenNeedLayout = true;
				_positionedChildrenNeedLayout = true;
				invalidateDocumentLayoutAndRendering();
				
			case InvalidationReason.backgroundImageLoaded:
				invalidateDocumentRendering();
				
			case InvalidationReason.other:
				_needsLayout = true;
				_childrenNeedLayout = true;
				_positionedChildrenNeedLayout = true;
				invalidateContainingBlock(invalidationReason);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when an in flow child was invalidated
	 */
	public function childInvalidated(invalidationReason:InvalidationReason):Void
	{
		invalidate(invalidationReason);
	}
	
	/**
	 * Called when a positioned child was invalidated
	 */
	public function positionedChildInvalidated(invalidationReason:InvalidationReason):Void
	{
		invalidate(invalidationReason);
	}
	
	/**
	 * Invalidate the containing block of the ElementRenderer,
	 * which might be the parent, the first positioned ancestor
	 * or the initial block renderer
	 */
	private function invalidateContainingBlock(invalidationReason:InvalidationReason):Void
	{
		//TODO 1 : not supposed to happen but bug with scrollbars for now
		if (parentNode == null)
		{
			return;
		}
		
		var containingBlockInvalidationReason:InvalidationReason;
		
		//for the containing block, the invalidation reason might change so that
		//the containing block knows that it was a children that was initially
		//invalidated, not itself
		switch (invalidationReason)
		{
			case InvalidationReason.styleChanged(styleName):
				if (isPositioned() == true)
				{
					containingBlockInvalidationReason = InvalidationReason.positionedChildStyleChanged(styleName);
				}
				else
				{
					containingBlockInvalidationReason = InvalidationReason.childStyleChanged(styleName);
				}
				
			default:
				containingBlockInvalidationReason = invalidationReason;
				
		}
		
		//call different invalidation method for positioned and
		//in flow block container
		//
		//TODO 2 : might be redundant with the invalidationreason change ?
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			_containingBlock.positionedChildInvalidated(containingBlockInvalidationReason);
		}
		else
		{
			_containingBlock.childInvalidated(containingBlockInvalidationReason);
		}
	}
	
	/**
	 * Called when a style change if this ElementRenderer
	 * caused the invalidation
	 */
	private function invalidatedStyle(styleName:String, invalidationReason:InvalidationReason):Void
	{
		switch (styleName)
		{
			//if one of the position style (left, right,top, bottom) was changed,
			//a layout and rendering is only needed for positioned child
			case CSSConstants.LEFT_STYLE_NAME, CSSConstants.RIGHT_STYLE_NAME,
			CSSConstants.TOP_STYLE_NAME, CSSConstants.BOTTOM_STYLE_NAME:
				
				if (isPositioned() == true && isRelativePositioned() == false)
				{
					_needsLayout = true;
					invalidateContainingBlock(invalidationReason);
				}
				//if the child is relatively positioned, it only needs a rendering, as its
				//layout is not affected by those styles
				else
				{
					invalidateDocumentRendering();
				}
				
			//those style invalidate the child TextµRenderer of this ElementRenderer	
			case CSSConstants.COLOR_STYLE_NAME, CSSConstants.FONT_FAMILY_STYLE_NAME, CSSConstants.FONT_SIZE_STYLE_NAME,
			CSSConstants.FONT_VARIANT_STYLE_NAME, CSSConstants.FONT_STYLE_STYLE_NAME, CSSConstants.FONT_WEIGHT_STYLE_NAME,
			CSSConstants.LETTER_SPACING_STYLE_NAME, CSSConstants.TEXT_TRANSFORM_STYLE_NAME, CSSConstants.WHITE_SPACE_STYLE_NAME:
				invalidateText(invalidationReason);
				_needsLayout = true;
				invalidateContainingBlock(invalidationReason);
			
			//a background style change only requires a re-rendering, as backgrounds never
			//affects layout
			case CSSConstants.BACKGROUND_COLOR_STYLE_NAME, CSSConstants.BACKGROUND_CLIP_STYLE_NAME,
			CSSConstants.BACKGROUND_IMAGE_STYLE_NAME, CSSConstants.BACKGROUND_POSITION_STYLE_NAME,
			CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME, CSSConstants.BACKGROUND_REPEAT_STYLE_NAME,
			CSSConstants.BACKGROUND_SIZE_STYLE_NAME:
				invalidateDocumentRendering();
			
			//for any other style change,invalidate layout, rendering and 
			//the containing block
			default:
				_needsLayout = true;
				invalidateContainingBlock(invalidationReason);
		}
	}
	
	/**
	 * Called when an inflow child style was changed
	 */
	private function invalidatedChildStyle(styleName:String, invalidationReason:InvalidationReason):Void
	{
		switch (styleName)
		{
			//TODO 2 : not supposed to be called anyway
			case CSSConstants.BACKGROUND_COLOR_STYLE_NAME, CSSConstants.BACKGROUND_CLIP_STYLE_NAME,
			CSSConstants.BACKGROUND_IMAGE_STYLE_NAME, CSSConstants.BACKGROUND_POSITION_STYLE_NAME,
			CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME, CSSConstants.BACKGROUND_REPEAT_STYLE_NAME,
			CSSConstants.BACKGROUND_SIZE_STYLE_NAME:
			
			//by default, set a relayout of this containing block and
			//a rendering of all its children
			default:
				_needsLayout = true;
				invalidateDocumentLayoutAndRendering();
		}
	}
	
	/**
	 * Called when a positioned children style was changed
	 */
	private function invalidatedPositionedChildStyle(styleName:String, invalidationReason:InvalidationReason):Void
	{
		switch (styleName)
		{
			case CSSConstants.BACKGROUND_COLOR_STYLE_NAME, CSSConstants.BACKGROUND_CLIP_STYLE_NAME,
			CSSConstants.BACKGROUND_IMAGE_STYLE_NAME, CSSConstants.BACKGROUND_POSITION_STYLE_NAME,
			CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME, CSSConstants.BACKGROUND_REPEAT_STYLE_NAME,
			CSSConstants.BACKGROUND_SIZE_STYLE_NAME:	
			
			default:
				_positionedChildrenNeedLayout = true;
				invalidateDocumentLayoutAndRendering();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * schedule a layout with the HTMLDocument
	 */
	private function invalidateDocumentLayout():Void
	{
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		htmlDocument.invalidateLayout();
	}
	
	/**
	 * schedule a rendering with the HTMLDocument
	 */
	private function invalidateDocumentRendering():Void
	{
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		htmlDocument.invalidateRendering();
	}
	
	/**
	 * schedule a layout and rendering with the HTMLDocument
	 */
	private function invalidateDocumentLayoutAndRendering():Void
	{
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		htmlDocument.invalidateLayout();
		htmlDocument.invalidateRendering();
	}
	
	/**
	 * Invalidate the TextRenderer children
	 */
	private function invalidateText(invalidationReason:InvalidationReason):Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			if (child.isText() == true)
			{
				child.invalidate(invalidationReason);
			}
		}
	}
	
}