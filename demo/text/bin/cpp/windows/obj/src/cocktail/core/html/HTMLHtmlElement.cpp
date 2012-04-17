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
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLHtmlElement
#include <cocktail/core/html/HTMLHtmlElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLHtmlElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLHtmlElement.hx",26)
	super::__construct(HX_CSTRING("html"));
}
;
	return null();
}

HTMLHtmlElement_obj::~HTMLHtmlElement_obj() { }

Dynamic HTMLHtmlElement_obj::__CreateEmpty() { return  new HTMLHtmlElement_obj; }
hx::ObjectPtr< HTMLHtmlElement_obj > HTMLHtmlElement_obj::__new()
{  hx::ObjectPtr< HTMLHtmlElement_obj > result = new HTMLHtmlElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLHtmlElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLHtmlElement_obj > result = new HTMLHtmlElement_obj();
	result->__construct();
	return result;}

::String HTMLHtmlElement_obj::HTML_HTML_TAG_NAME;


HTMLHtmlElement_obj::HTMLHtmlElement_obj()
{
}

void HTMLHtmlElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLHtmlElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLHtmlElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { return HTML_HTML_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic HTMLHtmlElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { HTML_HTML_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLHtmlElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_HTML_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLHtmlElement_obj::HTML_HTML_TAG_NAME,"HTML_HTML_TAG_NAME");
};

Class HTMLHtmlElement_obj::__mClass;

void HTMLHtmlElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLHtmlElement"), hx::TCanCast< HTMLHtmlElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLHtmlElement_obj::__boot()
{
	hx::Static(HTML_HTML_TAG_NAME) = HX_CSTRING("html");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
