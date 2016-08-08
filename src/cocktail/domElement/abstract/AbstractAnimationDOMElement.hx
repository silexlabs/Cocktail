/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;
import cocktail.domElement.DOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.nativeElement.NativeElement;

/**
 * This DOMElement is in charge of displaying animation such
 * as a .swf file in Flash or a .svg file in HTML
 * 
 * TO DO
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractAnimationDOMElement extends EmbeddedDOMElement
{
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
}