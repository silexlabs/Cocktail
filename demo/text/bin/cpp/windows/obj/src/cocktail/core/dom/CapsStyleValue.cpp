#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_CapsStyleValue
#include <cocktail/core/dom/CapsStyleValue.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

::cocktail::core::dom::CapsStyleValue CapsStyleValue_obj::none;

::cocktail::core::dom::CapsStyleValue CapsStyleValue_obj::round;

::cocktail::core::dom::CapsStyleValue CapsStyleValue_obj::square;

HX_DEFINE_CREATE_ENUM(CapsStyleValue_obj)

int CapsStyleValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("round")) return 2;
	if (inName==HX_CSTRING("square")) return 1;
	return super::__FindIndex(inName);
}

int CapsStyleValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("none")) return 0;
	if (inName==HX_CSTRING("round")) return 0;
	if (inName==HX_CSTRING("square")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CapsStyleValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("none")) return none;
	if (inName==HX_CSTRING("round")) return round;
	if (inName==HX_CSTRING("square")) return square;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("square"),
	HX_CSTRING("round"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CapsStyleValue_obj::none,"none");
	HX_MARK_MEMBER_NAME(CapsStyleValue_obj::round,"round");
	HX_MARK_MEMBER_NAME(CapsStyleValue_obj::square,"square");
};

static ::String sMemberFields[] = { ::String(null()) };
Class CapsStyleValue_obj::__mClass;

Dynamic __Create_CapsStyleValue_obj() { return new CapsStyleValue_obj; }

void CapsStyleValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.CapsStyleValue"), hx::TCanCast< CapsStyleValue_obj >,sStaticFields,sMemberFields,
	&__Create_CapsStyleValue_obj, &__Create,
	&super::__SGetClass(), &CreateCapsStyleValue_obj, sMarkStatics);
}

void CapsStyleValue_obj::__boot()
{
Static(none) = hx::CreateEnum< CapsStyleValue_obj >(HX_CSTRING("none"),0);
Static(round) = hx::CreateEnum< CapsStyleValue_obj >(HX_CSTRING("round"),2);
Static(square) = hx::CreateEnum< CapsStyleValue_obj >(HX_CSTRING("square"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace dom
