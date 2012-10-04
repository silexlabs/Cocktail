package cocktail.core.utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ObjectPool<T:IPoolable>
{
	private var _pool:Array<T>;
	
	private var _index:Int;

	private var _pooledClass:Class<T>;
	
	public function new(pooledClass:Class<T>) 
	{
		_pooledClass = pooledClass;
		_pool = new Array<T>();
		_index = 0;
	}
	
	private static var _t:Int = 0;
	
	private static var _r:Int = 0;
	public function get():T
	{
		if (_pool[_index] == null)
		{
			_t++;
			trace("instanttttttttttt : " + _t);
			_pool.push(Type.createInstance(_pooledClass, []));
		}
		else
		{
			_r++;
			trace("reuse : " + _r);
		}
		var ret:T = _pool[_index];
		_index++;
		return ret;
	}
	
	private static var _g:Int = 0;
	
	public function release(object:T):Void
	{
		var objectIndex:Int = 0;
		
		var found:Bool = false;
		
		var length:Int = _pool.length;
		for (i in 0...length)
		{
			objectIndex++;
			if (object == _pool[i])
			{
				_g++;
				trace("found : "+_g);
				found = true;
				break;
			}
		}
		
		if (found == false)
		{
			throw "object not in pool";
			return;
		}
		else
		{
			
		}
		
		object.reset();
		
		_pool[objectIndex] = _pool[_index];
		
		_pool[_index] = object;
		_index--;
	}
}