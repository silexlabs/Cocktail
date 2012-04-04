#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#define INCLUDED_cocktail_core_renderer_FlowBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class FlowBoxRenderer_obj : public ::cocktail::core::renderer::BoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BoxRenderer_obj super;
		typedef FlowBoxRenderer_obj OBJ_;
		FlowBoxRenderer_obj();
		Void __construct(::cocktail::port::flash_player::CoreStyle style);

	public:
		static hx::ObjectPtr< FlowBoxRenderer_obj > __new(::cocktail::port::flash_player::CoreStyle style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FlowBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("FlowBoxRenderer"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual bool establishesNewFormattingContext( );
		Dynamic establishesNewFormattingContext_dyn();

		virtual bool isEmbedded( );
		Dynamic isEmbedded_dyn();

		virtual bool canHaveChildren( );
		Dynamic canHaveChildren_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_FlowBoxRenderer */ 
