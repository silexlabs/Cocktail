#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#define INCLUDED_cocktail_core_html_HTMLBodyElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBodyElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLBodyElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef HTMLBodyElement_obj OBJ_;
		HTMLBodyElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLBodyElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLBodyElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLBodyElement"); }

		virtual Void initNativeElement( );
		Dynamic initNativeElement_dyn();

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		static ::String HTML_BODY_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLBodyElement */ 
