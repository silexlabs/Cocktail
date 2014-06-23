/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.graphics.BackgroundDrawer;
import cocktail.core.dom.Node;
import cocktail.core.graphics.BorderDrawer;
import cocktail.core.html.HTMLElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.linebox.InlineBox;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.css.CoreStyle;
import haxe.Log;
import cocktail.geom.GeomData;


/**
 * An Inline Box renderer is an element which participates
 * in an inline formatting context and which does not establishes
 * a formatting context.
 * 
 * It generates an inline box for each line into which one of its children
 * has inline box.
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBoxRenderer extends FlowBoxRenderer
{
	/**
	 * A reusable rectangle used during inline box
	 * rendering to compute their bounds
	 */
	private var _renderRect:RectangleVO;
	
	/**
	 * class constructor
	 */
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		_renderRect = new RectangleVO();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When rendering, in charge of rendering each inline box created by this InlineBoxRenderer,
	 * in the order of the line box where they are declared
	 */
	override public function render(graphicsContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{	
		var inlineBoxesLength:Int = inlineBoxes.length;
		for (i in 0...inlineBoxesLength)
		{
			var inlineBox:InlineBox = inlineBoxes[i];

			_renderRect.width = inlineBox.bounds.width;
			_renderRect.height = inlineBox.bounds.height;
			_renderRect.x = inlineBox.bounds.x + inlineBox.lineBox.bounds.x + globalBounds.x - scrollOffset.x;
			_renderRect.y = inlineBox.bounds.y + inlineBox.lineBox.bounds.y + globalBounds.y - scrollOffset.y;
			
			//render background if at least a background image or background color should be drawn
			if (coreStyle.hasBackgroundImage == true || coreStyle.hasBackgroundColor == true)
			{
				BackgroundDrawer.render(graphicsContext, _renderRect, coreStyle, this, clipRect);
			}
			
			BorderDrawer.draw(graphicsContext, _renderRect, coreStyle, clipRect);
		}
		
		
		//only call if has children
		if (firstChild != null)
		{
			//render child inline box if needed
			renderChildren(graphicsContext, clipRect, scrollOffset);
		}
	}
	
	/**
	 * inline box renderer create inline boxes, which are
	 * created during layout to contain  inline boxes of children,
	 * one is created per line where there are children inline boxes
	 */
	override public function updateInlineBoxes():Void
	{
		inlineBoxes = new Array<InlineBox>();
		var child:ElementRenderer = firstChild;
		while(child != null)
		{
			child.updateInlineBoxes();
			child = child.nextSibling;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as a InlineBoxRenderer may render its children if it creates its
	 * own layer. For instance if it is relative positioned, it should render all its
	 * inline children
	 */
	override private function renderChildren(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		super.renderChildren(graphicContext, clipRect, scrollOffset);
		
		//if it creates its own layer, render all child inline box renderer
		if (createOwnLayer() == true)
		{
			renderInlineChildren(this, layerRenderer, graphicContext, clipRect, scrollOffset);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * only block level elements can introduce
	 * clearance
	 */
	override public function canHaveClearance():Bool
	{	
		return false;
	}
}
