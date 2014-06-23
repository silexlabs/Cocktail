/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.core.config.Config;
import cocktail.event.CustomEvent;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.html.HTMLTextAreaElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.stacking.StackingContext;
import cocktail.geom.GeomData;
import cocktail.port.base.PlatformBase;
import cocktail.port.Bindings;
import flash.display.Bitmap;
import flash.display.DisplayObject;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.display.StageDisplayState;
import flash.display.StageQuality;
import flash.display.Graphics;
import flash.geom.Point;
import flash.Lib;
import flash.net.URLRequest;
import haxe.Log;

/**
 * This is the flash AVM2 implementation of the native platform.
 * Listens to flash global events, such as Stage resize and exposes
 * some flash public API
 * 
 * @author Yannick DOMINGUEZ
 */
class Platform extends PlatformBase
{
	/**
	 * The name of the attribute whose value to lookup on the flash Stage
	 * to determine wether fullscreen mode is allowed
	 */
	private static inline var ALLOW_FULLSCREEN_ATTRIBUTE:String = "allowsFullScreen";
	
	/**
	 * The Sprite that will be used as a root for the document,
	 * is directly attached to flash Stage
	 */
	private var _rootSprite:Sprite;
	
	/**
	 * The Sprite used as root for the platform layers
	 * of the document.
	 */
	private var _platformLayersRootSprite:Sprite;
	
	/**
	 * The sprite used for hit testing, e.g listening
	 * for mouse and touch event coming from the flash
	 * player. 
	 * 
	 * Set public so that mouse and touch listener classes
	 * can access it
	 */
	public var hitTestingSprite:Sprite;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		initDisplayList();
		
