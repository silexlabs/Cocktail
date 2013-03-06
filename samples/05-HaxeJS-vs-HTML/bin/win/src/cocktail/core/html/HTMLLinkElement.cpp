#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_XMLHttpRequestEventTarget
#include <cocktail/core/event/XMLHttpRequestEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLLinkElement
#include <cocktail/core/html/HTMLLinkElement.h>
#endif
#ifndef INCLUDED_cocktail_core_http_XMLHTTPRequest
#include <cocktail/core/http/XMLHTTPRequest.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLLinkElement_obj::__construct()
{
HX_STACK_PUSH("HTMLLinkElement::new","cocktail/core/html/HTMLLinkElement.hx",103);
{
	HX_STACK_LINE(104)
	super::__construct(HX_CSTRING("LINK"));
	HX_STACK_LINE(105)
	this->_hasLoadedResource = false;
}
;
	return null();
}

HTMLLinkElement_obj::~HTMLLinkElement_obj() { }

Dynamic HTMLLinkElement_obj::__CreateEmpty() { return  new HTMLLinkElement_obj; }
hx::ObjectPtr< HTMLLinkElement_obj > HTMLLinkElement_obj::__new()
{  hx::ObjectPtr< HTMLLinkElement_obj > result = new HTMLLinkElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLLinkElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLLinkElement_obj > result = new HTMLLinkElement_obj();
	result->__construct();
	return result;}

::String HTMLLinkElement_obj::set_type( ::String value){
	HX_STACK_PUSH("HTMLLinkElement::set_type","cocktail/core/html/HTMLLinkElement.hx",296);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(297)
	this->setAttribute(HX_CSTRING("type"),value);
	HX_STACK_LINE(298)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_type,return )

