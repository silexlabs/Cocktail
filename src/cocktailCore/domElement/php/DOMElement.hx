/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.php;


//import js.Dom;
import cocktail.domElement.abstract.AbstractDOMElement;

/**
 * This is the DOMElement implementation for PHP. 
 * It manipulates the native HTML DOM
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class DOMElement extends AbstractDOMElement
{

	/**
	 * Class constructor
	 */
	public function new(referenceToNativeDOM:Dynamic) 
	{
		super(referenceToNativeDOM);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden methods to manipulate the HTML DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Adds a native HTML DOMElement (an html element) to this DOMElement native DOMElement
	 * @param	domElement the html element to add to this
	 */
	override public function addChild(domElement:AbstractDOMElement):Void
	{
		super.addChild(domElement);
		this._nativeElement.addChild(domElement.getReferenceToNativeDOM());
	}
	
	/**
	 * Removes a native HTML DOMElement (an html element) from this DOMElement native DOMElement
	 * @param	domElement the html element to remove from this
	 */
	/*override public function removeChild(domElement:AbstractDOMElement):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.getReferenceToNativeDOM());
	}*/
	
	/**
	 * Return the value of a field of the native object
	 * @param	propertyName the name of the field value to return
	 * @return might be any type
	 */
	override public function getField(propertyName:String):Dynamic
	{
		//return Reflect.field(this._nativeElement, propertyName);
		return this._nativeElement.get(propertyName);
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Setters/Getters to manipulate the JavaScript DOMElement
	// set/get the following attributes : x,y,width,height,z-order
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	override public function setX(value:Int):Void 
	{
		
	}
	
	override public function getX():Int 
	{
	
		return 0;
	}
	
	override public function setY(value:Int):Void 
	{
		
	}
	
	override public function getY():Int 
	{
		
		return 0;
	}
	
	override public function setWidth(value:Int):Void
	{
		
	}
	
	override public function getWidth():Int 
	{
		
		return 0;
	}
	
	override public function setHeight(value:Int):Void 
	{
		
	}
	
	override public function getHeight():Int 
	{
	
		return 0;
	}
	
	/**
	 * Set rotation of the html element.
	 * @param	value the rotation angle in deg
	 */
	override public function setRotation(value:Int):Void
	{
		
	}
	
	/**
	 * When returning the rotation, the rotation value must be extracted from
	 * the CSS style
	 * @return the rotation in deg
	 */
	override public function getRotation():Int
	{
		
		return 0;
	}
	
	/**
	 * When setting the z-order on an HTML element,
	 * all the siblings z-indexes must be updated. If they
	 * are superior or equal to the z-index set on the current element,
	 * they are incremented
	 * @param	value the z index to set
	 */
	override public function setZIndex(value:Int) 
	{
		
	}
	
	override public function getZIndex():Int 
	{
		
		return 0;
	}
	
	/**
	 * This method create/updates the style of the div with given parameters
	 * The resulting attribute will be as follows:
	 *   style="x:100;y:200;z-index=5"
	 * 
	 * @param	property
	 * @param	value
	 */
	private function setStyle(property:String, value:String):Void
	{
		
		// styleHash is used to store all the style properties & values
		var styleHash:Hash<String> = new Hash<String>();
		
		// gets the existing styles
		
		// adds the new property & value
		
		// build the complete style value
		
		// updates the style attribute value
		
	}
	
	/**
	 * This method gets the style of the div
	 * If style="x:100;y:200;z-index=5", calling getStyle('x') will return '100'
	 * 
	 * @param	property
	 * @param	value
	 */
	private function getStyle(property:String):String
	{
		
		// styleHash is used to store all the style properties & values
		var styleHash:Hash<String> = new Hash<String>();
		
		// gets the property value in the list of existing styles
		return '';
	}
	
}