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

/**
 * Manages hit testing of the layer and rendering.
 * For a given point can return element renderers
 * and layers intersecting it and can order
 * them by z-index 
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
	 * @param	layer the root layer where the hit test begins
	 * @param	x the target x point relative to the window
	 * @param	y the target y point relative to the window
	 * @param	scrollX the x scroll offset applied to the point
	 * @param	scrollY the y scroll offset applied to the point
	 */
	public function getTopMostElementRendererAtPoint(layer:LayerRenderer, x:Float, y:Float, scrollX:Float, scrollY:Float):ElementRenderer
	{
		_targetPoint.x = x;
		_targetPoint.y = y;
		
		_elementRenderersAtPoint = new Array<ElementRenderer>();
		
		//get all the elementRenderers under the point, update the element renderers array
		getElementRenderersAtPoint(_elementRenderersAtPoint, layer, _targetPoint, scrollX, scrollY);
		//return the top most, the last of the array
		return _elementRenderersAtPoint[_elementRenderersAtPoint.length - 1];
	}
	
	/////////////////////////////////
	// PRIVATE HIT-TESTING METHODS
	////////////////////////////////
	
	/**
	 * Get all the ElemenRenderer whose bounds contain the given point. The returned
	 * ElementRenderers are ordered by z-index, from most negative to most positive.
	 */
	private function getElementRenderersAtPoint(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		getElementRenderersAtPointInLayer(elementRenderersAtPoint, layer, layer.rootElementRenderer, point, scrollX, scrollY);

		
		if (layer.rootElementRenderer.hasChildNodes() == true)
		{
			getElementRenderersAtPointInChildRenderers(elementRenderersAtPoint, layer, point, scrollX, scrollY);
		}
	}
	
	
	/**
	 * For a given layer, return all of the ElementRenderer belonging to this
	 * layer whose bounds contain the target point.
	 * 
	 * The rendering tree is traversed recursively, starting from the
	 * root element renderer of this layer
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
		
		var length:Int = renderer.childNodes.length;
		//loop in all the ElementRenderer using this LayerRenderer
		for (i in 0...length)
		{
			var child:ElementRenderer = renderer.childNodes[i];
			
			if (child.layerRenderer == layer)
			{
				if (child.hasChildNodes() == true)
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
		}
	}
	private function getElementRenderersAtPointInChildRenderers(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		doGetElementRenderersAtPointInChildRenderers(elementRenderersAtPoint, layer, layer.negativeZIndexChildLayerRenderers, point, scrollX, scrollY);
		doGetElementRenderersAtPointInChildRenderers(elementRenderersAtPoint, layer, layer.zeroAndAutoZIndexChildLayerRenderers, point, scrollX, scrollY);
		doGetElementRenderersAtPointInChildRenderers(elementRenderersAtPoint, layer, layer.positiveZIndexChildLayerRenderers, point, scrollX, scrollY);
	}
	private function doGetElementRenderersAtPointInChildRenderers(elementRenderersAtPoint:Array<ElementRenderer>, layer:LayerRenderer, childRenderers:Array<LayerRenderer>, point:PointVO, scrollX:Float, scrollY:Float):Void
	{
		var length:Int = childRenderers.length;
		for (i in 0...length)
		{
				var child:ElementRenderer = childRenderers[i].rootElementRenderer;
				//TODO 1 : hack, child renderer never 
				//supposed to be null at this point
				if (child != null)
				{
					if (child.createOwnLayer() == true)
					{
						//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
						if (child.isScrollBar() == true)
						{
							getElementRenderersAtPoint(elementRenderersAtPoint, child.layerRenderer, point, scrollX, scrollY);
						}
						//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
						else if (child.coreStyle.getKeyword(child.coreStyle.position) == FIXED)
						{
							getElementRenderersAtPoint(elementRenderersAtPoint, child.layerRenderer, point, scrollX , scrollY);
						}
						else
						{
							getElementRenderersAtPoint(elementRenderersAtPoint, child.layerRenderer, point, scrollX + layer.rootElementRenderer.scrollLeft, scrollY + layer.rootElementRenderer.scrollTop);
						}
					}
				}
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