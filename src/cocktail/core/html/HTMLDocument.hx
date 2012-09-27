/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.css.CSSRule;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.CSSStyleRule;
import cocktail.core.css.CSSStyleSheet;
import cocktail.core.css.DefaultCSSStyleSheet;
import cocktail.core.css.InitialStyleDeclaration;
import cocktail.core.css.StyleManager;
import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Element;
import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.TouchEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.focus.FocusManager;
import cocktail.core.html.HTMLAnchorElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLHtmlElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.formatter.BlockFormattingContext;
import cocktail.core.layout.formatter.InlineFormattingContext;
import cocktail.core.layout.LayoutManager;
import cocktail.core.multitouch.MultiTouchManager;
import cocktail.core.parser.DOMParser;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.event.EventData;
import cocktail.core.renderer.RendererData;
import cocktail.core.event.FocusEvent;
import cocktail.core.window.Window;
import cocktail.Lib;
import cocktail.core.graphics.GraphicsContext;
import haxe.Log;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import haxe.Stack;

/**
 * An HTMLDocument is the root of the HTML hierarchy and holds the entire content.
 * Besides providing access to the hierarchy, it also provides some convenience methods
 * for accessing certain sets of information from the document.
 * 
 * TODO 3 : should manage current click count
 * TODO 3 : should manage double click events
 * 
 * TODO 3 : class is too big with too many different
 * functionality
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLDocument extends Document
{
	/**
	 * key code listened to by the Document
	 */
	
	private static inline var TAB_KEY_CODE:Int = 9;
	
	private static inline var ENTER_KEY_CODE:Int = 13;
	
	private static inline var SPACE_KEY_CODE:Int = 32;
	
	/**
	 * A coefficient to apply to apply to the mouse
	 * wheel delta to get the right scroll amount, based
	 * on Windows implementation
	 */
	private static inline var MOUSE_WHEEL_DELTA_MULTIPLIER:Int = 10;
	
	/**
	 * The minimum amount of time between two layout and rendering. Can
	 * be used to set the framerate of the application. Dividing 1000
	 * by this value gives the framerate of the application
	 */
	private static inline var INVALIDATION_INTERVAL:Int = 20;
	
	/**
	 * The element that contains the content for the document.
	 * 
	 * The body is the root of the visual content in HTML
	 */
	public var body(default, null):HTMLBodyElement;
	
	/**
	 * The activeElement set/get the element
	 * in the document which is focused.
	 * If no element in the Document is focused, this returns the body element. 
	 */
	public var activeElement(get_activeElement, set_activeElement):HTMLElement;
	
	/**
	 * An instance of the FocusManager, managing the focus
	 * for this Document
	 */
	private var _focusManager:FocusManager;
	
	/**
	 * A reference to the ElementRenderer currently hovered by the
	 * mouse pointer. Used to detect when to dispatch mouse over
	 * and mouse out events 
	 */
	private var _hoveredElementRenderer:ElementRenderer;
	
	/**
	 * A reference to the currently mouse downed element, i.e
	 * the user clicked the primary button of its mouse over 
	 * this element and hasn't yet release the button.
	 * 
	 * If the mouse cursor moves over another element, this
	 * one still remains the moused element unitl the mouse
	 * button is released
	 */
	private var _mousedDownedElementRenderer:ElementRenderer;
	
	/**
	 * Returns true if document has the ability
	 * to display elements fullscreen, or false otherwise.
	 */
	public var fullscreenEnabled(get_fullscreenEnabled, never):Bool;
	
	/**
	 * Returns the element that is displayed fullscreen,
	 * or null if there is no such element.
	 */
	public var fullscreenElement(default, set_fullscreenElement):HTMLElement;
	
	/**
	 * getter/setter to set the whole document content with an 
	 * html string or to serialise the whole document into
	 * an html string
	 */
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
	/**
	 * Callback listened to by the Window object
	 * to enter fullscreen mode when needed using
	 * platform specific API
	 */
	public var onEnterFullscreen:Void->Void;
	
	/**
	 * Callback listened to by the Window object
	 * to exit fullscreen mode when needed using
	 * platform specific API
	 */
	public var onExitFullscreen:Void->Void;
	
	/**
	 * Callback listened to by the Window object
	 * to chnge the mouse cursor when needed using
	 * platform specific APIs
	 */
	public var onSetMouseCursor:CSSPropertyValue->Void;
	
	/**
	 * a flag determining if a click event must be dispatched
	 * on the hovered element on the next mouse up event.
	 * 
	 * A click event is dispatched if there was a mouse down
	 * event then a mouse up event dispatched on the same hovered
	 * element
	 */
	private var _shouldDispatchClickOnNextMouseUp:Bool;
	
	/**
	 * Wether a call to the invalidation method is already
	 * scheduled, only one call to this method
	 * method can be scheduled at a time to prevent too many
	 * re-layout and re-rendering
	 */
	private var _invalidationScheduled:Bool;
	
	/*
	 * Wheter the document needs a re-layout on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsLayout:Bool;
	
	/*
	 * Wheter the document needs a re-rendering on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsRendering:Bool;
	
	/**
	 * Wether the document needs to cascade the styles
	 * on nex invalidation method call
	 */
	private var _documentNeedsCascading:Bool;
	
	/**
	 * wether the rendering tree, in charge of layout
	 * and rendering should be updated after
	 * its structure changed
	 */
	private var _renderingTreeNeedsUpdate:Bool;
	
	/**
	 * wether the layer tree, in charge of the
	 * rendering of the rendering tree should
	 * be updated after its structure changed
	 */
	private var _layerTreeNeedsUpdate:Bool;
	
	/**
	 * Wether the stacking contexts, which represents
	 * the z-index for the layer of the document
	 * needs to be updated
	 */
	private var _stackingContextsNeedUpdate:Bool;
	
	/**
	 * Wether the native layer tree which is 
	 * a tree formed of native display list
	 * elements needs to be updated
	 */
	private var _nativeLayerTreeNeedsUpdate:Bool;
	
	/**
	 * Wheter the graphics context tree, used
	 * to paint the rendering tree should
	 * be updated after its structure changed
	 */
	private var _graphicsContextTreeNeedsUpdate:Bool;
	
	/**
	 * Wheter the whole graphics context tree should be
	 * updated. Happens when a compositing layer is
	 * attached/removed
	 */
	private var _forceGraphicsContextUpdate:Bool;
	
	/**
	 * This class is in charge of keeping track of the
	 * current touch points and of creating cross-platform
	 * TouchEvent
	 */
	private var _multiTouchManager:MultiTouchManager;
	
	/**
	 * A ref to the global Window object
	 */
	private var _window:Window;
	
	/**
	 * A ref to the style manager holding all the
	 * style sheet data of the document
	 */
	private var _styleManager:StyleManager;
	
	/**
	 * an instance of the initial style declaration. 
	 * This objects holds all the default values for each
	 * supported CSS styles.
	 * 
	 * When a CSS style has no specified value for a given
	 * HTML node, then its initial value from this object is used.
	 * 
	 * There is only one instance of it for the whole document, 
	 * as the initial style values are always the same for each
	 * node type. Every node use this object when cascading
	 */
	public var initialStyleDeclaration(default, null):InitialStyleDeclaration;
	
	/**
	 * an instance of the class managing layout.
	 * Holds instances of each class used during layout
	 */
	public var layoutManager(default, null):LayoutManager;
	
	/**
	 * the current mouse point, used when
	 * retrieving the ElementRenderer
	 * under mouse
	 */
	private var _mousePoint:PointVO;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(window:Window = null) 
	{
		super();
		
		initStyleManager();
		
		//TODO 2 : hack, Document probably shouldn't have
		//ref to Window
		if (window == null)
		{
			window = new Window();
		}
		
		_window = window;
		_focusManager = new FocusManager();
		
		_multiTouchManager = new MultiTouchManager();
		
		documentElement = createElement(HTMLConstants.HTML_HTML_TAG_NAME);
		
		initBody(cast(createElement(HTMLConstants.HTML_BODY_TAG_NAME)));
		
		_shouldDispatchClickOnNextMouseUp = false;
				
		_invalidationScheduled = false;
		_documentNeedsLayout = true;
		_documentNeedsRendering = true;
		_documentNeedsCascading = true;
		_graphicsContextTreeNeedsUpdate = true;
		_forceGraphicsContextUpdate = false;
		_renderingTreeNeedsUpdate = true;
		_layerTreeNeedsUpdate = true;
		_nativeLayerTreeNeedsUpdate = true;
		_stackingContextsNeedUpdate = true;
		
		_mousePoint = new PointVO(0.0, 0.0);
		
		layoutManager = new LayoutManager();
	}
	
	/**
	 * Init the body element of the document and the attributes
	 * depending on it. Set as public so that the body element
	 * can be reset if the inner HTML of the whole document
	 * changes
	 */
	public function initBody(htmlBodyElement:HTMLBodyElement):Void
	{
		body = htmlBodyElement;
		documentElement.appendChild(body);
		_hoveredElementRenderer = body.elementRenderer;
		activeElement = body;
	}
	
	/**
	 * Instantaite the style manager and add a default
	 * style sheet to it
	 */
	private function initStyleManager():Void
	{
		initialStyleDeclaration = new InitialStyleDeclaration();
		_styleManager = new StyleManager();
		_styleManager.addStyleSheet(new DefaultCSSStyleSheet());
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to instantiate specific HTML element if needed based
	 * on the tag name
	 */
	override public function createElement(tagName:String):HTMLElement
	{
		var element:HTMLElement;
		
		//tag names are always uppercase in HTML
		tagName = tagName.toUpperCase();
		
		switch (tagName)
		{
			case HTMLConstants.HTML_IMAGE_TAG_NAME:
				element = new HTMLImageElement();
				
			case HTMLConstants.HTML_INPUT_TAG_NAME:
				element = new HTMLInputElement();
				
			case HTMLConstants.HTML_ANCHOR_TAG_NAME:
				element = new HTMLAnchorElement();
				
			case HTMLConstants.HTML_HTML_TAG_NAME:
				element = new HTMLHtmlElement(); 
				
			case HTMLConstants.HTML_BODY_TAG_NAME:
				element = new HTMLBodyElement();
				
			case HTMLConstants.HTML_VIDEO_TAG_NAME:
				element = new HTMLVideoElement();
				
			case HTMLConstants.HTML_AUDIO_TAG_NAME:
				element = new HTMLAudioElement();
				
			case HTMLConstants.HTML_SOURCE_TAG_NAME:
				element = new HTMLSourceElement();
				
			case HTMLConstants.HTML_OBJECT_TAG_NAME:
				element = new HTMLObjectElement();
				
			case HTMLConstants.HTML_PARAM_TAG_NAME:
				element = new HTMLParamElement();
				
			case HTMLConstants.HTML_LINK_TAG_NAME:
				element = new HTMLLinkElement();
				
			case HTMLConstants.HTML_STYLE_TAG_NAME:
				element = new HTMLStyleElement();
				
			default:
				element = new HTMLElement(tagName);
		}
		
		element.ownerDocument = this;
		
		return element;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * parse the string representing the
	 * whole document. The returned node
	 * is the root of the html document
	 */
	private function set_innerHTML(value:String):String
	{
		//parse the html string into a node object
		var node:HTMLElement = DOMParser.parse(value, this);
		documentElement = node;
		initBody(cast(documentElement.getElementsByTagName(HTMLConstants.HTML_BODY_TAG_NAME)[0]));
		return value;
	}
	
	/**
	 * Return the serialized documentElement
	 * (the <HTML> element)
	 */
	private function get_innerHTML():String
	{
		return DOMParser.serialize(documentElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STYLE MANAGER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Add a CSS style sheet to the docuement, and cascade
	 * all the DOM as the new style sheet likely changes
	 * the styles value of some nodes
	 */
	public function addStyleSheet(stylesheet:CSSStyleSheet):Void
	{
		_styleManager.addStyleSheet(stylesheet);
		documentElement.invalidateStyleDeclaration(true);
		startCascade(false);
	}
	
	/**
	 * Remove a CSS style sheet from the document and cascade
	 * all of the DOM to refresh style definitions
	 */
	public function removeStyleSheet(stylesheet:CSSStyleSheet):Void
	{
		_styleManager.removeStyleSheet(stylesheet);
		documentElement.invalidateStyleDeclaration(true);
		startCascade(false);
	}
	
	/**
	 * For a given HTML node, retrive all the style declaration from
	 * the document's style sheets appying to it and return them as 
	 * a css declaration
	 */
	public function getStyleDeclaration(node:HTMLElement):CSSStyleDeclaration
	{
		return _styleManager.getStyleDeclaration(node, getMatchedPseudoClassesVO(node));
	}
	 
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STYLE MANAGER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a given node, return all of the
	 * pseudo classes that it currently matches
	 */
	private function getMatchedPseudoClassesVO(node:HTMLElement):MatchedPseudoClassesVO
	{
		var hover:Bool = false;
		var focus:Bool = false;
		var active:Bool = false;
		var link:Bool = false;
		var enabled:Bool = false;
		var disabled:Bool = false;
		var checked:Bool = false;
		
		//TODO 1 : shouldn't be null but his when setting style of HTML tag for the first time
		//check if node is the currently hovered node
		if (_hoveredElementRenderer != null)
		{
			hover = _hoveredElementRenderer.domNode == node;
		}
		//TODO 1 : shouldn't be null either
		//check if node is the currently focused element
		if (activeElement != null)
		{
			focus = activeElement == node;
		}
		
		//check if the node is the currently active (moused down) one
		if (_mousedDownedElementRenderer != null)
		{
			active = _mousedDownedElementRenderer.domNode == node;
		}
		
		//to match the :link pseudo class, the element must both be an anchor ("a") html element and also
		//have an "href" attribute
		if (node.tagName == HTMLConstants.HTML_ANCHOR_TAG_NAME && node.getAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME) != null)
		{
			link = true;
		}
		
		//enable/disable state only apply to form input element
		//
		//TODO 2 : check if it shouldn't apply to other elements
		if (node.tagName == HTMLConstants.HTML_INPUT_TAG_NAME)
		{
			//check if a disabled attribute is present on the node
			//to determine wether the form control is enabled or disabled
			if (node.getAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME) == null)
			{
				enabled = true;
				disabled = false;
			}
			else
			{
				disabled = true;
				enabled = false;
			}
			
			//check if the input element is checked
			//
			//might eventually need extra check, what if a text input has a checked attribute ?
			if (node.getAttribute(HTMLConstants.HTML_CHECKED_ATTRIBUTE_NAME) != null)
			{
				checked = true;
			}
		}
		
		return new MatchedPseudoClassesVO(hover, focus, active, link, enabled, disabled, checked);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PLATFORM CALLBACKS
	// Those callbacks are called in reaction to platform level event, such
	// as a resize of the window of the application
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dispatch the MouseEvent on the DOM node of the top most 
	 * ElementRenderer under the mouse pointer
	 * 
	 * @param	mouseEvent
	 */
	public function onPlatformMouseEvent(mouseEvent:MouseEvent):Void
	{
		//store the even type before dispatching it, as the event object is
		//reseted after dispatch
		var eventType:String = mouseEvent.type;
		
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent.screenX, mouseEvent.screenY);
		elementRendererAtPoint.domNode.dispatchEvent(mouseEvent);
	
		switch(eventType)
		{
			case EventConstants.MOUSE_DOWN:
				//reset the click sequence when a mouse down is dispatched
				_shouldDispatchClickOnNextMouseUp = true;
				
				//store the currently moused down element
				_mousedDownedElementRenderer = elementRendererAtPoint;
				//refresh its style, as now the :active pseudo-class applies to it
				elementRendererAtPoint.domNode.invalidateStyleDeclaration(false);
			
				
			case EventConstants.MOUSE_UP:
				//on mouse up, if nothing canceled the click sequence, dispatch
				//a click event after the mouse up event
				if (_shouldDispatchClickOnNextMouseUp == true)
				{
					dispatchClickEvent(mouseEvent);
				}
				
				//when the element is released, refresh
				//its styles, as the :active pseudo class
				//no longer applies
				if (_mousedDownedElementRenderer != null)
				{
					_mousedDownedElementRenderer = null;
					elementRendererAtPoint.domNode.invalidateStyleDeclaration(false);
				}
				
		}
	}
	
	/**
	 * When a mouse wheel event occurs first dispatch it, and
	 * if the default action wasn't prevented, vertically scroll
	 * the first vertically scrollable parent of the event target
	 */
	public function onPlatformMouseWheelEvent(wheelEvent:WheelEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(wheelEvent.screenX, wheelEvent.screenY);
		elementRendererAtPoint.domNode.dispatchEvent(wheelEvent);
		
		if (wheelEvent.defaultPrevented == false)
		{
			var htmlElement:HTMLElement = elementRendererAtPoint.domNode;
			
			//get the amount of vertical scrolling to apply in pixel
			var scrollOffset:Int = Math.round(wheelEvent.deltaY * MOUSE_WHEEL_DELTA_MULTIPLIER) ;
			
			//get the first ancestor which can be vertically scrolled
			var scrollableHTMLElement:HTMLElement = getFirstVerticallyScrollableHTMLElement(htmlElement, scrollOffset);
			if (scrollableHTMLElement != null)
			{
				scrollableHTMLElement.scrollTop -= scrollOffset;
			}
		
		}
	}
	
	/**
	 * MouseMove events are a special case of mouse event
	 * dispatching as they also must manager the hovered
	 * htmlElement
	 * 
	 * TODO 4 : implement all the mouse event such as mouseleave, and
	 * check if the implementation is in the right order
	 */
	public function onPlatformMouseMoveEvent(mouseEvent:MouseEvent):Void
	{
		//TODO 1 : hackish, mouse event shouldn't be 
		//listened to until docuement is ready
		if (documentElement.elementRenderer == null)
		{
			return;
		}
		if (_hoveredElementRenderer == null)
		{
			_hoveredElementRenderer = body.elementRenderer;
		}
		
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent.screenX, mouseEvent.screenY);
		
		if (_hoveredElementRenderer != elementRendererAtPoint)
		{
			//dispatch mouse out on the old hovered HTML element
			var mouseOutEvent:MouseEvent = new MouseEvent();
			mouseOutEvent.initMouseEvent(EventConstants.MOUSE_OUT, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
			mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey, mouseEvent.metaKey, mouseEvent.button, elementRendererAtPoint.domNode);
			
			_hoveredElementRenderer.domNode.dispatchEvent(mouseOutEvent);
			
			var oldHoveredElementRenderer:ElementRenderer = _hoveredElementRenderer;
			oldHoveredElementRenderer.domNode.invalidateStyleDeclaration(false);
			_hoveredElementRenderer = elementRendererAtPoint;
			
			//dispatch mouse over on the newly hovered HTML element
			var mouseOverEvent:MouseEvent = new MouseEvent();
			mouseOverEvent.initMouseEvent(EventConstants.MOUSE_OVER, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
			mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.shiftKey,  mouseEvent.altKey, mouseEvent.metaKey, mouseEvent.button, oldHoveredElementRenderer.domNode);
			
			elementRendererAtPoint.domNode.dispatchEvent(mouseOverEvent);
			
			//refresh the style of the newly hovered html element as a :hover
			//pseudo-class might apply to it
			elementRendererAtPoint.domNode.invalidateStyleDeclaration(false);
			
			//when the hovered element changes, if a mouse up event is dispatched
			//on the new hovered element, no click should be dispatched on it, as 
			//no mouse down was dispatched on it
			_shouldDispatchClickOnNextMouseUp = false;
			
			//update the mouse cursor with the cursor style of the newly hovered 
			//element
			setMouseCursor(elementRendererAtPoint.domNode.coreStyle.cursor);
		}
		
		elementRendererAtPoint.domNode.dispatchEvent(mouseEvent);
	}
	
	
	/**
	 * When a key is pressed, dispatch the keyboardEvent
	 * on the active element and detect if a tab
	 * focus or a simulated click must happen.
	 */
	public function onPlatformKeyDownEvent(keyboardEvent:KeyboardEvent):Void
	{
		activeElement.dispatchEvent(keyboardEvent);

		//TODO 4 : should this logic go into HTMLElement ? or is it application/embedder level ? 
		switch (Std.parseInt(keyboardEvent.keyChar))
		{
			case TAB_KEY_CODE:
				//only do sequantial navigation if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement = _focusManager.getNextFocusedElement(keyboardEvent.shiftKey == true, body, activeElement);
				}
	
			case ENTER_KEY_CODE, SPACE_KEY_CODE:
				//only simulate click if default was not prevented
				//TODO 3 : should run activation behaviour steps ?
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement.click();
				}
		}
	}
	
	/**
	 * When a key up event happens, dispatches it
	 * on the activeElement
	 */
	public function onPlatformKeyUpEvent(keyboardEvent:KeyboardEvent):Void
	{
		activeElement.dispatchEvent(keyboardEvent);
	}
	
	/**
	 * When the Window is resized, invalidate
	 * the body, redraw.
	 */
	public function onPlatformResizeEvent(event:UIEvent):Void
	{
		documentElement.invalidate(InvalidationReason.windowResize);
	}
	
	/**
	 * When a native touch event occurs, the state of the current
	 * active touch must be updated, then a new 
	 * 
	 * TODO 2 : should add default scrolling behaviour for touch
	 */
	public function onPlatformTouchEvent(touchEvent:TouchEvent):Void
	{	
		//at this point the TouchEvent contain only the one
		//Touch which triggered the event
		var touch:Touch = touchEvent.touches.item(0);
		var elementAtTouchPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(touch.screenX, touch.screenY);
		
		//send the event to the multitouch manager so that it can set up
		//all of its properties properly
		_multiTouchManager.setUpTouchEvent(touchEvent, elementAtTouchPoint.domNode);
		
		//dispatch the TouchEvent on the node onto which it was triggered
		elementAtTouchPoint.domNode.dispatchEvent(touchEvent);
		
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CLICK METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * dispatch a click event on the currently hovered element if a mouse down and mouse up
	 * was called on it without the mouse hovering another element in between
	 * 
	 * Mouse click event are a special case of
	 * mouse event dispatching, as they may trigger
	 * activation behaviour, such as following a 
	 * link for an HTMLAnchorElement
	 * 
	 * @param mouseEvent, the mouse up event which triggered the click
	 */
	private function dispatchClickEvent(mouseEvent:MouseEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent.screenX, mouseEvent.screenY);
		
		var htmlElement:HTMLElement = elementRendererAtPoint.domNode;
		
		//find the first parent of the HTMLElement which has an activation behaviour, might
		//return null
		var nearestActivatableElement:HTMLElement = htmlElement.getNearestActivatableElement();

		//execute pre activation
		if (nearestActivatableElement != null)
		{
			nearestActivatableElement.runPreClickActivation();
		}
		
		//create a mouse click event from the mouse up event
		var clickEvent:MouseEvent = new MouseEvent();
		clickEvent.initMouseEvent(EventConstants.CLICK, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY,
		mouseEvent.clientX, mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey,
		mouseEvent.metaKey, mouseEvent.button, null);
		
		htmlElement.dispatchEvent(clickEvent);
		
		//execute post or canceled activation behaviour
		if (nearestActivatableElement != null)
		{
			if (clickEvent.defaultPrevented == true)
			{
				nearestActivatableElement.runCanceledActivationStep();
			}
			else
			{
				nearestActivatableElement.runPostClickActivationStep(clickEvent);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Change the current mouse cursor, using platform
	 * specific APIs
	 */
	private function setMouseCursor(cursor:CSSPropertyValue):Void
	{
		if (onSetMouseCursor != null)
		{
			onSetMouseCursor(cursor);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FULLSCREEN METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Stops any elements within document
	 * from being displayed fullscreen.
	 * 
	 * TODO 5 : implementation doesn't respect
	 * w3c spec, but spec still in early stages
	 */
	public function exitFullscreen():Void
	{
		//do nothing if no element is on fullscreen
		//currently
		if (fullscreenElement == null)
		{
			return;
		}
		
		fullscreenElement = null;
		
		//call the callback, so that the Window
		//object can exit fullscreen using platform
		//specific API
		if (onExitFullscreen != null)
		{
			onExitFullscreen();
		}
		
		//fire a fullscreen event
		var fullscreenEvent:Event = new Event();
		fullscreenEvent.initEvent(EventConstants.FULL_SCREEN_CHANGE, true, false);
	}
	
	/**
	 * Return wether fullscreen mode is allowed
	 */
	private function get_fullscreenEnabled():Bool
	{
		return _window.platform.nativeWindow.fullScreenEnabled();
	}
	
	/**
	 * start fullscreen mode
	 * 
	 * TODO 5 : implementation doesn't respect
	 * w3c spec, but spec still in early stages
	 */
	private function set_fullscreenElement(value:HTMLElement):HTMLElement
	{
		//do nothing if element is null. Might also
		//be called when exiting fullscreen to set 
		//fullsrcreen element to null
		if (value == null)
		{
			fullscreenElement = null;
			return value;
		}
		
		//do nothing if already in fullscreen mode
		if (fullscreenElement != null)
		{
			return fullscreenElement;
		}
		
		fullscreenElement = value;
		
		//call enter fullscreen callbakc, so that
		//Window can enter fullscreen using platform
		//specific API
		if (onEnterFullscreen != null)
		{
			onEnterFullscreen();
		}
		
		//fire fullscreen event
		var fullscreenEvent:Event = new Event();
		fullscreenEvent.initEvent(EventConstants.FULL_SCREEN_CHANGE, true, false);
		
		return value;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * schedule a layout of the document, or 
	 * layout it immediately if needed
	 * @param immediate wether the layout should be
	 * synchronous
	 */
	public function invalidateLayout(immediate:Bool):Void
	{
		_documentNeedsLayout = true;
		if (immediate == false)
		{
			invalidate();
		}
		else
		{
			cascadeLayoutAndRender();
		}
	}
	
	/**
	 * schedule a rendering of the document
	 */
	public function invalidateRendering():Void
	{
		_documentNeedsRendering = true;
		invalidate();
	}
	
	/**
	 * Schedule an update of the rendering tree
	 */
	public function invalidateRenderingTree():Void
	{
		_renderingTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the layer tree
	 */
	public function invalidateLayerTree():Void
	{
		_layerTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the stacking context
	 */
	public function invalidateStackingContexts():Void
	{
		_stackingContextsNeedUpdate = true;
		invalidate();
	}
	
	/**
	 * schedule an update of the native layer tree
	 */
	public function invalidateNativeLayerTree():Void
	{
		_nativeLayerTreeNeedsUpdate = true;
		invalidate();
	}
	
	/**
	 * Shedule an update of the graphics
	 * context tree
	 */
	public function invalidateGraphicsContextTree(force:Bool):Void
	{
		_graphicsContextTreeNeedsUpdate = true;
		if (force == true)
		{
			_forceGraphicsContextUpdate = true;
		}
		invalidate();
	}
	
	/**
	 * schedule a cascade of the document
	 */
	public function invalidateCascade():Void
	{
		_documentNeedsCascading = true;
		invalidate();
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * schedule an invalidation
	 */
	private function invalidate():Void
	{
		if (_invalidationScheduled == false)
		{
			doInvalidate();
		}
	}
	
	/**
	 * Actually schedule an invalidation if one
	 * is not yet scheduled
	 */
	private function doInvalidate():Void
	{
		_invalidationScheduled = true;
		scheduleCascadeLayoutAndRender();
	}
	
	/**
	 * cascade, layout and render the document
	 * as needed
	 */
	private function cascadeLayoutAndRender():Void
	{
		//only cascade if needed
		if (_documentNeedsCascading == true)
		{
			startCascade(true);
		}
		
		//update the rendering tree before layout and
		//rendering if needed
		if (_renderingTreeNeedsUpdate == true)
		{
			documentElement.updateElementRenderer();
			documentElement.elementRenderer.updateAnonymousBlock();
			_renderingTreeNeedsUpdate = false;
		}
		
		//update the layer tree before rendergin if
		//needed
		if (_layerTreeNeedsUpdate == true)
		{
			documentElement.elementRenderer.updateLayerRenderer();
			_layerTreeNeedsUpdate = false;
		}
		
		//update the layers stacking contexts
		if (_stackingContextsNeedUpdate == true)
		{
			documentElement.elementRenderer.layerRenderer.updateStackingContext();
			_stackingContextsNeedUpdate = false;
		}
		
		//only layout if the invalidate layout
		//method was called
		if (_documentNeedsLayout == true)
		{
			startLayout(false);
			
			//start all pending animations
			var atLeastOneAnimationStarted:Bool = startPendingAnimation();
			
			//if at least one pending animation started, an immediate layout
			//must be performed before rendering, else the rendering will be
			//done with the end value of the animations instead of the beggining
			//value, resulting in a visual glitch
			if (atLeastOneAnimationStarted == true)
			{
				startLayout(true);
			}
		}
		
		//update the graphics context tree if needed,
		//before painting onto it
		if (_graphicsContextTreeNeedsUpdate == true)
		{
			documentElement.elementRenderer.layerRenderer.updateGraphicsContext(_forceGraphicsContextUpdate);
			_graphicsContextTreeNeedsUpdate = false;
			_forceGraphicsContextUpdate = false;
		}
		
		//update the tree of native layer if needed
		if (_nativeLayerTreeNeedsUpdate == true)
		{
			documentElement.elementRenderer.layerRenderer.graphicsContext.updateNativeLayer();
			_nativeLayerTreeNeedsUpdate = false;
		}
		
		//same as for layout
		if (_documentNeedsRendering == true)
		{
			startRendering();
			_documentNeedsRendering = false;
		}
		
		//when the document has been entirely updated
		//end the pending animation
		if (_documentNeedsLayout == true)
		{
			endPendingAnimation();
			_documentNeedsLayout = false;
		}
	}
	
	/**
	 * Callback called after an invalidation is
	 * scheduled, starts the layout and rendering
	 */
	private function onLayoutSchedule():Void
	{
		_invalidationScheduled = false;
		cascadeLayoutAndRender();
	}
	
	/**
	 * Start rendering the rendering
	 * tree, starting with the root LayerRenderer
	 */ 
	private function startRendering():Void
	{
		documentElement.elementRenderer.layerRenderer.render(_window.innerWidth, _window.innerHeight);
	}
	
	/**
	 * Start all the pending animation by calling
	 * the start animation method on all elements of the
	 * rendering tree
	 */
	private function startPendingAnimation():Bool
	{
		return documentElement.startPendingAnimation();
	}
	
	/**
	 * Make all animations which just ended dispose
	 * of themselves and dispatch a complete event.
	 * The event must be dispatched once the layout 
	 * and rendering are done to prevent the user
	 * from modififying the DOM with not updated
	 * info
	 */
	private function endPendingAnimation():Void
	{
		documentElement.endPendingAnimation();
	}
	
	/**
	 * Star cascading the whole document
	 * 
	 * @param programmaticChange whether the cascading
	 * is the result of a programmatic change to the DOM/CSS.
	 * It is used to determine wether animation/transition
	 * can be started during the cascade 
	 */
	private function startCascade(programmaticChange:Bool):Void
	{
		documentElement.cascade(new Hash<Void>(), programmaticChange);
		_documentNeedsCascading = false;
	}
	
	
	/**
	 * Start the layout of the rendering tree,
	 * starting with the root ElementRenderer
	 */
	private function startLayout(forceLayout:Bool):Void
	{
		//layout all ElementRenderer, after this, ElementRenderer are 
		//aware of their bounds relative to their containing block
		documentElement.elementRenderer.layout(forceLayout);
		
		//set the global bounds on the rendering tree. After this, ElementRenderer
		//are aware of their bounds relative ot the viewport
		documentElement.elementRenderer.setGlobalOrigins(0, 0, 0, 0, 0 ,0);
	}
	
	/**
	 * Set a timer to trigger a layout and rendering of the document asynchronously.
	 * Setting a timer to execute the layout and rendering ensure that it only
	 * happen once when a series of style values are set or when many elements
	 * are attached/removed from the DOM, instead of happening for every change.
	 */
	private function scheduleCascadeLayoutAndRender():Void
	{
		var onLayoutScheduleDelegate:Void->Void = onLayoutSchedule;
		#if macro
		#elseif (flash9 || nme)
		//calling the methods 1 millisecond later is enough to ensure
		//that first all synchronous code is executed
		haxe.Timer.delay(function () { 
			onLayoutScheduleDelegate();
		}, INVALIDATION_INTERVAL);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method returning the first ElementRenderer whose dom node
	 * is an Element node. This is used when dispatching MouseEvent, as their target
	 * can only be Element node.
	 * 
	 * TODO 1 : should never return initial container block, should return body instead
	 */
	private function getFirstElementRendererWhichCanDispatchMouseEvent(x:Int, y:Int):ElementRenderer
	{
		_mousePoint.x = x;
		_mousePoint.y = y;
		var elementRendererAtPoint:ElementRenderer = documentElement.elementRenderer.layerRenderer.getTopMostElementRendererAtPoint( _mousePoint, 0, 0  );
		
		//when no element is under mouse like for instance when the mouse leaves
		//the window, return the body
		if (elementRendererAtPoint == null)
		{
			return body.elementRenderer;
		}
		
		while (elementRendererAtPoint.domNode.nodeType != DOMConstants.ELEMENT_NODE || elementRendererAtPoint.isAnonymousBlockBox() == true)
		{
			elementRendererAtPoint = elementRendererAtPoint.parentNode;
			if (elementRendererAtPoint == null)
			{
				return null;
			}
		}
		
		return elementRendererAtPoint;
	}
	
	/**
	 * Utils method returning the first HTMLElement parent which
	 * can be vertically scrolled. The provided htmlElement is returned
	 * if it can be vertically scrolled
	 * 
	 * The scrollOffset is also provided as if a vertically scrollable element
	 * is completely scrolled and adding this offset won't make a difference,
	 * then it is not considered scrollable
	 */
	private function getFirstVerticallyScrollableHTMLElement(htmlElement:HTMLElement, scrollOffset:Int):HTMLElement
	{
		while (htmlElement.isVerticallyScrollable(scrollOffset) == false)
		{
			htmlElement = htmlElement.parentNode;
			if ( htmlElement == null)
			{
				return null;
			}
		}
		
		return htmlElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the activeElement on the focusManager
	 */
	private function set_activeElement(newActiveElement:HTMLElement):HTMLElement
	{	
		_focusManager.setActiveElement(newActiveElement, body);
		return activeElement;
	}
	
	/**
	 * get the active element from the focus manager,
	 */
	private function get_activeElement():HTMLElement
	{
		return _focusManager.activeElement;
	}
}