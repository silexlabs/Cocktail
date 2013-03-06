#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#include <cocktail/core/css/AttributeSelectorValue.h>
#endif
namespace cocktail{
namespace core{
namespace css{

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE(::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE"),0,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_LIST(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_LIST"),2,hx::DynamicArray(0,2).Add(name).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_VALUE(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_VALUE"),1,hx::DynamicArray(0,2).Add(name).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_VALUE_BEGINS"),3,hx::DynamicArray(0,2).Add(name).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST"),6,hx::DynamicArray(0,2).Add(name).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_VALUE_CONTAINS(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_VALUE_CONTAINS"),5,hx::DynamicArray(0,2).Add(name).Add(value)); }

::cocktail::core::css::AttributeSelectorValue  AttributeSelectorValue_obj::ATTRIBUTE_VALUE_ENDS(::String name,::String value)
	{ return hx::CreateEnum< AttributeSelectorValue_obj >(HX_CSTRING("ATTRIBUTE_VALUE_ENDS"),4,hx::DynamicArray(0,2).Add(name).Add(value)); }

HX_DEFINE_CREATE_ENUM(AttributeSelectorValue_obj)

int AttributeSelectorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 0;
	if (inName==HX_CSTRING("ATTRIBUTE_LIST")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE")) return 1;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS")) return 3;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST")) return 6;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_CONTAINS")) return 5;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_ENDS")) return 4;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(AttributeSelectorValue_obj,ATTRIBUTE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_LIST,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_VALUE,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_VALUE_BEGINS,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_VALUE_CONTAINS,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(AttributeSelectorValue_obj,ATTRIBUTE_VALUE_ENDS,return)

int AttributeSelectorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return 1;
	if (inName==HX_CSTRING("ATTRIBUTE_LIST")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_CONTAINS")) return 2;
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_ENDS")) return 2;
	return super::__FindArgCount(inName);
}

Dynamic AttributeSelectorValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ATTRIBUTE")) return ATTRIBUTE_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_LIST")) return ATTRIBUTE_LIST_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE")) return ATTRIBUTE_VALUE_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS")) return ATTRIBUTE_VALUE_BEGINS_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST")) return ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_CONTAINS")) return ATTRIBUTE_VALUE_CONTAINS_dyn();
	if (inName==HX_CSTRING("ATTRIBUTE_VALUE_ENDS")) return ATTRIBUTE_VALUE_ENDS_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("ATTRIBUTE"),
	HX_CSTRING("ATTRIBUTE_VALUE"),
	HX_CSTRING("ATTRIBUTE_LIST"),
	HX_CSTRING("ATTRIBUTE_VALUE_BEGINS"),
	HX_CSTRING("ATTRIBUTE_VALUE_ENDS"),
	HX_CSTRING("ATTRIBUTE_VALUE_CONTAINS"),
	HX_CSTRING("ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AttributeSelectorValue_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class AttributeSelectorValue_obj::__mClass;

Dynamic __Create_AttributeSelectorValue_obj() { return new AttributeSelectorValue_obj; }

void AttributeSelectorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.AttributeSelectorValue"), hx::TCanCast< AttributeSelectorValue_obj >,sStaticFields,sMemberFields,
	&__Create_AttributeSelectorValue_obj, &__Create,
	&super::__SGetClass(), &CreateAttributeSelectorValue_obj, sMarkStatics, sVisitStatic);
}

void AttributeSelectorValue_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace css
