#include <hxcpp.h>

#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
namespace nme{
namespace display{

::nme::display::SpreadMethod SpreadMethod_obj::PAD;

::nme::display::SpreadMethod SpreadMethod_obj::REFLECT;

::nme::display::SpreadMethod SpreadMethod_obj::REPEAT;

HX_DEFINE_CREATE_ENUM(SpreadMethod_obj)

int SpreadMethod_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("PAD")) return 0;
	if (inName==HX_CSTRING("REFLECT")) return 2;
	if (inName==HX_CSTRING("REPEAT")) return 1;
	return super::__FindIndex(inName);
}

int SpreadMethod_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("PAD")) return 0;
	if (inName==HX_CSTRING("REFLECT")) return 0;
	if (inName==HX_CSTRING("REPEAT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic SpreadMethod_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("PAD")) return PAD;
	if (inName==HX_CSTRING("REFLECT")) return REFLECT;
	if (inName==HX_CSTRING("REPEAT")) return REPEAT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("PAD"),
	HX_CSTRING("REPEAT"),
	HX_CSTRING("REFLECT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpreadMethod_obj::PAD,"PAD");
	HX_MARK_MEMBER_NAME(SpreadMethod_obj::REFLECT,"REFLECT");
	HX_MARK_MEMBER_NAME(SpreadMethod_obj::REPEAT,"REPEAT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SpreadMethod_obj::__mClass;

Dynamic __Create_SpreadMethod_obj() { return new SpreadMethod_obj; }

void SpreadMethod_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.SpreadMethod"), hx::TCanCast< SpreadMethod_obj >,sStaticFields,sMemberFields,
	&__Create_SpreadMethod_obj, &__Create,
	&super::__SGetClass(), &CreateSpreadMethod_obj, sMarkStatics);
}

void SpreadMethod_obj::__boot()
{
Static(PAD) = hx::CreateEnum< SpreadMethod_obj >(HX_CSTRING("PAD"),0);
Static(REFLECT) = hx::CreateEnum< SpreadMethod_obj >(HX_CSTRING("REFLECT"),2);
Static(REPEAT) = hx::CreateEnum< SpreadMethod_obj >(HX_CSTRING("REPEAT"),1);
}


} // end namespace nme
} // end namespace display
