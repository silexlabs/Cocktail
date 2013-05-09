package cocktail.port;

#if (air && !macro)
typedef Platform =  cocktail.port.platform.air.Platform;

#elseif (flash && !macro)
typedef GraphicsContextImpl =  cocktail.port.platform.flash_player.GraphicsContextImpl;
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
typedef TimerImpl =  cocktail.port.platform.flash_player.TimerImpl;
typedef TouchListener =  cocktail.port.platform.flash_player.TouchListener;
typedef FontBuilder = cocktail.port.platform.flash_player.FontBuilder;

#elseif (nme && !macro)
typedef GraphicsContextImpl =  cocktail.port.platform.flash_player.GraphicsContextImpl;
typedef ImageResource = cocktail.port.platform.nme.ImageResource;
typedef Keyboard =  cocktail.port.platform.flash_player.Keyboard;
typedef Mouse =  cocktail.port.platform.flash_player.Mouse;
typedef NativeAudio =  cocktail.port.platform.nme.NativeAudio;
typedef NativeBitmapData =  flash.display.BitmapData;
typedef NativeButton =  cocktail.port.platform.flash_player.NativeButton;
typedef NativeLayer =  flash.display.DisplayObjectContainer;
typedef NativeTextElement =  flash.display.DisplayObject;
typedef NativeHttp =  cocktail.port.platform.nme.NativeHttp;
typedef NativePasswordInput =  cocktail.port.platform.flash_player.NativePasswordInput;
typedef NativeText =  cocktail.port.platform.nme.NativeText;
typedef NativeTextArea =  cocktail.port.platform.flash_player.NativeTextArea;
typedef NativeTextInput =  cocktail.port.platform.flash_player.NativeTextInput;
typedef NativeVideo =  cocktail.port.base.NativeMedia;
typedef Platform =  cocktail.port.platform.flash_player.Platform;
typedef FontBuilder = cocktail.port.platform.nme.FontBuilder;

#else
typedef GraphicsContextImpl = cocktail.core.graphics.AbstractGraphicsContextImpl;
typedef ImageResource = cocktail.core.resource.AbstractResource;
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
typedef TimerImpl = cocktail.core.timer.AbstractTimerImpl;
typedef FontBuilder = cocktail.port.base.FontBuilderBase;
typedef TouchListener = cocktail.port.base.TouchListenerBase;
#end	

typedef NativeCheckbox = cocktail.port.base.NativeInputBase;
typedef NativeInput = cocktail.port.base.NativeInputBase;
typedef NativeRadio = cocktail.port.base.NativeInputBase;