#ifndef INCLUDED_neash_geom_Point
#define INCLUDED_neash_geom_Point

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,Point)
namespace neash{
namespace geom{


class Point_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Point_obj OBJ_;
		Point_obj();
		Void __construct(hx::Null< Float >  __o_inX,hx::Null< Float >  __o_inY);

	public:
		static hx::ObjectPtr< Point_obj > __new(hx::Null< Float >  __o_inX,hx::Null< Float >  __o_inY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Point_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Point"); }

		virtual Float nmeGetLength( );
		Dynamic nmeGetLength_dyn();

		virtual ::neash::geom::Point subtract( ::neash::geom::Point v);
		Dynamic subtract_dyn();

		virtual Void offset( Float dx,Float dy);
		Dynamic offset_dyn();

		virtual Void normalize( Float thickness);
		Dynamic normalize_dyn();

		virtual bool equals( ::neash::geom::Point toCompare);
		Dynamic equals_dyn();

		virtual ::neash::geom::Point clone( );
		Dynamic clone_dyn();

		virtual ::neash::geom::Point add( ::neash::geom::Point v);
		Dynamic add_dyn();

		Float y; /* REM */ 
		Float x; /* REM */ 
		Float length; /* REM */ 
		static Float distance( ::neash::geom::Point pt1,::neash::geom::Point pt2);
		static Dynamic distance_dyn();

		static ::neash::geom::Point interpolate( ::neash::geom::Point pt1,::neash::geom::Point pt2,Float f);
		static Dynamic interpolate_dyn();

		static ::neash::geom::Point polar( Float len,Float angle);
		static Dynamic polar_dyn();

};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Point */ 
