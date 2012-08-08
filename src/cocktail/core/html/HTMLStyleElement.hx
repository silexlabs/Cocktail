package cocktail.core.html;

/**
 * The style element allows authors to embed style information in their documents.
 * The style element is one of several inputs to the styling processing model.
 * The element does not represent content for the user.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLStyleElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public var disabled(get_disabled, set_disabled):Bool;
	
	public function new() 
	{
		super(HTMLConstants.HTML_STYLE_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_disabled():Bool
	{
		if (getAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private function set_disabled(value:Bool):Bool
	{
		super.setAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
}