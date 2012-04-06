#ifndef INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer
#define INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,EmbeddedBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class EmbeddedBoxRenderer_obj : public ::cocktail::core::renderer::BoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BoxRenderer_obj super;
		typedef EmbeddedBoxRenderer_obj OBJ_;
		EmbeddedBoxRenderer_obj();
		Void __construct(::cocktail::port::flash_player::CoreStyle style);

	public:
		static hx::ObjectPtr< EmbeddedBoxRenderer_obj > __new(::cocktail::port::flash_player::CoreStyle style);
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

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_EmbeddedBoxRenderer */ 
