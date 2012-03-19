/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
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
	 * keep references to each of the nativeElements which
	 * are attached to this styled DOMElement. Those
	 * can be background images, colors, nativeElements
	 * of other DOMElements...
	 */
	private var _nativeElements:Array<NativeElement>;
	
	/**
	 * class constructor
	 * @param	domElement
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		
		this._nativeElements = new Array<NativeElement>();
		
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the rendering of the rendering tree
	 * and attach the resulting nativeElement (background,
	 * border, embedded asset...) to the provided
	 * nativeElement
	 */ 
	public function render(nativeElement:NativeElement):Void
	{
		_nativeElements = _elementRenderer.layerRenderer.render();
		_nativeElements.reverse();
		attachNativeElements(_nativeElements);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	// TODO : should be on a Document object
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach a NativeElement to the
	 * styled DOMElement using runtime specific API
	 */ 
	private function attachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Remove a NativeElement from the
	 * styled DOMElement using runtime specific API
	 */
	private function detachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Attach an array of NativeElement to the
	 * styled DOMElement using runtime specific API
	 */
	private function attachNativeElements(nativeElements:Array<NativeElement>):Void
	{
		for (i in 0...nativeElements.length)
		{
			attachNativeElement(nativeElements[i]);
		}
	}
	
	/**
	 * Remove an array of NativeElement from the
	 * styled DOMElement using runtime specific API
	 */
	private function detachNativeElements(nativeElements:Array<NativeElement>):Void
	{
		for (i in 0...nativeElements.length)
		{
			detachNativeElement(nativeElements[i]);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The BodyDOMElement create an initial block renderer and always create a new layer
	 */
	override private function createElementRenderer(parentElementRenderer:FlowBoxRenderer):ElementRenderer
	{
		var elementRenderer:ElementRenderer = new InitialBlockRenderer(this);
		elementRenderer.layerRenderer = new LayerRenderer(elementRenderer);

		return elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The BodyDOMElement starts the rendering of the rendering tree
	 * 
	 * TODO : should instead be on a Document class
	 */
	override public function layout(containingDOMElementData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData, containingDOMElementFontMetricsData:FontMetricsData):Void
	{	
		//first detach all previously added children
		detachNativeElements(_nativeElements);
		
		super.layout(containingDOMElementData, lastPositionedDOMElementData, viewportData, containingDOMElementFontMetricsData);
		render(_domElement.nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A BodyDOMElement is never inserted into its parent flow as it is
	 * always located at the origin of the viewport, it is automatically
	 * inserted
	 */
	override private function insertDOMElement(formattingContext:FormattingContext, lastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		
	}
	
	/**
	 * overriden as the BodyDOMElement, being at the top of the hierarchy, always position its positioned
	 * children
	 */
	override private function positionAbsolutelyPositionedDOMElementsIfNeeded(childLastPositionedDOMElementData:LastPositionedDOMElementData, viewportData:ContainingDOMElementData):Void
	{
		doPositionAbsolutelyPositionedDOMElements(childLastPositionedDOMElementData, viewportData);	
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The returned dimensions of the Body are always those of the viewport
	 */
	override public function getContainerDOMElementData():ContainingDOMElementData
	{
		return getViewportData();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The BodyDOMElement is always a block container
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
		return new BlockFormattingContext(cast(this._elementRenderer));
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
		return getViewportData().height;
	}
	
	/**
	 * a bodyDOMElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
}