/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.renderer;

import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
import cocktailCore.style.Style;
import haxe.Log;

/**
 * Base class for embedded element
 * such as a picture
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBoxRenderer extends BoxRenderer
{

	/**
	 * class constructor. Set the width and height
	 * of the element, as for embedded element
	 * they are intrinsic to the embeddded asset
	 */
	public function new(style:Style) 
	{
		super(style);
		_bounds.width = style.htmlElement.offsetWidth;
		_bounds.height = style.htmlElement.offsetHeight;
	}
	
	/**
	 * Render the embedded asset and return a
	 * NativeElement from it
	 */
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		
		//TODO : check here if it is an Image, Video... or should be instantiated in
		//EmbeddedStyle ?
		/*
		var embeddedDOMElement:EmbeddedDOMElement = cast(_style.domElement);
		ret.push(embeddedDOMElement.embeddedAsset);
		
		
		#if (flash9 || nme)
		embeddedDOMElement.embeddedAsset.x = _bounds.x + _style.computedStyle.paddingLeft + _style.computedStyle.marginLeft;
		embeddedDOMElement.embeddedAsset.y = _bounds.y + _style.computedStyle.paddingTop + _style.computedStyle.marginTop;

		embeddedDOMElement.embeddedAsset.width = _style.computedStyle.width;
		embeddedDOMElement.embeddedAsset.height = _style.computedStyle.height;
		#end
		*/
		//TODO : apply transformations, opacity and visibility
		
		//TODO : opacity doesn't work on embedded asset and should also be applied to background
		
		return ret;
	}
	
	
	
}