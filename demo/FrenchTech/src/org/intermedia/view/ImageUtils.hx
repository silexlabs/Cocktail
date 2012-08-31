/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * This class defines utilities methods for images
 * 
 * @author Raphael Harmel
 */

class ImageUtils
{

	/**
	 * Automatically crops an image so it fits in the mask size
	 * 
	 * @param	node
	 * @param	maskSize
	 */
	public static function cropImage(image:Image, maskSize:Size):Image
	{
		// compute mask ratio
		var maskRatio:Float = maskSize.width / maskSize.height;
		
		// image ratio
		var imageRatio:Float = 0;
		if ((untyped { image.naturalHeight; }) != 0)
			imageRatio = (untyped { image.naturalWidth / image.naturalHeight; } );
			
		var resizedImageSize:Size = { width:0, height:0 };

		// if imageRatio is bigger than cell ratio, set image height to cell height
		if(imageRatio > maskRatio)
		{
			// compute new image size
			resizedImageSize.height = maskSize.height;
			resizedImageSize.width = Std.int(resizedImageSize.height * imageRatio);
	
			// resize image
			image.style.width = Std.string(resizedImageSize.width) + "px";
			image.style.height = Std.string(resizedImageSize.height) + "px";
			
			// offsets image
			image.style.marginTop = "0px";
			image.style.marginLeft = Std.string(-Math.abs((maskSize.width-resizedImageSize.width))/2) + "px";
		}
		// else, set image width to cell width
		else
		{
			// compute new image size
			resizedImageSize.width = maskSize.width;
			resizedImageSize.height = Std.int(resizedImageSize.width / imageRatio);
			
			// resize image
			image.style.width = Std.string(resizedImageSize.width) + "px";
			image.style.height = Std.string(resizedImageSize.height) + "px";
			
			// offsets image
			image.style.marginTop = Std.string( -Math.abs((maskSize.height - resizedImageSize.height)) / 2) + "px";
			image.style.marginLeft = "0px";
		}
		
		// return image;
		return image;
	}
	
}
