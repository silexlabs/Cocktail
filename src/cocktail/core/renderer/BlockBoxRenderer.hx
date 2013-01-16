 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.css.CascadeManager;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.InitialStyleDeclaration;
import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.geom.GeomUtils;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.linebox.LineBox;
import cocktail.core.linebox.InlineBox;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
import cocktail.core.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;
import cocktail.Lib;
import haxe.Firebug;
import haxe.Log;
import cocktail.core.layer.LayerRenderer;
import haxe.Stack;

/**
 * A block box renderer is an element which participate
 * in a block or inline formatting context and which can establish
 * either a block or inline formatting context.
 * 
 * When it starts an inline formatting context, it holds
 * an array of line box which which represents
 * each line created by this block box.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockBoxRenderer extends FlowBoxRenderer
{	
	/**
	 * An array where each item represents a line
	 * . Used when this block box establishes an 
	 * inline formatting context
	 */
	public var lineBoxes(default, null):Array<LineBox>;
	
	public var floatsManager:FloatsManager;
	
	/**
	 * during block layout, store position
	 * where next block child will be placed,
	 * relative to containing block (this)
	 */
	private var _childPosition:PointVO;
	
	/**
	 * during inline formatting, store the
	 * position where the next line box
	 * will be placed relative to containing
	 * block (this)
	 */
	private var _lineBoxPosition:PointVO;
	
	/**
	 * Reused structure when computing bounds
	 * of inline children, used to hold
	 * the bounds of an inline box with the added
	 * x and y offset of its line box so that it is
	 * converted to the space of the containing block 
	 * (this)
	 */
	private var _inlineBoxGlobalBounds:RectangleVO;
	
	/**
	 * If this block box establishes a new formatting
	 * context and its width is shrink-to-fit, this
	 * rectangle is used to retrieve the total
	 * width of the block formatting context
	 */
	private var _blockFormattingBounds:RectangleVO;
	
	/**
	 * a reusable rect used for the bounds of the 
	 * children during the computation of this block 
	 * bounds
	 */
	private var _childBlockFormattingBounds:RectangleVO;
	
	/**
	 * If this block establishes a new formatting context
	 * and its height is auto, then the height of
	 * its floated elements migt influence its own
	 * height
	 */
	private var _floatedElementsBounds:RectangleVO;
	
	/**
	 * A flag which might be set during inline
	 * formatting if a float is found, meaning
	 * that layout of block should
	 * be re-done with the new float
	 * data
	 */
	private var _floatFound:Bool;
	
	/**
	 * class constructor.
	 * Init class attributes
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		
		_lineBoxPosition = new PointVO(0, 0);
		_childPosition = new PointVO(0, 0);
		lineBoxes = new Array<LineBox>();
		floatsManager = new FloatsManager();
		_floatFound = false;
		_inlineBoxGlobalBounds = new RectangleVO();
		_blockFormattingBounds = new RectangleVO();
		_floatedElementsBounds = new RectangleVO();
		_childBlockFormattingBounds = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * If this block element renderer has both inline and
	 * block children, the inline children are wrapped
	 * in anonymous block to preserve the CSS invariant
	 * where all children of a block must either be all
	 * inline or all block
	 */
	override public function updateAnonymousBlock():Void
	{
		//flag determining wether inline children must be wrapped
		//in anonymous block
		var shouldMakeChildrenNonInline:Bool = false;
		
		//the BlockBoxRenderer should have at least one normal flow child to determine wether to 
		//establish/participate in a block or inline formatting context, and thus if inline children
		//shoud be wrapped in anonymous block
		if (firstNormalFlowChild != null)
		{
			//store wether the children of this block are curently inline
			//or block
			var childrenInline:Bool = childrenInline();
			
			//loop in all children, looking for one which doesn't
			//coreespond to the currrent formatting of the block
			var child:ElementRenderer = firstChild;
			while(child != null)
			{
				//absolutely positioned and floated children are not taken into account when determining wether this
				//BlockBoxRenderer establishes/participate in a block or inline formatting context
				if (child.isAbsolutelyPositioned() == false)
				{	
					if (child.isFloat() == false)
					{
						//if this child doesn't match the display of the other children,
						///for instance if it is the first inline while all the other
						//children are block, all the inline children should be wrapped in 
						//anonymous blocks
						if (child.isInlineLevel() != childrenInline)
						{
							shouldMakeChildrenNonInline = true;
							break;
						}
					}
				}
				
				child = child.nextSibling;
			}
		}
		
		//make all children non inline if necessary
		if (shouldMakeChildrenNonInline == true)
		{
			makeChildrenNonInline();
		}
		
		//call on all descendant block box
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.updateAnonymousBlock();
			child = child.nextSibling;
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANONYMOUS BLOCK METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is called when all the inline children of this block
	 * box should be wrapped in anonymous block. It is done to preserve
	 * the invariant in CSS where all the children of a block box must
	 * either all be block or must all be inline. Wrapping inline children
	 * makes all the children blocks
	 */
	private function makeChildrenNonInline():Void
	{
		//will store all the current block children and the newly created
		//anonymous block, in order and will replace the current child nodes array
		var newChildNodes:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		//hold the last created anonymous block, so that contiguous
		//inline level children are added to the same anonymous block
		//box instead of creating new one each time
		var lastCreatedAnonymousBlock:AnonymousBlockBoxRenderer = null;
		
		//loop in the child nodes in reverse order, as the child nodes
		//array will be modified during this loop
		var child:ElementRenderer = lastChild;
		while(child != null)
		{
			var previousSibling:ElementRenderer = child.previousSibling;
			
			//for inline children, create an anonymous block, and attach the child to it
			if (child.isInlineLevel() == true)
			{
				//use the previous if no block level child were in-between
				if (lastCreatedAnonymousBlock != null)
				{
					lastCreatedAnonymousBlock.insertBefore(child, lastCreatedAnonymousBlock.firstChild);
				}
				else
				{
					lastCreatedAnonymousBlock = createAnonymousBlock(child);
					newChildNodes.push(lastCreatedAnonymousBlock);
				}
			}
			else
			{
				lastCreatedAnonymousBlock = null;
				newChildNodes.push(child);
			}
			
			child = previousSibling;
		}
		
		//must reverse as the child nodes where
		//looped in reverse order
		newChildNodes.reverse();
		
		//attach all the block children and the newly
		//created anonymous block box
		var length:Int = newChildNodes.length;
		for (i in 0...length)
		{
			appendChild(newChildNodes[i]);
		}
	}
	
	/**
	 * create an anonymous block and append an inline child to it
	 */ 
	private function createAnonymousBlock(child:ElementRenderer):AnonymousBlockBoxRenderer
	{
		var anonymousBlock:AnonymousBlockBoxRenderer = new AnonymousBlockBoxRenderer();
		anonymousBlock.appendChild(child);
		
		anonymousBlock.coreStyle = anonymousBlock.domNode.coreStyle;
		
		//TODO 3 : all of this is very messy but before that styles of anonymous blocks
		//were cascaded which was very expensive and useless
		var initialStyleDeclaration:InitialStyleDeclaration = Lib.document.initialStyleDeclaration;
		anonymousBlock.coreStyle.specifiedValues = initialStyleDeclaration;
		anonymousBlock.coreStyle.computedValues = initialStyleDeclaration.initialComputedStyleDeclaration;
		anonymousBlock.coreStyle.isLeftAligned = true;
		
		return anonymousBlock;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a BlockBoxRenderer render its children too
	 */
	override private function renderChildren(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		super.renderChildren(graphicContext, clipRect, scrollOffset);
		
		//the BlockBoxRenderer is responsible for rendering its children in the same layer
		//context if it establishes a layer itself or is rendered as if it did
		if (createOwnLayer() == true || rendersAsIfCreateOwnLayer() == true)
		{
			//render all the block box which belong to the same stacking context
			renderBlockContainerChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
			
			//render all the replaced (embedded) box displayed as blocks belonging
			//to the same stacking context
			renderBlockReplacedChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
			
			//render all non-positioned floated elements
			renderFloatedChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
			
			//render all the line boxes belonging to the same stacking context
			renderLineBoxes(this, layerRenderer, graphicContext, clipRect, scrollOffset);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the LineBoxes of child BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderLineBoxes(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		if (rootRenderer.isBlockContainer() == true && rootRenderer.childrenInline() == true)
		{	
			renderInlineChildren(rootRenderer, referenceLayer, graphicContext, clipRect, scrollOffset);
		}
		else
		{
			var child:ElementRenderer = rootRenderer.firstChild;
			while(child != null)
			{
				if (child.layerRenderer == referenceLayer)
				{
					if (child.isReplaced() == false)
					{	
						if (child.coreStyle.isFloat == false)
						{
							renderLineBoxes(child, referenceLayer, graphicContext, clipRect, scrollOffset);
						}
					}
				}
				
				child = child.nextSibling;
			}
		}
	}
	
	/**
	 * Render all the replaced children displayed as blocks which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockReplacedChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootRenderer.firstChild;
		while(child != null)
		{
			if (child.layerRenderer == referenceLayer)
			{
				if (child.coreStyle.isFloat == false)
				{
					if (child.isReplaced() == false && child.coreStyle.isBlock == true )
					{
						renderBlockReplacedChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
					}
					else if (child.coreStyle.isBlock == true)
					{
						child.render(graphicContext, clipRect, scrollOffset);
					}
				}
				
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Render all the BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderBlockContainerChildren(rootElementRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			//check that the child is not positioned, as if it is an auto z-index positioned
			//element, it will be on the same layerRenderer but should not be rendered as 
			//a block container children
			if (child.layerRenderer == referenceLayer)
			{
				if (child.coreStyle.isInlineLevel == false)
				{
					if (child.isReplaced() == false)
					{
						if (child.coreStyle.isFloat == false)
						{
							child.render(graphicContext, clipRect, scrollOffset);
							renderBlockContainerChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
						}
					}
					
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Render all the floated BlockBoxRenderer which
	 * belong to the same stacking context as this BlockBoxRenderer
	 */
	private function renderFloatedChildren(rootElementRenderer:ElementRenderer, referenceLayer:LayerRenderer, graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			if (child.layerRenderer == referenceLayer)
			{
				if (child.coreStyle.isFloat == true)
				{
					child.render(graphicContext, clipRect, scrollOffset);
				}
				else
				{
					renderFloatedChildren(child, referenceLayer, graphicContext, clipRect, scrollOffset);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Layout all the children of this block box
	 * and deduce this block box width and height
	 * from it if needed
	 */
	override private function layoutChildren(layoutState:LayoutStateValue):Void
	{
		//before laying out, update the list of floated and clear elements
		updateFloatedAndClearElements();
		
		//do a first layout of the children
		//if any floated or clear element was encountered for the first time
		//during this layout, then it return true, and the layout
		//should be done again with the new floated and clear element list
		doLayoutChildren(layoutState);
		
		//if the width of this block box should be shrink-to-fit, it
		//can now be found 
		if (establishesNewBlockFormattingContext() == true)
		{
			applyShrinkToFitIfNeeded(layoutState);
		}
		
		//if the height of this block box depends on its content, 
		//it can now be found
		applyContentHeightIfNeeded();
	}
	
	/**
	 * layout all the children either in a block or inline
	 * formatting
	 */
	private function doLayoutChildren(layoutState:LayoutStateValue):Void
	{
		//children are either all block level or all inline level
		//(exluding floated and absolutely positioned element), 
		//so this block either formatting them as blocks or lines
		if (childrenInline() == false)
		{
			layoutBlockChildrenAndFloats(layoutState);
		}
		else
		{
			layoutInlineChildrenAndFloats(layoutState);
			
			//now that all children's inlineBoxes have been
			//laid out, their bounds can be updated
			updateInlineChildrenBounds(this);
		}
	}
	
	/**
	 * Update the list of floated element by converting
	 * their position to this block own space,
	 * and retrieve the list of clear element from the
	 * block formatting root
	 */
	public function updateFloatedAndClearElements():Void
	{	
		//if this block box is a block formatting root,
		//then it needs to reset its floated element and clear element list,
		//as it's children can't be affected by floated end clear elements
		//from another block formatting context
		if (establishesNewBlockFormattingContext() == true)
		{
			floatsManager.init();
		}
		//else this block box retrieves floated and clear elements from the nearest
		//block formatting context root and convert float elements to its own space
		else
		{
			var blockFormattingContextRoot:BlockBoxRenderer =  getNearestBlockFormattingContextRoot();
			floatsManager.retrieveFloatsFrom(this, blockFormattingContextRoot, getBlockBoxesOffset(this, blockFormattingContextRoot));
			floatsManager.childrenWithClearance = blockFormattingContextRoot.floatsManager.childrenWithClearance;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * If this block box width should be shrink-to-fit, compute it.
	 * 
	 * shrink-to-fit width roughly matches the width of the
	 * content of this block.
	 * 
	 * shrink-to-fit width is applied to block formatting root
	 * with an auto width. It can also be applied to child block
	 * container when a shrink-to-fit layout is in progress.
	 * 
	 * For instance, if this block has an inline-block child, when
	 * computed the preferred minimum width, the inline-block child
	 * would also be layout with the prefered minimum width layout state
	 */
	private function applyShrinkToFitIfNeeded(layoutState:LayoutStateValue):Void
	{
		//absolutely positioned element with not auto left and right style don't use shrink-to-fit width
		//if the layout state is not normal, shrink to fit might also be applied to block box which haven't auto width
		//but which still needs to compute their shrink-yo-fit width for their ancestor block formatting context
		if ((coreStyle.hasAutoWidth == true || layoutState != NORMAL) && isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight() == false)
		{
			//first prefered minimum width is found by laying out children by breaking line
			//at all possible line breaks
			doLayoutChildren(LayoutStateValue.SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH);
			
			//retrieve the maximum width of content formatted for prefered minimum width
			getBlockFormattingBounds();
			var preferedMinimumWidth:Float = _blockFormattingBounds.width;
			
			//in the case where this block has not an auto width, if its own width
			//is superior to the maximum width of its content, use its own width
			//instead
			if (coreStyle.hasAutoWidth == false)
			{
				if (bounds.width > preferedMinimumWidth)
				{
					preferedMinimumWidth = bounds.width;
				}
			}
			
			//then prefered width is found by laying children without breaking line
			//unless explicit break, such as a line feed happends
			doLayoutChildren(LayoutStateValue.SHRINK_TO_FIT_PREFERED_WIDTH);
			
			//retrieve maximum width of content formatted for prefered width
			getBlockFormattingBounds();
			var preferedWidth:Float = _blockFormattingBounds.width;
			
			//same as for prefered minimum width, use own width
			//if superior to children width
			if (coreStyle.hasAutoWidth == false)
			{
				if (bounds.width > preferedWidth)
				{
					preferedWidth = bounds.width;
				}
			}
			
			//available width is content width of containing block
			var availableWidth:Float = containingBlock.coreStyle.usedValues.width;
			
			//apply shrink to fit formula
			var shrinkToFitWidth:Float = Math.min(Math.max(preferedMinimumWidth, availableWidth), preferedWidth);
			
			//constrain shrink-to-fit width if needed
			if (coreStyle.hasMaxWidth == true)
			{
				if (shrinkToFitWidth > coreStyle.usedValues.maxWidth)
				{
					shrinkToFitWidth = coreStyle.usedValues.maxWidth;
				}
			}
			
			if (shrinkToFitWidth < coreStyle.usedValues.minWidth)
			{
				shrinkToFitWidth = coreStyle.usedValues.minWidth;
			}
			
			coreStyle.usedValues.width = shrinkToFitWidth;
			bounds.width = shrinkToFitWidth + coreStyle.usedValues.paddingLeft + coreStyle.usedValues.paddingRight;
			
			//now that shrink to fit is known layout children with it
			doLayoutChildren(LayoutStateValue.NORMAL);
		}
	}
	
	/**
	 * Get the bounds of all the children of this block box
	 * belonging to the same block formatting
	 */
	private function getBlockFormattingBounds():Void
	{
		_blockFormattingBounds.x = 50000;
		_blockFormattingBounds.y = 50000;
		_blockFormattingBounds.width = 0;
		_blockFormattingBounds.height = 0;
			
		doGetBlockFormattingBounds(this, _blockFormattingBounds, 0, 0);	
	}
	
	/**
	 * do get block formatting bounds by traversing the
	 * rendering tree recursively
	 */
	private function doGetBlockFormattingBounds(rootElementRenderer:ElementRenderer, blockFormattingBounds:RectangleVO, xOffset:Float, yOffset:Float):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while (child != null)
		{
			if (child.isFloat() == false)
			{
				if (child.isAbsolutelyPositioned() == false)
				{
					_childBlockFormattingBounds.x = child.bounds.x + xOffset - child.coreStyle.usedValues.marginLeft;
					_childBlockFormattingBounds.y = child.bounds.y + yOffset - child.coreStyle.usedValues.marginTop;
					_childBlockFormattingBounds.width = child.bounds.width + child.coreStyle.usedValues.marginRight + child.coreStyle.usedValues.marginLeft;
					_childBlockFormattingBounds.height = child.bounds.height + child.coreStyle.usedValues.marginBottom + child.coreStyle.usedValues.marginTop;

					GeomUtils.addBounds(_childBlockFormattingBounds, blockFormattingBounds);
					
					if (child.establishesNewBlockFormattingContext() == false && child.firstChild != null)
					{
						doGetBlockFormattingBounds(child, blockFormattingBounds, xOffset + child.bounds.x, yOffset + child.bounds.y);
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Get the bounds of all the floated elements
	 * belonging to the same block formatting
	 */
	private function getFloatedElementsBounds():Void
	{
		_floatedElementsBounds.x = 50000;
		_floatedElementsBounds.y = 50000;
		_floatedElementsBounds.width = 0;
		_floatedElementsBounds.height = 0;
		
		//if there are no floated elements in this block formatting
		//return 0 bounds
		if (floatsManager.floats.left.length == 0 && floatsManager.floats.right.length == 0)
		{
			_floatedElementsBounds.x = 0;
			_floatedElementsBounds.y = 0;
			return;
		}
			
		//we can use the bounds of the floats manager which are
		//already in the space of this block box
		doGetFloatedElementsBounds(floatsManager.floats.left, _floatedElementsBounds);
		doGetFloatedElementsBounds(floatsManager.floats.right, _floatedElementsBounds);
	}
	
	/**
	 * Set the bounds of an array
	 * of floated element bounds on a result bounds
	 */
	private function doGetFloatedElementsBounds(floats:Array<FloatVO>, floatedElementsBounds:RectangleVO):Void
	{
		for (i in 0...floats.length)
		{
			GeomUtils.addBounds(floats[i].bounds, floatedElementsBounds);
		}
	}
	
	/**
	 * If the height od this block box depends on its content,
	 * it can computed now that its children have been laid out
	 */
	private function applyContentHeightIfNeeded():Void
	{
		if (coreStyle.hasAutoHeight == true && isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom() == false)
		{
			//children height is either line boxes bounds or block children bounds
			//only normal flow children are taken into acount
			var childrenHeight:Float = 0;
			if (childrenInline() == false)
			{
				childrenHeight = _childPosition.y;
			}
			else
			{
				childrenHeight = _lineBoxPosition.y;
			}
			
			//in addition if this block box establishes a new block formatting and has floated descedant whose bottom
			//are below its bottom, then the height includes those floated elements
			if (establishesNewBlockFormattingContext() == true)
			{
				//update bounds of floated element of this block formatting context
				getFloatedElementsBounds();
				//use those bounds if higher than normal flow children height
				if (_floatedElementsBounds.y + _floatedElementsBounds.height > childrenHeight)
				{
					childrenHeight = _floatedElementsBounds.y + _floatedElementsBounds.height;
				}
			}
			
			//constrain children height if needed
			if (coreStyle.hasMaxHeight == true)
			{
				if (childrenHeight > coreStyle.usedValues.maxHeight)
				{
					childrenHeight = coreStyle.usedValues.maxHeight;
				}
			}
			
			if (childrenHeight < coreStyle.usedValues.minHeight)
			{
				childrenHeight = coreStyle.usedValues.minHeight;
			}
			
			coreStyle.usedValues.height = childrenHeight;
			//bounds height matches the border box
			bounds.height = childrenHeight + coreStyle.usedValues.paddingTop + coreStyle.usedValues.paddingBottom;
		}
	}
	
	/**
	 * Returns wether this block box is absolutely positioned, with
	 * an auto height and top and bottom styles which are not auto.
	 * In this particular case, the height can be deduced from solving
	 * this equation :
	 * 
	 * 'top' + 'margin-top' + 'border-top-width' + 'padding-top' + 'height' + 'padding-bottom' + 'border-bottom-width' + 'margin-bottom' + 'bottom' = height of containing block 
	 * 
	 * In this case, height should not be content height and was already computed before laying out children
	 * 
	 * note : couldn't think of a shorther func name
	 */
	private function isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom():Bool
	{
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			return coreStyle.hasAutoTop == false && coreStyle.hasAutoBottom == false;
		}
		
		return false;
	}
	
	/**
	 * Same as above for width computing.
	 * In this particular case, the width can be
	 * deduced and should not be shrink-to-fit
	 */
	private function isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight():Bool
	{
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			return coreStyle.hasAutoLeft == false && coreStyle.hasAutoRight == false;
		}
		
		return false;
	}
	
	/**
	 * Called when all children are blocks. 
	 * Layout them as well as floated children
	 */
	private function layoutBlockChildrenAndFloats(layoutState:LayoutStateValue):Void
	{
		//holds the x,y position, in this block box space where
		//to position the next child
		_childPosition.x = 0;
		_childPosition.y = 0;
			
		//loop in all children
		var child:ElementRenderer = firstChild;
		while (child != null)
		{
			//absolutely positioned child are not positioned here
			if (child.isPositioned() == false || child.isRelativePositioned() == true)
			{
				//wether child has clearance, in which case it doesn't need to add its
				//top margin to its y position
				var childHasClearance:Bool = false;
				
				//if child can introduce clearance it will be placed below previous
				//left, right or both float based on the value of the clear style
				if (child.canHaveClearance() == true)
				{
					//the position were the child will be placed if it doesn't have clearance
					var hypotheticalChildYPosition:Float = _childPosition.y + child.getCollapsedTopMargin();

					//check wether child actually has clearance, meaning that it should be placed
					//below a float declared earlier in the document
					if (floatsManager.hasClearance(child, hypotheticalChildYPosition) == true)
					{
						//register the clearing element the first time it is found
						if (floatsManager.clearIsAlreadyRegistered(child) == false)
						{
							registerClearElement(child);
						}
						//compute actual clearance and set it 
						//as the y position were the child will be placed
						var clearance:Float = floatsManager.getClearance(child, hypotheticalChildYPosition);
						_childPosition.y += clearance;
						childHasClearance = true;
					}
				}
				
				//if the child is not a float
				if (child.isFloat() == false)
				{
					//if it is a block box not establishing a new block formatting
					if (child.establishesNewBlockFormattingContext() == false && child.isBlockContainer() == true)
					{
						//if child has clearance, its top margin is not used
						if (childHasClearance == false)
						{
							//add its own margin to the x/y position, as it is the position
							//of its border box. Top margin is collapsed with adjoining margins
							//if needed
							//floats are not taken into account when positioning it but if it creates
							//line boxes they might be shortened by those floats
							_childPosition.y += child.getCollapsedTopMargin();
						}
						
						//update postion of child
						child.bounds.x = child.coreStyle.usedValues.marginLeft;
						child.bounds.y = _childPosition.y;
						
						//child can now be layout, it needs to know its own x and y bounds
						//before laying out its children to correctly deal with floated elements,
						//as child need to convert floated elements to their own space
						child.layout(true, layoutState);
					}
					//here the child is either a replaced block level element or a block box
					//establishing a new block formatting
					else
					{
						//the child must first be laid out so that its width and height are known
						child.layout(true, layoutState);
						
						//this child x and y position is influenced by floated elements, so the first y position
						//where this child can fit given the floated elements must be found
						var childMarginWidth:Float = child.bounds.width + child.coreStyle.usedValues.marginLeft + child.coreStyle.usedValues.marginRight;
						var childMarginHeight:Float = child.bounds.height + child.getCollapsedTopMargin() + child.getCollapsedBottomMargin();
						var contentWidth:Float = bounds.width - coreStyle.usedValues.paddingLeft - coreStyle.usedValues.paddingRight;
						_childPosition.y = floatsManager.getFirstAvailableYPosition(_childPosition.y, childMarginHeight, childMarginWidth, contentWidth, 0);

						//if child has clearance, its top margin is not used
						if (childHasClearance == false)
						{
							//add child margins. Top margin is collapsed with
							//adjoining margins if needed
							_childPosition.y += child.getCollapsedTopMargin();
						}
						
						//update position of child
						child.bounds.y = _childPosition.y;
						
						//for x position, it is either defined by floated elements or by the left
						//margin, whichever is bigger
						var leftFloatOffset:Float = floatsManager.getLeftFloatOffset(_childPosition.y, childMarginHeight);
						if (leftFloatOffset > child.coreStyle.usedValues.marginLeft)
						{
							child.bounds.x = leftFloatOffset;
						}
						else
						{
							child.bounds.x = child.coreStyle.usedValues.marginLeft;
						}
					}
					
					//add the current's child height so that next block child will be placed below it
					_childPosition.y += child.bounds.height;
					//add child bottom margin, collapsed with adjoining margins
					//if needed
					_childPosition.y += child.getCollapsedBottomMargin();
				}
				//here the child is a floated element
				else
				{
					//it must first be laid out so that its width and height are known
					child.layout(true, layoutState);
					
					//first time a float is found, register it
					//TOOD 2 : now that there is only 1 pass no need to check
					//if already registered
					if (floatsManager.floatIsAlreadyRegistered(child) == false)
					{
						var childPosition:PointVO = _childPosition;
						
						//implementation of a border case, if the previous 
						//sibling is an anonymous block starting an inline formatting context,
						//then the float should be aligned to the top of its last line box
						var previousFlowSibling:ElementRenderer = child.previousNormalFlowSibling;
						if (previousFlowSibling != null)
						{
							if (previousFlowSibling.isAnonymousBlockBox() == true)
							{
								if (previousFlowSibling.childrenInline() == true)
								{
									childPosition = new PointVO(_childPosition.x, _childPosition.y);
									var blockPreviousSibling:AnonymousBlockBoxRenderer = cast(previousFlowSibling);
									var lastLineBox:LineBox = blockPreviousSibling.lineBoxes[blockPreviousSibling.lineBoxes.length - 1];
									childPosition.y = lastLineBox.bounds.y + blockPreviousSibling.bounds.y;
								}
							}
						}
						
						registerFloatedElement(child, childPosition);
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * When a clear element is first encountered, it is
	 * stored in the nearest block formatting context root,
	 * then all the all the ancestor of this block update
	 * their clear elements reference
	 */
	private function registerClearElement(clearElement:ElementRenderer):Void
	{
		var blockFormattingContextRoot:BlockBoxRenderer = getNearestBlockFormattingContextRoot();
		blockFormattingContextRoot.floatsManager.registerClear(clearElement);
		
		//update float and clear ref of parents
		updateAncestorsFloatedAndClearElements();
	}
	
	/**
	 * When a floated element is first encountered, it is stored
	 * 
	 * The floated element is stored on the nearest block formatting context root
	 * ancestor (which might be this).
	 * 
	 * Then all ancestors of this block until the block formatting root update
	 * their floated elemenet reference to add a reference to the newly added element
	 */
	private function registerFloatedElement(floatedElement:ElementRenderer, childPosition:PointVO):Void
	{
		var blockFormattingContextRoot:BlockBoxRenderer = getNearestBlockFormattingContextRoot();
		
		//get the x and y offset between this and the first block formatting context root ancestor
		var offset:PointVO = getBlockBoxesOffset(this, blockFormattingContextRoot);
		
		//store the floated element margin box position relative to the block formatting context
		//root content box
		var floatOffset:PointVO = new PointVO(0, 0);
		floatOffset.x = childPosition.x + offset.x;
		floatOffset.y = childPosition.y + offset.y;
		
		//get this block box content width
		var contentWidth:Float = bounds.width - coreStyle.usedValues.paddingLeft - coreStyle.usedValues.paddingRight;
		
		//store the floated element, determine where it should be positioned, taking other floated elements
		//into account
		var floatVO:FloatVO = blockFormattingContextRoot.floatsManager.registerFloat(floatedElement, floatOffset, contentWidth);
		
		//position the border box of the floated element relative to this block box
		floatedElement.bounds.x = floatVO.bounds.x + floatedElement.coreStyle.usedValues.marginLeft;
		floatedElement.bounds.y = floatVO.bounds.y + floatedElement.coreStyle.usedValues.marginTop;

		//convert back from the block formatting root space to this block box space
		floatedElement.bounds.x -= offset.x;
		floatedElement.bounds.y -= offset.y;
		
		//update float and clear ref of parents
		updateAncestorsFloatedAndClearElements();
	}
	
	/**
	 * Update the reference of the floated and clear element
	 * for all the ancestors of this block until the
	 * block formatting root
	 */
	private function updateAncestorsFloatedAndClearElements():Void
	{
		var parent:BlockBoxRenderer = this;
		while (parent != null)
		{
			if (parent.isBlockContainer() == true && parent.establishesNewBlockFormattingContext() == false)
			{
				parent.updateFloatedAndClearElements();
				parent = cast(parent.parentNode);
			}
			else
			{
				return;
			}
		}
	}

	/**
	 * When all children are inline level, format them as 
	 * lines. Also format floated children
	 */
	private function layoutInlineChildrenAndFloats(layoutState:LayoutStateValue):Void
	{
		//reset the array of line boxes before layout
		lineBoxes = new Array<LineBox>();
		
		//this will hold the x and y position where
		//to place the next line box, relative to this
		//block box
		_lineBoxPosition.x = 0;
		_lineBoxPosition.y = 0;
		
		var firstLineBox:LineBox = createLineBox(_lineBoxPosition, layoutState);
		
		//during layout hold the inline box renderer currently laying out descendant inline boxes
		var openedElementRendererStack:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		//holds all the inline formatting data which get updated during layout
		var inlineFormattingData:InlineFormattingVO = new InlineFormattingVO();
		inlineFormattingData.inlineBox = firstLineBox.rootInlineBox;
		inlineFormattingData.lineBox = firstLineBox;
		inlineFormattingData.openedElementRenderers = openedElementRendererStack;
		inlineFormattingData.lineBoxPosition = _lineBoxPosition;
		
		//do layout, return the last created inline box
		var lastInlineBox:InlineBox = doLayoutInlineChildrenAndFloats(this, inlineFormattingData, layoutState);
		
		//if a float was first found during layout,
		//it should be done again
		//
		//TODO 2 : not implemented, when a float is found on
		//a line, the layout of the line should be done again
		if (_floatFound == true)
		{
			//reset flag before new layout
			_floatFound = false;
		}
		
		//layout the last line
		inlineFormattingData.lineBox.layout(true, lastInlineBox);
		
		//add last line box height so that the total line boxes height
		//is known
		_lineBoxPosition.y += inlineFormattingData.lineBox.bounds.height;
	}
	
	/**
	 * Create and return a new line box. Position
	 * it relative to its containing block 
	 */
	private function createLineBox(lineBoxPosition:PointVO, layoutState:LayoutStateValue):LineBox
	{
		//the width of a line box is the client width of the containing block minus
		//the margin box width of any floated element intersecting with the line
		var availableWidth:Float = coreStyle.usedValues.width - floatsManager.getLeftFloatOffset(lineBoxPosition.y, coreStyle.usedValues.lineHeight) - floatsManager.getRightFloatOffset(lineBoxPosition.y, coreStyle.usedValues.lineHeight, coreStyle.usedValues.width);

		var lineBox:LineBox = new LineBox(this, availableWidth, lineBoxes.length == 0, layoutState);

		//position the line box in x and y relative to the containing block (this)
		//taking floated elements into account
		lineBox.bounds.y = lineBoxPosition.y;
		lineBox.bounds.x = floatsManager.getLeftFloatOffset(lineBox.bounds.y, coreStyle.usedValues.lineHeight);
		lineBoxes.push(lineBox);
		
		return lineBox;
	}
	
	/**
	 * When a line box was filled with inlineBoxes,
	 * lay it out, which set all its inlineBoxes x and y
	 * relative to the top left of the line box.
	 */
	private function layoutLineBox(inlineFormattingData:InlineFormattingVO, layoutState:LayoutStateValue):Void
	{
		var lineBox:LineBox = inlineFormattingData.lineBox;
		var lineBoxPosition:PointVO = inlineFormattingData.lineBoxPosition;
		var openedElementRenderers:Array<ElementRenderer> = inlineFormattingData.openedElementRenderers;
		
		lineBox.layout(false, null);
		
		//after layout, height of line box is known and added
		//to position correctly next line box
		lineBoxPosition.y += lineBox.bounds.height;
		
		//find the first y position where the next line box should be created.
		//it should be created at a position where the content which couldn't 
		//fit on the previous line can be placed
		lineBoxPosition.y = floatsManager.getFirstAvailableYPosition(lineBoxPosition.y, coreStyle.usedValues.lineHeight, lineBox.unbreakableWidth, coreStyle.usedValues.width, 0);
		
		var newLineBox:LineBox = createLineBox(lineBoxPosition, layoutState);
		
		//will be stored as the inline box where next inline boxes
		//can be attached to
		var currentInlineBox:InlineBox = newLineBox.rootInlineBox;
		
		//create new inline boxes for all the inline box renderer which still have
		//children to layout, and add them to the new line box
		var length:Int = openedElementRenderers.length;
		for (i in 0...length)
		{
			//all inline boxes are attached as child of the previously created inline box
			//and not as sibling to respect the hierarchy of the previous line. Hierarchey
			//must be preserved to render with the right z-order and to get the right
			//bounds for each inline box renderer
			var childInlineBox:InlineBox = new InlineBox(openedElementRenderers[i]);
			childInlineBox.lineBox = newLineBox;
			openedElementRenderers[i].inlineBoxes.push(childInlineBox);
			currentInlineBox.appendChild(childInlineBox);
			currentInlineBox = childInlineBox;
		}
		
		inlineFormattingData.lineBox = newLineBox;
		inlineFormattingData.inlineBox = currentInlineBox;
	}
	
	/**
	 * Actually layout inline box renderer by 
	 * traversing all inline box renderer children
	 * recursively
	 * @param	elementRenderer the current element renderer being laid out in line box
	 * @param	inlineFormattingData holds the inline formatting data
	 * @param	layoutState current layout performed, for instance a shrink-to-fit might require
	 * a layout where no lines are broken
	 */
	private function doLayoutInlineChildrenAndFloats(elementRenderer:ElementRenderer, inlineFormattingData:InlineFormattingVO, layoutState:LayoutStateValue):InlineBox
	{	
		//loop in all the child of the container
		var child:ElementRenderer = elementRenderer.firstChild;
		while(child != null)
		{
			//absolutely positionned children can't be formatted in an inline formatting context
			if (child.isPositioned() == false || child.isRelativePositioned() == true)
			{
				//here the child is floated, apply same behaviour as when a float is found
				//during bloc formatting
				if (child.isFloat() == true)
				{
					child.layout(true, layoutState);
					if (floatsManager.floatIsAlreadyRegistered(child) == false)
					{
						//implementation for a border case : a float in an inline formatting
						//can also have clearance, mostly similar to element with clearance
						//in block formatting layout
						if (child.canHaveClearance() == true)
						{
							var hypotheticalChildYPosition:Float = inlineFormattingData.lineBoxPosition.y + child.coreStyle.usedValues.marginTop;
							
							if (floatsManager.hasClearance(child, hypotheticalChildYPosition) == true)
							{
								if (floatsManager.clearIsAlreadyRegistered(child) == false)
								{
									registerClearElement(child);
								}
								
								//if float does have clearance, place it below any other float, acting more like
								//a block formatting
								var clearance:Float = floatsManager.getClearance(child, hypotheticalChildYPosition);
								var clearedFloatPosition:PointVO = new PointVO(0, 0);
								clearedFloatPosition.y = inlineFormattingData.lineBoxPosition.y + clearance;
								registerFloatedElement(child, clearedFloatPosition);
								_floatFound = true;
							}
						}
						else
						{
							//here the float doesn't have clearance
							//check wether there is enough space in the current line to fit the floated
							//element. If not, create a new line box to fit it.
							var floatMarginWidth:Float = child.bounds.width + child.coreStyle.usedValues.marginLeft + child.coreStyle.usedValues.marginRight;
							if (inlineFormattingData.lineBox.widthCanFit(floatMarginWidth) == false)
							{
								layoutLineBox(inlineFormattingData, layoutState);
							}
							
							//for inline formatting, float are replaced are aligned
							//with the current line box position
							registerFloatedElement(child, inlineFormattingData.lineBoxPosition);
							
							//for inline formatting, a flag is set instead
							//of just returning a flag as return value
							//already used
							_floatFound = true;
						}
					}
				}
				//here the child is a TextRenderer, which has as many text inline box
				//as needed to represent all the content of the TextRenderer
				else if (child.isText() == true)
				{
					//insert the array of created inline boxes into the current line. As many new line boxes
					//as needed are created to hold all those text inline boxes
					var textLength:Int = child.inlineBoxes.length;
					for (i in 0...textLength)
					{
						var lineIsFull:Bool = inlineFormattingData.lineBox.insert(child.inlineBoxes[i], inlineFormattingData.inlineBox, false);
						//if inserting this text would make the line full, create a new line for it
						if (lineIsFull == true)
						{
							//layout current line, create a new one and set it on the
							//inline formatting data
							layoutLineBox(inlineFormattingData, layoutState);
							
							//text inline box can now be inserted in the new line box
							//
							//TODO : instead of just adding last text inline box, should insert all
							//unbreakable elements of last line box
							inlineFormattingData.lineBox.insert(child.inlineBoxes[i], inlineFormattingData.inlineBox, true);
						}
					}
				}
				//here the child either establishes a new formatting context, for instance an inline-block
				//element or it is replaced, like an inline image renderer
				else if (child.establishesNewBlockFormattingContext() == true || child.isReplaced() == true)
				{
					//the child must first be laid out so that its width
					//and height are known
					child.layout(true, layoutState);
					
					//those element generate only one inline box so
					//that they can be inserted in an inline formatting
					var childInlineBox:InlineBox = child.inlineBoxes[0];
					
					//set the bounds of the inline box and its margins
					childInlineBox.bounds.height = child.bounds.height;
					childInlineBox.bounds.width = child.bounds.width;
					childInlineBox.marginLeft = child.coreStyle.usedValues.marginLeft;
					childInlineBox.marginRight = child.coreStyle.usedValues.marginRight;
					
					//insert the inline box, create a new line box if needed to hold the inline box
					var lineIsFull:Bool = inlineFormattingData.lineBox.insert(childInlineBox, inlineFormattingData.inlineBox, false);
					
					if (lineIsFull == true)
					{
						layoutLineBox(inlineFormattingData, layoutState);
						inlineFormattingData.lineBox.insert(childInlineBox, inlineFormattingData.inlineBox, true);
					}
				}
				//here the child is an inline box renderer, which will create one inline box for each
				//line box its children are in
				else if (child.firstChild != null)
				{
					//the child must first be laid out so that
					//it computes its dimensions and font metrics
					child.layout(true, LayoutStateValue.NORMAL);
					
					//reset inline boxes before adding new ones
					child.inlineBoxes = new Array<InlineBox>();
					
					//create the first inline box for this inline box renderer
					var childInlineBox:InlineBox = new InlineBox(child);
					childInlineBox.lineBox = inlineFormattingData.lineBox;
					child.inlineBoxes.push(childInlineBox);
					
					var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
					
					//the first inline box created by an inline box renderer has its left margin and padding
					childInlineBox.marginLeft = childUsedValues.marginLeft;
					childInlineBox.paddingLeft = childUsedValues.paddingLeft;
					//the left margin and padding are added as an unbreakable width, as it can't be separated
					//from next inline box until a break opportunity occurs
					inlineFormattingData.lineBox.addUnbreakableWidth(childUsedValues.marginLeft + childUsedValues.paddingLeft);
					
					//attach the child inline box to its parent inline box to form the inline box tree for the current
					//line box
					inlineFormattingData.inlineBox.appendChild(childInlineBox);
					//current inline box is now the child
					inlineFormattingData.inlineBox = childInlineBox;
					
					//store the inline box renderer. Each time a new line box is created
					//by laying out a descandant of this inline box renderer, a new inline box
					//with a reference to this inline box renderer will be added to the new
					//line box. This way the inline box renderer will have one inline box
					//for each line box where it has descendant
					inlineFormattingData.openedElementRenderers.push(child);
					
					//format all the children of the inline box renderer recursively.
					//a reference to the last added inline box is returned, so that it can
					//be used as a starting point when laying out the siblings of the 
					//inline box renderer
					inlineFormattingData.inlineBox = doLayoutInlineChildrenAndFloats(child, inlineFormattingData, layoutState);
					
					//early exit if float was found as
					//inline formatting should be
					//restarted
					if (_floatFound == true)
					{
						return null;
					}
					
					//now that all of the descendant of the inline box renderer have been laid out,
					//remove the reference to this inline box renderer so that when a new line box
					//is created, no new inline box pointing to this inline box renderer are created
					inlineFormattingData.openedElementRenderers.pop();
					
					//The current inline box must also be set to the parent inline box so that no more
					//inline boxes are added to this inline box as it is done laying out its child inline boxes
					inlineFormattingData.inlineBox = inlineFormattingData.inlineBox.parentNode;
					
					//The right margin and padding is added to the last generated inline box of the current inline
					//box renderer
					var lastInLineBox:InlineBox = child.inlineBoxes[child.inlineBoxes.length - 1];
					lastInLineBox.marginRight = childUsedValues.marginRight;
					lastInLineBox.paddingRight = childUsedValues.paddingRight;
					inlineFormattingData.lineBox.addUnbreakableWidth(childUsedValues.marginRight + childUsedValues.paddingRight);
				}
			}
			
			child = child.nextSibling;
		}
	
		return inlineFormattingData.inlineBox;
	}
	
	/**
	 * Update the bounds, relative top the containing
	 * block (this) of all the normal flow inline
	 * children
	 */
	private function updateInlineChildrenBounds(elementRenderer:ElementRenderer):Void
	{
		//loop in all inline children
		var child:ElementRenderer = elementRenderer.firstChild;
		while(child != null)
		{
			//only compute bounds of normal flow children (no float and no absolut positioned)
			if ((child.isPositioned() == false || child.isRelativePositioned() == true) && child.isFloat() == false)
			{
				//recurse down the rendering tree
				//if the child establishes a new formatting context, it is an inline-block which
				//takes of its own layout
				if (child.firstChild != null && child.establishesNewBlockFormattingContext() == false)
				{
					updateInlineChildrenBounds(child);
				}
				
				//reset bounds of child
				child.bounds.width = 0;
				child.bounds.height = 0;
				child.bounds.x = 50000;
				child.bounds.y = 50000;
				
				//bounds of child is bounds of all its inline boxes, which 
				//might be any number of inline boxes for inline container
				//or just one for inline-block or replaced elements
				var inlineBoxesLength:Int = child.inlineBoxes.length;
				
				//if the child has no inline box, reset
				//bounds
				if (inlineBoxesLength == 0)
				{
					child.bounds.x = 0;
					child.bounds.y = 0;
				}
				
				for (i in 0...inlineBoxesLength)
				{
					var inlineBox:InlineBox = child.inlineBoxes[i];
			
					//inlineBox bounds are relative to their line box, so the
					//x and y of the line box needs to be added to get the inline
					//box bounds in the space of the containing block
					_inlineBoxGlobalBounds.width = inlineBox.bounds.width;
					_inlineBoxGlobalBounds.height = inlineBox.bounds.height;
					
					if (inlineBox.lineBox != null)
					{
						_inlineBoxGlobalBounds.x = inlineBox.bounds.x + inlineBox.lineBox.bounds.x;
						_inlineBoxGlobalBounds.y = inlineBox.bounds.y + inlineBox.lineBox.bounds.y;
					}
					
					
					GeomUtils.addBounds(_inlineBoxGlobalBounds, child.bounds);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE MARGIN COLLAPSING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function collapseTopMarginWithFirstChildTopMargin():Bool
	{ 
		//if there is no normal flow child, can't collapse
		if (firstNormalFlowChild == null)
		{
			return false;
		}
		
		//margin can only collapse with block level elements
		if (firstNormalFlowChild.isBlockContainer() == false)
		{
			return false;
		}
		
		//margin of block formatting root don't collapse with
		//children's margin
		if (establishesNewBlockFormattingContext() == true)
		{
			return false;
		}
		
		//if padding prevent margins from adjoining, they can't collapse
		if (coreStyle.usedValues.paddingTop != 0 || firstNormalFlowChild.coreStyle.usedValues.paddingTop != 0)
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * same as collapseTopMarginWithFirstChildTopMargin
	 * for bottom margin
	 * 
	 * TODO : implement
	 */
	override private function collapseBottomMarginWithLastChildBottomMargin():Bool
	{ 
		return false;
	}
	
	/**
	 * Return wether line boxes or block box descandant have
	 * a combined height of 0
	 */
	override private function hasZeroHeightChildren():Bool
	{
		//block establish an inline formatting
		if (childrenInline() == true)
		{
			//check wether on the line box has a non-zero
			//height
			var lineBoxesLength:Int = lineBoxes.length;
			for (i in 0...lineBoxesLength)
			{
				if (lineBoxes[i].bounds.height > 0)
				{
					return false;
				}
			}
		}
		//block establish or participate in block formatting
		else
		{
			//TODO : might not be enough, should also check if all
			//chidren margin collapse
			return bounds.height == 0;
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as BlockBoxRenderer can also create a new layer
	 * if the overflow x or y style value is different from visible
	 */
	override public function createOwnLayer():Bool
	{
		//check first wether it should create a new layer
		//anyway
		var createOwnLayer:Bool = super.createOwnLayer();
		
		if (createOwnLayer == true)
		{
			return true;
		}
		
		return coreStyle.canAlwaysOverflow != true;
	}
	
	/**
	 * Determine wether the ElementRenderer
	 * establishes a new block formatting context for
	 * its children or participate in its
	 * parent block formatting context
	 */
	override public function establishesNewBlockFormattingContext():Bool
	{
		//floats always establishes new block formatting context
		if (coreStyle.isFloat == true)
		{
			return true;
		}
		//block box renderer which may hide their overflowing
		//children always start a new block formatting context
		else if (coreStyle.canAlwaysOverflow == false)
		{
			return true;
		}
		//positioned element which are not relative always establishes new block context
		else if (coreStyle.isPositioned == true && coreStyle.isRelativePositioned == false)
		{
			return true;
		}
		else if (coreStyle.isInlineBlock == true)
		{
			return true;
		}
		
		//in the other cases, the block particpates in its parent's
		//block formatting context
		
		return false;
	}
	
	override public function isBlockContainer():Bool
	{
		return true;
	}
	
	/**
	 * Determine wether the children of this block box
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * @return true if at least one child is inline level
	 */
	override public function childrenInline():Bool
	{	
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			if (child.isInlineLevel() == true)
			{
				//floated and absolutely positioned element are not taken into
				//account
				if (child.isFloat() == false)
				{
					if (child.isAbsolutelyPositioned() == false)
					{
						return true;
					}
				}
			}
			
			child = child.nextSibling;
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as a block box renderer might be rendered as if
	 * it creates its own layer, based on its computed styles
	 * value
	 */
	override private function rendersAsIfCreateOwnLayer():Bool
	{
		if (coreStyle.isInlineBlock)
		{
			return true;
		}
		else if (coreStyle.isFloat == true)
		{
			return true;
		}
		
		return false;
	}
	
	/**
	 * Overriden, has if this block box renderer has its own
	 * layer, it must not use the scrollLeft and scrollTop
	 * of its layer when rendering background, as they
	 * should only apply to child element renderers and layers
	 */
	override private function getBackgroundBounds(scrollOffset:PointVO):RectangleVO
	{
		var backgroundBounds:RectangleVO = super.getBackgroundBounds(scrollOffset);
		
		if (_hasOwnLayer == true)
		{
			backgroundBounds.x += layerRenderer.scrollLeft;
			backgroundBounds.y += layerRenderer.scrollTop;
		}
		
		return backgroundBounds;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the x and y offset between a target and source
	 * block box
	 */
	private function getBlockBoxesOffset(target:BlockBoxRenderer, source:BlockBoxRenderer):PointVO
	{
		var offset:PointVO = new PointVO(0, 0);
		
		var parent:ElementRenderer = target;
		while (parent != null)
		{
			offset.x += parent.bounds.x;
			offset.y += parent.bounds.y;
			
			if (parent == source)
			{
				return offset;
			}
			
			parent = parent.parentNode;
			
		}
		
		return offset;
	}
	
	/**
	 * Returns the ancestor block box formatting context root into
	 * which this block box participates
	 */
	private function getNearestBlockFormattingContextRoot():BlockBoxRenderer
	{
		var parent:ElementRenderer = this;
		
		while (parent != null)
		{
			if (parent.establishesNewBlockFormattingContext() == true)
			{
				return cast(parent);
			}
			
			parent = parent.parentNode;
		}
		
		return cast(parent);
	}
	
}