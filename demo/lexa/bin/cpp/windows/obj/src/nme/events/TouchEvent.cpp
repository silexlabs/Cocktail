#include <hxcpp.h>

#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_MouseEvent
#include <nme/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_events_TouchEvent
#include <nme/events/TouchEvent.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace events{

Void TouchEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount)
{
bool bubbles = __o_bubbles.Default(true);
bool cancelable = __o_cancelable.Default(false);
double in_localX = __o_in_localX.Default(0);
double in_localY = __o_in_localY.Default(0);
bool in_ctrlKey = __o_in_ctrlKey.Default(false);
bool in_altKey = __o_in_altKey.Default(false);
bool in_shiftKey = __o_in_shiftKey.Default(false);
bool in_buttonDown = __o_in_buttonDown.Default(false);
int in_delta = __o_in_delta.Default(0);
bool in_commandKey = __o_in_commandKey.Default(false);
int in_clickCount = __o_in_clickCount.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",27)
	super::__construct(type,bubbles,cancelable,in_localX,in_localY,in_relatedObject,in_ctrlKey,in_altKey,in_shiftKey,in_buttonDown,in_delta,in_commandKey,in_clickCount);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",28)
	this->touchPointID = (int)0;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",29)
	this->isPrimaryTouchPoint = true;
}
;
	return null();
}

TouchEvent_obj::~TouchEvent_obj() { }

Dynamic TouchEvent_obj::__CreateEmpty() { return  new TouchEvent_obj; }
hx::ObjectPtr< TouchEvent_obj > TouchEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_in_localX,Dynamic __o_in_localY,::nme::display::InteractiveObject in_relatedObject,Dynamic __o_in_ctrlKey,Dynamic __o_in_altKey,Dynamic __o_in_shiftKey,Dynamic __o_in_buttonDown,Dynamic __o_in_delta,Dynamic __o_in_commandKey,Dynamic __o_in_clickCount)
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_in_localX,__o_in_localY,in_relatedObject,__o_in_ctrlKey,__o_in_altKey,__o_in_shiftKey,__o_in_buttonDown,__o_in_delta,__o_in_commandKey,__o_in_clickCount);
	return result;}

Dynamic TouchEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TouchEvent_obj > result = new TouchEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12]);
	return result;}

