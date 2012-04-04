#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
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
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void HTMLElement_obj::__construct(::String tagName)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLElement.hx",22)
	super::__construct(tagName);
}
;
	return null();
}

HTMLElement_obj::~HTMLElement_obj() { }

Dynamic HTMLElement_obj::__CreateEmpty() { return  new HTMLElement_obj; }
hx::ObjectPtr< HTMLElement_obj > HTMLElement_obj::__new(::String tagName)
{  hx::ObjectPtr< HTMLElement_obj > result = new HTMLElement_obj();
	result->__construct(tagName);
	return result;}

Dynamic HTMLElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLElement_obj > result = new HTMLElement_obj();
	result->__construct(inArgs[0]);
	return result;}


HTMLElement_obj::HTMLElement_obj()
{
}

void HTMLElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLElement_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic HTMLElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void HTMLElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class HTMLElement_obj::__mClass;

void HTMLElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.HTMLElement"), hx::TCanCast< HTMLElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
