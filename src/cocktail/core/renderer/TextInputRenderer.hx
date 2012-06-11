/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;

/**
 * This is an ElementRenderer in charge of
 * rendering a text input form control
 * 
 * TODO 1 IMPORTANT : this is a temporary 
 * implementation, eventually it will 
 * need to be implemented without relying
 * on flash Text Field
 * 
 * @author Yannick DOMINGUEZ
 */
class TextInputRenderer extends EmbeddedBoxRenderer
{
	
	/**
	 * A reference to a native flash text field
	 */
	#if (flash9 || nme)
	private var _nativeTextField:flash.text.TextField;
	#end
	
	/**
	 * Get/set the value of the flash text field
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "typewriter";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(node:Node) 
	{
		super(node);
		
		#if (flash9 || nme)
		_nativeTextField = new flash.text.TextField();
		_nativeTextField.tabEnabled = false;
		#end
		
		//listen to cocktail focus events on the HTMLInputElement
		_node.addEventListener(FocusEvent.FOCUS, onTextInputFocus);
	}
	
	/**
	 * Overriden to also render the native flash text field
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement)
	{
		updateNativeTextField();
		#if (flash9 || nme)
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		//TODO 3 : in NME, seems to make text field lose focus
		containerGraphicContext.addChild(_nativeTextField);
		#end
	}
	
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the HTMLInputElement gains focus, 
	 * set the flash native focus to the 
	 * native text field
	 */
	private function onTextInputFocus(e:cocktail.core.event.Event):Void
	{
		#if (flash9 || nme)
		//TODO 2 : seems to do nothing in NME
		flash.Lib.current.stage.focus = _nativeTextField;
		#end
	}
	
	//TODO 3 : duplicated code from FontManager NME implementation, a native
	//text element should be reconfigurable instead of needing to create a
	//new one each time ? Won't work for flash text engine, but will work
	//for texrt fields
	private function updateNativeTextField():Void
	{
		#if (flash9 || nme)
		_nativeTextField.type = flash.text.TextFieldType.INPUT;
		_nativeTextField.x = globalBounds.x;
		_nativeTextField.y = globalBounds.y + globalBounds.height / 2 - computedStyle.fontSize + _coreStyle.fontMetrics.ascent / 2;
		_nativeTextField.width = globalBounds.width;
		_nativeTextField.height = globalBounds.height;
		
		var textFormat:flash.text.TextFormat = new flash.text.TextFormat();
		textFormat.font = getNativeFontFamily(computedStyle.fontFamily);
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		textFormat.size = computedStyle.fontSize;
		
		
		
		var bold:Bool;
		
		switch (computedStyle.fontWeight)
		{
			case lighter, FontWeight.normal,
			css100, css200, css300, css400:
				bold = false;
				
			case FontWeight.bold, bolder, css500, css600,
			css700, css800, css900:
				bold = true;
		}
		
		textFormat.bold = bold;
		textFormat.italic = computedStyle.fontStyle == FontStyle.italic;
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		
		textFormat.color = computedStyle.color.color;
		
		_nativeTextField.defaultTextFormat = textFormat;
		_nativeTextField.setTextFormat(textFormat);
		#end
	}
	
	private function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String = value[i];
			
			switch (fontName)
			{
				case SERIF_GENERIC_FONT_NAME:
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_GENERIC_FONT_NAME:
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_GENERIC_FONT_NAME:
					fontName = MONOSPACE_FLASH_FONT_NAME;
			}
			
			fontFamily += fontName;
			
			if (i < value.length - 1)
			{
				fontFamily += ",";
			}
		}
		
		return fontFamily;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_value():String 
	{
		#if (flash9 || nme)
		return _nativeTextField.text;
		#end
		return null;
	}
	
	private function set_value(value:String):String 
	{
		#if (flash9 || nme)
		return _nativeTextField.text = value;
		#end
		return null;
	}
	
}