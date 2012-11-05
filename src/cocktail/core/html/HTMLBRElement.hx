package cocktail.core.html;

/**
 * The HTML Line Break element (<br>) produces a line break in text (carriage-return).
 * It is useful for writing a poem or an address, where the division of lines is significant.
 * Usage note: This attribute is obsolete in HTML5 and should not be used by authors.
 * @author Thomas Fétiveau
 */
class HTMLBRElement extends EmbeddedElement
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR AND INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_BR_TAG_NAME);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as <br> element are serialised
	 * as self-closing tags
	 */
	override public function isVoidElement():Bool
	{
		return true;
	}
}