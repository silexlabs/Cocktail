package ;

import cocktail.domObject.ImageDOMObject;
import haxe.Log;
import haxe.Timer;
import cocktail.domObject.GraphicDOMObject;
import cocktail.domObject.TextDOMObject;
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObjectData;
import cocktail.geom.GeomData;
import cocktail.domObject.DOMObject;
import cocktail.nativeReference.NativeReferenceManager;
import cocktail.resource.ResourceLoaderManager;


/**
 * Display an "analogue" and numeric clock updated each seconds
 * @author Yannick DOMINGUEZ
 */
class Clock 
{
	/**
	 * the background of the analogue clock
	 */
	private var _clockBackground:ImageDOMObject;
	
	/**
	 * the foreground of the analogue clock
	 */
	private var _clockForeGround:ImageDOMObject;
	
	/**
	 * the second needle of the clock
	 */
	private var _secondNeedle:ImageDOMObject;
	
	/**
	 * the minute needle of the clock
	 */
	private var _minuteNeedle:ImageDOMObject;
	
	/**
	 * the hour needle of the clock
	 */
	private var _hourNeedle:ImageDOMObject;
	
	/**
	 * the numeric clock 
	 */
	private var _clockDisplay:TextDOMObject;
	
	/**
	 * count the loading of assets
	 */
	private var _loadedAssetsCounter:Int;
	
	/**
	 * the center of the rotation for the second nedle
	 * as this needle goes further than the clock half
	 */
	private var _secondNeedleRotationCenter:Point;
	
	
	/**
	 * The root of the dom (stage in flash, body in html)
	 */
	private static var rootDOMObject:DOMObject;
	
	/**
	 * init the root dom object of the publication 
	 */
	public static function main()
	{
		rootDOMObject = new DOMObject(NativeReferenceManager.getRoot());
		
		//ibnstantiate the clock class
		var cl:Clock = new Clock();
	}
	
	/**
	 * starts the loading of all the clocks parts
	 */
	public function new() 
	{
		_loadedAssetsCounter = 0;
		
		ResourceLoaderManager.loadImage("assets/second_needle.png", onSecondNeedleLoaded, function(err){});
		ResourceLoaderManager.loadImage("assets/hour_needle.png", onHourNeedleLoaded, function(err){});
		ResourceLoaderManager.loadImage("assets/minute_needle.png", onMinuteNeedleLoaded, function(err){});
		ResourceLoaderManager.loadImage("assets/clock_background.png", onClockBackgroundLoaded, function(err){});
		ResourceLoaderManager.loadImage("assets/clock_foreground.png", onClockForegroundLoaded, function(err){});
	}
	
	/**
	 * Called once all the clock's assets
	 * are loaded
	 */
	private function init()
	{
		//init the numeric hour display
		_clockDisplay = new TextDOMObject();
		
		//ad all dom objects to the DOM
		rootDOMObject.addChild(_clockBackground);
		rootDOMObject.addChild(_secondNeedle);
		rootDOMObject.addChild(_minuteNeedle);
		rootDOMObject.addChild(_hourNeedle);
		rootDOMObject.addChild(_clockForeGround);
		rootDOMObject.addChild(_clockDisplay);
		
		//prepare the rotation center of the second needle
		var secondNeedleOffset:Float = 15.0;
		
		_secondNeedleRotationCenter = {
			x:_secondNeedle.width / 2,
			y:_secondNeedle.height - secondNeedleOffset
		}
		
		//move all the needles and the foreground to the center
		_secondNeedle.translate(_clockBackground.width / 2 - _secondNeedle.width /2, (_clockBackground.height / 2 - _secondNeedle.height + secondNeedleOffset));
		_minuteNeedle.translate(_clockBackground.width / 2 - _minuteNeedle.width / 2, (_clockBackground.height / 2 - _minuteNeedle.height ));
		_hourNeedle.translate(_clockBackground.width / 2 - _hourNeedle.width / 2, (_clockBackground.height / 2 - _hourNeedle.height));
		_clockForeGround.translate(_clockBackground.width / 2 - _clockForeGround.width / 2, (_clockBackground.height / 2 - _clockForeGround.height / 2));
		
		//set up the text display
		_clockDisplay.width = 300;
		_clockDisplay.y = _clockBackground.height;
		
		//update the needle position and the text display with the current time
		//and enter a loop, refreshing every second
		updateTime();
		
		
	}
	
	/**
	 * Update the clock display and set another delay
	 * re-calling this function every second
	 */
	private function updateTime():Void
	{
		_clockDisplay.text = Date.now().toString();
		
		_secondNeedle.setRotation(Math.round(Date.now().getSeconds() * 6), point(_secondNeedleRotationCenter));
		_minuteNeedle.setRotation(Math.round(Date.now().getMinutes() * 6), constant(center, bottom));
		_hourNeedle.setRotation(Math.round(Date.now().getHours() * (360/12)), constant(center, bottom));
		
		Timer.delay(updateTime, 1000);
	}
	

	
	/////////////////////////////////////////////
	// ASSET LOADING CALLBACK
	// Call the init method once all assets are loaded
	////////////////////////////////////////////
	
	private function onHourNeedleLoaded(imageDOMObject:ImageDOMObject):Void
	{
		_hourNeedle = imageDOMObject;
		checkLoadedAssets();
	}
	
	private function onMinuteNeedleLoaded(imageDOMObject:ImageDOMObject):Void
	{
		_minuteNeedle = imageDOMObject;
		checkLoadedAssets();
	}
	
	private function onSecondNeedleLoaded(imageDOMObject:ImageDOMObject):Void
	{
		_secondNeedle = imageDOMObject;
		checkLoadedAssets();
	}
	
	private function onClockBackgroundLoaded(imageDOMObject:ImageDOMObject):Void
	{
		_clockBackground = imageDOMObject;
		checkLoadedAssets();
	}
	
	private function onClockForegroundLoaded(imageDOMObject:ImageDOMObject):Void
	{
		_clockForeGround = imageDOMObject;
		checkLoadedAssets();
	}
	
	private function checkLoadedAssets()
	{
		_loadedAssetsCounter++;
		if (_loadedAssetsCounter == 5)
		{
			init();
		}
	}
	
	
}