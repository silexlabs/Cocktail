#ifndef INCLUDED_core_renderer_ElementRenderer
#define INCLUDED_core_renderer_ElementRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/dom/Node.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,LayerRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class ElementRenderer_obj : public ::core::dom::Node_obj{
	public:
		typedef ::core::dom::Node_obj super;
		typedef ElementRenderer_obj OBJ_;
		ElementRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< ElementRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ElementRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("ElementRenderer"); }

		Dynamic _bounds; /* REM */ 
		Dynamic bounds; /* REM */ 
		::port::flash_player::Style _style; /* REM */ 
		::port::flash_player::Style style; /* REM */ 
		::core::renderer::LayerRenderer _layerRenderer; /* REM */ 
		::core::renderer::LayerRenderer layerRenderer; /* REM */ 
		virtual Dynamic render( );
		Dynamic render_dyn();

		virtual Dynamic renderBackground( );
		Dynamic renderBackground_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

		virtual bool canHaveChildren( );
		Dynamic canHaveChildren_dyn();

		virtual bool isFloat( );
		Dynamic isFloat_dyn();

		virtual bool isPositioned( );
		Dynamic isPositioned_dyn();

		virtual bool isEmbedded( );
		Dynamic isEmbedded_dyn();

		virtual bool isText( );
		Dynamic isText_dyn();

		virtual bool isSpace( );
		Dynamic isSpace_dyn();

		virtual bool isLineFeed( );
		Dynamic isLineFeed_dyn();

		virtual bool isTab( );
		Dynamic isTab_dyn();

		virtual bool isInitialContainer( );
		Dynamic isInitialContainer_dyn();

		virtual ::core::renderer::LayerRenderer setLayerRenderer( ::core::renderer::LayerRenderer value);
		Dynamic setLayerRenderer_dyn();

		virtual ::core::renderer::LayerRenderer getLayerRenderer( );
		Dynamic getLayerRenderer_dyn();

		virtual ::port::flash_player::Style getStyle( );
		Dynamic getStyle_dyn();

		virtual Dynamic getBounds( );
		Dynamic getBounds_dyn();

		virtual Dynamic setBounds( Dynamic value);
		Dynamic setBounds_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_ElementRenderer */ 
