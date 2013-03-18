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
	// IDL SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_length():Int
	{
		return elements.length;
	}
	
}