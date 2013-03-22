#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::SimpleSelectorSequenceStartValue  SimpleSelectorSequenceStartValue_obj::TYPE(::String value)
	{ return hx::CreateEnum< SimpleSelectorSequenceStartValue_obj >(HX_CSTRING("TYPE"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::SimpleSelectorSequenceStartValue SimpleSelectorSequenceStartValue_obj::UNIVERSAL;

HX_DEFINE_CREATE_ENUM(SimpleSelectorSequenceStartValue_obj)

int SimpleSelectorSequenceStartValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("TYPE")) return 1;
	if (inName==HX_CSTRING("UNIVERSAL")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(SimpleSelectorSequenceStartValue_obj,TYPE,return)

int SimpleSelectorSequenceStartValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("TYPE")) return 1;
	if (inName==HX_CSTRING("UNIVERSAL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic SimpleSelectorSequenceStartValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("TYPE")) return TYPE_dyn();
	if (inName==HX_CSTRING("UNIVERSAL")) return UNIVERSAL;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("UNIVERSAL"),
	HX_CSTRING("TYPE"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleSelectorSequenceStartValue_obj::UNIVERSAL,"UNIVERSAL");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleSelectorSequenceStartValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SimpleSelectorSequenceStartValue_obj::UNIVERSAL,"UNIVERSAL");
};

static ::String sMemberFields[] = { ::String(null()) };
Class SimpleSelectorSequenceStartValue_obj::__mClass;

Dynamic __Create_SimpleSelectorSequenceStartValue_obj() { return new SimpleSelectorSequenceStartValue_obj; }

void SimpleSelectorSequenceStartValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SimpleSelectorSequenceStartValue"), hx::TCanCast< SimpleSelectorSequenceStartValue_obj >,sStaticFields,sMemberFields,
	&__Create_SimpleSelectorSequenceStartValue_obj, &__Create,
	&super::__SGetClass(), &CreateSimpleSelectorSequenceStartValue_obj, sMarkStatics, sVisitStatic);
}

void SimpleSelectorSequenceStartValue_obj::__boot()
{
Static(UNIVERSAL) = hx::CreateEnum< SimpleSelectorSequenceStartValue_obj >(HX_CSTRING("UNIVERSAL"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
