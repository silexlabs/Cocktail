/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.abstract;

import cocktail.viewport.Viewport;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.domElement.TextFragmentDOMElement;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktailCore.style.ContainerStyle;
import cocktailCore.style.formatter.BlockFormattingContext;
import cocktailCore.style.formatter.FormattingContext;
import cocktailCore.style.formatter.InlineFormattingContext;
import cocktailCore.style.positioner.AbsolutePositioner;
import cocktailCore.style.positioner.BoxPositioner;
import cocktailCore.style.positioner.FixedPositioner;
import cocktailCore.style.positioner.RelativePositioner;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import cocktail.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import cocktailCore.textElement.TextElementData;
import haxe.Timer;

#if flash9
import cocktailCore.style.as3.Style;
#elseif js
import cocktailCore.style.js.Style;
#end

import haxe.Log;

/**
 * This is the style implementation for BodyDOMElement.
 * It inherits from ContainerStyle and implement behaviours
 * specific to the root of the runtime where appropriate
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractBodyStyle extends ContainerStyle
{
	/**
	 * class constructor
	 * @param	domElement
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
		_isInvalid = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function invalidate():Void
	{
		if (this._isInvalid == false)
		{
			this._isInvalid = true;
			var viewPortData:ContainingDOMElementData = {
			globalX:0,
			globalY:0,
			isHeightAuto:false,
			isWidthAuto:false,
			width:new Viewport().width,
			height:new Viewport().height
			}
			
					
			
			var viewPortData2:ContainingDOMElementData = {
			globalX:0,
			globalY:0,
			isHeightAuto:false,
			isWidthAuto:false,
			width:new Viewport().width,
			height:new Viewport().height
			}
			
						
			var viewPortData3:ContainingDOMElementData = {
			globalX:0,
			globalY:0,
			isHeightAuto:false,
			isWidthAuto:false,
			width:new Viewport().width,
			height:new Viewport().height
			}
		
			doLayout(viewPortData, viewPortData2, viewPortData3);
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC DIMENSION AND POSITION METHODS
	// Those method actually apply a processed dimension or position value to 
	// the NativeElement of a target DOMElement.
	// they are runtime specific
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function applyComputedX(domElement:DOMElement, x:Int):Void
	{
		//abstract
	}
	
	override public function applyComputedY(domElement:DOMElement, y:Int):Void
	{
		//abstract
	}
	
	override public function applyComputedWidth(domElement:DOMElement, width:Int):Void
	{
		//abstract
	}
	
	override public function applyComputedHeight(domElement:DOMElement, height:Int):Void
	{
		//abstract
	}
	
	override private function getFormatingContext(previousFormatingContext:FormattingContext = null):FormattingContext
	{
		return new BlockFormattingContext(this._domElement, null);
	}
	
}