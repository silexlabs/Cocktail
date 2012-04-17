#ifndef INCLUDED_cocktail_port_flash_player_Window
#define INCLUDED_cocktail_port_flash_player_Window

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/window/AbstractWindow.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,window,AbstractWindow)
HX_DECLARE_CLASS3(cocktail,port,flash_player,Window)
namespace cocktail{
namespace port{
namespace flash_player{


class Window_obj : public ::cocktail::core::window::AbstractWindow_obj{
	public:
		typedef ::cocktail::core::window::AbstractWindow_obj super;
		typedef Window_obj OBJ_;
		Window_obj();
		Void __construct(::cocktail::core::dom::Document document);

	public:
		static hx::ObjectPtr< Window_obj > __new(::cocktail::core::dom::Document document);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Window_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Window"); }

		virtual Dynamic set_onResize( Dynamic value);
		Dynamic set_onResize_dyn();

		virtual int get_innerHeight( );
		Dynamic get_innerHeight_dyn();

		virtual int get_innerWidth( );
		Dynamic get_innerWidth_dyn();

		virtual Void onNativeResize( Dynamic event);
		Dynamic onNativeResize_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_Window */ 
