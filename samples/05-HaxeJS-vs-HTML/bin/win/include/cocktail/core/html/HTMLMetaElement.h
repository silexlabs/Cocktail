#ifndef INCLUDED_cocktail_core_html_HTMLMetaElement
#define INCLUDED_cocktail_core_html_HTMLMetaElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLMetaElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLMetaElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLMetaElement_obj OBJ_;
		HTMLMetaElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLMetaElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLMetaElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLMetaElement"); }

		virtual ::String set_content( ::String value);
		Dynamic set_content_dyn();

		virtual ::String get_content( );
		Dynamic get_content_dyn();

		virtual ::String set_name( ::String value);
		Dynamic set_name_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual Void updateConfig( );
		Dynamic updateConfig_dyn();

		virtual Void addedToDOM( );

		virtual ::String getAttribute( ::String attributeName);

		virtual Void setAttribute( ::String attributeName,::String value);

		::String content; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLMetaElement */ 
