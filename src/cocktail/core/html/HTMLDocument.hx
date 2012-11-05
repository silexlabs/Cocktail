/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.css.CascadeManager;
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
import cocktail.core.hittest.HitTestManager;
import cocktail.core.html.HTMLAnchorElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLHtmlElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.invalidation.InvalidationManager;
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
import cocktail.core.timer.Timer;
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
	 * A timer controlling the whole document event loop.
	 * Method which must be called asynchronously register
	 * themselves with the timer
	 */
	public var timer(default, null):Timer;
	
	/**
	 * This class is in charge of keeping track of the
	 * current touch points and of creating cross-platform
	 * TouchEvent
	 */
	private var _multiTouchManager:MultiTouchManager;
	
	/**
	 * Used to perform hit test on the layer and
	 * rendering trees to determine for instance 
	 * which element renderer is currently under
	 * the mouse pointer
	 */
	private var _hitTestManager:HitTestManager;
	
	/**
	 * A ref to the global Window object
	 */
	public var window(default, null):Window;
	
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
	 * an instance of the class managing the invalidation
	 * and update of the document
	 */
	public var invalidationManager(default, null):InvalidationManager;
	
	/**
	 * For a given HTMLElement, store
	 * which CSS pseudo classes it currently matches
	 */
	private var _matchedPseudoClasses:MatchedPseudoClassesVO;
	
	/**
	 * An instance of the cascade manager. During the cascade,
	 * keep track of the styles which must be updated
	 * for each HTMLElement
	 */
	public var cascadeManager(default, null):CascadeManager;
		
   /**  	
	* getter/setter to set the whole document content with an  	
	* html string or to serialise the whole document into
	* an html string  	
   */ 	
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(window:Window = null) 
	{
		super();
		
		timer = new Timer();
		initStyleManager();
		invalidationManager = new InvalidationManager(this);
		
		cascadeManager = new CascadeManager();
		
		//TODO 2 : hack, Document probably shouldn't have
		//ref to Window
		if (window == null)
		{
			window = new Window();
		}
		
		_matchedPseudoClasses = new MatchedPseudoClassesVO(false, false, false,
		false, false, false, false);
		
		this.window = window;
		_focusManager = new FocusManager();
		
		_hitTestManager = new HitTestManager();
		
		_multiTouchManager = new MultiTouchManager();
		
		documentElement = createElement(HTMLConstants.HTML_HTML_TAG_NAME);
		
		initBody(cast(createElement(HTMLConstants.HTML_BODY_TAG_NAME)));
		
		_shouldDispatchClickOnNextMouseUp = false;
		
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
		if (htmlBodyElement != null)
		{	
			body = htmlBodyElement;
			documentElement.appendChild(body);
			_hoveredElementRenderer = body.elementRenderer;
			activeElement = body;
		}
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
				
			case HTMLConstants.HTML_BR_TAG_NAME:
				element = new HTMLBRElement();
				
			default:
				element = new HTMLElement(tagName);
		}
		
		element.ownerDocument = this;
		
		return element;
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
		documentElement.cascade(cascadeManager, false);
	}
	
	/**
	 * Remove a CSS style sheet from the document and cascade
	 * all of the DOM to refresh style definitions
	 */
	public function removeStyleSheet(stylesheet:CSSStyleSheet):Void
	{
		_styleManager.removeStyleSheet(stylesheet);
		documentElement.invalidateStyleDeclaration(true);
		documentElement.cascade(cascadeManager, false);
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
		
		_matchedPseudoClasses.hover = hover;
		_matchedPseudoClasses.focus = focus;
		_matchedPseudoClasses.active = active;
		_matchedPseudoClasses.link = link;
		_matchedPseudoClasses.enabled = enabled;
		_matchedPseudoClasses.disabled = disabled;
		_matchedPseudoClasses.checked = checked;
		
		return _matchedPseudoClasses;
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
		
		//if a start or move touch event default behaviour is canceled
		//it should prevent simulating a click event when the touch ends
		switch(touchEvent.type)
		{
			case EventConstants.TOUCH_START, EventConstants.TOUCH_MOVE:
				if (touchEvent.defaultPrevented == true)
				{
					_shouldDispatchClickOnNextMouseUp = false;
				}
		}
		
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
		return window.platform.nativeWindow.fullScreenEnabled();
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
		var elementRendererAtPoint:ElementRenderer = _hitTestManager.getTopMostElementRendererAtPoint(documentElement.elementRenderer.layerRenderer, x, y, 0, 0  );

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