::String HTMLLinkElement_obj::get_type( ){
	HX_STACK_PUSH("HTMLLinkElement::get_type","cocktail/core/html/HTMLLinkElement.hx",291);
	HX_STACK_THIS(this);
	HX_STACK_LINE(291)
	return this->getAttribute(HX_CSTRING("type"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_type,return )

::String HTMLLinkElement_obj::set_hreflang( ::String value){
	HX_STACK_PUSH("HTMLLinkElement::set_hreflang","cocktail/core/html/HTMLLinkElement.hx",285);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(286)
	this->setAttribute(HX_CSTRING("hreflang"),value);
	HX_STACK_LINE(287)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_hreflang,return )

::String HTMLLinkElement_obj::get_hreflang( ){
	HX_STACK_PUSH("HTMLLinkElement::get_hreflang","cocktail/core/html/HTMLLinkElement.hx",280);
	HX_STACK_THIS(this);
	HX_STACK_LINE(280)
	return this->getAttribute(HX_CSTRING("hreflang"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_hreflang,return )

::String HTMLLinkElement_obj::set_media( ::String value){
	HX_STACK_PUSH("HTMLLinkElement::set_media","cocktail/core/html/HTMLLinkElement.hx",274);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(275)
	this->setAttribute(HX_CSTRING("media"),value);
	HX_STACK_LINE(276)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_media,return )

::String HTMLLinkElement_obj::get_media( ){
	HX_STACK_PUSH("HTMLLinkElement::get_media","cocktail/core/html/HTMLLinkElement.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_LINE(269)
	return this->getAttribute(HX_CSTRING("media"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_media,return )

Array< ::String > HTMLLinkElement_obj::get_relList( ){
	HX_STACK_PUSH("HTMLLinkElement::get_relList","cocktail/core/html/HTMLLinkElement.hx",264);
	HX_STACK_THIS(this);
	HX_STACK_LINE(264)
	return Array_obj< ::String >::__new();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_relList,return )

::String HTMLLinkElement_obj::set_rel( ::String value){
	HX_STACK_PUSH("HTMLLinkElement::set_rel","cocktail/core/html/HTMLLinkElement.hx",257);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(258)
	this->setAttribute(HX_CSTRING("rel"),value);
	HX_STACK_LINE(259)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_rel,return )

::String HTMLLinkElement_obj::get_rel( ){
	HX_STACK_PUSH("HTMLLinkElement::get_rel","cocktail/core/html/HTMLLinkElement.hx",252);
	HX_STACK_THIS(this);
	HX_STACK_LINE(252)
	return this->getAttribute(HX_CSTRING("rel"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_rel,return )

::String HTMLLinkElement_obj::set_href( ::String value){
	HX_STACK_PUSH("HTMLLinkElement::set_href","cocktail/core/html/HTMLLinkElement.hx",246);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(247)
	this->setAttribute(HX_CSTRING("href"),value);
	HX_STACK_LINE(248)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_href,return )

::String HTMLLinkElement_obj::get_href( ){
	HX_STACK_PUSH("HTMLLinkElement::get_href","cocktail/core/html/HTMLLinkElement.hx",241);
	HX_STACK_THIS(this);
	HX_STACK_LINE(241)
	return this->getAttribute(HX_CSTRING("href"));
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_href,return )

bool HTMLLinkElement_obj::set_disabled( bool value){
	HX_STACK_PUSH("HTMLLinkElement::set_disabled","cocktail/core/html/HTMLLinkElement.hx",235);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(236)
	this->super::setAttribute(HX_CSTRING("disabled"),::Std_obj::string(value));
	HX_STACK_LINE(237)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,set_disabled,return )

bool HTMLLinkElement_obj::get_disabled( ){
	HX_STACK_PUSH("HTMLLinkElement::get_disabled","cocktail/core/html/HTMLLinkElement.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_LINE(223)
	if (((this->getAttribute(HX_CSTRING("disabled")) != null()))){
		HX_STACK_LINE(225)
		return true;
	}
	else{
		HX_STACK_LINE(229)
		return false;
	}
	HX_STACK_LINE(223)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,get_disabled,return )

Void HTMLLinkElement_obj::createStyleSheet( ::String css){
{
		HX_STACK_PUSH("HTMLLinkElement::createStyleSheet","cocktail/core/html/HTMLLinkElement.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_ARG(css,"css");
		HX_STACK_LINE(213)
		this->sheet = ::cocktail::core::css::CSSStyleSheet_obj::__new(css,::cocktail::core::css::PropertyOriginValue_obj::AUTHOR_dyn(),null(),null(),null(),null());
		HX_STACK_LINE(214)
		::cocktail::core::html::HTMLDocument htmlDocument = this->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(215)
		htmlDocument->addStyleSheet(this->sheet);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,createStyleSheet,(void))

Void HTMLLinkElement_obj::onCSSLoaded( ::cocktail::core::event::Event event){
{
		HX_STACK_PUSH("HTMLLinkElement::onCSSLoaded","cocktail/core/html/HTMLLinkElement.hx",202);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(203)
		::cocktail::core::http::XMLHTTPRequest xmlHttpRequest = event->target;		HX_STACK_VAR(xmlHttpRequest,"xmlHttpRequest");
		HX_STACK_LINE(204)
		this->createStyleSheet(xmlHttpRequest->get_responseText());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLLinkElement_obj,onCSSLoaded,(void))

Void HTMLLinkElement_obj::unloadLinkedResource( ){
{
		HX_STACK_PUSH("HTMLLinkElement::unloadLinkedResource","cocktail/core/html/HTMLLinkElement.hx",184);
		HX_STACK_THIS(this);
		HX_STACK_LINE(184)
		if (((this->sheet != null()))){
			HX_STACK_LINE(189)
			::cocktail::core::html::HTMLDocument htmlDocument = this->ownerDocument;		HX_STACK_VAR(htmlDocument,"htmlDocument");
			HX_STACK_LINE(190)
			htmlDocument->removeStyleSheet(this->sheet);
			HX_STACK_LINE(191)
			this->sheet = null();
			HX_STACK_LINE(193)
			this->_hasLoadedResource = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,unloadLinkedResource,(void))

Void HTMLLinkElement_obj::loadLinkedResource( ){
{
		HX_STACK_PUSH("HTMLLinkElement::loadLinkedResource","cocktail/core/html/HTMLLinkElement.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(165)
		if (((bool((bool((this->get_type() == HX_CSTRING("text/css"))) && bool((this->get_href() != null())))) && bool((this->get_rel() == HX_CSTRING("stylesheet")))))){
			HX_STACK_LINE(170)
			this->_hasLoadedResource = true;
			HX_STACK_LINE(172)
			::cocktail::core::http::XMLHTTPRequest xmlHttpRequest = ::cocktail::core::http::XMLHTTPRequest_obj::__new();		HX_STACK_VAR(xmlHttpRequest,"xmlHttpRequest");
			HX_STACK_LINE(173)
			xmlHttpRequest->open(HX_CSTRING("GET"),this->get_href(),null(),null(),null());
			HX_STACK_LINE(174)
			xmlHttpRequest->addEventListener(HX_CSTRING("loadend"),this->onCSSLoaded_dyn(),null());
			HX_STACK_LINE(175)
			xmlHttpRequest->send(null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLLinkElement_obj,loadLinkedResource,(void))

Void HTMLLinkElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLLinkElement::createElementRenderer","cocktail/core/html/HTMLLinkElement.hx",148);
		HX_STACK_THIS(this);
	}
return null();
}


Void HTMLLinkElement_obj::removedFromDOM( ){
{
		HX_STACK_PUSH("HTMLLinkElement::removedFromDOM","cocktail/core/html/HTMLLinkElement.hx",132);
		HX_STACK_THIS(this);
		HX_STACK_LINE(133)
		this->super::removedFromDOM();
		HX_STACK_LINE(134)
		if (((this->_hasLoadedResource == true))){
			HX_STACK_LINE(135)
			this->unloadLinkedResource();
		}
	}
return null();
}


Void HTMLLinkElement_obj::addedToDOM( ){
{
		HX_STACK_PUSH("HTMLLinkElement::addedToDOM","cocktail/core/html/HTMLLinkElement.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_LINE(119)
		if (((this->_hasLoadedResource == false))){
			HX_STACK_LINE(120)
			this->loadLinkedResource();
		}
		HX_STACK_LINE(123)
		this->super::addedToDOM();
	}
return null();
}



HTMLLinkElement_obj::HTMLLinkElement_obj()
{
}

void HTMLLinkElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLLinkElement);
	HX_MARK_MEMBER_NAME(_hasLoadedResource,"_hasLoadedResource");
	HX_MARK_MEMBER_NAME(sheet,"sheet");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(hreflang,"hreflang");
	HX_MARK_MEMBER_NAME(media,"media");
	HX_MARK_MEMBER_NAME(relList,"relList");
	HX_MARK_MEMBER_NAME(rel,"rel");
	HX_MARK_MEMBER_NAME(href,"href");
	HX_MARK_MEMBER_NAME(disabled,"disabled");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLLinkElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_hasLoadedResource,"_hasLoadedResource");
	HX_VISIT_MEMBER_NAME(sheet,"sheet");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(hreflang,"hreflang");
	HX_VISIT_MEMBER_NAME(media,"media");
	HX_VISIT_MEMBER_NAME(relList,"relList");
	HX_VISIT_MEMBER_NAME(rel,"rel");
	HX_VISIT_MEMBER_NAME(href,"href");
	HX_VISIT_MEMBER_NAME(disabled,"disabled");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLLinkElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rel") ) { return inCallProp ? get_rel() : rel; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		if (HX_FIELD_EQ(inName,"href") ) { return inCallProp ? get_href() : href; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sheet") ) { return sheet; }
		if (HX_FIELD_EQ(inName,"media") ) { return inCallProp ? get_media() : media; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_rel") ) { return set_rel_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rel") ) { return get_rel_dyn(); }
		if (HX_FIELD_EQ(inName,"relList") ) { return inCallProp ? get_relList() : relList; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_type") ) { return set_type_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"set_href") ) { return set_href_dyn(); }
		if (HX_FIELD_EQ(inName,"get_href") ) { return get_href_dyn(); }
		if (HX_FIELD_EQ(inName,"hreflang") ) { return inCallProp ? get_hreflang() : hreflang; }
		if (HX_FIELD_EQ(inName,"disabled") ) { return inCallProp ? get_disabled() : disabled; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_media") ) { return set_media_dyn(); }
		if (HX_FIELD_EQ(inName,"get_media") ) { return get_media_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addedToDOM") ) { return addedToDOM_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_relList") ) { return get_relList_dyn(); }
		if (HX_FIELD_EQ(inName,"onCSSLoaded") ) { return onCSSLoaded_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_hreflang") ) { return set_hreflang_dyn(); }
		if (HX_FIELD_EQ(inName,"get_hreflang") ) { return get_hreflang_dyn(); }
		if (HX_FIELD_EQ(inName,"set_disabled") ) { return set_disabled_dyn(); }
		if (HX_FIELD_EQ(inName,"get_disabled") ) { return get_disabled_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"removedFromDOM") ) { return removedFromDOM_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"createStyleSheet") ) { return createStyleSheet_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"loadLinkedResource") ) { return loadLinkedResource_dyn(); }
		if (HX_FIELD_EQ(inName,"_hasLoadedResource") ) { return _hasLoadedResource; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"unloadLinkedResource") ) { return unloadLinkedResource_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLLinkElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rel") ) { if (inCallProp) return set_rel(inValue);rel=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { if (inCallProp) return set_type(inValue);type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"href") ) { if (inCallProp) return set_href(inValue);href=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sheet") ) { sheet=inValue.Cast< ::cocktail::core::css::CSSStyleSheet >(); return inValue; }
		if (HX_FIELD_EQ(inName,"media") ) { if (inCallProp) return set_media(inValue);media=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"relList") ) { relList=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"hreflang") ) { if (inCallProp) return set_hreflang(inValue);hreflang=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disabled") ) { if (inCallProp) return set_disabled(inValue);disabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_hasLoadedResource") ) { _hasLoadedResource=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLLinkElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_hasLoadedResource"));
	outFields->push(HX_CSTRING("sheet"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("hreflang"));
	outFields->push(HX_CSTRING("media"));
	outFields->push(HX_CSTRING("relList"));
	outFields->push(HX_CSTRING("rel"));
	outFields->push(HX_CSTRING("href"));
	outFields->push(HX_CSTRING("disabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_type"),
	HX_CSTRING("get_type"),
	HX_CSTRING("set_hreflang"),
	HX_CSTRING("get_hreflang"),
	HX_CSTRING("set_media"),
	HX_CSTRING("get_media"),
	HX_CSTRING("get_relList"),
	HX_CSTRING("set_rel"),
	HX_CSTRING("get_rel"),
	HX_CSTRING("set_href"),
	HX_CSTRING("get_href"),
	HX_CSTRING("set_disabled"),
	HX_CSTRING("get_disabled"),
	HX_CSTRING("createStyleSheet"),
	HX_CSTRING("onCSSLoaded"),
	HX_CSTRING("unloadLinkedResource"),
	HX_CSTRING("loadLinkedResource"),
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("removedFromDOM"),
	HX_CSTRING("addedToDOM"),
	HX_CSTRING("_hasLoadedResource"),
	HX_CSTRING("sheet"),
	HX_CSTRING("type"),
	HX_CSTRING("hreflang"),
	HX_CSTRING("media"),
	HX_CSTRING("relList"),
	HX_CSTRING("rel"),
	HX_CSTRING("href"),
	HX_CSTRING("disabled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLLinkElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLLinkElement_obj::__mClass,"__mClass");
};

Class HTMLLinkElement_obj::__mClass;

void HTMLLinkElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLLinkElement"), hx::TCanCast< HTMLLinkElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLLinkElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
