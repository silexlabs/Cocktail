#ifndef INCLUDED_cocktail_core_geom_CubicBezier
#define INCLUDED_cocktail_core_geom_CubicBezier

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,CubicBezier)
namespace cocktail{
namespace core{
namespace geom{


class CubicBezier_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CubicBezier_obj OBJ_;
		CubicBezier_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< CubicBezier_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~CubicBezier_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CubicBezier"); }

		virtual Float bezierY( Float t);
		Dynamic bezierY_dyn();

		virtual Float bezierX( Float t);
		Dynamic bezierX_dyn();

		virtual Void init( Float x1,Float y1,Float x2,Float y2);
		Dynamic init_dyn();

		Float _ay; /* REM */ 
		Float _by; /* REM */ 
		Float _cy; /* REM */ 
		Float _ax; /* REM */ 
		Float _bx; /* REM */ 
		Float _cx; /* REM */ 
		Float _y2; /* REM */ 
		Float _x2; /* REM */ 
		Float _y1; /* REM */ 
		Float _x1; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_CubicBezier */ 
