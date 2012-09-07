/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.renderer.TextInputRenderer;
import cocktail.core.css.CoreStyle;

/**
 * Form control.
 * 
 * TODO IMPORTANT : for now only the text input form control
 * is implemented and its implementation, relying on Flash
 * TextField is not ideal. It should be entirely abstracted, using
 * only a Text node.
 * The following features are missing for this : 
	 * text selection
	 * caret management
	 * text can be scrolled with
	 * the mouse when the mouse is down
	 * on an element
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLInputElement extends EmbeddedElement
{
	/**
	 * The intrinsic width and height of a text input used
	 * when no width or height attribute or CSS style defined, 
	 * values are abitrary, based on observation
	 */
	private static inline var HTML_INPUT_TEXT_INTRINSIC_WIDTH:Int = 150;
	
	private static inline var HTML_INPUT_TEXT_INTRINSIC_HEIGHT:Float = 30;
	
	/**
	 * When the type attribute of the element has the value "text",
	 * "file" or "password", this represents the current contents
	 * of the corresponding form control, in an interactive user
	 * agent. Changing this attribute changes the contents of the
	 * form control, but does not change the value of the HTML
	 * value attribute of the element. When the type attribute
	 * of the element has the value "button", "hidden", "submit",
	 * "reset", "image", "checkbox" or "radio", this represents 
	 * the HTML value attribute of the element.
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_INPUT_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as <input /> element are serialised
	 * as self-closing tags
	 */
	override public function isVoidElement():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate an input specific renderer
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new TextInputRenderer(this);
		
		var textInputElementRenderer:TextInputRenderer = cast(elementRenderer);
		
		//initialise value of native text input
		var value:String = getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
		
		if (value != null)
		{
			
			textInputElementRenderer.value = value;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDE PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An html form control element is inherently
	 * focusable
	 */
	override private function isDefaultFocusable():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	/////////////////////////////////
	
	override private function get_intrinsicWidth():Null<Float> 
	{
		return HTML_INPUT_TEXT_INTRINSIC_WIDTH;
	}
	
	override private function get_intrinsicHeight():Null<Float> 
	{
		return HTML_INPUT_TEXT_INTRINSIC_HEIGHT;
	}
	
	/////////////////////////////////
	// SETTER/GETTER
	/////////////////////////////////
	 
	/**
	 * When value set/get, also set/get it on the native
	 * text input
	 */
	private function set_value(value:String):String
	{
		setAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME, value);
	
		if (elementRenderer != null)
		{
			var textInputElementRenderer:TextInputRenderer = cast(elementRenderer);
			textInputElementRenderer.value = value;
		}
		
		return value;
	}
	
	private function get_value():String
	{
		if (elementRenderer != null)
		{
			var textInputElementRenderer:TextInputRenderer = cast(elementRenderer);
			return textInputElementRenderer.value;
		}
		
		return getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
	}
}