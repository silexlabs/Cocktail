/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.resource;
import cocktail.domElement.DOMElement;


 /**
  * Stores the data relative to a resource.
  */
typedef ResourceData = 
{
	/**
	 * Reference to the callback to execute once the file is loaded
	 */
	var onLoadComplete : Dynamic -> Void;
	
	/**
	 * Reference to the callback to execute when there is an error during loading
	 */
	var onLoadError : Dynamic -> Void;
	
	/**
	 * The url of the file to load
	 */
	var url : String;
	
	/**
	 * If not null, the loaded resource will
	 * be set on this DOMElement, else, a 
	 * new DOMElement will be created
	 */
	var domElement:DOMElement;
	
	/**
	 * Wether to allow the browser to cache the file
	 */
	var allowCache : Bool;
	
	/**
	 * The type of loaded file
	 */
	var loadingType : LoadingTypeValue;
}

/**
 * Enumerates the file type which can be loaded : 
 * data for text file,
 * image for picture such as .jpg, .gif and .png files,
 * text for html text files, 
 * animation for animated format such as .swf and .svg,
 * container for skin loading (.swf, .html),
 * and library for classes library which may be stored in .swf or .js files for instance
 */
enum LoadingTypeValue
{
	data;
	image;
	text;
	animation;
	container;
	library;
}