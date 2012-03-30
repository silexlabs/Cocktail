#ifndef INCLUDED_core_background_BackgroundDrawingManager
#define INCLUDED_core_background_BackgroundDrawingManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <port/flash_player/DrawingManager.h>
HX_DECLARE_CLASS2(core,background,BackgroundDrawingManager)
HX_DECLARE_CLASS2(core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS2(core,unit,GradientAngle)
HX_DECLARE_CLASS2(core,unit,GradientValue)
HX_DECLARE_CLASS2(port,flash_player,DrawingManager)
namespace core{
namespace background{


class BackgroundDrawingManager_obj : public ::port::flash_player::DrawingManager_obj{
	public:
		typedef ::port::flash_player::DrawingManager_obj super;
		typedef BackgroundDrawingManager_obj OBJ_;
		BackgroundDrawingManager_obj();
		Void __construct(Dynamic nativeElement,Dynamic backgroundBox);

	public:
		static hx::ObjectPtr< BackgroundDrawingManager_obj > __new(Dynamic nativeElement,Dynamic backgroundBox);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BackgroundDrawingManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("BackgroundDrawingManager"); }

		virtual Void drawBackgroundImage( Dynamic nativeImage,Dynamic backgroundPositioningBox,Dynamic backgroundPaintingBox,int intrinsicWidth,int intrinsicHeight,double intrinsicRatio,Dynamic computedBackgroundSize,Dynamic computedBackgroundPosition,Dynamic backgroundRepeat);
		Dynamic drawBackgroundImage_dyn();

		virtual Void drawBackgroundColor( Dynamic color,Dynamic backgroundPaintingBox);
		Dynamic drawBackgroundColor_dyn();

		virtual Void drawBackgroundGradient( ::core::unit::GradientValue gradient,Dynamic backgroundPositioningBox,Dynamic backgroundPaintingBox,Dynamic computedBackgroundSize,Dynamic computedBackgroundPosition,Dynamic backgroundRepeat);
		Dynamic drawBackgroundGradient_dyn();

		virtual Dynamic getGradientStops( Dynamic value);
		Dynamic getGradientStops_dyn();

		virtual int getRotation( ::core::unit::GradientAngle value);
		Dynamic getRotation_dyn();

};

} // end namespace core
} // end namespace background

#endif /* INCLUDED_core_background_BackgroundDrawingManager */ 
