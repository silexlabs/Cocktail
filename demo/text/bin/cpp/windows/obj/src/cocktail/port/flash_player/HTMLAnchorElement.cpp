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
#ifndef INCLUDED_cocktail_core_html_AbstractHTMLAnchorElement
#include <cocktail/core/html/AbstractHTMLAnchorElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLAnchorElement
#include <cocktail/port/flash_player/HTMLAnchorElement.h>
#endif
#ifndef INCLUDED_nme_Lib
#include <nme/Lib.h>
#endif
#ifndef INCLUDED_nme_net_URLRequest
#include <nme/net/URLRequest.h>
#endif
namespace cocktail{
namespace port{
namespace flash_player{

Void HTMLAnchorElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLAnchorElement.hx",25)
	super::__construct();
}
;
	return null();
}

HTMLAnchorElement_obj::~HTMLAnchorElement_obj() { }

Dynamic HTMLAnchorElement_obj::__CreateEmpty() { return  new HTMLAnchorElement_obj; }
hx::ObjectPtr< HTMLAnchorElement_obj > HTMLAnchorElement_obj::__new()
{  hx::ObjectPtr< HTMLAnchorElement_obj > result = new HTMLAnchorElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLAnchorElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLAnchorElement_obj > result = new HTMLAnchorElement_obj();
	result->__construct();
	return result;}

Void HTMLAnchorElement_obj::openDocument( ){
{
		HX_SOURCE_PUSH("HTMLAnchorElement_obj::openDocument")
		HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLAnchorElement.hx",35)
		if (((this->_href != null()))){
			HX_SOURCE_POS("../../src/cocktail/port/flash_player/HTMLAnchorElement.hx",37)
			::nme::Lib_obj::getURL(::nme::net::URLRequest_obj::__new(this->_href),this->_target);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLAnchorElement_obj,openDocument,(void))


HTMLAnchorElement_obj::HTMLAnchorElement_obj()
{
}

void HTMLAnchorElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLAnchorElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLAnchorElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"openDocument") ) { return openDocument_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic HTMLAnchorElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void HTMLAnchorElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("openDocument"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class HTMLAnchorElement_obj::__mClass;

void HTMLAnchorElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.port.flash_player.HTMLAnchorElement"), hx::TCanCast< HTMLAnchorElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLAnchorElement_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace port
} // end namespace flash_player
