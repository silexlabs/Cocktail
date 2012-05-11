/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.background.BackgroundManager;
import cocktail.core.dom.Node;
import cocktail.core.html.EmbeddedElement;
import cocktail.core.NativeElement;
import cocktail.core.style.computer.boxComputers.BoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedFloatBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBlockBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedInlineBoxStylesComputer;
import cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.font.FontData;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * Base class for embedded element
 * such as a picture.
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
	public function new(node:Node) 
	{
		super(node);
		
		//TODO : at this point, computed styles are false
	
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	

	override private function get_bounds():RectangleData
	{
		_bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		_bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
		
		return _bounds;
	}
	
	override public function isReplaced():Bool
	{
		return true;
	}
	
	/**
	 * Render the embedded asset and return a
	 * NativeElement from it
	 */
	override public function render(graphicContext:NativeElement):Void
	{
		var backgroundManager:BackgroundManager = new BackgroundManager();

		var ret:Array<NativeElement> = backgroundManager.render(_bounds, _coreStyle);
		#if (flash9 || nme)
		for (i in 0...ret.length)
		{
			
			ret[i].x = globalBounds.x;
			ret[i].y = globalBounds.y;
			graphicContext.addChild(ret[i]);
		
		}
		
		//TODO : check here if it is an Image, Video... or should be instantiated in
		//EmbeddedStyle ? -> Should be styles inheriting from EmbeddedStyle (ImageStyle, VideoStyle...)
	
		var embeddedHTMLElement:EmbeddedElement = cast(_node);
		
		graphicContext.addChild(embeddedHTMLElement.embeddedAsset);
	
		embeddedHTMLElement.embeddedAsset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft;
		embeddedHTMLElement.embeddedAsset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop;

		embeddedHTMLElement.embeddedAsset.width = _coreStyle.computedStyle.width;
		embeddedHTMLElement.embeddedAsset.height = _coreStyle.computedStyle.height;
		
		#end
	
		//TODO : apply transformations, opacity and visibility
		
		//TODO : opacity doesn't work on embedded asset and should also be applied to background
		
	}
	
	
	
	//TODO : re-implement + add an ImageRenderer
	//
	///**
	 //* apply a bilinear filtering to the loaded picture
	 //* 
	 //*/
	//private function smoothPicture():Void
	//{
		//cast the native element as a loader
		// and retrieve its bitmap content
		//var typedNativeElement:Loader = cast(this._embeddedAsset);
		//var bitmap:Bitmap = cast(typedNativeElement.content);
		//
		//if (bitmap != null)
		//{
			//activate picture smoothing
			//bitmap.smoothing = true;
		//}
	//}
	
	
	
}