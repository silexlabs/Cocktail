/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;
import cocktail.core.dom.Node;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import haxe.Log;

/**
 * This formatting context layout HTMLElement below each other
 * generally following the formattable tree order.
 * 
 * There might be exception, for instance if a container HTMLElement
 * with a fixed has overflowing children, its siblings will use
 * the height of the container to be positioned below, not the
 * added height of its children.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockFormattingContext extends FormattingContext
{
	/**
	 * class constructor
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		super(formattingContextRoot);
	}
	
	//TODO : should not be 2 methods
	override private function doFormat(staticPositionedElement:ElementRenderer = null):Void
	{
		//remove margin of formatting context, as child must be placed relative to padding box
		doFormat2(_formattingContextRoot, - _formattingContextRoot.coreStyle.computedStyle.marginLeft, - _formattingContextRoot.coreStyle.computedStyle.marginTop, staticPositionedElement,  _formattingContextRoot.coreStyle.computedStyle.marginTop,  _formattingContextRoot.coreStyle.computedStyle.marginBottom);	

	}
	
	private function doFormat2(elementRenderer:ElementRenderer, concatenatedX:Int, concatenatedY:Int, staticPositionedElement:ElementRenderer, parentCollapsedMarginTop:Int, parentCollapsedMarginBottom:Int):Void
	{
		concatenatedX += elementRenderer.coreStyle.computedStyle.paddingLeft  + elementRenderer.coreStyle.computedStyle.marginLeft;

		concatenatedY += elementRenderer.coreStyle.computedStyle.paddingTop + parentCollapsedMarginTop;

		for (i in 0...elementRenderer.childNodes.length)
		{

			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			//only allow static or relative
			//TODO : when static position element is found, should stop formatting as it is a formatting only done to format
			//this particular children
			if (child.coreStyle.isPositioned() == false || child.coreStyle.isRelativePositioned() == true || child == staticPositionedElement)
			{
				var marginTop:Int = getCollapsedMarginTop(child, parentCollapsedMarginTop);
				
				var marginBottom:Int = getCollapsedMarginBottom(child, parentCollapsedMarginBottom);

				
				if (child.hasChildNodes() == true)
				{
					if (child.establishesNewFormattingContext() == false)
					{
						doFormat2(child, concatenatedX, concatenatedY, staticPositionedElement, marginTop, marginBottom);
					}
				}
				
				var x:Float = concatenatedX + child.coreStyle.computedStyle.marginLeft;
				var y:Float = concatenatedY + marginTop;
				var computedStyle:ComputedStyleData = child.coreStyle.computedStyle;
				var width:Float = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
				var height:Float = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
			

				child.bounds = {
					x:x, 
					y:y,
					width:width,
					height:height
				}
				
				concatenatedY += Math.round(child.bounds.height) + marginTop + marginBottom;

				//find widest line for shrink-to-fit algorithm
				if (child.bounds.x + child.bounds.width + child.coreStyle.computedStyle.marginRight > _formattingContextData.maxWidth)
				{
					_formattingContextData.maxWidth = Math.round(child.bounds.x + child.bounds.width) + child.coreStyle.computedStyle.marginRight;
				}
				
				if (concatenatedY  > _formattingContextData.maxHeight)
				{
					_formattingContextData.maxHeight = concatenatedY;
				}
			}
		}
	}
	
	private function getCollapsedMarginTop(child:ElementRenderer, parentCollapsedMarginTop:Int):Int
	{
		var marginTop:Int = child.coreStyle.computedStyle.marginTop;

		if (child.coreStyle.computedStyle.paddingTop == 0)
		{
			if (child.previousSibling != null)
			{
				var previousSibling:ElementRenderer = cast(child.previousSibling);
				
				if (previousSibling.coreStyle.computedStyle.paddingBottom == 0)
				{
					if (previousSibling.coreStyle.computedStyle.marginBottom > marginTop)
					{
						//TODO : doc, this an exception for negative margin whose height are substracted
						//from collapsed margin height
						if (marginTop > 0)
						{
							marginTop = 0;
						}
					}
				}
			}
			else if (child.parentNode != null)
			{
				var parent:ElementRenderer = cast(child.parentNode);
				
				if (parent.establishesNewFormattingContext() == false)
				{
					if (parent.coreStyle.computedStyle.paddingTop == 0)
					{
						if (parentCollapsedMarginTop > marginTop)
						{
							marginTop = 0;
						}
					}
				}
			}
		}
		
		return marginTop;
	}
	
	private function getCollapsedMarginBottom(child:ElementRenderer, parentCollapsedMarginBottom:Int):Int
	{
		var marginBottom:Int = child.coreStyle.computedStyle.marginBottom;
		
		if (child.coreStyle.computedStyle.paddingBottom == 0)
		{
			if (child.nextSibling != null)
			{
				var nextSibling:ElementRenderer = cast(child.nextSibling);
				
				if (nextSibling.coreStyle.computedStyle.paddingTop == 0)
				{
					if (nextSibling.coreStyle.computedStyle.marginTop > marginBottom)
					{
						marginBottom = 0;
					}
				}
			}
			else if (child.parentNode != null)
			{
				var parent:ElementRenderer = cast(child.parentNode);
				
				if (parent.establishesNewFormattingContext() == false)
				{
					if (parent.coreStyle.computedStyle.paddingBottom == 0)
					{
						if (parentCollapsedMarginBottom > marginBottom)
						{
							marginBottom = 0;
						}
					}
				}
			}
		}
		
		return marginBottom;
	}
}