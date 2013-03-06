#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_layout_LayoutStateValue
#include <cocktail/core/layout/LayoutStateValue.h>
#endif
namespace cocktail{
namespace core{
namespace layout{

::cocktail::core::layout::LayoutStateValue LayoutStateValue_obj::NORMAL;

::cocktail::core::layout::LayoutStateValue LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH;

::cocktail::core::layout::LayoutStateValue LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_WIDTH;

HX_DEFINE_CREATE_ENUM(LayoutStateValue_obj)

int LayoutStateValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("NORMAL")) return 0;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH")) return 2;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_WIDTH")) return 1;
	return super::__FindIndex(inName);
}

int LayoutStateValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("NORMAL")) return 0;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH")) return 0;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_WIDTH")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LayoutStateValue_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("NORMAL")) return NORMAL;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH")) return SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH;
	if (inName==HX_CSTRING("SHRINK_TO_FIT_PREFERED_WIDTH")) return SHRINK_TO_FIT_PREFERED_WIDTH;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("SHRINK_TO_FIT_PREFERED_WIDTH"),
	HX_CSTRING("SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LayoutStateValue_obj::NORMAL,"NORMAL");
	HX_MARK_MEMBER_NAME(LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH,"SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH");
	HX_MARK_MEMBER_NAME(LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_WIDTH,"SHRINK_TO_FIT_PREFERED_WIDTH");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LayoutStateValue_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LayoutStateValue_obj::NORMAL,"NORMAL");
	HX_VISIT_MEMBER_NAME(LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH,"SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH");
	HX_VISIT_MEMBER_NAME(LayoutStateValue_obj::SHRINK_TO_FIT_PREFERED_WIDTH,"SHRINK_TO_FIT_PREFERED_WIDTH");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LayoutStateValue_obj::__mClass;

Dynamic __Create_LayoutStateValue_obj() { return new LayoutStateValue_obj; }

void LayoutStateValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.LayoutStateValue"), hx::TCanCast< LayoutStateValue_obj >,sStaticFields,sMemberFields,
	&__Create_LayoutStateValue_obj, &__Create,
	&super::__SGetClass(), &CreateLayoutStateValue_obj, sMarkStatics, sVisitStatic);
}

void LayoutStateValue_obj::__boot()
{
Static(NORMAL) = hx::CreateEnum< LayoutStateValue_obj >(HX_CSTRING("NORMAL"),0);
Static(SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH) = hx::CreateEnum< LayoutStateValue_obj >(HX_CSTRING("SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH"),2);
Static(SHRINK_TO_FIT_PREFERED_WIDTH) = hx::CreateEnum< LayoutStateValue_obj >(HX_CSTRING("SHRINK_TO_FIT_PREFERED_WIDTH"),1);
}


} // end namespace cocktail
} // end namespace core
} // end namespace layout
