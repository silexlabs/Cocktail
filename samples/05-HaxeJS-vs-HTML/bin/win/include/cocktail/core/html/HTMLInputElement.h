#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#define INCLUDED_cocktail_core_html_HTMLInputElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLInputElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLInputElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLInputElement"); }

		virtual int get_maxLength( );
		Dynamic get_maxLength_dyn();

		virtual int set_maxLength( int value);
		Dynamic set_maxLength_dyn();

		virtual ::String get_value( );
		Dynamic get_value_dyn();

		virtual ::String set_value( ::String value);
		Dynamic set_value_dyn();

		virtual Dynamic get_intrinsicHeight( );

		virtual Dynamic get_intrinsicWidth( );

		virtual bool isDefaultFocusable( );

		virtual Void createElementRenderer( );

		virtual bool isVoidElement( );

		int maxLength; /* REM */ 
		::String value; /* REM */ 
		static int HTML_INPUT_TEXT_INTRINSIC_WIDTH; /* REM */ 
		static Float HTML_INPUT_TEXT_INTRINSIC_HEIGHT; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLInputElement */ 
