package cocktail.core.resource;
import cocktail.port.Resource;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ResourceManager 
{
	private static var _resources:Hash<Resource>;
	
	private function new() 
	{
		
	}
	
	public static function getResource(url:String):Resource
	{
		if (_resources == null)
		{
			_resources = new Hash<Resource>();
		}
		
		if (_resources.exists(url) == false)
		{
			var resource:Resource = new Resource(url);
			_resources.set(url, resource);
		}
		
		return _resources.get(url);
	}
}