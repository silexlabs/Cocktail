package org.games.invaders.invaders;

import org.games.invaders.engine.MovingObject;
import org.games.invaders.invaders.Bullet;
import org.games.invaders.invaders.SpriteData;
import org.games.invaders.invaders.GameData;

enum InvaderType { INVADER_OCTOPUS; INVADER_CRAB; INVADER_SQUID; }
enum InvaderState { INVADER_OK; INVADER_EXPLODING; INVADER_DEAD; }

class Invader extends MovingObject
{
	public static inline var INVADER_COLOR = 0x313131;
	public var type:InvaderType;
	public var state:InvaderState;
	public var when_exploded:Int;

	public function new()
	{
		super(null, INVADER_COLOR, 0, 0, SpriteData.INVADER_WIDTH, SpriteData.INVADER_HEIGHT, 2);
		type = INVADER_OCTOPUS;
		state = INVADER_OK;
		when_exploded = 0;
	}

	public function init(the_type:InvaderType, the_x:Int, the_y:Int) 
	{
		type = the_type;
		x = the_x;
		y = the_y;

		var idx = 0;
		switch (type) 
		{
			case INVADER_OCTOPUS:
				idx = 0;
			
			case INVADER_CRAB:
				idx = 1;
			
			case INVADER_SQUID:
				idx = 2;
			
			default:
				idx = 0;
		}
	
		data = SpriteData.invaders_data[idx];
	}
	public function update(vblank_count:Int, animate:Bool, direction:Direction)
	{
		if (animate) 
		{
			frame++;
		
			switch (direction) 
			{
				case DIRECTION_UP:
					y -= 20;
			
				case DIRECTION_DOWN:
					y += 20;
			
				case DIRECTION_LEFT:
					x -= 8;
			
				case DIRECTION_RIGHT:
					x += 8;
			}
		}
	
		if (state == INVADER_EXPLODING) 
		{
			if (when_exploded == 0) 
			{
				when_exploded = vblank_count;
			
				data = SpriteData.invader_exploded[0];
				num_frames = 1;
				frame = 0;
			} else {
				if (vblank_count - when_exploded > 20) 
				{
					state = INVADER_DEAD;
				}
			}
		}
	}

	public function points_worth()
	{
		var points:Int;

		switch (type) 
		{
			case INVADER_OCTOPUS:
				points = 10;
			
			case INVADER_CRAB:
				points = 20;
			
			case INVADER_SQUID:
				points = 30;
			
			default:
				points = 0;
		}
	
		return points;
	}
}
