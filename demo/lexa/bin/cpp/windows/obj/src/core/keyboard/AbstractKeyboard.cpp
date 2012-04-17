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
#ifndef INCLUDED_core_event_KeyboardEvent
#include <core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_core_event_UIEvent
#include <core/event/UIEvent.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_keyboard_AbstractKeyboard
#include <core/keyboard/AbstractKeyboard.h>
#endif
#ifndef INCLUDED_core_keyboard_KeyboardKeyValue
#include <core/keyboard/KeyboardKeyValue.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace keyboard{

Void AbstractKeyboard_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",69)
	this->_htmlElement = htmlElement;
}
;
	return null();
}

AbstractKeyboard_obj::~AbstractKeyboard_obj() { }

Dynamic AbstractKeyboard_obj::__CreateEmpty() { return  new AbstractKeyboard_obj; }
hx::ObjectPtr< AbstractKeyboard_obj > AbstractKeyboard_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractKeyboard_obj > result = new AbstractKeyboard_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractKeyboard_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractKeyboard_obj > result = new AbstractKeyboard_obj();
	result->__construct(inArgs[0]);
	return result;}

Void AbstractKeyboard_obj::onNativeKeyDown( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::onNativeKeyDown")
		HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",83)
		if (((this->getOnKeyDown() != null()))){
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",85)
			this->getOnKeyDown()(this->getKeyData(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,onNativeKeyDown,(void))

Void AbstractKeyboard_obj::onNativeKeyUp( Dynamic event){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::onNativeKeyUp")
		HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",96)
		if (((this->getOnKeyUp() != null()))){
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",98)
			this->getOnKeyUp()(this->getKeyData(event)).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,onNativeKeyUp,(void))

Dynamic AbstractKeyboard_obj::setOnKeyDown( Dynamic value){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::setOnKeyDown")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",109)
	this->updateListeners(this->_keyDownEvent,this->onNativeKeyDown_dyn(),value);
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",110)
	return this->_onKeyDown = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,setOnKeyDown,return )

Dynamic AbstractKeyboard_obj::getOnKeyDown( ){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getOnKeyDown")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",114)
	return this->_onKeyDown_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractKeyboard_obj,getOnKeyDown,return )

Dynamic AbstractKeyboard_obj::setOnKeyUp( Dynamic value){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::setOnKeyUp")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",120)
	this->updateListeners(this->_keyUpEvent,this->onNativeKeyUp_dyn(),value);
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",121)
	return this->_onKeyUp = value;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,setOnKeyUp,return )

Dynamic AbstractKeyboard_obj::getOnKeyUp( ){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getOnKeyUp")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",125)
	return this->_onKeyUp_dyn();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractKeyboard_obj,getOnKeyUp,return )

Void AbstractKeyboard_obj::updateListeners( ::String keyboardEvent,Dynamic nativeCallback,Dynamic htmlElementCallback){
{
		HX_SOURCE_PUSH("AbstractKeyboard_obj::updateListeners")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractKeyboard_obj,updateListeners,(void))

::core::event::KeyboardEvent AbstractKeyboard_obj::getKeyData( Dynamic event){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getKeyData")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",152)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,getKeyData,return )

