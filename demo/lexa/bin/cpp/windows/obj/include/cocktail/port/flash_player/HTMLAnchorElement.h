#ifndef INCLUDED_cocktail_port_flash_player_HTMLAnchorElement
#define INCLUDED_cocktail_port_flash_player_HTMLAnchorElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/AbstractHTMLAnchorElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLAnchorElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLAnchorElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace port{
namespace flash_player{


class HTMLAnchorElement_obj : public ::cocktail::core::html::AbstractHTMLAnchorElement_obj{
	public:
		typedef ::cocktail::core::html::AbstractHTMLAnchorElement_obj super;
		typedef HTMLAnchorElement_obj OBJ_;
		HTMLAnchorElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLAnchorElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLAnchorElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLAnchorElement"); }

		virtual Void openDocument( );
		Dynamic openDocument_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_HTMLAnchorElement */ 
