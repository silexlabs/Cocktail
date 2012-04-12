#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#define INCLUDED_cocktail_core_html_EmbeddedElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/port/flash_player/HTMLElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class EmbeddedElement_obj : public ::cocktail::port::flash_player::HTMLElement_obj{
	public:
		typedef ::cocktail::port::flash_player::HTMLElement_obj super;
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
		::String __ToString() const { return HX_CSTRING("EmbeddedElement"); }

		Dynamic _intrinsicHeight; /* REM */ 
		Dynamic intrinsicHeight; /* REM */ 
		Dynamic _intrinsicWidth; /* REM */ 
		Dynamic intrinsicWidth; /* REM */ 
		Dynamic _intrinsicRatio; /* REM */ 
		Dynamic intrinsicRatio; /* REM */ 
		int _height; /* REM */ 
		int height; /* REM */ 
		int _width; /* REM */ 
		int width; /* REM */ 
		Dynamic _embeddedAsset; /* REM */ 
		Dynamic embeddedAsset; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void initEmbeddedAsset( );
		Dynamic initEmbeddedAsset_dyn();

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		virtual ::cocktail::core::dom::Node appendChild( ::cocktail::core::dom::Node newChild);
		Dynamic appendChild_dyn();

		virtual ::cocktail::core::dom::Node removeChild( ::cocktail::core::dom::Node oldChild);
		Dynamic removeChild_dyn();

		virtual Dynamic get_embeddedAsset( );
		Dynamic get_embeddedAsset_dyn();

		virtual Dynamic get_intrinsicHeight( );
		Dynamic get_intrinsicHeight_dyn();

		virtual Dynamic get_intrinsicWidth( );
		Dynamic get_intrinsicWidth_dyn();

		virtual Dynamic get_intrinsicRatio( );
		Dynamic get_intrinsicRatio_dyn();

		virtual int set_width( int value);
		Dynamic set_width_dyn();

		virtual int get_width( );
		Dynamic get_width_dyn();

		virtual int set_height( int value);
		Dynamic set_height_dyn();

		virtual int get_height( );
		Dynamic get_height_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_EmbeddedElement */ 
