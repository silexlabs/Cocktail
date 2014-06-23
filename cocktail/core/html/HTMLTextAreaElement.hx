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
	 * get/set the raw value of the text area
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
	public var readOnly(get_readOnly, set_readOnly):Bool;
	
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
	
	/**
	 * class constructor
	 */
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
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate a text area rendered
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new TextAreaRenderer(this, coreStyle);
		
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
	// OVERRIDEN FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the text area with the textContent
	 */
	override public function reset():Void
	{
		_rawValue = textContent;

		//refresh native input
		updateInputRendererState();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * a text area is focusable unless disabled
	 */
	override private function isDefaultFocusable():Bool
	{
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
	 * Called when text is input by the user in the text area
	 */
	private function onUserInput():Void
	{
		_valueIsDirty = true;
		
		//update text area value
		var inputRenderer:InputRenderer = cast(elementRenderer);
		_rawValue = inputRenderer.value;
		
		fireEvent(EventConstants.INPUT, true, false);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Update the model of the input renderer when an attribute
	 * of this text area is changed
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
		return HTMLConstants.INPUT_TEXT_AREA;
	}
}
