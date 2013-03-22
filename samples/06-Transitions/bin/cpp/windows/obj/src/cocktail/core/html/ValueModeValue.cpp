#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_html_ValueModeValue
#include <cocktail/core/html/ValueModeValue.h>
#endif
namespace cocktail{
namespace core{
namespace html{

::cocktail::core::html::ValueModeValue ValueModeValue_obj::DEFAULT;

::cocktail::core::html::ValueModeValue ValueModeValue_obj::DEFAULT_ON;

::cocktail::core::html::ValueModeValue ValueModeValue_obj::FILENAME;

::cocktail::core::html::ValueModeValue ValueModeValue_obj::VALUE;

HX_DEFINE_CREATE_ENUM(ValueModeValue_obj)

int ValueModeValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("DEFAULT")) return 1;
	if (inName==HX_CSTRING("DEFAULT_ON")) return 2;
	if (inName==HX_CSTRING("FILENAME")) return 3;
	if (inName==HX_CSTRING("VALUE")) return 0;
	return super::__FindIndex(inName);
}

int ValueModeValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("DEFAULT")) return 0;
	if (inName==HX_CSTRING("DEFAULT_ON")) return 0;
	if (inName==HX_CSTRING("FILENAME")) return 0;
	if (inName==HX_CSTRING("VALUE")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ValueModeValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("DEFAULT")) return DEFAULT;
	if (inName==HX_CSTRING("DEFAULT_ON")) return DEFAULT_ON;
	if (inName==HX_CSTRING("FILENAME")) return FILENAME;
	if (inName==HX_CSTRING("VALUE")) return VALUE;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("VALUE"),
	HX_CSTRING("DEFAULT"),
	HX_CSTRING("DEFAULT_ON"),
	HX_CSTRING("FILENAME"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ValueModeValue_obj::DEFAULT,"DEFAULT");
	HX_MARK_MEMBER_NAME(ValueModeValue_obj::DEFAULT_ON,"DEFAULT_ON");
	HX_MARK_MEMBER_NAME(ValueModeValue_obj::FILENAME,"FILENAME");
	HX_MARK_MEMBER_NAME(ValueModeValue_obj::VALUE,"VALUE");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ValueModeValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ValueModeValue_obj::DEFAULT,"DEFAULT");
	HX_VISIT_MEMBER_NAME(ValueModeValue_obj::DEFAULT_ON,"DEFAULT_ON");
	HX_VISIT_MEMBER_NAME(ValueModeValue_obj::FILENAME,"FILENAME");
	HX_VISIT_MEMBER_NAME(ValueModeValue_obj::VALUE,"VALUE");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ValueModeValue_obj::__mClass;

Dynamic __Create_ValueModeValue_obj() { return new ValueModeValue_obj; }

void ValueModeValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.ValueModeValue"), hx::TCanCast< ValueModeValue_obj >,sStaticFields,sMemberFields,
	&__Create_ValueModeValue_obj, &__Create,
	&super::__SGetClass(), &CreateValueModeValue_obj, sMarkStatics, sVisitStatic);
}

void ValueModeValue_obj::__boot()
{
Static(DEFAULT) = hx::CreateEnum< ValueModeValue_obj >(HX_CSTRING("DEFAULT"),1);
Static(DEFAULT_ON) = hx::CreateEnum< ValueModeValue_obj >(HX_CSTRING("DEFAULT_ON"),2);
Static(FILENAME) = hx::CreateEnum< ValueModeValue_obj >(HX_CSTRING("FILENAME"),3);
Static(VALUE) = hx::CreateEnum< ValueModeValue_obj >(HX_CSTRING("VALUE"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace html
