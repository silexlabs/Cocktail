package org.games.invaders.engine;

import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

import org.games.invaders.invaders.GameData;
import org.games.invaders.invaders.InvadersGame;

class MovingObject 
{
//	public var timeline:ContainerDOMElement;
	public var domElement:ImageDOMElement;

	public var oldData:String;
	public var data:String;
	public var color:Int;
	public var x:Float;
	public var y:Float;
	public var width:Int;
	public var height:Int;
	public var frame:Int;
	public var num_frames:Int;
	

	public function new(/*the_timeline:ContainerDOMElement, */the_data:String, the_color:Int, the_x:Float, the_y:Float, the_width:Int, the_height:Int, the_num_frames:Int)
	{
		data = the_data;	
		color = the_color;
		x = the_x;
		y = the_y;
		width = the_width;
		height = the_height;
		num_frames = the_num_frames;
		frame = 0;
		oldData = "";

		domElement = new ImageDOMElement();
		
		InvadersGame.timeline.addChild(domElement);
		domElement.style.position = PositionStyleValue.absolute;
		domElement.x = -1000;
		domElement.y = 0;
		domElement.width = width * 2;
		domElement.height = height * 2;

//		timeline = the_timeline;

	}
	public function cleanup()
	{
		data = "";
		domElement.isVisible=false;
	}
	public function draw()
	{//trace(width);
		var offset:Float = 0*frame * width * height;
		var put_x:Int;
		var put_y:Int;
		var get_x:Int;
		var get_y:Int;
	
if (data=="") 
{
	domElement.isVisible=false;
	return;
}
		domElement.width = width;
		domElement.height = height;
		domElement.x = Math.round(x);
		domElement.y = Math.round(y);
		
		if (data != oldData)
			domElement.load(data);

		oldData = data;

/*		domElement.clear();
		domElement.beginFill(monochrome({color:0, alpha:100}));
//		domElement.drawRect(0, 0, width*2, height*2);
		domElement.endFill();


		domElement.beginFill(monochrome({color:0xFFFFFF, alpha:100}));
		get_x = 0;
		for (put_x in 0...Math.round(width)) 
		{
			get_y = 0;
		
			for (put_y in 0...Math.round(height)) 
			{
				if (data[Math.round(offset + get_x + (get_y * width))] == 1) 
				{
//					domElement.drawRect(put_x*2, put_y*2, (put_x+1)*2, (put_y+1)*2);
					domElement.drawRect(put_x, put_y, (put_x), (put_y));
				}
				get_y++;
			}		
			get_x++;
		}
		domElement.endFill();
*/	}
	public function collision(sprite:MovingObject)
	{
		var sprite1_x:Float = x;
		var sprite1_y:Float = y;
		var sprite1_width:Int = width;
		var sprite1_height:Int = height;
	
		var sprite2_x:Float = sprite.x;
		var sprite2_y:Float = sprite.y;
		var sprite2_width:Int = sprite.width;
		var sprite2_height:Int = sprite.height;
	
		// Fix a weird bug
		sprite2_x += sprite2_width / 2;

		return (sprite2_x >= sprite1_x - (sprite1_width + sprite2_width) / 2) &&
		       (sprite2_x <= sprite1_x + (sprite1_width + sprite2_width) / 2) &&
		       (sprite2_y >= sprite1_y - (sprite1_height + sprite2_height) / 2) &&
		       (sprite2_y <= sprite1_y + (sprite1_height + sprite2_height) / 2);
	}
}
