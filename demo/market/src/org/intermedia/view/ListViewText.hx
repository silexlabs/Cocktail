/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import org.intermedia.model.ApplicationModel;

/**
 * Text list view
 * 
 * @author Raphael Harmel
 */

class ListViewText extends ListViewBase
{

	public function new() 
	{
		super();
		
	}
	
	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	override private function createCell():CellBase
	{
		var cell:CellText = new CellText();
		return cell;
	}
	
	/**
	 * removes default refreshstyle behaviour
	 */
	override public function refreshStyles():Void
	{
	}


	
}