/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.api;

import cocktail.event.EventConstants;
import cocktail.event.KeyboardEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.http.HTTPConstants;
import cocktail.timer.Timer;
import cocktail.core.window.Window;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;
import cocktail.core.http.HTTPData;
import haxe.Http;
import haxe.Resource;

/**
 * represents the position and size of the document
 * in the space of the native window containing
 * the document
 */
typedef Viewport = {
	var x:Int;
	var y:Int;
	var width:Int;
	var height:Int;
}

/**
 * This class wraps an instance of an html document and
 * is used to initialise the document properly.
 * 
 * You can think of this class as a tab in your browser or
 * a web view component,
 * in charge of displaying an html document and provide
 * it with the html to display.
 * 
 * You can set its viewport to set its position and size.
 * 
 * You can instantiate as many as this class as you need,
 * to have multiple html document in parrallel
 * 
 * @author Yannick DOMINGUEZ
 */
class CocktailView
{
	/**
	 * key code listened to, to interact with the 
	 * Document
	 */
	
	private static inline var TAB_KEY_CODE:Int = 9;
	
	private static inline var ENTER_KEY_CODE:Int = 13;
	
	private static inline var SPACE_KEY_CODE:Int = 32;
	
	
	/**
	 * the wrapped html document
	 */
	public var document(default, null):HTMLDocument;
	
	/**
	 * the wrapped window of the document
	 */
	public var window(default, null):Window;
	
	/**
	 * The root of the native display list used
	 * for the document. For instance, for flash
	 * it is the Sprite at the top of the Sprites
	 * used for the document
	 */
	public var root(default, null):Dynamic;
	
	/**
	 * the base url of the document or null
	 * if there are none
	 */
	public var url(default, null):String;
	
	/**
	 * the viewport of the document in the native viewport
	 * space. For instance for a flash movie in a browser, the
	 * space is the object tag containing the flash movie. For a desktop
	 * app it is the window.
	 * 
	 * if the viewport is set to null, then the document takes the available
	 * space. For instance in flash, it takes the whole stage
	 * 
	 * can be set any number of time to move and resize the document
	 */
	public var viewport(default, set_viewport):Viewport;

	/**
	 * a reference to the platform API instantiated for the 
	 * document
	 */ 
	private var _platform:Platform;
	
	/**
	 * class constructor
	 */
	public function new()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * create an html document with the provided html. Dispose of the current
	 * document if necessary
	 * 
	 * @param	html the hmtl to init the document with
	 * @param	url the base url of the document, used as base url
	 * when loading asset with relative urls. This base url is concatenated with
	 * the relative url to make an absolute url. 
	 * The provided url must be absolute.
	 */
	public function loadHTML(html:String, url:String = null):Void
	{
		if (document != null)
		{
			dispose();
		}
		
		createDocument();
		initDocument(document, html, url);
	}
	
	/**
	 * create an html document by loading the provided
	 * url. 
	 * @param	url the url of the html document to load,
	 * will also be used as base url
	 * @param	baseUrl an optionnal url to use as the base
	 * url for the document, else the loaded url is used instead
	 */
	public function loadURL(url:String, baseUrl:String = null):Void
	{
		if (document != null)
		{
			dispose();
		}
		
		//use default url as base base url
		if (baseUrl == null)
		{
			baseUrl = url;
		}
		
		//init document and window
		createDocument();
		
		//first try to retrieve html from embedded
		//resource
		var res = Resource.getString(url);
		if (res != null)
		{
			initDocument(document, res, baseUrl);
			return;
		}
		
		//then try to load over network
		var nativeHttp:NativeHttp = new NativeHttp(document.timer);
		
		var onHTMLLoaded = function (e) {
			initDocument(document, nativeHttp.response, baseUrl);
		}
		
		var onLoadError = function(e) {
			throw "could not load " + url;
		}
		
		nativeHttp.addEventListener(EventConstants.LOAD, onHTMLLoaded);
		nativeHttp.addEventListener(EventConstants.ERROR, onLoadError);
		nativeHttp.load(url, HTTPConstants.GET, null, null, DataFormatValue.TEXT);
	}
	
