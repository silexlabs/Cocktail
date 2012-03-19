/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.geom.Matrix;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import core.event.Event;
import core.event.KeyboardEvent;
import core.event.MouseEvent;
import cocktailCore.focus.FocusManager;
import cocktailCore.keyboard.Keyboard;
import cocktail.keyboard.KeyboardData;
import core.mouse.Mouse;
import core.mouse.MouseData;
import cocktail.nativeElement.NativeElement;
import cocktailCore.style.Style;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import cocktailCore.unit.UnitManager;
import haxe.Log;

/**
 * This is the base class for all DOMElements. A DOMElement is an abstraction of the visual base element of a runtime.
 * For instance in JS, a DOMElement is an HTML element, like a <div> or <img> element. In Flash AS3, a domElement is a DisplayObject.
 * This class abstracts manipulating DOM elements, each runtime implemented in a sub-class.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractDOMElement 
{
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Mouse attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to native mouse events
	 */
	private var _mouse:Mouse;
	
	/**
	 * The callback called on mouse down through the mouse instance
	 */
	private var _onMouseDown:MouseEvent->Void;
	public var onMouseDown(getOnMouseDown, setOnMouseDown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up through the mouse instance
	 */
	private var _onMouseUp:MouseEvent->Void;
	public var onMouseUp(getOnMouseUp, setOnMouseUp):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this dom element
	 */
	private var _onMouseOver:MouseEvent->Void;
	public var onMouseOver(getOnMouseOver, setOnMouseOver):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this dom element
	 */
	private var _onMouseOut:MouseEvent->Void;
	public var onMouseOut(getOnMouseOut, setOnMouseOut):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this dom element
	 */
	private var _onMouseMove:MouseEvent->Void;
	public var onMouseMove(getOnMouseMove, setOnMouseMove):MouseEvent->Void;
	
	/**
	 * The callback called when this dom element is double-clicked
	 */
	private var _onMouseDoubleClick:MouseEvent->Void;
	public var onMouseDoubleClick(getOnMouseDoubleClick, setOnMouseDoubleClick):MouseEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An instance of the cross-platform keyboard class, used to listen
	 * to key down and up event
	 */
	private var _keyboard:Keyboard;
	
	/**
	 * The callback called on key down through the keyboard instance
	 */
	private var _onKeyDown:KeyboardEvent->Void;
	public var onKeyDown(getOnKeyDown, setOnKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up through the keyboard instance
	 */
	private var _onKeyUp:KeyboardEvent->Void;
	public var onKeyUp(getOnKeyUp, setOnKeyUp):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the DOMElement can receive focus, 
	 * some DOMElements such as the LinkDOMElement can
	 * recive focus by default
	 */
	private var _tabEnabled:Bool;
	public var tabEnabled(getTabEnabled, setTabEnabled):Bool;
	
	/**
	 * The tab index order of the DOMElement. If the DOMElement
	 * is tab enabled, this index will be used when the
	 * user presses the TAB key to determine the order
	 * of the focusable DOMElements in the DOM
	 */
	private var _tabIndex:Int;
	public var tabIndex(getTabIndex, setTabIndex):Int;
	
	/**
	 * callback called when the DOMElement recives 
	 * the focus
	 */
	private var _onFocusIn:Void->Void;
	public var onFocusIn(getOnFocusIn, setOnFocusIn):Void->Void;
	
	/**
	 * callback called when the DOMElement loses the focus
	 */
	private var _onFocusOut:Void->Void;
	public var onFocusOut(getOnFocusOut, setOnFocusOut):Void->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when
	 * the content of the DOMElement
	 * is scrolled
	 */
	private var _onScroll:Event->Void;
	public var onScroll(getOnScroll, setOnScroll):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An abstract reference to the native element wrapped by this DOMElement.
	 * Varies for each runtime : in JS it is an HTML element, in Flash a Sprite,
	 * in PHP a resource...
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, setNativeElement):NativeElement;
	
	/**
	 * a reference to the parent of this DOMElement, of type container, the
	 * only kind of DOMElement which can have children
	 */ 
	private var _parent:ContainerDOMElement;
	public var parent(getParent, setParent):ContainerDOMElement;
	
	/////////////////////////////////
	// COORDS attributes
	////////////////////////////////
	
	/**
	 * Read-only, returns the width of the domElement
	 * + horizontal paddings + horizontal margins
	 */
	public var offsetWidth(getOffsetWidth, never):Int;
	
	/**
	 * Read-only, returns the height of the domElement
	 * + vertical paddings + vertical margins
	 */
	public var offsetHeight(getOffsetHeight, never):Int;
	
	/////////////////////////////////
	// STYLE attribute
	////////////////////////////////
	
	/**
	 * This Style object stores the styles of
	 * a DOMElement and manages how they are applied
	 */
	private var _style:Style;
	public var style(getStyle, never):Style;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor. Stores the reference to the
	 * native element triggering the initialisation
	 * of the DOMElement
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//store and init the dom element properties
		//with the native element if it isn't null
		if (nativeElement != null)
		{
			this.nativeElement = nativeElement;
		}
	}
	
	/**
	 * Init the DOMElement properties. Called each time
	 * the NativeElement is set
	 */
	private function init():Void
	{	
		//initialise the mouse listeners on this dom element by 
		//listening to the current native element
		_mouse = new Mouse(this._nativeElement);
		
		//init key listeners
		initKeyboard();
		
		//init the style for this DOMElement
		initStyle();
		
		//init the focus attributes
		initFocus();
	}
	
	/**
	 * initialise the keyboard listener of this dom element 
	 */
	private function initKeyboard():Void
	{
		_keyboard = new Keyboard(this._nativeElement);
	}
	
	/**
	 * Instantiate the right style object for this
	 * DOMElement. Overriden by DOMElements with
	 * specific style objects, such as ContainerDOMElement
	 */
	private function initStyle():Void
	{
		//abstract
	}
	
	/**
	 * init the focus attributes
	 */
	private function initFocus():Void
	{
		_tabIndex = 0;
		_tabEnabled = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM
	// Public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the parent of this DOMElement
	 */
	private function getParent():ContainerDOMElement
	{
		return this._parent;
	}
	
	/**
	 * set the parent of this DOMElement
	 */
	private function setParent(domElement:ContainerDOMElement):ContainerDOMElement
	{
		this._parent = domElement;
		return this._parent;
	}
	
	/**
	 * set the reference to this DOMElement NativeElement
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	private function setNativeElement(value:NativeElement):NativeElement
	{
		this._nativeElement = value;
		//reset the DOMElement's properties
		init();
		return value;
	}
	
	/**
	 * Returns the reference to this DOMElement native DOM element
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	private function getNativeElement():NativeElement
	{
		return this._nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE SETTER/GETTER
	// Proxies setting/getting properties from the mouse listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseDown = value;
		
		if (_onMouseDown == null)
		{
			_mouse.onMouseDown = null;
		}
		else
		{
			_mouse.onMouseDown = onMouseDownCallback;
		}
		
		return value;
	}
	
	private function getOnMouseDown():MouseEvent->Void
	{
		return _onMouseDown;
	}
	
	private function setOnMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseUp = value;
		
		if (_onMouseUp == null)
		{
			_mouse.onMouseUp = null;
		}
		else
		{
			_mouse.onMouseUp = onMouseUpCallback;
		}
		
		return value;
	}
	
	private function getOnMouseUp():MouseEvent->Void
	{
		return _onMouseUp;
	}
	
	private function setOnMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseOver = value;
		
		if (_onMouseOver == null)
		{
			_mouse.onMouseOver = null;
		}
		else
		{
			_mouse.onMouseOver = onMouseOverCallback;
		}
		
		return value;
	}
	
	private function getOnMouseOver():MouseEvent->Void
	{
		return _onMouseOver;
	}
	
	private function setOnMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseOut = value;
		
		if (_onMouseOut == null)
		{
			_mouse.onMouseOut = null;
		}
		else
		{
			_mouse.onMouseOut = onMouseOutCallback;
		}
		
		return value;
	}
	
	private function getOnMouseOut():MouseEvent->Void
	{
		return _onMouseOut;
	}
	
	private function setOnMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseMove = value;
		
		if (_onMouseMove == null)
		{
			_mouse.onMouseMove = null;
		}
		else
		{
			_mouse.onMouseMove = onMouseMoveCallback;
		}
		
		return value;
	}
	
	private function getOnMouseMove():MouseEvent->Void
	{
		return _onMouseMove;
	}
	
	private function setOnMouseDoubleClick(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseDoubleClick = value;
		
		if (_onMouseDoubleClick == null)
		{
			_mouse.onMouseDoubleClick = null;
		}
		else
		{
			_mouse.onMouseDoubleClick = onMouseDoubleClickCallback;
		}
		
		return value;
	}
	
	private function getOnMouseDoubleClick():MouseEvent->Void
	{
		return _onMouseDoubleClick;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE EVENT CALLBACK
	// called by the Mouse instance when the user interacts
	// with the DOMElement with its mouse
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onMouseDownCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseDown(mouseEventData);
	}
	
	private function onMouseUpCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseUp(mouseEventData);
	}
	
	private function onMouseMoveCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseMove(mouseEventData);
	}
	
	private function onMouseOverCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseOver(mouseEventData);
	}
	
	private function onMouseOutCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseOut(mouseEventData);
	}
	
	private function onMouseDoubleClickCallback(mouseEventData:MouseEvent):Void
	{
		_onMouseDoubleClick(mouseEventData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD SETTER/GETTER
	// Proxies setting/getting properties from the keyboard listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		_onKeyDown = value;
		
		if (_onKeyDown == null)
		{
			_keyboard.onKeyDown = null;
		}
		else
		{
			_keyboard.onKeyDown = onKeyDownCallback;
		}
		
		return value;
	}
	
	private function getOnKeyDown():KeyboardEvent->Void
	{
		return _keyboard.onKeyDown;
	}
	
	private function setOnKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		_onKeyUp = value;
		
		if (_onKeyUp == null)
		{
			_keyboard.onKeyUp = null;
		}
		else
		{
			_keyboard.onKeyUp = onKeyUpCallback;
		}
		
		return value;
	}
	
	private function getOnKeyUp():KeyboardEvent->Void
	{
		return _keyboard.onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD EVENT CALLBACK
	// called by the Keyboard instance when the user interacts
	// with the keyboard while this DOMElement has the focus
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onKeyDownCallback(keyEventData:KeyboardEvent):Void
	{
		_onKeyDown(keyEventData);
	}
	
	private function onKeyUpCallback(keyEventData:KeyboardEvent):Void
	{
		_onKeyUp(keyEventData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS SETTER/GETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the focus on this DOMElement, the focus
	 * manager must determine if the DOMElement can
	 * actually receive focus
	 */
	public function focus():Void
	{
		FocusManager.getInstance().activeDOMElement = cast(this);
	}
	
	private function setOnFocusIn(value:Void->Void):Void->Void
	{
		return _onFocusIn = value;
	}
	
	private function getOnFocusIn():Void->Void
	{
		return _onFocusIn;
	}
	
	private function setOnFocusOut(value:Void->Void):Void->Void
	{
		return _onFocusOut = value;
	}
	
	private function getOnFocusOut():Void->Void
	{
		return _onFocusOut;
	}
	
	/**
	 * When set, invalidate the focus manager
	 * tab list as this DOMElement must now
	 * be included or excluded from it
	 */
	private function setTabEnabled(value:Bool):Bool
	{
		FocusManager.getInstance().invalidate();
		return _tabEnabled = value;
	}
	
	private function getTabEnabled():Bool
	{
		return _tabEnabled;
	}
	
	/**
	 * when set, invalidate the focus manager
	 * tab list, as this DOMElement may appear
	 * at another index of the list
	 */
	private function setTabIndex(value:Int):Int
	{
		FocusManager.getInstance().invalidate();
		return _tabIndex = value;
	}
	
	private function getTabIndex():Int
	{
		return _tabIndex;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLING SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnScroll(value:Event->Void):Event->Void
	{
		return _onScroll = value;
	}
	
	private function getOnScroll():Event->Void
	{
		return _onScroll;
	}
	
	/**
	 * called when a native scroll event is
	 * emitted, called the user on scroll
	 * callback if any
	 */
	private function onScrollCallback(event:Event):Void
	{
		if (_onScroll != null)
		{
			_onScroll(event);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// POSITIONING SETTERS/GETTERS
	// Setters/Getters to manipulate a DOMElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * constructs the offset width from the computed
	 * box of this domElement
	 * 
	 * TODO : shouldn't include margin
	 */
	private function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	/**
	 * constructs the offset height from the computed
	 * box of this domElement
	 * 
	 * TODO : shouldn't include margin
	 */
	private function getOffsetHeight():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getStyle():Style
	{
		return this._style;
	}
}