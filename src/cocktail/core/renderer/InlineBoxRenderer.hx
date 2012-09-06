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
import cocktail.port.GraphicsContext;
import cocktail.port.NativeElement;
import cocktail.core.css.CoreStyle;
import haxe.Log;
import cocktail.core.geom.GeomData;

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
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as InlineBoxRenderer doesn't render a background of his own, it is its
	 * generatd line boxes which render their own backgrounds
	 */
	override private function renderBackground(graphicContext:GraphicsContext):Void
	{
		
	}
	
	/**
	 * Overriden as rendering an inline box renderer consist in rendering all of the 
	 * line boxes it generated
	 */
	override private function renderChildren(graphicContext:GraphicsContext):Void
	{
		super.renderChildren(graphicContext);
		
		//render all the child line boxes which belong to the same
		//stacking context as this InlineBoxRenderer
		renderChildLineBoxes(graphicContext);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually render the child line boxes
	 */
	private function renderChildLineBoxes(graphicContext:GraphicsContext):Void
	{
		var length:Int = lineBoxes.length;
		
		for (i in 0...length)
		{
			var childLineBoxes:Array<LineBox> = getLineBoxesInLine(lineBoxes[i]);
			
			var childLength:Int = childLineBoxes.length;
			for (j in 0...childLength)
			{
				var childLineBox:LineBox = childLineBoxes[j];
				if (childLineBox.elementRenderer.layerRenderer == layerRenderer)
				{
					childLineBox.render(graphicContext);
				}
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as the bounds of an inline box renderer is formed
	 * by the bounds of all of the line boxes it creates during
	 * formatting
	 */
	override private function get_bounds():RectangleVO
	{
		var lineBoxesBounds:Array<RectangleVO> = new Array<RectangleVO>();
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			lineBoxesBounds.push(lineBoxes[i].bounds);
		}
		
		return getChildrenBounds(lineBoxesBounds);
	}
}