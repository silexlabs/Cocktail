#ifndef INCLUDED_cocktail_core_mouse_MouseCursorManager
#define INCLUDED_cocktail_core_mouse_MouseCursorManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,mouse,AbstractMouseCursor)
HX_DECLARE_CLASS3(cocktail,core,mouse,MouseCursorManager)
HX_DECLARE_CLASS3(cocktail,core,mouse,MouseCursorValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MouseCursor)
namespace cocktail{
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

		static ::cocktail::port::flash_player::MouseCursor _mouseCursor; /* REM */ 
		static Void setMouseCursor( ::cocktail::core::mouse::MouseCursorValue mouseCursorValue);
		static Dynamic setMouseCursor_dyn();

		static ::cocktail::core::mouse::MouseCursorValue getMousecursor( );
		static Dynamic getMousecursor_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace mouse

#endif /* INCLUDED_cocktail_core_mouse_MouseCursorManager */ 
