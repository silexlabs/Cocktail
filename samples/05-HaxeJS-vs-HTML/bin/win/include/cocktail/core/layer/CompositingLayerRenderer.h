#ifndef INCLUDED_cocktail_core_layer_CompositingLayerRenderer
#define INCLUDED_cocktail_core_layer_CompositingLayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/LayerRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,layer,CompositingLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layer{


class CompositingLayerRenderer_obj : public ::cocktail::core::layer::LayerRenderer_obj{
	public:
		typedef ::cocktail::core::layer::LayerRenderer_obj super;
		typedef CompositingLayerRenderer_obj OBJ_;
		CompositingLayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< CompositingLayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CompositingLayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CompositingLayerRenderer"); }

		virtual bool isCompositingLayer( );

		virtual bool establishesNewGraphicsContext( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_CompositingLayerRenderer */ 
