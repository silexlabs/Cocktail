/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;

/**
 * This file defines bindings to platform specific implementation 
 * for suppported platform
 */

//types common to all platforms
typedef NativeCheckbox = cocktail.port.base.NativeInputBase;
typedef NativeInput = cocktail.port.base.NativeInputBase;
typedef NativeRadio = cocktail.port.base.NativeInputBase;

//bindings common to flash/air and nme
#if ((flash || nme || air) && !macro)
typedef GraphicsSurface =  cocktail.port.platform.flash_player.GraphicsSurface;
typedef ImageResource = cocktail.port.platform.flash_player.ImageResource;
typedef KeyboardListener =  cocktail.port.platform.flash_player.KeyboardListener;
typedef MouseListener =  cocktail.port.platform.flash_player.MouseListener;
typedef NativeBitmapData =  flash.display.BitmapData;
typedef NativeButton =  cocktail.port.platform.flash_player.NativeButton;
typedef NativeTextElement =  flash.display.DisplayObject;
typedef NativeLayer =  cocktail.port.platform.flash_player.NativeLayer;
typedef PlatformLayer = flash.display.DisplayObjectContainer;
typedef PlatformTimer =  cocktail.port.platform.flash_player.PlatformTimer;
typedef TouchListener =  cocktail.port.platform.flash_player.TouchListener;
typedef NativeAudio =  cocktail.port.platform.flash_player.NativeAudio;
typedef NativeHttp =  cocktail.port.platform.flash_player.NativeHttp;
typedef NativeText =  cocktail.port.platform.flash_player.NativeText;

	//bindings for flash or air, compiled either using nme or without
	#if (flash || air)
		typedef NativeVideo =  cocktail.port.platform.flash_player.NativeVideo;
		typedef FontBuilder = cocktail.port.platform.flash_player.FontBuilder;
		
		#if air
			typedef Platform =  cocktail.port.platform.air.Platform;
			typedef NativeTextInput =  cocktail.port.platform.air.NativeTextInput;
			typedef NativeTextArea =  cocktail.port.platform.air.NativeTextArea;
			typedef NativePasswordInput =  cocktail.port.platform.air.NativePasswordInput;
		#else
			typedef Platform =  cocktail.port.platform.flash_player.Platform;
			typedef NativeTextInput =  cocktail.port.platform.flash_player.NativeTextInput;
			typedef NativeTextArea =  cocktail.port.platform.flash_player.NativeTextArea;
			typedef NativePasswordInput =  cocktail.port.platform.flash_player.NativePasswordInput;
		#end
	//bindings for nme when not building for flash or air	
	#elseif nme
		typedef NativeVideo =  cocktail.port.base.NativeMedia;
		typedef FontBuilder = cocktail.port.platform.nme.FontBuilder;
		typedef Platform =  cocktail.port.platform.flash_player.Platform;
		typedef NativeTextInput =  cocktail.port.platform.flash_player.NativeTextInput;
		typedef NativeTextArea =  cocktail.port.platform.flash_player.NativeTextArea;
		typedef NativePasswordInput =  cocktail.port.platform.flash_player.NativePasswordInput;
	#end
#end

//default bindings for all the other platform to set a default 
//allowig build
#if (!flash && !nme && !air)
typedef PlatformTimer =  cocktail.port.base.PlatformTimerBase;
typedef GraphicsSurface = cocktail.port.base.GraphicsSurfaceBase;
typedef ImageResource = cocktail.port.base.ResourceBase;
typedef KeyboardListener = cocktail.port.base.KeyboardListenerBase;
typedef MouseListener = cocktail.port.base.MouseListenerBase;
typedef NativeAudio =  cocktail.port.base.NativeMedia;
typedef NativeBitmapData =  Dynamic;
typedef NativeButton = cocktail.port.base.NativeInputBase;
typedef NativeTextElement =  Dynamic;
typedef PlatformLayer = Dynamic;
typedef NativeHttp =  cocktail.port.base.NativeHttpBase;
typedef NativeLayer =  cocktail.port.base.NativeLayerBase;
typedef NativePasswordInput = cocktail.port.base.NativeTextInputBase;
typedef NativeText =  cocktail.port.base.NativeTextBase;
typedef NativeTextArea = cocktail.port.base.NativeTextInputBase;
typedef NativeTextInput = cocktail.port.base.NativeTextInputBase;
typedef NativeVideo =  cocktail.port.base.NativeMedia;
typedef Platform =  cocktail.port.base.PlatformBase;
typedef FontBuilder = cocktail.port.base.FontBuilderBase;
typedef TouchListener = cocktail.port.base.TouchListenerBase;
#end	