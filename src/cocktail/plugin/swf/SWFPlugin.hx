/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.plugin.swf;

import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.geom.GeomUtils;
import cocktail.core.html.HTMLConstants;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.plugin.Plugin;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.geom.GeomData;
import cocktail.port.NativeHttp;

#if macro
#elseif (flash || nme)
import flash.events.IOErrorEvent;
import flash.display.DisplayObjectContainer;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Loader;
import flash.geom.Rectangle;
import flash.net.URLRequest;
#if flash
import flash.system.ApplicationDomain;
import flash.system.LoaderContext;
#end
#end

/**
 * A plugin used to display flash swf
 * files. Works for the flash platform,
 * air and nme
 * 
 * @author Yannick DOMINGUEZ
 */
class SWFPlugin extends Plugin
{
#if macro
#elseif (flash || nme)
	
	//constant of the flash scale modes
	
	private static inline var NO_SCALE:String = "noscale";
	
	private static inline var SHOW_ALL:String = "showall";
	
	private static inline var EXACT_FIT:String = "exactfit";
	
	private static inline var SCALE_MODE:String = "scalemode";
	
	/**
	 * Store the scale mode of this swf. Either
	 * defined in a param tag or uses a default
	 */
	private var _scaleMode:String;
	
	/**
	 * A reference to the loaded swf
	 */
	private var _swf:DisplayObject;
	
	/**
	 * Holds the bounds of the swf object
	 */
	private var _swfBounds:RectangleVO;
	
	/**
	 * The height of the loaded swf,
	 * as defined in flash authoring tool
	 * or in the metadata of the swf.
	 * When computing scale mode, this height
	 * is used instead of the current height of the
	 * swf because the current height is only the
	 * height of the displayed clips. For instance
	 * if for a frame ther is no clip, the height 
	 * will be 0
	 */
	private var _swfHeight:Float;
	
	/**
	 * same as for the height, for the
	 * width
	 */
	private var _swfWidth:Float;
	
	/**
	 * the flash loader used to load
	 * the swf from its bytes
	 */
	private var _loader:Loader;
	
	/**
	 * Used to mask the swf so that it
	 * doesn't overflow the bounds
	 * of the object tag
	 */
	private var _mask:Sprite;
	
	/**
	 * class constructor, get a reference to the loaded swf
	 */
	public function new(elementAttributes:Hash<String>, params:Hash<String>, loadComplete:Void->Void, loadError:Void->Void) 
	{
		super(elementAttributes, params, loadComplete, loadError);
		_swfBounds = new RectangleVO();
		init();
	}
	
	/**
	 * init swf plugin
	 */
	private function init():Void
	{
		//retrive the scale mode if provded or use default
		if (_params.exists(SCALE_MODE))
		{
			_scaleMode = _params.get(SCALE_MODE);
		}
		else
		{
			_scaleMode = SHOW_ALL;
		}
		
		//will be used to mask the swf
		_mask = new Sprite();
		
		//retrieve the loaded swf, the plugin is not instantiated
		//until this swf is successfully loaded
		var loadedSWF:NativeHttp = ResourceManager.getSWFResource(_elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
		
		//all swf are loaded as byte array to prevent them from playing
		//until used with an object tag, the bytes are loaded via a flash loader
		_loader = new Loader();
		//loading bytes is asynchronous
		_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		
		#if nme
		//nme don't need loader context
		_loader.loadBytes(loadedSWF.response);
		#else
		
		//for target other than nme, needs loader context to allow code import
		var loaderContext:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
		loaderContext.allowCodeImport = true;
		
		//this property is a legacy property, doing the same thing as allowCodeImport.
		//Not present for every version of air and flash player but still seem required
		//for air for iOS
		if (Reflect.hasField(loaderContext, "allowLoadBytesCodeExecution"))
		{
			loaderContext.allowLoadBytesCodeExecution = true;
		}
		
		_loader.loadBytes(loadedSWF.response, loaderContext);
		#end
	}
	

	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Attach the loaded swf to the flash display list
	 */
	override public function attach(graphicsContext:GraphicsContext):Void
	{
		//get a reference to the native layer, which is a flash Sprite
		var containerGraphicContext:DisplayObjectContainer = cast(graphicsContext.nativeLayer);
		containerGraphicContext.addChild(_swf);
	}
	
	/**
	 * Detach the loaded swf from the flash display list
	 */
	override public function detach(graphicsContext:GraphicsContext):Void
	{
		var containerGraphicContext:DisplayObjectContainer = cast(graphicsContext.nativeLayer);
		containerGraphicContext.removeChild(_swf);
	}
	
	/**
	 * When the viewport changes, the position
	 * and/or dimension of the swf must be updated
	 */
	override public function updateViewport(x:Float, y:Float, width:Float, height:Float):Void
	{
		//only update if one the attribute of the viewport changed
		if (x == viewport.x && y == viewport.y
		&& width == viewport.width && height == viewport.height)
		{
			return;
		}
		
		viewport.x = x;
		viewport.y = y;
		viewport.width = width;
		viewport.height = height;
		
		//reset the transformations of the swf
		_swf.transform.matrix.identity();
		
		//get the bounds where the swf should be displayed
		GeomUtils.getCenteredBounds(viewport.width, viewport.height,
		_swfWidth, _swfHeight, _swfBounds);
		
		//apply flash scale mode to the swf
		switch (_scaleMode)
		{
			case NO_SCALE:
				_swf.x = Math.round(viewport.x);
				_swf.y = Math.round(viewport.y);
				
			case EXACT_FIT:
				_swf.x = Math.round(viewport.x);
				_swf.y = Math.round(viewport.y);
				_swf.scaleX = viewport.width / _swfWidth;
				_swf.scaleY = viewport.height / _swfHeight;

			default:
				_swf.x = Math.round(viewport.x + _swfBounds.x);
				_swf.y = Math.round(viewport.y + _swfBounds.y);
				_swf.scaleX = _swfBounds.width / _swfWidth;
				_swf.scaleY = _swfBounds.height / _swfHeight;
		}
		
		//update swf's mask position and dimensions
		_mask.graphics.clear();
		_mask.graphics.beginFill(0xFF0000, 0.5);
		_mask.graphics.drawRect(viewport.x, viewport.y, viewport.width, viewport.height);
		_mask.graphics.endFill();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////// //////////////////////////////////////////////////////
	
	/**
	 * When the swf is done loading, store
	 * its data
	 */
	private function onSWFLoadComplete(event:flash.events.Event):Void
	{
		_swfHeight = _loader.contentLoaderInfo.height;
		_swfWidth = _loader.contentLoaderInfo.width;
		_swf = _loader.content;
		
		//mask the swf, size of mask
		//is updated with the viewport
		_swf.mask = _mask;
		
		//swf plugin is now ready
		_loadComplete();
	}
	#end
}