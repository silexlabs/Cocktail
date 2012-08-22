 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import cocktail.core.style.StyleData;

/**
 * A base class for BlockBoxRenderer defining 
 * all the scrollbar and clipping related
 * functionnality
 * 
 * @author Yannick DOMINGUEZ
 */
class ScrollableRenderer extends FlowBoxRenderer
{
	/**
	 * A reference to the horizontal scrollbar which
	 * might be displayed by this BlockBoxRenderer
	 */
	private var _horizontalScrollBar:ScrollBar;
	
	/**
	 * A reference to the vertical scrollbar which
	 * might be displayed by this BlockBoxRenderer
	 */
	private var _verticalScrollBar:ScrollBar;
	
	/**
	 * Those are the bounds of the children (both in-flow and positioned)
	 * of the ElementRenderer, which are used when scrolling the
	 * content of this BlockBoxRenderer
	 */
	private var _scrollableBounds:RectangleData;
	
	/**
	 * Store the amount of scroll in the x axis of this BlockBoxRenderer
	 */
	private var _scrollLeft:Float;
	
	/**
	 * Store the amount of scroll in the y axis of this BlockBoxRenderer
	 */
	private var _scrollTop:Float;
	
	/**
	 * flag set when updating the scroll of the BlockBoxRenderer to prevent
	 * infinite loop caused by Scrollbar updating scroll
	 */
	private var _isUpdatingScroll:Bool;
	
