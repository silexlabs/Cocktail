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
	
	/**
	 * The callback called on mouse click (rapid mouse down and mouse up)
	 */
	public var onclick(default, set_onClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse double click
	 */
	public var ondblclick(default, set_onDblClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse down 
	 */
	public var onmousedown(default, set_onMouseDown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up
	 */
	public var onmouseup(default, set_onMouseUp):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this htmlElement
	 */
	public var onmouseover(default, set_onMouseOver):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this htmlElement
	 */
	public var onmouseout(default, set_onMouseOut):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this htmlElement
	 */
	public var onmousemove(default, set_onMouseMove):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse wheel is rotated while the mouse
	 * pointer is over this element
	 */
	public var onmousewheel(default, set_onMouseWheel):WheelEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback called on key down when this htmlElement has focus
	 */
	public var onkeydown(default, set_onKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up when this htmlElement has focus
	 */
	public var onkeyup(default, set_onKeyUp):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	public var onfocus(default, set_onFocus):FocusEvent->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	public var onblur(default, set_onBlur):FocusEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UI callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when the window through which
	 * the document is viewed is resized
	 */
	public var onresize(default, set_onResize):UIEvent->Void;
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	public var onscroll(default, set_onScroll):UIEvent->Void;
	
	/**
	 * Callback called when the document or
	 * an external resource, such as a picture
	 * is loaded
	 */
	public var onload(default, set_onLoad):UIEvent->Void;
	
	/**
	 * Callback called when there is an
	 * error while loading an external
	 * resource such as a picture
	 */
	public var onerror(default, set_onError):UIEvent->Void;
	
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
		updateCallbackListener(MouseEvent.CLICK, cast(value), cast(onclick));
		return onclick = value;
	}
	
	private function set_onDblClick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.DOUBLE_CLICK, cast(value), cast(ondblclick));
		return ondblclick = value;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_DOWN, cast(value), cast(onmousedown));
		return onmousedown = value;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_UP, cast(value), cast(onmouseup));
		return onmouseup = value;
	}
	
	private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_OVER, cast(value), cast(onmouseover));
		return onmouseover = value;
	}
	
	private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_OUT, cast(value), cast(onmouseout));
		return onmouseout = value;
	}
	
	private function set_onMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(MouseEvent.MOUSE_MOVE, cast(value), cast(onmousemove));
		return onmousemove = value;
	}
	
	private function set_onMouseWheel(value:WheelEvent->Void):WheelEvent->Void
	{
		updateCallbackListener(WheelEvent.MOUSE_WHEEL, cast(value), cast(onmousewheel));
		return onmousewheel = value;
	}
	
		// KEYBOARD
	////////////////////////////
	
	private function set_onKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(KeyboardEvent.KEY_DOWN, cast(value), cast(onkeydown));
		return onkeydown = value;
	}
	
	private function set_onKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(KeyboardEvent.KEY_UP, cast(value), cast(onkeyup));
		return onkeyup = value;
	}
	
		// FOCUS
	////////////////////////////
	
	private function set_onFocus(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(FocusEvent.FOCUS, cast(value), cast(onfocus));
		return onfocus = value;
	}
	
	private function set_onBlur(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(FocusEvent.BLUR, cast(value), cast(onblur));
		return onblur = value;
	}

		// UI
	////////////////////////////
	
	private function set_onResize(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.RESIZE, cast(value), cast(onresize));
		return onresize = value;
	}
	
	private function set_onScroll(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.SCROLL, cast(value), cast(onscroll));
		return onscroll = value;
	}
	
	private function set_onLoad(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.LOAD, cast(value), cast(onload));
		return onload = value;
	}
		
	private function set_onError(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(UIEvent.ERROR, cast(value), cast(onerror));
		return onerror = value;
	}
	
}