::core::keyboard::KeyboardKeyValue AbstractKeyboard_obj::getKeyValue( int keyCode){
	HX_SOURCE_PUSH("AbstractKeyboard_obj::getKeyValue")
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",164)
	::core::keyboard::KeyboardKeyValue keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::unknown_dyn();
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",166)
	switch( (int)(keyCode)){
		case (int)65: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",168)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::a_dyn();
		}
		;break;
		case (int)66: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",171)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::b_dyn();
		}
		;break;
		case (int)67: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",174)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::c_dyn();
		}
		;break;
		case (int)68: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",177)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::d_dyn();
		}
		;break;
		case (int)69: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",180)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::e_dyn();
		}
		;break;
		case (int)70: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",183)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::f_dyn();
		}
		;break;
		case (int)71: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",186)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::g_dyn();
		}
		;break;
		case (int)72: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",189)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::h_dyn();
		}
		;break;
		case (int)73: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",192)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::i_dyn();
		}
		;break;
		case (int)74: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",195)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::j_dyn();
		}
		;break;
		case (int)75: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",198)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::k_dyn();
		}
		;break;
		case (int)76: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",201)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::l_dyn();
		}
		;break;
		case (int)77: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",204)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::m_dyn();
		}
		;break;
		case (int)78: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",207)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::n_dyn();
		}
		;break;
		case (int)79: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",210)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::o_dyn();
		}
		;break;
		case (int)80: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",213)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::p_dyn();
		}
		;break;
		case (int)81: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",216)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::q_dyn();
		}
		;break;
		case (int)82: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",219)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::r_dyn();
		}
		;break;
		case (int)83: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",222)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::s_dyn();
		}
		;break;
		case (int)84: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",225)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::t_dyn();
		}
		;break;
		case (int)85: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",228)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::u_dyn();
		}
		;break;
		case (int)86: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",231)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::v_dyn();
		}
		;break;
		case (int)87: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",234)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::w_dyn();
		}
		;break;
		case (int)88: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",237)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::x_dyn();
		}
		;break;
		case (int)89: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",240)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::y_dyn();
		}
		;break;
		case (int)90: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",243)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::z_dyn();
		}
		;break;
		case (int)8: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",246)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::backSpace_dyn();
		}
		;break;
		case (int)20: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",249)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::capsLock_dyn();
		}
		;break;
		case (int)17: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",252)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::control_dyn();
		}
		;break;
		case (int)46: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",255)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::del_dyn();
		}
		;break;
		case (int)40: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",258)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::down_dyn();
		}
		;break;
		case (int)35: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",261)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::end_dyn();
		}
		;break;
		case (int)13: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",264)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::enter_dyn();
		}
		;break;
		case (int)27: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",267)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::escape_dyn();
		}
		;break;
		case (int)112: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",270)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F1_dyn();
		}
		;break;
		case (int)121: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",273)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F10_dyn();
		}
		;break;
		case (int)122: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",276)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F11_dyn();
		}
		;break;
		case (int)123: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",279)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F12_dyn();
		}
		;break;
		case (int)124: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",282)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F13_dyn();
		}
		;break;
		case (int)125: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",285)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F14_dyn();
		}
		;break;
		case (int)126: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",288)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F15_dyn();
		}
		;break;
		case (int)113: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",291)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F2_dyn();
		}
		;break;
		case (int)114: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",294)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F3_dyn();
		}
		;break;
		case (int)115: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",297)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F4_dyn();
		}
		;break;
		case (int)116: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",300)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F5_dyn();
		}
		;break;
		case (int)117: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",303)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F6_dyn();
		}
		;break;
		case (int)118: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",306)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F7_dyn();
		}
		;break;
		case (int)119: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",309)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F8_dyn();
		}
		;break;
		case (int)120: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",312)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::F9_dyn();
		}
		;break;
		case (int)36: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",315)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::home_dyn();
		}
		;break;
		case (int)45: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",318)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::insert_dyn();
		}
		;break;
		case (int)37: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",321)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::left_dyn();
		}
		;break;
		case (int)96: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",324)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad0_dyn();
		}
		;break;
		case (int)97: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",327)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad1_dyn();
		}
		;break;
		case (int)98: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",330)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad2_dyn();
		}
		;break;
		case (int)99: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",333)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad3_dyn();
		}
		;break;
		case (int)100: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",336)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad4_dyn();
		}
		;break;
		case (int)101: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",339)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad5_dyn();
		}
		;break;
		case (int)102: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",342)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad6_dyn();
		}
		;break;
		case (int)103: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",345)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad7_dyn();
		}
		;break;
		case (int)104: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",348)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad8_dyn();
		}
		;break;
		case (int)105: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",351)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpad9_dyn();
		}
		;break;
		case (int)107: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",354)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadAdd_dyn();
		}
		;break;
		case (int)108: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",357)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadEnter_dyn();
		}
		;break;
		case (int)110: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",360)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadDecimal_dyn();
		}
		;break;
		case (int)111: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",363)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadDivide_dyn();
		}
		;break;
		case (int)106: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",366)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadMultiply_dyn();
		}
		;break;
		case (int)109: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",369)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::numpadSubstract_dyn();
		}
		;break;
		case (int)34: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",372)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::pageDown_dyn();
		}
		;break;
		case (int)33: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",375)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::pageUp_dyn();
		}
		;break;
		case (int)39: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",378)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::right_dyn();
		}
		;break;
		case (int)16: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",381)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::shift_dyn();
		}
		;break;
		case (int)32: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",384)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::space_dyn();
		}
		;break;
		case (int)9: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",387)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::tab_dyn();
		}
		;break;
		case (int)38: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",390)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::up_dyn();
		}
		;break;
		default: {
			HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",393)
			keyboardKeyValue = ::core::keyboard::KeyboardKeyValue_obj::unknown_dyn();
		}
	}
	HX_SOURCE_POS("../../src/core/keyboard/AbstractKeyboard.hx",397)
	return keyboardKeyValue;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractKeyboard_obj,getKeyValue,return )

