#ifndef INCLUDED_core_mouse_MouseCursorManager
#define INCLUDED_core_mouse_MouseCursorManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,mouse,AbstractMouseCursor)
HX_DECLARE_CLASS2(core,mouse,MouseCursorManager)
HX_DECLARE_CLASS2(core,mouse,MouseCursorValue)
HX_DECLARE_CLASS2(port,flash_player,MouseCursor)
namespace core{
namespace mouse{


class MouseCursorManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MouseCursorManager_obj OBJ_;
		MouseCursorManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MouseCursorManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseCursorManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseCursorManager"); }

		static ::port::flash_player::MouseCursor _mouseCursor; /* REM */ 
		static Void setMouseCursor( ::core::mouse::MouseCursorValue mouseCursorValue);
		static Dynamic setMouseCursor_dyn();

		static ::core::mouse::MouseCursorValue getMousecursor( );
		static Dynamic getMousecursor_dyn();

};

} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_core_mouse_MouseCursorManager */ 
