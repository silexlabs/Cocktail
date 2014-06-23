/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.MouseEvent;
import cocktail.core.renderer.CheckboxRenderer;
import cocktail.core.renderer.InputButtonRenderer;
import cocktail.core.renderer.InputRenderer;
import cocktail.core.renderer.PasswordInputRenderer;
import cocktail.core.renderer.RadioRenderer;
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
class HTMLInputElement extends FormAssociatedElement
{
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
	 * This var keeps track of the native input current checkedness, it is
	 * separate from the checked attribute in the same way that
	 * _value is different from the value attribute
	 */
	private var _checkedness:Bool;
	
	/**
	 *  The dirty checkedness flag must be initially set 
	 * to false when the element is created, and must be set to 
	 * true whenever the user interacts with the control in 
	 * a way that changes the checkedness.
	 */
	private var _checkednessIsDirty:Bool;
	
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
		
		_valueIsDirty = false;
		_checkednessIsDirty = false;
		_valueMode = ValueModeValue.VALUE;
		_value = "";
		_checkedness = false;
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
	// OVERRIDEN EVENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to focus or blur native input
	 * when needed
	 */
	override public function dispatchEvent(evt:Event):Bool
	{
		var defaultPrevented:Bool = super.dispatchEvent(evt);
		
		if (elementRenderer != null)
		{
			if (evt.type == EventConstants.FOCUS)
			{
				var inputRenderer:InputRenderer = cast(elementRenderer);
				inputRenderer.focus();
			}
			else if (evt.type == EventConstants.BLUR)
			{
				var inputRenderer:InputRenderer = cast(elementRenderer);
				inputRenderer.blur();
			}
		}
		
		return defaultPrevented;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * perform input specific operation when
	 * some attributes are set
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		super.setAttribute(name, value);
		
		//If the "value" attribute is set, 
	    //must update the internal value of
	    //the input, is it is not dirty (changed
	    //by the user or programmatically).
		if (name == HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME)
		{
			if (_valueIsDirty == false)
			{
				_value = value;
			}
		}
		//Same for the "checked" attribute
		else if (name == HTMLConstants.HTML_CHECKED_ATTRIBUTE_NAME)
		{
			if (_checkednessIsDirty == false)
			{
				if (value == "true")
				{
					updateCheckedness(true);
				}
				else 
				{
					updateCheckedness(false);
				}
			}
		}
		//if name is changed, for radio input check if must
		//update radio button group
		else if (name == HTMLConstants.HTML_NAME_ATTRIBUTE_NAME)
		{
			if (_checkedness == true && type == HTMLConstants.INPUT_TYPE_RADIO)
			{
				updateRadioButtonGroup();
			}
		}
		//update native input rendering if disabled state is changed
		else if (name == HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME)
		{
			updateInputRendererState();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the input
	 */
	override public function reset():Void
	{
		_valueIsDirty = false;
		_checkednessIsDirty = false;
		_value = getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
		updateCheckedness(getAttributeAsBool(HTMLConstants.HTML_CHECKED_ATTRIBUTE_NAME));

		//TODO : reset list of selected files once file type implemented
		
		applyValueSanitization(value, type);

		//refresh native input
		updateInputRendererState();
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
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_TEXT:
				elementRenderer = new TextInputRenderer(this, coreStyle);
				
			case HTMLConstants.INPUT_TYPE_PASSWORD:
				elementRenderer = new PasswordInputRenderer(this, coreStyle);
				
			case HTMLConstants.INPUT_TYPE_CHECKBOX:
				elementRenderer = new CheckboxRenderer(this, coreStyle);
				
			case HTMLConstants.INPUT_TYPE_RADIO:
				elementRenderer = new RadioRenderer(this, coreStyle);
				
			case HTMLConstants.INPUT_TYPE_BUTTON,
			HTMLConstants.INPUT_TYPE_RESET,
			HTMLConstants.INPUT_TYPE_SUBMIT:
				elementRenderer = new InputButtonRenderer(this, coreStyle);
				
			default:	
		}
		
		//listen to event from native input and set its model
		if (elementRenderer != null)
		{
			var inputRenderer:InputRenderer = cast(elementRenderer);
			inputRenderer.onActivate = onUserActivation;
			inputRenderer.onInput = onUserInput;
			
			updateInputRendererState();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An html form control element is
	 * focusable in most cases
	 */
	override private function isDefaultFocusable():Bool
	{
		//not focusable if disabled
		if (disabled == true)
		{
			return false;
		}
		
		//some type of input can't be focused
		if (isFocusableType() == false)
		{
			return false;
		}
		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
		
	/**
	 * when form is set, need to update state if radio button
	 */
	override private function associateFormElement(form:HTMLFormElement):Void
	{
		super.associateFormElement(form);
		
		//if is a radio input, set all other radio input
		//to false
		if (_checkedness == true && type == HTMLConstants.INPUT_TYPE_RADIO)
		{
			updateRadioButtonGroup();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ACTIVATION BEHAVIOUR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	* most input types have activation behaviour
	*/
	override public function hasActivationBehaviour():Bool
	{
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_BUTTON, HTMLConstants.INPUT_TYPE_CHECKBOX,
			HTMLConstants.INPUT_TYPE_RADIO, HTMLConstants.INPUT_TYPE_RESET, 
			HTMLConstants.INPUT_TYPE_SUBMIT:
				return true;
			
			default:
				return false;
		}
	}
	
	/**
	 * based on input type, pre click activation vary
	 */
	override public function runPreClickActivation():Void
	{
		//no behaviour for immutable elements
		if (isMutable() == false)
		{
			return;
		}
		
		switch(type)
		{
			//invert checkedness
			case HTMLConstants.INPUT_TYPE_CHECKBOX:
				updateCheckedness(!_checkedness);
				
			//always set to true fro radio, and set all other
			//radio in the group to false
			case HTMLConstants.INPUT_TYPE_RADIO:
				updateCheckedness(true);
				
			//reset the form if has form owner
			case HTMLConstants.INPUT_TYPE_RESET:
				if (form != null)
				{
					form.reset();
				}
			
			//sumbit the form if has form owner	
			case HTMLConstants.INPUT_TYPE_SUBMIT:
				if (form != null)
				{
					form.submitFrom(this);
				}
		}
	}
	
	/**
	 * based on input type, post click activation vary
	 */
	override public function runPostClickActivationStep(event:MouseEvent):Void
	{
		//no behaviour for immutable elements
		if (isMutable() == false)
		{
			return;
		}
		
		switch(type)
		{
			//fire simple change event
			case HTMLConstants.INPUT_TYPE_CHECKBOX, HTMLConstants.INPUT_TYPE_RADIO:
				fireEvent(EventConstants.CHANGE, false, false);
		}
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
	 * Called after the type attribute value
	 * changed, perform all actions required
	 * by an input type change
	 * 
	 * This method is mostly an implementation of this algorithm :
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#input-type-change
	 * 
	 * @param oldType the input type before the type change.
	 * The new type is held by the type attribute
	 */
	private function updateInputType(oldType:String):Void
	{
		//no actual type change
		if (oldType == type)
		{
			return;
		}
		
		if (useValueMode(oldType) == true && useDefaultOrDefaultOnMode(type) == true)
		{
			if (_value != "")
			{
				setAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME, _value);
			}
		}
		else if (useValueMode(oldType) == false && useValueMode(type) == true)
		{
			_value = getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
			_valueIsDirty = false;
		}
		
		invalidateElementRenderer();
		
		_value = applyValueSanitization(_value, type);
	}
	
	/**
	 * Return wether the given
	 * input type use the "value"
	 * mode for its value
	 */
	private function useValueMode(type:String):Bool
	{	
		//TODO : implement fully
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_HIDDEN, HTMLConstants.INPUT_TYPE_CHECKBOX,
			HTMLConstants.INPUT_TYPE_RADIO:
				return false;
			
			default:
				return true;
		}
	}
	
	/**
	 * Return wether the given
	 * input type use the "default" or "default/on"
	 * mode for its value
	 */
	private function useDefaultOrDefaultOnMode(type:String):Bool
	{
		//TODO : implement fully
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_TEXT, HTMLConstants.INPUT_TYPE_PASSWORD:
				return false;
			
			default:
				return true;
		}
	} 
	
	/**
	 * Sanitize the value of the input, based
	 * on its type
	 */
	private function applyValueSanitization(value:String, type:String):String
	{
		//TODO : implement fully
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_TEXT, HTMLConstants.INPUT_TYPE_PASSWORD:
				return StringTools.replace(value, "\n", "");
		}
		
		return value;
	}
	
	/**
	 * Return wether the input
	 * is currently mutable
	 */
	private function isMutable():Bool
	{
		if (disabled == true)
		{
			return false;
		}
		else if (readonlyApplies() == true)
		{
			return readOnly == false;
		}
		
		return true;
	}
	
	/**
	 * Return wether the readonly attribute
	 * applies to the current input type
	 */
	private function readonlyApplies():Bool
	{
		//TODO : implement fully
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_TEXT, HTMLConstants.INPUT_TYPE_PASSWORD:
				return true;
				
			default:
				return false;
		}
	}
	
	/**
	 * Return wether the current type of
	 * input can be focused
	 */
	private function isFocusableType():Bool
	{
		switch(type)
		{
			case HTMLConstants.INPUT_TYPE_HIDDEN:
				return false;
				
			default:
				return true;
		}
	}
	
	/**
	 * Update checkedness of input. 
	 * 
	 * If it is a radio input, might need to
	 * also update checkedness of other radio input
	 * in the group
	 */
	private function updateCheckedness(value:Bool):Void
	{
		_checkedness = value;
		
		//style declaration must be updated as 
		//checkedness is linked to the :checked pseudo-class
		invalidateStyleDeclaration(false);
		
		//only update other radio if checkedness is true, means
		//that it is possible that no radio input in the group are
		//checked at some point
		if (_checkedness == true && type == HTMLConstants.INPUT_TYPE_RADIO)
		{
			updateRadioButtonGroup();
		}
	}
	
	/**
	 * Get all the radio input in the same radio group
	 * as this input and set their checkedness to false
	 */
	private function updateRadioButtonGroup():Void
	{
		//can't belong to a radio group with no name
		if (name == "")
		{
			return;
		}
		
		//TODO : instead of requesting from document, should be home subtree as even
		//if not inserted into document, might belong to same radio group
		var inputElements:Array<HTMLElement> = _ownerHTMLDocument.getElementsByTagName(HTMLConstants.HTML_INPUT_TAG_NAME);
		
		var inputLength:Int = inputElements.length;
		for (i in 0...inputLength)
		{
			var input:HTMLInputElement = cast(inputElements[i]);
			if (input.type == HTMLConstants.INPUT_TYPE_RADIO && input != this)
			{
				//must have either same form as this or both 
				//have null form
				if (input.form == form)
				{
					//both must have same name
					if (input.name == name)
					{
						input.checked = false;
					}
				}
			}
		}
	}
	
	/**
	 * return the "value" that should be provided to
	 * the element renderer of the input, varies based
	 * on the type of the input
	 */
	private function getElementRendererValue():String
	{
		switch(type)
		{
			//reset and submit buttons use the value attribute as label or
			//a default if no value is provided
			case HTMLConstants.INPUT_TYPE_RESET, HTMLConstants.INPUT_TYPE_SUBMIT:
				var valueAttribute:String = getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
				if (valueAttribute == null)
				{
					if (type == HTMLConstants.INPUT_TYPE_RESET)
					{
						return HTMLConstants.INPUT_RESET_LABEL;
					}
					else
					{
						return HTMLConstants.INPUT_SUBMIT_LABEL;
					}
				}
		}
		
		//in other cases, use the current value
		return value;
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
		triggerActivationBehaviour();
	}
	
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
	
	/////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	/////////////////////////////////
	
	override private function get_intrinsicWidth():Null<Float> 
	{
		if (elementRenderer != null)
		{
			var inputRenderer:InputRenderer = cast(elementRenderer);
			return inputRenderer.intrinsicWidth;
		}
		
		return 0;
	}
	
	override private function get_intrinsicHeight():Null<Float> 
	{
		if (elementRenderer != null)
		{
			var inputRenderer:InputRenderer = cast(elementRenderer);
			return inputRenderer.intrinsicHeight;
		}
		
		return 0;
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
                updateInputRendererState();
				
			case ValueModeValue.DEFAULT, ValueModeValue.DEFAULT_ON:
				setAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME, value);
                updateInputRendererState();
				
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
	
	private function get_checked():Bool
	{
		return _checkedness;
	}
	
	private function set_checked(value:Bool):Bool
	{
		_checkednessIsDirty = true;
		updateCheckedness(value);
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
		updateInputRendererState();
		return value;
	}
	
	private function get_type():String
	{
		return getEnumeratedAttributeAsDOMString(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, HTMLConstants.getInputTypeValues(), HTMLConstants.INPUT_TYPE_TEXT, null);
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
