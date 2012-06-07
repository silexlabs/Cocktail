#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_focus_FocusManager
#include <cocktail/core/focus/FocusManager.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement
#include <cocktail/core/html/AbstractHTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLHtmlElement
#include <cocktail/core/html/AbstractHTMLHtmlElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLImageElement
#include <cocktail/core/html/AbstractHTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLInputElement
#include <cocktail/core/html/AbstractHTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLCanvasElement
#include <cocktail/core/html/HTMLCanvasElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLAnchorElement
#include <cocktail/port/flash_player/HTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLInputElement
#include <cocktail/port/flash_player/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Window
#include <cocktail/port/flash_player/Window.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLDocument_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",61)
	super::__construct();
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",63)
	this->_body = ::cocktail::core::html::HTMLBodyElement_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",65)
	this->_documentElement = ::cocktail::core::html::AbstractHTMLHtmlElement_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",66)
	this->_documentElement->appendChild(this->_body);
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",69)
	::cocktail::core::focus::FocusManager_obj::getInstance()->setBodyElement(this->_body);
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",72)
	this->_window = ::cocktail::port::flash_player::Window_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",73)
	this->_window->set_onResize(this->onWindowResize_dyn());
}
;
	return null();
}

HTMLDocument_obj::~HTMLDocument_obj() { }

Dynamic HTMLDocument_obj::__CreateEmpty() { return  new HTMLDocument_obj; }
hx::ObjectPtr< HTMLDocument_obj > HTMLDocument_obj::__new()
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct();
	return result;}

Dynamic HTMLDocument_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct();
	return result;}

::cocktail::port::flash_player::HTMLElement HTMLDocument_obj::createElement( ::String tagName){
	HX_SOURCE_PUSH("HTMLDocument_obj::createElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",87)
	::cocktail::port::flash_player::HTMLElement element;
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",89)
	::String _switch_1 = (tagName.toLowerCase());
	if (  ( _switch_1==HX_CSTRING("img"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",91)
		element = ::cocktail::core::html::AbstractHTMLImageElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("canvas"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",94)
		element = ::cocktail::core::html::HTMLCanvasElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("input"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",97)
		element = ::cocktail::port::flash_player::HTMLInputElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("a"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",100)
		element = ::cocktail::port::flash_player::HTMLAnchorElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("html"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",103)
		element = ::cocktail::core::html::AbstractHTMLHtmlElement_obj::__new();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",106)
		element = ::cocktail::port::flash_player::HTMLElement_obj::__new(tagName);
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",110)
	return element;
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,createElement,return )

Void HTMLDocument_obj::onWindowResize( ::cocktail::core::event::Event event){
{
		HX_SOURCE_PUSH("HTMLDocument_obj::onWindowResize")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",123)
		this->_body->get_coreStyle()->invalidate(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,onWindowResize,(void))

::cocktail::port::flash_player::HTMLElement HTMLDocument_obj::get_body( ){
	HX_SOURCE_PUSH("HTMLDocument_obj::get_body")
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLDocument.hx",132)
	return this->_body;
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLDocument_obj,get_body,return )

::String HTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME;

::String HTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME;

::String HTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME;

::String HTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME;

::String HTMLDocument_obj::HTML_HTML_TAG_NAME;


HTMLDocument_obj::HTMLDocument_obj()
{
}

void HTMLDocument_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLDocument);
	HX_MARK_MEMBER_NAME(_body,"_body");
	HX_MARK_MEMBER_NAME(body,"body");
	HX_MARK_MEMBER_NAME(_window,"_window");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLDocument_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { return get_body(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_body") ) { return _body; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { return _window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_body") ) { return get_body_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onWindowResize") ) { return onWindowResize_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { return HTML_HTML_TAG_NAME; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_ELEMENT_TAG_NAME") ) { return HTML_IMAGE_ELEMENT_TAG_NAME; }
		if (HX_FIELD_EQ(inName,"HTML_INPUT_ELEMENT_TAG_NAME") ) { return HTML_INPUT_ELEMENT_TAG_NAME; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"HTML_CANVAS_ELEMENT_TAG_NAME") ) { return HTML_CANVAS_ELEMENT_TAG_NAME; }
		if (HX_FIELD_EQ(inName,"HTML_ANCHOR_ELEMENT_TAG_NAME") ) { return HTML_ANCHOR_ELEMENT_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic HTMLDocument_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { body=inValue.Cast< ::cocktail::port::flash_player::HTMLElement >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_body") ) { _body=inValue.Cast< ::cocktail::port::flash_player::HTMLElement >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { _window=inValue.Cast< ::cocktail::port::flash_player::Window >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { HTML_HTML_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"HTML_IMAGE_ELEMENT_TAG_NAME") ) { HTML_IMAGE_ELEMENT_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HTML_INPUT_ELEMENT_TAG_NAME") ) { HTML_INPUT_ELEMENT_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"HTML_CANVAS_ELEMENT_TAG_NAME") ) { HTML_CANVAS_ELEMENT_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HTML_ANCHOR_ELEMENT_TAG_NAME") ) { HTML_ANCHOR_ELEMENT_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLDocument_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_body"));
	outFields->push(HX_CSTRING("body"));
	outFields->push(HX_CSTRING("_window"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_IMAGE_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_CANVAS_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_INPUT_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_ANCHOR_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_HTML_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_body"),
	HX_CSTRING("body"),
	HX_CSTRING("_window"),
	HX_CSTRING("createElement"),
	HX_CSTRING("onWindowResize"),
	HX_CSTRING("get_body"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME,"HTML_IMAGE_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME,"HTML_CANVAS_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME,"HTML_INPUT_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME,"HTML_ANCHOR_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(HTMLDocument_obj::HTML_HTML_TAG_NAME,"HTML_HTML_TAG_NAME");
};

Class HTMLDocument_obj::__mClass;

void HTMLDocument_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLDocument"), hx::TCanCast< HTMLDocument_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLDocument_obj::__boot()
{
	hx::Static(HTML_IMAGE_ELEMENT_TAG_NAME) = HX_CSTRING("img");
	hx::Static(HTML_CANVAS_ELEMENT_TAG_NAME) = HX_CSTRING("canvas");
	hx::Static(HTML_INPUT_ELEMENT_TAG_NAME) = HX_CSTRING("input");
	hx::Static(HTML_ANCHOR_ELEMENT_TAG_NAME) = HX_CSTRING("a");
	hx::Static(HTML_HTML_TAG_NAME) = HX_CSTRING("html");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
