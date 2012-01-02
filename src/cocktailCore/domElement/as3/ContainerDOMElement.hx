/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.nativeElement.NativeElement;
import cocktailCore.domElement.abstract.AbstractContainerDOMElement;
import cocktail.style.StyleData;

import flash.Vector;
import haxe.Log;


/**
 * This is the Flash AS3 implementation of the container DOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerDOMElement extends AbstractContainerDOMElement
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Override public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to add the native flash display object as a 
	 * child of the native display object of this container
	 * @param domElement the flash display object to add to this 
	 * container
	 */
	override public function addChild(domElement:DOMElement):Void
	{
		super.addChild(domElement);
		this._nativeElement.addChild(domElement.nativeElement);
	}
	
	/**
	 * Overriden to remove the native flash display object from
	 * the native display object of this container
	 * @param domElement the flash display object to remove from
	 * this container
	 */
	override public function removeChild(domElement:DOMElement):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN TEXT FRAGMENT MANAGEMENT methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach the native flash TextLine object to this DOMElement native DisplayObjectContainer
	 */
	override public function addTextFragment(textFragmentDOMElement:TextFragmentDOMElement):Void
	{
		super.addTextFragment(textFragmentDOMElement);
		this._nativeElement.addChild(textFragmentDOMElement.nativeElement);
	}
	
	/**
	 * Removes the native flash TextLine object from this DOMElement native DisplayObjectContainer
	 */
	override private function removeTextFragment(textFragmentDOMElement:TextFragmentDOMElement):Void
	{		
		super.removeTextFragment(textFragmentDOMElement);
		this._nativeElement.removeChild(textFragmentDOMElement.nativeElement);
	}
	
}