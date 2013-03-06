#ifndef INCLUDED_cocktail_core_html_HTMLAudioElement
#define INCLUDED_cocktail_core_html_HTMLAudioElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLMediaElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLAudioElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLMediaElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLAudioElement_obj : public ::cocktail::core::html::HTMLMediaElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLMediaElement_obj super;
		typedef HTMLAudioElement_obj OBJ_;
		HTMLAudioElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLAudioElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLAudioElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLAudioElement"); }

		virtual Void createElementRenderer( );

		virtual Void initNativeMedia( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLAudioElement */ 
