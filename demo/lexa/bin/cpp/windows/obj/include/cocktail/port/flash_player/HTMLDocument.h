#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#define INCLUDED_cocktail_port_flash_player_HTMLDocument

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/AbstractHTMLDocument.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Document)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLDocument)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLDocument)
namespace cocktail{
namespace port{
namespace flash_player{


class HTMLDocument_obj : public ::cocktail::core::html::AbstractHTMLDocument_obj{
	public:
		typedef ::cocktail::core::html::AbstractHTMLDocument_obj super;
		typedef HTMLDocument_obj OBJ_;
		HTMLDocument_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLDocument_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLDocument_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLDocument"); }

		virtual Void attachNativeElement( Dynamic nativeElement);
		Dynamic attachNativeElement_dyn();

		virtual Void detachNativeElement( Dynamic nativeElement);
		Dynamic detachNativeElement_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_HTMLDocument */ 
