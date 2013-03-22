#ifndef INCLUDED_neash_display_Bitmap
#define INCLUDED_neash_display_Bitmap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <neash/display/DisplayObject.h>
HX_DECLARE_CLASS2(neash,display,Bitmap)
HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,Graphics)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,PixelSnapping)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
namespace neash{
namespace display{


class Bitmap_obj : public ::neash::display::DisplayObject_obj{
	public:
		typedef ::neash::display::DisplayObject_obj super;
		typedef Bitmap_obj OBJ_;
		Bitmap_obj();
		Void __construct(::neash::display::BitmapData bitmapData,::neash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing);

	public:
		static hx::ObjectPtr< Bitmap_obj > __new(::neash::display::BitmapData bitmapData,::neash::display::PixelSnapping pixelSnapping,hx::Null< bool >  __o_smoothing);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bitmap"); }

		virtual bool nmeSetSmoothing( bool inSmooth);
		Dynamic nmeSetSmoothing_dyn();

		virtual ::neash::display::BitmapData nmeSetBitmapData( ::neash::display::BitmapData inBitmapData);
		Dynamic nmeSetBitmapData_dyn();

		virtual Void nmeRebuild( );
		Dynamic nmeRebuild_dyn();

		::neash::display::Graphics mGraphics; /* REM */ 
		bool smoothing; /* REM */ 
		::neash::display::BitmapData bitmapData; /* REM */ 
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Bitmap */ 
