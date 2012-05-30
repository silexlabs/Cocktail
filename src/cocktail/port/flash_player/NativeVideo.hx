package cocktail.port.flash_player;
import cocktail.port.platform.nativeMedia.NativeMedia;
import flash.media.Video;
import flash.net.NetConnection;
import flash.net.NetStream;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class NativeVideo extends NativeMedia
{

	private var _video:Video;
	
	public function new() 
	{
		super();
		
		_video = new Video();
	}
	
	override private function set_src(value:String):String
	{
		var netStream:NetStream = new NetStream(new NetConnection());
		netStream.play(value);
		_video.attachNetStream(netStream);
		
		return value;
	}
	
}