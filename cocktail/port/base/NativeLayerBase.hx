/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.port.Bindings;

/**
 * This class wraps a platform layer (for instance Sprite in flash) and exposes
 * method to manipulate the native display tree
 * 
 * It also owns a graphics surface instance, used to draw the document on screen
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeLayerBase 
{
	/**
	 * a graphics object, used to draw the document
	 */
	public var graphics:GraphicsSurface;
	
	/**
	 * the actual platform specific layer
	 */
	public var platformLayer(default, null):PlatformLayer;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		graphics = new GraphicsSurface();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		graphics.dispose();
		graphics = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * attach a platform layer as a child of this instance platform layer at
	 * the provided index
	 */
	public function attach(platformLayer:PlatformLayer, index:Int):Void
	{
		//abstract
	}
	
	/**
	 * remove the provided platform layer from the children 
	 * of this instance platform layer
	 */
	public function detach(platformLayer:PlatformLayer):Void
	{
		//abstract
	}
	
	/**
	 * init the platform specific bitmap data with
	 * the provided width and height
	 */
	public function initBitmapData(width:Int, height:Int):Void
	{
		//abstract
	}
	
}