#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_stacking_StackingContext
#include <cocktail/core/stacking/StackingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_FastNode
#include <cocktail/core/utils/FastNode.h>
#endif
#ifndef INCLUDED_cocktail_port_base_KeyboardListenerBase
#include <cocktail/port/base/KeyboardListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_MouseListenerBase
#include <cocktail/port/base/MouseListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_PlatformBase
#include <cocktail/port/base/PlatformBase.h>
#endif
#ifndef INCLUDED_cocktail_port_base_TouchListenerBase
#include <cocktail/port/base/TouchListenerBase.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Keyboard
#include <cocktail/port/platform/flash_player/Keyboard.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Mouse
#include <cocktail/port/platform/flash_player/Mouse.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_Platform
#include <cocktail/port/platform/flash_player/Platform.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_TouchListener
#include <cocktail/port/platform/flash_player/TouchListener.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
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
namespace cocktail{
namespace port{
namespace base{

Void PlatformBase_obj::__construct()
{
HX_STACK_PUSH("PlatformBase::new","cocktail/port/base/PlatformBase.hx",93);
{
	HX_STACK_LINE(95)
	this->setNativeListeners();
	HX_STACK_LINE(97)
	this->mouse = ::cocktail::port::platform::flash_player::Mouse_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(98)
	this->keyboard = ::cocktail::port::platform::flash_player::Keyboard_obj::__new(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(99)
	this->touchListener = ::cocktail::port::platform::flash_player::TouchListener_obj::__new(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

PlatformBase_obj::~PlatformBase_obj() { }

Dynamic PlatformBase_obj::__CreateEmpty() { return  new PlatformBase_obj; }
hx::ObjectPtr< PlatformBase_obj > PlatformBase_obj::__new()
{  hx::ObjectPtr< PlatformBase_obj > result = new PlatformBase_obj();
	result->__construct();
	return result;}

Dynamic PlatformBase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlatformBase_obj > result = new PlatformBase_obj();
	result->__construct();
	return result;}

int PlatformBase_obj::get_innerWidth( ){
	HX_STACK_PUSH("PlatformBase::get_innerWidth","cocktail/port/base/PlatformBase.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_LINE(269)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,get_innerWidth,return )

int PlatformBase_obj::get_innerHeight( ){
	HX_STACK_PUSH("PlatformBase::get_innerHeight","cocktail/port/base/PlatformBase.hx",264);
	HX_STACK_THIS(this);
	HX_STACK_LINE(264)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,get_innerHeight,return )

::cocktail::core::event::Event PlatformBase_obj::getEvent( Dynamic event){
	HX_STACK_PUSH("PlatformBase::getEvent","cocktail/port/base/PlatformBase.hx",255);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(255)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,getEvent,return )

::cocktail::core::event::UIEvent PlatformBase_obj::getUIEvent( Dynamic event){
	HX_STACK_PUSH("PlatformBase::getUIEvent","cocktail/port/base/PlatformBase.hx",244);
	HX_STACK_THIS(this);
	HX_STACK_ARG(event,"event");
	HX_STACK_LINE(244)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,getUIEvent,return )

Void PlatformBase_obj::removeNativeListeners( ){
{
		HX_STACK_PUSH("PlatformBase::removeNativeListeners","cocktail/port/base/PlatformBase.hx",233);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,removeNativeListeners,(void))

Void PlatformBase_obj::setNativeListeners( ){
{
		HX_STACK_PUSH("PlatformBase::setNativeListeners","cocktail/port/base/PlatformBase.hx",225);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,setNativeListeners,(void))

Void PlatformBase_obj::onNativeOrientationChange( Dynamic event){
{
		HX_STACK_PUSH("PlatformBase::onNativeOrientationChange","cocktail/port/base/PlatformBase.hx",210);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(210)
		if (((this->onOrientationChange_dyn() != null()))){
			HX_STACK_LINE(212)
			this->onOrientationChange(this->getEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,onNativeOrientationChange,(void))

Void PlatformBase_obj::onNativeFullScreenChange( Dynamic event){
{
		HX_STACK_PUSH("PlatformBase::onNativeFullScreenChange","cocktail/port/base/PlatformBase.hx",195);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(195)
		if (((this->onFullScreenChange_dyn() != null()))){
			HX_STACK_LINE(197)
			this->onFullScreenChange(this->getEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,onNativeFullScreenChange,(void))

Void PlatformBase_obj::onNativeResize( Dynamic event){
{
		HX_STACK_PUSH("PlatformBase::onNativeResize","cocktail/port/base/PlatformBase.hx",180);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(180)
		if (((this->onResize_dyn() != null()))){
			HX_STACK_LINE(182)
			this->onResize(this->getUIEvent(event));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,onNativeResize,(void))

Void PlatformBase_obj::updateHitTestingBounds( ::cocktail::core::stacking::StackingContext stackingContext){
{
		HX_STACK_PUSH("PlatformBase::updateHitTestingBounds","cocktail/port/base/PlatformBase.hx",163);
		HX_STACK_THIS(this);
		HX_STACK_ARG(stackingContext,"stackingContext");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlatformBase_obj,updateHitTestingBounds,(void))

::neash::display::DisplayObjectContainer PlatformBase_obj::getInitialNativeLayer( ){
	HX_STACK_PUSH("PlatformBase::getInitialNativeLayer","cocktail/port/base/PlatformBase.hx",152);
	HX_STACK_THIS(this);
	HX_STACK_LINE(152)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,getInitialNativeLayer,return )

bool PlatformBase_obj::fullscreen( ){
	HX_STACK_PUSH("PlatformBase::fullscreen","cocktail/port/base/PlatformBase.hx",143);
	HX_STACK_THIS(this);
	HX_STACK_LINE(143)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,fullscreen,return )

bool PlatformBase_obj::fullScreenEnabled( ){
	HX_STACK_PUSH("PlatformBase::fullScreenEnabled","cocktail/port/base/PlatformBase.hx",135);
	HX_STACK_THIS(this);
	HX_STACK_LINE(135)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,fullScreenEnabled,return )

Void PlatformBase_obj::exitFullscreen( ){
{
		HX_STACK_PUSH("PlatformBase::exitFullscreen","cocktail/port/base/PlatformBase.hx",126);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,exitFullscreen,(void))

Void PlatformBase_obj::enterFullscreen( ){
{
		HX_STACK_PUSH("PlatformBase::enterFullscreen","cocktail/port/base/PlatformBase.hx",118);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlatformBase_obj,enterFullscreen,(void))

Void PlatformBase_obj::open( ::String url,::String name){
{
		HX_STACK_PUSH("PlatformBase::open","cocktail/port/base/PlatformBase.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(url,"url");
		HX_STACK_ARG(name,"name");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlatformBase_obj,open,(void))


PlatformBase_obj::PlatformBase_obj()
{
}

void PlatformBase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlatformBase);
	HX_MARK_MEMBER_NAME(innerWidth,"innerWidth");
	HX_MARK_MEMBER_NAME(innerHeight,"innerHeight");
	HX_MARK_MEMBER_NAME(onFullScreenChange,"onFullScreenChange");
	HX_MARK_MEMBER_NAME(onOrientationChange,"onOrientationChange");
	HX_MARK_MEMBER_NAME(onResize,"onResize");
	HX_MARK_MEMBER_NAME(touchListener,"touchListener");
	HX_MARK_MEMBER_NAME(mouse,"mouse");
	HX_MARK_MEMBER_NAME(keyboard,"keyboard");
	HX_MARK_END_CLASS();
}

void PlatformBase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(innerWidth,"innerWidth");
	HX_VISIT_MEMBER_NAME(innerHeight,"innerHeight");
	HX_VISIT_MEMBER_NAME(onFullScreenChange,"onFullScreenChange");
	HX_VISIT_MEMBER_NAME(onOrientationChange,"onOrientationChange");
	HX_VISIT_MEMBER_NAME(onResize,"onResize");
	HX_VISIT_MEMBER_NAME(touchListener,"touchListener");
	HX_VISIT_MEMBER_NAME(mouse,"mouse");
	HX_VISIT_MEMBER_NAME(keyboard,"keyboard");
}

Dynamic PlatformBase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mouse") ) { return mouse; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getEvent") ) { return getEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize; }
		if (HX_FIELD_EQ(inName,"keyboard") ) { return keyboard; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getUIEvent") ) { return getUIEvent_dyn(); }
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return fullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"innerWidth") ) { return inCallProp ? get_innerWidth() : innerWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { return inCallProp ? get_innerHeight() : innerHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"touchListener") ) { return touchListener; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_innerWidth") ) { return get_innerWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeResize") ) { return onNativeResize_dyn(); }
		if (HX_FIELD_EQ(inName,"exitFullscreen") ) { return exitFullscreen_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"enterFullscreen") ) { return enterFullscreen_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"fullScreenEnabled") ) { return fullScreenEnabled_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"setNativeListeners") ) { return setNativeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"onFullScreenChange") ) { return onFullScreenChange; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onOrientationChange") ) { return onOrientationChange; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"removeNativeListeners") ) { return removeNativeListeners_dyn(); }
		if (HX_FIELD_EQ(inName,"getInitialNativeLayer") ) { return getInitialNativeLayer_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"updateHitTestingBounds") ) { return updateHitTestingBounds_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"onNativeFullScreenChange") ) { return onNativeFullScreenChange_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"onNativeOrientationChange") ) { return onNativeOrientationChange_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlatformBase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mouse") ) { mouse=inValue.Cast< ::cocktail::port::platform::flash_player::Mouse >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { onResize=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"keyboard") ) { keyboard=inValue.Cast< ::cocktail::port::platform::flash_player::Keyboard >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"innerWidth") ) { innerWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { innerHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"touchListener") ) { touchListener=inValue.Cast< ::cocktail::port::platform::flash_player::TouchListener >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"onFullScreenChange") ) { onFullScreenChange=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"onOrientationChange") ) { onOrientationChange=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlatformBase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("innerWidth"));
	outFields->push(HX_CSTRING("innerHeight"));
	outFields->push(HX_CSTRING("touchListener"));
	outFields->push(HX_CSTRING("mouse"));
	outFields->push(HX_CSTRING("keyboard"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_innerWidth"),
	HX_CSTRING("get_innerHeight"),
	HX_CSTRING("getEvent"),
	HX_CSTRING("getUIEvent"),
	HX_CSTRING("removeNativeListeners"),
	HX_CSTRING("setNativeListeners"),
	HX_CSTRING("onNativeOrientationChange"),
	HX_CSTRING("onNativeFullScreenChange"),
	HX_CSTRING("onNativeResize"),
	HX_CSTRING("updateHitTestingBounds"),
	HX_CSTRING("getInitialNativeLayer"),
	HX_CSTRING("fullscreen"),
	HX_CSTRING("fullScreenEnabled"),
	HX_CSTRING("exitFullscreen"),
	HX_CSTRING("enterFullscreen"),
	HX_CSTRING("open"),
	HX_CSTRING("innerWidth"),
	HX_CSTRING("innerHeight"),
	HX_CSTRING("onFullScreenChange"),
	HX_CSTRING("onOrientationChange"),
	HX_CSTRING("onResize"),
	HX_CSTRING("touchListener"),
	HX_CSTRING("mouse"),
	HX_CSTRING("keyboard"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlatformBase_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlatformBase_obj::__mClass,"__mClass");
};

Class PlatformBase_obj::__mClass;

void PlatformBase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.base.PlatformBase"), hx::TCanCast< PlatformBase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PlatformBase_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace base
