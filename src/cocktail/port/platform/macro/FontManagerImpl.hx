/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.macro;
import cocktail.core.font.AbstractFontManagerImpl;
import cocktail.core.font.FontData;

/**
 * This is the port for the macro runtime (compilation)
 * for the font.
 */
class FontManagerImpl extends AbstractFontManagerImpl
{
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return new default font metrics.
	 * 
	 * TODO 5 : for now, return default font metrics to prevent crash
	 * while cascading style. Eventually, could retrieve font to allow
	 * layout at compile time
	 */
	override private function doGetFontMetrics(fontFamily:String, fontSize:Float):FontMetricsVO
	{
		return new FontMetricsVO(12.0, 12.0, 12.0, 12.0, 3.0, 3.0, 3.0, 5.0 );
	}
}
