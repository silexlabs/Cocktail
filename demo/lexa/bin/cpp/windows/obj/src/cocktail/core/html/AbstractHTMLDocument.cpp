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
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
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
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BodyCoreStyle
#include <cocktail/core/style/BodyCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ContainerCoreStyle
#include <cocktail/core/style/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
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
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void AbstractHTMLDocument_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",74)
	super::__construct();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",76)
	this->_body = this->createElement(HX_CSTRING("body"));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",77)
	this->_documentElement = this->createElement(HX_CSTRING("html"));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",78)
	this->_documentElement->appendChild(this->_body);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",80)
	this->_nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",83)
	::cocktail::core::focus::FocusManager_obj::getInstance()->setBodyElement(this->_body);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",86)
	this->_window = ::cocktail::port::flash_player::Window_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",87)
	this->_window->set_onResize(this->onWindowResize_dyn());
}
;
	return null();
}

AbstractHTMLDocument_obj::~AbstractHTMLDocument_obj() { }

Dynamic AbstractHTMLDocument_obj::__CreateEmpty() { return  new AbstractHTMLDocument_obj; }
hx::ObjectPtr< AbstractHTMLDocument_obj > AbstractHTMLDocument_obj::__new()
{  hx::ObjectPtr< AbstractHTMLDocument_obj > result = new AbstractHTMLDocument_obj();
	result->__construct();
	return result;}

Dynamic AbstractHTMLDocument_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractHTMLDocument_obj > result = new AbstractHTMLDocument_obj();
	result->__construct();
	return result;}

::cocktail::port::flash_player::HTMLElement AbstractHTMLDocument_obj::createElement( ::String tagName){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::createElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",100)
	::cocktail::port::flash_player::HTMLElement element;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",102)
	::String _switch_1 = (tagName.toLowerCase());
	if (  ( _switch_1==HX_CSTRING("img"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",104)
		element = ::cocktail::core::html::AbstractHTMLImageElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("canvas"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",107)
		element = ::cocktail::core::html::HTMLCanvasElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("input"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",110)
		element = ::cocktail::port::flash_player::HTMLInputElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("a"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",113)
		element = ::cocktail::port::flash_player::HTMLAnchorElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("html"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",116)
		element = ::cocktail::core::html::AbstractHTMLHtmlElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("body"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",119)
		element = ::cocktail::core::html::HTMLBodyElement_obj::__new();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",122)
		element = ::cocktail::port::flash_player::HTMLElement_obj::__new(tagName);
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",126)
	element->set_ownerDocument(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",128)
	return element;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,createElement,return )

Void AbstractHTMLDocument_obj::invalidate( Dynamic __o_immediate){
bool immediate = __o_immediate.Default(false);
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::invalidate");
{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",146)
		if (((immediate == false))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",150)
			this->scheduleLayoutAndRender();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",154)
			this->layoutAndRender();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,invalidate,(void))

Void AbstractHTMLDocument_obj::layoutAndRender( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::layoutAndRender")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",169)
		this->layout();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",170)
		this->render();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,layoutAndRender,(void))

Void AbstractHTMLDocument_obj::layout( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::layout")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",180)
		::cocktail::core::style::BodyCoreStyle bodyCoreStyle = this->_body->get_coreStyle();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",181)
		bodyCoreStyle->layout();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,layout,(void))

Void AbstractHTMLDocument_obj::render( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::render")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",195)
		this->detachNativeElements(this->_nativeElements);
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",198)
		this->_nativeElements = this->_body->get_coreStyle()->getElementRenderer()->getLayerRenderer()->render();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",199)
		this->attachNativeElements(this->_nativeElements);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,render,(void))

Void AbstractHTMLDocument_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::attachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,attachNativeElement,(void))

Void AbstractHTMLDocument_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::detachNativeElement")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,detachNativeElement,(void))

Void AbstractHTMLDocument_obj::attachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::attachNativeElements")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",226)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",226)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",226)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",228)
			this->attachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,attachNativeElements,(void))

Void AbstractHTMLDocument_obj::detachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::detachNativeElements")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",238)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",238)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",238)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",240)
			this->detachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,detachNativeElements,(void))

Void AbstractHTMLDocument_obj::scheduleLayoutAndRender( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::scheduleLayoutAndRender")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",251)
		Dynamic layoutAndRenderDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->layoutAndRender_dyn()));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,layoutAndRenderDelegate)
		Void run(){
{
				HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",255)
				layoutAndRenderDelegate->__GetItem((int)0)().Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",255)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(layoutAndRenderDelegate)),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,scheduleLayoutAndRender,(void))

Void AbstractHTMLDocument_obj::onWindowResize( ::cocktail::core::event::Event event){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::onWindowResize")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",269)
		this->scheduleLayoutAndRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,onWindowResize,(void))

::cocktail::port::flash_player::HTMLElement AbstractHTMLDocument_obj::get_body( ){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::get_body")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",278)
	return this->_body;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,get_body,return )

