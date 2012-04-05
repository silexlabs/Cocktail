#include <hxcpp.h>

#ifndef INCLUDED_nme_display_PixelSnapping
#include <nme/display/PixelSnapping.h>
#endif
namespace nme{
namespace display{

::nme::display::PixelSnapping PixelSnapping_obj::ALWAYS;

::nme::display::PixelSnapping PixelSnapping_obj::AUTO;

::nme::display::PixelSnapping PixelSnapping_obj::NEVER;

HX_DEFINE_CREATE_ENUM(PixelSnapping_obj)

int PixelSnapping_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ALWAYS")) return 2;
	if (inName==HX_CSTRING("AUTO")) return 1;
	if (inName==HX_CSTRING("NEVER")) return 0;
	return super::__FindIndex(inName);
}

int PixelSnapping_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ALWAYS")) return 0;
	if (inName==HX_CSTRING("AUTO")) return 0;
	if (inName==HX_CSTRING("NEVER")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic PixelSnapping_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("ALWAYS")) return ALWAYS;
	if (inName==HX_CSTRING("AUTO")) return AUTO;
	if (inName==HX_CSTRING("NEVER")) return NEVER;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NEVER"),
	HX_CSTRING("AUTO"),
	HX_CSTRING("ALWAYS"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PixelSnapping_obj::ALWAYS,"ALWAYS");
	HX_MARK_MEMBER_NAME(PixelSnapping_obj::AUTO,"AUTO");
	HX_MARK_MEMBER_NAME(PixelSnapping_obj::NEVER,"NEVER");
};

static ::String sMemberFields[] = { ::String(null()) };
Class PixelSnapping_obj::__mClass;

Dynamic __Create_PixelSnapping_obj() { return new PixelSnapping_obj; }

void PixelSnapping_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.PixelSnapping"), hx::TCanCast< PixelSnapping_obj >,sStaticFields,sMemberFields,
	&__Create_PixelSnapping_obj, &__Create,
	&super::__SGetClass(), &CreatePixelSnapping_obj, sMarkStatics);
}

void PixelSnapping_obj::__boot()
{
Static(ALWAYS) = hx::CreateEnum< PixelSnapping_obj >(HX_CSTRING("ALWAYS"),2);
Static(AUTO) = hx::CreateEnum< PixelSnapping_obj >(HX_CSTRING("AUTO"),1);
Static(NEVER) = hx::CreateEnum< PixelSnapping_obj >(HX_CSTRING("NEVER"),0);
}


} // end namespace nme
} // end namespace display
