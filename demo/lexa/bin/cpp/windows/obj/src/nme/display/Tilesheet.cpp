#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_Tilesheet
#include <nme/display/Tilesheet.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace nme{
namespace display{

Void Tilesheet_obj::__construct(::nme::display::BitmapData inImage)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Tilesheet.hx",49)
	this->nmeBitmap = inImage;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Tilesheet.hx",53)
	this->nmeHandle = ::nme::display::Tilesheet_obj::nme_tilesheet_create(inImage->nmeHandle);
}
;
	return null();
}

Tilesheet_obj::~Tilesheet_obj() { }

Dynamic Tilesheet_obj::__CreateEmpty() { return  new Tilesheet_obj; }
hx::ObjectPtr< Tilesheet_obj > Tilesheet_obj::__new(::nme::display::BitmapData inImage)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(inImage);
	return result;}

Dynamic Tilesheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Tilesheet_obj > result = new Tilesheet_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Tilesheet_obj::addTileRect( ::nme::geom::Rectangle rectangle,::nme::geom::Point centerPoint){
{
		HX_SOURCE_PUSH("Tilesheet_obj::addTileRect")
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Tilesheet.hx",73)
		::nme::display::Tilesheet_obj::nme_tilesheet_add_rect(this->nmeHandle,rectangle,centerPoint);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Tilesheet_obj,addTileRect,(void))

Void Tilesheet_obj::drawTiles( ::nme::display::Graphics graphics,Array< double > tileData,Dynamic __o_smooth,Dynamic __o_flags){
bool smooth = __o_smooth.Default(false);
int flags = __o_flags.Default(0);
	HX_SOURCE_PUSH("Tilesheet_obj::drawTiles");
{
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/Tilesheet.hx",171)
		graphics->drawTiles(hx::ObjectPtr<OBJ_>(this),tileData,smooth,flags);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Tilesheet_obj,drawTiles,(void))

int Tilesheet_obj::TILE_SCALE;

int Tilesheet_obj::TILE_ROTATION;

int Tilesheet_obj::TILE_RGB;

int Tilesheet_obj::TILE_ALPHA;

Dynamic Tilesheet_obj::nme_tilesheet_create;

Dynamic Tilesheet_obj::nme_tilesheet_add_rect;


Tilesheet_obj::Tilesheet_obj()
{
}

void Tilesheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Tilesheet);
	HX_MARK_MEMBER_NAME(nmeBitmap,"nmeBitmap");
	HX_MARK_MEMBER_NAME(nmeHandle,"nmeHandle");
	HX_MARK_END_CLASS();
}

Dynamic Tilesheet_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { return TILE_RGB; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeBitmap") ) { return nmeBitmap; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { return nmeHandle; }
		if (HX_FIELD_EQ(inName,"drawTiles") ) { return drawTiles_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { return TILE_SCALE; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { return TILE_ALPHA; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addTileRect") ) { return addTileRect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { return TILE_ROTATION; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_create") ) { return nme_tilesheet_create; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_add_rect") ) { return nme_tilesheet_add_rect; }
	}
	return super::__Field(inName);
}

Dynamic Tilesheet_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"TILE_RGB") ) { TILE_RGB=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"nmeBitmap") ) { nmeBitmap=inValue.Cast< ::nme::display::BitmapData >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nmeHandle") ) { nmeHandle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TILE_SCALE") ) { TILE_SCALE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TILE_ALPHA") ) { TILE_ALPHA=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TILE_ROTATION") ) { TILE_ROTATION=inValue.Cast< int >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_create") ) { nme_tilesheet_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nme_tilesheet_add_rect") ) { nme_tilesheet_add_rect=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Tilesheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeBitmap"));
	outFields->push(HX_CSTRING("nmeHandle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TILE_SCALE"),
	HX_CSTRING("TILE_ROTATION"),
	HX_CSTRING("TILE_RGB"),
	HX_CSTRING("TILE_ALPHA"),
	HX_CSTRING("nme_tilesheet_create"),
	HX_CSTRING("nme_tilesheet_add_rect"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeBitmap"),
	HX_CSTRING("nmeHandle"),
	HX_CSTRING("addTileRect"),
	HX_CSTRING("drawTiles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_SCALE,"TILE_SCALE");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ROTATION,"TILE_ROTATION");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_RGB,"TILE_RGB");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::TILE_ALPHA,"TILE_ALPHA");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::nme_tilesheet_create,"nme_tilesheet_create");
	HX_MARK_MEMBER_NAME(Tilesheet_obj::nme_tilesheet_add_rect,"nme_tilesheet_add_rect");
};

Class Tilesheet_obj::__mClass;

void Tilesheet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.Tilesheet"), hx::TCanCast< Tilesheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Tilesheet_obj::__boot()
{
	hx::Static(TILE_SCALE) = (int)1;
	hx::Static(TILE_ROTATION) = (int)2;
	hx::Static(TILE_RGB) = (int)4;
	hx::Static(TILE_ALPHA) = (int)8;
	hx::Static(nme_tilesheet_create) = ::nme::Loader_obj::load(HX_CSTRING("nme_tilesheet_create"),(int)1);
	hx::Static(nme_tilesheet_add_rect) = ::nme::Loader_obj::load(HX_CSTRING("nme_tilesheet_add_rect"),(int)3);
}

} // end namespace nme
} // end namespace display
