#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_native_Loader
#include <native/Loader.h>
#endif
#ifndef INCLUDED_native_display_BitmapData
#include <native/display/BitmapData.h>
#endif
#ifndef INCLUDED_native_display_BlendMode
#include <native/display/BlendMode.h>
#endif
#ifndef INCLUDED_native_display_IBitmapDrawable
#include <native/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_native_display_OptimizedPerlin
#include <native/display/OptimizedPerlin.h>
#endif
#ifndef INCLUDED_native_filters_BitmapFilter
#include <native/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_native_geom_ColorTransform
#include <native/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_native_geom_Matrix
#include <native/geom/Matrix.h>
#endif
#ifndef INCLUDED_native_geom_Point
#include <native/geom/Point.h>
#endif
#ifndef INCLUDED_native_geom_Rectangle
#include <native/geom/Rectangle.h>
#endif
#ifndef INCLUDED_native_utils_ByteArray
#include <native/utils/ByteArray.h>
#endif
#ifndef INCLUDED_native_utils_IDataInput
#include <native/utils/IDataInput.h>
#endif
#ifndef INCLUDED_native_utils_IMemoryRange
#include <native/utils/IMemoryRange.h>
#endif
namespace native{
namespace display{

Void BitmapData_obj::__construct(int inWidth,int inHeight,hx::Null< bool >  __o_inTransparent,Dynamic inFillRGBA,Dynamic inGPUMode)
{
HX_STACK_PUSH("BitmapData::new","native/display/BitmapData.hx",41);
bool inTransparent = __o_inTransparent.Default(true);
{
	HX_STACK_LINE(43)
	int fill_col;		HX_STACK_VAR(fill_col,"fill_col");
	HX_STACK_LINE(44)
	int fill_alpha;		HX_STACK_VAR(fill_alpha,"fill_alpha");
	HX_STACK_LINE(46)
	if (((inFillRGBA == null()))){
		HX_STACK_LINE(48)
		fill_col = (int)16777215;
		HX_STACK_LINE(49)
		fill_alpha = (int)255;
	}
	else{
		struct _Function_2_1{
			inline static int Block( Dynamic &inFillRGBA){
				HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",53);
				{
					HX_STACK_LINE(53)
					int v = inFillRGBA;		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(53)
					return (int(v) & int((int)16777215));
				}
				return null();
			}
		};
		HX_STACK_LINE(53)
		fill_col = _Function_2_1::Block(inFillRGBA);
		struct _Function_2_2{
			inline static int Block( Dynamic &inFillRGBA){
				HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",54);
				{
					HX_STACK_LINE(54)
					int v = inFillRGBA;		HX_STACK_VAR(v,"v");
					HX_STACK_LINE(54)
					return hx::UShr(v,(int)24);
				}
				return null();
			}
		};
		HX_STACK_LINE(54)
		fill_alpha = _Function_2_2::Block(inFillRGBA);
	}
	HX_STACK_LINE(58)
	if (((bool((inWidth < (int)1)) || bool((inHeight < (int)1))))){
		HX_STACK_LINE(58)
		this->nmeHandle = null();
	}
	else{
		HX_STACK_LINE(64)
		int flags = ::native::display::BitmapData_obj::HARDWARE;		HX_STACK_VAR(flags,"flags");
		HX_STACK_LINE(66)
		if ((inTransparent)){
			HX_STACK_LINE(66)
			hx::OrEq(flags,::native::display::BitmapData_obj::TRANSPARENT);
		}
		HX_STACK_LINE(68)
		this->nmeHandle = ::native::display::BitmapData_obj::nme_bitmap_data_create(inWidth,inHeight,flags,fill_col,fill_alpha,inGPUMode);
	}
}
;
	return null();
}

BitmapData_obj::~BitmapData_obj() { }

Dynamic BitmapData_obj::__CreateEmpty() { return  new BitmapData_obj; }
hx::ObjectPtr< BitmapData_obj > BitmapData_obj::__new(int inWidth,int inHeight,hx::Null< bool >  __o_inTransparent,Dynamic inFillRGBA,Dynamic inGPUMode)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inWidth,inHeight,__o_inTransparent,inFillRGBA,inGPUMode);
	return result;}

Dynamic BitmapData_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapData_obj > result = new BitmapData_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

hx::Object *BitmapData_obj::__ToInterface(const type_info &inType) {
	if (inType==typeid( ::native::display::IBitmapDrawable_obj)) return operator ::native::display::IBitmapDrawable_obj *();
	return super::__ToInterface(inType);
}

