/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.viewport.Viewport;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.Constants;

/**
 * This class defines the styles used by a SwippableListView
 * 
 * @author Raphael Harmel
 */

class SwippableListViewStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function setListsContainerStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.inlineBlock;
		//domElement.style.position = PositionStyleValue.absolute;
		domElement.style.position = PositionStyleValue.staticStyle;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		
		//domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.width = DimensionStyleValue.percent(300);
		domElement.style.height = DimensionStyleValue.percent(100);
	}
	
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function setSwippableListStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.position = PositionStyleValue.absolute;
		
		//domElement.style.display = DisplayStyleValue.block;
		//domElement.style.position = PositionStyleValue.staticStyle;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(Constants.LIST_TOP));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));

		domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.width = DimensionStyleValue.autoValue;
		//domElement.style.width = DimensionStyleValue.length(px(80));
		domElement.style.height = DimensionStyleValue.percent(100);

		domElement.style.overflow = { x:OverflowStyleValue.scroll, y:OverflowStyleValue.hidden };
		//domElement.style.overflow = { x:OverflowStyleValue.hidden, y:OverflowStyleValue.hidden };

	}
	
}
