#ifndef INCLUDED_neash_display_Tilesheet
#define INCLUDED_neash_display_Tilesheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(neash,display,BitmapData)
HX_DECLARE_CLASS2(neash,display,Graphics)
HX_DECLARE_CLASS2(neash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(neash,display,Tilesheet)
HX_DECLARE_CLASS2(neash,geom,Point)
HX_DECLARE_CLASS2(neash,geom,Rectangle)
namespace neash{
namespace display{


class Tilesheet_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Tilesheet_obj OBJ_;
		Tilesheet_obj();
		Void __construct(::neash::display::BitmapData inImage);

	public:
		static hx::ObjectPtr< Tilesheet_obj > __new(::neash::display::BitmapData inImage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Tilesheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Tilesheet"); }

		virtual Void drawTiles( ::neash::display::Graphics graphics,Array< Float > tileData,hx::Null< bool >  smooth,hx::Null< int >  flags);
		Dynamic drawTiles_dyn();

		virtual Void addTileRect( ::neash::geom::Rectangle rectangle,::neash::geom::Point centerPoint);
		Dynamic addTileRect_dyn();

		Dynamic nmeHandle; /* REM */ 
		::neash::display::BitmapData nmeBitmap; /* REM */ 
		static int TILE_SCALE; /* REM */ 
		static int TILE_ROTATION; /* REM */ 
		static int TILE_RGB; /* REM */ 
		static int TILE_ALPHA; /* REM */ 
		static int TILE_TRANS_2x2; /* REM */ 
		static int TILE_BLEND_NORMAL; /* REM */ 
		static int TILE_BLEND_ADD; /* REM */ 
		static Dynamic nme_tilesheet_create; /* REM */ 
		static Dynamic &nme_tilesheet_create_dyn() { return nme_tilesheet_create;}
		static Dynamic nme_tilesheet_add_rect; /* REM */ 
		static Dynamic &nme_tilesheet_add_rect_dyn() { return nme_tilesheet_add_rect;}
};

} // end namespace neash
} // end namespace display

#endif /* INCLUDED_neash_display_Tilesheet */ 
