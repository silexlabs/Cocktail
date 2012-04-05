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
#ifndef INCLUDED_core_html_AbstractHTMLInputElement
#include <core/html/AbstractHTMLInputElement.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLInputElement
#include <port/flash_player/HTMLInputElement.h>
#endif
namespace port{
namespace flash_player{

Void HTMLInputElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/port/flash_player/HTMLInputElement.hx",25)
	super::__construct();
}
;
	return null();
}

HTMLInputElement_obj::~HTMLInputElement_obj() { }

Dynamic HTMLInputElement_obj::__CreateEmpty() { return  new HTMLInputElement_obj; }
hx::ObjectPtr< HTMLInputElement_obj > HTMLInputElement_obj::__new()
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLInputElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLInputElement_obj > result = new HTMLInputElement_obj();
	result->__construct();
	return result;}


HTMLInputElement_obj::HTMLInputElement_obj()
{
}

void HTMLInputElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLInputElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLInputElement_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic HTMLInputElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void HTMLInputElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class HTMLInputElement_obj::__mClass;

void HTMLInputElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("port.flash_player.HTMLInputElement"), hx::TCanCast< HTMLInputElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLInputElement_obj::__boot()
{
}

} // end namespace port
} // end namespace flash_player
