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
import cocktail.core.http.HTTPConstants;

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
		
		//TODO : Let scheme be the <scheme> of the resulting absolute URL.
		
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
		
		//TODO : switch scheme
		if (method == HTTPConstants.GET)
		{
			mutateActionUrl(formDataSet, action);
		}
		else if (method == HTTPConstants.POST)
		{
			submitAsEntityBody(formDataSet, action, enctype);
		}
		
	}
	
	/**
	 * Used for http and https GET request, implement the following algorithm : 
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#submit-mutate-action
	 */
	private function mutateActionUrl(formDataSet:Array<FormData>, action:String):Void
	{
		var query:String = encodeAsURLQuery(formDataSet);
		
		//TODO : Let destination be a new URL that is equal to the action except
		//that its <query> component is replaced by query (adding a "?" (U+003F) character if appropriate).
		
		//TODO : Navigate target browsing context to destination. If replace is true, 
		//then target browsing context must be navigated with replacement enabled.
	}
	
	/**
	 * Used for http and https POST request, implement the following algorithm : 
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#submit-body
	 */
	private function submitAsEntityBody(formDataSet:Array<FormData>, action:String, enctype:String) 
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
		return getAttributeAsDOMString(HTMLConstants.HTML_ACTION_ATTRIBUTE_NAME);
	}
	
	/**
	 * Return the encoding to use for submitting
	 * 
	 * TODO : same as above
	 */
	private function getSubmitEnctype(submitter:HTMLElement):String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_ENCTYPE_ATTRIBUTE_NAME);
	}
	
	/**
	 * Return the method to use for submitting
	 * 
	 * TODO : same as above
	 */
	private function getSubmitMethod(submitter:HTMLElement):String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_METHOD_ATTRIBUTE_NAME);
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