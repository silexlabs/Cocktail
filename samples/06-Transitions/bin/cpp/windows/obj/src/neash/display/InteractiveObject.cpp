#include <hxcpp.h>

#ifndef INCLUDED_neash_Loader
#include <neash/Loader.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_IBitmapDrawable
#include <neash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
namespace neash{
namespace display{

Void InteractiveObject_obj::__construct(Dynamic inHandle,::String inType)
{
HX_STACK_PUSH("InteractiveObject::new","neash/display/InteractiveObject.hx",19);
{
	HX_STACK_LINE(20)
	this->doubleClickEnabled = false;
	HX_STACK_LINE(21)
	this->nmeMouseEnabled = true;
	HX_STACK_LINE(23)
	super::__construct(inHandle,inType);
}
;
	return null();
}

InteractiveObject_obj::~InteractiveObject_obj() { }

Dynamic InteractiveObject_obj::__CreateEmpty() { return  new InteractiveObject_obj; }
hx::ObjectPtr< InteractiveObject_obj > InteractiveObject_obj::__new(Dynamic inHandle,::String inType)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(inHandle,inType);
	return result;}

Dynamic InteractiveObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

bool InteractiveObject_obj::nmeGetNeedsSoftKeyboard( ){
	HX_STACK_PUSH("InteractiveObject::nmeGetNeedsSoftKeyboard","neash/display/InteractiveObject.hx",74);
	HX_STACK_THIS(this);
	HX_STACK_LINE(74)
	return ::neash::display::InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetNeedsSoftKeyboard,return )

bool InteractiveObject_obj::nmeSetNeedsSoftKeyboard( bool inVal){
	HX_STACK_PUSH("InteractiveObject::nmeSetNeedsSoftKeyboard","neash/display/InteractiveObject.hx",67);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(68)
	::neash::display::InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard(this->nmeHandle,inVal);
	HX_STACK_LINE(69)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetNeedsSoftKeyboard,return )

bool InteractiveObject_obj::nmeGetMoveForSoftKeyboard( ){
	HX_STACK_PUSH("InteractiveObject::nmeGetMoveForSoftKeyboard","neash/display/InteractiveObject.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	return ::neash::display::InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetMoveForSoftKeyboard,return )

bool InteractiveObject_obj::nmeSetMoveForSoftKeyboard( bool inVal){
	HX_STACK_PUSH("InteractiveObject::nmeSetMoveForSoftKeyboard","neash/display/InteractiveObject.hx",54);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(55)
	::neash::display::InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard(this->nmeHandle,inVal);
	HX_STACK_LINE(56)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetMoveForSoftKeyboard,return )

bool InteractiveObject_obj::nmeSetMouseEnabled( bool inVal){
	HX_STACK_PUSH("InteractiveObject::nmeSetMouseEnabled","neash/display/InteractiveObject.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(inVal,"inVal");
	HX_STACK_LINE(47)
	this->nmeMouseEnabled = inVal;
	HX_STACK_LINE(48)
	::neash::display::InteractiveObject_obj::nme_display_object_set_mouse_enabled(this->nmeHandle,inVal);
	HX_STACK_LINE(49)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetMouseEnabled,return )

bool InteractiveObject_obj::nmeGetMouseEnabled( ){
	HX_STACK_PUSH("InteractiveObject::nmeGetMouseEnabled","neash/display/InteractiveObject.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_LINE(44)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetMouseEnabled,return )

bool InteractiveObject_obj::requestSoftKeyboard( ){
	HX_STACK_PUSH("InteractiveObject::requestSoftKeyboard","neash/display/InteractiveObject.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(34)
	return ::neash::display::InteractiveObject_obj::nme_display_object_request_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,requestSoftKeyboard,return )

::neash::display::InteractiveObject InteractiveObject_obj::nmeAsInteractiveObject( ){
	HX_STACK_PUSH("InteractiveObject::nmeAsInteractiveObject","neash/display/InteractiveObject.hx",28);
	HX_STACK_THIS(this);
	HX_STACK_LINE(28)
	return hx::ObjectPtr<OBJ_>(this);
}


Dynamic InteractiveObject_obj::nme_display_object_set_mouse_enabled;

Dynamic InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard;

Dynamic InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard;

Dynamic InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard;

Dynamic InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard;

Dynamic InteractiveObject_obj::nme_display_object_request_soft_keyboard;


InteractiveObject_obj::InteractiveObject_obj()
{
}

void InteractiveObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InteractiveObject);
	HX_MARK_MEMBER_NAME(nmeMouseEnabled,"nmeMouseEnabled");
	HX_MARK_MEMBER_NAME(needsSoftKeyboard,"needsSoftKeyboard");
	HX_MARK_MEMBER_NAME(moveForSoftKeyboard,"moveForSoftKeyboard");
	HX_MARK_MEMBER_NAME(mouseEnabled,"mouseEnabled");
	HX_MARK_MEMBER_NAME(doubleClickEnabled,"doubleClickEnabled");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InteractiveObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(nmeMouseEnabled,"nmeMouseEnabled");
	HX_VISIT_MEMBER_NAME(needsSoftKeyboard,"needsSoftKeyboard");
	HX_VISIT_MEMBER_NAME(moveForSoftKeyboard,"moveForSoftKeyboard");
	HX_VISIT_MEMBER_NAME(mouseEnabled,"mouseEnabled");
	HX_VISIT_MEMBER_NAME(doubleClickEnabled,"doubleClickEnabled");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InteractiveObject_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return inCallProp ? nmeGetMouseEnabled() : mouseEnabled; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { return nmeMouseEnabled; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { return inCallProp ? nmeGetNeedsSoftKeyboard() : needsSoftKeyboard; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"nmeSetMouseEnabled") ) { return nmeSetMouseEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMouseEnabled") ) { return nmeGetMouseEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { return doubleClickEnabled; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"requestSoftKeyboard") ) { return requestSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { return inCallProp ? nmeGetMoveForSoftKeyboard() : moveForSoftKeyboard; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeAsInteractiveObject") ) { return nmeAsInteractiveObject_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nmeGetNeedsSoftKeyboard") ) { return nmeGetNeedsSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetNeedsSoftKeyboard") ) { return nmeSetNeedsSoftKeyboard_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nmeGetMoveForSoftKeyboard") ) { return nmeGetMoveForSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMoveForSoftKeyboard") ) { return nmeSetMoveForSoftKeyboard_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mouse_enabled") ) { return nme_display_object_set_mouse_enabled; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nme_display_object_request_soft_keyboard") ) { return nme_display_object_request_soft_keyboard; }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_needs_soft_keyboard") ) { return nme_display_object_set_needs_soft_keyboard; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_needs_soft_keyboard") ) { return nme_display_object_get_needs_soft_keyboard; }
		break;
	case 46:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_moves_for_soft_keyboard") ) { return nme_display_object_set_moves_for_soft_keyboard; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_moves_for_soft_keyboard") ) { return nme_display_object_get_moves_for_soft_keyboard; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InteractiveObject_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { if (inCallProp) return nmeSetMouseEnabled(inValue);mouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { nmeMouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { if (inCallProp) return nmeSetNeedsSoftKeyboard(inValue);needsSoftKeyboard=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { doubleClickEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { if (inCallProp) return nmeSetMoveForSoftKeyboard(inValue);moveForSoftKeyboard=inValue.Cast< bool >(); return inValue; }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_mouse_enabled") ) { nme_display_object_set_mouse_enabled=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"nme_display_object_request_soft_keyboard") ) { nme_display_object_request_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_needs_soft_keyboard") ) { nme_display_object_set_needs_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_needs_soft_keyboard") ) { nme_display_object_get_needs_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 46:
		if (HX_FIELD_EQ(inName,"nme_display_object_set_moves_for_soft_keyboard") ) { nme_display_object_set_moves_for_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_display_object_get_moves_for_soft_keyboard") ) { nme_display_object_get_moves_for_soft_keyboard=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InteractiveObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("nmeMouseEnabled"));
	outFields->push(HX_CSTRING("needsSoftKeyboard"));
	outFields->push(HX_CSTRING("moveForSoftKeyboard"));
	outFields->push(HX_CSTRING("mouseEnabled"));
	outFields->push(HX_CSTRING("doubleClickEnabled"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("nme_display_object_set_mouse_enabled"),
	HX_CSTRING("nme_display_object_set_needs_soft_keyboard"),
	HX_CSTRING("nme_display_object_get_needs_soft_keyboard"),
	HX_CSTRING("nme_display_object_set_moves_for_soft_keyboard"),
	HX_CSTRING("nme_display_object_get_moves_for_soft_keyboard"),
	HX_CSTRING("nme_display_object_request_soft_keyboard"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("nmeGetNeedsSoftKeyboard"),
	HX_CSTRING("nmeSetNeedsSoftKeyboard"),
	HX_CSTRING("nmeGetMoveForSoftKeyboard"),
	HX_CSTRING("nmeSetMoveForSoftKeyboard"),
	HX_CSTRING("nmeSetMouseEnabled"),
	HX_CSTRING("nmeGetMouseEnabled"),
	HX_CSTRING("requestSoftKeyboard"),
	HX_CSTRING("nmeAsInteractiveObject"),
	HX_CSTRING("nmeMouseEnabled"),
	HX_CSTRING("needsSoftKeyboard"),
	HX_CSTRING("moveForSoftKeyboard"),
	HX_CSTRING("mouseEnabled"),
	HX_CSTRING("doubleClickEnabled"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_mouse_enabled,"nme_display_object_set_mouse_enabled");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard,"nme_display_object_set_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard,"nme_display_object_get_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard,"nme_display_object_set_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard,"nme_display_object_get_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_request_soft_keyboard,"nme_display_object_request_soft_keyboard");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_mouse_enabled,"nme_display_object_set_mouse_enabled");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard,"nme_display_object_set_needs_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard,"nme_display_object_get_needs_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard,"nme_display_object_set_moves_for_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard,"nme_display_object_get_moves_for_soft_keyboard");
	HX_VISIT_MEMBER_NAME(InteractiveObject_obj::nme_display_object_request_soft_keyboard,"nme_display_object_request_soft_keyboard");
};

Class InteractiveObject_obj::__mClass;

void InteractiveObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("neash.display.InteractiveObject"), hx::TCanCast< InteractiveObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InteractiveObject_obj::__boot()
{
	nme_display_object_set_mouse_enabled= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_mouse_enabled"),(int)2);
	nme_display_object_set_needs_soft_keyboard= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_needs_soft_keyboard"),(int)2);
	nme_display_object_get_needs_soft_keyboard= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_needs_soft_keyboard"),(int)1);
	nme_display_object_set_moves_for_soft_keyboard= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_set_moves_for_soft_keyboard"),(int)2);
	nme_display_object_get_moves_for_soft_keyboard= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_get_moves_for_soft_keyboard"),(int)1);
	nme_display_object_request_soft_keyboard= ::neash::Loader_obj::load(HX_CSTRING("nme_display_object_request_soft_keyboard"),(int)1);
}

} // end namespace neash
} // end namespace display
