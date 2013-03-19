/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.event.EventConstants;
import cocktail.core.html.HTMLData;

/**
 * The form element represents a collection of form-associated elements, 
 * some of which can represent editable values that can be submitted 
 * to a server for processing.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLFormElement extends HTMLElement
{

	/**
	 * The elements IDL attribute must return an HTMLFormControlsCollection 
	 * rooted at the Document node while the form element is in a Document 
	 * and rooted at the form element itself when it is not,
	 * whose filter matches listed elements whose form owner
	 * is the form element, with the exception of input elements
	 * whose type attribute is in the Image Button state, 
	 * which must, for historical reasons, be excluded from
	 * this particular collection.
	 * 
	 * TODO 4 : not implemented as an HTMLCollection
	 */
	public var elements(default, null):Array<HTMLElement>;
	
	/**
	 * The length IDL attribute must return the number 
	 * of nodes represented by the elements collection.
	 */
	public var length(get_length, null):Int;
	
	public function new() 
	{
		super(HTMLConstants.HTML_FORM_TAG_NAME);
		elements = new Array<HTMLElement>();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Submits the form.
	 */
	public function submit():Void
	{
		//TODO : implement
	}
	
	/**
	 * Resets the form.
	 */
	override public function reset():Void
	{
		var defaultPrevented:Bool = fireEvent(EventConstants.RESET, false, true);
		
		//reset was canceled
		if (defaultPrevented == true)
		{
			return;
		}
		
		//reset all form elements
		for (i in 0...length)
		{
			elements[i].reset();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Build and return the form data set to be submitted,
	 * this is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#constructing-the-form-data-set
	 * 
	 * @param submitter the submit button or input of type submit which submitted the form,
	 * might be null if submitted byb script
	 * 
	 * TODO : will need to be completed as new types of submittable elements are supported
	 */
	private function constructFormDataSet(submitter:HTMLElement):Array<FormData>
	{
		var submittableElements:Array<HTMLElement> = getSubmittablesElements(this, new Array<HTMLElement>());
		var formDataSet:Array<FormData> = new Array<FormData>();
		
		var length:Int = submittableElements.length;
		for (i in 0...length)
		{
			var submittableElement:HTMLElement = submittableElements[i];
			if (canBeSubmitted(submittableElement, submitter) == true)
			{
				var type:String = getElementType(submittableElement);
				
				//TODO : If the field element is an input element whose type attribute is in the Image Button state, then run these further nested substeps...
				
				var name:String = submittableElement.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME);
				
				if (submittableElement.tagName == HTMLConstants.HTML_SELECT_TAG_NAME)
				{
					//TODO : If the field element is a select element...
				}
				else if (submittableElement.tagName == HTMLConstants.HTML_INPUT_TAG_NAME && 
				(type == HTMLConstants.INPUT_TYPE_CHECKBOX || type == HTMLConstants.INPUT_TYPE_RADIO))
				{
					var value:String = submittableElement.getAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
					if (value == "")
					{
						value = HTMLConstants.RADIO_OR_CHECKBOX_ON;
					}
					
					formDataSet.push( { name:name, type:type, value:value } );
				}
				else if (submittableElement.tagName == HTMLConstants.HTML_INPUT_TAG_NAME && 
				type == HTMLConstants.INPUT_TYPE_FILE)
				{
					//TODO : Otherwise, if the field element is an input element whose type attribute is in the File Upload state...
				}
				else if (submittableElement.tagName == HTMLConstants.HTML_OBJECT_TAG_NAME)
				{
					//TODO : Otherwise, if the field element is an object element: try to obtain a form submission value from the plugin...
				}
				else 
				{
					var value:String = getElementValue(submittableElement);
					formDataSet.push( { name:name, value:value, type:type } );
				}
				
				//TODO : If the element has a form control dirname attribute...
			}
		}
		
		//TODO : End: For the name of each entry in the form data set, and for the 
		//value of each entry in the form data set whose type is not "file"
		//or "textarea", replace every occurrence of a "CR"...
		
		return formDataSet;
	}
	
	/**
	 * Return an array containing all the submittable elements
	 * descendant of this form, in tree order
	 * 
	 * TODO : some types such as textarea are not implemented yet
	 */
	private function getSubmittablesElements(rootElement:HTMLElement, submittableElements:Array<HTMLElement>):Array<HTMLElement>
	{
		var child:HTMLElement = rootElement.firstChild;
		while (child != null)
		{
			switch(child.tagName)
			{
				case HTMLConstants.HTML_INPUT_TAG_NAME, 
				HTMLConstants.HTML_OBJECT_TAG_NAME:
					submittableElements.push(child);
			}
			
			getSubmittablesElements(child, submittableElements);
			child = child.nextSibling;
		}
		
		return submittableElements;
	}
	
	/**
	 * Return wether a submittable element can actually
	 * be submitted.
	 * 
	 * This is an  implementation of a sub-part of the
	 * form algorithm
	 */
	private function canBeSubmitted(element:HTMLElement, submitter:HTMLElement):Bool
	{
		//TODO : The field element has a datalist element ancestor.
		
		//disabled
		if (element.getAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME) != "")
		{
			return false;
		}
		
		//not submitter button
		if (isButton(element) == true)
		{
			if (element != submitter)
			{
				return false;
			}
		}
		
		//not checked
		if (isUncheckedRadioOrCheckBox(element) == true)
		{
			return false;
		}
		
		//TODO : The field element is not an input element whose
		//type attribute is in the Image Button state, and either the 
		//field element does not have a name attribute specified, or its
		//name attribute's value is the empty string.
		
		//TODO : The field element is an object element that is not using a plugin.
		
		if (element.tagName == HTMLConstants.HTML_OBJECT_TAG_NAME)
		{
			var objectElement:HTMLObjectElement = cast(element);
			if (objectElement.plugin == null)
			{
				return false;
			}
		}
		
		return true;
	}
	
	/**
	 * Return wether the element is
	 * a button element or an input
	 * of type button/submit/reset
	 */
	private function isButton(element:HTMLElement):Bool
	{
		if (element.tagName == HTMLConstants.HTML_BUTTON_TAG_NAME)
		{
			return true;
		}
		else if (element.tagName == HTMLConstants.HTML_INPUT_TAG_NAME)
		{
			var inputElement:HTMLInputElement = cast(element);
			switch(inputElement.type)
			{
				case HTMLConstants.INPUT_TYPE_RESET,
				HTMLConstants.INPUT_TYPE_BUTTON,
				HTMLConstants.INPUT_TYPE_SUBMIT:
					return true;
			}
		}
		
		return false;
	}
	
	/**
	 * Return wether the element is an
	 * unchecked radio or check box
	 */
	private function isUncheckedRadioOrCheckBox(element:HTMLElement):Bool
	{
		if (element.tagName == HTMLConstants.HTML_INPUT_TAG_NAME)
		{
			var inputElement:HTMLInputElement = cast(element);
			switch(inputElement.type)
			{
				case HTMLConstants.INPUT_TYPE_RADIO, HTMLConstants.INPUT_TYPE_CHECKBOX:
					return inputElement.checked == false;
			}
			
		}
		
		return false;
	}
	
	/**
	 * Return the value of the type
	 * IDL attribute of a submittable
	 * element.
	 * 
	 * note : need to be implemented as this way,
	 * as submittable element don'tshare a common
	 * base class or interface, probably for history
	 * reason
	 * 
	 * TODO : should be completed when new submittable
	 * element, such as textarea are supported
	 */
	private function getElementType(element:HTMLElement):String
	{
		switch(element.tagName)
		{
			case HTMLConstants.HTML_INPUT_TAG_NAME:
				var inputElement:HTMLInputElement = cast(element);
				return inputElement.type;
				
			default:
				return "";
		}
	}
	
	/**
	 * Same as above for the value IDL attribute
	 */
	private function getElementValue(element:HTMLElement):String
	{
		switch(element.tagName)
		{
			case HTMLConstants.HTML_INPUT_TAG_NAME:
				var inputElement:HTMLInputElement = cast(element);
				return inputElement.value;
				
			default:
				return "";
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_length():Int
	{
		return elements.length;
	}
	
}