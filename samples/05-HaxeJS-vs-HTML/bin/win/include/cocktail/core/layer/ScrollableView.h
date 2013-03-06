#ifndef INCLUDED_cocktail_core_layer_ScrollableView
#define INCLUDED_cocktail_core_layer_ScrollableView

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/FastNode.h>
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace layer{


class ScrollableView_obj : public ::cocktail::core::utils::FastNode_obj{
	public:
		typedef ::cocktail::core::utils::FastNode_obj super;
		typedef ScrollableView_obj OBJ_;
		ScrollableView_obj();
		Void __construct(::cocktail::core::renderer::ElementRenderer rootElementRenderer);

	public:
		static hx::ObjectPtr< ScrollableView_obj > __new(::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ScrollableView_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ScrollableView"); }

		virtual bool treatVisibleOverflowAsAuto( );
		Dynamic treatVisibleOverflowAsAuto_dyn();

		virtual bool isYAxisClipped( );
		Dynamic isYAxisClipped_dyn();

		virtual bool isXAxisClipped( );
		Dynamic isXAxisClipped_dyn();

		virtual bool isContainingBlockChildren( Dynamic layer);
		Dynamic isContainingBlockChildren_dyn();

		virtual Void scrollChanged( );
		Dynamic scrollChanged_dyn();

		virtual Float set_scrollTop( Float value);
		Dynamic set_scrollTop_dyn();

		virtual Float set_scrollLeft( Float value);
		Dynamic set_scrollLeft_dyn();

		virtual Void doGetScrollableBounds( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO scrollableBounds,Dynamic referenceLayer,bool getHorizontalBounds,bool getVerticalBounds);
		Dynamic doGetScrollableBounds_dyn();

		virtual Void getScrollableBounds( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO scrollableBounds);
		Dynamic getScrollableBounds_dyn();

		virtual ::cocktail::core::geom::RectangleVO getScrollableBoundsIfNeeded( Dynamic layer);
		Dynamic getScrollableBoundsIfNeeded_dyn();

		virtual Void updateScrollableBounds( );
		Dynamic updateScrollableBounds_dyn();

		virtual Void doGetElementRenderersBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds);
		Dynamic doGetElementRenderersBounds_dyn();

		virtual Void getElementRenderersBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds);
		Dynamic getElementRenderersBounds_dyn();

		virtual Void updateClippedBounds( );
		Dynamic updateClippedBounds_dyn();

		virtual Void updateBounds( );
		Dynamic updateBounds_dyn();

		virtual Void addScrollOffsetToChildren( Dynamic rootLayerRenderer,Float scrollLeft,Float scrollTop,Dynamic referenceLayer);
		Dynamic addScrollOffsetToChildren_dyn();

		virtual Void addScrollOffsetIfNeeded( Dynamic layer,Float scrollLeft,Float scrollTop);
		Dynamic addScrollOffsetIfNeeded_dyn();

		virtual Void updateScrollOffset( );
		Dynamic updateScrollOffset_dyn();

		virtual Void resetScrollOffset( );
		Dynamic resetScrollOffset_dyn();

		virtual bool clipIfNeeded( ::cocktail::core::geom::RectangleVO parentClipRect,Dynamic layer);
		Dynamic clipIfNeeded_dyn();

		virtual Void clipChildren( Dynamic rootLayerRenderer,::cocktail::core::geom::RectangleVO clipRect,Dynamic referenceLayer);
		Dynamic clipChildren_dyn();

		virtual Void updateClipRect( );
		Dynamic updateClipRect_dyn();

		virtual Void resetClipRect( Float x,Float y,Float width,Float height);
		Dynamic resetClipRect_dyn();

		Float scrollTop; /* REM */ 
		Float scrollLeft; /* REM */ 
		::cocktail::core::geom::RectangleVO clipRect; /* REM */ 
		::cocktail::core::geom::RectangleVO scrollableBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO _clippedBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO bounds; /* REM */ 
		Float _previousScrollOffsetY; /* REM */ 
		Float _previousScrollOffsetX; /* REM */ 
		::cocktail::core::geom::PointVO scrollOffset; /* REM */ 
		::cocktail::core::geom::PointVO _ancestorsScrollOffset; /* REM */ 
		::cocktail::core::renderer::ElementRenderer rootElementRenderer; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace layer

#endif /* INCLUDED_cocktail_core_layer_ScrollableView */ 
