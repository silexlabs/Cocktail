#ifndef INCLUDED_cocktail_core_graphics_TextDrawer
#define INCLUDED_cocktail_core_graphics_TextDrawer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,graphics,TextDrawer)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace graphics{


class TextDrawer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextDrawer_obj OBJ_;
		TextDrawer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TextDrawer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TextDrawer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextDrawer"); }

		static ::cocktail::core::geom::PointVO _destPoint; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _renderRect; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _decorationRect; /* REM */ 
		static Float TEXT_DECORATION_THICKNESS; /* REM */ 
		static Void draw( ::cocktail::core::graphics::GraphicsContext graphicsContext,::cocktail::core::renderer::ElementRenderer elementRenderer,bool hasUnderline,bool hasOverline,bool hasLineThrough,bool hasBlink,::cocktail::core::geom::PointVO scrollOffset,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic draw_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace graphics

#endif /* INCLUDED_cocktail_core_graphics_TextDrawer */ 
