/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.plugin.swf;

import cocktail.core.config.Config;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.geom.GeomUtils;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.resource.ResourceManager;
import cocktail.plugin.Plugin;
import cocktail.core.graphics.GraphicsContext;
import cocktail.geom.GeomData;
import cocktail.port.Bindings;
import haxe.Timer;

#if macro
#elseif (flash || openfl)
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
import flash.display.ActionScriptVersion;
#end
#end

/**
 * A plugin used to display flash swf
 * files. Works for the flash platform,
 * air and OpenFL
 * 
 * @author Yannick DOMINGUEZ
 */
class SWFPlugin extends Plugin
{
#if macro
#elseif (flash || openfl)
	
	//constant of the flash scale modes
	
	private static inline var NO_SCALE:String = "noscale";
	
	private static inline var SHOW_ALL:String = "showall";
	
	private static inline var EXACT_FIT:String = "exactfit";
	
	private static inline var SCALE_MODE:String = "scale";
	
	//html attributes
	
	private static inline var DATA_ATTRIBUTE:String = "data";
	
	private static inline var FLASHVARS_ATTRIBUTE:String = "flashvars";
	
	private static inline var WMODE_ATTRIBUTE:String = "wmode";
	
	private static inline var WMODE_TRANSPARENT:String = "transparent";
	
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
	 * Store wether the loaded swf is currently
	 * added to the flash stage
	 */
	private var _swfAddedToStage:Bool;
	
	/**
	 * Wether the loaded swf was compiled for
	 * AVM1 (actionscript 1 or 2) or AVM2 (actionscript 3)
	 * 
	 * For AVM1 swf, they can't be directly added to the
	 * as3 display list and so there loader should be attached
	 * instead
	 */
	private var _isAVM1swf:Bool;
	
