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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBRElement
#include <cocktail/core/html/HTMLBRElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLBRElement_obj::__construct()
{
HX_STACK_PUSH("HTMLBRElement::new","cocktail/core/html/HTMLBRElement.hx",20);
{
	HX_STACK_LINE(20)
	super::__construct(HX_CSTRING("BR"));
}
;
	return null();
}

HTMLBRElement_obj::~HTMLBRElement_obj() { }

Dynamic HTMLBRElement_obj::__CreateEmpty() { return  new HTMLBRElement_obj; }
hx::ObjectPtr< HTMLBRElement_obj > HTMLBRElement_obj::__new()
{  hx::ObjectPtr< HTMLBRElement_obj > result = new HTMLBRElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLBRElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLBRElement_obj > result = new HTMLBRElement_obj();
	result->__construct();
	return result;}

bool HTMLBRElement_obj::isVoidElement( ){
	HX_STACK_PUSH("HTMLBRElement::isVoidElement","cocktail/core/html/HTMLBRElement.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(34)
	return true;
}



HTMLBRElement_obj::HTMLBRElement_obj()
{
}

void HTMLBRElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLBRElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLBRElement_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLBRElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"isVoidElement") ) { return isVoidElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLBRElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLBRElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isVoidElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLBRElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLBRElement_obj::__mClass,"__mClass");
};

Class HTMLBRElement_obj::__mClass;

void HTMLBRElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLBRElement"), hx::TCanCast< HTMLBRElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLBRElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
