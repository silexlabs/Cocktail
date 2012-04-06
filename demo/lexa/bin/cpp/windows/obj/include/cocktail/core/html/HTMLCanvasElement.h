#ifndef INCLUDED_cocktail_core_html_HTMLCanvasElement
#define INCLUDED_cocktail_core_html_HTMLCanvasElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/html/EmbeddedElement.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS3(cocktail,core,event,IEventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,AbstractHTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLCanvasElement)
HX_DECLARE_CLASS3(cocktail,port,flash_player,DrawingManager)
HX_DECLARE_CLASS3(cocktail,port,flash_player,HTMLElement)
namespace cocktail{
namespace core{
namespace html{


class HTMLCanvasElement_obj : public ::cocktail::core::html::EmbeddedElement_obj{
	public:
		typedef ::cocktail::core::html::EmbeddedElement_obj super;
		typedef HTMLCanvasElement_obj OBJ_;
		HTMLCanvasElement_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HTMLCanvasElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HTMLCanvasElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("HTMLCanvasElement"); }

		::cocktail::port::flash_player::DrawingManager _drawingManager; /* REM */ 
		virtual Void initEmbeddedAsset( );
		Dynamic initEmbeddedAsset_dyn();

		virtual ::cocktail::port::flash_player::DrawingManager getContext( ::String contextID);
		Dynamic getContext_dyn();

		virtual int set_width( int value);
		Dynamic set_width_dyn();

		virtual int set_height( int value);
		Dynamic set_height_dyn();

		static int CANVAS_INTRINSIC_HEIGHT; /* REM */ 
		static int CANVAS_INTRINSIC_WIDTH; /* REM */ 
		static ::String HTML_CANVAS_TAG_NAME; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace html

#endif /* INCLUDED_cocktail_core_html_HTMLCanvasElement */ 
