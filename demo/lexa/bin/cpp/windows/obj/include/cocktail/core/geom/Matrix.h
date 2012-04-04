#ifndef INCLUDED_cocktail_core_geom_Matrix
#define INCLUDED_cocktail_core_geom_Matrix

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,Matrix)
namespace cocktail{
namespace core{
namespace geom{


class Matrix_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix_obj OBJ_;
		Matrix_obj();
		Void __construct(Dynamic data);

	public:
		static hx::ObjectPtr< Matrix_obj > __new(Dynamic data);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Matrix_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Matrix"); }

		Dynamic _data; /* REM */ 
		Dynamic data; /* REM */ 
		virtual Void identity( );
		Dynamic identity_dyn();

		virtual Dynamic setData( Dynamic data);
		Dynamic setData_dyn();

		virtual Dynamic getData( );
		Dynamic getData_dyn();

		virtual Void concatenate( ::cocktail::core::geom::Matrix matrix);
		Dynamic concatenate_dyn();

		virtual Void translate( double x,double y);
		Dynamic translate_dyn();

		virtual Void rotate( double angle,Dynamic registrationPoint);
		Dynamic rotate_dyn();

		virtual Void scale( double scaleX,double scaleY,Dynamic registrationPoint);
		Dynamic scale_dyn();

		virtual Void skew( double skewX,double skewY,Dynamic registrationPoint);
		Dynamic skew_dyn();

		virtual Void setRotation( double angle,Dynamic registrationPoint);
		Dynamic setRotation_dyn();

		virtual double getRotation( );
		Dynamic getRotation_dyn();

		virtual int getFlip( );
		Dynamic getFlip_dyn();

		virtual Void setScaleX( double scaleXFactor,Dynamic registrationPoint);
		Dynamic setScaleX_dyn();

		virtual double getScaleX( );
		Dynamic getScaleX_dyn();

		virtual Void setScaleY( double scaleYFactor,Dynamic registrationPoint);
		Dynamic setScaleY_dyn();

		virtual double getScaleY( );
		Dynamic getScaleY_dyn();

		virtual Void setTranslationX( double translationX);
		Dynamic setTranslationX_dyn();

		virtual double getTranslationX( );
		Dynamic getTranslationX_dyn();

		virtual Void setTranslationY( double translationY);
		Dynamic setTranslationY_dyn();

		virtual double getTranslationY( );
		Dynamic getTranslationY_dyn();

		virtual double getSkewX( );
		Dynamic getSkewX_dyn();

		virtual double getSkewY( );
		Dynamic getSkewY_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_Matrix */ 
