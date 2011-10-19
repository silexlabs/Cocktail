/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.formatter;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class BlockFormattingContext extends FormattingContext
{

	public function new(domElement:DOMElement, previsouFormatingContext:FormattingContext) 
	{
		super(domElement, previsouFormatingContext);
	}
	
	override private function place(domElement:DOMElement):Void
	{
		super.place(domElement);
		
		startNewLine();
		
		_flowData.x = flowData.firstLineX;
					
		domElement.x = _flowData.x + domElement.style.computedStyle.marginLeft + domElement.style.computedStyle.paddingLeft;
		domElement.y = _flowData.y + _flowData.maxLineHeight + domElement.style.computedStyle.marginTop;
	
		_flowData.y += domElement.style.computedStyle.height + domElement.style.computedStyle.marginTop + 
		domElement.style.computedStyle.paddingTop + domElement.style.computedStyle.paddingBottom + domElement.style.computedStyle.marginBottom;
		
		
		_flowData.totalHeight = _flowData.y + _flowData.maxLineHeight ;
		_flowData.maxLineHeight = 0;
		
	}
	

	

	
	
	
	override public function clearFloat(clear:ClearStyleValue):Void
	{
		switch (clear)
		{
			case none:
				
			case left:
				clearLeft();
			case right:
				clearRight();
			case both:	
				clearBoth();
		}
	}
	
	private function clearLeft():Void
	{
		
	}
	
	private function clearRight():Void
	{
		
	}
	
	private function clearBoth():Void
	{
		clearLeft();
		clearRight();
	}
	
	
	
	

	
}