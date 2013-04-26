/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.nme;

import cocktail.core.html.HTMLDocument;
import cocktail.core.timer.Timer;
import cocktail.port.base.NativeHttpBase;
import cocktail.core.http.HTTPData;

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
class NativeHttp extends NativeHttpBase
{
	/**
	 * class constructor
	 */
	public function new(timer:Timer) 
	{
		super(timer);
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
			super.doLoad(url, method, data, authorRequestHeaders, dataFormat);
		}
	}
}