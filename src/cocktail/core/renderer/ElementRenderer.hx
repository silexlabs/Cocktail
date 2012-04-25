/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.NativeElement;
import cocktail.core.drawing.DrawingManager;
import cocktail.core.geom.GeomData;
import cocktail.core.style.CoreStyle;

/**
 * This is the base class for element renderers.
 * An ElementRenderer is responsible for displaying
 * elements on the screen.
 * 
 * An element can be for instance an image or a text and
 * is generated by an HTMLElement.
 * 
 * The element renderer as a reference to the bounds of
 * the element which is in the space of containing block
 * which established the formatting context into which
 * this ElementRenderer participates in
 * 
 * The tree build with the ElementRenderers constitute the
 * rendering tree, which is a tree parrallel to the DOM tree.
 * For instance, an html div element, sisplayed as a block 
 * will create a BlockBoxRenderer in the rendering tree
 * 
 * The ElementRenderer is rendered by a LayerRenderer. An 
 * ElementRenderer can either generate its own LayerRenderer
 * or use the one of its parent. For instance, a positioned
 * ElementRenderer (absolute, fixed or relative) always
 * create a new LayerRenderer.
 * 
 * The layerRenderer are used to display the rendering 
 * tree in 3 dimensions, each ElementRenderer generating
 * a LayerRenderer can determine if it is on top or below
 * other LayerRenderer using the z-index style
 * 
 * @author Yannick DOMINGUEZ
 */
class ElementRenderer extends Node
{
	/**
	 * The bounds of the element renderer, relative to its
	 * formatting context root
	 */
	private var _bounds:RectangleData;
	public var bounds(get_bounds, set_bounds):RectangleData;
	
	//TODO : maybe should be containing block bounds instead ?
	private var _globalOrigin:PointData;
	public var globalOrigin(get_globalOrigin, set_globalOrigin):PointData;
	
	private var _positionedOrigin:PointData;
	public var positionedOrigin(get_positionedOrigin, set_positionedOrigin):PointData;
	
	/**
	 * A reference to the Style which instantiated
	 * the ElementRenderer
	 * 
	 * TODO : should be instantiated by the DOM tree instead ?
	 */
	private var _coreStyle:CoreStyle;
	public var coreStyle(getCoreStyle, never):CoreStyle;
	
	/**
	 * A reference to the LayerRenderer rendering this
	 * ElementRenderer
	 */
	private var _layerRenderer:LayerRenderer;
	public var layerRenderer(getLayerRenderer, setLayerRenderer):LayerRenderer;
	
	/**
	 * A reference to the line box generated by this ElementRenderer. For
	 * instance for a Text renderer, and array of Text line box will be created.
	 * For a block box which doesn't establish an inline formatting context,
	 * no line box will be created
	 */ 
	private var _lineBoxes:Array<LineBox>;
	public var lineBoxes(getLineBoxes, setLineBoxes):Array<LineBox>;
	
	/**
	 * class constructor. init class attribute
	 * @param	htmlElement the Style which created
	 * the ElementRenderer
	 */
	public function new(style:CoreStyle) 
	{
		super();
		_coreStyle = style;
		
		_positionedOrigin = {
			x:0.0,
			y:0.0
		}
		_bounds = {
			x:0.0,
			y:0.0,
			width : 0.0,
			height: 0.0
		}
		_globalOrigin = {
			x:0.0,
			y:0.0
		}
		
		_lineBoxes = new Array<LineBox>();
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Render the element using runtime specific
	 * API and return an array of NativeElement from it
	 */
	public function render():Array<NativeElement>
	{
		return [];
	}
	
	private function getChildrenBounds(childrenBounds:Array<RectangleData>):RectangleData
	{

		var bounds:RectangleData;
		
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		
		for (i in 0...childrenBounds.length)
		{
			if (childrenBounds[i].x < left)
			{
				left = childrenBounds[i].x;
			}
			if (childrenBounds[i].y < top)
			{
				top = childrenBounds[i].y;
			}
			if (childrenBounds[i].x + childrenBounds[i].width > right)
			{
				right = childrenBounds[i].x + childrenBounds[i].width;
			}
			if (childrenBounds[i].y + childrenBounds[i].height  > bottom)
			{
				bottom = childrenBounds[i].y + childrenBounds[i].height;
			}
		}
			
		bounds = {
					x:left,
					y:top,
					width : right - left,
					height :  bottom - top,
				}
		
		//need to implement better fix,
		//sould not be negative
		if (bounds.width < 0)
		{
			bounds.width = 0;
		}
		if (bounds.height < 0)
		{
			bounds.height = 0;
		}
				
		return bounds;
		
	}
	
	/////////////////////////////////
	// PUBLIC HELPER METHODS
	// TODO : shouldn't have to repeat this
	// from CoreStyle
	////////////////////////////////
	
	public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	public function canHaveChildren():Bool
	{
		return false;
	}
	
	public function isFloat():Bool
	{
		return _coreStyle.isFloat();
	}
	
	public function isPositioned():Bool
	{
		return _coreStyle.isPositioned();
	}
	
	public function isInlineLevel():Bool
	{
		return _coreStyle.isInlineLevel();
	}
	
	public function isEmbedded():Bool
	{
		return true;
	}
	
	public function isText():Bool
	{
		return false;
	}
	
	public function isInitialContainer():Bool
	{
		return false;
	}
	
	public function isDisplayed():Bool
	{
		return _coreStyle.isDisplayed();
	}
	
	/////////////////////////////////
	// SETTERS/GETTERS
	////////////////////////////////
	
	private function getLineBoxes():Array<LineBox>
	{
		return _lineBoxes;
	}
	
	private function setLineBoxes(value:Array<LineBox>):Array<LineBox>
	{
		return _lineBoxes = value;
	}
	
	private function setLayerRenderer(value:LayerRenderer):LayerRenderer
	{
		return _layerRenderer = value;
	}
	
	private function getLayerRenderer():LayerRenderer
	{
		return _layerRenderer;
	}
	
	private function getCoreStyle():CoreStyle
	{
		return _coreStyle;
	}
	
	private function get_bounds():RectangleData
	{
		return _bounds;
	}
	
	private function set_bounds(value:RectangleData):RectangleData
	{
		return _bounds = value;
	}
	
	private function get_globalOrigin():PointData
	{
		return _globalOrigin;
	}
	
	private function set_globalOrigin(value:PointData):PointData
	{
		return _globalOrigin = value;
	}
	
	private function get_positionedOrigin():PointData
	{
		return _positionedOrigin;
	}
	
	private function set_positionedOrigin(value:PointData):PointData
	{
		return _positionedOrigin = value;
	}
}