/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.core.config.Config;
import cocktail.core.event.CustomEvent;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.UIEvent;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.html.HTMLTextAreaElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.stacking.StackingContext;
import cocktail.core.geom.GeomData;
import cocktail.port.base.PlatformBase;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.port.NativeLayer;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.display.StageDisplayState;
import flash.display.StageQuality;
import flash.display.Graphics;
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
	 * The Sprite used as root for the native layers
	 * of the document
	 */
	private var _nativeLayersRootSprite:Sprite;
	
	/**
	 * The sprite used for hit testing, e.g listening
	 * for mouse and touch event coming from the flash
	 * player. 
	 * 
	 * 
	 * There are 2 types of hit testing which can be used,
	 * defined by config : 
	 * - "basic", the hit testing Sprite is below all of cocktail's
	 * bitmap and loaded elements, such as swf movie. This is the 
	 * fastest hit testing but the tradeof is that if there are loaded
	 * swf movie, hit testing Sprite won't be able to catch mouse and touch
	 * event on top of the loaded swf, as the hit testing Sprite will
	 * always be below the swf movie. 
	 * note : also cause issues with flash native text field
	 * 
	 * - "advanced", the hit testing Sprite is on top of all of cocktail's
	 * bitmap and loaded elements such as swf movie. This is slower, because
	 * each time the hit testing bounds of the document is updated, the
	 * hit testing Sprite must also be redrawn to dig "holes" where swf movie
	 * appears, so that swf movie can be interacted with.
	 * note : now also applies to flash native text fields
	 * 
	 * Set public so that mouse and touch listener classes
	 * can access it
	 */
	public var hitTestingSprite:Sprite;
	
	/**
	 * During update of hit testing Sprite, hold a ref
	 * to the bounds of layer created by "hollowing" tags such
	 * as the object tag, so
	 * that they can be used to create "hole" in the hit
	 * testing Sprite, so that native flash display objects
	 * can be interacted with
	 */
	private var _hollowedTagsBounds:Array<RectangleVO>;
	
	/**
	 * During update of hit testing Sprite, set to true
	 * as soon as one layer created by an "hollowed" tag
	 * is found
	 */
	private var _foundHollowedTag:Bool;
	
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
		
		if (_nativeLayersRootSprite.parent != null)
		{
			_nativeLayersRootSprite.parent.removeChild(_nativeLayersRootSprite);
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
		
		_nativeLayersRootSprite = new Sprite();
		
		hitTestingSprite = new Sprite();
		updateHitTestingSprite();
		
		if (Config.getInstance().useAdvancedHitTesting == true)
		{
			_rootSprite.addChild(_nativeLayersRootSprite);
			_rootSprite.addChild(hitTestingSprite);
		}
		else
		{
			hitTestingSprite = _nativeLayersRootSprite;
			_rootSprite.addChild(_nativeLayersRootSprite);
		}
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
	override public function getRootNativeLayer():NativeLayer
	{
		return _rootSprite;
	}
	
	/**
	 * Return the Sprite to be used for the top of the
	 * native layer tree
	 */
	override public function getTopNativeLayer():NativeLayer
	{
		return _nativeLayersRootSprite;
	}
	
	/**
	 * Update the hit testing Sprite in flash, so that it covers the bounds
	 * of all the layer in the document except the layer created by 
	 * object elements.
	 * addendum : now also applies to layer created by text input elements
	 * 
	 * Note : this solution is a workaround for the fact that if there is an
	 * object tag which load a swf movie in the document, the swf movie will prevent
	 * hit testing from working properly in cocktail. This is only an issue when there
	 * is html elements generated by cocktail on top of the swf content.
	 * 
	 * For instance if there is a swf movie on the stage, if the hit testing Sprite is
	 * below it, then the swf movie will prevent cocktail from receiving mouse and
	 * touch event. If instead the hit testing Sprite is above the swf, then the swf
	 * won't receive mouse and touch event
	 * 
	 * One solution which almost worked was to simulate event dispatching on the loaded
	 * swf, but some swf, like Youtube API prevent accessing the inner display list
	 * 
	 * The "best" solution found, is to draw on the hit testing sprite all the region
	 * which corresponds to layers which are not created by "object" elements
	 */
	override public function updateHitTestingBounds(stackingContext:StackingContext):Void
	{
		//only applies for advanced hit testing
		if (Config.getInstance().useAdvancedHitTesting == false)
		{
			return;
		}
		
		_hollowedTagsBounds = new Array<RectangleVO>();
		_foundHollowedTag = false;
		
		updateHitTestingSprite();
		doUpdateHitTestingBounds(stackingContext);
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
		
		//not supported by nme
		#if flash9
		Lib.current.stage.addEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
		#end
	}
	
	/**
	 * Remove resize listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.stage.removeEventListener(flash.events.Event.RESIZE, onNativeResize);
		
		//not supported by nme
		#if flash9
		Lib.current.stage.removeEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
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
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * draw/redraw the background of the 
	 * hit testing Sprite, which must
	 * match the size of the Stage
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
		//hack for nme, completely transparent Sprite don't
		//recive mouse events
		#if nme
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Called when a layer created by an "hollowed" element
	 * is found, reset the hit testing Sprite by filling
	 * its surface then create hole for each hollowed layer
	 * found so far
	 */
	private function resetHitTestingSprite():Void
	{
		hitTestingSprite.graphics.clear();
		setupTransparentFill(hitTestingSprite.graphics);
		hitTestingSprite.graphics.drawRect(0, 0, viewportWidth, viewportHeight);
		
		for (i in 0..._hollowedTagsBounds.length)
		{
			hitTestingSprite.graphics.drawRect(_hollowedTagsBounds[i].x,
			_hollowedTagsBounds[i].y, _hollowedTagsBounds[i].width, _hollowedTagsBounds[i].height);
		}
		
		hitTestingSprite.graphics.endFill();
	}
	
	/**
	 * Called when a layer which is not created by an hollowed tag is found,
	 * fill the hit testing Sprite within bound, so that the layer can be clicked
	 */
	private function fillHitTestingSprite(rect:RectangleVO):Void
	{
		setupTransparentFill(hitTestingSprite.graphics);
		hitTestingSprite.graphics.drawRect(rect.x, rect.y, rect.width, rect.height);
		hitTestingSprite.graphics.endFill();
	}
	
	/**
	 * Check wether a layer was created with an hollowed element
	 * If it does, create hole in hit testing Sprite for those
	 * else fill the hit testing Sprite with the bounds of the layer
	 */
	private function hitTestLayer(layerRenderer:LayerRenderer):Void
	{
		if (layerRenderer.rootElementRenderer.domNode.tagName == HTMLConstants.HTML_OBJECT_TAG_NAME)
		{
			_foundHollowedTag = true;
			_hollowedTagsBounds.push(layerRenderer.bounds);
			resetHitTestingSprite();
			return;
		}
		
		//for input element, special case :
		//exclude from hit testing if this is a text based input,
		//creating a native flash text field and if it is the currently
		//focused element of the document
		if (layerRenderer.rootElementRenderer.domNode.tagName == HTMLConstants.HTML_INPUT_TAG_NAME)
		{
			var inputElement:HTMLInputElement = cast(layerRenderer.rootElementRenderer.domNode);
			if (inputElement.type == HTMLConstants.INPUT_TYPE_TEXT || inputElement.type == HTMLConstants.INPUT_TYPE_PASSWORD)
			{
				var htmlDocument:HTMLDocument = cast(inputElement.ownerDocument);
				if (htmlDocument.activeElement == inputElement)
				{
					_foundHollowedTag = true;
					_hollowedTagsBounds.push(layerRenderer.bounds);
					resetHitTestingSprite();
					return;
				}
			}
		}
		//same for text area element
		else if (layerRenderer.rootElementRenderer.domNode.tagName == HTMLConstants.HTML_TEXT_AREA_TAG_NAME)
		{
			
			var textArea:HTMLElement = layerRenderer.rootElementRenderer.domNode;
			var htmlDocument:HTMLDocument = cast(textArea.ownerDocument);
				if (htmlDocument.activeElement == textArea)
				{
					_foundHollowedTag = true;
					_hollowedTagsBounds.push(layerRenderer.bounds);
					resetHitTestingSprite();
					return;
				}
		}

		if (_foundHollowedTag == true)
		{
			fillHitTestingSprite(layerRenderer.bounds);
		}
	}
	
	/**
	 * Traverse the stacking context tree recursively,
	 * in z-index order and fill the hit testing Sprite
	 * accordingly.
	 * 
	 * Logic is similar to rendering of stacking context
	 */
	public function doUpdateHitTestingBounds(stackingContext:StackingContext):Void
	{
		hitTestLayer(stackingContext.layerRenderer);
		
		var child:StackingContext = stackingContext.firstChild;
		
		var hasHitTestedAutoAndZeroLayers:Bool = false;
		
		while (child != null)
		{
			switch(child.layerRenderer.rootElementRenderer.coreStyle.zIndex)
			{
				case INTEGER(value):
					
					if (value == 0)
					{
						
					}
					else
					{
						if (value > 0 && hasHitTestedAutoAndZeroLayers == false)
						{
							hitTestChildrenInSameStackingContext(stackingContext.layerRenderer);
							hasHitTestedAutoAndZeroLayers = true;
						}
						
						doUpdateHitTestingBounds(child);
					}
					
				default:	
			}
			
			child = child.nextSibling;
		}
		
		if (hasHitTestedAutoAndZeroLayers == false)
		{
			hitTestChildrenInSameStackingContext(stackingContext.layerRenderer);
		}
	}
	
	/**
	 * hit test layer 
	 */
	private function hitTestChildrenInSameStackingContext(rootLayer:LayerRenderer):Void
	{
		var child:LayerRenderer = rootLayer.firstChild;
		while (child != null)
		{
			if (child.hasOwnStackingContext == false)
			{
				hitTestLayer(child);
				hitTestChildrenInSameStackingContext(child);
			}
			else
			{
				switch(child.rootElementRenderer.coreStyle.zIndex)
				{
					case INTEGER(value):
						if (value == 0)
						{
							doUpdateHitTestingBounds(child.stackingContext);
						}
					default:	
				}
			}
			
			child = child.nextSibling;
		}
	}
}