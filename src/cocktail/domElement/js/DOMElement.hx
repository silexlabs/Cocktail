/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.js;

import cocktail.nativeElement.NativeElement;
import haxe.Log;
import js.Dom;
import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.Matrix;
import cocktail.geom.GeomData;

/**
 * This is the DOMElement implementation for JavaScript. 
 * It manipulates the native HTML DOM
 * @author Yannick DOMINGUEZ
 */
class DOMElement extends AbstractDOMElement
{
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	/**
	 * Set the domElement properties which can be retrieved
	 * from the native HTML DOM element
	 */
	override private function init():Void
	{
		super.init();
		
		//all DOMElements are positioned as absolute to prevent most
		//of browsers inconsistencies regarding margin/padding. 
		//Margin, padding , floating... concepts will be abstracted
		_nativeElement.style.position = "absolute";
		
		if (_nativeElement.style.width != null)
		{
			this._width = Std.parseInt(_nativeElement.style.width);
		}
		else
		{
			this._width = _nativeElement.offsetWidth;
		}
		
		if (_nativeElement.style.height != null)
		{
			this._height = Std.parseInt(_nativeElement.style.height);
		}
		else
		{
			this._height = _nativeElement.offsetHeight;
		}
		
		this._x = Std.parseInt(_nativeElement.style.left);
		this._y = Std.parseInt(_nativeElement.style.top);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attaches this domElement NativeElement (an HTML element) to its
	 * parent NativeElement
	 */
	override public function attach():Void
	{
		this._parent.nativeElement.appendChild(this._nativeElement);
	}
	
	/**
	 * Detaches this domElement NativeElement (an HTML element) from its
	 * parent NativeElement
	 */
	override public function detach():Void
	{
		this._parent.nativeElement.removeChild(this._nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public and private methods to manage the visibility and opacity of the dom element
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
			this._nativeElement.style.visibility = "visible";
		}
		else
		{
			this._nativeElement.style.visibility = "hidden";
		}
		
		return value;
	}
	
	/**
	 * Return wether the native HTML element is visible.
	 */
	override public function getIsVisible():Bool
	{
		if (this._nativeElement.style.visibility == "visible")
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
		untyped this._nativeElement.style.opacity = value;
		return value;
	}
	
	/**
	 * return the opacity of the HTML element, 
	 * from 0 to 1
	 */ 
	override public function getAlpha():Float
	{
		return untyped Std.parseFloat(this._nativeElement.style.opacity);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden methods to transform the dom element and manipulate it's matrix
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
		
		//get the data of the cross-platform matrix
		var matrixData:MatrixData = matrix.getMatrixData();
		
		//report the data to number with 2 decimal
		//as number with too much decimal prevent
		//JS matrix style to work
		var a:Float = matrixData.a;
		a = untyped a.toFixed(2);
		var b:Float = matrixData.b;
		b = untyped b.toFixed(2);
		var c:Float = matrixData.c;
		c = untyped c.toFixed(2);
		var d:Float = matrixData.d;
		d = untyped d.toFixed(2);
		var e:Float = matrixData.e;
		e = untyped e.toFixed(2);
		var f:Float = matrixData.f;
		f = untyped f.toFixed(2);
		
		var cssMatrixProperty:String = "matrix(" + a + "," + b + "," + c + "," + d + "," + e + "," + f + ")";
		
		//first test if the transform property is set for the current browser,
		//else test vendor specific properties
		if (untyped this._nativeElement.style.transform != null)
		{
			untyped this._nativeElement.style.transform = cssMatrixProperty;
			untyped this._nativeElement.style.transformOrigin = "0 0";
		}
		if (untyped this._nativeElement.style.MozTransform != null)
		{
			untyped this._nativeElement.style.MozTransform = cssMatrixProperty;
			untyped this._nativeElement.style.MozTransformOrigin = "0 0";
		}
		else if (untyped this._nativeElement.style.WebkitTransform != null)
		{
			untyped this._nativeElement.style.WebkitTransform = cssMatrixProperty;
			untyped this._nativeElement.style.WebkitTransformOrigin = "0 0";
		}
		else if (untyped this._nativeElement.style.OTransform != null)
		{
			untyped this._nativeElement.style.OTransform = cssMatrixProperty;
			untyped this._nativeElement.style.OTransform = "0 0";
		}
		
		return this._matrix;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Setters to manipulate the JavaScript DOMElement
	// set the following attributes : x,y,width,height
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setX(value:Int):Int 
	{
		super.setX(value);
		
		this._nativeElement.style.left = value + "px";
		return this._x;
	}
	
	override public function setY(value:Int):Int 
	{
		super.setY(value);
		this._nativeElement.style.top = value + "px";
		return this._y;
	}
	
	override public function setWidth(value:Int):Int
	{
		super.setWidth(value);
		this._nativeElement.style.width = value +"px";
		return this._width;
	}
	
	override public function setHeight(value:Int):Int 
	{
		super.setHeight(value);
		this._nativeElement.style.height = value + "px";
		return this._height;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a native DOMElement z order in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting the z-index on an HTML element,
	 * all the siblings z-indexes must be updated. If they
	 * are superior or equal to the z-index set on the current element,
	 * they are incremented
	 * @param	value the z index to set
	 */
	override public function setZIndex(value:Int):Int 
	{
		//if the z-index is outside of the children range, 
		//set it as the last z-index of the range
		if (value > _parent.children.length - 1)
		{
			value = _parent.children.length - 1;
		}
		
		var nativeParent:HtmlDom = this._nativeElement.parentNode;
		var numChildren:Int = nativeParent.childNodes.length;
		
		var oldIndex:Int = this.zIndex;
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
		this._nativeElement.style.zIndex = value;
		
		return value;
	}
	
	override public function getZIndex():Int 
	{
		return this._nativeElement.style.zIndex;
	}
	
}