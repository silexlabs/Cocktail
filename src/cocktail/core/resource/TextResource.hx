package cocktail.core.resource;
import haxe.Http;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextResource extends AbstractResource
{

	public function new(url:String) 
	{
		super(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overidden private loading method
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * starts the loading of the resource using platform
	 * specific APIs
	 */
	override private function load(url:String):Void
	{
		#if macro
		#else
		var http:Http = new Http(url);
		http.onData = onTextLoadComplete;
		http.onError = onTextLoadError;
		http.request(false);
		#end
	}
	
	private function onTextLoadComplete(text:Dynamic):Void
	{
		nativeResource = text;
		onLoadComplete();
	}
	
	private function onTextLoadError(error:String):Void
	{
		onLoadError();
	}
}