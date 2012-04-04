#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#define INCLUDED_cocktail_port_flash_player_HTMLElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/AbstractHTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace port{
namespace flash_player{


class HTMLElement_obj : public ::cocktail::core::html::AbstractHTMLElement_obj{
	public:
		typedef ::cocktail::core::html::AbstractHTMLElement_obj super;
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

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_HTMLElement */ 
