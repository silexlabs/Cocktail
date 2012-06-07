#include <hxcpp.h>

#ifndef INCLUDED_core_style_WhiteSpace
#include <core/style/WhiteSpace.h>
#endif
namespace core{
namespace style{

::core::style::WhiteSpace WhiteSpace_obj::normal;

::core::style::WhiteSpace WhiteSpace_obj::nowrap;

::core::style::WhiteSpace WhiteSpace_obj::pre;

::core::style::WhiteSpace WhiteSpace_obj::preLine;

::core::style::WhiteSpace WhiteSpace_obj::preWrap;

HX_DEFINE_CREATE_ENUM(WhiteSpace_obj)

int WhiteSpace_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("nowrap")) return 2;
	if (inName==HX_CSTRING("pre")) return 1;
	if (inName==HX_CSTRING("preLine")) return 4;
	if (inName==HX_CSTRING("preWrap")) return 3;
	return super::__FindIndex(inName);
}

int WhiteSpace_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("normal")) return 0;
	if (inName==HX_CSTRING("nowrap")) return 0;
	if (inName==HX_CSTRING("pre")) return 0;
	if (inName==HX_CSTRING("preLine")) return 0;
	if (inName==HX_CSTRING("preWrap")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic WhiteSpace_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("normal")) return normal;
	if (inName==HX_CSTRING("nowrap")) return nowrap;
	if (inName==HX_CSTRING("pre")) return pre;
	if (inName==HX_CSTRING("preLine")) return preLine;
	if (inName==HX_CSTRING("preWrap")) return preWrap;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("normal"),
	HX_CSTRING("pre"),
	HX_CSTRING("nowrap"),
	HX_CSTRING("preWrap"),
	HX_CSTRING("preLine"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WhiteSpace_obj::normal,"normal");
	HX_MARK_MEMBER_NAME(WhiteSpace_obj::nowrap,"nowrap");
	HX_MARK_MEMBER_NAME(WhiteSpace_obj::pre,"pre");
	HX_MARK_MEMBER_NAME(WhiteSpace_obj::preLine,"preLine");
	HX_MARK_MEMBER_NAME(WhiteSpace_obj::preWrap,"preWrap");
};

static ::String sMemberFields[] = { ::String(null()) };
Class WhiteSpace_obj::__mClass;

Dynamic __Create_WhiteSpace_obj() { return new WhiteSpace_obj; }

void WhiteSpace_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.WhiteSpace"), hx::TCanCast< WhiteSpace_obj >,sStaticFields,sMemberFields,
	&__Create_WhiteSpace_obj, &__Create,
	&super::__SGetClass(), &CreateWhiteSpace_obj, sMarkStatics);
}

void WhiteSpace_obj::__boot()
{
Static(normal) = hx::CreateEnum< WhiteSpace_obj >(HX_CSTRING("normal"),0);
Static(nowrap) = hx::CreateEnum< WhiteSpace_obj >(HX_CSTRING("nowrap"),2);
Static(pre) = hx::CreateEnum< WhiteSpace_obj >(HX_CSTRING("pre"),1);
Static(preLine) = hx::CreateEnum< WhiteSpace_obj >(HX_CSTRING("preLine"),4);
Static(preWrap) = hx::CreateEnum< WhiteSpace_obj >(HX_CSTRING("preWrap"),3);
}


} // end namespace core
} // end namespace style
