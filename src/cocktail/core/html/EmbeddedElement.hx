/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.dom.Node;
import cocktail.core.renderer.EmbeddedBoxRenderer;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.style.CoreStyle;
import cocktail.port.NativeElement;

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
	 * 
	 * TODO 4 : inheriting classes should instead have a reference
	 * to a loaded asset and retrieve the intrisic dimensions from
	 * it, they are not supposed to be stored here
	 */
	public var intrinsicHeight(get_intrinsicHeight, null):Null<Int>;
	
	/**
	 * The intrinsic width of the embedded asset, for instance
	 * for an image, its width in pixel
	 */
	public var intrinsicWidth(get_intrinsicWidth, null):Null<Int>;
	
	/**
	 * The intrinsic ratio of the embedded asset, for instance
	 * for a video, its pixel ratio
	 */
	public var intrinsicRatio(get_intrinsicRatio, null):Null<Float>;
	
	/**
	 * A reference to the embedded asset
	 * 
	 * TODO 1 :the embeddedasset attribute seems obsolete and shouldn't exist anymore
	 * with the ResourceManager
	 */
	public var embeddedAsset(default, null):NativeElement;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String) 
	{
		super(tagName);
	}
	
	override private function init():Void
	{
		initEmbeddedAsset();
		super.init();
	}
	
	/**
	 * get a reference to the embedded asset
	 */
	private function initEmbeddedAsset():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME)
		{
			height = Std.parseInt(value);
		}
		else if (name == HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME)
		{
			width = Std.parseInt(value);
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	override public function getAttribute(name:String):String
	{
		if (name == HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME)
		{
			return Std.string(get_height());
		}
		else if (name == HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME)
		{
			return Std.string(get_width());
		}
		else
		{
			return super.getAttribute(name);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_intrinsicHeight():Null<Int> 
	{
		return intrinsicHeight;
	}
	
	private function get_intrinsicWidth():Null<Int> 
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
		super.setAttribute(HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_width():Int
	{
		var width:String = super.getAttribute(HTMLConstants.HTML_WIDTH_ATTRIBUTE_NAME);
		if (width == null)
		{
			return 0;
		}
		else
		{
			return Std.parseInt(width);
		}
	}
	
	private function set_height(value:Int):Int
	{
		super.setAttribute(HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_height():Int
	{
		var height:String = super.getAttribute(HTMLConstants.HTML_HEIGHT_ATTRIBUTE_NAME);
		if (height == null)
		{
			return 0;
		}
		else
		{
			return Std.parseInt(height);
		}
	}
}