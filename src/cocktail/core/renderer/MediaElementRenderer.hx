/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;

/**
 * This a base renderer class to render media
 * elements and their associated controls, such
 * as for video and audio
 * 
 * @author Yannick DOMINGUEZ
 */
class MediaElementRenderer extends EmbeddedBoxRenderer
{

	public var currentTime(get_currentTime, set_currentTime):Float;
	
	public var duration(get_duration, never):Float;
	
	public var paused(get_paused,  never):Bool;
	
	public var ended(get_ended, never):Bool;
	
	public var autoplay(get_autoplay, set_autoplay):Bool;
	
	public var loop(get_loop, set_loop):Bool;
	
	public function new(node:Node) 
	{
		super(node);
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	private function get_currentTime():Float 
	{
		return 0;
	}
	
	private function set_currentTime(value:Float):Float 
	{
		return value;
	}
	
	private function get_duration():Float
	{
		return 0;
	}
	
	private function get_paused():Bool
	{
		return false;
	}
	
	private function get_ended():Bool 
	{
		return false;
	}
	
	private function get_autoplay():Bool
	{
		return false;
	}
	
	private function set_autoplay(value:Bool):Bool
	{
		return value;
	}
	
	private function get_loop():Bool
	{
		return false;
	}
	
	private function set_loop(value:Bool):Bool
	{
		return value;
	}
	
}