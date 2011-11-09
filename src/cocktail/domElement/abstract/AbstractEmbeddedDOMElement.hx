/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.style.EmbeddedStyle;

#if flash9
import cocktail.domElement.as3.DOMElement;
#elseif js
import cocktail.domElement.js.DOMElement;
#end

/**
 * A base DOMElement class for embedded content such as picture or video. An embedded element, also called a
 * replaced element in HTML, typically has an intrinsic width, height and ratio. 
 * For example, for a picture it corresponds to the picture's dimensions in pixel
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractEmbeddedDOMElement extends DOMElement
{

	/**
	 * The instrinsic width of an embedded content. For example, for a video, the width
	 * in pixel of the video
	 */
	private var _intrinsicWidth:Null<Int>;
	public var intrinsicWidth(getIntrinsicWidth, setIntrinsicWidth):Null<Int>;
	
	/**
	 * The instrinsic height of an embedded content. For example, for a video, the height
	 * in pixel of the video
	 */
	private var _intrinsicHeight:Null<Int>;
	public var intrinsicHeight(getIntrinsicHeight, setIntrinsicHeight):Null<Int>;
	
	/**
	 * The instrinsic ratio of an embedded content. For example, for a video, the height/width
	 * ratio of the video
	 */
	private var _intrinsicRatio:Null<Float>;
	public var intrinsicRatio(getIntrinsicRatio, setIntrinsicRatio):Null<Float>;
	
	/**
	 * Constructor. Init the default dimensions and intrinsic dimensions of the DOMElement
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
		initDimensions();
		initInstrinsicDimensions();
	}
	
	/**
	 * Override to instantiate an embedded DOMElement specific 
	 * style manager
	 */
	override private function initStyle():Void
	{
		this._style = new EmbeddedStyle(this);
	}
	
	/**
	 * Init the default width and height of an 
	 * embedded DOMElement, varies for each inheriting
	 * DOMElement
	 */
	private function initDimensions():Void
	{
		//abstract
	}
	
	/**
	 * Init the default intrinsic width, height and ratio.
	 * Different for each inheriting embedded DOMElement
	 */
	private function initInstrinsicDimensions():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// INTRINSIC DIMENSIONS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setIntrinsicWidth(value:Null<Int>):Null<Int>
	{
		this._intrinsicWidth = value;
		return value;
	}
	
	private function getIntrinsicWidth():Null<Int>
	{
		return this._intrinsicWidth;
	}
	
	private function setIntrinsicHeight(value:Null<Int>):Null<Int>
	{
		this._intrinsicHeight = value;
		return value;
	}
	
	private function getIntrinsicHeight():Null<Int>
	{
		return this._intrinsicHeight;
	}
	
	private function getIntrinsicRatio():Null<Float>
	{
		return this._intrinsicRatio;
	}
	
	private function setIntrinsicRatio(value:Null<Float>):Null<Float>
	{
		this._intrinsicRatio = value;
		return value;
	}
}