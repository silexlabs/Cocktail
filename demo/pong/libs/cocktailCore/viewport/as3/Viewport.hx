/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.viewport.as3;

import haxe.Log;

import flash.Lib;
import flash.events.Event;

import cocktailCore.viewport.abstract.AbstractViewport;

/**
 * This class handles the interaction with the view port of the application.
 * The viewport is the visible portion of a 2D area which is larger than the visualization device.
 * Viewport width and height are read only and define the size of the visible area of our application.
 * The Viewport class is to be instanciated and the instances gives access to the viewport callbacks (events) and attributes.
 * This is the implementation for the Flash/AS3 runtime. 
 * @author zabojad
 * @date	12-2011
 */
class Viewport extends AbstractViewport
{
	/**
	 * Constructor
	 */
	public function new() 
	{
		super();
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overrides of private virtual methods
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * start listening to the viewport event
	 */
	override private function _addResizeEvent() : Void
	{
		Lib.current.stage.addEventListener( Event.RESIZE , _onResizeCallback );
	}
	/**
	 * stop listening to the viewport event
	 */
	override private function _removeResizeEvent() : Void
	{
		Lib.current.stage.removeEventListener( Event.RESIZE , _onResizeCallback );
	}

	/**
	 * start listening to the viewport event
	 */
	override private function _addOrientationChangeEvent() : Void
	{
		Lib.current.stage.addEventListener( Event.RESIZE , _onOrientationChangeCallback );
	}
	/**
	 * stop listening to the viewport event
	 */
	override private function _removeOrientationChangeEvent() : Void
	{
		Lib.current.stage.removeEventListener( Event.RESIZE , _onOrientationChangeCallback );
	}

	/**
	 * getter for the value
	 */
	override private function _getWidth() : Int
	{
		return Lib.current.stage.stageWidth;
	}

	/**
	 * getter for the value
	 */
	override private function _getHeight() : Int
	{
		return Lib.current.stage.stageHeight;
	}
	
}
