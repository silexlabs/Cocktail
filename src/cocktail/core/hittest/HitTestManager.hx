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
	 * class constructor
	 */
	public function new() 
	{
		_scrolledPoint = new PointVO(0.0, 0.0);
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
	 * @param	point the target point relative to the window
	 * @param	scrollX the x scroll offset applied to the point
	 * @param	scrollY the y scroll offset applied to the point
	 */
	public function getTopMostElementRendererAtPoint(layer:LayerRenderer, point:PointVO, scrollX:Float, scrollY:Float):ElementRenderer
	{
		//get all the elementRenderers under the point
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPoint(layer, point, scrollX, scrollY);
		//return the top most, the last of the array
		return elementRenderersAtPoint[elementRenderersAtPoint.length - 1];
	}
	
	/////////////////////////////////
	// PRIVATE HIT-TESTING METHODS
	////////////////////////////////
	
	/**
	 * Get all the ElemenRenderer whose bounds contain the given point. The returned
	 * ElementRenderers are ordered by z-index, from most negative to most positive.
	 */
	private function getElementRenderersAtPoint(layer:LayerRenderer, point:PointVO, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPointInLayer(layer, layer.rootElementRenderer, point, scrollX, scrollY);

		if (layer.rootElementRenderer.hasChildNodes() == true)
		{
			var childRenderers:Array<ElementRenderer> = getChildRenderers(layer);
			
			var elementRenderersAtPointInChildRenderers:Array<ElementRenderer> = getElementRenderersAtPointInChildRenderers(layer.rootElementRenderer, point, childRenderers, scrollX, scrollY);
			var length:Int = elementRenderersAtPointInChildRenderers.length;
			for (i in 0...length)
			{
				elementRenderersAtPoint.push(elementRenderersAtPointInChildRenderers[i]);
			}
		}
	
		return elementRenderersAtPoint;
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
	private function getElementRenderersAtPointInLayer(layer:LayerRenderer, renderer:ElementRenderer, point:PointVO, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPointInLayer:Array<ElementRenderer> = new Array<ElementRenderer>();
		
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
				elementRenderersAtPointInLayer.push(renderer);
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
					var childElementRenderersAtPointInLayer:Array<ElementRenderer> = getElementRenderersAtPointInLayer(layer, child, point, scrollX, scrollY);
					var childLength:Int = childElementRenderersAtPointInLayer.length;
					for (j in 0...childLength)
					{
						if (childElementRenderersAtPointInLayer[j].isVisible() == true)
						{
							elementRenderersAtPointInLayer.push(childElementRenderersAtPointInLayer[j]);
						}
					}
				}
				else
				{
					_scrolledPoint.x = point.x + scrollX;
					_scrolledPoint.y = point.y + scrollY;
					
					if (isWithinBounds(_scrolledPoint, child.globalBounds) == true)
					{
						if (child.isVisible() == true)
						{
							elementRenderersAtPointInLayer.push(child);
						}
					}
				}
			}
		}
		
		return elementRenderersAtPointInLayer;
	}
	
	private function getElementRenderersAtPointInChildRenderers(elementRenderer:ElementRenderer, point:PointVO, childRenderers:Array<ElementRenderer>, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPointInChildRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var length:Int = childRenderers.length;
		for (i in 0...length)
		{
				
				//TODO 1 : hack, child renderer never 
				//supposed to be null at this point
				if (childRenderers[i] != null)
				{
					var elementRenderersAtPointInChildRenderer:Array<ElementRenderer> = [];
				
					if (childRenderers[i].createOwnLayer() == true)
					{
						//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
						if (childRenderers[i].isScrollBar() == true)
						{
							elementRenderersAtPointInChildRenderer = getElementRenderersAtPoint(childRenderers[i].layerRenderer, point, scrollX, scrollY);
						}
						//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
						else if (childRenderers[i].coreStyle.getKeyword(childRenderers[i].coreStyle.position) == FIXED)
						{
							elementRenderersAtPointInChildRenderer = getElementRenderersAtPoint(childRenderers[i].layerRenderer, point, scrollX , scrollY);
						}
						else
						{
							elementRenderersAtPointInChildRenderer = getElementRenderersAtPoint(childRenderers[i].layerRenderer, point, scrollX + elementRenderer.scrollLeft, scrollY + elementRenderer.scrollTop);
						}
					}
				
					var childLength:Int = elementRenderersAtPointInChildRenderer.length;
					for (j in 0...childLength)
					{
						elementRenderersAtPointInChildRenderers.push(elementRenderersAtPointInChildRenderer[j]);
					}
				}
		}
		
		
		return elementRenderersAtPointInChildRenderers;
	}
	
	/**
	 * Utils method determining if a given point is within
	 * a given recrtangle
	 */
	private function isWithinBounds(point:PointVO, bounds:RectangleVO):Bool
	{
		return point.x >= bounds.x && (point.x <= bounds.x + bounds.width) && point.y >= bounds.y && (point.y <= bounds.y + bounds.height);	
	}
	
	/**
	 * Concatenate all the child element renderers of this
	 * LayerRenderer
	 */
	private function getChildRenderers(layer:LayerRenderer):Array<ElementRenderer>
	{
		var childRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var length:Int = layer.negativeZIndexChildLayerRenderers.length;
		for (i in 0...length)
		{
			var childRenderer:LayerRenderer = layer.negativeZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		length = layer.zeroAndAutoZIndexChildLayerRenderers.length;
		for (i in 0...length)
		{
			var childRenderer:LayerRenderer = layer.zeroAndAutoZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		length = layer.positiveZIndexChildLayerRenderers.length;
		for (i in 0...length)
		{
			var childRenderer:LayerRenderer = layer.positiveZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		
		return childRenderers;
	}
	
}