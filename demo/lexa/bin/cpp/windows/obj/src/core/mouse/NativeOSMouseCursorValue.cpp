#include <hxcpp.h>

#ifndef INCLUDED_core_mouse_NativeOSMouseCursorValue
#include <core/mouse/NativeOSMouseCursorValue.h>
#endif
namespace core{
namespace mouse{

::core::mouse::NativeOSMouseCursorValue NativeOSMouseCursorValue_obj::pointer;

::core::mouse::NativeOSMouseCursorValue NativeOSMouseCursorValue_obj::text;

HX_DEFINE_CREATE_ENUM(NativeOSMouseCursorValue_obj)

int NativeOSMouseCursorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("pointer")) return 0;
	if (inName==HX_CSTRING("text")) return 1;
	return super::__FindIndex(inName);
}

int NativeOSMouseCursorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("pointer")) return 0;
	if (inName==HX_CSTRING("text")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic NativeOSMouseCursorValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("pointer")) return pointer;
	if (inName==HX_CSTRING("text")) return text;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("pointer"),
	HX_CSTRING("text"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeOSMouseCursorValue_obj::pointer,"pointer");
	HX_MARK_MEMBER_NAME(NativeOSMouseCursorValue_obj::text,"text");
};

static ::String sMemberFields[] = { ::String(null()) };
Class NativeOSMouseCursorValue_obj::__mClass;

Dynamic __Create_NativeOSMouseCursorValue_obj() { return new NativeOSMouseCursorValue_obj; }

void NativeOSMouseCursorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.mouse.NativeOSMouseCursorValue"), hx::TCanCast< NativeOSMouseCursorValue_obj >,sStaticFields,sMemberFields,
	&__Create_NativeOSMouseCursorValue_obj, &__Create,
	&super::__SGetClass(), &CreateNativeOSMouseCursorValue_obj, sMarkStatics);
}

void NativeOSMouseCursorValue_obj::__boot()
{
Static(pointer) = hx::CreateEnum< NativeOSMouseCursorValue_obj >(HX_CSTRING("pointer"),0);
Static(text) = hx::CreateEnum< NativeOSMouseCursorValue_obj >(HX_CSTRING("text"),1);
}


} // end namespace core
} // end namespace mouse
