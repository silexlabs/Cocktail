package cocktail.port.flash_player;
import cocktail.core.NativeElement;
import cocktail.port.platform.nativeMedia.NativeMedia;
import flash.Lib;
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
		var nc = new NetConnection();
		nc.connect(null);
		var netStream:NetStream = new NetStream(nc);
		trace(value);
		netStream.play(value);
		_video.attachNetStream(netStream);
		
		return value;
	}
	
	override private function get_nativeElement():NativeElement
	{
		//TODO 1 : very messy
		var d:Dynamic = _video;

		return d;
	}
	
}