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
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace event{

Void MouseEvent_obj::__construct(::String type,::port::flash_player::HTMLElement target,double detail,double screenX,double screenY,double clientX,double clientY,bool ctrlKey,bool shiftKey,bool altKey)
{
{
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",125)
	super::__construct(type,target,detail);
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",127)
	this->_screenX = screenX;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",128)
	this->_screenY = screenY;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",129)
	this->_clientX = clientX;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",130)
	this->_clientY = clientY;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",131)
	this->_ctrlKey = ctrlKey;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",132)
	this->_shiftKey = shiftKey;
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",133)
	this->_altKey = altKey;
}
;
	return null();
}

MouseEvent_obj::~MouseEvent_obj() { }

Dynamic MouseEvent_obj::__CreateEmpty() { return  new MouseEvent_obj; }
hx::ObjectPtr< MouseEvent_obj > MouseEvent_obj::__new(::String type,::port::flash_player::HTMLElement target,double detail,double screenX,double screenY,double clientX,double clientY,bool ctrlKey,bool shiftKey,bool altKey)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(type,target,detail,screenX,screenY,clientX,clientY,ctrlKey,shiftKey,altKey);
	return result;}

Dynamic MouseEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9]);
	return result;}

bool MouseEvent_obj::get_altKey( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_altKey")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",141)
	return this->_altKey;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_altKey,return )

bool MouseEvent_obj::get_shiftKey( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_shiftKey")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",146)
	return this->_shiftKey;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_shiftKey,return )

bool MouseEvent_obj::get_ctrlKey( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_ctrlKey")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",151)
	return this->_ctrlKey;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_ctrlKey,return )

double MouseEvent_obj::get_clientY( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_clientY")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",156)
	return this->_clientY;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_clientY,return )

double MouseEvent_obj::get_clientX( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_clientX")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",161)
	return this->_clientX;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_clientX,return )

double MouseEvent_obj::get_screenX( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_screenX")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",166)
	return this->_screenX;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_screenX,return )

double MouseEvent_obj::get_screenY( ){
	HX_SOURCE_PUSH("MouseEvent_obj::get_screenY")
	HX_SOURCE_POS("../../src/core/event/MouseEvent.hx",171)
	return this->_screenY;
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,get_screenY,return )

::String MouseEvent_obj::CLICK;

::String MouseEvent_obj::MOUSE_UP;

::String MouseEvent_obj::MOUSE_DOWN;

::String MouseEvent_obj::MOUSE_OVER;

::String MouseEvent_obj::MOUSE_OUT;

::String MouseEvent_obj::MOUSE_MOVE;


MouseEvent_obj::MouseEvent_obj()
{
}

void MouseEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MouseEvent);
	HX_MARK_MEMBER_NAME(_screenX,"_screenX");
	HX_MARK_MEMBER_NAME(screenX,"screenX");
	HX_MARK_MEMBER_NAME(_screenY,"_screenY");
	HX_MARK_MEMBER_NAME(screenY,"screenY");
	HX_MARK_MEMBER_NAME(_clientX,"_clientX");
	HX_MARK_MEMBER_NAME(clientX,"clientX");
	HX_MARK_MEMBER_NAME(_clientY,"_clientY");
	HX_MARK_MEMBER_NAME(clientY,"clientY");
	HX_MARK_MEMBER_NAME(_ctrlKey,"_ctrlKey");
	HX_MARK_MEMBER_NAME(ctrlKey,"ctrlKey");
	HX_MARK_MEMBER_NAME(_shiftKey,"_shiftKey");
	HX_MARK_MEMBER_NAME(shiftKey,"shiftKey");
	HX_MARK_MEMBER_NAME(_altKey,"_altKey");
	HX_MARK_MEMBER_NAME(altKey,"altKey");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic MouseEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CLICK") ) { return CLICK; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { return get_altKey(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"screenX") ) { return get_screenX(); }
		if (HX_FIELD_EQ(inName,"screenY") ) { return get_screenY(); }
		if (HX_FIELD_EQ(inName,"clientX") ) { return get_clientX(); }
		if (HX_FIELD_EQ(inName,"clientY") ) { return get_clientY(); }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { return get_ctrlKey(); }
		if (HX_FIELD_EQ(inName,"_altKey") ) { return _altKey; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { return MOUSE_UP; }
		if (HX_FIELD_EQ(inName,"_screenX") ) { return _screenX; }
		if (HX_FIELD_EQ(inName,"_screenY") ) { return _screenY; }
		if (HX_FIELD_EQ(inName,"_clientX") ) { return _clientX; }
		if (HX_FIELD_EQ(inName,"_clientY") ) { return _clientY; }
		if (HX_FIELD_EQ(inName,"_ctrlKey") ) { return _ctrlKey; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { return get_shiftKey(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { return MOUSE_OUT; }
		if (HX_FIELD_EQ(inName,"_shiftKey") ) { return _shiftKey; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { return MOUSE_DOWN; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { return MOUSE_OVER; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { return MOUSE_MOVE; }
		if (HX_FIELD_EQ(inName,"get_altKey") ) { return get_altKey_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_ctrlKey") ) { return get_ctrlKey_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientY") ) { return get_clientY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clientX") ) { return get_clientX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_screenX") ) { return get_screenX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_screenY") ) { return get_screenY_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_shiftKey") ) { return get_shiftKey_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MouseEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CLICK") ) { CLICK=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"altKey") ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"screenX") ) { screenX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"screenY") ) { screenY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientX") ) { clientX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clientY") ) { clientY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctrlKey") ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_altKey") ) { _altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_screenX") ) { _screenX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_screenY") ) { _screenY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_clientX") ) { _clientX=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_clientY") ) { _clientY=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_ctrlKey") ) { _ctrlKey=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shiftKey") ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { MOUSE_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_shiftKey") ) { _shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { MOUSE_OVER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { MOUSE_MOVE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MouseEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_screenX"));
	outFields->push(HX_CSTRING("screenX"));
	outFields->push(HX_CSTRING("_screenY"));
	outFields->push(HX_CSTRING("screenY"));
	outFields->push(HX_CSTRING("_clientX"));
	outFields->push(HX_CSTRING("clientX"));
	outFields->push(HX_CSTRING("_clientY"));
	outFields->push(HX_CSTRING("clientY"));
	outFields->push(HX_CSTRING("_ctrlKey"));
	outFields->push(HX_CSTRING("ctrlKey"));
	outFields->push(HX_CSTRING("_shiftKey"));
	outFields->push(HX_CSTRING("shiftKey"));
	outFields->push(HX_CSTRING("_altKey"));
	outFields->push(HX_CSTRING("altKey"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CLICK"),
	HX_CSTRING("MOUSE_UP"),
	HX_CSTRING("MOUSE_DOWN"),
	HX_CSTRING("MOUSE_OVER"),
	HX_CSTRING("MOUSE_OUT"),
	HX_CSTRING("MOUSE_MOVE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_screenX"),
	HX_CSTRING("screenX"),
	HX_CSTRING("_screenY"),
	HX_CSTRING("screenY"),
	HX_CSTRING("_clientX"),
	HX_CSTRING("clientX"),
	HX_CSTRING("_clientY"),
	HX_CSTRING("clientY"),
	HX_CSTRING("_ctrlKey"),
	HX_CSTRING("ctrlKey"),
	HX_CSTRING("_shiftKey"),
	HX_CSTRING("shiftKey"),
	HX_CSTRING("_altKey"),
	HX_CSTRING("altKey"),
	HX_CSTRING("get_altKey"),
	HX_CSTRING("get_shiftKey"),
	HX_CSTRING("get_ctrlKey"),
	HX_CSTRING("get_clientY"),
	HX_CSTRING("get_clientX"),
	HX_CSTRING("get_screenX"),
	HX_CSTRING("get_screenY"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MouseEvent_obj::CLICK,"CLICK");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_UP,"MOUSE_UP");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_DOWN,"MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_OVER,"MOUSE_OVER");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_OUT,"MOUSE_OUT");
	HX_MARK_MEMBER_NAME(MouseEvent_obj::MOUSE_MOVE,"MOUSE_MOVE");
};

Class MouseEvent_obj::__mClass;

void MouseEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.event.MouseEvent"), hx::TCanCast< MouseEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MouseEvent_obj::__boot()
{
	hx::Static(CLICK) = HX_CSTRING("click");
	hx::Static(MOUSE_UP) = HX_CSTRING("mouseup");
	hx::Static(MOUSE_DOWN) = HX_CSTRING("mousedown");
	hx::Static(MOUSE_OVER) = HX_CSTRING("mouseover");
	hx::Static(MOUSE_OUT) = HX_CSTRING("mouseout");
	hx::Static(MOUSE_MOVE) = HX_CSTRING("mousemove");
}

} // end namespace core
} // end namespace event
