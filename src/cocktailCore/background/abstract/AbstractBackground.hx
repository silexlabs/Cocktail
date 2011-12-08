/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.background.abstract;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktailCore.domElement.abstract.AbstractGraphicDOMElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractBackground 
{

	private var _backgroundColorCanvas:AbstractGraphicDOMElement;
	
	private var _backgroundColor:Int;
	public var backgroundColor(getBackgroundColor, setBackgroundColor):Int;
	
	private var _backgroundImage:String;
	public var backgroundImage(getBackgroundImage, setBackgroundImage):String;
	
	private var _backgroundPositionX:Int;
	public var backgroundPositionX(getBackgroundPositionX, setBackgroundPositionX):Int;
	
	private var _backgroundPositionY:Int;
	public var backgroundPositionY(getBackgroundPositionY, setBackgroundPositionY):Int;
	
	private var _backgroundRepeatX:Bool;
	public var backgroundRepeatX(getBackgroundRepeatX, setBackgroundRepeatX):Bool;
	
	private var _backgroundRepeatY:Bool;
	public var backgroundRepeatY(getBackgroundRepeatY, setBackgroundRepeatY):Bool;
	
	public function new() 
	{
		
	}
	
	public function attachToDOMElement(domElement:AbstractDOMElement):Void
	{
		
	}
	
	private function setBackgroundColor(value:Int):Int
	{
		return _backgroundColor = value;
	}
	
	private function getBackgroundColor():Int
	{
		return _backgroundColor;
	}
	
	private function setBackgroundImage(value:String):String
	{
		return _backgroundImage = value;
	}
	
	private function getBackgroundImage():String
	{
		return _backgroundImage;
	}
	
	private function setBackgroundPositionX(value:Int):Int
	{
		return _backgroundPositionX = value;
	}
	
	private function getBackgroundPositionX():Int
	{
		return _backgroundPositionX;
	}
	
	private function setBackgroundPositionY(value:Int):Int
	{
		return _backgroundPositionY = value;
	}
	
	private function getBackgroundPositionY():Int
	{
		return _backgroundPositionY;
	}
	
	private function setBackgroundRepeatX(value:Bool):Bool
	{
		return _backgroundRepeatX = value;
	}
	
	private function getBackgroundRepeatX():Bool
	{
		return _backgroundRepeatX;
	}
	
	private function setBackgroundRepeatY(value:Bool):Bool
	{
		return _backgroundRepeatY = value;
	}
	
	private function getBackgroundRepeatY():Bool
	{
		return _backgroundRepeatY;
	}
	
	
	
	
}