/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.html.HTMLConstants;

/**
 * Anonmymous block are used to wrap inlineBoxRenderer
 * which are children of a block box establishing or particpating
 * in a block formatting context.
 * 
 * Wrapping the inlineBoxRenderer in an anonymous block allows to 
 * keep the invariant of CSS where all the children of a block box
 * must be blocks or all the children must be inline
 * 
 * @author Yannick DOMINGUEZ
 */
class AnonymousBlockBoxRenderer extends BlockBoxRenderer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(Lib.document.createElement(HTMLConstants.HTML_DIV_TAG_NAME));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An anonymous block has only one child, which is the 
	 * wrapped inlineBoxRenderer. When this child
	 * is removed form the DOM, the anonymous block must
	 * also be removed
	 */
	override public function removeChild(oldChild:ElementRenderer):ElementRenderer
	{
		super.removeChild(oldChild);
		//removes itself
		parentNode.removeChild(this);
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	override public function isPositioned():Bool
	{
		return false;
	}
	
	override public function isAnonymousBlockBox():Bool
	{
		return true;
	}
	
	override public function createOwnLayer():Bool
	{
		return false;
	}
	
	override public function isInlineLevel():Bool
	{
		return false;
	}
}