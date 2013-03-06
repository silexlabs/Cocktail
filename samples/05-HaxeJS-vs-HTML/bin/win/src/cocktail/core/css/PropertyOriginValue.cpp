#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::PropertyOriginValue PropertyOriginValue_obj::AUTHOR;

::cocktail::core::css::PropertyOriginValue PropertyOriginValue_obj::USER_AGENT;

HX_DEFINE_CREATE_ENUM(PropertyOriginValue_obj)

int PropertyOriginValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("AUTHOR")) return 0;
	if (inName==HX_CSTRING("USER_AGENT")) return 1;
	return super::__FindIndex(inName);
}

int PropertyOriginValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("AUTHOR")) return 0;
	if (inName==HX_CSTRING("USER_AGENT")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic PropertyOriginValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("AUTHOR")) return AUTHOR;
	if (inName==HX_CSTRING("USER_AGENT")) return USER_AGENT;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("AUTHOR"),
	HX_CSTRING("USER_AGENT"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PropertyOriginValue_obj::AUTHOR,"AUTHOR");
	HX_MARK_MEMBER_NAME(PropertyOriginValue_obj::USER_AGENT,"USER_AGENT");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PropertyOriginValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PropertyOriginValue_obj::AUTHOR,"AUTHOR");
	HX_VISIT_MEMBER_NAME(PropertyOriginValue_obj::USER_AGENT,"USER_AGENT");
};

static ::String sMemberFields[] = { ::String(null()) };
Class PropertyOriginValue_obj::__mClass;

Dynamic __Create_PropertyOriginValue_obj() { return new PropertyOriginValue_obj; }

void PropertyOriginValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.PropertyOriginValue"), hx::TCanCast< PropertyOriginValue_obj >,sStaticFields,sMemberFields,
	&__Create_PropertyOriginValue_obj, &__Create,
	&super::__SGetClass(), &CreatePropertyOriginValue_obj, sMarkStatics, sVisitStatic);
}

void PropertyOriginValue_obj::__boot()
{
Static(AUTHOR) = hx::CreateEnum< PropertyOriginValue_obj >(HX_CSTRING("AUTHOR"),0);
Static(USER_AGENT) = hx::CreateEnum< PropertyOriginValue_obj >(HX_CSTRING("USER_AGENT"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
