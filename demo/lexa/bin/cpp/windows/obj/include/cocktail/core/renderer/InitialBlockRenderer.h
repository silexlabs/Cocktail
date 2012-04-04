#ifndef INCLUDED_cocktail_core_renderer_InitialBlockRenderer
#define INCLUDED_cocktail_core_renderer_InitialBlockRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/BlockBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BlockBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InitialBlockRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,AbstractCoreStyle)
HX_DECLARE_CLASS3(cocktail,port,flash_player,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class InitialBlockRenderer_obj : public ::cocktail::core::renderer::BlockBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::BlockBoxRenderer_obj super;
		typedef InitialBlockRenderer_obj OBJ_;
		InitialBlockRenderer_obj();
		Void __construct(::cocktail::port::flash_player::CoreStyle style);

	public:
		static hx::ObjectPtr< InitialBlockRenderer_obj > __new(::cocktail::port::flash_player::CoreStyle style);
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

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_InitialBlockRenderer */ 
