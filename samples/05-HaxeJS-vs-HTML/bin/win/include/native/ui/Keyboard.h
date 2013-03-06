#ifndef INCLUDED_native_ui_Keyboard
#define INCLUDED_native_ui_Keyboard

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(native,ui,Keyboard)
namespace native{
namespace ui{


class Keyboard_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Keyboard_obj OBJ_;
		Keyboard_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Keyboard_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Keyboard_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Keyboard"); }

		static int A; /* REM */ 
		static int B; /* REM */ 
		static int C; /* REM */ 
		static int D; /* REM */ 
		static int E; /* REM */ 
		static int F; /* REM */ 
		static int G; /* REM */ 
		static int H; /* REM */ 
		static int I; /* REM */ 
		static int J; /* REM */ 
		static int K; /* REM */ 
		static int L; /* REM */ 
		static int M; /* REM */ 
		static int N; /* REM */ 
		static int O; /* REM */ 
		static int P; /* REM */ 
		static int Q; /* REM */ 
		static int R; /* REM */ 
		static int S; /* REM */ 
		static int T; /* REM */ 
		static int U; /* REM */ 
		static int V; /* REM */ 
		static int W; /* REM */ 
		static int X; /* REM */ 
		static int Y; /* REM */ 
		static int Z; /* REM */ 
		static int ALTERNATE; /* REM */ 
		static int BACKQUOTE; /* REM */ 
		static int BACKSLASH; /* REM */ 
		static int BACKSPACE; /* REM */ 
		static int CAPS_LOCK; /* REM */ 
		static int COMMA; /* REM */ 
		static int COMMAND; /* REM */ 
		static int CONTROL; /* REM */ 
		static int DELETE; /* REM */ 
		static int DOWN; /* REM */ 
		static int END; /* REM */ 
		static int ENTER; /* REM */ 
		static int EQUAL; /* REM */ 
		static int ESCAPE; /* REM */ 
		static int F1; /* REM */ 
		static int F2; /* REM */ 
		static int F3; /* REM */ 
		static int F4; /* REM */ 
		static int F5; /* REM */ 
		static int F6; /* REM */ 
		static int F7; /* REM */ 
		static int F8; /* REM */ 
		static int F9; /* REM */ 
		static int F10; /* REM */ 
		static int F11; /* REM */ 
		static int F12; /* REM */ 
		static int F13; /* REM */ 
		static int F14; /* REM */ 
		static int F15; /* REM */ 
		static int HOME; /* REM */ 
		static int INSERT; /* REM */ 
		static int LEFT; /* REM */ 
		static int LEFTBRACKET; /* REM */ 
		static int MINUS; /* REM */ 
		static int NUMBER_0; /* REM */ 
		static int NUMBER_1; /* REM */ 
		static int NUMBER_2; /* REM */ 
		static int NUMBER_3; /* REM */ 
		static int NUMBER_4; /* REM */ 
		static int NUMBER_5; /* REM */ 
		static int NUMBER_6; /* REM */ 
		static int NUMBER_7; /* REM */ 
		static int NUMBER_8; /* REM */ 
		static int NUMBER_9; /* REM */ 
		static int NUMPAD; /* REM */ 
		static int NUMPAD_0; /* REM */ 
		static int NUMPAD_1; /* REM */ 
		static int NUMPAD_2; /* REM */ 
		static int NUMPAD_3; /* REM */ 
		static int NUMPAD_4; /* REM */ 
		static int NUMPAD_5; /* REM */ 
		static int NUMPAD_6; /* REM */ 
		static int NUMPAD_7; /* REM */ 
		static int NUMPAD_8; /* REM */ 
		static int NUMPAD_9; /* REM */ 
		static int NUMPAD_ADD; /* REM */ 
		static int NUMPAD_DECIMAL; /* REM */ 
		static int NUMPAD_DIVIDE; /* REM */ 
		static int NUMPAD_ENTER; /* REM */ 
		static int NUMPAD_MULTIPLY; /* REM */ 
		static int NUMPAD_SUBTRACT; /* REM */ 
		static int PAGE_DOWN; /* REM */ 
		static int PAGE_UP; /* REM */ 
		static int PERIOD; /* REM */ 
		static int QUOTE; /* REM */ 
		static int RIGHT; /* REM */ 
		static int RIGHTBRACKET; /* REM */ 
		static int SEMICOLON; /* REM */ 
		static int SHIFT; /* REM */ 
		static int SLASH; /* REM */ 
		static int SPACE; /* REM */ 
		static int TAB; /* REM */ 
		static int UP; /* REM */ 
};

} // end namespace native
} // end namespace ui

#endif /* INCLUDED_native_ui_Keyboard */ 
