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
import cocktail.core.dom.NamedNodeMap;
import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLDocument;
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
import cocktail.core.renderer.TextRenderer;
import cocktail.core.style.adapter.Style;
import cocktail.core.style.CoreStyle;
import haxe.Log;
import cocktail.core.focus.FocusManager;
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
class HTMLElement extends Element
{
	/**
	 * The name of the id attribute in HTML
	 */
	private static inline var HTML_ID_ATTRIBUTE:String = "id";
	
	/**
	 * The name of the class attribute in HTML
	 */
	private static inline var HTML_CLASS_ATTRIBUTE:String = "class";
	
	/**
	 * the name of the tab index attribute in HTML
	 */
	private static inline var HTML_TAB_INDEX_ATTRIBUTE:String = "tabIndex";
	
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
	
	/**
	 * The callback called when the mouse wheel is rotated while the mouse
	 * pointer is over this element
	 */
	private var _onMouseWheel:WheelEvent->Void;
	public var onmousewheel(get_onMouseWheel, set_onMouseWheel):WheelEvent->Void;
	
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
	 * user press the TAB key. If it is not set or set to 0, the document
	 * order is used to establish focus order and the HTMLElement
	 * is only focused if it is intrinsically focusable, like for
	 * instance an HTMLInputElement
	 */
	public var tabIndex(get_tabIndex, set_tabIndex):Int;
	
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
	 * The scroll view height of the HTMLElement. Returns either
	 * the height of the HTMLElement or the height of its content,
	 * whichever is greater. For instance if the HTMLElement displays
	 * scrollbars because its content is higher than its content area,
	 * scrollHeight will be larger than clientHeight
	 */
	public var scrollHeight(get_scrollHeight, never):Int;
	
