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
 * The input element represents a typed data field, usually with
 * a form control to allow the user to edit the data.
 *
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
	 * Limit the max number of characters whihc can
	 * be inputed
	 */
	public var maxLength(get_maxLength, set_maxLength):Int;
	
	/**
	 * The checked IDL attribute allows scripts to manipulate the checkedness of an
	 * input element. On getting, it must return the current checkedness 
	 * of the element; and on setting, it must set the element's
	 * checkedness to the new value and set the element's
	 * dirty checkedness flag to true.
	 */
	public var checked(get_checked, set_checked):Bool;
	
	/**
	 * The readonly attribute is a boolean attribute that controls
	 * whether or not the user can edit the form control.
	 */
	public var readOnly(get_readOnly, set_readOnly):Bool;
	
	/**
	 * A form control that is disabled must prevent any click events
	 * that are queued on the user interaction task source
	 * from being dispatched on the element.
	 */
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * The type attribute controls the data type 
	 * (and associated control) of the element
	 */
	public var type(get_type, set_type):String;
	
	/**
	 * The name content attribute gives the name of the form control,
	 * as used in form submission and in the form element's elements object
	 */
	public var name(get_name, set_name):String;
	
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
		
		//initialise max length of input
		var maxLength:Int = get_maxLength();
		if (maxLength != -1)
		{
			textInputElementRenderer.maxLength = maxLength;
		}
		
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
	
	/**
	 * When max length updated, update also
	 * on the native text input
	 */
	private function set_maxLength(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_MAXLENGTH_ATTRIBUTE_NAME, Std.string(value));
		
		if (elementRenderer != null)
		{
			var textInputElementRenderer:TextInputRenderer = cast(elementRenderer);
			textInputElementRenderer.maxLength = value;
		}
		
		return value;
	}
	
	private function get_maxLength():Int
	{
		return getAttributeAsPositiveSignedInteger(HTMLConstants.HTML_MAXLENGTH_ATTRIBUTE_NAME, null);
	}
	
	private function get_checked():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_CHECKED_ATTRIBUTE_NAME);
	}
	
	private function set_checked(value:Bool):Bool
	{
		setAttributeAsBool(HTMLConstants.HTML_CHECKED_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_readOnly():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_READ_ONLY_ATTRIBUTE_NAME);
	}
	
	private function set_readOnly(value:Bool):Bool
	{
		setAttributeAsBool(HTMLConstants.HTML_READ_ONLY_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_disabled():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME);
	}
	
	private function set_disabled(value:Bool):Bool
	{
		setAttributeAsBool(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_type():String
	{
		return type;
	}
	
	private function set_type(value:String):String
	{
		return value;
	}
	
	private function get_name():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME);
	}
	
	private function set_name(value:String):String
	{
		setAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME, value);
		return value;
	}
}