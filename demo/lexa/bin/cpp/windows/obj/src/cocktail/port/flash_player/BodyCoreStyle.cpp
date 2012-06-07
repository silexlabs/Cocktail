#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLElement
#include <cocktail/core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractBodyCoreStyle
#include <cocktail/core/style/AbstractBodyCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractContainerCoreStyle
#include <cocktail/core/style/AbstractContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_BodyCoreStyle
#include <cocktail/port/flash_player/BodyCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_ContainerCoreStyle
#include <cocktail/port/flash_player/ContainerCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
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
namespace cocktail{
namespace port{
namespace flash_player{

Void BodyCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/BodyCoreStyle.hx",28)
	super::__construct(htmlElement);
}
;
	return null();
}

BodyCoreStyle_obj::~BodyCoreStyle_obj() { }

Dynamic BodyCoreStyle_obj::__CreateEmpty() { return  new BodyCoreStyle_obj; }
hx::ObjectPtr< BodyCoreStyle_obj > BodyCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< BodyCoreStyle_obj > result = new BodyCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic BodyCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BodyCoreStyle_obj > result = new BodyCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BodyCoreStyle_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("BodyCoreStyle_obj::attachNativeElement")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/BodyCoreStyle.hx",39)
		::nme::Lib_obj::nmeGetCurrent()->addChild(nativeElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BodyCoreStyle_obj,attachNativeElement,(void))

Void BodyCoreStyle_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("BodyCoreStyle_obj::detachNativeElement")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/BodyCoreStyle.hx",44)
		if ((::nme::Lib_obj::nmeGetCurrent()->contains(nativeElement))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/BodyCoreStyle.hx",49)
			::nme::Lib_obj::nmeGetCurrent()->removeChild(nativeElement);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BodyCoreStyle_obj,detachNativeElement,(void))


BodyCoreStyle_obj::BodyCoreStyle_obj()
{
}

void BodyCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BodyCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic BodyCoreStyle_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"attachNativeElement") ) { return attachNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElement") ) { return detachNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BodyCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BodyCoreStyle_obj::__GetFields(Array< ::String> &outFields)
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

Class BodyCoreStyle_obj::__mClass;

void BodyCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.BodyCoreStyle"), hx::TCanCast< BodyCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BodyCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
