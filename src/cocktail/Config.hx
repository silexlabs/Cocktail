/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail;

/**
 * This class exposes global configuration constants
 * used throughout cocktail.
 * 
 * For now, to override those constants,
 * you can either change them here or duplicate the config
 * and import it in your project to replace this original
 * file altogether
 * 
 * @author Yannick Dominguez 
 */
class Config 
{

	/**
	 * Enable or disable compositing. Compositing is used
	 * for elements which require their own rendering surface, to respect z-order of the document.
	 * For instance, a video, a text input or a swf object in flash
	 * needs their own native surface, for instance a Sprite in flash.
	 * 
	 * You can disable it to improve performance by avoiding creating
	 * too many bitmap surface and/or native element, however element
	 * which would be otherwise composited will now always be on top
	 * of the rendered text and picture
	 */
	public static inline var ENABLE_COMPOSITING:Bool = true;
	
	/**
	 * Disable listening to the platform mouse event. This is
	 * mainly useful on mobile platform where touch events
	 * are preferred. If false, Mouse event won't be listened to and dispatch
	 * anymore however a quick touch tap will still synthesize
	 * a "click" mouse event
	 */
	public static inline var ENABLE_MOUSE_EVENT:Bool = true;
	
	public function new() 
	{
		
	}
	
}