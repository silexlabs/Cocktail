/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

/**
 * A base for elements which are associated with a
 * form, such as <input> or <textarea>, it deals
 * with associating the node with a form
 * 
 * @author Yannick DOMINGUEZ
 */
class FormAssociatedElement extends EmbeddedElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the element's form owner.
	 * Returns null if there isn't one.
	 */
	public var form(default, null):HTMLFormElement;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String) 
	{
		super(tagName);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE DOM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Should update form owner when appended
	 * to a node
	 */
	override private function appended():Void
	{
		super.appended();
		resetFormOwner();
	}
	
	/**
	 * Should update the form owner when
	 * removed from a node
	 */
	override private function removed():Void
	{
		super.removed();
		resetFormOwner();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Associate this input with its
	 * form owner if any.
	 * 
	 * This is an implementatio of the following
	 * algorithm :
	 * http://www.w3.org/TR/2012/CR-html5-20121217/forms.html#reset-the-form-owner
	 * 
	 * TODO : incomplete implementation, doesn't
	 * implement form attribute
	 */
	private function resetFormOwner():Void
	{
		var firstFormAncestor:HTMLFormElement = getFirstFormAncestor();
		
		//do nothing, if already associated or if both
		//are null
		if (firstFormAncestor == form)
		{
			return;
		}
		
		//dissociate from previous form if any
		if (form != null)
		{
			dissociateFormElement(form);
			form = null;
		}
		
		//associate with new form if any
		if (firstFormAncestor != null)
		{
			form = firstFormAncestor;
			associateFormElement(form);
		}
	}
	
	/**
	 * Return the first form element ancestor
	 * of this input or null if there is
	 * no such ancestor
	 */
	private function getFirstFormAncestor():HTMLFormElement
	{
		var parent:HTMLElement = parentNode;
		while (parent != null)
		{
			if (parent.tagName == HTMLConstants.HTML_FORM_TAG_NAME)
			{
				return cast(parent);
			}
			parent = parent.parentNode;
		}
		
		return null;
	}
	
	/**
	 * associate this input with the provided form element
	 */
	private function associateFormElement(form:HTMLFormElement):Void
	{
		form.elements.push(this);
	}
	
	/**
	 * dissociate this input from the provided form element
	 */
	private function dissociateFormElement(form:HTMLFormElement):Void
	{
		form.elements.remove(this);
	}
}