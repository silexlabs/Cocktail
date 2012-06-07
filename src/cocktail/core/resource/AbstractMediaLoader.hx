/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.resource;

import cocktail.core.NativeElement;

/**
 * This is the base class for loading class
 * loading media assets such as pictures
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractMediaLoader extends ResourceLoader
{
	/**
	 * A reference to the native element actually loading
	 * the asset. For instance, for an image in Flash, a Loader, in JS,
	 * an img tag. When multiple loads occurs, this NativeElement is
	 * reused instead of a new one being created.
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, never):NativeElement;
	
	/**
	 * The intrinsic width of the loaded asset.
	 */
	private var _intrinsicWidth:Int;
	public var intrinsicWidth(getIntrinsicWidth, never):Int;
	
	/**
	 * The intrinsic height of the loaded asset.
	 */
	private var _intrinsicHeight:Int;
	public var intrinsicHeight(getIntrinsicHeight, never):Int;
	
	/**
	 * The intrinsic ratio of the loaded asset.
	 */
	private var _intrinsicRatio:Float;
	public var intrinsicRatio(getIntrinsicRatio, never):Float;
	
	/**
	 * class constructor. Store provided NativeElement
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getNativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	private function getIntrinsicWidth():Int
	{
		return _intrinsicWidth;
	}
	
	private function getIntrinsicHeight():Int
	{
		return _intrinsicHeight;
	}
	
	private function getIntrinsicRatio():Float
	{
		return _intrinsicRatio;
	}
	
}