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
import cocktail.port.DrawingManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * EmbeddedLineBoxes wrap an embedded element
 * when it is displayed on a line, such
 * as an image element with a display style of 'inline'
 * 
 * It also wrap inline-block elements starting new formatting
 * context
 * 
 * Those embedded ElementRenderer only have one line box
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedLineBox extends LineBox
{
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Embeded LineBoxes defer rendering to their ElementRenderer
	 */
	override public function render(graphicContext:DrawingManager):Void
	{
		elementRenderer.render(graphicContext);
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * The ascent of an embedded inline box, is always
	 * equal to its ElementRenderer's margin box
	 * 
	 * TODO 3 : should add special case of inline-block whose
	 * ascent is its last line baseline if it establishes an inline
	 * formatting context
	 */
	override private function getLeadedAscent():Float 
	{
		var computedStyle:ComputedStyle = elementRenderer.coreStyle.computedStyle;
		return bounds.height + computedStyle.marginTop + computedStyle.marginBottom;
	}
	
	/**
	 * An embbeded line box don't have any descent
	 */
	override private function getLeadedDescent():Float
	{
		return 0;
	}
	
	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////

	/**
	 * Embedded Line boxes return the bounds of its embedded ElementRenderer
	 */
	override private function get_bounds():RectangleData
	{
		return elementRenderer.bounds;
	}
}