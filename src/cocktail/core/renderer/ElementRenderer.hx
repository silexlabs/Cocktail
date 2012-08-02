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
import cocktail.port.GraphicsContext;
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
	 * The total of all the x and y scroll
	 * applied to the parent of this ElementRenderer
	 */
	public var scrollOffset:PointData;
	
	/**
	 * A reference to the Node in the DOM tree
	 * which created this ElementRenderer. It might
	 * be an HTMLElement or a Text node
	 * 
	 * TODO IMPORTANT : for now HTMLElement as event
	 * Text inherits from HTMLElement in haxe JS API,
	 * shouldn't be so
	 */
	public var domNode(default, null):HTMLElement;
	
	/**
	 * A reference to the coreStyle from which
	 * the styles of this ElementRenderer are retrieved
	 */
	public var coreStyle:CoreStyle;
	
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
	 * flag similar to the above. When an ElementRenderer is attached, if it
	 * is positioned, it registers itself with its first positioned ancestor.
	 * This flasg is there to ensure that, when detached, the ElementRenderer
	 * unregisters itself with its first positioned ancestor, even if the 
	 * detachement was cause by a change to its display style
	 */
	private var _wasPositioned:Bool;
	
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

	/**
	 * A reference to the containing block of this
	 * ElementRenderer, which might be its parent,
	 * its first positioned ancestor or the initial
	 * block renderer based on its positioning
	 * scheme
	 */
	private var _containingBlock:FlowBoxRenderer;
	
	/**
	 * class constructor. init class attribute
	 */
	public function new(domNode:HTMLElement) 
	{
		super();

		this.domNode = domNode;
		
		_hasOwnLayer = false;
		_wasPositioned = false;
		
		bounds = {
			x:0.0,
			y:0.0,
			width : 0.0,
			height: 0.0
		}
		
		scrollOffset = {
			x:0.0,
			y:0.0
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
		
		
		lineBoxes = new Array<LineBox>();
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
		
		newChild.attach();
		
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
		oldChild.detach();
		
		super.removeChild(oldChild);
		invalidate(InvalidationReason.other);
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Render this ElementRenderer using the provided
	 * graphic context as canvas
	 */
	public function render(parentGraphicContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * Render the scrollbars of this ElementRenderer if needed, only
	 * apply to BlockBoxElementRenderer
	 */
	public function renderScrollBars(graphicContext:GraphicsContext, windowWidth:Int, windowHeight:Int):Void
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
	 * @param	forceLayout force the layout of this
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
	public function setGlobalOrigins(addedX:Float, addedY:Float, addedPositionedX:Float, addedPositionedY:Float, addedScrollX:Float, addedScrollY:Float):Void
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
		
		//TODO 1 : doc + this is a shortcut, should apply
		//to all elementRenderer whose containing block is a parent
		//of the scrolled BlockBoxRenderer.
		//computing scroll offset should probably be done at the
		//LayerRenderer level instead of in the ElementRenderer
		if (coreStyle.computedStyle.position != fixed)
		{
			addedScrollX += scrollLeft;
			addedScrollY += scrollTop;
		}
		else
		{
			addedScrollX = 0;
			addedScrollY = 0;
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
			
			child.scrollOffset = {
				x: addedScrollX,
				y: addedScrollY
			}
			
			//call the method recursively if the child has children itself
			if (child.hasChildNodes() == true)
			{
				child.setGlobalOrigins(addedX, addedY, addedPositionedX, addedPositionedY, addedScrollX, addedScrollY);
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
		
		registerWithContaininingBlock();
	}
	
	/**
	 * Detach the LayerRenderer of this ElementRenderer from the LayerRenderer
	 * tree if necessary
	 */
	public function detach():Void
	{
		unregisterWithContainingBlock();
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
	// PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a LayerRenderer or use the one
	 * of the parent to be rendered
	 */
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
	
	/**
	 * Detach the LayerRenderer
	 */
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
		
		layerRenderer = null;
	}
	
	/**
	 * If the ElementRenderer is positioned, it
	 * must register itself with its first positioned
	 * ancestor
	 */
	private function registerWithContaininingBlock():Void
	{
		if (isPositioned() == true)
		{
			_containingBlock.addPositionedChildren(this);
			//flag remembering that the child was positioned at
			//attach time
			_wasPositioned = true;
		}
	}
	
	/**
	 * If the ElementRenderer was positioned when attached,
	 * it must unregister itself from its first positioned
	 * ancestor
	 */
	private function unregisterWithContainingBlock():Void
	{
		if (_wasPositioned == true)
		{
			_containingBlock.removePositionedChild(this);
			_wasPositioned = false;
		}
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	// Overriden by inheriting classes
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
	
	public function isTransformed():Bool
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
			if (coreStyle.computedStyle.position == fixed)
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
		return cast(domNode.ownerDocument.documentElement.elementRenderer);
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
	
	/**
	 * An ElementRenderer is invalidated for instance when one of its style value changes,
	 * or when a child is appended to it. When this happens, the ElementRenderer determinates
	 * the steps to take. 
	 * 
	 * For instance, a positioned ElementRenderer might need to also
	 * invalidate its first positioned ancestor when one of its style changes.
	 * 
	 * In most case, invalidating an ElementRenderer schedules an asynchronous re-layout
	 * and re-rendering with HTMLDocument.
	 * 
	 * This methods tries to optimise the number of computation that will be
	 * needed on next layout and rendering
	 * 
	 * @param	invalidationReason an enumeration of all the possible reason causing
	 * the invalidation
	 */
	public function invalidate(invalidationReason:InvalidationReason):Void
	{
		//abstract
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
		
		var bounds:RectangleData = this.bounds;
		
		//fixed positioned
		if (coreStyle.position == fixed)
		{
			//here it uses its static position for x
			if (coreStyle.left == PositionOffset.cssAuto && coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			//here it uses its position relative to the Window for x
			else
			{
				globalX = positionedOrigin.x;
			}
			//static position
			if (coreStyle.top == PositionOffset.cssAuto && coreStyle.bottom == PositionOffset.cssAuto)
			{
				globalY = globalContainingBlockOrigin.y + bounds.y;
			}
			else
			{
				globalY = positionedOrigin.y;
			}
		}
		//absolute positioned
		else if (coreStyle.position == absolute)
		{
			//static position for x
			if (coreStyle.left == PositionOffset.cssAuto && coreStyle.right == PositionOffset.cssAuto)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			else
			{
				globalX = globalPositionnedAncestorOrigin.x + positionedOrigin.x;
			}
			//static position for y
			if (coreStyle.top == PositionOffset.cssAuto && coreStyle.bottom == PositionOffset.cssAuto)
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
		var bounds:RectangleData = this.bounds;
		
		return {
			x: bounds.x + relativeOffset.x,
			y: bounds.y + relativeOffset.y,
			width: bounds.width,
			height: bounds.height
		};
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