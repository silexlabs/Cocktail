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
	 * InlineBoxRenderer don't do any rendering, as the rendering of their line boxes
	 * is managed by the closest block container ancestor
	 * 
	 * TODO : instead, when render called, should render each inline box -> but should be done line box by line box, might
	 * cause z-index issue ?
	 */
	override public function render(parentGraphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{	
		
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
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * only block level elements can introduce
	 * clearance
	 */
	override public function hasClearance():Bool
	{	
		return false;
	}
}