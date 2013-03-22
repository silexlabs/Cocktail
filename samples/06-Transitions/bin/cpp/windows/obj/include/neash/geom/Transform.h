#ifndef INCLUDED_neash_geom_Transform
#define INCLUDED_neash_geom_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,geom,ColorTransform)
HX_DECLARE_CLASS2(neash,geom,Matrix)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
HX_DECLARE_CLASS2(neash,geom,Transform)
namespace neash{
namespace geom{


class Transform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Transform_obj OBJ_;
		Transform_obj();
		Void __construct(::neash::display::DisplayObject inParent);

	public:
		static hx::ObjectPtr< Transform_obj > __new(::neash::display::DisplayObject inParent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Transform"); }

		virtual ::neash::geom::Rectangle nmeGetPixelBounds( );
		Dynamic nmeGetPixelBounds_dyn();

		virtual ::neash::geom::Matrix nmeSetMatrix( ::neash::geom::Matrix inMatrix);
		Dynamic nmeSetMatrix_dyn();

		virtual ::neash::geom::Matrix nmeGetMatrix( );
		Dynamic nmeGetMatrix_dyn();

		virtual ::neash::geom::Matrix nmeGetConcatenatedMatrix( );
		Dynamic nmeGetConcatenatedMatrix_dyn();

		virtual ::neash::geom::ColorTransform nmeGetConcatenatedColorTransform( );
		Dynamic nmeGetConcatenatedColorTransform_dyn();

		virtual ::neash::geom::ColorTransform nmeSetColorTransform( ::neash::geom::ColorTransform inTrans);
		Dynamic nmeSetColorTransform_dyn();

		virtual ::neash::geom::ColorTransform nmeGetColorTransform( );
		Dynamic nmeGetColorTransform_dyn();

		::neash::display::DisplayObject nmeObj; /* REM */ 
		::neash::geom::Rectangle pixelBounds; /* REM */ 
		::neash::geom::Matrix matrix; /* REM */ 
		::neash::geom::Matrix concatenatedMatrix; /* REM */ 
		::neash::geom::ColorTransform concatenatedColorTransform; /* REM */ 
		::neash::geom::ColorTransform colorTransform; /* REM */ 
};

} // end namespace neash
} // end namespace geom

#endif /* INCLUDED_neash_geom_Transform */ 
