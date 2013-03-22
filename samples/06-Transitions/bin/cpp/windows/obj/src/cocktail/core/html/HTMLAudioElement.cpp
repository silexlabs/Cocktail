#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_EmbeddedElement
#include <cocktail/core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLAudioElement
#include <cocktail/core/html/HTMLAudioElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLMediaElement
#include <cocktail/core/html/HTMLMediaElement.h>
#endif
#ifndef INCLUDED_cocktail_port_base_NativeMedia
#include <cocktail/port/base/NativeMedia.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_flash_player_NativeAudio
#include <cocktail/port/platform/flash_player/NativeAudio.h>
#endif
#ifndef INCLUDED_cocktail_port_platform_nme_NativeAudio
#include <cocktail/port/platform/nme/NativeAudio.h>
#endif
namespace cocktail{
namespace core{
namespace html{

Void HTMLAudioElement_obj::__construct()
{
HX_STACK_PUSH("HTMLAudioElement::new","cocktail/core/html/HTMLAudioElement.hx",23);
{
	HX_STACK_LINE(23)
	super::__construct(HX_CSTRING("AUDIO"));
}
;
	return null();
}

HTMLAudioElement_obj::~HTMLAudioElement_obj() { }

Dynamic HTMLAudioElement_obj::__CreateEmpty() { return  new HTMLAudioElement_obj; }
hx::ObjectPtr< HTMLAudioElement_obj > HTMLAudioElement_obj::__new()
{  hx::ObjectPtr< HTMLAudioElement_obj > result = new HTMLAudioElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLAudioElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLAudioElement_obj > result = new HTMLAudioElement_obj();
	result->__construct();
	return result;}

Void HTMLAudioElement_obj::createElementRenderer( ){
{
		HX_STACK_PUSH("HTMLAudioElement::createElementRenderer","cocktail/core/html/HTMLAudioElement.hx",43);
		HX_STACK_THIS(this);
	}
return null();
}


Void HTMLAudioElement_obj::initNativeMedia( ){
{
		HX_STACK_PUSH("HTMLAudioElement::initNativeMedia","cocktail/core/html/HTMLAudioElement.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(31)
		this->nativeMedia = ::cocktail::port::platform::nme::NativeAudio_obj::__new();
	}
return null();
}



HTMLAudioElement_obj::HTMLAudioElement_obj()
{
}

void HTMLAudioElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLAudioElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTMLAudioElement_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic HTMLAudioElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"initNativeMedia") ) { return initNativeMedia_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"createElementRenderer") ) { return createElementRenderer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTMLAudioElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void HTMLAudioElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("createElementRenderer"),
	HX_CSTRING("initNativeMedia"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLAudioElement_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTMLAudioElement_obj::__mClass,"__mClass");
};

Class HTMLAudioElement_obj::__mClass;

void HTMLAudioElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLAudioElement"), hx::TCanCast< HTMLAudioElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HTMLAudioElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
