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
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.plugin.Plugin;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.geom.GeomData;

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
	 * A rectangle used to mask the loaded swf
	 */
	private var _scrollRect:Rectangle;
	
	/**
	 * class constructor, get a reference to the loaded swf
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
		
		//retrieve the loaded swf, the plugin is not instantiated
		//until this swf is successfully loaded
		var loadedSWF:AbstractResource = ResourceManager.getSWFResource(elementAttributes.get(HTMLConstants.HTML_DATA_ATTRIBUTE_NAME));
		
		_swfHeight = loadedSWF.intrinsicHeight;
		_swfWidth = loadedSWF.intrinsicWidth;
		_swf = loadedSWF.nativeResource;
		
		//swf plugin is now ready
		//TODO 1 : don't seem to work unless swf readiness
		//is delayed
		Lib.document.timer.delay(function(e) { loadComplete(); });
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
		var assetBounds:RectangleVO = getAssetBounds(viewport.width, viewport.height,
		_swfWidth, _swfHeight);
		
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
				_swf.x = Math.round(viewport.x + assetBounds.x);
				_swf.y = Math.round(viewport.y + assetBounds.y);
				_swf.scaleX = assetBounds.width / _swfWidth;
				_swf.scaleY = assetBounds.height / _swfHeight;
		}
		
		//apply a scroll rect to the swf to prevent it
		//from overflowing in object tag
		if (_scrollRect == null)
		{
			_scrollRect = new Rectangle(Math.round(-viewport.x), Math.round( -viewport.y), Math.round(viewport.width), Math.round(viewport.height));
		}
		else
		{
			_scrollRect.x = Math.round(-viewport.x);
			_scrollRect.y = Math.round(-viewport.y);
			_scrollRect.width = Math.round(viewport.width);
			_scrollRect.height = Math.round(viewport.height);
		}
		
		_swf.scrollRect = _scrollRect;
		
				
		return;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////// //////////////////////////////////////////////////////
	
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
		
		var rect:RectangleVO = new RectangleVO();
		rect.x = xOffset;
		rect.y = yOffset;
		rect.width = width;
		rect.height = height;
		return rect;
	}
	#end
}