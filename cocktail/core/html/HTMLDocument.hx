/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.animation.TransitionManager;
import cocktail.core.config.Config;
import cocktail.core.css.CascadeManager;
import cocktail.core.css.CSSRule;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.CSSStyleRule;
import cocktail.core.css.CSSStyleSheet;
import cocktail.core.css.DefaultCSSStyleSheet;
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
import cocktail.core.font.FontManager;
import cocktail.core.hittest.HitTestManager;
import cocktail.core.html.HTMLAnchorElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLHtmlElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.invalidation.InvalidationManager;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.LayoutManager;
import cocktail.core.location.Location;
import cocktail.core.multitouch.MultiTouchManager;
import cocktail.core.parser.DOMParser;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.event.EventData;
import cocktail.core.parser.ParserData;
import cocktail.core.event.FocusEvent;
import cocktail.core.resource.ResourceManager;
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
	 * and mouse out events.
	 * 
	 * Might be null if the mouse is not currently hovering the document
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
	 * element.
	 * 
	 * Additionaly, if touch event are also dispatched, if
	 * the touch moves too much between the mouse down / touch down
	 * and mouse up / touch up event, then no click is dispatched
	 * as it is assumed that the user is probably scrolling instead
	 */
	private var _shouldDispatchClickOnNextMouseUp:Bool;
	
	/**
	 * When a touch start event is dispatched, store its
	 * position so that the total touch offset can be processed
	 * when subsequent touch move and touch end events are dispatched
	 */
	private var _lastTouchStartPosition:PointVO;
	
	/**
	 * Initialy false, set to true once the document
	 * is fully loaded, meaning that all embedded element, such
	 * as pictures are also fully loaded
	 */
	private var _documentLoaded:Bool;
	
	/**
	 * Each time an element delay dispatching
	 * the load event of the document, it increments
	 * this counter and decrements it once it no 
	 * longer needs to delay the load event
	 */
	private var _delayLoadEventCounter:Int;
	
	/**
	 * A timer controlling the whole document event loop.
	 * Method which must be called asynchronously register
	 * themselves with the timer
	 */
	public var timer(default, null):Timer;
	
	/**
	 * an instance of the class managing the font 
	 * of the document
	 */
	public var fontManager(default, null):FontManager;
	
	/**
	 * an instance of the class managing the 
	 * transitions of the document
	 */
	public var transitionManager(default, null):TransitionManager;
	
	/**
	 * An instance of the class managing loading and storing 
	 * the document's assets
	 */
	public var resourceManager(default, null):ResourceManager;
	
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
	public var window:Window;
	
	/**
	 * A ref to the style manager holding all the
	 * style sheet data of the document
	 */
	private var _styleManager:StyleManager;
	
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
	 * holds the location of this document
	 */
	public var location(default, null):Location;
	
   /**  	
	* getter/setter to set the whole document content with an  	
	* html string or to serialise the whole document into
	* an html string  	
   */ 	
	public var innerHTML(get_innerHTML, set_innerHTML):String;
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super();
		init();	
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		timer.dispose();
		timer = null;
		fontManager.dispose();
		fontManager = null;
		resourceManager.dispose();
		resourceManager = null;
		transitionManager.dispose();
		transitionManager = null;
		invalidationManager.dispose();
		invalidationManager = null;
		cascadeManager.dispose();
		cascadeManager = null;
		_matchedPseudoClasses = null;
		_focusManager.dispose();
		_focusManager = null;
		_hitTestManager.dispose();
		_hitTestManager = null;
		_multiTouchManager.dispose();
		_multiTouchManager = null;
		_lastTouchStartPosition = null;
		layoutManager.dispose();
		layoutManager = null;
		location.dispose();
		location = null;
		
		if (documentElement != null)
		{
			documentElement.dispose();
			documentElement = null;
			body = null;
		}
	}
	
	/**
	 * global document init
	 */
	private function init():Void
	{
		timer = new Timer();
		
		fontManager = new FontManager();
		resourceManager = new ResourceManager(this);
		transitionManager = new TransitionManager(this);
		
		location = new Location(this);
		location.onLocationChanged = onLocationChanged;
		
		initStyleManager();
		invalidationManager = new InvalidationManager(this);
		
		cascadeManager = new CascadeManager();
		
		_matchedPseudoClasses = new MatchedPseudoClassesVO(false, false, false,
		false, false, false, false, false, false, null, null, null);
		
		_focusManager = new FocusManager();
		
		_hitTestManager = new HitTestManager();
		
		_multiTouchManager = new MultiTouchManager();
		
		
		_shouldDispatchClickOnNextMouseUp = false;
		_lastTouchStartPosition = new PointVO(0, 0);
		
		layoutManager = new LayoutManager();
		
		_delayLoadEventCounter = 0;
		_documentLoaded = false;
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
			activeElement = body;
		}
	}

	/**
	 * Instantaite the style manager and add a default
	 * style sheet to it
	 */
	private function initStyleManager():Void
	{
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
				
			case HTMLConstants.HTML_META_TAG_NAME:
				element = new HTMLMetaElement();
				
			case HTMLConstants.HTML_FORM_TAG_NAME:
				element = new HTMLFormElement();
				
			case HTMLConstants.HTML_TEXT_AREA_TAG_NAME:
				element = new HTMLTextAreaElement();
				
			default:
				element = new HTMLElement(tagName);
		}
		
		element.ownerDocument = this;
		
		return element;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * before the document is fully loaded, 
	 * elements which delay its load, such as
	 * an img element with a src, delay dispatching
	 * the load event of the document until they
	 * finished their loading task
	 */
	public function delayLoadEvent():Void
	{
		_delayLoadEventCounter++;
	}
	
	/**
	 * called by an element delaying the load event
	 * of the document once it doesn't need to delay it
	 * anymore, for instance for an img when its picture
	 * has been loaded or there was an error loading it
	 */
	public function undelayLoadEvent():Void
	{	
		_delayLoadEventCounter--;
		
		if (_delayLoadEventCounter == 0 && _documentLoaded == false)
		{
			onDocumentLoaded();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INIT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the document and all embedded
	 * element, such as pictures, CSS stylesheet...
	 * are loaded.
	 * 
	 * Dispatch a load event on the window
	 */
	private function onDocumentLoaded():Void
	{
		_documentLoaded = true;
		
		var event:UIEvent = new UIEvent();
		event.initUIEvent(EventConstants.LOAD, false, false, null, 0);
		window.dispatchEvent(event);
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
		
		if (_hoveredElementRenderer != null)
		{
			hover = _hoveredElementRenderer.domNode == node;
		}
		//TODO 1 : shouldn't be null
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
			var inputNode:HTMLInputElement = cast(node);
			
			//check if a disabled attribute is present on the node
			//to determine wether the form control is enabled or disabled
			if (inputNode.disabled == false)
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
			if (inputNode.type == HTMLConstants.INPUT_TYPE_CHECKBOX || inputNode.type == HTMLConstants.INPUT_TYPE_RADIO)
			{
				if (inputNode.checked == true)
				{
					checked = true;
				}
			}
		}
		
		//store wether the store has an ID to know if it is
		//useful to match it against classes selector
		_matchedPseudoClasses.hasClasses = node.className != "";
		
		//store node classes
		if (_matchedPseudoClasses.hasClasses == true)
		{
			_matchedPseudoClasses.nodeClassList = node.classList;
		}
		
		//store wether the node has an ID to know
		//if it is useful to match it against ID selectors
		_matchedPseudoClasses.hasId = node.id != "";
		
		//store node id
		if (_matchedPseudoClasses.hasId == true)
		{
			_matchedPseudoClasses.nodeId = node.id;
		}
		
		//store the node type of the node
		_matchedPseudoClasses.nodeType = node.tagName;
		
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
		
		//hovered element must also be refreshed when there is a mouse click
		refreshHoveredElement(elementRendererAtPoint, mouseEvent);
		
		if (elementRendererAtPoint == null)
		{
			return;
		}
		
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
					_mousedDownedElementRenderer.domNode.invalidateStyleDeclaration(false);
					_mousedDownedElementRenderer = null;
				}
				
		}
	}
	
	/**
	 * Called when the mouse leaves the window of the document.
	 * Dispatch mouse out event on previously hovered component
	 * 
	 * TODO 3 : for now mouse out event doesn't use position of
	 * the mouse just before it left the window, store previous 
	 * mouse move event ? In platform specific code, store
	 * last mouse move event and dispatch one with the same 
	 * data with mouse leave type ?
	 */
	public function onPlatformMouseLeaveEvent(event:Event):Void
	{
		if (_hoveredElementRenderer != null)
		{
			var oldHoveredElementRenderer:ElementRenderer = _hoveredElementRenderer;
			//dispatch mouse out on the old hovered HTML element
			var mouseOutEvent:MouseEvent = new MouseEvent();
			mouseOutEvent.initMouseEvent(EventConstants.MOUSE_OUT, true, true, null, 0, 0, 0, 0,
			0, false, false,false, false, 0, null);
			
			_hoveredElementRenderer.domNode.dispatchEvent(mouseOutEvent);
			oldHoveredElementRenderer.domNode.invalidateStyleDeclaration(false);
			_hoveredElementRenderer = null;
			
			//when mouse leave, reset mouse cursor to let OS manage it
			setMouseCursor(CSSPropertyValue.KEYWORD(AUTO));
		}
	}
	
	/**
	 * When a mouse wheel event occurs first dispatch it 
	 * 
	 * TODO 2 : once scrollbar properly implemented, implement default scrolling
	 */
	public function onPlatformMouseWheelEvent(wheelEvent:WheelEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(wheelEvent.screenX, wheelEvent.screenY);
		elementRendererAtPoint.domNode.dispatchEvent(wheelEvent);
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
		
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent.screenX, mouseEvent.screenY);
		
		//update hovered element after mouse move
		refreshHoveredElement(elementRendererAtPoint, mouseEvent);

		if (elementRendererAtPoint != null)
		{
			elementRendererAtPoint.domNode.dispatchEvent(mouseEvent);
		}
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
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement.triggerActivationBehaviour();
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
		
		//check if simulating a click event when the touch ends should
		//be prevented
		if (_shouldDispatchClickOnNextMouseUp == true)
		{
			switch(touchEvent.type)
			{	
				case EventConstants.TOUCH_START:
					//if default prevented, prevent click
					if (touchEvent.defaultPrevented == true)
					{
						_shouldDispatchClickOnNextMouseUp = false;
					}
					//else if multi touch, prevent click
					else if (touchEvent.touches.length > 1)
					{
						
					}
					//else store touch start position, if touch
					//then moves too much, click prevented
					else
					{
						_lastTouchStartPosition.x = touchEvent.touches.item(0).screenX;
						_lastTouchStartPosition.y = touchEvent.touches.item(0).screenY;
					}
					
				case EventConstants.TOUCH_MOVE:
					//if default prevented, prevent click
					if (touchEvent.defaultPrevented == true)
					{
						_shouldDispatchClickOnNextMouseUp = false;
					}
					//else check the offset of the current touch position
					//from the place where it started, and if the distance
					//is too great, prevent click dispatch
					else
					{
						var yOffset:Float = touchEvent.touches.item(0).screenY - _lastTouchStartPosition.y;
						if (Math.abs(yOffset) > Config.getInstance().touchMovePreventClickDistance)
						{
							_shouldDispatchClickOnNextMouseUp = false;
						}
						else
						{
							var xOffset:Float = touchEvent.touches.item(0).screenX - _lastTouchStartPosition.x;
							if (Math.abs(xOffset) > Config.getInstance().touchMovePreventClickDistance)
							{
								_shouldDispatchClickOnNextMouseUp = false;
							}
						}
					}
			}
		}
	}
	
	/**
	 * When the viewport is resized, invalidate
	 * the html document so that its layout
	 * and rendering gets updated.
	 */
	public function onPlatformResizeEvent(e:UIEvent):Void
	{
		invalidationManager.invalidateViewportSize();
	}
	
	/**
	 * When the viewport orientation is changed, invalidate
	 * the html document so that its layout
	 * and rendering gets updated
	 */
	public function onPlatformOrientationChangeEvent(e:Event):Void
	{
		invalidationManager.invalidateViewportSize();
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
		
		//create a mouse click event from the mouse up event
		var clickEvent:MouseEvent = new MouseEvent();
		clickEvent.initMouseEvent(EventConstants.CLICK, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY,
		mouseEvent.clientX, mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey,
		mouseEvent.metaKey, mouseEvent.button, null);
		
		htmlElement.triggerActivationBehaviour(clickEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE METHODS
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
	
	/**
	 * Refresh the currently hovered element after a mouse event
	 */
	private function refreshHoveredElement(elementRendererAtPoint:ElementRenderer, mouseEvent:MouseEvent):Void
	{
		if (elementRendererAtPoint == null)
		{
			return;
		}
		
		if (_hoveredElementRenderer != elementRendererAtPoint)
		{
			var oldHoveredElementRenderer:ElementRenderer = _hoveredElementRenderer;
			//might be null if mouse pointer left the window
			if (_hoveredElementRenderer != null)
			{
				//dispatch mouse out on the old hovered HTML element
				var mouseOutEvent:MouseEvent = new MouseEvent();
				mouseOutEvent.initMouseEvent(EventConstants.MOUSE_OUT, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
				mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey, mouseEvent.metaKey, mouseEvent.button, elementRendererAtPoint.domNode);
				
				_hoveredElementRenderer.domNode.dispatchEvent(mouseOutEvent);
			
				oldHoveredElementRenderer.domNode.invalidateStyleDeclaration(false);
			}
			
			_hoveredElementRenderer = elementRendererAtPoint;
			
			//send html elment which was just moused out
			var relatedTarget:HTMLElement = null;
			if (_hoveredElementRenderer != null)
			{
				relatedTarget = _hoveredElementRenderer.domNode;
			}
			
			//dispatch mouse over on the newly hovered HTML element
			var mouseOverEvent:MouseEvent = new MouseEvent();
			mouseOverEvent.initMouseEvent(EventConstants.MOUSE_OVER, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
			mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.shiftKey,  mouseEvent.altKey, mouseEvent.metaKey, mouseEvent.button, relatedTarget);
			
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
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// LOCATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * called when the location's href is set
	 */
	private function onLocationChanged():Void
	{
		//TODO : update document
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
		return window.platform.fullScreenEnabled();
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
	 */
	private function getFirstElementRendererWhichCanDispatchMouseEvent(x:Int, y:Int):ElementRenderer
	{
		var elementRendererAtPoint:ElementRenderer = _hitTestManager.getTopMostElementRendererAtPoint(documentElement.elementRenderer.layerRenderer.stackingContext, x, y);

		//might be null, for instance when mouse leaves the
		//window
		if (elementRendererAtPoint == null)
		{
			return null;
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
	 * 
	 * TODO 1 : should use htmlElement.scrollHeight - (htmlElement.scrollTop + scrollOffset)
	 * + check wether a vertical scrollbar is displayed with layer
	 */
	private function getFirstVerticallyScrollableHTMLElement(htmlElement:HTMLElement, scrollOffset:Int):HTMLElement
	{
		//while (htmlElement.isVerticallyScrollable(scrollOffset) == false)
		//{
			//htmlElement = htmlElement.parentNode;
			//if ( htmlElement == null)
			//{
				//return null;
			//}
		//}
		
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