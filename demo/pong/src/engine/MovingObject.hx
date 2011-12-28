package engine;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.ContainerDOMElement;

class MovingObject 
{
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
		
		if (x < 0)
		{
			x = 0;
			speedX = -speedX;
		}
		else if (x + imageDOMElement.width > _timeline.width)
		{
			x = _timeline.width - imageDOMElement.width;
			speedX = -speedX;
		}

		imageDOMElement.x = Math.round(x);
	}
	public function updateVertical()
	{
		speedY += accelY;
		y += speedY;
		
		if (y < 0)
		{
			y = 0;
			speedY = -speedY;
		}
		else if (y + imageDOMElement.height > _timeline.height)
		{
			y = _timeline.height - imageDOMElement.height;
			speedY = -speedY;
		}

		imageDOMElement.y = Math.round(y);
	}
}
