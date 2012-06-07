#ifndef INCLUDED_core_renderer_BoxRenderer
#define INCLUDED_core_renderer_BoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <core/renderer/ElementRenderer.h>
HX_DECLARE_CLASS2(core,background,BackgroundManager)
HX_DECLARE_CLASS2(core,dom,Node)
HX_DECLARE_CLASS2(core,renderer,BoxRenderer)
HX_DECLARE_CLASS2(core,renderer,ElementRenderer)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(port,flash_player,Style)
namespace core{
namespace renderer{


class BoxRenderer_obj : public ::core::renderer::ElementRenderer_obj{
	public:
		typedef ::core::renderer::ElementRenderer_obj super;
		typedef BoxRenderer_obj OBJ_;
		BoxRenderer_obj();
		Void __construct(::port::flash_player::Style style);

	public:
		static hx::ObjectPtr< BoxRenderer_obj > __new(::port::flash_player::Style style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoxRenderer"); }

		::core::background::BackgroundManager _backgroundManager; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic renderBackground( );
		Dynamic renderBackground_dyn();

};

} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_core_renderer_BoxRenderer */ 
