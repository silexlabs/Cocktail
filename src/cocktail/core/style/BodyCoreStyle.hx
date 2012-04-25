/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.FontManager;
import cocktail.core.HTMLDocument;
import cocktail.core.NativeElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.LayerRenderer;
import cocktail.core.font.FontData;
import haxe.Log;

/**
 * This is the style implementation for HTMLBodyElement.
 * It inherits from ContainerStyle and implement behaviours
 * specific to the root of the runtime where appropriate
 * 
 * @author Yannick DOMINGUEZ
 */
class BodyCoreStyle extends ContainerCoreStyle
{
	
	/**
	 * class constructor
	 * @param	htmlElement
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
		
		//the HTMLBodyElement is set to valid by default
		//to allow triggering the first layout when a children
		//will be added to it
		_isDirty = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The HTMLBodyElement doesn't have a parent, so when invalidated,
	 * it always schedule a layout using the window dimensions as
	 * its containing HTMLElement dimensions
	 */
	override public function invalidate(immediate:Bool = false):Void
	{
		//don't call if the body has already scheduled a layout, unless
		//an immediate layout is required
		if (this._isDirty == false || immediate == true)
		{
			this._isDirty = true;
			var htmlDocument:HTMLDocument = cast(_htmlElement.ownerDocument);
			htmlDocument.invalidate(immediate);
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
	 * The main layout method. When called, the HTMLElement's styles (width, height, margins, paddings...)
	 * are computed into actual values, the HTMLElement layout its children if it has any then add itself
	 * to the layout.
	 * 
	 * TODO : update doc
	 * 
	 * @param	containingHTMLElementData the dimensions of the parent HTMLElement into which 
	 * this HTMLElement must be laid out
	 * @param	lastPositionedHTMLElementData the dimensions of the first ancestor HTMLElement in the hierararchy which is 'positioned', meaning that
	 * it has a 'position' style other than 'static'. When positioning an absolutely positioned HTMLElement (a HTMLElement with a 'position' style
	 * of 'absolute'), it it used as origin.
	 * @param	viewportData a reference to the viewport of the document. When positioning a fixed positioned HTMLElement
	 * (a HTMLElement with a 'position' of 'fixed'), it is used as origin
	 * @param containingHTMLElementFontMetricsData contains font metrics of the parent HTMLElement, used for instance
	 * to layout children in an inline formatting context
	 */
	public function startLayout():Void
	{
		var windowData:ContainingHTMLElementData = getWindowData();
		
		//the first positioned parent of the body is always the viewport					
		var lastPositionedHTMLElementData:LastPositionedHTMLElementData = {
			children: new Array<PositionedElementData>(),
			data:windowData
		}
		
		layout(windowData, windowData, lastPositionedHTMLElementData, fontMetrics, null, null);
		setGlobalOrigins(_elementRenderer, _computedStyle.marginLeft, _computedStyle.marginTop);
	}
	
	//TODO : there is still a problem with bbody margin. Should body child have the margins of the body
	//in their bounds ?
	private function setGlobalOrigins(elementRenderer:ElementRenderer, addedX:Float, addedY:Float):Void
	{
		if (elementRenderer.establishesNewFormattingContext() == true)
		{
			//TODO : should be either bounds or static position ?
			//add a method to return the right origin ?
			addedX += elementRenderer.bounds.x;
			addedY += elementRenderer.bounds.y;
			
			if (elementRenderer.isPositioned() == true)
			{
				//TODO : don't do if uses static position
				if (elementRenderer.coreStyle.left != PositionOffset.cssAuto || elementRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					addedX += elementRenderer.positionedOrigin.x;
				}
				if (elementRenderer.coreStyle.top != PositionOffset.cssAuto || elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					addedY += elementRenderer.positionedOrigin.y;
				}
				
			}
			
		}
		
		for (i in 0...elementRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			child.globalOrigin = {
				x: addedX,
				y : addedY
			}
			
			//child.positionedOrigin.x += addedX;
			//child.positionedOrigin.y += addedY;

			
			if (child.hasChildNodes() == true)
			{
				setGlobalOrigins(child, addedX, addedY);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as the HTMLBodyElement, being at the top of the hierarchy, always position its positioned
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
	 * The HTMLBodyElement is always a block container
	 */
	override public function isInlineLevel():Bool
	{
		return false;
	}
	
	/**
	 * The HTMLBodyElement is always an
	 * offset parent
	 */
	override public function isOffsetParent():Bool
	{
		return true;
	}
	
	/**
	 * The HTMLBodyElement has no offset parent has it is
	 * the first visual node of the document
	 */
	override public function getFirstPositionedAncestor():HTMLElement
	{
		return null;
	}
	
	/**
	 * The root of the runtime always starts a block formatting context
	 */
	override private function getFormattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		return new BlockFormattingContext(cast(this._elementRenderer));
	}
	
	/**
	 * The HTMLBodyElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
}