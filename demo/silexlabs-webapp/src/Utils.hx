/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package ;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.DOMElementData;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.textElement.TextElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;


/**
 * This contains the utils methods
 * 
 * @author Raphael Harmel
 */

class Utils 
{

	/**
	 * Initializes a ContainerDOMElement
	 * 
	 * @return the initalized ContainerDOMElement
	 */
	public static function getContainer():ContainerDOMElement
	{
		var ret:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(neutral));
		ret.style.display = block;
		//ret.x = 0;
		//ret.y = 0;
		return ret;
	}
	
	/**
	 * Initializes a ContainerDOMElement containing a text node
	 * 
	 * @return the initalized ContainerDOMElement
	 */
	public static function getTextContainer(text:String):ContainerDOMElement
	{
		var textContainer:ContainerDOMElement = Utils.getContainer();

		textContainer.addText(new TextElement(text));

		return textContainer;
	}
	
	/**
	 * Initializes a GraphicDOMElement
	 * 
	 * @return the initalized GraphicDOMElement
	 */
	public static function getGraphic():GraphicDOMElement
	{
		var ret:GraphicDOMElement = new GraphicDOMElement();
		
		return ret;
	}
	
	/**
	 * Fills a GraphicDOMElement with a rectangle of the specified color
	 * 
	 * @param	domElement
	 * @param	color
	 */
	public static function fillGraphic(domElement:GraphicDOMElement, color:Int):Void
	{
		domElement.clear();
		domElement.beginFill(FillStyleValue.monochrome( { color:color, alpha:100 } ), LineStyleValue.none);
		domElement.drawRect(0, 0, domElement.width, domElement.height);
		domElement.endFill();
		domElement.alpha = 1;
	}

}