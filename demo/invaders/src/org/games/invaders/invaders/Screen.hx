

package org.games.invaders.invaders;

class Screen 
{
	public static inline var SCREEN_TOP = 1;
	public static inline var SCREEN_BOTTOM = 0;

/*
void Screen::clear(Color color) const {
	u16 i;

	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		screens[SCREEN_TOP][i] = color;
		screens[SCREEN_BOTTOM][i] = color;
	}
}

void Screen::darken() const {
	u16 i;
	Color pixel;
	
	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		pixel = screens[SCREEN_TOP][i];
		screens[SCREEN_TOP][i] = ((pixel & 0x1F) >> 1) |
		                          ((((pixel >> 5) & 0x1F) >> 1) << 5) |
		                          ((((pixel >> 10) & 0x1F) >> 1) << 10) |
								  (1 << 15);
	}
}

Color Screen::get_pixel(u16 x, u16 y) const {
	u8 screen = SCREEN_TOP;
	
	if (y >= SCREEN_HEIGHT) {
		y -= SCREEN_HEIGHT;
		screen = SCREEN_BOTTOM;
	}
	
	return screens[screen][x + y * SCREEN_WIDTH];
}
*/
}
