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
#ifndef INCLUDED_core_style_AbstractEmbeddedStyle
#include <core/style/AbstractEmbeddedStyle.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
#ifndef INCLUDED_port_flash_player_Style
#include <port/flash_player/Style.h>
#endif
namespace core{
namespace style{

Void AbstractEmbeddedStyle_obj::__construct(::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/core/style/AbstractEmbeddedStyle.hx",38)
	super::__construct(htmlElement);
}
;
	return null();
}

AbstractEmbeddedStyle_obj::~AbstractEmbeddedStyle_obj() { }

Dynamic AbstractEmbeddedStyle_obj::__CreateEmpty() { return  new AbstractEmbeddedStyle_obj; }
hx::ObjectPtr< AbstractEmbeddedStyle_obj > AbstractEmbeddedStyle_obj::__new(::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractEmbeddedStyle_obj > result = new AbstractEmbeddedStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractEmbeddedStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractEmbeddedStyle_obj > result = new AbstractEmbeddedStyle_obj();
	result->__construct(inArgs[0]);
	return result;}


AbstractEmbeddedStyle_obj::AbstractEmbeddedStyle_obj()
{
}

void AbstractEmbeddedStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractEmbeddedStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractEmbeddedStyle_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic AbstractEmbeddedStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractEmbeddedStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractEmbeddedStyle_obj::__mClass;

void AbstractEmbeddedStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.AbstractEmbeddedStyle"), hx::TCanCast< AbstractEmbeddedStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractEmbeddedStyle_obj::__boot()
{
}

} // end namespace core
} // end namespace style
