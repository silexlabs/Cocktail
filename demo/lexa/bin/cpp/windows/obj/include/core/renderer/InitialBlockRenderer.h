#ifndef INCLUDED_core_renderer_InitialBlockRenderer
#define INCLUDED_core_renderer_InitialBlockRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/BlockBoxRenderer.h>
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS2(core,renderer,InitialBlockRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class InitialBlockRenderer_obj : public ::core::renderer::BlockBoxRenderer_obj{
	public:
		typedef ::core::renderer::BlockBoxRenderer_obj super;
		typedef InitialBlockRenderer_obj OBJ_;
		InitialBlockRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< InitialBlockRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~InitialBlockRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("InitialBlockRenderer"); }

		virtual bool isInitialContainer( );
		Dynamic isInitialContainer_dyn();

		virtual Void init( );
		Dynamic init_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_InitialBlockRenderer */ 
