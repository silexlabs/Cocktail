#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
#ifndef INCLUDED_nme_display_GradientType
#include <nme/display/GradientType.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_IGraphicsData
#include <nme/display/IGraphicsData.h>
#endif
#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
#ifndef INCLUDED_nme_display_JointStyle
#include <nme/display/JointStyle.h>
#endif
#ifndef INCLUDED_nme_display_LineScaleMode
#include <nme/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
#ifndef INCLUDED_nme_display_Tilesheet
#include <nme/display/Tilesheet.h>
#endif
#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace nme{
namespace display{

Void Graphics_obj::__construct(Dynamic inHandle)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",27)
	this->nmeHandle = inHandle;
}
;
	return null();
}

Graphics_obj::~Graphics_obj() { }

Dynamic Graphics_obj::__CreateEmpty() { return  new Graphics_obj; }
hx::ObjectPtr< Graphics_obj > Graphics_obj::__new(Dynamic inHandle)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inHandle);
	return result;}

Dynamic Graphics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Graphics_obj > result = new Graphics_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Graphics_obj::arcTo( double inCX,double inCY,double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::arcTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",33)
		::nme::display::Graphics_obj::nme_gfx_arc_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,arcTo,(void))

Void Graphics_obj::beginBitmapFill( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic __o_repeat,Dynamic __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::beginBitmapFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",39)
		::nme::display::Graphics_obj::nme_gfx_begin_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,beginBitmapFill,(void))

