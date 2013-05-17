/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;
import cocktail.port.base.FontBuilderBase;

/**
 * This class is used to share code between flash
 * and nme implementation of the font builder
 * @author Yannick Dominguez
 */
class FlashFontBuilderBase extends FontBuilderBase
{
	/**
	 * holds CSS and flash generic serif names
	 */
	private static inline var SERIF_CSS_FONT_NAME:String = "SERIF";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * holds CSS and flash generig sans serif names
	 */
	private static inline var SANS_SERIF_CSS_FONT_NAME:String = "SANS-SERIF";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * holds CSS and flash generic monospace names
	 */
	private static inline var MONOSPACE_CSS_FONT_NAME:String = "MONOSPACE";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names
	 * 
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	override public function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		var length:Int = value.length;
		for (i in 0...length)
		{
			var fontName:String = value[i];
			
			//check if the font name is a generic CSS font name,
			//in which case, it needs to be replaced with the corresponding
			//flash generic font name
			switch (fontName.toUpperCase())
			{
				case SERIF_CSS_FONT_NAME:
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_CSS_FONT_NAME:
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_CSS_FONT_NAME:
					fontName = MONOSPACE_FLASH_FONT_NAME;
			}
			
			fontFamily += fontName;
			
			if (i < value.length - 1)
			{
				fontFamily += ",";
			}
		}
		
		return fontFamily;
	}
}