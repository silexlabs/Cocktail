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
	private var _horizontalScrollBar:HTMLElement;
	
	private var _verticalScrollBar:HTMLElement;
	
	//TODO : should be set during formatting, as only 
	//block box establishing context need them
	//must also add positionned element to those bounds, have a
	//separate attribute ?
	private var _scrollableBounds:RectangleData;
	
	/**
	 * class constructor
	 */
	public function new(node:Node) 
	{
		super(node);
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
		attachScrollBarsIfnecessary();
	}
	
	private function getScrollableBounds():RectangleData
	{
		return { x:0.0, y:0.0, width:500.0, height:500.0 };
	}
	
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
		_horizontalScrollBar.onscroll = onHorizontalScroll;
	}
	
	private function attachHorizontalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.x < _bounds.x || _scrollableBounds.x + _scrollableBounds.width > _bounds.x + _bounds.width)
		{
			attachHorizontalScrollBar();
		}
	}
	
	private function attachVerticalScrollBar():Void
	{
		_verticalScrollBar = new ScrollBar(true);
		_verticalScrollBar.attach();
		appendChild(_verticalScrollBar.elementRenderer);
		_verticalScrollBar.onscroll = onVerticalScroll;
	}
	
	private function attachVerticalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.y < _bounds.y || _scrollableBounds.y + _scrollableBounds.height > _bounds.y + _bounds.height)
		{
			attachVerticalScrollBar();
		}
	}
	
	private function onHorizontalScroll(event:Event):Void
	{
		
	}
	
	private function onVerticalScroll(event:Event):Void
	{
		
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
}