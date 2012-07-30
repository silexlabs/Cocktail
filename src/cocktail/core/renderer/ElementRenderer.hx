/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Document;
import cocktail.core.dom.Node;
import cocktail.core.dom.NodeBase;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.linebox.LineBox;
import cocktail.port.NativeElement;
import cocktail.port.DrawingManager;
import cocktail.core.geom.GeomData;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.CSSConstants;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import cocktail.core.renderer.RendererData;
import cocktail.core.layer.LayerRenderer;
import haxe.Timer;


/**
 * This is the base class for element renderers.
 * An ElementRenderer is responsible for displaying
 * an element of the DOM tree on screen
 * 
 * A tree of ElementRenderers, paralleling the DOM tree
 * is built for rendering, starting at the HTMLBodyElement
 * 
 * Each element of the DOM tree which must be displayed
 * creates a corresponding ElementRenderer. For instance,
 * an HTML 'div' element by default will create a 
 * BlockBoxRenderer to be displayed. A TextNode in 
 * the DOM tree will create a TextRenderer in the 
 * rendering tree.
 * 
 * DOM tree elemtents which are not visual, for instance 
 * the 'head' HTML element don't create ElementRenderer
 * 
 * An ElementRenderer is associated with a CoreStyle object
 * which holds all of the styles used to render the
 * ElementRenderer.
 * 
 * An ElementRenderer knows how to layout itself, meaning
 * that once laid out it knows all its necessary bounds
 * to be rendered
 * 
 * It also knows how to render itself and will do it as many
 * times as necessary, each time is layout or rendering becomes
 * invalid
 * 
 * @author Yannick DOMINGUEZ
 */
class ElementRenderer extends NodeBase<ElementRenderer>
{
	/**
	 * The bounds of the ElementRenderer.
	 * 
	 * For ElementRenderers conforming to the box model, such
	 * as block or inline box, the width and height represents
	 * the border box of the element. For instance for width, it
	 * is the width from the left border to the right border, 
	 * including the borders width.
	 * 
	 * For ElementRenderers not conforming to the box model,
	 * for instance a TextRenderer, it is the width and height
	 * of their content. For instance, for a TextRenderer, the width
	 * will be the width of the bounds of its formatted TextLineBoxes
	 * 
	 * The x and y of the bounds are relative to the padding edge of
	 * the containing block of the ElementRenderer, which is the BlockBoxRenderer
	 * which established the formatting context this ElementRenderer 
	 * participates in.
	 */
	public var bounds(get_bounds, set_bounds):RectangleData;
	
	/**
	 * The bounds of the ElementRenderer in the space of the Window.
	 * 
	 * This is a utility read-only property which returns the
	 * relevant global bounds for an ElementRenderer. For instance
	 * if the ElementRenderer uses the normal flow, then its bounds
	 * will be used to determine its global bounds whereas if it
	 * is absolutely positioned, it will use its positioned bounds
	 */
	public var globalBounds(get_globalBounds, never):RectangleData;
	
	/**
	 * The scrollable bounds of the ElementRenderer in the space of the scrollable containing
	 * block used to determine the scrolling area of the containing block. 
	 * 
	 * The difference with the regular bounds is that any offset needed
	 * in the computation of scrollable bounds are added. 
	 * 
	 * For instance if the ElementRenderer is relatively positioned, its
	 * bounds once transformed with the relative offset are returned
	 * instead of its bounds in the flow like the regular bounds.
	 * 
	 * This is a utility read-only method
	 */
	public var scrollableBounds(get_scrollableBounds, never):RectangleData;
	
	/**
	 * This is the position of the top left padding box corner of the 
	 * containing block of this ElementRenderer in the Window space.
	 * This is used to render elements using the normal flow.
	 * 
	 * When added to the x and y bounds of the ElementRenderer, 
	 * it gives the global x and y of the ElementRenderer
	 */
	public var globalContainingBlockOrigin:PointData;
	
