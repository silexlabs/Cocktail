/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.resource;

import cocktail.port.MediaLoader;
import haxe.Http;
import haxe.Log;

/**
 * This class is in charge of loading a picture. When multiple
 * pictures are loaded with the same instance, the picture is 
 * replaced
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageLoader extends MediaLoader
{
	/**
	 * class constructor
	 */
	public function new()
	{
		super();
	}
}