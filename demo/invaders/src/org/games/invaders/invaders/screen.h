#ifndef _screen_h
#define _screen_h

#ifndef NULL
#define NULL 0
#endif

const u8 SCREEN_TOP = 1;
const u8 SCREEN_BOTTOM = 0;

typedef u16 Color;

// RGB15() is defined in libnds, but it doesn't set bit 15 which is needed when
// displaying the color on the screen. This macro sets bit 15.
#define RGB(r, g, b) (RGB15((r), (g), (b)) | BIT(15))

class Screen {
	public:
		Screen();
		~Screen();
		void clear(Color color) const;
		void darken() const;
		void plot(u8 x, u8 y, Color color) { screens[SCREEN_TOP][x + y * SCREEN_WIDTH] = color; }
		void swap() { lcdSwap(); screens_swapped = !screens_swapped; }
		bool swapped() const { return screens_swapped; }
		Color get_pixel(u16 x, u16 y) const;
	private:
		Color *screens[2];
		bool screens_swapped;
};

extern Screen screen;

#endif
