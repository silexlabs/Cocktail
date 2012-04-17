#include <hxcpp.h>

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
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement
#include <cocktail/core/html/AbstractHTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_AbstractMouse
#include <cocktail/core/mouse/AbstractMouse.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_MouseCursorManager
#include <cocktail/core/mouse/MouseCursorManager.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_MouseCursorValue
#include <cocktail/core/mouse/MouseCursorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_mouse_NativeOSMouseCursorValue
#include <cocktail/core/mouse/NativeOSMouseCursorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementTypeValue
#include <cocktail/core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Mouse
#include <cocktail/port/flash_player/Mouse.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void AbstractHTMLAnchorElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",74)
	super::__construct(HX_CSTRING("a"));
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",75)
	this->_target = HX_CSTRING("_self");
}
;
	return null();
}

AbstractHTMLAnchorElement_obj::~AbstractHTMLAnchorElement_obj() { }

Dynamic AbstractHTMLAnchorElement_obj::__CreateEmpty() { return  new AbstractHTMLAnchorElement_obj; }
hx::ObjectPtr< AbstractHTMLAnchorElement_obj > AbstractHTMLAnchorElement_obj::__new()
{  hx::ObjectPtr< AbstractHTMLAnchorElement_obj > result = new AbstractHTMLAnchorElement_obj();
	result->__construct();
	return result;}

Dynamic AbstractHTMLAnchorElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractHTMLAnchorElement_obj > result = new AbstractHTMLAnchorElement_obj();
	result->__construct();
	return result;}

Void AbstractHTMLAnchorElement_obj::initNativeElement( ){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::initNativeElement")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",82)
		this->_nativeElement = ::cocktail::core::nativeElement::NativeElementManager_obj::createNativeElement(::cocktail::core::nativeElement::NativeElementTypeValue_obj::anchor_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,initNativeElement,(void))

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseDown")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",99)
	this->_onMouseDown = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",100)
	this->_mouse->setOnMouseDown(this->onMouseDownCallback_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",102)
	return this->_onMouseDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseDown,return )

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseOver( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseOver")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",112)
	this->_onMouseOver = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",113)
	this->_mouse->setOnMouseOver(this->onMouseOverCallback_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",115)
	return this->_onMouseOver_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseOver,return )

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseOut( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseOut")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",123)
	this->_onMouseOut = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",124)
	this->_mouse->setOnMouseOut(this->onMouseOutCallback_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",126)
	return this->_onMouseOut_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseOut,return )

