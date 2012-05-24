/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.ScrollBar;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
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
	public function new(node:Node) 
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * TODO 1 : seems a bit overkill but works to referesh the thumb size
	 */
	override public function layout(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{	
		super.layout(containingBlockData, viewportData, firstPositionedAncestorData, containingBlockFontMetricsData, formattingContext);
		
	//	var scrollBar:ScrollBar = cast(_node);
	//	scrollBar.updateThumbSize();
	}

	
	/**
	 * Get the right containing block dimensions for an ElementRenderer
	 * based on its positioning scheme
	 */
	override private function getRelevantContainingBlockData(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:ContainingBlockData):ContainingBlockData
	{
		var containingBlockDimensions:ContainingBlockData;
		
		switch (computedStyle.position)
		{

			//for 'static' or 'relative' ElementRenderer, takes the containing block dimensions which is the parent	block	
			case cssStatic, relative, fixed, absolute:
				containingBlockDimensions = containingBlockData;
				
		}
		
		return containingBlockDimensions;
	}
	
		/**
	 * Insert the ElementRenderer in the array of absolutely positioned elements if it
	 * in fact an absolutely positioned element
	 */
	override private function storeAbsolutelyPositionedChild(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{
		
	}
}