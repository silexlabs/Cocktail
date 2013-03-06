#include <hxcpp.h>

#ifndef INCLUDED_native_ui_MultitouchInputMode
#include <native/ui/MultitouchInputMode.h>
#endif
namespace native{
namespace ui{

::native::ui::MultitouchInputMode MultitouchInputMode_obj::GESTURE;

::native::ui::MultitouchInputMode MultitouchInputMode_obj::NONE;

::native::ui::MultitouchInputMode MultitouchInputMode_obj::TOUCH_POINT;

HX_DEFINE_CREATE_ENUM(MultitouchInputMode_obj)

int MultitouchInputMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("GESTURE")) return 2;
	if (inName==HX_CSTRING("NONE")) return 0;
	if (inName==HX_CSTRING("TOUCH_POINT")) return 1;
	return super::__FindIndex(inName);
}

int MultitouchInputMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("GESTURE")) return 0;
	if (inName==HX_CSTRING("NONE")) return 0;
	if (inName==HX_CSTRING("TOUCH_POINT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic MultitouchInputMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("GESTURE")) return GESTURE;
	if (inName==HX_CSTRING("NONE")) return NONE;
	if (inName==HX_CSTRING("TOUCH_POINT")) return TOUCH_POINT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NONE"),
	HX_CSTRING("TOUCH_POINT"),
	HX_CSTRING("GESTURE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MultitouchInputMode_obj::GESTURE,"GESTURE");
	HX_MARK_MEMBER_NAME(MultitouchInputMode_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(MultitouchInputMode_obj::TOUCH_POINT,"TOUCH_POINT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MultitouchInputMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MultitouchInputMode_obj::GESTURE,"GESTURE");
	HX_VISIT_MEMBER_NAME(MultitouchInputMode_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(MultitouchInputMode_obj::TOUCH_POINT,"TOUCH_POINT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class MultitouchInputMode_obj::__mClass;

Dynamic __Create_MultitouchInputMode_obj() { return new MultitouchInputMode_obj; }

void MultitouchInputMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.ui.MultitouchInputMode"), hx::TCanCast< MultitouchInputMode_obj >,sStaticFields,sMemberFields,
	&__Create_MultitouchInputMode_obj, &__Create,
	&super::__SGetClass(), &CreateMultitouchInputMode_obj, sMarkStatics, sVisitStatic);
}

void MultitouchInputMode_obj::__boot()
{
Static(GESTURE) = hx::CreateEnum< MultitouchInputMode_obj >(HX_CSTRING("GESTURE"),2);
Static(NONE) = hx::CreateEnum< MultitouchInputMode_obj >(HX_CSTRING("NONE"),0);
Static(TOUCH_POINT) = hx::CreateEnum< MultitouchInputMode_obj >(HX_CSTRING("TOUCH_POINT"),1);
}


} // end namespace native
} // end namespace ui
