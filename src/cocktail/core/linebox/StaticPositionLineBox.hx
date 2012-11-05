/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.geom.GeomData;
import cocktail.core.graphics.GraphicsContext;

/**
 * This line box is used as a place holder for absolutely
 * positioned elements, to determine their static position
 * when formatting an inline formatting context
 * 
 * @author Yannick DOMINGUEZ
 */
class StaticPositionLineBox extends LineBox
{
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as static line box are not supposed
	 * to render their background as they always wrap
	 * a block box renderer caused by an absolutely
	 * positioned element
	 */
	override public function render(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{
		
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHOD
	////////////////////////////////
	
	override public function isStaticPosition():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////

	/**
	 * Return the bounds of the absolutely positioned
	 * element, so that its static bounds can be set
	 * during formatting
	 */
	override private function get_bounds():RectangleVO
	{
		return elementRenderer.bounds;
	}
	
}