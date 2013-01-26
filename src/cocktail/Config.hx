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
	
	/**
	 * The distance in pixel that a touch on screen has to move to 
	 * prevent dispatching a click event on next touch up. 
	 * 
	 * If the touch moves more than this distance, then it is assumed
	 * that the user don't want to click but instead is scrolling 
	 * or drag'n'dropping an element
	 */ 
	public static inline var TOUCH_MOVE_PREVENT_CLICK_DISTANCE:Int = 10;
	
	/**
	 * When drawing bitmap, determine if smoothing should be applied
	 * to it when it not displayed at 100% of its size. This improves
	 * the rendering of the bitmap but decreases performances.
	 */
	public static inline var ENABLE_BITMAP_SMOOTHING:Bool = true;
	
	/**
	 * Flash specific.
	 * 
	 * Use a low stage quality to slightly improve performance, however
	 * it degrades visual rendering. If the application is mostly bitmap
	 * based, it doesn't make much difference in the rendering
	 */
	public static inline var USE_LOW_STAGE_QUALITY:Bool = false;
	
	/**
	 * The document might be updated immediately instead of waiting
	 * for next update on some conditions. For instance, getting
	 * the offsetWidth or offsetTop of an HTMLElement requires the document
	 * to be up to date.
	 * 
	 * It can be deactivated for improved performance, but some properties
	 * might return not up to date value. If you deactivatye it avoid setting
	 * styles and immediately requesting the size or position of an element, set
	 * a timer instead
	 */
	public static inline var ENABLE_SYNCHRONOUS_UPDATE:Bool = true;
	
	public function new() 
	{
		
	}
	
}