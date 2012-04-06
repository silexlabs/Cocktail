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
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractEmbeddedCoreStyle
#include <cocktail/core/style/AbstractEmbeddedCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_CoreStyle
#include <cocktail/port/flash_player/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_port_flash_player_HTMLElement
#include <cocktail/port/flash_player/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace style{

Void AbstractEmbeddedCoreStyle_obj::__construct(::cocktail::port::flash_player::HTMLElement htmlElement)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/AbstractEmbeddedCoreStyle.hx",38)
	super::__construct(htmlElement);
}
;
	return null();
}

AbstractEmbeddedCoreStyle_obj::~AbstractEmbeddedCoreStyle_obj() { }

Dynamic AbstractEmbeddedCoreStyle_obj::__CreateEmpty() { return  new AbstractEmbeddedCoreStyle_obj; }
hx::ObjectPtr< AbstractEmbeddedCoreStyle_obj > AbstractEmbeddedCoreStyle_obj::__new(::cocktail::port::flash_player::HTMLElement htmlElement)
{  hx::ObjectPtr< AbstractEmbeddedCoreStyle_obj > result = new AbstractEmbeddedCoreStyle_obj();
	result->__construct(htmlElement);
	return result;}

Dynamic AbstractEmbeddedCoreStyle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractEmbeddedCoreStyle_obj > result = new AbstractEmbeddedCoreStyle_obj();
	result->__construct(inArgs[0]);
	return result;}


AbstractEmbeddedCoreStyle_obj::AbstractEmbeddedCoreStyle_obj()
{
}

void AbstractEmbeddedCoreStyle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractEmbeddedCoreStyle);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic AbstractEmbeddedCoreStyle_obj::__Field(const ::String &inName)
{
	return super::__Field(inName);
}

Dynamic AbstractEmbeddedCoreStyle_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void AbstractEmbeddedCoreStyle_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractEmbeddedCoreStyle_obj::__mClass;

void AbstractEmbeddedCoreStyle_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.AbstractEmbeddedCoreStyle"), hx::TCanCast< AbstractEmbeddedCoreStyle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractEmbeddedCoreStyle_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
