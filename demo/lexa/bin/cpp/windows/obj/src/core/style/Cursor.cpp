#include <hxcpp.h>

#ifndef INCLUDED_core_style_Cursor
#include <core/style/Cursor.h>
#endif
namespace core{
namespace style{

::core::style::Cursor Cursor_obj::_auto;

::core::style::Cursor Cursor_obj::crosshair;

::core::style::Cursor Cursor_obj::cssDefault;

::core::style::Cursor Cursor_obj::pointer;

HX_DEFINE_CREATE_ENUM(Cursor_obj)

int Cursor_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("auto")) return 0;
	if (inName==HX_CSTRING("crosshair")) return 1;
	if (inName==HX_CSTRING("cssDefault")) return 2;
	if (inName==HX_CSTRING("pointer")) return 3;
	return super::__FindIndex(inName);
}

int Cursor_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("auto")) return 0;
	if (inName==HX_CSTRING("crosshair")) return 0;
	if (inName==HX_CSTRING("cssDefault")) return 0;
	if (inName==HX_CSTRING("pointer")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Cursor_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("auto")) return _auto;
	if (inName==HX_CSTRING("crosshair")) return crosshair;
	if (inName==HX_CSTRING("cssDefault")) return cssDefault;
	if (inName==HX_CSTRING("pointer")) return pointer;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("auto"),
	HX_CSTRING("crosshair"),
	HX_CSTRING("cssDefault"),
	HX_CSTRING("pointer"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Cursor_obj::_auto,"_auto");
	HX_MARK_MEMBER_NAME(Cursor_obj::crosshair,"crosshair");
	HX_MARK_MEMBER_NAME(Cursor_obj::cssDefault,"cssDefault");
	HX_MARK_MEMBER_NAME(Cursor_obj::pointer,"pointer");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Cursor_obj::__mClass;

Dynamic __Create_Cursor_obj() { return new Cursor_obj; }

void Cursor_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Cursor"), hx::TCanCast< Cursor_obj >,sStaticFields,sMemberFields,
	&__Create_Cursor_obj, &__Create,
	&super::__SGetClass(), &CreateCursor_obj, sMarkStatics);
}

void Cursor_obj::__boot()
{
Static(_auto) = hx::CreateEnum< Cursor_obj >(HX_CSTRING("auto"),0);
Static(crosshair) = hx::CreateEnum< Cursor_obj >(HX_CSTRING("crosshair"),1);
Static(cssDefault) = hx::CreateEnum< Cursor_obj >(HX_CSTRING("cssDefault"),2);
Static(pointer) = hx::CreateEnum< Cursor_obj >(HX_CSTRING("pointer"),3);
}


} // end namespace core
} // end namespace style
