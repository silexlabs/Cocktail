#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#define INCLUDED_cocktail_core_renderer_BlockBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/FlowBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,layer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,layer,ScrollableView)
HX_DECLARE_CLASS3(cocktail,core,layout,FloatVO)
HX_DECLARE_CLASS3(cocktail,core,layout,InlineFormattingVO)
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
HX_DECLARE_CLASS4(cocktail,core,layout,floats,FloatsManager)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,linebox,LineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,AnonymousBlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class BlockBoxRenderer_obj : public ::cocktail::core::renderer::FlowBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::FlowBoxRenderer_obj super;
		typedef BlockBoxRenderer_obj OBJ_;
		BlockBoxRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< BlockBoxRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlockBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlockBoxRenderer"); }

		virtual ::cocktail::core::renderer::BlockBoxRenderer getNearestBlockFormattingContextRoot( );
		Dynamic getNearestBlockFormattingContextRoot_dyn();

		virtual ::cocktail::core::geom::PointVO getBlockBoxesOffset( ::cocktail::core::renderer::BlockBoxRenderer target,::cocktail::core::renderer::BlockBoxRenderer source);
		Dynamic getBlockBoxesOffset_dyn();

		virtual bool establishesNewBlockFormattingContextOnlyBecauseOfOverflow( );
		Dynamic establishesNewBlockFormattingContextOnlyBecauseOfOverflow_dyn();

		virtual bool hasNonZeroHeightInlineBox( ::cocktail::core::renderer::ElementRenderer rootElementRenderer);
		Dynamic hasNonZeroHeightInlineBox_dyn();

		virtual ::cocktail::core::geom::RectangleVO getBackgroundAndBordersBounds( ::cocktail::core::geom::PointVO scrollOffset);

		virtual bool childrenInline( );

		virtual bool establishesNewBlockFormattingContext( );

		virtual bool createOwnLayer( );

		virtual bool hasZeroHeightChildren( );

		virtual bool collapseBottomMarginWithLastChildBottomMargin( );

		virtual bool collapseTopMarginWithFirstChildTopMargin( );

		virtual Void updateInlineChildrenBounds( ::cocktail::core::renderer::ElementRenderer elementRenderer);
		Dynamic updateInlineChildrenBounds_dyn();

		virtual ::cocktail::core::linebox::InlineBox doLayoutInlineChildrenAndFloats( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::InlineFormattingVO inlineFormattingData,::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic doLayoutInlineChildrenAndFloats_dyn();

		virtual Void layoutLineBox( ::cocktail::core::layout::InlineFormattingVO inlineFormattingData,::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layoutLineBox_dyn();

		virtual ::cocktail::core::linebox::LineBox createLineBox( ::cocktail::core::geom::PointVO lineBoxPosition,::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic createLineBox_dyn();

		virtual Void layoutInlineChildrenAndFloats( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layoutInlineChildrenAndFloats_dyn();

		virtual Void registerFloatedElement( ::cocktail::core::renderer::ElementRenderer floatedElement,::cocktail::core::geom::PointVO childPosition);
		Dynamic registerFloatedElement_dyn();

		virtual Void registerClearElement( ::cocktail::core::renderer::ElementRenderer clearElement);
		Dynamic registerClearElement_dyn();

		virtual Void layoutBlockChildrenAndFloats( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layoutBlockChildrenAndFloats_dyn();

		virtual bool isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight( );
		Dynamic isAutoWidthAbsolutelyPositionedWithNotAutoLeftAndRight_dyn();

		virtual bool isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom( );
		Dynamic isAutoHeightAbsolutelyPositionedWithNotAutoTopAndBottom_dyn();

		virtual Void applyContentHeightIfNeeded( );
		Dynamic applyContentHeightIfNeeded_dyn();

		virtual Void doGetFloatedElementsBounds( Array< ::cocktail::core::layout::FloatVO > floats,::cocktail::core::geom::RectangleVO floatedElementsBounds);
		Dynamic doGetFloatedElementsBounds_dyn();

		virtual Void getFloatedElementsBounds( );
		Dynamic getFloatedElementsBounds_dyn();

		virtual Void doGetBlockFormattingBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO blockFormattingBounds,Float xOffset,Float yOffset);
		Dynamic doGetBlockFormattingBounds_dyn();

		virtual Void getBlockFormattingBounds( );
		Dynamic getBlockFormattingBounds_dyn();

		virtual Void applyShrinkToFitIfNeeded( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic applyShrinkToFitIfNeeded_dyn();

		virtual Void updateFloatedAndClearElements( );
		Dynamic updateFloatedAndClearElements_dyn();

		virtual Void doLayoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic doLayoutChildren_dyn();

		virtual Void layoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState);

		virtual Void renderFloatedChildren( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderFloatedChildren_dyn();

		virtual Void renderBlockContainerChildren( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderBlockContainerChildren_dyn();

		virtual Void renderBlockReplacedChildren( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderBlockReplacedChildren_dyn();

		virtual Void renderLineBoxes( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderLineBoxes_dyn();

		virtual Void renderChildren( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);

		virtual ::cocktail::core::renderer::AnonymousBlockBoxRenderer createAnonymousBlock( ::cocktail::core::renderer::ElementRenderer child);
		Dynamic createAnonymousBlock_dyn();

		virtual Void makeChildrenNonInline( );
		Dynamic makeChildrenNonInline_dyn();

		virtual Void updateAnonymousBlock( );

		::cocktail::core::geom::PointVO _offsetFromBlockFormattingRoot; /* REM */ 
		bool _floatFound; /* REM */ 
		::cocktail::core::geom::RectangleVO _floatedElementsBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO _childBlockFormattingBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO _blockFormattingBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO _inlineBoxGlobalBounds; /* REM */ 
		::cocktail::core::geom::PointVO _lineBoxPosition; /* REM */ 
		::cocktail::core::geom::PointVO _childPosition; /* REM */ 
		::cocktail::core::layout::floats::FloatsManager floatsManager; /* REM */ 
		Array< ::cocktail::core::linebox::LineBox > lineBoxes; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_BlockBoxRenderer */ 
