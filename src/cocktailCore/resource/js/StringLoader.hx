/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.resource.js;

import cocktailCore.resource.abstract.AbstractResourceLoader;
import cocktailCore.resource.abstract.AbstractStringLoader;

/**
 * Implementation of StringLoader for the JavaScript runtime, used to load resource
 * such as ax XML or JSON file using AJAX. It used the default implementation, found in 
 * it's parent class, the haxe.Http class acting as an abstraction layer
 * @author Yannick DOMINGUEZ
 */
class StringLoader extends AbstractStringLoader
{
	public function new() 
	{
		super();
	}
}