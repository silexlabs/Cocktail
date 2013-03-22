#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeInputBase
#include <cocktail/port/base/NativeInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeTextInputBase
#include <cocktail/port/base/NativeTextInputBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativePasswordInput
#include <cocktail/port/platform/flash_player/NativePasswordInput.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeTextInput
#include <cocktail/port/platform/flash_player/NativeTextInput.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_text_TextField
#include <neash/text/TextField.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void NativePasswordInput_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("NativePasswordInput::new","cocktail/port/platform/flash_player/NativePasswordInput.hx",23);
{
	HX_STACK_LINE(24)
	super::__construct(node);
	HX_STACK_LINE(25)
	this->_textField->nmeSetDisplayAsPassword(true);
}
;
	return null();
}

NativePasswordInput_obj::~NativePasswordInput_obj() { }

Dynamic NativePasswordInput_obj::__CreateEmpty() { return  new NativePasswordInput_obj; }
hx::ObjectPtr< NativePasswordInput_obj > NativePasswordInput_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< NativePasswordInput_obj > result = new NativePasswordInput_obj();
	result->__construct(node);
	return result;}

Dynamic NativePasswordInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativePasswordInput_obj > result = new NativePasswordInput_obj();
	result->__construct(inArgs[0]);
	return result;}


NativePasswordInput_obj::NativePasswordInput_obj()
{
}

void NativePasswordInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativePasswordInput);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativePasswordInput_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativePasswordInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic NativePasswordInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NativePasswordInput_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativePasswordInput_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativePasswordInput_obj::__mClass,"__mClass");
};

Class NativePasswordInput_obj::__mClass;

void NativePasswordInput_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.NativePasswordInput"), hx::TCanCast< NativePasswordInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativePasswordInput_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
