/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.DOMElement;
import cocktail.geom.Matrix;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktailCore.keyboard.Keyboard;
import cocktail.keyboard.KeyboardData;
import cocktailCore.mouse.Mouse;
import cocktail.mouse.MouseData;
import cocktail.nativeElement.NativeElement;
import cocktailCore.style.Style;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import cocktail.unit.UnitData;
import haxe.Log;

/**
 * This is the base class for all DOMElements. A DOMElement is an abstraction of the visual base element of a runtime.
 * For instance in JS, a DOMElement is an HTML element, like a <div> or <img> element. In Flash AS3, a domElement is a DisplayObject.
 * This class abstracts manipulating DOM elements, each runtime implemented in a sub-class.
 * 
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
	 * The callback called when the mouse pointer hovers this dom element
	 */
	public var onMouseOver(getOnMouseOver, setOnMouseOver):MouseEventData->Void;
	
	/**
	 * The callback called on mouse out of this dom element
	 */
	public var onMouseOut(getOnMouseOut, setOnMouseOut):MouseEventData->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this dom element
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
	 * to key down and up event
	 */
	private var _keyboard:Keyboard;
	
	/**
	 * The callback called on key down through the keyboard instance
	 */
	public var onKeyDown(getOnKeyDown, setOnKeyDown):KeyEventData->Void;
	
	/**
	 * The callback called on key up through the keyboard instance
	 */
	public var onKeyUp(getOnKeyUp, setOnKeyUp):KeyEventData->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An abstract reference to the native element wrapped by this DOMElement.
	 * Varies for each runtime : in JS it is an HTML element, in Flash a Sprite,
	 * in PHP a resource...
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(getNativeElement, setNativeElement):NativeElement;
	
	/**
	 * a reference to the parent of this DOMElement, of type container, the
	 * only kind of DOMElement which can have children
	 */ 
	private var _parent:AbstractContainerDOMElement;
	public var parent(getParent, setParent):AbstractContainerDOMElement;
	
	/////////////////////////////////
	// COORDS attributes
	////////////////////////////////
	
	/**
	 * get/set the x position of this DOMElement's nativeElement
	 */
	public var x(getX, setX):Int;
	
	/**
	 * get/set the global x. It is relative to the root 
	 * DOMElement.
	 */
	public var globalX(getGlobalX, setGlobalX):Int;
	
	/**
	 * get/set the y position of this DOMElement's nativeElement
	 */
	public var y(getY, setY):Int;
	
	/**
	 * get/set the global y. It is relative to the root 
	 * DOMElement.
	 */
	public var globalY(getGlobalY, setGlobalY):Int;
	
	/**
	 * get/set the width position of this DOMElement's nativeElement
	 */
	public var width(getWidth, setWidth):Int;
	
	/**
	 * get/set the height position of this DOMElement's nativeElement
	 */
	public var height(getHeight, setHeight):Int;
	
	/**
	 * Read-only, returns the width of the domElement
	 * + horizontal paddings + horizontal margins
	 */
	public var offsetWidth(getOffsetWidth, never):Int;
	
	/**
	 * Read-only, returns the height of the domElement
	 * + vertical paddings + vertical margins
	 */
	public var offsetHeight(getOffsetHeight, never):Int;
	
	/////////////////////////////////
	// STYLE attribute
	////////////////////////////////
	
	/**
	 * This Style object stores the styles of
	 * a DOMElement and manages how they are applied
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
	 * Stores a reference to this domElement 2d transformation matrix
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
	 * get/set the rotation in deg (0 to 360)
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
	 * The z-index of this DOM Object, relative to
	 * its parent (the first child of a ContainerDOMElement always has
	 * a 0 z-index)
	 */
	public var zIndex(getZIndex, setZIndex):Int;
	
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * class constructor. Stores the reference to the
	 * native element triggering the initialisation
	 * of the DOMElement
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
	 * Init the DOMElement properties. Called each time
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
		
		//init the style for this DOMElement
		initStyle();
	}
	
	/**
	 * Instantiate the right style object for this
	 * DOMElement. Overriden by DOMElements with
	 * specific style objects, such as ContainerDOMElement
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
	 * Returns the parent of this DOMElement
	 */
	private function getParent():AbstractContainerDOMElement
	{
		return this._parent;
	}
	
	/**
	 * set the parent of this DOMElement
	 */
	private function setParent(domElement:AbstractContainerDOMElement):AbstractContainerDOMElement
	{
		this._parent = domElement;
		return this._parent;
	}
	
	/**
	 * set the reference to this DOMElement NativeElement
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	private function setNativeElement(value:NativeElement):NativeElement
	{
		this._nativeElement = value;
		//reset the DOMElement's properties
		init();
		return value;
	}
	
	/**
	 * Returns the reference to this DOMElement native DOM element
	 * @return a DisplayObject in AS, an HTML element in JS, a resource in PHP
	 */
	private function getNativeElement():NativeElement
	{
		return this._nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// VISIBILITY/OPACITY
	// Public and private methods to manage the visibility and opacity of the dom element
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Show or hide the native DOMElement.
	 * @param	value true if the DOM object must be visible
	 */
	private function setIsVisible(value:Bool):Bool
	{
		var visibility:VisibilityStyleValue;
		if (value == true)
		{
			visibility = visible;
		}
		else
		{
			visibility = hidden;
		}
		_style.visibility = visibility;
		return value;
	}
	
	/**
	 * Return wether the DOMElement is visible.
	 */
	private function getIsVisible():Bool
	{
		return _style.getNativeVisibility();
	}
	
	/**
	 * Set the opacity of the DOMElement
	 * @param	value from 0 (transparent) to 1 (opaque)
	 */
	private function setAlpha(value:Float):Float
	{
		 _style.opacity = OpacityStyleValue.number(value);
		return value;
	}
	
	/**
	 * returns the opacity of the DOMElement, 
	 * from 0 to 1
	 */ 
	private function getAlpha():Float
	{
		return _style.getNativeOpacity();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TRANSFORMATIONS
	// Public and private methods to transform the dom element and manipulate it's matrix
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the transformation matrix of this DOMElement. Overriden
	 * by the inheriting runtime specific class to update
	 * their native matrix transformations
	 */
	private function setMatrix(matrix:Matrix):Matrix
	{
		this._matrix = matrix;
		return this._matrix;
	}
	
	/**
	 * Return this DOMElement matrix
	 */
	private function getMatrix():Matrix
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
	private function getRegistrationPointValueAsPoint(registrationPoint:RegistrationPointValue):PointData
	{
		//init the returned point
		var registrationPointPoint:PointData = { x:0.0, y:0.0 };
		
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
					registrationPointPoint.x = this.width / 2;
					
				case right :
					registrationPointPoint.x = this.width;
			}
			
			//for y point coordinate	
			switch registrationPointY
			{
				case top : 
					registrationPointPoint.y = 0;
				
				case middle :
					registrationPointPoint.y = this.height / 2;
					
				case bottom :
					registrationPointPoint.y = this.height;
			}
		}
		
		return registrationPointPoint;
	}
	
	
	/**
	 * Translate the DOMElement along the x and y axis, using x and y as offset
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
	 * Rotate the DOMElement with the given angle using the registrationPoint as pivot point
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
		_matrix.rotate(angle, getRegistrationPointValueAsPoint(registrationPoint));
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	/**
	 * Scale the DOMElement with the scaleX and scaleY factor, using the registrationPoint as scaling
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
		_matrix.scale(scaleX, scaleY, getRegistrationPointValueAsPoint(registrationPoint));
		
		//refresh the matrix to refresh the domElement display
		this.matrix = this._matrix;
	}
	
	/**
	 * skew the DOMElement with the skewX and skewY factor, using the registrationPoint as skewing
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
		_matrix.skew(skewX, skewY, getRegistrationPointValueAsPoint(registrationPoint));
		
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
	private function setTranslationX(translationX:Float):Float
	{
		_matrix.setTranslationX(translationX);
		this.matrix = this._matrix;
		return translationX;
	}
	
	/**
	 * Return the current x translation
	 * @return
	 */
	private function getTranslationX():Float
	{
		return this._matrix.getTranslationX();
	}
	
	/**
	 * Set the absolute y translation instead of adding it to 
	 * the current y translation
	 * @param	translationX the target y translation
	 */
	private function setTranslationY(translationY:Float):Float
	{
		_matrix.setTranslationY(translationY);
		this.matrix = this._matrix;
		return translationY;
	}
	
	/**
	 * Return the current y translation
	 * @return
	 */
	private function getTranslationY():Float
	{
		return this._matrix.getTranslationY();
	}
	
	/**
	 * set the absolute x scale of the domElement instead of adding it to the current scale
	 * @param	scaleX the target x scale
	 */
	private function setScaleX(scaleX:Float):Float
	{
		_matrix.setScaleX(scaleX, getRegistrationPointValueAsPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return scaleX;
	}
	
	/**
	 * Return the current x scale
	 * @return a float, 1 corresponds to no x scale
	 */
	private function getScaleX():Float { 
		return _matrix.getScaleX();
	}

	
	/**
	 * set the absolute y scale of the domElement instead of adding it to the current scale
	 * @param	scaleX the target y scale
	 */
	private function setScaleY(scaleY:Float):Float
	{
		//default transformation center is top left
		if (registrationPoint == null)
		{
			registrationPoint = constant(left, top);
		}
		
		_matrix.setScaleY(scaleY, getRegistrationPointValueAsPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return scaleY;
	}
	
	/**
	 * Return the current y scale
	 * @return a float, 1 corresponds to no y scale
	 */
	private function getScaleY():Float { 
		return _matrix.getScaleY();
	}
	
	/**
	 * Set the rotation to an absolute angle instead of adding a rotation to the existing 
	 * rotation
	 * @param	angle the target angle
	 */
	private function setRotation(angle:Int):Int 
	{
		
		//default transformation center is top left
		if (registrationPoint == null)
		{
			registrationPoint = constant(left, top);
		}
		
		_matrix.setRotation(angle, getRegistrationPointValueAsPoint(this.registrationPoint));
		this.matrix = this._matrix;
		return angle;
	}
	
	/**
	 * Return the current rotation angle in deg
	 * @return an Int from 0 to 360
	 */
	private function getRotation():Int { 
		return _matrix.getRotation();
	}
	
	/**
	 * Set the origin of the domElement transformations
	 * @param	registrationPoint the new origin of transformation
	 * @return an enum value containing a constant or a point
	 */
	private function setRegistrationPoint(registrationPoint:RegistrationPointValue):RegistrationPointValue
	{
		this._registrationPoint = registrationPoint;
		return this._registrationPoint;
	}
	
	/**
	 * Return the transformation origin
	 */
	private function getRegistrationPoint():RegistrationPointValue
	{
		return this._registrationPoint;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE SETTER/GETTER
	// Proxies setting/getting properties from the mouse listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseDown = value;
		return value;
	}
	
	private function getOnMouseDown():MouseEventData->Void
	{
		return _mouse.onMouseDown;
	}
	
	private function setOnMouseUp(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseUp = value;
		return value;
	}
	
	private function getOnMouseUp():MouseEventData->Void
	{
		return _mouse.onMouseUp;
	}
	
	private function setOnMouseOver(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseOver = value;
		return value;
	}
	
	private function getOnMouseOver():MouseEventData->Void
	{
		return _mouse.onMouseOver;
	}
	
	private function setOnMouseOut(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseOut = value;
		return value;
	}
	
	private function getOnMouseOut():MouseEventData->Void
	{
		return _mouse.onMouseOut;
	}
	
	private function setOnMouseMove(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseMove = value;
		return value;
	}
	
	private function getOnMouseMove():MouseEventData->Void
	{
		return _mouse.onMouseMove;
	}
	
	private function setOnMouseDoubleClick(value:MouseEventData->Void):MouseEventData->Void
	{
		_mouse.onMouseDoubleClick = value;
		return value;
	}
	
	private function getOnMouseDoubleClick():MouseEventData->Void
	{
		return _mouse.onMouseDoubleClick;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD SETTER/GETTER
	// Proxies setting/getting properties from the keyboard listener instance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnKeyDown(value:KeyEventData->Void):KeyEventData->Void
	{
		_keyboard.onKeyDown = value;
		return value;
	}
	
	private function getOnKeyDown():KeyEventData->Void
	{
		return _keyboard.onKeyDown;
	}
	
	private function setOnKeyUp(value:KeyEventData->Void):KeyEventData->Void
	{
		_keyboard.onKeyUp = value;
		return value;
	}
	
	private function getOnKeyUp():KeyEventData->Void
	{
		return _keyboard.onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM SETTER/GETTER
	// Generic Setters/Getters to manipulate any attribute of the DOMElement
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a field value on the nativeElement
	 * @param	propertyName the name of the field
	 * @param	propertyValue the new value of the field
	 */
	private function setField(propertyName:String, propertyValue:Dynamic):Void
	{
		Reflect.setField(this._nativeElement, propertyName, propertyValue);
	}
	
	/**
	 * Return the value of a field of the nativeElement
	 * @param	propertyName the name of the field value to return
	 * @return might be any type
	 */
	private function getField(propertyName:String):Dynamic
	{
		return Reflect.field(this._nativeElement, propertyName);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// POSITIONING SETTERS/GETTERS
	// Setters/Getters to manipulate a DOMElement position and dimensions in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * update the left style, triggering a layout of the document
	 */ 
	private function setX(value:Int):Int 
	{
		this._style.left = PositionOffsetStyleValue.length(px(value));
		this._style.setNativeX(cast(this), value);
		return value;
	}
	
	/**
	 * return the x of the nativeElement, relative to its parent
	 */ 
	private function getX():Int 
	{ 
		return this._style.getNativeX(); 
	}
	
	/**
	 * update the top style, triggering a layout of the document
	 */ 
	private function setY(value:Int):Int
	{
		this._style.top = PositionOffsetStyleValue.length(px(value));
		this._style.setNativeY(cast(this), value);
		return value;
	}
		
	/**
	 * return the y of the nativeElement, relative to its parent
	 */
	private function getY():Int 
	{ 
		return this._style.getNativeY(); 
	}
	
	/**
	 * update the width style, triggering a layout of the document
	 */ 
	private function setWidth(value:Int):Int
	{
		this._style.width = DimensionStyleValue.length(px(value));
		this._style.setNativeWidth(cast(this), value);
		return value;
	}
	
	/**
	 * return the width of the nativeElement
	 */
	private function getWidth():Int 
	{ 
		return this._style.getNativeWidth(); 
	}
	
	/**
	 * update the height style, triggering a layout of the document
	 */ 
	private function setHeight(value:Int):Int
	{
		this._style.height = DimensionStyleValue.length(px(value));
		this._style.setNativeHeight(cast(this), value);
		return value;
	}
	
	/**
	 * return the height of the nativeElement
	 */
	private function getHeight():Int 
	{ 
		return this._style.getNativeHeight(); 
	}
	
	/**
	 * constructs the offset width from the computed
	 * box of this domElement
	 */
	private function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.width + computedStyle.marginLeft + computedStyle.marginRight + computedStyle.paddingLeft + computedStyle.paddingRight;
	}
	
	/**
	 * constructs the offset height from the computed
	 * box of this domElement
	 */
	private function getOffsetHeight():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return computedStyle.height + computedStyle.marginTop + computedStyle.marginBottom + computedStyle.paddingTop + computedStyle.paddingBottom;
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
	private function setGlobalX(value:Int):Int
	{
		//init the local x position with the provided value
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
		//affect the new local X to the nativeElement
		this._style.setNativeX(cast(this), localX);
		
		return value;
	}
	
	/**
	 * Return the x position of this DOMElement relative
	 * to the root DOMElement x position
	 */
	private function getGlobalX():Int
	{
		//init the globalX with the current localX
		//if this DOMElement has no parent, it will
		//be the returned value
		var newGlobalX:Int = this._style.getNativeX();
		
		//if this DOMElement has a parent
		if (this._parent != null)
		{
			var parentDOMElement:DOMElement = this._parent;
			//Add the localX of each parent until a DOMElement
			//with no parent is found (the root DOMElement).
			//The added localX form the globalX valu
			while (parentDOMElement != null)
			{
				newGlobalX += parentDOMElement.style.getNativeX();
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
	private function setGlobalY(value:Int):Int
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
		this._style.setNativeY(cast(this), localY);
		
		return value;
	}
	
	/**
	 * Return the y position of this DOMElement relative
	 * to the root DOMElement y position
	 */
	private function getGlobalY():Int
	{
		//see getGlobalY
		var newGlobalY:Int = this._style.getNativeY();
		
		if (this._parent != null)
		{
			var parentDOMElement:DOMElement = this._parent;
			while (parentDOMElement != null)
			{
				newGlobalY += parentDOMElement.style.getNativeY();
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
	
	private function setZIndex(value:Int):Int 
	{
		return value;
	}
	
	private function getZIndex():Int 
	{
		return 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STYLE GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getStyle():Style
	{
		return this._style;
	}
}