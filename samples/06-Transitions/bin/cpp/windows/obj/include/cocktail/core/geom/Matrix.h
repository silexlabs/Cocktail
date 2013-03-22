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
		Void __construct(hx::Null< Float >  __o_a,hx::Null< Float >  __o_b,hx::Null< Float >  __o_c,hx::Null< Float >  __o_d,hx::Null< Float >  __o_e,hx::Null< Float >  __o_f);

	public:
		static hx::ObjectPtr< Matrix_obj > __new(hx::Null< Float >  __o_a,hx::Null< Float >  __o_b,hx::Null< Float >  __o_c,hx::Null< Float >  __o_d,hx::Null< Float >  __o_e,hx::Null< Float >  __o_f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Matrix_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Matrix"); }

		virtual Void skew( Float skewX,Float skewY);
		Dynamic skew_dyn();

		virtual Void scale( Float scaleX,Float scaleY);
		Dynamic scale_dyn();

		virtual Void rotate( Float angle);
		Dynamic rotate_dyn();

		virtual Void translate( Float x,Float y);
		Dynamic translate_dyn();

		virtual bool isIdentity( );
		Dynamic isIdentity_dyn();

		virtual Void concatenate( ::cocktail::core::geom::Matrix matrix);
		Dynamic concatenate_dyn();

		virtual Void identity( );
		Dynamic identity_dyn();

		Float f; /* REM */ 
		Float d; /* REM */ 
		Float e; /* REM */ 
		Float c; /* REM */ 
		Float b; /* REM */ 
		Float a; /* REM */ 
		static ::cocktail::core::geom::Matrix _concatenationMatrix; /* REM */ 
		static ::cocktail::core::geom::Matrix getConcatenationMatrix( Float a,Float b,Float c,Float d,Float e,Float f);
		static Dynamic getConcatenationMatrix_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_Matrix */ 
