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
import cocktail.core.html.HTMLData;

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
	 * This var keeps track of the native input
	 * value, it is separate from the value attribute
	 * of this node.
	 * 
	 * For instance if the input is a text input with
	 * a "value" attribute with the value "default", 
	 * at first _value will be "default" but as soon as the
	 * user input or delete text, it will be changed to the text field
	 * content, whereas the "value" attribute of the node remains "default"
	 */
	private var _value:String;
	
	/**
	 * the current mode of the "value" attribute, 
	 * based on the current input type
	 */
	private var _valueMode:ValueModeValue;
	
	/**
	 * The dirty value flag must be initially set to false when
	 * the element is created, and must be set to true whenever 
	 * the user interacts with the control in a way that changes the
	 * value. It is also set to true when the value is programmatically changed
	 */
	private var _valueIsDirty:Bool;
	
	/**
	 *  The dirty checkedness flag must be initially set 
	 * to false when the element is created, and must be set to 
	 * true whenever the user interacts with the control in 
	 * a way that changes the checkedness.
	 */
	private var _checkednessIsDirty:Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_INPUT_TAG_NAME);
		
		_valueIsDirty = false;
		_checkednessIsDirty = false;
		_valueMode = ValueModeValue.VALUE;
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
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_TEXT:
				elementRenderer = new TextInputRenderer(this);
				
			default:	
		}
		
		//TODO : should set callback for native input and activation
		//event
		
		updateInputRendererState();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
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
	
	//TODO : should bary based on input type, should be provided by
	//native input through elment renderer for som input types
	override private function get_intrinsicWidth():Null<Float> 
	{
		return HTML_INPUT_TEXT_INTRINSIC_WIDTH;
	}
	
	override private function get_intrinsicHeight():Null<Float> 
	{
		return HTML_INPUT_TEXT_INTRINSIC_HEIGHT;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the model of the input renderer when an attribute
	 * of this input element is changed
	 */
	private function updateInputRendererState():Void
	{
		if (elementRenderer != null)
		{
			//TODO : should update all the states of the input
			//(value, checkedness, disabled...), change based on type, for isntance
			//if radio, check if should be selected or not ? -> no, for radio, should be
			//set as soon as value change ?
		}
	}
	
	/**
	 * Called after the type attribute value
	 * changed, perform all actions required
	 * by an input type change
	 * 
	 * @param oldType the input type before the type change.
	 * The new type is held by the type attribute
	 */
	private function updateInputType(oldType:String):Void
	{
		//TODO : update valueMode
		//TODO : update checkedness ?
		//TODO : update value ?
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// NATIVE INPUT CALLBACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the native input is "activated" by the user.
	 * Activated is used as a more generic name for 
	 * clicked, touched or any other form of user input
	 * 
	 * Behaviour will vary based on the type of input
	 */
	private function onUserActivation():Void
	{
		//TODO : based on type, may submit form, set checkedness, 
		//select a radio button
	}
	
	/**
	 * Called when text is input by the user in the native input.
	 * Only applies to text base input such as "text"
	 * or "password"
	 */
	private function onUserInput():Void
	{
		//TODO : dispatch an input event
	}
	
	/////////////////////////////////
	// SETTER/GETTER
	/////////////////////////////////
	
	
	private function set_value(value:String):String
	{
		switch(_valueMode)
		{
			case ValueModeValue.VALUE:
				_value = value;
				
			case ValueModeValue.DEFAULT, ValueModeValue.DEFAULT_ON:
				setAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME, value);
				
			case ValueModeValue.FILENAME:	
				//TODO : On setting, if the new value is the empty string,
				//it must empty the list of selected files; otherwise,
				//it must throw an InvalidStateError exception.
		}
		
		return value;
	}
	
	private function get_value():String
	{
		switch(_valueMode)
		{
			case ValueModeValue.VALUE:
				return _value;
				
			case ValueModeValue.DEFAULT:
				return getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
				
			case ValueModeValue.DEFAULT_ON:
				return getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
				//TODO : On getting, if the element has a value attribute,
				//it must return that attribute's value; otherwise, it must return the string "on"
				
			case ValueModeValue.FILENAME:	
				return ""; 
				//TODO : On getting, it must return the string "C:\fakepath\"
				//followed by the filename of the first file in the list of selected
				//files, if any, or the empty string if the list is empty.
		}
	}
	
	private function set_maxLength(value:Int):Int
	{
		setAttribute(HTMLConstants.HTML_MAXLENGTH_ATTRIBUTE_NAME, Std.string(value));
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
		return getEnumeratedAttributeAsDOMString(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, HTMLConstants.INPUT_TYPE_VALUES, HTMLConstants.INPUT_TYPE_TEXT, null);
	}
	
	private function set_type(value:String):String
	{
		var oldType:String = type;
		setAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, value);
		updateInputType(oldType);
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