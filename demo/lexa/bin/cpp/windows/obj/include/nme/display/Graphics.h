#ifndef INCLUDED_nme_display_Graphics
#define INCLUDED_nme_display_Graphics

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(nme,display,BitmapData)
HX_DECLARE_CLASS2(nme,display,CapsStyle)
HX_DECLARE_CLASS2(nme,display,GradientType)
HX_DECLARE_CLASS2(nme,display,Graphics)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
HX_DECLARE_CLASS2(nme,display,IGraphicsData)
HX_DECLARE_CLASS2(nme,display,InterpolationMethod)
HX_DECLARE_CLASS2(nme,display,JointStyle)
HX_DECLARE_CLASS2(nme,display,LineScaleMode)
HX_DECLARE_CLASS2(nme,display,SpreadMethod)
HX_DECLARE_CLASS2(nme,display,Tilesheet)
HX_DECLARE_CLASS2(nme,display,TriangleCulling)
HX_DECLARE_CLASS2(nme,geom,Matrix)
namespace nme{
namespace display{


class Graphics_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Graphics_obj OBJ_;
		Graphics_obj();
		Void __construct(Dynamic inHandle);

	public:
		static hx::ObjectPtr< Graphics_obj > __new(Dynamic inHandle);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Graphics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		::String __ToString() const { return HX_CSTRING("Graphics"); }

		Dynamic nmeHandle; /* REM */ 
		virtual Void arcTo( double inCX,double inCY,double inX,double inY);
		Dynamic arcTo_dyn();

		virtual Void beginBitmapFill( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic repeat,Dynamic smooth);
		Dynamic beginBitmapFill_dyn();

		virtual Void beginFill( int color,Dynamic alpha);
		Dynamic beginFill_dyn();

		virtual Void beginGradientFill( ::nme::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio);
		Dynamic beginGradientFill_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual Void curveTo( double inCX,double inCY,double inX,double inY);
		Dynamic curveTo_dyn();

		virtual Void drawCircle( double inX,double inY,double inRadius);
		Dynamic drawCircle_dyn();

		virtual Void drawEllipse( double inX,double inY,double inWidth,double inHeight);
		Dynamic drawEllipse_dyn();

		virtual Void drawGraphicsData( Array< ::nme::display::IGraphicsData > graphicsData);
		Dynamic drawGraphicsData_dyn();

		virtual Void drawGraphicsDatum( ::nme::display::IGraphicsData graphicsDatum);
		Dynamic drawGraphicsDatum_dyn();

		virtual Void drawPoints( Array< double > inXY,Array< int > inPointRGBA,Dynamic inDefaultRGBA,Dynamic inSize);
		Dynamic drawPoints_dyn();

		virtual Void drawRect( double inX,double inY,double inWidth,double inHeight);
		Dynamic drawRect_dyn();

		virtual Void drawRoundRect( double inX,double inY,double inWidth,double inHeight,double inRadX,Dynamic inRadY);
		Dynamic drawRoundRect_dyn();

		virtual Void drawTiles( ::nme::display::Tilesheet sheet,Array< double > inXYID,Dynamic inSmooth,Dynamic inFlags);
		Dynamic drawTiles_dyn();

		virtual Void drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::nme::display::TriangleCulling culling,Array< int > colours,Dynamic blendMode,Array< double > viewport);
		Dynamic drawTriangles_dyn();

		virtual Void endFill( );
		Dynamic endFill_dyn();

		virtual Void lineBitmapStyle( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic repeat,Dynamic smooth);
		Dynamic lineBitmapStyle_dyn();

		virtual Void lineGradientStyle( ::nme::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic focalPointRatio);
		Dynamic lineGradientStyle_dyn();

		virtual Void lineStyle( Dynamic thickness,Dynamic color,Dynamic alpha,Dynamic pixelHinting,::nme::display::LineScaleMode scaleMode,::nme::display::CapsStyle caps,::nme::display::JointStyle joints,Dynamic miterLimit);
		Dynamic lineStyle_dyn();

		virtual Void lineTo( double inX,double inY);
		Dynamic lineTo_dyn();

		virtual Void moveTo( double inX,double inY);
		Dynamic moveTo_dyn();

