/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;

import cocktail.geom.Matrix;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.keyboard.Keyboard;
import cocktail.keyboard.KeyboardData;
import cocktail.mouse.Mouse;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;
import haxe.Log;

/**
 * This is a base class for runtime specific DOMElement. A DOMElement is an abstraction of the visual base element of a runtime.
 * For instance in JS, a DOMElement is an HTML element, like a <div> or <img> element. In Flash AS3, a domElement is a Sprite.
 * This class abstracts manipulating DOM elements, each runtime is implemented in an inheriting class
 * @author Yannick DOMINGUEZ
 */
class AbstractDOMElement 
{
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Mouse attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to native mouse events
	 */
	private var _mouse:Mouse;
	
	/**
	 * The callback called on mouse down through the mouse instance
	 */
	public var onMouseDown(getOnMouseDown, setOnMouseDown):MouseEventData->Void;
	
	/**
	 * The callback called on mouse up through the mouse instance
	 */
	public var onMouseUp(getOnMouseUp, setOnMouseUp):MouseEventData->Void;
	
	/**
	 * The callback called when the mouse over this dom element
	 */
	public var onMouseOver(getOnMouseOver, setOnMouseOver):MouseEventData->Void;
	
	/**
	 * The callback called on mouse out of this dom element
	 */
	public var onMouseOut(getOnMouseOut, setOnMouseOut):MouseEventData->Void;
	
	/**
	 * The callback called when the mouse move over this dom element
	 */
	public var onMouseMove(getOnMouseMove, setOnMouseMove):MouseEventData->Void;
	
	/**
	 * The callback called when this dom element is double-clicked
	 */
	public var onMouseDoubleClick(getOnMouseDoubleClick, setOnMouseDoubleClick):MouseEventData->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard attributes and callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An instance of the cross-platform keyboard class, used to listen
	 * to key dow and up event
	 */
	private var _keyboard:Keyboard;
	
	/**
	 * The callback called on key down through the keyboard instance
	 */
	public var onKeyDown(getOnKeyDown, setOnKeyDown):Key->Void;
	
