#ifndef INCLUDED_cocktail_core_renderer_InlineBoxRenderer
#define INCLUDED_cocktail_core_renderer_InlineBoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/FlowBoxRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,FlowBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,InlineBoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class InlineBoxRenderer_obj : public ::cocktail::core::renderer::FlowBoxRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::FlowBoxRenderer_obj super;
		typedef InlineBoxRenderer_obj OBJ_;
		InlineBoxRenderer_obj();
		Void __construct(::cocktail::core::style::CoreStyle style);

	public:
		static hx::ObjectPtr< InlineBoxRenderer_obj > __new(::cocktail::core::style::CoreStyle style);
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

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_InlineBoxRenderer */ 
