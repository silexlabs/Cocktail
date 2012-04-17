#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#define INCLUDED_cocktail_core_renderer_LayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,LayerRenderer)
namespace cocktail{
namespace core{
namespace renderer{


class LayerRenderer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LayerRenderer_obj OBJ_;
		LayerRenderer_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootRenderer);

	public:
		static hx::ObjectPtr< LayerRenderer_obj > __new(::cocktail::core::renderer::ElementRenderer rootRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LayerRenderer"); }

		::cocktail::core::renderer::ElementRenderer _rootRenderer; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual Dynamic renderChildrenBlockContainerBackground( );
		Dynamic renderChildrenBlockContainerBackground_dyn();

		virtual Array< ::cocktail::core::renderer::ElementRenderer > getBlockContainerChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer);
		Dynamic getBlockContainerChildren_dyn();

		virtual Dynamic renderChildLayer( );
		Dynamic renderChildLayer_dyn();

		virtual Array< ::cocktail::core::renderer::LayerRenderer > getChildLayers( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer,::cocktail::core::renderer::LayerRenderer referenceLayer);
		Dynamic getChildLayers_dyn();

		virtual Dynamic renderInFlowChildren( );
		Dynamic renderInFlowChildren_dyn();

		virtual Array< ::cocktail::core::renderer::ElementRenderer > getInFlowChildren( ::cocktail::core::renderer::FlowBoxRenderer rootRenderer);
		Dynamic getInFlowChildren_dyn();

		virtual Void setNativeMatrix( ::cocktail::core::geom::Matrix matrix);
		Dynamic setNativeMatrix_dyn();

		virtual ::cocktail::core::geom::Matrix getConcatenatedMatrix( ::cocktail::core::geom::Matrix matrix);
		Dynamic getConcatenatedMatrix_dyn();

		virtual ::cocktail::core::geom::Matrix getConcatenatedMatrix2( ::cocktail::core::geom::Matrix matrix);
		Dynamic getConcatenatedMatrix2_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_LayerRenderer */ 
