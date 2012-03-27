package cocktail;

import core.html.HTMLDocument;
import core.Window;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Lib 
{
	private static var _document:HTMLDocument;
	public static var document(get_document, never):HTMLDocument;
	
	private static var _window:Window;
	public static var window(get_window, never):Window;
	
	private function new() 
	{
		
	}
	
	private static function get_document():HTMLDocument 
	{
		if (_document == null)
		{
			init();
		}
		return _document;
	}
	
	private static function get_window():Window
	{
		if (_window == null)
		{
			init();
		}
		return _window;
	}
	
	private static function init():Void
	{
		_document = new HTMLDocument();
		_window = new Window(_document);
	}
	
}