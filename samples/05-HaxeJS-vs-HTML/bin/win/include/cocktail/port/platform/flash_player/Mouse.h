#ifndef INCLUDED_cocktail_port_platform_flash_player_Mouse
#define INCLUDED_cocktail_port_platform_flash_player_Mouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/base/MouseListenerBase.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,event,WheelEvent)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,port,base,MouseListenerBase)
HX_DECLARE_CLASS3(cocktail,port,base,PlatformBase)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Mouse)
HX_DECLARE_CLASS4(cocktail,port,platform,flash_player,Platform)
HX_DECLARE_CLASS2(native,display,BitmapData)
HX_DECLARE_CLASS2(native,display,IBitmapDrawable)
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{


class Mouse_obj : public ::cocktail::port::base::MouseListenerBase_obj{
	public:
		typedef ::cocktail::port::base::MouseListenerBase_obj super;
		typedef Mouse_obj OBJ_;
		Mouse_obj();
		Void __construct(::cocktail::port::platform::flash_player::Platform platform);

	public:
		static hx::ObjectPtr< Mouse_obj > __new(::cocktail::port::platform::flash_player::Platform platform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Mouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mouse"); }

		virtual ::cocktail::core::event::Event getEvent( Dynamic event);

		virtual ::cocktail::core::event::WheelEvent getWheelEvent( Dynamic event);

		virtual ::cocktail::core::event::MouseEvent getMouseEvent( Dynamic event);

		virtual Void removeNativeListeners( );

		virtual Void setNativeListeners( );

		virtual Void setBitmapCursor( ::native::display::BitmapData nativeBitmapData,::cocktail::core::geom::PointVO hotSpot);
		Dynamic setBitmapCursor_dyn();

		virtual Void setMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor);

};

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_platform_flash_player_Mouse */ 
