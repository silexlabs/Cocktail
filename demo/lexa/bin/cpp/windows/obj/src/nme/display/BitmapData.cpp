#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_filters_BitmapFilter
#include <nme/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_nme_geom_ColorTransform
#include <nme/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
#ifndef INCLUDED_nme_utils_ByteArray
#include <nme/utils/ByteArray.h>
#endif
#ifndef INCLUDED_nme_utils_IDataInput
#include <nme/utils/IDataInput.h>
#endif
namespace nme{
namespace display{

Void BitmapData_obj::__construct(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA)
{
bool inTransparent = __o_inTransparent.Default(true);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",66)
	int fill_col;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",67)
	int fill_alpha;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",69)
	if (((inFillRGBA == null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",71)
		fill_col = (int)16777215;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",72)
		fill_alpha = (int)255;
	}
	else{
		struct _Function_2_1{
			inline static int Block( Dynamic &inFillRGBA){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",76)
				int v = inFillRGBA;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",76)
				return (int(v) & int((int)16777215));
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",76)
		fill_col = _Function_2_1::Block(inFillRGBA);
		struct _Function_2_2{
			inline static int Block( Dynamic &inFillRGBA){
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",77)
				int v = inFillRGBA;
				HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",77)
				return hx::UShr(v,(int)24);
			}
		};
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",77)
		fill_alpha = _Function_2_2::Block(inFillRGBA);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",80)
	if (((bool((inWidth < (int)1)) || bool((inHeight < (int)1))))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",81)
		this->nmeHandle = null();
	}
	else{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",86)
		int flags = ::nme::display::BitmapData_obj::HARDWARE;
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",88)
		if ((inTransparent)){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",89)
			hx::OrEq(flags,::nme::display::BitmapData_obj::TRANSPARENT);
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",91)
		this->nmeHandle = ::nme::display::BitmapData_obj::nme_bitmap_data_create(inWidth,inHeight,flags,fill_col,fill_alpha);
	}
}
;
	return null();
}

BitmapData_obj::~BitmapData_obj() { }

Dynamic BitmapData_obj::__CreateEmpty() { return  new BitmapData_obj; }
hx::ObjectPtr< BitmapData_obj > BitmapData_obj::__new(int inWidth,int inHeight,Dynamic __o_inTransparent,Dynamic inFillRGBA)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inWidth,inHeight,__o_inTransparent,inFillRGBA);
	return result;}

Dynamic BitmapData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

hx::Object *BitmapData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::nme::display::IBitmapDrawable_obj)) return operator ::nme::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

Void BitmapData_obj::applyFilter( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::filters::BitmapFilter filter){
{
		HX_SOURCE_PUSH("BitmapData_obj::applyFilter")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",105)
		::nme::display::BitmapData_obj::nme_bitmap_data_apply_filter(this->nmeHandle,sourceBitmapData->nmeHandle,sourceRect,destPoint,filter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapData_obj,applyFilter,(void))

Void BitmapData_obj::clear( int color){
{
		HX_SOURCE_PUSH("BitmapData_obj::clear")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",115)
		::nme::display::BitmapData_obj::nme_bitmap_data_clear(this->nmeHandle,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,clear,(void))

::nme::display::BitmapData BitmapData_obj::clone( ){
	HX_SOURCE_PUSH("BitmapData_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",126)
	::nme::display::BitmapData bm = ::nme::display::BitmapData_obj::__new((int)0,(int)0,null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",127)
	bm->nmeHandle = ::nme::display::BitmapData_obj::nme_bitmap_data_clone(this->nmeHandle);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",128)
	return bm;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,clone,return )

Void BitmapData_obj::colorTransform( ::nme::geom::Rectangle rect,::nme::geom::ColorTransform colorTransform){
{
		HX_SOURCE_PUSH("BitmapData_obj::colorTransform")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",138)
		::nme::display::BitmapData_obj::nme_bitmap_data_color_transform(this->nmeHandle,rect,colorTransform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,colorTransform,(void))

Void BitmapData_obj::copyChannel( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,int inSourceChannel,int inDestChannel){
{
		HX_SOURCE_PUSH("BitmapData_obj::copyChannel")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",152)
		::nme::display::BitmapData_obj::nme_bitmap_data_copy_channel(sourceBitmapData->nmeHandle,sourceRect,this->nmeHandle,destPoint,inSourceChannel,inDestChannel);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapData_obj,copyChannel,(void))

Void BitmapData_obj::copyPixels( ::nme::display::BitmapData sourceBitmapData,::nme::geom::Rectangle sourceRect,::nme::geom::Point destPoint,::nme::display::BitmapData alphaBitmapData,::nme::geom::Point alphaPoint,Dynamic __o_mergeAlpha){
bool mergeAlpha = __o_mergeAlpha.Default(false);
	HX_SOURCE_PUSH("BitmapData_obj::copyPixels");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",167)
		::nme::display::BitmapData_obj::nme_bitmap_data_copy(sourceBitmapData->nmeHandle,sourceRect,this->nmeHandle,destPoint,mergeAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,copyPixels,(void))

Void BitmapData_obj::createHardwareSurface( ){
{
		HX_SOURCE_PUSH("BitmapData_obj::createHardwareSurface")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",184)
		::nme::display::BitmapData_obj::nme_bitmap_data_create_hardware_surface(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,createHardwareSurface,(void))

Void BitmapData_obj::destroyHardwareSurface( ){
{
		HX_SOURCE_PUSH("BitmapData_obj::destroyHardwareSurface")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",190)
		::nme::display::BitmapData_obj::nme_bitmap_data_destroy_hardware_surface(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,destroyHardwareSurface,(void))

Void BitmapData_obj::dispose( ){
{
		HX_SOURCE_PUSH("BitmapData_obj::dispose")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",197)
		this->nmeHandle = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dispose,(void))

Void BitmapData_obj::draw( ::nme::display::IBitmapDrawable source,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,Dynamic __o_smoothing){
bool smoothing = __o_smoothing.Default(false);
	HX_SOURCE_PUSH("BitmapData_obj::draw");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",203)
		source->nmeDrawToSurface(this->nmeHandle,matrix,colorTransform,blendMode,clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,draw,(void))

Void BitmapData_obj::dumpBits( ){
{
		HX_SOURCE_PUSH("BitmapData_obj::dumpBits")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",209)
		::nme::display::BitmapData_obj::nme_bitmap_data_dump_bits(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dumpBits,(void))

::nme::utils::ByteArray BitmapData_obj::encode( ::String inFormat,Dynamic __o_inQuality){
double inQuality = __o_inQuality.Default(0.9);
	HX_SOURCE_PUSH("BitmapData_obj::encode");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",215)
		return ::nme::display::BitmapData_obj::nme_bitmap_data_encode(this->nmeHandle,inFormat,inQuality);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,encode,return )

Void BitmapData_obj::fillRect( ::nme::geom::Rectangle rect,int inColour){
{
		HX_SOURCE_PUSH("BitmapData_obj::fillRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",242)
		int a = hx::UShr(inColour,(int)24);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",243)
		int c = (int(inColour) & int((int)16777215));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",244)
		::nme::display::BitmapData_obj::nme_bitmap_data_fill(this->nmeHandle,rect,c,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,fillRect,(void))

Void BitmapData_obj::fillRectEx( ::nme::geom::Rectangle rect,int inColour,Dynamic __o_inAlpha){
int inAlpha = __o_inAlpha.Default(255);
	HX_SOURCE_PUSH("BitmapData_obj::fillRectEx");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",249)
		::nme::display::BitmapData_obj::nme_bitmap_data_fill(this->nmeHandle,rect,inColour,inAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,fillRectEx,(void))

::nme::geom::Rectangle BitmapData_obj::generateFilterRect( ::nme::geom::Rectangle sourceRect,::nme::filters::BitmapFilter filter){
	HX_SOURCE_PUSH("BitmapData_obj::generateFilterRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",256)
	::nme::geom::Rectangle result = ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",257)
	::nme::display::BitmapData_obj::nme_bitmap_data_generate_filter_rect(sourceRect,filter,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",258)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,generateFilterRect,return )

::nme::geom::Rectangle BitmapData_obj::getColorBoundsRect( int mask,int color,Dynamic __o_findColor){
bool findColor = __o_findColor.Default(true);
	HX_SOURCE_PUSH("BitmapData_obj::getColorBoundsRect");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",264)
		::nme::geom::Rectangle result = ::nme::geom::Rectangle_obj::__new(null(),null(),null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",265)
		::nme::display::BitmapData_obj::nme_bitmap_data_get_color_bounds_rect(this->nmeHandle,mask,color,findColor,result);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",266)
		return result;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,getColorBoundsRect,return )

int BitmapData_obj::getPixel( int x,int y){
	HX_SOURCE_PUSH("BitmapData_obj::getPixel")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",271)
	return ::nme::display::BitmapData_obj::nme_bitmap_data_get_pixel(this->nmeHandle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel,return )

int BitmapData_obj::getPixel32( int x,int y){
	HX_SOURCE_PUSH("BitmapData_obj::getPixel32")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",277)
	return ::nme::display::BitmapData_obj::nme_bitmap_data_get_pixel32(this->nmeHandle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel32,return )

::nme::utils::ByteArray BitmapData_obj::getPixels( ::nme::geom::Rectangle rect){
	HX_SOURCE_PUSH("BitmapData_obj::getPixels")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",288)
	::nme::utils::ByteArray result = ::nme::display::BitmapData_obj::nme_bitmap_data_get_pixels(this->nmeHandle,rect);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",290)
	if (((result != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",291)
		result->position = result->length;
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",293)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getPixels,return )

Array< int > BitmapData_obj::getVector( ::nme::geom::Rectangle rect){
	HX_SOURCE_PUSH("BitmapData_obj::getVector")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",299)
	int pixels = ::Std_obj::_int((rect->width * rect->height));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",301)
	if (((pixels < (int)1))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",302)
		return Array_obj< int >::__new();
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",304)
	Array< int > result = Array_obj< int >::__new();
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",305)
	result[(pixels - (int)1)] = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",308)
	::nme::display::BitmapData_obj::nme_bitmap_data_get_array(this->nmeHandle,rect,result);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",316)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getVector,return )

Void BitmapData_obj::lock( ){
{
		HX_SOURCE_PUSH("BitmapData_obj::lock")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,lock,(void))

Void BitmapData_obj::nmeDrawToSurface( Dynamic inSurface,::nme::geom::Matrix matrix,::nme::geom::ColorTransform colorTransform,::String blendMode,::nme::geom::Rectangle clipRect,bool smoothing){
{
		HX_SOURCE_PUSH("BitmapData_obj::nmeDrawToSurface")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",374)
		::nme::display::BitmapData_obj::nme_render_surface_to_surface(inSurface,this->nmeHandle,matrix,colorTransform,blendMode,clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,nmeDrawToSurface,(void))

Void BitmapData_obj::scroll( int inDX,int inDY){
{
		HX_SOURCE_PUSH("BitmapData_obj::scroll")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",381)
		::nme::display::BitmapData_obj::nme_bitmap_data_scroll(this->nmeHandle,inDX,inDY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,scroll,(void))

Void BitmapData_obj::setFlags( int inFlags){
{
		HX_SOURCE_PUSH("BitmapData_obj::setFlags")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",387)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_flags(this->nmeHandle,inFlags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFlags,(void))

Void BitmapData_obj::setPixel( int inX,int inY,int inColour){
{
		HX_SOURCE_PUSH("BitmapData_obj::setPixel")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",394)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_pixel(this->nmeHandle,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel,(void))

Void BitmapData_obj::setPixel32( int inX,int inY,int inColour){
{
		HX_SOURCE_PUSH("BitmapData_obj::setPixel32")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",400)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_pixel32(this->nmeHandle,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel32,(void))

Void BitmapData_obj::setPixels( ::nme::geom::Rectangle rect,::nme::utils::ByteArray pixels){
{
		HX_SOURCE_PUSH("BitmapData_obj::setPixels")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",411)
		int size = ::Std_obj::_int(((rect->width * rect->height) * (int)4));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",412)
		pixels->checkData(::Std_obj::_int(size));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",413)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_bytes(this->nmeHandle,rect,pixels,pixels->position);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",414)
		hx::AddEq(pixels->position,size);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setPixels,(void))

Void BitmapData_obj::setVector( ::nme::geom::Rectangle rect,Array< int > inPixels){
{
		HX_SOURCE_PUSH("BitmapData_obj::setVector")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",420)
		int count = ::Std_obj::_int((rect->width * rect->height));
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",421)
		if (((inPixels->length < count))){
			HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",422)
			return null();
		}
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",425)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_array(this->nmeHandle,rect,inPixels);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setVector,(void))

Void BitmapData_obj::unlock( ::nme::geom::Rectangle changeRect){
{
		HX_SOURCE_PUSH("BitmapData_obj::unlock")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,unlock,(void))

Void BitmapData_obj::setFormat( int format){
{
		HX_SOURCE_PUSH("BitmapData_obj::setFormat")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",441)
		::nme::display::BitmapData_obj::nme_bitmap_data_set_format(this->nmeHandle,format);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFormat,(void))

::nme::geom::Rectangle BitmapData_obj::nmeGetRect( ){
	HX_SOURCE_PUSH("BitmapData_obj::nmeGetRect")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",450)
	return ::nme::geom::Rectangle_obj::__new((int)0,(int)0,this->nmeGetWidth(),this->nmeGetHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,nmeGetRect,return )

int BitmapData_obj::nmeGetWidth( ){
	HX_SOURCE_PUSH("BitmapData_obj::nmeGetWidth")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",451)
	return ::nme::display::BitmapData_obj::nme_bitmap_data_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,nmeGetWidth,return )

int BitmapData_obj::nmeGetHeight( ){
	HX_SOURCE_PUSH("BitmapData_obj::nmeGetHeight")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",452)
	return ::nme::display::BitmapData_obj::nme_bitmap_data_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,nmeGetHeight,return )

bool BitmapData_obj::nmeGetTransparent( ){
	HX_SOURCE_PUSH("BitmapData_obj::nmeGetTransparent")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",453)
	return ::nme::display::BitmapData_obj::nme_bitmap_data_get_transparent(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,nmeGetTransparent,return )

int BitmapData_obj::CLEAR;

int BitmapData_obj::BLACK;

int BitmapData_obj::WHITE;

int BitmapData_obj::RED;

int BitmapData_obj::GREEN;

int BitmapData_obj::BLUE;

::String BitmapData_obj::PNG;

::String BitmapData_obj::JPG;

int BitmapData_obj::TRANSPARENT;

int BitmapData_obj::HARDWARE;

int BitmapData_obj::FORMAT_8888;

int BitmapData_obj::FORMAT_4444;

int BitmapData_obj::FORMAT_565;

int BitmapData_obj::createColor( int inRGB,Dynamic __o_inAlpha){
int inAlpha = __o_inAlpha.Default(255);
	HX_SOURCE_PUSH("BitmapData_obj::createColor");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",173)
		return (int(inRGB) | int((int(inAlpha) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,createColor,return )

int BitmapData_obj::extractAlpha( int v){
	HX_SOURCE_PUSH("BitmapData_obj::extractAlpha")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",221)
	return hx::UShr(v,(int)24);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractAlpha,return )

int BitmapData_obj::extractColor( int v){
	HX_SOURCE_PUSH("BitmapData_obj::extractColor")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",231)
	return (int(v) & int((int)16777215));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractColor,return )

::nme::display::BitmapData BitmapData_obj::load( ::String inFilename,Dynamic __o_format){
int format = __o_format.Default(0);
	HX_SOURCE_PUSH("BitmapData_obj::load");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",328)
		::nme::display::BitmapData result = ::nme::display::BitmapData_obj::__new((int)0,(int)0,null(),null());
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",329)
		result->nmeHandle = ::nme::display::BitmapData_obj::nme_bitmap_data_load(inFilename,format);
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",330)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,load,return )

::nme::display::BitmapData BitmapData_obj::loadFromBytes( ::nme::utils::ByteArray inBytes,::nme::utils::ByteArray inRawAlpha){
	HX_SOURCE_PUSH("BitmapData_obj::loadFromBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",344)
	::nme::display::BitmapData result = ::nme::display::BitmapData_obj::__new((int)0,(int)0,null(),null());
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",345)
	result->nmeHandle = ::nme::display::BitmapData_obj::nme_bitmap_data_from_bytes(inBytes,inRawAlpha);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",346)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,loadFromBytes,return )

::nme::display::BitmapData BitmapData_obj::loadFromHaxeBytes( ::haxe::io::Bytes inBytes,::haxe::io::Bytes inRawAlpha){
	HX_SOURCE_PUSH("BitmapData_obj::loadFromHaxeBytes")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/BitmapData.hx",359)
	return ::nme::display::BitmapData_obj::loadFromBytes(::nme::utils::ByteArray_obj::fromBytes(inBytes),(  (((inRawAlpha == null()))) ? ::nme::utils::ByteArray(null()) : ::nme::utils::ByteArray(::nme::utils::ByteArray_obj::fromBytes(inRawAlpha)) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,loadFromHaxeBytes,return )

Dynamic BitmapData_obj::nme_bitmap_data_create;

Dynamic BitmapData_obj::nme_bitmap_data_load;

Dynamic BitmapData_obj::nme_bitmap_data_from_bytes;

Dynamic BitmapData_obj::nme_bitmap_data_clear;

Dynamic BitmapData_obj::nme_bitmap_data_clone;

Dynamic BitmapData_obj::nme_bitmap_data_apply_filter;

Dynamic BitmapData_obj::nme_bitmap_data_color_transform;

Dynamic BitmapData_obj::nme_bitmap_data_copy;

Dynamic BitmapData_obj::nme_bitmap_data_copy_channel;

Dynamic BitmapData_obj::nme_bitmap_data_fill;

Dynamic BitmapData_obj::nme_bitmap_data_get_pixels;

Dynamic BitmapData_obj::nme_bitmap_data_get_pixel;

Dynamic BitmapData_obj::nme_bitmap_data_get_pixel32;

Dynamic BitmapData_obj::nme_bitmap_data_get_pixel_rgba;

Dynamic BitmapData_obj::nme_bitmap_data_get_array;

Dynamic BitmapData_obj::nme_bitmap_data_get_color_bounds_rect;

Dynamic BitmapData_obj::nme_bitmap_data_scroll;

Dynamic BitmapData_obj::nme_bitmap_data_set_pixel;

Dynamic BitmapData_obj::nme_bitmap_data_set_pixel32;

Dynamic BitmapData_obj::nme_bitmap_data_set_pixel_rgba;

Dynamic BitmapData_obj::nme_bitmap_data_set_bytes;

Dynamic BitmapData_obj::nme_bitmap_data_set_format;

Dynamic BitmapData_obj::nme_bitmap_data_set_array;

Dynamic BitmapData_obj::nme_bitmap_data_create_hardware_surface;

Dynamic BitmapData_obj::nme_bitmap_data_destroy_hardware_surface;

Dynamic BitmapData_obj::nme_bitmap_data_generate_filter_rect;

Dynamic BitmapData_obj::nme_render_surface_to_surface;

Dynamic BitmapData_obj::nme_bitmap_data_height;

Dynamic BitmapData_obj::nme_bitmap_data_width;

Dynamic BitmapData_obj::nme_bitmap_data_get_transparent;

Dynamic BitmapData_obj::nme_bitmap_data_set_flags;

Dynamic BitmapData_obj::nme_bitmap_data_encode;

Dynamic BitmapData_obj::nme_bitmap_data_dump_bits;


BitmapData_obj::BitmapData_obj()
{
}

void BitmapData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapData);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(rect,"rect");
	HX_MARK_MEMBER_NAME(transparent,"transparent");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic BitmapData_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { return RED; }
		if (HX_FIELD_EQ(inName,"PNG") ) { return PNG; }
		if (HX_FIELD_EQ(inName,"JPG") ) { return JPG; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { return BLUE; }
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"rect") ) { return nmeGetRect(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"lock") ) { return lock_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CLEAR") ) { return CLEAR; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { return BLACK; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { return WHITE; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { return GREEN; }
		if (HX_FIELD_EQ(inName,"width") ) { return nmeGetWidth(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return nmeGetHeight(); }
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll_dyn(); }
		if (HX_FIELD_EQ(inName,"unlock") ) { return unlock_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { return HARDWARE; }
		if (HX_FIELD_EQ(inName,"dumpBits") ) { return dumpBits_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRect") ) { return fillRect_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel") ) { return getPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"setFlags") ) { return setFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel") ) { return setPixel_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"getPixels") ) { return getPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"getVector") ) { return getVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixels") ) { return setPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"setVector") ) { return setVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setFormat") ) { return setFormat_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FORMAT_565") ) { return FORMAT_565; }
		if (HX_FIELD_EQ(inName,"copyPixels") ) { return copyPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRectEx") ) { return fillRectEx_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel32") ) { return getPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel32") ) { return setPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetRect") ) { return nmeGetRect_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TRANSPARENT") ) { return TRANSPARENT; }
		if (HX_FIELD_EQ(inName,"FORMAT_8888") ) { return FORMAT_8888; }
		if (HX_FIELD_EQ(inName,"FORMAT_4444") ) { return FORMAT_4444; }
		if (HX_FIELD_EQ(inName,"createColor") ) { return createColor_dyn(); }
		if (HX_FIELD_EQ(inName,"transparent") ) { return nmeGetTransparent(); }
		if (HX_FIELD_EQ(inName,"applyFilter") ) { return applyFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"copyChannel") ) { return copyChannel_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetWidth") ) { return nmeGetWidth_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"extractAlpha") ) { return extractAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"extractColor") ) { return extractColor_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetHeight") ) { return nmeGetHeight_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"loadFromBytes") ) { return loadFromBytes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return colorTransform_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeDrawToSurface") ) { return nmeDrawToSurface_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"loadFromHaxeBytes") ) { return loadFromHaxeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetTransparent") ) { return nmeGetTransparent_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"generateFilterRect") ) { return generateFilterRect_dyn(); }
		if (HX_FIELD_EQ(inName,"getColorBoundsRect") ) { return getColorBoundsRect_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_load") ) { return nme_bitmap_data_load; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_copy") ) { return nme_bitmap_data_copy; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_fill") ) { return nme_bitmap_data_fill; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_clear") ) { return nme_bitmap_data_clear; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_clone") ) { return nme_bitmap_data_clone; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_width") ) { return nme_bitmap_data_width; }
		if (HX_FIELD_EQ(inName,"createHardwareSurface") ) { return createHardwareSurface_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_create") ) { return nme_bitmap_data_create; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_scroll") ) { return nme_bitmap_data_scroll; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_height") ) { return nme_bitmap_data_height; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_encode") ) { return nme_bitmap_data_encode; }
		if (HX_FIELD_EQ(inName,"destroyHardwareSurface") ) { return destroyHardwareSurface_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel") ) { return nme_bitmap_data_get_pixel; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_array") ) { return nme_bitmap_data_get_array; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel") ) { return nme_bitmap_data_set_pixel; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_bytes") ) { return nme_bitmap_data_set_bytes; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_array") ) { return nme_bitmap_data_set_array; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_flags") ) { return nme_bitmap_data_set_flags; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_dump_bits") ) { return nme_bitmap_data_dump_bits; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_from_bytes") ) { return nme_bitmap_data_from_bytes; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixels") ) { return nme_bitmap_data_get_pixels; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_format") ) { return nme_bitmap_data_set_format; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel32") ) { return nme_bitmap_data_get_pixel32; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel32") ) { return nme_bitmap_data_set_pixel32; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_apply_filter") ) { return nme_bitmap_data_apply_filter; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_copy_channel") ) { return nme_bitmap_data_copy_channel; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_render_surface_to_surface") ) { return nme_render_surface_to_surface; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel_rgba") ) { return nme_bitmap_data_get_pixel_rgba; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel_rgba") ) { return nme_bitmap_data_set_pixel_rgba; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_color_transform") ) { return nme_bitmap_data_color_transform; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_transparent") ) { return nme_bitmap_data_get_transparent; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_generate_filter_rect") ) { return nme_bitmap_data_generate_filter_rect; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_color_bounds_rect") ) { return nme_bitmap_data_get_color_bounds_rect; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_create_hardware_surface") ) { return nme_bitmap_data_create_hardware_surface; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_destroy_hardware_surface") ) { return nme_bitmap_data_destroy_hardware_surface; }
	}
	return super::__Field(inName);
}

Dynamic BitmapData_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { RED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PNG") ) { PNG=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"JPG") ) { JPG=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { BLUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rect") ) { rect=inValue.Cast< ::nme::geom::Rectangle >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CLEAR") ) { CLEAR=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { BLACK=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { WHITE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { GREEN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { HARDWARE=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FORMAT_565") ) { FORMAT_565=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TRANSPARENT") ) { TRANSPARENT=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FORMAT_8888") ) { FORMAT_8888=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FORMAT_4444") ) { FORMAT_4444=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transparent") ) { transparent=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_load") ) { nme_bitmap_data_load=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_copy") ) { nme_bitmap_data_copy=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_fill") ) { nme_bitmap_data_fill=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_clear") ) { nme_bitmap_data_clear=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_clone") ) { nme_bitmap_data_clone=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_width") ) { nme_bitmap_data_width=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_create") ) { nme_bitmap_data_create=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_scroll") ) { nme_bitmap_data_scroll=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_height") ) { nme_bitmap_data_height=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_encode") ) { nme_bitmap_data_encode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel") ) { nme_bitmap_data_get_pixel=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_array") ) { nme_bitmap_data_get_array=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel") ) { nme_bitmap_data_set_pixel=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_bytes") ) { nme_bitmap_data_set_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_array") ) { nme_bitmap_data_set_array=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_flags") ) { nme_bitmap_data_set_flags=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_dump_bits") ) { nme_bitmap_data_dump_bits=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_from_bytes") ) { nme_bitmap_data_from_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixels") ) { nme_bitmap_data_get_pixels=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_format") ) { nme_bitmap_data_set_format=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel32") ) { nme_bitmap_data_get_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel32") ) { nme_bitmap_data_set_pixel32=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_apply_filter") ) { nme_bitmap_data_apply_filter=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_copy_channel") ) { nme_bitmap_data_copy_channel=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_render_surface_to_surface") ) { nme_render_surface_to_surface=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_pixel_rgba") ) { nme_bitmap_data_get_pixel_rgba=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_set_pixel_rgba") ) { nme_bitmap_data_set_pixel_rgba=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_color_transform") ) { nme_bitmap_data_color_transform=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_transparent") ) { nme_bitmap_data_get_transparent=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_generate_filter_rect") ) { nme_bitmap_data_generate_filter_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_get_color_bounds_rect") ) { nme_bitmap_data_get_color_bounds_rect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_create_hardware_surface") ) { nme_bitmap_data_create_hardware_surface=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_destroy_hardware_surface") ) { nme_bitmap_data_destroy_hardware_surface=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("rect"));
	outFields->push(HX_CSTRING("transparent"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CLEAR"),
	HX_CSTRING("BLACK"),
	HX_CSTRING("WHITE"),
	HX_CSTRING("RED"),
	HX_CSTRING("GREEN"),
	HX_CSTRING("BLUE"),
	HX_CSTRING("PNG"),
	HX_CSTRING("JPG"),
	HX_CSTRING("TRANSPARENT"),
	HX_CSTRING("HARDWARE"),
	HX_CSTRING("FORMAT_8888"),
	HX_CSTRING("FORMAT_4444"),
	HX_CSTRING("FORMAT_565"),
	HX_CSTRING("createColor"),
	HX_CSTRING("extractAlpha"),
	HX_CSTRING("extractColor"),
	HX_CSTRING("load"),
	HX_CSTRING("loadFromBytes"),
	HX_CSTRING("loadFromHaxeBytes"),
	HX_CSTRING("nme_bitmap_data_create"),
	HX_CSTRING("nme_bitmap_data_load"),
	HX_CSTRING("nme_bitmap_data_from_bytes"),
	HX_CSTRING("nme_bitmap_data_clear"),
	HX_CSTRING("nme_bitmap_data_clone"),
	HX_CSTRING("nme_bitmap_data_apply_filter"),
	HX_CSTRING("nme_bitmap_data_color_transform"),
	HX_CSTRING("nme_bitmap_data_copy"),
	HX_CSTRING("nme_bitmap_data_copy_channel"),
	HX_CSTRING("nme_bitmap_data_fill"),
	HX_CSTRING("nme_bitmap_data_get_pixels"),
	HX_CSTRING("nme_bitmap_data_get_pixel"),
	HX_CSTRING("nme_bitmap_data_get_pixel32"),
	HX_CSTRING("nme_bitmap_data_get_pixel_rgba"),
	HX_CSTRING("nme_bitmap_data_get_array"),
	HX_CSTRING("nme_bitmap_data_get_color_bounds_rect"),
	HX_CSTRING("nme_bitmap_data_scroll"),
	HX_CSTRING("nme_bitmap_data_set_pixel"),
	HX_CSTRING("nme_bitmap_data_set_pixel32"),
	HX_CSTRING("nme_bitmap_data_set_pixel_rgba"),
	HX_CSTRING("nme_bitmap_data_set_bytes"),
	HX_CSTRING("nme_bitmap_data_set_format"),
	HX_CSTRING("nme_bitmap_data_set_array"),
	HX_CSTRING("nme_bitmap_data_create_hardware_surface"),
	HX_CSTRING("nme_bitmap_data_destroy_hardware_surface"),
	HX_CSTRING("nme_bitmap_data_generate_filter_rect"),
	HX_CSTRING("nme_render_surface_to_surface"),
	HX_CSTRING("nme_bitmap_data_height"),
	HX_CSTRING("nme_bitmap_data_width"),
	HX_CSTRING("nme_bitmap_data_get_transparent"),
	HX_CSTRING("nme_bitmap_data_set_flags"),
	HX_CSTRING("nme_bitmap_data_encode"),
	HX_CSTRING("nme_bitmap_data_dump_bits"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("height"),
	HX_CSTRING("rect"),
	HX_CSTRING("transparent"),
	HX_CSTRING("width"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("applyFilter"),
	HX_CSTRING("clear"),
	HX_CSTRING("clone"),
	HX_CSTRING("colorTransform"),
	HX_CSTRING("copyChannel"),
	HX_CSTRING("copyPixels"),
	HX_CSTRING("createHardwareSurface"),
	HX_CSTRING("destroyHardwareSurface"),
	HX_CSTRING("dispose"),
	HX_CSTRING("draw"),
	HX_CSTRING("dumpBits"),
	HX_CSTRING("encode"),
	HX_CSTRING("fillRect"),
	HX_CSTRING("fillRectEx"),
	HX_CSTRING("generateFilterRect"),
	HX_CSTRING("getColorBoundsRect"),
	HX_CSTRING("getPixel"),
	HX_CSTRING("getPixel32"),
	HX_CSTRING("getPixels"),
	HX_CSTRING("getVector"),
	HX_CSTRING("lock"),
	HX_CSTRING("nmeDrawToSurface"),
	HX_CSTRING("scroll"),
	HX_CSTRING("setFlags"),
	HX_CSTRING("setPixel"),
	HX_CSTRING("setPixel32"),
	HX_CSTRING("setPixels"),
	HX_CSTRING("setVector"),
	HX_CSTRING("unlock"),
	HX_CSTRING("setFormat"),
	HX_CSTRING("nmeGetRect"),
	HX_CSTRING("nmeGetWidth"),
	HX_CSTRING("nmeGetHeight"),
	HX_CSTRING("nmeGetTransparent"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapData_obj::CLEAR,"CLEAR");
	HX_MARK_MEMBER_NAME(BitmapData_obj::BLACK,"BLACK");
	HX_MARK_MEMBER_NAME(BitmapData_obj::WHITE,"WHITE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::RED,"RED");
	HX_MARK_MEMBER_NAME(BitmapData_obj::GREEN,"GREEN");
	HX_MARK_MEMBER_NAME(BitmapData_obj::BLUE,"BLUE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::PNG,"PNG");
	HX_MARK_MEMBER_NAME(BitmapData_obj::JPG,"JPG");
	HX_MARK_MEMBER_NAME(BitmapData_obj::TRANSPARENT,"TRANSPARENT");
	HX_MARK_MEMBER_NAME(BitmapData_obj::HARDWARE,"HARDWARE");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_8888,"FORMAT_8888");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_4444,"FORMAT_4444");
	HX_MARK_MEMBER_NAME(BitmapData_obj::FORMAT_565,"FORMAT_565");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_create,"nme_bitmap_data_create");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_load,"nme_bitmap_data_load");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_from_bytes,"nme_bitmap_data_from_bytes");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_clear,"nme_bitmap_data_clear");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_clone,"nme_bitmap_data_clone");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_apply_filter,"nme_bitmap_data_apply_filter");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_color_transform,"nme_bitmap_data_color_transform");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_copy,"nme_bitmap_data_copy");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_copy_channel,"nme_bitmap_data_copy_channel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_fill,"nme_bitmap_data_fill");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixels,"nme_bitmap_data_get_pixels");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel,"nme_bitmap_data_get_pixel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel32,"nme_bitmap_data_get_pixel32");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel_rgba,"nme_bitmap_data_get_pixel_rgba");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_array,"nme_bitmap_data_get_array");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_color_bounds_rect,"nme_bitmap_data_get_color_bounds_rect");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_scroll,"nme_bitmap_data_scroll");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel,"nme_bitmap_data_set_pixel");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel32,"nme_bitmap_data_set_pixel32");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel_rgba,"nme_bitmap_data_set_pixel_rgba");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_bytes,"nme_bitmap_data_set_bytes");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_format,"nme_bitmap_data_set_format");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_array,"nme_bitmap_data_set_array");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_create_hardware_surface,"nme_bitmap_data_create_hardware_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_destroy_hardware_surface,"nme_bitmap_data_destroy_hardware_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_generate_filter_rect,"nme_bitmap_data_generate_filter_rect");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_render_surface_to_surface,"nme_render_surface_to_surface");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_height,"nme_bitmap_data_height");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_width,"nme_bitmap_data_width");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_transparent,"nme_bitmap_data_get_transparent");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_flags,"nme_bitmap_data_set_flags");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_encode,"nme_bitmap_data_encode");
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_dump_bits,"nme_bitmap_data_dump_bits");
};

