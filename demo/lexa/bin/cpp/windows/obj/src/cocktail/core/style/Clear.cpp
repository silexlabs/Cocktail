#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
namespace cocktail{
namespace core{
namespace style{

::cocktail::core::style::Clear Clear_obj::both;

::cocktail::core::style::Clear Clear_obj::left;

::cocktail::core::style::Clear Clear_obj::none;

::cocktail::core::style::Clear Clear_obj::right;

HX_DEFINE_CREATE_ENUM(Clear_obj)

int Clear_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("both")) return 3;
	if (inName==HX_CSTRING("left")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("right")) return 2;
	return super::__FindIndex(inName);
}

int Clear_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("both")) return 0;
	if (inName==HX_CSTRING("left")) return 0;
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("right")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Clear_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("both")) return both;
	if (inName==HX_CSTRING("left")) return left;
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("right")) return right;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("left"),
	HX_CSTRING("right"),
	HX_CSTRING("both"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Clear_obj::both,"both");
	HX_MARK_MEMBER_NAME(Clear_obj::left,"left");
	HX_MARK_MEMBER_NAME(Clear_obj::none,"none");
	HX_MARK_MEMBER_NAME(Clear_obj::right,"right");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Clear_obj::__mClass;

Dynamic __Create_Clear_obj() { return new Clear_obj; }

void Clear_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.Clear"), hx::TCanCast< Clear_obj >,sStaticFields,sMemberFields,
	&__Create_Clear_obj, &__Create,
	&super::__SGetClass(), &CreateClear_obj, sMarkStatics);
}

void Clear_obj::__boot()
{
Static(both) = hx::CreateEnum< Clear_obj >(HX_CSTRING("both"),3);
Static(left) = hx::CreateEnum< Clear_obj >(HX_CSTRING("left"),1);
Static(none) = hx::CreateEnum< Clear_obj >(HX_CSTRING("none"),0);
Static(right) = hx::CreateEnum< Clear_obj >(HX_CSTRING("right"),2);
}


} // end namespace cocktail
} // end namespace core
} // end namespace style
