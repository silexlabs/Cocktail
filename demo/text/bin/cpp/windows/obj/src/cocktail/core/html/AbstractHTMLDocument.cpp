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
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
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
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLCanvasElement
#include <cocktail/core/html/HTMLCanvasElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLHtmlElement
#include <cocktail/core/html/HTMLHtmlElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLImageElement
#include <cocktail/core/html/HTMLImageElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLInputElement
#include <cocktail/core/html/HTMLInputElement.h>
#endif
#ifndef INCLUDED_cocktail_core_keyboard_AbstractKeyboard
#include <cocktail/core/keyboard/AbstractKeyboard.h>
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
#ifndef INCLUDED_cocktail_port_flash_player_Keyboard
#include <cocktail/port/flash_player/Keyboard.h>
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
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",108)
	super::__construct();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",110)
	this->_body = this->createElement(HX_CSTRING("body"));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",111)
	this->_documentElement = this->createElement(HX_CSTRING("html"));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",112)
	this->_documentElement->appendChild(this->_body);
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",114)
	this->_nativeElements = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",116)
	this->_focusManager = ::cocktail::core::focus::FocusManager_obj::__new();
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",117)
	this->_activeElement = this->_body;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",120)
	this->_window = ::cocktail::port::flash_player::Window_obj::__new(null());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",121)
	this->_window->set_onResize(this->onWindowResize_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",123)
	this->initKeyboardListeners();
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

Void AbstractHTMLDocument_obj::initKeyboardListeners( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::initKeyboardListeners")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",132)
		::cocktail::port::flash_player::Keyboard keyboard = ::cocktail::port::flash_player::Keyboard_obj::__new(this->_body);
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",133)
		keyboard->setOnKeyDown(this->onKeyDown_dyn());
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",134)
		keyboard->setOnKeyUp(this->onKeyUp_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,initKeyboardListeners,(void))

::cocktail::core::html::HTMLElement AbstractHTMLDocument_obj::createElement( ::String tagName){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::createElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",147)
	::cocktail::core::html::HTMLElement element;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",149)
	::String _switch_1 = (tagName.toLowerCase());
	if (  ( _switch_1==HX_CSTRING("img"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",151)
		element = ::cocktail::core::html::HTMLImageElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("canvas"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",154)
		element = ::cocktail::core::html::HTMLCanvasElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("input"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",157)
		element = ::cocktail::core::html::HTMLInputElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("a"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",160)
		element = ::cocktail::port::flash_player::HTMLAnchorElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("html"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",163)
		element = ::cocktail::core::html::HTMLHtmlElement_obj::__new();
	}
	else if (  ( _switch_1==HX_CSTRING("body"))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",166)
		element = ::cocktail::core::html::HTMLBodyElement_obj::__new();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",169)
		element = ::cocktail::core::html::HTMLElement_obj::__new(tagName);
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",173)
	element->set_ownerDocument(hx::ObjectPtr<OBJ_>(this));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",175)
	return element;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,createElement,return )

Void AbstractHTMLDocument_obj::invalidate( Dynamic __o_immediate){
bool immediate = __o_immediate.Default(false);
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::invalidate");
{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",193)
		if (((immediate == false))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",197)
			this->scheduleLayoutAndRender();
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",201)
			this->layoutAndRender();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,invalidate,(void))

Void AbstractHTMLDocument_obj::onKeyDown( ::cocktail::core::event::KeyboardEvent keyboardEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::onKeyDown")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",217)
		if (((this->get_activeElement()->get_onKeyDown() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",218)
			this->get_activeElement()->get_onKeyDown()(keyboardEvent).Cast< Void >();
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",222)
		switch( (int)(keyboardEvent->get_key())){
			case (int)9: {
				HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",224)
				if (((keyboardEvent->get_defaultPrevented() == false))){
					HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",227)
					this->set_activeElement(this->_focusManager->getNextFocusedElement((keyboardEvent->get_shiftKey() == true),this->_body,this->get_activeElement()));
				}
			}
			;break;
			case (int)13: case (int)32: {
				HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",232)
				if (((keyboardEvent->get_defaultPrevented() == false))){
					HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",235)
					this->get_activeElement()->click();
				}
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,onKeyDown,(void))

Void AbstractHTMLDocument_obj::onKeyUp( ::cocktail::core::event::KeyboardEvent keyEventData){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::onKeyUp")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",246)
		if (((this->get_activeElement()->get_onKeyUp() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",248)
			this->get_activeElement()->get_onKeyUp()(keyEventData).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,onKeyUp,(void))

Void AbstractHTMLDocument_obj::layoutAndRender( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::layoutAndRender")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",263)
		this->layout();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",264)
		this->render();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,layoutAndRender,(void))

Void AbstractHTMLDocument_obj::layout( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::layout")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",274)
		::cocktail::core::style::BodyCoreStyle bodyCoreStyle = this->_body->get_coreStyle();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",275)
		bodyCoreStyle->layout();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,layout,(void))

Void AbstractHTMLDocument_obj::render( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::render")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",289)
		this->detachNativeElements(this->_nativeElements);
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",292)
		this->_nativeElements = this->_body->get_coreStyle()->getElementRenderer()->getLayerRenderer()->render();
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",293)
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
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",320)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",320)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",320)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",322)
			this->attachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,attachNativeElements,(void))

Void AbstractHTMLDocument_obj::detachNativeElements( Dynamic nativeElements){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::detachNativeElements")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",332)
		int _g1 = (int)0;
		int _g = nativeElements->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",332)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",332)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",334)
			this->detachNativeElement(nativeElements->__GetItem(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,detachNativeElements,(void))

Void AbstractHTMLDocument_obj::scheduleLayoutAndRender( ){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::scheduleLayoutAndRender")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",345)
		Dynamic layoutAndRenderDelegate = Dynamic( Array_obj<Dynamic>::__new().Add(this->layoutAndRender_dyn()));

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,layoutAndRenderDelegate)
		Void run(){
{
				HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",349)
				layoutAndRenderDelegate->__GetItem((int)0)().Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",349)
		::haxe::Timer_obj::delay( Dynamic(new _Function_1_1(layoutAndRenderDelegate)),(int)1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,scheduleLayoutAndRender,(void))

Void AbstractHTMLDocument_obj::onWindowResize( ::cocktail::core::event::Event event){
{
		HX_SOURCE_PUSH("AbstractHTMLDocument_obj::onWindowResize")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",363)
		this->scheduleLayoutAndRender();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,onWindowResize,(void))

::cocktail::core::html::HTMLBodyElement AbstractHTMLDocument_obj::get_body( ){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::get_body")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",372)
	return this->_body;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,get_body,return )

::cocktail::core::html::HTMLElement AbstractHTMLDocument_obj::set_activeElement( ::cocktail::core::html::HTMLElement value){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::set_activeElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",385)
	if (((value == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",386)
		return this->_activeElement;
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",392)
	if (((value != this->get_activeElement()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",395)
		if (((this->get_activeElement()->get_onBlur() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",396)
			this->get_activeElement()->get_onBlur()(::cocktail::core::event::Event_obj::__new(HX_CSTRING("blur"),this->get_activeElement())).Cast< Void >();
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",401)
		this->_activeElement = value;
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",402)
		if (((this->_activeElement->get_onFocus() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",403)
			this->_activeElement->get_onFocus()(::cocktail::core::event::Event_obj::__new(HX_CSTRING("focus"),this->_activeElement)).Cast< Void >();
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",408)
	return this->_activeElement;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLDocument_obj,set_activeElement,return )

::cocktail::core::html::HTMLElement AbstractHTMLDocument_obj::get_activeElement( ){
	HX_SOURCE_PUSH("AbstractHTMLDocument_obj::get_activeElement")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLDocument.hx",413)
	return this->_activeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLDocument_obj,get_activeElement,return )

::String AbstractHTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_HTML_TAG_NAME;

::String AbstractHTMLDocument_obj::HTML_BODY_TAG_NAME;

int AbstractHTMLDocument_obj::TAB_KEY_CODE;

int AbstractHTMLDocument_obj::ENTER_KEY_CODE;

int AbstractHTMLDocument_obj::SPACE_KEY_CODE;


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
	HX_MARK_MEMBER_NAME(_activeElement,"_activeElement");
	HX_MARK_MEMBER_NAME(activeElement,"activeElement");
	HX_MARK_MEMBER_NAME(_focusManager,"_focusManager");
	HX_MARK_MEMBER_NAME(_keyboard,"_keyboard");
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
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_body") ) { return get_body_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_keyboard") ) { return _keyboard; }
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TAB_KEY_CODE") ) { return TAB_KEY_CODE; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return get_activeElement(); }
		if (HX_FIELD_EQ(inName,"_focusManager") ) { return _focusManager; }
		if (HX_FIELD_EQ(inName,"createElement") ) { return createElement_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ENTER_KEY_CODE") ) { return ENTER_KEY_CODE; }
		if (HX_FIELD_EQ(inName,"SPACE_KEY_CODE") ) { return SPACE_KEY_CODE; }
		if (HX_FIELD_EQ(inName,"_activeElement") ) { return _activeElement; }
		if (HX_FIELD_EQ(inName,"onWindowResize") ) { return onWindowResize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_nativeElements") ) { return _nativeElements; }
		if (HX_FIELD_EQ(inName,"layoutAndRender") ) { return layoutAndRender_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_activeElement") ) { return set_activeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"get_activeElement") ) { return get_activeElement_dyn(); }
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
	case 21:
		if (HX_FIELD_EQ(inName,"initKeyboardListeners") ) { return initKeyboardListeners_dyn(); }
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
		if (HX_FIELD_EQ(inName,"body") ) { body=inValue.Cast< ::cocktail::core::html::HTMLBodyElement >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_body") ) { _body=inValue.Cast< ::cocktail::core::html::HTMLBodyElement >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_window") ) { _window=inValue.Cast< ::cocktail::port::flash_player::Window >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_keyboard") ) { _keyboard=inValue.Cast< ::cocktail::port::flash_player::Keyboard >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TAB_KEY_CODE") ) { TAB_KEY_CODE=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return set_activeElement(inValue); }
		if (HX_FIELD_EQ(inName,"_focusManager") ) { _focusManager=inValue.Cast< ::cocktail::core::focus::FocusManager >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"ENTER_KEY_CODE") ) { ENTER_KEY_CODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SPACE_KEY_CODE") ) { SPACE_KEY_CODE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_activeElement") ) { _activeElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
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
	outFields->push(HX_CSTRING("_activeElement"));
	outFields->push(HX_CSTRING("activeElement"));
	outFields->push(HX_CSTRING("_focusManager"));
	outFields->push(HX_CSTRING("_keyboard"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_IMAGE_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_CANVAS_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_INPUT_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_ANCHOR_ELEMENT_TAG_NAME"),
	HX_CSTRING("HTML_HTML_TAG_NAME"),
	HX_CSTRING("HTML_BODY_TAG_NAME"),
	HX_CSTRING("TAB_KEY_CODE"),
	HX_CSTRING("ENTER_KEY_CODE"),
	HX_CSTRING("SPACE_KEY_CODE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_body"),
	HX_CSTRING("body"),
	HX_CSTRING("_window"),
	HX_CSTRING("_nativeElements"),
	HX_CSTRING("_activeElement"),
	HX_CSTRING("activeElement"),
	HX_CSTRING("_focusManager"),
	HX_CSTRING("_keyboard"),
	HX_CSTRING("initKeyboardListeners"),
	HX_CSTRING("createElement"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("onKeyUp"),
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
	HX_CSTRING("set_activeElement"),
	HX_CSTRING("get_activeElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_IMAGE_ELEMENT_TAG_NAME,"HTML_IMAGE_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_CANVAS_ELEMENT_TAG_NAME,"HTML_CANVAS_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_INPUT_ELEMENT_TAG_NAME,"HTML_INPUT_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_ANCHOR_ELEMENT_TAG_NAME,"HTML_ANCHOR_ELEMENT_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_HTML_TAG_NAME,"HTML_HTML_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::HTML_BODY_TAG_NAME,"HTML_BODY_TAG_NAME");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::TAB_KEY_CODE,"TAB_KEY_CODE");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::ENTER_KEY_CODE,"ENTER_KEY_CODE");
	HX_MARK_MEMBER_NAME(AbstractHTMLDocument_obj::SPACE_KEY_CODE,"SPACE_KEY_CODE");
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
	hx::Static(TAB_KEY_CODE) = (int)9;
	hx::Static(ENTER_KEY_CODE) = (int)13;
	hx::Static(SPACE_KEY_CODE) = (int)32;
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
