/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer.boxComputers;

import cocktail.core.style.AbstractStyle;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitManager;

/**
 * this is the box computer for floated non-embedded HTMLElement
 * such as a floated ContainerHTMLElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class FloatBoxStylesComputer extends InlineBlockBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for floated non-embedded HTMLElements, an auto width is computed as 'shrink-to-fit' once all the children
	 * have been laid out
	 */
	override private function getComputedAutoWidth(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		return 0;
	}

}