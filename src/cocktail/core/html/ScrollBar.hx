/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.event.Event;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.ScrollBarRenderer;
import cocktail.Lib;
import haxe.Log;

/**
 * This HTMLElement is a scrollbar displayed as needed when the content
 * of a BlockBoxRenderer overflows. It might be displayed as horizontal 
 * or vertical.
 * 
 * It is part of the Shadow DOM, meaning that it won't appear in the public
 * DOM tree, as it is owned and instantiated by a BlockBoxRenderer when needed.
 * This allows styling it like any other DOM tree HTMLElement without polluting
 * the public DOM tree
 * 
 * TODO 2 : implement disabled scrollbar when maxScroll is smaller than scroll height / width
 * 
 * TODO 3 : reproducing Windows look and feel, is this what we want ?
 * 
 * @author Yannick DOMINGUEZ
 */
class ScrollBar extends HTMLElement
{
	/**
	 * The amount of scroll offset to add or remove when the up
	 * or down arrow is clicked
	 */
	private static inline var ARROW_SCROLL_OFFSET:Int = 10;
	
	/**
	 * The amount of scroll offset to add or remove the
	 * track is clicked
	 */
	private static inline var TRACK_SCROLL_OFFSET:Int = 50;
	
	private static inline var THUMB_DEFAULT_DIMENSION:Int = 16;
	
	private static inline var ARROW_DEFAULT_DIMENSION:Int = 16;
	
	private static inline var TRACK_DEFAULT_DIMENSION:Int = 16;
	
	/**
	 * wether tht scrollbar should be displayed vertically
	 */
	private var _isVertical:Bool;
	
	/**
	 * The current scroll offset of the scroll bar
	 */
	private var _scroll:Float;
	public var scroll(get_scroll, set_scroll):Float;
	
	/**
	 * The maximum scroll offset of the scrollbar, corresponding
	 * to the height or width bounds of the children of the
	 * BlockBoxRenderer owning the ScrollBar
	 */
	private var _maxScroll:Float;
	public var maxScroll(get_maxScroll, set_maxScroll):Float;
	
	/**
	 * A reference to the thumb of the scroll
	 */
	private var _scrollThumb:HTMLElement;
	
	/**
	 * A reference to the up arrow of the scroll, for
	 * an horizontal scrollbar, it is displayed on the left
	 */
	private var _upArrow:HTMLElement;
	
	/**
	 * A reference to the down arrow of the scroll,
	 * for an horizontal scrollbar it is displayed on the right
	 */
	private var _downArrow:HTMLElement;
	
	/**
	 * When the thumb of the scrollbar is clicked, store
	 * the x or y position of the mouse so that it 
	 * can be used to compute the delta of each subsequent
	 * mouse move
	 */
	private var _mouseMoveStart:Float;
	
	private var _thumbMoveDelegate:MouseEvent->Void;
	
	private var _thumbUpDelegate:MouseEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor. Init class parameter. 
	 * Instantiate and attach scrollbar parts
	 */
	public function new(isVertical:Bool) 
	{
		_isVertical = isVertical;
		
		super(HTMLConstants.HTML_DIV_TAG_NAME);
		
		//create through factory method so they can have a reference
		//to the Document
		_scrollThumb = Lib.document.createElement(HTMLConstants.HTML_DIV_TAG_NAME);
		_upArrow = Lib.document.createElement(HTMLConstants.HTML_DIV_TAG_NAME);
		_downArrow = Lib.document.createElement(HTMLConstants.HTML_DIV_TAG_NAME);
	
		_scroll = 0;
		_maxScroll = 0;
		_mouseMoveStart = 0;
		
		//style the scrollbar parts for vertical
		//or horizontal scrollbar
		initScrollBar();
		
		if (_isVertical)
		{
			initVerticalScrollBar();
		}
		else
		{
			initHorizontalScrollBar();
		}
		
		//attach the different scrollbar parts
		appendChild(_scrollThumb);
		appendChild(_upArrow);
		appendChild(_downArrow);
		
		//set callbacks on the scrollbar parts
		//TODO 2 : should be cleaned-up when detached, should keep ref to all the callback
		addEventListener(MouseEvent.MOUSE_DOWN, cast(onTrackMouseDown));
		_scrollThumb.addEventListener(MouseEvent.MOUSE_DOWN, cast(onThumbMouseDown));
		_downArrow.addEventListener(MouseEvent.MOUSE_DOWN, cast(onDownArrowMouseDown));
		_upArrow.addEventListener(MouseEvent.MOUSE_DOWN, cast(onUpArrowMouseDown));
	}
	
