/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.nme;
import flash.media.Sound;

/**
 * This is the nme port of the native audio,
 * takes most of its code from the flash
 * port but add nme embbedded asset management
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeAudio extends cocktail.port.platform.flash_player.NativeAudio
{
	/**
	 * class constructor. 
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to check if the sound file
	 * was embedded and use it if it is
	 */
	override private function initSound(src:String):Void
	{
		var asset:Sound = nme.Assets.getSound(src);
		
		//here the sound file was embedded, use it
		if (asset != null)
		{
			_sound = asset;
			onNativeLoadedMetaData();
		}
		else
		{
			super.initSound(src);
		}
	}
}