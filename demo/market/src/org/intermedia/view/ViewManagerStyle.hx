<<<<<<< HEAD
/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;

/**
 * Contains all style applied to ViewManager
 * 
 * @author Raphael Harmel
 */

class ViewManagerStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setBodyStyle(node:HtmlDom):Void
	{
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingBottom = "0px";
		
		node.style.width = "100%";
		node.style.height = "130%";
		
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
	}
	
}

=======
/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;

/**
 * Contains all style applied to ViewManager
 * 
 * @author Raphael Harmel
 */

class ViewManagerStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setBodyStyle(node:HtmlDom):Void
	{
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingBottom = "0px";
		
		node.style.width = "100%";
		node.style.height = "100%";
		
		node.style.overflowX = "hidden";
		node.style.overflowY = "auto";
	}
	
}

>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
