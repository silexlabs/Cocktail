/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.php;

import cocktail.domElement.abstract.AbstractTextDOMElement;

/**
 * This is the JavaScript implementation for the Text DOMElement
 * 
 * It adds the JavaScript specific behaviour of setting the HTML
 * of the reference to native DOM object
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class TextDOMElement extends AbstractTextDOMElement
{
	/**
	 * class constructor
	 */
	public function new(referenceToNativeDOMElement:Dynamic) 
	{
		super(referenceToNativeDOMElement);
	}
	
	/**
	 * Set the of the reference to the native HTML tag (Xml node here)
	 * with the provided text with div encapsulation
	 * @param	text an HTML formatted text
	 */
	override public function setText(text:String):Void
	{
		// sets the text of the DOMElement
		super.setText(text);
		// adds a child Xml PCData node containing the text to _nativeElement
		this._nativeElement.addChild(Xml.createPCData(text));
	}
	
}