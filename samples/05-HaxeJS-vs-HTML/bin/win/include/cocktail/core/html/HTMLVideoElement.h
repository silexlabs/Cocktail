#ifndef INCLUDED_cocktail_core_html_HTMLVideoElement
#define INCLUDED_cocktail_core_html_HTMLVideoElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/HTMLMediaElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLMediaElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLVideoElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLVideoElement_obj : public ::cocktail::core::html::HTMLMediaElement_obj{
	public:
		typedef ::cocktail::core::html::HTMLMediaElement_obj super;
		typedef HTMLVideoElement_obj OBJ_;
		HTMLVideoElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLVideoElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLVideoElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLVideoElement"); }

		virtual int get_videoHeight( );
		Dynamic get_videoHeight_dyn();

		virtual int get_videoWidth( );
		Dynamic get_videoWidth_dyn();

		virtual ::String get_poster( );
		Dynamic get_poster_dyn();

		virtual ::String set_poster( ::String value);
		Dynamic set_poster_dyn();

		virtual Void removeListeners( );
		Dynamic removeListeners_dyn();

		virtual Void onPosterLoadError( ::cocktail::core::event::Event e);
		Dynamic onPosterLoadError_dyn();

		virtual Void onPosterLoadComplete( ::cocktail::core::event::Event e);
		Dynamic onPosterLoadComplete_dyn();

		virtual bool shouldRenderPosterFrame( );
		Dynamic shouldRenderPosterFrame_dyn();

		virtual Void createElementRenderer( );

		virtual Void setAttribute( ::String name,::String value);

		virtual Void initPosterFrame( );
		Dynamic initPosterFrame_dyn();

		virtual Void initNativeMedia( );

		int videoHeight; /* REM */ 
		int videoWidth; /* REM */ 
		Dynamic _onPosterLoadError; /* REM */ 
		Dynamic &_onPosterLoadError_dyn() { return _onPosterLoadError;}
		Dynamic _onPosterLoadComplete; /* REM */ 
		Dynamic &_onPosterLoadComplete_dyn() { return _onPosterLoadComplete;}
		Dynamic posterFrameEmbeddedAsset; /* REM */ 
		::cocktail::core::html::HTMLImageElement _posterImage; /* REM */ 
		::String poster; /* REM */ 
		static int HTML_VIDEO_DEFAULT_WIDTH; /* REM */ 
		static int HTML_VIDEO_DEFAULT_HEIGHT; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLVideoElement */ 
