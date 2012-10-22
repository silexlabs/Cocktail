/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.hittest;

import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import cocktail.core.stacking.StackingContext;
using cocktail.core.utils.Utils;

/**
 * Manages hit testing of the document.
 * For a given point can return element renderers
 * and layers intersecting it and can order
 * them by z-index 
 * 
 * When hit testing, the stacking context tree
 * is traversed recursively and hit test
 * each of its own layer layer and each layer hit tests each 
 * of its own element renderers
 * 
 * @author Yannick DOMINGUEZ
 */
class HitTestManager 
{	    	
	/**
	 * A point used to determine wether an
	 * ElementRenderer is within a given bound
	 */
	private var _scrolledPoint:PointVO;
	
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
		_scrolledPoint = new PointVO(0.0, 0.0);
		_targetPoint = new PointVO(0.0, 0.0);
		_elementRenderersAtPoint = new Array<ElementRenderer>();
	}
	
	/////////////////////////////////
	// PUBLIC HIT-TESTING METHODS
	////////////////////////////////
	
	/**
	 * For a given point return the top most ElementRenderer whose bounds contain this point. The top
	 * most element is determined by the z-index of the layer renderers. If 2 or more elements matches
	 * the point, the one belonging to the higher layer renderer will be returned
	 * 
	 * TODO 2 : shouldn' the scroll offset be directly added to the point ?
	 * TODO 2 : for now traverse all tree, but should instead return as soon as an ElementRenderer
	 *	is found
	 * 
	 * @param	stackingContext the root stacking context where the hit test begins
	 * @param	x the target x point relative to the window
	 * @param	y the target y point relative to the window
	 * @param	scrollX the x scroll offset applied to the point
	 * @param	scrollY the y scroll offset applied to the point
	 */
	public function getTopMostElementRendererAtPoint(stackingContext:StackingContext, x:Float, y:Float, scrollX:Float, scrollY:Float):ElementRenderer
	{
		_targetPoint.x = x;
		_targetPoint.y = y;
		
		_elementRenderersAtPoint = _elementRenderersAtPoint.clear();
		
		//get all the elementRenderers under the point, update the element renderers array
		getElementRenderersAtPointInStackingContext(_elementRenderersAtPoint, stackingContext, _targetPoint, scrollX, scrollY);
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
	private function getElementRenderersAtPointInStackingContext(elementRenderersAtPoint:Array<ElementRenderer>, stackingContext:StackingContext, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		getElementRenderersAtPointInLayers(elementRenderersAtPoint, stackingContext.layerRenderer, stackingContext.layerRenderer.rootElementRenderer, point, scrollX, scrollY);
	
		var child:StackingContext = stackingContext.firstChild;
		while (child != null)
		{
			getElementRenderersAtPointInStackingContext(elementRenderersAtPoint, child, point, scrollX, scrollY);
			child = child.nextSibling;
		}
	}
	
	/**
	 * For a given layer hit test
	 * all the element renderers belonging
	 * to this layer. Start hit testing of
	 * layers which belongs to the same stacking
	 * context
	 */
	private function getElementRenderersAtPointInLayers(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, renderer:ElementRenderer, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		getElementRenderersAtPointInLayer(elementRenderersAtPoint, layer, renderer, point, scrollX, scrollY);
		
		var child:LayerRenderer = layer.firstChild;
		while (child != null)
		{
			if (child.hasOwnStackingContext == false)
			{
				getElementRenderersAtPointInLayers(elementRenderersAtPoint, child, renderer, point, scrollX, scrollY);
			}
			
			child = child.nextSibling;
		}
	}
	
	
	/**
	 * For a given layer, return all of the ElementRenderer belonging to this
	 * layer whose bounds contain the target point.
	 * 
	 * TODO 2 : can probably be optimised, in one layer, no elements are supposed to
	 * overlap, meaning that only 1 elementRenderer can be returned for each layer
	 */
	private function getElementRenderersAtPointInLayer(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, renderer:ElementRenderer, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		_scrolledPoint.x = point.x + scrollX;
		_scrolledPoint.y = point.y + scrollY;
		
		//if the target point is within the ElementRenderer bounds, store
		//the ElementRenderer
		if (isWithinBounds(_scrolledPoint, renderer.globalBounds) == true)
		{
			//ElementRenderer which are no currently visible
			//can't be hit
			if (renderer.isVisible() == true)
			{
				elementRenderersAtPoint.push(renderer);
			}
		}
		
		scrollX += renderer.scrollLeft;
		scrollY += renderer.scrollTop;
		
		var child:ElementRenderer = renderer.firstChild;
		//loop in all the ElementRenderer belonging to the target layer
		while(child != null)
		{
			if (child.layerRenderer == layer)
			{
				//if the child has child of its own, hit test them
				if (child.firstChild != null)
				{
					getElementRenderersAtPointInLayer(elementRenderersAtPoint, layer, child, point, scrollX, scrollY);
				}
				else
				{
					_scrolledPoint.x = point.x + scrollX;
					_scrolledPoint.y = point.y + scrollY;
					
					if (isWithinBounds(_scrolledPoint, child.globalBounds) == true)
					{
						if (child.isVisible() == true)
						{
							elementRenderersAtPoint.push(child);
						}
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Utils method determining if a given point is within
	 * a given recrtangle
	 */
	private function isWithinBounds(point:PointVO, bounds:RectangleVO):Bool
	{
		return point.x >= bounds.x && (point.x <= bounds.x + bounds.width) && point.y >= bounds.y && (point.y <= bounds.y + bounds.height);	
	}
}