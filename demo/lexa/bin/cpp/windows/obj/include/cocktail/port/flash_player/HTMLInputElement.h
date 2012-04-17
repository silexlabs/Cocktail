#ifndef INCLUDED_cocktail_port_flash_player_HTMLInputElement
#define INCLUDED_cocktail_port_flash_player_HTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/AbstractHTMLInputElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLInputElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLInputElement)
namespace cocktail{
namespace port{
namespace flash_player{


class HTMLInputElement_obj : public ::cocktail::core::html::AbstractHTMLInputElement_obj{
	public:
		typedef ::cocktail::core::html::AbstractHTMLInputElement_obj super;
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

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_HTMLInputElement */ 
