/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.css.*;
import cocktail.css.CSSOMData;
import cocktail.event.Event;
import cocktail.core.css.CSSCascadeData;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.core.http.HTTPConstants;
import cocktail.core.http.XMLHTTPRequest;
import cocktail.core.resource.ResourceManager;
import cocktail.port.Bindings;
import cocktail.core.http.HTTPData;

/**
 * The link element allows authors to link their document to other resources.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLLinkElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The IDL attribute disabled only applies to style sheet links. 
	 * When the link element defines a style sheet link, then the
	 * disabled attribute behaves as defined for the alternative style
	 * sheets DOM. For all other link elements it always return
	 * false and does nothing on setting.
	 */
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * The destination of the link(s) is given by the href attribute,
	 * which must be present and must contain a valid non-empty URL
	 * potentially surrounded by spaces. If the href attribute
	 * is absent, then the element does not define a link.
	 */
	public var href(get_href, set_href):String;
	
	/**
	 * The types of link indicated (the relationships) are given by
	 * the value of the rel attribute, which, if present, must have
	 * a value that is a set of space-separated tokens.
	 * If the rel attribute is absent, has no keywords,
	 * or if none of the keywords used are allowed then the 
	 * element does not create any links.
	 */
	public var rel(get_rel, set_rel):String;
	
	/**
	 * A list of the space separated rel attributes
	 */
	public var relList(get_relList, null):Array<String>;
	
	/**
	 * The media attribute says which media the resource
	 * applies to. The value must be a valid media query.
	 */
	public var media(get_media, set_media):String;
	
	/**
	 * The hreflang attribute on the link element has the same semantics
	 * as the hreflang attribute on a and area elements.
	 */
	public var hreflang(get_hreflang, set_hreflang):String;
	
	/**
	 * The type attribute gives the MIME type of the linked resource. 
	 * It is purely advisory. The value must be a valid MIME type.
	 * 
	 * For external resource links, the type attribute is used as a
	 * hint to user agents so that they can avoid fetching resources
	 * they do not support.
	 */
	public var type(get_type, set_type):String;
	
	/**
	 * A reference to the CSS style sheet created by this
	 * node's content. It is null by default, a style sheet
	 * is only created if this element links to an external
	 * stylsheet and is attached to the DOM 
	 */
	public var sheet(default, null):CSSStyleSheet;
	
	/**
	 * Flag which is true when the link element either
	 * has loaded its resource of it is loading it.
	 * Used to prevent simultaneaous
	 * multiple loading of the resource
	 */
	private var _hasLoadedResource:Bool;
	
	public function new() 
	{
		super(HTMLConstants.HTML_LINK_TAG_NAME);
		_hasLoadedResource = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden, as when added
	 * to the DOM, the link element
	 * tries to load its linked resource
	 */
	override private function addedToDOM():Void
	{
		if (_hasLoadedResource == false)
		{	
			loadLinkedResource();
		}
		super.addedToDOM();
	}

	/**
	 * Overriden as when detahed from
	 * the DOM, the link dispose of its
	 * linked resource as needed
	 */
	override private function removedFromDOM():Void
	{
		super.removedFromDOM();
		if (_hasLoadedResource == true)
		{
			unloadLinkedResource();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The link element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Check what kind of external resource
	 * is linked to and if it is of a 
	 * supported type, load it
	 * 
	 * TODO 3 : for now, only CSS stylesheet
	 * are supported
	 */
	private function loadLinkedResource():Void
	{
		//check if if the linke element links to an external CSS
		//stylesheet and load it if it does
		if (href != null && rel == CSSConstants.STYLESHEET_REL)
		{
			_hasLoadedResource = true;
			
			//delay load event until linked resource is loaded
			_ownerHTMLDocument.delayLoadEvent();
			
			var nativeHttp:NativeHttp = new NativeHttp(_ownerHTMLDocument.timer);
			nativeHttp.addEventListener(EventConstants.LOAD, onCSSLoaded);
			nativeHttp.addEventListener(EventConstants.ERROR, onCSSLoadError);
			
			//convert to absolute url if needed before loading
			var absoluteHref:String = _ownerHTMLDocument.getAbsoluteURL(href);
			
			nativeHttp.load(absoluteHref, HTTPConstants.GET, null, null, DataFormatValue.TEXT);
		}
	}
	
	/**
	 * Unload any linked resource, vary based
	 * on the type of linked resource
	 */
	private function unloadLinkedResource():Void
	{
		//if a CSS stylesheet was loaded, remove
		//it from the style manager
		if (sheet != null)
		{
			var htmlDocument:HTMLDocument = cast(ownerDocument);
			htmlDocument.removeStyleSheet(sheet);
			sheet = null;
			
			_hasLoadedResource = false;
		}
	}
	
	/**
	 * Callback called when a linked CSS
	 * stylesheet is successfully loaded
	 */
	private function onCSSLoaded(event:Event):Void
	{
		var nativeHttp:NativeHttp = cast(event.target);
		createStyleSheet(nativeHttp.response);
		
		//signal end of loading
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(EventConstants.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
		
		//document load event can now be dispatched
		_ownerHTMLDocument.undelayLoadEvent();
	}
	
	/**
	 * Callback called when there was an error
	 * was loading the linked CSS stylsheet
	 */
	private function onCSSLoadError(event:Event):Void
	{
		//signal loading error
		fireEvent(EventConstants.ERROR, false, false);
		
		//document load event can now be dispatched
		_ownerHTMLDocument.undelayLoadEvent();
	}
	
	/**
	 * Create a style sheet object from a CSS string and attach
	 * it to the style manager
	 */
	private function createStyleSheet(css:String):Void
	{
		sheet = new CSSStyleSheet(css, PropertyOriginValue.AUTHOR, null, href);
		var htmlDocument:HTMLDocument = cast(ownerDocument);
		htmlDocument.addStyleSheet(sheet);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_disabled():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME);
	}
	
	private function set_disabled(value:Bool):Bool
	{
		setAttributeAsBool(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_href():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME);
	}
	
	private function set_href(value:String):String
	{
		setAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_rel():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_REL_ATTRIBUTE_NAME);
	}
	
	private function set_rel(value:String):String
	{
		setAttribute(HTMLConstants.HTML_REL_ATTRIBUTE_NAME, value);
		return value;
	}
	
	//TODO 2 : implement
	private function get_relList():Array<String>
	{
		return [];
	}
	
	private function get_media():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME);
	}
	
	private function set_media(value:String):String
	{
		setAttribute(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_hreflang():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_HREFLANG_ATTRIBUTE_NAME);
	}
	
	private function set_hreflang(value:String):String
	{
		setAttribute(HTMLConstants.HTML_HREFLANG_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_type():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME);
	}
	
	private function set_type(value:String):String
	{
		setAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, value);
		return value;
	}
	
}
