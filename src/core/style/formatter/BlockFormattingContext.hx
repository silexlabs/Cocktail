/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.formatter;
import core.dom.Node;
import core.renderer.FlowBoxRenderer;
import core.style.StyleData;
import core.geom.GeomData;
import core.renderer.BlockBoxRenderer;
import core.renderer.ElementRenderer;
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
	
	override private function doFormat(elementsInFormattingContext:Array<ElementRenderer>):Void
	{
		doFormat2(_formattingContextRoot);
	}
	
	private function doFormat2(elementRenderer:ElementRenderer):Void
	{
		
		var currentAddedSiblingsHeight:Int = 0;
		
		_formattingContextData.x += elementRenderer.style.computedStyle.marginLeft + elementRenderer.style.computedStyle.paddingLeft;
		
		for (i in 0...elementRenderer.childNodes.length)
		{

			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			
			var marginTop:Int = child.style.computedStyle.marginTop;
			
			if (i == 0)
			{
				var firstChild:ElementRenderer = cast(child.firstChild);
				if (firstChild.style.computedStyle.marginTop > marginTop && child.style.computedStyle.paddingTop == 0)
				{
						marginTop = firstChild.style.computedStyle.marginTop;
				}
			}
			
			if (child.hasChildNodes == true)
			{
				if (child.establishesNewFormattingContext() == false)
				{
					doFormat2(child);
				}
			}
		
			
			var marginBottom:Int = child.style.computedStyle.marginBottom;
			
			if (child.nextSibling != null)
			{
				var nextSibling:ElementRenderer = cast(child.nextSibling);
				
				if (nextSibling.style.computedStyle.marginTop > marginBottom)
				{
					marginBottom = 0;
				}
				else
				{
					marginBottom -= nextSibling.style.computedStyle.marginTop;
				}
			}
		
		
			
			var x:Float = _formattingContextData.x;
			var y:Float = _formattingContextData.y + marginTop + elementRenderer.style.computedStyle.paddingTop ;
			var width:Float = child.style.htmlElement.offsetWidth;
			var height:Float = child.style.htmlElement.offsetHeight;
			
			child.bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
	
			_formattingContextData.y += Math.round(child.bounds.height) + marginTop + marginBottom;
			currentAddedSiblingsHeight += Math.round(child.bounds.height) + marginTop + marginBottom;
			
		}
		
		

		_formattingContextData.y -= currentAddedSiblingsHeight;
	}
	
	/**
	 * Insert a floated HTMLElement. overriden by sub-classes
	 * 
	 */
	override private function insertFloat(element:ElementRenderer):Void
	{
		var parent:FlowBoxRenderer = cast( element.parentNode);
		var floatData:FloatData = _floatsManager.computeFloatData(element, _formattingContextData, Math.round(parent.style.computedStyle.width));
		
		var x:Float = floatData.x + parent.style.computedStyle.paddingLeft;
		var y:Float = floatData.y + parent.style.computedStyle.paddingTop;
		var width:Float = floatData.width;
		var height:Float = floatData.height;
		
		element.bounds = {
			x:x,
			y:y,
			width:width,
			height:height
		}
	}
	
}