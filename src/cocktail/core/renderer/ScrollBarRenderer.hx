/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
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