int AbstractKeyboard_obj::TAB;

int AbstractKeyboard_obj::ENTER;

int AbstractKeyboard_obj::SPACE;


AbstractKeyboard_obj::AbstractKeyboard_obj()
{
}

void AbstractKeyboard_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractKeyboard);
	HX_MARK_MEMBER_NAME(_onKeyDown,"_onKeyDown");
	HX_MARK_MEMBER_NAME(onKeyDown,"onKeyDown");
	HX_MARK_MEMBER_NAME(_onKeyUp,"_onKeyUp");
	HX_MARK_MEMBER_NAME(onKeyUp,"onKeyUp");
	HX_MARK_MEMBER_NAME(_htmlElement,"_htmlElement");
	HX_MARK_MEMBER_NAME(_keyDownEvent,"_keyDownEvent");
	HX_MARK_MEMBER_NAME(_keyUpEvent,"_keyUpEvent");
	HX_MARK_END_CLASS();
}

Dynamic AbstractKeyboard_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"TAB") ) { return TAB; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ENTER") ) { return ENTER; }
		if (HX_FIELD_EQ(inName,"SPACE") ) { return SPACE; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return getOnKeyUp(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { return _onKeyUp; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return getOnKeyDown(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { return _onKeyDown; }
		if (HX_FIELD_EQ(inName,"setOnKeyUp") ) { return setOnKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnKeyUp") ) { return getOnKeyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"getKeyData") ) { return getKeyData_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_keyUpEvent") ) { return _keyUpEvent; }
		if (HX_FIELD_EQ(inName,"getKeyValue") ) { return getKeyValue_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { return _htmlElement; }
		if (HX_FIELD_EQ(inName,"setOnKeyDown") ) { return setOnKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"getOnKeyDown") ) { return getOnKeyDown_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_keyDownEvent") ) { return _keyDownEvent; }
		if (HX_FIELD_EQ(inName,"onNativeKeyUp") ) { return onNativeKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"onNativeKeyDown") ) { return onNativeKeyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"updateListeners") ) { return updateListeners_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractKeyboard_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"TAB") ) { TAB=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ENTER") ) { ENTER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SPACE") ) { SPACE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return setOnKeyUp(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_onKeyUp") ) { _onKeyUp=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return setOnKeyDown(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_onKeyDown") ) { _onKeyDown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"_keyUpEvent") ) { _keyUpEvent=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_htmlElement") ) { _htmlElement=inValue.Cast< ::port::flash_player::HTMLElement >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_keyDownEvent") ) { _keyDownEvent=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractKeyboard_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_htmlElement"));
	outFields->push(HX_CSTRING("_keyDownEvent"));
	outFields->push(HX_CSTRING("_keyUpEvent"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TAB"),
	HX_CSTRING("ENTER"),
	HX_CSTRING("SPACE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_onKeyDown"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("_onKeyUp"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("_htmlElement"),
	HX_CSTRING("_keyDownEvent"),
	HX_CSTRING("_keyUpEvent"),
	HX_CSTRING("onNativeKeyDown"),
	HX_CSTRING("onNativeKeyUp"),
	HX_CSTRING("setOnKeyDown"),
	HX_CSTRING("getOnKeyDown"),
	HX_CSTRING("setOnKeyUp"),
	HX_CSTRING("getOnKeyUp"),
	HX_CSTRING("updateListeners"),
	HX_CSTRING("getKeyData"),
	HX_CSTRING("getKeyValue"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AbstractKeyboard_obj::TAB,"TAB");
	HX_MARK_MEMBER_NAME(AbstractKeyboard_obj::ENTER,"ENTER");
	HX_MARK_MEMBER_NAME(AbstractKeyboard_obj::SPACE,"SPACE");
};

Class AbstractKeyboard_obj::__mClass;

void AbstractKeyboard_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.keyboard.AbstractKeyboard"), hx::TCanCast< AbstractKeyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractKeyboard_obj::__boot()
{
	hx::Static(TAB) = (int)9;
	hx::Static(ENTER) = (int)13;
	hx::Static(SPACE) = (int)32;
}

} // end namespace core
} // end namespace keyboard
