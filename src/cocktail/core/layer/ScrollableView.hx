/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layer;

import cocktail.core.html.ScrollBar;
import cocktail.core.utils.FastNode;
import cocktail.core.geom.GeomData;
import cocktail.core.geom.GeomUtils;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.css.CSSData;

/**
 * This is a base class for layers which represent the 
 * z-ordering of the document. This base class implements
 * all the functionnality for scrolling and masking (implementation of
 * the CSS 'overflow' style).
 * 
 * More general information about layer can be found in the LayerRenderer class
 * 
 * All the bounds defined in this class (bounds, scrollableBounds...), 
 * are defined in document space. This space's origin is the top left
 * of the canvas where the document is rendered and the bottom is the bottom
 * most point where the document is rendered.
 * 
 * @author Yannick DOMINGUEZ
 */
class ScrollableView<ViewClass:ScrollableView<ViewClass>> extends FastNode<ViewClass>
{	
	/**
	 * A reference to the ElementRenderer which
	 * created the layer
	 */
	public var rootElementRenderer(default, null):ElementRenderer;
	
	/**
	 * A reference to the horizontal scrollbar which
	 * might be displayed on the layer. Is null while
	 * no horizontal scrollbar is displayed
	 */
	private var _horizontalScrollBar:ScrollBar;
	
	/**
	 * A reference to the vertical scrollbar which
	 * might be displayed on the layer. Is null while
	 * no vertical scrollbar is displayed
	 */
	private var _verticalScrollBar:ScrollBar;
	
	/**
	 * This is thee added scroll offsets of all
	 * the ancestors layers. For instance if an
	 * ancestor layer as an overflow of 'hidden'
	 * and has a scrollLeft of 5, it will add
	 * 5 to scrollOffset.x of this layer
	 */
	private var _scrollOffset:PointVO; 
	
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
	private var _scrollableBounds:RectangleVO; 
	
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
	 * The initial layer, at the top of the layer tree has initially
	 * a clip rect matching the viewport, as this is the maximum area
	 * which can be painted
	 */
	private var _clipRect:RectangleVO;
	
	/**
	 * Represent the offset in the x-axis to apply
	 * to these layer children if the layer does not
	 * overflow in the x-axis. The scroll offset can't be
	 * inferior to 0
	 */
	public var scrollLeft(default, null):Float;
	
	/**
	 * same as scrollLeft for the y-axis
	 */
	public var scrollTop(default, null):Float;
	
