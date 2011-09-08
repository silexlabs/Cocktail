package ;

import haxe.Log;
import haxe.Timer;
import cocktail.domObject.GraphicDOMObject;
import cocktail.domObject.TextDOMObject;
import cocktail.domObject.base.DOMObjectBase;
import cocktail.domObject.DOMObjectData;
import cocktail.geom.GeomData;
import cocktail.domObject.DOMObject;
import cocktail.nativeReference.NativeReferenceManager;

/**
 * Display an "analogue" and numeric clock updated each seconds
 * @author Yannick DOMINGUEZ
 */
class Clock 
{
	/**
	 * the background of the analogue clock
	 */
	private var _clockBackground:GraphicDOMObject;
	
	/**
	 * the second needle of the clock
	 */
	private var _clockSeconds:GraphicDOMObject;
	
	/**
	 * the numeric clock 
	 */
	private var _clockDisplay:TextDOMObject;
	
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
	 * draw/instantiate all the clock parts, set
	 * them up and start the clock update  
	 */
	public function new() 
	{
		_clockBackground = getClockBackground();
		_clockSeconds = getClockSeconds();
		_clockDisplay = new TextDOMObject();
		
		_clockSeconds.translate(200.0, 0);
		
		_clockDisplay.y = 400;
		_clockDisplay.width = 300;
		_clockDisplay.height = 300;
		
		rootDOMObject.addChild(_clockBackground);
		rootDOMObject.addChild(_clockSeconds);
		rootDOMObject.addChild(_clockDisplay);
		
		
		Timer.delay(updateTime, 1000);
		
	}
	
	/**
	 * Update the clock display and set another delay
	 * re-calling this function every second
	 */
	private function updateTime():Void
	{
		_clockDisplay.text = Date.now().toString();
		_clockSeconds.setRotation(Math.round(Date.now().getSeconds() * 6), constant(center, bottom));
		
		Timer.delay(updateTime, 1000);
	}
	
	/**
	 * draw and return the clock background
	 */
	private function getClockBackground():GraphicDOMObject
	{
		var clockBackground:GraphicDOMObject = new GraphicDOMObject();
		
		clockBackground.width = 400;
		clockBackground.height = 400;
		
		var gradientStops:Array<GradientStopData> = [];
		gradientStops.push( { colorStop: { color:Std.parseInt("0xDDDDDD"), alpha:100 }, ratio:0 } );
		gradientStops.push( { colorStop: { color:Std.parseInt("0xAAAAAA"), alpha:100 }, ratio:100 } );
		
		var gradientStyle:GradientStyleData = {
			gradientType:linear,
			gradientStops:gradientStops,
			rotation:90		}
	
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		var fillStyle:FillStyleValue = gradient(gradientStyle);
		
		clockBackground.beginFill(fillStyle, lineStyle);
		
		clockBackground.drawEllipse(0, 0, 400, 400);
		clockBackground.endFill();
		
		return clockBackground;
	}
	
	/**
	 * draw and return the clock seconds needle
	 */
	private function getClockSeconds():GraphicDOMObject
	{
		var clockSeconds:GraphicDOMObject = new GraphicDOMObject();
		
		clockSeconds.width = 5;
		clockSeconds.height = 200;
		
		var colorStop:ColorStopData = { color:Std.parseInt("0x000000") , alpha:100 };
		
		var fillStyle:FillStyleValue = monochrome(colorStop);
		
		var lineStyle:LineStyleValue = LineStyleValue.none;
		
		clockSeconds.beginFill(fillStyle, lineStyle);
		
		var cornerRadiuses:CornerRadiusData = {
			tlCornerRadius:3,
			trCornerRadius:3,
			blCornerRadius:0,
			brCornerRadius:0
		}
		
		
		clockSeconds.drawRect(0, 0, 5, 200, cornerRadiuses);
		clockSeconds.endFill();
		
		return clockSeconds;
	}
	
}