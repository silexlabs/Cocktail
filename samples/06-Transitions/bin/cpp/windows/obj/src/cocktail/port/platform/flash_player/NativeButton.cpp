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
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeButton
#include <cocktail/port/platform/flash_player/NativeButton.h>
#endif
namespace cocktail{
namespace port{
namespace platform{
namespace flash_player{

Void NativeButton_obj::__construct(::cocktail::core::html::HTMLElement node)
{
HX_STACK_PUSH("NativeButton::new","cocktail/port/platform/flash_player/NativeButton.hx",29);
{
	HX_STACK_LINE(29)
	super::__construct(node);
}
;
	return null();
}

NativeButton_obj::~NativeButton_obj() { }

Dynamic NativeButton_obj::__CreateEmpty() { return  new NativeButton_obj; }
hx::ObjectPtr< NativeButton_obj > NativeButton_obj::__new(::cocktail::core::html::HTMLElement node)
{  hx::ObjectPtr< NativeButton_obj > result = new NativeButton_obj();
	result->__construct(node);
	return result;}

Dynamic NativeButton_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeButton_obj > result = new NativeButton_obj();
	result->__construct(inArgs[0]);
	return result;}

::String NativeButton_obj::set_value( ::String textValue){
	HX_STACK_PUSH("NativeButton::set_value","cocktail/port/platform/flash_player/NativeButton.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_ARG(textValue,"textValue");
	HX_STACK_LINE(35)
	this->_node->set_innerHTML(textValue);
	HX_STACK_LINE(36)
	return textValue;
}



NativeButton_obj::NativeButton_obj()
{
}

void NativeButton_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(NativeButton);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void NativeButton_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic NativeButton_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"set_value") ) { return set_value_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic NativeButton_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeButton_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeButton_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeButton_obj::__mClass,"__mClass");
};

Class NativeButton_obj::__mClass;

void NativeButton_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.platform.flash_player.NativeButton"), hx::TCanCast< NativeButton_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void NativeButton_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace platform
} // end namespace flash_player