bool BitmapData_obj::get_transparent( ){
	HX_STACK_PUSH("BitmapData::get_transparent","native/display/BitmapData.hx",442);
	HX_STACK_THIS(this);
	HX_STACK_LINE(442)
	return ::native::display::BitmapData_obj::nme_bitmap_data_get_transparent(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_transparent,return )

int BitmapData_obj::get_height( ){
	HX_STACK_PUSH("BitmapData::get_height","native/display/BitmapData.hx",441);
	HX_STACK_THIS(this);
	HX_STACK_LINE(441)
	return ::native::display::BitmapData_obj::nme_bitmap_data_height(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_height,return )

int BitmapData_obj::get_width( ){
	HX_STACK_PUSH("BitmapData::get_width","native/display/BitmapData.hx",440);
	HX_STACK_THIS(this);
	HX_STACK_LINE(440)
	return ::native::display::BitmapData_obj::nme_bitmap_data_width(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_width,return )

::native::geom::Rectangle BitmapData_obj::get_rect( ){
	HX_STACK_PUSH("BitmapData::get_rect","native/display/BitmapData.hx",439);
	HX_STACK_THIS(this);
	HX_STACK_LINE(439)
	return ::native::geom::Rectangle_obj::__new((int)0,(int)0,this->get_width(),this->get_height());
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,get_rect,return )

Void BitmapData_obj::noise( int randomSeed,hx::Null< int >  __o_low,hx::Null< int >  __o_high,hx::Null< int >  __o_channelOptions,hx::Null< bool >  __o_grayScale){
int low = __o_low.Default(0);
int high = __o_high.Default(255);
int channelOptions = __o_channelOptions.Default(7);
bool grayScale = __o_grayScale.Default(false);
	HX_STACK_PUSH("BitmapData::noise","native/display/BitmapData.hx",425);
	HX_STACK_THIS(this);
	HX_STACK_ARG(randomSeed,"randomSeed");
	HX_STACK_ARG(low,"low");
	HX_STACK_ARG(high,"high");
	HX_STACK_ARG(channelOptions,"channelOptions");
	HX_STACK_ARG(grayScale,"grayScale");
{
		HX_STACK_LINE(425)
		::native::display::BitmapData_obj::nme_bitmap_data_noise(this->nmeHandle,randomSeed,low,high,channelOptions,grayScale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapData_obj,noise,(void))

Void BitmapData_obj::setFormat( int format){
{
		HX_STACK_PUSH("BitmapData::setFormat","native/display/BitmapData.hx",418);
		HX_STACK_THIS(this);
		HX_STACK_ARG(format,"format");
		HX_STACK_LINE(418)
		::native::display::BitmapData_obj::nme_bitmap_data_set_format(this->nmeHandle,format);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFormat,(void))

Void BitmapData_obj::unlock( ::native::geom::Rectangle changeRect){
{
		HX_STACK_PUSH("BitmapData::unlock","native/display/BitmapData.hx",411);
		HX_STACK_THIS(this);
		HX_STACK_ARG(changeRect,"changeRect");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,unlock,(void))

Void BitmapData_obj::setVector( ::native::geom::Rectangle rect,Array< int > inPixels){
{
		HX_STACK_PUSH("BitmapData::setVector","native/display/BitmapData.hx",393);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(inPixels,"inPixels");
		HX_STACK_LINE(395)
		int count = ::Std_obj::_int((rect->width * rect->height));		HX_STACK_VAR(count,"count");
		HX_STACK_LINE(397)
		if (((inPixels->length < count))){
			HX_STACK_LINE(397)
			return null();
		}
		HX_STACK_LINE(400)
		::native::display::BitmapData_obj::nme_bitmap_data_set_array(this->nmeHandle,rect,inPixels);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setVector,(void))

Void BitmapData_obj::setPixels( ::native::geom::Rectangle rect,::native::utils::ByteArray pixels){
{
		HX_STACK_PUSH("BitmapData::setPixels","native/display/BitmapData.hx",383);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(pixels,"pixels");
		HX_STACK_LINE(385)
		int size = ::Std_obj::_int(((rect->width * rect->height) * (int)4));		HX_STACK_VAR(size,"size");
		HX_STACK_LINE(386)
		pixels->checkData(::Std_obj::_int(size));
		HX_STACK_LINE(387)
		::native::display::BitmapData_obj::nme_bitmap_data_set_bytes(this->nmeHandle,rect,pixels,pixels->position);
		HX_STACK_LINE(388)
		hx::AddEq(pixels->position,size);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,setPixels,(void))

Void BitmapData_obj::setPixel32( int inX,int inY,int inColour){
{
		HX_STACK_PUSH("BitmapData::setPixel32","native/display/BitmapData.hx",372);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inX,"inX");
		HX_STACK_ARG(inY,"inY");
		HX_STACK_ARG(inColour,"inColour");
		HX_STACK_LINE(372)
		::native::display::BitmapData_obj::nme_bitmap_data_set_pixel32(this->nmeHandle,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel32,(void))

Void BitmapData_obj::setPixel( int inX,int inY,int inColour){
{
		HX_STACK_PUSH("BitmapData::setPixel","native/display/BitmapData.hx",365);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inX,"inX");
		HX_STACK_ARG(inY,"inY");
		HX_STACK_ARG(inColour,"inColour");
		HX_STACK_LINE(365)
		::native::display::BitmapData_obj::nme_bitmap_data_set_pixel(this->nmeHandle,inX,inY,inColour);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,setPixel,(void))

Void BitmapData_obj::setFlags( int inFlags){
{
		HX_STACK_PUSH("BitmapData::setFlags","native/display/BitmapData.hx",357);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inFlags,"inFlags");
		HX_STACK_LINE(357)
		::native::display::BitmapData_obj::nme_bitmap_data_set_flags(this->nmeHandle,inFlags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,setFlags,(void))

Void BitmapData_obj::scroll( int inDX,int inDY){
{
		HX_STACK_PUSH("BitmapData::scroll","native/display/BitmapData.hx",350);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inDX,"inDX");
		HX_STACK_ARG(inDY,"inDY");
		HX_STACK_LINE(350)
		::native::display::BitmapData_obj::nme_bitmap_data_scroll(this->nmeHandle,inDX,inDY);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,scroll,(void))

Void BitmapData_obj::perlinNoise( Float baseX,Float baseY,int numOctaves,int randomSeed,bool stitch,bool fractalNoise,hx::Null< int >  __o_channelOptions,hx::Null< bool >  __o_grayScale,Array< ::native::geom::Point > offsets){
int channelOptions = __o_channelOptions.Default(7);
bool grayScale = __o_grayScale.Default(false);
	HX_STACK_PUSH("BitmapData::perlinNoise","native/display/BitmapData.hx",342);
	HX_STACK_THIS(this);
	HX_STACK_ARG(baseX,"baseX");
	HX_STACK_ARG(baseY,"baseY");
	HX_STACK_ARG(numOctaves,"numOctaves");
	HX_STACK_ARG(randomSeed,"randomSeed");
	HX_STACK_ARG(stitch,"stitch");
	HX_STACK_ARG(fractalNoise,"fractalNoise");
	HX_STACK_ARG(channelOptions,"channelOptions");
	HX_STACK_ARG(grayScale,"grayScale");
	HX_STACK_ARG(offsets,"offsets");
{
		HX_STACK_LINE(344)
		::native::display::OptimizedPerlin perlin = ::native::display::OptimizedPerlin_obj::__new(randomSeed,numOctaves,null());		HX_STACK_VAR(perlin,"perlin");
		HX_STACK_LINE(345)
		perlin->fill(hx::ObjectPtr<OBJ_>(this),baseX,baseY,(int)0,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(BitmapData_obj,perlinNoise,(void))

Void BitmapData_obj::nmeDrawToSurface( Dynamic inSurface,::native::geom::Matrix matrix,::native::geom::ColorTransform colorTransform,::String blendMode,::native::geom::Rectangle clipRect,bool smoothing){
{
		HX_STACK_PUSH("BitmapData::nmeDrawToSurface","native/display/BitmapData.hx",334);
		HX_STACK_THIS(this);
		HX_STACK_ARG(inSurface,"inSurface");
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_ARG(clipRect,"clipRect");
		HX_STACK_ARG(smoothing,"smoothing");
		HX_STACK_LINE(334)
		::native::display::BitmapData_obj::nme_render_surface_to_surface(inSurface,this->nmeHandle,matrix,colorTransform,blendMode,clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,nmeDrawToSurface,(void))

Void BitmapData_obj::lock( ){
{
		HX_STACK_PUSH("BitmapData::lock","native/display/BitmapData.hx",327);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,lock,(void))

Array< int > BitmapData_obj::getVector( ::native::geom::Rectangle rect){
	HX_STACK_PUSH("BitmapData::getVector","native/display/BitmapData.hx",280);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(282)
	int pixels = ::Std_obj::_int((rect->width * rect->height));		HX_STACK_VAR(pixels,"pixels");
	HX_STACK_LINE(284)
	if (((pixels < (int)1))){
		HX_STACK_LINE(284)
		return Array_obj< int >::__new();
	}
	HX_STACK_LINE(286)
	Array< int > result = Array_obj< int >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(287)
	result[(pixels - (int)1)] = (int)0;
	HX_STACK_LINE(290)
	::native::display::BitmapData_obj::nme_bitmap_data_get_array(this->nmeHandle,rect,result);
	HX_STACK_LINE(297)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getVector,return )

::native::utils::ByteArray BitmapData_obj::getPixels( ::native::geom::Rectangle rect){
	HX_STACK_PUSH("BitmapData::getPixels","native/display/BitmapData.hx",248);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(250)
	::native::utils::ByteArray result = ::native::display::BitmapData_obj::nme_bitmap_data_get_pixels(this->nmeHandle,rect);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(251)
	if (((result != null()))){
		HX_STACK_LINE(251)
		result->position = result->length;
	}
	HX_STACK_LINE(252)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getPixels,return )

int BitmapData_obj::getPixel32( int x,int y){
	HX_STACK_PUSH("BitmapData::getPixel32","native/display/BitmapData.hx",237);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(237)
	return ::native::display::BitmapData_obj::nme_bitmap_data_get_pixel32(this->nmeHandle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel32,return )

int BitmapData_obj::getPixel( int x,int y){
	HX_STACK_PUSH("BitmapData::getPixel","native/display/BitmapData.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(230)
	return ::native::display::BitmapData_obj::nme_bitmap_data_get_pixel(this->nmeHandle,x,y);
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,getPixel,return )

::native::geom::Rectangle BitmapData_obj::getColorBoundsRect( int mask,int color,hx::Null< bool >  __o_findColor){
bool findColor = __o_findColor.Default(true);
	HX_STACK_PUSH("BitmapData::getColorBoundsRect","native/display/BitmapData.hx",221);
	HX_STACK_THIS(this);
	HX_STACK_ARG(mask,"mask");
	HX_STACK_ARG(color,"color");
	HX_STACK_ARG(findColor,"findColor");
{
		HX_STACK_LINE(223)
		::native::geom::Rectangle result = ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(224)
		::native::display::BitmapData_obj::nme_bitmap_data_get_color_bounds_rect(this->nmeHandle,mask,color,findColor,result);
		HX_STACK_LINE(225)
		return result;
	}
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,getColorBoundsRect,return )

::native::geom::Rectangle BitmapData_obj::generateFilterRect( ::native::geom::Rectangle sourceRect,::native::filters::BitmapFilter filter){
	HX_STACK_PUSH("BitmapData::generateFilterRect","native/display/BitmapData.hx",212);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceRect,"sourceRect");
	HX_STACK_ARG(filter,"filter");
	HX_STACK_LINE(214)
	::native::geom::Rectangle result = ::native::geom::Rectangle_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(215)
	::native::display::BitmapData_obj::nme_bitmap_data_generate_filter_rect(sourceRect,filter,result);
	HX_STACK_LINE(216)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,generateFilterRect,return )

Void BitmapData_obj::fillRectEx( ::native::geom::Rectangle rect,int inColour,hx::Null< int >  __o_inAlpha){
int inAlpha = __o_inAlpha.Default(255);
	HX_STACK_PUSH("BitmapData::fillRectEx","native/display/BitmapData.hx",205);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_ARG(inColour,"inColour");
	HX_STACK_ARG(inAlpha,"inAlpha");
{
		HX_STACK_LINE(205)
		::native::display::BitmapData_obj::nme_bitmap_data_fill(this->nmeHandle,rect,inColour,inAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BitmapData_obj,fillRectEx,(void))

Void BitmapData_obj::fillRect( ::native::geom::Rectangle rect,int inColour){
{
		HX_STACK_PUSH("BitmapData::fillRect","native/display/BitmapData.hx",196);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(inColour,"inColour");
		HX_STACK_LINE(198)
		int a = hx::UShr(inColour,(int)24);		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(199)
		int c = (int(inColour) & int((int)16777215));		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(200)
		::native::display::BitmapData_obj::nme_bitmap_data_fill(this->nmeHandle,rect,c,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,fillRect,(void))

::native::utils::ByteArray BitmapData_obj::encode( ::String inFormat,hx::Null< Float >  __o_inQuality){
Float inQuality = __o_inQuality.Default(0.9);
	HX_STACK_PUSH("BitmapData::encode","native/display/BitmapData.hx",167);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inFormat,"inFormat");
	HX_STACK_ARG(inQuality,"inQuality");
{
		HX_STACK_LINE(167)
		return ::native::display::BitmapData_obj::nme_bitmap_data_encode(this->nmeHandle,inFormat,inQuality);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,encode,return )

Void BitmapData_obj::dumpBits( ){
{
		HX_STACK_PUSH("BitmapData::dumpBits","native/display/BitmapData.hx",160);
		HX_STACK_THIS(this);
		HX_STACK_LINE(160)
		::native::display::BitmapData_obj::nme_bitmap_data_dump_bits(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dumpBits,(void))

Void BitmapData_obj::draw( ::native::display::IBitmapDrawable source,::native::geom::Matrix matrix,::native::geom::ColorTransform colorTransform,::native::display::BlendMode blendMode,::native::geom::Rectangle clipRect,hx::Null< bool >  __o_smoothing){
bool smoothing = __o_smoothing.Default(false);
	HX_STACK_PUSH("BitmapData::draw","native/display/BitmapData.hx",153);
	HX_STACK_THIS(this);
	HX_STACK_ARG(source,"source");
	HX_STACK_ARG(matrix,"matrix");
	HX_STACK_ARG(colorTransform,"colorTransform");
	HX_STACK_ARG(blendMode,"blendMode");
	HX_STACK_ARG(clipRect,"clipRect");
	HX_STACK_ARG(smoothing,"smoothing");
{
		HX_STACK_LINE(153)
		source->nmeDrawToSurface(this->nmeHandle,matrix,colorTransform,::Std_obj::string(blendMode),clipRect,smoothing);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,draw,(void))

Void BitmapData_obj::dispose( ){
{
		HX_STACK_PUSH("BitmapData::dispose","native/display/BitmapData.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_LINE(146)
		this->nmeHandle = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,dispose,(void))

Void BitmapData_obj::destroyHardwareSurface( ){
{
		HX_STACK_PUSH("BitmapData::destroyHardwareSurface","native/display/BitmapData.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_LINE(138)
		::native::display::BitmapData_obj::nme_bitmap_data_destroy_hardware_surface(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,destroyHardwareSurface,(void))

Void BitmapData_obj::createHardwareSurface( ){
{
		HX_STACK_PUSH("BitmapData::createHardwareSurface","native/display/BitmapData.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_LINE(131)
		::native::display::BitmapData_obj::nme_bitmap_data_create_hardware_surface(this->nmeHandle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,createHardwareSurface,(void))

Void BitmapData_obj::copyPixels( ::native::display::BitmapData sourceBitmapData,::native::geom::Rectangle sourceRect,::native::geom::Point destPoint,::native::display::BitmapData alphaBitmapData,::native::geom::Point alphaPoint,hx::Null< bool >  __o_mergeAlpha){
bool mergeAlpha = __o_mergeAlpha.Default(false);
	HX_STACK_PUSH("BitmapData::copyPixels","native/display/BitmapData.hx",112);
	HX_STACK_THIS(this);
	HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
	HX_STACK_ARG(sourceRect,"sourceRect");
	HX_STACK_ARG(destPoint,"destPoint");
	HX_STACK_ARG(alphaBitmapData,"alphaBitmapData");
	HX_STACK_ARG(alphaPoint,"alphaPoint");
	HX_STACK_ARG(mergeAlpha,"mergeAlpha");
{
		HX_STACK_LINE(112)
		::native::display::BitmapData_obj::nme_bitmap_data_copy(sourceBitmapData->nmeHandle,sourceRect,this->nmeHandle,destPoint,mergeAlpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(BitmapData_obj,copyPixels,(void))

Void BitmapData_obj::copyChannel( ::native::display::BitmapData sourceBitmapData,::native::geom::Rectangle sourceRect,::native::geom::Point destPoint,int inSourceChannel,int inDestChannel){
{
		HX_STACK_PUSH("BitmapData::copyChannel","native/display/BitmapData.hx",105);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(inSourceChannel,"inSourceChannel");
		HX_STACK_ARG(inDestChannel,"inDestChannel");
		HX_STACK_LINE(105)
		::native::display::BitmapData_obj::nme_bitmap_data_copy_channel(sourceBitmapData->nmeHandle,sourceRect,this->nmeHandle,destPoint,inSourceChannel,inDestChannel);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(BitmapData_obj,copyChannel,(void))

Void BitmapData_obj::colorTransform( ::native::geom::Rectangle rect,::native::geom::ColorTransform colorTransform){
{
		HX_STACK_PUSH("BitmapData::colorTransform","native/display/BitmapData.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_ARG(colorTransform,"colorTransform");
		HX_STACK_LINE(98)
		::native::display::BitmapData_obj::nme_bitmap_data_color_transform(this->nmeHandle,rect,colorTransform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,colorTransform,(void))

::native::display::BitmapData BitmapData_obj::clone( ){
	HX_STACK_PUSH("BitmapData::clone","native/display/BitmapData.hx",89);
	HX_STACK_THIS(this);
	HX_STACK_LINE(91)
	::native::display::BitmapData bm = ::native::display::BitmapData_obj::__new((int)0,(int)0,null(),null(),null());		HX_STACK_VAR(bm,"bm");
	HX_STACK_LINE(92)
	bm->nmeHandle = ::native::display::BitmapData_obj::nme_bitmap_data_clone(this->nmeHandle);
	HX_STACK_LINE(93)
	return bm;
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapData_obj,clone,return )

Void BitmapData_obj::clear( int color){
{
		HX_STACK_PUSH("BitmapData::clear","native/display/BitmapData.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(color,"color");
		HX_STACK_LINE(82)
		::native::display::BitmapData_obj::nme_bitmap_data_clear(this->nmeHandle,color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,clear,(void))

Void BitmapData_obj::applyFilter( ::native::display::BitmapData sourceBitmapData,::native::geom::Rectangle sourceRect,::native::geom::Point destPoint,::native::filters::BitmapFilter filter){
{
		HX_STACK_PUSH("BitmapData::applyFilter","native/display/BitmapData.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceBitmapData,"sourceBitmapData");
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_ARG(destPoint,"destPoint");
		HX_STACK_ARG(filter,"filter");
		HX_STACK_LINE(75)
		::native::display::BitmapData_obj::nme_bitmap_data_apply_filter(this->nmeHandle,sourceBitmapData->nmeHandle,sourceRect,destPoint,filter);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BitmapData_obj,applyFilter,(void))

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

int BitmapData_obj::createColor( int inRGB,hx::Null< int >  __o_inAlpha){
int inAlpha = __o_inAlpha.Default(255);
	HX_STACK_PUSH("BitmapData::createColor","native/display/BitmapData.hx",119);
	HX_STACK_ARG(inRGB,"inRGB");
	HX_STACK_ARG(inAlpha,"inAlpha");
{
		HX_STACK_LINE(119)
		return (int(inRGB) | int((int(inAlpha) << int((int)24))));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,createColor,return )

int BitmapData_obj::extractAlpha( int v){
	HX_STACK_PUSH("BitmapData::extractAlpha","native/display/BitmapData.hx",174);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(174)
	return hx::UShr(v,(int)24);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractAlpha,return )

int BitmapData_obj::extractColor( int v){
	HX_STACK_PUSH("BitmapData::extractColor","native/display/BitmapData.hx",185);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(185)
	return (int(v) & int((int)16777215));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,extractColor,return )

::native::utils::ByteArray BitmapData_obj::getRGBAPixels( ::native::display::BitmapData bitmapData){
	HX_STACK_PUSH("BitmapData::getRGBAPixels","native/display/BitmapData.hx",257);
	HX_STACK_ARG(bitmapData,"bitmapData");
	HX_STACK_LINE(259)
	::native::utils::ByteArray p = bitmapData->getPixels(::native::geom::Rectangle_obj::__new((int)0,(int)0,bitmapData->get_width(),bitmapData->get_height()));		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(260)
	int num = (bitmapData->get_width() * bitmapData->get_height());		HX_STACK_VAR(num,"num");
	HX_STACK_LINE(262)
	{
		HX_STACK_LINE(262)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(262)
		while(((_g < num))){
			HX_STACK_LINE(262)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(264)
			int alpha = p->__get((i * (int)4));		HX_STACK_VAR(alpha,"alpha");
			HX_STACK_LINE(265)
			int red = p->__get(((i * (int)4) + (int)1));		HX_STACK_VAR(red,"red");
			HX_STACK_LINE(266)
			int green = p->__get(((i * (int)4) + (int)2));		HX_STACK_VAR(green,"green");
			HX_STACK_LINE(267)
			int blue = p->__get(((i * (int)4) + (int)3));		HX_STACK_VAR(blue,"blue");
			HX_STACK_LINE(269)
			hx::__ArrayImplRef(p,(i * (int)4)) = red;
			HX_STACK_LINE(270)
			hx::__ArrayImplRef(p,((i * (int)4) + (int)1)) = green;
			HX_STACK_LINE(271)
			hx::__ArrayImplRef(p,((i * (int)4) + (int)2)) = blue;
			HX_STACK_LINE(272)
			hx::__ArrayImplRef(p,((i * (int)4) + (int)3)) = alpha;
		}
	}
	HX_STACK_LINE(276)
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BitmapData_obj,getRGBAPixels,return )

::native::display::BitmapData BitmapData_obj::load( ::String inFilename,hx::Null< int >  __o_format){
int format = __o_format.Default(0);
	HX_STACK_PUSH("BitmapData::load","native/display/BitmapData.hx",302);
	HX_STACK_ARG(inFilename,"inFilename");
	HX_STACK_ARG(format,"format");
{
		HX_STACK_LINE(304)
		::native::display::BitmapData result = ::native::display::BitmapData_obj::__new((int)0,(int)0,null(),null(),null());		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(305)
		result->nmeHandle = ::native::display::BitmapData_obj::nme_bitmap_data_load(inFilename,format);
		HX_STACK_LINE(306)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,load,return )

::native::display::BitmapData BitmapData_obj::loadFromBytes( ::native::utils::ByteArray inBytes,::native::utils::ByteArray inRawAlpha){
	HX_STACK_PUSH("BitmapData::loadFromBytes","native/display/BitmapData.hx",311);
	HX_STACK_ARG(inBytes,"inBytes");
	HX_STACK_ARG(inRawAlpha,"inRawAlpha");
	HX_STACK_LINE(313)
	::native::display::BitmapData result = ::native::display::BitmapData_obj::__new((int)0,(int)0,null(),null(),null());		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(314)
	result->nmeHandle = ::native::display::BitmapData_obj::nme_bitmap_data_from_bytes(inBytes,inRawAlpha);
	HX_STACK_LINE(315)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(BitmapData_obj,loadFromBytes,return )

::native::display::BitmapData BitmapData_obj::loadFromHaxeBytes( ::haxe::io::Bytes inBytes,::haxe::io::Bytes inRawAlpha){
	HX_STACK_PUSH("BitmapData::loadFromHaxeBytes","native/display/BitmapData.hx",320);
	HX_STACK_ARG(inBytes,"inBytes");
	HX_STACK_ARG(inRawAlpha,"inRawAlpha");
	HX_STACK_LINE(320)
	return ::native::display::BitmapData_obj::loadFromBytes(::native::utils::ByteArray_obj::fromBytes(inBytes),(  (((inRawAlpha == null()))) ? ::native::utils::ByteArray(null()) : ::native::utils::ByteArray(::native::utils::ByteArray_obj::fromBytes(inRawAlpha)) ));
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

Dynamic BitmapData_obj::nme_bitmap_data_noise;


BitmapData_obj::BitmapData_obj()
{
}

void BitmapData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapData);
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(transparent,"transparent");
	HX_MARK_MEMBER_NAME(rect,"rect");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void BitmapData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(transparent,"transparent");
	HX_VISIT_MEMBER_NAME(rect,"rect");
	HX_VISIT_MEMBER_NAME(height,"height");
}

Dynamic BitmapData_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"lock") ) { return lock_dyn(); }
		if (HX_FIELD_EQ(inName,"draw") ) { return draw_dyn(); }
		if (HX_FIELD_EQ(inName,"rect") ) { return inCallProp ? get_rect() : rect; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"CLEAR") ) { return CLEAR; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { return BLACK; }
		if (HX_FIELD_EQ(inName,"WHITE") ) { return WHITE; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { return GREEN; }
		if (HX_FIELD_EQ(inName,"noise") ) { return noise_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"unlock") ) { return unlock_dyn(); }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll_dyn(); }
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HARDWARE") ) { return HARDWARE; }
		if (HX_FIELD_EQ(inName,"get_rect") ) { return get_rect_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel") ) { return setPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"setFlags") ) { return setFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel") ) { return getPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRect") ) { return fillRect_dyn(); }
		if (HX_FIELD_EQ(inName,"dumpBits") ) { return dumpBits_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"setFormat") ) { return setFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"setVector") ) { return setVector_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixels") ) { return setPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"getVector") ) { return getVector_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixels") ) { return getPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FORMAT_565") ) { return FORMAT_565; }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"setPixel32") ) { return setPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixel32") ) { return getPixel32_dyn(); }
		if (HX_FIELD_EQ(inName,"fillRectEx") ) { return fillRectEx_dyn(); }
		if (HX_FIELD_EQ(inName,"copyPixels") ) { return copyPixels_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TRANSPARENT") ) { return TRANSPARENT; }
		if (HX_FIELD_EQ(inName,"FORMAT_8888") ) { return FORMAT_8888; }
		if (HX_FIELD_EQ(inName,"FORMAT_4444") ) { return FORMAT_4444; }
		if (HX_FIELD_EQ(inName,"createColor") ) { return createColor_dyn(); }
		if (HX_FIELD_EQ(inName,"perlinNoise") ) { return perlinNoise_dyn(); }
		if (HX_FIELD_EQ(inName,"copyChannel") ) { return copyChannel_dyn(); }
		if (HX_FIELD_EQ(inName,"applyFilter") ) { return applyFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"transparent") ) { return inCallProp ? get_transparent() : transparent; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"extractAlpha") ) { return extractAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"extractColor") ) { return extractColor_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getRGBAPixels") ) { return getRGBAPixels_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFromBytes") ) { return loadFromBytes_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorTransform") ) { return colorTransform_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_transparent") ) { return get_transparent_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeDrawToSurface") ) { return nmeDrawToSurface_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"loadFromHaxeBytes") ) { return loadFromHaxeBytes_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getColorBoundsRect") ) { return getColorBoundsRect_dyn(); }
		if (HX_FIELD_EQ(inName,"generateFilterRect") ) { return generateFilterRect_dyn(); }
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
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_noise") ) { return nme_bitmap_data_noise; }
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
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapData_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { RED=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PNG") ) { PNG=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"JPG") ) { JPG=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"BLUE") ) { BLUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rect") ) { rect=inValue.Cast< ::native::geom::Rectangle >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"nme_bitmap_data_noise") ) { nme_bitmap_data_noise=inValue.Cast< Dynamic >(); return inValue; }
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
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeHandle"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("transparent"));
	outFields->push(HX_CSTRING("rect"));
	outFields->push(HX_CSTRING("height"));
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
	HX_CSTRING("getRGBAPixels"),
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
	HX_CSTRING("nme_bitmap_data_noise"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_transparent"),
	HX_CSTRING("get_height"),
	HX_CSTRING("get_width"),
	HX_CSTRING("get_rect"),
	HX_CSTRING("noise"),
	HX_CSTRING("setFormat"),
	HX_CSTRING("unlock"),
	HX_CSTRING("setVector"),
	HX_CSTRING("setPixels"),
	HX_CSTRING("setPixel32"),
	HX_CSTRING("setPixel"),
	HX_CSTRING("setFlags"),
	HX_CSTRING("scroll"),
	HX_CSTRING("perlinNoise"),
	HX_CSTRING("nmeDrawToSurface"),
	HX_CSTRING("lock"),
	HX_CSTRING("getVector"),
	HX_CSTRING("getPixels"),
	HX_CSTRING("getPixel32"),
	HX_CSTRING("getPixel"),
	HX_CSTRING("getColorBoundsRect"),
	HX_CSTRING("generateFilterRect"),
	HX_CSTRING("fillRectEx"),
	HX_CSTRING("fillRect"),
	HX_CSTRING("encode"),
	HX_CSTRING("dumpBits"),
	HX_CSTRING("draw"),
	HX_CSTRING("dispose"),
	HX_CSTRING("destroyHardwareSurface"),
	HX_CSTRING("createHardwareSurface"),
	HX_CSTRING("copyPixels"),
	HX_CSTRING("copyChannel"),
	HX_CSTRING("colorTransform"),
	HX_CSTRING("clone"),
	HX_CSTRING("clear"),
	HX_CSTRING("applyFilter"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("width"),
	HX_CSTRING("transparent"),
	HX_CSTRING("rect"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapData_obj::__mClass,"__mClass");
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
	HX_MARK_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_noise,"nme_bitmap_data_noise");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapData_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::CLEAR,"CLEAR");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::BLACK,"BLACK");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::WHITE,"WHITE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::RED,"RED");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::GREEN,"GREEN");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::BLUE,"BLUE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::PNG,"PNG");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::JPG,"JPG");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::TRANSPARENT,"TRANSPARENT");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::HARDWARE,"HARDWARE");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_8888,"FORMAT_8888");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_4444,"FORMAT_4444");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::FORMAT_565,"FORMAT_565");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_create,"nme_bitmap_data_create");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_load,"nme_bitmap_data_load");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_from_bytes,"nme_bitmap_data_from_bytes");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_clear,"nme_bitmap_data_clear");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_clone,"nme_bitmap_data_clone");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_apply_filter,"nme_bitmap_data_apply_filter");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_color_transform,"nme_bitmap_data_color_transform");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_copy,"nme_bitmap_data_copy");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_copy_channel,"nme_bitmap_data_copy_channel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_fill,"nme_bitmap_data_fill");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixels,"nme_bitmap_data_get_pixels");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel,"nme_bitmap_data_get_pixel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel32,"nme_bitmap_data_get_pixel32");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_pixel_rgba,"nme_bitmap_data_get_pixel_rgba");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_array,"nme_bitmap_data_get_array");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_color_bounds_rect,"nme_bitmap_data_get_color_bounds_rect");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_scroll,"nme_bitmap_data_scroll");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel,"nme_bitmap_data_set_pixel");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel32,"nme_bitmap_data_set_pixel32");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_pixel_rgba,"nme_bitmap_data_set_pixel_rgba");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_bytes,"nme_bitmap_data_set_bytes");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_format,"nme_bitmap_data_set_format");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_array,"nme_bitmap_data_set_array");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_create_hardware_surface,"nme_bitmap_data_create_hardware_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_destroy_hardware_surface,"nme_bitmap_data_destroy_hardware_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_generate_filter_rect,"nme_bitmap_data_generate_filter_rect");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_render_surface_to_surface,"nme_render_surface_to_surface");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_height,"nme_bitmap_data_height");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_width,"nme_bitmap_data_width");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_get_transparent,"nme_bitmap_data_get_transparent");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_set_flags,"nme_bitmap_data_set_flags");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_encode,"nme_bitmap_data_encode");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_dump_bits,"nme_bitmap_data_dump_bits");
	HX_VISIT_MEMBER_NAME(BitmapData_obj::nme_bitmap_data_noise,"nme_bitmap_data_noise");
};

