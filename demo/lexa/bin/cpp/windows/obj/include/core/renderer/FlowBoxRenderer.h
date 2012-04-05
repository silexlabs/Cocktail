#ifndef INCLUDED_core_renderer_FlowBoxRenderer
#define INCLUDED_core_renderer_FlowBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/BoxRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class FlowBoxRenderer_obj : public ::core::renderer::BoxRenderer_obj{
	public:
		typedef ::core::renderer::BoxRenderer_obj super;
		typedef FlowBoxRenderer_obj OBJ_;
		FlowBoxRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< FlowBoxRenderer_obj > __new(::port::flash_player::Style style);
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

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_FlowBoxRenderer */ 