	/**
	 * This is the position of the top left corner of this
	 * ElementRenderer relative to the top left padding box
	 * corner of the first positioned ancestor of this
	 * ElementRenderer.
	 * 
	 * It is used when this ElementRenderer
	 * is absolutely positioned. When added to the global
	 * positioned ancestor origin, it gives the global
	 * positioned origin of the ElementRenderer
	 */
	public var positionedOrigin:PointData;
	
	/**
	 * This is the position of the top left padding box corner
	 * of the first positioned ancestor of this ElementRenderer
	 * in the Window space.
	 * 
	 * It is used when this ElementRenderer
	 * is absolutely positioned.
	 */
	public var globalPositionnedAncestorOrigin:PointData;
	
	/**
	 * A reference to the Node in the DOM tree
	 * which created this ElementRenderer. It might
	 * be an HTMLElement or a Text node
	 */
	public var node(default, null):HTMLElement;
	
	/**
	 * A reference to the coreStyle from which
	 * the styles of this ElementRenderer are retrieved
	 */
	private var _coreStyle:CoreStyle;
	public var coreStyle(get_coreStyle, set_coreStyle):CoreStyle;
	
	/**
	 * A reference to the LayerRenderer in the LayerRenderer tree
	 * responsible for rendering this ElementRenderer
	 */
	public var layerRenderer(default, null):LayerRenderer;
	
	/**
	 * A reference to the line boxes generated by this ElementRenderer. For
	 * instance for a Text renderer, an array of Text line box will be created.
	 * 
	 * For a block box which doesn't establish an inline formatting context,
	 * no line box will be created
	 */ 
	public var lineBoxes:Array<LineBox>;
	
	/**
	 * Determine wheter this ElementRenderer establishes its own
	 * stacking context (instantiates a new LayerRenderer)
	 * 
	 * TODO 2 : not very clean, should layerRenderer be null instead
	 * for ElementRenderer not starting a layer ? -> or should use 
	 * the establishesNewStackingContextMethod ? + doc is false
	 */
	private var _hasOwnLayer:Bool;
	
	/**
	 * flag similar to hasOwnLayer. When an ElementRenderer is auto z-index
	 * positioned, it must remove itself from its layerRenderer when detached.
	 * This flag ensures that it does, as if for instance the detachement was
	 * caused by the change of this ElementRenderer z-index from auto to an integer,
	 * without this flags, it won't know that it was auto z-index positioned 
	 * at the time of detachement
	 */
	private var _wasAutoZIndexPositioned:Bool;
	
	/**
	 * Stores all of the value of styles once computed.
	 * For example, if a size is set as a percentage, it will
	 * be stored once computed to pixels into this structure
	 */
	public var computedStyle(getComputedStyle, setComputedStyle):ComputedStyle;
	
	/**
	 * get/set the scrolling in the x axis of this ElementRenderer.
	 */
	public var scrollLeft(get_scrollLeft, set_scrollLeft):Float;
	
	/**
	 * get/set the scrolling in the y axis of this ElementRenderer
	 */
	public var scrollTop(get_scrollTop, set_scrollTop):Float;
	
	/**
	 * get the larger width between the ElementRenderer's and its children
	 * width
	 * 
	 * TODO 3 : does it mean that scrollBounds should also be computed for
	 * this ElementRenderer ? renamed as childrenBounds ?
	 * check http://dev.w3.org/csswg/cssom-view/#dom-element-scrollwidth
	 */
	public var scrollWidth(get_scrollWidth, never):Float;
	
	/**
	 * get the larger height between the ElementRenderer's and its children
	 * height
	 */
	public var scrollHeight(get_scrollHeight, never):Float;
	
	private var _needsLayout:Bool;
	
	private var _childrenNeedLayout:Bool;
	
	private var _positionedChildrenNeedLayout:Bool;
	
