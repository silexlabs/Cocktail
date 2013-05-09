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

//types common to all platform
typedef NativeCheckbox = cocktail.port.base.NativeInputBase;
typedef NativeInput = cocktail.port.base.NativeInputBase;
typedef NativeRadio = cocktail.port.base.NativeInputBase;

//bindings for air
#if (air && !macro)
typedef Platform =  cocktail.port.platform.air.Platform;
typedef NativeTextInput =  cocktail.port.platform.air.NativeTextInput;
#end

//bindings for flash and nme
#if ((flash || nme) && !macro)
typedef GraphicsSurface =  cocktail.port.platform.flash_player.GraphicsSurface;
typedef ImageResource = cocktail.port.platform.flash_player.ImageResource;
typedef Keyboard =  cocktail.port.platform.flash_player.Keyboard;
typedef Mouse =  cocktail.port.platform.flash_player.Mouse;
typedef NativeAudio =  cocktail.port.platform.flash_player.NativeAudio;
typedef NativeBitmapData =  flash.display.BitmapData;
typedef NativeButton =  cocktail.port.platform.flash_player.NativeButton;
typedef NativeTextElement =  flash.display.DisplayObject;
typedef NativeLayer =  flash.display.DisplayObjectContainer;
typedef NativeHttp =  cocktail.port.platform.flash_player.NativeHttp;
typedef NativePasswordInput =  cocktail.port.platform.flash_player.NativePasswordInput;
typedef NativeText =  cocktail.port.platform.flash_player.NativeText;
typedef NativeTextArea =  cocktail.port.platform.flash_player.NativeTextArea;
typedef NativeTextInput =  cocktail.port.platform.flash_player.NativeTextInput;
typedef NativeVideo =  cocktail.port.platform.flash_player.NativeVideo;
typedef Platform =  cocktail.port.platform.flash_player.Platform;
typedef PlatformTimer =  cocktail.port.platform.flash_player.PlatformTimer;
typedef TouchListener =  cocktail.port.platform.flash_player.TouchListener;
typedef FontBuilder = cocktail.port.platform.flash_player.FontBuilder;
#end

//bindings for nme
#if (nme && !macro)
typedef ImageResource = cocktail.port.platform.nme.ImageResource;
typedef NativeAudio =  cocktail.port.platform.nme.NativeAudio;
typedef NativeHttp =  cocktail.port.platform.nme.NativeHttp;
typedef NativeText =  cocktail.port.platform.nme.NativeText;
typedef NativeVideo =  cocktail.port.base.NativeMedia;
typedef FontBuilder = cocktail.port.platform.nme.FontBuilder;
#end

//default bindings for all the other platform to set a default 
//allowig build
#if (!flash && !nme && !air)
typedef PlatformTimer =  cocktail.port.base.PlatformTimerBase;
typedef GraphicsSurface = cocktail.port.base.GraphicsSurfaceBase;
typedef ImageResource = cocktail.port.base.ResourceBase;
typedef Keyboard = cocktail.port.base.KeyboardListenerBase;
typedef Mouse = cocktail.port.base.MouseListenerBase;
typedef NativeAudio =  cocktail.port.base.NativeMedia;
typedef NativeBitmapData =  Dynamic;
typedef NativeButton = cocktail.port.base.NativeInputBase;
typedef NativeTextElement =  Dynamic;
typedef NativeHttp =  cocktail.port.base.NativeHttpBase;
typedef NativeLayer =  Dynamic;
typedef NativePasswordInput = cocktail.port.base.NativeTextInputBase;
typedef NativeText =  cocktail.port.base.NativeTextBase;
typedef NativeTextArea = cocktail.port.base.NativeTextInputBase;
typedef NativeTextInput = cocktail.port.base.NativeTextInputBase;
typedef NativeVideo =  cocktail.port.base.NativeMedia;
typedef Platform =  cocktail.port.base.PlatformBase;
typedef FontBuilder = cocktail.port.base.FontBuilderBase;
typedef TouchListener = cocktail.port.base.TouchListenerBase;
#end	