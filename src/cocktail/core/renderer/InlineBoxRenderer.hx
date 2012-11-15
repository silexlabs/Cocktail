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
import cocktail.core.html.HTMLElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.linebox.InlineBox;
import cocktail.core.graphics.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.css.CoreStyle;
import haxe.Log;
import cocktail.core.geom.GeomData;
import haxe.Stack;

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
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When rendering, in charge of rendering each inline box created by this InlineBoxRenderer,
	 * in the order of the line box where they are declared
	 * 
	 * TODO : instead, when render called, should render each inline box -> but should be done line box by line box, might
	 * cause z-index issue ?
	 */
	override public function render(graphicsContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{	
		var inlineBoxesLength:Int = inlineBoxes.length;

		for (i in 0...inlineBoxesLength)
		{
			var inlineBox:InlineBox = inlineBoxes[i];
			
			//TODO : should line box bounds + global bounds of containing block
			BackgroundManager.render(graphicsContext, inlineBoxes[i].bounds, coreStyle, this, clipRect);
		}
		//render child inline box if needed
		renderChildren(graphicsContext, clipRect, scrollOffset);
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