/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
import js.Lib;
import js.Dom;

/**
 * Getting Started with cocktail
 * 
 * @author	Raphael Harmel
 * @date	2012-08-13
 */
class Main
{
	static inline var ICON_COCKTAIL_PATH:String = "assets/icone_cocktail_blanche_ombre.png";
	static inline var ICON_HAXE_PATH:String = "assets/icone_haxe_blanche_ombre.png";
	
	public function new()
	{
		// get the image node
		var image:Image = cast Lib.document.getElementById("icon");
		
		// create interactivity
		image.onmouseup = function(event:Event) {
			// if image source is cocktail icon, change it to Haxe one
			if (image.src.indexOf(ICON_COCKTAIL_PATH) != -1)
				image.src = ICON_HAXE_PATH;
			// if image source is not cocktail icon, change it back to cocktail
			else
				image.src = ICON_COCKTAIL_PATH;
		}
	}
}