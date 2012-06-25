package cocktail.core.resource;
import cocktail.core.event.EventTarget;
import cocktail.core.event.UIEvent;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class AbstractResource extends EventTarget
{
	public var loaded(default, null):Bool;
	
	public var loadedWithError(default, null):Bool;
	
	public var nativeResource(default, null):Dynamic;

	/**
	 * The intrinsic width of the loaded resource
	 */
	public var intrinsicWidth(default, null):Int;
	
	/**
	 * The intrinsic height of the loaded resource
	 */
	public var intrinsicHeight(default, null):Int;
	
	/**
	 * The intrinsic ratio of the loaded resource
	 */
	public var intrinsicRatio(default, null):Float;
	
	public function new(url:String) 
	{
		super();
		
		loaded = false;
		loadedWithError = false;
		load(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private loading method
	//////////////////////////////////////////////////////////////////////////////////////////

	private function load(url:String):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private method on resource load complete/error
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onLoadComplete():Void
	{
		loaded = true;
		
		var loadEvent:UIEvent = new UIEvent();
		loadEvent.initUIEvent(UIEvent.LOAD, false, false, null, 0.0);
		dispatchEvent(loadEvent);
	}
	
	private function onLoadError():Void
	{
		loaded = true;
		loadedWithError = true;
		
		var errorEvent:UIEvent = new UIEvent();
		errorEvent.initUIEvent(UIEvent.ERROR, false, false, null, 0.0);
		dispatchEvent(errorEvent);
	}
}