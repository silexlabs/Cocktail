package cocktail.core.graphics;

import cocktail.core.geom.Matrix;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.dom.NodeBase;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class AbstractGraphicsContext extends NodeBase<AbstractGraphicsContext>
{
	/**
	 * A reference to the nativeElement used
	 * as drawing surface
	 * 
	 * TODO 1 : rename NativeElement into NativeLayer
	 */
	public var nativeLayer(get_nativeLayer, null):NativeElement;
	
	/**
	 * A reference to the bitmap data of the drawing manager, wrapped
	 * in an implementation specific class
	 */
	public var nativeBitmapData(get_nativeBitmapData, null):NativeBitmapData;

	public function new(nativeLayer:NativeElement = null)
	{
		super();
	}
	
	public function initBitmapData(width:Int, height:Int):Void
	{
		
	}
	
	/**
	 * Clears the current shape and line of the graphic HTMLElement.
	 */
	public function clear():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw bitmap data onto the bitmap surface. Alpha is preserved 
	 * for transparent bitmap
	 * @param	bitmapData the source  bitmap data
	 * @param	matrix a transformation matrix to apply yo the bitmap data when drawing to 
	 * to the bitmap. Defaults to an identity matrix
	 * @param	sourceRect defines the zone from the source bitmap data that must be copied onto the 
	 * native graphic dom element. Takes the whole bitmap data by default
	 */
	public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix = null, sourceRect:RectangleData = null):Void
	{
		//abstract
	}
	
	/**
	 * fast pixel manipulation method used when no transformation is applied to the image
	 * @param	bitmapData the pixels to copy
	 * @param	sourceRect the area of the source bitmap data to use
	 * @param	destPoint the upper left corner of the rectangular aeaa where the new
	 * pixels are placed
	 */
	public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleData, destPoint:PointData):Void
	{
		//abstract
	}
	
	/**
	 * Fill a rect with the specified color
	 * @param rect the rectangle to fill
	 * @param color the rectangle's color
	 */
	public function fillRect(rect:RectangleData, color:ColorData):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeBitmapData():NativeBitmapData
	{
		return null;
	}
	
	private function get_nativeLayer():NativeElement
	{
		return null;
	}
	
}