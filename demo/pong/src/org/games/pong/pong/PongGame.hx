package org.games.pong.pong;
import haxe.Timer;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.BodyDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import cocktail.keyboard.KeyboardData;
import cocktail.unit.UnitData;
import cocktail.mouse.MouseData;

class PongGame 
{
	private var _ball:Ball;
	private var _isMouseDown:Bool;
	private var _bat01:Bat;
	private var _bat02:Bat;
	private var _mouseX:Int;
	private var _mouseY:Int;
	public static inline var FG_IMAGE_URL = "assets/pong/foreground.png";
	public static inline var BG_IMAGE_URL = "assets/pong/background.png";
	public static inline var MARGIN_H = 200;
	public static inline var MARGIN_V = 200;
	
	public function new()
	{
		trace("New Pong Game !");
		
		_isMouseDown = false;
		
		// main container
		var timeline:ContainerDOMElement = new ContainerDOMElement();
		var bodyDOMElement:BodyDOMElement = new BodyDOMElement();
		timeline.style.position = PositionStyleValue.absolute;
		timeline.style.display = DisplayStyleValue.block;
		timeline.style.width = DimensionStyleValue.percent(100);
		timeline.style.height = DimensionStyleValue.percent(100);
		timeline.x = 0;
		timeline.y = 0;
		bodyDOMElement.addChild(timeline);

		// background
		var bgDOMElement = new ImageDOMElement();
		bgDOMElement.load(BG_IMAGE_URL);
		bgDOMElement.style.position = PositionStyleValue.absolute;
		//bgDOMElement.style.display = DisplayStyleValue.block;
		bgDOMElement.style.width = DimensionStyleValue.percent(100);
		bgDOMElement.style.height = DimensionStyleValue.percent(100);
		bgDOMElement.x = 0;
		bgDOMElement.y = 0;
		//bgDOMElement.alpha = .8;
		bgDOMElement.onMouseDown = onMouseDown;
		bgDOMElement.onMouseUp = onMouseUp;
		//bgDOMElement.onMouseMove = onMouseMove;
		timeline.addChild(bgDOMElement); 

		// ball
		_ball = new Ball(timeline);
		_ball.onTouchLeftSide = ballOutYourSide;
		_ball.onTouchRightSide = ballOutMySide;
		_ball.imageDOMElement.alpha = 0;

		// bat1
		_bat01 = new Bat(timeline);
		_bat01.imageDOMElement.alpha = 0;
		_bat01.imageDOMElement.style.left = PositionOffsetStyleValue.length(px(0));
		_bat01.imageDOMElement.style.marginLeft = MarginStyleValue.length(px(MARGIN_H));
		
		// bat1
		_bat02 = new Bat(timeline);
		_bat02.imageDOMElement.alpha = 0;
		_bat02.imageDOMElement.style.right = PositionOffsetStyleValue.length(px(0));
		_bat02.imageDOMElement.style.marginRight = MarginStyleValue.length(px(MARGIN_H));
		
		// foreround stripes
/*		var fgDOMElement = new ImageDOMElement();
		fgDOMElement.load(FG_IMAGE_URL);
		fgDOMElement.style.position = PositionStyleValue.absolute;
		//fgDOMElement.style.display = DisplayStyleValue.block;
		fgDOMElement.style.width = DimensionStyleValue.percent(100);
		fgDOMElement.style.height = DimensionStyleValue.percent(100);
		fgDOMElement.x = 0;
		fgDOMElement.y = 0;
//		fgDOMElement.zIndex = 100;
		timeline.addChild(fgDOMElement); 
*/
		// events
		attachKeyboardEvents(bgDOMElement);
		
		// 
		reset();

	}
	public function reset()
	{
		_ball.imageDOMElement.alpha = 1;
		_ball.x = MARGIN_H + 100;
		_ball.y = MARGIN_V + 15;
		_ball.speedX = 5;
		_ball.speedY = 3;

		_bat01.imageDOMElement.alpha = 1;
		_bat01.y = 10;

		_bat02.imageDOMElement.alpha = 1;
		_bat02.y = 10;
	}
	public function ballOutMySide()
	{
		if(_ball.y < _bat02.y || _ball.y > _bat02.y + _bat02.imageDOMElement.height)
		{
			reset();
			iLost();
		}
		else
		{
			// speed up
			_ball.speedY += _bat02.speedY * .3;
			if (_ball.speedY > 10) _ball.speedY = 10;
			_ball.speedX *= 1.1;
		}
	}
	public function ballOutYourSide()
	{
		if(_ball.y < _bat01.y || _ball.y > _bat01.y + _bat01.imageDOMElement.height)
		{
			reset();
			iWon();
		}
		else
		{
			// speed up
			_ball.speedY += _bat01.speedY * .3;
			if (_ball.speedY > 10) _ball.speedY = 10;
			_ball.speedX *= 1.1;
		}
	}
	public function iWon()
	{
		trace("I WON");
	}
	public function iLost()
	{
		trace("I LOST");
	}
	public function attachKeyboardEvents(bgDOMElement:DOMElement)
	{
		bgDOMElement.onKeyDown = onKeyDown;
	}
	public function onMouseDown(mouseEventData:MouseEventData)
	{
		trace("onMouseDown " + mouseEventData.mousePosition.localY + " - "+_bat01.y);
		_isMouseDown = true;
		onMouseMove(mouseEventData);
	}
	public function onMouseUp(mouseEventData:MouseEventData)
	{
		trace("onMouseUp " + mouseEventData.mousePosition);
		_isMouseDown = false;
	}
	public function onMouseMove(mouseEventData:MouseEventData)
	{
		_mouseX = Math.round(mouseEventData.mousePosition.localX);
		_mouseY = Math.round(mouseEventData.mousePosition.localY);
		followMousePosition();
	}

	public function followMousePosition()
	{
		//trace("onMouseMove " + mouseEventData.mousePosition);
		if (_mouseY > _bat01.y +(_bat01.imageDOMElement.height / 2))
			goDown();
		else
			goUp();
	}
	public function goUp()
	{
		_bat01.speedY -= 22;
	}
	public function goDown()
	{
		_bat01.speedY += 22;
	}
	public function onKeyDown(key:KeyEventData)
	{
		//trace(key);
		if (key.value == KeyboardKeyValue.down)
			goDown();
		else if (key.value == KeyboardKeyValue.up)
			goUp();
	}
	
	public function mainLoop()
	{
		_ball.update();
		_bat01.update();
		
//		if(_ball.y < _bat02.y + (_bat02.imageDOMElement.height / 2))
		if(_ball.y < _bat02.y + 20)
			_bat02.accelY -= Math.random() * 3.6;
//		else if(_ball.y > _bat02.y +(_bat02.imageDOMElement.height / 2))
		else if(_ball.y > _bat02.y + _bat02.imageDOMElement.height - 20)
			_bat02.accelY += Math.random() * 3.6;
			
		_bat02.update();
		
		// follow mouse position
		if (_isMouseDown)
		{
			followMousePosition();
		}
	}
}
