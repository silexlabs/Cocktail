package org.games.pong.pong;

import org.games.pong.engine.MovingObject;
import cocktail.domElement.ContainerDOMElement;
import cocktail.style.StyleData;

class Bat extends MovingObject
{
	public static inline var IMAGE_URL = "assets/pong/bat.png";
	public function new(timeline:ContainerDOMElement)
	{
		super(timeline);
		imageDOMElement.load(IMAGE_URL);
		imageDOMElement.style.position = PositionStyleValue.absolute;
		imageDOMElement.zIndex = 10;
	}
	override public function update()
	{
		//super.update();
		//trace("Update Ball !");
		
		updateVertical();
		speedY /= 1.5;
		accelY /= 1.5;
	}
}
