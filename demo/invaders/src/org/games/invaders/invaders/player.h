#ifndef _player_h
#define _player_h

const Color PLAYER_COLOR = RGB(0, 31, 0);
const s16 PLAYER_X = (SCREEN_WIDTH / 2) - (PLAYER_WIDTH / 2); // center
const s16 PLAYER_Y = SCREEN_HEIGHT - PLAYER_HEIGHT - 8;
const u8 PLAYER_MARGIN = 16;

class Player : public Sprite {
	public:
		// Constructors
		Player() : Sprite(player_data, PLAYER_COLOR, PLAYER_X, PLAYER_Y, PLAYER_WIDTH, PLAYER_HEIGHT, 3) {
		}
		
		// Accessors
		void move_left(u8 amount);
		void move_right(u8 amount);
};

#endif
