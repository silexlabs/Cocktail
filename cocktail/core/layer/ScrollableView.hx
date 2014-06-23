/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.ds.FastNode;
import cocktail.geom.GeomData;
import cocktail.geom.GeomUtils;
import cocktail.core.renderer.ElementRenderer;

/**
 * Had to add this when updating to Haxe3 as recursive
 * type parameters no longer compile
 */
interface IScrollableView<ViewClass> {
	var rootElementRenderer(default, null):ElementRenderer;
	function updateClipRect():Void;
	function clipIfNeeded(parentClipRect:RectangleVO, layer:ViewClass):Bool;
	function resetClipRect(x:Float, y:Float, width:Float, height:Float):Void;
	function updateScrollOffset():Void;
	function addScrollOffsetIfNeeded(layer:ViewClass, scrollLeft:Float, scrollTop:Float):Void;
	function resetScrollOffset():Void;
	function updateScrollableBounds():Void;
	function isYAxisClipped():Bool;
	function isXAxisClipped():Bool;
	function getScrollableBoundsIfNeeded(layer:ViewClass):RectangleVO;
	function updateClippedBounds():Void;
	function updateBounds():Void;
}

/**
 * This is a base class for layers which represent the 
 * z-ordering of the document. This base class implements
 * all the functionnality for scrolling and masking (implementation of
 * the CSS 'overflow' style).
 * 
 * More general information about layer can be found in the LayerRenderer class
 * 
 * Some bounds defined in this class (bounds, scrollableBounds...), 
 * are defined in document space. This space's origin is the top left
 * of the canvas where the document is rendered and the bottom is the bottom
 * most point where the document is rendered.
 * 
 * @author Yannick DOMINGUEZ
 */
class ScrollableView<ViewClass:(FastNode<ViewClass>, IScrollableView<ViewClass>)> extends FastNode<ViewClass> implements IScrollableView<ViewClass>
{	
	/**
	 * A reference to the ElementRenderer which
	 * created the layer
	 */
	public var rootElementRenderer(default, null):ElementRenderer;
	
	/**
	 * This is the added scroll offsets of all
	 * the ancestors layers. For instance if an
	 * ancestor layer as an overflow of 'hidden'
	 * and has a scrollLeft of 5, it will add
	 * 5 to scrollOffset.x of this layer
	 */
	private var _ancestorsScrollOffset:PointVO; 
	
	/**
	 * Same as ancestorsScrollOffset but it
	 * also includes the layer's own scrollLeft
	 * and scrollTop;
	 */
	public var scrollOffset(default, null):PointVO;
	
	/**
	 * When setting a new scroll offset for the layer, save
	 * the previous value of x. It is used when
	 * redrawing layer which scrolled to only redraw
	 * the part of the layer which scrolled
	 */
	private var _previousScrollOffsetX:Float;
	
	/**
	 * same as above for scroll offset y
	 */
	private var _previousScrollOffsetY:Float;
	
	/**
	 * Those represent the bounds of the layer
	 * in the document space. The bounds of the layer
	 * are the bounds of all the element renderers using
	 * it as layer. The layer transformations are applied
	 * to those bounds. For instance, if the layer's root
	 * element renderer is relative positioned with a
	 * 'left' style of 10px, then 10 will be added to 
	 * bounds.x
	 */
	public var bounds(default, null):RectangleVO;
	
	/**
	 * Those are the bounds used when overflow of this
	 * layer is not visible. Those matches the bounds
	 * of the root element renderer with the layer's
	 * transformations applied to them.
	 * 
	 * If overflow is visible, those are the same
	 * as the bounds of the layer
	 */
	private var _clippedBounds:RectangleVO;
	
	/**
	 * if the layer's overflow is not visible, those
	 * are the bounds used to determine the scrolling
	 * area masked by this layer.
	 * Those bounds encompasses the layer's own bound
	 * and all the bounds of its descendant layers
	 */
	public var scrollableBounds(default, null):RectangleVO; 
	
