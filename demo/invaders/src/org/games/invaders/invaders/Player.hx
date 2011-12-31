package org.games.invaders.invaders;

import org.games.invaders.engine.MovingObject;
import org.games.invaders.invaders.GameData;
import org.games.invaders.invaders.SpriteData;

class Player extends MovingObject
{
	public static inline var PLAYER_COLOR = 0x003100;
	public static inline var PLAYER_X = (GameData.SCREEN_WIDTH / 2) - (SpriteData.PLAYER_WIDTH / 2); // center
	public static inline var PLAYER_Y = GameData.SCREEN_HEIGHT - SpriteData.PLAYER_HEIGHT - 8;
	public static inline var PLAYER_MARGIN = 16;

	public function new()
	{
		super(SpriteData.player_data[0], PLAYER_COLOR, PLAYER_X, PLAYER_Y, SpriteData.PLAYER_WIDTH, SpriteData.PLAYER_HEIGHT, 3);
	}
	public function move_left(amount:Int)
	{
		if (x - amount < PLAYER_MARGIN) 
		{
			x = PLAYER_MARGIN;
		} else {
			x -= amount;
		}	
	}
	
	public function move_right(amount:Int)
	{
		if (x + amount > GameData.SCREEN_WIDTH - PLAYER_MARGIN - width)
		{
			x = GameData.SCREEN_WIDTH - PLAYER_MARGIN - width;
		} else {
			x += amount;
		}
	}
}
