/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.style.ComputedStyle;
import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
/**
 * A subclass of TextLineBox, a space is lighter as 
 * it doesn't need to instantiate a native text display object,
 * its font metrics are sufficient for layout
 * 
 * @author Yannick DOMINGUEZ
 */
class SpaceLineBox extends TextLineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, fontMetrics:FontMetricsData, fontManager:FontManager) 
	{
		super(elementRenderer, "", fontMetrics, null);
	}
	
	/**
	 * Don't need to create a native text element for space
	 */ 
	override private function initNativeTextElement(text:String, fontManager:FontManager, computedStyle:ComputedStyle):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Spaces don't need to be rendered
	 */
	override public function render(graphicContext:NativeElement, forceRendering:Bool):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function isSpace():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the space width using the font metrics
	 */
	override private function getTextWidth():Float
	{
		return _fontMetrics.spaceWidth;
	}
}