	/**
	 * dispose of the current instance of
	 * the document
	 */
	public function dispose():Void
	{
		if (document != null)
		{
			document.dispose();
		}
		
		if (window != null)
		{
			window.dispose();
		}
		
		if (_platform != null)
		{
			_platform.dispose();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * actually create the document
	 */
	private function createDocument():Void
	{
		_platform = initPlatform();
		
		document = new HTMLDocument();
		window = new Window(document);
		updateViewport(viewport);
	}
	
	/**
	 * instantiating the platform interface 
	 * (expose native apis)
	 * 
	 * store a reference to the graphic root
	 * of the platform
	 */
	private function initPlatform():Platform
	{
		var platform:Platform = new Platform();
		root = platform.getRootPlatformLayer();
		return platform;
	}
	
	/**
	 * init the document with the provided html, url and viewport
	 */
	private function initDocument(htmlDocument:HTMLDocument, html:String, url:String):Void
	{
		setDocumentBindings(document);
		setPlatformBindings(_platform, document);
		
		if (url != null)
		{
			//set base url of document
			htmlDocument.location.href = url;
		}
		
		if (html != null)
		{
			//starts the loading of the document
			htmlDocument.innerHTML = html;
		}
	}
	
	/**
	 * set bindings between the native platform and 
	 * the document, for instance the platform receives
	 * the native mouse event then forward them to the document.
	 * 
	 * Can be customised for instance to disable mouse event or touch
	 * event based on the targeted platform
	 */
	private function setPlatformBindings(platform:Platform, htmlDocument:HTMLDocument):Void
	{
		setMouseBindings(platform, htmlDocument);
		setKeyboardBindings(platform, htmlDocument);
		setTouchBindings(platform, htmlDocument);
		setFullscreenBindings(platform, htmlDocument);
		setViewportBindings(platform, htmlDocument);
		setMouseCursorBindings(platform, htmlDocument);
		setNavigationBindings(platform, htmlDocument);
	}
	
	/**
	 * set default behaviours for some document updating process
	 */
	private function setDocumentBindings(htmlDocument:HTMLDocument):Void
	{
		document.onDocumentUpdated = onDocumentUpdated;
		document.onDocumentInvalidated = onDocumentInvalidated;
	}
	
	/**
	 * update the viewport of the document if the
	 * document is ready
	 */
	private function updateViewport(viewport:Viewport):Void
	{
		//document not ready yet
		if (window == null)
			return;
		
		//reset the viewport if null
		if (viewport == null)
		{
			_platform.viewport = null;
		}
		else
		{
			//convert to cocktail internal rect structure
			var rect = new RectangleVO();
			rect.x = viewport.x;
			rect.y = viewport.y;
			rect.width = viewport.width;
			rect.height = viewport.height;
			
			_platform.viewport = rect;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PLATFORM AND DOCUMENT BINDINGS
	// link the platform and document object, override those metohds
	// to alter cocktail's default behaviour
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Binds the platform mouse events to the document
	 */
	private function setMouseBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		platform.mouseListener.onMouseDown = htmlDocument.onPlatformMouseEvent;
		platform.mouseListener.onMouseUp = htmlDocument.onPlatformMouseEvent;
		platform.mouseListener.onMouseMove = htmlDocument.onPlatformMouseMoveEvent;
		platform.mouseListener.onMouseWheel = htmlDocument.onPlatformMouseWheelEvent;
		platform.mouseListener.onMouseLeave = htmlDocument.onPlatformMouseLeaveEvent;
	}
	
	/**
	 * Binds the mouse cursor events to the document
	 */
	private function setMouseCursorBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		document.onSetMouseCursor = platform.mouseListener.setMouseCursor;
	}
	
	/**
	 * Binds the keyboard events to the document
	 */
	private function setKeyboardBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		platform.keyboardListener.onKeyDown = onPlatformKeyDown;
		platform.keyboardListener.onKeyUp = htmlDocument.onPlatformKeyUpEvent;
	}
	
	/**
	 * Binds the touch events to the document
	 */
	private function setTouchBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		platform.touchListener.onTouchStart = htmlDocument.onPlatformTouchEvent;
		platform.touchListener.onTouchMove = htmlDocument.onPlatformTouchEvent;
		platform.touchListener.onTouchEnd = htmlDocument.onPlatformTouchEvent;
	}
	
