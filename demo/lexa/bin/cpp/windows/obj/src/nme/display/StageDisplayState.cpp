#include <hxcpp.h>

#ifndef INCLUDED_nme_display_StageDisplayState
#include <nme/display/StageDisplayState.h>
#endif
namespace nme{
namespace display{

::nme::display::StageDisplayState StageDisplayState_obj::FULL_SCREEN;

::nme::display::StageDisplayState StageDisplayState_obj::FULL_SCREEN_INTERACTIVE;

::nme::display::StageDisplayState StageDisplayState_obj::NORMAL;

HX_DEFINE_CREATE_ENUM(StageDisplayState_obj)

int StageDisplayState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("FULL_SCREEN")) return 1;
	if (inName==HX_CSTRING("FULL_SCREEN_INTERACTIVE")) return 2;
	if (inName==HX_CSTRING("NORMAL")) return 0;
	return super::__FindIndex(inName);
}

int StageDisplayState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("FULL_SCREEN")) return 0;
	if (inName==HX_CSTRING("FULL_SCREEN_INTERACTIVE")) return 0;
	if (inName==HX_CSTRING("NORMAL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StageDisplayState_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("FULL_SCREEN")) return FULL_SCREEN;
	if (inName==HX_CSTRING("FULL_SCREEN_INTERACTIVE")) return FULL_SCREEN_INTERACTIVE;
	if (inName==HX_CSTRING("NORMAL")) return NORMAL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("FULL_SCREEN"),
	HX_CSTRING("FULL_SCREEN_INTERACTIVE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StageDisplayState_obj::FULL_SCREEN,"FULL_SCREEN");
	HX_MARK_MEMBER_NAME(StageDisplayState_obj::FULL_SCREEN_INTERACTIVE,"FULL_SCREEN_INTERACTIVE");
	HX_MARK_MEMBER_NAME(StageDisplayState_obj::NORMAL,"NORMAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StageDisplayState_obj::__mClass;

Dynamic __Create_StageDisplayState_obj() { return new StageDisplayState_obj; }

void StageDisplayState_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.StageDisplayState"), hx::TCanCast< StageDisplayState_obj >,sStaticFields,sMemberFields,
	&__Create_StageDisplayState_obj, &__Create,
	&super::__SGetClass(), &CreateStageDisplayState_obj, sMarkStatics);
}

void StageDisplayState_obj::__boot()
{
Static(FULL_SCREEN) = hx::CreateEnum< StageDisplayState_obj >(HX_CSTRING("FULL_SCREEN"),1);
Static(FULL_SCREEN_INTERACTIVE) = hx::CreateEnum< StageDisplayState_obj >(HX_CSTRING("FULL_SCREEN_INTERACTIVE"),2);
Static(NORMAL) = hx::CreateEnum< StageDisplayState_obj >(HX_CSTRING("NORMAL"),0);
}


} // end namespace nme
} // end namespace display
