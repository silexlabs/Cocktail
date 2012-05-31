package cocktail.port.platform.nativeMedia;
import cocktail.core.event.Event;
import cocktail.core.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class NativeMedia
{
	
	public var duration(get_duration, never):Float;
	
	private var volume(get_volume, set_volume):Float;
	
	public var src(never, set_src):String;

	private var _onLoadedMetaData:Event->Void;
	public var onLoadedMetaData(get_onLoadedMetaData, set_onLoadedMetaData):Event->Void;
	
	private var _onTimeUpdate:Event->Void;
	public var onTimeUpdate(get_onTimeUpdate, set_onTimeUpdate):Event->Void;
	
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function play():Void
	{
		
	}
	
	public function pause():Void
	{
		
	}
	
	public function seek(time:Float):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native video event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onNativeLoadedMetaData(event:Dynamic):Void
	{
		if (_onLoadedMetaData != null)
		{
			var loaddedMetadataEvent:Event = new Event();
			loaddedMetadataEvent.initEvent(Event.LOADED_METADATA, false, false);
			_onLoadedMetaData(loaddedMetadataEvent);
		}
	}
	
	private function onNativeTimeUpdate(event:Dynamic):Void
	{
		if (_onTimeUpdate != null)
		{
			var timeUpdateEvent:Event = new Event();
			timeUpdateEvent.initEvent(Event.TIME_UPDATE, false, false);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_onLoadedMetaData():Event->Void
	{
		return _onLoadedMetaData;
	}
	
	private function set_onLoadedMetaData(value:Event->Void):Event->Void
	{
		return _onLoadedMetaData = value;
	}
	
	private function get_onTimeUpdate():Event->Void
	{
		return _onTimeUpdate;
	}
	
	private function set_onTimeUpdate(value:Event->Void):Event->Void
	{
		return _onTimeUpdate = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeElement():NativeElement
	{
		return null;
	}
	
	private function get_duration():Float
	{
		return 0;
	}
	
	private function set_src(value:String):String
	{
		return value;
	}
	
	private function get_volume():Float
	{
		return 0;
	}
	
	private function set_volume(value:Float):Float
	{
		return value;
	}
}