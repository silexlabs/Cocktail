#include <hxcpp.h>

#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_style_AbstractBodyStyle
#include <core/style/AbstractBodyStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractContainerStyle
#include <core/style/AbstractContainerStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
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
#ifndef INCLUDED_nme_events_EventDispatcher
#include <nme/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_port_flash_player_BodyStyle
#include <port/flash_player/BodyStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_ContainerStyle
#include <port/flash_player/ContainerStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace port{
namespace flash_player{

Void BodyStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/port/flash_player/BodyStyle.hx",28)
	super::__construct(htmlElement);
}
;
	return null();
}

BodyStyle_obj::~BodyStyle_obj() { }

Dynamic BodyStyle_obj::__CreateEmpty() { return  new BodyStyle_obj; }
hx::ObjectPtr< BodyStyle_obj > BodyStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< BodyStyle_obj > result = new BodyStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic BodyStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BodyStyle_obj > result = new BodyStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BodyStyle_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("BodyStyle_obj::attachNativeElement")
		HX_SOURCE_POS("../../src/port/flash_player/BodyStyle.hx",39)
		::nme::Lib_obj::nmeGetCurrent()->addChild(nativeElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BodyStyle_obj,attachNativeElement,(void))

Void BodyStyle_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("BodyStyle_obj::detachNativeElement")
		HX_SOURCE_POS("../../src/port/flash_player/BodyStyle.hx",44)
		if ((::nme::Lib_obj::nmeGetCurrent()->contains(nativeElement))){
			HX_SOURCE_POS("../../src/port/flash_player/BodyStyle.hx",49)
			::nme::Lib_obj::nmeGetCurrent()->removeChild(nativeElement);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BodyStyle_obj,detachNativeElement,(void))


BodyStyle_obj::BodyStyle_obj()
{
}

void BodyStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BodyStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BodyStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"attachNativeElement") ) { return attachNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElement") ) { return detachNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BodyStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BodyStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("attachNativeElement"),
	HX_CSTRING("detachNativeElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BodyStyle_obj::__mClass;

void BodyStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("port.flash_player.BodyStyle"), hx::TCanCast< BodyStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BodyStyle_obj::__boot()
{
}

} // end namespace port
} // end namespace flash_player
