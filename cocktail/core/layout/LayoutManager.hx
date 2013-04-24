/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout;

import cocktail.core.layout.computer.boxComputers.BlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.BoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.FloatBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InlineBlockBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.InLineBoxStylesComputer;
import cocktail.core.layout.computer.boxComputers.PositionedBoxStylesComputer;
import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.renderer.ElementRenderer;

/**
 * This class holds instances of each class
 * used during layout which only need to
 * be instantiated once as well as 
 * layout helper methods
 * 
 * @author Yannick DOMINGUEZ
 */
class LayoutManager 
{
	/**
	 * Box styles computer, keep an instance of each box style computer
	 */
	
	public var blockBoxStyleComputer:BlockBoxStylesComputer;
	
	public var embeddedBlockBoxStylesComputer:EmbeddedBlockBoxStylesComputer;
	
	public var embeddedFloatBoxStylesComputer:EmbeddedFloatBoxStylesComputer;
	
	public var embeddedInlineBlockBoxStylesComputer:EmbeddedInlineBlockBoxStylesComputer;
	
	public var embeddedInlineBoxStylesComputer:EmbeddedInlineBoxStylesComputer;
	
	public var embeddedPositionedBoxStylesComputer:EmbeddedPositionedBoxStylesComputer;
	
	public var floatBoxStylesComputer:FloatBoxStylesComputer;
	
	public var inlineBlockBoxStylesComputer:InlineBlockBoxStylesComputer;
	
	public var inlineBoxStylesComputer:InLineBoxStylesComputer;
	
	public var positionedBoxStylesComputer:PositionedBoxStylesComputer;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		embeddedBlockBoxStylesComputer = new EmbeddedBlockBoxStylesComputer();
		embeddedFloatBoxStylesComputer = new EmbeddedFloatBoxStylesComputer();
		embeddedInlineBlockBoxStylesComputer = new EmbeddedInlineBlockBoxStylesComputer();
		embeddedInlineBoxStylesComputer = new EmbeddedInlineBoxStylesComputer();
		embeddedPositionedBoxStylesComputer = new EmbeddedPositionedBoxStylesComputer();
		
		blockBoxStyleComputer = new BlockBoxStylesComputer();
		floatBoxStylesComputer = new FloatBoxStylesComputer();
		inlineBoxStylesComputer = new InLineBoxStylesComputer();
		inlineBlockBoxStylesComputer = new InlineBlockBoxStylesComputer();
		positionedBoxStylesComputer = new PositionedBoxStylesComputer();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		embeddedBlockBoxStylesComputer = null;
		embeddedFloatBoxStylesComputer = null;
		embeddedInlineBlockBoxStylesComputer = null;
		embeddedInlineBoxStylesComputer = null;
		embeddedPositionedBoxStylesComputer = null;
		
		blockBoxStyleComputer = null;
		floatBoxStylesComputer = null;
		inlineBoxStylesComputer = null;
		inlineBlockBoxStylesComputer = null;
		positionedBoxStylesComputer = null;
	}
	
	/**
	 * Return the right box style computer for a given element
	 */
	public function getBoxStylesComputer(elementRenderer:ElementRenderer):BoxStylesComputer
	{
		//get the box computer for float
		if (elementRenderer.isFloat() == true)
		{
			if (elementRenderer.isReplaced == true)
			{
				return embeddedFloatBoxStylesComputer;
			}
			else
			{
				return floatBoxStylesComputer;
			}
		}
		//get it for HTMLElement with 'position' value of 'absolute' or 'fixed'
		else if (elementRenderer.isPositioned() == true && elementRenderer.isRelativePositioned() == false)
		{
			if (elementRenderer.isReplaced == true)
			{
				return embeddedPositionedBoxStylesComputer;
			}
			else
			{
				return positionedBoxStylesComputer;
			}
		}
		//anonymous block always use block box style computer
		else if (elementRenderer.isAnonymousBlockBox() == true)
		{
			return blockBoxStyleComputer;
		}
		//else get the box computer based on the display style
		else
		{
			switch(elementRenderer.coreStyle.display)
			{
				case KEYWORD(value):
					switch (value)
					{
						case BLOCK:
							if (elementRenderer.isReplaced == true)
							{
								return embeddedBlockBoxStylesComputer;
							}
							else
							{
								return blockBoxStyleComputer;
							}
							
							
						case INLINE_BLOCK:
							if (elementRenderer.isReplaced == true)
							{
								return embeddedInlineBlockBoxStylesComputer;
							}
							else
							{
								return inlineBlockBoxStylesComputer;
							}
							
						case INLINE:
							if (elementRenderer.isReplaced == true)
							{
								return embeddedInlineBoxStylesComputer;
							}
							else
							{
								return inlineBoxStylesComputer;
							}
							
						//not supposed to happen	
						default:
							return null;
					}
					
					default:
						return null;
			}
		}
	}
}