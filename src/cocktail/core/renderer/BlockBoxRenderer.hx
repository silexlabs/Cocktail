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
	private var _horizontalScrollBar:ScrollBar;
	
	private var _verticalScrollBar:ScrollBar;
	
	//TODO : should be set during formatting, as only 
	//block box establishing context need them
	//must also add positionned element to those bounds, have a
	//separate attribute ?
	private var _scrollableBounds:RectangleData;
	
	//TODO : rename scrollLeft and scrollTop
	private var _scrollX:Float;
	
	private var _scrollY:Float;
	
	/**
	 * class constructor
	 */
	public function new(node:Node) 
	{
		super(node);
		_scrollX = 0;
		_scrollY = 0;
		
		_scrollableBounds = {
			x:0.0,
			y:0.0,
			width:0.0,
			height:0.0
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the in flow children (not positioned) using
	 * this LayerRenderer and return an array of NativeElement
	 * from it
	 */
	public function renderLineBoxes(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var lineBoxes:Array<LineBox> = getChilrenLineBoxes(this, _layerRenderer);

		for (i in 0...lineBoxes.length)
		{
			var nativeElements:Array<NativeElement> = [];
			if (lineBoxes[i].establishesNewFormattingContext() == false)
			{
				lineBoxes[i].render(graphicContext, relativeOffset);
			}
			else
			{	
				//TODO : doc, inlineBlock do not render the child layers, as it only simulates a new
				//layer, will need to do the same thing for floats
				lineBoxes[i].layerRenderer.render(graphicContext, relativeOffset, lineBoxes[i].elementRenderer, false);
			}
		}
		
	}
	
	//TODO : doc
	public function renderBlockReplacedChildren(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var childrenBlockReplaced:Array<ElementRenderer> = getBlockReplacedChildren(this, _layerRenderer);
		
		for (i in 0...childrenBlockReplaced.length)
		{
			childrenBlockReplaced[i].render(graphicContext, relativeOffset);
		}
	}
	
	/**
	 * Render all the block container children of the layer
	 */
	public function renderBlockContainerChildren(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var childrenBlockContainer:Array<ElementRenderer> = getBlockContainerChildren(this, _layerRenderer);

		for (i in 0...childrenBlockContainer.length)
		{
			childrenBlockContainer[i].render(graphicContext, relativeOffset);
		}
	}
	
	public function renderScrollBars(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		if (_horizontalScrollBar != null)
		{
			_horizontalScrollBar.elementRenderer.render(graphicContext, relativeOffset);
			updateScroll();
		}
		
		if (_verticalScrollBar != null)
		{
			_verticalScrollBar.elementRenderer.render(graphicContext, relativeOffset);
			updateScroll();
		}
		

	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return all the in flow children of this LayerRenderer by traversing
	 * recursively the rendering tree
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
	 * Retrieve all the children block container of this LayerRenderer by traversing
	 * recursively the rendering tree.
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
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ElementRenderer
	 * 
	 */
	override private function layoutChildren(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		super.layoutChildren(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		_scrollableBounds = getScrollableBounds();
		attachScrollBarsIfnecessary();
		

	//	TODO : this re-layout should only happen if at least one scrollbar is attached, return bool from attachScrollBarsIfnecessary ?
		//var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
		//var childrenContainingBlockData:ContainingBlockData = getContainerBlockData();
		//var childFirstPositionedAncestorData:FirstPositionedAncestorData = getChildrenFirstPositionedAncestorData(firstPositionedAncestorData);
		//doLayoutChildren(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, _coreStyle.fontMetrics, childrenFormattingContext);
	
	}
	
	/**
	 * Actually layout all the children of the ElementRenderer by calling
	 * the layout method recursively on all the children
	 */
	override private function doLayoutChildren(childrenContainingBlockData:ContainingBlockData, viewportData:ContainingBlockData, childFirstPositionedAncestorData:FirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):Void
	{			
		for (i in 0..._childNodes.length)
		{
			var childElementRenderer:ElementRenderer = cast(_childNodes[i]);
			
			//TODO : clean-up, this is used to send right containing dimensions to scrollbars.
			// also, if both are displayed, how should they now the width/height to withdraw for
			//the corner ?
			if (_horizontalScrollBar != null)
			{
				if (childElementRenderer == _horizontalScrollBar.elementRenderer)
				{
					childrenContainingBlockData.width += _horizontalScrollBar.coreStyle.computedStyle.width;
					childFirstPositionedAncestorData.data = childrenContainingBlockData;
					childElementRenderer.layout(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
				}
			}
			else if (_verticalScrollBar != null)
			{
				if (childElementRenderer == _verticalScrollBar.elementRenderer)
				{
					childrenContainingBlockData.height += _verticalScrollBar.coreStyle.computedStyle.height;
					childFirstPositionedAncestorData.data = childrenContainingBlockData;
					childElementRenderer.layout(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
				}
			}
			childElementRenderer.layout(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer belonging to it. After this call, all the
		//ElementRenderer have the right bounds, in the space of the containing
		//block which established the formatting context
		//
		//This method is only called if a new formatting
		//context was established by this ElementRenderer,
		//meaning that it also is responsible of formatting it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SCROLLING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function isXAxisClipped():Bool
	{
		switch (computedStyle.overflowX)
		{
			case Overflow.hidden,
			Overflow.scroll:
				return true;
				
			case Overflow.cssAuto:
				return _horizontalScrollBar != null;
				
			case Overflow.visible:
				return false;
		}
	}
	
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
				return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SCROLLING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_scrollX():Float 
	{
		return _scrollX;
	}
	
	override private function set_scrollX(value:Float):Float 
	{
		if (value < 0)
		{
			_scrollX = 0;
		}
		else if (value > _scrollableBounds.width)
		{
			_scrollY = Math.round(_scrollableBounds.width);
		}
		else
		{
			_scrollX = value;
		}
		
		updateScroll();
		
		return value;
	}
	
	override private function get_scrollY():Float 
	{
		return _scrollY;
	}
	
	override private function set_scrollY(value:Float):Float 
	{
	
		if (value < 0)
		{
			_scrollY = 0;
		}
		else if (value > _scrollableBounds.height)
		{
			_scrollY = Math.round(_scrollableBounds.height);
		}
		else
		{
			_scrollY = value;
		}
		updateScroll();
		
		return value;
	}
	
	private function updateScroll():Void
	{
		if (isXAxisClipped() == true || isYAxisClipped() == true)
		{
			_layerRenderer.scroll(_scrollX, _scrollY);
		}
		
	}
	
	//TODO : should manage the following case : 
	// - child is relative positioned,
	// - child is absolute positioned
	// - child is fixed positioned or absolute positoned but 
	// block container is parent of this block box renderer and it must
	// not be scrolled and clipped
	private function getScrollableBounds():RectangleData
	{
		return getChildrenBounds(doGetScrollableBounds(this));
	}
	
	//TODO : work but shouldn't have to parse all rendering tree, should done during formatting
	//and then another pass for absolutely positioned children. Maybe this way less expensive in
	//the  end because onlt called when useful ?
	private function doGetScrollableBounds(rootRenderer:ElementRenderer):Array<RectangleData>
	{
		var childrenBounds:Array<RectangleData> = new Array<RectangleData>();

		for (i in 0...rootRenderer.childNodes.length)
		{
			
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
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
		
		return childrenBounds;
		
	}
	
	//TODO : if at least one is attached, should do a new layout, 
	//else the scrollbar is at first 0,0 at first rendering
	//TODO : implement border case where one has scroll attached, and the 
	//other is visible but should still display scroll
	//
	//TODO : should refresh maxScroll n attach scrollbars
	private function attachScrollBarsIfnecessary():Void
	{
		if (canAlwaysOverflow() == true)
		{
			return;
		}

		if (_horizontalScrollBar == null)
		{
			//TODO : should use computed styles but not computed yet
			switch (_coreStyle.overflowX)
			{
				case scroll:
					attachHorizontalScrollBar();
					
				case hidden, visible:
					
				case cssAuto:
					attachHorizontalScrollBarIfNecessary();
			}
		}
		
		if (_verticalScrollBar == null)
		{
			switch (_coreStyle.overflowY)
			{
				case scroll:
					attachVerticalScrollBar();
					
				case hidden, visible:
					
				case cssAuto:
					attachVerticalScrollBarIfNecessary();
			}
		}
	}
	
	private function attachHorizontalScrollBar():Void
	{
		_horizontalScrollBar = new ScrollBar(false);
		_horizontalScrollBar.attach();
		appendChild(_horizontalScrollBar.elementRenderer);
		_horizontalScrollBar.maxScroll = bounds.width;
		_horizontalScrollBar.onscroll = onHorizontalScroll;
	}
	
	private function attachHorizontalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.x < bounds.x || _scrollableBounds.x + _scrollableBounds.width > bounds.x + bounds.width)
		{
			attachHorizontalScrollBar();
		}
	}
	
	private function attachVerticalScrollBar():Void
	{
		_verticalScrollBar = new ScrollBar(true);
		_verticalScrollBar.attach();
		appendChild(_verticalScrollBar.elementRenderer);
		_verticalScrollBar.maxScroll = bounds.height;
		_verticalScrollBar.onscroll = onVerticalScroll;
	}
	
	private function attachVerticalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.y < bounds.y || _scrollableBounds.y + _scrollableBounds.height > bounds.y + bounds.height)
		{
			attachVerticalScrollBar();
		}
	}
	
	private function onHorizontalScroll(event:Event):Void
	{
		scrollX = _horizontalScrollBar.scroll;
	}
	
	private function onVerticalScroll(event:Event):Void
	{
		scrollY = _verticalScrollBar.scroll;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	 * TODO : doc
	 */
	override private function getContainerBlockData():ContainingBlockData
	{
		var width:Int = this.computedStyle.width;
		if (_horizontalScrollBar != null)
		{
			width -= _horizontalScrollBar.coreStyle.computedStyle.width;
		}
		
		var height:Int = this.computedStyle.height;
		if (_verticalScrollBar != null)
		{
			height -= _verticalScrollBar.coreStyle.computedStyle.height;
		}
		
		return {
			width:width,
			isWidthAuto:this._coreStyle.width == Dimension.cssAuto,
			height:height,
			isHeightAuto:this._coreStyle.height == Dimension.cssAuto
		};
	}
	
	//TODO : doc
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
	
	//TODO : should use computed style (for instance for inherit) but not yet computed at this point
	private function canAlwaysOverflow():Bool
	{
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
}