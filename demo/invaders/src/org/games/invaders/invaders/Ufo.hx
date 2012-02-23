package org.games.invaders.invaders;

import org.games.invaders.engine.MovingObject;
import org.games.invaders.invaders.Bullet;
import org.games.invaders.invaders.SpriteData;
import org.games.invaders.invaders.GameData;

enum UfoState { UFO_FLYING; UFO_NOT_FLYING; UFO_SHOT_DOWN; }

class Ufo extends MovingObject
{
	public static inline var UFO_COLOR = 0x310000;
	public static inline var UFO_Y = 120;

	public var direction:Direction;
	public var state:UfoState;
	public var timer:Int;
	public var last_score:Int;

	public function new()
	{
		super(SpriteData.ufo_data[0], UFO_COLOR, -(SpriteData.UFO_WIDTH), UFO_Y, SpriteData.UFO_WIDTH, SpriteData.UFO_HEIGHT, 1);
		state = UFO_NOT_FLYING;
	}

	public function move()
	{
		if (state == UFO_FLYING) {
			switch (direction) {
				case DIRECTION_LEFT:
					if (x < -width) {
						state = UFO_NOT_FLYING;
					} else {
						x -= 16;
					}
		
				case DIRECTION_RIGHT:
					if (x > GameData.SCREEN_WIDTH) {
						state = UFO_NOT_FLYING;
					} else {
						x += 16;
					}
				default:
			}
		}
	
		if (state == UFO_SHOT_DOWN && timer >= 16) {
			state = UFO_NOT_FLYING;
			timer = 0;
			cleanup();
		}
	
		if (state == UFO_SHOT_DOWN) {
			if (timer % 4 == 0 || timer == 0) {
				//font.set_color(RGB(31, 0, 0));
				//font.print_number(last_score, x + 2, y + 1);
			} else if (timer % 2 == 0) {
				//font.set_color(RGB(0, 0, 0));
				//font.print_number(last_score, x + 2, y + 1);
			}
			timer++;
		}
	}

	public function reset()
	{
		if (Math.random() <.5) {
			direction = DIRECTION_LEFT;
			x = GameData.SCREEN_WIDTH;
		} else {
			direction = DIRECTION_RIGHT;
			x = -width;
		}
	
		state = UFO_FLYING;
	}

	public function score():Int
	{
		var possible_scores = [50, 100, 150, 200, 250, 300];
		last_score = possible_scores[Math.round(Math.random() * 5)];
		return last_score;
	}
}
