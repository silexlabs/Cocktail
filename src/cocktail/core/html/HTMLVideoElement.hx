/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.renderer.VideoRenderer;
import cocktail.port.NativeVideo;

/**
 * A video element is used for playing videos or movies.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLVideoElement extends HTMLMediaElement
{
	/**
	 * the html tag name for the video element
	 */
	private static inline var HTML_VIDEO_TAG_NAME:String = "video";
	
	/**
	 * Returns the intrinsic width of the video in CSS pixels
	 */
	public var videoWidth(get_videoWidth, never):Int;
	
	/**
	 * Returns the intrinsic height of the video in CSS pixels
	 */
	public var videoHeight(get_videoHeight, never):Int;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTML_VIDEO_TAG_NAME);
		
		
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		//TODO 1 : should have own init
		_nativeMedia = new NativeVideo();
		_embeddedAsset = _nativeMedia.nativeElement;
	}
	
		//TODO 1 : doc
	override private function createElementRenderer():Void
	{
		_elementRenderer = new VideoRenderer(this);
		
		_elementRenderer.coreStyle = _coreStyle;
	
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	//TODO 1 : The intrinsic width of a video element's playback area
	//is the intrinsic width of the video resource, if that is available;
	//otherwise it is the intrinsic width of the poster frame, if that is
	//available; otherwise it is 300 CSS pixels.
	private function get_videoWidth():Int
	{
		return 0;
	}
	
	//TODO 1 : same as for width
	private function get_videoHeight():Int
	{
		return 0;
	}
}