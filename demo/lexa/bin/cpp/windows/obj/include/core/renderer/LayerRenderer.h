#ifndef INCLUDED_core_renderer_LayerRenderer
#define INCLUDED_core_renderer_LayerRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,geom,Matrix)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,LayerRenderer)
namespace core{
namespace renderer{


class LayerRenderer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef LayerRenderer_obj OBJ_;
		LayerRenderer_obj();
		Void __construct(::core::renderer::ElementRenderer rootRenderer);

	public:
		static hx::ObjectPtr< LayerRenderer_obj > __new(::core::renderer::ElementRenderer rootRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~LayerRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("LayerRenderer"); }

		::core::renderer::ElementRenderer _rootRenderer; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual Dynamic renderChildrenBlockContainerBackground( );
		Dynamic renderChildrenBlockContainerBackground_dyn();

		virtual Array< ::core::renderer::ElementRenderer > getBlockContainerChildren( ::core::renderer::FlowBoxRenderer rootRenderer);
		Dynamic getBlockContainerChildren_dyn();

		virtual Dynamic renderChildLayer( );
		Dynamic renderChildLayer_dyn();

		virtual Array< ::core::renderer::LayerRenderer > getChildLayers( ::core::renderer::FlowBoxRenderer rootRenderer,::core::renderer::LayerRenderer referenceLayer);
		Dynamic getChildLayers_dyn();

		virtual Dynamic renderInFlowChildren( );
		Dynamic renderInFlowChildren_dyn();

		virtual Array< ::core::renderer::ElementRenderer > getInFlowChildren( ::core::renderer::FlowBoxRenderer rootRenderer);
		Dynamic getInFlowChildren_dyn();

		virtual Void setNativeMatrix( ::core::geom::Matrix matrix);
		Dynamic setNativeMatrix_dyn();

		virtual ::core::geom::Matrix getConcatenatedMatrix( ::core::geom::Matrix matrix);
		Dynamic getConcatenatedMatrix_dyn();

		virtual ::core::geom::Matrix getConcatenatedMatrix2( ::core::geom::Matrix matrix);
		Dynamic getConcatenatedMatrix2_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_LayerRenderer */ 
