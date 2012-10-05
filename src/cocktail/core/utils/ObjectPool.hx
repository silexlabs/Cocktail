package cocktail.core.utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class ObjectPool<T:IPoolable>
{
	private var _pool:Array<T>;
	
	private var _freeObjectIndex:Int;

	private var _pooledClass:Class<T>;
	
	public function new(pooledClass:Class<T>) 
	{
		_pooledClass = pooledClass;
		_pool = new Array<T>();
		_freeObjectIndex = -1;
	}
	
	private static var _t:Int = 0;
	
	private static var _r:Int = 0;
	public function get():T
	{
		if (_freeObjectIndex == -1)
		{
			_t++;
			//trace("instanttttttttttt : " + _t);
			return Type.createInstance(_pooledClass, []);
		}
		else
		{
			_r++;
			//trace("reuse : " + _r);
			var object:T = _pool[_freeObjectIndex];
			_freeObjectIndex--;
			return object;
		}
	}
	
	private static var _g:Int = 0;
	
	public function release(object:T):Void
	{
		object.reset();
		_freeObjectIndex++;
		_pool[_freeObjectIndex] = object;
	}
}