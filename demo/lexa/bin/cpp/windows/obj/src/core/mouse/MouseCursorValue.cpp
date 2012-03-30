#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLImageElement
#include <core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_mouse_MouseCursorValue
#include <core/mouse/MouseCursorValue.h>
#endif
#ifndef INCLUDED_core_mouse_NativeOSMouseCursorValue
#include <core/mouse/NativeOSMouseCursorValue.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace mouse{

::core::mouse::MouseCursorValue MouseCursorValue_obj::cssAuto;

::core::mouse::MouseCursorValue  MouseCursorValue_obj::custom(::core::html::AbstractHTMLImageElement htmlImageElement,Dynamic hotSpot)
	{ return hx::CreateEnum< MouseCursorValue_obj >(HX_CSTRING("custom"),0,hx::DynamicArray(0,2).Add(htmlImageElement).Add(hotSpot)); }

::core::mouse::MouseCursorValue  MouseCursorValue_obj::native(::core::mouse::NativeOSMouseCursorValue nativeOSMouseCursorValue)
	{ return hx::CreateEnum< MouseCursorValue_obj >(HX_CSTRING("native"),3,hx::DynamicArray(0,1).Add(nativeOSMouseCursorValue)); }

::core::mouse::MouseCursorValue MouseCursorValue_obj::none;

HX_DEFINE_CREATE_ENUM(MouseCursorValue_obj)

int MouseCursorValue_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 1;
	if (inName==HX_CSTRING("custom")) return 0;
	if (inName==HX_CSTRING("native")) return 3;
	if (inName==HX_CSTRING("none")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC2(MouseCursorValue_obj,custom,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(MouseCursorValue_obj,native,return)

int MouseCursorValue_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("cssAuto")) return 0;
	if (inName==HX_CSTRING("custom")) return 2;
	if (inName==HX_CSTRING("native")) return 1;
	if (inName==HX_CSTRING("none")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic MouseCursorValue_obj::__Field(const ::String &inName)
{
	if (inName==HX_CSTRING("cssAuto")) return cssAuto;
	if (inName==HX_CSTRING("custom")) return custom_dyn();
	if (inName==HX_CSTRING("native")) return native_dyn();
	if (inName==HX_CSTRING("none")) return none;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_CSTRING("custom"),
	HX_CSTRING("cssAuto"),
	HX_CSTRING("none"),
	HX_CSTRING("native"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseCursorValue_obj::cssAuto,"cssAuto");
	HX_MARK_MEMBER_NAME(MouseCursorValue_obj::none,"none");
};

static ::String sMemberFields[] = { ::String(null()) };
Class MouseCursorValue_obj::__mClass;

Dynamic __Create_MouseCursorValue_obj() { return new MouseCursorValue_obj; }

void MouseCursorValue_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.mouse.MouseCursorValue"), hx::TCanCast< MouseCursorValue_obj >,sStaticFields,sMemberFields,
	&__Create_MouseCursorValue_obj, &__Create,
	&super::__SGetClass(), &CreateMouseCursorValue_obj, sMarkStatics);
}

void MouseCursorValue_obj::__boot()
{
Static(cssAuto) = hx::CreateEnum< MouseCursorValue_obj >(HX_CSTRING("cssAuto"),1);
Static(none) = hx::CreateEnum< MouseCursorValue_obj >(HX_CSTRING("none"),2);
}


} // end namespace core
} // end namespace mouse
