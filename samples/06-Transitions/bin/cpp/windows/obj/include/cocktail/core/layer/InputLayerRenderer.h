#ifndef INCLUDED_cocktail_core_layer_InputLayerRenderer
#define INCLUDED_cocktail_core_layer_InputLayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/CompositingLayerRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,layer,CompositingLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,InputLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layer{


class InputLayerRenderer_obj : public ::cocktail::core::layer::CompositingLayerRenderer_obj{
	public:
		typedef ::cocktail::core::layer::CompositingLayerRenderer_obj super;
		typedef InputLayerRenderer_obj OBJ_;
		InputLayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< InputLayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InputLayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InputLayerRenderer"); }

		virtual Void detachGraphicsContext( );

		virtual Void attachGraphicsContext( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_InputLayerRenderer */ 
