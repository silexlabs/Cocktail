#ifndef INCLUDED_cocktail_core_layer_PluginLayerRenderer
#define INCLUDED_cocktail_core_layer_PluginLayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/CompositingLayerRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,layer,CompositingLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,PluginLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layer{


class PluginLayerRenderer_obj : public ::cocktail::core::layer::CompositingLayerRenderer_obj{
	public:
		typedef ::cocktail::core::layer::CompositingLayerRenderer_obj super;
		typedef PluginLayerRenderer_obj OBJ_;
		PluginLayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< PluginLayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PluginLayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PluginLayerRenderer"); }

		virtual Void doClear( Float x,Float y,Float width,Float height);

		virtual bool needsBitmap( );

		virtual bool isCompositingLayer( );

		virtual Void detachGraphicsContext( );

		virtual Void attachGraphicsContext( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_PluginLayerRenderer */ 