	/**
	 * The callback called on key up through the keyboard instance
	 */
	public var onKeyUp(getOnKeyUp, setOnKeyUp):Key->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A reference to the native DOM object. Varies for each
	 * runtime : in JS it is an HTML element, in Flash a Sprite,
	 * in PHP a resource
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, setNativeElement):NativeElement;
	
	/**
	 * a reference to the parent of this DOMElement, of type container
	 */ 
	private var _parent:AbstractContainerDOMElement;
	public var parent(getParent, setParent):AbstractContainerDOMElement;
	
	/////////////////////////////////
	// COORDS attributes
	// Stores the coords of the DOM Object
	// as they are set. This abstraction is used
	// to prevent runtime inconsistencies happening
	// when retrieving coords from a native dom element
	////////////////////////////////
	
	/**
	 * Stores the x position of this dom element, relative
	 * to its parent
	 */
	private var _x:Int;
	public var x(getX, setX):Int;
	
	/**
	 * get/set the global x. It is relative to the root 
	 * DOMElement.
	 */
	public var globalX(getGlobalX, setGlobalX):Int;
	
	/**
	 * Stores the y position of this dom element, relative
	 * to its parent
	 */
	private var _y:Int;
	public var y(getY, setY):Int;
	
	/**
	 * get/set the global y. It is relative to the root 
	 * DOMElement.
	 */
	public var globalY(getGlobalY, setGlobalY):Int;
	
	/**
	 * Stores the width position of this dom element
	 */
	private var _width:Int;
	public var width(getWidth, setWidth):Int;
	
	/**
	 * Stores the height position of this dom element
	 */
	private var _height:Int;
	public var height(getHeight, setHeight):Int;
	
	/////////////////////////////////
	// STYLE attribute
	////////////////////////////////
	
	/**
	 * Stores the styles of a DOMElement and manage
	 * how they are applied
	 */
	private var _style:Style;
	public var style(getStyle, never):Style;
	
	/////////////////////////////////
	// TRANSFORMATION attributes
	////////////////////////////////
	
	/**
	 * Stores the origin of the domElement transformations.
	 * It is used by defautlt when none is provided for a
	 * transformation. It defaults to the top left of the
	 * domElement
	 */
	private var _registrationPoint:RegistrationPointValue;
	public var registrationPoint(getRegistrationPoint, setRegistrationPoint):RegistrationPointValue;
	
	/**
	 * Stores a reference to this domElement transformation matrix
	 */
	private var _matrix:Matrix;
	public var matrix(getMatrix, setMatrix):Matrix;
	
	/**
	 * get/set x scale
	 */
	public var scaleX(getScaleX, setScaleX):Float;
	
	/**
	 * get/set y scale
	 */
	public var scaleY(getScaleY, setScaleY):Float;
	
	/**
	 * get/set translation x
	 */
	public var translationX(getTranslationX, setTranslationX):Float;
	
	/**
	 * get/set translation y
	 */
	public var translationY(getTranslationY, setTranslationY):Float;
	
	/**
	 * get/set the rotation on degree
	 */
	public var rotation(getRotation, setRotation):Int;
	
	/////////////////////////////////
	// VISIBILITY/OPACITY attributes
	////////////////////////////////
	
	/**
	 * The opacity of the DOM Object, from 0 to 1
	 */
	public var alpha(getAlpha, setAlpha):Float;
	
	/**
	 * Wheter the DOMElement is visible
	 */
	public var isVisible(getIsVisible, setIsVisible):Bool;
	
	/////////////////////////////////
	// Z-Index attribute
	/////////////////////////////////
	
	/**
	 * The z-order / z-index of this DOM Object, relative to
	 * its parent (the first child of a ContainerDOMElement always has
	 * a 0 z-index)
	 */
	public var zIndex(getZIndex, setZIndex):Int;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor. Set the native element to the native DOMElement
	 * and initialise it
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//store and init the dom element properties
		//with the native element if it isn't null
		if (nativeElement != null)
		{
			this.nativeElement = nativeElement;
		}
	}
	
	/**
	 * Init the domElement properties. Called each time
	 * the NativeElement is set
	 */
	private function init():Void
	{	
		//initialise the transformation matrix of this dom element
		_matrix = new Matrix();
		
		//initialise the keyboard listener of this dom element 
		_keyboard = new Keyboard();
		
		//initialise the mouse listeners on this dom element by 
		//listening to the current native element
		_mouse = new Mouse(this._nativeElement);
		
		//init the origin transformation point to the 
		//top left of this domElement
		_registrationPoint = constant(left, top);
		
		//init the origin positioning of the DOMElement
		_x = 0;
		_y = 0;
		
		//init the style for this DOMElement
		initStyle();
	}
	
	/**
	 * Instantiate the right style manager for this
	 * DOMElement. Overriden by DOMElements with
	 * specific style manager, such as Text
	 */
	private function initStyle():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM
	// Public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * attaches the NativeElement to its parent's
	 * NativeElement
	 */
	public function attach():Void
	{
		//abstract
	}
	
	/**
	 * detaches the NativeElement from its parent's
	 * NativeElement
	 */
	public function detach():Void
	{
		//abstract
	}
	
	/**
	 * Returns the DOMElement parent of this DOMElement
	 */
	public function getParent():AbstractContainerDOMElement
	{
		return this._parent;
	}
	
	/**
	 * set the parent of this DOMElement
	 */
	public function setParent(domElement:AbstractContainerDOMElement):AbstractContainerDOMElement
	{
		this._parent = domElement;
		return this._parent;
	}
	
	/**
	 * set the reference to this DOMElement NativeElement
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	public function setNativeElement(value:NativeElement):NativeElement
	{
		this._nativeElement = value;
		init();
		return value;
	}
	
	/**
	 * Returns the reference to this DOMElement native DOM element
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	public function getNativeElement():NativeElement
	{
		return this._nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// VISIBILITY/OPACITY
	// Public and private methods to manage the visibility and opacity of the dom element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Show or hide the native DOM Object. Implemented
	 * by runtime specific sub class
	 * @param	value true if the DOM object must be visible
	 */
	public function setIsVisible(value:Bool):Bool
	{
		return value;
	}
	
	/**
	 * Return wether the DOM object is visible. Implemented
	 * by runtime specific sub class
	 */
	public function getIsVisible():Bool
	{
		return false;
	}
	
	/**
	 * Set the opacity of the DOM object
	 * @param	value from 0 (transparent) to 1 (opaque)
	 */
	public function setAlpha(value:Float):Float
	{
		return value;
	}
	
	/**
	 * return the opacity of the DOM Object, 
	 * from 0 to 1
	 */ 
	public function getAlpha():Float
	{
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TRANSFORMATIONS
	// Public and private methods to transform the dom element and manipulate it's matrix
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the transformation matrix of this domElement. Used
	 * by the inheriting runtime specific class to update
	 * their native matrix transformations
	 */
	public function setMatrix(matrix:Matrix):Matrix
	{
		this._matrix = matrix;
		return this._matrix;
	}
	
	/**
	 * Return this domElement matrix
	 */
	public function getMatrix():Matrix
	{
		return this._matrix;
	}
	
	/**
	 * Reset the matrix to an identity matrix (no transformations)
	 */
	public function resetTransformations():Void
	{
		_matrix.identity();
		this.matrix = this._matrix;
	}
	
	/**
	 * Return the transformation origin as a Point, from a
	 * RegistrationPointValue
	 */
	private function getRegistrationPointPoint(registrationPoint:RegistrationPointValue):Point
	{
		//set the returned point
		var registrationPointPoint:Point = { x:0.0, y:0.0 };
		
		//switch the origin point value
		switch (registrationPoint)
		{
			//if it is given as point (in pixels), set it
			//on the registrationPointPoint that will be returned
			case point(point):
				registrationPointPoint = point;
			
			//else if it is given as constants, deduce the point coordinate
			//from the constant value
			case constant(registrationPointX, registrationPointY):
			
			//for x point coordinate	
			switch registrationPointX
			{
				case left : 
					registrationPointPoint.x = 0;
				
				case center :
					registrationPointPoint.x = getWidth() / 2;
					
				case right :
					registrationPointPoint.x = getWidth();
			}
			
			//for y point coordinate	
			switch registrationPointY
			{
				case top : 
					registrationPointPoint.y = 0;
				
				case middle :
					registrationPointPoint.y = getHeight() / 2;
					
				case bottom :
					registrationPointPoint.y = getHeight();
			}
		}
		
		return registrationPointPoint;
	}
	
	
	/**
	 * Translate the domElement along the x and y axis, using x and y as offset
	 * @param	x the x offset
	 * @param	y the y offset
	 */
	public function translate(x:Float, y:Float):Void
	{
		//use the matrix API
		_matrix.translate(x, y);
		
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	/**
	 * Rotate the domElement with the given angle using the registrationPoint as pivot point
	 * @param	angle the rotation angle, in degree
	 * @param	registrationPoint the pivot point, represented as an enum value or as a point
	 */
	public function rotate(angle:Int, registrationPoint:RegistrationPointValue = null):Void
	{
		//if no transformation origin, get the currently stored one
		if (registrationPoint == null)
		{
			registrationPoint = this.registrationPoint;
		}
		
		//use the matrix API, retrieve the pivot point
		_matrix.rotate(angle, getRegistrationPointPoint(registrationPoint));
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	/**
	 * Scale the domElement with the scaleX and scaleY factor, using the registrationPoint as scaling
	 * center
	 * @param	scaleX the horizontal scale factor
	 * @param	scaleY the vertical scale factor
	 * @param	registrationPoint the scale center, represented as an enum value or as a point
	 */
	public function scale(scaleX:Float, scaleY:Float, registrationPoint:RegistrationPointValue = null):Void
	{
		//if no transformation origin, get the currently stored one
		if (registrationPoint == null)
		{
			registrationPoint = this.registrationPoint;
		}
		
		//use the matrix API, retrieve the scale center
		_matrix.scale(scaleX, scaleY, getRegistrationPointPoint(registrationPoint));
		
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	/**
	 * skew the domElement with the skewX and skewY factor, using the registrationPoint as skewing
	 * center
	 * @param	skewX the horizontal skew factor
	 * @param	skewY the vertical skew factor
	 * @param	registrationPoint the skew center, represented as an enum value or as a point
	 */
	public function skew(skewX:Float, skewY:Float, registrationPoint:RegistrationPointValue = null):Void
	{
		//if no transformation origin, get the currently stored one
		if (registrationPoint == null)
		{
			registrationPoint = this.registrationPoint;
		}
		
		//use the matrix API, retrieve the skew center
		_matrix.skew(skewX, skewY, getRegistrationPointPoint(registrationPoint));
		
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TRANSFORMATION SETTER/GETTER
	// Set/get transformations absolute value
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the absolute x translation instead of adding it to 
	 * the current x translation
	 * @param	translationX the target x translation
	 */
	public function setTranslationX(translationX:Float):Float
	{
		_matrix.setTranslationX(translationX);
		this.matrix = this._matrix;
		return translationX;
	}
	
	/**
	 * Return the current x translation
	 * @return
	 */
	public function getTranslationX():Float
	{
		return this._matrix.getTranslationX();
	}
	
	/**
	 * Set the absolut y translation instead of adding it to 
	 * the current y translation
	 * @param	translationX the target y translation
	 */
	public function setTranslationY(translationY:Float):Float
	{
		_matrix.setTranslationY(translationY);
		this.matrix = this._matrix;
		return translationY;
	}
	
	/**
	 * Return the current y translation
	 * @return
	 */
	public function getTranslationY():Float
	{
		return this._matrix.getTranslationY();
	}
	
	/**
	 * set the absolut x scale of the domElement instead of adding it to the current scale
	 * @param	scaleX the target x scale
	 */
	public function setScaleX(scaleX:Float):Float
	{
		_matrix.setScaleX(scaleX, getRegistrationPointPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return scaleX;
	}
	
	/**
	 * Return the current x scale
	 * @return a float, 1 corresponds to no x scale
	 */
	public function getScaleX():Float { 
		return _matrix.getScaleX();
	}

	
	/**
	 * set the absolut y scale of the domElement instead of adding it to the current scale
	 * @param	scaleX the target y scale
	 */
	public function setScaleY(scaleY:Float):Float
	{
		//default transformation center is top left
		if (registrationPoint == null)
		{
			registrationPoint = constant(left, top);
		}
		
		_matrix.setScaleY(scaleY, getRegistrationPointPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return scaleY;
	}
	
	/**
	 * Return the current y scale
	 * @return a float, 1 corresponds to no y scale
	 */
	public function getScaleY():Float { 
		return _matrix.getScaleY();
	}
	
	/**
	 * Set the rotation to an absolute angle instead of adding a rotation to the existing 
	 * rotation
	 * @param	angle the target angle
	 */
	public function setRotation(angle:Int):Int 
	{
		
		//default transformation center is top left
		if (registrationPoint == null)
		{
			registrationPoint = constant(left, top);
		}
		
		_matrix.setRotation(angle, getRegistrationPointPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return angle;
	}
	
	/**
	 * Return the current rotation angle in deg
	 * @return an Int from 0 to 360
	 */
	public function getRotation():Int { 
		return _matrix.getRotation();
	}
	
	/**
	 * Set the origin of the domElement transformations
	 * @param	registrationPoint the new origin of transformation
	 * @return an enum value containing a constant or a point
	 */
	public function setRegistrationPoint(registrationPoint:RegistrationPointValue):RegistrationPointValue
	{
		this._registrationPoint = registrationPoint;
		return this._registrationPoint;
	}
	
	/**
	 * Return the transformation origin
	 */
	public function getRegistrationPoint():RegistrationPointValue
	{
		return this._registrationPoint;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE SETTER/GETTER
	// Proxies setting/getting properties from the mouse listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseDown = value;
		return value;
	}
	
	public function getOnMouseDown():MouseEventData->Void
	{
		return _mouse.onMouseDown;
	}
	
	public function setOnMouseUp(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseUp = value;
		return value;
	}
	
	public function getOnMouseUp():MouseEventData->Void
	{
		return _mouse.onMouseUp;
	}
	
	public function setOnMouseOver(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseOver = value;
		return value;
	}
	
	public function getOnMouseOver():MouseEventData->Void
	{
		return _mouse.onMouseOver;
	}
	
	public function setOnMouseOut(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseOut = value;
		return value;
	}
	
	public function getOnMouseOut():MouseEventData->Void
	{
		return _mouse.onMouseOut;
	}
	
	public function setOnMouseMove(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseMove = value;
		return value;
	}
	
	public function getOnMouseMove():MouseEventData->Void
	{
		return _mouse.onMouseMove;
	}
	
	public function setOnMouseDoubleClick(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseDoubleClick = value;
		return value;
	}
	
	public function getOnMouseDoubleClick():MouseEventData->Void
	{
		return _mouse.onMouseDoubleClick;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD SETTER/GETTER
	// Proxies setting/getting properties from the keyboard listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function setOnKeyDown(value:Key->Void):Key->Void
	{
		_keyboard.onKeyDown = value;
		return value;
	}
	
	public function getOnKeyDown():Key->Void
	{
		return _keyboard.onKeyDown;
	}
	
	public function setOnKeyUp(value:Key->Void):Key->Void
	{
		_keyboard.onKeyUp = value;
		return value;
	}
	
	public function getOnKeyUp():Key->Void
	{
		return _keyboard.onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM SETTER/GETTER
	// Generic Setters/Getters to manipulate any attribute of the DOMElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a field value on the native DOM object
	 * @param	propertyName the name of the field
	 * @param	propertyValue the new value of the field
	 */
	public function setField(propertyName:String, propertyValue:Dynamic):Void
	{
		Reflect.setField(this._nativeElement, propertyName, propertyValue);
	}
	
	/**
	 * Return the value of a field of the native object
	 * @param	propertyName the name of the field value to return
	 * @return might be any type
	 */
	public function getField(propertyName:String):Dynamic
	{
		return Reflect.field(this._nativeElement, propertyName);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// POSITIONING SETTERS/GETTERS
	// Setters/Getters to manipulate a native DOMElement positioning in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function setX(value:Int):Int 
	{
		this._x = value;
		return this._x;
	}
	
	public function getX():Int 
	{ 
		return this._x; 
	}
	
	public function setY(value:Int):Int
	{
		this._y = value;
		return this._y;
	}
	
	public function getY():Int 
	{ 
		return this._y; 
	}
	
	public function setWidth(value:Int):Int
	{
		this._width = value;
		return this._width;
	}
	
	public function getWidth():Int 
	{ 
		return this._width; 
	}
	
	public function setHeight(value:Int):Int
	{
		this._height = value;
		return this._height;
	}
	
	public function getHeight():Int 
	{ 
		return this._height;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GLOBAL POSITION SETTERS/GETTERS
	// Setters/Getters to manipulate a nativeElement global position (relative to the root 
	// DOMElement)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get a global x position (relative to the root DOMElement)
	 * and convert to an x position relative to the parent DOMElement
	 * @param	value the new x position of the DOMElement
	 */
	public function setGlobalX(value:Int):Int
	{
		//init the local x position with the provided value
		//, if the DOMElement has no parent, it will be the 
		//returned value
		var localX:Int = value;
		
		//if the DOMElement has a parent
		if (this._parent != null)
		{
			//retrieve its global x value, and substract
			//it to the local value, effectively computing
			//the x that this DOMElement should have relative
			//to its parent
			var parentGlobalX:Int = this._parent.globalX;
			localX -= parentGlobalX;
			
		}
		//if this DOMElement has no parent, then it is the 
		//root DOMElement and the origin for all global position
		else 
		{
			localX = 0;
		}
		this.x = localX;
		
		return this._x;
	}
	
	/**
	 * Return the x position of this DOMElement relative
	 * to the root DOMElement x position
	 */
	public function getGlobalX():Int
	{
		//init the globalX with the current localX
		//if this DOMElement has no parent, it will
		//be the returned value
		var newGlobalX:Int = this.x;
		
		//if this DOMElement has a parent
		if (this._parent != null)
		{
			var parentDOMElement:AbstractDOMElement = this._parent;
			//Add the localX of each parent until a DOMElement
			//with no parent is found (the root DOMElement).
			//The added localX form the globalX valu
			while (parentDOMElement != null)
			{
				newGlobalX += parentDOMElement.x;
				parentDOMElement = parentDOMElement.parent;
			}
		}
		//if this DOMElement has no parent, then it is the 
		//root DOMElement and the origin for all global position
		else
		{
			newGlobalX = 0;
		}
		return newGlobalX;
		
	}
	
	/**
	 * Set the DOMElement y position relative to the root DOMElement
	 * y position
	 * @param	value the new y position of the DOMElement
	 */
	public function setGlobalY(value:Int):Int
	{
		//see setGlobalX
		var localY:Int = value;
		
		if (this._parent != null)
		{
			var parentGlobalY:Int = this._parent.globalY;
			localY -= parentGlobalY;
			
		}
		else
		{
			localY = 0;
		}
		this.y = localY;
		
		return this._y;
	}
	
	/**
	 * Return the y position of this DOMElement relative
	 * to the root DOMElement y position
	 */
	public function getGlobalY():Int
	{
		//see getGlobalY
		var newGlobalY:Int = this.y;
		
		if (this._parent != null)
		{
			var parentDOMElement:AbstractDOMElement = this._parent;
			while (parentDOMElement != null)
			{
				newGlobalY += parentDOMElement.y;
				parentDOMElement = parentDOMElement.parent;
			}
		}
		else
		{
			newGlobalY = 0;
		}
		
		return newGlobalY;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a native DOMElement z-index in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function setZIndex(value:Int):Int 
	{
		return value;
	}
	
	public function getZIndex():Int 
	{
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function getStyle():Style
	{
		return this._style;
	}
}