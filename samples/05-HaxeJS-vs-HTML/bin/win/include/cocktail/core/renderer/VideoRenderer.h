#ifndef INCLUDED_cocktail_core_renderer_VideoRenderer
#define INCLUDED_cocktail_core_renderer_VideoRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/ImageRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,EmbeddedElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLMediaElement)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLVideoElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,EmbeddedBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ImageRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,VideoRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class VideoRenderer_obj : public ::cocktail::core::renderer::ImageRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::ImageRenderer_obj super;
		typedef VideoRenderer_obj OBJ_;
		VideoRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement domNode);

	public:
		static hx::ObjectPtr< VideoRenderer_obj > __new(::cocktail::core::html::HTMLElement domNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VideoRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VideoRenderer"); }

		virtual Void renderPosterFrame( ::cocktail::core::html::HTMLVideoElement htmlVideoElement,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderPosterFrame_dyn();

		virtual Void renderVideo( ::cocktail::core::html::HTMLVideoElement htmlVideoElement,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderVideo_dyn();

		virtual Void renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void doCreateLayer( );

		virtual bool createOwnLayer( );

		::cocktail::core::geom::RectangleVO _videoBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO _posterBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_VideoRenderer */ 
