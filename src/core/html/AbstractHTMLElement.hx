/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.html;

import core.dom.Element;
import core.dom.Node;
import core.event.IEventTarget;
import core.HTMLElement;
import core.nativeElement.NativeElement;
import core.event.Event;
import core.event.KeyboardEvent;
import core.event.MouseEvent;
import cocktailCore.focus.FocusManager;
import core.Keyboard;
import core.Mouse;
import core.ContainerStyle;
import core.nativeElement.NativeElementManager;
import core.Style;
import core.nativeElement.NativeElementData;
import core.style.StyleData;

/**
 * All HTML element interfaces derive from this class.
 * Elements that only expose the HTML core attributes are represented 
 * by the base HTMLElement interface.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLElement extends Element, implements IEventTarget
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
	 * The callback called on mouse click (rapid mouse down and mouse up)
	 * through the mouse instance
	 */
	private var _onClick:MouseEvent->Void;
	public var onClick(get_onClick, set_onClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse down through the mouse instance
	 */
	private var _onMouseDown:MouseEvent->Void;
	public var onMouseDown(get_onMouseDown, set_onMouseDown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up through the mouse instance
	 */
	private var _onMouseUp:MouseEvent->Void;
	public var onMouseUp(get_onMouseUp, set_onMouseUp):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this htmlElement
	 */
	private var _onMouseOver:MouseEvent->Void;
	public var onMouseOver(get_onMouseOver, set_onMouseOver):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this htmlElement
	 */
	private var _onMouseOut:MouseEvent->Void;
	public var onMouseOut(get_onMouseOut, set_onMouseOut):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this htmlElement
	 */
	private var _onMouseMove:MouseEvent->Void;
	public var onMouseMove(get_onMouseMove, set_onMouseMove):MouseEvent->Void;
	
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
	public var onKeyDown(get_onKeyDown, set_onKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up through the keyboard instance
	 */
	private var _onKeyUp:KeyboardEvent->Void;
	public var onKeyUp(get_onKeyUp, set_onKeyUp):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The tab index order of the HTMLElement. If the index
	 * is set, it is used to determine focus order when the
	 * user press the TAB key. If it is not set, the document
	 * order is used to establish focus order and the HTMLElement
	 * is only focused if it is intrinsivally focusable, like for
	 * instance an HTMLInputElement
	 */
	private var _tabIndex:Null<Int>;
	public var tabIndex(get_tabIndex, set_tabIndex):Null<Int>;
	
	/**
	 * Return wheter this HTMLElement is intrinsically
	 * focusable. For instance, html input or anchor elements
	 * are intrinsically focusable
	 */
	public var isDefaultFocusable(get_isDefaultFocusable, never):Bool;
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	private var _onFocus:Event->Void;
	public var onFocus(get_onFocus, set_onFocus):Event->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	private var _onBlur:Event->Void;
	public var onBlur(get_onBlur, set_onBlur):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	private var _onScroll:Event->Void;
	public var onScroll(get_onScroll, set_onScroll):Event->Void;
	
	/**
	 * Gets/sets the top scroll offset of an element
	 */
	public var scrollTop(get_scrollTop, set_scrollTop):Int;
	
	/**
	 * Gets/sets the left scroll offset of an element
	 */
	public var scrollLeft(get_scrollLeft, set_scrollLeft):Int;
	
	/**
	 * The scroll view height of the HTMLElement
	 */
	public var scrollHeight(get_scrollHeight, never):Int;
	
	/**
	 * The scroll view width of the HTMLElement
	 */
	public var scrollWidth(get_scrollWidth, never):Int;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An abstract reference to the native element wrapped by this HTMLElement.
	 * Varies for each runtime : in JS it is an HTML element, in Flash a Sprite,
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	/////////////////////////////////
	// COORDS attributes
	////////////////////////////////
	
	/**
	 * The element from which all offset calculations are currently computed,
	 * this is the first positioned ancestor of the HTMLElement
	 */
	public var offsetParent(get_offsetParent, never):HTMLElement;
	
	/**
	 * The width of an element, relative to the layout
	 */
	public var offsetWidth(get_offsetWidth, never):Int;
	
	/**
	 * The height of an element, relative to the layout
	 */
	public var offsetHeight(get_offsetHeight, never):Int;
	
	/**
	 * The distance from this element's left border to its 
	 * offsetParent's left border.
	 * 
	 * TODO : implement border
	 */
	public var offsetLeft(get_offsetLeft, never):Int;
	
	/**
	 * The distance from this element's top border to its
	 * offsetParent's top border.
	 */
	public var offsetTop(get_offsetTop, never):Int;
	
	/**
	 * The inner width of an element
	 */
	public var clientWidth(get_clientWidth, never):Int;
	
	/**
	 * The inner height of an element
	 */
	public var clientHeight(get_clientHeight, never):Int;
	
	/**
	 * The width of the left border of an element
	 */
	public var clientLeft(get_clientLeft, never):Int;
	
	/**
	 * The width of the top border of an element
	 */
	public var clientTop(get_clientTop, never):Int;
	
	/////////////////////////////////
	// STYLE attribute
	////////////////////////////////
	
	/**
	 * This Style object stores the styles of
	 * an HTMLElement and manages how they are applied
	 */
	private var _style:Style;
	public var style(get_style, never):Style;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor.
	 */
	public function new(tagName:String) 
	{
		super(tagName);
		init();
	}
	
	/**
	 * Init the HTMLElement attributes
	 */
	private function init():Void
	{	
		//instantiate the right NativeElement for this HTMLElement
		initNativeElement();
		
		//init mouse listeners
		initMouse();
		
		//init key listeners
		initKeyboard();
		
		//init the style for this HTMLElement
		initStyle();
	}
	
	/**
	 * instantiate the right nativeElement
	 */
	private function initNativeElement():Void
	{
		_nativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.custom(_tagName));
	}
	
	/**
	 * initialise the mouse listeners on this HTMLElement by 
	 * listening to the current native element
	 */
	private function initMouse():Void
	{
		_mouse = new Mouse(cast(this));
	}
	
	/**
	 * initialise the keyboard listener on this HTMLElement. The 
	 * key events are triggered on the HTMLElement which has the
	 * focus
	 */
	private function initKeyboard():Void
	{
		_keyboard = new Keyboard(cast(this));
	}
	
	/**
	 * Instantiate the right style object for this
	 * HTMLElement. Overriden by HTMLElements with
	 * specific style objects, such as HTMLImageElement
	 */
	private function initStyle():Void
	{
		this._style = new ContainerStyle(cast(this));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * invalidate Style after DOM change
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		_style.invalidate();
		return newChild;
	}
	
	/**
	 * invalidate Style after DOM change
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		_style.invalidate();
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE SETTER/GETTER
	// Proxies setting/getting properties from the mouse listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		_onClick = value;
		
		if (_onClick == null)
		{
			_mouse.onClick = null;
		}
		else
		{
			_mouse.onClick = onClickCallback;
		}
		
		return value;
	}
	
	private function get_onClick():MouseEvent->Void
	{
		return _onClick;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
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
	
	private function get_onMouseDown():MouseEvent->Void
	{
		return _onMouseDown;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
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
	
	private function get_onMouseUp():MouseEvent->Void
	{
		return _onMouseUp;
	}
	
	private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
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
	
	private function get_onMouseOver():MouseEvent->Void
	{
		return _onMouseOver;
	}
	
	private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
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
	
	private function get_onMouseOut():MouseEvent->Void
	{
		return _onMouseOut;
	}
	
	private function set_onMouseMove(value:MouseEvent->Void):MouseEvent->Void
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
	
	private function get_onMouseMove():MouseEvent->Void
	{
		return _onMouseMove;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE EVENT CALLBACK
	// called by the Mouse instance when the user interacts
	// with the HTMLElement with its mouse
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onClickCallback(mouseEvent:MouseEvent):Void
	{
		_onClick(mouseEvent);
	}
	
	private function onMouseDownCallback(mouseEvent:MouseEvent):Void
	{
		_onMouseDown(mouseEvent);
	}
	
	private function onMouseUpCallback(mouseEvent:MouseEvent):Void
	{
		_onMouseUp(mouseEvent);
	}
	
	private function onMouseMoveCallback(mouseEvent:MouseEvent):Void
	{
		_onMouseMove(mouseEvent);
	}
	
	private function onMouseOverCallback(mouseEvent:MouseEvent):Void
	{
		_onMouseOver(mouseEvent);
	}
	
	private function onMouseOutCallback(mouseEvent:MouseEvent):Void
	{
		_onMouseOut(mouseEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD SETTER/GETTER
	// Proxies setting/getting properties from the keyboard listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
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
	
	private function get_onKeyDown():KeyboardEvent->Void
	{
		return _keyboard.onKeyDown;
	}
	
	private function set_onKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
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
	
	private function get_onKeyUp():KeyboardEvent->Void
	{
		return _keyboard.onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD EVENT CALLBACK
	// called by the Keyboard instance when the user interacts
	// with the keyboard while this HTMLElement has the focus
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
	 * Gives keyboard focus to the HTMLElement
	 * The focus manager determines if the HTMLElement can
	 * actually receive focus
	 */
	public function focus():Void
	{
		FocusManager.getInstance().activeElement = cast(this);
	}
	
	/**
	 * Removes keyboard focus from this HTMLElement and 
	 * the focus on the Document
	 * 
	 * TODO : check if it actually work
	 * TODO : check if focus must be set on Document if
	 * this element currently doesn't have focus
	 * TODO : should call focus on Document or Document.body
	 * instead of setting activeElement to null. Should
	 * Document have a focus() method ? Should it inherit
	 * form HTMLElement or share common interface ?
	 */
	public function blur():Void
	{
		FocusManager.getInstance().activeElement = null;
	}
	
	/**
	 * default HTMLElement are not focusable unless their
	 * tabIndex attribute is not null
	 */
	private function get_isDefaultFocusable():Bool
	{
		return false;
	}
	
	private function set_onFocus(value:Event->Void):Event->Void
	{
		return _onFocus = value;
	}
	
	private function get_onFocus():Event->Void
	{
		return _onFocus;
	}
	
	private function set_onBlur(value:Event->Void):Event->Void
	{
		return _onBlur = value;
	}
	
	private function get_onBlur():Event->Void
	{
		return _onBlur;
	}
	
	/**
	 * when set, invalidate the focus manager
	 * tab list, as this HTMLElement may appear
	 * at another index of the tab list
	 */
	private function set_tabIndex(value:Null<Int>):Null<Int>
	{
		FocusManager.getInstance().invalidate();
		return _tabIndex = value;
	}
	
	private function get_tabIndex():Null<Int>
	{
		return _tabIndex;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLING SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onScroll(value:Event->Void):Event->Void
	{
		return _onScroll = value;
	}
	
	private function get_onScroll():Event->Void
	{
		return _onScroll;
	}
	
	/**
	 * called when a native scroll event is
	 * emitted, calles the user on scroll
	 * callback if any
	 */
	private function onScrollCallback(event:Event):Void
	{
		if (_onScroll != null)
		{
			_onScroll(event);
		}
	}
	
	//TODO : implement
	private function get_scrollHeight():Int
	{
		return -1;
	}
	
	private function get_scrollWidth():Int
	{
		return -1;
	}
	
	private function set_scrollLeft(value:Int):Int
	{
		return -1;
	}
	
	private function get_scrollLeft():Int
	{
		return -1;
	}
	
	private function set_scrollTop(value:Int):Int
	{
		return -1;
	}
	
	private function get_scrollTop():Int
	{
		return -1;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the reference to this HTMLElement native element
	 * @return a DisplayObject in AS, an HTML element in JS...
	 */
	private function get_nativeElement():NativeElement
	{
		return this._nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// COORDS SETTERS/GETTERS
	// Setters/Getters for an HTMLElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the first positioned ancestor of the HTMLElement
	 * 
	 * @return an HTMLElement or null if this HTMLElement is not yet
	 * added to the DOM
	 */
	private function get_offsetParent():HTMLElement
	{
		return _style.getFirstPositionedAncestor();
	}
	
	private function get_offsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	private function get_offsetHeight():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//TODO : will it work for inline elements ?
	private function get_offsetLeft():Int
	{
		var firstPositionedAncestor:HTMLElement = offsetParent;
		
		var offsetLeft:Int = 0;
		
		if (firstPositionedAncestor != null)
		{
			var parent:HTMLElement = cast(parentNode);
			
			while (parent != firstPositionedAncestor)
			{
				offsetLeft += parent.style.computedStyle.paddingLeft + parent.style.computedStyle.marginLeft;
				parent = cast(parent.parentNode);
			}
		}
		
		return offsetLeft;
	}
	
	private function get_offsetTop():Int
	{
		var firstPositionedAncestor:HTMLElement = offsetParent;
		
		var offsetTop:Int = 0;
		
		if (firstPositionedAncestor != null)
		{
			var parent:HTMLElement = cast(parentNode);
			
			while (parent != firstPositionedAncestor)
			{
				offsetTop += parent.style.computedStyle.paddingTop + parent.style.computedStyle.marginTop;
				parent = cast(parent.parentNode);
			}
		}
		
		return offsetTop;
	}
	
	private function get_clientWidth():Int
	{
		return _style.computedStyle.width;
	}
	
	private function get_clientHeight():Int
	{
		return _style.computedStyle.height;
	}
	
	private function get_clientTop():Int
	{
		return _style.computedStyle.paddingTop;
	}
	
	private function get_clientLeft():Int
	{
		return _style.computedStyle.paddingLeft;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_style():Style
	{
		return this._style;
	}
	
}