/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.CapsStyle;
import flash.display.DisplayObjectContainer;
import flash.display.GradientType;
import flash.display.JointStyle;
import flash.display.LineScaleMode;
import flash.display.Sprite;
import flash.geom.Matrix;
import flash.Lib;
import haxe.Log;
import cocktailCore.domElement.abstract.AbstractGraphicDOMElement;
import cocktail.geom.GeomData;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;

/**
 * This is the Flash AVM2 implementation of the graphic DOMElement.
 * It draws shape programatically onto a native Sprite object.
 * The sprite DOMElement is then cached as a bitmap. It allows to work
 * with both the flash vector drawing API and bitmaps.
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicDOMElement extends AbstractGraphicDOMElement
{	
	/**
	 * A transparent clip used to give a width and height
	 * to the DOMElement without scaling its content. 
	 */
	private var _backGroundSprite:Sprite;
	
	/**
	 * class constructor. Init the background Sprite with
	 * a default width and height. Add a bitmap display object that
	 * will copy the vector drawing as they are drawn
	 */
	public function new(nativeElement:NativeElement = null)
	{
		super(nativeElement);
		
		//init the background sprite and attach it to the display list
		_backGroundSprite = new Sprite();
		this._nativeElement.addChild(_backGroundSprite);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden getter/setter
	// The width and height setter/getter are overriden. In Flash, the with and height
	// depends on the transparent background Sprite, it allows drawing graphics
	// smaller than the whole graphic DOMElement. The background Sprite also
	// acts as a mask, to clip the graphics
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setWidth(value:Int):Int
	{
		super.setWidth(value);
		
		setUpBackgroundSprite(_backGroundSprite, width, height);
		_drawingManager.clearRect(0, 0, this.width, this.height);
		
		return value;
	}
	
	override private function setHeight(value:Int):Int 
	{
		super.setHeight(value);
		
		setUpBackgroundSprite(_backGroundSprite, width, height);
		_drawingManager.clearRect(0, 0, this.width, this.height);
	
		return value;
	}
	
		/**
	 * fill the background flash sprite with a transparent fill, this sprite becomes
	 * the actual with and height of this DOMElement. Set it as the mask of the native
	 * DOMElement used to draw the graphics, to clip the graphics
	 */
	private function setUpBackgroundSprite(sprite:Sprite, width:Int, height:Int):Void
	{
		sprite.graphics.clear();
		sprite.graphics.beginFill(0, 0);
		sprite.graphics.drawRect(0, 0, width, height);
		sprite.graphics.endFill();
		
		this._nativeElement.mask = _backGroundSprite;
	}
	
}