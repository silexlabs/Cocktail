/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.php;

import cocktail.domElement.abstract.AbstractContainerDOMElement;

/**
 * This is the PHP implementation of the container DOMElement.
 * 
 * When its semantic is set, it adds the PHP specific behaviour
 * of changing the root node type of the reference to the native DOM
 * by setting it's name
 * 
 * @author Raphael HARMEL
 */
class ContainerDOMElement extends AbstractContainerDOMElement
{
	/**
	 * class constructor
	 */
	public function new(referenceToNativeDOMElement:Dynamic) 
	{
		super(referenceToNativeDOMElement);
	}
	
	/**
	 * Set the semantic of this DOMElement and set it as the node name
	 * of the root tag of the native DOMElement (which is an HTML tag)
	 * @param	semantic the new node name
	 */
	override public function setSemantic(semantic:String):Void
	{
		super.setSemantic(semantic);
		
		//TODO
		//trace(this._nativeElement);
	}
}