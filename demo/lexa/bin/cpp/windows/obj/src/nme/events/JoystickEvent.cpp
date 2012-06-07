#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_JoystickEvent
#include <nme/events/JoystickEvent.h>
#endif
namespace nme{
namespace events{

Void JoystickEvent_obj::__construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_device,Dynamic __o_id,Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{
bool bubbles = __o_bubbles.Default(false);
bool cancelable = __o_cancelable.Default(false);
int device = __o_device.Default(0);
int id = __o_id.Default(0);
double x = __o_x.Default(0);
double y = __o_y.Default(0);
double z = __o_z.Default(0);
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",22)
	super::__construct(type,bubbles,cancelable);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",24)
	this->device = device;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",25)
	this->id = id;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",26)
	this->x = x;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",27)
	this->y = y;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",28)
	this->z = z;
}
;
	return null();
}

JoystickEvent_obj::~JoystickEvent_obj() { }

Dynamic JoystickEvent_obj::__CreateEmpty() { return  new JoystickEvent_obj; }
hx::ObjectPtr< JoystickEvent_obj > JoystickEvent_obj::__new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable,Dynamic __o_device,Dynamic __o_id,Dynamic __o_x,Dynamic __o_y,Dynamic __o_z)
{  hx::ObjectPtr< JoystickEvent_obj > result = new JoystickEvent_obj();
	result->__construct(type,__o_bubbles,__o_cancelable,__o_device,__o_id,__o_x,__o_y,__o_z);
	return result;}

Dynamic JoystickEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< JoystickEvent_obj > result = new JoystickEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7]);
	return result;}

::nme::events::Event JoystickEvent_obj::clone( ){
	HX_SOURCE_PUSH("JoystickEvent_obj::clone")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",33)
	return ::nme::events::JoystickEvent_obj::__new(this->nmeGetType(),this->nmeGetBubbles(),this->nmeGetCancelable(),this->device,this->id,this->x,this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(JoystickEvent_obj,clone,return )

::String JoystickEvent_obj::toString( ){
	HX_SOURCE_PUSH("JoystickEvent_obj::toString")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/events/JoystickEvent.hx",39)
	return ((((((((((((((((HX_CSTRING("[JoystickEvent type=") + this->nmeGetType()) + HX_CSTRING(" bubbles=")) + this->nmeGetBubbles()) + HX_CSTRING(" cancelable=")) + this->nmeGetCancelable()) + HX_CSTRING(" device=")) + this->device) + HX_CSTRING(" id=")) + this->id) + HX_CSTRING(" x=")) + this->x) + HX_CSTRING(" y=")) + this->y) + HX_CSTRING(" z=")) + this->z) + HX_CSTRING("]"));
}


HX_DEFINE_DYNAMIC_FUNC0(JoystickEvent_obj,toString,return )

::String JoystickEvent_obj::AXIS_MOVE;

::String JoystickEvent_obj::BALL_MOVE;

::String JoystickEvent_obj::BUTTON_DOWN;

::String JoystickEvent_obj::BUTTON_UP;

::String JoystickEvent_obj::HAT_MOVE;


JoystickEvent_obj::JoystickEvent_obj()
{
}

void JoystickEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(JoystickEvent);
	HX_MARK_MEMBER_NAME(device,"device");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic JoystickEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"device") ) { return device; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HAT_MOVE") ) { return HAT_MOVE; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AXIS_MOVE") ) { return AXIS_MOVE; }
		if (HX_FIELD_EQ(inName,"BALL_MOVE") ) { return BALL_MOVE; }
		if (HX_FIELD_EQ(inName,"BUTTON_UP") ) { return BUTTON_UP; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"BUTTON_DOWN") ) { return BUTTON_DOWN; }
	}
	return super::__Field(inName);
}

Dynamic JoystickEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< double >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< double >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"device") ) { device=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"HAT_MOVE") ) { HAT_MOVE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"AXIS_MOVE") ) { AXIS_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BALL_MOVE") ) { BALL_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BUTTON_UP") ) { BUTTON_UP=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"BUTTON_DOWN") ) { BUTTON_DOWN=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void JoystickEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("device"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("AXIS_MOVE"),
	HX_CSTRING("BALL_MOVE"),
	HX_CSTRING("BUTTON_DOWN"),
	HX_CSTRING("BUTTON_UP"),
	HX_CSTRING("HAT_MOVE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("device"),
	HX_CSTRING("id"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	HX_CSTRING("clone"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(JoystickEvent_obj::AXIS_MOVE,"AXIS_MOVE");
	HX_MARK_MEMBER_NAME(JoystickEvent_obj::BALL_MOVE,"BALL_MOVE");
	HX_MARK_MEMBER_NAME(JoystickEvent_obj::BUTTON_DOWN,"BUTTON_DOWN");
	HX_MARK_MEMBER_NAME(JoystickEvent_obj::BUTTON_UP,"BUTTON_UP");
	HX_MARK_MEMBER_NAME(JoystickEvent_obj::HAT_MOVE,"HAT_MOVE");
};

Class JoystickEvent_obj::__mClass;

void JoystickEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.events.JoystickEvent"), hx::TCanCast< JoystickEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void JoystickEvent_obj::__boot()
{
	hx::Static(AXIS_MOVE) = HX_CSTRING("axisMove");
	hx::Static(BALL_MOVE) = HX_CSTRING("ballMove");
	hx::Static(BUTTON_DOWN) = HX_CSTRING("buttonDown");
	hx::Static(BUTTON_UP) = HX_CSTRING("buttonUp");
	hx::Static(HAT_MOVE) = HX_CSTRING("hatMove");
}

} // end namespace nme
} // end namespace events
