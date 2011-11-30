/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;
import cocktail.style.StyleData;

#if flash9
import cocktail.domElement.as3.DOMElement;
#elseif js
import cocktail.domElement.js.DOMElement;
#end

/**
 * This DOMElement represents a native text element,
 * which might be a word or a space.
 * 
 * It is not meant to be instantiated but instead it
 * is created during layout to render TextNodes
 * that were added to a ContainerDOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractTextLineDOMElement extends DOMElement
{
	/**
	 * Class constructor. Unlike other DOMElements, this
	 * DOMElement doesn't instantiate its own style, it 
	 * takes the style of the ContainerDOMElement to 
	 * which it belongs
	 * 
	 * @param nativeElement
	 * @param style a reference to the Style Object of the
	 * ContainerDOMElement owning this DOMElement (the one
	 * which has the TextNode which was used as a model
	 * to create this DOMElement)
	 */
	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement);
		this._style = style;
	}

	/**
	 * Overriden to prevent instantiating a Style object.
	 * This DOMElement instead use a Style object
	 * provided by its ContainerDOMElement.
	 */
	override private function initStyle():Void
	{
		
	}
	
}