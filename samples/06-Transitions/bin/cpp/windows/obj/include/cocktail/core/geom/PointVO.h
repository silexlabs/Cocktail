#ifndef INCLUDED_cocktail_core_geom_PointVO
#define INCLUDED_cocktail_core_geom_PointVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,PointVO)
namespace cocktail{
namespace core{
namespace geom{


class PointVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PointVO_obj OBJ_;
		PointVO_obj();
		Void __construct(Float x,Float y);

	public:
		static hx::ObjectPtr< PointVO_obj > __new(Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~PointVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PointVO"); }

		Float y; /* REM */ 
		Float x; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_PointVO */ 
