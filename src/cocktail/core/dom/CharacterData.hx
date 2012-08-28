/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.html.HTMLElement;

/**
 * The CharacterData interface extends Node with a set of attributes and methods for accessing character data in the DOM.
 * For clarity this set is defined here rather than on each object that uses these attributes and methods.
 * No DOM objects correspond directly to CharacterData, though Text and others do inherit the interface from it.
 * 
 * IMPORTANT : this class isn't supposed to inherit from HTMLElement but from Node. However in Haxe/JS, 
 * text nodes also inherit from the HTMLDom classes when they shouldn't. This should be corrected when
 * the Haxe JS standard lib is updated.
 * 
 * @author Yannick DOMINGUEZ
 */
class CharacterData extends HTMLElement
{
	/**
	 * The character data of the node that implements this interface. The DOM implementation 
	 * may not put arbitrary limits on the amount of data that may be stored in a CharacterData node.
	 * However, implementation limits may mean that the entirety of a node's data may not fit into
	 * a single DOMString. In such cases, the user may call substringData
	 * to retrieve the data in appropriately sized pieces
	 */
	public var data:String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super("");
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Cascading doesn't apply to text, only to 
	 * actual HTMLElement
	 */
	override public function cascade(parentChangedProperties:Hash<Void>, programmaticChange:Bool):Void
	{
		
	}
	
	/**
	 * Overriden as cascade doesn't apply
	 * to text
	 */
	override public function invalidateCascade():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as cascade doesn't apply to text
	 */
	override private function initialCascadeSelf():Void
	{
		
	}
	
	/**
	 * Overriden as a text as no style declaration
	 */
	override private function getStyleDeclaration():Void
	{
		
	}
	
	/**
	 * Overriden as Text is not supposed to instantiate
	 * any of the attribute used by atual HTMLElement
	 */
	override private function init():Void
	{	
		
	}
	
	/**
	 * Overriden as Text is not responsible for
	 * starting animations, only actual HTMLElement
	 */
	override public function startPendingAnimation():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeValue():String 
	{
		return data;
	}
	
	override private function set_nodeValue(value:String):String 
	{
		return data = value;
	}
}