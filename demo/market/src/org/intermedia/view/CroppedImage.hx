/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import org.intermedia.model.ApplicationModel;
import haxe.Timer;
import feffects.Tween;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;


/**
 * This class defines utilities methods for images
 * 
 * @author Raphael Harmel
 */

class CroppedImage extends ContainerDOMElement
{
	// image to crop
	private var _image:ImageDOMElement;
	
	// maskSize
	private var _maskSize:Size;
	
	public function new(imageUrl:String, maskSize:Size)
	{
		super();
		_image = new ImageDOMElement();
		_maskSize = maskSize;
		loadThumb(imageUrl);
	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb(imageUrl:String):Void
	{
		// load image
		_image.onLoad = onImageLoadSuccess;
		_image.load(imageUrl);
	}
	
	/**
	 * image load success callback
	 */
	private function onImageLoadSuccess(image:ImageDOMElement):Void
	{
		// set image style. It is needed to do it here as we need to access to the intrisic size of the image,
		// which we can access only when the image has been loaded
		//listStyle.cellThumbnail(cellImage,screenResolutionSize);
		//_cellStyle.thumbnail(_cellImage, _thumbMask);
		// add image to cell
		//this.addChild(_cellImage);

		// apply image start style so it is invisible (for fade-in)
		image.style.opacity = OpacityStyleValue.number(0);
		
		this.addChild(ImageUtils.cropImage(image,_maskSize));
		
		// display thumb using a random effect
		Timer.delay(fadeIn,Std.random(1000));
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
    function tweenOpacity( e : Float )
    {
        _image.style.opacity = OpacityStyleValue.number(e);
    }

    function tweenEnd(e : Float )
	{
		
	}

}
