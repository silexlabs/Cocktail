package cocktail.port.platform.nativeText;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractNativeText 
{

	
	public var width(get_width, null):Float;
	
	public var nativeBitmap(get_nativeBitmap, null):NativeBitmapData;
	
	private var _nativeElement:NativeElement;
	
	public function new(nativeElement:NativeElement) 
	{
		_nativeElement = nativeElement;
	}
	
	private function get_width():Float
	{
		return 0.0;
	}
	
	private function get_nativeBitmap():NativeBitmapData
	{
		return null;
	}
	
	
	
}