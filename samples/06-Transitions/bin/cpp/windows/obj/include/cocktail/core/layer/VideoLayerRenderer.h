#ifndef INCLUDED_cocktail_core_layer_VideoLayerRenderer
#define INCLUDED_cocktail_core_layer_VideoLayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/CompositingLayerRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,layer,CompositingLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,layer,VideoLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layer{


class VideoLayerRenderer_obj : public ::cocktail::core::layer::CompositingLayerRenderer_obj{
	public:
		typedef ::cocktail::core::layer::CompositingLayerRenderer_obj super;
		typedef VideoLayerRenderer_obj OBJ_;
		VideoLayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< VideoLayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~VideoLayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("VideoLayerRenderer"); }

		virtual Void doClear( Float x,Float y,Float width,Float height);

		virtual bool needsBitmap( );

		virtual Void detachGraphicsContext( );

		virtual Void attachGraphicsContext( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_VideoLayerRenderer */ 
