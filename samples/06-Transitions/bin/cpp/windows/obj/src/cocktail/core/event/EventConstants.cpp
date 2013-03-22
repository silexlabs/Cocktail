#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_EventConstants
#include <cocktail/core/event/EventConstants.h>
#endif
namespace cocktail{
namespace core{
namespace event{

Void EventConstants_obj::__construct()
{
HX_STACK_PUSH("EventConstants::new","cocktail/core/event/EventConstants.hx",484);
{
}
;
	return null();
}

EventConstants_obj::~EventConstants_obj() { }

Dynamic EventConstants_obj::__CreateEmpty() { return  new EventConstants_obj; }
hx::ObjectPtr< EventConstants_obj > EventConstants_obj::__new()
{  hx::ObjectPtr< EventConstants_obj > result = new EventConstants_obj();
	result->__construct();
	return result;}

Dynamic EventConstants_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventConstants_obj > result = new EventConstants_obj();
	result->__construct();
	return result;}

::String EventConstants_obj::PLAY;

::String EventConstants_obj::PLAYING;

::String EventConstants_obj::PAUSE;

::String EventConstants_obj::ABORT;

::String EventConstants_obj::LOAD_START;

::String EventConstants_obj::WAITING;

::String EventConstants_obj::TIME_UPDATE;

::String EventConstants_obj::ENDED;

::String EventConstants_obj::LOADED_DATA;

::String EventConstants_obj::SEEKING;

::String EventConstants_obj::SEEKED;

::String EventConstants_obj::PROGRESS;

::String EventConstants_obj::CAN_PLAY;

::String EventConstants_obj::EMPTIED;

::String EventConstants_obj::LOADED_METADATA;

::String EventConstants_obj::DURATION_CHANGE;

::String EventConstants_obj::VOLUME_CHANGE;

::String EventConstants_obj::SUSPEND;

::String EventConstants_obj::STALLED;

::String EventConstants_obj::CAN_PLAY_THROUGH;

::String EventConstants_obj::READY_STATE_CHANGE;

::String EventConstants_obj::TIME_OUT;

::String EventConstants_obj::LOAD_END;

::String EventConstants_obj::FULL_SCREEN_CHANGE;

::String EventConstants_obj::FOCUS;

::String EventConstants_obj::BLUR;

::String EventConstants_obj::FOCUS_IN;

::String EventConstants_obj::FOCUS_OUT;

::String EventConstants_obj::KEY_DOWN;

::String EventConstants_obj::KEY_UP;

::String EventConstants_obj::CLICK;

::String EventConstants_obj::DOUBLE_CLICK;

::String EventConstants_obj::MOUSE_UP;

::String EventConstants_obj::MOUSE_DOWN;

::String EventConstants_obj::MOUSE_OVER;

::String EventConstants_obj::MOUSE_OUT;

::String EventConstants_obj::MOUSE_MOVE;

::String EventConstants_obj::MOUSE_LEAVE;

::String EventConstants_obj::TOUCH_START;

::String EventConstants_obj::TOUCH_END;

::String EventConstants_obj::TOUCH_MOVE;

::String EventConstants_obj::TOUCH_CANCEL;

::String EventConstants_obj::TRANSITION_END;

::String EventConstants_obj::SCROLL;

::String EventConstants_obj::RESIZE;

::String EventConstants_obj::LOAD;

::String EventConstants_obj::ERROR;

::String EventConstants_obj::CHANGE;

::String EventConstants_obj::INPUT;

::String EventConstants_obj::RESET;

::String EventConstants_obj::SUBMIT;

::String EventConstants_obj::MOUSE_WHEEL;

::String EventConstants_obj::POP_STATE;

::String EventConstants_obj::CONFIG_CHANGED;


EventConstants_obj::EventConstants_obj()
{
}

void EventConstants_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EventConstants);
	HX_MARK_END_CLASS();
}

