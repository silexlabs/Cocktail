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
import cocktail.core.geom.GeomUtils;
import cocktail.core.geom.Matrix;
import cocktail.core.linebox.InlineBox;

import cocktail.core.event.TransitionEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.animation.Animator;
import cocktail.core.animation.Transition;
import cocktail.core.geom.GeomData;
import cocktail.core.utils.FastNode;
import haxe.Stack;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSConstants;
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
class ElementRenderer extends FastNode<ElementRenderer>
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
	public var bounds(default, null):RectangleVO;
	
	/**
	 * The bounds of the ElementRenderer in the space of the document.
	 * 
	 * Returns the
	 * relevant global bounds for an ElementRenderer. For instance
	 * if the ElementRenderer uses the normal flow, then its bounds
	 * will be used to determine its global bounds whereas if it
	 * is absolutely positioned, it will use its positioned bounds
	 */
	public var globalBounds(default, null):RectangleVO;
	
	/**
	 * Those are the bounds of the element renderer used for hit testing,
	 * for instance when a mouse pointer hovers the document, those
	 * bounds are used to determine wheter this element renderer is under
	 * the mouse pointer.
	 * 
	 * Those bounds are the global bounds converted to the viewport space
	 * by adding the all the scroll offsets of ancestors layers, and
	 * all transformations matrix of ancestors layers. Those
	 * bounds are also clipped by all ancestors layer, as if a part
	 * of the element is not displayed, this part can't be hit-tested
	 */
	public var hitTestingBounds(default, null):RectangleVO;
	
	/**
	 * For absolutely positioned elements,
	 * this represents their x and y offset relative
	 * to their static containing block, which
	 * is the containing block they would have had
	 * if they weren't positioned. This origin
	 * is used when the left and right and/or top and
	 * bottom style are auto
	 */
	public var staticOrigin:PointVO;
	
	/**
	 * A reference to the Node in the DOM tree
	 * which created this ElementRenderer. It might
	 * be an HTMLElement or a Text node
	 * 
	 * TODO IMPORTANT : for now HTMLElement as even
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
	 * A reference to the inline boxes generated by this ElementRenderer. For
	 * instance for a Text renderer, an array of text inline box will be created.
	 * An inline box renderer will create as many inline box as there line boxes
	 * into which it has children
	 */ 
	public var inlineBoxes:Array<InlineBox>;
	
	/**
	 * Determine wheter this ElementRenderer establishes its own
	 * stacking context (instantiates a new LayerRenderer)
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
	 * is absolutely positioned, it registers itself with its first positioned ancestor.
	 * This flag is there to ensure that, when detached, the ElementRenderer
	 * unregisters itself with its first positioned ancestor, even if the 
	 * detachement was cause by a change to its display style
	 */
	private var _wasAbsolutelyPositioned:Bool;
	
	/**
	 * get/set the scrolling in the x axis of this ElementRenderer.
	 */
	public var scrollLeft(get_scrollLeft, set_scrollLeft):Float;
	
	/**
	 * get/set the scrolling in the y axis of this ElementRenderer
	 */
	public var scrollTop(get_scrollTop, set_scrollTop):Float;
	
	/**
	 * get the greater value between the element's content area 
	 * width and its scrollable content width
	 */
	public var scrollWidth(get_scrollWidth, never):Float;
	
	/**
	 * get the greater value between the element's content area 
	 * height and its scrollable content height
	 */
	public var scrollHeight(get_scrollHeight, never):Float;

	/**
	 * A reference to the containing block of this
	 * ElementRenderer, which might be its parent,
	 * its first positioned ancestor or the initial
	 * block renderer based on its positioning
	 * scheme
	 */
	public var containingBlock(default, null):FlowBoxRenderer;
	
	/**
	 * Return the first previous sibling belonging to the
	 * normal flow (not floatged or absolutely positioned)
	 * or null if no such sibling exists
	 */
	public var previousNormalFlowSibling(get_previousNormalFlowSibling, null):ElementRenderer;
	
	/**
	 * Return the first next sibling belonging to the
	 * normal flow (not floatged or absolutely positioned)
	 * or null if no such sibling exists
	 */
	public var nextNormalFlowSibling(get_nextNormalFlowSibling, null):ElementRenderer;
	
	/**
	 * Return the first child belonging to the
	 * normal flow (not floatged or absolutely positioned)
	 * or null if no such child exists
	 */
	public var firstNormalFlowChild(get_firstNormalFlowChild, null):ElementRenderer;
	
	/**
	 * Return the last child belonging to the
	 * normal flow (not floatged or absolutely positioned)
	 * or null if no such child exists
	 */
	public var lastNormalFlowChild(get_lastNormalFlowChild, null):ElementRenderer;
	
	/**
	 * Helper attribute, return wether
	 * this ElementRenderer is a replaced
	 * element, like an ImageRenderer
	 */
	public var isReplaced:Bool;
	
	/**
	 * Helper attribute, return wether
	 * this ElementRenderer is a 
	 * block box renderer
	 */
	public var isBlockContainer:Bool;
	
	/**
	 * Helper atribute, return wether
	 * this ElementRenderer is a TextRenderer
	 */
	public var isText:Bool;
	
	/**
	 * Wether this element renderer has at
	 * least one line box. It must be 
	 * a block box renderer with inline 
	 * children to have line boxes
	 */
	public var hasLineBoxes:Bool;
	
	/**
	 * class constructor. init class attribute
	 */
	public function new(domNode:HTMLElement) 
	{
		super();

		this.domNode = domNode;
		
		initCoreStyle();
		_hasOwnLayer = false;
		_wasAbsolutelyPositioned = false;
		_needsLayerRendererUpdate = true;
		
		bounds = new RectangleVO();
		
		globalBounds = new RectangleVO();
		
		staticOrigin = new PointVO(0.0, 0.0);
		
		hitTestingBounds = new RectangleVO();
		
		inlineBoxes = new Array<InlineBox>();
		
		isBlockContainer = false;
		isReplaced = false;
		isText = false;
		hasLineBoxes = false;
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
		staticOrigin = null;
		hitTestingBounds = null;
		layerRenderer = null;
		
		var length:Int = inlineBoxes.length;
		for (i in 0...length)
		{
			inlineBoxes[i].dispose();
		}
		
		inlineBoxes = null;
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
	override public function appendChild(newChild:ElementRenderer):Void
	{
		super.appendChild(newChild);
		
		newChild.addedToRenderingTree();
		invalidate();
	}
	
	/**
	 * overriden as when an ElementRenderer is removed, a clean-up 
	 * method is called on it
	 */
	override public function removeChild(oldChild:ElementRenderer):Void
	{
		oldChild.removedFromRenderingTree();
		
		super.removeChild(oldChild);
		invalidate();
	}
	
	/**
	 * Overriden as when an ElementRenderer is inserted, its
	 * init method should be called
	 */
	override public function insertBefore(newChild:ElementRenderer, refChild:ElementRenderer):Void
	{
		super.insertBefore(newChild, refChild);
		
		//if the ref child is null, then the 
		//new child was inserted using appendChild,
		//which already calls the init method
		if (refChild == null)
		{
			return;
		}
		
		newChild.addedToRenderingTree();
		invalidate();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HIT TESTING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the bounds of the element renderer used for
	 * hit testing. Update the whole rendering tree recursively
	 */
	public function updateHitTestingBounds():Void
	{
		
		//set initial value for hit testing bounds, start
		//with global bounds
		hitTestingBounds.x = globalBounds.x;
		hitTestingBounds.y = globalBounds.y;
		hitTestingBounds.width = globalBounds.width;
		hitTestingBounds.height = globalBounds.height;
		
		//if inline box renderer or text, add x and y
		//bounds of all inline boxes
		if (coreStyle.isInline == true || isText == true)
		{
			hitTestingBounds.x += bounds.x;
			hitTestingBounds.y += bounds.y;
		}
		
		//apply offset and matrix of layer to converted document bounds
		//to viewport bounds
		var scrollOffset:PointVO = layerRenderer.scrollOffset;
		hitTestingBounds.x -= scrollOffset.x;
		hitTestingBounds.y -= scrollOffset.y;
		
		//TODO 2 : for now, only translations supported, if layer
		//is rotated or scaled, it won't hit test properly
		var matrix:Matrix = layerRenderer.matrix;
		hitTestingBounds.x += matrix.e;
		hitTestingBounds.y += matrix.f;
		
		//if the element renderer is the root of its layer, then it
		//shouldn't use its scrollLeft and srollTop, which should only
		//apply to child element renderers and child layers
		if (_hasOwnLayer == true)
		{
			hitTestingBounds.x += layerRenderer.scrollLeft;
			hitTestingBounds.y += layerRenderer.scrollTop;
		}
		
		//clip the hit testing bounds with the clip rect of the layer, which
		//is also defined in viewport space
		GeomUtils.intersectBounds(layerRenderer.clipRect, hitTestingBounds, hitTestingBounds);
		
		//update hit test bounds of all element renderers
		var child:ElementRenderer = firstChild;
		while (child != null)
		{
			child.updateHitTestingBounds();
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Render this ElementRenderer using the provided
	 * graphic context as canvas
	 */
	public function render(parentGraphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		//abstract
	}
	
	/**
	 * update text elements used 
	 * for rendering
	 */
	public function updateText():Void
	{
		var child:ElementRenderer = firstChild;
		while (child != null)
		{
			child.updateText();
			child = child.nextSibling;
		}
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
	public function layout(forceLayout:Bool, layoutState:LayoutStateValue):Void
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
		//if is positioned, set the global position for its own children
		if (isPositioned() == true)
		{
			addedPositionedX = globalBounds.x;
			addedPositionedY = globalBounds.y;
		}
		//if is block container, set the normal flow position for its children
		if (isBlockContainer == true)
		{
			addedX = globalBounds.x + coreStyle.usedValues.paddingLeft;
			addedY = globalBounds.y + coreStyle.usedValues.paddingTop;
		}
		
		//for each child of the element
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			//set global bounds for absolutely positioned child
			if (child.isAbsolutelyPositioned())
			{
				setAbsolutelyPositionedGlobalOrigins(child, addedX, addedY, addedPositionedX, addedPositionedY);
			}
			//set global bounds for normal flow child
			else
			{
				child.globalBounds.x = addedX;
				child.globalBounds.y = addedY;
				
				//block level and replaced child also add their their own
				//offset relative to their containing block,
				//whereas non-replaced inline level child are represented 
				//by inline boxes which take care of this offset
				if (child.isInlineLevel() == false || child.isReplaced == true)
				{
					child.globalBounds.x += child.bounds.x;
					child.globalBounds.y += child.bounds.y;
				}
				//here the element is an inline-block whose bounds
				//matches the one inline box it generated during 
				//inline formatting
				else if (child.isBlockContainer == true)
				{
					child.globalBounds.x += child.bounds.x;
					child.globalBounds.y += child.bounds.y;
				}
			}
			
			//set global dimension for child
			child.globalBounds.width = child.bounds.width;
			child.globalBounds.height = child.bounds.height;
			
			//call the method recursively if the child has children itself
			if (child.firstChild != null)
			{
				child.setGlobalOrigins(addedX, addedY, addedPositionedX, addedPositionedY);
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the global bounds of an absolutely positioned
	 * element
	 */
	public function setAbsolutelyPositionedGlobalOrigins(elementRenderer:ElementRenderer, addedX:Float, addedY:Float, addedPositionedX:Float, addedPositionedY:Float):Void
	{
		var elementRendererCoreStyle:CoreStyle = elementRenderer.coreStyle;
		
		//here the element is fixed positioned (relative to the viewport)
		if (elementRendererCoreStyle.isFixedPositioned)
		{
			//if both left and right are auto, static position is used
			if (elementRendererCoreStyle.hasAutoLeft == true && elementRendererCoreStyle.hasAutoRight == true)
			{
				elementRenderer.globalBounds.x = addedX + elementRenderer.staticOrigin.x;
			}
			//else use own bounds, for fixed element, no need to add previous global bounds
			//as they are always positioned relative to the viewport
			else
			{
				elementRenderer.globalBounds.x = elementRenderer.bounds.x;
			}
			//same for vertical position
			if (elementRendererCoreStyle.hasAutoTop == true && elementRendererCoreStyle.hasAutoBottom == true)
			{
				elementRenderer.globalBounds.y = addedY + elementRenderer.staticOrigin.y;
			}
			else
			{
				elementRenderer.globalBounds.y = elementRenderer.bounds.y;
			}
		}
		//here the element is absolute positioned (relative to first positioned ancestor)
		else
		{
			//if left and right auto, use static position
			if (elementRendererCoreStyle.hasAutoLeft == true && elementRendererCoreStyle.hasAutoRight == true)
			{
				//add global normal flow position to static position
				elementRenderer.globalBounds.x = addedX + elementRenderer.staticOrigin.x;
			}
			//here uses bounds which are relative to first positioned ancestor
			else
			{
				//add previous positioned ancestor global position
				elementRenderer.globalBounds.x = addedPositionedX + elementRenderer.bounds.x;
			}
			//same for vertical position
			if (elementRendererCoreStyle.hasAutoTop == true && elementRendererCoreStyle.hasAutoBottom == true)
			{
				elementRenderer.globalBounds.y = addedY + elementRenderer.staticOrigin.y;
			}
			else
			{
				elementRenderer.globalBounds.y = addedPositionedY + elementRenderer.bounds.y;
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC MARGIN COLLAPSING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the top margin of an element which 
	 * might be the result of collapsing multiple
	 * adjoining margins
	 */
	public function getCollapsedTopMargin():Float
	{
		return 0.0;
	}
	
	/**
	 * same as getCollapsedTopMargin for bottom
	 * margin
	 */
	public function getCollapsedBottomMargin():Float
	{
		return 0.0;
	}
	
	/**
	 * push the width of each adjoining margin 
	 * of this element's top margin
	 */
	public function getAdjoiningTopMargins(adjoiningMargins:Array<Float>):Void
	{
		
	}
	
	/**
	 * same as getAdjoiningTopMargins for bottom margins
	 */
	public function getAdjoiningBottomMargins(adjoiningMargins:Array<Float>):Void
	{
		
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
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.updateLayerRenderer();
			child = child.nextSibling;
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
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.attach();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Detach the LayerRenderer of this ElementRenderer from the LayerRenderer
	 * tree if necessary
	 */
	public function detach():Void
	{
		//first detach the LayerRenderer of all its children
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.detach();
			child = child.nextSibling;
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
		
	}
	
	/**
	 * Called by the document when the line box
	 * trees belonging to block box element renderer
	 * establishing an inline formatting context
	 * needs to be updated
	 * 
	 * inline boxes are generated for elements 
	 * participating in an inline formatting
	 * context
	 */
	public function updateInlineBoxes():Void
	{
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.updateInlineBoxes();
			child = child.nextSibling;
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
		containingBlock = getContainingBlock();
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
		containingBlock = null;
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
	 * If the ElementRenderer is absolutely positioned, it
	 * must register itself with its first positioned
	 * ancestor
	 */
	private function registerWithContaininingBlock():Void
	{
		if (isAbsolutelyPositioned() == true)
		{
			containingBlock.addAbsolutelyPositionedChildren(this);
			//flag remembering that the child was absolutely positioned at
			//attach time
			_wasAbsolutelyPositioned = true;
		}
	}
	
	/**
	 * If the ElementRenderer was absolutely positioned when attached,
	 * it must unregister itself from its first positioned
	 * ancestor
	 */
	private function unregisterWithContainingBlock():Void
	{
		if (_wasAbsolutelyPositioned == true)
		{
			containingBlock.removeAbsolutelyPositionedChild(this);
			_wasAbsolutelyPositioned = false;
		}
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	// Overriden by inheriting classes
	////////////////////////////////
	
	public function establishesNewBlockFormattingContext():Bool
	{
		return false;
	}
	
	public function isScrollBar():Bool
	{
		return false;
	}
	
	public function canHaveClearance():Bool
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
	
	public function isAbsolutelyPositioned():Bool
	{
		return false;
	}
	
	public function isInlineLevel():Bool
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
	
	public function hasCSSTransform():Bool
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
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
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
		if (isAbsolutelyPositioned() == true)
		{
			//for absolutely positioned fixed elements, the containing block
			//is the viewport
			if (coreStyle.isFixedPositioned == true)
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
		while (parent.isBlockContainer == false)
		{
			parent = parent.parentNode;
		}
		
		return cast(parent);
	}
	
	/**
	 * Set the bounds of an array of inlinebox
	 * on a provided bounds object
	 */
	private function getInlineBoxesBounds(inLineBoxes:Array<InlineBox>, bounds:RectangleVO):Void
	{
		//first reset the bounds
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		var length:Int = inLineBoxes.length;
		for (i in 0...length)
		{
			GeomUtils.addBounds(inLineBoxes[i].bounds, bounds);
		}
	}
	
	/**
	 * Traverse all the children recursively
	 * and apply their bounds to the
	 * target bounds
	 */
	private function doGetChildrenBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			GeomUtils.addBounds(child.bounds, bounds);
			if (child.firstChild != null)
			{
				doGetChildrenBounds(child, bounds);
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An ElementRenderer is invalidated for instance when one of its style value changes,
	 * or when a child is appended to it. When this happens, the ElementRenderer determinates
	 * the steps to take (wether to re-layout and/or re-render the element)
	 * 
	 * In most cases, an invalidation schedule an update of the docuement
	 * layout and rendering
	 * 
	 * This method is a generic invalidation method
	 * for cases which are not yet optimised
	 */
	public function invalidate():Void
	{
		//abstract
	}
	
	/**
	 * Called when a style of the owning HTMLElement
	 * changed
	 * @param	styleIndex the index of the style whose
	 * value changed
	 */
	public function invalidateStyle(styleIndex:Int):Void
	{
		//abstract
	}
	
	/**
	 * Called when this element renderer needs
	 * to be re-rendered
	 */
	public function invalidateRendering():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * If this element renderer creates its own
	 * layer, then forward scroll left update
	 * to the layer. If it doesn't create
	 * any layer, then no need to forward as
	 * it won't be taken into account anyway.
	 * Element renderer which can be scrolled
	 * ('overflow' different from visible)
	 * always create their own layer
	 * 
	 * The layer will determine 
	 * wether to actually update scroll left.
	 */
	private function set_scrollLeft(value:Float):Float 
	{
		if (_hasOwnLayer == true)
		{
			layerRenderer.scrollLeft = value;
		}
		
		return value;
	}
	
	/**
	 * same as when setting scroll left, if element
	 * has own layer, retrieve scroll left from layer,
	 * else it doesn't have any scroll left
	 */
	private function get_scrollLeft():Float
	{
		if (_hasOwnLayer == true)
		{
			return layerRenderer.scrollLeft;
		}
		
		return 0;
	}
	
	/**
	 * same as setting scroll left for top
	 */
	private function set_scrollTop(value:Float):Float 
	{
		if (_hasOwnLayer == true)
		{
			layerRenderer.scrollTop = value;
		}
		
		return value;
	}
	
	/**
	 * same as getting scroll left for top
	 */
	private function get_scrollTop():Float
	{
		if (_hasOwnLayer == true)
		{
			return layerRenderer.scrollTop;
		}
		
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TREE TRAVERSAL GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_previousNormalFlowSibling():ElementRenderer
	{
		var previousElementRendererSibling:ElementRenderer = previousSibling;
		
		while (previousElementRendererSibling != null)
		{
			if (previousElementRendererSibling.isFloat() == false)
			{
				if (previousElementRendererSibling.isAbsolutelyPositioned() == false)
				{
					return previousElementRendererSibling;
				}
			}
			
			previousElementRendererSibling = previousElementRendererSibling.previousSibling;
		}
		
		return null;
	}
	
	private function get_nextNormalFlowSibling():ElementRenderer
	{
		var nextElementRendererSibling:ElementRenderer = nextSibling;
	
		while (nextElementRendererSibling != null)
		{
			if (nextElementRendererSibling.isFloat() == false)
			{
				if (nextElementRendererSibling.isAbsolutelyPositioned() == false)
				{
					return nextElementRendererSibling;
				}
			}
			
			nextElementRendererSibling = nextElementRendererSibling.nextSibling;
		}
		
		return null;
	}
	
	private function get_firstNormalFlowChild():ElementRenderer
	{
		var firstElementRendererChild:ElementRenderer = firstChild;
		
		if (firstElementRendererChild != null)
		{
			if (firstElementRendererChild.isFloat() == false)
			{
				if (firstElementRendererChild.isAbsolutelyPositioned() == false)
				{
					return firstElementRendererChild;
				}
			}
			
			return firstElementRendererChild.nextNormalFlowSibling;
		}
		
		return null;
	}
	
	private function get_lastNormalFlowChild():ElementRenderer
	{
		var lastElementRendererChild:ElementRenderer = lastChild;
		
		if (lastElementRendererChild != null)
		{
			if (lastElementRendererChild.isFloat() == false)
			{
				if (lastElementRendererChild.isAbsolutelyPositioned() == false)
				{
					return lastElementRendererChild;
				}
			}
			
			return lastElementRendererChild.previousNormalFlowSibling;
		}
		
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////

	
	private function get_scrollWidth():Float
	{
		if (_hasOwnLayer == true)
		{
			var scrollableWidth:Float = layerRenderer.scrollableBounds.width;
			
			if (scrollableWidth > bounds.width)
			{
				return scrollableWidth;
			}
		}
		
		return bounds.width;
	}
	
	private function get_scrollHeight():Float
	{
		if (_hasOwnLayer == true)
		{
			var scrollableHeight:Float = layerRenderer.scrollableBounds.height;
			
			if (scrollableHeight > bounds.height)
			{
				return scrollableHeight;
			}
		}
		
		return bounds.height;
	}
}