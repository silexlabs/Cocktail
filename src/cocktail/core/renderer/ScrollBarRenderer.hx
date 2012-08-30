/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;

/**
 * An ElementRenderer for rendering an horizontal or 
 * vertical scrollbar
 * 
 * @author Yannick DOMINGUEZ
 */
class ScrollBarRenderer extends BlockBoxRenderer
{
	/**
	 * class cosntructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function isScrollBar():Bool
	{
		return true;
	}
	
	/**
	 * Scrollbar are always considered block level elements
	 */
	override public function isInlineLevel():Bool
	{
		return false;
	}
	
	/**
	 * scrollbars always create a new layer to render itself
	 */
	override public function createOwnLayer():Bool
	{
		return true;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The containing block of a scrollbar is always the block box
	 * renderer which instantiated it
	 */
	override private function getContainingBlock():FlowBoxRenderer
	{	
		return getFirstBlockContainer();
	}
}