	/**
	 * class constructor, get a reference to the loaded swf
	 */
	public function new(node:HTMLElement, elementAttributes:Map<String, String>, params:Map<String, String>, loadComplete:Void->Void, loadError:Void->Void) 
	{
		super(node, elementAttributes, params, loadComplete, loadError);
		_swfBounds = new RectangleVO();
		_swfAddedToStage = false;
		_isAVM1swf = false;
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
		var htmlDocument:HTMLDocument = cast(_node.ownerDocument);
		var loadedSWF:NativeHttp = htmlDocument.resourceManager.getBinaryResource(_elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
		
		//in some cases, the swf might be loaded with a flash loader instead of
		//loaded as bytes to circumvent security sandbox. In this
		//case, the loader is already ready
		if (Std.is(loadedSWF.response, Loader))
		{
			_loader = cast(loadedSWF.response);
			
			//delay the call to simulate asynchronous loading, else
			//if load event dispatch immediately, this instance won't
			//be ready yet
			var htmlDocument:HTMLDocument = cast(_node.ownerDocument);
			htmlDocument.timer.delay(function(e) { onLoaderReady(_loader); } );
			return;
		}
		
		//all swf are loaded as byte array to prevent them from playing
		//until used with an object tag, the bytes are loaded via a flash loader
		_loader = new Loader();
		//loading bytes is asynchronous
		_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		
		#if openfl
		//openfl don't need loader context
		_loader.loadBytes(loadedSWF.response);
		#else
		
		//for target other than openfl, needs loader context to allow code import
		var loaderContext:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
		loaderContext.allowCodeImport = true;
		
		//this property is a legacy property, doing the same thing as allowCodeImport.
		//Not present for every version of air and flash player but still seem required
		//for air for iOS
		if (Reflect.hasField(loaderContext, "allowLoadBytesCodeExecution"))
		{
			loaderContext.allowLoadBytesCodeExecution = true;
		}
		
		//get content loader info parameters
		//set with reflection as this is a newish flash feature,
		//available starting from flash player 11
		if (Reflect.hasField(loaderContext, "parameters"))
		{
			Reflect.setField(loaderContext, "parameters",  getLoaderContextParams());
		}
		
		_loader.loadBytes(loadedSWF.response, loaderContext);
		#end
	}
	
	/**
	 * Returns the param from the swf loader which simulates
	 * the flash vars for the loaded swf. It concateantes
	 * the "flashvars" param tag if present and the query 
	 * string parameters of the loaded swf if present.
	 * 
	 * for example if the swf is loaded with this markup :
		 * <object data="mySwf?mySwfParam=value">
			* <param name="flashvars" value="myFlashVarParam=value" />
		 * </object>
	 * It will have two parameters : mySwfParam and myFlashVarParam,
	 * accessible from the content loader info
	 */
	private function getLoaderContextParams():Dynamic
	{
		var data = null;
		
		//check if url has any query string params
		var swfUrl:String = _elementAttributes.get(DATA_ATTRIBUTE);
		if (swfUrl.indexOf("?") != -1)
		{
			data = { };
			parseQueryString(data, swfUrl.substr(swfUrl.indexOf("?") + 1));
		}
		
		//check if flash vars param exists
		if (_params.exists(FLASHVARS_ATTRIBUTE))
		{
			if (data == null)
			{
				data = { };
			}
			
			parseQueryString(data, _params.get(FLASHVARS_ATTRIBUTE));
		}
		
		return data;
	}
	
	/**
	 * Utils method parsing query string and setting 
	 * the parsed value on data
	 */
	private function parseQueryString(data:Dynamic, queryString:String):Void
	{
		var params:Array<String> = queryString.split("&");
	
		for (i in 0...params.length)
		{
			var param:Array<String> = params[i].split("=");
			Reflect.setField(data, param[0], param[1]);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Attach the loaded swf to the flash display list
	 */
	override public function attach(graphicsContext:GraphicsContext):Void
	{
		//check to prevent adding multiple times
		if (_swfAddedToStage == false)
		{
			//get a reference to the native layer, which is a flash Sprite
			var containerGraphicContext:DisplayObjectContainer = cast(graphicsContext.nativeLayer.platformLayer);
			
			//when compositing is not enabled, swf might be added below cocktail's
			//main bitmap
			//
			//TODO 4 : cocktail's Config should not be known by plugins ?
			if (Config.getInstance().enableCompositing == false && Config.getInstance().objectBelowWhenNoCompositing == true)
			{
				//TODO 3 : messy to reference parent, should cocktail instead provide right surface
				//in this method ?
				if (_isAVM1swf == false)
				{
					containerGraphicContext.parent.addChildAt(_swf, 0);
				}
				//for avm1 movies, attach the Loader instead of the movie
				else
				{
					containerGraphicContext.parent.addChildAt(_loader, 0);
				}
			}
			else
			{
				if ( _isAVM1swf == false)
				{
					containerGraphicContext.addChild(_swf);
				}
				//for avm1 movies, attach the Loader instead of the movie,
				//avm1 movies can't be attached to the avm2 display list
				else
				{
					containerGraphicContext.addChild(_loader);
				}
			}
			
			_swfAddedToStage = true;
		}
		
	}
	
	/**
	 * Detach the loaded swf from the flash display list
	 */
	override public function detach(graphicsContext:GraphicsContext):Void
	{
		//check to prevent removing multiple times
		if (_swfAddedToStage == true)
		{
			if (_isAVM1swf == false)
			{
				_swf.parent.removeChild(_swf);
			}
			//for avm1 movies, remove Loader parent instead of movie
			else
			{
				_loader.parent.removeChild(_loader);
			}
			_swfAddedToStage = false;
		}
	}
	
	/**
	 * Clean up loaded swf 
	 */
	override public function dispose():Void
	{
		//not supprted by openfl
		#if !openfl
		_loader.unloadAndStop();
		#end
		
		_loader = null;
		_swf = null;
		
		//if the swf was loaded with a regular flash loader instead
		//of being loaded as bytes, remove it from cache, this way if the
		//swf is needed again, it will be cleanly reloaded
		var htmlDocument:HTMLDocument = cast(_node.ownerDocument);
		var loadedSWF:NativeHttp = htmlDocument.resourceManager.getBinaryResource(_elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
		if (Std.is(loadedSWF.response, Loader) == true)
		{
			htmlDocument.resourceManager.removeBinaryResource(_elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
		}
	}
	
	/**
	 * SWF plugin are always composited
	 */
	override public function isCompositedPlugin():Bool
	{
		return true;
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
	 * Called after a successful load
	 */
	private function onSWFLoadComplete(event:flash.events.Event):Void
	{
		onLoaderReady(_loader);
	}
	
	/**
	 * When the swf is done loading, store
	 * its data
	 */
	private function onLoaderReady(loader:Loader):Void
	{
		//check if actionscript 1/2 or 3
		#if openfl
		//not supported in openfl
		_isAVM1swf = false;
		#else
		_isAVM1swf = loader.contentLoaderInfo.actionScriptVersion == ActionScriptVersion.ACTIONSCRIPT2;
		#end
		
		_swfHeight = loader.contentLoaderInfo.height;
		_swfWidth = loader.contentLoaderInfo.width;
		_swf = loader.content;
		
		//mask the swf, size of mask
		//is updated with the viewport
		_swf.mask = _mask;
		
		//swf plugin is now ready
		_loadComplete();
	}
	#end
}
