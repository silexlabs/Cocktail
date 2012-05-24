/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.DrawingManager;

/**
 * ...
 * 
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLCanvasElement extends EmbeddedElement
{
	private static inline var CANVAS_INTRINSIC_HEIGHT:Int = 150;
	
	private static inline var CANVAS_INTRINSIC_WIDTH:Int = 300;
	
	/**
	 * the html tag name of an image
	 */
	private static inline var HTML_CANVAS_TAG_NAME:String = "canvas";
	
	private static inline var CANVAS_2D_CONTEXT:String = "2d";
	
	
	/**
	 * A reference to the manager used to 
	 * draw on the NativeElement
	 */
	private var _drawingManager:DrawingManager;
	
	public function new() 
	{
		_intrinsicHeight = CANVAS_INTRINSIC_HEIGHT;
		_intrinsicWidth = CANVAS_INTRINSIC_WIDTH;
		_intrinsicRatio = _intrinsicWidth / _intrinsicHeight;
		
		_drawingManager = new DrawingManager(_intrinsicHeight, _intrinsicWidth );
		
		super(HTML_CANVAS_TAG_NAME);
	}
	
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _drawingManager.nativeElement;
	}
	
	public function getContext(contextID:String):DrawingManager
	{	
		if (contextID == CANVAS_2D_CONTEXT)
		{
			return _drawingManager;
		}
		else
		{
			return null;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_width(value:Int):Int
	{
		_drawingManager.width = value;
		return _width = value;
	}
	
	override private function set_height(value:Int):Int
	{
		_drawingManager.height = value;
		return _height = value;
	}
}