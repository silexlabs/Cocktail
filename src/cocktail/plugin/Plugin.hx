package cocktail.plugin;

import cocktail.core.event.Event;
import cocktail.core.event.EventCallback;
import cocktail.port.GraphicsContext;
import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class Plugin
{

	public var loaded(default, null):Bool;
	
	public var error(default, null):Bool;
	
	public var viewport(get_viewport, set_viewport):RectangleVO;
	
	private var _loadComplete:Void->Void;
	
	private var _loadError:Void->Void;
	
	public function new(elementAttributes:Hash<String>, params:Hash<String>,loadComplete:Void->Void, loadError:Void->Void) 
	{
		viewport = new RectangleVO(0.0, 0.0, 0.0, 0.0);
		loaded = false;
		error = false;
		_loadComplete = loadComplete;
		_loadError = loadError;
	}
	
	public function dispose():Void
	{
		
	}
	
	public function attach(graphicsContext:GraphicsContext):Void
	{
		
	}
	
	public function detach(graphicsContext:GraphicsContext):Void
	{
		
	}
	
	private function get_viewport():RectangleVO
	{
		return viewport;
	}
	
	private function set_viewport(value:RectangleVO):RectangleVO
	{
		return viewport = value;
	}
	
}