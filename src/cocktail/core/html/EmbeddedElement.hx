/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.dom.Node;
import cocktail.core.renderer.EmbeddedBoxRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.style.CoreStyle;
import cocktail.core.NativeElement;

/**
 * This is a ase class for element which are repaced by an external
 * resource in the document, for instance an image element.
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedElement extends HTMLElement
{
	/**
	 * The name of the html width attribute
	 */
	private static inline var HTML_WIDTH_ATTRIBUTE:String = "width";
	
	/**
	 * The name of the html height attribute
	 */
	private static inline var HTML_HEIGHT_ATTRIBUTE:String = "height";
	
	/**
	 * The intrinsic height of the embedded asset, for instance
	 * for an image, its height in pixel
	 * 
	 * TODO : inheriting classes should instead have a reference
	 * to a loaded asset and retrieve the intrisic dimensions from
	 * it, they are not supposed to be stored here
	 */
	private var _intrinsicHeight:Null<Int>;
	public var intrinsicHeight(get_intrinsicHeight, never):Null<Int>;
	
	/**
	 * The intrinsic width of the embedded asset, for instance
	 * for an image, its width in pixel
	 */
	private var _intrinsicWidth:Null<Int>;
	public var intrinsicWidth(get_intrinsicWidth, never):Null<Int>;
	
	/**
	 * The intrinsic ratio of the embedded asset, for instance
	 * for a video, its pixel ratio
	 */
	private var _intrinsicRatio:Null<Float>;
	public var intrinsicRatio(get_intrinsicRatio, never):Null<Float>;

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
	
	/**
	 * A reference to the embedded asset
	 */
	private var _embeddedAsset:NativeElement;
	public var embeddedAsset(get_embeddedAsset, never):NativeElement;
	
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
	
	/**
	 * Embedded elements can't have children
	 */
	override public function appendChild(newChild:Node):Node
	{
		return newChild;
	}
		
	/**
	 * Embedded elements can't have children
	 */
	override public function removeChild(oldChild:Node):Node
	{
		return oldChild;
	}
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTML_HEIGHT_ATTRIBUTE)
		{
			height = Std.parseInt(value);
		}
		else if (name == HTML_WIDTH_ATTRIBUTE)
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
		if (name == HTML_HEIGHT_ATTRIBUTE)
		{
			return Std.string(get_height());
		}
		else if (name == HTML_WIDTH_ATTRIBUTE)
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
	
	private function get_embeddedAsset():NativeElement
	{
		return _embeddedAsset;
	}
	
	private function get_intrinsicHeight():Null<Int> 
	{
		return _intrinsicHeight;
	}
	
	private function get_intrinsicWidth():Null<Int> 
	{
		return _intrinsicWidth;
	}
	
	private function get_intrinsicRatio():Null<Float> 
	{
		return _intrinsicRatio;
	}
	
	private function set_width(value:Int):Int
	{
		setAttribute(HTML_WIDTH_ATTRIBUTE, Std.string(value));
		return value;
	}
	
	private function get_width():Int
	{
		var width:String = getAttribute(HTML_WIDTH_ATTRIBUTE);
		if (width == "")
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
		setAttribute(HTML_HEIGHT_ATTRIBUTE, Std.string(value));
		return value;
	}
	
	private function get_height():Int
	{
		var height:String = getAttribute(HTML_HEIGHT_ATTRIBUTE);
		if (height == "")
		{
			return 0;
		}
		else
		{
			return Std.parseInt(height);
		}
	}
}