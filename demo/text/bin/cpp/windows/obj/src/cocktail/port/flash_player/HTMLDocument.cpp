#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Document
#include <cocktail/core/dom/Document.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLDocument
#include <cocktail/core/html/AbstractHTMLDocument.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLDocument
#include <cocktail/port/flash_player/HTMLDocument.h>
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

Void HTMLDocument_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLDocument.hx",25)
	super::__construct();
}
;
	return null();
}

HTMLDocument_obj::~HTMLDocument_obj() { }

Dynamic HTMLDocument_obj::__CreateEmpty() { return  new HTMLDocument_obj; }
hx::ObjectPtr< HTMLDocument_obj > HTMLDocument_obj::__new()
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct();
	return result;}

Dynamic HTMLDocument_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLDocument_obj > result = new HTMLDocument_obj();
	result->__construct();
	return result;}

Void HTMLDocument_obj::attachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("HTMLDocument_obj::attachNativeElement")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLDocument.hx",35)
		::nme::Lib_obj::nmeGetCurrent()->addChild(nativeElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,attachNativeElement,(void))

Void HTMLDocument_obj::detachNativeElement( Dynamic nativeElement){
{
		HX_SOURCE_PUSH("HTMLDocument_obj::detachNativeElement")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLDocument.hx",40)
		::nme::Lib_obj::nmeGetCurrent()->removeChild(nativeElement);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HTMLDocument_obj,detachNativeElement,(void))


HTMLDocument_obj::HTMLDocument_obj()
{
}

void HTMLDocument_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLDocument);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLDocument_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 19:
		if (HX_FIELD_EQ(inName,"attachNativeElement") ) { return attachNativeElement_dyn(); }
		if (HX_FIELD_EQ(inName,"detachNativeElement") ) { return detachNativeElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic HTMLDocument_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void HTMLDocument_obj::__GetFields(Array< ::String> &outFields)
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

Class HTMLDocument_obj::__mClass;

void HTMLDocument_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.HTMLDocument"), hx::TCanCast< HTMLDocument_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLDocument_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
