package org.games.pong.pong;

import org.games.pong.engine.MovingObject;
import cocktail.domElement.ContainerDOMElement;
import cocktail.style.StyleData;

class Ball extends MovingObject
{
	public static inline var IMAGE_URL = "assets/pong/ball.png";
	
	public var onTouchRightSide:Void->Void;
	public var onTouchLeftSide:Void->Void;
	public var onTouchTopSide:Void->Void;
	public var onTouchBottomSide:Void->Void;
	
	public function new(timeline:ContainerDOMElement)
	{
		super(timeline);
		imageDOMElement.load(IMAGE_URL);
		imageDOMElement.style.position = PositionStyleValue.absolute;
		imageDOMElement.zIndex = 10;
	}
	override public function update()
	{
		super.update();
		//trace("Update Ball !");
		
		if (x <= MARGIN_H)
			if (onTouchLeftSide != null)
				onTouchLeftSide();
			
		if (x + imageDOMElement.width >= _timeline.width - MARGIN_H)
			if (onTouchRightSide != null)
				onTouchRightSide();
			
		if (y <= 0)
			if (onTouchTopSide != null)
				onTouchTopSide();

		if (y + imageDOMElement.height >= _timeline.height)
			if (onTouchBottomSide != null)
				onTouchBottomSide();
		
	}
}
