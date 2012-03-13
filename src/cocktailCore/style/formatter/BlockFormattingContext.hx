/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.formatter;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import cocktailCore.style.renderer.ElementRenderer;
import haxe.Log;

/**
 * This formatting context layout DOMElement below each other
 * generally following the formattable tree order.
 * 
 * There might be exception, for instance if a container DOMElement
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
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/**
	 * Called by the containing DOMElement once each of its children
	 * has been inserted in the formatting context to start the formatting.
	 * 
	 * TODO : implement margin collapsing
	 */
	override public function format(layOutLastLine:Bool = false):Void
	{
		
		doFormat(_elementsInFormattingContext);
		
	}
	
	private function doFormat(elementsInFormattingContext:Array<ElementRenderer>):Void
	{
		//init/reset the formating context data to insert the first element at the
		//origin of the containing block
		_formattingContextData = initFormattingContextData(_containingDOMElement);
		var currentAddedSiblingsHeight:Int = 0;
		_lastInsertedElement = _containingDOMElement.style.elementRenderer;

		var elementsInColumn = new Array<ElementRenderer>();
		
		
		//format all the box element in order
		for (i in 0...elementsInFormattingContext.length)
		{
			if (isSiblingOfLastInsertedElement(elementsInFormattingContext[i]))
			{
				
			}
			else if (isParentOfLastInsertedElement(elementsInFormattingContext[i]))
			{
				_formattingContextData.y -= currentAddedSiblingsHeight;
				currentAddedSiblingsHeight = 0;
				
				for (j in 0...elementsInColumn.length)
				{
					if (isAncestorOfElement(elementsInColumn[j], elementsInFormattingContext[i] ) == true )
					{
						if (elementsInColumn[j].domElement.style.position == fixed)
						{
							Log.trace(elementsInColumn[j].bounds.y);
						}
						
						elementsInColumn[j].bounds.y += elementsInFormattingContext[i].domElement.style.computedStyle.marginTop + elementsInFormattingContext[i].domElement.style.computedStyle.paddingTop;
						elementsInColumn[j].bounds.x += elementsInFormattingContext[i].domElement.style.computedStyle.marginLeft + elementsInFormattingContext[i].domElement.style.computedStyle.paddingLeft;
				
					}
					
				}
				
					
			}
			else
			{
				currentAddedSiblingsHeight = 0;	
			}
			
			
			
			_lastInsertedElement = elementsInFormattingContext[i];
			
			elementsInColumn.push(elementsInFormattingContext[i]);
			
			doInsertElement(elementsInFormattingContext[i], isNextElementALineFeed(elementsInFormattingContext, i));
				
		
			elementsInFormattingContext[i].bounds.y += _containingDOMElement.style.computedStyle.marginTop + _containingDOMElement.style.computedStyle.paddingTop;
			elementsInFormattingContext[i].bounds.x += _containingDOMElement.style.computedStyle.marginLeft + _containingDOMElement.style.computedStyle.paddingLeft;
			
		
		
			
			
			if (elementsInFormattingContext[i].bounds.width > _formattingContextData.maxWidth)
			{
				_formattingContextData.maxWidth = Math.round(elementsInFormattingContext[i].bounds.width);
			}	
			
			_formattingContextData.y += Math.round(elementsInFormattingContext[i].bounds.height);
			
			//TODO : max height might be wrong
			_formattingContextData.maxHeight = _formattingContextData.y;
			
			currentAddedSiblingsHeight += Math.round(elementsInFormattingContext[i].bounds.height);
		}
	}
	
	private function isAncestorOfElement(element:ElementRenderer, ancestor:ElementRenderer):Bool
	{
		var isAncestorOfElement:Bool = false;
		
		
		var parent:ElementRenderer = element.parent;
		while (parent != _containingDOMElement.style.elementRenderer)
		{
			if (parent == ancestor)
			{
				isAncestorOfElement = true;
				break;
			}
			
			parent = parent.parent;
		}
		return isAncestorOfElement;
	}
	
	override public function getStaticPosition(element:ElementRenderer):PointData
	{
		var elementsToFormat:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0..._elementsInFormattingContext.length)
		{
			elementsToFormat.push(_elementsInFormattingContext[i]);
		}
		
		elementsToFormat.push(element);
		
		doFormat(elementsToFormat);
		/**
		if (isSiblingOfLastInsertedElement(element))
			{
				
			}
			else if (isParentOfLastInsertedElement(element))
			{
				_formattingContextData.y -= _currentAddedSiblingsHeight;
				_currentAddedSiblingsHeight = 0;
				
			}
			else
			{
				_currentAddedSiblingsHeight = 0;	
			}
		*/
		var x:Float = element.bounds.x;
		var y:Float = element.bounds.y;
		
		return {x:x, y:y};
	}
	
	private function isParentOfLastInsertedElement(element:ElementRenderer):Bool
	{
		return element.domElement == _lastInsertedElement.domElement.parent;
	}
	
	private function isSiblingOfLastInsertedElement(element:ElementRenderer):Bool
	{
		return _lastInsertedElement.domElement.parent == element.domElement.parent;
	}

	override private function insertEmbeddedElement(element:ElementRenderer):Void
	{
		
		var x:Float = _formattingContextData.x;
		var y:Float = _formattingContextData.y;
		//TODO : should not use offset dimensions
		var width:Float = element.domElement.offsetWidth;
		var height:Float = element.domElement.offsetHeight;
		
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
		var width:Float = element.domElement.offsetWidth;
		var height:Float = element.domElement.offsetHeight;
		
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
			var width:Float = element.domElement.offsetWidth;
			var height:Float = element.domElement.offsetHeight;
			element.bounds = {
				x:x, 
				y:y,
				width:width,
				height:height
			}
			
		
	}

	
	
	
	
	
	

	
}