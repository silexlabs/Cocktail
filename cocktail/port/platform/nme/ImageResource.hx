/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.nme;
import flash.display.BitmapData;
import flash.display.Loader;

/**
 * This the nme implementation of the ImageResource.
 * It takes most of its code form the flash implementaion,
 * but add nme embedded asset management
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageResource extends cocktail.port.platform.flash_player.ImageResource
{
	/**
	 * class constructor.
	 */
	public function new(url:String)
	{
		super(url);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden method 
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to check if the asset to load was
	 * embedded at compile time
	 */
	override private function load(url:String):Void
	{
		var asset:BitmapData = nme.Assets.getBitmapData(url);
		
		//here the asset was embedded, no need
		//to load
		if (asset != null)
		{
			nativeResource = asset;
			intrinsicHeight = asset.height;
			intrinsicWidth = asset.width;
			intrinsicRatio = intrinsicWidth / intrinsicHeight;
			onLoadComplete();
		}
		else
		{
			super.load(url);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden as nme don't support contentLoaderInfo width and height
	 */
	override private function setIntrinsicDimensions(loader:Loader):Void
	{
		intrinsicHeight = Math.round(loader.height);
		intrinsicWidth = Math.round(loader.width);
		intrinsicRatio = intrinsicWidth / intrinsicHeight;
	}
}