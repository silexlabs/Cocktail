/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domObject.js;

import cocktail.nativeReference.NativeReference;
import haxe.Log;
import js.Dom;
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObjectData;
import cocktail.geom.Matrix;
import cocktail.geom.GeomData;

/**
 * This is the DOMObject implementation for JavaScript. 
 * It manipulates the native HTML DOM
 * @author Yannick DOMINGUEZ
 */
class DOMObject extends DOMObjectBase
{
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new(nativeReference:NativeReference = null) 
	{
		super(nativeReference);
	}
	
	/**
	 * Set the domObject properties which can be retrieved
	 * from the native HTML DOM element
	 */
	override private function init():Void
	{
		//all DOMObjects are positioned as absolute to prevent most
		//of browsers inconsistencies regarding margin/padding. 
		//Margin, padding , floating... concepts will be abstracted
		_nativeReference.style.position = "absolute";
		
		if (_nativeReference.style.width != null)
		{
			this._width = Std.parseInt(_nativeReference.style.width);
		}
		else
		{
			this._width = _nativeReference.offsetWidth;
		}
		
		if (_nativeReference.style.height != null)
		{
			this._height = Std.parseInt(_nativeReference.style.height);
		}
		else
		{
			this._height = _nativeReference.offsetHeight;
		}
		
		
		this._height = _nativeReference.offsetHeight;
		this._x = Std.parseInt(_nativeReference.style.left);
		this._y = Std.parseInt(_nativeReference.style.top);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden methods to manipulate the HTML DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Adds a native HTML DOMObject (an html element) to this DOMObject native DOMObject
	 * @param	domObject the html element to add to this
	 */
	override public function addChild(domObject:DOMObjectBase):Void
	{
		super.addChild(domObject);
		this._nativeReference.appendChild(domObject.nativeReference);
		
		//intialise z-order on the DOMObject, as it is null by default in JavaScript
		domObject.nativeReference.style.zIndex = _children.length - 1;
	}
	
	/**
	 * Removes a native HTML DOMObject (an html element) from this DOMObject native DOMObject
	 * @param	domObject the html element to remove from this
	 */
	override public function removeChild(domObject:DOMObjectBase):Void
	{
		super.removeChild(domObject);
		this._nativeReference.removeChild(domObject.nativeReference);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public and private methods to manage the visibility and opacity of the dom object
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Show or hide the native HTML element. 
	 * @param	value true if the element must be visible
	 */
	override public function setIsVisible(value:Bool):Bool
	{
		//set the right visibility CSS property value
		if (value == true)
		{
			this._nativeReference.style.visibility = "visible";
		}
		else
		{
			this._nativeReference.style.visibility = "hidden";
		}
		
		return value;
	}
	
	/**
	 * Return wether the native HTML element is visible.
	 */
	override public function getIsVisible():Bool
	{
		if (this._nativeReference.style.visibility == "visible")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/**
	 * Set the opacity of the HTML element
	 * @param	value from 0 (transparent) to 1 (opaque)
	 */
	override public function setAlpha(value:Float):Float
	{
		super.setAlpha(value);
		untyped this._nativeReference.style.opacity = value;
		return value;
	}
	
	/**
	 * return the opacity of the HTML element, 
	 * from 0 to 1
	 */ 
	override public function getAlpha():Float
	{
		return untyped Std.parseFloat(this._nativeReference.style.opacity);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden methods to transform the dom object and manipulate it's matrix
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * when the matrix is set, update also
	 * the value of the transform CSS property of this
	 * HTML DOM native element
	 * @param	matrix
	 */
	override public function setMatrix(matrix:Matrix):Matrix
	{
		super.setMatrix(matrix);
		
		//type the native dom object
		var nativeSprite:HtmlDom = this._nativeReference;
		
		//get the data of the cross-platform matrix
		var matrixData:MatrixData = matrix.getMatrixData();
		
		var cssMatrixProperty:String = "matrix(" + matrixData.a + "," + matrixData.b + "," + matrixData.c + "," + matrixData.d + "," + matrixData.e + "," + matrixData.f + ")";
		
		//first test if the transform property is set for the current browser,
		//else test vendor specific properties
		if (untyped this._nativeReference.style.transform != null)
		{
			untyped this._nativeReference.style.transform = cssMatrixProperty;
			untyped this._nativeReference.style.transformOrigin = "0 0";
		}
		if (untyped this._nativeReference.style.MozTransform != null)
		{
			untyped this._nativeReference.style.MozTransform = cssMatrixProperty;
			untyped this._nativeReference.style.MozTransformOrigin = "0 0";
		}
		else if (untyped this._nativeReference.style.WebkitTransform != null)
		{
			untyped this._nativeReference.style.WebkitTransform = cssMatrixProperty;
			untyped this._nativeReference.style.WebkitTransformOrigin = "0 0";
		}
		else if (untyped this._nativeReference.style.OTransform != null)
		{
			untyped this._nativeReference.style.OTransform = cssMatrixProperty;
			untyped this._nativeReference.style.OTransform = "0 0";
		}
		
		return this._matrix;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Setters to manipulate the JavaScript DOMObject
	// set the following attributes : x,y,width,height
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setX(value:Int):Int 
	{
		super.setX(value);
		this._nativeReference.style.left = value + "px";
		return this._x;
	}
	
	override public function setY(value:Int):Int 
	{
		super.setY(value);
		this._nativeReference.style.top = value + "px";
		return this._y;
	}
	
	override public function setWidth(value:Int):Int
	{
		super.setWidth(value);
		this._nativeReference.style.width = value +"px";
		return this._width;
	}
	
	override public function setHeight(value:Int):Int 
	{
		super.setHeight(value);
		this._nativeReference.style.height = value + "px";
		return this._height;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a native DOMObject z order in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting the z-order on an HTML element,
	 * all the siblings z-indexes must be updated. If they
	 * are superior or equal to the z-index set on the current element,
	 * they are incremented
	 * @param	value the z index to set
	 */
	override public function setZOrder(value:Int):Int 
	{
		//if the z-index is outside of the children range, 
		//set it as the last z-index of the range
		if (value > _parent.getChildren().length - 1)
		{
			value = _parent.getChildren().length - 1;
		}
		
		var nativeParent:HtmlDom = this._nativeReference.parentNode;
		var numChildren:Int = nativeParent.childNodes.length;
		
		var oldIndex:Int = getZOrder();
		var newIndex:Int = value;
		
		//check all the siblings of the current native DOM element,
		//and increment their z index as needed in two loops
		
		//the first loop "removes" the moved item from the z-index position
		//so every z-index superior to the removed z-index is decremented as their is
		//one less z-index value
		for (i in 0...numChildren)
		{
			var currentChildren:HtmlDom = nativeParent.childNodes[i];
			
			//check if there is a style attribute to prevent manipulating text node
			if (currentChildren.style != null)
			{
				var currentChildrenZIndex:Int = currentChildren.style.zIndex;
				if (currentChildrenZIndex > oldIndex)
				{
					currentChildrenZIndex--;
					currentChildren.style.zIndex = currentChildrenZIndex;
				}
			}
		}
		
		//the second loop "insert" the moved item into the z-indexes
		//so every z-index superior or equal to the inserted item is 
		//incremented
		for (i in 0...numChildren)
		{
			var currentChildren:HtmlDom = nativeParent.childNodes[i];
			if (currentChildren.style != null)
			{
				var currentChildrenZIndex:Int = currentChildren.style.zIndex;
				if (currentChildrenZIndex >= newIndex)
				{
					currentChildrenZIndex++;
					currentChildren.style.zIndex = currentChildrenZIndex;
				}
			}
		}
		
		//set the z-index of the current element
		this._nativeReference.style.zIndex = value;
		
		return value;
	}
	
	override public function getZOrder():Int 
	{
		return this._nativeReference.style.zIndex;
	}
	
}