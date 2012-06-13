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
import cocktail.core.event.EventTarget;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.ComputedStyle;
import lib.hxtml.CssParser;
import lib.hxtml.HxtmlConverter;
import lib.haxe.xml.Parser;
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
import cocktail.Lib;
import haxe.Log;
import cocktail.core.focus.FocusManager;
import cocktail.core.style.StyleData;
import lib.hxtml.IStyleProxy;
import cocktail.core.renderer.RendererData;

/**
 * All HTML element interfaces derive from this class.
 * Elements that only expose the HTML core attributes are represented 
 * by the base HTMLElement interface.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLElement extends Element
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Scroll attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	// DOM PARSER attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
		var id:Attr = new Attr(HTMLConstants.HTML_ID_ATTRIBUTE_NAME);
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
	 * Overriden to update the style of the HTMLElement when
	 * the style attribte is set
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME)
		{
			//TODO 1 : big hack to make style work, hxtml is no longer 
			//useful at this point
			var styleProxy = new StyleProxy();
			new CssParser<HTMLElement>().parse(value, this, cast(styleProxy));
			super.setAttribute(name, value);
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	/**
	 * Overriden to run through the necessary check for 
	 * HTML attribute retrieval
	 */
	override public function getAttribute(name:String):String
	{
		if (name == HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME)
		{
			return Std.string(get_tabIndex());
		}
		else
		{
			return super.getAttribute(name);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to also add the html document and the window
	 * as targets ancestors for the bubbling and capture phase
	 * of the event
	 */
	override private function getTargetAncestors():Array<EventTarget>
	{
		var targetAncestors:Array<EventTarget> = super.getTargetAncestors();
		targetAncestors.push(Lib.document);
		targetAncestors.push(Lib.window);
		return targetAncestors;
	}
	
	/**
	 * Execute the default actions of the HTMLElement for a given event type,
	 * if the default was not prevented
	 */
	override private function executeDefaultActionIfNeeded(defaultPrevented:Bool, event:Event):Void
	{
		if (defaultPrevented == false)
		{
			switch (event.type)
			{
				//if the element is focusable, by default
				//on mouse down, it will gain focus
				case MouseEvent.MOUSE_DOWN:
					focus();
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the specified value of a style requiring a re-layout
	 * is changed, for instance when the width is changed. Invalidate
	 * the layout of the elementRenderer if the HTMLElement is rendered
	 */
	public function invalidate(invalidationReason:InvalidationReason):Void
	{
		//TODO 4 : should use helper method like isRenderer instead of
		//relying on nullness
		if (_elementRenderer != null)
		{
			_elementRenderer.invalidate(invalidationReason);
		}
	}
	
	/**
	 * When the Display style changes, this special case happen, as the 
	 * ElementRenderer might need to be changed.
	 * 
	 * For instance if the previous value of Display was
	 * "block" and it is changed to "none", then the ElementRenderer
	 * must be removed from the rendering tree and destroyed
	 * 
	 * Another example is if the value of Display is "inline" and
	 * it is swiched to "block", then the current inline ElementRenderer
	 * must be replaced by a block ElementRenderer
	 * 
	 * TODO 2 : update doc, now also called for position style changes, should
	 * be for all positioning scheme styles
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
				var length:Int = _childNodes.length;
				for (i in 0...length)
				{
					//only text and element node can be attached, as other nodes
					//types are not visual
					switch (_childNodes[i].nodeType)
					{
						//attach element node
						case Node.ELEMENT_NODE:
							var child:HTMLElement = cast(_childNodes[i]);
							child.attach();
						
						//attach text node
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
				var length:Int = _childNodes.length;
				for (i in 0...length)
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
				
				_elementRenderer.dispose();
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
					var elementRenderParent:ElementRenderer = nextSibling.elementRenderer.parentNode;
					
					//in the case where the parent of the next sibling's elementRenderer is an 
					//anonymous block, the anonymous block should be return as sibling
					if (elementRenderParent.isAnonymousBlockBox() == true)
					{
						return elementRenderParent;
					}
					return nextSibling.elementRenderer;
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
	 * When this HTMLElement is detached, it detaches its
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
	 * TODO 3 : should use computed display style (although it computes
	 * the same as the specified value, will be a problem when adding inherit
	 * style value) and also take into account
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
	// CLICK SYNTHESIS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Simulates a mouse click on an element.
	 * 
	 * The screen and client coordinate of the 
	 * generated MouseEvent are 0 and modifier
	 * key (Shift, control...) correspond
	 * to the current modifier key state
	 * 
	 * TODO 2 : get current modifier key state
	 */
	public function click():Void
	{
		var mouseEvent:MouseEvent = new MouseEvent();
		mouseEvent.initMouseEvent(MouseEvent.CLICK, false, false, null, 0, 0, 0, 0, 0, false, false, false, false,
		0, null); 
		dispatchEvent(mouseEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENT DISPATCH HELPERS
	// helper methods to dispatch events on this HTMLElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * dispatch event of type Event
	 */
	private function fireEvent(eventTye:String, bubbles:Bool, cancelable:Bool):Void
	{
		var event:Event = new Event();
		event.initEvent(eventTye, bubbles, cancelable);
		dispatchEvent(event);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS METHODS
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
		var htmlDocument:HTMLDocument = cast(ownerDocument);
		htmlDocument.activeElement = this;
	}
	
	/**
	 * Removes keyboard focus from this HTMLElement and 
	 * the focus on the Document
	 */
	public function blur():Void
	{
		var htmlDocument:HTMLDocument = cast(ownerDocument);
		htmlDocument.body.focus();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FULLSCREEN METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Displays the element fullscreen
	 * 
	 * TODO 5 : the implementation is different from
	 * the spec, simpler. However the spec are only
	 * at early stage, will be updated once they
	 * are more widely implemented
	 */
	public function requestFullscreen():Void
	{
		var htmlDocument:HTMLDocument = cast(_ownerDocument);
		htmlDocument.fullscreenElement = this;
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
	
	/**
	 * Return the first ancestor HTMLElement which has an 
	 * activation behaviour. HTMLElement return itself if
	 * it has one
	 */
	public function getNearestActivatableElement():HTMLElement
	{
		var htmlElement:HTMLElement = this;
		while (htmlElement.hasActivationBehaviour() == false)
		{
			if (htmlElement.parentNode == null)
			{
				return null;
			}
			htmlElement = cast(htmlElement.parentNode);
		}
		
		return htmlElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SCROLLING SETTER/GETTER AND METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method determining wether
	 * the HTMLElement displays an active
	 * vertical scrolbar
	 * @param scrollOffset an optionnal parameter determining
	 * the scroll offset which tries to be applied to the vertical scrollbar.
	 * If applying the offset doesn't scroll the HTMLElement, for instance
	 * if the HTMLElement is completely scrolled and a positive offset
	 * is applied to it, then the method return false
	 * 
	 * @return true if a vertical scrollbar is displayed
	 * and isactive
	 */
	public function isVerticallyScrollable(scrollOffset:Int = 0):Bool
	{
		if (_elementRenderer != null)
		{
			return _elementRenderer.isVerticallyScrollable(scrollOffset);
		}
		return false;
	}
	
	/**
	 * same as absove for the horizontal scrollbar
	 */
	public function isHorizontallyScrollable(scrollOffset:Int = 0):Bool
	{
		if (_elementRenderer != null)
		{
			return _elementRenderer.isHorizontallyScrollable(scrollOffset);
		}
		return false;
	}
	
	//TODO 3 : should unit test, not very sure what this getter
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
	
	
	//TODO 4 : shouldn't HTMLElement be the model for all attributes
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
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_tabIndex(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	/**
	 * Return the tab index as an int
	 * @return
	 */
	private function get_tabIndex():Int
	{
		var tabIndex:String = super.getAttribute(HTMLConstants.HTML_TAB_INDEX_ATTRIBUTE_NAME);
		
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
	
	/**
	 * Retrieve the id value from the attributes
	 * map
	 * @return the id as a String or null
	 * if it was not set 
	 */
	private function get_id():String
	{
		return getAttribute(HTMLConstants.HTML_ID_ATTRIBUTE_NAME);
	}
	
	/**
	 * update the id value on the attributes map
	 */
	private function set_id(value:String):String
	{
		setAttribute(HTMLConstants.HTML_ID_ATTRIBUTE_NAME, value);
		return value;
	}
	
	/**
	 * Return the class name value from the attributes
	 * hash
	 */
	private function get_className():String
	{
		return getAttribute(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME);
	}
	
	/**
	 * set the class name value on the attributes
	 * hash
	 */
	private function set_className(value:String):String
	{
		setAttribute(HTMLConstants.HTML_CLASS_ATTRIBUTE_NAME, value);
		return value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove all the currently added child nodes,
	 * deserialise the passed HTML string and attach
	 * the resulting child nodes
	 * 
	 * @param	value an HTML String 
	 */
	private function set_innerHTML(value:String):String
	{
		var childLength:Int = _childNodes.length;
		for (i in 0...childLength)
		{
			removeChild(_childNodes[0]);	
		}
		
		//wrap the HTML String in a div element, else
		//when creating the html node, only the first 
		//node content is deserialized and not its
		//siblings
		var wrappedHTML:String = HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;
		wrappedHTML += value;
		wrappedHTML += HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_TOKEN_SOLIDUS + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;
		
		var node:HTMLElement = doSetInnerHTML(Parser.parse(wrappedHTML).firstElement());

		//the returned node might be null for instance, if 
		//only an empty string was provided
		if (node == null)
		{
			return value;
		}
		
		//append all children of the generated node
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			appendChild(node.childNodes[0]);
		}
		
		return value;
	}
	
	/**
	 * Actually desirialize the HTML string
	 * and return the root Node created
	 * 
	 * @param xml the HTML string, deserialized as an
	 * Haxe xml object
	 */
	private function doSetInnerHTML(xml : Xml):HTMLElement
	{
		switch( xml.nodeType ) {
		
		//node type for text node
		case Xml.PCData:
			return _ownerDocument.createTextNode(xml.nodeValue);
		
		//node type for comment node	
		case Xml.Comment:
			return _ownerDocument.createComment(xml.nodeValue);
		
		//node type for element node
		case Xml.Element:
			
			var htmlElement : HTMLElement;
			var name:String = xml.nodeName.toLowerCase();
	
			//create an HTMLElement with the name of the xml element
			//node
			htmlElement = _ownerDocument.createElement(name);
			
			//loop in all of the xml child node
			for (child in xml)
			{
				//switch the type of the child node
				switch (child.nodeType)
				{
					//if it is a text node,
					//check if the child is not just an
					//empty string, in which case, no text node
					//is created
					case Xml.PCData:
						if (child.nodeValue == "")
						{
							continue;
						}
				}
			
				//desrialize the child, thus deserializing
				//the whole DOM tree recursively
				var childNode:HTMLElement = doSetInnerHTML(child);

				htmlElement.appendChild(childNode);
			} 
			
			//set all the attributes of the xml node on the 
			//new HTMLElement node
			for( attribute in xml.attributes() ){
				attribute = attribute.toLowerCase();
				var value:String = xml.get(attribute);
				htmlElement.setAttribute(attribute, value);
			}
			
			return htmlElement;
		}
		
		//TODO 2 : will cause bug if node type not supported
		return null;
	}
	
	/**
	 * Serialise the descendant nodes of this HTMLElement
	 * and return the result as an HTML String
	 */
	private function get_innerHTML():String
	{
		var xml:Xml = doGetInnerHTML(this, Xml.createElement(nodeName));
		
		var str:String = xml.toString();
		
		//remove the first and last tag, as they correspond to this HTMLElement
		//tag which should not be returned as its inner html
		str = str.substr(str.indexOf(HTMLConstants.HTML_TOKEN_MORE_THAN) + 1 , str.lastIndexOf(HTMLConstants.HTML_TOKEN_LESS_THAN) - str.indexOf(HTMLConstants.HTML_TOKEN_MORE_THAN) - 1);
		
		return str;
	}
	
	/**
	 * Actually serialise all the chil nodes of this HTMLElement
	 * by traversing the DOM recursively.
	 * 
	 * Returns all the children serialised data as an Xml
	 * 
	 * TODO 5 : should serialize other type of nodes, such as
	 * doctype...
	 */
	private function doGetInnerHTML(node:HTMLElement, xml:Xml):Xml
	{
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			var child:HTMLElement = cast(node.childNodes[i]);
			
			switch(child.nodeType)
			{
				case Node.ELEMENT_NODE:
				
					//create an xml node with the tag name of the HTMLElement,
					//for instance 'div', 'span', 'img'...
					var childXml:Xml = Xml.createElement(child.nodeName);
					
					//set all the attributes of the child on its Xml node
					var childAttributes:NamedNodeMap = child.attributes;
					var childAttributesLength:Int = childAttributes.length;
					for (j in 0...childAttributesLength)
					{
						var attribute:Attr = cast(childAttributes.item(j));
						
						if (attribute.specified == true)
						{
							childXml.set(attribute.name, attribute.value);
						}
					}
					
					//concatenate all the of the specified styles of the HTMLElement
					//children into a CSS string
					var htmlChild:HTMLElement = child;
					var styleAttributes:NamedNodeMap = htmlChild.style.attributes;
					var concatenatedStyles:String = "";
					
					var attributesLength:Int = styleAttributes.length;
					for (j in 0...attributesLength)
					{
						var attribute:Attr = cast(styleAttributes.item(j));
						
						if (attribute.specified == true)
						{
							concatenatedStyles += attribute.name + ":" + attribute.value +";";
						}
					}
					
					//set the CSS string as the 'style' attribute of the HTMLElement
					//if at least one style one specified on it
					if (concatenatedStyles != "")
					{
						childXml.set(HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME, concatenatedStyles);
					}
					
					//add the children's content to the Xml of the child
					xml.addChild(doGetInnerHTML(child, childXml));
					
					//when the child xml doesn't have children itself, check if it
					//is a void element, as if it isn't, it must not be represented as 
					//a self-closing tag and so an empty string children is added to it
					//to be sure that the xml parser also returns a closing tag 
					if (childXml.firstChild() == null && isVoidElement() == false)
					{
						childXml.addChild(Xml.createPCData(""));
					}

				case Node.TEXT_NODE:
					//serialize a Text node
					var text:Xml = Xml.createPCData(child.nodeValue);
					xml.addChild(text);
					
				case Node.COMMENT_NODE:
					//serialize a Comment node
					var comment:Xml = Xml.createComment(child.nodeValue);
					xml.addChild(comment);
			}
		}
		
		return xml;
	}
	
	/**
	 * Utils method describing wether the HTMLElement
	 * is a void element, meaning it can't have any
	 * context and can be represented by a self-closing
	 * tag, like for instance the <img/> tag
	 */
	public function isVoidElement():Bool
	{
		return false;
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
		invalidate(InvalidationReason.needsImmediateLayout);
		var computedStyle:ComputedStyle = this._coreStyle.computedStyle;
		return Math.round(computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight);
	}
	
	private function get_offsetHeight():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		var computedStyle:ComputedStyle = this._coreStyle.computedStyle;
		return Math.round(computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom);
	}
	
	//TODO 3  : unit test
	private function get_offsetLeft():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return Math.round(_elementRenderer.positionedOrigin.x);
	}
	
	private function get_offsetTop():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return Math.round(_elementRenderer.positionedOrigin.y);
	}
	
	private function get_clientWidth():Int
	{
		//need to perform an immediate layout to be sure
		//that the computed styles are up to date
		invalidate(InvalidationReason.needsImmediateLayout);
		var computedStyle:ComputedStyle = this._coreStyle.computedStyle;
		return Math.round(computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight);
	}
	
	private function get_clientHeight():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		var computedStyle:ComputedStyle = this._coreStyle.computedStyle;
		return Math.round(computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom);
	}
	
	//TODO 5 : should be top border height
	private function get_clientTop():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
		return 0;
	}
	
	//TODO 5 : should be left border width
	private function get_clientLeft():Int
	{
		invalidate(InvalidationReason.needsImmediateLayout);
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