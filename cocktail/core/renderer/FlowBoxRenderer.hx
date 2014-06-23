 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.layout.LayoutManager;
import cocktail.core.linebox.InlineBox;

import cocktail.core.boxmodel.BlockBoxStylesComputer;
import cocktail.core.boxmodel.BoxStylesComputer;
import cocktail.core.boxmodel.FloatBoxStylesComputer;
import cocktail.core.boxmodel.InlineBlockBoxStylesComputer;
import cocktail.core.boxmodel.InLineBoxStylesComputer;
import cocktail.core.boxmodel.PositionedBoxStylesComputer;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.geom.GeomData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSCascadeData;

/**
 * This is a base class for ElementRenderer which are
 * container such as the block box and inline box.
 * 
 * It takes cares of laying out its children
 * 
 * @author Yannick DOMINGUEZ
 */
class FlowBoxRenderer extends BoxRenderer 
{
	/**
	 * holds a reference to each absolutely positioned child
	 * for which this FlowBoxRenderer is the first
	 * positioned ancestor.
	 * 
	 * Absolutely positioned children register and unregister
	 * themselves when attached and detached
	 */
	private var _absolutelyPositionedChildren:Array<ElementRenderer>;
	
	/**
	 * A point used to find the static position
	 * of an absolutely positioned child, reused
	 * for each static position computation
	 */
	private var _childStaticOrigin:PointVO;
	
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		_absolutelyPositionedChildren = new Array<ElementRenderer>();
		_childStaticOrigin = new PointVO(0, 0);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render inline children of a box recursively.
	 * Put here as it is used by both block renderers
	 * starting an inline formatting and inline box
	 * with their own layer (for instance with a relative position)
	 * 
	 * @param	rootRenderer
	 * @param	referenceLayer
	 * @param	graphicContext
	 * @param	clipRect
	 * @param	scrollOffset
	 */
	private function renderInlineChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootRenderer.firstChild;
		while(child != null)
		{
			if (child.layerRenderer == referenceLayer)
			{
				if (child.coreStyle.isFloat == false)
				{
					child.render(graphicContext, clipRect, scrollOffset);
					
					//render recursively except for child establishing new formatting context, such as inline-block
					if (child.firstChild != null && child.establishesNewBlockFormattingContext() == false)
					{
						renderInlineChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
					}
				}
				
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Used by absolutely positioned children to register themselves to their
	 * first positioned ancestor so that they can be laid out by it.
	 * Called when the children are attached
	 */
	public function addAbsolutelyPositionedChildren(element:ElementRenderer):Void
	{
		_absolutelyPositionedChildren.push(element);
	}
	
	/**
	 * The absolutely positioned children unregister themselves when they 
	 * are detached
	 */
	public function removeAbsolutelyPositionedChild(element:ElementRenderer):Void
	{
		_absolutelyPositionedChildren.remove(element);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as FlowBoxRenderer are also responsible
	 * for laying out their children
	 */
	override public function layout(forceLayout:Bool, layoutState:LayoutStateValue):Void
	{
		super.layout(forceLayout, layoutState);
		
		//only call if has children
		if (firstChild != null)
		{
			//layout all the in flow children (non positioned or floated)
			layoutChildren(layoutState);
		}
		
		
		//if this ElementRenderer is positioned, it means that it is the first positioned ancestor
		//for its absolutely positioned children and it is its responsability to lay them out
		if (isPositioned() == true)
		{
			//only call if has positioned children
			if (_absolutelyPositionedChildren.length > 0 )
			{
				layoutAbsolutelyPositionedChildren(layoutState);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Layout the children of the box which belongs
	 * to the normal flow or are floated.
	 * Implemented by BlockBoxRenderer
	 */
	private function layoutChildren(layoutState:LayoutStateValue):Void
	{
		//abstract
	}
	
	/**
	 * Layout all the absolutely positioned children, with style fixed and absolute
	 */
	private function layoutAbsolutelyPositionedChildren(layoutState:LayoutStateValue):Void
	{
		var containerBlockData:ContainingBlockVO = getContainerBlockData();
		var viewportData:ContainingBlockVO = getViewportData();
		
		//lay out each stored children
		var length:Int = _absolutelyPositionedChildren.length;
		for (i in 0...length)
		{
			_absolutelyPositionedChildren[i].layout(true, layoutState);
			//layout the child ElementRenderer which set its x and y positioned origin in the space of this ElementRenderer's
			//positioned origin
			layoutPositionedChild(_absolutelyPositionedChildren[i], containerBlockData, viewportData);
		}
	}
	
	/**
	 * layout an absolutely positioned ElementRenderer (with a position style of 'fixed' or 'absolute')
	 * using either the first positioned ancestor dimensions or the viewport's
	 * 
	 * @param firstPositionedAncestorData the dimensions of the first positioned ancestor
	 * @param viewportData the dimensions of the viewport
	 */
	private function layoutPositionedChild(elementRenderer:ElementRenderer, firstPositionedAncestorData:ContainingBlockVO, viewportData:ContainingBlockVO):Void
	{
		var coreStyle:CoreStyle = elementRenderer.coreStyle;
		//positioned 'fixed' ElementRenderer, use the viewport
		if (coreStyle.isFixedPositioned == true)
		{
			doLayoutPositionedChild(elementRenderer, viewportData, false);
		}
		//positioned 'absolute' ElementRenderer use the first positioned ancestor data	
		else
		{
			doLayoutPositionedChild(elementRenderer, firstPositionedAncestorData, true);
		}
	}
	
	/**
	 * Actually lay out the positioned ElementRenderer
	 * @param elementRenderer the absolute of fixed element laid out
	 * @param containingBlockData contain the dimension of the first positioned ancestor or the viewport
	 * @param isAbsolutelyPositioned wether the element is absolut (true) or fixed (false) positioned
	 */
	private function doLayoutPositionedChild(elementRenderer:ElementRenderer, containingBlockData:ContainingBlockVO, isAbsolutelyPositioned:Bool):Void
	{
		var elementCoreStyle:CoreStyle = elementRenderer.coreStyle;

		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (elementCoreStyle.hasAutoLeft == false)
		{
			elementRenderer.bounds.x = getLeftOffset(elementRenderer, isAbsolutelyPositioned);
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing block width minus the
		//width of the positioned children as value for a 0 right offset
		else if (elementCoreStyle.hasAutoRight == false)
		{
			elementRenderer.bounds.x = getRightOffset(elementRenderer, containingBlockData.width, isAbsolutelyPositioned);
		}
		//if both right and left are 'auto', then the ElementRenderer is positioned to its
		//static position, the position it would have had in the flow if it were positioned as 'static'.
		//At this point the layout of all the normal flow element belonging to the same formatting
		//is done, and the element renderer can retrieve its static position
		else
		{
			elementRenderer.staticOrigin.x = getStaticPosition(elementRenderer).x;
		}
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (elementCoreStyle.hasAutoTop == false)
		{
			elementRenderer.bounds.y = getTopOffset(elementRenderer, isAbsolutelyPositioned);
		}
		else if (elementCoreStyle.hasAutoBottom == false)
		{
			elementRenderer.bounds.y = getBottomOffset(elementRenderer, containingBlockData.height, isAbsolutelyPositioned);
		}
		else
		{
			elementRenderer.staticOrigin.y = getStaticPosition(elementRenderer).y;
		}
	}
	
	/**
	 * get the left offset to apply the ElementRenderer
	 */
	private function getLeftOffset(elementRenderer:ElementRenderer, isAbsolutelyPositioned:Bool):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		var leftOffset:Float = usedValues.left + usedValues.marginLeft;
		
		//if the element is absolut positioned, then it is
		//placed relative to the padding box and not content
		//box of its first positioned ancestor, so any padding and border
		//of this first positioned ancesotr is removed
		if (isAbsolutelyPositioned == true)
		{
			leftOffset -= coreStyle.usedValues.paddingLeft - coreStyle.usedValues.borderLeftWidth;
		}
		
		return leftOffset;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(elementRenderer:ElementRenderer, containingHTMLElementWidth:Float, isAbsolutelyPositioned:Bool):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		
		var rightOffset:Float = containingHTMLElementWidth - usedValues.width - usedValues.paddingLeft
		- usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.right - usedValues.marginRight;
		
		//place relative to padding box instead of content box
		if (isAbsolutelyPositioned == true)
		{
			rightOffset += coreStyle.usedValues.paddingRight + coreStyle.usedValues.borderRightWidth;
		}
		
		return rightOffset;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(elementRenderer:ElementRenderer, isAbsolutelyPositioned:Bool):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		
		var topOffset:Float = usedValues.top + usedValues.marginTop;
		
		//place relative to padding box instead of content box
		if (isAbsolutelyPositioned == true)
		{
			topOffset -= coreStyle.usedValues.paddingTop - coreStyle.usedValues.borderTopWidth;
		}
		
		return topOffset;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(elementRenderer:ElementRenderer, containingHTMLElementHeight:Float, isAbsolutelyPositioned:Bool):Float
	{
		var usedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		
		var bottomOffset:Float = containingHTMLElementHeight - usedValues.height - usedValues.paddingTop -
		usedValues.paddingBottom - usedValues.bottom - usedValues.marginBottom;
		
		//place relative to padding box instead of content box
		if (isAbsolutelyPositioned == true)
		{
			bottomOffset += coreStyle.usedValues.paddingBottom + coreStyle.usedValues.borderBottomWidth;
		}
		
		return bottomOffset;
	}
	
	/**
	 * Return the static position of an absolutely positioned
	 * element renderer, which is the position it would have had
	 * if it weren't absolutely positioned. This position is
	 * relative to its first containing block parent
	 */
	private function getStaticPosition(elementRenderer:ElementRenderer):PointVO
	{
		//find the first parent which is a block container, it will
		//be the containing block that the element renderer would have
		//had with a static positioning
		var staticContainingBlock:ElementRenderer = elementRenderer.parentNode;
		while (staticContainingBlock != null)
		{
			if (staticContainingBlock.isBlockContainer == true)
			{
				break;
			}
			
			staticContainingBlock = staticContainingBlock.parentNode;
		}
		
		//retrieving the static position depends
		//on wether the containing block establishes/participate
		//in a block formatting or if it establishes an inline
		//formatting
		//
		//here it participates/establishes a block formatting
		if (staticContainingBlock.childrenInline() == false)
		{
			//get the first previous sibling belonging to the normal flow
			var previousNormalFlowSibling:ElementRenderer = elementRenderer.previousNormalFlowSibling;
			
			//if there is none, static position is the top left of the containing block
			if (previousNormalFlowSibling == null)
			{
				//use the top and left margin
				_childStaticOrigin.x = elementRenderer.coreStyle.usedValues.marginLeft;
				_childStaticOrigin.y = elementRenderer.coreStyle.usedValues.marginTop;
			}
			//else static position is below the previous normal flow sibling
			else
			{
				_childStaticOrigin.x = elementRenderer.coreStyle.usedValues.marginLeft;
				
				//placed below margin box of previous normal flow child
				_childStaticOrigin.y = previousNormalFlowSibling.bounds.y + previousNormalFlowSibling.bounds.height + previousNormalFlowSibling.coreStyle.usedValues.marginBottom;
				//add top margin of element which never collapse when finding static position
				_childStaticOrigin.y += elementRenderer.coreStyle.usedValues.marginTop;
			}
		}
		//here the containing block establishes an inline formatting
		else
		{
			//get the first previous sibling belonging to the normal flow
			var previousNormalFlowSibling:ElementRenderer = elementRenderer.previousNormalFlowSibling;
			
			//if there is none
			if (previousNormalFlowSibling == null)
			{
				//get the parent which might be a block or inline container
				var parent:ElementRenderer = elementRenderer.parentNode;
				//if it is a block, then this element is the first of the inline formatting context,
				//and can be placed to the top left of the containing block
				if (parent.isBlockContainer == true)
				{
					//use the top and left margin
					_childStaticOrigin.x = elementRenderer.coreStyle.usedValues.marginLeft;
					_childStaticOrigin.y = elementRenderer.coreStyle.usedValues.marginTop;
				}
				//else the static position is after the last inline box generated by the parent
				else
				{
					var lastInlineBox:InlineBox = parent.inlineBoxes[parent.inlineBoxes.length - 1];
					_childStaticOrigin = getPositionAfterInlineBox(lastInlineBox, elementRenderer, _childStaticOrigin);
				}
			}
			//else the static position is after the last inline box generated by the previous sibling
			else
			{
				var lastInlineBox:InlineBox = previousNormalFlowSibling.inlineBoxes[previousNormalFlowSibling.inlineBoxes.length - 1];
				_childStaticOrigin = getPositionAfterInlineBox(lastInlineBox, elementRenderer, _childStaticOrigin);
			}
		}
		
		return _childStaticOrigin;
	}
	
	/**
	 * For a given inline box, find and return the position
	 * after which would be used as static origin
	 */
	private function getPositionAfterInlineBox(inlineBox:InlineBox, elementRenderer:ElementRenderer, staticOrigin:PointVO):PointVO
	{
		//if the line box of the last inline box is null it means it wasn't
		//attached to the line box tree, might happen for instance for a space
		//at the beginning or end of line which gets removed
		//
		//TODO : should use first inline box which is attached ?
		if (inlineBox.lineBox == null)
		{
			staticOrigin.x = elementRenderer.coreStyle.usedValues.marginLeft;
			staticOrigin.y = elementRenderer.coreStyle.usedValues.marginTop;
		}
		else
		{
			staticOrigin.x = inlineBox.bounds.x + inlineBox.lineBox.bounds.x + inlineBox.bounds.width + inlineBox.marginLeft + inlineBox.marginRight;
			staticOrigin.x += elementRenderer.coreStyle.usedValues.marginLeft;
			
			staticOrigin.y = inlineBox.bounds.y + inlineBox.lineBox.bounds.y;
			staticOrigin.y += elementRenderer.coreStyle.usedValues.marginTop;
		}
		
		return staticOrigin;
	}
}
