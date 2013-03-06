#ifndef INCLUDED_cocktail_core_stacking_StackingContext
#define INCLUDED_cocktail_core_stacking_StackingContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/FastNode.h>
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,stacking,StackingContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace stacking{


class StackingContext_obj : public ::cocktail::core::utils::FastNode_obj{
	public:
		typedef ::cocktail::core::utils::FastNode_obj super;
		typedef StackingContext_obj OBJ_;
		StackingContext_obj();
		Void __construct(::cocktail::core::layer::LayerRenderer layerRenderer);

	public:
		static hx::ObjectPtr< StackingContext_obj > __new(::cocktail::core::layer::LayerRenderer layerRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StackingContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StackingContext"); }

		virtual Void renderChildrenInSameStackingContext( ::cocktail::core::layer::LayerRenderer rootLayer,::cocktail::core::geom::RectangleVO dirtyRect);
		Dynamic renderChildrenInSameStackingContext_dyn();

		virtual Void render( ::cocktail::core::geom::RectangleVO dirtyRect);
		Dynamic render_dyn();

		::cocktail::core::layer::LayerRenderer layerRenderer; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace stacking

#endif /* INCLUDED_cocktail_core_stacking_StackingContext */ 
