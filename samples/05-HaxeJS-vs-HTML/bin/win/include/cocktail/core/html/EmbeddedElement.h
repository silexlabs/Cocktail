#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#define INCLUDED_cocktail_core_html_EmbeddedElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class EmbeddedElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
		typedef EmbeddedElement_obj OBJ_;
		EmbeddedElement_obj();
		Void __construct(::String tagName);

	public:
		static hx::ObjectPtr< EmbeddedElement_obj > __new(::String tagName);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedElement"); }

		virtual int get_height( );
		Dynamic get_height_dyn();

		virtual int set_height( int value);
		Dynamic set_height_dyn();

		virtual int get_width( );
		Dynamic get_width_dyn();

		virtual int set_width( int value);
		Dynamic set_width_dyn();

		virtual Dynamic get_intrinsicRatio( );
		Dynamic get_intrinsicRatio_dyn();

		virtual Dynamic get_intrinsicWidth( );
		Dynamic get_intrinsicWidth_dyn();

		virtual Dynamic get_intrinsicHeight( );
		Dynamic get_intrinsicHeight_dyn();

		virtual ::String getAttribute( ::String name);

		virtual Void setAttribute( ::String name,::String value);

		virtual Void init( );

		Dynamic intrinsicRatio; /* REM */ 
		Dynamic intrinsicWidth; /* REM */ 
		Dynamic intrinsicHeight; /* REM */ 
		int width; /* REM */ 
		int height; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_EmbeddedElement */ 
