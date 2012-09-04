package cocktail.port.platform.nativeHttp;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractNativeHttp 
{
	public var status(default, null):Int;
	
	public var total(get_total, null):Int;
	
	public var loaded(get_loaded, null):Int;
	
	public var responseHeaders(default, null):Hash<String>;
	
	public var responseHeadersLoaded(default, null):Bool;
	
	public var response(get_response, null):Dynamic;
	
	public var error(default, null):Bool;
	
	public function new() 
	{
		
	}
	
	public function load(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>):Void
	{
		status = 0;
		total = 0;
		loaded = 0;
		responseHeaders = new Hash<String>();
		responseHeadersLoaded = false;
		response = null;
		error = false;
	}
	
	public function close():Void
	{
		
	}
	
	private function get_response():Dynamic
	{
		return response;
	}
	
	private function get_total():Int
	{
		return -1;
	}
	private function get_loaded():Int
	{
		return -1;
	}
	
}