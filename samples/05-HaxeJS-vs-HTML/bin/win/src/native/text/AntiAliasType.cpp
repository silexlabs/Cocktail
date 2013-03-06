#include <hxcpp.h>

#ifndef INCLUDED_native_text_AntiAliasType
#include <native/text/AntiAliasType.h>
#endif
namespace native{
namespace text{

::native::text::AntiAliasType AntiAliasType_obj::ADVANCED;

::native::text::AntiAliasType AntiAliasType_obj::NORMAL;

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

Dynamic AntiAliasType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ADVANCED")) return ADVANCED;
	if (inName==HX_CSTRING("NORMAL")) return NORMAL;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ADVANCED"),
	HX_CSTRING("NORMAL"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AntiAliasType_obj::ADVANCED,"ADVANCED");
	HX_MARK_MEMBER_NAME(AntiAliasType_obj::NORMAL,"NORMAL");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AntiAliasType_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AntiAliasType_obj::ADVANCED,"ADVANCED");
	HX_VISIT_MEMBER_NAME(AntiAliasType_obj::NORMAL,"NORMAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class AntiAliasType_obj::__mClass;

Dynamic __Create_AntiAliasType_obj() { return new AntiAliasType_obj; }

void AntiAliasType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("native.text.AntiAliasType"), hx::TCanCast< AntiAliasType_obj >,sStaticFields,sMemberFields,
	&__Create_AntiAliasType_obj, &__Create,
	&super::__SGetClass(), &CreateAntiAliasType_obj, sMarkStatics, sVisitStatic);
}

void AntiAliasType_obj::__boot()
{
Static(ADVANCED) = hx::CreateEnum< AntiAliasType_obj >(HX_CSTRING("ADVANCED"),0);
Static(NORMAL) = hx::CreateEnum< AntiAliasType_obj >(HX_CSTRING("NORMAL"),1);
}


} // end namespace native
} // end namespace text