	/**
	 * class constructor
	 * @param	rootElementRenderer the element renderer
	 * which created the layer
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super();
		
		scrollLeft = 0;
		scrollTop = 0;
		_scrollOffset = new PointVO(0, 0);
		bounds = new RectangleVO();
		_clippedBounds = new RectangleVO();
		_scrollableBounds = new RectangleVO();
		_clipRect = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CLIP RECT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the clip rect of all layers before
	 * re-computing it
	 */
	public function resetClipRect():Void
	{
		//set it to an 'infinite' value
		_clipRect.x = -50000;
		_clipRect.y = -50000;
		_clipRect.width = 100000;
		_clipRect.height = 100000;
		
		//traverse whole layer tree
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.resetClipRect();
			child = cast(child.nextSibling);
		}
	}
	
	/**
	 * Update the clip rect of this layer,
	 * by clipping itself and its children if needed
	 */
	public function updateClipRect():Void
	{
		if (isXAxisClipped() == true || isYAxisClipped() == true)
		{
			GeomUtils.intersectBounds(_clipRect, _clippedBounds, _clipRect);
			clipChildren(cast(this), _clipRect, cast(this));
		}
		
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.updateClipRect();
			child = cast(child.nextSibling);
		}
	}
	
	private function clipChildren(rootLayerRenderer:ViewClass, clipRect:RectangleVO, referenceLayer:ViewClass):Void
	{
		var child:ViewClass = rootLayerRenderer.firstChild;
		while (child != null)
		{
			child.clipIfNeeded(clipRect, referenceLayer);
			
			if (child.firstChild != null)
			{
				clipChildren(child, clipRect, referenceLayer);
			}
			
			child = cast(child.nextSibling);
		}
	}
	
	public function clipIfNeeded(clipRect:RectangleVO, layer:ViewClass):Void
	{
		if (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.position) == FIXED)
		{
			return;
		}
		
		if (isContainingBlockChildren(layer) == true)
		{
			return;
		}
		
		GeomUtils.intersectBounds(_clipRect, clipRect, _clipRect);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL OFFSET METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function resetScrollOffset():Void
	{
		_scrollOffset.x = 0;
		_scrollOffset.y = 0;
		
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.resetScrollOffset();
			child = cast(child.nextSibling);
		}
	}
	
	public function updateScrollOffset():Void
	{
		
		if (isXAxisClipped() == true || isYAxisClipped() == true)
		{
			//TODO  : if scrollableBounds.x - bounds.x < 0, scrollLeftForChild = scrollableBounds.x + scrollLeft, 
			//same for y, as if scrollLeft specified as 0, child should
			//be rendered using layer top left as origin.
			_scrollOffset.x += scrollLeft;
			_scrollOffset.y += scrollTop;
			addScrollOffsetToChildren(cast(this), _scrollOffset.x, _scrollOffset.y, cast(this));
		}
		
		var child:ViewClass = firstChild;
		while (child != null)
		{
			child.updateScrollOffset();
			child = cast(child.nextSibling);
		}
	}
	
	public function addScrollOffsetIfNeeded(layer:ViewClass, scrollLeft:Float, scrollTop:Float):Void
	{
		if (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.position) == FIXED)
		{
			return;
		}
		
		if (isContainingBlockChildren(layer) == true)
		{
			return;
		}
		
		_scrollOffset.x += scrollLeft;
		_scrollOffset.y += scrollTop;
		
	}
	
	private function addScrollOffsetToChildren(rootLayerRenderer:ViewClass, scrollLeft:Float, scrollTop:Float, referenceLayer:ViewClass):Void
	{
		var child:ViewClass = rootLayerRenderer.firstChild;
		while (child != null)
		{
			child.addScrollOffsetIfNeeded(referenceLayer, scrollLeft, scrollTop);
			
			if (child.firstChild != null)
			{
				addScrollOffsetToChildren(child, scrollLeft, scrollTop, referenceLayer);
			}
			
			child = cast(child.nextSibling);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// BOUNDS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function updateBounds():Void
	{
		var child:ViewClass = firstChild;
		
		//TODO : apply layer's transformation matrix
		getElementRenderersBounds(rootElementRenderer, bounds);
		
		while (child != null)
		{
			child.updateBounds();
			child = cast(child.nextSibling);
		}
	}
	
	public function updateClippedBounds():Void
	{
		var child:ViewClass = firstChild;
		
		var x:Float = bounds.x;
		var y:Float = bounds.y;
		var width:Float = bounds.width;
		var height:Float = bounds.height;
		
		//TODO : apply layers transformation to x and y
		if (isXAxisClipped() == true)
		{
			x = rootElementRenderer.globalBounds.x;
			width = rootElementRenderer.globalBounds.width;
		}
		
		if (isYAxisClipped() == true)
		{
			y = rootElementRenderer.globalBounds.y;
			height = rootElementRenderer.globalBounds.height;
		}
		
		_clippedBounds.x = x;
		_clippedBounds.y = y;
		_clippedBounds.width = width;
		_clippedBounds.height = height;
		
		while (child != null)
		{
			child.updateClippedBounds();
			child = cast(child.nextSibling);
		}
	}
	
	
	
	/**
	 * Set the bounds of an array of linebox
	 * on a provided bounds object
	 */
	private function getElementRenderersBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		//first reset the bounds
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		GeomUtils.addBounds(rootElementRenderer.globalBounds, bounds);
		
		doGetElementRenderersBounds(rootElementRenderer, bounds);
	}
	
	/**
	 * Traverse all the children recursively
	 * and apply their bounds to the
	 * target bounds
	 */
	private function doGetElementRenderersBounds(rootElementRenderer:ElementRenderer, bounds:RectangleVO):Void
	{
		var child:ElementRenderer = rootElementRenderer.firstChild;
		while(child != null)
		{
			if (child.layerRenderer == cast(this))
			{
				GeomUtils.addBounds(child.globalBounds, bounds);
				if (child.firstChild != null)
				{
					doGetElementRenderersBounds(child, bounds);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLABLE BOUNDS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function updateScrollableBounds():Void
	{
		var child:ViewClass = firstChild;
		
		//TODO : apply layer's transformation matrix
		getScrollableBounds(cast(this), _scrollableBounds);
		
		while (child != null)
		{
			child.updateBounds();
			child = cast(child.nextSibling);
		}
	}
	
	public function getScrollableBoundsIfNeeded(layer:ViewClass):RectangleVO
	{
		if (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.position) == FIXED)
		{
			return null;
		}
		
		if (isContainingBlockChildren(layer) == true)
		{
			return null;
		}
		
		
		if (isXAxisClipped() == false && isYAxisClipped() == false)
		{
			return bounds;
		}
		else
		{
			return _clippedBounds;
		}
	}
	
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
	
	private function getScrollableBounds(rootLayerRenderer:ViewClass, scrollableBounds:RectangleVO):Void
	{
		bounds.x = 50000;
		bounds.y = 50000;
		bounds.width = 0;
		bounds.height = 0;
		
		GeomUtils.addBounds(this.bounds, scrollableBounds);
		
		doGetScrollableBounds(rootLayerRenderer, scrollableBounds, cast(this), true, true);
	}
	
	private function doGetScrollableBounds(rootLayerRenderer:ViewClass, scrollableBounds:RectangleVO, referenceLayer:ViewClass, useHorizontalBounds:Bool, useVerticalBounds:Bool):Void
	{
		var child:ViewClass = rootLayerRenderer.firstChild;
		while(child != null)
		{
			var childBounds:RectangleVO = child.getScrollableBoundsIfNeeded(referenceLayer);
			
			if (childBounds != null)
			{
				GeomUtils.addBounds(childBounds, scrollableBounds, useHorizontalBounds, useVerticalBounds);
				if (child.firstChild != null)
				{
					if (child.isXAxisClipped() == true)
					{
						useHorizontalBounds = false;
					}
					
					if (child.isYAxisClipped() == true)
					{
						useVerticalBounds = false;
					}
					
					if (useHorizontalBounds == true || useVerticalBounds == true)
					{
						doGetScrollableBounds(child, scrollableBounds, referenceLayer, useHorizontalBounds, useVerticalBounds);
					}
				}
			}
				
			child = cast(child.nextSibling);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UTILS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wheter the x axis of this layer
	 * is clipped to its width
	 */
	public function isXAxisClipped():Bool
	{
		switch (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.overflowX))
		{
			case HIDDEN, SCROLL:
				return true;
				
			//when overflow is auto, the x axis is only
			//clipped if a scrollbar is displayed
			case AUTO:
				return _horizontalScrollBar != null;
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return _horizontalScrollBar != null;
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
		switch (rootElementRenderer.coreStyle.getKeyword(rootElementRenderer.coreStyle.overflowY))
		{
			case HIDDEN, SCROLL:
				return true;
				
			case AUTO:
				return _verticalScrollBar != null;
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return _verticalScrollBar != null;
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
	
	//
	//
	//
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SCROLLING GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	//
	///**
	 //* Overriden as BlockBoxRenderer might actually be scrolled
	 //*/
	//override private function get_scrollLeft():Float 
	//{
		//return _scrollLeft;
	//}
	//
	///**
	 //* Overriden as BLockBoxRenderer might actually be scrolled
	 //*/
	//override private function set_scrollLeft(value:Float):Float 
	//{
		//negative values are illegal
		//if (value <= 0)
		//{
			//_scrollLeft = 0;
		//}
		//if the value if more the available scrollable width, set
		//the value to the max scrollable width
		//else if (value > getHorizontalMaxScroll())
		//{
			//_scrollLeft = getHorizontalMaxScroll();
		//}
		//else
		//{
			//_scrollLeft = value;
		//}
		//
		//updateScroll();
		//
		//return value;
	//}
	//
	//override private function get_scrollTop():Float 
	//{
		//return _scrollTop;
	//}  
	//
	//override private function set_scrollTop(value:Float):Float 
	//{
		//if (value <= 0)
		//{
			//_scrollTop = 0;
		//}
		//else if (value > getVerticalMaxScroll())
		//{
			//_scrollTop = getVerticalMaxScroll();
		//}
		//else
		//{
			//_scrollTop = value;
		//}
		//
		//updateScroll();
		//
		//return value;
	//}
	//
	///**
	 //* overriden as the scroll width for a block
	 //* box might be its scrollable bounds width
	 //* 
	 //* TODO 4 : should it be only when scrollbars are
	 //* displayed ?
	 //*/
	//override private function get_scrollWidth():Float
	//{
		//if (_scrollableBounds.width > bounds.width)
		//{
			//return _scrollableBounds.width;
		//}
		//
		//return bounds.width;
	//}
	//
	//override private function get_scrollHeight():Float
	//{
		//if (_scrollableBounds.height > bounds.height)
		//{
			//return _scrollableBounds.height;
		//}
		//
		//return bounds.height;
	//}
	//
	//
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
	///**
	 //* Utils method to return the containing block data
	 //* without any scrollbars. Used when positioning scrollbars
	 //* themselves
	 //*/
	//private function getScrollbarContainerBlock():ContainingBlockVO
	//{
		//return super.getContainerBlockData();
	//}
	//
	///**
	 //* Return the maximum amount of scroll in pixels in the
	 //* vertical direcion. Maximum scroll can't be negative
	 //*/
	//private function getVerticalMaxScroll():Float
	//{
		//var maxScroll:Float = _scrollableBounds.height - getContainerBlockData().height;
		//
		//if the container is higher than its children, 
		//then it can't be scrolled
		//if (maxScroll < 0)
		//{
			//return 0;
		//}
		//
		//return maxScroll;
	//}
	//
	///**
	 //* Same as above for horizontal max scroll
	 //*/
	//private function getHorizontalMaxScroll():Float
	//{
		//var maxScroll:Float = _scrollableBounds.width - getContainerBlockData().width;
		//
		//if (maxScroll < 0)
		//{
			//return 0;
		//}
		//
		//return maxScroll;
	//}
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