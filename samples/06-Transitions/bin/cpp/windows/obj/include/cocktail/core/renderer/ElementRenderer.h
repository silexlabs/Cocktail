#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#define INCLUDED_cocktail_core_renderer_ElementRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/utils/FastNode.h>
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
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
HX_DECLARE_CLASS3(cocktail,core,layout,LayoutStateValue)
HX_DECLARE_CLASS3(cocktail,core,linebox,InlineBox)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InitialBlockRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace renderer{


class ElementRenderer_obj : public ::cocktail::core::utils::FastNode_obj{
	public:
		typedef ::cocktail::core::utils::FastNode_obj super;
		typedef ElementRenderer_obj OBJ_;
		ElementRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement domNode);

	public:
		static hx::ObjectPtr< ElementRenderer_obj > __new(::cocktail::core::html::HTMLElement domNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ElementRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ElementRenderer"); }

		virtual Float get_scrollHeight( );
		Dynamic get_scrollHeight_dyn();

		virtual Float get_scrollWidth( );
		Dynamic get_scrollWidth_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer get_lastNormalFlowChild( );
		Dynamic get_lastNormalFlowChild_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer get_firstNormalFlowChild( );
		Dynamic get_firstNormalFlowChild_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer get_nextNormalFlowSibling( );
		Dynamic get_nextNormalFlowSibling_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer get_previousNormalFlowSibling( );
		Dynamic get_previousNormalFlowSibling_dyn();

		virtual Float get_scrollTop( );
		Dynamic get_scrollTop_dyn();

		virtual Float set_scrollTop( Float value);
		Dynamic set_scrollTop_dyn();

		virtual Float get_scrollLeft( );
		Dynamic get_scrollLeft_dyn();

		virtual Float set_scrollLeft( Float value);
		Dynamic set_scrollLeft_dyn();

		virtual Void invalidateRendering( );
		Dynamic invalidateRendering_dyn();

		virtual Void invalidateStyle( int styleIndex);
		Dynamic invalidateStyle_dyn();

		virtual Void invalidate( );
		Dynamic invalidate_dyn();

		virtual Void doGetChildrenBounds( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::geom::RectangleVO bounds);
		Dynamic doGetChildrenBounds_dyn();

		virtual Void getInlineBoxesBounds( Array< ::cocktail::core::linebox::InlineBox > inLineBoxes,::cocktail::core::geom::RectangleVO bounds);
		Dynamic getInlineBoxesBounds_dyn();

		virtual ::cocktail::core::renderer::FlowBoxRenderer getFirstBlockContainer( );
		Dynamic getFirstBlockContainer_dyn();

		virtual ::cocktail::core::renderer::InitialBlockRenderer getInitialContainingBlock( );
		Dynamic getInitialContainingBlock_dyn();

		virtual ::cocktail::core::renderer::FlowBoxRenderer getFirstPositionedAncestor( );
		Dynamic getFirstPositionedAncestor_dyn();

		virtual ::cocktail::core::renderer::FlowBoxRenderer getContainingBlock( );
		Dynamic getContainingBlock_dyn();

		virtual ::cocktail::core::renderer::ElementRenderer getNextElementRendererWithOwnLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer);
		Dynamic getNextElementRendererWithOwnLayerRenderer_dyn();

		virtual ::cocktail::core::layer::LayerRenderer getNextLayerRenderer( ::cocktail::core::renderer::ElementRenderer rootElementRenderer,::cocktail::core::renderer::ElementRenderer referenceElementRenderer);
		Dynamic getNextLayerRenderer_dyn();

		virtual Void doCreateLayer( );
		Dynamic doCreateLayer_dyn();

		virtual Void createLayer( ::cocktail::core::layer::LayerRenderer parentLayer);
		Dynamic createLayer_dyn();

		virtual bool createOwnLayer( );
		Dynamic createOwnLayer_dyn();

		virtual bool isVisible( );
		Dynamic isVisible_dyn();

		virtual bool hasCSSTransform( );
		Dynamic hasCSSTransform_dyn();

		virtual bool isTransformed( );
		Dynamic isTransformed_dyn();

		virtual bool isAnonymousBlockBox( );
		Dynamic isAnonymousBlockBox_dyn();

		virtual bool childrenInline( );
		Dynamic childrenInline_dyn();

		virtual bool isTransparent( );
		Dynamic isTransparent_dyn();

		virtual bool isRelativePositioned( );
		Dynamic isRelativePositioned_dyn();

		virtual bool isInlineLevel( );
		Dynamic isInlineLevel_dyn();

		virtual bool isAbsolutelyPositioned( );
		Dynamic isAbsolutelyPositioned_dyn();

		virtual bool isPositioned( );
		Dynamic isPositioned_dyn();

		virtual bool isFloat( );
		Dynamic isFloat_dyn();

		virtual bool canHaveClearance( );
		Dynamic canHaveClearance_dyn();

		virtual bool isScrollBar( );
		Dynamic isScrollBar_dyn();

		virtual bool establishesNewBlockFormattingContext( );
		Dynamic establishesNewBlockFormattingContext_dyn();

		virtual Float getLeadedDescent( );
		Dynamic getLeadedDescent_dyn();

		virtual Float getLeadedAscent( );
		Dynamic getLeadedAscent_dyn();

		virtual Void unregisterWithContainingBlock( );
		Dynamic unregisterWithContainingBlock_dyn();

		virtual Void registerWithContaininingBlock( );
		Dynamic registerWithContaininingBlock_dyn();

		virtual Void detachLayer( );
		Dynamic detachLayer_dyn();

		virtual Void attachLayer( );
		Dynamic attachLayer_dyn();

		virtual Void removedFromRenderingTree( );
		Dynamic removedFromRenderingTree_dyn();

		virtual Void addedToRenderingTree( );
		Dynamic addedToRenderingTree_dyn();

		virtual Void updateInlineBoxes( );
		Dynamic updateInlineBoxes_dyn();

		virtual Void updateAnonymousBlock( );
		Dynamic updateAnonymousBlock_dyn();

		virtual Void detach( );
		Dynamic detach_dyn();

		virtual Void attach( );
		Dynamic attach_dyn();

		virtual Void updateLayerRenderer( );
		Dynamic updateLayerRenderer_dyn();

		virtual Void getAdjoiningBottomMargins( Array< Float > adjoiningMargins);
		Dynamic getAdjoiningBottomMargins_dyn();

		virtual Void getAdjoiningTopMargins( Array< Float > adjoiningMargins);
		Dynamic getAdjoiningTopMargins_dyn();

		virtual Float getCollapsedBottomMargin( );
		Dynamic getCollapsedBottomMargin_dyn();

		virtual Float getCollapsedTopMargin( );
		Dynamic getCollapsedTopMargin_dyn();

		virtual Void setAbsolutelyPositionedGlobalOrigins( ::cocktail::core::renderer::ElementRenderer elementRenderer,Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY);
		Dynamic setAbsolutelyPositionedGlobalOrigins_dyn();

		virtual Void setGlobalOrigins( Float addedX,Float addedY,Float addedPositionedX,Float addedPositionedY);
		Dynamic setGlobalOrigins_dyn();

		virtual Void layout( bool forceLayout,::cocktail::core::layout::LayoutStateValue layoutState);
		Dynamic layout_dyn();

		virtual Void invalidateLayerRenderer( );
		Dynamic invalidateLayerRenderer_dyn();

		virtual Void updateTextDecorations( bool inheritUnderline,bool inheritOverline,bool inheritLineThrough,bool inheritBlink);
		Dynamic updateTextDecorations_dyn();

		virtual Void updateText( );
		Dynamic updateText_dyn();

		virtual Void render( ::cocktail::core::graphics::GraphicsContext parentGraphicContext,::cocktail::core::geom::RectangleVO clipRect,::cocktail::core::geom::PointVO scrollOffset);
		Dynamic render_dyn();

		virtual Void updateHitTestingBounds( );
		Dynamic updateHitTestingBounds_dyn();

		virtual Void insertBefore( Dynamic _tmp_newChild,Dynamic _tmp_refChild);

		virtual Void removeChild( Dynamic _tmp_oldChild);

		virtual Void appendChild( Dynamic _tmp_newChild);

		virtual Void initCoreStyle( );
		Dynamic initCoreStyle_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		bool hasLineBoxes; /* REM */ 
		bool isText; /* REM */ 
		bool isBlockContainer; /* REM */ 
		bool isReplaced; /* REM */ 
		::cocktail::core::renderer::ElementRenderer lastNormalFlowChild; /* REM */ 
		::cocktail::core::renderer::ElementRenderer firstNormalFlowChild; /* REM */ 
		::cocktail::core::renderer::ElementRenderer nextNormalFlowSibling; /* REM */ 
		::cocktail::core::renderer::ElementRenderer previousNormalFlowSibling; /* REM */ 
		::cocktail::core::renderer::FlowBoxRenderer containingBlock; /* REM */ 
		Float scrollHeight; /* REM */ 
		Float scrollWidth; /* REM */ 
		Float scrollTop; /* REM */ 
		Float scrollLeft; /* REM */ 
		bool _wasAbsolutelyPositioned; /* REM */ 
		bool _needsLayerRendererUpdate; /* REM */ 
		bool _hasOwnLayer; /* REM */ 
		Array< ::cocktail::core::linebox::InlineBox > inlineBoxes; /* REM */ 
		::cocktail::core::layer::LayerRenderer layerRenderer; /* REM */ 
		::cocktail::core::css::CoreStyle coreStyle; /* REM */ 
		::cocktail::core::html::HTMLElement domNode; /* REM */ 
		::cocktail::core::geom::PointVO staticOrigin; /* REM */ 
		::cocktail::core::geom::RectangleVO hitTestingBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO globalBounds; /* REM */ 
		::cocktail::core::geom::RectangleVO bounds; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_ElementRenderer */ 
