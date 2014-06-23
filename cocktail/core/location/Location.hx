/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.location;
import cocktail.core.html.HTMLDocument;
import cocktail.url.URL;

/**
 * Location objects provide a representation of their document's address,
 * and allow the current entry of the browsing context's session
 * history to be changed, by adding or replacing entries in the history object.
 * 
 * @author Yannick DOMINGUEZ
 */
class Location 
{

	/**
	 * Returns the current page's location.
	 * Can be set, to navigate to another page.
	 */
	public var href(default, set_href):String;
	
	/**
	 * callback called when the location is set
	 */
	public var onLocationChanged:Void->Void;
	
	/**
	 * URL decomposition IDL attributes 
	 * 
	 * TODO : implement setters
	 */
	public var protocol(get_protocol, never):String;
	
	public var host(get_host, never):String;
	
	public var hostname(get_hostname, never):String;
	
	public var port(get_port, never):String;
	
	public var pathname(get_pathname, never):String;
	
	public var search(get_search, never):String;
	
	/**
	 * a ref to the document owning this location
	 */
	private var _document:HTMLDocument;
	
	/**
	 * the typed url
	 */
	private var _url:URL;
	
	/**
	 * class constructor
	 */
	public function new(document:HTMLDocument) 
	{
		_document = document;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_document = null;
		_url = null;
	}
	
	private function set_href(value:String):String
	{
		href = value;
		_url = URL.fromString(href);
		if (onLocationChanged != null)
		{
			onLocationChanged();
		}
		
		return value;
	}
	
	private function get_protocol():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.scheme;
	}
	
	private function get_host():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.host;
	}
	
	private function get_hostname():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.authority;
	}
	
	private function get_port():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.port;
	}
	
	private function get_pathname():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.path;
	}
	
	private function get_search():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.query;
	}
	
	private function get_hash():String
	{
		if (_url == null)
		{
			return null;
		}
		
		return _url.fragment;
	}
}
