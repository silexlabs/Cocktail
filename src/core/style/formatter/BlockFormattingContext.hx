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
		initFormattingContextData();
		doFormat2(_formattingContextRoot, 0);
		
		return;
		
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		initFormattingContextData();
		var currentAddedSiblingsHeight:Int = 0;
		_lastInsertedElement = _formattingContextRoot;

		var elementsInColumn = new Array<ElementRenderer>();
		
		
		//format all the box element in order
		for (i in 0...elementsInFormattingContext.length)
		{
			
			if (elementsInFormattingContext[i].isFloat() == true)
			{
				//doInsertElement(elementsInFormattingContext[i], isNextElementALineFeed(elementsInFormattingContext, i));
			}
			else
			{
				
				var marginTop:Int = elementsInFormattingContext[i].style.computedStyle.marginTop;
				var marginBottom:Int = elementsInFormattingContext[i].style.computedStyle.marginBottom;
				
				if (elementsInFormattingContext[i].parentNode == _lastInsertedElement.parentNode)
				{
					if (marginTop > _lastInsertedElement.style.computedStyle.marginBottom)
					{
						
					}
					else
					{ 
						marginTop = 0;
					}
				}
				else if (elementsInFormattingContext[i] == _lastInsertedElement.parentNode)
				{
					
					_formattingContextData.y -= currentAddedSiblingsHeight;
					currentAddedSiblingsHeight = 0;
					
					for (j in 0...elementsInColumn.length)
					{
						if (isAncestorOfElement(elementsInColumn[j], elementsInFormattingContext[i] ) == true )
						{

							
							elementsInColumn[j].bounds.y += marginTop + elementsInFormattingContext[i].style.computedStyle.paddingTop;
							elementsInColumn[j].bounds.x += elementsInFormattingContext[i].style.computedStyle.marginLeft + elementsInFormattingContext[i].style.computedStyle.paddingLeft;
					
						}
						
					}
					
						
				}
				//herer its child or grand child
				else
				{
					currentAddedSiblingsHeight = 0;	
				}
				
				
				
				_lastInsertedElement = elementsInFormattingContext[i];
				
				elementsInColumn.push(elementsInFormattingContext[i]);
				
				_formattingContextData.x = _floatsManager.getLeftFloatOffset(_formattingContextData.y);
				
				//doInsertElement(elementsInFormattingContext[i], isNextElementALineFeed(elementsInFormattingContext, i));
				//_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, Math.round(elementsInFormattingContext[i].bounds.width), Math.round(elementsInFormattingContext[i].parent.bounds.width));
			
				var element = elementsInFormattingContext[i];
				
				var x:Float = _formattingContextData.x;
				var y:Float = _formattingContextData.y;
				var width:Float = element.style.htmlElement.offsetWidth;
				var height:Float = element.style.htmlElement.offsetHeight;
		
				element.bounds = {
					x:x, 
					y:y,
					width:width,
					height:height
				}
				
			
				elementsInFormattingContext[i].bounds.y += _formattingContextRoot.style.computedStyle.marginTop +  _formattingContextRoot.style.computedStyle.paddingTop;
				elementsInFormattingContext[i].bounds.x +=  _formattingContextRoot.style.computedStyle.marginLeft +  _formattingContextRoot.style.computedStyle.paddingLeft;
				
			
			
				
				
				if (elementsInFormattingContext[i].bounds.width > _formattingContextData.maxWidth)
				{
					_formattingContextData.maxWidth = Math.round(elementsInFormattingContext[i].bounds.width);
					
				}	
				
				_formattingContextData.y += Math.round(elementsInFormattingContext[i].bounds.height) + marginTop + elementsInFormattingContext[i].style.computedStyle.marginBottom ;
				currentAddedSiblingsHeight += Math.round(elementsInFormattingContext[i].bounds.height) + marginTop + elementsInFormattingContext[i].style.computedStyle.marginBottom;

				removeFloats();
				
				//TODO : max height might be wrong
				_formattingContextData.maxHeight = _formattingContextData.y;
		
					
			}
		
		}
	}
	
	private function doFormat2(elementRenderer:ElementRenderer, concatenatedY:Int ):Void
	{
		
		var currentAddedSiblingsHeight:Int = 0;
		
		for (i in 0...elementRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			var marginTop:Int = child.style.computedStyle.marginTop;
			var marginBottom:Int = child.style.computedStyle.marginBottom;
			
			if (i == 0)
			{
				var firstChild:ElementRenderer = cast(child.firstChild);
				if (firstChild.style.computedStyle.marginTop > marginTop)
				{
					marginTop = firstChild.style.computedStyle.marginTop;
					
				}
				else 
				{
					concatenatedY += marginTop;
				}
			}
			
			if (child.hasChildNodes == true)
			{
				if (child.establishesNewFormattingContext() == false)
				{
					doFormat2(child, concatenatedY);
				}
			}
			
		
		
			
			var x:Float = _formattingContextData.x + child.style.computedStyle.marginLeft;
			var y:Float = _formattingContextData.y + marginTop;
			var width:Float = child.style.htmlElement.offsetWidth;
			var height:Float = child.style.htmlElement.offsetHeight;

			child.bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
		
			_formattingContextData.y += Math.round(child.bounds.height) + marginTop + child.style.computedStyle.marginBottom ;
			currentAddedSiblingsHeight += Math.round(child.bounds.height) + marginTop + child.style.computedStyle.marginBottom;
		}
		
		
		
		_formattingContextData.y -= currentAddedSiblingsHeight;
	}
	
	private function isAncestorOfElement(element:ElementRenderer, ancestor:ElementRenderer):Bool
	{
		var isAncestorOfElement:Bool = false;
		
		
		var parent:Node = element.parentNode;
		while (parent != _formattingContextRoot)
		{
			if (parent == ancestor)
			{
				isAncestorOfElement = true;
				break;
			}
			
			parent = parent.parentNode;
		}
		return isAncestorOfElement;
	}
	
	override private function insertEmbeddedElement(element:ElementRenderer):Void
	{
		var x:Float = _formattingContextData.x;
		var y:Float = _formattingContextData.y;
		//TODO : should not use offset dimensions
		var width:Float = element.style.htmlElement.offsetWidth;
		var height:Float = element.style.htmlElement.offsetHeight;
		
		element.bounds = {
			x:x, 
			y:y,
			width:width,
			height:height
		}
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

	override private function insertFormattingContextRootElement(element:ElementRenderer):Void
	{

		var x:Float = _formattingContextData.x;
		var y:Float = _formattingContextData.y;
		var width:Float = element.style.htmlElement.offsetWidth;
		var height:Float = element.style.htmlElement.offsetHeight;
		
		element.bounds = {
			x:x, 
			y:y,
			width:width,
			height:height
		}
		
	}

	override private function insertContainerElement(element:ElementRenderer):Void
	{
		var x:Float = _formattingContextData.x;
		var y:Float = _formattingContextData.y;
		var width:Float = element.style.htmlElement.offsetWidth;
		var height:Float = element.style.htmlElement.offsetHeight;
		element.bounds = {
			x:x, 
			y:y,
			width:width,
			height:height
		}
		
		Log.trace(element.bounds);
		
	}

	
	
	
	
	
	

	
}