	public function new(domNode:HTMLElement) 
	{
		super(domNode);
		
		_isUpdatingScroll = false;
		
		_scrollLeft = 0;
		_scrollTop = 0;
		
		_scrollableBounds = {
			x:0.0,
			y:0.0,
			width:0.0,
			height:0.0
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to deal with the scrollbars once the children of this
	 * BlockBoxRenderer are laid out
	 */
	override public function layout(forceLayout:Bool):Void
	{	
		super.layout(forceLayout);
		
		//only get scrollable bounds for bloc box renderer
		//which might display scrollbars
		if (canAlwaysOverflow() == false)
		{
			_scrollableBounds = getScrollableBounds();
		}
		
		var isVerticalScrollAttached:Bool = _verticalScrollBar != null;
		var isHorizontalScrollAttached:Bool = _horizontalScrollBar != null;
		
		attachScrollBarsIfnecessary();
		
		if (isVerticalScrollAttached != (_verticalScrollBar != null) || isHorizontalScrollAttached != (_horizontalScrollBar != null) )
		{
			_needsLayout = true;
			_childrenNeedLayout = true;
			super.layout(forceLayout);
		}
		
		layoutScrollBarsIfNecessary(getWindowData());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 4 : more complex thant it should
	private function layoutScrollBarsIfNecessary(viewportData:ContainingBlockData):Void
	{
		var horizontalScrollBarContainerBlockData = getContainerBlockData();
		
		if (_horizontalScrollBar != null)
		{
			horizontalScrollBarContainerBlockData.height += _horizontalScrollBar.coreStyle.usedValues.height;
		}
		
		if (_horizontalScrollBar != null)
		{	
			layoutPositionedChild(_horizontalScrollBar.elementRenderer, horizontalScrollBarContainerBlockData, viewportData);
		}
		
		var verticalScrollBarContainerBlockData = getContainerBlockData();
		
		if (_verticalScrollBar != null)
		{
			verticalScrollBarContainerBlockData.width += _verticalScrollBar.coreStyle.usedValues.width;
		}
		
		if (_verticalScrollBar != null)
		{
			layoutPositionedChild(_verticalScrollBar.elementRenderer, verticalScrollBarContainerBlockData, viewportData);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SCROLLING GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as BlockBoxRenderer might actually be scrolled
	 */
	override private function get_scrollLeft():Float 
	{
		return _scrollLeft;
	}
	
	/**
	 * Overriden as BLockBoxRenderer might actually be scrolled
	 */
	override private function set_scrollLeft(value:Float):Float 
	{
		//negative values are illegal
		if (value <= 0)
		{
			_scrollLeft = 0;
		}
		//if the value if more the available scrollable width, set
		//the value to the max scrollable width
		else if (value > getHorizontalMaxScroll())
		{
			_scrollLeft = getHorizontalMaxScroll();
		}
		else
		{
			_scrollLeft = value;
		}
		
		updateScroll();
		
		return value;
	}
	
	override private function get_scrollTop():Float 
	{
		return _scrollTop;
	}
	
	override private function set_scrollTop(value:Float):Float 
	{
		if (value <= 0)
		{
			_scrollTop = 0;
		}
		else if (value > getVerticalMaxScroll())
		{
			_scrollTop = getVerticalMaxScroll();
		}
		else
		{
			_scrollTop = value;
		}
		
		updateScroll();
		
		return value;
	}
	
	/**
	 * overriden as the scroll width for a block
	 * box might be its scrollable bounds width
	 * 
	 * TODO 4 : should it be only when scrollbars are
	 * displayed ?
	 */
	override private function get_scrollWidth():Float
	{
		if (_scrollableBounds.width > bounds.width)
		{
			return _scrollableBounds.width;
		}
		
		return bounds.width;
	}
	
	override private function get_scrollHeight():Float
	{
		if (_scrollableBounds.height > bounds.height)
		{
			return _scrollableBounds.height;
		}
		
		return bounds.height;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SCROLLING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wheter the x axis of this BlockBoxRenderer
	 * is clipped to its width
	 */
	private function isXAxisClipped():Bool
	{
		switch (coreStyle.overflowX)
		{
			case KEYWORD(value):
				switch(value)
				{
					case HIDDEN, SCROLL:
						return true;
						
					//when overflow is auto, the x axis is only
					//clipped if a scrollbar was attached	
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
			default:
				return false;
		}
	}
	
	/**
	 * Determine wheter the y axis of this BlockBoxRenderer
	 * is clipped to its height
	 */
	private function isYAxisClipped():Bool
	{
		switch (coreStyle.overflowY)
		{
			case KEYWORD(value):
				switch(value)
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
			default:
				return false;
		}
	}
	
	/**
	 * When a scroll value changes, update the rendering
	 */
	private function updateScroll():Void
	{
		//only called if not already updating scroll, else
		//infinite loop with scrollbars
		if (_isUpdatingScroll == false)
		{
			_isUpdatingScroll = true;
			
			if (isXAxisClipped() == true || isYAxisClipped() == true)
			{
				//scroll(_scrollLeft, _scrollTop);
			}
			
			if (_horizontalScrollBar != null)
			{
				_horizontalScrollBar.scroll = scrollLeft;
			}
			if (_verticalScrollBar != null)
			{
				_verticalScrollBar.scroll = scrollTop;
			}
			
			//when scrolling is done, dispatched a scroll
			//event on the dom node
			dispatchScrollEvent();
			
			_isUpdatingScroll = false;
		}
	}
	
	//TODO 2 : should manage the following case : 
	// - child is relative positioned,
	// - child is absolute positioned
	// - child is fixed positioned or absolute positoned but 
	// block container is parent of this block box renderer and it must
	// not be scrolled and clipped. ElementRenderer should be able to know
	//their containing block
	
	/**
	 * Get the bounds of all of the children of this BlockBoxRenderer
	 */
	private function getScrollableBounds():RectangleData
	{
		return getChildrenBounds(doGetScrollableBounds(this));
	}
	
	//TODO 2 : work but shouldn't have to parse all rendering tree, should be done during formatting
	//and then another pass for absolutely positioned children. Maybe this way less expensive in
	//the  end because only called when useful ?
	/**
	 * Get the bounds of all of the children
	 * by traversing the rendering tree
	 */
	private function doGetScrollableBounds(rootRenderer:ElementRenderer):Array<RectangleData>
	{
		var childrenBounds:Array<RectangleData> = new Array<RectangleData>();

		var length:Int = rootRenderer.childNodes.length;
		for (i in 0...length)
		{
			
			var child:ElementRenderer = rootRenderer.childNodes[i];
				
			if (child.domNode != _horizontalScrollBar && child.domNode != _verticalScrollBar)
			{
				if (child.hasChildNodes() == true)
				{
					var childChildrenBounds:Array<RectangleData> = doGetScrollableBounds(child);
					
					var childLength:Int = childChildrenBounds.length;
					for (j in 0...childLength)
					{
						childrenBounds.push(childChildrenBounds[j]);
					}
				}
				
				childrenBounds.push(child.scrollableBounds);
			}
		}
		return childrenBounds;
	}
	
	//TODO 3 : implement border case where one has scroll attached, and the 
	//other is visible but should still display scroll
	/**
	 * Attach the horizontal and vertical scrollbar if they are
	 * needed, based on the overflow style of the BlockBoxRenderer
	 */
	private function attachScrollBarsIfnecessary():Void
	{
		//only try to remove attached scrollbars if both
		//overflow x and y are set to visible
		if (canAlwaysOverflow() == true)
		{
			detachHorizontalScrollBar();
			detachVerticalScrollBar();
			return;
		}
		
		//tries to attach or detach horizontal scrollbar based on x
		//overflow
		switch (coreStyle.getKeyword(coreStyle.overflowX))
		{
			case SCROLL:
				attachHorizontalScrollBar();
				
			case HIDDEN:
				detachHorizontalScrollBar();
				
			case AUTO:
				attachOrDetachHorizontalScrollBarIfNecessary();
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					attachOrDetachHorizontalScrollBarIfNecessary();
				}
				else
				{
					detachHorizontalScrollBar();
				}
				
			default:
				throw "invalid value for overflowX";
		}

		//tries to attach or detach vertical scrolbar based on 
		//overflow y
		switch (coreStyle.getKeyword(coreStyle.overflowY))
		{
			case SCROLL:
				attachVerticalScrollBar();
				
			case HIDDEN:
				detachVerticalScrollBar();
				
			case AUTO:
				attachOrDetachVerticalScrollBarIfNecessary();
				
			case VISIBLE:
				if (treatVisibleOverflowAsAuto() == true)
				{
					attachOrDetachVerticalScrollBarIfNecessary();
				}	
				else
				{
					detachVerticalScrollBar();
				}
				
			default:
				throw "invalid value for overflowY";
		}
	}
	
	/**
	 * Instantiate the horizontal scrollbar DOM element
	 * and attach it to the rendering tree, if it isn't
	 * already attached
	 * 
	 * Listen to scroll event on it to update the
	 * scroll display as needed
	 */
	private function attachHorizontalScrollBar():Void
	{
		if (_horizontalScrollBar == null)
		{
			_horizontalScrollBar = new ScrollBar(false);
			_horizontalScrollBar.ownerDocument = domNode.ownerDocument;
			_horizontalScrollBar.attach();
			appendChild(_horizontalScrollBar.elementRenderer);
			_horizontalScrollBar.onscroll = onHorizontalScroll;
		}
		//refresh the max scroll when a layout of the BlockBoxRenderer happens
		if (_horizontalScrollBar != null)
		{
			_horizontalScrollBar.maxScroll = getHorizontalMaxScroll();
		}
	}
	
	/**
	 * Detach the horizontal scrollbar if it is 
	 * currently displayed
	 */
	private function detachHorizontalScrollBar():Void
	{
		if (_horizontalScrollBar != null)
		{
			removeChild(_horizontalScrollBar.elementRenderer);
			_horizontalScrollBar.onscroll = null;
			_horizontalScrollBar = null;
			
			//reset scroll so that the display don't "jump" if
			//the horizontal scrollbar is attached again
			scrollLeft = 0;
		}
	}
	
	/**
	 * When overflow x is set to auto, only try to attach the horizontal scrollbar
	 * if the children width is superior to the BlockBoxRenderer width, else
	 * try to detach it
	 */
	private function attachOrDetachHorizontalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.x < 0 || _scrollableBounds.x + _scrollableBounds.width > bounds.width)
		{
			attachHorizontalScrollBar();
		}
		else
		{
			detachHorizontalScrollBar();
		}
	}
	
	/**
	 * same as for horizontal scrollbar
	 */
	private function attachVerticalScrollBar():Void
	{
		if (_verticalScrollBar == null)
		{
			_verticalScrollBar = new ScrollBar(true);
			_verticalScrollBar.ownerDocument = domNode.ownerDocument;
			_verticalScrollBar.attach();
			appendChild(_verticalScrollBar.elementRenderer);
			_verticalScrollBar.onscroll = onVerticalScroll;
		}
		if (_verticalScrollBar != null)
		{
			_verticalScrollBar.maxScroll = getVerticalMaxScroll();
		}
	}
	
	/**
	 * same as for horizontal scrollbar
	 */
	private function detachVerticalScrollBar():Void
	{
		if (_verticalScrollBar != null)
		{
			removeChild(_verticalScrollBar.elementRenderer);
			_verticalScrollBar.onscroll = null;
			_verticalScrollBar = null;
			
			//reset scroll so that the display don't "jump" if
			//the vertical scrollbar is attached again
			scrollTop = 0;
		}
	}
	
	/**
	 * same as for horizontal scrollbar
	 */
	private function attachOrDetachVerticalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.y < 0 || _scrollableBounds.y + _scrollableBounds.height >  bounds.height)
		{
			attachVerticalScrollBar();
		}
		else
		{
			detachVerticalScrollBar();
		}
	}
	
	/**
	 * Update scroll left when a scroll event
	 * is displateched by the horizontal scrollbar
	 */
	private function onHorizontalScroll(event:Event):Void
	{
		scrollLeft = _horizontalScrollBar.scroll;
	}
	
	/**
	 * same as for horizontal scrollbar
	 */
	private function onVerticalScroll(event:Event):Void
	{
		scrollTop = _verticalScrollBar.scroll;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Wether a vertical active scrollbar is displayed and
	 * scrollable. It is not considered scrollable if the
	 * provided scroll offset wouldn't make it scroll, for
	 * intance if scrollTop is 0 and the provided offset is -10,
	 * it won't make it scroll
	 * 
	 * TODO 3 : must return false if scrollbar disabled
	 */
	override public function isVerticallyScrollable(scrollOffset:Int):Bool
	{
		if (_verticalScrollBar == null)
		{
			return false;
		}
		if (scrollOffset < 0)
		{
			if (scrollTop >= _scrollableBounds.height - getContainerBlockData().height)
			{
				return false;
			}
		}
		else if (scrollOffset > 0)
		{
			if (scrollTop <= 0)
			{
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * same as above for horizontal scrollbar
	 */
	override public function isHorizontallyScrollable(scrollOffset:Int):Bool
	{
		if (_horizontalScrollBar == null)
		{
			return false;
		}
		
		if (scrollOffset < 0)
		{
			if (scrollLeft >= _scrollableBounds.width - getContainerBlockData().width)
			{
				return false;
			}
		}
		else if (scrollOffset > 0)
		{
			if (scrollLeft <= 0)
			{
				return false;
			}
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method to return the containing block data
	 * without any scrollbars. Used when positioning scrollbars
	 * themselves
	 */
	private function getScrollbarContainerBlock():ContainingBlockData
	{
		return super.getContainerBlockData();
	}
	
	/**
	 * Return the maximum amount of scroll in pixels in the
	 * vertical direcion. Maximum scroll can't be negative
	 */
	private function getVerticalMaxScroll():Float
	{
		var maxScroll:Float = _scrollableBounds.height - getContainerBlockData().height;
		
		//if the container is higher than its children, 
		//then it can't be scrolled
		if (maxScroll < 0)
		{
			return 0;
		}
		
		return maxScroll;
	}
	
	/**
	 * Same as above for horizontal max scroll
	 */
	private function getHorizontalMaxScroll():Float
	{
		var maxScroll:Float = _scrollableBounds.width - getContainerBlockData().width;
		
		if (maxScroll < 0)
		{
			return 0;
		}
		
		return maxScroll;
	}
	
	/**
	 * Utils method dispatching a Scroll event
	 * on the dom node after a scrolling occured
	 */
	private function dispatchScrollEvent():Void
	{
		var scrollEvent:UIEvent = new UIEvent();
		scrollEvent.initUIEvent(UIEvent.SCROLL, mustBubbleScrollEvent(), false, null, 0.0);
		domNode.dispatchEvent(scrollEvent);
	}
	
	/**
	 * Utils method determining wether the dispatched scroll
	 * event must bubble. Scroll event only bubbles 
	 * when dispatched on the HTMLHTMLElement, as it
	 * needs to bubble to the Document and Window
	 * objects
	 */
	private function mustBubbleScrollEvent():Bool
	{
		return false;
	}
	
	/**
	 * Determine wether this BlockBoxRenderer always overflows
	 * in both x and y axis. If either overflow x or y
	 * is deifferent from visible, then it is considered to
	 * not always overflow
	 */
	private function canAlwaysOverflow():Bool
	{
		if (treatVisibleOverflowAsAuto() == true)
		{
			return false;
		}
		
		switch (coreStyle.getKeyword(coreStyle.overflowX))
		{
			case VISIBLE:
				
			default:
				return false;
		}
		
		switch (coreStyle.getKeyword(coreStyle.overflowY))
		{
			case VISIBLE:
				
			default:
				return false;
		}
		
		return true;
	}
	
	/**
	 * This helper method is used to differentiate between
	 * a block box renderer and the initial block box renderer.
	 * 
	 * For the initial block box renderer, a computed value
	 * of visible for overflow behaves the same as a computed
	 * value of auto
	 */
	private function treatVisibleOverflowAsAuto():Bool
	{
		return false;
	}
}