	private var _needsRendering:Bool;
	
	private var _childrenNeedRendering:Bool;
	
	private var _needsVisualEffectsRendering:Bool;

	private var _containingBlock:FlowBoxRenderer;
	
	
	/**
	 * class constructor. init class attribute
	 */
	public function new(node:HTMLElement) 
	{
		super();

		this.node = node;
		
		
		_hasOwnLayer = false;
		_wasAutoZIndexPositioned = false;
		
		bounds = {
			x:0.0,
			y:0.0,
			width : 0.0,
			height: 0.0
		}
		
		positionedOrigin = {
			x:0.0,
			y:0.0
		}
		
		globalPositionnedAncestorOrigin = {
			x:0.0,
			y:0.0
		}
		
		globalContainingBlockOrigin = {
			x:0.0,
			y:0.0
		}
		
		_needsRendering = true;
		_childrenNeedRendering = true;
		_needsLayout = true;
		_childrenNeedLayout = true;
		_positionedChildrenNeedLayout = true;
		_needsVisualEffectsRendering = true;
		
		lineBoxes = new Array<LineBox>();
	}
	
	/**
	 * clean-up method
	 * 
	 * TODO 1 : when setting to null, in flash, don't
	 *	dereference but instead set the actual object to null
	 */
	public function dispose():Void
	{
		//_lineBoxes = null;
		//_graphicsContext = null;
		//_coreStyle = null;
		//_layerRenderer = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as when an ElementRenderer is appended, it must be attached
	 * to the LayerRenderer tree
	 */
	override public function appendChild(newChild:ElementRenderer):ElementRenderer
	{
		super.appendChild(newChild);
		
		var elementRendererChild:ElementRenderer = newChild;
		elementRendererChild.attach();
		
		invalidate(InvalidationReason.other);
		return newChild;
	}
	
	
	/**
	 * overriden as when an ElementRenderer is removed, it must be
	 * removed from the LayerRenderer tree
	 */
	override public function removeChild(oldChild:ElementRenderer):ElementRenderer
	{
		//must happen before calling super, else the ElementRenderer
		//won't have a parent anymore
		var elementRendererChild:ElementRenderer = oldChild;
		elementRendererChild.detach();
		
		super.removeChild(oldChild);
		invalidate(InvalidationReason.other);
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Recursively start pending animation
	 */
	public function startPendingAnimation():Bool
	{
		return doStartPendingAnimation(this);
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ANIMATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * start pending animations of self and of all children 
	 */
	private function doStartPendingAnimation(elementRenderer:ElementRenderer):Bool
	{
		var atLeastOneAnimationStarted:Bool = false;

		var animationStarted:Bool = elementRenderer.coreStyle.startPendingAnimations();

		if (animationStarted == true)
		{
			atLeastOneAnimationStarted = true;
		}

		for (i in 0...childNodes.length)
		{
			var animationStarted:Bool = childNodes[i].startPendingAnimation();

			if (animationStarted == true)
			{
				atLeastOneAnimationStarted = true;
			}
		}

		return atLeastOneAnimationStarted;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Render this ElementRenderer using the provided
	 * graphic context as canvas
	 */
	public function render(parentGraphicContext:NativeElement, forceRendering:Bool):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/*
	 * Layout this ElementRenderer so that it knows its
	 * bounds and can be rendered to the screen
	 * 
	 * @param forceLayout force the layout of this
	 * ElementRenderer and of its children
	 */ 
	public function layout(forceLayout:Bool):Void
	{	
		//abstract
	}

	/**
	 * Set the global bounds (relative to the window) of all the elements of the rendering tree, by
	 * traversing it recursively
	 * 
	 * @param	addedX the added x position for the normal flow
	 * @param	addedY the added y position for the normal flow
	 * @param	addedPositionedX the added X position for positioned elements
	 * @param	addedPositionedY the added Y position for positioned elements
	 */
	public function setGlobalOrigins(addedX:Float, addedY:Float, addedPositionedX:Float, addedPositionedY:Float):Void
	{
		//if the element establishes a new formatting context, then its
		//bounds must be added to the global x and y bounds for the normal flow
		if (establishesNewFormattingContext() == true)
		{
			var globalBounds:RectangleData = globalBounds;
			addedX = globalBounds.x;
			addedY = globalBounds.y;
		}
		
		//if the element is positioned, it must also add
		//its bounds to the global positioned origin
		if (isPositioned() == true)
		{
			var globalBounds:RectangleData = globalBounds;
			addedPositionedX = globalBounds.x;
			addedPositionedY = globalBounds.y;
		}
		
		//for its child of the element
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			
			child.globalContainingBlockOrigin = {
				x: addedX,
				y : addedY
			}
			
			child.globalPositionnedAncestorOrigin = {
				x: addedPositionedX,
				y : addedPositionedY
			}
			
			//call the method recursively if the child has children itself
			if (child.hasChildNodes() == true)
			{
				child.setGlobalOrigins(addedX, addedY, addedPositionedX, addedPositionedY);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach the LayerRenderer of this ElementRenderer
	 * to the LayerRenderer tree so that it can be rendered
	 */
	public function attach():Void
	{
		attachLayer();
		
		//the ElementRenderer is attached to the LayerRenderer
		//tree and must now also attach its children
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			child.attach();
		}
		
		_containingBlock = getContainingBlock();
		
		attachContaininingBlock();
	}
	
	/**
	 * Detach the LayerRenderer of this ElementRenderer from the LayerRenderer
	 * tree if necessary
	 */
	public function detach():Void
	{
		detachContainingBlock();
		_containingBlock = null;
		
		//first detach the LayerRenderer of all its children
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = childNodes[i];
			child.detach();
		}
		
		detachLayer();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRVIATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function attachLayer():Void
	{
		//create the LayerRenderer if needed
		if (layerRenderer == null)
		{
			if (parentNode != null)
			{
				var parent:ElementRenderer = parentNode;
				if (parent.layerRenderer != null)
				{
					createLayer(parent.layerRenderer);
				}
			}
		}
	}
	
	private function detachLayer():Void
	{
		//only detach the LayerRenderer if this ElementRenderer
		//created it, else it will be detached by the ElementRenderer
		//which created it when detached
		if (_hasOwnLayer == true)
		{
			var parent:ElementRenderer = parentNode;
			parent.layerRenderer.removeChild(layerRenderer);
			_hasOwnLayer = false;
		}
		//else if the ElementRenderer was auto z-index positioned when attached,
		//it means that it was added to the LayerRenderer
		//as a auto positioned child and must now be removed from it
		else if (_wasAutoZIndexPositioned == true)
		{
			//TODO 3 : is LayerRenderer supposed to be null ?, detachLayer seems
			//to be called before attachLayer in some case, shouldn't arrive here
			//if it does
			if (layerRenderer != null)
			{
				layerRenderer.removeAutoZIndexChildElementRenderer(this);
			}
			_wasAutoZIndexPositioned = false;
		}
		
		layerRenderer = null;
	}
	
	private function attachContaininingBlock():Void
	{
		//TODO 2 : shouldn't be applied to Scrollbar, or scrollbar ContainingBlock
		//should always be the parent block box
		//if the ElementRenderer is positioned, it registers itself
		//with its first positioned ancestor
		if (isPositioned() == true)
		{
			_containingBlock.addPositionedChildren(this);
		}
	}
	
	private function detachContainingBlock():Void
	{
		//the ElementRenderer tries to unregister itself
		//form its containing block, won't have any effect
		//if the ElementRenderer is not positionned
		//
		//TODO 2 : shouldn't always call it but won't work if the detachement
		//was caused by the change of the position style
		_containingBlock.removePositionedChild(this);
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	// Overriden by inheriting classes
	// TODO 3 : should copy most doc from BoxRenderer
	////////////////////////////////
	
	public function isVerticallyScrollable(scrollOffset:Int):Bool
	{
		return false;
	}
	
	public function isHorizontallyScrollable(scrollOffset:Int):Bool
	{
		return false;
	}
	
	public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	public function isScrollBar():Bool
	{
		return false;
	}
	
	public function isFloat():Bool
	{
		return false;
	}
	
	public function isPositioned():Bool
	{
		return false;
	}
	
	public function isInlineLevel():Bool
	{
		return false;
	}
	
	public function isReplaced():Bool
	{
		return false;
	}
	
	public function isText():Bool
	{
		return false;
	}
	
	public function isRelativePositioned():Bool
	{
		return false;
	}
	
	public function isBlockContainer():Bool
	{
		return false;
	}
	
	public function childrenInline():Bool
	{
		return false;
	}
	
	public function isAnonymousBlockBox():Bool
	{
		return false;
	}
	
	/**
	 * Determine wether this ElementRenderer creates a
	 * new LayerRenderer for itself or use the
	 * one of its parent
	 */
	public function establishesNewStackingContext():Bool
	{
		return false;
	}
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return the relative offset applied by this ElementRenderer
	 * when rendering. Only relatively positioned ElementRenderer
	 * have this offset
	 */
	private function getRelativeOffset():PointData
	{
		var relativeOffset:PointData = { x:0.0, y:0.0 };
		
		//only relatively positioned ElementRenderer can have
		//an offset
		if (isRelativePositioned() == true)
		{
			//first try to apply the left offset of the ElementRenderer if it is
			//not auto
			if (coreStyle.left != PositionOffset.cssAuto)
			{
				relativeOffset.x += coreStyle.computedStyle.left;
			}
			//else the right offset,
			else if (coreStyle.right != PositionOffset.cssAuto)
			{
				relativeOffset.x -= coreStyle.computedStyle.right;
			}
			
			//if both left and right offset are auto, then the ElementRenderer uses its static
			//position (its normal position in the flow) and no relative offset needs to
			//be applied
		
			//same for vertical offset
			if (coreStyle.top != PositionOffset.cssAuto)
			{
				relativeOffset.y += coreStyle.computedStyle.top; 
			}
			else if (coreStyle.bottom != PositionOffset.cssAuto)
			{
				relativeOffset.y -= coreStyle.computedStyle.bottom; 
			}
		}
		
		return relativeOffset;
	}
	
	/**
	 * Determine wether this ElementRenderer is rendered
	 * as if it started a stacking context itself. 
	 * 
	 * For instance, an ElementRenderer which doesn't start
	 * a stacking context but as a display of inline-block is rendered
	 * as if it established a new stacking context, but it won't try
	 * to render the child layers of its LayerRenderer.
	 */
	private function rendersAsIfEstablishingStackingContext():Bool
	{
		return false;
	}
	
	/**
	 * Determine wether this ElementRenderer is 
	 * both positioned and has an 'auto' z-index value,
	 * which influence the rendering order of its
	 * LayerRenderer
	 */
	private function isAutoZIndexPositioned():Bool
	{
		return false;
	}
	
	/**
	 * Create a new LayerRenderer for this ElementRenderer or
	 * use the one from its parent
	 */
	private function createLayer(parentLayer:LayerRenderer):Void
	{
		if (establishesNewStackingContext() == true)
		{
			layerRenderer = new LayerRenderer(this);
			parentLayer.appendChild(layerRenderer);
			_hasOwnLayer = true;
		}
		else
		{
			layerRenderer = parentLayer;
			
			//if the ElementRenderer is positioned with
			//an 'auto' z-index value, then it must be added
			//in a special array in its LayerRenderer has it will
			//be rendered during its own rendering phase
			if (isAutoZIndexPositioned() == true)
			{
				layerRenderer.insertAutoZIndexChildElementRenderer(this);
				
				//flag that this ElementRenderer was added as auto zindex child,
				//to be sure that it is removed when detach is called
				_wasAutoZIndexPositioned = true;
			}
		}
	}
	
	/**
	 * Get the containing block of the ElementRenderer, based
	 * on its positioning scheme
	 */
	private function getContainingBlock():FlowBoxRenderer
	{	
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			//for absolutely positioned fixed elements, the containing block
			//is the viewport
			if (computedStyle.position == fixed)
			{
				return getInitialContainingBlock();
			}
			//for absolutely positioned it is the first positoned
			//ancestor
			else
			{
				return getFirstPositionedAncestor();
			}
		}
		//for normal flow children, it is the first block
		//parent. 
		//
		//TODO 1 : what about inline box renderer ? should
		//return first block or first parent?
		else
		{
			return getFirstBlockContainer();
		}
	}
	
	/**
	 * Get the first parent which is positioned
	 */
	private function getFirstPositionedAncestor():FlowBoxRenderer
	{
		var parent:ElementRenderer = parentNode;
		while (parent.isPositioned() == false)
		{
			parent = parent.parentNode;
		}
		return cast(parent);
	}
	
	/**
	 * Get the viewport ElementRenderer
	 */
	private function getInitialContainingBlock():InitialBlockRenderer
	{
		return cast(node.ownerDocument.documentElement.elementRenderer);
	}
	
	/**
	 * Get the first block ancestor
	 */
	private function getFirstBlockContainer():FlowBoxRenderer
	{
		var parent:ElementRenderer = parentNode;
		while (parent.isBlockContainer() == false)
		{
			parent = parent.parentNode;
		}
		
		return cast(parent);
	}
	
	/**
	 * Determine the bounds of the children of this ElementRenderer
	 * in this ElementRenderer space
	 */
	private function getChildrenBounds(childrenBounds:Array<RectangleData>):RectangleData
	{
		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;

		
		var length:Int = childrenBounds.length;
		for (i in 0...length)
		{
			var childBounds:RectangleData = childrenBounds[i];
			if (childBounds.x < left)
			{
				left = childBounds.x;
			}
			if (childBounds.y < top)
			{
				top = childBounds.y;
			}
			if (childBounds.x + childBounds.width > right)
			{
				right = childBounds.x + childBounds.width;
			}
			if (childBounds.y + childBounds.height  > bottom)
			{
				bottom = childBounds.y + childBounds.height;
			}
		}
			
		
		
		bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
				
		//TODO 4 : need to implement better fix,
		//sould not be negative
		if (bounds.width < 0)
		{
			bounds.width = 0;
		}
		if (bounds.height < 0)
		{
			bounds.height = 0;
		}
				
		return bounds;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function invalidate(invalidationReason:InvalidationReason):Void
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
				_childrenNeedRendering = true;
				_needsRendering = true;
				_positionedChildrenNeedLayout = true;
				invalidateDocumentLayoutAndRendering();
				
			case InvalidationReason.backgroundImageLoaded:
				_needsRendering = true;
				invalidateDocumentRendering();
				
			case InvalidationReason.other:
				_needsLayout = true;
				_childrenNeedLayout = true;
				_childrenNeedRendering = true;
				_needsRendering = true;
				_positionedChildrenNeedLayout = true;
				invalidateContainingBlock(invalidationReason);
		}
	}
	
	public function childInvalidated(invalidationReason:InvalidationReason):Void
	{
		invalidate(invalidationReason);
	}
	
	public function positionedChildInvalidated(invalidationReason:InvalidationReason):Void
	{
		invalidate(invalidationReason);
	}
	
	private function invalidateContainingBlock(invalidationReason:InvalidationReason):Void
	{
		//TODO 1 : not supposed to happen but bug with scrollbars for now
		if (parentNode == null)
		{
			return;
		}
		
		var containingBlockInvalidationReason:InvalidationReason;
		
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
		
		if (isPositioned() == true && isRelativePositioned() == false)
		{
			_containingBlock.positionedChildInvalidated(containingBlockInvalidationReason);
		}
		else
		{
			_containingBlock.childInvalidated(containingBlockInvalidationReason);
		}
	}
	
	private function invalidateDocumentLayout():Void
	{
		var htmlDocument:HTMLDocument = cast(node.ownerDocument);
		htmlDocument.invalidateLayout();
	}
	
	private function invalidateDocumentRendering():Void
	{
		var htmlDocument:HTMLDocument = cast(node.ownerDocument);
		htmlDocument.invalidateRendering();
	}
	
	private function invalidateDocumentLayoutAndRendering():Void
	{
		var htmlDocument:HTMLDocument = cast(node.ownerDocument);
		htmlDocument.invalidateLayout();
		htmlDocument.invalidateRendering();
	}
	
	private function invalidatedStyle(styleName:String, invalidationReason:InvalidationReason):Void
	{
		switch (styleName)
		{
			case CSSConstants.LEFT_STYLE_NAME, CSSConstants.RIGHT_STYLE_NAME,
			CSSConstants.TOP_STYLE_NAME, CSSConstants.BOTTOM_STYLE_NAME:
				
				_needsRendering = true;
				if (isPositioned() == true && isRelativePositioned() == false)
				{
					_needsLayout = true;
					invalidateContainingBlock(invalidationReason);
				}
				else
				{
					invalidateDocumentRendering();
				}
				
			case CSSConstants.COLOR_STYLE_NAME, CSSConstants.FONT_FAMILY_STYLE_NAME, CSSConstants.FONT_SIZE_STYLE_NAME,
			CSSConstants.FONT_VARIANT_STYLE_NAME, CSSConstants.FONT_STYLE_STYLE_NAME, CSSConstants.FONT_WEIGHT_STYLE_NAME,
			CSSConstants.LETTER_SPACING_STYLE_NAME, CSSConstants.TEXT_TRANSFORM_STYLE_NAME, CSSConstants.WHITE_SPACE_STYLE_NAME:
				invalidateText();
				_needsLayout = true;
				_needsRendering = true;
				invalidateContainingBlock(invalidationReason);
			
			case CSSConstants.BACKGROUND_COLOR_STYLE_NAME, CSSConstants.BACKGROUND_CLIP_STYLE_NAME,
			CSSConstants.BACKGROUND_IMAGE_STYLE_NAME, CSSConstants.BACKGROUND_POSITION_STYLE_NAME,
			CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME, CSSConstants.BACKGROUND_REPEAT_STYLE_NAME,
			CSSConstants.BACKGROUND_SIZE_STYLE_NAME:
				_needsRendering = true;
				invalidateDocumentRendering();
				
			default:
				_needsLayout = true;
				_needsRendering = true;
				_childrenNeedRendering = true;
				invalidateDocumentRendering();
				invalidateContainingBlock(invalidationReason);
		
				
		}
	}
	
	private function invalidatedChildStyle(styleName:String, invalidationReason:InvalidationReason):Void
	{
		switch (styleName)
		{
			case CSSConstants.BACKGROUND_COLOR_STYLE_NAME, CSSConstants.BACKGROUND_CLIP_STYLE_NAME,
			CSSConstants.BACKGROUND_IMAGE_STYLE_NAME, CSSConstants.BACKGROUND_POSITION_STYLE_NAME,
			CSSConstants.BACKGROUND_ORIGIN_STYLE_NAME, CSSConstants.BACKGROUND_REPEAT_STYLE_NAME,
			CSSConstants.BACKGROUND_SIZE_STYLE_NAME:
			
			default:
				_needsLayout = true;
				_childrenNeedRendering = true;
				invalidateContainingBlock(invalidationReason);
				invalidateDocumentLayoutAndRendering();
		}
	}
	
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
				_childrenNeedRendering = true;
				invalidateDocumentLayoutAndRendering();
		}
	}
	
	/**
	 * Call when a style which require a re-layout
	 * of the text (such as font-size, fon-family...)
	 * is changed
	 */
	private function invalidateText():Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].invalidateText();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the bounds of the ElementRenderer relative to the
	 * Window, depending on its positioning scheme
	 */
	private function get_globalBounds():RectangleData
	{
		var globalX:Float;
		var globalY:Float;
		
		//fixed positioned
		if (_coreStyle.position == fixed)
		{
			//here it uses its static position for x
			if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			//here it uses its position relative to the Window for x
			else
			{
				globalX = positionedOrigin.x;
			}
			//static position
			if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
			{
				globalY = globalContainingBlockOrigin.y + bounds.y;
			}
			else
			{
				globalY = positionedOrigin.y;
			}
		}
		//absolute positioned
		else if (_coreStyle.position == absolute)
		{
			//static position for x
			if (_coreStyle.left == PositionOffset.cssAuto && _coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			else
			{
				globalX = globalPositionnedAncestorOrigin.x + positionedOrigin.x;
			}
			//static position for y
			if (_coreStyle.top == PositionOffset.cssAuto && _coreStyle.bottom == PositionOffset.cssAuto)
			{
				globalY = globalContainingBlockOrigin.y + bounds.y;
			}
			else
			{
				globalY = globalPositionnedAncestorOrigin.y + positionedOrigin.y;
			}
		}
		//here the ElementRenderer uses the normal flow
		else
		{
			globalX = globalContainingBlockOrigin.x + bounds.x;
			globalY = globalContainingBlockOrigin.y + bounds.y;
		}
		
		return {
			x:globalX,
			y:globalY,
			width:bounds.width,
			height:bounds.height
		}
	}
	
	/**
	 * Return the bounds of the ElementRenderer as they
	 * need to be to compute the scrollable bounds of its
	 * containing block
	 * 
	 * TODO 3 : should implement the case of absolutely 
	 * positioned children
	 */
	private function get_scrollableBounds():RectangleData
	{
		//if the elementRenderer is not relatively positioned,
		//the bounds are the same as the regular bounds
		if (isRelativePositioned() == false)
		{
			return bounds;
		}
		
		//else the bounds with the relative offset applied to them
		//are returned
		var relativeOffset:PointData = getRelativeOffset();
		var bounds:RectangleData = get_bounds();
		
		return {
			x: bounds.x + relativeOffset.x,
			y: bounds.y + relativeOffset.y,
			width: bounds.width,
			height: bounds.height
		};
	}
	
	private function getComputedStyle():ComputedStyle
	{
		return _coreStyle.computedStyle;
	}
	
	private function setComputedStyle(value:ComputedStyle):ComputedStyle
	{
		return _coreStyle.computedStyle = value;
	}
	
	private function get_coreStyle():CoreStyle
	{
		return _coreStyle;
	}
	 
	private function set_coreStyle(value:CoreStyle):CoreStyle
	{
		_coreStyle = value;
		return value;
	}
	
	private function get_bounds():RectangleData
	{
		return bounds;
	}
	
	private function set_bounds(value:RectangleData):RectangleData
	{
		return bounds = value;
	}
	
	private function get_scrollLeft():Float 
	{
		return 0;
	}
	
	private function set_scrollLeft(value:Float):Float 
	{
		return value;
	}
	
	private function get_scrollTop():Float 
	{
		return 0;
	}
	
	private function set_scrollTop(value:Float):Float 
	{
		return value;
	}
	
	private function get_scrollWidth():Float
	{
		return bounds.width;
	}
	
	private function get_scrollHeight():Float
	{
		return bounds.height;
	}
}