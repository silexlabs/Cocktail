/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.css.CascadeManager;
import cocktail.core.css.CoreStyle;
import cocktail.core.renderer.BodyBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.TextRenderer;

/**
 * The HTML document body. This element is always present
 * in the DOM API, even if the tags are not present in the source document.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLBodyElement extends HTMLElement
{
	/**
	 * class constructor.
	 */
	public function new() 
	{	
		super(HTMLConstants.HTML_BODY_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The HTMLBodyElement has its own block box subclass
	 */
	override private function createElementRenderer():Void
	{ 
		elementRenderer = new BodyBoxRenderer(this, coreStyle);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE CASCADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as once the HTML's body styles are computed, the computed
	 * values of the overflow styles might propagate to the HTML html root
	 * element
	 * 
	 * TODO 3 : is this the right place to do this or should it just happen in ElementRenderer ?
	 */
	override private function cascadeSelf(cascadeManager:CascadeManager, programmaticChange:Bool):Void
	{
		super.cascadeSelf(cascadeManager, programmaticChange);
		
		var parent:HTMLElement = cast(parentNode);
		var parentCoreStyle:CoreStyle = parent.coreStyle;
		
		//if the parent (the HTML root element) has a value of visible
		//for overflow-x, it takes the value of the body element
		if (parentCoreStyle.computedValues.overflowX != null)
		{
			switch(parentCoreStyle.getKeyword(parentCoreStyle.overflowX))
			{
				case VISIBLE:
					parentCoreStyle.computedValues.overflowX = coreStyle.computedValues.overflowX;
					
				default:	
			}
		}
		
		//same for overflow-y
		if (parentCoreStyle.computedValues.overflowY != null)
		{
			switch(parentCoreStyle.getKeyword(parentCoreStyle.overflowY))
			{
				case VISIBLE:
					parentCoreStyle.computedValues.overflowY = coreStyle.computedValues.overflowY;
					
				default:	
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN COORDS SETTERS/GETTERS
	// Setters/Getters for an HTMLElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The body don't have an offset parent
	 */
	override private function get_offsetParent():HTMLElement
	{
		return null;
	}
	
	/**
	 * The body don't have an offset top
	 */
	override private function get_offsetTop():Int
	{
		return 0;
	}
	
	/**
	 * The body don't have an offset left
	 */
	override private function get_offsetLeft():Int
	{
		return 0;
	}
}
