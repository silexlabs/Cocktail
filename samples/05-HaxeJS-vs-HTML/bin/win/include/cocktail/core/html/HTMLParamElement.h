#ifndef INCLUDED_cocktail_core_html_HTMLParamElement
#define INCLUDED_cocktail_core_html_HTMLParamElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLParamElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLParamElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLParamElement_obj OBJ_;
		HTMLParamElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLParamElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLParamElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLParamElement"); }

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::String set_name( ::String value);
		Dynamic set_name_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		virtual bool isVoidElement( );

		virtual Void createElementRenderer( );

		::String value; /* REM */ 
		::String name; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLParamElement */ 
