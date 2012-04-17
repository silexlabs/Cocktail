#include <hxcpp.h>

#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace display{

Void InteractiveObject_obj::__construct(Dynamic inHandle,::String inType)
{
{
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",21)
	this->doubleClickEnabled = false;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",22)
	this->nmeMouseEnabled = true;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",24)
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

::nme::display::InteractiveObject InteractiveObject_obj::nmeAsInteractiveObject( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeAsInteractiveObject")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",29)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeAsInteractiveObject,return )

bool InteractiveObject_obj::requestSoftKeyboard( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::requestSoftKeyboard")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",35)
	return ::nme::display::InteractiveObject_obj::nme_display_object_request_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,requestSoftKeyboard,return )

bool InteractiveObject_obj::nmeGetMouseEnabled( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeGetMouseEnabled")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",45)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetMouseEnabled,return )

bool InteractiveObject_obj::nmeSetMouseEnabled( bool inVal){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeSetMouseEnabled")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",48)
	this->nmeMouseEnabled = inVal;
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",49)
	::nme::display::InteractiveObject_obj::nme_display_object_set_mouse_enabled(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",50)
	return this->nmeMouseEnabled;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetMouseEnabled,return )

bool InteractiveObject_obj::nmeSetMoveForSoftKeyboard( bool inVal){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeSetMoveForSoftKeyboard")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",56)
	::nme::display::InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",57)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetMoveForSoftKeyboard,return )

bool InteractiveObject_obj::nmeGetMoveForSoftKeyboard( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeGetMoveForSoftKeyboard")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",62)
	return ::nme::display::InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetMoveForSoftKeyboard,return )

bool InteractiveObject_obj::nmeSetNeedsSoftKeyboard( bool inVal){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeSetNeedsSoftKeyboard")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",69)
	::nme::display::InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard(this->nmeHandle,inVal);
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",70)
	return inVal;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,nmeSetNeedsSoftKeyboard,return )

bool InteractiveObject_obj::nmeGetNeedsSoftKeyboard( ){
	HX_SOURCE_PUSH("InteractiveObject_obj::nmeGetNeedsSoftKeyboard")
	HX_SOURCE_POS("C:\\Motion-Twin\\haxe\\lib\\nme/3,3,0/nme/display/InteractiveObject.hx",75)
	return ::nme::display::InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard(this->nmeHandle);
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,nmeGetNeedsSoftKeyboard,return )

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
	HX_MARK_MEMBER_NAME(doubleClickEnabled,"doubleClickEnabled");
	HX_MARK_MEMBER_NAME(mouseEnabled,"mouseEnabled");
	HX_MARK_MEMBER_NAME(moveForSoftKeyboard,"moveForSoftKeyboard");
	HX_MARK_MEMBER_NAME(needsSoftKeyboard,"needsSoftKeyboard");
	HX_MARK_MEMBER_NAME(nmeMouseEnabled,"nmeMouseEnabled");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InteractiveObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return nmeGetMouseEnabled(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { return nmeMouseEnabled; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { return nmeGetNeedsSoftKeyboard(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { return doubleClickEnabled; }
		if (HX_FIELD_EQ(inName,"nmeGetMouseEnabled") ) { return nmeGetMouseEnabled_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeSetMouseEnabled") ) { return nmeSetMouseEnabled_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { return nmeGetMoveForSoftKeyboard(); }
		if (HX_FIELD_EQ(inName,"requestSoftKeyboard") ) { return requestSoftKeyboard_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"nmeAsInteractiveObject") ) { return nmeAsInteractiveObject_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"nmeSetNeedsSoftKeyboard") ) { return nmeSetNeedsSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetNeedsSoftKeyboard") ) { return nmeGetNeedsSoftKeyboard_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"nmeSetMoveForSoftKeyboard") ) { return nmeSetMoveForSoftKeyboard_dyn(); }
		if (HX_FIELD_EQ(inName,"nmeGetMoveForSoftKeyboard") ) { return nmeGetMoveForSoftKeyboard_dyn(); }
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
	return super::__Field(inName);
}

Dynamic InteractiveObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"mouseEnabled") ) { return nmeSetMouseEnabled(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"nmeMouseEnabled") ) { nmeMouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"needsSoftKeyboard") ) { return nmeSetNeedsSoftKeyboard(inValue); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"doubleClickEnabled") ) { doubleClickEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"moveForSoftKeyboard") ) { return nmeSetMoveForSoftKeyboard(inValue); }
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
	return super::__SetField(inName,inValue);
}

void InteractiveObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("doubleClickEnabled"));
	outFields->push(HX_CSTRING("mouseEnabled"));
	outFields->push(HX_CSTRING("moveForSoftKeyboard"));
	outFields->push(HX_CSTRING("needsSoftKeyboard"));
	outFields->push(HX_CSTRING("nmeMouseEnabled"));
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
	HX_CSTRING("doubleClickEnabled"),
	HX_CSTRING("mouseEnabled"),
	HX_CSTRING("moveForSoftKeyboard"),
	HX_CSTRING("needsSoftKeyboard"),
	HX_CSTRING("nmeMouseEnabled"),
	HX_CSTRING("nmeAsInteractiveObject"),
	HX_CSTRING("requestSoftKeyboard"),
	HX_CSTRING("nmeGetMouseEnabled"),
	HX_CSTRING("nmeSetMouseEnabled"),
	HX_CSTRING("nmeSetMoveForSoftKeyboard"),
	HX_CSTRING("nmeGetMoveForSoftKeyboard"),
	HX_CSTRING("nmeSetNeedsSoftKeyboard"),
	HX_CSTRING("nmeGetNeedsSoftKeyboard"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_mouse_enabled,"nme_display_object_set_mouse_enabled");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_needs_soft_keyboard,"nme_display_object_set_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_needs_soft_keyboard,"nme_display_object_get_needs_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_set_moves_for_soft_keyboard,"nme_display_object_set_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_get_moves_for_soft_keyboard,"nme_display_object_get_moves_for_soft_keyboard");
	HX_MARK_MEMBER_NAME(InteractiveObject_obj::nme_display_object_request_soft_keyboard,"nme_display_object_request_soft_keyboard");
};

Class InteractiveObject_obj::__mClass;

void InteractiveObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("nme.display.InteractiveObject"), hx::TCanCast< InteractiveObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InteractiveObject_obj::__boot()
{
	hx::Static(nme_display_object_set_mouse_enabled) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_set_mouse_enabled"),(int)2);
	hx::Static(nme_display_object_set_needs_soft_keyboard) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_set_needs_soft_keyboard"),(int)2);
	hx::Static(nme_display_object_get_needs_soft_keyboard) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_get_needs_soft_keyboard"),(int)1);
	hx::Static(nme_display_object_set_moves_for_soft_keyboard) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_set_moves_for_soft_keyboard"),(int)2);
	hx::Static(nme_display_object_get_moves_for_soft_keyboard) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_get_moves_for_soft_keyboard"),(int)1);
	hx::Static(nme_display_object_request_soft_keyboard) = ::nme::Loader_obj::load(HX_CSTRING("nme_display_object_request_soft_keyboard"),(int)1);
}

} // end namespace nme
} // end namespace display
