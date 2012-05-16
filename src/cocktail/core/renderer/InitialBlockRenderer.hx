/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.style.CoreStyle;
import flash.display.Sprite;
import flash.Lib;
import haxe.Log;
import haxe.Timer;

/**
 * This is the ElementRenderer generated by a BodyHTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialBlockRenderer extends BlockBoxRenderer
{
	
	
	/**
	 * class constructor. Set the viewport as the bounds
	 * of the ElementRenderer, as a BodyHTMLElement
	 * always covers all of the viewport
	 */
	public function new(node:Node) 
	{
		super(node);
		
		

		
		//in Flash, the Stage is always defined as no scale as the transformations
		//will be managed by Cocktail
		
		flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
	}
	

	
	override public function attachLayer():Void
	{
		_layerRenderer = new LayerRenderer(this);
	}
	
	
	
	
	override private function attachVerticalScrollBarIfNecessary():Void
	{
		if (_scrollableBounds.y < bounds.y || _scrollableBounds.y + _scrollableBounds.height > cocktail.Lib.window.innerHeight)
		{
			attachVerticalScrollBar();
		}
	}
	
	//TODO : a lot of dublicate code with BlockBoxRenderer
	override private function attachScrollBarsIfnecessary():Void
	{
		

		if (_horizontalScrollBar == null)
		{
			//TODO : should use computed styles but not computed yet
			switch (_coreStyle.overflowX)
			{
				case scroll:
					attachHorizontalScrollBar();
					
				case hidden:
					
				case cssAuto, visible:
					attachHorizontalScrollBarIfNecessary();
			}
		}
		if (_horizontalScrollBar != null)
		{
			_horizontalScrollBar.maxScroll = _scrollableBounds.width - bounds.width;
		}
		
		if (_verticalScrollBar == null)
		{
			switch (_coreStyle.overflowY)
			{
				case scroll:
					attachVerticalScrollBar();
					
				case hidden:
					
					case cssAuto, visible:
					attachVerticalScrollBarIfNecessary();
			}
		}
		if (_verticalScrollBar != null)
		{
			_verticalScrollBar.maxScroll = _scrollableBounds.height - bounds.height;
		}
	}
	
	override public function isXAxisClipped():Bool
	{
		switch (computedStyle.overflowX)
		{
			case Overflow.hidden,
			Overflow.scroll:
				return true;
				
			case Overflow.cssAuto, visible:
				return _horizontalScrollBar != null;
				
			
		}
	}
	
	override public function isYAxisClipped():Bool
	{
		switch (computedStyle.overflowY)
		{
			case Overflow.hidden,
			Overflow.scroll:
				return true;
				
			case Overflow.cssAuto, visible:
				return _verticalScrollBar != null;
				
		
		}
	}
	
	override private function get_globalBounds():RectangleData
	{
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		return {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The HTMLBodyElement doesn't have a parent, so when invalidated,
	 * it always schedule a layout using the window dimensions as
	 * its containing HTMLElement dimensions
	 */
	override public function invalidateLayout(immediate:Bool = false):Void
	{
		//don't call if the body has already scheduled a layout, unless
		//an immediate layout is required
		if (this._isLayingOut == false || immediate == true)
		{
			this._isLayingOut = true;
			doInvalidate(immediate);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The Document is invalidated for instance when the
	 * DOM changes after adding/removing a child or when
	 * a style changes.
	 * When this happen, the Document needs to be layout
	 * and rendered again
	 * 
	 * @param immediate define wether the layout must be synchronous
	 * or asynchronous
	 */
	private function doInvalidate(immediate:Bool = false):Void
	{
		//either schedule an asynchronous layout and rendering, or layout
		//and render immediately
		if (immediate == false)
		{
			scheduleLayoutAndRender();
		}
		else
		{
			layoutAndRender();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * As the name implies,
	 * layout the DOM, then render it
	 */
	private function layoutAndRender():Void
	{
		startLayout();
		startRendering();
	}
	
	/**
	 * Start the rendering of the rendering tree
	 * built during layout
	 * and attach the resulting nativeElements (background,
	 * border, embedded asset...) to the display root
	 * of the runtime (for instance the Stage in Flash)
	 */ 
	private function startRendering():Void
	{
		//start the rendering at the root layer renderer
		_layerRenderer.render(Lib.current, {x:0.0, y:0.0});
	}
	
	/**
	 * Set a timer to trigger a layout and rendering of the HTML Document asynchronously.
	 * Setting a timer to execute the layout and rendering ensure that the layout only happen once when a series of style
	 * values are set or when many elements are attached/removed from the DOM, instead of happening for every change.
	 */
	private function scheduleLayoutAndRender():Void
	{
		var layoutAndRenderDelegate:Void->Void = layoutAndRender;
		
		//calling the methods 1 millisecond later is enough to ensure
		//that first all synchronous code is executed
		Timer.delay(function () { 
			layoutAndRenderDelegate();
		}, 1);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as the initial ElementRenderer always layout its positioned children as it is the root of the rendering tree
	 * 	
	 * TODO : check that the childrenFirstPositionedAncestorData data is the viewport data
	 */
	override private function layoutAbsolutelyPositionedChildrenIfNeeded(childrenFirstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{
		for (i in 0...childrenFirstPositionedAncestorData.elements.length)
		{
			var element:ElementRenderer = childrenFirstPositionedAncestorData.elements[i];
			//use the viewport dimensions both times
			layoutPositionedChild(element, childrenFirstPositionedAncestorData.data, viewportData);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrieve the data of the viewport. The viewport
	 * origin is always to the top left of the window
	 * displaying the document
	 */
	override private function getWindowData():ContainingBlockData
	{	
		
		var windowData:ContainingBlockData = {
			isHeightAuto:false,
			isWidthAuto:false,
			width:cocktail.Lib.window.innerWidth,
			height:cocktail.Lib.window.innerHeight
		}
		
		if (_verticalScrollBar != null)
		{
			windowData.width -= _verticalScrollBar.coreStyle.computedStyle.width;
		}
		
		if (_horizontalScrollBar != null)
		{
			windowData.height -= _horizontalScrollBar.coreStyle.computedStyle.height;
		}
		
		return windowData;
	}
	
	/**
	 * TODO : doc
	 */
	override private function getContainerBlockData():ContainingBlockData
	{
		return getWindowData();
	}
	
	/**
	 * The initital ElementRenderer is always a block container
	 */
	override public function isInlineLevel():Bool
	{
		return false;
	}
	
	
	/**
	 * The root of the runtime always starts a block formatting context
	 */
	override private function getFormattingContext(previousformattingContext:FormattingContext):FormattingContext
	{
		return new BlockFormattingContext(this);
	}
	
	/**
	 * The HTMLBodyElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
	override private function get_bounds():RectangleData
	{
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		
		return {
			x:0.0,
			y:0.0,
			width:width,
			height:height
		};
	}
	
}