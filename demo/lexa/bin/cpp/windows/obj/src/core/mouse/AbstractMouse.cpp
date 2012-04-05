#include <hxcpp.h>

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
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_mouse_AbstractMouse
#include <core/mouse/AbstractMouse.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace mouse{

Void AbstractMouse_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",90)
	this->_htmlElement = htmlElement;
}
;
	return null();
}

AbstractMouse_obj::~AbstractMouse_obj() { }

Dynamic AbstractMouse_obj::__CreateEmpty() { return  new AbstractMouse_obj; }
hx::ObjectPtr< AbstractMouse_obj > AbstractMouse_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractMouse_obj > result = new AbstractMouse_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractMouse_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractMouse_obj > result = new AbstractMouse_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractMouse_obj::onNativeClick( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeClick")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",104)
		if (((this->get_onClick() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",106)
			this->get_onClick()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeClick,(void))

Void AbstractMouse_obj::onNativeMouseDown( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeMouseDown")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",116)
		if (((this->getOnMouseDown() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",118)
			this->getOnMouseDown()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeMouseDown,(void))

Void AbstractMouse_obj::onNativeMouseUp( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeMouseUp")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",128)
		if (((this->getOnMouseUp() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",130)
			this->getOnMouseUp()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeMouseUp,(void))

Void AbstractMouse_obj::onNativeMouseOver( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeMouseOver")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",140)
		if (((this->getOnMouseOver() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",142)
			this->getOnMouseOver()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeMouseOver,(void))

Void AbstractMouse_obj::onNativeMouseOut( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeMouseOut")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",152)
		if (((this->getOnMouseOut() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",154)
			this->getOnMouseOut()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeMouseOut,(void))

Void AbstractMouse_obj::onNativeMouseMove( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::onNativeMouseMove")
		HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",165)
		if (((this->getOnMouseMove() != null()))){
			HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",167)
			this->getOnMouseMove()(this->getMouseEvent(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,onNativeMouseMove,(void))

Void AbstractMouse_obj::updateListeners( ::String mouseEvent,Dynamic nativeCallback,Dynamic htmlElementCallback){
{
		HX_SOURCE_PUSH("AbstractMouse_obj::updateListeners")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractMouse_obj,updateListeners,(void))

::core::event::MouseEvent AbstractMouse_obj::getMouseEvent( Dynamic event){
	HX_SOURCE_PUSH("AbstractMouse_obj::getMouseEvent")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",195)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,getMouseEvent,return )

Dynamic AbstractMouse_obj::set_onClick( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::set_onClick")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",205)
	this->updateListeners(this->_clickEvent,this->onNativeClick_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",206)
	return this->_onClick = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,set_onClick,return )

Dynamic AbstractMouse_obj::get_onClick( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::get_onClick")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",210)
	return this->_onClick_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,get_onClick,return )

Dynamic AbstractMouse_obj::setOnMouseDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::setOnMouseDown")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",216)
	this->updateListeners(this->_mouseDownEvent,this->onNativeMouseDown_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",217)
	return this->_onMouseDown = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,setOnMouseDown,return )

Dynamic AbstractMouse_obj::getOnMouseDown( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::getOnMouseDown")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",221)
	return this->_onMouseDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,getOnMouseDown,return )

Dynamic AbstractMouse_obj::setOnMouseUp( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::setOnMouseUp")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",227)
	this->updateListeners(this->_mouseUpEvent,this->onNativeMouseUp_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",228)
	return this->_onMouseUp = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,setOnMouseUp,return )

Dynamic AbstractMouse_obj::getOnMouseUp( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::getOnMouseUp")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",232)
	return this->_onMouseUp_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,getOnMouseUp,return )

Dynamic AbstractMouse_obj::setOnMouseOver( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::setOnMouseOver")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",238)
	this->updateListeners(this->_mouseOverEvent,this->onNativeMouseOver_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",239)
	return this->_onMouseOver = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,setOnMouseOver,return )

Dynamic AbstractMouse_obj::getOnMouseOver( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::getOnMouseOver")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",243)
	return this->_onMouseOver_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,getOnMouseOver,return )

Dynamic AbstractMouse_obj::setOnMouseOut( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::setOnMouseOut")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",249)
	this->updateListeners(this->_mouseOutEvent,this->onNativeMouseOut_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",250)
	return this->_onMouseOut = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,setOnMouseOut,return )

Dynamic AbstractMouse_obj::getOnMouseOut( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::getOnMouseOut")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",254)
	return this->_onMouseOut_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,getOnMouseOut,return )

Dynamic AbstractMouse_obj::setOnMouseMove( Dynamic value){
	HX_SOURCE_PUSH("AbstractMouse_obj::setOnMouseMove")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",260)
	this->updateListeners(this->_mouseMoveEvent,this->onNativeMouseMove_dyn(),value);
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",261)
	return this->_onMouseMove = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractMouse_obj,setOnMouseMove,return )

Dynamic AbstractMouse_obj::getOnMouseMove( ){
	HX_SOURCE_PUSH("AbstractMouse_obj::getOnMouseMove")
	HX_SOURCE_POS("../../src/core/mouse/AbstractMouse.hx",265)
	return this->_onMouseMove_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractMouse_obj,getOnMouseMove,return )


AbstractMouse_obj::AbstractMouse_obj()
{
}

void AbstractMouse_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractMouse);
	HX_MARK_MEMBER_NAME(_onClick,"_onClick");
	HX_MARK_MEMBER_NAME(onClick,"onClick");
	HX_MARK_MEMBER_NAME(_onMouseDown,"_onMouseDown");
	HX_MARK_MEMBER_NAME(onMouseDown,"onMouseDown");
	HX_MARK_MEMBER_NAME(_onMouseUp,"_onMouseUp");
	HX_MARK_MEMBER_NAME(onMouseUp,"onMouseUp");
	HX_MARK_MEMBER_NAME(_onMouseOver,"_onMouseOver");
	HX_MARK_MEMBER_NAME(onMouseOver,"onMouseOver");
	HX_MARK_MEMBER_NAME(_onMouseOut,"_onMouseOut");
	HX_MARK_MEMBER_NAME(onMouseOut,"onMouseOut");
	HX_MARK_MEMBER_NAME(_onMouseMove,"_onMouseMove");
	HX_MARK_MEMBER_NAME(onMouseMove,"onMouseMove");
	HX_MARK_MEMBER_NAME(_clickEvent,"_clickEvent");
	HX_MARK_MEMBER_NAME(_mouseDownEvent,"_mouseDownEvent");
	HX_MARK_MEMBER_NAME(_mouseUpEvent,"_mouseUpEvent");
	HX_MARK_MEMBER_NAME(_mouseOverEvent,"_mouseOverEvent");
	HX_MARK_MEMBER_NAME(_mouseOutEvent,"_mouseOutEvent");
	HX_MARK_MEMBER_NAME(_mouseMoveEvent,"_mouseMoveEvent");
	HX_MARK_MEMBER_NAME(_htmlElement,"_htmlElement");
	HX_MARK_END_CLASS();
}

Dynamic AbstractMouse_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return get_onClick(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onClick") ) { return _onClick; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return getOnMouseUp(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { return _onMouseUp; }
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return getOnMouseOut(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return getOnMouseDown(); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return getOnMouseOver(); }
		if (HX_FIELD_EQ(inName,"_onMouseOut") ) { return _onMouseOut; }
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return getOnMouseMove(); }
		if (HX_FIELD_EQ(inName,"_clickEvent") ) { return _clickEvent; }
		if (HX_FIELD_EQ(inName,"set_onClick") ) { return set_onClick_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onClick") ) { return get_onClick_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { return _onMouseDown; }
		if (HX_FIELD_EQ(inName,"_onMouseOver") ) { return _onMouseOver; }
		if (HX_FIELD_EQ(inName,"_onMouseMove") ) { return _onMouseMove; }
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { return _htmlElement; }
		if (HX_FIELD_EQ(inName,"setOnMouseUp") ) { return setOnMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnMouseUp") ) { return getOnMouseUp_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_mouseUpEvent") ) { return _mouseUpEvent; }
		if (HX_FIELD_EQ(inName,"onNativeClick") ) { return onNativeClick_dyn(); }
		if (HX_FIELD_EQ(inName,"getMouseEvent") ) { return getMouseEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"setOnMouseOut") ) { return setOnMouseOut_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnMouseOut") ) { return getOnMouseOut_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_mouseOutEvent") ) { return _mouseOutEvent; }
		if (HX_FIELD_EQ(inName,"setOnMouseDown") ) { return setOnMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnMouseDown") ) { return getOnMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"setOnMouseOver") ) { return setOnMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnMouseOver") ) { return getOnMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"setOnMouseMove") ) { return setOnMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnMouseMove") ) { return getOnMouseMove_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_mouseDownEvent") ) { return _mouseDownEvent; }
		if (HX_FIELD_EQ(inName,"_mouseOverEvent") ) { return _mouseOverEvent; }
		if (HX_FIELD_EQ(inName,"_mouseMoveEvent") ) { return _mouseMoveEvent; }
		if (HX_FIELD_EQ(inName,"onNativeMouseUp") ) { return onNativeMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"updateListeners") ) { return updateListeners_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"onNativeMouseOut") ) { return onNativeMouseOut_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onNativeMouseDown") ) { return onNativeMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeMouseOver") ) { return onNativeMouseOver_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeMouseMove") ) { return onNativeMouseMove_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractMouse_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onClick") ) { return set_onClick(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onClick") ) { _onClick=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onMouseUp") ) { return setOnMouseUp(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onMouseUp") ) { _onMouseUp=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onMouseOut") ) { return setOnMouseOut(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return setOnMouseDown(inValue); }
		if (HX_FIELD_EQ(inName,"onMouseOver") ) { return setOnMouseOver(inValue); }
		if (HX_FIELD_EQ(inName,"_onMouseOut") ) { _onMouseOut=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return setOnMouseMove(inValue); }
		if (HX_FIELD_EQ(inName,"_clickEvent") ) { _clickEvent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onMouseDown") ) { _onMouseDown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onMouseOver") ) { _onMouseOver=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_onMouseMove") ) { _onMouseMove=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { _htmlElement=inValue.Cast< ::port::flash_player::HTMLElement >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_mouseUpEvent") ) { _mouseUpEvent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_mouseOutEvent") ) { _mouseOutEvent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_mouseDownEvent") ) { _mouseDownEvent=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mouseOverEvent") ) { _mouseOverEvent=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mouseMoveEvent") ) { _mouseMoveEvent=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractMouse_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_clickEvent"));
	outFields->push(HX_CSTRING("_mouseDownEvent"));
	outFields->push(HX_CSTRING("_mouseUpEvent"));
	outFields->push(HX_CSTRING("_mouseOverEvent"));
	outFields->push(HX_CSTRING("_mouseOutEvent"));
	outFields->push(HX_CSTRING("_mouseMoveEvent"));
	outFields->push(HX_CSTRING("_htmlElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onClick"),
	HX_CSTRING("onClick"),
	HX_CSTRING("_onMouseDown"),
	HX_CSTRING("onMouseDown"),
	HX_CSTRING("_onMouseUp"),
	HX_CSTRING("onMouseUp"),
	HX_CSTRING("_onMouseOver"),
	HX_CSTRING("onMouseOver"),
	HX_CSTRING("_onMouseOut"),
	HX_CSTRING("onMouseOut"),
	HX_CSTRING("_onMouseMove"),
	HX_CSTRING("onMouseMove"),
	HX_CSTRING("_clickEvent"),
	HX_CSTRING("_mouseDownEvent"),
	HX_CSTRING("_mouseUpEvent"),
	HX_CSTRING("_mouseOverEvent"),
	HX_CSTRING("_mouseOutEvent"),
	HX_CSTRING("_mouseMoveEvent"),
	HX_CSTRING("_htmlElement"),
	HX_CSTRING("onNativeClick"),
	HX_CSTRING("onNativeMouseDown"),
	HX_CSTRING("onNativeMouseUp"),
	HX_CSTRING("onNativeMouseOver"),
	HX_CSTRING("onNativeMouseOut"),
	HX_CSTRING("onNativeMouseMove"),
	HX_CSTRING("updateListeners"),
	HX_CSTRING("getMouseEvent"),
	HX_CSTRING("set_onClick"),
	HX_CSTRING("get_onClick"),
	HX_CSTRING("setOnMouseDown"),
	HX_CSTRING("getOnMouseDown"),
	HX_CSTRING("setOnMouseUp"),
	HX_CSTRING("getOnMouseUp"),
	HX_CSTRING("setOnMouseOver"),
	HX_CSTRING("getOnMouseOver"),
	HX_CSTRING("setOnMouseOut"),
	HX_CSTRING("getOnMouseOut"),
	HX_CSTRING("setOnMouseMove"),
	HX_CSTRING("getOnMouseMove"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractMouse_obj::__mClass;

void AbstractMouse_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.mouse.AbstractMouse"), hx::TCanCast< AbstractMouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractMouse_obj::__boot()
{
}

} // end namespace core
} // end namespace mouse
