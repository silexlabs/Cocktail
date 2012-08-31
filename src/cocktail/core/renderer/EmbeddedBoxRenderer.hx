/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.html.HTMLElement;
import cocktail.port.NativeElement;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * Base class for embedded element
 * such as a picture.
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBoxRenderer extends BoxRenderer
{
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to also render the embedded asset, for instance a picture for
	 * an image renderer
	 */
	override private function renderSelf(graphicContext:NativeElement):Void
	{
		super.renderSelf(graphicContext);
		renderEmbeddedAsset(graphicContext);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	override public function isReplaced():Bool
	{
		return true;
	}

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Renders an embedded asset using the graphic context as canvas
	 */
	private function renderEmbeddedAsset(graphicContext:NativeElement)
	{
		//abstract
	}
	

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO 4 : messy
	override private function get_bounds():RectangleData
	{
		bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
		return bounds;
	}
}