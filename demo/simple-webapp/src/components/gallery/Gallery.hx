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

import components.gallery.StyleGallery;

 
class Gallery extends ContainerDOMElement
{
	// flag to know if the gallery is currently displayed
	public var galleryDisplayed:Bool;
	
	// container for the thumblist image gallery
	private static var _galleryContainer:ContainerDOMElement;
	
	// container for the full-size image
	private var _currentMainImage:ImageDOMElement;
	
	/**
	 * Constuctor
	 * 
	 * @param	rssFeedPath
	 */
	public function new(rssFeedPath:String) 
	{
		super();
		
		// create a ul node
		_galleryContainer = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("ul")));
		// apply style
		StyleGallery.getDefaultStyle(_galleryContainer);
		
		// add the gallery container to the gallery
		this.addChild(_galleryContainer);
		
		// set the galleryDisplayed flag to true
		galleryDisplayed = true;

		// load the rss feed
		loadRssFeed(rssFeedPath);
	}
	
	/**
	 * Loads the rss feed
	 * 
	 * @param	rssFeedUrl
	 */
	private function loadRssFeed(rssFeedUrl:String):Void
	{
		ResourceLoaderManager.loadString( "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url="+StringTools.urlEncode(rssFeedUrl), onRssFeedLoaded, onRssFeedError);
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
		// parse the rss feed
		var galleryXml:Xml =  Xml.parse(response);
		
		var channelNode:Xml = galleryXml.firstElement().firstElement();
		
		// get the rss data
		for ( channelChild in channelNode.elements() )
		{
			if (channelChild.nodeName == "item")
			{
				// create the li nodes 
				var imageThumbContainer:ContainerDOMElement = new ContainerDOMElement(NativeElementManager.createNativeElement(NativeElementTypeValue.custom("li")));
				// apply style
				StyleGallery.getCellStyle(imageThumbContainer);
				// create an image thumb container
				var imageThumbDOMElement:ImageThumbDOMElement = new ImageThumbDOMElement();
				// attach it to the gallery container
				_galleryContainer.addChild(imageThumbContainer);
				
				// for each node
				for (entryElement in channelChild.elements())
				{
					// if node is a full size image, store its url string into imageThumbDOMElement
					if (entryElement.nodeName == "media:content")
					{
						imageThumbDOMElement.fullImagePath = entryElement.get("url");
					}
					// if node is a thumbnail image, loads it to the gallery
					else if (entryElement.nodeName == "media:thumbnail")
					{
						imageThumbDOMElement.load(entryElement.get("url"));

						StyleGallery.getThumbStyle(imageThumbDOMElement);
						//_galleryContainer.addChild(imageThumbDOMElement);
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
		// reset and load full size image into _currentMainImage
		_currentMainImage = new ImageDOMElement();
		_currentMainImage.load(imageThumbDOMElement.fullImagePath);
		
		StyleGallery.getFullSizePictureStyle(_currentMainImage);
		
		// removes the gallery container
		this.removeChild(_galleryContainer);
		// set the galleryDisplayed flag to false
		galleryDisplayed = false;
		// add the full-size image
		this.addChild(_currentMainImage);
		
		_currentMainImage.onMouseUp = onFullsizeImageMouseUp;
	}
	
	/**
	 * Full size images mouse up callback
	 * 
	 * @param	mouseEventData
	 */
	private function onFullsizeImageMouseUp(mouseEvent:MouseEventData):Void
	{
		displayGallery();
	}
	
	/**
	 * Displays the gallery
	 * 
	 * @param	mouseEventData
	 */
	public function displayGallery():Void
	{
		// removes the full-size image 
		this.removeChild(_currentMainImage);
		// add the gallery container
		this.addChild(_galleryContainer);
		// set the galleryDisplayed flag to true
		galleryDisplayed = true;
	}
}
