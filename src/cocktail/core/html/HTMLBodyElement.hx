/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
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
		elementRenderer = new BodyBoxRenderer(this);
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
	override private function cascadeSelf(parentChangedProperties:Hash<Void>, programmaticChange:Bool):Hash<Void>
	{
		var changedProperties:Hash<Void> = super.cascadeSelf(parentChangedProperties, programmaticChange);
		
		var parentCoreStyle:CoreStyle = parentNode.coreStyle;
		
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
		
		return changedProperties;
	}
}