#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#define INCLUDED_cocktail_core_background_BackgroundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,background,BackgroundManager)
HX_DECLARE_CLASS3(cocktail,core,css,CSSPropertyValue)
HX_DECLARE_CLASS3(cocktail,core,css,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,event,EventTarget)
HX_DECLARE_CLASS3(cocktail,core,geom,DimensionVO)
HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,graphics,GraphicsContext)
HX_DECLARE_CLASS3(cocktail,core,renderer,ElementRenderer)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResource)
HX_DECLARE_CLASS3(cocktail,core,utils,FastNode)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace background{


class BackgroundManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BackgroundManager_obj OBJ_;
		BackgroundManager_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BackgroundManager_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BackgroundManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BackgroundManager"); }

		static ::cocktail::core::geom::RectangleVO _box; /* REM */ 
		static ::cocktail::core::geom::PointVO _destinationPoint; /* REM */ 
		static ::cocktail::core::geom::RectangleVO _intersectionBounds; /* REM */ 
		static Void render( ::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::css::CoreStyle style,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic render_dyn();

		static Array< ::cocktail::core::css::CSSPropertyValue > getAsArray( ::cocktail::core::css::CSSPropertyValue cssProperty);
		static Dynamic getAsArray_dyn();

		static Void drawBackgroundImage( ::cocktail::core::graphics::GraphicsContext graphicContext,::String url,::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::css::CSSPropertyValue backgroundImage,::cocktail::core::renderer::ElementRenderer elementRenderer,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic drawBackgroundImage_dyn();

		static Void doDrawBackgroundImage( ::cocktail::core::geom::RectangleVO backgroundBox,::cocktail::core::graphics::GraphicsContext graphicContext,::cocktail::core::resource::AbstractResource resource,::cocktail::core::geom::RectangleVO backgroundPositioningBox,::cocktail::core::geom::RectangleVO backgroundPaintingBox,Float intrinsicWidth,Float intrinsicHeight,Float intrinsicRatio,::cocktail::core::geom::DimensionVO computedBackgroundSize,::cocktail::core::geom::PointVO computedBackgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::geom::RectangleVO clipRect);
		static Dynamic doDrawBackgroundImage_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace background

#endif /* INCLUDED_cocktail_core_background_BackgroundManager */ 
