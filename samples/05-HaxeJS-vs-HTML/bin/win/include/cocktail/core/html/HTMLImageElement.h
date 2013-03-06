#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#define INCLUDED_cocktail_core_html_HTMLImageElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
namespace cocktail{
namespace core{
namespace html{


class HTMLImageElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
		typedef HTMLImageElement_obj OBJ_;
		HTMLImageElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLImageElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLImageElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLImageElement"); }

		virtual int get_naturalWidth( );
		Dynamic get_naturalWidth_dyn();

		virtual int get_naturalHeight( );
		Dynamic get_naturalHeight_dyn();

		virtual ::String get_src( );
		Dynamic get_src_dyn();

		virtual Void onLoadError( );
		Dynamic onLoadError_dyn();

		virtual Void onLoadComplete( ::cocktail::core::resource::AbstractResource resource);
		Dynamic onLoadComplete_dyn();

		virtual Void removeListeners( ::cocktail::core::event::EventTarget resource);
		Dynamic removeListeners_dyn();

		virtual Void onResourceLoadError( ::cocktail::core::event::Event e);
		Dynamic onResourceLoadError_dyn();

		virtual Void onResourceLoaded( ::cocktail::core::event::Event e);
		Dynamic onResourceLoaded_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual bool isVoidElement( );

		virtual Void createElementRenderer( );

		virtual Void setAttribute( ::String name,::String value);

		Dynamic _resourceLoadError; /* REM */ 
		Dynamic &_resourceLoadError_dyn() { return _resourceLoadError;}
		Dynamic _resourceLoadedCallback; /* REM */ 
		Dynamic &_resourceLoadedCallback_dyn() { return _resourceLoadedCallback;}
		int naturalHeight; /* REM */ 
		int naturalWidth; /* REM */ 
		::String src; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLImageElement */ 
