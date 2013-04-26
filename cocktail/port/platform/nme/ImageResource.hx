/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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