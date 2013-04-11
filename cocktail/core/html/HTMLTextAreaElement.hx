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
import cocktail.core.renderer.InputRenderer;
import cocktail.core.renderer.TextAreaRenderer;

/**
 * The textarea element represents a multiline plain text edit control for the element's raw value.
 * The contents of the control represent the control's default value.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLTextAreaElement extends FormAssociatedElement
{
	/**
	 * A textarea element has a dirty value flag, which must be 
	 * initially set to false, and must be set to true
	 * whenever the user interacts with the
	 * control in a way that changes the raw value.
	 */
	private var _valueIsDirty:Bool;
	
	/**
	 * the current raw value of the 
	 * text area control
	 */
	private var _rawValue:String;
	
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
	 *	return the text area type
	 */
	public var type(get_type, null):String;
	
	
	
	public function new() 
	{
		super(HTMLConstants.HTML_TEXT_AREA_TAG_NAME);
		
		_valueIsDirty = false;
		_rawValue = "";
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
		
		elementRenderer = new TextAreaRenderer(this);
		
		if (_valueIsDirty == false)
		{
			_rawValue = textContent;
		}
		
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
		_rawValue = inputRenderer.value;
		
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
			inputRenderer.value = value;
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
		_rawValue = value;
		updateInputRendererState();
		
		return value;
	}
	
	private function get_value():String
	{
		//TODO : value normalization
		return _rawValue;
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
		return HTMLConstants.INPUT_TEXT_AREA;
	}
}