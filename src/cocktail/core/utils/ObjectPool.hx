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
	
	public function get():T
	{
		if (_freeObjectIndex == -1)
		{
			return Type.createInstance(_pooledClass, []);
		}
		else
		{
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