		static int TILE_SCALE; /* REM */ 
		static int TILE_ROTATION; /* REM */ 
		static int TILE_RGB; /* REM */ 
		static int TILE_ALPHA; /* REM */ 
		static int TILE_SMOOTH; /* REM */ 
		static int TILE_BLEND_NORMAL; /* REM */ 
		static int TILE_BLEND_ADD; /* REM */ 
		static int RGBA( int inRGB,Dynamic inA);
		static Dynamic RGBA_dyn();

		static Dynamic nme_gfx_clear; /* REM */ 
	Dynamic &nme_gfx_clear_dyn() { return nme_gfx_clear;}
		static Dynamic nme_gfx_begin_fill; /* REM */ 
	Dynamic &nme_gfx_begin_fill_dyn() { return nme_gfx_begin_fill;}
		static Dynamic nme_gfx_begin_bitmap_fill; /* REM */ 
	Dynamic &nme_gfx_begin_bitmap_fill_dyn() { return nme_gfx_begin_bitmap_fill;}
		static Dynamic nme_gfx_line_bitmap_fill; /* REM */ 
	Dynamic &nme_gfx_line_bitmap_fill_dyn() { return nme_gfx_line_bitmap_fill;}
		static Dynamic nme_gfx_begin_gradient_fill; /* REM */ 
	Dynamic &nme_gfx_begin_gradient_fill_dyn() { return nme_gfx_begin_gradient_fill;}
		static Dynamic nme_gfx_line_gradient_fill; /* REM */ 
	Dynamic &nme_gfx_line_gradient_fill_dyn() { return nme_gfx_line_gradient_fill;}
		static Dynamic nme_gfx_end_fill; /* REM */ 
	Dynamic &nme_gfx_end_fill_dyn() { return nme_gfx_end_fill;}
		static Dynamic nme_gfx_line_style; /* REM */ 
	Dynamic &nme_gfx_line_style_dyn() { return nme_gfx_line_style;}
		static Dynamic nme_gfx_move_to; /* REM */ 
	Dynamic &nme_gfx_move_to_dyn() { return nme_gfx_move_to;}
		static Dynamic nme_gfx_line_to; /* REM */ 
	Dynamic &nme_gfx_line_to_dyn() { return nme_gfx_line_to;}
		static Dynamic nme_gfx_curve_to; /* REM */ 
	Dynamic &nme_gfx_curve_to_dyn() { return nme_gfx_curve_to;}
		static Dynamic nme_gfx_arc_to; /* REM */ 
	Dynamic &nme_gfx_arc_to_dyn() { return nme_gfx_arc_to;}
		static Dynamic nme_gfx_draw_ellipse; /* REM */ 
	Dynamic &nme_gfx_draw_ellipse_dyn() { return nme_gfx_draw_ellipse;}
		static Dynamic nme_gfx_draw_data; /* REM */ 
	Dynamic &nme_gfx_draw_data_dyn() { return nme_gfx_draw_data;}
		static Dynamic nme_gfx_draw_datum; /* REM */ 
	Dynamic &nme_gfx_draw_datum_dyn() { return nme_gfx_draw_datum;}
		static Dynamic nme_gfx_draw_rect; /* REM */ 
	Dynamic &nme_gfx_draw_rect_dyn() { return nme_gfx_draw_rect;}
		static Dynamic nme_gfx_draw_tiles; /* REM */ 
	Dynamic &nme_gfx_draw_tiles_dyn() { return nme_gfx_draw_tiles;}
		static Dynamic nme_gfx_draw_points; /* REM */ 
	Dynamic &nme_gfx_draw_points_dyn() { return nme_gfx_draw_points;}
		static Dynamic nme_gfx_draw_round_rect; /* REM */ 
	Dynamic &nme_gfx_draw_round_rect_dyn() { return nme_gfx_draw_round_rect;}
		static Dynamic nme_gfx_draw_triangles; /* REM */ 
	Dynamic &nme_gfx_draw_triangles_dyn() { return nme_gfx_draw_triangles;}
};

} // end namespace nme
} // end namespace display

#endif /* INCLUDED_nme_display_Graphics */ 
