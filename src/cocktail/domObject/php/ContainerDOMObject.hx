/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domObject.php;

import cocktail.domObject.base.ContainerDOMObjectBase;

/**
 * This is the PHP implementation of the container DOMObject.
 * 
 * When its semantic is set, it adds the PHP specific behaviour
 * of changing the root node type of the reference to the native DOM
 * by setting it's name
 * 
 * @author Raphael HARMEL
 */
class ContainerDOMObject extends ContainerDOMObjectBase
{
	/**
	 * class constructor
	 */
	public function new(referenceToNativeDOMObject:Dynamic) 
	{
		super(referenceToNativeDOMObject);
	}
	
	/**
	 * Set the semantic of this DOMObject and set it as the node name
	 * of the root tag of the native DOMObject (which is an HTML tag)
	 * @param	semantic the new node name
	 */
	override public function setSemantic(semantic:String):Void
	{
		super.setSemantic(semantic);
		
		//TODO
		//trace(this._nativeReference);
	}
}