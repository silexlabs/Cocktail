#ifndef INCLUDED_neash_geom_Rectangle
#define INCLUDED_neash_geom_Rectangle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace geom{


class Rectangle_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Rectangle_obj OBJ_;
		Rectangle_obj();
		Void __construct(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight);

	public:
		static hx::ObjectPtr< Rectangle_obj > __new(Dynamic inX,Dynamic inY,Dynamic inWidth,Dynamic inHeight);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Rectangle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Rectangle"); }

		virtual ::neash::geom::Point nmeSetTopLeft( ::neash::geom::Point p);
		Dynamic nmeSetTopLeft_dyn();

		virtual ::neash::geom::Point nmeGetTopLeft( );
		Dynamic nmeGetTopLeft_dyn();

		virtual Float nmeSetTop( Float t);
		Dynamic nmeSetTop_dyn();

		virtual Float nmeGetTop( );
		Dynamic nmeGetTop_dyn();

		virtual ::neash::geom::Point nmeSetSize( ::neash::geom::Point p);
		Dynamic nmeSetSize_dyn();

		virtual ::neash::geom::Point nmeGetSize( );
		Dynamic nmeGetSize_dyn();

		virtual Float nmeSetRight( Float r);
		Dynamic nmeSetRight_dyn();

		virtual Float nmeGetRight( );
		Dynamic nmeGetRight_dyn();

		virtual Float nmeSetLeft( Float l);
		Dynamic nmeSetLeft_dyn();

		virtual Float nmeGetLeft( );
		Dynamic nmeGetLeft_dyn();

		virtual ::neash::geom::Point nmeSetBottomRight( ::neash::geom::Point p);
		Dynamic nmeSetBottomRight_dyn();

		virtual ::neash::geom::Point nmeGetBottomRight( );
		Dynamic nmeGetBottomRight_dyn();

		virtual Float nmeSetBottom( Float b);
		Dynamic nmeSetBottom_dyn();

		virtual Float nmeGetBottom( );
		Dynamic nmeGetBottom_dyn();

		virtual ::neash::geom::Rectangle _union( ::neash::geom::Rectangle toUnion);
		Dynamic _union_dyn();

		virtual ::neash::geom::Rectangle transform( ::neash::geom::Matrix m);
		Dynamic transform_dyn();

		virtual Void setEmpty( );
		Dynamic setEmpty_dyn();

		virtual Void offsetPoint( ::neash::geom::Point point);
		Dynamic offsetPoint_dyn();

		virtual Void offset( Float dx,Float dy);
		Dynamic offset_dyn();

		virtual bool isEmpty( );
		Dynamic isEmpty_dyn();

		virtual bool intersects( ::neash::geom::Rectangle toIntersect);
		Dynamic intersects_dyn();

		virtual ::neash::geom::Rectangle intersection( ::neash::geom::Rectangle toIntersect);
		Dynamic intersection_dyn();

		virtual Void inflatePoint( ::neash::geom::Point point);
		Dynamic inflatePoint_dyn();

		virtual Void inflate( Float dx,Float dy);
		Dynamic inflate_dyn();

		virtual Void extendBounds( ::neash::geom::Rectangle r);
		Dynamic extendBounds_dyn();

		virtual bool equals( ::neash::geom::Rectangle toCompare);
		Dynamic equals_dyn();

		virtual bool containsRect( ::neash::geom::Rectangle rect);
		Dynamic containsRect_dyn();

		virtual bool containsPoint( ::neash::geom::Point point);
		Dynamic containsPoint_dyn();

		virtual bool contains( Float inX,Float inY);
		Dynamic contains_dyn();

		virtual ::neash::geom::Rectangle clone( );
		Dynamic clone_dyn();

		Float y; /* REM */ 
		Float x; /* REM */ 
		Float width; /* REM */ 
		::neash::geom::Point topLeft; /* REM */ 
		Float top; /* REM */ 
		::neash::geom::Point size; /* REM */ 
		Float right; /* REM */ 
		Float left; /* REM */ 
		Float height; /* REM */ 
		::neash::geom::Point bottomRight; /* REM */ 
		Float bottom; /* REM */ 
};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Rectangle */ 
