#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_window_AbstractWindow
#include <cocktail/core/window/AbstractWindow.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_Window
#include <cocktail/port/flash_player/Window.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObject
#include <nme/display/DisplayObject.h>
#endif
#ifndef INCLUDED_nme_display_DisplayObjectContainer
#include <nme/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_display_InteractiveObject
#include <nme/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_nme_display_MovieClip
#include <nme/display/MovieClip.h>
#endif
#ifndef INCLUDED_nme_display_Sprite
#include <nme/display/Sprite.h>
#endif
#ifndef INCLUDED_nme_display_Stage
#include <nme/display/Stage.h>
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
namespace cocktail{
namespace port{
namespace flash_player{

Void Window_obj::__construct(::cocktail::core::dom::Document document)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",27)
	super::__construct(document);
}
;
	return null();
}

Window_obj::~Window_obj() { }

Dynamic Window_obj::__CreateEmpty() { return  new Window_obj; }
hx::ObjectPtr< Window_obj > Window_obj::__new(::cocktail::core::dom::Document document)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(document);
	return result;}

Dynamic Window_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic Window_obj::set_onResize( Dynamic value){
	HX_SOURCE_PUSH("Window_obj::set_onResize")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",41)
	if (((value == null()))){
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",42)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->removeEventListener(::nme::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null());
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",46)
		::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->addEventListener(::nme::events::Event_obj::RESIZE,this->onNativeResize_dyn(),null(),null(),null());
	}
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",50)
	return this->_onResize = value;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,set_onResize,return )

int Window_obj::get_innerHeight( ){
	HX_SOURCE_PUSH("Window_obj::get_innerHeight")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",57)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeGetStageHeight();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,get_innerHeight,return )

int Window_obj::get_innerWidth( ){
	HX_SOURCE_PUSH("Window_obj::get_innerWidth")
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",65)
	return ::nme::Lib_obj::nmeGetCurrent()->nmeGetStage()->nmeGetStageWidth();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,get_innerWidth,return )

Void Window_obj::onNativeResize( Dynamic event){
{
		HX_SOURCE_PUSH("Window_obj::onNativeResize")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",77)
		if (((this->_onResize_dyn() != null()))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/Window.hx",79)
			this->_onResize(::cocktail::core::event::Event_obj::__new(HX_CSTRING("resize"),hx::ObjectPtr<OBJ_>(this)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onNativeResize,(void))


Window_obj::Window_obj()
{
}

void Window_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Window);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic Window_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"set_onResize") ) { return set_onResize_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_innerWidth") ) { return get_innerWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"onNativeResize") ) { return onNativeResize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_onResize"),
	HX_CSTRING("get_innerHeight"),
	HX_CSTRING("get_innerWidth"),
	HX_CSTRING("onNativeResize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Window_obj::__mClass;

void Window_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.Window"), hx::TCanCast< Window_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Window_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
