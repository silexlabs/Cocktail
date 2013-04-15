/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.api;

import cocktail.core.html.HTMLDocument;
import cocktail.core.window.Window;
import cocktail.port.Platform;
import cocktail.core.geom.GeomData;

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
 * You can think of this class as a tab in your browser, 
 * in charge of displaying an html document and provide
 * it with the html to display.
 * 
 * You can instantite as many as this class as you need,
 * to have multiple html document in parrallel
 * 
 * @author Yannick DOMINGUEZ
 */
class Cocktail 
{
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
	 * used fo rthe document
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
	 * create a new document and window
	 * 
	 * @param	html the hmtl to init the document with
	 * 
	 * @param	url the base url of the document, used as base url
	 * when loading asset with relative urls. This base url is concatenated with
	 * the relative url to make an absolute url. 
	 * The provided url must be absolute.
	 * 
	 * If none is provided,
	 * the asset will be loaded using the relative url
	 * 
	 * @param	viewport set the viewport of the document
	 */
	public function new(html:String = null, url:String = null, viewport:Viewport = null)
	{
		createDocument(html, url, viewport);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * actually create the document
	 */
	private function createDocument(html:String = null, url:String = null, viewport:Viewport = null):Void
	{
		var platform:Platform = initPlatform();
		
		document = new HTMLDocument();
		window = new Window(document, platform);
		document.window = window;
		
		setPlatformBindings(platform, document);
		initDocument(document, html, url, viewport);
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
		root = platform.getRootNativeLayer();
		return platform;
	}
	
	/**
	 * init the document with the provided html, url and viewport
	 */
	private function initDocument(htmlDocument:HTMLDocument, html:String, url:String, viewport:Viewport):Void
	{
		if (viewport != null)
		{
			this.viewport = viewport;
		}
		
		if (url != null)
		{
			//todo : set base url on document
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
		platform.mouse.onMouseDown = document.onPlatformMouseEvent;
		platform.mouse.onMouseUp = document.onPlatformMouseEvent;
		platform.mouse.onMouseMove = document.onPlatformMouseMoveEvent;
		platform.mouse.onMouseWheel = document.onPlatformMouseWheelEvent;
		platform.mouse.onMouseLeave = document.onPlatformMouseLeaveEvent;
		
		platform.keyboard.onKeyDown = document.onPlatformKeyDownEvent;
		platform.keyboard.onKeyUp = document.onPlatformKeyUpEvent;
		
		platform.onResize = document.onPlatformResizeEvent;
		platform.onOrientationChange = document.onPlatformOrientationChangeEvent;
		
		platform.touchListener.onTouchStart = document.onPlatformTouchEvent;
		platform.touchListener.onTouchMove = document.onPlatformTouchEvent;
		platform.touchListener.onTouchEnd = document.onPlatformTouchEvent;
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
		
		//reset the viewport if null
		if (viewport == null)
		{
			window.platform.viewport = null;
		}
		else
		{
			//convert to cocktail internal rect structure
			var rect = new RectangleVO();
			rect.x = value.x;
			rect.y = value.y;
			rect.width = value.width;
			rect.height = value.height;
			
			window.platform.viewport = rect;
		}
		
		return value;
	}
}