void EventConstants_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic EventConstants_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"PLAY") ) { return PLAY; }
		if (HX_FIELD_EQ(inName,"BLUR") ) { return BLUR; }
		if (HX_FIELD_EQ(inName,"LOAD") ) { return LOAD; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PAUSE") ) { return PAUSE; }
		if (HX_FIELD_EQ(inName,"ABORT") ) { return ABORT; }
		if (HX_FIELD_EQ(inName,"ENDED") ) { return ENDED; }
		if (HX_FIELD_EQ(inName,"FOCUS") ) { return FOCUS; }
		if (HX_FIELD_EQ(inName,"CLICK") ) { return CLICK; }
		if (HX_FIELD_EQ(inName,"ERROR") ) { return ERROR; }
		if (HX_FIELD_EQ(inName,"INPUT") ) { return INPUT; }
		if (HX_FIELD_EQ(inName,"RESET") ) { return RESET; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SEEKED") ) { return SEEKED; }
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { return KEY_UP; }
		if (HX_FIELD_EQ(inName,"SCROLL") ) { return SCROLL; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { return RESIZE; }
		if (HX_FIELD_EQ(inName,"CHANGE") ) { return CHANGE; }
		if (HX_FIELD_EQ(inName,"SUBMIT") ) { return SUBMIT; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"PLAYING") ) { return PLAYING; }
		if (HX_FIELD_EQ(inName,"WAITING") ) { return WAITING; }
		if (HX_FIELD_EQ(inName,"SEEKING") ) { return SEEKING; }
		if (HX_FIELD_EQ(inName,"EMPTIED") ) { return EMPTIED; }
		if (HX_FIELD_EQ(inName,"SUSPEND") ) { return SUSPEND; }
		if (HX_FIELD_EQ(inName,"STALLED") ) { return STALLED; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"PROGRESS") ) { return PROGRESS; }
		if (HX_FIELD_EQ(inName,"CAN_PLAY") ) { return CAN_PLAY; }
		if (HX_FIELD_EQ(inName,"TIME_OUT") ) { return TIME_OUT; }
		if (HX_FIELD_EQ(inName,"LOAD_END") ) { return LOAD_END; }
		if (HX_FIELD_EQ(inName,"FOCUS_IN") ) { return FOCUS_IN; }
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { return KEY_DOWN; }
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { return MOUSE_UP; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FOCUS_OUT") ) { return FOCUS_OUT; }
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { return MOUSE_OUT; }
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { return TOUCH_END; }
		if (HX_FIELD_EQ(inName,"POP_STATE") ) { return POP_STATE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LOAD_START") ) { return LOAD_START; }
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { return MOUSE_DOWN; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { return MOUSE_OVER; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { return MOUSE_MOVE; }
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { return TOUCH_MOVE; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TIME_UPDATE") ) { return TIME_UPDATE; }
		if (HX_FIELD_EQ(inName,"LOADED_DATA") ) { return LOADED_DATA; }
		if (HX_FIELD_EQ(inName,"MOUSE_LEAVE") ) { return MOUSE_LEAVE; }
		if (HX_FIELD_EQ(inName,"TOUCH_START") ) { return TOUCH_START; }
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL") ) { return MOUSE_WHEEL; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DOUBLE_CLICK") ) { return DOUBLE_CLICK; }
		if (HX_FIELD_EQ(inName,"TOUCH_CANCEL") ) { return TOUCH_CANCEL; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"VOLUME_CHANGE") ) { return VOLUME_CHANGE; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TRANSITION_END") ) { return TRANSITION_END; }
		if (HX_FIELD_EQ(inName,"CONFIG_CHANGED") ) { return CONFIG_CHANGED; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"LOADED_METADATA") ) { return LOADED_METADATA; }
		if (HX_FIELD_EQ(inName,"DURATION_CHANGE") ) { return DURATION_CHANGE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_THROUGH") ) { return CAN_PLAY_THROUGH; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_CHANGE") ) { return READY_STATE_CHANGE; }
		if (HX_FIELD_EQ(inName,"FULL_SCREEN_CHANGE") ) { return FULL_SCREEN_CHANGE; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EventConstants_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"PLAY") ) { PLAY=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLUR") ) { BLUR=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOAD") ) { LOAD=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PAUSE") ) { PAUSE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ABORT") ) { ABORT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ENDED") ) { ENDED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FOCUS") ) { FOCUS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CLICK") ) { CLICK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ERROR") ) { ERROR=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"INPUT") ) { INPUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RESET") ) { RESET=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SEEKED") ) { SEEKED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KEY_UP") ) { KEY_UP=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SCROLL") ) { SCROLL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RESIZE") ) { RESIZE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CHANGE") ) { CHANGE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SUBMIT") ) { SUBMIT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"PLAYING") ) { PLAYING=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WAITING") ) { WAITING=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SEEKING") ) { SEEKING=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"EMPTIED") ) { EMPTIED=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SUSPEND") ) { SUSPEND=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"STALLED") ) { STALLED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"PROGRESS") ) { PROGRESS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CAN_PLAY") ) { CAN_PLAY=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TIME_OUT") ) { TIME_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOAD_END") ) { LOAD_END=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FOCUS_IN") ) { FOCUS_IN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"KEY_DOWN") ) { KEY_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_UP") ) { MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FOCUS_OUT") ) { FOCUS_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_OUT") ) { MOUSE_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { TOUCH_END=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"POP_STATE") ) { POP_STATE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"LOAD_START") ) { LOAD_START=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_DOWN") ) { MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_OVER") ) { MOUSE_OVER=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_MOVE") ) { MOUSE_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { TOUCH_MOVE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TIME_UPDATE") ) { TIME_UPDATE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LOADED_DATA") ) { LOADED_DATA=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_LEAVE") ) { MOUSE_LEAVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_START") ) { TOUCH_START=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MOUSE_WHEEL") ) { MOUSE_WHEEL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DOUBLE_CLICK") ) { DOUBLE_CLICK=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_CANCEL") ) { TOUCH_CANCEL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"VOLUME_CHANGE") ) { VOLUME_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TRANSITION_END") ) { TRANSITION_END=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"CONFIG_CHANGED") ) { CONFIG_CHANGED=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"LOADED_METADATA") ) { LOADED_METADATA=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DURATION_CHANGE") ) { DURATION_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"CAN_PLAY_THROUGH") ) { CAN_PLAY_THROUGH=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"READY_STATE_CHANGE") ) { READY_STATE_CHANGE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FULL_SCREEN_CHANGE") ) { FULL_SCREEN_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EventConstants_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PLAY"),
	HX_CSTRING("PLAYING"),
	HX_CSTRING("PAUSE"),
	HX_CSTRING("ABORT"),
	HX_CSTRING("LOAD_START"),
	HX_CSTRING("WAITING"),
	HX_CSTRING("TIME_UPDATE"),
	HX_CSTRING("ENDED"),
	HX_CSTRING("LOADED_DATA"),
	HX_CSTRING("SEEKING"),
	HX_CSTRING("SEEKED"),
	HX_CSTRING("PROGRESS"),
	HX_CSTRING("CAN_PLAY"),
	HX_CSTRING("EMPTIED"),
	HX_CSTRING("LOADED_METADATA"),
	HX_CSTRING("DURATION_CHANGE"),
	HX_CSTRING("VOLUME_CHANGE"),
	HX_CSTRING("SUSPEND"),
	HX_CSTRING("STALLED"),
	HX_CSTRING("CAN_PLAY_THROUGH"),
	HX_CSTRING("READY_STATE_CHANGE"),
	HX_CSTRING("TIME_OUT"),
	HX_CSTRING("LOAD_END"),
	HX_CSTRING("FULL_SCREEN_CHANGE"),
	HX_CSTRING("FOCUS"),
	HX_CSTRING("BLUR"),
	HX_CSTRING("FOCUS_IN"),
	HX_CSTRING("FOCUS_OUT"),
	HX_CSTRING("KEY_DOWN"),
	HX_CSTRING("KEY_UP"),
	HX_CSTRING("CLICK"),
	HX_CSTRING("DOUBLE_CLICK"),
	HX_CSTRING("MOUSE_UP"),
	HX_CSTRING("MOUSE_DOWN"),
	HX_CSTRING("MOUSE_OVER"),
	HX_CSTRING("MOUSE_OUT"),
	HX_CSTRING("MOUSE_MOVE"),
	HX_CSTRING("MOUSE_LEAVE"),
	HX_CSTRING("TOUCH_START"),
	HX_CSTRING("TOUCH_END"),
	HX_CSTRING("TOUCH_MOVE"),
	HX_CSTRING("TOUCH_CANCEL"),
	HX_CSTRING("TRANSITION_END"),
	HX_CSTRING("SCROLL"),
	HX_CSTRING("RESIZE"),
	HX_CSTRING("LOAD"),
	HX_CSTRING("ERROR"),
	HX_CSTRING("CHANGE"),
	HX_CSTRING("INPUT"),
	HX_CSTRING("RESET"),
	HX_CSTRING("SUBMIT"),
	HX_CSTRING("MOUSE_WHEEL"),
	HX_CSTRING("POP_STATE"),
	HX_CSTRING("CONFIG_CHANGED"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EventConstants_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EventConstants_obj::PLAY,"PLAY");
	HX_MARK_MEMBER_NAME(EventConstants_obj::PLAYING,"PLAYING");
	HX_MARK_MEMBER_NAME(EventConstants_obj::PAUSE,"PAUSE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::ABORT,"ABORT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::LOAD_START,"LOAD_START");
	HX_MARK_MEMBER_NAME(EventConstants_obj::WAITING,"WAITING");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TIME_UPDATE,"TIME_UPDATE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::ENDED,"ENDED");
	HX_MARK_MEMBER_NAME(EventConstants_obj::LOADED_DATA,"LOADED_DATA");
	HX_MARK_MEMBER_NAME(EventConstants_obj::SEEKING,"SEEKING");
	HX_MARK_MEMBER_NAME(EventConstants_obj::SEEKED,"SEEKED");
	HX_MARK_MEMBER_NAME(EventConstants_obj::PROGRESS,"PROGRESS");
	HX_MARK_MEMBER_NAME(EventConstants_obj::CAN_PLAY,"CAN_PLAY");
	HX_MARK_MEMBER_NAME(EventConstants_obj::EMPTIED,"EMPTIED");
	HX_MARK_MEMBER_NAME(EventConstants_obj::LOADED_METADATA,"LOADED_METADATA");
	HX_MARK_MEMBER_NAME(EventConstants_obj::DURATION_CHANGE,"DURATION_CHANGE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::VOLUME_CHANGE,"VOLUME_CHANGE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::SUSPEND,"SUSPEND");
	HX_MARK_MEMBER_NAME(EventConstants_obj::STALLED,"STALLED");
	HX_MARK_MEMBER_NAME(EventConstants_obj::CAN_PLAY_THROUGH,"CAN_PLAY_THROUGH");
	HX_MARK_MEMBER_NAME(EventConstants_obj::READY_STATE_CHANGE,"READY_STATE_CHANGE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TIME_OUT,"TIME_OUT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::LOAD_END,"LOAD_END");
	HX_MARK_MEMBER_NAME(EventConstants_obj::FULL_SCREEN_CHANGE,"FULL_SCREEN_CHANGE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::FOCUS,"FOCUS");
	HX_MARK_MEMBER_NAME(EventConstants_obj::BLUR,"BLUR");
	HX_MARK_MEMBER_NAME(EventConstants_obj::FOCUS_IN,"FOCUS_IN");
	HX_MARK_MEMBER_NAME(EventConstants_obj::FOCUS_OUT,"FOCUS_OUT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::KEY_DOWN,"KEY_DOWN");
	HX_MARK_MEMBER_NAME(EventConstants_obj::KEY_UP,"KEY_UP");
	HX_MARK_MEMBER_NAME(EventConstants_obj::CLICK,"CLICK");
	HX_MARK_MEMBER_NAME(EventConstants_obj::DOUBLE_CLICK,"DOUBLE_CLICK");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_UP,"MOUSE_UP");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_DOWN,"MOUSE_DOWN");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_OVER,"MOUSE_OVER");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_OUT,"MOUSE_OUT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_MOVE,"MOUSE_MOVE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_LEAVE,"MOUSE_LEAVE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TOUCH_START,"TOUCH_START");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TOUCH_END,"TOUCH_END");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TOUCH_MOVE,"TOUCH_MOVE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TOUCH_CANCEL,"TOUCH_CANCEL");
	HX_MARK_MEMBER_NAME(EventConstants_obj::TRANSITION_END,"TRANSITION_END");
	HX_MARK_MEMBER_NAME(EventConstants_obj::SCROLL,"SCROLL");
	HX_MARK_MEMBER_NAME(EventConstants_obj::RESIZE,"RESIZE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::LOAD,"LOAD");
	HX_MARK_MEMBER_NAME(EventConstants_obj::ERROR,"ERROR");
	HX_MARK_MEMBER_NAME(EventConstants_obj::CHANGE,"CHANGE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::INPUT,"INPUT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::RESET,"RESET");
	HX_MARK_MEMBER_NAME(EventConstants_obj::SUBMIT,"SUBMIT");
	HX_MARK_MEMBER_NAME(EventConstants_obj::MOUSE_WHEEL,"MOUSE_WHEEL");
	HX_MARK_MEMBER_NAME(EventConstants_obj::POP_STATE,"POP_STATE");
	HX_MARK_MEMBER_NAME(EventConstants_obj::CONFIG_CHANGED,"CONFIG_CHANGED");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EventConstants_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::PLAY,"PLAY");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::PLAYING,"PLAYING");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::PAUSE,"PAUSE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::ABORT,"ABORT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::LOAD_START,"LOAD_START");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::WAITING,"WAITING");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TIME_UPDATE,"TIME_UPDATE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::ENDED,"ENDED");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::LOADED_DATA,"LOADED_DATA");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::SEEKING,"SEEKING");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::SEEKED,"SEEKED");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::PROGRESS,"PROGRESS");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::CAN_PLAY,"CAN_PLAY");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::EMPTIED,"EMPTIED");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::LOADED_METADATA,"LOADED_METADATA");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::DURATION_CHANGE,"DURATION_CHANGE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::VOLUME_CHANGE,"VOLUME_CHANGE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::SUSPEND,"SUSPEND");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::STALLED,"STALLED");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::CAN_PLAY_THROUGH,"CAN_PLAY_THROUGH");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::READY_STATE_CHANGE,"READY_STATE_CHANGE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TIME_OUT,"TIME_OUT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::LOAD_END,"LOAD_END");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::FULL_SCREEN_CHANGE,"FULL_SCREEN_CHANGE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::FOCUS,"FOCUS");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::BLUR,"BLUR");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::FOCUS_IN,"FOCUS_IN");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::FOCUS_OUT,"FOCUS_OUT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::KEY_DOWN,"KEY_DOWN");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::KEY_UP,"KEY_UP");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::CLICK,"CLICK");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::DOUBLE_CLICK,"DOUBLE_CLICK");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_UP,"MOUSE_UP");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_DOWN,"MOUSE_DOWN");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_OVER,"MOUSE_OVER");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_OUT,"MOUSE_OUT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_MOVE,"MOUSE_MOVE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_LEAVE,"MOUSE_LEAVE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TOUCH_START,"TOUCH_START");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TOUCH_END,"TOUCH_END");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TOUCH_MOVE,"TOUCH_MOVE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TOUCH_CANCEL,"TOUCH_CANCEL");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::TRANSITION_END,"TRANSITION_END");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::SCROLL,"SCROLL");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::RESIZE,"RESIZE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::LOAD,"LOAD");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::ERROR,"ERROR");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::CHANGE,"CHANGE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::INPUT,"INPUT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::RESET,"RESET");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::SUBMIT,"SUBMIT");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::MOUSE_WHEEL,"MOUSE_WHEEL");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::POP_STATE,"POP_STATE");
	HX_VISIT_MEMBER_NAME(EventConstants_obj::CONFIG_CHANGED,"CONFIG_CHANGED");
};

