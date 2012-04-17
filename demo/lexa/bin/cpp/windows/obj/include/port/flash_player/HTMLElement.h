#ifndef INCLUDED_port_flash_player_HTMLElement
#define INCLUDED_port_flash_player_HTMLElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/html/AbstractHTMLElement.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
namespace port{
namespace flash_player{


class HTMLElement_obj : public ::core::html::AbstractHTMLElement_obj{
	public:
		typedef ::core::html::AbstractHTMLElement_obj super;
		typedef HTMLElement_obj OBJ_;
		HTMLElement_obj();
		Void __construct(::String tagName);

	public:
		static hx::ObjectPtr< HTMLElement_obj > __new(::String tagName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLElement"); }

};

} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_port_flash_player_HTMLElement */ 
