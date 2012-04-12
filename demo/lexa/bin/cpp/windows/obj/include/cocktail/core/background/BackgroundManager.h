#ifndef INCLUDED_cocktail_core_background_BackgroundManager
#define INCLUDED_cocktail_core_background_BackgroundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,background,BackgroundDrawingManager)
HX_DECLARE_CLASS3(cocktail,core,background,BackgroundManager)
HX_DECLARE_CLASS3(cocktail,core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractImageLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS3(cocktail,core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundClip)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundImage)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundOrigin)
HX_DECLARE_CLASS3(cocktail,core,style,BackgroundSize)
HX_DECLARE_CLASS3(cocktail,core,style,CoreStyle)
HX_DECLARE_CLASS3(cocktail,core,unit,CSSColor)
HX_DECLARE_CLASS3(cocktail,core,unit,GradientValue)
HX_DECLARE_CLASS3(cocktail,port,flash_player,DrawingManager)
HX_DECLARE_CLASS3(cocktail,port,flash_player,MediaLoader)
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
		::String __ToString() const { return HX_CSTRING("BackgroundManager"); }

		Array< ::cocktail::core::background::BackgroundDrawingManager > _backgroundDrawingManagers; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic render( Dynamic backgroundBox,::cocktail::core::style::CoreStyle style);
		Dynamic render_dyn();

		virtual Dynamic drawBackgroundImage( Dynamic imageDeclaration,::cocktail::core::style::CoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundImage_dyn();

		virtual Void onBackgroundImageLoaded( Dynamic backgroundImageNativeElement,Dynamic loadedBackgroundImage,::cocktail::core::resource::AbstractImageLoader imageLoader,::cocktail::core::style::CoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		Dynamic onBackgroundImageLoaded_dyn();

		virtual Void onBackgroundImageLoadError( ::String error,::cocktail::core::unit::CSSColor backgroundColor,Dynamic backgroundImageNativeElement,::cocktail::core::style::CoreStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		Dynamic onBackgroundImageLoadError_dyn();

		virtual Void drawBackgroundColor( ::cocktail::core::style::CoreStyle style,Dynamic backgroundColor,Dynamic backgroundColorNativeElement,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundColor_dyn();

		virtual Dynamic drawBackgroundGradient( ::cocktail::core::style::CoreStyle style,::cocktail::core::unit::GradientValue gradientValue,Dynamic backgroundBox,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundGradient_dyn();

		virtual Dynamic getBackgroundPaintingBox( Dynamic computedBackgroundBox);
		Dynamic getBackgroundPaintingBox_dyn();

		virtual Dynamic getBackgroundPositioningBox( Dynamic computedPositioningBox);
		Dynamic getBackgroundPositioningBox_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace background

#endif /* INCLUDED_cocktail_core_background_BackgroundManager */ 