	/**
	 * This is the clipping rect of the layer, representing
	 * the area where this layer can actually be painted.
	 * 
	 * For instance if a layer has an overflow not visible, then
	 * is will clip its own bounds to the size and position of its root
	 * element renderer, and will also clip its children. Its children
	 * can in turn be further clipped if they themselves have an
	 * overflow not visible.
	 * 
	 * The initial clip rect for all layers is the viewport
	 * as this is the maximum area which can be painted
	 * 
	 * The clip rect is defined in the space of the viewport
	 */
	public var clipRect(default, null):RectangleVO;
	
	/**
	 * Represent the offset in the x-axis to apply
	 * to these layer children if the layer does not
	 * overflow in the x-axis. The scroll offset can't be
	 * inferior to 0
	 */
	public var scrollLeft(default, set_scrollLeft):Float;
	
	/**
	 * same as scrollLeft for the y-axis
	 */
	public var scrollTop(default, set_scrollTop):Float;
	
	/**
	 * class constructor
	 * @param	rootElementRenderer the element renderer
	 * which created the layer
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super();
		this.rootElementRenderer = rootElementRenderer;
		
		scrollLeft = 0;
		scrollTop = 0;
		
		_previousScrollOffsetX = 0;
		_previousScrollOffsetY = 0;
		_ancestorsScrollOffset = new PointVO(0, 0);
		scrollOffset = new PointVO(0, 0);
		bounds = new RectangleVO();
		_clippedBounds = new RectangleVO();
		scrollableBounds = new RectangleVO();
		clipRect = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CLIP RECT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the clip rect of all layers before
	 * re-computing it. All layers default
	 * to the clip rect defined by the viewport.
	 */
	public function resetClipRect(x:Float, y:Float, width:Float, height:Float):Void
	{
		clipRect.x = x;
		clipRect.y = y;
		clipRect.width = width;
		clipRect.height = height;
		
		//traverse whole layer tree
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.resetClipRect(x, y, width, height);
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the clip rect of this layer,
	 * by clipping itself and its children if needed
	 */
	public function updateClipRect():Void
	{
		//check if clipped
		var clipped:Bool = false;
		if (isXAxisClipped() == true)
		{
			clipped = true;
		}
		else if (isYAxisClipped() == true)
		{
			clipped = true;
		}
		
		//if this layer is clipped in the x, y or both axis,
		//find its own clip rect and apply it to its children
		if (clipped == true)
		{
			//before computing clip rect, convert the clipped bounds from
			//document space to viewport space with scroll offsets
			_clippedBounds.x -= _ancestorsScrollOffset.x;
			_clippedBounds.y -= _ancestorsScrollOffset.y;
			
			//find the intersecting rect between its current clip rect (clip
			//rect established by its ancestors) and its own clip rect
			GeomUtils.intersectBounds(clipRect, _clippedBounds, clipRect);
			
			//convert back to document space
			_clippedBounds.x += _ancestorsScrollOffset.x;
			_clippedBounds.y += _ancestorsScrollOffset.y;
			
			clipChildren(cast(this), clipRect, cast(this));
		}
		
		//clip while layer tree recursively
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.updateClipRect();
			child = child.nextSibling;
		}
	}
	
	/**
	 * When a layer is clipped because of its overflow style, apply its
	 * own clip rect to all its descendant layer
	 * 
	 * @param	rootLayerRenderer the current layer onto which the clip rect is applied
	 * @param	clipRect the clip rect to apply
	 * @param	referenceLayer the layer which was clipped
	 */
	private function clipChildren(rootLayerRenderer:ViewClass, clipRect:RectangleVO, referenceLayer:ViewClass):Void
	{
		//traverse all descendants
		var child:ViewClass = rootLayerRenderer.firstChild;
		while (child != null)
		{
			//try to apply the clipping to the child, the child
			//determine wether it applies to it
			var childWasClipped:Bool = child.clipIfNeeded(clipRect, referenceLayer);
			
			//child return wether it was clipped or not,
			//if it wasn't clipped, then its child layer
			//shouldn't be clipped either
			if (childWasClipped == true)
			{
				if (child.firstChild != null)
				{
					clipChildren(child, clipRect, referenceLayer);
				}
			}
		
			child = child.nextSibling;
		}
	}
	
