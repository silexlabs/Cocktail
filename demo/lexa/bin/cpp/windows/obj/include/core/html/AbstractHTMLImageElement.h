#ifndef INCLUDED_core_html_AbstractHTMLImageElement
#define INCLUDED_core_html_AbstractHTMLImageElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/html/EmbeddedElement.h>
HX_DECLARE_CLASS2(core,dom,Element)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,event,Event)
HX_DECLARE_CLASS2(core,event,IEventTarget)
HX_DECLARE_CLASS2(core,html,AbstractHTMLElement)
HX_DECLARE_CLASS2(core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS2(core,html,EmbeddedElement)
HX_DECLARE_CLASS2(core,resource,AbstractImageLoader)
HX_DECLARE_CLASS2(core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS2(core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS2(port,flash_player,HTMLElement)
HX_DECLARE_CLASS2(port,flash_player,MediaLoader)
namespace core{
namespace html{


class AbstractHTMLImageElement_obj : public ::core::html::EmbeddedElement_obj{
	public:
		typedef ::core::html::EmbeddedElement_obj super;
		typedef AbstractHTMLImageElement_obj OBJ_;
		AbstractHTMLImageElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AbstractHTMLImageElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractHTMLImageElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractHTMLImageElement"); }

		Dynamic onLoad; /* REM */ 
	Dynamic &onLoad_dyn() { return onLoad;}
		Dynamic onError; /* REM */ 
	Dynamic &onError_dyn() { return onError;}
		Dynamic naturalWidth; /* REM */ 
		Dynamic naturalHeight; /* REM */ 
		::String _src; /* REM */ 
		::String src; /* REM */ 
		::core::resource::AbstractImageLoader _imageLoader; /* REM */ 
		virtual Void initEmbeddedAsset( );
		Dynamic initEmbeddedAsset_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual Void onLoadComplete( Dynamic image);
		Dynamic onLoadComplete_dyn();

		virtual Void onLoadError( ::String message);
		Dynamic onLoadError_dyn();

		virtual ::String get_src( );
		Dynamic get_src_dyn();

		virtual Dynamic get_naturalHeight( );
		Dynamic get_naturalHeight_dyn();

		virtual Dynamic get_naturalWidth( );
		Dynamic get_naturalWidth_dyn();

		static ::String HTML_IMAGE_TAG_NAME; /* REM */ 
};

} // end namespace core
} // end namespace html

#endif /* INCLUDED_core_html_AbstractHTMLImageElement */ 
