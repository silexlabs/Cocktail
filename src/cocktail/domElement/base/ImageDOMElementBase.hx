/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.base;

import cocktail.domElement.DOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * This DOMElement is in charge of displaying a picture of 
 * type .jpg, .png or .gif
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageDOMElementBase extends DOMElement
{

	/**
	 * The URL of the loaded picture.
	 * It is only an information, setting
	 * it afterward won't load another
	 * picture in the Image DOM object
	 */
	private var _src:String;
	public var src(getSrc, setSrc):String;
	
	/**
	 * Determine wether the bitmap should be smoothed
	 */
	private var _smooth:Bool;
	public var smooth(getSmooth, setSmooth):Bool;
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
		

		
	}
	
	/**
	 * Init the smoothing of the picture
	 */
	override private function init():Void
	{	
		super.init();
		
		//smooth the picture by default
		this.smooth = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden hierarchy methods
	// The addChild and removeChild method are not implemented for this 
	// DOMElement, as it is a leaf DOMElement (can't have children)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function addChild(domElement:DOMElementBase):Void
	{
		
	}
	
	override public function removeChild(domElement:DOMElementBase):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function getSrc():String
	{
		return this._src;
	}
	
	public function setSrc(value:String):String
	{
		this._src = value;
		return value;
	}
	
	public function setSmooth(value:Bool):Bool
	{
		this._smooth = value;
		return value;
	}
	
	public function getSmooth():Bool
	{
		return this._smooth;
	}
	
}