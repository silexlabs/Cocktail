/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;

/**
 * The textarea element represents a multiline plain text edit control for the element's raw value.
 * The contents of the control represent the control's default value.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLTextAreaElement extends FormAssociatedElement
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	 * The readonly attribute is a boolean attribute that controls
	 * whether or not the user can edit the form control.
	 */
	public var readOnly(get_readonly, set_readonly):Bool;
	
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
	public var type(get_type, null):String;
	
	public function new() 
	{
		super(HTMLConstants.HTML_TEXT_AREA_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN EVENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to focus or blur native text area
	 * when needed
	 */
	override public function dispatchEvent(evt:Event):Bool
	{
		var defaultPrevented:Bool = super.dispatchEvent(evt);
		
		if (elementRenderer != null)
		{
			if (evt.type == EventConstants.FOCUS)
			{
				//TODO : focus text are renderer
			}
			else if (evt.type == EventConstants.BLUR)
			{
				//TODO : blur texyt area
			}
		}
		
		return defaultPrevented;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate an input specific renderer if needed (for instance
	 * hidden input don't render)
	 */
	override private function createElementRenderer():Void
	{
		//TODO : instantiate text area renderer
		
		//listen to event from native input and set its model
		if (elementRenderer != null)
		{
			var inputRenderer:InputRenderer = cast(elementRenderer);
			inputRenderer.onInput = onUserInput;
			
			updateInputRendererState();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * a text area is focusable unless 
	 */
	override private function isDefaultFocusable():Bool
	{
		//not focusable if disabled
		if (disabled == true)
		{
			return false;
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// NATIVE INPUT CALLBACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when text is input by the user in the native input.
	 * Only applies to text base input such as "text"
	 * or "password"
	 */
	private function onUserInput():Void
	{
		_valueIsDirty = true;
		
		//update text value
		var inputRenderer:InputRenderer = cast(elementRenderer);
		_value = inputRenderer.value;
		
		fireEvent(EventConstants.INPUT, true, false);
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
			var inputRenderer:InputRenderer = cast(elementRenderer);
			inputRenderer.readonly = readOnly;
			inputRenderer.disabled = disabled;
			inputRenderer.maxLength = maxLength;
			inputRenderer.value = getElementRendererValue();
			inputRenderer.checked = _checkedness;
		}
	}
	
	/**
	 * mutable unless disabled or readonly
	 */
	private function isMutable():Bool
	{
		if (disabled == true || readOnly == true)
		{
			return false;
		}
		
		return true;
	}
	
	/////////////////////////////////
	// SETTER/GETTER
	/////////////////////////////////
	
	private function set_value(value:String):String
	{
		_valueIsDirty = true;
		
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
				var value:String = getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
				if (value == "")
				{
					return HTMLConstants.RADIO_OR_CHECKBOX_ON;
				}
				else
				{
					return value;
				}
				
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
	
	private function get_readonly():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_READ_ONLY_ATTRIBUTE_NAME);
	}
	
	private function set_readonly(value:Bool):Bool
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
		updateInputRendererState();
		return value;
	}
	
	private function get_type():String
	{
		return getEnumeratedAttributeAsDOMString(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, HTMLConstants.INPUT_TYPE_VALUES, HTMLConstants.INPUT_TYPE_TEXT, null);
	}
	
}