/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.http;

import cocktail.core.event.XMLHttpRequestEventTarget;

/**
 * Used by XMLHttpRequest to dispatch events
 * when data are uploaded
 * 
 * @author Yannick DOMINGUEZ
 */
class XMLHttpRequestUpload extends XMLHttpRequestEventTarget
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
}