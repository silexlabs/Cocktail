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
 * @author Yannick Dominguez
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
	public static function fromString(stringUrl:String):URL
	{
		// The almighty regexp (courtesy of http://blog.stevenlevithan.com/archives/parseuri)
        var r : EReg = ~/^(?:(?![^:@]+:[^:@\/]*@)([^:\/?#.]+):)?(?:\/\/)?((?:(([^:@]*)(?::([^:@]*))?)?@)?([^:\/?#]*)(?::(\d*))?)(((\/(?:[^?#](?![^?#\/]*\.[^?#\/.]+(?:[?#]|$)))*\/?)?([^?#\/]*))(?:\?([^#]*))?(?:#(.*))?)/;
 
        // Match the regexp to the url
        r.match(stringUrl);
 
		var url:URL = new URL();
		
        // Use reflection to set each part
        for (i in 0..._parts.length)
        {
            Reflect.setField(url, _parts[i],  r.matched(i));
        }
		
		//hack for relative url with only a file
		if (isRelative(url) == true)
		{
			if (url.directory == null && url.host != null)
			{
				url.file = url.host;
				url.host = null;
			}
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
		
		if (url.directory != null)
		{
			result += url.directory;
		}
		
		if (url.file != null)
		{
			result += url.file;
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
	
	/**
	 * takes 2 urls and return a new url which is the result
	 * of appending the second url to the first.
	 * 
	 * if the first url points to a file, the file is removed
	 * and the appended url is added after the last directory
	 * 
	 * only the query string and fragment of the appended url are used
	 */
	public static function appendURL(url:URL, appendedURL:URL):URL
	{
		if (isRelative(url) == true)
		{
			return appendToRelativeURL(url, appendedURL);
		}
		else
		{
			return appendToAbsoluteURL(url, appendedURL);
		}
	}
	
	/**
	 * return wether the url is relative (true)
	 * or absolute (false)
	 */
	public static function isRelative(url:URL):Bool
	{
		return url.scheme == null;
	}
	
	/**
	 * append the appended url to a relative url 
	 */
	private static function appendToRelativeURL(url:URL, appendedURL:URL):URL
	{
		//when relative url parsed, if it contains only a file (ex : "style.css")
		//then it will store it in the host attribute. So if the url has no directory
		//then only the appended url content is returned, as this method replace the file
		//part of the base url anyway
		if (url.directory == null || url.host == null)
		{
			return cloneURL(appendedURL);
		}
		
		var resultURL:URL = new URL();
		resultURL.host = url.host;
		resultURL.directory = url.directory;

		if (appendedURL.host != null)
		{
			resultURL.directory += appendedURL.host;
		}
		
		if (appendedURL.directory != null)
		{
			var directory = appendedURL.directory;
			if (appendedURL.host == null)
			{
				//remove the initial '/' char if no host, as already present
				//in base url
				resultURL.directory += directory.substr(1);
			}
			else
			{
				resultURL.directory += directory;
			}
			
		}
		
		if (appendedURL.file != null)
		{
			resultURL.file = appendedURL.file;
		}
		
		resultURL.path = resultURL.directory + resultURL.file;
		
		if (appendedURL.query != null)
		{
			resultURL.query = appendedURL.query;
		}
		
		if (appendedURL.fragment != null)
		{
			resultURL.fragment = appendedURL.fragment;
		}
		
		return resultURL;
	}
	
	/**
	 * append the appended url to an absolute url 
	 */
	private static function appendToAbsoluteURL(url:URL, appendedURL:URL):URL
	{
		var resultURL:URL = new URL();
		
		if (url.scheme != null)
		{
			resultURL.scheme = url.scheme;
		}
		
		if (url.host != null)
		{
			resultURL.host = url.host;
		}
		
		var directory:String = "";
		if (url.directory != null)
		{
			directory = url.directory;
		}
		
		if (appendedURL.host != null)
		{
			appendedURL.directory += appendedURL.host;
		}
		
		if (appendedURL.directory != null)
		{
			directory += appendedURL.directory;
		}
		
		resultURL.directory = directory;
		
		if (appendedURL.file != null)
		{
			resultURL.file = appendedURL.file;
		}
		
		resultURL.path = resultURL.directory + resultURL.file;
		
		if (appendedURL.query != null)
		{
			resultURL.query = appendedURL.query;
		}
		
		if (appendedURL.fragment != null)
		{
			resultURL.fragment = appendedURL.fragment;
		}
		
		return resultURL;
	}
	
	/**
	 * clone the provided url
	 */
	private static function cloneURL(url:URL):URL
	{
		var clonedURL:URL = new URL();
		
		clonedURL.url = url.url;
		clonedURL.source = url.source;
		clonedURL.scheme = url.scheme;
		clonedURL.authority = url.authority;
		clonedURL.userInfo = url.userInfo;
		clonedURL.password = url.password;
		clonedURL.host = url.host;
		clonedURL.port = url.port;
		clonedURL.relative = url.relative;
		clonedURL.path = url.path;
		clonedURL.directory = url.directory;
		clonedURL.file = url.file;
		clonedURL.query = url.query;
		clonedURL.fragment = url.fragment;
		
		return clonedURL;
	}
}