		super();
	}
	
	/**
	 * clean up method
	 */
	override public function dispose():Void
	{
		super.dispose();
		
		if (_rootSprite.parent != null)
		{
			_rootSprite.parent.removeChild(_rootSprite);
		}
		
		if (_platformLayersRootSprite.parent != null)
		{
			_platformLayersRootSprite.parent.removeChild(_platformLayersRootSprite);
		}
		
		if (hitTestingSprite.parent != null)
		{
			hitTestingSprite.parent.removeChild(hitTestingSprite);
		}
	}
	
	/**
	 * Init the flash display list used
	 * for cocktail document
	 */
	private function initDisplayList():Void
	{
		_rootSprite = new Sprite();
		
		_platformLayersRootSprite = new Sprite();
		
		//platform root sprite is used for hit testing
		hitTestingSprite = _platformLayersRootSprite;
		
		updateHitTestingSprite();
		_rootSprite.addChild(_platformLayersRootSprite);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open a new window using flash API
	 */
	override public function open(url:String, name:String):Void
	{
		flash.Lib.getURL(new URLRequest(url), name);
	}
		
	/**
	 * Uses flash fullscreen API
	 */
	override public function enterFullscreen():Void
	{
		flash.Lib.current.stage.displayState = StageDisplayState.FULL_SCREEN;
	}
	
	/**
	 * Uses flash fullscreen API
	 */
	override public function exitFullscreen():Void
	{
		flash.Lib.current.stage.displayState = StageDisplayState.NORMAL;
	}
	
	/**
	 * Look for the allowFullScreen attribute on the Stage
	 * to determine wether fullscreen is allowed.
	 * A bit hackish but no other way in flash
	 */
	override public function fullScreenEnabled():Bool
	{
		return Reflect.hasField(Lib.current.stage, ALLOW_FULLSCREEN_ATTRIBUTE);
	}
	
	/**
	 * uses flash fullscreen API
	 */
	override public function fullscreen():Bool
	{
		return flash.Lib.current.stage.displayState == StageDisplayState.FULL_SCREEN;
	}
	
	/**
	 * Return the root Sprite of the document, which will needs
	 * to be attached to the Stage to display the whole document
	 */
	override public function getRootPlatformLayer():PlatformLayer
	{
		return _rootSprite;
	}
	
	/**
	 * Return the Sprite to be used for the top of the
	 * platform layer tree
	 */
	override public function getTopPlatformLayer():PlatformLayer
	{
		return _platformLayersRootSprite;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Public utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	* when the mouse event target is not the hit testing sprite (might be a text field for instance),
	* convert the mouse event point on the space of the hit testing sprite
	*/
	public function convertToHitTestingSpriteSpace(point:Point, target:DisplayObject, hitTestingSprite:flash.display.DisplayObject):Point
	{
		if (target == hitTestingSprite)
		{
			return point;
		}

		point.x += target.x;
		point.y += target.y;

		var parent:DisplayObjectContainer = target.parent;
		while (parent != hitTestingSprite)
		{
			point.x += parent.x;
			point.y += parent.y;

			parent = parent.parent;

			if (parent == null)
			{
				return point;
			}
		}

		return point;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set resize listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
		Lib.current.stage.addEventListener(flash.events.Event.RESIZE, onNativeResize);
		
		//not supported by openfl
		#if flash
		Lib.current.stage.addEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
		#end
		
		//stage orientation only supported for air
		#if air
		Lib.current.stage.addEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
		#end
	}
	
	/**
	 * Remove resize listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.stage.removeEventListener(flash.events.Event.RESIZE, onNativeResize);
		
		//not supported by openfl
		#if flash
		Lib.current.stage.removeEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
		#end
		
		//stage orientation only supported for air
		#if air
		flash.Lib.current.stage.removeEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
		#end
	}
	
	/**
	 * Create and return a cross-platform resize event
	 * from the flash event
	 * 
	 * @param	event the native event
	 */
	override private function getUIEvent(event:Dynamic):UIEvent
	{
		var resizeEvent:UIEvent = new UIEvent();
		resizeEvent.initUIEvent(EventConstants.RESIZE, false, false, null, 0.0);
		
		return resizeEvent;
	}
	
	/**
	 * Create and return a cross-platform event
	 * from the dispatched native event
	 * 
	 * @param	event the native event
	 */
	override private function getEvent(event:Dynamic):Event
	{
		var fullScreenChangeEvent:Event = new Event();
		fullScreenChangeEvent.initEvent(EventConstants.FULL_SCREEN_CHANGE, false, false);
		
		return fullScreenChangeEvent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden events method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the Stage is resize, the hit testing
	 * sprite must be updated
	 */
	override private function onNativeResize(event:Dynamic):Void
	{
		updateHitTestingSprite();
		super.onNativeResize(event);
	}
	
	/**
	 * When orientation changes, the hit testing Sprite
	 * must be updated
	 */
	override private function onNativeOrientationChange(event:Dynamic):Void
	{
		updateHitTestingSprite();
		super.onNativeOrientationChange(event);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * draw/redraw the background of the 
	 * hit testing Sprite, which must
	 * match the size of the viewport
	 */
	private function updateHitTestingSprite():Void
	{
		hitTestingSprite.graphics.clear();
		setupTransparentFill(hitTestingSprite.graphics);
		hitTestingSprite.graphics.drawRect(0, 0, viewportWidth, viewportHeight);
		hitTestingSprite.graphics.endFill();
	}
	
	/**
	 * start transparent fill
	 */
	private function setupTransparentFill(graphics:Graphics):Void
	{
		//hack for openfl, completely transparent Sprite don't
		//receive mouse events
		#if openfl
		graphics.beginFill(0x000000, 0.01);
		#else
		graphics.beginFill(0x000000, 0.0);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the flash Stage height
	 */
	override private function getNativeViewportHeight():Float
	{
		return Lib.current.stage.stageHeight;
	}
	
	/**
	 * Return the flash Stage width
	 */
	override private function getNativeViewportWidth():Float
	{
		return Lib.current.stage.stageWidth;
	}
	
	/**
	 * Return the x origin of the stage
	 */
	override private function getNativeViewportX():Float
	{	
		return 0;
	}
	
	/**
	 * return the y origin of the stage
	 */
	override private function getNativeViewportY():Float 
	{
		return 0;
	}
	
	/**
	 * update display list to reflect new viewport
	 */
	override private function onViewportUpdate():Void
	{
		_rootSprite.x = viewportX;
		_rootSprite.y = viewportY;
	}
}
