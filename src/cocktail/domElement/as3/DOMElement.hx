/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.as3;

import cocktail.nativeElement.NativeElement;
import flash.display.DisplayObjectContainer;
import flash.events.MouseEvent;
import haxe.Log;
import cocktail.domElement.base.DOMElementBase;
import cocktail.geom.Matrix;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;

/**
 * This is the DOMElement implementation for FLASH AVM2. 
 * It manipulates the native Flash DOM
 * @author Yannick DOMINGUEZ
 */
class DOMElement extends DOMElementBase
{

	/**
	 * Class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	/**
	 * Set the domElement properties which can be retrieved
	 * from the native Display Object
	 */
	override private function init():Void
	{	
		super.init();
		this._width = Math.round(_nativeElement.width);
		this._height = Math.round(_nativeElement.height);
		this._x = Math.round(_nativeElement.x);
		this._y = Math.round(_nativeElement.y);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden methods to manipulate the Flash DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Adds a native Flash DOMElement (DisplayObject) to this DOMElement native DOMElement
	 * @param	domElement the DisplayObject to add to this
	 */
	override public function addChild(domElement:DOMElementBase):Void
	{
		super.addChild(domElement);
		this._nativeElement.addChild(domElement.nativeElement);
	}
	
	/**
	 * Removes a native Flash DOMElement (DisplayObject) from this DOMElement native DOMElement
	 * @param	domElement the DisplayObject to remove from this
	 */
	override public function removeChild(domElement:DOMElementBase):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public and private methods to manage the visibility and opacity of the dom element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Show or hide the native DisplayObject. 
	 * @param	value true if the DisplayObject must be visible
	 */
	override public function setIsVisible(value:Bool):Bool
	{
		this._nativeElement.visible = value;
		return value;
	}
	
	/**
	 * Return wether the native DisplayObject is visible.
	 */
	override public function getIsVisible():Bool
	{
		return this._nativeElement.visible;
	}
	
	/**
	 * Set the opacity of the DisplayObject
	 * @param	value from 0 (transparent) to 1 (opaque)
	 */
	override public function setAlpha(value:Float):Float
	{
		this._nativeElement.alpha = value;
		return value;
	}
	
	/**
	 * return the opacity of the DisplayObject, 
	 * from 0 to 1
	 */ 
	override public function getAlpha():Float
	{
		return this._nativeElement.alpha;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden transformation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * when the matrix is set, update also
	 * the values of the native flash matrix of the
	 * native DisplayObject
	 * @param	matrix
	 */
	override public function setMatrix(matrix:Matrix):Matrix
	{
		super.setMatrix(matrix);
		
		//get the data of the cross-platform matrix
		var matrixData:MatrixData = matrix.getMatrixData();
		
		//create a native matrix with the cross-platform matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
		
		//set the native matrix on the native DisplayObject to refresh its display
		this._nativeElement.transform.matrix = nativeTransformMatrix;
		
		return this._matrix;
	}
	
	/**
	 * In flash when the transformation matrix is reseted, the x
	 * and y are set to 0 as they represent the translation x and y
	 * of the flash display object. We need to set x and y back to
	 * the stored class attribute after a matrix reset
	 */
	override public function resetTransformations():Void
	{
		super.resetTransformations();
		this.x = this._x;
		this.y = this._y;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Setters to manipulate the Flash DOMElement
	// set the following attributes : x,y,width,height
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setX(value:Int):Int 
	{
		Log.trace("set x");
		super.setX(value);
		Log.trace(this._nativeElement);
		this._nativeElement.x = value;
		Log.trace("set x 3 ");
		return this._x;
	}
	
	override public function setY(value:Int):Int 
	{
		super.setY(value);
		this._nativeElement.y = value;
		return this._y;
	}
	
	override public function setWidth(value:Int):Int
	{
		super.setWidth(value);
		this._nativeElement.width = value;
		return this._width;
	}
	
	override public function setHeight(value:Int):Int 
	{
		super.setHeight(value);
		this._nativeElement.height = value;
		return this._height;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a native DOMElement z order in the publication
	//////////////////////////////////////////////////////////////////////////////////////////

	override public function setZOrder(value:Int):Int
	{
		//if the value is outside of the children range, set it to the 
		//last children range
		if (value > _parent.getChildren().length - 1)
		{
			value = _parent.getChildren().length - 1;
		}
		
		//retrieve the parent Display Object, and use it to set
		//the new index on the current DisplayObject
		var parent:DisplayObjectContainer = this._nativeElement.parent;
		parent.setChildIndex(this._nativeElement, value);
		
		return value;
	}
	
	override public function getZOrder():Int 
	{
		//retrieve the parent Display object, and use it to retrieve the current
		//child index
		var parent:DisplayObjectContainer = this._nativeElement.parent;
		return parent.getChildIndex(this._nativeElement);
	}
	
}