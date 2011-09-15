/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement;

/**
 * Set the right runtime specific GraphicDOMElement at compile-time
 */
#if flash9
typedef GraphicDOMElement =  cocktail.domElement.as3.GraphicDOMElement;

#elseif js
typedef GraphicDOMElement =  cocktail.domElement.js.GraphicDOMElement;

#elseif doc
/**
 * This is the class that must be instantiated, it is implemented
 * for each cocktail targets
 */
class GraphicDOMElement extends cocktail.domElement.abstract.AbstractGraphicDOMElement { }

#end