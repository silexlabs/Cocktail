#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#define INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BoxRenderer.h>
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
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class EmbeddedBoxRenderer_obj : public ::cocktail::core::renderer::BoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BoxRenderer_obj super;
		typedef EmbeddedBoxRenderer_obj OBJ_;
		EmbeddedBoxRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< EmbeddedBoxRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedBoxRenderer"); }

		virtual Void renderEmbeddedAsset( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderEmbeddedAsset_dyn();

		virtual Void renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer */ 