Void Graphics_obj::beginFill( int color,Dynamic __o_alpha){
double alpha = __o_alpha.Default(1.0);
	HX_SOURCE_PUSH("Graphics_obj::beginFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",45)
		::nme::display::Graphics_obj::nme_gfx_begin_fill(this->nmeHandle,color,alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,beginFill,(void))

Void Graphics_obj::beginGradientFill( ::nme::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::beginGradientFill");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",52)
		if (((matrix == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",54)
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",55)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",58)
		::nme::display::Graphics_obj::nme_gfx_begin_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,beginGradientFill,(void))

Void Graphics_obj::clear( ){
{
		HX_SOURCE_PUSH("Graphics_obj::clear")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",63)
		::nme::display::Graphics_obj::nme_gfx_clear(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,clear,(void))

Void Graphics_obj::curveTo( double inCX,double inCY,double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::curveTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",69)
		::nme::display::Graphics_obj::nme_gfx_curve_to(this->nmeHandle,inCX,inCY,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,curveTo,(void))

Void Graphics_obj::drawCircle( double inX,double inY,double inRadius){
{
		HX_SOURCE_PUSH("Graphics_obj::drawCircle")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",75)
		::nme::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,(inRadius * (int)2),(inRadius * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Graphics_obj,drawCircle,(void))

Void Graphics_obj::drawEllipse( double inX,double inY,double inWidth,double inHeight){
{
		HX_SOURCE_PUSH("Graphics_obj::drawEllipse")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",81)
		::nme::display::Graphics_obj::nme_gfx_draw_ellipse(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawEllipse,(void))

Void Graphics_obj::drawGraphicsData( Array< ::nme::display::IGraphicsData > graphicsData){
{
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsData")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",88)
		Dynamic handles = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",90)
		{
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",90)
			int _g = (int)0;
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",90)
			while(((_g < graphicsData->length))){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",90)
				::nme::display::IGraphicsData datum = graphicsData->__get(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",90)
				++(_g);
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",91)
				handles->__Field(HX_CSTRING("push"))(datum->nmeHandle);
			}
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",93)
		::nme::display::Graphics_obj::nme_gfx_draw_data(this->nmeHandle,handles);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsData,(void))

Void Graphics_obj::drawGraphicsDatum( ::nme::display::IGraphicsData graphicsDatum){
{
		HX_SOURCE_PUSH("Graphics_obj::drawGraphicsDatum")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",98)
		::nme::display::Graphics_obj::nme_gfx_draw_datum(this->nmeHandle,graphicsDatum->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Graphics_obj,drawGraphicsDatum,(void))

Void Graphics_obj::drawPoints( Array< double > inXY,Array< int > inPointRGBA,Dynamic __o_inDefaultRGBA,Dynamic __o_inSize){
int inDefaultRGBA = __o_inDefaultRGBA.Default(-1);
double inSize = __o_inSize.Default(-1.0);
	HX_SOURCE_PUSH("Graphics_obj::drawPoints");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",104)
		::nme::display::Graphics_obj::nme_gfx_draw_points(this->nmeHandle,inXY,inPointRGBA,inDefaultRGBA,false,inSize);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawPoints,(void))

Void Graphics_obj::drawRect( double inX,double inY,double inWidth,double inHeight){
{
		HX_SOURCE_PUSH("Graphics_obj::drawRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",110)
		::nme::display::Graphics_obj::nme_gfx_draw_rect(this->nmeHandle,inX,inY,inWidth,inHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawRect,(void))

Void Graphics_obj::drawRoundRect( double inX,double inY,double inWidth,double inHeight,double inRadX,Dynamic inRadY){
{
		HX_SOURCE_PUSH("Graphics_obj::drawRoundRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",116)
		::nme::display::Graphics_obj::nme_gfx_draw_round_rect(this->nmeHandle,inX,inY,inWidth,inHeight,inRadX,(  (((inRadY == null()))) ? Dynamic(inRadX) : Dynamic(inRadY) ));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Graphics_obj,drawRoundRect,(void))

Void Graphics_obj::drawTiles( ::nme::display::Tilesheet sheet,Array< double > inXYID,Dynamic __o_inSmooth,Dynamic __o_inFlags){
bool inSmooth = __o_inSmooth.Default(false);
int inFlags = __o_inFlags.Default(0);
	HX_SOURCE_PUSH("Graphics_obj::drawTiles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",126)
		this->beginBitmapFill(sheet->nmeBitmap,null(),false,inSmooth);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",128)
		if ((inSmooth)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",129)
			hx::OrEq(inFlags,(int)4096);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",131)
		::nme::display::Graphics_obj::nme_gfx_draw_tiles(this->nmeHandle,sheet->nmeHandle,inXYID,inFlags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,drawTiles,(void))

Void Graphics_obj::drawTriangles( Array< double > vertices,Array< int > indices,Array< double > uvtData,::nme::display::TriangleCulling culling,Array< int > colours,Dynamic __o_blendMode,Array< double > viewport){
int blendMode = __o_blendMode.Default(0);
	HX_SOURCE_PUSH("Graphics_obj::drawTriangles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",137)
		int cull = (  (((culling == null()))) ? int((int)0) : int((culling->__Index() - (int)1)) );
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",138)
		::nme::display::Graphics_obj::nme_gfx_draw_triangles(this->nmeHandle,vertices,indices,uvtData,cull,colours,blendMode,viewport);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(Graphics_obj,drawTriangles,(void))

Void Graphics_obj::endFill( ){
{
		HX_SOURCE_PUSH("Graphics_obj::endFill")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",143)
		::nme::display::Graphics_obj::nme_gfx_end_fill(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Graphics_obj,endFill,(void))

Void Graphics_obj::lineBitmapStyle( ::nme::display::BitmapData bitmap,::nme::geom::Matrix matrix,Dynamic __o_repeat,Dynamic __o_smooth){
bool repeat = __o_repeat.Default(true);
bool smooth = __o_smooth.Default(false);
	HX_SOURCE_PUSH("Graphics_obj::lineBitmapStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",149)
		::nme::display::Graphics_obj::nme_gfx_line_bitmap_fill(this->nmeHandle,bitmap->nmeHandle,matrix,repeat,smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Graphics_obj,lineBitmapStyle,(void))

Void Graphics_obj::lineGradientStyle( ::nme::display::GradientType type,Dynamic colors,Dynamic alphas,Dynamic ratios,::nme::geom::Matrix matrix,::nme::display::SpreadMethod spreadMethod,::nme::display::InterpolationMethod interpolationMethod,Dynamic __o_focalPointRatio){
double focalPointRatio = __o_focalPointRatio.Default(0.0);
	HX_SOURCE_PUSH("Graphics_obj::lineGradientStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",156)
		if (((matrix == null()))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",158)
			matrix = ::nme::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",159)
			matrix->createGradientBox((int)200,(int)200,(int)0,(int)-100,(int)-100);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",162)
		::nme::display::Graphics_obj::nme_gfx_line_gradient_fill(this->nmeHandle,type->__Index(),colors,alphas,ratios,matrix,(  (((spreadMethod == null()))) ? int((int)0) : int(spreadMethod->__Index()) ),(  (((interpolationMethod == null()))) ? int((int)0) : int(interpolationMethod->__Index()) ),focalPointRatio);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineGradientStyle,(void))

Void Graphics_obj::lineStyle( Dynamic thickness,Dynamic __o_color,Dynamic __o_alpha,Dynamic __o_pixelHinting,::nme::display::LineScaleMode scaleMode,::nme::display::CapsStyle caps,::nme::display::JointStyle joints,Dynamic __o_miterLimit){
int color = __o_color.Default(0);
double alpha = __o_alpha.Default(1.0);
bool pixelHinting = __o_pixelHinting.Default(false);
double miterLimit = __o_miterLimit.Default(3);
	HX_SOURCE_PUSH("Graphics_obj::lineStyle");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",167)
		::nme::display::Graphics_obj::nme_gfx_line_style(this->nmeHandle,thickness,color,alpha,pixelHinting,(  (((scaleMode == null()))) ? int((int)0) : int(scaleMode->__Index()) ),(  (((caps == null()))) ? int((int)0) : int(caps->__Index()) ),(  (((joints == null()))) ? int((int)0) : int(joints->__Index()) ),miterLimit);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(Graphics_obj,lineStyle,(void))

Void Graphics_obj::lineTo( double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::lineTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",173)
		::nme::display::Graphics_obj::nme_gfx_line_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,lineTo,(void))

Void Graphics_obj::moveTo( double inX,double inY){
{
		HX_SOURCE_PUSH("Graphics_obj::moveTo")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",179)
		::nme::display::Graphics_obj::nme_gfx_move_to(this->nmeHandle,inX,inY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,moveTo,(void))

int Graphics_obj::TILE_SCALE;

int Graphics_obj::TILE_ROTATION;

int Graphics_obj::TILE_RGB;

int Graphics_obj::TILE_ALPHA;

int Graphics_obj::TILE_SMOOTH;

int Graphics_obj::TILE_BLEND_NORMAL;

int Graphics_obj::TILE_BLEND_ADD;

int Graphics_obj::RGBA( int inRGB,Dynamic __o_inA){
int inA = __o_inA.Default(255);
	HX_SOURCE_PUSH("Graphics_obj::RGBA");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Graphics.hx",185)
		return (int(inRGB) | int((int(inA) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Graphics_obj,RGBA,return )

Dynamic Graphics_obj::nme_gfx_clear;

Dynamic Graphics_obj::nme_gfx_begin_fill;

Dynamic Graphics_obj::nme_gfx_begin_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_line_bitmap_fill;

Dynamic Graphics_obj::nme_gfx_begin_gradient_fill;

Dynamic Graphics_obj::nme_gfx_line_gradient_fill;

Dynamic Graphics_obj::nme_gfx_end_fill;

Dynamic Graphics_obj::nme_gfx_line_style;

Dynamic Graphics_obj::nme_gfx_move_to;

Dynamic Graphics_obj::nme_gfx_line_to;

Dynamic Graphics_obj::nme_gfx_curve_to;

Dynamic Graphics_obj::nme_gfx_arc_to;

Dynamic Graphics_obj::nme_gfx_draw_ellipse;

Dynamic Graphics_obj::nme_gfx_draw_data;

Dynamic Graphics_obj::nme_gfx_draw_datum;

Dynamic Graphics_obj::nme_gfx_draw_rect;

Dynamic Graphics_obj::nme_gfx_draw_tiles;

Dynamic Graphics_obj::nme_gfx_draw_points;

Dynamic Graphics_obj::nme_gfx_draw_round_rect;

Dynamic Graphics_obj::nme_gfx_draw_triangles;


Graphics_obj::Graphics_obj()
{
}

void Graphics_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Graphics);
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic Graphics_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"RGBA") ) { return RGBA_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"arcTo") ) { return arcTo_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"lineTo") ) { return lineTo_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"curveTo") ) { return curveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"endFill") ) { return endFill_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { return TILE_RGB; }
		if (HX_FIELD_EQ(inName,"drawRect") ) { return drawRect_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"beginFill") ) { return beginFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		if (HX_FIELD_EQ(inName,"lineStyle") ) { return lineStyle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { return TILE_SCALE; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { return TILE_ALPHA; }
		if (HX_FIELD_EQ(inName,"drawCircle") ) { return drawCircle_dyn(); }
		if (HX_FIELD_EQ(inName,"drawPoints") ) { return drawPoints_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_SMOOTH") ) { return TILE_SMOOTH; }
		if (HX_FIELD_EQ(inName,"drawEllipse") ) { return drawEllipse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { return TILE_ROTATION; }
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { return nme_gfx_clear; }
		if (HX_FIELD_EQ(inName,"drawRoundRect") ) { return drawRoundRect_dyn(); }
		if (HX_FIELD_EQ(inName,"drawTriangles") ) { return drawTriangles_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { return TILE_BLEND_ADD; }
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { return nme_gfx_arc_to; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { return nme_gfx_move_to; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { return nme_gfx_line_to; }
		if (HX_FIELD_EQ(inName,"beginBitmapFill") ) { return beginBitmapFill_dyn(); }
		if (HX_FIELD_EQ(inName,"lineBitmapStyle") ) { return lineBitmapStyle_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { return nme_gfx_end_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { return nme_gfx_curve_to; }
		if (HX_FIELD_EQ(inName,"drawGraphicsData") ) { return drawGraphicsData_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { return TILE_BLEND_NORMAL; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { return nme_gfx_draw_data; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { return nme_gfx_draw_rect; }
		if (HX_FIELD_EQ(inName,"beginGradientFill") ) { return beginGradientFill_dyn(); }
		if (HX_FIELD_EQ(inName,"drawGraphicsDatum") ) { return drawGraphicsDatum_dyn(); }
		if (HX_FIELD_EQ(inName,"lineGradientStyle") ) { return lineGradientStyle_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { return nme_gfx_begin_fill; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { return nme_gfx_line_style; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { return nme_gfx_draw_datum; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { return nme_gfx_draw_tiles; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { return nme_gfx_draw_points; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { return nme_gfx_draw_ellipse; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { return nme_gfx_draw_triangles; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { return nme_gfx_draw_round_rect; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { return nme_gfx_line_bitmap_fill; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { return nme_gfx_begin_bitmap_fill; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { return nme_gfx_line_gradient_fill; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { return nme_gfx_begin_gradient_fill; }
	}
	return super::__Field(inName);
}

Dynamic Graphics_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { TILE_RGB=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { TILE_SCALE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { TILE_ALPHA=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TILE_SMOOTH") ) { TILE_SMOOTH=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { TILE_ROTATION=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_clear") ) { nme_gfx_clear=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_ADD") ) { TILE_BLEND_ADD=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_arc_to") ) { nme_gfx_arc_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nme_gfx_move_to") ) { nme_gfx_move_to=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_to") ) { nme_gfx_line_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nme_gfx_end_fill") ) { nme_gfx_end_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_curve_to") ) { nme_gfx_curve_to=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"TILE_BLEND_NORMAL") ) { TILE_BLEND_NORMAL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_data") ) { nme_gfx_draw_data=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_rect") ) { nme_gfx_draw_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_fill") ) { nme_gfx_begin_fill=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_line_style") ) { nme_gfx_line_style=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_datum") ) { nme_gfx_draw_datum=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_tiles") ) { nme_gfx_draw_tiles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_points") ) { nme_gfx_draw_points=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_ellipse") ) { nme_gfx_draw_ellipse=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_triangles") ) { nme_gfx_draw_triangles=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nme_gfx_draw_round_rect") ) { nme_gfx_draw_round_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_bitmap_fill") ) { nme_gfx_line_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_bitmap_fill") ) { nme_gfx_begin_bitmap_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_gfx_line_gradient_fill") ) { nme_gfx_line_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_gfx_begin_gradient_fill") ) { nme_gfx_begin_gradient_fill=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Graphics_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("TILE_SMOOTH"),
	HX_CSTRING("TILE_BLEND_NORMAL"),
	HX_CSTRING("TILE_BLEND_ADD"),
	HX_CSTRING("RGBA"),
	HX_CSTRING("nme_gfx_clear"),
	HX_CSTRING("nme_gfx_begin_fill"),
	HX_CSTRING("nme_gfx_begin_bitmap_fill"),
	HX_CSTRING("nme_gfx_line_bitmap_fill"),
	HX_CSTRING("nme_gfx_begin_gradient_fill"),
	HX_CSTRING("nme_gfx_line_gradient_fill"),
	HX_CSTRING("nme_gfx_end_fill"),
	HX_CSTRING("nme_gfx_line_style"),
	HX_CSTRING("nme_gfx_move_to"),
	HX_CSTRING("nme_gfx_line_to"),
	HX_CSTRING("nme_gfx_curve_to"),
	HX_CSTRING("nme_gfx_arc_to"),
	HX_CSTRING("nme_gfx_draw_ellipse"),
	HX_CSTRING("nme_gfx_draw_data"),
	HX_CSTRING("nme_gfx_draw_datum"),
	HX_CSTRING("nme_gfx_draw_rect"),
	HX_CSTRING("nme_gfx_draw_tiles"),
	HX_CSTRING("nme_gfx_draw_points"),
	HX_CSTRING("nme_gfx_draw_round_rect"),
	HX_CSTRING("nme_gfx_draw_triangles"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("arcTo"),
	HX_CSTRING("beginBitmapFill"),
	HX_CSTRING("beginFill"),
	HX_CSTRING("beginGradientFill"),
	HX_CSTRING("clear"),
	HX_CSTRING("curveTo"),
	HX_CSTRING("drawCircle"),
	HX_CSTRING("drawEllipse"),
	HX_CSTRING("drawGraphicsData"),
	HX_CSTRING("drawGraphicsDatum"),
	HX_CSTRING("drawPoints"),
	HX_CSTRING("drawRect"),
	HX_CSTRING("drawRoundRect"),
	HX_CSTRING("drawTiles"),
	HX_CSTRING("drawTriangles"),
	HX_CSTRING("endFill"),
	HX_CSTRING("lineBitmapStyle"),
	HX_CSTRING("lineGradientStyle"),
	HX_CSTRING("lineStyle"),
	HX_CSTRING("lineTo"),
	HX_CSTRING("moveTo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_SMOOTH,"TILE_SMOOTH");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_NORMAL,"TILE_BLEND_NORMAL");
	HX_MARK_MEMBER_NAME(Graphics_obj::TILE_BLEND_ADD,"TILE_BLEND_ADD");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_clear,"nme_gfx_clear");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_fill,"nme_gfx_begin_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_bitmap_fill,"nme_gfx_begin_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_bitmap_fill,"nme_gfx_line_bitmap_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_begin_gradient_fill,"nme_gfx_begin_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_gradient_fill,"nme_gfx_line_gradient_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_end_fill,"nme_gfx_end_fill");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_style,"nme_gfx_line_style");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_move_to,"nme_gfx_move_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_line_to,"nme_gfx_line_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_curve_to,"nme_gfx_curve_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_arc_to,"nme_gfx_arc_to");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_ellipse,"nme_gfx_draw_ellipse");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_data,"nme_gfx_draw_data");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_datum,"nme_gfx_draw_datum");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_rect,"nme_gfx_draw_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_tiles,"nme_gfx_draw_tiles");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_points,"nme_gfx_draw_points");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_round_rect,"nme_gfx_draw_round_rect");
	HX_MARK_MEMBER_NAME(Graphics_obj::nme_gfx_draw_triangles,"nme_gfx_draw_triangles");
};

Class Graphics_obj::__mClass;

void Graphics_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Graphics"), hx::TCanCast< Graphics_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Graphics_obj::__boot()
{
	hx::Static(TILE_SCALE) = (int)1;
	hx::Static(TILE_ROTATION) = (int)2;
	hx::Static(TILE_RGB) = (int)4;
	hx::Static(TILE_ALPHA) = (int)8;
	hx::Static(TILE_SMOOTH) = (int)4096;
	hx::Static(TILE_BLEND_NORMAL) = (int)0;
	hx::Static(TILE_BLEND_ADD) = (int)65536;
	hx::Static(nme_gfx_clear) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_clear"),(int)1);
	hx::Static(nme_gfx_begin_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_fill"),(int)3);
	hx::Static(nme_gfx_begin_bitmap_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_line_bitmap_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_bitmap_fill"),(int)5);
	hx::Static(nme_gfx_begin_gradient_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_begin_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_line_gradient_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_gradient_fill"),(int)-1);
	hx::Static(nme_gfx_end_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_end_fill"),(int)1);
	hx::Static(nme_gfx_line_style) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_style"),(int)-1);
	hx::Static(nme_gfx_move_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_move_to"),(int)3);
	hx::Static(nme_gfx_line_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_line_to"),(int)3);
	hx::Static(nme_gfx_curve_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_curve_to"),(int)5);
	hx::Static(nme_gfx_arc_to) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_arc_to"),(int)5);
	hx::Static(nme_gfx_draw_ellipse) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_ellipse"),(int)5);
	hx::Static(nme_gfx_draw_data) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_data"),(int)2);
	hx::Static(nme_gfx_draw_datum) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_datum"),(int)2);
	hx::Static(nme_gfx_draw_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_rect"),(int)5);
	hx::Static(nme_gfx_draw_tiles) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_tiles"),(int)4);
	hx::Static(nme_gfx_draw_points) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_points"),(int)-1);
	hx::Static(nme_gfx_draw_round_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_round_rect"),(int)-1);
	hx::Static(nme_gfx_draw_triangles) = ::nme::Loader_obj::load(HX_CSTRING("nme_gfx_draw_triangles"),(int)-1);
}

} // end namespace nme
} // end namespace display
