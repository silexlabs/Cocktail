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
#ifndef INCLUDED_cocktail_core_style_positioner_BoxPositioner
#include <cocktail/core/style/positioner/BoxPositioner.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_RelativePositioner
#include <cocktail/core/style/positioner/RelativePositioner.h>
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
namespace positioner{

Void RelativePositioner_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/RelativePositioner.hx",33)
	super::__construct();
}
;
	return null();
}

RelativePositioner_obj::~RelativePositioner_obj() { }

Dynamic RelativePositioner_obj::__CreateEmpty() { return  new RelativePositioner_obj; }
hx::ObjectPtr< RelativePositioner_obj > RelativePositioner_obj::__new()
{  hx::ObjectPtr< RelativePositioner_obj > result = new RelativePositioner_obj();
	result->__construct();
	return result;}

Dynamic RelativePositioner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RelativePositioner_obj > result = new RelativePositioner_obj();
	result->__construct();
	return result;}

int RelativePositioner_obj::getLeftOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int staticPosition){
	HX_SOURCE_PUSH("RelativePositioner_obj::getLeftOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/RelativePositioner.hx",42)
	return (staticPosition + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("left")));
}


HX_DEFINE_DYNAMIC_FUNC2(RelativePositioner_obj,getLeftOffset,return )

int RelativePositioner_obj::getRightOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int containingHTMLElementWidth,int staticPosition){
	HX_SOURCE_PUSH("RelativePositioner_obj::getRightOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/RelativePositioner.hx",47)
	return (staticPosition - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("right")));
}


HX_DEFINE_DYNAMIC_FUNC3(RelativePositioner_obj,getRightOffset,return )

int RelativePositioner_obj::getTopOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int staticPosition){
	HX_SOURCE_PUSH("RelativePositioner_obj::getTopOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/RelativePositioner.hx",52)
	return (staticPosition + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("top")));
}


HX_DEFINE_DYNAMIC_FUNC2(RelativePositioner_obj,getTopOffset,return )

int RelativePositioner_obj::getBottomOffset( ::cocktail::port::flash_player::HTMLElement htmlElement,int containingHTMLElementHeight,int staticPosition){
	HX_SOURCE_PUSH("RelativePositioner_obj::getBottomOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/RelativePositioner.hx",57)
	return (staticPosition - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("bottom")));
}


HX_DEFINE_DYNAMIC_FUNC3(RelativePositioner_obj,getBottomOffset,return )


RelativePositioner_obj::RelativePositioner_obj()
{
}

void RelativePositioner_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RelativePositioner);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic RelativePositioner_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"getTopOffset") ) { return getTopOffset_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getLeftOffset") ) { return getLeftOffset_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getRightOffset") ) { return getRightOffset_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getBottomOffset") ) { return getBottomOffset_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic RelativePositioner_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void RelativePositioner_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getLeftOffset"),
	HX_CSTRING("getRightOffset"),
	HX_CSTRING("getTopOffset"),
	HX_CSTRING("getBottomOffset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class RelativePositioner_obj::__mClass;

void RelativePositioner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.positioner.RelativePositioner"), hx::TCanCast< RelativePositioner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void RelativePositioner_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace positioner
