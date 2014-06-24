/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.renderer.EmbeddedBoxRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.css.CoreStyle;

/**
 * This is a ase class for element which are repaced by an external
 * resource in the document, for instance an image element.
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * get/set the height html attribute of this embedded element. Return
	 * value depends on the subclass embedded element
	 */
	public var height(get_height, set_height):Int;
		
	/**
	 * get/set the width html attribute of this embedded element. Return
	 * value depends on the subclass embedded element
	 */
	public var width(get_width, set_width):Int;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The intrinsic height of the embedded asset, for instance
	 * for an image, its height in pixel
	 */
	public var intrinsicHeight(get_intrinsicHeight, null):Null<Float>;
	
	/**
	 * The intrinsic width of the embedded asset, for instance
	 * for an image, its width in pixel
	 */
	public var intrinsicWidth(get_intrinsicWidth, null):Null<Float>;
	
	/**
	 * The intrinsic ratio of the embedded asset, for instance
	 * for a video, its pixel ratio
	 */
	public var intrinsicRatio(get_intrinsicRatio, null):Null<Float>;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String) 
	{
		super(tagName);
	}
	
	override private function init():Void
	{
		super.init();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_intrinsicHeight():Null<Float> 
	{
		return intrinsicHeight;
	}
	
	private function get_intrinsicWidth():Null<Float> 
	{
		return intrinsicWidth;
	}
	
	private function get_intrinsicRatio():Null<Float> 
	{
		return intrinsicRatio;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_width(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_width():Int
	{
		return getAttributeAsPositiveSignedInteger(HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME, 0);
	}
	
	private function set_height(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_height():Int
	{
		return getAttributeAsPositiveSignedInteger(HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME, 0);
	}
}
