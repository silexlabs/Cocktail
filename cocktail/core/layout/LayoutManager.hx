/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.layout;

import cocktail.core.boxmodel.BlockBoxStylesComputer;
import cocktail.core.boxmodel.BoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedBlockBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedFloatBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedInlineBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.boxmodel.FloatBoxStylesComputer;
import cocktail.core.boxmodel.InlineBlockBoxStylesComputer;
import cocktail.core.boxmodel.InLineBoxStylesComputer;
import cocktail.core.boxmodel.PositionedBoxStylesComputer;
import cocktail.core.floats.FloatsManager;
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