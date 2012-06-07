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
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLHtmlElement
#include <cocktail/core/html/AbstractHTMLHtmlElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void AbstractHTMLHtmlElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLHtmlElement.hx",35)
	super::__construct(HX_CSTRING("html"));
}
;
	return null();
}

AbstractHTMLHtmlElement_obj::~AbstractHTMLHtmlElement_obj() { }

Dynamic AbstractHTMLHtmlElement_obj::__CreateEmpty() { return  new AbstractHTMLHtmlElement_obj; }
hx::ObjectPtr< AbstractHTMLHtmlElement_obj > AbstractHTMLHtmlElement_obj::__new()
{  hx::ObjectPtr< AbstractHTMLHtmlElement_obj > result = new AbstractHTMLHtmlElement_obj();
	result->__construct();
	return result;}

Dynamic AbstractHTMLHtmlElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractHTMLHtmlElement_obj > result = new AbstractHTMLHtmlElement_obj();
	result->__construct();
	return result;}

::String AbstractHTMLHtmlElement_obj::HTML_HTML_TAG_NAME;


AbstractHTMLHtmlElement_obj::AbstractHTMLHtmlElement_obj()
{
}

void AbstractHTMLHtmlElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractHTMLHtmlElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractHTMLHtmlElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { return HTML_HTML_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic AbstractHTMLHtmlElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { HTML_HTML_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractHTMLHtmlElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_HTML_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLHtmlElement_obj::HTML_HTML_TAG_NAME,"HTML_HTML_TAG_NAME");
};

Class AbstractHTMLHtmlElement_obj::__mClass;

void AbstractHTMLHtmlElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.AbstractHTMLHtmlElement"), hx::TCanCast< AbstractHTMLHtmlElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLHtmlElement_obj::__boot()
{
	hx::Static(HTML_HTML_TAG_NAME) = HX_CSTRING("html");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
