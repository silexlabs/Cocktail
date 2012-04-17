#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#define INCLUDED_cocktail_core_renderer_BoxRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/renderer/ElementRenderer.h>
HX_DECLARE_CLASS3(cocktail,core,background,BackgroundManager)
HX_DECLARE_CLASS3(cocktail,core,dom,Node)
HX_DECLARE_CLASS3(cocktail,core,renderer,BoxRenderer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
namespace cocktail{
namespace core{
namespace renderer{


class BoxRenderer_obj : public ::cocktail::core::renderer::ElementRenderer_obj{
	public:
		typedef ::cocktail::core::renderer::ElementRenderer_obj super;
		typedef BoxRenderer_obj OBJ_;
		BoxRenderer_obj();
		Void __construct(::cocktail::core::style::CoreStyle style);

	public:
		static hx::ObjectPtr< BoxRenderer_obj > __new(::cocktail::core::style::CoreStyle style);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BoxRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BoxRenderer"); }

		::cocktail::core::background::BackgroundManager _backgroundManager; /* REM */ 
		virtual Void init( );
		Dynamic init_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic renderBackground( );
		Dynamic renderBackground_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace renderer

#endif /* INCLUDED_cocktail_core_renderer_BoxRenderer */ 
