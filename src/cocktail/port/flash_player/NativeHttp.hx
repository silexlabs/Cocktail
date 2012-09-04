package cocktail.port.flash_player;
import cocktail.port.platform.nativeHttp.AbstractNativeHttp;
import flash.events.HTTPStatusEvent;
import flash.net.URLLoader;
import flash.net.URLRequest;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class NativeHttp extends AbstractNativeHttp
{

	private var _urlLoader:URLLoader;
	
	public function new() 
	{
		super();
		
		_urlLoader = new URLLoader();
	}
	
	override public function load(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>):Void
	{
		super.load(url, method, data, authorRequestHeaders);
		
		var urlRequest:URLRequest = new URLRequest(url);
		urlRequest.method = method;
		urlRequest.data = data;
		
		_urlLoader.addEventListener(HTTPStatusEvent.HTTP_STATUS, onHttpStatus);
		_urlLoader.load(urlRequest);
		//TODO 2 : implement custom request header
		//urlRequest.requestHeaders
		
	}
	
	private function onHttpStatus(event:HTTPStatusEvent):Void
	{
		status = event.status;
		//TODO 2 : no way in flash to get response headers, only in AIR
		responseHeadersLoaded = true;
	}
	
	override public function close():Void
	{
		_urlLoader.close();
	}
	
	override private function get_response():Dynamic
	{
		return _urlLoader.data;
	}
	
	override private function get_total():Int
	{
		return _urlLoader.bytesTotal;
	}
	
	override private function get_loaded():Int
	{
		return _urlLoader.bytesLoaded;
	}
	
}