/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.css.CoreStyle;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.boxmodel.BoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedBlockBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedFloatBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedInlineBoxStylesComputer;
import cocktail.core.boxmodel.EmbeddedPositionedBoxStylesComputer;
import cocktail.geom.GeomData;
import cocktail.core.layout.LayoutManager;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.layout.LayoutData;

/**
 * Base class for embedded element
 * such as a picture.
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBoxRenderer extends BoxRenderer
{
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		isReplaced = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to also render the embedded asset, for instance a picture for
	 * an image renderer
	 */
	override private function renderSelf(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{ 
		super.renderSelf(graphicContext, clipRect, scrollOffset);
		renderEmbeddedAsset(graphicContext, clipRect, scrollOffset);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Renders an embedded asset using the graphic context as canvas
	 */
	private function renderEmbeddedAsset(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO)
	{
		//abstract
	}
}
