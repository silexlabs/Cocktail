#ifndef INCLUDED_cocktail_core_html_AbstractHTMLImageElement
#define INCLUDED_cocktail_core_html_AbstractHTMLImageElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,Event)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLImageElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractImageLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MediaLoader)
namespace cocktail{
namespace core{
namespace html{


class AbstractHTMLImageElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
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
		int naturalWidth; /* REM */ 
		int naturalHeight; /* REM */ 
		::String src; /* REM */ 
		::cocktail::core::resource::AbstractImageLoader _imageLoader; /* REM */ 
		virtual Void initEmbeddedAsset( );
		Dynamic initEmbeddedAsset_dyn();

		virtual Void setAttribute( ::String name,::String value);
		Dynamic setAttribute_dyn();

		virtual ::String set_src( ::String value);
		Dynamic set_src_dyn();

		virtual Void onLoadComplete( Dynamic image);
		Dynamic onLoadComplete_dyn();

		virtual Void onLoadError( ::String message);
		Dynamic onLoadError_dyn();

		virtual ::String get_src( );
		Dynamic get_src_dyn();

		virtual int get_naturalHeight( );
		Dynamic get_naturalHeight_dyn();

		virtual int get_naturalWidth( );
		Dynamic get_naturalWidth_dyn();

		static ::String HTML_IMAGE_TAG_NAME; /* REM */ 
		static ::String HTML_IMAGE_SRC_ATTRIBUTE; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_AbstractHTMLImageElement */ 
