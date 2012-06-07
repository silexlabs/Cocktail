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
	 * The default width of the video tag, if the video is not yet loaded 
	 */
	private static inline var HTML_VIDEO_DEFAULT_WIDTH:Int = 300;
	
	/**
	 * The default height of the video tag, if the video is not yet loaded 
	 */
	private static inline var HTML_VIDEO_DEFAULT_HEIGHT:Int = 150;
	
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
		super(HTMLConstants.HTML_VIDEO_TAG_NAME);
	}
	
	/**
	 * Instantiate a video media manager
	 */
	override private function initNativeMedia():Void
	{
		_nativeMedia = new NativeVideo();
	}
	
	/**
	 * the embedded assed is held by the image loader
	 */
	override private function initEmbeddedAsset():Void
	{
		_embeddedAsset = _nativeMedia.nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate a video renderer
	 */
	override private function createElementRenderer():Void
	{
		_elementRenderer = new VideoRenderer(this);
		_elementRenderer.coreStyle = _coreStyle;
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	/**
	 * Return the intrinsic width of the video
	 * if available, else return CSS default for
	 * video
	 */
	private function get_videoWidth():Int
	{
		if (_nativeMedia.width != null)
		{
			return Math.round(_nativeMedia.width);
		}
		else
		{
			return HTML_VIDEO_DEFAULT_WIDTH;
		}
	}
	
	/**
	 * Same as for width
	 */
	private function get_videoHeight():Int
	{
		if (_nativeMedia.height != null)
		{
			return Math.round(_nativeMedia.height);
		}
		else
		{
			return HTML_VIDEO_DEFAULT_HEIGHT;
		}
	}
}