/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

/**
 * 
 * A special case of EmbeddedLineBox which
 * wraps an ElementRenderer displayed as InlineBlock
 * 
 * TODO 4 : is it really useful ? EmbeddedLineBox might
 * be able to differientate with establishesNewFormattingContext
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBlockLineBox extends EmbeddedLineBox
{

	/**
	 * class cosntructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	//TODO 2 : should return ascent to the last line, if the inline block
	//establishes an inline formatting context
	override private function get_leadedAscent():Float 
	{
		return bounds.height + _elementRenderer.coreStyle.computedStyle.marginTop + _elementRenderer.coreStyle.computedStyle.marginBottom;
	}
	
}