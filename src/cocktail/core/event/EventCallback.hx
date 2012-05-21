/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * Exposes attributes to set/get callbacks for all the DOM
 * events in one location. 
 * 
 * Add/Remove event listeners for the EventTarget
 * when callbacks are set/removed.
 * 
 * This classes is inherited by all DOM Objects
 * which can receive and dispatch events, such
 * as Node, Document and Window
 *
 * @author Yannick DOMINGUEZ
 */
class EventCallback extends EventTarget
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// Mouse callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : add mouse double click
	
	/**
	 * The callback called on mouse click (rapid mouse down and mouse up)
	 */
	private var _onClick:MouseEvent->Void;
	public var onclick(get_onClick, set_onClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse down 
	 */
	private var _onMouseDown:MouseEvent->Void;
	public var onmousedown(get_onMouseDown, set_onMouseDown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up
	 */
	private var _onMouseUp:MouseEvent->Void;
	public var onmouseup(get_onMouseUp, set_onMouseUp):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this htmlElement
	 */
	private var _onMouseOver:MouseEvent->Void;
	public var onmouseover(get_onMouseOver, set_onMouseOver):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this htmlElement
	 */
	private var _onMouseOut:MouseEvent->Void;
	public var onmouseout(get_onMouseOut, set_onMouseOut):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this htmlElement
	 */
	private var _onMouseMove:MouseEvent->Void;
	public var onmousemove(get_onMouseMove, set_onMouseMove):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse wheel is rotated while the mouse
	 * pointer is over this element
	 */
	private var _onMouseWheel:WheelEvent->Void;
	public var onmousewheel(get_onMouseWheel, set_onMouseWheel):WheelEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback called on key down when this htmlElement has focus
	 */
	private var _onKeyDown:KeyboardEvent->Void;
	public var onkeydown(get_onKeyDown, set_onKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up when this htmlElement has focus
	 */
	private var _onKeyUp:KeyboardEvent->Void;
	public var onkeyup(get_onKeyUp, set_onKeyUp):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	private var _onFocus:FocusEvent->Void;
	public var onfocus(get_onFocus, set_onFocus):FocusEvent->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	private var _onBlur:FocusEvent->Void;
	public var onblur(get_onBlur, set_onBlur):FocusEvent->Void;
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	private var _onScroll:UIEvent->Void;
	public var onscroll(get_onScroll, set_onScroll):UIEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UI callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when the window through which
	 * the document is viewed is resized
	 */
	private var _onResize:UIEvent->Void;
	public var onresize(get_onResize, set_onResize):UIEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACK HELPER
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Utils method to update the listener used by a callback
	 */
	private function updateCallbackListener(eventType:String, newListener:Event->Void, oldListener:Event->Void):Void
	{
		//if the callback is alreay linked to an EventListener
		//remove the event listener
		if (oldListener != null)
		{
			removeEventListener(eventType, oldListener);
		}
		
		//add a new event listener if the callback is not null
		if (newListener != null)
		{
			addEventListener(eventType, newListener);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// MOUSE
	////////////////////////////
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.CLICK, cast(value), cast(_onClick));
		return _onClick = value;
	}
	
	private function get_onClick():MouseEvent->Void
	{
		return _onClick;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_DOWN, cast(value), cast(_onMouseDown));
		return _onMouseDown = value;
	}
	
	private function get_onMouseDown():MouseEvent->Void
	{
		return _onMouseDown;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_UP, cast(value), cast(_onMouseUp));
		return _onMouseUp = value;
	}
	
	private function get_onMouseUp():MouseEvent->Void
	{
		return _onMouseUp;
	}
	
	private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_OVER, cast(value), cast(_onMouseOver));
		return _onMouseOver = value;
	}
	
	private function get_onMouseOver():MouseEvent->Void
	{
		return _onMouseOver;
	}
	
	private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_OUT, cast(value), cast(_onMouseOut));
		return _onMouseOut = value;
	}
	
	private function get_onMouseOut():MouseEvent->Void
	{
		return _onMouseOut;
	}
	
	private function set_onMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_MOVE, cast(value), cast(_onMouseMove));
		return _onMouseMove = value;
	}
	
	private function get_onMouseMove():MouseEvent->Void
	{
		return _onMouseMove;
	}
	
	private function set_onMouseWheel(value:WheelEvent->Void):WheelEvent->Void
	{
		updateCallbackListener(WheelEvent.MOUSE_WHEEL, cast(value), cast(_onMouseWheel));
		return _onMouseWheel = value;
	}
	
	private function get_onMouseWheel():WheelEvent->Void
	{
		return _onMouseWheel;
	}
	
		// KEYBOARD
	////////////////////////////
	
	private function set_onKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(KeyboardEvent.KEY_DOWN, cast(value), cast(_onKeyDown));
		return _onKeyDown = value;
	}
	
	private function get_onKeyDown():KeyboardEvent->Void
	{
		return _onKeyDown;
	}
	
	private function set_onKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(KeyboardEvent.KEY_UP, cast(value), cast(_onKeyUp));
		return _onKeyUp = value;
	}
	
	private function get_onKeyUp():KeyboardEvent->Void
	{
		return _onKeyUp;
	}
	
		// FOCUS
	////////////////////////////
	
	private function set_onFocus(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(FocusEvent.FOCUS, cast(value), cast(_onFocus));
		return _onFocus = value;
	}
	
	private function get_onFocus():FocusEvent->Void
	{
		return _onFocus;
	}
	
	private function set_onBlur(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(FocusEvent.BLUR, cast(value), cast(_onBlur));
		return _onBlur = value;
	}
	
	private function get_onBlur():FocusEvent->Void
	{
		return _onBlur;
	}
	
		// SCROLL
	////////////////////////////
	
	private function set_onScroll(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.SCROLL, cast(value), cast(_onScroll));
		return _onScroll = value;
	}
	
	private function get_onScroll():UIEvent->Void
	{
		return _onScroll;
	}
		
		// UI
	////////////////////////////
	
	private function set_onResize(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.RESIZE, cast(value), cast(_onResize));
		return _onResize = value;
	}
	
	private function get_onResize():UIEvent->Void
	{
		return _onResize;
	}
	
}