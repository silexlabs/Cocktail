#include <hxcpp.h>

#ifndef INCLUDED_nme_display_StageAlign
#include <nme/display/StageAlign.h>
#endif
namespace nme{
namespace display{

::nme::display::StageAlign StageAlign_obj::BOTTOM;

::nme::display::StageAlign StageAlign_obj::BOTTOM_LEFT;

::nme::display::StageAlign StageAlign_obj::BOTTOM_RIGHT;

::nme::display::StageAlign StageAlign_obj::LEFT;

::nme::display::StageAlign StageAlign_obj::RIGHT;

::nme::display::StageAlign StageAlign_obj::TOP;

::nme::display::StageAlign StageAlign_obj::TOP_LEFT;

::nme::display::StageAlign StageAlign_obj::TOP_RIGHT;

HX_DEFINE_CREATE_ENUM(StageAlign_obj)

int StageAlign_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BOTTOM")) return 7;
	if (inName==HX_CSTRING("BOTTOM_LEFT")) return 6;
	if (inName==HX_CSTRING("BOTTOM_RIGHT")) return 5;
	if (inName==HX_CSTRING("LEFT")) return 4;
	if (inName==HX_CSTRING("RIGHT")) return 3;
	if (inName==HX_CSTRING("TOP")) return 2;
	if (inName==HX_CSTRING("TOP_LEFT")) return 1;
	if (inName==HX_CSTRING("TOP_RIGHT")) return 0;
	return super::__FindIndex(inName);
}

int StageAlign_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BOTTOM")) return 0;
	if (inName==HX_CSTRING("BOTTOM_LEFT")) return 0;
	if (inName==HX_CSTRING("BOTTOM_RIGHT")) return 0;
	if (inName==HX_CSTRING("LEFT")) return 0;
	if (inName==HX_CSTRING("RIGHT")) return 0;
	if (inName==HX_CSTRING("TOP")) return 0;
	if (inName==HX_CSTRING("TOP_LEFT")) return 0;
	if (inName==HX_CSTRING("TOP_RIGHT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic StageAlign_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("BOTTOM")) return BOTTOM;
	if (inName==HX_CSTRING("BOTTOM_LEFT")) return BOTTOM_LEFT;
	if (inName==HX_CSTRING("BOTTOM_RIGHT")) return BOTTOM_RIGHT;
	if (inName==HX_CSTRING("LEFT")) return LEFT;
	if (inName==HX_CSTRING("RIGHT")) return RIGHT;
	if (inName==HX_CSTRING("TOP")) return TOP;
	if (inName==HX_CSTRING("TOP_LEFT")) return TOP_LEFT;
	if (inName==HX_CSTRING("TOP_RIGHT")) return TOP_RIGHT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("TOP_RIGHT"),
	HX_CSTRING("TOP_LEFT"),
	HX_CSTRING("TOP"),
	HX_CSTRING("RIGHT"),
	HX_CSTRING("LEFT"),
	HX_CSTRING("BOTTOM_RIGHT"),
	HX_CSTRING("BOTTOM_LEFT"),
	HX_CSTRING("BOTTOM"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StageAlign_obj::BOTTOM,"BOTTOM");
	HX_MARK_MEMBER_NAME(StageAlign_obj::BOTTOM_LEFT,"BOTTOM_LEFT");
	HX_MARK_MEMBER_NAME(StageAlign_obj::BOTTOM_RIGHT,"BOTTOM_RIGHT");
	HX_MARK_MEMBER_NAME(StageAlign_obj::LEFT,"LEFT");
	HX_MARK_MEMBER_NAME(StageAlign_obj::RIGHT,"RIGHT");
	HX_MARK_MEMBER_NAME(StageAlign_obj::TOP,"TOP");
	HX_MARK_MEMBER_NAME(StageAlign_obj::TOP_LEFT,"TOP_LEFT");
	HX_MARK_MEMBER_NAME(StageAlign_obj::TOP_RIGHT,"TOP_RIGHT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class StageAlign_obj::__mClass;

Dynamic __Create_StageAlign_obj() { return new StageAlign_obj; }

void StageAlign_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.StageAlign"), hx::TCanCast< StageAlign_obj >,sStaticFields,sMemberFields,
	&__Create_StageAlign_obj, &__Create,
	&super::__SGetClass(), &CreateStageAlign_obj, sMarkStatics);
}

void StageAlign_obj::__boot()
{
Static(BOTTOM) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("BOTTOM"),7);
Static(BOTTOM_LEFT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("BOTTOM_LEFT"),6);
Static(BOTTOM_RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("BOTTOM_RIGHT"),5);
Static(LEFT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("LEFT"),4);
Static(RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("RIGHT"),3);
Static(TOP) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("TOP"),2);
Static(TOP_LEFT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("TOP_LEFT"),1);
Static(TOP_RIGHT) = hx::CreateEnum< StageAlign_obj >(HX_CSTRING("TOP_RIGHT"),0);
}


} // end namespace nme
} // end namespace display
