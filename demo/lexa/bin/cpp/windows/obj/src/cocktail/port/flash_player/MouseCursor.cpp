#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_mouse_AbstractMouseCursor
#include <cocktail/core/mouse/AbstractMouseCursor.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_MouseCursor
#include <cocktail/port/flash_player/MouseCursor.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void MouseCursor_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/MouseCursor.hx",38)
	super::__construct();
}
;
	return null();
}

MouseCursor_obj::~MouseCursor_obj() { }

Dynamic MouseCursor_obj::__CreateEmpty() { return  new MouseCursor_obj; }
hx::ObjectPtr< MouseCursor_obj > MouseCursor_obj::__new()
{  hx::ObjectPtr< MouseCursor_obj > result = new MouseCursor_obj();
	result->__construct();
	return result;}

Dynamic MouseCursor_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseCursor_obj > result = new MouseCursor_obj();
	result->__construct();
	return result;}


MouseCursor_obj::MouseCursor_obj()
{
}

void MouseCursor_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseCursor);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MouseCursor_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic MouseCursor_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void MouseCursor_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class MouseCursor_obj::__mClass;

void MouseCursor_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.MouseCursor"), hx::TCanCast< MouseCursor_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MouseCursor_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
