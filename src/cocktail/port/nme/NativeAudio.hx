/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.nme;
import flash.media.Sound;

/**
 * This is the nme port of the native audio,
 * takes most of its code from the flash
 * port but add nme embbedded asset management
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeAudio extends cocktail.port.flash_player.NativeAudio
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