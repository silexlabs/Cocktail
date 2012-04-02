#include <hxcpp.h>

#ifndef INCLUDED_core_dom_AnchorTarget
#include <core/dom/AnchorTarget.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_Event
#include <core/event/Event.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_event_MouseEvent
#include <core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_core_event_UIEvent
#include <core/event/UIEvent.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLAnchorElement
#include <core/html/AbstractHTMLAnchorElement.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_mouse_AbstractMouse
#include <core/mouse/AbstractMouse.h>
#endif
#ifndef INCLUDED_core_mouse_MouseCursorManager
#include <core/mouse/MouseCursorManager.h>
#endif
#ifndef INCLUDED_core_mouse_MouseCursorValue
#include <core/mouse/MouseCursorValue.h>
#endif
#ifndef INCLUDED_core_mouse_NativeOSMouseCursorValue
#include <core/mouse/NativeOSMouseCursorValue.h>
#endif
#ifndef INCLUDED_core_nativeElement_NativeElementManager
#include <core/nativeElement/NativeElementManager.h>
#endif
#ifndef INCLUDED_core_nativeElement_NativeElementTypeValue
#include <core/nativeElement/NativeElementTypeValue.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Mouse
#include <port/flash_player/Mouse.h>
#endif
namespace core{
namespace html{

Void AbstractHTMLAnchorElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",61)
	super::__construct(HX_CSTRING("a"));
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",62)
	this->_target = ::core::dom::AnchorTarget_obj::self_dyn();
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
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",69)
		this->_nativeElement = ::core::nativeElement::NativeElementManager_obj::createNativeElement(::core::nativeElement::NativeElementTypeValue_obj::link_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,initNativeElement,(void))

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseDown")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",86)
	this->_onMouseDown = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",87)
	this->_mouse->setOnMouseDown(this->onMouseDownCallback_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",89)
	return this->_onMouseDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseDown,return )

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseOver( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseOver")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",97)
	this->_onMouseOver = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",98)
	this->_mouse->setOnMouseOver(this->onMouseOverCallback_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",100)
	return this->_onMouseOver_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseOver,return )

Dynamic AbstractHTMLAnchorElement_obj::set_onMouseOut( Dynamic value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_onMouseOut")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",108)
	this->_onMouseOut = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",109)
	this->_mouse->setOnMouseOut(this->onMouseOutCallback_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",111)
	return this->_onMouseOut_dyn();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_onMouseOut,return )

Void AbstractHTMLAnchorElement_obj::onMouseDownCallback( ::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseDownCallback")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",123)
		if (((this->_onMouseDown_dyn() != null()))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",124)
			this->_onMouseDown(mouseEvent);
		}
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",130)
		if (((mouseEvent->get_defaultPrevented() == false))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",131)
			this->openDocument();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseDownCallback,(void))

Void AbstractHTMLAnchorElement_obj::onMouseOverCallback( ::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseOverCallback")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",138)
		if (((this->_onMouseOver_dyn() != null()))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",139)
			this->_onMouseOver(mouseEvent);
		}
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",143)
		this->displayPointerCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseOverCallback,(void))

Void AbstractHTMLAnchorElement_obj::onMouseOutCallback( ::core::event::MouseEvent mouseEvent){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::onMouseOutCallback")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",148)
		if (((this->_onMouseOut_dyn() != null()))){
			HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",149)
			this->_onMouseOut(mouseEvent);
		}
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",153)
		this->hidePointerCursor();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,onMouseOutCallback,(void))

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
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",172)
		::core::mouse::MouseCursorManager_obj::setMouseCursor(::core::mouse::MouseCursorValue_obj::native(::core::mouse::NativeOSMouseCursorValue_obj::pointer_dyn()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,displayPointerCursor,(void))

Void AbstractHTMLAnchorElement_obj::hidePointerCursor( ){
{
		HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::hidePointerCursor")
		HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",177)
		::core::mouse::MouseCursorManager_obj::setMouseCursor(::core::mouse::MouseCursorValue_obj::cssAuto_dyn());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,hidePointerCursor,(void))

::String AbstractHTMLAnchorElement_obj::getTargetAsString( ::core::dom::AnchorTarget value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::getTargetAsString")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",187)
	::String target;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",189)
	{
::core::dom::AnchorTarget _switch_1 = (value);
		switch((_switch_1)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",191)
				target = HX_CSTRING("_blank");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",194)
				target = HX_CSTRING("_parent");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",197)
				target = HX_CSTRING("_self");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",200)
				target = HX_CSTRING("_top");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",204)
	return target;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,getTargetAsString,return )

::String AbstractHTMLAnchorElement_obj::set_href( ::String value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_href")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",218)
	this->_href = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",219)
	this->set_onMouseDown(this->_onMouseDown_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",220)
	this->set_onMouseOver(this->_onMouseOver_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",221)
	this->set_onMouseOut(this->_onMouseOut_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",222)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_href,return )

::String AbstractHTMLAnchorElement_obj::get_href( ){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::get_href")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",226)
	return this->_href;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,get_href,return )

::core::dom::AnchorTarget AbstractHTMLAnchorElement_obj::set_target( ::core::dom::AnchorTarget value){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::set_target")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",237)
	this->_target = value;
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",238)
	this->set_onMouseDown(this->_onMouseDown_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",239)
	this->set_onMouseOver(this->_onMouseOver_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",240)
	this->set_onMouseOut(this->_onMouseOut_dyn());
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",241)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractHTMLAnchorElement_obj,set_target,return )

::core::dom::AnchorTarget AbstractHTMLAnchorElement_obj::get_target( ){
	HX_SOURCE_PUSH("AbstractHTMLAnchorElement_obj::get_target")
	HX_SOURCE_POS("../../src/core/html/AbstractHTMLAnchorElement.hx",245)
	return this->_target;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractHTMLAnchorElement_obj,get_target,return )

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
		if (HX_FIELD_EQ(inName,"set_target") ) { return set_target_dyn(); }
		if (HX_FIELD_EQ(inName,"get_target") ) { return get_target_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"openDocument") ) { return openDocument_dyn(); }
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
		if (HX_FIELD_EQ(inName,"getTargetAsString") ) { return getTargetAsString_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onMouseOutCallback") ) { return onMouseOutCallback_dyn(); }
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
		if (HX_FIELD_EQ(inName,"_target") ) { _target=inValue.Cast< ::core::dom::AnchorTarget >(); return inValue; }
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
	HX_CSTRING("openDocument"),
	HX_CSTRING("displayPointerCursor"),
	HX_CSTRING("hidePointerCursor"),
	HX_CSTRING("getTargetAsString"),
	HX_CSTRING("set_href"),
	HX_CSTRING("get_href"),
	HX_CSTRING("set_target"),
	HX_CSTRING("get_target"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractHTMLAnchorElement_obj::HTML_ANCHOR_TAG_NAME,"HTML_ANCHOR_TAG_NAME");
};

Class AbstractHTMLAnchorElement_obj::__mClass;

void AbstractHTMLAnchorElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.html.AbstractHTMLAnchorElement"), hx::TCanCast< AbstractHTMLAnchorElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractHTMLAnchorElement_obj::__boot()
{
	hx::Static(HTML_ANCHOR_TAG_NAME) = HX_CSTRING("a");
}

} // end namespace core
} // end namespace html
