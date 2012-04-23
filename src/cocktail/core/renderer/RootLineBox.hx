/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.style.CoreStyle;

/**
 * A special kind of line box which represents
 * the start of a line in an inline formatting context.
 * 
 * Each line is stored as a tree of line boxes started
 * by a RootLineBox
 * 
 * @author Yannick DOMINGUEZ
 */
class RootLineBox extends LineBox
{

	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
}