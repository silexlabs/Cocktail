package cocktail.plugin.swf;

import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.plugin.Plugin;
import cocktail.port.GraphicsContext;
import haxe.macro.Format;



#if macro
#elseif (flash || nme)
import flash.events.IOErrorEvent;
import flash.display.DisplayObjectContainer;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Loader;
import flash.net.URLRequest;
import flash.system.LoaderContext;
#end

import cocktail.core.geom.GeomData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class SWFPlugin extends Plugin
{

	#if macro
	#elseif (flash || nme)
	private static inline var NO_SCALE:String = "noscale";
	
	private static inline var SHOW_ALL:String = "showall";
	
	private static inline var EXACT_FIT:String = "exactfit";
	
	private var _scaleMode:String;
	
	private var _swf:DisplayObject;
	
	private var _loader:Loader;
	#end
	
	public function new(elementAttributes:Hash<String>, params:Hash<String>, loadComplete:Void->Void, loadError:Void->Void) 
	{
		super(elementAttributes, params, loadComplete, loadError);
		#if macro
		#elseif (flash || nme)
		if (params.exists("scalemode"))
		{
			_scaleMode = params.get("scalemode");
		}
		else
		{
			_scaleMode = SHOW_ALL;
		}
		
		loadSWF(elementAttributes.get("data"));
	
		#end
	}
	
	#if macro
	#elseif (flash || nme)
	override public function attach(graphicsContext:GraphicsContext):Void
	{
		trace(_swf);
		var containerGraphicContext:DisplayObjectContainer = cast(graphicsContext.nativeLayer);
		containerGraphicContext.addChild(_swf);
	}
	
	override public function detach(graphicsContext:GraphicsContext):Void
	{
		var containerGraphicContext:DisplayObjectContainer = cast(graphicsContext.nativeLayer);
		containerGraphicContext.removeChild(_swf);
	}
	
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		if (viewport == null)
		{
			return viewport = value;
		}
		if (value.x == viewport.x && value.y == viewport.y
		&& value.width == viewport.width && value.height == viewport.height)
		{
			return viewport;
		}
		
		trace(viewport);
		viewport = value;
		
		_swf.transform.matrix = new flash.geom.Matrix();
		
		//get the intrinsic width and height of the sprite
		var width:Float = _swf.width;
		var height:Float = _swf.height;
		
		
		var assetBounds:RectangleVO = getAssetBounds(viewport.width, viewport.height,
		width, height);
		
		switch (_scaleMode)
		{
			case NO_SCALE:
				_swf.x = viewport.x;
				_swf.y = viewport.y;
				
			case EXACT_FIT:
				_swf.x = viewport.x;
				_swf.y = viewport.y;
				_swf.scaleX = viewport.width / width;
				_swf.scaleY = viewport.height / height;

			default:
				_swf.x = viewport.x + assetBounds.x;
				_swf.y = viewport.y + assetBounds.y;
				_swf.scaleX = assetBounds.width / width;
				_swf.scaleY = assetBounds.height / height;
		}
		
		//mask the sprite so that it doesn't overflow
		var mask = new Sprite();
		mask.graphics.beginFill(0xFF0000, 0.0);
		mask.graphics.drawRect( 
		viewport.x, viewport.y,
		viewport.width, viewport.height);
		mask.graphics.endFill();
		_swf.mask = mask;
		
		return viewport;
	}
	
	private function loadSWF(url:String):Void
	{
		#if nme
		trace(url);
		trace(nme.Assets.getBytes(url) == null);
		
		var bytes = nme.Assets.getBytes(url);
		if (bytes != null)
		{
			var swf = new format.SWF(bytes);
			_swf = swf.createMovieClip();
			
			trace(_swf);
			
			_loadComplete();
			return;
		}
		
		#end
		
		_loader = new Loader();
		
		//listen for complete/error event on the loader
		_loader.contentLoaderInfo.addEventListener(flash.events.Event.INIT, onSWFLoadComplete);
		_loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, onSWFLoadIOError);
		
		//instantiate a native request object
		var request:URLRequest = new URLRequest(url);
		
		//add a loading context so that the resource will be loaded in the current context
		#if flash9
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
	
		//////////////////////////////////////////////////////////////////////////////////////////
	// Native loading callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	

	private function onSWFLoadComplete(event:flash.events.Event):Void
	{	
		removeLoaderListeners(_loader);
		_swf = _loader.content;
		
		_loadComplete();
	}
	
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