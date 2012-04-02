#include <hxcpp.h>

#ifndef INCLUDED_core_style_Visibility
#include <core/style/Visibility.h>
#endif
namespace core{
namespace style{

::core::style::Visibility Visibility_obj::hidden;

::core::style::Visibility Visibility_obj::visible;

HX_DEFINE_CREATE_ENUM(Visibility_obj)

int Visibility_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("hidden")) return 1;
	if (inName==HX_CSTRING("visible")) return 0;
	return super::__FindIndex(inName);
}

int Visibility_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("hidden")) return 0;
	if (inName==HX_CSTRING("visible")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Visibility_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("hidden")) return hidden;
	if (inName==HX_CSTRING("visible")) return visible;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("visible"),
	HX_CSTRING("hidden"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Visibility_obj::hidden,"hidden");
	HX_MARK_MEMBER_NAME(Visibility_obj::visible,"visible");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Visibility_obj::__mClass;

Dynamic __Create_Visibility_obj() { return new Visibility_obj; }

void Visibility_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.Visibility"), hx::TCanCast< Visibility_obj >,sStaticFields,sMemberFields,
	&__Create_Visibility_obj, &__Create,
	&super::__SGetClass(), &CreateVisibility_obj, sMarkStatics);
}

void Visibility_obj::__boot()
{
Static(hidden) = hx::CreateEnum< Visibility_obj >(HX_CSTRING("hidden"),1);
Static(visible) = hx::CreateEnum< Visibility_obj >(HX_CSTRING("visible"),0);
}


} // end namespace core
} // end namespace style
