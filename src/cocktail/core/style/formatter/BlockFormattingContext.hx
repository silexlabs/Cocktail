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
		doFormat2(_formattingContextRoot, - _formattingContextRoot.coreStyle.computedStyle.marginLeft, - _formattingContextRoot.coreStyle.computedStyle.marginTop, staticPositionedElement);
	}
	
	private function doFormat2(elementRenderer:ElementRenderer, concatenatedX:Int, concatenatedY:Int, staticPositionedElement:ElementRenderer):Void
	{
		concatenatedX += elementRenderer.coreStyle.computedStyle.paddingLeft  + elementRenderer.coreStyle.computedStyle.marginLeft;
		//TODO : should try to collapse top margin here
		concatenatedY += elementRenderer.coreStyle.computedStyle.paddingTop + elementRenderer.coreStyle.computedStyle.marginTop;

		for (i in 0...elementRenderer.childNodes.length)
		{

			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			//only allow static or relative
			//TODO : when static position element is found, should stop formatting as it is a formatting only done to format
			//this particular children
			if (child.coreStyle.isPositioned() == false || child.coreStyle.isRelativePositioned() == true || child == staticPositionedElement)
			{
				
				//TODO : margin collapsing is messy
				var marginTop:Int = child.coreStyle.computedStyle.marginTop;
				
				if (i == 0)
				{
					if (child.firstChild != null)
					{
						var firstChild:ElementRenderer = cast(child.firstChild);
						if (firstChild.coreStyle.computedStyle.marginTop > marginTop && child.coreStyle.computedStyle.paddingTop == 0)
						{
								marginTop = firstChild.coreStyle.computedStyle.marginTop;
						}
					}
					
				}
				
				var marginBottom:Int = getCollapsedMarginBottom(child);
				/////////////////////////////TODO : margin collapsing is messy
				
				if (child.hasChildNodes() == true)
				{
					if (child.establishesNewFormattingContext() == false)
					{
						doFormat2(child, concatenatedX, concatenatedY, staticPositionedElement);
					}
				}
				
				var x:Float = concatenatedX + child.coreStyle.computedStyle.marginLeft;
				var y:Float = concatenatedY + child.coreStyle.computedStyle.marginTop;
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
	
	private function getCollapsedMarginBottom(child:ElementRenderer):Int
	{
		var marginBottom:Int = child.coreStyle.computedStyle.marginBottom;
		
		if (child.nextSibling != null)
		{
			var nextSibling:ElementRenderer = cast(child.nextSibling);
			
			if (nextSibling.coreStyle.computedStyle.marginTop > marginBottom)
			{
				marginBottom = 0;
			}
			else
			{
				marginBottom -= nextSibling.coreStyle.computedStyle.marginTop;
			}
		}
		
		return marginBottom;
	}
	
	/**
	 * Insert a floated HTMLElement. overriden by sub-classes
	 * 
	 
	override private function insertFloat(element:ElementRenderer):Void
	{
		var parent:FlowBoxRenderer = cast( element.parentNode);
		var floatData:FloatData = _floatsManager.computeFloatData(element, _formattingContextData, Math.round(parent.coreStyle.computedStyle.width));
		
		var x:Float = floatData.x + parent.coreStyle.computedStyle.paddingLeft;
		var y:Float = floatData.y + parent.coreStyle.computedStyle.paddingTop;
		var width:Float = floatData.width;
		var height:Float = floatData.height;
		
		element.bounds = {
			x:x,
			y:y,
			width:width,
			height:height
		}
	}
	*/
}