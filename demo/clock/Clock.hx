package ;

import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import haxe.Log;
import haxe.Timer;
import cocktail.domElement.GraphicDOMElement;
import cocktail.textElement.TextElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;
import cocktail.geom.Matrix;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

/**
 * Display an "analog" and numeric clock updated each seconds
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
	 * the numeric clock container 
	 */
	private var _clockDisplay:ContainerDOMElement;
	
	/**
	 * the numeric clock text 
	 */
	private var _time:TextElement;

	
	/**
	 * count the loading of assets
	 */
	private var _loadedAssetsCounter:Int;
	
	/**
	 * the center of the rotation for the second nedle
	 * as this needle goes further than the clock half
	 */
	private var _secondNeedleRotationCenter:PointData;
	private var _minuteNeedleRotationCenter:PointData;
	private var _hourNeedleRotationCenter:PointData;
	
	
	/**
	 * The root of the dom (stage in flash, body in html)
	 */
	private static var rootDOMElement:BodyDOMElement;
	
	/**
	 * init the root dom element of the publication 
	 */
	public static function main()
	{
		rootDOMElement = new BodyDOMElement();
		
		//instantiate the clock class
		var cl:Clock = new Clock();
	}
	
	/**
	 * starts the loading of all the clocks parts
	 */
	public function new() 
	{
		_loadedAssetsCounter = 0;
		
		//ResourceLoaderManager.loadImage("assets/second_needle.png", onSecondNeedleLoaded, function(err){});
		//ResourceLoaderManager.loadImage("assets/hour_needle.png", onHourNeedleLoaded, function(err){});
		//ResourceLoaderManager.loadImage("assets/minute_needle.png", onMinuteNeedleLoaded, function(err){});
		//ResourceLoaderManager.loadImage("assets/clock_background.png", onClockBackgroundLoaded, function(err){});
		//ResourceLoaderManager.loadImage("assets/clock_foreground.png", onClockForegroundLoaded, function(err){});
		_secondNeedle = new ImageDOMElement();
		_hourNeedle = new ImageDOMElement();
		_minuteNeedle = new ImageDOMElement();
		_clockBackground = new ImageDOMElement();
		_clockForeGround = new ImageDOMElement();
		
		_secondNeedle.matrix = new Matrix();
		_hourNeedle.matrix = new Matrix();
		_minuteNeedle.matrix = new Matrix();
		_clockForeGround.matrix = new Matrix();
		//trace(_secondNeedle.matrix);
		
		_secondNeedle.onLoad = onSecondNeedleLoaded;
		_hourNeedle.onLoad = onHourNeedleLoaded;
		_minuteNeedle.onLoad = onMinuteNeedleLoaded;
		_clockBackground.onLoad = onClockBackgroundLoaded;
		_clockForeGround.onLoad = onClockForegroundLoaded;
		
		_secondNeedle.load("assets/second_needle.png");
		_hourNeedle.load("assets/hour_needle.png");
		_minuteNeedle.load("assets/minute_needle.png");
		_clockBackground.load("assets/clock_background.png");
		_clockForeGround.load("assets/clock_foreground.png");
	}
	
	/**
	 * Called once all the clock's assets
	 * are loaded
	 */
	private function init()
	{
		//init the numeric hour display
		_clockDisplay = new ContainerDOMElement();
		_time = new TextElement("");
		_clockDisplay.addText(_time);

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
			x:_secondNeedle.intrinsicWidth / 2,
			y:cast _secondNeedle.intrinsicHeight - secondNeedleOffset
		}
		//trace(_secondNeedleRotationCenter);
		_minuteNeedleRotationCenter = {
			x:_minuteNeedle.intrinsicWidth / 2,
			y:cast _minuteNeedle.intrinsicHeight
		}
		_hourNeedleRotationCenter = {
			x:_hourNeedle.intrinsicWidth / 2,
			y:cast _hourNeedle.intrinsicHeight
		}
		
		//set the pivot point for each needle
		//_secondNeedle.registrationPoint = point(_secondNeedleRotationCenter);
		//_minuteNeedle.registrationPoint = constant(center, bottom);
		//_hourNeedle.registrationPoint = constant(center, bottom);
		
		var secondNeedleRegistrationPoint:PointData = _secondNeedleRotationCenter;
		var minuteNeedleRegistrationPoint:PointData = _minuteNeedleRotationCenter;
		var hourNeedleRegistrationPoint:PointData = _hourNeedleRotationCenter;
		//_secondNeedle.matrix = new Matrix();
		
		//move all the needles and the foreground to the center
		_secondNeedle.matrix.translate(_clockBackground.intrinsicWidth / 2 - _secondNeedle.intrinsicWidth /2, (_clockBackground.intrinsicHeight / 2 - _secondNeedle.intrinsicHeight + secondNeedleOffset));
		_minuteNeedle.matrix.translate(_clockBackground.intrinsicWidth / 2 - _minuteNeedle.intrinsicWidth / 2, (_clockBackground.intrinsicHeight / 2 - _minuteNeedle.intrinsicHeight ));
		_hourNeedle.matrix.translate(_clockBackground.intrinsicWidth / 2 - _hourNeedle.intrinsicWidth / 2, (_clockBackground.intrinsicHeight / 2 - _hourNeedle.intrinsicHeight));
		_clockForeGround.matrix.translate(_clockBackground.intrinsicWidth / 2 - _clockForeGround.intrinsicWidth / 2, (_clockBackground.intrinsicHeight / 2 - _clockForeGround.intrinsicHeight / 2));_secondNeedle.matrix.translate(_clockBackground.intrinsicWidth / 2 - _secondNeedle.intrinsicWidth /2, (_clockBackground.intrinsicHeight / 2 - _secondNeedle.intrinsicHeight + secondNeedleOffset));
		
	
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
		_clockDisplay.removeText(_time);
		_time = new TextElement(Date.now().toString());
		_clockDisplay.addText(_time);
		
		_secondNeedle.rotation = Math.round(Date.now().getSeconds() * 6);
		//_secondNeedle.matrix.rotate(Math.round(Date.now().getSeconds() * 6), _secondNeedleRotationCenter);
		//trace(_secondNeedle.matrix);
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