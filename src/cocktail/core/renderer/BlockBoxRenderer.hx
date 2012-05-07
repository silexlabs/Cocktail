 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.NativeElement;
import cocktail.core.style.CoreStyle;
import haxe.Log;

/**
 * A block box renderer is an element which participate
 * in a block formatting context and which can start
 * either a block or inline formatting context.
 * 
 * When it starts an inline formatting context, it holds
 * an array of root line box which are the start of
 * each of the lines created by this block box.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockBoxRenderer extends FlowBoxRenderer
{
		
	public function new(node:Node) 
	{
		super(node);
	}
}