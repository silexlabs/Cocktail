#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_FillStyleValue
#include <cocktail/core/dom/FillStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLImageElement
#include <cocktail/core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

::cocktail::core::dom::FillStyleValue  FillStyleValue_obj::bitmap(::cocktail::core::html::AbstractHTMLImageElement htmlImageElement,bool repeat)
	{ return hx::CreateEnum< FillStyleValue_obj >(HX_CSTRING("bitmap"),3,hx::DynamicArray(0,2).Add(htmlImageElement).Add(repeat)); }

::cocktail::core::dom::FillStyleValue  FillStyleValue_obj::gradient(Dynamic gradientStyle)
	{ return hx::CreateEnum< FillStyleValue_obj >(HX_CSTRING("gradient"),2,hx::DynamicArray(0,1).Add(gradientStyle)); }

::cocktail::core::dom::FillStyleValue  FillStyleValue_obj::monochrome(Dynamic colorStop)
	{ return hx::CreateEnum< FillStyleValue_obj >(HX_CSTRING("monochrome"),1,hx::DynamicArray(0,1).Add(colorStop)); }

::cocktail::core::dom::FillStyleValue FillStyleValue_obj::none;

HX_DEFINE_CREATE_ENUM(FillStyleValue_obj)

int FillStyleValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bitmap")) return 3;
	if (inName==HX_CSTRING("gradient")) return 2;
	if (inName==HX_CSTRING("monochrome")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC2(FillStyleValue_obj,bitmap,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FillStyleValue_obj,gradient,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FillStyleValue_obj,monochrome,return)

int FillStyleValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bitmap")) return 2;
	if (inName==HX_CSTRING("gradient")) return 1;
	if (inName==HX_CSTRING("monochrome")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FillStyleValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("bitmap")) return bitmap_dyn();
	if (inName==HX_CSTRING("gradient")) return gradient_dyn();
	if (inName==HX_CSTRING("monochrome")) return monochrome_dyn();
	if (inName==HX_CSTRING("none")) return none;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("none"),
	HX_CSTRING("monochrome"),
	HX_CSTRING("gradient"),
	HX_CSTRING("bitmap"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FillStyleValue_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FillStyleValue_obj::__mClass;

Dynamic __Create_FillStyleValue_obj() { return new FillStyleValue_obj; }

void FillStyleValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.FillStyleValue"), hx::TCanCast< FillStyleValue_obj >,sStaticFields,sMemberFields,
	&__Create_FillStyleValue_obj, &__Create,
	&super::__SGetClass(), &CreateFillStyleValue_obj, sMarkStatics);
}

void FillStyleValue_obj::__boot()
{
Static(none) = hx::CreateEnum< FillStyleValue_obj >(HX_CSTRING("none"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace dom
