#ifndef INCLUDED_nme_display_Tilesheet
#define INCLUDED_nme_display_Tilesheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,Tilesheet)
HX_DECLARE_CLASS2(nme,geom,Point)
HX_DECLARE_CLASS2(nme,geom,Rectangle)
namespace nme{
namespace display{


class Tilesheet_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Tilesheet_obj OBJ_;
		Tilesheet_obj();
		Void __construct(::nme::display::BitmapData inImage);

	public:
		static hx::ObjectPtr< Tilesheet_obj > __new(::nme::display::BitmapData inImage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Tilesheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Tilesheet"); }

		::nme::display::BitmapData nmeBitmap; /* REM */ 
		Dynamic nmeHandle; /* REM */ 
		virtual Void addTileRect( ::nme::geom::Rectangle rectangle,::nme::geom::Point centerPoint);
		Dynamic addTileRect_dyn();

		virtual Void drawTiles( ::nme::display::Graphics graphics,Array< double > tileData,Dynamic smooth,Dynamic flags);
		Dynamic drawTiles_dyn();

		static int TILE_SCALE; /* REM */ 
		static int TILE_ROTATION; /* REM */ 
		static int TILE_RGB; /* REM */ 
		static int TILE_ALPHA; /* REM */ 
		static Dynamic nme_tilesheet_create; /* REM */ 
	Dynamic &nme_tilesheet_create_dyn() { return nme_tilesheet_create;}
		static Dynamic nme_tilesheet_add_rect; /* REM */ 
	Dynamic &nme_tilesheet_add_rect_dyn() { return nme_tilesheet_add_rect;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Tilesheet */ 