Class EventConstants_obj::__mClass;

void EventConstants_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.event.EventConstants"), hx::TCanCast< EventConstants_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void EventConstants_obj::__boot()
{
	PLAY= HX_CSTRING("play");
	PLAYING= HX_CSTRING("playing");
	PAUSE= HX_CSTRING("pause");
	ABORT= HX_CSTRING("abort");
	LOAD_START= HX_CSTRING("loadstart");
	WAITING= HX_CSTRING("waiting");
	TIME_UPDATE= HX_CSTRING("timeupdate");
	ENDED= HX_CSTRING("ended");
	LOADED_DATA= HX_CSTRING("loadeddata");
	SEEKING= HX_CSTRING("seeking");
	SEEKED= HX_CSTRING("seeked");
	PROGRESS= HX_CSTRING("progress");
	CAN_PLAY= HX_CSTRING("canplay");
	EMPTIED= HX_CSTRING("emptied");
	LOADED_METADATA= HX_CSTRING("loadedmetadata");
	DURATION_CHANGE= HX_CSTRING("durationchange");
	VOLUME_CHANGE= HX_CSTRING("volumechange");
	SUSPEND= HX_CSTRING("suspend");
	STALLED= HX_CSTRING("stalled");
	CAN_PLAY_THROUGH= HX_CSTRING("canplaythrough");
	READY_STATE_CHANGE= HX_CSTRING("readystatechange");
	TIME_OUT= HX_CSTRING("timeout");
	LOAD_END= HX_CSTRING("loadend");
	FULL_SCREEN_CHANGE= HX_CSTRING("fullscreenchange");
	FOCUS= HX_CSTRING("focus");
	BLUR= HX_CSTRING("blur");
	FOCUS_IN= HX_CSTRING("focusin");
	FOCUS_OUT= HX_CSTRING("focusout");
	KEY_DOWN= HX_CSTRING("keydown");
	KEY_UP= HX_CSTRING("keyup");
	CLICK= HX_CSTRING("click");
	DOUBLE_CLICK= HX_CSTRING("dblclick");
	MOUSE_UP= HX_CSTRING("mouseup");
	MOUSE_DOWN= HX_CSTRING("mousedown");
	MOUSE_OVER= HX_CSTRING("mouseover");
	MOUSE_OUT= HX_CSTRING("mouseout");
	MOUSE_MOVE= HX_CSTRING("mousemove");
	MOUSE_LEAVE= HX_CSTRING("mouseleave");
	TOUCH_START= HX_CSTRING("touchstart");
	TOUCH_END= HX_CSTRING("touchend");
	TOUCH_MOVE= HX_CSTRING("touchmove");
	TOUCH_CANCEL= HX_CSTRING("touchcancel");
	TRANSITION_END= HX_CSTRING("transitionend");
	SCROLL= HX_CSTRING("scroll");
	RESIZE= HX_CSTRING("resize");
	LOAD= HX_CSTRING("load");
	ERROR= HX_CSTRING("error");
	CHANGE= HX_CSTRING("change");
	INPUT= HX_CSTRING("input");
	RESET= HX_CSTRING("reset");
	SUBMIT= HX_CSTRING("submit");
	MOUSE_WHEEL= HX_CSTRING("wheel");
	POP_STATE= HX_CSTRING("popstate");
	CONFIG_CHANGED= HX_CSTRING("configchanged");
}

} // end namespace cocktail
} // end namespace core
} // end namespace event
