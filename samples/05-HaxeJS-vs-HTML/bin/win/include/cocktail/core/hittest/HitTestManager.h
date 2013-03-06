#ifndef INCLUDED_cocktail_core_hittest_HitTestManager
#define INCLUDED_cocktail_core_hittest_HitTestManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,hittest,HitTestManager)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,stacking,StackingContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace hittest{


class HitTestManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HitTestManager_obj OBJ_;
		HitTestManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< HitTestManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HitTestManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HitTestManager"); }

		virtual bool isWithinBounds( ::cocktail::core::geom::PointVO point,::cocktail::core::geom::RectangleVO bounds);
		Dynamic isWithinBounds_dyn();

		virtual Void hitTestElementRenderer( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::PointVO point);
		Dynamic hitTestElementRenderer_dyn();

		virtual Void getElementRenderersAtPointInLayer( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::layer::LayerRenderer layer,::cocktail::core::renderer::ElementRenderer renderer,::cocktail::core::geom::PointVO point);
		Dynamic getElementRenderersAtPointInLayer_dyn();

		virtual Void getElementRenderersAtPointInLayers( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::layer::LayerRenderer layer,::cocktail::core::geom::PointVO point);
		Dynamic getElementRenderersAtPointInLayers_dyn();

		virtual Void getElementRenderersAtPointInStackingContext( Array< ::cocktail::core::renderer::ElementRenderer > elementRenderersAtPoint,::cocktail::core::stacking::StackingContext stackingContext,::cocktail::core::geom::PointVO point);
		Dynamic getElementRenderersAtPointInStackingContext_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer getTopMostElementRendererAtPoint( ::cocktail::core::stacking::StackingContext stackingContext,Float x,Float y);
		Dynamic getTopMostElementRendererAtPoint_dyn();

		::cocktail::core::geom::PointVO _targetPoint; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > _elementRenderersAtPoint; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace hittest

#endif /* INCLUDED_cocktail_core_hittest_HitTestManager */ 
