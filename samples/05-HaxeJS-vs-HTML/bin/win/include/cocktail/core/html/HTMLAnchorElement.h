#ifndef INCLUDED_cocktail_core_html_HTMLAnchorElement
#define INCLUDED_cocktail_core_html_HTMLAnchorElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,event,MouseEvent)
HX_DECLARE_CLASS3(cocktail,core,event,UIEvent)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLAnchorElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLAnchorElement_obj : public ::cocktail::core::html::HTMLElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLElement_obj super;
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
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLAnchorElement"); }

		virtual ::String get_target( );
		Dynamic get_target_dyn();

		virtual ::String set_target( ::String value);
		Dynamic set_target_dyn();

		virtual ::String get_href( );
		Dynamic get_href_dyn();

		virtual ::String set_href( ::String value);
		Dynamic set_href_dyn();

		virtual Void openDocument( );
		Dynamic openDocument_dyn();

		virtual bool isDefaultFocusable( );

		virtual ::String getAttribute( ::String name);

		virtual Void runPostClickActivationStep( ::cocktail::core::event::MouseEvent event);

		virtual bool hasActivationBehaviour( );

		::String target; /* REM */ 
		::String href; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLAnchorElement */ 
