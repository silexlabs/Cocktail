package org.games.invaders.invaders;

import org.games.invaders.engine.MovingObject;
import org.games.invaders.invaders.SpriteData;
import org.games.invaders.invaders.GameData;

enum BulletType { BULLET_HUMAN; BULLET_SQUIGGLY; BULLET_CROSS; }
enum Direction { DIRECTION_UP; DIRECTION_DOWN; DIRECTION_LEFT; DIRECTION_RIGHT; }

class Bullet extends MovingObject
{
	public static inline var BULLET_COLOR = 0x1F;
	public var type:BulletType;
	public var direction:Direction;

	public function new()
	{
		super(null, BULLET_COLOR, 0, 0, SpriteData.BULLET_WIDTH, SpriteData.BULLET_HEIGHT, 2);
	}
	public function move():Bool
	{
		var speed:Float;

		switch (type) {
			case BULLET_HUMAN:
				speed = 12;
		
			case BULLET_SQUIGGLY:
				speed = 8;

			case BULLET_CROSS:
				speed = 8;
		}

		switch (direction) {
			case DIRECTION_UP:
				y -= speed;

			case DIRECTION_DOWN:
				y += speed;
			default:
		}
	
		if (y < 30 || y > Player.PLAYER_Y + SpriteData.PLAYER_HEIGHT - height) {
			return false;
		} else {
			return true;
		}
	}

	public function init(the_type, the_x, the_y)
	{
		type = the_type;
		var idx = 0;
	
		switch (type) {
			case BULLET_HUMAN:
				direction = DIRECTION_UP;
				idx = 0;
			
			case BULLET_SQUIGGLY:
				direction = DIRECTION_DOWN;
				idx = 1;

			case BULLET_CROSS:
				direction = DIRECTION_DOWN;
				idx = 2;
		}
	
		data = SpriteData.bullets_data[idx];
		x = the_x;
		y = the_y;
	}
}
