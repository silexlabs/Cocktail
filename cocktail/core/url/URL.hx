/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.url;

/**
 * Parse and serialize an URL.
 * 
 * note : parts of the implementation originate from
 * here : http://haxe.org/doc/snip/uri_parser,
 * some part of the URL have been renamed to match
 * w3c spec
 * 
 * @author 
 */
class URL
{	
	/**
	 * URL parts names
	 */
	private static var _parts : Array<String> = ["source", "scheme", "authority", "userInfo", "user",
	"password","host","port","relative","path","directory","file","query","fragment"];

	/**
	 * URL parts
	 */
	public var url : String;
    public var source : String;
    public var scheme : String;
    public var authority : String;
    public var userInfo : String;
    public var user : String;
    public var password : String;
    public var host : String;
    public var port : String;
    public var relative : String;
    public var path : String;
    public var directory : String;
    public var file : String;
    public var query : String;
    public var fragment : String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	/**
	 * Parse a string url and return a typed
	 * object from it.
	 * 
	 * note : implementation originate from here :
	 * http://haxe.org/doc/snip/uri_parser
	 */
	public static function fromString(url:String):URL
	{
		// The almighty regexp (courtesy of http://blog.stevenlevithan.com/archives/parseuri)
        var r : EReg = ~/^(?:(?![^:@]+:[^:@\/]*@)([^:\/?#.]+):)?(?:\/\/)?((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?)(((\/(?:[^?#](?![^?#\/]*\.[^?#\/.]+(?:[?#]|$)))*\/?)?([^?#\/]*))(?:\?([^#]*))?(?:#(.*))?)/;
 
        // Match the regexp to the url
        r.match(url);
 
		var url:URL = new URL();
		
        // Use reflection to set each part
        for (i in 0..._parts.length)
        {
            Reflect.setField(url, _parts[i],  r.matched(i));
        }
		
		return url;
	}
	
	/**
	 * Serialize an URL object into an 
	 * URL string
	 */
	public static function toString(url:URL):String
	{
		var result:String = "";
		
		if (url.scheme != null)
		{
			result += url.scheme + "://";
		}
		
		if (url.user != null)
		{
			result += url.user + ":";
		}
		
		if (url.password != null)
		{
			result += url.password + "@";
		}
		
		if (url.host != null)
		{
			result += url.host;
		}
		
		if (url.port != null)
		{
			result += ":" + url.port;
		}
		
		if (url.path != null)
		{
			result += url.path;
		}
		
		if (url.query != null)
		{
			result += "?" + url.query;
		}
		
		if (url.fragment != null)
		{
			result += "#" + url.fragment;
		}
		
		return result;
	}
}