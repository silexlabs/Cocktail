/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.runtime.abstract;

/**
 * This class handles the interaction with the view port of the application.
 * The viewport is the visible portion of a 2D area which is larger than the visualization device.
 * Viewport width and height are read only and define the size of the visible area of our application.
 * The Viewport class is to be instanciated and the instances gives access to the viewport callbacks (events) and attributes.
 * This is the implementation for the JavaScript runtime. 
 * @author lexa
 * @date	12-2011
 */
class AbstractViewport 
{	
	/**
	 * Constructor
	 */
	public function new() 
	{
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Resize callback
	 */
	public var onResize(_getOnResize, _setOnResize) : Void->Void;
	/**
	 * Rotate callback
	 */
	public var onRotate(_getOnRotate, _setOnRotate) : Void->Void;
	/**
	 * width of the viewport
	 */
	public var width(_getWidth, null) : Int;
	/**
	 * height of the viewport
	 */
	public var height(_getHeight, null) : Int;
	/**
	 * orientation of the viewport
	 */
	public var orientation(_getOrientation, null) : Int;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private virtual methods
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * start listening to the viewport event
	 */
	private function _addResizeEvent() : Void
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
	}
	/**
	 * stop listening to the viewport event
	 */
	private function _removeResizeEvent() : Void
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
	}

	/**
	 * start listening to the viewport event
	 */
	private function _addOrientationChangeEvent() : Void
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
	}
	/**
	 * stop listening to the viewport event
	 */
	private function _removeOrientationChangeEvent() : Void
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
	}
	/**
	 * getter for the value
	 */
	private function _getWidth() : Int
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
		return null;
	}

	/**
	 * getter for the value
	 */
	private function _getHeight() : Int
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
		return null;
	}

	/**
	 * getter for the value
	 */
	private function _getOrientation() : OrientationValue
	{
		throw("this function is virtual, it is supposed to be implemented in the derived class");
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private setters/getters
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * private variable used to store the callback
	 */
	private var _onResize : Void->Void;
	/**
	 * getter for the callback
	 */
	private function _getOnResize() : Void->Void
	{
		return _onResize;
	}
	/**
	 * setter for the callback
	 */
	private function _setOnResize(callbackFunction : Void->Void) : Void->Void
	{
		if (_onResize == null && callbackFunction != null)
			_addResizeEvent();
		else if (_onResize != null && callbackFunction== null)
			_removeResizeEvent();

		_onResize = callbackFunction;
		return _onResize;
	}

	/**
	 * private variable used to store the callback
	 */
	private var _onRotate : Void->Void;
	/**
	 * getter for the callback
	 */
	private function _getOnRotate() : Void->Void
	{
		return _onRotate;
	}
	/**
	 * setter for the callback
	 */
	private function _setOnRotate(callbackFunction : Void->Void) : Void->Void
	{
		if (_onRotate == null && callbackFunction != null)
			_addRotateEvent();
		else if (_onRotate != null && callbackFunction== null)
			_removeRotateEvent();

		_onRotate = callbackFunction;
		return _onRotate;
	}

	/**
	 * getter for the value
	 */
	override private function _getOrientation() : OrientationValue
	{
		if (height > width) 
		{
			//portrait mode 
			return vertical;
		}
		else
		{
			//landscape mode  
			return horizontal;
		}   
	}
}
