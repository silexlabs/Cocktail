#ifndef INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer
#define INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/ElementRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Element)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,event,EventCallback)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,html,HTMLElement)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InvalidatingElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
namespace cocktail{
namespace core{
namespace renderer{


class InvalidatingElementRenderer_obj : public ::cocktail::core::renderer::ElementRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::ElementRenderer_obj super;
		typedef InvalidatingElementRenderer_obj OBJ_;
		InvalidatingElementRenderer_obj();
		Void __construct(::cocktail::core::html::HTMLElement domNode);

	public:
		static hx::ObjectPtr< InvalidatingElementRenderer_obj > __new(::cocktail::core::html::HTMLElement domNode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InvalidatingElementRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InvalidatingElementRenderer"); }

		virtual Void invalidateText( );
		Dynamic invalidateText_dyn();

		virtual Void invalidateLayoutAndRendering( );
		Dynamic invalidateLayoutAndRendering_dyn();

		virtual Void invalidateLayout( );
		Dynamic invalidateLayout_dyn();

		virtual Void invalidatedPositionedChildStyle( int styleIndex);
		Dynamic invalidatedPositionedChildStyle_dyn();

		virtual Void invalidatedChildStyle( int styleIndex);
		Dynamic invalidatedChildStyle_dyn();

		virtual Void invalidatedStyle( int styleIndex);
		Dynamic invalidatedStyle_dyn();

		virtual Void invalidateContainingBlock( int styleIndex);
		Dynamic invalidateContainingBlock_dyn();

		virtual Void positionedChildInvalidated( );
		Dynamic positionedChildInvalidated_dyn();

		virtual Void childInvalidated( );
		Dynamic childInvalidated_dyn();

		virtual Void invalidateStyle( int styleIndex);

		virtual Void invalidateRendering( );

		virtual Void invalidate( );

		virtual Void addedToRenderingTree( );

		bool _positionedChildrenNeedLayout; /* REM */ 
		bool _childrenNeedLayout; /* REM */ 
		bool _needsLayout; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_InvalidatingElementRenderer */ 
