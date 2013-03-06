#ifndef INCLUDED_cocktail_core_html_HTMLLinkElement
#define INCLUDED_cocktail_core_html_HTMLLinkElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,css,CSSStyleSheet)
HX_DECLARE_CLASS3(cocktail,core,css,StyleSheet)
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLLinkElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLLinkElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLLinkElement_obj OBJ_;
		HTMLLinkElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLLinkElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLLinkElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLLinkElement"); }

		virtual ::String set_type( ::String value);
		Dynamic set_type_dyn();

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual ::String set_hreflang( ::String value);
		Dynamic set_hreflang_dyn();

		virtual ::String get_hreflang( );
		Dynamic get_hreflang_dyn();

		virtual ::String set_media( ::String value);
		Dynamic set_media_dyn();

		virtual ::String get_media( );
		Dynamic get_media_dyn();

		virtual Array< ::String > get_relList( );
		Dynamic get_relList_dyn();

		virtual ::String set_rel( ::String value);
		Dynamic set_rel_dyn();

		virtual ::String get_rel( );
		Dynamic get_rel_dyn();

		virtual ::String set_href( ::String value);
		Dynamic set_href_dyn();

		virtual ::String get_href( );
		Dynamic get_href_dyn();

		virtual bool set_disabled( bool value);
		Dynamic set_disabled_dyn();

		virtual bool get_disabled( );
		Dynamic get_disabled_dyn();

		virtual Void createStyleSheet( ::String css);
		Dynamic createStyleSheet_dyn();

		virtual Void onCSSLoaded( ::cocktail::core::event::Event event);
		Dynamic onCSSLoaded_dyn();

		virtual Void unloadLinkedResource( );
		Dynamic unloadLinkedResource_dyn();

		virtual Void loadLinkedResource( );
		Dynamic loadLinkedResource_dyn();

		virtual Void createElementRenderer( );

		virtual Void removedFromDOM( );

		virtual Void addedToDOM( );

		bool _hasLoadedResource; /* REM */ 
		::cocktail::core::css::CSSStyleSheet sheet; /* REM */ 
		::String type; /* REM */ 
		::String hreflang; /* REM */ 
		::String media; /* REM */ 
		Array< ::String > relList; /* REM */ 
		::String rel; /* REM */ 
		::String href; /* REM */ 
		bool disabled; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLLinkElement */ 
