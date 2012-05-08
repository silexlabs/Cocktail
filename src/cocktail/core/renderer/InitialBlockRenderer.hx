/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.InitialBlockBackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.style.formatter.BlockFormattingContext;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.style.CoreStyle;
import haxe.Log;

/**
 * This is the ElementRenderer generated by a BodyHTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class InitialBlockRenderer extends BlockBoxRenderer
{
	/**
	 * class constructor. Set the viewport as the bounds
	 * of the ElementRenderer, as a BodyHTMLElement
	 * always covers all of the viewport
	 */
	public function new(node:Node) 
	{
		super(node);
		
		//TODO : re-implement when coreStyle is set
		/**
		var width:Float = cocktail.Lib.window.innerWidth;
		var height:Float = cocktail.Lib.window.innerHeight;
		
		_bounds.width = width;
		_bounds.height = height;
		*/
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
		if (this._isLayingOut == false || immediate == true)
		{
			this._isLayingOut = true;
			var htmlDocument:HTMLDocument = cast(_node.ownerDocument);
			htmlDocument.invalidate(immediate);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the layout of all of the HTMLElements tree which set the bounds
	 * of the all of the rendring tree elements relative to their containing block.
	 * Then set the global bounds (relative to the window) for all of the elements
	 * of the rendering tree
	 */
	public function startLayout():Void
	{
		var windowData:ContainingHTMLElementData = getWindowData();
		
		//the first positioned parent of the body is always the viewport					
		var lastPositionedHTMLElementData:LastPositionedHTMLElementData = {
			elements: new Array<ElementRenderer>(),
			data:windowData
		}
		
		//layout all the HTMLElements. After that they all know their bounds relative to the containing
		//blocks
		layout(windowData, windowData, lastPositionedHTMLElementData, _coreStyle.fontMetrics, null);
		//set the global bounds on the rendering tree. After that all the elements know their positions
		//relative to the window
		setGlobalOrigins(this,0,0, 0,0);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the global bounds (relative to the window) of all the elements of the rendering tree, by
	 * traversing it recursively
	 * 
	 * TODO : should be on ElementRenderer instead for incremental layout
	 * 
	 * @param	elementRenderer the current node in the render tree onto which the global bounds are set
	 * @param	addedX the added x position for the normal flow
	 * @param	addedY the added y position for the norlam flow
	 * @param	addedPositionedX the added X position for positioned elements
	 * @param	addedPositionedY the added Y position for positioned elements
	 */
	private function setGlobalOrigins(elementRenderer:ElementRenderer, addedX:Float, addedY:Float, addedPositionedX:Float, addedPositionedY:Float):Void
	{
		//if the element establishes a new formatting context, then its
		//bounds must be added to the global x and y bounds for the normal flow
		if (elementRenderer.establishesNewFormattingContext() == true)
		{
			//if the element is positioned, it can either add its bounds
			//or positioned origin to the global x and y for normal flow. If it
			//uses its static position, it uses its bounds, else it uses its
			//positioned origin
			if (elementRenderer.isPositioned() == true)
			{
				//TODO : use globalBounds to determine which bounds to add ?
				if (elementRenderer.coreStyle.left != PositionOffset.cssAuto || elementRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedX += elementRenderer.positionedOrigin.x;
					}
					//here the positioned ElementRenderer is fixed and is placed
					//relative to the window. In this case, its x is not added
					//TODO : complet doc + check if necessary everywhere
					else
					{
						addedX = elementRenderer.positionedOrigin.x;
					}
					
				}
				else
				{
					addedX += elementRenderer.bounds.x;
				}
				
				if (elementRenderer.coreStyle.top != PositionOffset.cssAuto || elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedY += elementRenderer.positionedOrigin.y;
					}
					else
					{
						addedY = elementRenderer.positionedOrigin.y;
					}
				}
				else
				{
					addedY += elementRenderer.bounds.y;
				}
			}
			//if the element is not positioned or relatively positioned, it always add
			//its bounds to the global x and y flow
			else
			{
				addedX += elementRenderer.bounds.x;
				addedY += elementRenderer.bounds.y;
			}
		}
		
		//if the element is positioned, it must also add
		//its bounds to the global positioned origin
		if (elementRenderer.isPositioned() == true)
		{
			//absolutely positioned elements either add their static position
			//or their positioned origin
			if (elementRenderer.coreStyle.computedStyle.position != relative)
			{
				if (elementRenderer.coreStyle.left != PositionOffset.cssAuto || elementRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedPositionedX += elementRenderer.positionedOrigin.x;
					}
					else
					{
						addedPositionedX = elementRenderer.positionedOrigin.x;
					}
					
				}
				else
				{
					addedPositionedX += elementRenderer.bounds.x;
				}
				if (elementRenderer.coreStyle.top != PositionOffset.cssAuto || elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					if (elementRenderer.coreStyle.computedStyle.position == absolute)
					{
						addedPositionedY += elementRenderer.positionedOrigin.y;
					}
					else
					{
						addedPositionedY = elementRenderer.positionedOrigin.y;
					}
					
				}
				else
				{
					addedPositionedY += elementRenderer.bounds.y;
				}
			}
			//relative positioned elements always use their bounds, as the relative
			//offset is only applied at render time and isn't used in the bounds
			//computation
			else
			{
				addedPositionedX += elementRenderer.bounds.x;
				addedPositionedY += elementRenderer.bounds.y;
			}
		}
		
		//for its child of the element
		for (i in 0...elementRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			//TODO : doc on added ody margin
			child.globalContainingBlockOrigin = {
				x: addedX + computedStyle.marginLeft,
				y : addedY + computedStyle.marginTop
			}
			
			child.globalPositionnedAncestorOrigin = {
				x: addedPositionedX + computedStyle.marginLeft,
				y : addedPositionedY + computedStyle.marginTop
			}
			
			//call the method recursively if the child has children itself
			if (child.hasChildNodes() == true)
			{
				setGlobalOrigins(child, addedX, addedY, addedPositionedX, addedPositionedY);
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
	 * The root of the runtime always starts a block formatting context
	 */
	override private function getFormattingContext(previousformattingContext:FormattingContext = null):FormattingContext
	{
		return new BlockFormattingContext(cast(this));
	}
	
	/**
	 * The HTMLBodyElement always establishes a block formatting context
	 * for its children
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return true;
	}
	
	override public function isInitialContainer():Bool
	{
		return true;
	}
	
	override private function init():Void
	{
		_backgroundManager = new InitialBlockBackgroundManager();
	}
}