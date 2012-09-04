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
	/**
	 * Constructor
	 */
	public function new()
	{

		// get the image node
		var image:Image = cast Lib.document.getElementById("icon");
		
		// create interactivity
		image.onmousedown = onMouseDown;
		image.onmouseup = onMouseUp;
	}
	
	/**
	 * Mouse Down callback. Changes the image to be displayed.
	 * @param	event
	 */
	public static function onMouseDown(event:Event):Void
	{
		var image:Image = cast(event.target);
		image.src = "assets/icone_haxe_blanche_ombre.png";
	}
	
	/**
	 * Mouse Up callback. Resets the image to be displayed and loads the dynamic data.
	 * @param	event
	 */
	public static function onMouseUp(event:Event):Void
	{
		var image:Image = cast(event.target);
		image.src = "assets/icone_cocktail_blanche_ombre.png";
	}
	
}