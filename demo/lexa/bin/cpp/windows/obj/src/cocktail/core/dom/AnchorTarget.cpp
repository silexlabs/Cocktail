#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_AnchorTarget
#include <cocktail/core/dom/AnchorTarget.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

::cocktail::core::dom::AnchorTarget AnchorTarget_obj::blank;

::cocktail::core::dom::AnchorTarget AnchorTarget_obj::parent;

::cocktail::core::dom::AnchorTarget AnchorTarget_obj::self;

::cocktail::core::dom::AnchorTarget AnchorTarget_obj::top;

HX_DEFINE_CREATE_ENUM(AnchorTarget_obj)

int AnchorTarget_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("blank")) return 0;
	if (inName==HX_CSTRING("parent")) return 2;
	if (inName==HX_CSTRING("self")) return 1;
	if (inName==HX_CSTRING("top")) return 3;
	return super::__FindIndex(inName);
}

int AnchorTarget_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("blank")) return 0;
	if (inName==HX_CSTRING("parent")) return 0;
	if (inName==HX_CSTRING("self")) return 0;
	if (inName==HX_CSTRING("top")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AnchorTarget_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("blank")) return blank;
	if (inName==HX_CSTRING("parent")) return parent;
	if (inName==HX_CSTRING("self")) return self;
	if (inName==HX_CSTRING("top")) return top;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("blank"),
	HX_CSTRING("self"),
	HX_CSTRING("parent"),
	HX_CSTRING("top"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnchorTarget_obj::blank,"blank");
	HX_MARK_MEMBER_NAME(AnchorTarget_obj::parent,"parent");
	HX_MARK_MEMBER_NAME(AnchorTarget_obj::self,"self");
	HX_MARK_MEMBER_NAME(AnchorTarget_obj::top,"top");
};

static ::String sMemberFields[] = { ::String(null()) };
Class AnchorTarget_obj::__mClass;

Dynamic __Create_AnchorTarget_obj() { return new AnchorTarget_obj; }

void AnchorTarget_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.AnchorTarget"), hx::TCanCast< AnchorTarget_obj >,sStaticFields,sMemberFields,
	&__Create_AnchorTarget_obj, &__Create,
	&super::__SGetClass(), &CreateAnchorTarget_obj, sMarkStatics);
}

void AnchorTarget_obj::__boot()
{
Static(blank) = hx::CreateEnum< AnchorTarget_obj >(HX_CSTRING("blank"),0);
Static(parent) = hx::CreateEnum< AnchorTarget_obj >(HX_CSTRING("parent"),2);
Static(self) = hx::CreateEnum< AnchorTarget_obj >(HX_CSTRING("self"),1);
Static(top) = hx::CreateEnum< AnchorTarget_obj >(HX_CSTRING("top"),3);
}


} // end namespace cocktail
} // end namespace core
} // end namespace dom
