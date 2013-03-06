#ifndef INCLUDED_cocktail_core_html_HTMLBRElement
#define INCLUDED_cocktail_core_html_HTMLBRElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLBRElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLBRElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
		typedef HTMLBRElement_obj OBJ_;
		HTMLBRElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLBRElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLBRElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLBRElement"); }

		virtual bool isVoidElement( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLBRElement */ 