Void AbstractHTMLAnchorElement_obj::onMouseDownCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseDownCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",138)
		if (((this->_onMouseDown_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",139)
			this->_onMouseDown(mouseEvent);
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",145)
		if (((mouseEvent->get_defaultPrevented() == false))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",146)
			this->openDocument();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseDownCallback,(void))

Void AbstractHTMLAnchorElement_obj::onMouseOverCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseOverCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",156)
		if (((this->_onMouseOver_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",157)
			this->_onMouseOver(mouseEvent);
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",161)
		this->displayPointerCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseOverCallback,(void))

Void AbstractHTMLAnchorElement_obj::onMouseOutCallback( ::cocktail::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseOutCallback")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",169)
		if (((this->_onMouseOut_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",170)
			this->_onMouseOut(mouseEvent);
		}
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",174)
		this->hidePointerCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseOutCallback,(void))

bool AbstractHTMLAnchorElement_obj::isDefaultFocusable( ){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::isDefaultFocusable")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",187)
	if (((this->get_href() != null()))){
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",189)
		return true;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",193)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,isDefaultFocusable,return )

Void AbstractHTMLAnchorElement_obj::openDocument( ){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::openDocument")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,openDocument,(void))

Void AbstractHTMLAnchorElement_obj::displayPointerCursor( ){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::displayPointerCursor")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",212)
		::cocktail::core::mouse::MouseCursorManager_obj::setMouseCursor(::cocktail::core::mouse::MouseCursorValue_obj::native(::cocktail::core::mouse::NativeOSMouseCursorValue_obj::pointer_dyn()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,displayPointerCursor,(void))

Void AbstractHTMLAnchorElement_obj::hidePointerCursor( ){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::hidePointerCursor")
		HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",220)
		::cocktail::core::mouse::MouseCursorManager_obj::setMouseCursor(::cocktail::core::mouse::MouseCursorValue_obj::cssAuto_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,hidePointerCursor,(void))

::String AbstractHTMLAnchorElement_obj::set_href( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_href")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",235)
	this->_href = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",236)
	this->set_onMouseDown(this->_onMouseDown_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",237)
	this->set_onMouseOver(this->_onMouseOver_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",238)
	this->set_onMouseOut(this->_onMouseOut_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",239)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_href,return )

::String AbstractHTMLAnchorElement_obj::get_href( ){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::get_href")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",243)
	return this->_href;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,get_href,return )

::String AbstractHTMLAnchorElement_obj::set_target( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_target")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",254)
	this->_target = value;
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",255)
	this->set_onMouseDown(this->_onMouseDown_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",256)
	this->set_onMouseOver(this->_onMouseOver_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",257)
	this->set_onMouseOut(this->_onMouseOut_dyn());
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",258)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_target,return )

::String AbstractHTMLAnchorElement_obj::get_target( ){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::get_target")
	HX_SOURCE_POS("../../src/cocktail/core/html/AbstractHTMLAnchorElement.hx",262)
	return this->_target;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,get_target,return )

::String AbstractHTMLAnchorElement_obj::TARGET_BLANK;

::String AbstractHTMLAnchorElement_obj::TARGET_SELF;

::String AbstractHTMLAnchorElement_obj::TARGET_PARENT;

::String AbstractHTMLAnchorElement_obj::TARGET_TOP;

::String AbstractHTMLAnchorElement_obj::HTML_ANCHOR_TAG_NAME;


AbstractHTMLAnchorElement_obj::AbstractHTMLAnchorElement_obj()
{
}

void AbstractHTMLAnchorElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractHTMLAnchorElement);
	HX_MARK_MEMBER_NAME(_href,"_href");
	HX_MARK_MEMBER_NAME(href,"href");
	HX_MARK_MEMBER_NAME(_target,"_target");
	HX_MARK_MEMBER_NAME(target,"target");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractHTMLAnchorElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { return get_href(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_href") ) { return _href; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return get_target(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_target") ) { return _target; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_href") ) { return set_href_dyn(); }
		if (HX_FIELD_EQ(inName,"get_href") ) { return get_href_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TARGET_TOP") ) { return TARGET_TOP; }
		if (HX_FIELD_EQ(inName,"set_target") ) { return set_target_dyn(); }
		if (HX_FIELD_EQ(inName,"get_target") ) { return get_target_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TARGET_SELF") ) { return TARGET_SELF; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TARGET_BLANK") ) { return TARGET_BLANK; }
		if (HX_FIELD_EQ(inName,"openDocument") ) { return openDocument_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TARGET_PARENT") ) { return TARGET_PARENT; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_onMouseOut") ) { return set_onMouseOut_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_onMouseDown") ) { return set_onMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"set_onMouseOver") ) { return set_onMouseOver_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initNativeElement") ) { return initNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"hidePointerCursor") ) { return hidePointerCursor_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onMouseOutCallback") ) { return onMouseOutCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"isDefaultFocusable") ) { return isDefaultFocusable_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onMouseDownCallback") ) { return onMouseDownCallback_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseOverCallback") ) { return onMouseOverCallback_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"HTML_ANCHOR_TAG_NAME") ) { return HTML_ANCHOR_TAG_NAME; }
		if (HX_FIELD_EQ(inName,"displayPointerCursor") ) { return displayPointerCursor_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractHTMLAnchorElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"href") ) { return set_href(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_href") ) { _href=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return set_target(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_target") ) { _target=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TARGET_TOP") ) { TARGET_TOP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TARGET_SELF") ) { TARGET_SELF=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TARGET_BLANK") ) { TARGET_BLANK=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TARGET_PARENT") ) { TARGET_PARENT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"HTML_ANCHOR_TAG_NAME") ) { HTML_ANCHOR_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractHTMLAnchorElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_href"));
	outFields->push(HX_CSTRING("href"));
	outFields->push(HX_CSTRING("_target"));
	outFields->push(HX_CSTRING("target"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TARGET_BLANK"),
	HX_CSTRING("TARGET_SELF"),
	HX_CSTRING("TARGET_PARENT"),
	HX_CSTRING("TARGET_TOP"),
	HX_CSTRING("HTML_ANCHOR_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_href"),
	HX_CSTRING("href"),
	HX_CSTRING("_target"),
	HX_CSTRING("target"),
	HX_CSTRING("initNativeElement"),
	HX_CSTRING("set_onMouseDown"),
	HX_CSTRING("set_onMouseOver"),
	HX_CSTRING("set_onMouseOut"),
	HX_CSTRING("onMouseDownCallback"),
	HX_CSTRING("onMouseOverCallback"),
	HX_CSTRING("onMouseOutCallback"),
	HX_CSTRING("isDefaultFocusable"),
	HX_CSTRING("openDocument"),
	HX_CSTRING("displayPointerCursor"),
	HX_CSTRING("hidePointerCursor"),
	HX_CSTRING("set_href"),
	HX_CSTRING("get_href"),
	HX_CSTRING("set_target"),
	HX_CSTRING("get_target"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::TARGET_BLANK,"TARGET_BLANK");
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::TARGET_SELF,"TARGET_SELF");
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::TARGET_PARENT,"TARGET_PARENT");
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::TARGET_TOP,"TARGET_TOP");
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::HTML_ANCHOR_TAG_NAME,"HTML_ANCHOR_TAG_NAME");
};

Class AbstractHTMLAnchorElement_obj::__mClass;

void AbstractHTMLAnchorElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.AbstractHTMLAnchorElement"), hx::TCanCast< AbstractHTMLAnchorElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLAnchorElement_obj::__boot()
{
	hx::Static(TARGET_BLANK) = HX_CSTRING("_blank");
	hx::Static(TARGET_SELF) = HX_CSTRING("_self");
	hx::Static(TARGET_PARENT) = HX_CSTRING("_parent");
	hx::Static(TARGET_TOP) = HX_CSTRING("_top");
	hx::Static(HTML_ANCHOR_TAG_NAME) = HX_CSTRING("a");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
