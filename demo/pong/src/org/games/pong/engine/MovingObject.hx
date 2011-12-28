package org.games.pong.engine;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.ContainerDOMElement;

class MovingObject 
{
	public var MARGIN_H:Int;
	public var MARGIN_V:Int;
	private var _timeline:ContainerDOMElement;

	public var x:Float;
	public var y:Float;
	public var speedX:Float;
	public var speedY:Float;
	public var accelX:Float;
	public var accelY:Float; 
	
	public var imageDOMElement:ImageDOMElement;

	public function new(timeline:ContainerDOMElement)
	{
		MARGIN_H = 220;
		MARGIN_V = 200;
		_timeline = timeline;
		x = y = speedX = speedY = accelX = accelY = 0;
		imageDOMElement = new ImageDOMElement();
		timeline.addChild(imageDOMElement);
	}
	public function update()
	{
		updateHorizontal();
		updateVertical();
	}
	public function updateHorizontal()
	{
		speedX += accelX;
		x += speedX;
		
		if (x < MARGIN_H)
		{
			x = MARGIN_H;
			speedX = -speedX;
		}
		else if (x + imageDOMElement.width > _timeline.width - MARGIN_H)
		{
			x = _timeline.width - imageDOMElement.width - MARGIN_H;
			speedX = -speedX;
		}

		imageDOMElement.x = Math.round(x);
	}
	public function updateVertical()
	{
		speedY += accelY;
		y += speedY;
		
		if (y < MARGIN_V)
		{
			y = MARGIN_V;
			speedY = -speedY;
		}
		else if (y + imageDOMElement.height > _timeline.height - MARGIN_V)
		{
			y = _timeline.height - imageDOMElement.height - MARGIN_V;
			speedY = -speedY;
		}

		imageDOMElement.y = Math.round(y);
	}
}
