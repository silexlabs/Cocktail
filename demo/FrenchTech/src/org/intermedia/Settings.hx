/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia;

/**
 * This clas defines the application global settings
 * 
 * @author Raphael Harmel
 */

class Settings 
{
	// settings singleton
	private static var _settings:Settings;
	
	// debug flag
	public static inline var DEBUG:Bool = false;
	
	// online feed delay - ie. delay before switching from online data to offline data loading. in milliseconds.
	public static var ONLINE_FEED_DELAY:Int = 10000;
	
	// dataloader timeout message
	public static var DATALOADER_TIMEOUT_MESSAGE:String = "dataloader timeout";
	
	// online flag
	public var online:Bool = true;
	
	private function new():Void
	{
		
	}
	
	// get the singleton instance
	public static function getInstance():Settings
	{
		if (_settings == null)
		{
			_settings = new Settings();
		}
		return _settings;
	}
	
}