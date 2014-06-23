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
import cocktail.ds.FastNode;
import cocktail.geom.GeomData;

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
 * in turn call the render method of its layer renderer.
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
	 * recursively.
	 * 
	 * Rendering is in 3 phases :
		 * first stacking context with a negative z-index are
		 * rendered
		 * 
		 * then stacking context with a 0 zindex are rendered, along with layer renderer
		 * with an 'auto' zindex, following layer tree (not stacking context tree) order
		 * 
		 * finally stacking context with a positive z index are rendered
		 * 
	 *	@param dirtyRect the rect in the viewport space which needs
	 * to actually be repainted
	 */
	public function render(dirtyRect:RectangleVO):Void
	{
		layerRenderer.render(dirtyRect);
		
		var child:StackingContext = firstChild;
		
		//flasg determining wether layer with a 0 or auto
		//z-index have already been renderd
		var hasRenderedAutoAndZeroLayers:Bool = false;
		
		while (child != null)
		{
			//check the zindex of the child to be sure to render in right
			//zindex order
			switch(child.layerRenderer.rootElementRenderer.coreStyle.zIndex)
			{
				case INTEGER(value):
					
					//if zindex is 0, then the layer will be rendered
					//along with auto layer, following layer tree order
					if (value == 0)
					{
						
					}
					else
					{
						//first time a positive zindex stacking context is found,
						//render all 0 stacking context and auto layer before this
						//positive stacking context
						if (value > 0 && hasRenderedAutoAndZeroLayers == false)
						{
							renderChildrenInSameStackingContext(layerRenderer, dirtyRect);
							hasRenderedAutoAndZeroLayers = true;
						}
						
						child.render(dirtyRect);
					}
					
				default:	
			}
			
			child = child.nextSibling;
		}
		
		//if 0 and auto zindex were not rendered, for instance
		//if this stacking context only has 0 zindex child, render
		//now
		if (hasRenderedAutoAndZeroLayers == false)
		{
			renderChildrenInSameStackingContext(layerRenderer, dirtyRect);
		}
	}
	
	/**
	 * Render all child layer belonging to this stacking
	 * context as well as child stacking context with a zindex of
	 * 0, which must be rendered in layer tree order
	 */
	private function renderChildrenInSameStackingContext(rootLayer:LayerRenderer, dirtyRect:RectangleVO):Void
	{
		var child:LayerRenderer = rootLayer.firstChild;
		while (child != null)
		{
			if (child.hasOwnStackingContext == false)
			{
				child.render(dirtyRect);
				//render all 'auto' layer renderer belonging
				//to this stacking context recursively
				renderChildrenInSameStackingContext(child, dirtyRect);
			}
			else
			{
				switch(child.rootElementRenderer.coreStyle.zIndex)
				{
					case INTEGER(value):
						if (value == 0)
						{
							//rendering should start at the stacking
							//context so that child stacking context
							//are also rendered
							child.stackingContext.render(dirtyRect);
						}
					default:	
				}
			}
			
			child = child.nextSibling;
		}
	}
	
}
