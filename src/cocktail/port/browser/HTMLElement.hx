/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;

import cocktail.core.dom.Node;
import cocktail.core.html.AbstractHTMLElement;
import cocktail.core.event.Event;
import cocktail.core.NativeElement;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;
import haxe.Log;
import js.Dom;
import cocktail.core.dom.DOMData;
import cocktail.core.geom.Matrix;
import cocktail.core.geom.GeomData;

/**
 * This is the HTMLElement implementation for the browser runtime.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLElement extends AbstractHTMLElement
{
	/**
	 * Class constructor
	 */
	public function new(tagName:String) 
	{
		super(tagName);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also remove the child from the native 
	 * HTML DOM
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		
		switch (oldChild.nodeType)
		{
			case Node.ELEMENT_NODE:
				var childHTMLElement:HTMLElement = cast(oldChild);
				_nativeElement.removeChild(childHTMLElement.nativeElement);
				
			case Node.TEXT_NODE:
				var childTextElement:cocktail.core.dom.Text = cast(oldChild);
				_nativeElement.removeChild(childTextElement.nativeElement);
				
			default:
				//TODO : DOM exception ?
				
		}
		
		return oldChild;
	}
	
	/**
	 * Overriden to also append the child to the native 
	 * HTML DOM
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		switch (newChild.nodeType)
		{
			case Node.ELEMENT_NODE:
				var childHTMLElement:HTMLElement = cast(newChild);
				_nativeElement.appendChild(childHTMLElement.nativeElement);
				
			case Node.TEXT_NODE:
				var childTextElement:cocktail.core.dom.Text = cast(newChild);
				_nativeElement.appendChild(childTextElement.nativeElement);
				
			default:
				//TODO : DOM exception ?
				
		}
		return newChild;
	}
	
	/**
	 * Overriden to also insert before the native 
	 * HTML DOM
	 */
	override public function insertBefore(newChild:Node, refChild:Node):Node
	{
		super.insertBefore(newChild, refChild);
		
		untyped _nativeElement.insertBefore(newChild.nativeElement, refChild.nativeElement);
		
		return newChild;
	}
	
	/**
	 * Overriden to also replace the child of the native 
	 * HTML DOM
	 */
	override public function replaceChild(newChild:Node, oldChild:Node):Node
	{
		super.replaceChild(newChild, oldChild);
		
		untyped _nativeElement.replaceChild(newChild.nativeElement, refChild.nativeElement);
		
		return oldChild;
	}
	
	/**
	 * overriden to also update the atttribute of the
	 * native HTML element
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		super.setAttribute(name, value);
		_nativeElement.setAttribute(name, value);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN POSITIONING SETTERS/GETTERS
	// Return the native offset width and height of the HTML element
	//////////////////////////////////////////////////////////////////////////////////////////

	override private function get_offsetWidth():Int
	{
		return _nativeElement.offsetWidth;
	}

	override private function get_offsetHeight():Int
	{
		return _nativeElement.offsetHeight;
	}
	
	override private function get_offsetLeft():Int
	{
		return _nativeElement.offsetLeft;
	}
	
	override private function get_offsetTop():Int
	{
		return _nativeElement.offsetTop;
	}
	
	override private function get_clientWidth():Int
	{
		return _nativeElement.clientWidth;
	}
	
	override private function get_clientHeight():Int
	{
		return _nativeElement.clientHeight;
	}
	
	override private function get_clientLeft():Int
	{
		return untyped _nativeElement.clientLeft;
	}
	
	override private function get_clientTop():Int
	{
		return untyped _nativeElement.clientTop;
	}
	
	override private function set_scrollTop(value:Int):Int
	{
		return _nativeElement.scrollTop = value;
	}
	
	override private function get_scrollTop():Int
	{
		return  _nativeElement.scrollTop;
	}
	
	override private function set_scrollLeft(value:Int):Int
	{
		return _nativeElement.scrollLeft = value;
	}
	
	override private function get_scrollLeft():Int
	{
		return  _nativeElement.scrollLeft;
	}
	
	override private function get_scrollWidth():Int
	{
		return  _nativeElement.scrollWidth;
	}
	
	override private function get_scrollHeight():Int
	{
		return  _nativeElement.scrollHeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN FOCUS SETTER/GETTER AND METHODS
	// The browser focus implementation relies on the native browser focus
	// instead of Cocktail's FocusManager
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a listener on the nativeElement for focus events
	 */
	override private function set_onFocus(value:Event->Void):Event->Void
	{
		if (value == null)
		{
			untyped _nativeElement.removeEventListener("focus", onNativeFocus);
		}
		else
		{
			untyped _nativeElement.addEventListener("focus", onNativeFocus);
		}
		
		return _onFocus = value;
	}
	
	/**
	 * Set a listener on the nativeElement for blur events
	 */
	override private function set_onBlur(value:Event->Void):Event->Void
	{
		if (value == null)
		{
			untyped _nativeElement.removeEventListener("blur", onNativeBlur);
		}
		else
		{
			untyped _nativeElement.addEventListener("blur", onNativeBlur);
		}
		
		return _onBlur = value;
	}
	
	/**
	 * Set also the tabIndex on the native HTML element
	 */
	override private function set_tabIndex(value:Null<Int>):Null<Int>
	{
		super.set_tabIndex(value);
		untyped _nativeElement.tabIndex = value;
		return _tabIndex;
	}
	
	/**
	 * set focus on the nativeElement
	 */
	override public function focus():Void
	{
		super.focus();
		_nativeElement.focus();
	}
	
	/**
	 * blur the nativeElement
	 */
	override public function blur():Void
	{
		super.blur();
		_nativeElement.blur();
	}
	
	/**
	 * When a native focus event is dispatched,
	 * call the focus callback if not null
	 */
	private function onNativeFocus(event:Dynamic):Void
	{
		if (_onFocus != null)
		{
			_onFocus(new Event(Event.FOCUS, this));
		}
	}
	
	/**
	 * When a native blur event is dispatched,
	 * call the blur callback if not null
	 */
	private function onNativeBlur(event:Dynamic):Void
	{
		if (_onBlur != null)
		{
			_onBlur(new Event(Event.BLUR, this));
		}
	}
	
	/////////////////////////////////
	// OVERRIDEN SCROLLING SETTER/GETTER
	/////////////////////////////////
	
	/**
	 * When the user onscroll callback is set, set
	 * a native listener on the nativeElement
	 */
	override private function set_onScroll(value:Event->Void):Event->Void
	{
		//first always remove previous listener
		untyped _nativeElement.removeEventListener("scroll", onNativeScroll);
		
		_onScroll = value;
		
		//only add listener if user callback is not null
		if (_onScroll != null)
		{
			untyped _nativeElement.addEventListener("scroll", onNativeScroll);
		}
		
		return value;
	}
	
	/**
	 * called when a native javascript scroll event is emitted
	 * by the native HTML element
	 */
	private function onNativeScroll(event:Dynamic):Void
	{
		onScrollCallback(new Event(Event.SCROLL, this));
	}
	
}