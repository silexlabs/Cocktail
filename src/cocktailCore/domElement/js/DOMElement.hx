/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktail.nativeElement.NativeElement;
import haxe.Log;
import js.Dom;
import cocktailCore.domElement.abstract.AbstractDOMElement;
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

	//////////////////////////////////////////////////////////////////////////////////////////
	// Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a nativeElement z order in the publication
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting the z-index on an HTML element,
	 * all the siblings z-indexes must be updated. If they
	 * are superior or equal to the z-index set on the current element,
	 * they are incremented
	 * @param	value the z index to set
	 */
	override private function setZIndex(value:Int):Int 
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
	
	override private function getZIndex():Int 
	{
		return this._nativeElement.style.zIndex;
	}
	
}