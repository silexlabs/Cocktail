/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.nme;

import cocktail.port.platform.nativeHttp.NativeHTTPData;

/**
 * This is the implementation of the http class
 * for the nme platform. 
 * 
 * It uses mose of the implementation of the flash
 * platform but add management of embedded asset.
 * 
 * Before an asset is loaded, it is first checked if
 * it was embedded in the application at compile
 * time
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeHttp extends cocktail.port.flash_player.NativeHttp
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to first check if the requested asset was embedded
	 */
	override public function doLoad(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>, dataFormat:DataFormatValue):Void
	{
		var asset:String = nme.Assets.getText(url);
		
		//if the asset was embbedded, store it
		if (asset != null)
		{
			response = asset;
			complete = true;
			responseHeadersLoaded = true;
		}
		//else load it
		else
		{
			super.doLoad(url, method, data, authorRequestHeaders);
		}
	}
}