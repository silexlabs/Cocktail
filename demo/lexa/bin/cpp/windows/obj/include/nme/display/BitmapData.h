#ifndef INCLUDED_nme_display_BitmapData
#define INCLUDED_nme_display_BitmapData

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <nme/display/IBitmapDrawable.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,filters,BitmapFilter)
HX_DECLARE_CLASS2(nme,geom,ColorTransform)
HX_DECLARE_CLASS2(nme,geom,Matrix)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
HX_DECLARE_CLASS2(nme,utils,ByteArray)
HX_DECLARE_CLASS2(nme,utils,IDataInput)
namespace nme{
namespace display{


class BitmapData_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapData_obj OBJ_;
		BitmapData_obj();
		Void __construct(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA);

	public:
		static hx::ObjectPtr< BitmapData_obj > __new(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapData_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		inline operator ::nme::display::IBitmapDrawable_obj *()
			{ return new ::nme::display::IBitmapDrawable_delegate_< BitmapData_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_CSTRING("BitmapData"); }

		int height; /* REM */ 
		::nme::geom::Rectangle rect; /* REM */ 
		bool transparent; /* REM */ 
		int width; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		virtual Void applyFilter( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::filters::BitmapFilter filter);
		Dynamic applyFilter_dyn();

		virtual Void clear( int color);
		Dynamic clear_dyn();

		virtual ::nme::display::BitmapData clone( );
		Dynamic clone_dyn();

		virtual Void colorTransform( ::nme::geom::Rectangle rect,::nme::geom::ColorTransform colorTransform);
		Dynamic colorTransform_dyn();

		virtual Void copyChannel( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,int inSourceChannel,int inDestChannel);
		Dynamic copyChannel_dyn();

		virtual Void copyPixels( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::display::BitmapData alphaBitmapData,::nme::geom::Point alphaPoint,Dynamic mergeAlpha);
		Dynamic copyPixels_dyn();

		virtual Void createHardwareSurface( );
		Dynamic createHardwareSurface_dyn();

		virtual Void destroyHardwareSurface( );
		Dynamic destroyHardwareSurface_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void draw( ::nme::display::IBitmapDrawable source,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,Dynamic smoothing);
		Dynamic draw_dyn();

		virtual Void dumpBits( );
		Dynamic dumpBits_dyn();

		virtual ::nme::utils::ByteArray encode( ::String inFormat,Dynamic inQuality);
		Dynamic encode_dyn();

		virtual Void fillRect( ::nme::geom::Rectangle rect,int inColour);
		Dynamic fillRect_dyn();

		virtual Void fillRectEx( ::nme::geom::Rectangle rect,int inColour,Dynamic inAlpha);
		Dynamic fillRectEx_dyn();

		virtual ::nme::geom::Rectangle generateFilterRect( ::nme::geom::Rectangle sourceRect,::nme::filters::BitmapFilter filter);
		Dynamic generateFilterRect_dyn();

		virtual ::nme::geom::Rectangle getColorBoundsRect( int mask,int color,Dynamic findColor);
		Dynamic getColorBoundsRect_dyn();

		virtual int getPixel( int x,int y);
		Dynamic getPixel_dyn();

		virtual int getPixel32( int x,int y);
		Dynamic getPixel32_dyn();

		virtual ::nme::utils::ByteArray getPixels( ::nme::geom::Rectangle rect);
		Dynamic getPixels_dyn();

		virtual Array< int > getVector( ::nme::geom::Rectangle rect);
		Dynamic getVector_dyn();

		virtual Void lock( );
		Dynamic lock_dyn();

		virtual Void nmeDrawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing);
		Dynamic nmeDrawToSurface_dyn();

		virtual Void scroll( int inDX,int inDY);
		Dynamic scroll_dyn();

		virtual Void setFlags( int inFlags);
		Dynamic setFlags_dyn();

		virtual Void setPixel( int inX,int inY,int inColour);
		Dynamic setPixel_dyn();

		virtual Void setPixel32( int inX,int inY,int inColour);
		Dynamic setPixel32_dyn();

