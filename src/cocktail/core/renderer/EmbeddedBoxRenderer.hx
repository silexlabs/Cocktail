/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.html.EmbeddedElement;
import cocktail.core.NativeElement;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
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
	public function new(style:CoreStyle) 
	{
		super(style);
		var computedStyle:ComputedStyleData = style.computedStyle;
		_bounds.width = computedStyle.width + computedStyle.paddingLeft + computedStyle.paddingRight;
		_bounds.height = computedStyle.height + computedStyle.paddingTop + computedStyle.paddingBottom;
	}
	
	/**
	 * Render the embedded asset and return a
	 * NativeElement from it
	 */
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		
		//TODO : check here if it is an Image, Video... or should be instantiated in
		//EmbeddedStyle ? -> Should be styles inheriting from EmbeddedStyle (ImageStyle, VideoStyle...)
		
		
	
		
		#if (flash9 || nme)
		
	
		
		
		//TODO : implement properly hit area for flash_player
		var nativeElement:flash.display.Sprite = cast(_coreStyle.htmlElement.nativeElement);
		
		nativeElement.x = 0;
		nativeElement.y = 0;
		
		nativeElement.graphics.clear();
		
		nativeElement.graphics.beginFill(0xFF0000, 0.0);
		nativeElement.graphics.drawRect(_bounds.x,_bounds.y, _bounds.width,_bounds.height);
		nativeElement.graphics.endFill();

		var embeddedHTMLElement:EmbeddedElement = cast(_coreStyle.htmlElement);
		ret.push(embeddedHTMLElement.embeddedAsset);
		
		embeddedHTMLElement.embeddedAsset.x = _bounds.x + _coreStyle.computedStyle.paddingLeft;
		embeddedHTMLElement.embeddedAsset.y = _bounds.y + _coreStyle.computedStyle.paddingTop;

		embeddedHTMLElement.embeddedAsset.width = _coreStyle.computedStyle.width;
		embeddedHTMLElement.embeddedAsset.height = _coreStyle.computedStyle.height;
		
	
		
		ret.push(nativeElement);
		
		
		#end
		
		
		//TODO : apply transformations, opacity and visibility
		
		//TODO : opacity doesn't work on embedded asset and should also be applied to background
		
		return ret;
	}
	
		/**
	 * Render and position the background color and
	 * image of the element using runtime specific
	 * API and return an array of NativeElement from
	 * it
	 */
	override public function renderBackground():Array<NativeElement>
	{
		var backgrounds:Array<NativeElement> = _backgroundManager.render(_bounds, _coreStyle);
		
		for (i in 0...backgrounds.length)
		{
			#if (flash9 || nme)
			backgrounds[i].x = _bounds.x;
			backgrounds[i].y = _bounds.y;
			#end
		}
		return backgrounds;
	}
	
	//TODO : re-implement + add an ImageRenderer
	//
	///**
	 //* apply a bilinear filtering to the loaded picture
	 //* 
	 //* TODO : should be applied during rendering
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