::nme::events::MouseEvent TouchEvent_obj::nmeCreateSimilar( ::String inType,::nme::display::InteractiveObject related,::nme::display::InteractiveObject targ){
	HX_SOURCE_PUSH("TouchEvent_obj::nmeCreateSimilar")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",46)
	::nme::events::TouchEvent result = ::nme::events::TouchEvent_obj::__new(inType,this->nmeGetBubbles(),this->nmeGetCancelable(),this->localX,this->localY,(  (((related == null()))) ? ::nme::display::InteractiveObject(this->relatedObject) : ::nme::display::InteractiveObject(related) ),this->ctrlKey,this->altKey,this->shiftKey,this->buttonDown,this->delta,this->commandKey,this->clickCount);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",48)
	result->touchPointID = this->touchPointID;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",49)
	result->isPrimaryTouchPoint = this->isPrimaryTouchPoint;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",50)
	if (((targ != null()))){
		HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",51)
		result->nmeSetTarget(targ);
	}
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",52)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC3(TouchEvent_obj,nmeCreateSimilar,return )

::String TouchEvent_obj::TOUCH_BEGIN;

::String TouchEvent_obj::TOUCH_END;

::String TouchEvent_obj::TOUCH_MOVE;

::String TouchEvent_obj::TOUCH_OUT;

::String TouchEvent_obj::TOUCH_OVER;

::String TouchEvent_obj::TOUCH_ROLL_OUT;

::String TouchEvent_obj::TOUCH_ROLL_OVER;

::String TouchEvent_obj::TOUCH_TAP;

::nme::events::TouchEvent TouchEvent_obj::nmeCreate( ::String inType,Dynamic inEvent,::nme::geom::Point inLocal,::nme::display::InteractiveObject inTarget){
	HX_SOURCE_PUSH("TouchEvent_obj::nmeCreate")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",35)
	int flags = inEvent->__Field(HX_CSTRING("flags"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",36)
	::nme::events::TouchEvent evt = ::nme::events::TouchEvent_obj::__new(inType,true,false,inLocal->x,inLocal->y,null(),(((int(flags) & int(::nme::events::MouseEvent_obj::efCtrlDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efAltDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efShiftDown))) != (int)0),(((int(flags) & int(::nme::events::MouseEvent_obj::efLeftDown))) != (int)0),(int)0,null(),(int)0);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",37)
	evt->stageX = inEvent->__Field(HX_CSTRING("x"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",38)
	evt->stageY = inEvent->__Field(HX_CSTRING("y"));
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",39)
	evt->nmeSetTarget(inTarget);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/TouchEvent.hx",40)
	return evt;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(TouchEvent_obj,nmeCreate,return )


TouchEvent_obj::TouchEvent_obj()
{
}

void TouchEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TouchEvent);
	HX_MARK_MEMBER_NAME(isPrimaryTouchPoint,"isPrimaryTouchPoint");
	HX_MARK_MEMBER_NAME(touchPointID,"touchPointID");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic TouchEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { return TOUCH_END; }
		if (HX_FIELD_EQ(inName,"TOUCH_OUT") ) { return TOUCH_OUT; }
		if (HX_FIELD_EQ(inName,"TOUCH_TAP") ) { return TOUCH_TAP; }
		if (HX_FIELD_EQ(inName,"nmeCreate") ) { return nmeCreate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { return TOUCH_MOVE; }
		if (HX_FIELD_EQ(inName,"TOUCH_OVER") ) { return TOUCH_OVER; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TOUCH_BEGIN") ) { return TOUCH_BEGIN; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { return touchPointID; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OUT") ) { return TOUCH_ROLL_OUT; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OVER") ) { return TOUCH_ROLL_OVER; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"nmeCreateSimilar") ) { return nmeCreateSimilar_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"isPrimaryTouchPoint") ) { return isPrimaryTouchPoint; }
	}
	return super::__Field(inName);
}

Dynamic TouchEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"TOUCH_END") ) { TOUCH_END=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_OUT") ) { TOUCH_OUT=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_TAP") ) { TOUCH_TAP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"TOUCH_MOVE") ) { TOUCH_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TOUCH_OVER") ) { TOUCH_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"TOUCH_BEGIN") ) { TOUCH_BEGIN=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"touchPointID") ) { touchPointID=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OUT") ) { TOUCH_ROLL_OUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"TOUCH_ROLL_OVER") ) { TOUCH_ROLL_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"isPrimaryTouchPoint") ) { isPrimaryTouchPoint=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TouchEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isPrimaryTouchPoint"));
	outFields->push(HX_CSTRING("touchPointID"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TOUCH_BEGIN"),
	HX_CSTRING("TOUCH_END"),
	HX_CSTRING("TOUCH_MOVE"),
	HX_CSTRING("TOUCH_OUT"),
	HX_CSTRING("TOUCH_OVER"),
	HX_CSTRING("TOUCH_ROLL_OUT"),
	HX_CSTRING("TOUCH_ROLL_OVER"),
	HX_CSTRING("TOUCH_TAP"),
	HX_CSTRING("nmeCreate"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isPrimaryTouchPoint"),
	HX_CSTRING("touchPointID"),
	HX_CSTRING("nmeCreateSimilar"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_BEGIN,"TOUCH_BEGIN");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_END,"TOUCH_END");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_MOVE,"TOUCH_MOVE");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_OUT,"TOUCH_OUT");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_OVER,"TOUCH_OVER");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OUT,"TOUCH_ROLL_OUT");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_ROLL_OVER,"TOUCH_ROLL_OVER");
	HX_MARK_MEMBER_NAME(TouchEvent_obj::TOUCH_TAP,"TOUCH_TAP");
};

Class TouchEvent_obj::__mClass;

void TouchEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.TouchEvent"), hx::TCanCast< TouchEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TouchEvent_obj::__boot()
{
	hx::Static(TOUCH_BEGIN) = HX_CSTRING("touchBegin");
	hx::Static(TOUCH_END) = HX_CSTRING("touchEnd");
	hx::Static(TOUCH_MOVE) = HX_CSTRING("touchMove");
	hx::Static(TOUCH_OUT) = HX_CSTRING("touchOut");
	hx::Static(TOUCH_OVER) = HX_CSTRING("touchOver");
	hx::Static(TOUCH_ROLL_OUT) = HX_CSTRING("touchRollOut");
	hx::Static(TOUCH_ROLL_OVER) = HX_CSTRING("touchRollOver");
	hx::Static(TOUCH_TAP) = HX_CSTRING("touchTap");
}

} // end namespace nme
} // end namespace events
