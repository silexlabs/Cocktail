/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.dom.Attr;
import cocktail.core.dom.Element;
import cocktail.core.dom.Node;
import cocktail.core.event.IEventTarget;
import cocktail.core.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.hxtml.HxtmlConverter;
import cocktail.core.NativeElement;
import cocktail.core.event.Event;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InlineBlockLineBox;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.style.adapter.Style;
import cocktail.core.style.CoreStyle;
import haxe.Log;
//import cocktail.core.focus.FocusManager;
import cocktail.core.Keyboard;
import cocktail.core.Mouse;
import cocktail.core.style.StyleData;

/**
 * All HTML element interfaces derive from this class.
 * Elements that only expose the HTML core attributes are represented 
 * by the base HTMLElement interface.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLElement extends Element, implements IEventTarget
{
	/**
	 * The name of the id attribute in HTML
	 */
	private static inline var HTML_ID_ATTRIBUTE:String = "id";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Mouse attributes and callback
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard attributes and callback
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
	// Focus attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The tab index order of the HTMLElement. If the index
	 * is set, it is used to determine focus order when the
	 * user press the TAB key. If it is not set, the document
	 * order is used to establish focus order and the HTMLElement
	 * is only focused if it is intrinsically focusable, like for
	 * instance an HTMLInputElement
	 * 
	 * TODO : should be stored in the attributes hash instead,
	 * no need for class attribute
	 */
	private var _tabIndex:Null<Int>;
	public var tabIndex(get_tabIndex, set_tabIndex):Null<Int>;
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	private var _onFocus:Event->Void;
	public var onfocus(get_onFocus, set_onFocus):Event->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	private var _onBlur:Event->Void;
	public var onblur(get_onBlur, set_onBlur):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	private var _onScroll:Event->Void;
	public var onscroll(get_onScroll, set_onScroll):Event->Void;
	
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
	 * This attribute assigns an id to an element. 
	 * This id must be unique in a document.
	 * 
	 * get/set the id attribute from the attributes
	 * map
	 */
	public var id(get_id, set_id):String;
	
	/**
	 * sets or gets the HTML
	 * syntax describing the element's descendants.
	 */
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Rendering attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This object is part of the rendering tree
	 * and is used to render this HTMLElement using
	 * its computed styles
	 */
	private var _elementRenderer:ElementRenderer;
	public var elementRenderer(get_elementRenderer, never):ElementRenderer;
	
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
	 * This attributes stores the Style data
	 * as typed objects and use them to compute
	 * the box model and the text rendering of the
	 * HTMLElement. It is the style object used
	 * internally doing all the style heavy lifting.
	 * It can be used by end-user when they want to
	 * define styles using typed object instead of string
	 */
	private var _coreStyle:CoreStyle;
	public var coreStyle(get_coreStyle, never):CoreStyle;
	
	/**
	 * This is the style object exposed by the public API.
	 * It is used to set and get CSS styles with strings, like
	 * when using JavaScript in the browser,
	 * and is in charge of converting them to typed object
	 * which it sets on coreStyle
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
		//init the core style for this HTMLElement
		initCoreStyle();
		
		//init the CSS style adapter
		initStyle();
		
		//init the Id attribute
		initId();
	}
	
	/**
	 * Instantiate the right style object for this
	 * HTMLElement. Overriden by HTMLElements with
	 * specific style objects, such as HTMLImageElement
	 */
	private function initCoreStyle():Void
	{
		this._coreStyle = new CoreStyle();
	}
	
	/**
	 * Init the style adapter providing manipulation
	 * of the styles through CSS strings
	 */
	private function initStyle():Void
	{
		_style = new Style(cast(_coreStyle));
	}
	
	/**
	 * Define the id attribute in the
	 * attribute maps, but it has no
	 * value yet
	 */
	private function initId():Void
	{
		var id:Attr = new Attr(HTML_ID_ATTRIBUTE);
		setIdAttributeNode(id, true);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : doc
	public function attach(parent:ElementRenderer):Void
	{
		createElementRenderer();
		if (_elementRenderer != null)
		{
			parent.appendChild(_elementRenderer);
		}
		
	}
	
	public function detach(parent:ElementRenderer):Void
	{
		parent.removeChild(_elementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function createElementRenderer():Void
	{
		switch (_coreStyle.computedStyle.display)
		{
			case block, inlineBlock:
				_elementRenderer = new BlockBoxRenderer(this);
				_elementRenderer.coreStyle = _coreStyle;
				
			case cssInline:
				_elementRenderer = new InlineBoxRenderer(this);
				_elementRenderer.coreStyle = _coreStyle;
				
			case none:
		}
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
	//	_coreStyle.invalidate();
		return newChild;
	}
	
	/**
	 * invalidate Style after DOM change
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		//_coreStyle.invalidate();
		return oldChild;
	}
	
	/**
	 * Overriden to make the tag name case-insensitive in an
	 * HTML document
	 */
	override public function getElementsByTagName(tagName:String):Array<Node>
	{
		return super.getElementsByTagName(tagName.toLowerCase());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE SETTER/GETTER AND METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Simulates a mouse click on an element.
	 * 
	 * The screen and client coordinate of the 
	 * generated MouseEvent are 0 and modifier
	 * key (Shift, control...) correspond
	 * to the current modifier key state
	 * 
	 * TODO : get current modifier key state
	 */
	public function click():Void
	{
		if (_onClick != null)
		{
			_onClick(new MouseEvent(MouseEvent.CLICK, cast(this), 0, 0, 0, 0, 0, false, false, false));
		}
	}
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onClick = value;
	}
	
	private function get_onClick():MouseEvent->Void
	{
		return _onClick;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onMouseDown = value;
	}
	
	private function get_onMouseDown():MouseEvent->Void
	{
		return _onMouseDown;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onMouseUp = value;
	}
	
	private function get_onMouseUp():MouseEvent->Void
	{
		return _onMouseUp;
	}
	
	private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onMouseOver = value;
	}
	
	private function get_onMouseOver():MouseEvent->Void
	{
		return _onMouseOver;
	}
	
	private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onMouseOut = value;
	}
	
	private function get_onMouseOut():MouseEvent->Void
	{
		return _onMouseOut;
	}
	
	private function set_onMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		return _onMouseMove = value;
	}
	
	private function get_onMouseMove():MouseEvent->Void
	{
		return _onMouseMove;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		return _onKeyDown = value;
	}
	
	private function get_onKeyDown():KeyboardEvent->Void
	{
		return _onKeyDown;
	}
	
	private function set_onKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		return _onKeyUp = value;
	}
	
	private function get_onKeyUp():KeyboardEvent->Void
	{
		return _onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS SETTER/GETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the htmlElement can receive
	 * focus
	 */
	public function isFocusable():Bool
	{
		//if it isn't attached to the DOM,
		//it can't be focused
		if (parentNode == null)
		{
			return false;
		}
		
		//it can be focused if it is inherently
		//focusable
		else if (isDefaultFocusable() == true)
		{
			return true;
		}
		
		//else, an element with a tab index 
		//superior to 0 can receive focus
		else if (tabIndex != null)
		{
			if (tabIndex > 0)
			{
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Return wether this HTMLElement can intrinsically recieve
	 * focus, this is the case for instance for HTMLInputElement
	 */
	private function isDefaultFocusable():Bool
	{
		return false;
	}
	
	/**
	 * Gives keyboard focus to the HTMLElement
	 * The focus manager determines if the HTMLElement can
	 * actually receive focus
	 */
	public function focus():Void
	{
		if (isFocusable() == true)
		{
			var htmlDocument:HTMLDocument = cast(ownerDocument);
			htmlDocument.activeElement = cast(this);
		}
	}
	
	/**
	 * Removes keyboard focus from this HTMLElement and 
	 * the focus on the Document
	 * 
	 * TODO : check if focus must be set on Document if
	 * this element currently doesn't have focus
	 */
	public function blur():Void
	{
		var htmlDocument:HTMLDocument = cast(ownerDocument);
		htmlDocument.body.focus();
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
	
	private function set_tabIndex(value:Null<Int>):Null<Int>
	{
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
	
	//TODO : implement scroll
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
	// DOM GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrieve the id value from the attributes
	 * map
	 * @return the id as a String or an empty
	 * String if it was not set 
	 * 
	 * TODO : maybe for getter should return null
	 * if not defined ?
	 */
	private function get_id():String
	{
		return getAttribute(HTML_ID_ATTRIBUTE);
	}
	
	/**
	 * update the id value on the attributes map
	 */
	private function set_id(value:String):String
	{
		setAttribute(HTML_ID_ATTRIBUTE, value);
		return value;
	}
	
	/**
	 * Remove all the currently added child nodes,
	 * deserialise the passed HTML string and attach
	 * the resulting child nodes
	 * 
	 * @param	value an HTML String 
	 */
	private function set_innerHTML(value:String):String
	{
		for (i in 0..._childNodes.length)
		{
			removeChild(_childNodes[i]);
		}
		appendChild(HxtmlConverter.getNode(value));
		return value;
	}
	
	/**
	 * Serialise the descendant nodes of this HTMLElement
	 * and return the result as an HTML String
	 * 
	 * TODO : implement
	 */
	private function get_innerHTML():String
	{
		return '';
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// COORDS SETTERS/GETTERS
	// Setters/Getters for an HTMLElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the first positioned ancestor of the HTMLElement
	 * 
	 * @return an HTMLElement or null if this HTMLElement is not yet
	 * added to the DOM or is the HTMLBodyElement
	 */
	private function get_offsetParent():HTMLElement
	{
		return _elementRenderer.getFirstPositionedAncestor();
	}
	
	private function get_offsetWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		//_coreStyle.invalidate(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	private function get_offsetHeight():Int
	{
		//_coreStyle.invalidate(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//TODO : unit test
	private function get_offsetLeft():Int
	{
		//_coreStyle.invalidate(true);
		return Math.round(_elementRenderer.positionedOrigin.x);
	}
	
	private function get_offsetTop():Int
	{
		//_coreStyle.invalidate(true);
		return Math.round(_elementRenderer.positionedOrigin.y);
	}
	
	private function get_clientWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		//_coreStyle.invalidate(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	private function get_clientHeight():Int
	{
		//_coreStyle.invalidate(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//TODO : should be top border height
	private function get_clientTop():Int
	{
		//_coreStyle.invalidate(true);
		return 0;
	}
	
	//TODO : should be left border width
	private function get_clientLeft():Int
	{
		//_coreStyle.invalidate(true);
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// RENDERING GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_elementRenderer():ElementRenderer
	{
		return _elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_coreStyle():CoreStyle
	{
		return this._coreStyle;
	}
	
	private function get_style():Style
	{
		return _style;
	}
	
}