/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import cocktailCore.style.Style;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextFragmentDOMElement extends AbstractTextFragmentDOMElement
{

	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
		
		if (_nativeElement != null)
		{
			if (untyped _nativeElement.textWidth == 0)
			{
				this._width = style.fontMetrics.spaceWidth;
			}
		}
	
	}
	
	override private function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		var relevantWidth:Float;
	
		if (untyped _nativeElement.textWidth == 0)
		{
			//return this._width;
			//relevantWidth = untyped _nativeElement.getAtomBounds(0).width;
			return this._width + _style.computedStyle.letterSpacing + _style.computedStyle.wordSpacing;
			
		}
		else
		{

			return untyped _nativeElement.textWidth ;
		}				
		
	}
	

	override private function getOffsetHeight():Int
	{
		
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		
		//return untyped _nativeElement.textHeight;
		return Math.round(computedStyle.lineHeight);
	}
	

	
}