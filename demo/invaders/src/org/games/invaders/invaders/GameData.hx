package org.games.invaders.invaders;

class GameData 
{
	public static inline var INVADER_ROWS:Int = 5;
	public static inline var INVADER_COLUMNS:Int = 11;
	public static inline var INVADERS_X:Int = 64;
	public static inline var INVADERS_Y:Int = 256;
	public static inline var INVADERS_SPACING:Int = 30;
 
	public static inline var SCREEN_WIDTH:Int = 1280;
	public static inline var SCREEN_HEIGHT:Int = 720;
	public static inline var INVADER_WIDTH:Int = 40;

	public static inline var INVADERS_X_RIGHT:Int = SCREEN_WIDTH - INVADERS_X 
		- ((INVADER_COLUMNS * INVADER_WIDTH) + (INVADER_COLUMNS * INVADERS_SPACING) - INVADERS_SPACING);

	public static inline var MAX_BULLETS:Int = 10;

	private function new(){}
}

enum GameState { GAMESTATE_WON; GAMESTATE_LOST; GAMESTATE_PLAYING; }

