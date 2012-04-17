#ifndef INCLUDED_cocktail_port_flash_player_DrawingManager
#define INCLUDED_cocktail_port_flash_player_DrawingManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <cocktail/core/drawing/AbstractDrawingManager.h>
HX_DECLARE_CLASS3(cocktail,core,dom,CapsStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,FillStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,GradientTypeValue)
HX_DECLARE_CLASS3(cocktail,core,dom,JointStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,LineStyleValue)
HX_DECLARE_CLASS3(cocktail,core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
HX_DECLARE_CLASS3(cocktail,port,flash_player,DrawingManager)
HX_DECLARE_CLASS2(nme,display,Bitmap)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(nme,display,GradientType)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,InteractiveObject)
HX_DECLARE_CLASS2(nme,display,Sprite)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace cocktail{
namespace port{
namespace flash_player{


class DrawingManager_obj : public ::cocktail::core::drawing::AbstractDrawingManager_obj{
	public:
		typedef ::cocktail::core::drawing::AbstractDrawingManager_obj super;
		typedef DrawingManager_obj OBJ_;
		DrawingManager_obj();
		Void __construct(Dynamic nativeElement,int width,int height);

	public:
		static hx::ObjectPtr< DrawingManager_obj > __new(Dynamic nativeElement,int width,int height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DrawingManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("DrawingManager"); }

		::nme::display::Bitmap _bitmapDrawing; /* REM */ 
		::nme::display::Sprite _typedNativeElement; /* REM */ 
		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void blit( );
		Dynamic blit_dyn();

		virtual Void setFillStyle( ::cocktail::core::dom::FillStyleValue fillStyle);
		Dynamic setFillStyle_dyn();

		virtual Void setLineStyle( ::cocktail::core::dom::LineStyleValue lineStyle);
		Dynamic setLineStyle_dyn();

		virtual Void drawImage( Dynamic source,::cocktail::core::geom::Matrix matrix,Dynamic sourceRect);
		Dynamic drawImage_dyn();

		virtual Void lineTo( double x,double y);
		Dynamic lineTo_dyn();

		virtual Void moveTo( double x,double y);
		Dynamic moveTo_dyn();

		virtual Void curveTo( double controlX,double controlY,double x,double y);
		Dynamic curveTo_dyn();

		virtual Dynamic toNativeAlpha( double genericAlpha);
		Dynamic toNativeAlpha_dyn();

		virtual Dynamic toNativeRatio( int genericRatio);
		Dynamic toNativeRatio_dyn();

		virtual Dynamic toNativeCapStyle( ::cocktail::core::dom::CapsStyleValue genericCapStyle);
		Dynamic toNativeCapStyle_dyn();

		virtual Dynamic toNativeJointStyle( ::cocktail::core::dom::JointStyleValue genericJointStyle);
		Dynamic toNativeJointStyle_dyn();

		virtual ::nme::display::GradientType getGradientType( ::cocktail::core::dom::GradientTypeValue genericGradientType);
		Dynamic getGradientType_dyn();

		virtual ::nme::display::BitmapData getBitmapData( Dynamic nativeElement);
		Dynamic getBitmapData_dyn();

		virtual Array< int > getGradientColors( Dynamic gradientStops);
		Dynamic getGradientColors_dyn();

		virtual Array< double > getGradientAlphas( Dynamic gradientStops);
		Dynamic getGradientAlphas_dyn();

		virtual Array< int > getGradientRatios( Dynamic gradientStops);
		Dynamic getGradientRatios_dyn();

		virtual ::nme::geom::Matrix getGradientBox( Dynamic gradientStyle);
		Dynamic getGradientBox_dyn();

		virtual int setWidth( int value);
		Dynamic setWidth_dyn();

		virtual int setHeight( int value);
		Dynamic setHeight_dyn();

};

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player

#endif /* INCLUDED_cocktail_port_flash_player_DrawingManager */ 
