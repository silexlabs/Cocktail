/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.air;

/**
 * This is the air port of the native window.
 * 
 * In addition to the flash player NativeWindow class,
 * it listens to screen orientation events for mobile
 * and tablet devices
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeWindow extends cocktail.port.platform.flash_player.NativeWindow
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * add orientation change listener
	 */
	override private function setNativeListeners():Void
	{
		super.setNativeListeners();
		flash.Lib.current.stage.addEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
	}
	
	/**
	 * remove orientation change listener
	 */
	override private function removeNativeListeners():Void
	{
		super.removeNativeListeners();
		flash.Lib.current.stage.removeEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
	}
}