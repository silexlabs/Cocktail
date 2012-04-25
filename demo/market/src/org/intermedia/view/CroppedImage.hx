/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import haxe.Timer;
import feffects.Tween;


/**
 * This class defines a cropped image, i.e. an image cropped by a containerDOM used as a mask
 * 
 * @author Raphael Harmel
 */

class CroppedImage
{
	// node which corresponds to the image mask
	public var node:HtmlDom;
	
	// image to crop
	private var _image:Image;
	
	// onImageLoadSuccess callback
	public var onImageLoadSuccess:Void->Void;
	
	//public function new(imageUrl:String, ?maskSize:Size)
	//public function new(imageUrl:String)
	public function new()
	{
		// create and initialise node
		node = Lib.document.createElement("div");

		// apply mask style so it can crop the image
		//node.style.overflowX = "hidden";
		//node.style.overflowY = "hidden";
		//node.style.display = "inline-block";
		//untyped { node.style.borderRadius = "10px"; };
		//CellStyle.addBorderCss(node);

		//loadThumb(imageUrl);
	}
	
	/**
	 *  load thumb image
	 */
	public function loadThumb(imageUrl:String):Void
	{
		// create image
		_image = cast Lib.document.createElement("img");
		// load image
		_image.onload = onImageLoadSuccessCallback;
		_image.src = imageUrl;
	}
	
	/**
	 * image load success callback
	 */
	private function onImageLoadSuccessCallback(event:Event):Void
	{
		// apply image start style so it is invisible (for fade-in)
		untyped { _image.style.opacity = 0; };
		
		node.appendChild(_image);
		
		// display thumb using a random effect
		Timer.delay(fadeIn, Std.random(Constants.CELL_THUMB_APPARITION_DELAY));
		
		if (onImageLoadSuccess != null)
		{
			onImageLoadSuccess();
		}
	}
	
	/**
	 * thum display fade in
	 */
	private function fadeIn():Void
	{
		// create the tween
        var tween = new Tween( 0, 1, 400 );
		tween.setTweenHandlers( tweenOpacity, tweenEnd );
        // launch the tween
        tween.start();
	}
	
	/**
	 * opacity tweening
	 * @param	e
	 */
    private function tweenOpacity( e : Float )
    {
        untyped { _image.style.opacity = e;};
    }

    /**
     * opacity tweening end
	 * 
     * @param	e
     */
	function tweenEnd(e : Float )
	{
		
	}
	
	/**
	 * Resets the style of mask & image, used when resizing
	 */
	public function resetStyle():Void
	{
		// get maskSize in pixel
		var maskSize:Size = { width:node.clientWidth, height:node.clientHeight };
		
		// crop image based on the mask size in pixel
		ImageUtils.cropImage(_image, maskSize);
	}

}
