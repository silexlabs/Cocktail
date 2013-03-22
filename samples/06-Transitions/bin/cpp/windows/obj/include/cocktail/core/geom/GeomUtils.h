#ifndef INCLUDED_cocktail_core_geom_GeomUtils
#define INCLUDED_cocktail_core_geom_GeomUtils

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(cocktail,core,geom,GeomUtils)
HX_DECLARE_CLASS3(cocktail,core,geom,RectangleVO)
HX_DECLARE_CLASS3(cocktail,core,utils,IPoolable)
namespace cocktail{
namespace core{
namespace geom{


class GeomUtils_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GeomUtils_obj OBJ_;
		GeomUtils_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< GeomUtils_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~GeomUtils_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GeomUtils"); }

		static Void addBounds( ::cocktail::core::geom::RectangleVO addedBounds,::cocktail::core::geom::RectangleVO bounds,hx::Null< bool >  getHorizontalBounds,hx::Null< bool >  getVerticalBounds);
		static Dynamic addBounds_dyn();

		static Void intersectBounds( ::cocktail::core::geom::RectangleVO bounds1,::cocktail::core::geom::RectangleVO bounds2,::cocktail::core::geom::RectangleVO resultBounds);
		static Dynamic intersectBounds_dyn();

		static Void getCenteredBounds( Float maximumWidth,Float maximumHeight,Float boundsWidth,Float boundsHeight,::cocktail::core::geom::RectangleVO resultBounds);
		static Dynamic getCenteredBounds_dyn();

};

} // end namespace cocktail
} // end namespace core
} // end namespace geom

#endif /* INCLUDED_cocktail_core_geom_GeomUtils */ 
