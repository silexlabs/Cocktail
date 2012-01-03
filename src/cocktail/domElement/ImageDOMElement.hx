/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement;

/**
 * Set the right runtime specific ImageDOMElement at compile-time
 */
#if (flash9 || cpp || nme)
typedef ImageDOMElement =  cocktailCore.domElement.as3.ImageDOMElement;

#elseif js
typedef ImageDOMElement =  cocktailCore.domElement.js.ImageDOMElement;

#elseif php
typedef ImageDOMElement =  cocktailCore.domElement.php.ImageDOMElement;

#elseif doc
/**
 * This is the class that must be instantiated, it is implemented
 * for each cocktail targets
 */
class ImageDOMElement extends cocktailCore.domElement.abstract.AbstractImageDOMElement { }

#end