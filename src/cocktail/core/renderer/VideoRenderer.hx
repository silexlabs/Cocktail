 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLVideoElement;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * Renders an embedded video asset
 * 
 * @author Yannick DOMINGUEZ
 */
class VideoRenderer extends EmbeddedBoxRenderer
{
	/**
	 * class constructor
	 */
	public function new(node:Node) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the embedded video asset.
	 * 
	 * Video intrinsic aspect ratio is always preserved, so the
	 * video might be letterboxed to fit in the available bounds,
	 * the video always takes the maximum amount of space available
	 * while keeping its aspect ratio
	 */
	override private function renderEmbeddedAsset(graphicContext:NativeElement)
	{
		var htmlVideoElement:HTMLVideoElement = cast(_node);
		
		//those will hold the actual value used for the video
		//dimensions, with the kept aspect ratio
		var width:Float;
		var height:Float;
		
		//here the bounds of the ElementRenderer are larger than the height
		if (_coreStyle.computedStyle.width >= _coreStyle.computedStyle.height)
		{
			//get the ratio between the intrinsic video width and the width it must be displayed at
			var ratio:Float = htmlVideoElement.videoHeight / _coreStyle.computedStyle.height;

			//the video width use the computed width while the height apply the ratio
			//to the video height, so that the ratio is kept while displaying the video
			//as big as possible
			width =  htmlVideoElement.videoWidth / ratio ;
			height = _coreStyle.computedStyle.height;
			
		}
		else
		{
			var ratio:Float = htmlVideoElement.videoWidth / _coreStyle.computedStyle.width;
			
			height = htmlVideoElement.videoHeight / ratio;
			width = _coreStyle.computedStyle.width;
		}
		
		//the video must be centered in the ElementRenderer, so deduce the offsets
		//to apply to the x and y direction
		var xOffset:Float = (_coreStyle.computedStyle.width - width) / 2;
		var yOffset:Float = (_coreStyle.computedStyle.height - height) /2;
		
		#if (flash9 || nme)
		
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		containerGraphicContext.addChild(htmlVideoElement.embeddedAsset);
		
		//add the x and y offset for the video
		htmlVideoElement.embeddedAsset.x = globalBounds.x + _coreStyle.computedStyle.paddingLeft + xOffset;
		htmlVideoElement.embeddedAsset.y = globalBounds.y + _coreStyle.computedStyle.paddingTop + yOffset;
		
		//use the actual video width and height
		htmlVideoElement.embeddedAsset.width = width;
		htmlVideoElement.embeddedAsset.height = height;
		
		htmlVideoElement.embeddedAsset.alpha = computedStyle.opacity;
		#end
	}
	
}