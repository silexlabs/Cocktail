#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

::cocktail::core::unit::Length  Length_obj::cm(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("cm"),1,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::cssIn(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("cssIn"),5,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::em(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("em"),6,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::ex(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("ex"),7,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::mm(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("mm"),2,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::pc(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("pc"),4,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::pt(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("pt"),3,hx::DynamicArray(0,1).Add(value)); }

::cocktail::core::unit::Length  Length_obj::px(double value)
	{ return hx::CreateEnum< Length_obj >(HX_CSTRING("px"),0,hx::DynamicArray(0,1).Add(value)); }

HX_DEFINE_CREATE_ENUM(Length_obj)

int Length_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cm")) return 1;
	if (inName==HX_CSTRING("cssIn")) return 5;
	if (inName==HX_CSTRING("em")) return 6;
	if (inName==HX_CSTRING("ex")) return 7;
	if (inName==HX_CSTRING("mm")) return 2;
	if (inName==HX_CSTRING("pc")) return 4;
	if (inName==HX_CSTRING("pt")) return 3;
	if (inName==HX_CSTRING("px")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,cm,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,cssIn,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,em,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,ex,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,mm,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,pc,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,pt,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Length_obj,px,return)

int Length_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cm")) return 1;
	if (inName==HX_CSTRING("cssIn")) return 1;
	if (inName==HX_CSTRING("em")) return 1;
	if (inName==HX_CSTRING("ex")) return 1;
	if (inName==HX_CSTRING("mm")) return 1;
	if (inName==HX_CSTRING("pc")) return 1;
	if (inName==HX_CSTRING("pt")) return 1;
	if (inName==HX_CSTRING("px")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Length_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("cm")) return cm_dyn();
	if (inName==HX_CSTRING("cssIn")) return cssIn_dyn();
	if (inName==HX_CSTRING("em")) return em_dyn();
	if (inName==HX_CSTRING("ex")) return ex_dyn();
	if (inName==HX_CSTRING("mm")) return mm_dyn();
	if (inName==HX_CSTRING("pc")) return pc_dyn();
	if (inName==HX_CSTRING("pt")) return pt_dyn();
	if (inName==HX_CSTRING("px")) return px_dyn();
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("px"),
	HX_CSTRING("cm"),
	HX_CSTRING("mm"),
	HX_CSTRING("pt"),
	HX_CSTRING("pc"),
	HX_CSTRING("cssIn"),
	HX_CSTRING("em"),
	HX_CSTRING("ex"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static ::String sMemberFields[] = { ::String(null()) };
Class Length_obj::__mClass;

Dynamic __Create_Length_obj() { return new Length_obj; }

void Length_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.Length"), hx::TCanCast< Length_obj >,sStaticFields,sMemberFields,
	&__Create_Length_obj, &__Create,
	&super::__SGetClass(), &CreateLength_obj, sMarkStatics);
}

void Length_obj::__boot()
{
}


} // end namespace cocktail
} // end namespace core
} // end namespace unit