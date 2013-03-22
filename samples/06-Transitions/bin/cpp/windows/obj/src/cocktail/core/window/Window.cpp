#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_KeyboardEvent
#include <cocktail/core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_MouseEvent
#include <cocktail/core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_WheelEvent
#include <cocktail/core/event/WheelEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_history_History
#include <cocktail/core/history/History.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLDocument
#include <cocktail/core/html/HTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_core_invalidation_InvalidationManager
#include <cocktail/core/invalidation/InvalidationManager.h>
#endif
#ifndef INCLUDED_cocktail_core_window_Window
#include <cocktail/core/window/Window.h>
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
namespace cocktail{
namespace core{
namespace window{

Void Window_obj::__construct()
{
HX_STACK_PUSH("Window::new","cocktail/core/window/Window.hx",82);
{
	HX_STACK_LINE(83)
	super::__construct();
	HX_STACK_LINE(84)
	this->init();
}
;
	return null();
}

Window_obj::~Window_obj() { }

Dynamic Window_obj::__CreateEmpty() { return  new Window_obj; }
hx::ObjectPtr< Window_obj > Window_obj::__new()
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct();
	return result;}

Dynamic Window_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct();
	return result;}

int Window_obj::get_innerWidth( ){
	HX_STACK_PUSH("Window::get_innerWidth","cocktail/core/window/Window.hx",240);
	HX_STACK_THIS(this);
	HX_STACK_LINE(240)
	return this->platform->get_innerWidth();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,get_innerWidth,return )

int Window_obj::get_innerHeight( ){
	HX_STACK_PUSH("Window::get_innerHeight","cocktail/core/window/Window.hx",235);
	HX_STACK_THIS(this);
	HX_STACK_LINE(235)
	return this->platform->get_innerHeight();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,get_innerHeight,return )

Void Window_obj::onPlatformOrientationChangeEvent( ::cocktail::core::event::Event e){
{
		HX_STACK_PUSH("Window::onPlatformOrientationChangeEvent","cocktail/core/window/Window.hx",226);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(226)
		this->document->invalidationManager->invalidateViewportSize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onPlatformOrientationChangeEvent,(void))

Void Window_obj::onPlatformResizeEvent( ::cocktail::core::event::UIEvent e){
{
		HX_STACK_PUSH("Window::onPlatformResizeEvent","cocktail/core/window/Window.hx",216);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(216)
		this->document->invalidationManager->invalidateViewportSize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onPlatformResizeEvent,(void))

Void Window_obj::onDocumentSetMouseCursor( ::cocktail::core::css::CSSPropertyValue cursor){
{
		HX_STACK_PUSH("Window::onDocumentSetMouseCursor","cocktail/core/window/Window.hx",186);
		HX_STACK_THIS(this);
		HX_STACK_ARG(cursor,"cursor");
		HX_STACK_LINE(186)
		if (((this->_currentMouseCursor == null()))){
			HX_STACK_LINE(190)
			this->_currentMouseCursor = cursor;
			HX_STACK_LINE(191)
			this->platform->mouse->setMouseCursor(cursor);
		}
		else{
			HX_STACK_LINE(194)
			if (((cursor != this->_currentMouseCursor))){
				HX_STACK_LINE(199)
				this->_currentMouseCursor = cursor;
				HX_STACK_LINE(200)
				this->platform->mouse->setMouseCursor(cursor);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onDocumentSetMouseCursor,(void))

Void Window_obj::onDocumentExitFullscreen( ){
{
		HX_STACK_PUSH("Window::onDocumentExitFullscreen","cocktail/core/window/Window.hx",174);
		HX_STACK_THIS(this);
		HX_STACK_LINE(174)
		this->platform->exitFullscreen();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,onDocumentExitFullscreen,(void))

Void Window_obj::onDocumentEnterFullscreen( ){
{
		HX_STACK_PUSH("Window::onDocumentEnterFullscreen","cocktail/core/window/Window.hx",165);
		HX_STACK_THIS(this);
		HX_STACK_LINE(165)
		this->platform->enterFullscreen();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,onDocumentEnterFullscreen,(void))

Void Window_obj::onPlatformFullScreenChange( ::cocktail::core::event::Event event){
{
		HX_STACK_PUSH("Window::onPlatformFullScreenChange","cocktail/core/window/Window.hx",151);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(151)
		if (((this->platform->fullscreen() == false))){
			HX_STACK_LINE(155)
			this->document->exitFullscreen();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,onPlatformFullScreenChange,(void))

Void Window_obj::open( ::String url,::String __o_name){
::String name = __o_name.Default(HX_CSTRING("_blank"));
	HX_STACK_PUSH("Window::open","cocktail/core/window/Window.hx",134);
	HX_STACK_THIS(this);
	HX_STACK_ARG(url,"url");
	HX_STACK_ARG(name,"name");
{
		HX_STACK_LINE(134)
		this->platform->open(url,name);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Window_obj,open,(void))

Void Window_obj::init( ){
{
		HX_STACK_PUSH("Window::init","cocktail/core/window/Window.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_LINE(93)
		this->platform = ::cocktail::port::platform::flash_player::Platform_obj::__new();
		HX_STACK_LINE(94)
		::cocktail::core::html::HTMLDocument htmlDocument = ::cocktail::core::html::HTMLDocument_obj::__new(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(htmlDocument,"htmlDocument");
		HX_STACK_LINE(96)
		this->platform->mouse->onMouseDown = htmlDocument->onPlatformMouseEvent_dyn();
		HX_STACK_LINE(97)
		this->platform->mouse->onMouseUp = htmlDocument->onPlatformMouseEvent_dyn();
		HX_STACK_LINE(98)
		this->platform->mouse->onMouseMove = htmlDocument->onPlatformMouseMoveEvent_dyn();
		HX_STACK_LINE(99)
		this->platform->mouse->onMouseWheel = htmlDocument->onPlatformMouseWheelEvent_dyn();
		HX_STACK_LINE(100)
		this->platform->mouse->onMouseLeave = htmlDocument->onPlatformMouseLeaveEvent_dyn();
		HX_STACK_LINE(102)
		this->platform->keyboard->onKeyDown = htmlDocument->onPlatformKeyDownEvent_dyn();
		HX_STACK_LINE(103)
		this->platform->keyboard->onKeyUp = htmlDocument->onPlatformKeyUpEvent_dyn();
		HX_STACK_LINE(105)
		this->platform->onResize = this->onPlatformResizeEvent_dyn();
		HX_STACK_LINE(106)
		this->platform->onOrientationChange = this->onPlatformOrientationChangeEvent_dyn();
		HX_STACK_LINE(108)
		this->platform->touchListener->onTouchStart = htmlDocument->onPlatformTouchEvent_dyn();
		HX_STACK_LINE(109)
		this->platform->touchListener->onTouchMove = htmlDocument->onPlatformTouchEvent_dyn();
		HX_STACK_LINE(110)
		this->platform->touchListener->onTouchEnd = htmlDocument->onPlatformTouchEvent_dyn();
		HX_STACK_LINE(113)
		htmlDocument->onEnterFullscreen = this->onDocumentEnterFullscreen_dyn();
		HX_STACK_LINE(114)
		htmlDocument->onExitFullscreen = this->onDocumentExitFullscreen_dyn();
		HX_STACK_LINE(115)
		this->platform->onFullScreenChange = this->onPlatformFullScreenChange_dyn();
		HX_STACK_LINE(118)
		htmlDocument->onSetMouseCursor = this->onDocumentSetMouseCursor_dyn();
		HX_STACK_LINE(120)
		this->document = htmlDocument;
		HX_STACK_LINE(123)
		this->history = ::cocktail::core::history::History_obj::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,init,(void))


Window_obj::Window_obj()
{
}

void Window_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Window);
	HX_MARK_MEMBER_NAME(_currentMouseCursor,"_currentMouseCursor");
	HX_MARK_MEMBER_NAME(history,"history");
	HX_MARK_MEMBER_NAME(platform,"platform");
	HX_MARK_MEMBER_NAME(innerWidth,"innerWidth");
	HX_MARK_MEMBER_NAME(innerHeight,"innerHeight");
	HX_MARK_MEMBER_NAME(document,"document");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Window_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_currentMouseCursor,"_currentMouseCursor");
	HX_VISIT_MEMBER_NAME(history,"history");
	HX_VISIT_MEMBER_NAME(platform,"platform");
	HX_VISIT_MEMBER_NAME(innerWidth,"innerWidth");
	HX_VISIT_MEMBER_NAME(innerHeight,"innerHeight");
	HX_VISIT_MEMBER_NAME(document,"document");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"open") ) { return open_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"history") ) { return history; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"platform") ) { return platform; }
		if (HX_FIELD_EQ(inName,"document") ) { return document; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"innerWidth") ) { return inCallProp ? get_innerWidth() : innerWidth; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { return inCallProp ? get_innerHeight() : innerHeight; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_innerWidth") ) { return get_innerWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_innerHeight") ) { return get_innerHeight_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_currentMouseCursor") ) { return _currentMouseCursor; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"onPlatformResizeEvent") ) { return onPlatformResizeEvent_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"onDocumentSetMouseCursor") ) { return onDocumentSetMouseCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"onDocumentExitFullscreen") ) { return onDocumentExitFullscreen_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"onDocumentEnterFullscreen") ) { return onDocumentEnterFullscreen_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"onPlatformFullScreenChange") ) { return onPlatformFullScreenChange_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"onPlatformOrientationChangeEvent") ) { return onPlatformOrientationChangeEvent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"history") ) { history=inValue.Cast< ::cocktail::core::history::History >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"platform") ) { platform=inValue.Cast< ::cocktail::port::platform::flash_player::Platform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"document") ) { document=inValue.Cast< ::cocktail::core::html::HTMLDocument >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"innerWidth") ) { innerWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"innerHeight") ) { innerHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_currentMouseCursor") ) { _currentMouseCursor=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_currentMouseCursor"));
	outFields->push(HX_CSTRING("history"));
	outFields->push(HX_CSTRING("platform"));
	outFields->push(HX_CSTRING("innerWidth"));
	outFields->push(HX_CSTRING("innerHeight"));
	outFields->push(HX_CSTRING("document"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_innerWidth"),
	HX_CSTRING("get_innerHeight"),
	HX_CSTRING("onPlatformOrientationChangeEvent"),
	HX_CSTRING("onPlatformResizeEvent"),
	HX_CSTRING("onDocumentSetMouseCursor"),
	HX_CSTRING("onDocumentExitFullscreen"),
	HX_CSTRING("onDocumentEnterFullscreen"),
	HX_CSTRING("onPlatformFullScreenChange"),
	HX_CSTRING("open"),
	HX_CSTRING("init"),
	HX_CSTRING("_currentMouseCursor"),
	HX_CSTRING("history"),
	HX_CSTRING("platform"),
	HX_CSTRING("innerWidth"),
	HX_CSTRING("innerHeight"),
	HX_CSTRING("document"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Window_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Window_obj::__mClass,"__mClass");
};

Class Window_obj::__mClass;

void Window_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.window.Window"), hx::TCanCast< Window_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Window_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace window
