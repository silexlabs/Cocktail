/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.event.EventConstants;
import cocktail.core.html.HTMLData;
import cocktail.core.http.HTTPConstants;
import cocktail.url.URL;

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
	
	/**
	 * A flag determining when the form is submitted
	 * wether it was programmativcally (true) or
	 * the result of a user action
	 */
	private var _submittedFromSubmitMethod:Bool;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * http method to use when submitting, defaults to 
	 * GET
	 */
	public var method(get_method, set_method):String;
	
	/**
	 * encoding type used to submit data, 
	 * default to url encoded
	 */
	public var enctype(get_enctype, set_enctype):String;
	
	/**
	 * contains the URL where to submit the form
	 */
	public var action(get_action, set_action):String;
	
	public function new() 
	{
		super(HTMLConstants.HTML_FORM_TAG_NAME);
		elements = new Array<HTMLElement>();
		_submittedFromSubmitMethod = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC FORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Submits the form.
	 * Called when the form is
	 * submitted programmatically
	 */
	public function submit():Void
	{
		_submittedFromSubmitMethod = true;
		doSubmit(null);
	}
	
	/**
	 * Submit the form form a provided submit button, 
	 * activated by the user
	 */
	public function submitFrom(submitter:HTMLElement):Void 
	{
		_submittedFromSubmitMethod = false;
		doSubmit(submitter);
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
	 * Actually submit the form, this is an 
	 * implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#form-submission-algorithm
	 */
	private function doSubmit(submitter:HTMLElement):Void
	{
		
		//TODO : If form is already being submitted (i.e. the form was submitted again
		//while processing the events fired from the next two steps, probably from a 
		//script redundantly calling the submit() method on form), then abort these steps.
		//This doesn't affect the earlier instance of this algorithm.
		
		//TODO : If the submitted from submit() method flag is not set, and the submitter
		//element's no-validate state is false, then interactively validate the constraints
		//of form and examine the result: if the result is negative (the constraint validation
		//concluded that there were invalid fields and probably informed the user of this)
		//then abort these steps.
		
		if (_submittedFromSubmitMethod == false)
		{
			var defaultPrevented:Bool = fireEvent(EventConstants.SUBMIT, false, true);
			if (defaultPrevented == true)
			{
				return;
			}
		}
		
		var formDataSet:Array<FormData> = constructFormDataSet(submitter);
	
		var action:String = getSubmitAction(submitter);
		
		//TODO : If action is the empty string, let action be the document's address of the form document.
		
		var scheme:String = URL.fromString(action).scheme;
		
		var enctype:String = getSubmitEnctype(submitter);
		
		var method:String = getSubmitMethod(submitter);
		
		var target:String = getSubmitTarget(submitter);
		
		//TODO : If the user indicated a specific browsing context to use when submitting the form, 
		//then let target browsing context be that browsing context. Otherwise, apply the rules
		//for choosing a browsing context given a browsing context name using target as the name 
		//and form browsing context as the context in which the algorithm is executed, and let
		//target browsing context be the resulting browsing context.
		
		//TODO : If target browsing context was created in the previous step,
		//or if the form document has not yet completely loaded,
		//then let replace be true. Otherwise, let it be false.
		
		//TODO : only http for now
		
		//if action empty, default to GET
		if (action != "")
		{
			switch(scheme)
			{
				case HTTPConstants.HTTP:
					if (method.toUpperCase() == HTTPConstants.GET)
					{
						mutateActionUrl(formDataSet, action);
					}
					else if (method.toUpperCase() == HTTPConstants.POST)
					{
						submitAsEntityBody(formDataSet, action, enctype);
					}
			}
		}
		else
		{
			mutateActionUrl(formDataSet, action);
		}
	}
	
	/**
	 * Used for http and https GET request, implement the following algorithm : 
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#submit-mutate-action
	 */
	private function mutateActionUrl(formDataSet:Array<FormData>, action:String):Void
	{
		var query:String = encodeAsURLQuery(formDataSet);
		
		//replace query string
		var actionURL:URL = URL.fromString(action);
		actionURL.query = query;
		var destination:String = URL.toString(actionURL);
		
		_ownerHTMLDocument.navigateToURL(destination);
	}
	
	/**
	 * Used for http and https POST request, implement the following algorithm : 
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#submit-body
	 */
	private function submitAsEntityBody(formDataSet:Array<FormData>, action:String, enctype:String):Void
	{
		
	}
	
	/**
	 * Encode the form data set as url query string, using the following
	 * algorithm :
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#application/x-www-form-urlencoded-encoding-algorithm
	 * 
	 * TODO : very crude implementation for now
	 */
	private function encodeAsURLQuery(formDataSet:Array<FormData>):String
	{
		var result:String = "";
		
		var length:Int = formDataSet.length;
		for (i in 0...length)
		{
			if (result != "")
			{
				result += "&";
			}
			
			var formData:FormData = formDataSet[i];
			result += StringTools.urlEncode(formData.name) + "=" + StringTools.urlEncode(formData.value);
		}
		
		return result;
	}
	
	/**
	 * Return the action to use to submit based on the
	 * form submitter
	 * 
	 * TODO : for now only use form's action, should use
	 * formaction from submitter if provided
	 */
	private function getSubmitAction(submitter:HTMLElement):String
	{
		return action;
	}
	
	/**
	 * Return the encoding to use for submitting
	 * 
	 * TODO : same as above
	 */
	private function getSubmitEnctype(submitter:HTMLElement):String
	{
		return enctype;
	}
	
	/**
	 * Return the method to use for submitting
	 * 
	 * TODO : same as above
	 */
	private function getSubmitMethod(submitter:HTMLElement):String
	{
		var formMethod:String = method;
		
		//TODO : should default to GET as no missing default value provided ?
		//seems to match browser implementation
		if (formMethod == "")
		{
			formMethod = HTTPConstants.GET;
		}
		
		return formMethod;
	}
	
	/**
	 * Return the target to use for submitting
	 * 
	 * TODO : same as above
	 */
	private function getSubmitTarget(submitter:HTMLElement):String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME);
	}
	
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
					var inputElement:HTMLInputElement = cast(submittableElement);
					var value:String = inputElement.value;
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
		var child:HTMLElement = cast(rootElement.firstChild);
		while (child != null)
		{
			switch(child.tagName)
			{
				case HTMLConstants.HTML_INPUT_TAG_NAME, 
				HTMLConstants.HTML_OBJECT_TAG_NAME, HTMLConstants.HTML_TEXT_AREA_TAG_NAME:
					submittableElements.push(child);
			}
			
			getSubmittablesElements(child, submittableElements);
			child = cast(child.nextSibling);
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
		if (element.getAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME) != null)
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
		
		if (getElementType(element) != HTMLConstants.INPUT_TYPE_IMAGE)
		{
			if (element.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) == null ||
			element.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) == "")
			{
				return false;
			}
		}
		
		if (element.tagName == HTMLConstants.HTML_OBJECT_TAG_NAME)
		{
			var objectElement:HTMLObjectElement = cast(element);
			if (objectElement.plugin == null)
			{
				return false;
			}
		}
		
		//text area
		if (element.tagName == HTMLConstants.HTML_TEXT_AREA_TAG_NAME)
		{
			if (element.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) == null ||
			element.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME) == "")
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
				
			case HTMLConstants.HTML_TEXT_AREA_TAG_NAME:
				var textAreaElement:HTMLTextAreaElement = cast(element);
				return textAreaElement.value;
				
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
	
	private function get_method():String
	{
		return getEnumeratedAttributeAsDOMString(HTMLConstants.HTML_METHOD_ATTRIBUTE_NAME, HTTPConstants.getFormSubmitMethods(), 
		null, HTTPConstants.GET);
	}
	
	private function set_method(value:String):String
	{
		setAttribute(HTMLConstants.HTML_METHOD_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_enctype():String
	{
		return getEnumeratedAttributeAsDOMString(HTMLConstants.HTML_ENCTYPE_ATTRIBUTE_NAME, HTTPConstants.getFormEncodings(), 
		null, HTTPConstants.URL_ENCODING);
	}
	
	private function set_enctype(value:String):String
	{
		setAttribute(HTMLConstants.HTML_ENCTYPE_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_action():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_ACTION_ATTRIBUTE_NAME);
	}
	
	private function set_action(value:String):String
	{
		setAttribute(HTMLConstants.HTML_ACTION_ATTRIBUTE_NAME, value);
		return value;
	}
}