::String AbstractHTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_HTML_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_BODY_TAG_NAME;


AbstractHTMLDocument_obj::AbstractHTMLDocument_obj()
{
}

void AbstractHTMLDocument_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractHTMLDocument);
	HX_MARK_MEMBER_NAME(_body,"_body");
	HX_MARK_MEMBER_NAME(body,"body");
	HX_MARK_MEMBER_NAME(_window,"_window");
	HX_MARK_MEMBER_NAME(_nativeElements,"_nativeElements");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractHTMLDocument_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"body") ) { return get_body(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_body") ) { return _body; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"layout") ) { return layout_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { return _window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_body") ) { return get_body_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"onWindowResize") ) { return onWindowResize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { return _nativeElements; }
		if (HX_FIELD_EQ(inName,"layoutAndRender") ) { return layoutAndRender_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { return HTML_HTML_TAG_NAME; }
		if (HX_FIELD_EQ(inName,"HTML_BODY_TAG_NAME") ) { return HTML_BODY_TAG_NAME; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"attachNativeElement") ) { return attachNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElement") ) { return detachNativeElement_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"attachNativeElements") ) { return attachNativeElements_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElements") ) { return detachNativeElements_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"scheduleLayoutAndRender") ) { return scheduleLayoutAndRender_dyn(); }
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

Dynamic AbstractHTMLDocument_obj::__SetField(const ::String &inName,const Dynamic &inValue)
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
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { _nativeElements=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_HTML_TAG_NAME") ) { HTML_HTML_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"HTML_BODY_TAG_NAME") ) { HTML_BODY_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
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

void AbstractHTMLDocument_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_body"));
	outFields->push(HX_CSTRING("body"));
	outFields->push(HX_CSTRING("_window"));
	outFields->push(HX_CSTRING("_nativeElements"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_IMAGE_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_CANVAS_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_INPUT_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_ANCHOR_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_HTML_TAG_NAME"),
	HX_CSTRING("HTML_BODY_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_body"),
	HX_CSTRING("body"),
	HX_CSTRING("_window"),
	HX_CSTRING("_nativeElements"),
	HX_CSTRING("createElement"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("layoutAndRender"),
	HX_CSTRING("layout"),
	HX_CSTRING("render"),
	HX_CSTRING("attachNativeElement"),
	HX_CSTRING("detachNativeElement"),
	HX_CSTRING("attachNativeElements"),
	HX_CSTRING("detachNativeElements"),
	HX_CSTRING("scheduleLayoutAndRender"),
	HX_CSTRING("onWindowResize"),
	HX_CSTRING("get_body"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME,"HTML_IMAGE_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME,"HTML_CANVAS_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME,"HTML_INPUT_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME,"HTML_ANCHOR_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_HTML_TAG_NAME,"HTML_HTML_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_BODY_TAG_NAME,"HTML_BODY_TAG_NAME");
};

Class AbstractHTMLDocument_obj::__mClass;

void AbstractHTMLDocument_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.AbstractHTMLDocument"), hx::TCanCast< AbstractHTMLDocument_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLDocument_obj::__boot()
{
	hx::Static(HTML_IMAGE_ELEMENT_TAG_NAME) = HX_CSTRING("img");
	hx::Static(HTML_CANVAS_ELEMENT_TAG_NAME) = HX_CSTRING("canvas");
	hx::Static(HTML_INPUT_ELEMENT_TAG_NAME) = HX_CSTRING("input");
	hx::Static(HTML_ANCHOR_ELEMENT_TAG_NAME) = HX_CSTRING("a");
	hx::Static(HTML_HTML_TAG_NAME) = HX_CSTRING("html");
	hx::Static(HTML_BODY_TAG_NAME) = HX_CSTRING("body");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
