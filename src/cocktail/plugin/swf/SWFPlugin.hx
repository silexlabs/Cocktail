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
import cocktail.core.html.HTMLConstants;
import cocktail.plugin.Plugin;
import cocktail.port.GraphicsContext;
import cocktail.core.geom.GeomData;

#if macro
#elseif (flash || nme)
import flash.events.IOErrorEvent;
import flash.display.DisplayObjectContainer;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Loader;
import flash.net.URLRequest;
#if flash
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
	 * The flash loader used to load the swf
	 */
	private var _loader:Loader;
	
	/**
	 * class constructor, start loading the swf
	 */
	public function new(elementAttributes:Hash<String>, params:Hash<String>, loadComplete:Void->Void, loadError:Void->Void) 
	{
		super(elementAttributes, params, loadComplete, loadError);

		//retrive the scale mode if provded or use default
		if (params.exists(SCALE_MODE))
		{
			_scaleMode = params.get(SCALE_MODE);
		}
		else
		{
			_scaleMode = SHOW_ALL;
		}
		
		_swfHeight = 0;
		_swfWidth = 0;
		
		//start loading
		loadSWF(elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
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
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the viewport changes, the position
	 * and/or dimension of the swf must be updated
	 */
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		//the viewport is null on first call
		if (viewport == null)
		{
			return viewport = value;
		}
		
		//only update if one the attribute of the viewport changed
		if (value.x == viewport.x && value.y == viewport.y
		&& value.width == viewport.width && value.height == viewport.height)
		{
			return viewport;
		}
		
		viewport = value;
		
		//reset the transformations of the swf
		_swf.transform.matrix = new flash.geom.Matrix();
		
		//get the bounds where the swf should be displayed
		var assetBounds:RectangleVO = getAssetBounds(viewport.width, viewport.height,
		_swfWidth, _swfHeight);
		
		//apply flash scale mode to the swf
		switch (_scaleMode)
		{
			case NO_SCALE:
				_swf.x = viewport.x;
				_swf.y = viewport.y;
				
			case EXACT_FIT:
				_swf.x = viewport.x;
				_swf.y = viewport.y;
				_swf.scaleX = viewport.width / _swfWidth;
				_swf.scaleY = viewport.height / _swfHeight;

			default:
				_swf.x = viewport.x + assetBounds.x;
				_swf.y = viewport.y + assetBounds.y;
				_swf.scaleX = assetBounds.width / _swfWidth;
				_swf.scaleY = assetBounds.height / _swfHeight;
		}
		
		//mask the swf so that it doesn't overflow
		var mask = new Sprite();
		mask.graphics.beginFill(0xFF0000, 0.0);
		mask.graphics.drawRect( 
		viewport.x, viewport.y,
		viewport.width, viewport.height);
		mask.graphics.endFill();
		_swf.mask = mask;
		
		return viewport;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * start loading the swf. 
	 * If nme is targeted, first check
	 * wether the swf is embedded
	 * 
	 * @param	url the url of the swf
	 * to load
	 */
	private function loadSWF(url:String):Void
	{
		#if nme
		//check wether bytes are available for this
		//url
		var bytes = nme.Assets.getBytes(url);
		if (bytes != null)
		{
			#if air
			
			//if the runtime is air, use native flash api to load
			//content from bytes
			var loadingContext:LoaderContext = new LoaderContext(false);
			loadingContext.allowCodeImport = true;
			_loader = new Loader();
			_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
			_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
			_loader.loadBytes(bytes, loadingContext);
			return;
			
			#else
			//if they are, create a movieclip from it
			var swf:format.SWF = new format.SWF(bytes);
			_swf = swf.createMovieClip();
			
			//store width height metadata
			//of the swf
			_swfHeight = swf.height;
			_swfWidth = swf.width;
			
			//call the ready callback and return, no
			//need to load the swf
			_loadComplete();
			return;
			#end
		}
		#end
		
		_loader = new Loader();
		
		//listen for complete/error event on the loader
		_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the resource will be loaded in the current context
		#if flash
		var loadingContext:LoaderContext = new LoaderContext(false);
		//always check policy file (crossdomain.xml) for cross-domain loading
		loadingContext.checkPolicyFile = true;

		//start the loading
		_loader.load(request, loadingContext);
		#else
		//start the loading
		_loader.load(request);
		#end
	}
	

	/**
	 * When loaded, store the loaded swf, call the
	 * success callback as the plugin is now ready
	 */
	private function onSWFLoadComplete(event:flash.events.Event):Void
	{	
		removeLoaderListeners(_loader);
		_swf = _loader.content;
		
		//store width height metadata
		//of the loaded swf
		_swfHeight = _loader.height;
		_swfWidth = _loader.width;
		
		_loadComplete();
	}
	
	/**
	 * Call the error callback
	 */
	private function onSWFLoadIOError(event:IOErrorEvent):Void
	{
		removeLoaderListeners(_loader);
		_loadError();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////// //////////////////////////////////////////////////////
	
	/**
	 * Remove loading listeners from the flash loader
	 */
	private function removeLoaderListeners(loader:Loader):Void
	{
		loader.contentLoaderInfo.removeEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		loader.contentLoaderInfo.removeEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
	}
	
	/**
	 * TODO 1 : this method is duplicated from EmbeddedElementRenderer, should
	 * not need to. Should ObjectRenderer instead retrive size of the swf somehow ?
	 * or set as static method ?
	 * 
	 * Utils method returning the right rectangle so that
	 * a picture or video can take the maximum available width
	 * and height while preserving their aspect ratio and also be 
	 * centered in the available space
	 * 
	 * @param	availableWidth the maximum width available for the picture or video
	 * @param	availableHeight the maximum height available for the picture or video
	 * @param	assetWidth the intrinsic width of the video or picture
	 * @param	assetHeight the intrinsic height of the video or picture
	 * @return	the bounds of the asset
	 */
	private function getAssetBounds(availableWidth:Float, availableHeight:Float, assetWidth:Float, assetHeight:Float):RectangleVO
	{
		//those will hold the actual value used for the video or poster 
		//dimensions, with the kept aspect ratio
		var width:Float;
		var height:Float;

		if (availableWidth > availableHeight)
		{
			//get the ratio between the intrinsic asset width and the width it must be displayed at
			var ratio:Float = assetHeight / availableHeight;
			
			//check that the asset isn't wider than the available width
			if ((assetWidth / ratio) < availableWidth)
			{
				//the asset width use the computed width while the height apply the ratio
				//to the asset height, so that the ratio is kept while displaying the asset
				//as big as possible
				width =  assetWidth / ratio ;
				height = availableHeight;
			}
			//else reduce the height instead of the width
			else
			{
				ratio = assetWidth / availableWidth;
				
				width = availableWidth;
				height = assetHeight / ratio;
			}
		}
		//same as above but inverted
		else
		{
			var ratio:Float = assetWidth / availableWidth;
			
			if ((assetHeight / ratio) < availableHeight)
			{
				height = assetHeight / ratio;
				width = availableWidth;
			}
			else
			{
				ratio = assetHeight / availableHeight;
				width =  assetWidth / ratio ;
				height = availableHeight;
			}
		}
		
		//the asset must be centered in the ElementRenderer, so deduce the offsets
		//to apply to the x and y direction
		var xOffset:Float = (availableWidth - width) / 2;
		var yOffset:Float = (availableHeight - height) / 2;
		
		return new RectangleVO(xOffset, yOffset, width, height);
	}
	#end
}