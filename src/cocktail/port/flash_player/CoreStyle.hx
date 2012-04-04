/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.geom.Matrix;
import cocktail.core.geom.GeomData;
import cocktail.core.NativeElement;
import cocktail.core.HTMLElement;
import cocktail.core.style.AbstractCoreStyle;
import cocktail.core.style.StyleData;
import flash.text.TextFieldAutoSize;

/**
 * This is the Flash AS3 implementation of the Style object.
 * 
 * It constructs the font metrics object using Flash text engine
 * font metrics. It uses the style object font size and font family
 * value to determine the font metrics
 * 
 * @author Yannick DOMINGUEZ
 */
class CoreStyle extends AbstractCoreStyle
{
	public function new(htmlElement:HTMLElement) 
	{

		super(htmlElement);
	}

}