/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.viewport;


#if (flash9 || cpp || nme)
typedef Viewport = cocktailCore.viewport.as3.Viewport;
#elseif js
typedef Viewport = cocktailCore.viewport.js.Viewport;
#elseif php
typedef Viewport = cocktailCore.viewport.php.Viewport;
#elseif doc
import cocktailCore.viewport.abstract.AbstractViewport;
class Viewport extends AbstractViewport {}
#end	
