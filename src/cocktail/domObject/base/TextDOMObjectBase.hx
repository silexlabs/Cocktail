/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domObject.base;
import cocktail.domObject.DOMObject;
import cocktail.nativeReference.NativeReference;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.nativeReference.NativeReferenceData;

/**
 * This is a DOMObject in charge of displaying an 
 * HTML text
 * 
 * @author Yannick DOMINGUEZ
 */
class TextDOMObjectBase extends DOMObject
{

	/**
	 * Stores the HTML text displaying by this DOMObject
	 */
	private var _text:String;
	public var text(getText, setText):String;
	
	/**
	 * class contructor
	 */
	public function new(nativeReference:NativeReference = null)
	{
		//create a text native reference if none is provided
		if (nativeReference == null)
		{
			nativeReference = NativeReferenceManager.createNativeReference(NativeReferenceTypeValue.text);
		}
		
		super(nativeReference);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden hierarchy methods
	// The addChild and removeChild method are not implemented for this 
	// DOMObject, as it is a leaf DOMObject (can't have children)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function addChild(domObject:DOMObjectBase):Void
	{
		
	}
	
	override public function removeChild(domObject:DOMObjectBase):Void
	{
		
	}
	
	/**
	 * Set the HTML text displayed by this component
	 * @param	text a text formatted with HTML tags
	 */
	public function setText(text:String):String
	{
		this._text = text;
		return this._text;
	}
	
	/**
	 * Return the HTML text displayed by this component
	 * @return	text a text formatted with HTML tags
	 */
	public function getText():String
	{
		return this._text;
	}
	
}