		virtual Void setPixels( ::nme::geom::Rectangle rect,::nme::utils::ByteArray pixels);
		Dynamic setPixels_dyn();

		virtual Void setVector( ::nme::geom::Rectangle rect,Array< int > inPixels);
		Dynamic setVector_dyn();

		virtual Void unlock( ::nme::geom::Rectangle changeRect);
		Dynamic unlock_dyn();

		virtual Void setFormat( int format);
		Dynamic setFormat_dyn();

		virtual ::nme::geom::Rectangle nmeGetRect( );
		Dynamic nmeGetRect_dyn();

		virtual int nmeGetWidth( );
		Dynamic nmeGetWidth_dyn();

		virtual int nmeGetHeight( );
		Dynamic nmeGetHeight_dyn();

		virtual bool nmeGetTransparent( );
		Dynamic nmeGetTransparent_dyn();

		static int CLEAR; /* REM */ 
		static int BLACK; /* REM */ 
		static int WHITE; /* REM */ 
		static int RED; /* REM */ 
		static int GREEN; /* REM */ 
		static int BLUE; /* REM */ 
		static ::String PNG; /* REM */ 
		static ::String JPG; /* REM */ 
		static int TRANSPARENT; /* REM */ 
		static int HARDWARE; /* REM */ 
		static int FORMAT_8888; /* REM */ 
		static int FORMAT_4444; /* REM */ 
		static int FORMAT_565; /* REM */ 
		static int createColor( int inRGB,Dynamic inAlpha);
		static Dynamic createColor_dyn();

		static int extractAlpha( int v);
		static Dynamic extractAlpha_dyn();

		static int extractColor( int v);
		static Dynamic extractColor_dyn();

		static ::nme::display::BitmapData load( ::String inFilename,Dynamic format);
		static Dynamic load_dyn();

		static ::nme::display::BitmapData loadFromBytes( ::nme::utils::ByteArray inBytes,::nme::utils::ByteArray inRawAlpha);
		static Dynamic loadFromBytes_dyn();

		static ::nme::display::BitmapData loadFromHaxeBytes( ::haxe::io::Bytes inBytes,::haxe::io::Bytes inRawAlpha);
		static Dynamic loadFromHaxeBytes_dyn();