	/**
	 * Same as scrollHeight for width
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
	 * get/set a class on the HTMLElement.
	 * An array of class can be given by separating each
	 * class name by a space
	 * 
	 * className is used instead of class for conflict with
	 * language reserved word
	 */
	public var className(get_className, set_className):String;
	
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
	 * its computed styles. It is only instantiated
	 * if the HTMLElement must be displayed.
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
		this._coreStyle = new CoreStyle(this);
	}
	
	/**
	 * Init the style adapter providing manipulation
	 * of the styles through CSS strings
	 */
	private function initStyle():Void
	{
		_style = new Style(_coreStyle);
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
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * try to attach the new child to the
	 * rendering tree
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		//only element and text node are visual and can be
		//attached to the rendering tree
		switch (newChild.nodeType)
		{
			case Node.ELEMENT_NODE:
				var htmlChild:HTMLElement = cast(newChild);
				htmlChild.attach();
				
			case Node.TEXT_NODE:
				var textChild:Text = cast(newChild);
				textChild.attach();
		}
		
		return newChild;
	}
	
	/**
	 * try to detach the old child from the
	 * rendering tree
	 */
	override public function removeChild(oldChild:Node):Node
	{
		//must happen before calling super, else
		//the HTMLElement won't have a parent to be detached
		//from anymore
		switch (oldChild.nodeType)
		{
			case Node.ELEMENT_NODE:
				var htmlChild:HTMLElement = cast(oldChild);
				htmlChild.detach();
				
			case Node.TEXT_NODE:
				var textChild:Text = cast(oldChild);
				textChild.detach();
		}
		
		super.removeChild(oldChild);
	
	
		return oldChild;
	}
	
	/**
	 * Overriden to make the tag name case-insensitive in an
	 * HTML document
	 */
	override public function getElementsByTagName(tagName:String):Array<HTMLElement>
	{
		return super.getElementsByTagName(tagName.toLowerCase());
	}
	
	/**
	 * Overriden to run through the necessary check for 
	 * HTML attribute retrieval
	 */
	override public function getAttribute(name:String):String
	{
		if (name == HTML_TAB_INDEX_ATTRIBUTE)
		{
			return Std.string(get_tabIndex());
		}
		else
		{
			return super.getAttribute(name);
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the value of a style changes, the ElementRenderer is 
	 * invalidated if this HTMLElement is being rendered as it 
	 * might need a re-layout and re-rendering
	 */
	public function invalidateLayout(immediate:Bool = false):Void
	{
		if (_elementRenderer != null)
		{
			_elementRenderer.invalidateLayout(immediate);
		}
	}
	
	public function invalidateLayer():Void
	{
		if (_elementRenderer != null)
		{
			_elementRenderer.invalidateLayer();
		}
	}
	
	
	public function invalidateText():Void
	{
		if (_elementRenderer != null)
		{
			_elementRenderer.invalidateText();
		}
	}
	
	/**
	 * When the Display style this special case happen, as the 
	 * ElementRenderer needs to be changed.
	 * 
	 * For instance if the previous value of Display was
	 * "block" and it is changed to "none", then the ElementRenderer
	 * must be removed from the rendering tree and destroyed
	 * 
	 * Another example is if the value of Display if "inline" and
	 * it is swiched to "blick", then the current inline ElementRenderer
	 * must be replaced by a block ElementRenderer
	 */
	public function invalidateDisplay():Void
	{
		detach();
		attach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING TREE METHODS
	//
	// The HTMLElement is in charge of attaching and detaching its ElementRenderer to/from
	// the rendering tree when appropriate. The HTMLElement is only displayed to the screen
	// when attached to the rendering tree
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Tries to attach the ElementRender to the rendering tree. If it is
	 * in fact attached, all of its children will be attached too.
	 * 
	 * The parent HTMLElement's ElementRenderer is always attached before
	 * its children ElementRenderers
	 */
	public function attach():Void
	{	
		//if the parent HTMLElement ElementRenderers is null, then
		//the parent is either not attached to the DOM or not rendered,
		//and this HTMLElement is not rendered either
		if (isParentRendered() == true)
		{
	
			//create the ElementRenderer if needed
			if (_elementRenderer == null && isRendered() == true)
			{
				createElementRenderer();
			}
			
			//if the ElementRenderer wasn't instantiated, then this
			//HTMLElement is not supposed to be rendered
			if (_elementRenderer != null)
			{
				//do attach to parent ElementRenderer
				attachToParentElementRenderer();
				
				//the HTMLElement is now attached and can attach its children
				for (i in 0..._childNodes.length)
				{
					//only text and element node can be attached, as other nodes
					//types are not visual
					switch (_childNodes[i].nodeType)
					{
						case Node.ELEMENT_NODE:
							var child:HTMLElement = cast(_childNodes[i]);
							child.attach();
							
						//when one of the child is a text node, it is the responsability
						//of the parent HTMLElement node to create a TextRenderer and attach it
						//to the rendering tree
						//TODO : obsolete doc
						case Node.TEXT_NODE:
							var child:Text = cast(_childNodes[i]);
							child.attach();
					}
				}
			}
		}
	}
	
	/**
	 * Detach the ElementRenderer from the rendering tree
	 * and all of its children.
	 * 
	 * The children ElementRenderer are always detached before
	 * their parent ElementRenderer
	 */
	public function detach():Void
	{
		//if the parent is not attached, then this ElementRenderer
		//is not attached
		if (isParentRendered() == true)
		{
		
			var parent:HTMLElement = cast(_parentNode);
			
			//if this HTMLElement isn't currently rendered, no need
			//to detach it
			if (_elementRenderer != null)
			{	
				//detach first all children
				for (i in 0..._childNodes.length)
				{
					switch (_childNodes[i].nodeType)
					{
						case Node.ELEMENT_NODE:
							var child:HTMLElement = cast(_childNodes[i]);
							child.detach();
							
						case Node.TEXT_NODE:
							var child:Text = cast(_childNodes[i]);
							child.detach();
					}
				}
											
				//then detach this ElementRenderer from the parent 
				//ElementRenderer, then destroy it
				detachFromParentElementRenderer();
				_elementRenderer = null;
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the first HTMLElement sibling which has an
	 * ElementRenderer attached to the rendering tree or null
	 * if there is none. It is used to know where to attach this
	 * HTMLElement's ElementRenderer in the rendering tree
	 */
	private function getNextElementRendererSibling():ElementRenderer
	{
		var nextSibling:HTMLElement = cast(nextSibling);
		
		if (nextSibling == null)
		{
			return null;
		}
		else
		{
			while (nextSibling != null)
			{
				if (nextSibling.elementRenderer != null)
				{
					return cast(nextSibling.elementRenderer);
				}
				
				nextSibling = cast(nextSibling.nextSibling);
			}
		}
		
		return null;
	}
	
	/**
	 * attach the created ElementRenderer to the rendering tree before the ElementRenderer
	 * of the first next HTMLElement sibling which also has an attached ElementRenderer.
	 * If there is none such sibling, it is appended as the last child of this node of
	 * the rendering tree
	 */
	private function attachToParentElementRenderer():Void
	{
		var parent:HTMLElement = cast(_parentNode);
		parent.elementRenderer.insertBefore(_elementRenderer, getNextElementRendererSibling());
	
	}
	
	/**
	 * When this HTMLElement is detached, it detached its
	 * ElementRenderer from its parent ElementRenderer
	 */
	private function detachFromParentElementRenderer():Void
	{
		_elementRenderer.parentNode.removeChild(_elementRenderer);
	}
	
	/**
	 * Instantiate the right ElementRenderer
	 * based on the Display style and/or the 
	 * type of HTMLElement
	 */
	private function createElementRenderer():Void
	{
		_coreStyle.computeDisplayStyles();
		
		switch (_coreStyle.computedStyle.display)
		{
			case block, inlineBlock:
				_elementRenderer = new BlockBoxRenderer(this);
				//TODO : when creating, coreStyle should be reinitialised
				_elementRenderer.coreStyle = _coreStyle;
				
			case cssInline:
				_elementRenderer = new InlineBoxRenderer(this);
				_elementRenderer.coreStyle = _coreStyle;
				
			case none:
		}
	}
	
	/**
	 * Return wether this HTMLElement is supposed to be rendered
	 * 
	 * TODO : should use computed display style (although it computes
	 * the same as the specified value ?) and also take into account
	 * the HTML "hidden" attribute
	 */
	private function isRendered():Bool
	{
		return _coreStyle.display != Display.none;
	}
	
	/**
	 * Determine wether the parent HTMLElement is
	 * rendered and attached to the rendering tree
	 */
	private function isParentRendered():Bool
	{
		if (_parentNode == null)
		{
			return false;
		}
		var htmlParent:HTMLElement = cast(_parentNode);
		if (htmlParent.elementRenderer != null)
		{
			return true;
		}
		else
		{
			return false;
		}
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
			var mouseEvent:MouseEvent = new MouseEvent();
			mouseEvent.initMouseEvent(MouseEvent.CLICK, false, false, null, 0, 0, 0, 0, 0, false, false, false, false,
			0, null);
			_onClick(mouseEvent);
		}
	}
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		if (_onClick != null)
		{
			removeEventListener(MouseEvent.CLICK, cast(_onClick));
		}
		_onClick = value;
		if (_onClick != null)
		{
			addEventListener(MouseEvent.CLICK, cast(_onClick));
		}
		
		return value;
	}
	
	private function get_onClick():MouseEvent->Void
	{
		return _onClick;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		if (_onMouseDown != null)
		{
			removeEventListener(MouseEvent.MOUSE_DOWN, cast(_onMouseDown));
		}
		_onMouseDown = value;
		if (_onMouseDown != null)
		{
			addEventListener(MouseEvent.MOUSE_DOWN, cast(_onMouseDown));
		}
		
		return value;
	}
	
	private function get_onMouseDown():MouseEvent->Void
	{
		return _onMouseDown;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		if (_onMouseUp != null)
		{
			removeEventListener(MouseEvent.MOUSE_UP, cast(_onMouseUp));
		}
		_onMouseUp = value;
		if (_onMouseUp != null)
		{
			addEventListener(MouseEvent.MOUSE_UP, cast(_onMouseUp));
		}
		
		return value;
	}
	
	private function get_onMouseUp():MouseEvent->Void
	{
		return _onMouseUp;
	}
	//TODO : update with event listeners
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
	
	private function set_onMouseWheel(value:WheelEvent->Void):WheelEvent->Void
	{
		return _onMouseWheel = value;
	}
	
	private function get_onMouseWheel():WheelEvent->Void
	{
		return _onMouseWheel;
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
		else if (tabIndex > 0)
		{
			return true;
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
	
	private function set_tabIndex(value:Int):Int
	{
		setAttribute(HTML_TAB_INDEX_ATTRIBUTE, Std.string(value));
		return value;
	}
	
	/**
	 * Return the tab index as an int
	 * @return
	 */
	private function get_tabIndex():Int
	{
		var tabIndex:String = getAttribute(HTML_TAB_INDEX_ATTRIBUTE);
		if (tabIndex == "")
		{
			//default value for focusable element is 0,
			//else its -1
			if (isDefaultFocusable() == true)
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return Std.parseInt(tabIndex);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// ACTIVATION BEHAVIOUR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Certain elements in HTML have an activation behavior,
	 * which means that the user can activate them. 
	 * This triggers a sequence of events dependent on the activation mechanism,
	 * and normally culminating in a click event, as described below.
	 * 
	 * For instance, an HTMLAnchorElement has the activation behaviour of
	 * following a link. If one of its children is clicked by the user,
	 * it will trigger its activation behaviour
	 */
	
	 /**
	  * Wheter this HTMLElement has any activation 
	  * behaviour associated with it
	  */
	public function hasActivationBehaviour():Bool
	{
		return false;
	}
	
	/**
	 * called before the click event is dipatched
	 */
	public function runPreClickActivation():Void
	{
		
	}
	
	/**
	 * Called if the activation behaviour is cancelled
	 */
	public function runCanceledActivationStep():Void
	{
		
	}
	
	/**
	 * Called after the click was dispatched
	 */
	public function runPostClickActivationStep(event:MouseEvent):Void
	{
		
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
	
	//TODO : should unit test, not very what this getter
	//is supposed to return
	private function get_scrollHeight():Int
	{
		if (_elementRenderer != null)
		{
			return Math.round(_elementRenderer.scrollHeight);
		}
		return 0;
	}
	
	private function get_scrollWidth():Int
	{
		if (_elementRenderer != null)
		{
			return Math.round(_elementRenderer.scrollWidth);
		}
		return 0;
	}
	
	
	//TODO : shouldn't HTMLElement be the model for all attributes
	//instead ? Shouldn't ElementRenderer set the value of scrollLeft/scrollTop
	//on the HTMLElement ?
	private function set_scrollLeft(value:Int):Int
	{
		if (_elementRenderer != null)
		{
			_elementRenderer.scrollLeft = value;
		}
		return 0;
	}
	
	private function get_scrollLeft():Int
	{
		if (_elementRenderer != null)
		{
			return Math.round(_elementRenderer.scrollLeft);
		}
		return 0;
	}
	
	private function set_scrollTop(value:Int):Int
	{
		if (_elementRenderer != null)
		{
			_elementRenderer.scrollTop = value;
		}
		return 0;
	}
	
	private function get_scrollTop():Int
	{
		if (_elementRenderer != null)
		{
			return Math.round(_elementRenderer.scrollTop);
		}
		return 0;
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
	 * Return the class name value from the attributes
	 * hash
	 */
	private function get_className():String
	{
		return getAttribute(HTML_CLASS_ATTRIBUTE);
	}
	
	/**
	 * set the class name value on the attributes
	 * hash
	 */
	private function set_className(value:String):String
	{
		setAttribute(HTML_CLASS_ATTRIBUTE, value);
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
			removeChild(_childNodes[0]);	
		}
		
		//TODO : only detach all node in this case ?
		if (value == "")
		{
			return value;
		}
		
		//TODO : returned elements should be direct child
		//of this, wrapped should not be direct child of
		//this
		var bim:String = "<div>";
		bim += value;
		bim += "</div>";
		
		var node:Node = HxtmlConverter.getNode(bim);
		
		for (i in 0...node.childNodes.length)
		{
			appendChild(node.childNodes[0]);
		}
		
		
		return value;
	}
	
	/**
	 * Serialise the descendant nodes of this HTMLElement
	 * and return the result as an HTML String
	 */
	private function get_innerHTML():String
	{
		var xml:Xml = doGetInnerHTML(this, Xml.createElement(nodeName));
		
		var str:String = xml.toString();
		
		str = str.substr(str.indexOf(">") + 1 , str.lastIndexOf("<") - str.indexOf(">") - 1);
		
		return str;
	}
	
	//TODO : doc
	private function doGetInnerHTML(node:Node, xml:Xml):Xml
	{
		
		for (i in 0...node.childNodes.length)
		{
			var child:Node = node.childNodes[i];
			
			switch(child.nodeType)
			{
				case Node.ELEMENT_NODE:
					var childXml:Xml = Xml.createElement(child.nodeName);
					
					var childAttributes:NamedNodeMap = child.attributes;
					
					for (j in 0...childAttributes.length)
					{
						var attribute:Attr = cast(childAttributes.item(j));
						
						if (attribute.specified == true)
						{
							childXml.set(attribute.name, attribute.value);
						}
					}
					
					xml.addChild(doGetInnerHTML(child, childXml));
					
				case Node.TEXT_NODE:
					
					var textXml:Xml = Xml.parse(child.nodeValue);
					xml.addChild(textXml.firstChild());
			}
		}
		
		return xml;
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
		//here the HTMLElement is not
		//attached to the DOM
		if (_parentNode == null)
		{
			return null;
		}
		
		var parent:HTMLElement = cast(_parentNode);
		
		//loop in all the parents until a positioned or a null parent is found
		var isOffsetParent:Bool = parent.elementRenderer.isPositioned();
		
		while (isOffsetParent == false)
		{
			if (parent.parentNode != null)
			{
				parent = cast(parent.parentNode);
				isOffsetParent = parent.elementRenderer.isPositioned();
			}
			//break the loop if the current parent has no parent
			else
			{
				isOffsetParent = true;
			}
		}
		
		return parent;
	}
	
	private function get_offsetWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		invalidateLayout(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	private function get_offsetHeight():Int
	{
		invalidateLayout(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//TODO : unit test
	private function get_offsetLeft():Int
	{
		invalidateLayout(true);
		return Math.round(_elementRenderer.positionedOrigin.x);
	}
	
	private function get_offsetTop():Int
	{
		invalidateLayout(true);
		return Math.round(_elementRenderer.positionedOrigin.y);
	}
	
	private function get_clientWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		invalidateLayout(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	private function get_clientHeight():Int
	{
		invalidateLayout(true);
		var computedStyle:ComputedStyleData = this._coreStyle.computedStyle;
		return computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	//TODO : should be top border height
	private function get_clientTop():Int
	{
		invalidateLayout(true);
		return 0;
	}
	
	//TODO : should be left border width
	private function get_clientLeft():Int
	{
		invalidateLayout(true);
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