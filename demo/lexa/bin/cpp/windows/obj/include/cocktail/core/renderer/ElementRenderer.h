#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#define INCLUDED_cocktail_core_renderer_ElementRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/dom/Node.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,LayerRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class ElementRenderer_obj : public ::cocktail::core::dom::Node_obj{
	public:
		typedef ::cocktail::core::dom::Node_obj super;
		typedef ElementRenderer_obj OBJ_;
		ElementRenderer_obj();
		Void __construct(::cocktail::port::flash_player::CoreStyle style);

	public:
		static hx::ObjectPtr< ElementRenderer_obj > __new(::cocktail::port::flash_player::CoreStyle style);
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
		::cocktail::port::flash_player::CoreStyle _coreStyle; /* REM */ 
		::cocktail::port::flash_player::CoreStyle coreStyle; /* REM */ 
		::cocktail::core::renderer::LayerRenderer _layerRenderer; /* REM */ 
		::cocktail::core::renderer::LayerRenderer layerRenderer; /* REM */ 
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

		virtual ::cocktail::core::renderer::LayerRenderer setLayerRenderer( ::cocktail::core::renderer::LayerRenderer value);
		Dynamic setLayerRenderer_dyn();

		virtual ::cocktail::core::renderer::LayerRenderer getLayerRenderer( );
		Dynamic getLayerRenderer_dyn();

		virtual ::cocktail::port::flash_player::CoreStyle getCoreStyle( );
		Dynamic getCoreStyle_dyn();

		virtual Dynamic getBounds( );
		Dynamic getBounds_dyn();

		virtual Dynamic setBounds( Dynamic value);
		Dynamic setBounds_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_ElementRenderer */ 
