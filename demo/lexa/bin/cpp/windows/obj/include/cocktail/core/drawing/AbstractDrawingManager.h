#ifndef INCLUDED_cocktail_core_drawing_AbstractDrawingManager
#define INCLUDED_cocktail_core_drawing_AbstractDrawingManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,dom,CapsStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,FillStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,JointStyleValue)
HX_DECLARE_CLASS3(cocktail,core,dom,LineStyleValue)
HX_DECLARE_CLASS3(cocktail,core,drawing,AbstractDrawingManager)
HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
namespace cocktail{
namespace core{
namespace drawing{


class AbstractDrawingManager_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AbstractDrawingManager_obj OBJ_;
		AbstractDrawingManager_obj();
		Void __construct(Dynamic nativeElement,int width,int height);

	public:
		static hx::ObjectPtr< AbstractDrawingManager_obj > __new(Dynamic nativeElement,int width,int height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AbstractDrawingManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("AbstractDrawingManager"); }

		Dynamic _nativeElement; /* REM */ 
		Dynamic nativeElement; /* REM */ 
		int _width; /* REM */ 
		int width; /* REM */ 
		int _height; /* REM */ 
		int height; /* REM */ 
		virtual Void beginFill( ::cocktail::core::dom::FillStyleValue fillStyle,::cocktail::core::dom::LineStyleValue lineStyle);
		Dynamic beginFill_dyn();

		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void setLineStyle( ::cocktail::core::dom::LineStyleValue lineStyle);
		Dynamic setLineStyle_dyn();

		virtual Void setFillStyle( ::cocktail::core::dom::FillStyleValue fillStyle);
		Dynamic setFillStyle_dyn();

		virtual Void drawRect( int x,int y,int width,int height,Dynamic cornerRadiuses);
		Dynamic drawRect_dyn();

		virtual Void drawEllipse( int x,int y,int width,int height);
		Dynamic drawEllipse_dyn();

		virtual Void drawImage( Dynamic source,::cocktail::core::geom::Matrix matrix,Dynamic sourceRect);
		Dynamic drawImage_dyn();

		virtual Void lineTo( double x,double y);
		Dynamic lineTo_dyn();

		virtual Void moveTo( double x,double y);
		Dynamic moveTo_dyn();

		virtual Void curveTo( double controlX,double controlY,double x,double y);
		Dynamic curveTo_dyn();

		virtual Dynamic toNativeAlpha( double genericAlpa);
		Dynamic toNativeAlpha_dyn();

		virtual Dynamic toNativeColor( int genericColor);
		Dynamic toNativeColor_dyn();

		virtual Dynamic toNativeRatio( int genericRatio);
		Dynamic toNativeRatio_dyn();

		virtual Dynamic toNativeCapStyle( ::cocktail::core::dom::CapsStyleValue genericCapStyle);
		Dynamic toNativeCapStyle_dyn();

		virtual Dynamic toNativeJointStyle( ::cocktail::core::dom::JointStyleValue genericJointStyle);
		Dynamic toNativeJointStyle_dyn();

		virtual Dynamic getNativeElement( );
		Dynamic getNativeElement_dyn();

		virtual int setWidth( int value);
		Dynamic setWidth_dyn();

		virtual int getWidth( );
		Dynamic getWidth_dyn();

		virtual int setHeight( int value);
		Dynamic setHeight_dyn();

		virtual int getHeight( );
		Dynamic getHeight_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace drawing

#endif /* INCLUDED_cocktail_core_drawing_AbstractDrawingManager */ 
