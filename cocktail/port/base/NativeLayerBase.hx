package cocktail.port.base;

import cocktail.port.Bindings;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class NativeLayerBase 
{

	public var graphics:GraphicsSurface;
	
	public var layer(default, null):PlatformLayer;
	
	public function new() 
	{
		graphics = new GraphicsSurface();
	}
	
	public function dispose():Void
	{
		graphics.dispose();
		graphics = null;
	}
	
	public function attach(platformLayer:PlatformLayer, index:Int):Void
	{
		
	}
	
	public function detach(platformLayer:PlatformLayer):Void
	{
		
	}
	
	public function initBitmapData(width:Int, height:Int):Void
	{
		
	}
	
}