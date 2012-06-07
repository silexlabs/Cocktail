#ifndef INCLUDED_core_background_BackgroundManager
#define INCLUDED_core_background_BackgroundManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(core,background,BackgroundDrawingManager)
HX_DECLARE_CLASS2(core,background,BackgroundManager)
HX_DECLARE_CLASS2(core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS2(core,resource,AbstractImageLoader)
HX_DECLARE_CLASS2(core,resource,AbstractMediaLoader)
HX_DECLARE_CLASS2(core,resource,AbstractResourceLoader)
HX_DECLARE_CLASS2(core,style,AbstractStyle)
HX_DECLARE_CLASS2(core,style,BackgroundClip)
HX_DECLARE_CLASS2(core,style,BackgroundImage)
HX_DECLARE_CLASS2(core,style,BackgroundOrigin)
HX_DECLARE_CLASS2(core,style,BackgroundSize)
HX_DECLARE_CLASS2(core,unit,CSSColor)
HX_DECLARE_CLASS2(core,unit,GradientValue)
HX_DECLARE_CLASS2(port,flash_player,DrawingManager)
HX_DECLARE_CLASS2(port,flash_player,MediaLoader)
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

		Array< ::core::background::BackgroundDrawingManager > _backgroundDrawingManagers; /* REM */ 
		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Dynamic render( Dynamic backgroundBox,::core::style::AbstractStyle style);
		Dynamic render_dyn();

		virtual Dynamic drawBackgroundImage( Dynamic imageDeclaration,::core::style::AbstractStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundImage_dyn();

		virtual Void onBackgroundImageLoaded( Dynamic backgroundImageNativeElement,Dynamic loadedBackgroundImage,::core::resource::AbstractImageLoader imageLoader,::core::style::AbstractStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		Dynamic onBackgroundImageLoaded_dyn();

		virtual Void onBackgroundImageLoadError( ::String error,::core::unit::CSSColor backgroundColor,Dynamic backgroundImageNativeElement,::core::style::AbstractStyle style,Dynamic backgroundBox,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		Dynamic onBackgroundImageLoadError_dyn();

		virtual Void drawBackgroundColor( ::core::style::AbstractStyle style,Dynamic backgroundColor,Dynamic backgroundColorNativeElement,Dynamic backgroundBox,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundColor_dyn();

		virtual Dynamic drawBackgroundGradient( ::core::style::AbstractStyle style,::core::unit::GradientValue gradientValue,Dynamic backgroundBox,Dynamic backgroundPosition,::core::style::BackgroundSize backgroundSize,::core::style::BackgroundOrigin backgroundOrigin,::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::core::style::BackgroundImage backgroundImage);
		Dynamic drawBackgroundGradient_dyn();

		virtual Dynamic getBackgroundPaintingBox( Dynamic computedBackgroundBox);
		Dynamic getBackgroundPaintingBox_dyn();

		virtual Dynamic getBackgroundPositioningBox( Dynamic computedPositioningBox);
		Dynamic getBackgroundPositioningBox_dyn();

};

} // end namespace core
} // end namespace background

#endif /* INCLUDED_core_background_BackgroundManager */ 