		static Dynamic nme_bitmap_data_create; /* REM */ 
	Dynamic &nme_bitmap_data_create_dyn() { return nme_bitmap_data_create;}
		static Dynamic nme_bitmap_data_load; /* REM */ 
	Dynamic &nme_bitmap_data_load_dyn() { return nme_bitmap_data_load;}
		static Dynamic nme_bitmap_data_from_bytes; /* REM */ 
	Dynamic &nme_bitmap_data_from_bytes_dyn() { return nme_bitmap_data_from_bytes;}
		static Dynamic nme_bitmap_data_clear; /* REM */ 
	Dynamic &nme_bitmap_data_clear_dyn() { return nme_bitmap_data_clear;}
		static Dynamic nme_bitmap_data_clone; /* REM */ 
	Dynamic &nme_bitmap_data_clone_dyn() { return nme_bitmap_data_clone;}
		static Dynamic nme_bitmap_data_apply_filter; /* REM */ 
	Dynamic &nme_bitmap_data_apply_filter_dyn() { return nme_bitmap_data_apply_filter;}
		static Dynamic nme_bitmap_data_color_transform; /* REM */ 
	Dynamic &nme_bitmap_data_color_transform_dyn() { return nme_bitmap_data_color_transform;}
		static Dynamic nme_bitmap_data_copy; /* REM */ 
	Dynamic &nme_bitmap_data_copy_dyn() { return nme_bitmap_data_copy;}
		static Dynamic nme_bitmap_data_copy_channel; /* REM */ 
	Dynamic &nme_bitmap_data_copy_channel_dyn() { return nme_bitmap_data_copy_channel;}
		static Dynamic nme_bitmap_data_fill; /* REM */ 
	Dynamic &nme_bitmap_data_fill_dyn() { return nme_bitmap_data_fill;}
		static Dynamic nme_bitmap_data_get_pixels; /* REM */ 
	Dynamic &nme_bitmap_data_get_pixels_dyn() { return nme_bitmap_data_get_pixels;}
		static Dynamic nme_bitmap_data_get_pixel; /* REM */ 
	Dynamic &nme_bitmap_data_get_pixel_dyn() { return nme_bitmap_data_get_pixel;}
		static Dynamic nme_bitmap_data_get_pixel32; /* REM */ 
	Dynamic &nme_bitmap_data_get_pixel32_dyn() { return nme_bitmap_data_get_pixel32;}
		static Dynamic nme_bitmap_data_get_pixel_rgba; /* REM */ 
		static Dynamic nme_bitmap_data_get_array; /* REM */ 
	Dynamic &nme_bitmap_data_get_array_dyn() { return nme_bitmap_data_get_array;}
		static Dynamic nme_bitmap_data_get_color_bounds_rect; /* REM */ 
	Dynamic &nme_bitmap_data_get_color_bounds_rect_dyn() { return nme_bitmap_data_get_color_bounds_rect;}
		static Dynamic nme_bitmap_data_scroll; /* REM */ 
	Dynamic &nme_bitmap_data_scroll_dyn() { return nme_bitmap_data_scroll;}
		static Dynamic nme_bitmap_data_set_pixel; /* REM */ 
	Dynamic &nme_bitmap_data_set_pixel_dyn() { return nme_bitmap_data_set_pixel;}
		static Dynamic nme_bitmap_data_set_pixel32; /* REM */ 
	Dynamic &nme_bitmap_data_set_pixel32_dyn() { return nme_bitmap_data_set_pixel32;}
		static Dynamic nme_bitmap_data_set_pixel_rgba; /* REM */ 
		static Dynamic nme_bitmap_data_set_bytes; /* REM */ 
	Dynamic &nme_bitmap_data_set_bytes_dyn() { return nme_bitmap_data_set_bytes;}
		static Dynamic nme_bitmap_data_set_format; /* REM */ 
	Dynamic &nme_bitmap_data_set_format_dyn() { return nme_bitmap_data_set_format;}
		static Dynamic nme_bitmap_data_set_array; /* REM */ 
	Dynamic &nme_bitmap_data_set_array_dyn() { return nme_bitmap_data_set_array;}
		static Dynamic nme_bitmap_data_create_hardware_surface; /* REM */ 
	Dynamic &nme_bitmap_data_create_hardware_surface_dyn() { return nme_bitmap_data_create_hardware_surface;}
		static Dynamic nme_bitmap_data_destroy_hardware_surface; /* REM */ 
	Dynamic &nme_bitmap_data_destroy_hardware_surface_dyn() { return nme_bitmap_data_destroy_hardware_surface;}
		static Dynamic nme_bitmap_data_generate_filter_rect; /* REM */ 
	Dynamic &nme_bitmap_data_generate_filter_rect_dyn() { return nme_bitmap_data_generate_filter_rect;}
		static Dynamic nme_render_surface_to_surface; /* REM */ 
	Dynamic &nme_render_surface_to_surface_dyn() { return nme_render_surface_to_surface;}
		static Dynamic nme_bitmap_data_height; /* REM */ 
	Dynamic &nme_bitmap_data_height_dyn() { return nme_bitmap_data_height;}
		static Dynamic nme_bitmap_data_width; /* REM */ 
	Dynamic &nme_bitmap_data_width_dyn() { return nme_bitmap_data_width;}
		static Dynamic nme_bitmap_data_get_transparent; /* REM */ 
	Dynamic &nme_bitmap_data_get_transparent_dyn() { return nme_bitmap_data_get_transparent;}
		static Dynamic nme_bitmap_data_set_flags; /* REM */ 
	Dynamic &nme_bitmap_data_set_flags_dyn() { return nme_bitmap_data_set_flags;}
		static Dynamic nme_bitmap_data_encode; /* REM */ 
	Dynamic &nme_bitmap_data_encode_dyn() { return nme_bitmap_data_encode;}
		static Dynamic nme_bitmap_data_dump_bits; /* REM */ 
	Dynamic &nme_bitmap_data_dump_bits_dyn() { return nme_bitmap_data_dump_bits;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_BitmapData */ 