Class BitmapData_obj::__mClass;

void BitmapData_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.display.BitmapData"), hx::TCanCast< BitmapData_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BitmapData_obj::__boot()
{
	CLEAR= (int)0;
struct _Function_0_1{
	inline static int Block( ){
		HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",19);
		{
			HX_STACK_LINE(19)
			int inAlpha = (int)255;		HX_STACK_VAR(inAlpha,"inAlpha");
			HX_STACK_LINE(19)
			return (int((int)0) | int((int(inAlpha) << int((int)24))));
		}
		return null();
	}
};
	BLACK= _Function_0_1::Block();
struct _Function_0_2{
	inline static int Block( ){
		HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",20);
		{
			HX_STACK_LINE(20)
			int inAlpha = (int)255;		HX_STACK_VAR(inAlpha,"inAlpha");
			HX_STACK_LINE(20)
			return (int((int)0) | int((int(inAlpha) << int((int)24))));
		}
		return null();
	}
};
	WHITE= _Function_0_2::Block();
struct _Function_0_3{
	inline static int Block( ){
		HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",21);
		{
			HX_STACK_LINE(21)
			int inAlpha = (int)255;		HX_STACK_VAR(inAlpha,"inAlpha");
			HX_STACK_LINE(21)
			return (int((int)16711680) | int((int(inAlpha) << int((int)24))));
		}
		return null();
	}
};
	RED= _Function_0_3::Block();
struct _Function_0_4{
	inline static int Block( ){
		HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",22);
		{
			HX_STACK_LINE(22)
			int inAlpha = (int)255;		HX_STACK_VAR(inAlpha,"inAlpha");
			HX_STACK_LINE(22)
			return (int((int)65280) | int((int(inAlpha) << int((int)24))));
		}
		return null();
	}
};
	GREEN= _Function_0_4::Block();
struct _Function_0_5{
	inline static int Block( ){
		HX_STACK_PUSH("*::closure","native/display/BitmapData.hx",23);
		{
			HX_STACK_LINE(23)
			int inAlpha = (int)255;		HX_STACK_VAR(inAlpha,"inAlpha");
			HX_STACK_LINE(23)
			return (int((int)255) | int((int(inAlpha) << int((int)24))));
		}
		return null();
	}
};
	BLUE= _Function_0_5::Block();
	PNG= HX_CSTRING("png");
	JPG= HX_CSTRING("jpg");
	TRANSPARENT= (int)1;
	HARDWARE= (int)2;
	FORMAT_8888= (int)0;
	FORMAT_4444= (int)1;
	FORMAT_565= (int)2;
	nme_bitmap_data_create= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_create"),(int)-1);
	nme_bitmap_data_load= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_load"),(int)2);
	nme_bitmap_data_from_bytes= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_from_bytes"),(int)2);
	nme_bitmap_data_clear= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_clear"),(int)2);
	nme_bitmap_data_clone= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_clone"),(int)1);
	nme_bitmap_data_apply_filter= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_apply_filter"),(int)5);
	nme_bitmap_data_color_transform= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_color_transform"),(int)3);
	nme_bitmap_data_copy= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_copy"),(int)5);
	nme_bitmap_data_copy_channel= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_copy_channel"),(int)-1);
	nme_bitmap_data_fill= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_fill"),(int)4);
	nme_bitmap_data_get_pixels= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixels"),(int)2);
	nme_bitmap_data_get_pixel= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel"),(int)3);
	nme_bitmap_data_get_pixel32= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel32"),(int)3);
	nme_bitmap_data_get_pixel_rgba= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_pixel_rgba"),(int)3);
	nme_bitmap_data_get_array= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_array"),(int)3);
	nme_bitmap_data_get_color_bounds_rect= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_color_bounds_rect"),(int)5);
	nme_bitmap_data_scroll= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_scroll"),(int)3);
	nme_bitmap_data_set_pixel= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel"),(int)4);
	nme_bitmap_data_set_pixel32= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel32"),(int)4);
	nme_bitmap_data_set_pixel_rgba= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_pixel_rgba"),(int)4);
	nme_bitmap_data_set_bytes= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_bytes"),(int)4);
	nme_bitmap_data_set_format= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_format"),(int)2);
	nme_bitmap_data_set_array= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_array"),(int)3);
	nme_bitmap_data_create_hardware_surface= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_create_hardware_surface"),(int)1);
	nme_bitmap_data_destroy_hardware_surface= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_destroy_hardware_surface"),(int)1);
	nme_bitmap_data_generate_filter_rect= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_generate_filter_rect"),(int)3);
	nme_render_surface_to_surface= ::native::Loader_obj::load(HX_CSTRING("nme_render_surface_to_surface"),(int)-1);
	nme_bitmap_data_height= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_height"),(int)1);
	nme_bitmap_data_width= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_width"),(int)1);
	nme_bitmap_data_get_transparent= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_get_transparent"),(int)1);
	nme_bitmap_data_set_flags= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_set_flags"),(int)1);
	nme_bitmap_data_encode= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_encode"),(int)3);
	nme_bitmap_data_dump_bits= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_dump_bits"),(int)1);
	nme_bitmap_data_noise= ::native::Loader_obj::load(HX_CSTRING("nme_bitmap_data_noise"),(int)-1);
}

} // end namespace native
} // end namespace display
