/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.domElement.DOMElement;
import cocktailCore.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktailCore.style.computer.boxComputers.NoneBoxStylesComputer;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import haxe.Log;

#if (flash9 || cpp || nme)
import cocktailCore.style.as3.Style;
#elseif js
import cocktailCore.style.js.Style;
#end

/**
 * This is the style implementation for embedded
 * DOMElement. Embedded DOMElement include external
 * content in the document, such as picture or video
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractEmbeddedStyle extends Style
{
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE COMPUTING METHODS
	// compute styles definition into usable values
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to use box computer specific to 
	 * embedded DOMElement instead of the default one
	 */
	override private function getBoxStylesComputer():BoxStylesComputer
	{
		var boxComputer:BoxStylesComputer;
		
		//get the embedded box computers based on
		//the positioning scheme
		if (isFloat() == true)
		{
			boxComputer = new EmbeddedFloatBoxStylesComputer();
		}
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new EmbeddedPositionedBoxStylesComputer();
		}
		switch(this._computedStyle.display)
		{
			case block:
				boxComputer = new EmbeddedBlockBoxStylesComputer();
				
			case inlineBlock:
				boxComputer = new EmbeddedInlineBlockBoxStylesComputer();	
			
			case none:
				boxComputer = new NoneBoxStylesComputer();
			
			case inlineStyle:
				boxComputer = new EmbeddedInlineBoxStylesComputer();
		}
		
		return boxComputer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as all inherithing classes of the
	 * Embedded DOMElement are embedded
	 */
	override public function isEmbedded():Bool
	{
		return true;
	}
}