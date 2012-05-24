 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * EmbeddedLineBoxes wrap an embedded element
 * when it is displayed on a line, such
 * as an image element with a display style of 'inline'
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
	override public function render(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		_elementRenderer.render(graphicContext, relativeOffset);
	}
	
	/////////////////////////////////
	// OVERRIDEN GETTER/SETTER
	////////////////////////////////
	
	/**
	 * The ascent of an embedded inline box, is always
	 * equal to its ElementRenderer's margin box
	 */
	override private function get_leadedAscent():Float 
	{
		return bounds.height + _elementRenderer.coreStyle.computedStyle.marginTop + _elementRenderer.coreStyle.computedStyle.marginBottom;
	}
	
	/**
	 * An embbeded line box don't have any descent
	 */
	override private function get_leadedDescent():Float
	{
		return 0.0;
	}
	
	/**
	 * Embedded Line boxes return the bounds of its embedded ElementRenderer
	 */
	override private function get_bounds():RectangleData
	{
		return _elementRenderer.bounds;
	}
}