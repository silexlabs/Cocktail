/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.stacking;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.utils.FastNode;

/**
 * Stacking contexts are used to determine the z-index
 * ordering of the document when rendering the document.
 * 
 * Stacking contexts are ordered as a tree structure.
 * 
 * Each LayerRenderer either creates a new stacking context
 * or use the one of its parent.
 * 
 * There is at least one stacking context for a document,
 * created by the root layer renderer.
 * 
 * Stacking contexts are created by layer renderer which
 * are positioned and have a z-index which is an integer value
 * (not 'auto').
 * 
 * Stacking contexts are ordered by z-index, for instance for a given
 * stacking context, each of its previous sibling will be created by
 * a layerRenderer with a lower z-index than itself and each of its following
 * sibling will have a higher z-index
 * 
 * When rendering of the document starts, the render method is called on each
 * stacking context, in stacking context (z-index) order. Each stacking context
 * in turn call the render method of its layer renderer. Each layer renderer
 * is in turn responsible for rendering each child layer which belong to
 * the same stacking context, in layer tree order
 * 
 * @author Yannick DOMINGUEZ
 */
class StackingContext extends FastNode<StackingContext>
{

	/**
	 * A reference to the layer which instantiated this stacking context
	 */
	public var layerRenderer(default, null):LayerRenderer;
	
	/**
	 * class constuctor
	 */
	public function new(layerRenderer:LayerRenderer) 
	{
		super();
		this.layerRenderer = layerRenderer;
	}
	
	/**
	 * Start the rendering of the layer which 
	 * instantiated this stacking context, and
	 * render all the stacking context tree
	 * recursively
	 */
	public function render():Void
	{
		layerRenderer.render();
		
		var child:StackingContext = firstChild;
		
		while (child != null)
		{
			child.render();
			child = child.nextSibling;
		}
	}
	
}