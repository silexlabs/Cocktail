/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
/**
 * This class creates an iphone like gallery
 * 
 * @author Raphael Harmel based on Thomas Fétiveau's work
 */
package components.gallery;

import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import haxe.Http;
import cocktail.resource.ResourceLoaderManager;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.mouse.MouseData;
import cocktail.unit.UnitData;

import cocktail.style.StyleData;

import components.gallery.StyleIphone;

 
class Gallery extends ContainerDOMElement
{
	private static var galleryContainer:ContainerDOMElement;
	
	private var currentMainImage:ImageDOMElement;
	
	/**
	 * Constuctor
	 * 
	 * @param	rssFeedPath
	 */
	public function new(rssFeedPath:String) 
	{
		super();
		
		// create a ul node
		galleryContainer = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("ul")));
		StyleIphone.getDefaultStyle(galleryContainer);
		
		this.addChild(galleryContainer);
		
		var currentAlbumUrl:String = rssFeedPath;

		loadRssFeed(currentAlbumUrl);
	}
	
	/**
	 * Loads the rss feed
	 * 
	 * @param	rssFeedUrl
	 */
	private function loadRssFeed(rssFeedUrl:String):Void
	{
		ResourceLoaderManager.loadString( "GalleryRssProxy.php?url="+StringTools.urlEncode(rssFeedUrl), onRssFeedLoaded, onRssFeedError);
	}
	
	/**
	 * Rss feeds error callback
	 * 
	 * @param	msg
	 */
	private function onRssFeedError( msg : String ):Void
	{
		trace("Error while loading RSS feed : "+msg);
	}
	
	/**
	 * Rss feeds success callback
	 * Parses the rss feed, gets the thumbnails (with full image path also) and adds them to the gallery container 
	 * 
	 * @param	response
	 */
	private function onRssFeedLoaded(response:String):Void
	{
		//trace("onRssFeedLoaded called ");
		var galleryXml:Xml =  Xml.parse(response);
		
		var channelNode:Xml = galleryXml.firstElement().firstElement();
		
		// 2 listage du contenu 
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				var imageThumbContainer:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));
				var imageThumbDOMElement:ImageThumbDOMElement = new ImageThumbDOMElement();
				galleryContainer.addChild(imageThumbContainer);
				
				for (entryElement in channelChild.elements())
				{
					if (entryElement.nodeName == "media:content")
					{
						imageThumbDOMElement.fullImagePath = entryElement.get("url");
					}
					//if (entryElement.nodeName == "media:content")
					else if (entryElement.nodeName == "media:thumbnail")
					{
						imageThumbDOMElement.load(entryElement.get("url"));

						StyleIphone.getThumbStyle(imageThumbDOMElement);
						//galleryContainer.addChild(imageThumbDOMElement);
						imageThumbContainer.addChild(imageThumbDOMElement);
						
						//ImageDOMElement.onMouseUp = displayPicture;
						var displayPictureDelegate = displayPicture;
						imageThumbDOMElement.onMouseUp = function(event) {
							displayPictureDelegate(imageThumbDOMElement);
						}
					}
				}
			}
		}
	}
	
	/**
	 * Thumbnail images mouse up callback
	 * Displays the full size picture
	 * 
	 * @param	imageThumbDOMElement
	 */
	private function displayPicture(imageThumbDOMElement:ImageThumbDOMElement):Void
	{
		// reset and load full size image into currentMainImage
		currentMainImage = new ImageDOMElement();
		currentMainImage.load(imageThumbDOMElement.fullImagePath);
		
		StyleIphone.getFullSizePictureStyle(currentMainImage);
		
		this.removeChild(galleryContainer);
		this.addChild(currentMainImage);
		
		currentMainImage.onMouseUp = displayGallery;
	}
	
	/**
	 * Full size images mouse up callback
	 * Displays the gallery
	 * 
	 * @param	mouseEventData
	 */
	private function displayGallery(mouseEventData:MouseEventData):Void
	{
		this.removeChild(currentMainImage);
		this.addChild(galleryContainer);
	}
	
}
