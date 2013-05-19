/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;

 /**
  * This interface describes an individual touch point 
  * for a touch event. Touch objects are immutable;
  * after one is created, its attributes must not change.
  * 
  * @author Yannick Dominguez
  */
class Touch
{
	/**
	 * An identification number for each touch point.
	 * When a touch point becomes active, it must be assigned
	 * an identifier that is distinct from any other
	 * active touch point. While the touch point remains 
	 * active, all events that refer to it must assign it the same identifier.
	 */
	public var identifier:Int;
	
	/**
	 * The Element on which the touch point started when it was first
	 * placed on the surface, even if the touch point has since
	 * moved outside the interactive area of that element.
	 */
	public var target:EventTarget;
	
	/**
	 * The horizontal coordinate of point relative to the
	 * screen in pixels
	 */
	public var screenX:Int;
	
	/**
	 * The vertical coordinate of point relative to the screen in pixels
	 */
	public var screenY:Int;
	
	/**
	 * The horizontal coordinate of point relative to the viewport in pixels, excluding any scroll offset
	 */
	public var clientX:Int;
	
	/**
	 * The vertical coordinate of point relative to the viewport in pixels, excluding any scroll offset
	 */
	public var clientY:Int;
	
	/**
	 * The horizontal coordinate of point relative to the viewport in pixels, including any scroll offset
	 */
	public var pageX:Int;
	
	/**
	 * The vertical coordinate of point relative to the viewport in pixels, including any scroll offset
	 */
	public var pageY:Int;
	
	/**
	 * constructor
	 */
	public function new() 
	{
		
	}
}