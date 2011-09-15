package ;

import cocktail.domElement.ImageDOMElement;
import haxe.Log;
import haxe.Timer;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElementManager;
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
	private var _clockBackground:ImageDOMElement;
	
	/**
	 * the foreground of the analogue clock
	 */
	private var _clockForeGround:ImageDOMElement;
	
	/**
	 * the second needle of the clock
	 */
	private var _secondNeedle:ImageDOMElement;
	
	/**
	 * the minute needle of the clock
	 */
	private var _minuteNeedle:ImageDOMElement;
	
	/**
	 * the hour needle of the clock
	 */
	private var _hourNeedle:ImageDOMElement;
	
	/**
	 * the numeric clock 
	 */
	private var _clockDisplay:TextDOMElement;
	
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
	private static var rootDOMElement:DOMElement;
	
	/**
	 * init the root dom element of the publication 
	 */
	public static function main()
	{
		rootDOMElement = new DOMElement(NativeElementManager.getRoot());
		
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
		_clockDisplay = new TextDOMElement();
		
		//ad all dom elements to the DOM
		rootDOMElement.addChild(_clockBackground);
		rootDOMElement.addChild(_secondNeedle);
		rootDOMElement.addChild(_minuteNeedle);
		rootDOMElement.addChild(_hourNeedle);
		rootDOMElement.addChild(_clockForeGround);
		rootDOMElement.addChild(_clockDisplay);
		
		//prepare the rotation center of the second needle
		var secondNeedleOffset:Float = 15.0;
		
		_secondNeedleRotationCenter = {
			x:_secondNeedle.width / 2,
			y:_secondNeedle.height - secondNeedleOffset
		}
		
		//set the pivot point for each needle
		_secondNeedle.registrationPoint = point(_secondNeedleRotationCenter);
		_minuteNeedle.registrationPoint = constant(center, bottom);
		_hourNeedle.registrationPoint = constant(center, bottom);
		
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
		
		_secondNeedle.rotation = Math.round(Date.now().getSeconds() * 6);
		_minuteNeedle.rotation = Math.round(Date.now().getMinutes() * 6);
		_hourNeedle.rotation = Math.round(Date.now().getHours() * (360/12));
		
		Timer.delay(updateTime, 1000);
	}
	

	
	/////////////////////////////////////////////
	// ASSET LOADING CALLBACK
	// Call the init method once all assets are loaded
	////////////////////////////////////////////
	
	private function onHourNeedleLoaded(imageDOMElement:ImageDOMElement):Void
	{
		_hourNeedle = imageDOMElement;
		checkLoadedAssets();
	}
	
	private function onMinuteNeedleLoaded(imageDOMElement:ImageDOMElement):Void
	{
		_minuteNeedle = imageDOMElement;
		checkLoadedAssets();
	}
	
	private function onSecondNeedleLoaded(imageDOMElement:ImageDOMElement):Void
	{
		_secondNeedle = imageDOMElement;
		checkLoadedAssets();
	}
	
	private function onClockBackgroundLoaded(imageDOMElement:ImageDOMElement):Void
	{
		_clockBackground = imageDOMElement;
		checkLoadedAssets();
	}
	
	private function onClockForegroundLoaded(imageDOMElement:ImageDOMElement):Void
	{
		_clockForeGround = imageDOMElement;
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