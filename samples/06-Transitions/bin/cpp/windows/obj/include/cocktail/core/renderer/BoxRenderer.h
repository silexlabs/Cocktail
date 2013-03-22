#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#define INCLUDED_cocktail_core_renderer_BoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/InvalidatingElementRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class BoxRenderer_obj : public ::cocktail::core::renderer::InvalidatingElementRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::InvalidatingElementRenderer_obj super;
		typedef BoxRenderer_obj OBJ_;
		BoxRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement domNode);

	public:
		static hx::ObjectPtr< BoxRenderer_obj > __new(::cocktail::core::html::HTMLElement domNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoxRenderer"); }

		virtual ::cocktail::core::layout::ContainingBlockVO getWindowData( );
		Dynamic getWindowData_dyn();

		virtual ::cocktail::core::layout::ContainingBlockVO getContainerBlockData( );
		Dynamic getContainerBlockData_dyn();

		virtual ::cocktail::core::geom::RectangleVO getOutlineBounds( ::cocktail::core::geom::PointVO scrollOffset);
		Dynamic getOutlineBounds_dyn();

		virtual ::cocktail::core::geom::RectangleVO getBackgroundAndBordersBounds( ::cocktail::core::geom::PointVO scrollOffset);
		Dynamic getBackgroundAndBordersBounds_dyn();

		virtual bool isTransparent( );

		virtual bool isVisible( );

		virtual bool hasCSSTransform( );

		virtual bool isTransformed( );

		virtual bool createOwnLayer( );

		virtual bool isInlineLevel( );

		virtual bool isRelativePositioned( );

		virtual bool isAbsolutelyPositioned( );

		virtual bool isPositioned( );

		virtual bool canHaveClearance( );

		virtual bool isFloat( );

		virtual bool hasZeroHeightChildren( );
		Dynamic hasZeroHeightChildren_dyn();

		virtual bool collapseTopMarginWithBottomMargin( );
		Dynamic collapseTopMarginWithBottomMargin_dyn();

		virtual bool collapseBottomMarginWithLastChildBottomMargin( );
		Dynamic collapseBottomMarginWithLastChildBottomMargin_dyn();

		virtual bool collapseTopMarginWithFirstChildTopMargin( );
		Dynamic collapseTopMarginWithFirstChildTopMargin_dyn();

		virtual bool collapseBottomMarginWithNextSiblingTopMargin( );
		Dynamic collapseBottomMarginWithNextSiblingTopMargin_dyn();

		virtual bool collapseTopMarginWithPreviousSiblingBottomMargin( );
		Dynamic collapseTopMarginWithPreviousSiblingBottomMargin_dyn();

		virtual bool collapseBottomMarginWithParentBottomMargin( );
		Dynamic collapseBottomMarginWithParentBottomMargin_dyn();

		virtual bool collapseTopMarginWithParentTopMargin( );
		Dynamic collapseTopMarginWithParentTopMargin_dyn();

		virtual Float getCollapsedMargin( Array< Float > adjoiningMargins);
		Dynamic getCollapsedMargin_dyn();

		virtual Void getAdjoiningBottomMargins( Array< Float > adjoiningMargins);

		virtual Float getCollapsedBottomMargin( );

		virtual Void getAdjoiningTopMargins( Array< Float > adjoiningMargins);

		virtual Float getCollapsedTopMargin( );

		virtual Void computeBoxModelStyles( ::cocktail::core::layout::ContainingBlockVO containingBlockDimensions);
		Dynamic computeBoxModelStyles_dyn();

		virtual Float getHeightOfFirstParentWithNotAutoHeight( );
		Dynamic getHeightOfFirstParentWithNotAutoHeight_dyn();

		virtual Void updateUsedTextIndent( Float containingBlockWidth);
		Dynamic updateUsedTextIndent_dyn();

		virtual Void layoutSelfIfNeeded( bool forceLayout);
		Dynamic layoutSelfIfNeeded_dyn();

		virtual Void layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState);

		virtual Void renderChildren( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderChildren_dyn();

		virtual Void renderOutline( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderOutline_dyn();

		virtual Void renderBorder( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderBorder_dyn();

		virtual Void renderBackground( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderBackground_dyn();

		virtual Void renderSelf( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderSelf_dyn();

		virtual Void render( ::cocktail::core::graphics::GraphicsContext parentGraphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual Void updateInlineBoxes( );

		::cocktail::core::geom::RectangleVO _backgroundAndBorderBounds; /* REM */ 
		::cocktail::core::layout::ContainingBlockVO _windowData; /* REM */ 
		::cocktail::core::layout::ContainingBlockVO _containerBlockData; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _intersectBounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_BoxRenderer */ 
