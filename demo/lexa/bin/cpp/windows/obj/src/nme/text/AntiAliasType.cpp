#include <hxcpp.h>

#ifndef INCLUDED_nme_text_AntiAliasType
#include <nme/text/AntiAliasType.h>
#endif
namespace nme{
namespace text{

::nme::text::AntiAliasType AntiAliasType_obj::ADVANCED;

::nme::text::AntiAliasType AntiAliasType_obj::NORMAL;

HX_DEFINE_CREATE_ENUM(AntiAliasType_obj)

int AntiAliasType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ADVANCED")) return 0;
	if (inName==HX_CSTRING("NORMAL")) return 1;
	return super::__FindIndex(inName);
}

int AntiAliasType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ADVANCED")) return 0;
	if (inName==HX_CSTRING("NORMAL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AntiAliasType_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("ADVANCED")) return ADVANCED;
	if (inName==HX_CSTRING("NORMAL")) return NORMAL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ADVANCED"),
	HX_CSTRING("NORMAL"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AntiAliasType_obj::ADVANCED,"ADVANCED");
	HX_MARK_MEMBER_NAME(AntiAliasType_obj::NORMAL,"NORMAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class AntiAliasType_obj::__mClass;

Dynamic __Create_AntiAliasType_obj() { return new AntiAliasType_obj; }

void AntiAliasType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.text.AntiAliasType"), hx::TCanCast< AntiAliasType_obj >,sStaticFields,sMemberFields,
	&__Create_AntiAliasType_obj, &__Create,
	&super::__SGetClass(), &CreateAntiAliasType_obj, sMarkStatics);
}

void AntiAliasType_obj::__boot()
{
Static(ADVANCED) = hx::CreateEnum< AntiAliasType_obj >(HX_CSTRING("ADVANCED"),0);
Static(NORMAL) = hx::CreateEnum< AntiAliasType_obj >(HX_CSTRING("NORMAL"),1);
}


} // end namespace nme
} // end namespace text
