#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_LineStyleValue
#include <cocktail/core/dom/LineStyleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
namespace cocktail{
namespace core{
namespace dom{

::cocktail::core::dom::LineStyleValue  LineStyleValue_obj::bitmap(::cocktail::core::html::HTMLImageElement htmlImageElement,Dynamic lineStyle,bool repeat)
	{ return hx::CreateEnum< LineStyleValue_obj >(HX_CSTRING("bitmap"),3,hx::DynamicArray(0,3).Add(htmlImageElement).Add(lineStyle).Add(repeat)); }

::cocktail::core::dom::LineStyleValue  LineStyleValue_obj::gradient(Dynamic gradientStyle,Dynamic lineStyle)
	{ return hx::CreateEnum< LineStyleValue_obj >(HX_CSTRING("gradient"),2,hx::DynamicArray(0,2).Add(gradientStyle).Add(lineStyle)); }

::cocktail::core::dom::LineStyleValue  LineStyleValue_obj::monochrome(Dynamic color,Dynamic lineStyle)
	{ return hx::CreateEnum< LineStyleValue_obj >(HX_CSTRING("monochrome"),1,hx::DynamicArray(0,2).Add(color).Add(lineStyle)); }

::cocktail::core::dom::LineStyleValue LineStyleValue_obj::none;

HX_DEFINE_CREATE_ENUM(LineStyleValue_obj)

int LineStyleValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("bitmap")) return 3;
	if (inName==HX_CSTRING("gradient")) return 2;
	if (inName==HX_CSTRING("monochrome")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC3(LineStyleValue_obj,bitmap,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(LineStyleValue_obj,gradient,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(LineStyleValue_obj,monochrome,return)

int LineStyleValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("bitmap")) return 3;
	if (inName==HX_CSTRING("gradient")) return 2;
	if (inName==HX_CSTRING("monochrome")) return 2;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic LineStyleValue_obj::__Field(const ::String &inName)
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
	HX_MARK_MEMBER_NAME(LineStyleValue_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class LineStyleValue_obj::__mClass;

Dynamic __Create_LineStyleValue_obj() { return new LineStyleValue_obj; }

void LineStyleValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.dom.LineStyleValue"), hx::TCanCast< LineStyleValue_obj >,sStaticFields,sMemberFields,
	&__Create_LineStyleValue_obj, &__Create,
	&super::__SGetClass(), &CreateLineStyleValue_obj, sMarkStatics);
}

void LineStyleValue_obj::__boot()
{
Static(none) = hx::CreateEnum< LineStyleValue_obj >(HX_CSTRING("none"),0);
}


} // end namespace cocktail
} // end namespace core
} // end namespace dom