	/**
	 * Binds the fullscreen events and API to the document
	 */
	private function setFullscreenBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		platform.onFullScreenChange = document.onPlatformFullScreenChange;
		document.onEnterFullscreen = platform.enterFullscreen;
		document.onExitFullscreen = platform.exitFullscreen;
		document.isFullscreen = platform.fullscreen;
		document.isFullScreenEnabled = platform.fullScreenEnabled;
	}
	
	/**
	 * Binds the viewport events to the document
	 */
	private function setViewportBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		platform.onResize = document.onPlatformResizeEvent;
		platform.onOrientationChange = document.onPlatformOrientationChangeEvent;
		document.getViewportHeight = function() return platform.viewportHeight;
		document.getViewportWidth = function() return platform.viewportWidth;
		document.getTopPlatformLayer = platform.getTopPlatformLayer;
	}
	
	/**
	 * Binds the navigation events to the document
	 */
	private function setNavigationBindings(platform:Platform, htmlDocument:HTMLDocument):Void 
	{
		document.onNavigateToURL = platform.open;
	}
	
	/**
	 * Called just after the document has been fully
	 * updated. 
	 * No default behaviour but can be overrided to perform
	 * additional steps just after document updated as there
	 * are no standard api for this
	 */
	private function onDocumentUpdated():Void
	{
		
	}
	
	/**
	 * Called when the document gets invalidated. For instance
	 * when the rendering or layout of an htmlelement must get
	 * updated.
	 * 
	 * By default, set the document to get updated on next tick,
	 * using the document's timer.
	 * 
	 * Can be overriden for instance to prevent updating the document.
	 * Can be useful if only the DOM part is needed and not the layout
	 * and rendering part
	 */
	private function onDocumentInvalidated():Void
	{
		document.timer.delay(function(timestamp) document.update());
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE PLATFORM AND DOCUMENT BINDINGS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * add custom behaviour after a key down event
	 */
	private function onPlatformKeyDown(keyboardEvent:KeyboardEvent):Void
	{
		document.onPlatformKeyDownEvent(keyboardEvent);
		onAfterKeyDownEvent(keyboardEvent, document);
	}
	
	/**
	 * by default after a key down event, do sequential 
	 * navigation (focus next or previous element) or
	 * simulate a click on the currently focused element
	 * if the right key are pressed
	 */
	private function onAfterKeyDownEvent(keyboardEvent:KeyboardEvent, htmlDocument:HTMLDocument):Void
	{
		switch (Std.parseInt(keyboardEvent.keyChar))
		{
			case TAB_KEY_CODE:
				//only do sequantial navigation if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					if (keyboardEvent.shiftKey == true)
					{
						htmlDocument.focusPreviousElement();
					}
					else
					{
						htmlDocument.focusNextElement();
					}
				}
	
			case ENTER_KEY_CODE, SPACE_KEY_CODE:
				//only simulate click if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					if (htmlDocument.activeElement != null)
					{
						htmlDocument.activeElement.triggerActivationBehaviour();
					}
				}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * update the viewport of the document
	 * @param	value
	 * @return
	 */
	private function set_viewport(value:Viewport):Viewport
	{
		viewport = value;
		updateViewport(viewport);
		return value;
	}
}
