#ifndef INCLUDED_cocktail_port_flash_player_MouseCursor
#define INCLUDED_cocktail_port_flash_player_MouseCursor

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/mouse/AbstractMouseCursor.h>
HX_DECLARE_CLASS3(cocktail,core,mouse,AbstractMouseCursor)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MouseCursor)
namespace cocktail{
namespace port{
namespace flash_player{


class MouseCursor_obj : public ::cocktail::core::mouse::AbstractMouseCursor_obj{
	public:
		typedef ::cocktail::core::mouse::AbstractMouseCursor_obj super;
		typedef MouseCursor_obj OBJ_;
		MouseCursor_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MouseCursor_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseCursor_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("MouseCursor"); }

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_MouseCursor */ 
