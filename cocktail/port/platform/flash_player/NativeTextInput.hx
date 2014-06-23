/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeTextInputBase;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;
import cocktail.geom.GeomData;

/**
 * This is the flash port of for the native text input,
 * allowing manipulation of a flash TextField
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextInput extends NativeTextInputBase
{

	//those const holds CSS standard font name and their equivalent
	//for flash, so that the name can be switched when setting the font
	//of the text field

	private static inline var SERIF_GENERIC_FONT_NAME:String = "serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans-serif";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "typewriter";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";

	/**
	 * The wrapped native flash text field
	 */
	private var _textField:TextField;
	
	/**
	 * The text format for the text field, storing
	 * its style
	 */
	private var _textFormat:TextFormat;
	
	/**
	 * Mask the text field so that it doesn't
	 * overflow its clip rect bounds
	 */
	private var _mask:Sprite;
	
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		
		_textField = new TextField();
		
		_mask = new Sprite();
		_textField.mask = _mask;
		
		//not supported in openfl
		#if flash9
		_textField.tabEnabled = false;
		#end
		
		//make the text field editable
		_textField.type = TextFieldType.INPUT;
		
		//forward input event
		//note : "change" used instead of "input", as input is dispatched before
		//actual text field value changed
		_textField.addEventListener(flash.events.Event.CHANGE, function(e) { onInput(); } );
		
		_textFormat = new TextFormat();
		
		updateTextFormat();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The flash text field attach itself to the flash display list
	 */
	override public function attach(graphicContext:GraphicsContext):Void
	{
		var containerGraphicContext:DisplayObjectContainer = graphicContext.nativeLayer.platformLayer;
		containerGraphicContext.addChild(_textField);
		
		//note : the mask should be attached as well to be certain that it is in the 
		//same coordinate space as the text field
		containerGraphicContext.addChild(_mask);
	}
	
	/**
	 * The flash text field detach itself from the flash display list
	 */
	override public function detach(graphicContext:GraphicsContext):Void
	{
		var containerGraphicContext:DisplayObjectContainer = graphicContext.nativeLayer.platformLayer;
		containerGraphicContext.removeChild(_textField);
		
		containerGraphicContext.removeChild(_mask);
	}
	
	/**
	 * set the flash native foxus on the text field
	 */
	override public function focus():Void
	{	
		flash.Lib.current.stage.focus = _textField;
	}
	
		
	/**
	 * set the flash native foxus on the text field
	 */
	override public function blur():Void
	{	
		//TODO 2 : seems to do nothing in openfl
		flash.Lib.current.stage.focus = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * TextFormat needs to be set on the text field
	 * each time one of its style changes
	 */
	private function updateTextFormat():Void
	{
		_textField.defaultTextFormat = _textFormat;
		_textField.setTextFormat(_textFormat);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	// set/get the attribute on the flash text field and text format
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_viewport():RectangleVO
	{
		var rect:RectangleVO = new RectangleVO();
		rect.x = _textField.x;
		rect.y = _textField.y;
		rect.width = _textField.width;
		rect.height = _textField.height;
		return rect;
	}
	
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		_textField.x = value.x;
		_textField.y = value.y;
		_textField.width = value.width;
		_textField.height = value.height;
		
		return value;
	}
	
	override private function get_clipRect():RectangleVO
	{
		return clipRect;
	}
	
	override private function set_clipRect(value:RectangleVO):RectangleVO
	{
		_mask.graphics.clear();
		_mask.graphics.beginFill(0xFF0000, 0.5);
		_mask.graphics.drawRect(value.x, value.y, value.width, value.height);
		_mask.graphics.endFill();
		return value;
	}
	
	override private function set_fontSize(value:Float):Float
	{
		_textFormat.size = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_fontSize():Float
	{
		return _textFormat.size;
	}
	
	override private function set_italic(value:Bool):Bool
	{
		_textFormat.italic = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_italic():Bool
	{
		return _textFormat.italic;
	}
	
	override private function get_bold():Bool
	{
		return _textFormat.bold;
	}
	
	override private function set_bold(value:Bool):Bool
	{
		_textFormat.bold = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function set_color(value:Int):Int
	{
		_textFormat.color = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_color():Int
	{
		return _textFormat.color;
	}
	
	/**
	 * Replace CSS font name by flash font name if
	 * needed
	 */
	override private function set_fontFamily(value:String):String
	{
		switch (value)
		{
			case SERIF_GENERIC_FONT_NAME:
				value = SERIF_FLASH_FONT_NAME;
				
			case SANS_SERIF_GENERIC_FONT_NAME:
				value = SANS_SERIF_FLASH_FONT_NAME;
				
			case MONOSPACE_GENERIC_FONT_NAME:
				value = MONOSPACE_FLASH_FONT_NAME;
		}
		
		_textFormat.font = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_fontFamily():String
	{
		return _textFormat.font;
	}
	
	override private function get_value():String 
	{
		return _textField.text;
	}
	
	override private function set_value(textValue:String):String 
	{
		return _textField.text = textValue;
	}
	
	override private function set_maxLength(value:Int):Int
	{
		//in HTML, -1 means no max length, while in flash
		//its 0
		if (value == -1)
		{
			value = 0;
		}
		return _textField.maxChars = value;
	}
	
	override private function set_letterSpacing(value:Float):Float
	{
		_textFormat.letterSpacing = value;
		updateTextFormat();
		
		return value;
	}
	
	override private function get_letterSpacing():Float
	{
		return _textFormat.letterSpacing;
	}
	
}
