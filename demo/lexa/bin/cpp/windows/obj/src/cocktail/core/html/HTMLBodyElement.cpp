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
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_nativeElement_NativeElementManager
#include <cocktail/core/nativeElement/NativeElementManager.h>
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
namespace cocktail{
namespace core{
namespace html{

Void HTMLBodyElement_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/html/HTMLBodyElement.hx",44)
	super::__construct(HX_CSTRING("body"));
}
;
	return null();
}

HTMLBodyElement_obj::~HTMLBodyElement_obj() { }

Dynamic HTMLBodyElement_obj::__CreateEmpty() { return  new HTMLBodyElement_obj; }
hx::ObjectPtr< HTMLBodyElement_obj > HTMLBodyElement_obj::__new()
{  hx::ObjectPtr< HTMLBodyElement_obj > result = new HTMLBodyElement_obj();
	result->__construct();
	return result;}

Dynamic HTMLBodyElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTMLBodyElement_obj > result = new HTMLBodyElement_obj();
	result->__construct();
	return result;}

Void HTMLBodyElement_obj::initNativeElement( ){
{
		HX_SOURCE_PUSH("HTMLBodyElement_obj::initNativeElement")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLBodyElement.hx",52)
		this->_nativeElement = ::cocktail::core::nativeElement::NativeElementManager_obj::getRoot();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLBodyElement_obj,initNativeElement,(void))

Void HTMLBodyElement_obj::initCoreStyle( ){
{
		HX_SOURCE_PUSH("HTMLBodyElement_obj::initCoreStyle")
		HX_SOURCE_POS("../../src/cocktail/core/html/HTMLBodyElement.hx",61)
		this->_coreStyle = ::cocktail::port::flash_player::BodyCoreStyle_obj::__new(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTMLBodyElement_obj,initCoreStyle,(void))

::String HTMLBodyElement_obj::HTML_BODY_TAG_NAME;


HTMLBodyElement_obj::HTMLBodyElement_obj()
{
}

void HTMLBodyElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTMLBodyElement);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic HTMLBodyElement_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"initCoreStyle") ) { return initCoreStyle_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"initNativeElement") ) { return initNativeElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_BODY_TAG_NAME") ) { return HTML_BODY_TAG_NAME; }
	}
	return super::__Field(inName);
}

Dynamic HTMLBodyElement_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 18:
		if (HX_FIELD_EQ(inName,"HTML_BODY_TAG_NAME") ) { HTML_BODY_TAG_NAME=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void HTMLBodyElement_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("HTML_BODY_TAG_NAME"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("initNativeElement"),
	HX_CSTRING("initCoreStyle"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTMLBodyElement_obj::HTML_BODY_TAG_NAME,"HTML_BODY_TAG_NAME");
};

Class HTMLBodyElement_obj::__mClass;

void HTMLBodyElement_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.html.HTMLBodyElement"), hx::TCanCast< HTMLBodyElement_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void HTMLBodyElement_obj::__boot()
{
	hx::Static(HTML_BODY_TAG_NAME) = HX_CSTRING("body");
}

} // end namespace cocktail
} // end namespace core
} // end namespace html
