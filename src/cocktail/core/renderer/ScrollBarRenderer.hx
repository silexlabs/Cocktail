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
	 * scrollbars always establishes new stacking context
	 */
	override public function establishesNewStackingContext():Bool
	{
		return true;
	}
	
	override public function scroll(x:Float, y:Float):Void
	{
		#if (flash9 || nme)
		{
			graphicsContext.x = x;
			graphicsContext.y = y;
		}
		#end
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function isAutoZIndexPositioned():Bool
	{
		return false;
	}
	
	/**
	 * The containing block of a scrollbar is always the block box
	 * renderer which instantiated it
	 */
	override private function getContainingBlock():FlowBoxRenderer
	{	
		return getFirstBlockContainer();
	}
}