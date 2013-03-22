#ifndef INCLUDED_cocktail_core_geom_DimensionVO
#define INCLUDED_cocktail_core_geom_DimensionVO

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,DimensionVO)
namespace cocktail{
namespace core{
namespace geom{


class DimensionVO_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DimensionVO_obj OBJ_;
		DimensionVO_obj();
		Void __construct(Float width,Float height);

	public:
		static hx::ObjectPtr< DimensionVO_obj > __new(Float width,Float height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DimensionVO_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("DimensionVO"); }

		Float height; /* REM */ 
		Float width; /* REM */ 
};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_DimensionVO */ 
