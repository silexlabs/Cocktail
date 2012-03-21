/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.browser;

import core.dom.AbstractHTMLElement;
import core.event.Event;
import core.nativeElement.NativeElement;
import haxe.Log;
import js.Dom;
import cocktailCore.domElement.DOMElementData;
import core.geom.Matrix;
import core.geom.GeomData;

/**
 * This is the DOMElement implementation for JavaScript. 
 * It manipulates the native HTML DOM
 * @author Yannick DOMINGUEZ
 */
class HTMLElement extends AbstractHTMLElement
{
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN POSITIONING SETTERS/GETTERS
	// Return the native offset width and height of the HTML element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to attach the native HTML element to the HTML DOM and
	 * to set the CSS z-index of the newly attached children
	 * @param	domElement the html element to add to this container
	 */
	override public function addChild(domElement:DOMElement):Void
	{
		super.addChild(domElement);
		this._nativeElement.appendChild(domElement.nativeElement);
		//intialise z-index on the DOMElement, as it is null by default in JavaScript
		domElement.nativeElement.style.zIndex = _children.length - 1;
	}
	
	/**
	 * Overriden to remove the native HTML element from
	 * the HTML DOM
	 * @param domElement the html element to remove from this container
	 */
	override public function removeChild(domElement:DOMElement):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.nativeElement);
	}
	
	override private function getOffsetWidth():Int
	{
		return untyped _nativeElement.offsetWidth;
	}

	override private function getOffsetHeight():Int
	{
		return untyped _nativeElement.offsetHeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN FOCUS SETTER/GETTER AND METHODS
	// The JavaScript focus implementation relies on the browser
	// instead of Cocktail's FocusManager
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a listener on the nativeElement for focus events
	 */
	override private function setOnFocusIn(value:Void->Void):Void->Void
	{
		if (value == null)
		{
			_nativeElement.onfocus = null;
		}
		else
		{
			_nativeElement.onfocus = onNativeFocusIn;
		}
		
		return _onFocusIn = value;
	}
	
	/**
	 * Set a listener on the nativeElement for blur events
	 */
	override private function setOnFocusOut(value:Void->Void):Void->Void
	{
		if (value == null)
		{
			_nativeElement.onblur = null;
		}
		else
		{
			_nativeElement.onblur = onNativeFocusOut;
		}
		
		return _onFocusOut = value;
	}
	
	/**
	 * Stores the tabIndex attribute and reset the tabEnabled
	 * setter. This way the HTML attribute will only be set if
	 * tab is enabled
	 */
	override private function setTabIndex(value:Int):Int
	{
		//TODO : tabIndex is not set on the nativeElement
		_tabIndex = value;
		
		return _tabIndex;
	}
	
	/**
	 * set focus on the nativeElement
	 */
	override public function focus():Void
	{
		_nativeElement.focus();
	}
	
	/**
	 * When a native focus event is dispatched,
	 * call the focus callback
	 */
	private function onNativeFocusIn(event:Dynamic):Void
	{
		if (onFocusIn != null)
		{
			onFocusIn();
		}
	}
	
	/**
	 * When a native blur event is dispatched,
	 * call the blur callback
	 */
	private function onNativeFocusOut(event:Dynamic):Void
	{
		if (onFocusOut != null)
		{
			onFocusOut();
		}
	}
	
	/////////////////////////////////
	// OVERRIDEN SCROLLING SETTER/GETTER
	/////////////////////////////////
	
	/**
	 * When the user onscroll callback is set, set
	 * a native JavaScript listener on the element
	 */
	override private function setOnScroll(value:Event->Void):Event->Void
	{
		//TODO : re-implement
		/**
		//first always remove previous listener
		untyped _nativeElement.removeEventListener("scroll", onNativeScroll);
		
		_onScroll = value;
		
		//only add listener if user callback is not null
		if (_onScroll != null)
		{
			untyped _nativeElement.addEventListener("scroll", onNativeScroll);
		}
		*/
		return value;
	}
	
	/**
	 * called when a native javascript scroll event is emitted
	 * by the HTML element
	 */
	private function onNativeScroll(event:Dynamic):Void
	{
		//TODO : re-implement
		/**
		//build the abstract sroll event data
		var scrollEventData:ScrollEventData = {
			scrollLeft : _nativeElement.scrollLeft,
			scrollTop : _nativeElement.scrollTop,
			scrollWidth : _nativeElement.scrollWidth,
			scrollHeight : _nativeElement.scrollHeight
		}
		
		onScrollCallback(scrollEventData);
		*/
	}
	
}