	/**
	 * style the scrollbar working for horizontal
	 * and vertical scrollbar
	 */
	private function initScrollBar():Void
	{
		style.backgroundColor = "#DDDDDD";
		style.display = "block";
		style.position = "absolute";
		
		_scrollThumb.style.backgroundColor = "#AAAAAA";
		_scrollThumb.style.position = "absolute";
		_scrollThumb.style.display = "block";
		_scrollThumb.style.width = THUMB_DEFAULT_DIMENSION +"px";
		_scrollThumb.style.height = THUMB_DEFAULT_DIMENSION + "px";
		
		_upArrow.style.backgroundColor = "#CCCCCC";
		_upArrow.style.position = "absolute";
		_upArrow.style.display = "block";
		_upArrow.style.width = ARROW_DEFAULT_DIMENSION +"px";
		_upArrow.style.height = ARROW_DEFAULT_DIMENSION + "px";
		
		_downArrow.style.backgroundColor = "#CCCCCC";
		_downArrow.style.position = "absolute";
		_downArrow.style.display = "block";
		_downArrow.style.width = ARROW_DEFAULT_DIMENSION + "px";
		_downArrow.style.height = ARROW_DEFAULT_DIMENSION + "px";
		
	}
	
	/**
	 * style as a vertical scrollbar
	 */
	private function initVerticalScrollBar():Void
	{
		style.height = "100%";
		style.width = TRACK_DEFAULT_DIMENSION + "px";
		style.right = "0";
		style.top = "0";
		
		_downArrow.style.bottom = "0";
		
		_scrollThumb.style.top = THUMB_DEFAULT_DIMENSION +"px";
	}
	
		
	/**
	 * style as an horizontal scrollbar
	 */
	private function initHorizontalScrollBar():Void
	{
		style.width = "100%";
		style.height = TRACK_DEFAULT_DIMENSION + "px";
		style.bottom = "0";
		style.left = "0";
		
		_downArrow.style.right = "0";
		
		_scrollThumb.style.left = THUMB_DEFAULT_DIMENSION +"px";
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function createElementRenderer():Void
	{
		elementRenderer = new ScrollBarRenderer(this);
	}
	
	/**
	 * The Scrollbar has no DOM parent node as it is part of the Shadow DOM
	 * and belongs to a BlockBoxRenderer, however its parent should be considered
	 * rendered so that the scroll can render itself and its parent
	 */ 
	override private function isParentRendered():Bool
	{
		return true;
	}

	/**
	 * do nothing, as attachement is managed by the owning BlockBoxRenderer
	 */
	override private function attachToParentElementRenderer():Void
	{
	
	}

	/**
	 * do nothing, as detachement is managed by the owning BlockBoxRenderer
	 */
	override private function detachFromParentElementRenderer():Void
	{
		
	}
	
	/**
	 * Overriden as the ScrollBar is not supposed to 
	 * have a default action. Overriden because, else tries to focus on document without
	 * having a reference to the document.
	 */
	override private function executeDefaultActionIfNeeded(defaultPrevented:Bool, event:Event):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL ARROWS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * on mouse down, increment the scroll offset
	 * 
	 * TODO 1 : add timer to call the method again while the mouse is down
	 */
	private function onDownArrowMouseDown(event:MouseEvent):Void
	{
		scroll += ARROW_SCROLL_OFFSET;
		
		//have to stop propagation else event bubbles to track
		event.stopPropagation();
	}
	
	/**
	 * on mouse down, decrement the scroll offset
	 */
	private function onUpArrowMouseDown(event:MouseEvent):Void
	{
		scroll -= ARROW_SCROLL_OFFSET;
		event.stopPropagation();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL THUMB
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * on mouse down of the thumb of the scroll, start to listen
	 * to global mouse move event to update the scroll and to
	 * global mouse up event to stop scrolling with the thumb
	 */
	private function onThumbMouseDown(event:MouseEvent):Void
	{
		//store the current x and y of the mouse, as the thumb
		//scrolling is applied as a delta with the new mouse position
		//on each mouse move
		if (_isVertical == true)
		{
			_mouseMoveStart = event.screenY;
		}
		else
		{
			_mouseMoveStart = event.screenX;
		}
		
		event.stopPropagation();
		
		_thumbMoveDelegate = onThumbMove;
		_thumbUpDelegate = onThumbMouseUp;
		
		//TODO 2 : originally, listened to those event on the Body but as the ScrollBar is not
		//attached to the DOM, the event didn't bubled when mouse hovered track. Should scrollbar
		//events bubble to document and window ?
		cocktail.Lib.document.addEventListener(MouseEvent.MOUSE_MOVE, cast(_thumbMoveDelegate));
		cocktail.Lib.document.addEventListener(MouseEvent.MOUSE_UP, cast(_thumbUpDelegate));
	}
	
	/**
	 * On mouse up, stops the thumb scrolling
	 */
	private function onThumbMouseUp(event:MouseEvent):Void
	{
		cocktail.Lib.document.removeEventListener(MouseEvent.MOUSE_MOVE, cast(_thumbMoveDelegate));
		cocktail.Lib.document.removeEventListener(MouseEvent.MOUSE_UP, cast(_thumbUpDelegate));
	}
	
	/**
	 * When the mouse move, while thethumb is pressed, update the
	 * scroll offset using the delta of the current mouse position
	 * with its position when the thumb scroll began
	 */
	private function onThumbMove(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
			//TODO 1 : not very precise
			var thumbDelta:Float = event.screenY - _mouseMoveStart;
			scroll += thumbDelta;
			
			_mouseMoveStart = event.screenY;
		}
		else
		{
			//TODO 1 : not very precise
			var thumbDelta:Float = event.screenX - _mouseMoveStart;
			scroll += thumbDelta;
			
			_mouseMoveStart = event.screenX;
		}
	}
	 
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL TRACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the track is clicked, either increment or decrement
	 * the scroll offset based on wether the click on the track
	 * was before or after the scroll thumb
	 */
	private function onTrackMouseDown(event:MouseEvent):Void
	{
		if (_isVertical == true)
		{
			if (event.screenY > _scrollThumb.elementRenderer.globalBounds.y)
			{
				scroll += TRACK_SCROLL_OFFSET;
			}
			else
			{
				scroll -= TRACK_SCROLL_OFFSET;
 			}
			
		}
		else
		{
			if (event.screenX > _scrollThumb.elementRenderer.globalBounds.x)
			{
				scroll += TRACK_SCROLL_OFFSET;
			}
			else
			{
				scroll -= TRACK_SCROLL_OFFSET;
 			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLL UPDATE
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function updateScroll():Void
	{
		if (_scroll > _maxScroll)
		{
			_scroll = maxScroll;
		}
		else if (_scroll < 0)
		{
			_scroll = 0;
		}
		
		var progress:Float = scroll / maxScroll;
		
		if (_isVertical == true)
		{
			var thumbY:Int = Math.round(progress * (coreStyle.computedStyle.height -
			_upArrow.coreStyle.computedStyle.height - _downArrow.coreStyle.computedStyle.height - _scrollThumb.coreStyle.computedStyle.height)
			+  _upArrow.coreStyle.computedStyle.height);
			_scrollThumb.style.top = thumbY + "px";
		}
		else
		{
			var thumbX:Int = Math.round(progress * (coreStyle.computedStyle.width -
			_upArrow.coreStyle.computedStyle.width - _downArrow.coreStyle.computedStyle.width - _scrollThumb.coreStyle.computedStyle.width)
			+  _upArrow.coreStyle.computedStyle.width);
			
			_scrollThumb.style.left = thumbX + "px";
		}
		
		dispatchScrollEvent();
	}
	
	/**
	 * When the max scroll offset changes, 
	 * the size of the thumb to reflect
	 * the amount of scrollablze offset
	 */
	public function updateThumbSize():Void
	{
		
		if (_isVertical == true)
		{
			var thumbHeight:Float = coreStyle.computedStyle.height - _downArrow.coreStyle.computedStyle.height - _upArrow.coreStyle.computedStyle.height - maxScroll;

			if (thumbHeight < THUMB_DEFAULT_DIMENSION)
			{
				thumbHeight = THUMB_DEFAULT_DIMENSION;
			}
			
			if (thumbHeight != _scrollThumb.coreStyle.computedStyle.height)
			{
				_scrollThumb.style.height = thumbHeight + "px";
			}
			
		}
		else
		{
			var thumbWidth:Float = coreStyle.computedStyle.width - _downArrow.coreStyle.computedStyle.width - _upArrow.coreStyle.computedStyle.width - maxScroll;

			if (thumbWidth < THUMB_DEFAULT_DIMENSION)
			{
				thumbWidth = THUMB_DEFAULT_DIMENSION;
			}
			
			if (thumbWidth != _scrollThumb.coreStyle.computedStyle.width)
			{
				_scrollThumb.style.width = thumbWidth + "px";
			}
		}
	}
	
	private function dispatchScrollEvent():Void
	{
		var scrollEvent:UIEvent = new UIEvent();
		scrollEvent.initUIEvent(UIEvent.SCROLL, false, false, null, 0.0);
		dispatchEvent(scrollEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_maxScroll():Float 
	{
		return _maxScroll;
	}
	
	private function set_maxScroll(value:Float):Float 
	{
		var scrollPercent:Float = _scroll / _maxScroll;
		
		if (_maxScroll == 0)
		{
			scrollPercent = 0;
		}
		
		_maxScroll = value;
		scroll = _maxScroll * scrollPercent; 
		
		updateThumbSize();
		
		return value;
	}

	private function get_scroll():Float
	{
		return _scroll ;
	}
	
	private function set_scroll(value:Float):Float 
	{
		_scroll = value;
		updateScroll();
		
		return value;
	}
}