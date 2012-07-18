package cocktail.port.flash_player;

import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.port.platform.nativeText.AbstractNativeText;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class NativeText extends AbstractNativeText
{

	private var _bitmap:Dynamic;
	
	public function new(nativeElement:NativeElement) 
	{
		super(nativeElement);
		
			_bitmap = new flash.display.BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
			var matr = new flash.geom.Matrix();
			matr.translate(0.0, leadedAscent);
			
			_bitmap.draw(_nativeElement, matr);
	}
	
	override private function get_width():Float
	{
		return 0.0;
	}
	
	override private function get_nativeBitmap():NativeBitmapData
	{
		return null;
	}
	
}