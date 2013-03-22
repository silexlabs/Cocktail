#ifndef INCLUDED_cocktail_core_renderer_ImageRenderer
#define INCLUDED_cocktail_core_renderer_ImageRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/EmbeddedBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,EmbeddedBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ImageRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
namespace cocktail{
namespace core{
namespace renderer{


class ImageRenderer_obj : public ::cocktail::core::renderer::EmbeddedBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::EmbeddedBoxRenderer_obj super;
		typedef ImageRenderer_obj OBJ_;
		ImageRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement domNode);

	public:
		static hx::ObjectPtr< ImageRenderer_obj > __new(::cocktail::core::html::HTMLElement domNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ImageRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ImageRenderer"); }

		virtual Void paintResource( ::cocktail::core::graphics::GraphicsContext graphicContext,::neash::display::BitmapData nativeBitmapData,::cocktail::core::geom::RectangleVO bounds,Float intrinsicWidth,Float intrinsicHeight,::cocktail::core::geom::RectangleVO clipRect);
		Dynamic paintResource_dyn();

		virtual Void renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		::cocktail::core::geom::PointVO _destinationPoint; /* REM */ 
		::cocktail::core::geom::RectangleVO _paintBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_ImageRenderer */ 
