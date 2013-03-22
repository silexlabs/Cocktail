#ifndef INCLUDED_cocktail_core_graphics_BorderDrawer
#define INCLUDED_cocktail_core_graphics_BorderDrawer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,css,CSSKeywordValue)
HX_DECLARE_CLASS3(cocktail,core,css,ColorVO)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,BorderDrawer)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace graphics{


class BorderDrawer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BorderDrawer_obj OBJ_;
		BorderDrawer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BorderDrawer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BorderDrawer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BorderDrawer"); }

		static ::cocktail::core::geom::RectangleVO _currentBorderBox; /* REM */ 
		static Void draw( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO borderBox,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic draw_dyn();

		static Void drawOutline( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO outlineBox,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic drawOutline_dyn();

		static Void drawBorder( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO borderBox,::cocktail::core::css::ColorVO borderColor,::cocktail::core::css::CSSKeywordValue borderStyle,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic drawBorder_dyn();

		static ::cocktail::core::geom::RectangleVO getTopBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth);
		static Dynamic getTopBorderBox_dyn();

		static ::cocktail::core::geom::RectangleVO getBottomBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth);
		static Dynamic getBottomBorderBox_dyn();

		static ::cocktail::core::geom::RectangleVO getLeftBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth);
		static Dynamic getLeftBorderBox_dyn();

		static ::cocktail::core::geom::RectangleVO getRightBorderBox( ::cocktail::core::geom::RectangleVO borderBox,Float borderWidth);
		static Dynamic getRightBorderBox_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace graphics

#endif /* INCLUDED_cocktail_core_graphics_BorderDrawer */ 
