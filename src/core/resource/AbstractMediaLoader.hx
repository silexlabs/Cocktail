package core.resource;
import core.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractMediaLoader extends AbstractResourceLoader
{

	/**
	 * A reference to the native element actually loading
	 * the asset. For instance, for an image in Flash, a Loader, in JS,
	 * an img tag. When multiple loads occurs, this NativeElement is
	 * reused instead of a new one being created.
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, never):NativeElement;
	
	
	/**
	 * The intrinsic width of the loaded asset. 
	 * Null if no asset is loaded yet or if it is
	 * non applicabel such as when loading a string
	 */
	private var _intrinsicWidth:Int;
	public var intrinsicWidth(getIntrinsicWidth, never):Int;
	
	/**
	 * The intrinsic height of the loaded asset. 
	 * Null if no asset is loaded yet or if it is
	 * non applicabel such as when loading a string
	 */
	private var _intrinsicHeight:Int;
	public var intrinsicHeight(getIntrinsicHeight, never):Int;
	
	/**
	 * The intrinsic ratio of the loaded asset. 
	 * Null if no asset is loaded yet or if it is
	 * non applicabel such as when loading a string
	 */
	private var _intrinsicRatio:Float;
	public var intrinsicRatio(getIntrinsicRatio, never):Float;
	
	public function new(nativeElement:NativeElement = null) 
	{
		//a ResourceLoader doesn't necessarily have a NativeElement.
		//for instance when loading a String, flash will use an URLLoader
		//and JS an XMLHttpRequest object
		if (nativeElement != null)
		{
			_nativeElement = nativeElement;
		}
		
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getNativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function getIntrinsicWidth():Int
	{
		return _intrinsicWidth;
	}
	
	private function getIntrinsicHeight():Int
	{
		return _intrinsicHeight;
	}
	
	private function getIntrinsicRatio():Float
	{
		return _intrinsicRatio;
	}
	
}