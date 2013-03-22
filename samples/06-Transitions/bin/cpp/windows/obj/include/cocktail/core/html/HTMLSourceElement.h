#ifndef INCLUDED_cocktail_core_html_HTMLSourceElement
#define INCLUDED_cocktail_core_html_HTMLSourceElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLSourceElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLSourceElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLSourceElement_obj OBJ_;
		HTMLSourceElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLSourceElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLSourceElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLSourceElement"); }

		virtual ::String set_media( ::String value);
		Dynamic set_media_dyn();

		virtual ::String get_media( );
		Dynamic get_media_dyn();

		virtual ::String set_type( ::String value);
		Dynamic set_type_dyn();

		virtual ::String get_type( );
		Dynamic get_type_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual ::String get_src( );
		Dynamic get_src_dyn();

		virtual bool isVoidElement( );

		virtual Void createElementRenderer( );

		::String media; /* REM */ 
		::String type; /* REM */ 
		::String src; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLSourceElement */ 
