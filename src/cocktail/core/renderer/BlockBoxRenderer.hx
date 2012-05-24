 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.NativeElement;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.formatter.InlineFormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * A block box renderer is an element which participate
 * in a block formatting context and which can establish
 * either a block or inline formatting context.
 * 
 * When it starts an inline formatting context, it holds
 * an array of root line box which are the start of
 * each of the lines created by this block box.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockBoxRenderer extends FlowBoxRenderer
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
	
	/**
	 * class constructor.
	 * Init class attributes
	 */
	public function new(node:Node) 
	{
		super(node);
		
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
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as when an ElementRenderer is appended, its LayerRenderer
	 * must be attached so that it can be rendered
	 */
	override public function appendChild(newChild:Node):Node
	{
	
		var shouldMakeChildrenNonInline:Bool = false;
		var elementRendererChild:ElementRenderer = cast(newChild);
	
		if (_childNodes.length > 0)
		{
			if (elementRendererChild.isInlineLevel() != childrenInline())
			{
				shouldMakeChildrenNonInline = true;
			}
		}
		
		if (elementRendererChild.isAnonymousBlockBox() == true)
		{
			shouldMakeChildrenNonInline = false;
		}
		
		super.appendChild(newChild);
		
		if (shouldMakeChildrenNonInline == true)
		{	
			//makeChildrenNonInline();
		
			
		}
	
		return newChild;
	}
	
	private function makeChildrenNonInline():Void
	{
		for (i in 0..._childNodes.length)
		{
			var child:ElementRenderer = cast(_childNodes[i]);

			if (child.isInlineLevel() == true)
			{
				
				
				var anonymousBlock:AnonymousBlockBoxRenderer = createAnonymousBlock();
				
				replaceChild(anonymousBlock, child);
				anonymousBlock.appendChild(child);
				
				
			}
		}
		
	}
	
	override public function insertBefore(newChild:Node, refChild:Node):Node
	{
		if (refChild == null)
		{
			appendChild(newChild);
		}
		else
		{
			
			for (i in 0..._childNodes.length)
			{
				var child:ElementRenderer = cast(_childNodes[i]);
	
				if (_childNodes[i] == refChild)
				{
					
					appendChild(newChild);
				}
				else if (child.isAnonymousBlockBox() == true)
				{
					if (child.firstChild != null)
					{
						if (child.firstChild == refChild)
						{
							appendChild(newChild);
						}
					}
				}
				
				appendChild(child);
			}
		}
		
		
		
		return newChild;
	}
	
	private function createAnonymousBlock():AnonymousBlockBoxRenderer
	{
		var anonymousBlock:AnonymousBlockBoxRenderer = new AnonymousBlockBoxRenderer(_node);
		
		anonymousBlock.coreStyle = new CoreStyle(cast(_node));
		
		return anonymousBlock;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the LineBoxes created by this BlockBoxRenderer, using
	 * the graphic context as canvas. A BlockBoxRenderer can only have
	 * LineBoxes if it establishes an inline formatting context
	 */
	public function renderLineBoxes(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		//retrieve all the line boxes in all of the lines generated in this BlockBoxRenderer
		var lineBoxes:Array<LineBox> = getChilrenLineBoxes(this, _layerRenderer);

		//loop in all of the lineboxes
		for (i in 0...lineBoxes.length)
		{
			if (lineBoxes[i].establishesNewFormattingContext() == false)
			{
				lineBoxes[i].render(graphicContext, relativeOffset);
			}
			//if the line box establishes a new formatting context, it is displayed as an inline-block
			//which are rendered as if they started a new layerRenderer themselves
			else
			{	
				lineBoxes[i].layerRenderer.render(graphicContext, relativeOffset, lineBoxes[i].elementRenderer, false);
			}
		}
		
	}
	
	/**
	 * Render the replaced children of this BlockBoxRenderer which are displayed as blocks, such
	 * as an HTMLImageElement with a display style of 'block'
	 */
	public function renderBlockReplacedChildren(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var childrenBlockReplaced:Array<ElementRenderer> = getBlockReplacedChildren(this, _layerRenderer);
		for (i in 0...childrenBlockReplaced.length)
		{
			childrenBlockReplaced[i].render(graphicContext, relativeOffset);
		}
	}
	
	/**
	 * Render all the block children of this BlockBoxRenderer
	 */
	public function renderBlockContainerChildren(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var childrenBlockContainer:Array<ElementRenderer> = getBlockContainerChildren(this, _layerRenderer);

		for (i in 0...childrenBlockContainer.length)
		{
			childrenBlockContainer[i].render(graphicContext, relativeOffset);
		}
	}
	
	/**
	 * Render the scrollbars of this BlockBoxRenderer as needed
	 */
	public function renderScrollBars(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		
		if (_horizontalScrollBar != null)
		{
			_horizontalScrollBar.elementRenderer.layerRenderer.render(graphicContext, relativeOffset);
			
			updateScroll();

		}
		
		if (_verticalScrollBar != null)
		{
			_verticalScrollBar.elementRenderer.layerRenderer.render(graphicContext, relativeOffset);
			updateScroll();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return all the in line boxes of this BlockBoxRenderer, by traversing
	 * the rendering tree
	 * 
	 * TODO : can probably be simplified
	 */
	private function getChilrenLineBoxes(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		if (rootRenderer.establishesNewFormattingContext() == true && rootRenderer.childrenInline() == true)
		{
			var blockBoxRenderer:BlockBoxRenderer = cast(rootRenderer);
			
			for (i in 0...blockBoxRenderer.lineBoxes.length)
			{
				var lineBoxes:Array<LineBox> = getLineBoxesInLine(blockBoxRenderer.lineBoxes[i]);
				for (j in 0...lineBoxes.length)
				{
					if (lineBoxes[j].layerRenderer == referenceLayer)
					{
						ret.push(lineBoxes[j]);
					}
				}
			}
		}
		else
		{
			for (i in 0...rootRenderer.childNodes.length)
			{
				var child:ElementRenderer = cast(rootRenderer.childNodes[i]);

				if (child.layerRenderer == referenceLayer)
				{
					if (child.isPositioned() == false)
					{	
						if (child.isReplaced() == false)
						{	
							var childLineBoxes:Array<LineBox> = getChilrenLineBoxes(child, referenceLayer);
							for (j in 0...childLineBoxes.length)
							{
								ret.push(childLineBoxes[j]);
							}
						}
					}
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Return all the replaced block children of the BlockBoxRenderer by traversing the rendering
	 * tree
	 */
	private function getBlockReplacedChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...rootRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
			
			if (child.layerRenderer == referenceLayer)
			{
				//TODO : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.display == block)
				{
					var childElementRenderer:Array<ElementRenderer> = getBlockReplacedChildren(child, referenceLayer);
					
					for (j in 0...childElementRenderer.length)
					{
						ret.push(childElementRenderer[j]);
					}
				}
				else if (child.coreStyle.display == block)
				{
					ret.push(child);
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Return all the block children of the BlockBoxRenderer by traversing the rendering
	 * tree
	 */
	private function getBlockContainerChildren(rootRenderer:ElementRenderer, referenceLayer:LayerRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...rootRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);

			if (child.layerRenderer == referenceLayer)
			{
				//TODO : must add more condition, for instance, no float
				if (child.isReplaced() == false && child.coreStyle.display != inlineBlock)
				{
					ret.push(cast(child));
					
					var childElementRenderer:Array<ElementRenderer> = getBlockContainerChildren(child, referenceLayer);
					
					for (j in 0...childElementRenderer.length)
					{
						ret.push(childElementRenderer[j]);
					}
				}
			}
		}
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to deal with the scrollbars once the children of this
	 * BlockBoxRenderer are laid out
	 */
	override public function layout(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		
	
		
		super.layout(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		
		_isLayingOut = true;

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
			super.layout(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		}
		
		layoutScrollBarsIfNecessary(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);

		_isLayingOut = false;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : more complex thant it should
	private function layoutScrollBarsIfNecessary(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		var horizontalScrollBarContainerBlockData = getContainerBlockData();
		
		if (_horizontalScrollBar != null)
		{
			horizontalScrollBarContainerBlockData.height += _horizontalScrollBar.coreStyle.computedStyle.height;
		}
		
		if (_horizontalScrollBar != null)
		{	
			layoutPositionedChild(_horizontalScrollBar.elementRenderer, horizontalScrollBarContainerBlockData, viewportData);
		}
		
		var verticalScrollBarContainerBlockData = getContainerBlockData();
		
		if (_verticalScrollBar != null)
		{
			verticalScrollBarContainerBlockData.width += _verticalScrollBar.coreStyle.computedStyle.width;
		}
		
		if (_verticalScrollBar != null)
		{
			//TODO : x and y position of scrollbar are false when block box is not positioned, as the scrollbar
			//are positioned relative to the first positioned ancestor
			layoutPositionedChild(_verticalScrollBar.elementRenderer, verticalScrollBarContainerBlockData, viewportData);
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SCROLLING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wheter the x axis of this BlockBoxRenderer
	 * is clipped to its width
	 */
	public function isXAxisClipped():Bool
	{
		switch (computedStyle.overflowX)
		{
			case Overflow.hidden,
			Overflow.scroll:
				return true;
				
			//when overflow is auto, the x axis is only
			//clipped if a scrollbar was attached
			case Overflow.cssAuto:
				return _horizontalScrollBar != null;
				
			case Overflow.visible:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return _horizontalScrollBar != null;
				}
				return false;
		}
	}
	
	/**
	 * Determine wheter the y axis of this BlockBoxRenderer
	 * is clipped to its height
	 */
	public function isYAxisClipped():Bool
	{
		switch (computedStyle.overflowY)
		{
			case Overflow.hidden,
			Overflow.scroll:
				return true;
				
			case Overflow.cssAuto:
				return _verticalScrollBar != null;
				
			case Overflow.visible:
				if (treatVisibleOverflowAsAuto() == true)
				{
					return _verticalScrollBar != null;
				}
				return false;
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
	 * TODO : should it be only when scrollbars are
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
	 * When a scroll value changes, update the rendering
	 * 
	 * TODO 1 : when resizing the viewport, the scroll bars
	 * no longer work unless new scrollbars are displayed
	 * in the viewport
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
				_layerRenderer.scroll(_scrollLeft, _scrollTop);
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
	
	//TODO : should manage the following case : 
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
	
	//TODO : work but shouldn't have to parse all rendering tree, should be done during formatting
	//and then another pass for absolutely positioned children. Maybe this way less expensive in
	//the  end because only called when useful ?
	/**
	 * Get the bounds of all of the children
	 * by traversing the rendering tree
	 */
	private function doGetScrollableBounds(rootRenderer:ElementRenderer):Array<RectangleData>
	{
		var childrenBounds:Array<RectangleData> = new Array<RectangleData>();

		for (i in 0...rootRenderer.childNodes.length)
		{
			
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
			
			if (child.node != _horizontalScrollBar && child.node != _verticalScrollBar)
			{
				if (child.hasChildNodes() == true && child.establishesNewFormattingContext() == false)
				{
					var childChildrenBounds:Array<RectangleData> = doGetScrollableBounds(child);
					
					for (j in 0...childChildrenBounds.length)
					{
						childrenBounds.push(childChildrenBounds[j]);
						
					}
				}
				
				childrenBounds.push(child.bounds);
			}
		}

		return childrenBounds;
	}
	
	//TODO : implement border case where one has scroll attached, and the 
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
		

		//TODO : should use computed styles but not computed yet
		//tries to attach or detach horizontal scrollbar based on x
		//overflow
		switch (_coreStyle.overflowX)
		{
			case scroll:
				attachHorizontalScrollBar();
				
			case hidden:
				detachHorizontalScrollBar();
				
			case cssAuto:
				attachOrDetachHorizontalScrollBarIfNecessary();
				
			case visible:
				if (treatVisibleOverflowAsAuto() == true)
				{
					attachOrDetachHorizontalScrollBarIfNecessary();
				}
				else
				{
					detachHorizontalScrollBar();
				}
		}

		//tries to attach or detach vertical scrolbar based on 
		//overflow y
		switch (_coreStyle.overflowY)
		{
			case scroll:
				attachVerticalScrollBar();
				
			case hidden:
				detachVerticalScrollBar();
				
			case cssAuto:
				attachOrDetachVerticalScrollBarIfNecessary();
				
			case visible:
				if (treatVisibleOverflowAsAuto() == true)
				{
					attachOrDetachVerticalScrollBarIfNecessary();
				}	
				else
				{
					detachVerticalScrollBar();
				}
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
		if (_scrollableBounds.x < bounds.x || _scrollableBounds.x + _scrollableBounds.width > bounds.x + bounds.width)
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
			_verticalScrollBar.attach();
			appendChild(_verticalScrollBar.elementRenderer);
			_verticalScrollBar.onscroll = onVerticalScroll;
			
			var htmlElement:HTMLElement = cast(_node);
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
			_verticalScrollBar.detach();
			_verticalScrollBar.onscroll = null;
			
			var htmlElement:HTMLElement = cast(_node);
			
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
		if (_scrollableBounds.y < bounds.y || _scrollableBounds.y + _scrollableBounds.height > bounds.y + bounds.height)
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
	
	/**
	 * Determine wether the ElementRenderer
	 * establishes a new formatting context for
	 * its children or participate in its
	 * parent formatting context
	 */
	override public function establishesNewFormattingContext():Bool
	{
		var establishesNewFormattingContext:Bool = false;
		
		//floats always establishes new formatting context
		if (isFloat() == true)
		{
			establishesNewFormattingContext = true;
		}
		//block box renderer which may use scrollbars to display
		//their children always establishes a new formatting context
		else if (canAlwaysOverflow() == false)
		{
			establishesNewFormattingContext = true;
		}
		//positioned element which are not relative always establishes new context
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			establishesNewFormattingContext = true;
		}
		else
		{
			switch (this.computedStyle.display)
			{
				//element with an inline-block display style
				//always establishes a new context
				case inlineBlock:
				establishesNewFormattingContext = true; 
				
				//a block ElementRenderer may start a new inline
				//formatting context if all its children are inline,
				//else it participates in the current block formatting
				//context
				case block:
					if (childrenInline() == true)
					{
						establishesNewFormattingContext = true;
					}
					
				default:
			}
		}
		
		//in the other cases, the block particpates in its parent's
		//formatting context
		
		return establishesNewFormattingContext;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden, as if scrollbars are displayed, their 
	 * width or height must be substracted from the containing
	 * block width/height
	 */
	override private function getContainerBlockData():ContainingBlockData
	{
		var height:Int = this.computedStyle.height;
		if (_horizontalScrollBar != null)
		{
			height -= _horizontalScrollBar.coreStyle.computedStyle.height;
		}
		
		var width:Int = this.computedStyle.width;
		if (_verticalScrollBar != null)
		{
			width -= _verticalScrollBar.coreStyle.computedStyle.width;
		}
		
		return {
			width:width,
			isWidthAuto:this._coreStyle.width == Dimension.cssAuto,
			height:height,
			isHeightAuto:this._coreStyle.height == Dimension.cssAuto
		};
	}
	
	/**
	 * Overriden as BlockBoxRenderer can also starts a new stacking context
	 * if the overflow x or y style value is different from visible
	 */
	override private function establishesNewStackingContext():Bool
	{
		var establishesNewStackingContext:Bool = super.establishesNewStackingContext();
		
		if (establishesNewStackingContext == true)
		{
			return true;
		}
		return canAlwaysOverflow() != true;
	}
	
	/**
	 * Return the right formatting context to layout this ElementRenderer's
	 * children. Overriden as block box are the only sub class of ElementRenderer
	 * which can establishe a new formatting context
	 */
	override private function getFormattingContext(previousformattingContext:FormattingContext):FormattingContext
	{
		var formattingContext:FormattingContext;
		
		//here, a new formatting context is created
		if (establishesNewFormattingContext() == true)
		{	
			//instantiate the right formatting context
			//based on the children computed display styles
			if (childrenInline() == true)
			{
				formattingContext = new InlineFormattingContext(this);	
			}
			else
			{
				formattingContext = new BlockFormattingContext(this);
			}
		}
		else
		{
			formattingContext = previousformattingContext;
		}
		
		return formattingContext;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
		_node.dispatchEvent(scrollEvent);
	}
	
	/**
	 * Utils method determining wether the dispatched scroll
	 * event must bubble. Scroll event only bubbles 
	 * when dispatched on the HTMLBodyElement, as it
	 * needs to bubble to the Document and Window
	 * objects
	 */
	private function mustBubbleScrollEvent():Bool
	{
		return false;
	}
	
	//TODO : should use computed style (for instance for inherit) but not yet computed at this point, when
	//called from establishesNewStackingContext
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
		
		switch (_coreStyle.overflowX)
		{
			case Overflow.visible:
				
				
			default:
				return false;
		}
		
		switch (_coreStyle.overflowY)
		{
			case Overflow.visible:
				
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as scrollbar shuold be removed from 
	 * the width and height of the bounds of this
	 * ElementRenderer
	 */
	override private function get_globalBounds():RectangleData
	{
		var globalBounds:RectangleData = super.get_globalBounds();
		
		if (_horizontalScrollBar != null)
		{
			//globalBounds.height -= _horizontalScrollBar.coreStyle.computedStyle.height;
		}
		
		if (_verticalScrollBar != null)
		{
			//globalBounds.width -= _verticalScrollBar.coreStyle.computedStyle.width;
		}
		
		return globalBounds;
	}
}