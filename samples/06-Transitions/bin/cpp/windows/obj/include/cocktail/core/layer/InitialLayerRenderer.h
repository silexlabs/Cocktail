#ifndef INCLUDED_cocktail_core_layer_InitialLayerRenderer
#define INCLUDED_cocktail_core_layer_InitialLayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/layer/LayerRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,layer,InitialLayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace layer{


class InitialLayerRenderer_obj : public ::cocktail::core::layer::LayerRenderer_obj{
	public:
		typedef ::cocktail::core::layer::LayerRenderer_obj super;
		typedef InitialLayerRenderer_obj OBJ_;
		InitialLayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< InitialLayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InitialLayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InitialLayerRenderer"); }

		virtual bool treatVisibleOverflowAsAuto( );

		virtual bool hasCompositingLayerSibling( );

		virtual bool establishesNewStackingContext( );

		virtual bool establishesNewGraphicsContext( );

		virtual Void doDetachStackingContext( );

		virtual Void doAttachStackingContext( );

		virtual Void doDetachGraphicsContext( );

		virtual Void doAttachGraphicsContext( );

};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_InitialLayerRenderer */ 
