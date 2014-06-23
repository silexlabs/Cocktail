/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.config;
import cocktail.event.CustomEvent;
import cocktail.event.EventConstants;
import cocktail.event.EventTarget;

/**
 * This class exposes global configuration parameters
 * used throughout cocktail.
 * 
 * All those parameters have a default value.
 * This default value can be overriden using a <meta>
 * tag, added in the head element of the document.
 * 
 * For instance, if you want to override the value
 * of the "defaultFont" attribute to set it to "sans-serif",
 * add the following meta tag to the document : 
	 * <meta name="defaultFont" content="sans-serif"></meta>
 * 
 * When a config value is updated this way, it dispatches an
 * event providing the name of the changed param
 * 
 * TODO 4 : for now implemented as singleton for simplicity,
 * if multiple document needed however, will need to be implemented
 * as a document instance
 * 
 * @author Yannick Dominguez 
 */
class Config extends EventTarget
{
	/**
	 * The distance in pixel that a touch on screen has to move to 
	 * prevent dispatching a click event on next touch up. 
	 * 
	 * If the touch moves more than this distance, then it is assumed
	 * that the user don't want to click but instead is scrolling 
	 * or drag'n'dropping an element
	 */ 
	public var touchMovePreventClickDistance(default, null):Int;
	
	/**
	 * Flash specific.
	 * 
	 * When true use flash StageVideo API introduce in flash player 10.2
	 * which allows hardware rendering of video for reduced cpu usage.
	 * If falls back to software rendering if hardware do not permit it.
	 * 
	 * It comes with some limitations, the main one being that the video
	 * is always behind the flash display list
	 * 
	 * Set to false if you want to always use software video in flash
	 */
	public var useStageVideoIfAvailable(default, null):Bool;
	
	/////////////////////////////////////////////////
	// FONT CONFIG
	/////////////////////////////////////////////////
	
	/**
	 * This is the name of the font used by default for an element
	 * when no other font is given
	 */
	public var defaultFont(default, null):String;
	
	/**
	 * The default color to use to render text when no other
	 * value is given for an element, as an hex value
	 */
	public var defaultFontColor(default, null):String;
	
	/**
	 * The actual font size when the 'xx-small' font size is
	 * used for an element
	 */
	public var xxSmallFontSize(default, null):Int;
	
	/**
	 * same as above for x-small
	 */
	public var xSmallFontSize(default, null):Int;
	
	/**
	 * same as above for small
	 */
	public var smallFontSize(default, null):Int;
	
	/**
	 * same as above for medium
	 */
	public var mediumFontSize(default, null):Int;
	
	/**
	 * same as above for large
	 */
	public var largeFontSize(default, null):Int;
	
	/**
	 * same as above for x-large
	 */
	public var xLargeFontSize(default, null):Int;
	
	/**
	 * same as above for xx-large
	 */
	public var xxLargeFontSize(default, null):Int;
	
	/////////////////////////////////////////////////
	// BORDER CONFIG
	/////////////////////////////////////////////////
	
	/**
	 * The actual border width used when 'thin' is used
	 * as border width
	 */
	public var thinBorderWidth:Int;
	
	/**
	 * same as above for 'medium'
	 */
	public var mediumBorderWidth:Int;
	
	/**
	 * same as above for 'thick'
	 */
	public var thickBorderWidth:Int;
	
	/////////////////////////////////////////////////
	// COMPOSITING CONFIG
	/////////////////////////////////////////////////
	
	/**
	 * Enable or disable compositing. Compositing is used
	 * for elements which require their own rendering surface, to respect z-order of the document.
	 * For instance, a video, a text input or a swf object in flash
	 * needs their own native surface, for instance a Sprite in flash.
	 * 
	 * You can disable it to improve performance by avoiding creating
	 * too many bitmap surface and/or native element, however element
	 * which would be otherwise composited will now always be on top
	 * of the rendered text and picture
	 */
	public var enableCompositing(default, null):Bool;
	
	/**
	 * This parameter only applies if ENABLE_COMPOSITING is false.
	 * 
	 * If false, plugin loaded with <object> tag, such as flash movies
	 * are displayed on top of cocktail's bitmap. Else, those plugin
	 * are below cocktail's bitmap and they can be seen if cocktail's bitmap
	 * is transparent where the plugin appears.
	 */
	public var objectBelowWhenNoCompositing(default, null):Bool;
	
	/**
	 * Same as OBJECT_BELOW_WHEN_NO_COMPOSITING, 
	 * but applies to video created with <Video> tag
	 */
	public var videoBelowWhenNoCompositing(default, null):Bool;
	
	/**
	 * instance for singleton
	 */
	private static var _instance:Config;
	
	/**
	 * implemented as a singleton
	 */
	private function new() 
	{
		super();
		
		touchMovePreventClickDistance = 10;

		useStageVideoIfAvailable = false;
		defaultFont = "serif";
		defaultFontColor = "#000000";
		
		xxSmallFontSize = 9;
		xSmallFontSize = 10;
		smallFontSize = 13;
		mediumFontSize = 16;
		largeFontSize = 18;
		xLargeFontSize = 24;
		xxLargeFontSize = 32;
		
		thinBorderWidth = 1;
		mediumBorderWidth = 3;
		thickBorderWidth = 5;
		
		enableCompositing = false;
		objectBelowWhenNoCompositing = true;
		videoBelowWhenNoCompositing = true;
	}
	
	/**
	 * singleton
	 */ 
	public static function getInstance():Config
	{
		if (_instance == null)
		{
			_instance = new Config();
		}
		
		return _instance;
	}
	
	/**
	 * Update the field of the config with the provided name
	 * if it exists with the provided value
	 */
	public function updateConfig(name:String, value:String):Void
	{
		var didUpdate:Bool = false;
		
		switch(name)
		{
			case "useStageVideoIfAvailable",
			"enableCompositing", "objectBelowWhenNoCompositing", "videoBelowWhenNoCompositing":
				updateBoolParam(name, value);
				didUpdate = true;
				
			case "touchMovePreventClickDistance", "xxSmallFontSize", "xSmallFontSize", "smallFontSize",
			"mediumFontSize", "largeFontSize", "xLargeFontSize", "xxLargeFontSize", "thinBorderWidth",
			"mediumBorderWidth", "thickBorderWidth":
				updateIntParam(name, value);
				didUpdate = true;
				
			case "defaultFont", "defaultFontColor":
				updateStringParam(name, value);
				didUpdate = true;
		}
		
		//if config actually changed, notify classes using config
		if (didUpdate == true)
		{
			var configEvent:CustomEvent = new CustomEvent();
			configEvent.initCustomEvent(EventConstants.CONFIG_CHANGED, false, false, name);
			dispatchEvent(configEvent);
		}
	}
	
	/**
	 * Set value for a Bool param, check validity of value
	 */
	private function updateBoolParam(name:String, value:String):Void
	{
		if (value == "true")
		{
			Reflect.setField(this, name, true);
		}
		else if (value == "false")
		{
			Reflect.setField(this, name, false);
		}
	}
	
	/**
	 * Set value for int param, check that string can be parsed
	 * as int
	 */
	private function updateIntParam(name:String, value:String):Void
	{
		var int:Null<Int> = Std.parseInt(value);
		if (int != null)
		{
			Reflect.setField(this, name, int);
		}
	}
	
	/**
	 * Set value of string param
	 */
	private function updateStringParam(name:String, value:String):Void
	{
		Reflect.setField(this, name, value);
	}
	
}
