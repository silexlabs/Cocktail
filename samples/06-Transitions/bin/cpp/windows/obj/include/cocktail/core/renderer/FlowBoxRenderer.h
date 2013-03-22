#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#define INCLUDED_cocktail_core_renderer_FlowBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BoxRenderer.h>
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
HX_DECLARE_CLASS3(cocktail,core,layout,ContainingBlockVO)
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class FlowBoxRenderer_obj : public ::cocktail::core::renderer::BoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BoxRenderer_obj super;
		typedef FlowBoxRenderer_obj OBJ_;
		FlowBoxRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement node);

	public:
		static hx::ObjectPtr< FlowBoxRenderer_obj > __new(::cocktail::core::html::HTMLElement node);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlowBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlowBoxRenderer"); }

		virtual ::cocktail::core::geom::PointVO getPositionAfterInlineBox( ::cocktail::core::linebox::InlineBox inlineBox,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::PointVO staticOrigin);
		Dynamic getPositionAfterInlineBox_dyn();

		virtual ::cocktail::core::geom::PointVO getStaticPosition( ::cocktail::core::renderer::ElementRenderer elementRenderer);
		Dynamic getStaticPosition_dyn();

		virtual Float getBottomOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float containingHTMLElementHeight,bool isAbsolutelyPositioned);
		Dynamic getBottomOffset_dyn();

		virtual Float getTopOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,bool isAbsolutelyPositioned);
		Dynamic getTopOffset_dyn();

		virtual Float getRightOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float containingHTMLElementWidth,bool isAbsolutelyPositioned);
		Dynamic getRightOffset_dyn();

		virtual Float getLeftOffset( ::cocktail::core::renderer::ElementRenderer elementRenderer,bool isAbsolutelyPositioned);
		Dynamic getLeftOffset_dyn();

		virtual Void doLayoutPositionedChild( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::ContainingBlockVO containingBlockData,bool isAbsolutelyPositioned);
		Dynamic doLayoutPositionedChild_dyn();

		virtual Void layoutPositionedChild( ::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::layout::ContainingBlockVO firstPositionedAncestorData,::cocktail::core::layout::ContainingBlockVO viewportData);
		Dynamic layoutPositionedChild_dyn();

		virtual Void layoutAbsolutelyPositionedChildren( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layoutAbsolutelyPositionedChildren_dyn();

		virtual Void layoutChildren( ::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layoutChildren_dyn();

		virtual Void layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState);

		virtual Void removeAbsolutelyPositionedChild( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic removeAbsolutelyPositionedChild_dyn();

		virtual Void addAbsolutelyPositionedChildren( ::cocktail::core::renderer::ElementRenderer element);
		Dynamic addAbsolutelyPositionedChildren_dyn();

		virtual Void renderInlineChildren( ::cocktail::core::renderer::ElementRenderer rootRenderer,::cocktail::core::layer::LayerRenderer referenceLayer,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic renderInlineChildren_dyn();

		::cocktail::core::geom::PointVO _childStaticOrigin; /* REM */ 
		Array< ::cocktail::core::renderer::ElementRenderer > _absolutelyPositionedChildren; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_FlowBoxRenderer */ 
