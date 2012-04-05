/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style;

import core.NativeElement;
import core.HTMLElement;
import core.style.formatter.BlockFormattingContext;
import core.style.formatter.FormattingContext;
import core.style.StyleData;
import core.geom.GeomData;
import core.renderer.ElementRenderer;
import core.renderer.FlowBoxRenderer;
import core.renderer.InitialBlockRenderer;
import core.renderer.LayerRenderer;
import haxe.Log;

#if (flash9 || nme)
import port.flash_player.ContainerStyle;

#elseif js
import core.style.AbstractContainerStyle;
#end

/**
 * This is the style implementation for BodyHTMLElement.
 * It inherits from ContainerStyle and implement behaviours
 * specific to the root of the runtime where appropriate
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractBodyStyle extends ContainerStyle
{
		
	/**
	 * keep references to each of the nativeElements which
	 * are attached to this styled HTMLElement. Those
	 * can be background images, colors, nativeElements
	 * of other HTMLElements...
	 */
	private var _nativeElements:Array<NativeElement>;
	
	/**
	 * class constructor
	 * @param	htmlElement
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
		
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
	 * The BodyHTMLElement doesn't have a parent, so when invalidated,
	 * it always schedule a layout using the viewport dimensions as
	 * its containing HTMLElement dimensions
	 */
	override public function invalidate():Void
	{
		if (this._isDirty == false)
		{
			this._isDirty = true;
			var windowData:ContainingHTMLElementData = getWindowData();
		
			//the first positioned parent of the body is always the viewport					
			var lastPositionedHTMLElementData:LastPositionedHTMLElementData = {
				children: new Array<PositionedHTMLElementData>(),
				data:windowData
			}
			
			scheduleLayout(windowData, lastPositionedHTMLElementData, windowData);
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
	 * styled HTMLElement using runtime specific API
	 */ 
	private function attachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Remove a NativeElement from the
	 * styled HTMLElement using runtime specific API
	 */
	private function detachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Attach an array of NativeElement to the
	 * styled HTMLElement using runtime specific API
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
	 * styled HTMLElement using runtime specific API
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
	 * The BodyHTMLElement create an initial block renderer and always create a new layer
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
	 * The BodyHTMLElement starts the rendering of the rendering tree
	 * 
	 * TODO : should instead be on a Document class
	 */
	override public function layout(containingHTMLElementData:ContainingHTMLElementData, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{	
		//first detach all previously added children
		detachNativeElements(_nativeElements);
		
		super.layout(containingHTMLElementData, lastPositionedHTMLElementData, viewportData, containingHTMLElementFontMetricsData);
		render(_htmlElement.nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A BodyHTMLElement is never inserted into its parent flow as it is
	 * always located at the origin of the viewport, it is automatically
	 * inserted
	 */
	override private function insertHTMLElement(formattingContext:FormattingContext, lastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		
	}
	
	/**
	 * overriden as the BodyHTMLElement, being at the top of the hierarchy, always position its positioned
	 * children
	 */
	override private function positionAbsolutelyPositionedHTMLElementsIfNeeded(childLastPositionedHTMLElementData:LastPositionedHTMLElementData, viewportData:ContainingHTMLElementData):Void
	{
		doPositionAbsolutelyPositionedHTMLElements(childLastPositionedHTMLElementData, viewportData);	
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the dimension of the Window for the HTMLBodyElement
	 */
	override private function getPositionedHTMLElementData():ContainingHTMLElementData
	{
		return getWindowData();
	}
	
	/**
	 * The BodyHTMLElement is always a block container
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
	 * a bodyHTMLElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
}