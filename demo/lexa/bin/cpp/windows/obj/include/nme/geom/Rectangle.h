#ifndef INCLUDED_nme_geom_Rectangle
#define INCLUDED_nme_geom_Rectangle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
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
		::String __ToString() const { return HX_CSTRING("Rectangle"); }

		double bottom; /* REM */ 
		::nme::geom::Point bottomRight; /* REM */ 
		double height; /* REM */ 
		double left; /* REM */ 
		double right; /* REM */ 
		::nme::geom::Point size; /* REM */ 
		double top; /* REM */ 
		::nme::geom::Point topLeft; /* REM */ 
		double width; /* REM */ 
		double x; /* REM */ 
		double y; /* REM */ 
		virtual ::nme::geom::Rectangle clone( );
		Dynamic clone_dyn();

		virtual bool contains( double inX,double inY);
		Dynamic contains_dyn();

		virtual bool containsPoint( ::nme::geom::Point point);
		Dynamic containsPoint_dyn();

		virtual bool containsRect( ::nme::geom::Rectangle rect);
		Dynamic containsRect_dyn();

		virtual bool equals( ::nme::geom::Rectangle toCompare);
		Dynamic equals_dyn();

		virtual Void extendBounds( ::nme::geom::Rectangle r);
		Dynamic extendBounds_dyn();

		virtual Void inflate( double dx,double dy);
		Dynamic inflate_dyn();

		virtual Void inflatePoint( ::nme::geom::Point point);
		Dynamic inflatePoint_dyn();

		virtual ::nme::geom::Rectangle intersection( ::nme::geom::Rectangle toIntersect);
		Dynamic intersection_dyn();

		virtual bool intersects( ::nme::geom::Rectangle toIntersect);
		Dynamic intersects_dyn();

		virtual bool isEmpty( );
		Dynamic isEmpty_dyn();

		virtual Void offset( double dx,double dy);
		Dynamic offset_dyn();

		virtual Void offsetPoint( ::nme::geom::Point point);
		Dynamic offsetPoint_dyn();

		virtual Void setEmpty( );
		Dynamic setEmpty_dyn();

		virtual ::nme::geom::Rectangle transform( ::nme::geom::Matrix m);
		Dynamic transform_dyn();

		virtual ::nme::geom::Rectangle _union( ::nme::geom::Rectangle toUnion);
		Dynamic _union_dyn();

		virtual double nmeGetBottom( );
		Dynamic nmeGetBottom_dyn();

		virtual double nmeSetBottom( double b);
		Dynamic nmeSetBottom_dyn();

		virtual ::nme::geom::Point nmeGetBottomRight( );
		Dynamic nmeGetBottomRight_dyn();

		virtual ::nme::geom::Point nmeSetBottomRight( ::nme::geom::Point p);
		Dynamic nmeSetBottomRight_dyn();

		virtual double nmeGetLeft( );
		Dynamic nmeGetLeft_dyn();

		virtual double nmeSetLeft( double l);
		Dynamic nmeSetLeft_dyn();

		virtual double nmeGetRight( );
		Dynamic nmeGetRight_dyn();

		virtual double nmeSetRight( double r);
		Dynamic nmeSetRight_dyn();

		virtual ::nme::geom::Point nmeGetSize( );
		Dynamic nmeGetSize_dyn();

		virtual ::nme::geom::Point nmeSetSize( ::nme::geom::Point p);
		Dynamic nmeSetSize_dyn();

		virtual double nmeGetTop( );
		Dynamic nmeGetTop_dyn();

		virtual double nmeSetTop( double t);
		Dynamic nmeSetTop_dyn();

		virtual ::nme::geom::Point nmeGetTopLeft( );
		Dynamic nmeGetTopLeft_dyn();

		virtual ::nme::geom::Point nmeSetTopLeft( ::nme::geom::Point p);
		Dynamic nmeSetTopLeft_dyn();

};

} // end namespace nme
} // end namespace geom

#endif /* INCLUDED_nme_geom_Rectangle */ 
