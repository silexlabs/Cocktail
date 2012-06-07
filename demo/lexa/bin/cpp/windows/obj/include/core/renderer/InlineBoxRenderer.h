#ifndef INCLUDED_core_renderer_InlineBoxRenderer
#define INCLUDED_core_renderer_InlineBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/FlowBoxRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,InlineBoxRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class InlineBoxRenderer_obj : public ::core::renderer::FlowBoxRenderer_obj{
	public:
		typedef ::core::renderer::FlowBoxRenderer_obj super;
		typedef InlineBoxRenderer_obj OBJ_;
		InlineBoxRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< InlineBoxRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InlineBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InlineBoxRenderer"); }

		virtual Dynamic render( );
		Dynamic render_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_InlineBoxRenderer */ 
