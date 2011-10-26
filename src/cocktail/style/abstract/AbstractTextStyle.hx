/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.Style;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractTextStyle extends Style
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	

	override private function flowChildren(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, formatingContext:FormattingContext = null ):Void
	{
		
		var textDOMElement:TextDOMElement = cast(this._domElement);
		
		var textLine:DOMElement = textDOMElement.createTextLine(formatingContext.getRemainingLineWidth());
		
		
		while( textLine != null)
		{
			
			textLine.style.marginLeft = MarginStyleValue.length(px(0));
			textLine.style.marginRight = MarginStyleValue.length(px(0));
			textLine.style.marginTop = MarginStyleValue.length(px(0));
			textLine.style.marginBottom = MarginStyleValue.length(px(0));
			
			textLine.style.paddingLeft = PaddingStyleValue.length(px(0));
			textLine.style.paddingRight = PaddingStyleValue.length(px(0));
			textLine.style.paddingTop = PaddingStyleValue.length(px(0));
			textLine.style.paddingBottom = PaddingStyleValue.length(px(0));
			
			textLine.style.top = PositionOffsetStyleValue.length(px(0));
			textLine.style.left = PositionOffsetStyleValue.length(px(0));
			textLine.style.right = PositionOffsetStyleValue.length(px(0));
			textLine.style.bottom  = PositionOffsetStyleValue.length(px(0));
			
			textLine.style.minWidth = ConstrainedDimensionStyleValue.none;
			textLine.style.maxWidth = ConstrainedDimensionStyleValue.none;
			textLine.style.minHeight = ConstrainedDimensionStyleValue.none;
			textLine.style.maxHeight = ConstrainedDimensionStyleValue.none;
			
			textLine.style.display = DisplayStyleValue._inline;
			
			textLine.style.position = _static;
			
			textLine.style.width = DimensionStyleValue.auto;
			textLine.style.height = DimensionStyleValue.auto;
			
			textLine.style.float = FloatStyleValue.none;
			textLine.style.clear = ClearStyleValue.none;
			
			textLine.style.computeBoxModelStyle(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions);
			
			formatingContext.insert(textLine);
			Log.trace(formatingContext.getRemainingLineWidth());
			textLine = textDOMElement.createTextLine(formatingContext.getRemainingLineWidth());
		}
	}
	
}