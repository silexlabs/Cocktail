package core.html;
import core.dom.Document;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class HTMLDocument extends Document
{

	private var _body:HTMLBodyElement;
	public var body(get_body, never):HTMLBodyElement;
	
	public function new() 
	{
		super();
		_body = new HTMLBodyElement();
	}
	
	private function get_body():HTMLBodyElement 
	{
		return _body;
	}
}