#ifndef INCLUDED_core_renderer_EmbeddedBoxRenderer
#define INCLUDED_core_renderer_EmbeddedBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/BoxRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,EmbeddedBoxRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class EmbeddedBoxRenderer_obj : public ::core::renderer::BoxRenderer_obj{
	public:
		typedef ::core::renderer::BoxRenderer_obj super;
		typedef EmbeddedBoxRenderer_obj OBJ_;
		EmbeddedBoxRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< EmbeddedBoxRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EmbeddedBoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("EmbeddedBoxRenderer"); }

		virtual Dynamic render( );
		Dynamic render_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_EmbeddedBoxRenderer */ 
