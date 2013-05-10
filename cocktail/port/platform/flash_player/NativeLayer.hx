/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.port.base.NativeLayerBase;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.display.PixelSnapping;
import cocktail.port.Bindings;

/**
 * This is the flash implementation of the native layer.
 * Builds the flash display list for this layer
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeLayer extends NativeLayerBase
{
	/**
	 * The native flash bitmap which will be filled
	 * with the graphics BitmapData
	 */
	private var _nativeBitmap:Bitmap;
	
	/**
	 * The native flash Sprite, used a native
	 * layer
	 */
	private var _nativeLayer:Sprite;
	
	/**
	 * A container for the native flash bitmapData
	 */
	private var _bitmapContainer:Sprite;
	
	/**
	 * A container for the children layer of
	 * this GraphicContext. A container is necessary
	 * so that tha native Bitmap is always below the children
	 * layer
	 */
	private var _childrenNativeLayer:Sprite;
	
	/**
	 * the current width of the BitmapData
	 */
	private var _width:Int;
	
	/**
	 * the current height of the BitmapData
	 */
	private var _height:Int;
	
	/**
	 * class constructor. Build the display list
	 * for this native layer
	 */
	public function new() 
	{
		super();
		
		_nativeLayer = new Sprite();
		_nativeLayer.mouseEnabled = false;
		
		_childrenNativeLayer = new Sprite();
		_childrenNativeLayer.mouseEnabled = false;
		
		_bitmapContainer = new Sprite();
		_bitmapContainer.mouseEnabled = false;
		
		_width = 0;
		_height = 0;

		//build native display list
		_childrenNativeLayer.addChild(_bitmapContainer);
		_childrenNativeLayer.addChild(_nativeLayer);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * attach the provided Sprite to this instance Sprite for children
	 */
	override public function attach(platformLayer:PlatformLayer, index:Int):Void
	{
		platformLayer.addChildAt(_childrenNativeLayer, index);
	}
	
	/**
	 * remove the provided Sprite from the children of this instance's
	 * Sprite for children
	 */
	override public function detach(platformLayer:PlatformLayer):Void
	{
		if (_childrenNativeLayer.parent != null)
		{
			platformLayer.removeChild(_childrenNativeLayer);
		}
	}
	
	/**
	 * Create new BitmapData when the size of the window changes
	 */
	override public function initBitmapData(width:Int, height:Int):Void
	{
		//here the bitmap data is created for the first time
		if (_nativeBitmap == null)
		{
			graphics.initBitmapData(width, height);
			_nativeBitmap = new Bitmap(graphics.nativeBitmapData, PixelSnapping.AUTO, false);
			_bitmapContainer.addChild(_nativeBitmap);
		}
		else
		{
			//no need to update if the size didn't change
			if (_width == width && _height == height)
			{
				return;
			}
			
			graphics.dispose();
			graphics.initBitmapData(width, height);
		}
		
		_width = width;
		_height = height;
	}
	
}