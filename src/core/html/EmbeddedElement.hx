package core.html;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 #if (flash9 || cpp || nme)
import core.NativeElement;
import port.flash_player.HTMLElement;

#elseif js
import port.browser.HTMLElement;

#end
 
class EmbeddedElement extends HTMLElement
{

	private var _intrinsicHeight:Null<Int>;
	public var intrinsicHeight(get_intrinsicHeight, never):Null<Int>;
	
	private var _intrinsicWidth:Null<Int>;
	public var intrinsicWidth(get_intrinsicWidth, never):Null<Int>;
	
	private var _intrinsicRatio:Null<Float>;
	public var intrinsicRatio(get_intrinsicRatio, never):Null<Float>;

	private var _height:Int;
	public var height(get_height, set_height):Int;
		
	private var _width:Int;
	public var width(get_width, set_width):Int;
	
	private var _embeddedAsset:NativeElement;
	public var embeddedAsset(get_embeddedAsset, never):NativeElement;
	
	
	
	public function new() 
	{
		super();
	}
	
	override private function init():Void
	{
		initEmbeddedAsset();
		super.init();
	}
	
	private function initEmbeddedAsset():Void
	{
		
	}
	
	private function get_embeddedAsset():NativeElement
	{
		return _embeddedAsset;
	}
	
	private function get_intrinsicHeight():Null<Int> 
	{
		return _intrinsicHeight;
	}
	
	private function get_intrinsicWidth():Null<Int> 
	{
		return _intrinsicWidth;
	}
	
	private function get_intrinsicRatio():Null<Float> 
	{
		return _intrinsicRatio;
	}
	
	private function set_width(value:Int):Int
	{
		return _width = value;
	}
	
	private function get_width():Int
	{
		return _width;
	}
	
	private function set_height(value:Int):Int
	{
		return _height = value;
	}
	
	private function get_height():Int
	{
		return _height;
	}
}