/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.js;
import cocktail.nativeElement.NativeElement;
import js.Lib;
import js.Dom;
import cocktail.domElement.base.ContainerDOMElementBase;

/**
 * This is the JavaScript implementation of the container DOMElement.
 * 
 * When it's semantic is set, it adds the JavaScript specific behaviour
 * of changing the root node type of the reference to the native DOM
 * by setting it's name
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerDOMElement extends ContainerDOMElementBase
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	/**
	 * Set the semantic of this DOMElement and set it as the node name
	 * of the root tag of the native DOMElement (which is an HTML tag)
	 * @param	semantic the new node name
	 */
	override public function setSemantic(semantic:String):Void
	{
		super.setSemantic(semantic);
		
		//to set the new nodeName, we need to create a new element with the right nodeName
		//and replace the current node, as the nodeName attribute is read only
		
		//store the inner html of the current node, to set it later on the new node
		var currentNativeDOMContent:Dynamic = this._nativeElement.innerHTML;
		
		//store all the attributes of the current node to set them on the new node
		 var currentNativeDOMAttributes:Array<Dynamic> = untyped this._nativeElement.attributes;
		
		//create a new node with the right node name
		var newReferenceToNativeDOM:Dynamic = Lib.document.createElement(semantic);
		
		//set it's inner html to the current node inner html
		newReferenceToNativeDOM.innerHTML = currentNativeDOMContent;
		
		//paste all the attributes of the current node on the new node
		for (i in 0...currentNativeDOMAttributes.length)
		{
			newReferenceToNativeDOM.setAttribute(currentNativeDOMAttributes[i].nodeName, currentNativeDOMAttributes[i].nodeValue);
		}
		
		//replace the current node with the new node
		this._nativeElement.parentNode.replaceChild(newReferenceToNativeDOM, _nativeElement);
		
		//store a reference to the new node
		this._nativeElement = newReferenceToNativeDOM;
	}
	
}