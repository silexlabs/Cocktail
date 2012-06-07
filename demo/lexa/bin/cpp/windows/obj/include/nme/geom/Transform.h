#ifndef INCLUDED_nme_geom_Transform
#define INCLUDED_nme_geom_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,DisplayObject)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,events,EventDispatcher)
HX_DECLARE_CLASS2(nme,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS2(nme,geom,Transform)
namespace nme{
namespace geom{


class Transform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Transform_obj OBJ_;
		Transform_obj();
		Void __construct(::nme::display::DisplayObject inParent);

	public:
		static hx::ObjectPtr< Transform_obj > __new(::nme::display::DisplayObject inParent);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Transform"); }

		::nme::geom::ColorTransform colorTransform; /* REM */ 
		::nme::geom::ColorTransform concatenatedColorTransform; /* REM */ 
		::nme::geom::Matrix concatenatedMatrix; /* REM */ 
		::nme::geom::Matrix matrix; /* REM */ 
		::nme::geom::Rectangle pixelBounds; /* REM */ 
		::nme::display::DisplayObject nmeObj; /* REM */ 
		virtual ::nme::geom::ColorTransform nmeGetColorTransform( );
		Dynamic nmeGetColorTransform_dyn();

		virtual ::nme::geom::ColorTransform nmeSetColorTransform( ::nme::geom::ColorTransform inTrans);
		Dynamic nmeSetColorTransform_dyn();

		virtual ::nme::geom::ColorTransform nmeGetConcatenatedColorTransform( );
		Dynamic nmeGetConcatenatedColorTransform_dyn();

		virtual ::nme::geom::Matrix nmeGetConcatenatedMatrix( );
		Dynamic nmeGetConcatenatedMatrix_dyn();

		virtual ::nme::geom::Matrix nmeGetMatrix( );
		Dynamic nmeGetMatrix_dyn();

		virtual ::nme::geom::Matrix nmeSetMatrix( ::nme::geom::Matrix inMatrix);
		Dynamic nmeSetMatrix_dyn();

		virtual ::nme::geom::Rectangle nmeGetPixelBounds( );
		Dynamic nmeGetPixelBounds_dyn();

};

} // end namespace nme
} // end namespace geom

#endif /* INCLUDED_nme_geom_Transform */ 
