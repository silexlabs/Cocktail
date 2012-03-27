package core.window;
import core.dom.EventTarget;
import core.event.Event;
import core.html.HTMLDocument;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractWindow extends EventTarget
{

	private var _onResize:Event->Void;
	public var onResize(get_onResize, set_onResize):Event->Void;
	
	private var _document:HTMLDocument;
	public var document(get_document, never):HTMLDocument;
	
	public var innerHeight(get_innerHeight, never):Int;
	
	public var innerWidth(get_innerWidth, never):Int;
	
	public function new() 
	{
		_document = new HTMLDocument();
		super("");
	}
	
	private function set_onResize(value:Event->Void):Event->Void
	{
		_onResize = value;
		return value;
	}
	
	private function get_onResize():Event->Void
	{
		return _onResize;
	}
	
	private function get_innerHeight():Int
	{
		return -1;
	}
	
	private function get_innerWidth():Int
	{
		return -1;
	}
	
	private function get_document():HTMLDocument
	{
		return _document;
	}
	
}