Class BitmapData_obj::__mClass;

void BitmapData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.BitmapData"), hx::TCanCast< BitmapData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapData_obj::__boot()
{
	hx::Static(CLEAR) = (int)0;
	hx::Static(BLACK) = (int)-16777216;
	hx::Static(WHITE) = (int)-16777216;
	hx::Static(RED) = (int)-65536;
	hx::Static(GREEN) = (int)-16711936;
	hx::Static(BLUE) = (int)-16776961;
	hx::Static(PNG) = HX_CSTRING("png");
	hx::Static(JPG) = HX_CSTRING("jpg");
	hx::Static(TRANSPARENT) = (int)1;
	hx::Static(HARDWARE) = (int)2;
	hx::Static(FORMAT_8888) = (int)0;
	hx::Static(FORMAT_4444) = (int)1;
	hx::Static(FORMAT_565) = (int)2;
	hx::Static(nme_bitmap_data_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_create"),(int)5);
	hx::Static(nme_bitmap_data_load) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_load"),(int)2);
	hx::Static(nme_bitmap_data_from_bytes) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_from_bytes"),(int)2);
	hx::Static(nme_bitmap_data_clear) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_clear"),(int)2);
	hx::Static(nme_bitmap_data_clone) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_clone"),(int)1);
	hx::Static(nme_bitmap_data_apply_filter) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_apply_filter"),(int)5);
	hx::Static(nme_bitmap_data_color_transform) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_color_transform"),(int)3);
	hx::Static(nme_bitmap_data_copy) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_copy"),(int)5);
	hx::Static(nme_bitmap_data_copy_channel) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_copy_channel"),(int)-1);
	hx::Static(nme_bitmap_data_fill) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_fill"),(int)4);
	hx::Static(nme_bitmap_data_get_pixels) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixels"),(int)2);
	hx::Static(nme_bitmap_data_get_pixel) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel"),(int)3);
	hx::Static(nme_bitmap_data_get_pixel32) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel32"),(int)3);
	hx::Static(nme_bitmap_data_get_pixel_rgba) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel_rgba"),(int)3);
	hx::Static(nme_bitmap_data_get_array) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_array"),(int)3);
	hx::Static(nme_bitmap_data_get_color_bounds_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_color_bounds_rect"),(int)5);
	hx::Static(nme_bitmap_data_scroll) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_scroll"),(int)3);
	hx::Static(nme_bitmap_data_set_pixel) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel"),(int)4);
	hx::Static(nme_bitmap_data_set_pixel32) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel32"),(int)4);
	hx::Static(nme_bitmap_data_set_pixel_rgba) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel_rgba"),(int)4);
	hx::Static(nme_bitmap_data_set_bytes) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_bytes"),(int)4);
	hx::Static(nme_bitmap_data_set_format) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_format"),(int)2);
	hx::Static(nme_bitmap_data_set_array) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_array"),(int)3);
	hx::Static(nme_bitmap_data_create_hardware_surface) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_create_hardware_surface"),(int)1);
	hx::Static(nme_bitmap_data_destroy_hardware_surface) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_destroy_hardware_surface"),(int)1);
	hx::Static(nme_bitmap_data_generate_filter_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_generate_filter_rect"),(int)3);
	hx::Static(nme_render_surface_to_surface) = ::nme::Loader_obj::load(HX_CSTRING("nme_render_surface_to_surface"),(int)-1);
	hx::Static(nme_bitmap_data_height) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_height"),(int)1);
	hx::Static(nme_bitmap_data_width) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_width"),(int)1);
	hx::Static(nme_bitmap_data_get_transparent) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_transparent"),(int)1);
	hx::Static(nme_bitmap_data_set_flags) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_flags"),(int)1);
	hx::Static(nme_bitmap_data_encode) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_encode"),(int)3);
	hx::Static(nme_bitmap_data_dump_bits) = ::nme::Loader_obj::load(HX_CSTRING("nme_bitmap_data_dump_bits"),(int)1);
}

} // end namespace nme
} // end namespace display
