/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.viewport.Viewport;
import cocktailCore.style.ContainerStyle;
import cocktailCore.style.formatter.BlockFormattingContext;
import cocktailCore.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import cocktailCore.style.renderer.ElementRenderer;
import cocktailCore.style.renderer.FlowBoxRenderer;
import cocktailCore.style.renderer.InitialBlockRenderer;
import cocktailCore.style.renderer.LayerRenderer;
import haxe.Log;

/**
 * This is the style implementation for BodyDOMElement.
 * It inherits from ContainerStyle and implement behaviours
 * specific to the root of the runtime where appropriate
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractBodyStyle extends ContainerStyle
{
	/**
	 * class constructor
	 * @param	domElement
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		
		//the BodyDOMElelement is set to valid by default
		//to allow triggering the first layout when a children
		//will be added to it
		_isDirty = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The BodyDOMElement doesn't have a parent, so when invalidated,
	 * it always schedule a layout using the viewport dimensions as
	 * its containing DOMElement dimensions
	 */
	override public function invalidate():Void
	{
		if (this._isDirty == false)
		{
			this._isDirty = true;
			var viewPortData:ContainingDOMElementData = getViewportData();
		
			//the first positioned parent of the body is always the viewport					
			var lastPositionedDOMElementData:LastPositionedDOMElementData = {
				children: new Array<PositionedDOMElementData>(),
				data:viewPortData
			}
			
			scheduleLayout(viewPortData, lastPositionedDOMElementData, viewPortData);
		}
	}
	
	override private function createElementRenderer(parentElementRenderer:FlowBoxRenderer):ElementRenderer
	{
		var elementRenderer:ElementRenderer = new InitialBlockRenderer(_domElement);
		elementRenderer.layerRenderer = new LayerRenderer(elementRenderer);

		return elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{	
		super.layout(containingDOMElementData, lastPositionedDOMElementData, viewportData, containingDOMElementFontMetricsData);
		render(_domElement.nativeElement);
	}
	
	/**
	 * A BodyDOMElement is never inserted into its parent flow as it is
	 * always located at the origin of the viewport, it is automatically
	 * inserted
	 */
	override private function insertDOMElement(formattingContext:FormattingContext, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		
	}
	
	/**
	 * Overriden because a BodyDOMElement being at the top of the
	 * DOM tree must always position its absolutely positioned
	 * children
	 */
	override private function doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor:Bool, childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Array<ElementRenderer>
	{
		isFirstPositionedAncestor = true;
		return super.doPositionAbsolutelyPositionedDOMElements(isFirstPositionedAncestor, childLastPositionedDOMElementData, viewportData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The return dimensions of the Body are always those of the viewport
	 */
	override public function getContainerDOMElementData():ContainingDOMElementData
	{
		var viewPort:Viewport = new Viewport();
		
		return {
			width:viewPort.width,
			isWidthAuto:this._width == DimensionStyleValue.autoValue,
			height:viewPort.height,
			isHeightAuto:this._height == DimensionStyleValue.autoValue
		};
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		/**
	 * An inline-level DOMElement is one that is
	 * laid out on a line. It will be placed
	 * either next to the preceding DOMElement
	 * or on a new line if the current line
	 * is too short to host it.
	 * 
	 * Wheter an element is inline-level is determined
	 * by its display style
	 */
	override public function isInlineLevel():Bool
	{
		return false;
	}
	
	/**
	 * The root of the runtime always starts a block formatting context
	 */
	override private function getformattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		return new BlockFormattingContext(this._domElement);
	}

	/**
	 * The computed height of the BodyDOMElement is always
	 * the same as the viewport
	 * 
	 * TODO : might be wrong if the Body as top/bottom margin
	 * or padding, maybe should instead override the 
	 * offsetHeight ?
	 */
	override private function getComputedHeight():Int
	{
		return new Viewport().height;
	}
	
	/**
	 * a bodyDOMElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DIMENSION AND POSITION SETTERS
	// Those properties can't be set on the root of the runtime
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setNativeX(domElement:DOMElement, x:Int):Void
	{
		
	}
	
	override public function setNativeY(domElement:DOMElement, y:Int):Void
	{
		
	}
	
	override public function setNativeWidth(width:Int):Void
	{
		
	}
	
	override public function setNativeHeight(height:Int):Void
	{
		
	}
	
	override public function setNativeOpacity(opacity:Float):Void
	{
		
	}
	
	override public function setNativeVisibility(visibility:Bool):Void
	{
		
	}
	
}