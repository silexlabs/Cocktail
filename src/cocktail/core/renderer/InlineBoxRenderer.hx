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
import cocktail.core.linebox.LineBox;
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
 * It generates a line box for each line into which one of its children
 * participates in.
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
	 */
	override public function render(parentGraphicContext:GraphicsContext):Void
	{	
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden as the bounds of an inline box renderer is formed
	 * by the bounds of all of the line boxes it creates during
	 * formatting
	 */
	override public function updateBounds():Void
	{
		var lineBoxesBounds:Array<RectangleVO> = new Array<RectangleVO>();
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			lineBoxesBounds.push(lineBoxes[i].bounds);
		}
		
		var childrenBounds:RectangleVO =  getChildrenBounds(lineBoxesBounds);
		bounds.x = childrenBounds.x;
		bounds.y = childrenBounds.y;
		bounds.width = childrenBounds.width;
		bounds.height = childrenBounds.height;
	}
}