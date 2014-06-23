/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.hittest;

import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.geom.GeomData;
import cocktail.core.stacking.StackingContext;

/**
 * Manages hit testing of the document.
 * For a given point can return element renderers
 * and layers intersecting it and can order
 * them by z-index 
 * 
 * When hit testing, the stacking context tree
 * is traversed recursively and hit test
 * each of its own layer and each layer hit tests each 
 * of its own element renderers
 * 
 * @author Yannick DOMINGUEZ
 */
class HitTestManager 
{	    	
	/**
	 * Holds the element renderers for the last hit tested
	 * point
	 */
	private var _elementRenderersAtPoint:Array<ElementRenderer>;
	
	/**
	 * The point being hit tested
	 */
	private var _targetPoint:PointVO;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_targetPoint = new PointVO(0.0, 0.0);
		_elementRenderersAtPoint = new Array<ElementRenderer>();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_elementRenderersAtPoint = null;
		_targetPoint = null;
	}
	
	/////////////////////////////////
	// PUBLIC HIT-TESTING METHODS
	////////////////////////////////
	
	/**
	 * For a given point return the top most ElementRenderer whose bounds contain this point. The top
	 * most element is determined by the z-index of the layer renderers. If 2 or more elements matches
	 * the point, the one belonging to the higher layer renderer will be returned
	 * 
	 * TODO 2 : for now traverse all tree, but should instead return as soon as an ElementRenderer
	 *	is found
	 * 
	 * @param	stackingContext the root stacking context where the hit test begins
	 * @param	x the target x point relative to the window
	 * @param	y the target y point relative to the window
	 */
	public function getTopMostElementRendererAtPoint(stackingContext:StackingContext, x:Float, y:Float):ElementRenderer
	{
		_targetPoint.x = x;
		_targetPoint.y = y;
		
		_elementRenderersAtPoint = [];
		
		//get all the elementRenderers under the point, update the element renderers array
		getElementRenderersAtPointInStackingContext(_elementRenderersAtPoint, stackingContext, _targetPoint);
		//return the top most, the last of the array
		return _elementRenderersAtPoint[_elementRenderersAtPoint.length - 1];
	}
	
	/////////////////////////////////
	// PRIVATE HIT-TESTING METHODS
	////////////////////////////////
	
	/**
	 * For a given stacking context, hit test
	 * all the layer belonging to this stacking context,
	 * and start hit test of its child stacking context
	 */
	private function getElementRenderersAtPointInStackingContext(elementRenderersAtPoint:Array<ElementRenderer>, stackingContext:StackingContext, point:PointVO):Void
	{
		getElementRenderersAtPointInLayers(elementRenderersAtPoint, stackingContext.layerRenderer, point);
	
		var child:StackingContext = stackingContext.firstChild;
		while (child != null)
		{
			getElementRenderersAtPointInStackingContext(elementRenderersAtPoint, child, point);
			child = child.nextSibling;
		}
	}
	
	/**
	 * For a given layer hit test
	 * all the element renderers belonging
	 * to this layer and start hit test of
	 * child layers which belongs to the same stacking
	 * context
	 */
	private function getElementRenderersAtPointInLayers(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, point:PointVO):Void
	{
		getElementRenderersAtPointInLayer(elementRenderersAtPoint, layer, layer.rootElementRenderer, point);
		
		var child:LayerRenderer = layer.firstChild;
		while (child != null)
		{
			if (child.hasOwnStackingContext == false)
			{
				getElementRenderersAtPointInLayers(elementRenderersAtPoint, child, point);
			}
			
			child = child.nextSibling;
		}
	}
	
	
	/**
	 * For a given layer, return all of the ElementRenderer belonging to this
	 * layer whose bounds contain the target point.
	 */
	private function getElementRenderersAtPointInLayer(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, renderer:ElementRenderer, point:PointVO):Void
	{
		//hit test renderer, stored if point within bounds
		hitTestElementRenderer(elementRenderersAtPoint, renderer, point);
		
		var child:ElementRenderer = renderer.firstChild;
		//loop in all the ElementRenderer belonging to the target layer
		while(child != null)
		{
			if (child.layerRenderer == layer)
			{
				//if the child has child of its own, hit test them
				if (child.firstChild != null)
				{
					getElementRenderersAtPointInLayer(elementRenderersAtPoint, layer, child, point);
				}
				else
				{
					hitTestElementRenderer(elementRenderersAtPoint, child, point);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Hit test a given element renderer, if the provided
	 * point is within its bounds, store the element renderer
	 */
	private function hitTestElementRenderer(elementRenderersAtPoint:Array<ElementRenderer>, elementRenderer:ElementRenderer, point:PointVO):Void
	{
		if (isWithinBounds(point, elementRenderer.hitTestingBounds) == true)
		{
			//ElementRenderer which are not currently visible
			//can't be hit
			if (elementRenderer.isVisible() == true)
			{
				elementRenderersAtPoint.push(elementRenderer);
			}
		}
	}
	
	/**
	 * Utils method determining if a given point is within
	 * a given recrtangle
	 */
	private inline function isWithinBounds(point:PointVO, bounds:RectangleVO):Bool
	{
		return point.x >= bounds.x && (point.x <= bounds.x + bounds.width) && point.y >= bounds.y && (point.y <= bounds.y + bounds.height);	
	}
}
