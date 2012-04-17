#ifndef INCLUDED_port_flash_player_Mouse
#define INCLUDED_port_flash_player_Mouse

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/mouse/AbstractMouse.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,event,MouseEvent)
HX_DECLARE_CLASS2(core,event,UIEvent)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,mouse,AbstractMouse)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,Mouse)
namespace port{
namespace flash_player{


class Mouse_obj : public ::core::mouse::AbstractMouse_obj{
	public:
		typedef ::core::mouse::AbstractMouse_obj super;
		typedef Mouse_obj OBJ_;
		Mouse_obj();
		Void __construct(::port::flash_player::HTMLElement htmlElement);

	public:
		static hx::ObjectPtr< Mouse_obj > __new(::port::flash_player::HTMLElement htmlElement);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Mouse_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mouse"); }

		virtual Void updateListeners( ::String mouseEvent,Dynamic nativeCallback,Dynamic htmlElementCallback);
		Dynamic updateListeners_dyn();

		virtual ::core::event::MouseEvent getMouseEvent( Dynamic event);
		Dynamic getMouseEvent_dyn();

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_Mouse */ 
