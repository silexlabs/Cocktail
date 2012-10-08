/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Node;
import cocktail.core.dom.NodeBase;
import cocktail.core.event.TransitionEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.InlineFormattingContext;
import cocktail.core.linebox.LineBox;
import cocktail.core.animation.Animator;
import cocktail.core.animation.Transition;
import cocktail.core.geom.GeomData;
import haxe.Stack;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSConstants;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.renderer.RendererData;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.css.CSSData;


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
	public var bounds(get_bounds, null):RectangleVO;
	
	/**
	 * Holds the current 
	 * bounds of the children
	 */
	private var _childrenBounds:RectangleVO;
	
	/**
	 * The bounds of the ElementRenderer in the space of the Window.
	 * 
	 * Returns the
	 * relevant global bounds for an ElementRenderer. For instance
	 * if the ElementRenderer uses the normal flow, then its bounds
	 * will be used to determine its global bounds whereas if it
	 * is absolutely positioned, it will use its positioned bounds
	 */
	public var globalBounds(get_globalBounds, null):RectangleVO;
	
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
	 */
	public var scrollableBounds(get_scrollableBounds, null):RectangleVO;
	
	/**
	 * This is the position of the top left padding box corner of the 
	 * containing block of this ElementRenderer in the Window space.
	 * This is used to render elements using the normal flow.
	 * 
	 * When added to the x and y bounds of the ElementRenderer, 
	 * it gives the global x and y of the ElementRenderer
	 */
	public var globalContainingBlockOrigin:PointVO;
	
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
	public var positionedOrigin:PointVO;
	
	/**
	 * This is the position of the top left padding box corner
	 * of the first positioned ancestor of this ElementRenderer
	 * in the Window space.
	 * 
	 * It is used when this ElementRenderer
	 * is absolutely positioned.
	 */
	public var globalPositionnedAncestorOrigin:PointVO;
	
	/**
	 * The total of all the x and y scroll
	 * applied to the parent of this ElementRenderer
	 */
	public var scrollOffset:PointVO;
	
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
	 * the establishesNewStackingContext Method ? + doc is false
	 */
	private var _hasOwnLayer:Bool;
	
	/**
	 * Wether the layer renderer for this element renderer
	 * should be re-instantiated and re-attached to the
	 * layer render tree. Happens for instance, when the 
	 * 'position' style of the element renderer's html
	 * element changes and requires the element renderer
	 * to have its own layer renderer
	 */
	private var _needsLayerRendererUpdate:Bool;
	
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
		
		initCoreStyle();
		_hasOwnLayer = false;
		_wasPositioned = false;
		_needsLayerRendererUpdate = true;
		
		bounds = new RectangleVO();
		
		globalBounds = new RectangleVO();
		
		scrollOffset = new PointVO(0.0, 0.0);
		
		positionedOrigin = new PointVO(0.0, 0.0);
		
		globalPositionnedAncestorOrigin = new PointVO(0.0, 0.0); 
		
		globalContainingBlockOrigin = new PointVO(0.0, 0.0);
		
		scrollableBounds = new RectangleVO();
		
		_childrenBounds = new RectangleVO();
		
		lineBoxes = new Array<LineBox>();
	}
	
	/**
	 * clean-up method
	 */
	public function dispose():Void
	{
		domNode = null;
		coreStyle = null;
		
		bounds = null;
		globalBounds = null;
		scrollOffset = null;
		positionedOrigin = null;
		globalPositionnedAncestorOrigin = null;
		globalContainingBlockOrigin = null;
		layerRenderer = null;
		
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			lineBoxes[i].dispose();
		}
		
		lineBoxes = null;
	}
	
	/**
	 * Retrieve a reference to the dom 
	 * node style object
	 */
	private function initCoreStyle():Void
	{
		coreStyle = domNode.coreStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as when an ElementRenderer is appended, an init 
	 * method is called on it
	 */ 
	override public function appendChild(newChild:ElementRenderer):ElementRenderer
	{
		super.appendChild(newChild);
		
		newChild.addedToRenderingTree();
		invalidate(InvalidationReason.other);
		return newChild;
	}
	
	/**
	 * overriden as when an ElementRenderer is removed, a clean-up 
	 * method is called on it
	 */
	override public function removeChild(oldChild:ElementRenderer):ElementRenderer
	{
		oldChild.removedFromRenderingTree();
		
		super.removeChild(oldChild);
		invalidate(InvalidationReason.other);
		return oldChild;
	}
	
	/**
	 * Overriden as when an ElementRenderer is inserted, its
	 * init method should be called
	 */
	override public function insertBefore(newChild:ElementRenderer, refChild:ElementRenderer):ElementRenderer
	{
		super.insertBefore(newChild, refChild);
		
		//if the ref child is null, then the 
		//new child was inserted using appendChild,
		//which already calls the init method
		if (refChild == null)
		{
			return newChild;
		}
		
		newChild.addedToRenderingTree();
		invalidate(InvalidationReason.other);
		
		return newChild;
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
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the layer renderer of this
	 * element renderer has been invalidated
	 * and needs to be re-created before
	 * next rendering
	 */
	public function invalidateLayerRenderer():Void
	{
		_needsLayerRendererUpdate = true;
		
		switch(domNode.nodeType)
		{
			case DOMConstants.ELEMENT_NODE:
				var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
				htmlDocument.invalidationManager.invalidateLayerTree();
		}
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
			var globalBounds:RectangleVO = globalBounds;
			addedX = globalBounds.x;
			addedY = globalBounds.y;
		}
		
		//if the element is positioned, it must also add
		//its bounds to the global positioned origin
		if (isPositioned() == true)
		{
			var globalBounds:RectangleVO = globalBounds;
			addedPositionedX = globalBounds.x;
			addedPositionedY = globalBounds.y;
		}
		
		//TODO 1 : doc + this is a shortcut, should apply
		//to all elementRenderer whose containing block is a parent
		//of the scrolled BlockBoxRenderer.
		//computing scroll offset should probably be done at the
		//LayerRenderer level instead of in the ElementRenderer
		if (coreStyle.getKeyword(coreStyle.position) != FIXED)
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
			
			var childGlobalBounds:RectangleVO = child.globalBounds;
			
			//store the global bounds before update, to check if there
			//is any change. If there is, the child needs to be re-rendered
			var currentX:Float = childGlobalBounds.x;
			var currentY:Float = childGlobalBounds.y;
			var currentWidth:Float = childGlobalBounds.width;
			var currentHeight:Float = childGlobalBounds.height;
			
			child.globalContainingBlockOrigin.x = addedX;
			child.globalContainingBlockOrigin.y = addedY;
			
			child.globalPositionnedAncestorOrigin.x = addedPositionedX;
			child.globalPositionnedAncestorOrigin.y = addedPositionedY;
			
			child.scrollOffset.x = addedScrollX;
			child.scrollOffset.y = addedScrollY;
			
			//some subclass of element renderer need
			//to update there bounds, for instance inline
			//box renderer update their bounds to reflect
			//their content
			child.updateBounds();
			
			//make the child compute its new global bounds
			child.updateGlobalBounds();
			
			//if there was any change in the bounds of the child, its
			//layer is invalidated so that it gets re-painted on next
			//rendering
			if (currentX != childGlobalBounds.x ||
			currentY != childGlobalBounds.y ||
			currentWidth != childGlobalBounds.width ||
			currentHeight != childGlobalBounds.height)
			{
				child.layerRenderer.invalidateRendering();
			}
			
			//call the method recursively if the child has children itself
			if (child.hasChildNodes() == true)
			{
				child.setGlobalOrigins(addedX, addedY, addedPositionedX, addedPositionedY, addedScrollX, addedScrollY);
			}
		}
	}
	
	/**
	 * Update the bounds relative to the 
	 * containing block
	 */
	public function updateBounds():Void
	{
		//abstract
	}
	
	/**
	 * update the global bounds bounds of the ElementRenderer
	 * which are its bounds relative to the
	 * Window
	 */
	public function updateGlobalBounds():Void
	{
		var globalX:Float;
		var globalY:Float;
		
		var positionKeyword:CSSKeywordValue = coreStyle.getKeyword(coreStyle.position);
		
		//fixed positioned
		if (positionKeyword == FIXED)
		{
			//here it uses its static position for x
			if (coreStyle.isAuto(coreStyle.left) == true && coreStyle.isAuto(coreStyle.right) == true)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			//here it uses its position relative to the Window for x
			else
			{
				globalX = positionedOrigin.x;
			}
			//static position
			if (coreStyle.isAuto(coreStyle.top) == true && coreStyle.isAuto(coreStyle.bottom) == true)
			{
				globalY = globalContainingBlockOrigin.y + bounds.y;
			}
			else
			{
				globalY = positionedOrigin.y;
			}
		}
		//absolute positioned
		else if (positionKeyword == ABSOLUTE)
		{
			//static position for x
			if (coreStyle.isAuto(coreStyle.left) == true && coreStyle.isAuto(coreStyle.right) == true)
			{
				globalX = globalContainingBlockOrigin.x + bounds.x;
			}
			else
			{
				globalX = globalPositionnedAncestorOrigin.x + positionedOrigin.x;
			}
			//static position for y
			if (coreStyle.isAuto(coreStyle.top) == true && coreStyle.isAuto(coreStyle.bottom) == true)
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
		
		globalBounds.x = globalX;
		globalBounds.y = globalY;
		globalBounds.width = bounds.width;
		globalBounds.height = bounds.height;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Main method to update the layer tree.
	 * Traverse the rendering tree recursively
	 * until all of the layer render tree is
	 * updated
	 * 
	 * ElementRenderer with invalid layer renderer
	 * attach/detach them as necessary
	 * 
	 * Called by the document before rendering
	 * if the layer tree was invalidated since
	 * last rendering
	 * 
	 * TODO 1 : not optimised yet, no need to
	 * detach/attach all in most cases
	 */
	public function updateLayerRenderer():Void
	{
		if (_needsLayerRendererUpdate == true)
		{	
			//here the layer is consider updated
			_needsLayerRendererUpdate = false;
			//if the element renderer currently
			//doesn't have a layer, always attach it,
			//element renderer should always have a
			//layer when rendering
			if (layerRenderer == null)
			{
				attach();
				
				//return as attaching also attach all
				//the children
				return;
			}
			//else re-attach the layer if the state
			//of the layer changed, meaning the element
			//renderer is now supposed to have or no 
			//longer have its own layer
			else if (_hasOwnLayer != createOwnLayer())
			{
				detach();
				attach();
				return;
			}
			//else, if the element renderer has its own
			//layer, refresh its position in its parent child
			//node list
			else
			{
				if (createOwnLayer() == true)
				{
					parentNode.layerRenderer.insertBefore(layerRenderer, getNextLayerRendererSibling());
				}
			}
				
		}
		
		//update all the children if this element renderer
		//didn't do it already
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].updateLayerRenderer();
		}
	}
	
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
			childNodes[i].attach();
		}
	}
	
	/**
	 * Detach the LayerRenderer of this ElementRenderer from the LayerRenderer
	 * tree if necessary
	 */
	public function detach():Void
	{
		//first detach the LayerRenderer of all its children
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].detach();
		}
		
		if (layerRenderer != null)
		{
			detachLayer();
		}
	}
	
	/**
	 * Called by the document as part of the update of the
	 * rendering tree. Wraps element renderer in anonymous
	 * block if necessary by traversing all the 
	 * rendering tree. For instance if an element renderer
	 * has both inline and blocjk children, the inline children
	 * should be wrapped in anonymous blocks
	 * 
	 * Wrapping element renderer is only done by BlockBoxRenderer,
	 * see this class for more info
	 */
	public function updateAnonymousBlock():Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].updateAnonymousBlock();
		}
	}
	
	/**
	 * Called by the document when the line box
	 * trees belonging to block box element renderer
	 * establishing an inline formatting context
	 * needs to be updated
	 * 
	 * line boxes are generated for elements 
	 * participating in an inline formatting
	 * context
	 */
	public function updateLineBoxes():Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			childNodes[i].updateLineBoxes();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called by the parent ElementRenderer when
	 * this ElementRenderer is appended to the
	 * rendering tree
	 */
	private function addedToRenderingTree():Void
	{
		//retrieve containing block
		_containingBlock = getContainingBlock();
		registerWithContaininingBlock();
		
		//schedule update of layer renderer before
		//next rendering
		invalidateLayerRenderer();
	}
	
	/**
	 * Called by the parent ElementRenderer when
	 * this ElementRenderer is removed from the
	 * rendering tree
	 */
	private function removedFromRenderingTree():Void
	{
		//detach from layer render tree
		detach();
		
		//remove itself from containing block
		unregisterWithContainingBlock();
		_containingBlock = null;
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
		if (parentNode != null)
		{
			createLayer(parentNode.layerRenderer);
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
			parentNode.layerRenderer.removeChild(layerRenderer);
			_hasOwnLayer = false;
			layerRenderer.dispose();
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
	
	public function isTransparent():Bool
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
	
	public function isVisible():Bool
	{
		return true;
	}
	
	
	/**
	 * Determine wether this ElementRenderer creates a
	 * new LayerRenderer for itself or use the
	 * one of its parent
	 */
	public function createOwnLayer():Bool
	{
		return false;
	}
	
	/**
	 * Return the relative offset applied by this ElementRenderer
	 * when rendering. Only relatively positioned ElementRenderer
	 * have this offset
	 */
	public function getRelativeOffset():PointVO
	{
		var relativeOffset:PointVO = new PointVO(0.0, 0.0);
		
		//only relatively positioned ElementRenderer can have
		//an offset
		if (isRelativePositioned() == true)
		{
			//first try to apply the left offset of the ElementRenderer if it is
			//not auto
			if (coreStyle.isAuto(coreStyle.left) == false)
			{
				relativeOffset.x += coreStyle.usedValues.left;
			}
			//else the right offset,
			else if (coreStyle.isAuto(coreStyle.right) == false)
			{
				relativeOffset.x -= coreStyle.usedValues.right;
			}
			
			//if both left and right offset are auto, then the ElementRenderer uses its static
			//position (its normal position in the flow) and no relative offset needs to
			//be applied
		
			//same for vertical offset
			if (coreStyle.isAuto(coreStyle.top) == false)
			{
				relativeOffset.y += coreStyle.usedValues.top; 
			}
			else if (coreStyle.isAuto(coreStyle.bottom) == false)
			{
				relativeOffset.y -= coreStyle.usedValues.bottom; 
			}
		}
		
		return relativeOffset;
	}
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * Determine wether this ElementRenderer is rendered
	 * as if it started a layer itself. 
	 * 
	 * For instance, an ElementRenderer which doesn't start
	 * a layer but as a display of inline-block is rendered
	 * as if it created a new layer, but it won't try
	 * to render the child layers of its LayerRenderer.
	 * 
	 * TODO 3 : is this still necessary now that
	 * there is a disambiguation between layer and
	 * stacking context
	 */
	private function rendersAsIfCreateOwnLayer():Bool
	{
		return false;
	}
	
	/**
	 * Create a new LayerRenderer for this ElementRenderer or
	 * use the one from its parent
	 */
	private function createLayer(parentLayer:LayerRenderer):Void
	{
		if (createOwnLayer() == true)
		{
			doCreateLayer();
			parentLayer.insertBefore(layerRenderer, getNextLayerRendererSibling());
			_hasOwnLayer = true;
		}
		else
		{
			layerRenderer = parentLayer;
		}
	}
	
	/**
	 * Actually instantiate the layer whose
	 * type might vary based on the type
	 * of renderer
	 */
	private function doCreateLayer():Void
	{
		layerRenderer = new LayerRenderer(this);
	}
	
	/**
	 * Return the first next sibling which creates its own
	 * layer. It is used to know the index where to attach
	 * this element renderer's layer in the layer renderer
	 * tree. If there is no suvh sibling, it will be appended
	 * to its parent layer
	 * 
	 * @return a layer renderer or null if there is no next
	 * sibling with its own layer
	 */
	private function getNextLayerRendererSibling():LayerRenderer
	{
		var nextElementRendererSibling:ElementRenderer = nextSibling;
		if (nextSibling == null)
		{
			return null;
		}
		
		while (nextElementRendererSibling != null)
		{
			if (nextElementRendererSibling.layerRenderer != null)
			{
				if (nextElementRendererSibling.createOwnLayer() == true)
				{
					return nextElementRendererSibling.layerRenderer;
				}
			}
			
			nextElementRendererSibling = nextElementRendererSibling.nextSibling;
		}
		
		return null;
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
			if (coreStyle.getKeyword(coreStyle.position) == FIXED)
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
			//TODO 3 : this check was introduced for anonymous block.
			//when a positioned element is the descendant of an anonymous block
			//at the time where this method is first called, the anonymous block
			//is not attached to the rendering tree yet, so its parent is null.
			//Be sure that it doesn't cause trouble down the line
			if (parent.parentNode == null)
			{
				break;
			}
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
	 * Set the bounds of an array of linebox
	 * on a provided bounds object
	 */
	private function getLineBoxesBounds(lineBoxes:Array<LineBox>, bounds:RectangleVO):Void
	{
		//first reset the bounds
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			doGetBounds(lineBoxes[i].bounds, bounds);
		}
	}
	
	/**
	 * Set the bounds of an array of linebox
	 * on a provided bounds object
	 */
	private function getChildrenBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		//first reset the bounds
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			doGetBounds(lineBoxes[i].bounds, bounds);
		}
	}
	
	/**
	 * apply the bounds of a children to
	 * the global bounds
	 */
	private function doGetBounds(childBounds:RectangleVO, globalBounds:RectangleVO):Void
	{
		if (childBounds.x < globalBounds.x)
		{
			globalBounds.x = childBounds.x;
		}
		if (childBounds.y < globalBounds.y)
		{
			globalBounds.y = childBounds.y;
		}
		if (childBounds.x + childBounds.width > globalBounds.x + globalBounds.width)
		{
			globalBounds.width = childBounds.x + childBounds.width - globalBounds.x;
		}
		if (childBounds.y + childBounds.height  > globalBounds.y + globalBounds.height)
		{
			globalBounds.height = childBounds.y + childBounds.height - globalBounds.y;
		}
	}
	
	/**
	 * Traverse all the children recursively
	 * and apply their bounds to the
	 * target bounds
	 */
	private function doGetChildrenBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		var length:Int = rootElementRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = rootElementRenderer.childNodes[i];
			doGetBounds(child.bounds, bounds);
			if (child.hasChildNodes() == true)
			{
				doGetChildrenBounds(child, bounds);
			}
		}
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

	private function get_globalBounds():RectangleVO
	{
		return globalBounds;
	}
	
	/**
	 * Return the bounds of the ElementRenderer as they
	 * need to be to compute the scrollable bounds of its
	 * containing block
	 * 
	 * TODO 3 : should implement the case of absolutely 
	 * positioned children
	 */
	private function get_scrollableBounds():RectangleVO
	{
		//if the elementRenderer is not relatively positioned,
		//the bounds are the same as the regular bounds
		if (isRelativePositioned() == false)
		{
			return bounds;
		}
		
		//else the bounds with the relative offset applied to them
		//are returned
		var relativeOffset:PointVO = getRelativeOffset();
		var bounds:RectangleVO = this.bounds;
		
		scrollableBounds.x = bounds.x + relativeOffset.x;
		scrollableBounds.y = bounds.y + relativeOffset.y;
		scrollableBounds.width = bounds.width;
		scrollableBounds.height = bounds.height;
		
		return scrollableBounds;
	}
	
	private function get_bounds():RectangleVO
	{
		return bounds;
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