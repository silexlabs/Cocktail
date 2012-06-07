#ifndef INCLUDED_port_flash_player_HTMLInputElement
#define INCLUDED_port_flash_player_HTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/html/AbstractHTMLInputElement.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLInputElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLInputElement)
namespace port{
namespace flash_player{


class HTMLInputElement_obj : public ::core::html::AbstractHTMLInputElement_obj{
	public:
		typedef ::core::html::AbstractHTMLInputElement_obj super;
		typedef HTMLInputElement_obj OBJ_;
		HTMLInputElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLInputElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLInputElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLInputElement"); }

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_HTMLInputElement */ 