	/**
	 * When an ancestor layer is clipped, this method is
	 * called with the clip rect of the ancestor and a reference
	 * to the ancestor. This layer determines wether this clipping
	 * should apply to itself
	 * 
	 * @param	parentClipRect the clip rect to apply to this layer
	 * @param	layer the layer which was clipped
	 * @return	return wether the layer was clipped
	 */
	public function clipIfNeeded(parentClipRect:RectangleVO, layer:ViewClass):Bool
	{
		//if the layer's root element renderer is fixed, than it can't be clipped as
		//its containing block is the viewport
		if (rootElementRenderer.coreStyle.isFixedPositioned == true)
		{
			return false;
		}
		//else if the containing block is a parent of the clipped layer, the
		//the clipping doesn't apply to this layer
		if (isContainingBlockChildren(layer) == true)
		{
			return false;
		}
		
		//else clip by finding the intersecting rect between
		//the current clip rect and the ancestor's clip rect
		GeomUtils.intersectBounds(clipRect, parentClipRect, clipRect);
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL OFFSET METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset scroll offset of all layers before
	 * re-computing it
	 */
	public function resetScrollOffset():Void
	{
		_ancestorsScrollOffset.x = 0;
		_ancestorsScrollOffset.y = 0;
		
		_previousScrollOffsetX = scrollOffset.x;
		_previousScrollOffsetY = scrollOffset.y;
		
		scrollOffset.x = 0;
		scrollOffset.y = 0;
		
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.resetScrollOffset();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the scroll offset of this layer
	 * which is the added scroll offset of all 
	 * its ancestors
	 */
	public function updateScrollOffset():Void
	{
		//TODO  : if scrollableBounds.x - bounds.x < 0, scrollLeftForChild = scrollableBounds.x + scrollLeft, 
		//same for y, as if scrollLeft specified as 0, child should
		//be rendered using layer top left as origin.
		if (isXAxisClipped() == true)
		{
			//add offset to all descendant
			addScrollOffsetToChildren(cast(this), scrollLeft, scrollTop, cast(this));
		}
		else if (isYAxisClipped() == true)
		{
			addScrollOffsetToChildren(cast(this), scrollLeft, scrollTop, cast(this));
		}
		
		//apply scroll offset to the whole
		//layer tree recursively
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.updateScrollOffset();
			child = child.nextSibling;
		}
		
		//can now update combined scrolloffset
		scrollOffset.x = _ancestorsScrollOffset.x + scrollLeft;
		scrollOffset.y = _ancestorsScrollOffset.y + scrollTop;
	}
	
	/**
	 * Called when an ancestor has a scroll left and/top offset.
	 * This layer determine wether it should add it to its own
	 * scroll offset
	 */
	public function addScrollOffsetIfNeeded(layer:ViewClass, scrollLeft:Float, scrollTop:Float):Void
	{
		//scroll offset don't apply to fiexed element, as they are always positioned relative to the
		//viewport
		if (rootElementRenderer.coreStyle.isFixedPositioned == true)
		{
			return;
		}
		//if the layer with the scroll offset is a child of the containing block
		//of this layer, then the scroll offset doesn't apply to it
		if (isContainingBlockChildren(layer) == true)
		{
			return;
		}
		
		//else add to own offset
		_ancestorsScrollOffset.x += scrollLeft;
		_ancestorsScrollOffset.y += scrollTop;
		
	}
	
	/**
	 * When a layer  has a scroll offset left or top, it tries to add it
	 * to all its descendant. Each descendant determine wether it applies
	 * to itself
	 * @param	rootLayerRenderer the current layer onto which the scroll offset is applied
	 * @param	scrollLeft the scroll left of the offset layer
	 * @param	scrollTop the scroll top of the offset layer
	 * @param	referenceLayer the layer with a scroll left and/or top
	 */
	private function addScrollOffsetToChildren(rootLayerRenderer:ViewClass, scrollLeft:Float, scrollTop:Float, referenceLayer:ViewClass):Void
	{
		//traverse all descedant recursively
		var child:ViewClass = rootLayerRenderer.firstChild;
		while (child != null)
		{
			//each child determine wether the scroll offset applies to it
			child.addScrollOffsetIfNeeded(referenceLayer, scrollLeft, scrollTop);
			
			if (child.firstChild != null)
			{
				addScrollOffsetToChildren(child, scrollLeft, scrollTop, referenceLayer);
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// BOUNDS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the bounds of this layer, which
	 * are the transformed bounds of all its 
	 * element renderers
	 */
	public function updateBounds():Void
	{
		var child:ViewClass = firstChild;
		
		//TODO : apply layer's transformation matrix
		getElementRenderersBounds(rootElementRenderer, bounds);
		
		//update bounds of all layers recursively
		while (child != null)
		{
			child.updateBounds();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the clipped bounds of this
	 * layer, which are the bounds it has
	 * if overflow is not visible. It is 
	 * the transformed bounds of its root
	 * element renderers
	 */
	public function updateClippedBounds():Void
	{
		var child:ViewClass = firstChild;
		
		//clipped bounds are at first same as bounds,
		//they remain the same if the layer has overflow
		//visible
		var x:Float = bounds.x;
		var y:Float = bounds.y;
		var width:Float = bounds.width;
		var height:Float = bounds.height;
		
		//TODO : apply layers transformation to x and y
		//clip the x axis
		if (isXAxisClipped() == true)
		{
			x = rootElementRenderer.globalBounds.x;
			width = rootElementRenderer.globalBounds.width;
		}
		
		//clip the y axis
		if (isYAxisClipped() == true)
		{
			y = rootElementRenderer.globalBounds.y;
			height = rootElementRenderer.globalBounds.height;
		}
		
		_clippedBounds.x = x;
		_clippedBounds.y = y;
		_clippedBounds.width = width;
		_clippedBounds.height = height;
		
		//update all layer tree recursively
		while (child != null)
		{
			child.updateClippedBounds();
			child = child.nextSibling;
		}
	}
	
	/**
	 * get the bounds of all the element
	 * renders using this layer, starting
	 * from the root element renderer
	 */
	private function getElementRenderersBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		//reset the bounds
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		//first add the bounds of the root element renderer
		GeomUtils.addBounds(rootElementRenderer.globalBounds, bounds);
		
		//then all its children using this layer
		doGetElementRenderersBounds(rootElementRenderer, bounds);
	}
	
	/**
	 * Traverse all element renderers
	 * of this layer recursively and add their bounds
	 * to the layer's bounds
	 */
	private function doGetElementRenderersBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		//must cast this into a layerRenderer
		//TODO 3 : clumsy, should implementation be in LayerRenderer ?
		var thisAsLayer:LayerRenderer = cast(this);
		
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			//don't use text bounds, as they are included
			//in all block and inline element renderer during
			//layout
			if (child.isText == false)
			{
				//check that child belong to this layer
				if (child.layerRenderer == thisAsLayer)
				{
					//add bounds of child
					GeomUtils.addBounds(child.globalBounds, bounds);
					if (child.firstChild != null)
					{
						doGetElementRenderersBounds(child, bounds);
					}
				}
			}
		
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLABLE BOUNDS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the scrollable bounds of this layer
	 * which are formed by its own bounds and
	 * the bounds of all descedant layers
	 */
	public function updateScrollableBounds():Void
	{
		var child:ViewClass = firstChild;
		
		//TODO : apply layer's transformation matrix
		getScrollableBounds(cast(this), scrollableBounds);
		
		//update all the layer tree recursively
		while (child != null)
		{
			child.updateScrollableBounds();
			child = child.nextSibling;
		}
	}
	
	/**
	 * Called when an ancestor is computing its scrollable bounds, this layer
	 * determine what bounds to return to this ancestor.
	 * 
	 * @param	layer the ancestor layer computing its scroll bounds
	 * @return	bounds or clipped bounds of this layer, or null if doesn't apply
	 */
	public function getScrollableBoundsIfNeeded(layer:ViewClass):RectangleVO
	{
		//if the layer is fixed, then it won't be scrolled by its ancestor, and so
		//it returns null as it shouldn't be added to its ancestor scroll bounds
		if (rootElementRenderer.coreStyle.isFixedPositioned == true)
		{
			return null;
		}
		
		//else if the containing block of this layers is a parent of the 
		//root element renderer of the ancestor layer, then this layer
		//won't be scrolled by the ancestor layer
		if (isContainingBlockChildren(layer) == true)
		{
			return null;
		}
		
		//else if not clipped, return the bounds of its element renderers
		if (isXAxisClipped() == false)
		{
			if (isYAxisClipped() == false)
			{
				return bounds;
			}
		}
		
		//else return its clipped bounds
		return _clippedBounds;
	}
	
	/**
	 * Get the scroll bounds of this layer by getting 
	 * the bounds of all the descendant layers
	 */
	private function getScrollableBounds(rootLayerRenderer:ViewClass, scrollableBounds:RectangleVO):Void
	{
		scrollableBounds.x = 50000;
		scrollableBounds.y = 50000;
		scrollableBounds.width = 0;
		scrollableBounds.height = 0;
		
		//first add its own bounds
		GeomUtils.addBounds(this.bounds, scrollableBounds);
		
		//add bounds of all descedant layers
		doGetScrollableBounds(rootLayerRenderer, scrollableBounds, cast(this), true, true);
	}
	
	/**
	 * Traverse all layer descendant and request bounds on each
	 * @param	rootLayerRenderer the current layer whose bounds are requested
	 * @param	scrollableBounds the scrollable bounds of this layer where all other bounds are added
	 * @param	referenceLayer a reference to this layer, then one whose scroll bounds are requested
	 * @param	getHorizontalBounds wheter horizontal bounds should be requested on descendant layer
	 * @param	getVerticalBounds wheter vertical bounds should be requested on descendant layer
	 */
	private function doGetScrollableBounds(rootLayerRenderer:ViewClass, scrollableBounds:RectangleVO, referenceLayer:ViewClass, getHorizontalBounds:Bool, getVerticalBounds:Bool):Void
	{
		//traverse all the layer tree recursively
		var child:ViewClass = rootLayerRenderer.firstChild;
		while(child != null)
		{
			//request bounds of child, child determine what bounds it should return
			var childBounds:RectangleVO = child.getScrollableBoundsIfNeeded(referenceLayer);

			
			//if child returned null bounds, then it is not 
			//scrolled by this layer
			if (childBounds != null)
			{
				//else, add bounds of child to scrollable bounds
				GeomUtils.addBounds(childBounds, scrollableBounds, getHorizontalBounds, getVerticalBounds);
				
				if (child.firstChild != null)
				{
					//if child x-axis is clipped, then there is no need
					//to request horizontal bounds on its children, the
					//only horizontal bounds added to the scrollable bounds
					//are the clipped horizontal bounds of the child
					if (child.isXAxisClipped() == true)
					{
						getHorizontalBounds = false;
					}
					
					//same for y-axis
					if (child.isYAxisClipped() == true)
					{
						getVerticalBounds = false;
					}
					
					//if both x and y axis are clipped, there is no need to
					//request child bounds.
					if (getHorizontalBounds == true || getVerticalBounds == true)
					{
						doGetScrollableBounds(child, scrollableBounds, referenceLayer, getHorizontalBounds, getVerticalBounds);
					}
				}
			}
				
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_scrollLeft(value:Float):Float
	{
		//if the layer can't be scrolled on the x-axis, 
		//scroll left remain 0
		if (isXAxisClipped() == false)
		{
			return scrollLeft = 0;
		}
		
		//negative values are illegal
		if (value <= 0)
		{
			if (scrollLeft > 0)
			{
				scrollChanged();
			}
			scrollLeft = 0;
		}
		else
		{
			//else get maximum available scroll
			var maxWidthScroll:Float = scrollableBounds.width - _clippedBounds.width;
			
			//if negative, means that content of layer's width is smaller than
			//the root element render width, so it can't be scrolled
			if (maxWidthScroll <= 0)
			{
				if (scrollLeft != 0)
				{
					scrollChanged();
				}
				
				scrollLeft = 0;
			}
			//else clip the scroll value to the max scroll width
			//if necessary
			else
			{
				if (value > maxWidthScroll)
				{
					if (scrollLeft != maxWidthScroll)
					{
						scrollChanged();
					}
					
					scrollLeft = maxWidthScroll;
				}
				else
				{
					if (scrollLeft != value)
					{
						scrollChanged();
					}
					
					scrollLeft = value;
				}
			}
		}
		
		return value;
	}

	private function set_scrollTop(value:Float):Float
	{
		if (isYAxisClipped() == false)
		{
			return scrollTop = 0;
		}
		
		if (value <= 0)
		{
			if (scrollTop > 0)
			{
				scrollChanged();
			}
			scrollTop = 0;
		}
		else 
		{
			var maxHeightScroll:Float = scrollableBounds.height - _clippedBounds.height;
			
			if (maxHeightScroll <= 0)
			{
				if (scrollTop != 0)
				{
					scrollChanged();
				}
				
				scrollTop = 0;
			}
			else
			{
				if (value > maxHeightScroll)
				{
					if (scrollTop != maxHeightScroll)
					{
						scrollChanged();
					}
					
					scrollTop = maxHeightScroll;
				}
				else
				{
					if (scrollTop != value)
					{
						scrollChanged();
					}
					
					scrollTop = value;
				}
			}
		}
		
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UTILS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the value of scroll left or scroll top
	 * changed on a layer which can scroll
	 */
	private function scrollChanged():Void
	{
		//abstract
	}
	
	/**
	 * Determine wether the target layer's root element renderer is a child of this layer's
	 * root element renderer's containing block.
	 */
	private function isContainingBlockChildren(layer:ViewClass):Bool
	{
		var containingBlock:ElementRenderer = rootElementRenderer.containingBlock;
		
		var layerContainingBlock:ElementRenderer = layer.rootElementRenderer.containingBlock;
		
		if (containingBlock == layerContainingBlock)
		{
			return false;
		}
		
		var parent:ElementRenderer = layerContainingBlock;
		
		while (parent != null)
		{
			if (parent == containingBlock)
			{
				return true;
			}
			
			parent = parent.parentNode;
		}
		
		return false;
	}
	
	/**
	 * Determine wheter the x axis of this layer
	 * is clipped to its width
	 */
	public function isXAxisClipped():Bool
	{
		//only block containers can be clipped
		if (rootElementRenderer.isBlockContainer == false)
		{
			return false;
		}
		
		//here overflow x and y are both visible
		if (rootElementRenderer.coreStyle.canAlwaysOverflow == true)
		{
			return false;
		}
		
		//here x is clipped
		if (rootElementRenderer.coreStyle.hasHiddenOrScrollOverflowX == true)
		{
			return true;
		}
		
		switch (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.overflowX))
		{
			case HIDDEN, SCROLL:
				return true;
				
			//when overflow is auto, the x axis is only
			//clipped if a scrollbar is displayed
			case AUTO:
				//TODO 3 : when scrollbar implemented, return
				//wether scrollbar currently visible
				return false;
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return false;
				}
				return false;
				
			default:
				return false;
		}
	}
	
	/**
	 * Determine wheter the y axis of this layer
	 * is clipped to its height
	 */
	public function isYAxisClipped():Bool
	{
		//only block containers can be clipped
		if (rootElementRenderer.isBlockContainer == false)
		{
			return false;
		}
		
		//here overflow x and y are both visible
		if (rootElementRenderer.coreStyle.canAlwaysOverflow == true)
		{
			return false;
		}
		
		//here y is clipped
		if (rootElementRenderer.coreStyle.hasHiddenOrScrollOverflowY == true)
		{
			return true;
		}
		
		switch (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.overflowY))
		{
			case HIDDEN, SCROLL:
				return true;
				
			case AUTO:
				return false;
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return false;
				}
				return false;
				
			default:
				return false;
		}
	}
	
	/**
	 * This helper method is used to differentiate between
	 * a layer and the initial layer, at the top of the layer
	 * tree
	 * 
	 * For the initial layer, a computed value
	 * of visible for overflow behaves the same as a computed
	 * value of auto
	 */
	private function treatVisibleOverflowAsAuto():Bool
	{
		return false;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SCROLLING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//
	///**
	 //* When a scroll value changes, update the rendering
	 //*/
	//private function updateScroll():Void
	//{
		//only called if not already updating scroll, else
		//infinite loop with scrollbars
		//if (_isUpdatingScroll == false)
		//{
			//_isUpdatingScroll = true;
			//
			//if (isXAxisClipped() == true || isYAxisClipped() == true)
			//{
				//invalidate layout of scrolled element
				//invalidate();
			//}
			//
			//if (_horizontalScrollBar != null)
			//{
				//_horizontalScrollBar.scroll = scrollLeft;
			//}
			//if (_verticalScrollBar != null)
			//{
				//_verticalScrollBar.scroll = scrollTop;
			//}
			//
			//when scrolling is done, dispatched a scroll
			//event on the dom node
			//dispatchScrollEvent();
			//
			//_isUpdatingScroll = false;
		//}
	//}
	
	//
	//TODO 3 : implement border case where one has scroll attached, and the 
	//other is visible but should still display scroll
	///**
	 //* Attach the horizontal and vertical scrollbar if they are
	 //* needed, based on the overflow style of the BlockBoxRenderer
	 //*/
	//private function attachScrollBarsIfnecessary():Void
	//{
		//only try to remove attached scrollbars if both
		//overflow x and y are set to visible
		//if (canAlwaysOverflow() == true)
		//{
			//detachHorizontalScrollBar();
			//detachVerticalScrollBar();
			//return;
		//}
		//
		//tries to attach or detach horizontal scrollbar based on x
		//overflow
		//switch (coreStyle.getKeyword(coreStyle.overflowX))
		//{
			//case SCROLL:
				//attachHorizontalScrollBar();
				//
			//case HIDDEN:
				//detachHorizontalScrollBar();
				//
			//case AUTO:
				//attachOrDetachHorizontalScrollBarIfNecessary();
				//
			//case VISIBLE:
				//if (treatVisibleOverflowAsAuto() == true)
				//{
					//attachOrDetachHorizontalScrollBarIfNecessary();
				//}
				//else
				//{
					//detachHorizontalScrollBar();
				//}
				//
			//default:
				//throw "invalid value for overflowX";
		//}
//
		//tries to attach or detach vertical scrolbar based on 
		//overflow y
		//switch (coreStyle.getKeyword(coreStyle.overflowY))
		//{
			//case SCROLL:
				//attachVerticalScrollBar();
				//
			//case HIDDEN:
				//detachVerticalScrollBar();
				//
			//case AUTO:
				//attachOrDetachVerticalScrollBarIfNecessary();
				//
			//case VISIBLE:
				//if (treatVisibleOverflowAsAuto() == true)
				//{
					//attachOrDetachVerticalScrollBarIfNecessary();
				//}	
				//else
				//{
					//detachVerticalScrollBar();
				//}
				//
			//default:
				//throw "invalid value for overflowY";
		//}
	//}
	//
	///**
	 //* Instantiate the horizontal scrollbar DOM element
	 //* and attach it to the rendering tree, if it isn't
	 //* already attached
	 //* 
	 //* Listen to scroll event on it to update the
	 //* scroll display as needed
	 //*/
	//private function attachHorizontalScrollBar():Void
	//{
		//if (_horizontalScrollBar == null)
		//{
			//_horizontalScrollBar = new ScrollBar(false);
			//_horizontalScrollBar.ownerDocument = domNode.ownerDocument;
			//_horizontalScrollBar.attach(true);
			//appendChild(_horizontalScrollBar.elementRenderer);
			//_horizontalScrollBar.onscroll = onHorizontalScroll;
		//}
		//refresh the max scroll when a layout of the BlockBoxRenderer happens
		//if (_horizontalScrollBar != null)
		//{
			//_horizontalScrollBar.maxScroll = getHorizontalMaxScroll();
		//}
	//}
	//
	///**
	 //* Detach the horizontal scrollbar if it is 
	 //* currently displayed
	 //*/
	//private function detachHorizontalScrollBar():Void
	//{
		//if (_horizontalScrollBar != null)
		//{
			//removeChild(_horizontalScrollBar.elementRenderer);
			//_horizontalScrollBar.onscroll = null;
			//_horizontalScrollBar = null;
			//
			//reset scroll so that the display don't "jump" if
			//the horizontal scrollbar is attached again
			//scrollLeft = 0;
		//}
	//}
	//
	///**
	 //* When overflow x is set to auto, only try to attach the horizontal scrollbar
	 //* if the children width is superior to the BlockBoxRenderer width, else
	 //* try to detach it
	 //*/
	//private function attachOrDetachHorizontalScrollBarIfNecessary():Void
	//{
		//if (_scrollableBounds.x < 0 || _scrollableBounds.x + _scrollableBounds.width > bounds.width)
		//{
			//attachHorizontalScrollBar();
		//}
		//else
		//{
			//detachHorizontalScrollBar();
		//}
	//}
	//
	///**
	 //* same as for horizontal scrollbar
	 //*/
	//private function attachVerticalScrollBar():Void
	//{
		//if (_verticalScrollBar == null)
		//{
			//_verticalScrollBar = new ScrollBar(true);
			//_verticalScrollBar.ownerDocument = domNode.ownerDocument;
			//_verticalScrollBar.attach(true);
			//appendChild(_verticalScrollBar.elementRenderer);
			//_verticalScrollBar.onscroll = onVerticalScroll;
		//}
		//if (_verticalScrollBar != null)
		//{
			//_verticalScrollBar.maxScroll = getVerticalMaxScroll();
		//}
	//}
	//
	///**
	 //* same as for horizontal scrollbar
	 //*/
	//private function detachVerticalScrollBar():Void
	//{
		//if (_verticalScrollBar != null)
		//{
			//removeChild(_verticalScrollBar.elementRenderer);
			//_verticalScrollBar.onscroll = null;
			//_verticalScrollBar = null;
			//
			//reset scroll so that the display don't "jump" if
			//the vertical scrollbar is attached again
			//scrollTop = 0;
		//}
	//}
	//
	///**
	 //* same as for horizontal scrollbar
	 //*/
	//private function attachOrDetachVerticalScrollBarIfNecessary():Void
	//{
		//if (_scrollableBounds.y < 0 || _scrollableBounds.y + _scrollableBounds.height >  bounds.height)
		//{
			//attachVerticalScrollBar();
		//}
		//else
		//{
			//detachVerticalScrollBar();
		//}
	//}
	//
	///**
	 //* Update scroll left when a scroll event
	 //* is displateched by the horizontal scrollbar
	 //*/
	//private function onHorizontalScroll(event:Event):Void
	//{
		//scrollLeft = _horizontalScrollBar.scroll;
	//}
	//
	///**
	 //* same as for horizontal scrollbar
	 //*/
	//private function onVerticalScroll(event:Event):Void
	//{
		//scrollTop = _verticalScrollBar.scroll;
	//}
	//
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	//
	///**
	 //* Determine wether this BlockBoxRenderer always overflows
	 //* in both x and y axis. If either overflow x or y
	 //* is deifferent from visible, then it is considered to
	 //* not always overflow
	 //*/
	//private function canAlwaysOverflow():Bool
	//{
		//if (treatVisibleOverflowAsAuto() == true)
		//{
			//return false;
		//}
		//
		//switch (coreStyle.getKeyword(coreStyle.overflowX))
		//{
			//case VISIBLE:
				//
			//default:
				//return false;
		//}
		//
		//switch (coreStyle.getKeyword(coreStyle.overflowY))
		//{
			//case VISIBLE:
				//
			//default:
				//return false;
		//}
		//
		//return true;
	//}
	//
}
