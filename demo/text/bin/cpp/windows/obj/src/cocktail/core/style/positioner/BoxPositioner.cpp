#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_PositionOffset
#include <cocktail/core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_cocktail_core_style_positioner_BoxPositioner
#include <cocktail/core/style/positioner/BoxPositioner.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace positioner{

Void BoxPositioner_obj::__construct()
{
{
}
;
	return null();
}

BoxPositioner_obj::~BoxPositioner_obj() { }

Dynamic BoxPositioner_obj::__CreateEmpty() { return  new BoxPositioner_obj; }
hx::ObjectPtr< BoxPositioner_obj > BoxPositioner_obj::__new()
{  hx::ObjectPtr< BoxPositioner_obj > result = new BoxPositioner_obj();
	result->__construct();
	return result;}

Dynamic BoxPositioner_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxPositioner_obj > result = new BoxPositioner_obj();
	result->__construct();
	return result;}

::cocktail::core::renderer::ElementRenderer BoxPositioner_obj::position( ::cocktail::core::renderer::ElementRenderer elementRenderer,Dynamic containingHTMLElementData,Dynamic staticPosition){
	HX_SOURCE_PUSH("BoxPositioner_obj::position")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",66)
	::cocktail::core::html::HTMLElement htmlElement = elementRenderer->getCoreStyle()->get_htmlElement();
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",70)
	if (((htmlElement->get_coreStyle()->getLeft() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",71)
		elementRenderer->getBounds()->__FieldRef(HX_CSTRING("x")) = this->getLeftOffset(htmlElement,::Math_obj::round(staticPosition->__Field(HX_CSTRING("x"))));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",77)
		if (((htmlElement->get_coreStyle()->getRight() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",78)
			elementRenderer->getBounds()->__FieldRef(HX_CSTRING("x")) = this->getRightOffset(htmlElement,containingHTMLElementData->__Field(HX_CSTRING("width")),::Math_obj::round(staticPosition->__Field(HX_CSTRING("x"))));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",84)
			elementRenderer->getBounds()->__FieldRef(HX_CSTRING("x")) = ::Math_obj::round(staticPosition->__Field(HX_CSTRING("x")));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",89)
	if (((htmlElement->get_coreStyle()->getTop() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",90)
		elementRenderer->getBounds()->__FieldRef(HX_CSTRING("y")) = this->getTopOffset(htmlElement,::Math_obj::round(staticPosition->__Field(HX_CSTRING("y"))));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",93)
		if (((htmlElement->get_coreStyle()->getBottom() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",94)
			elementRenderer->getBounds()->__FieldRef(HX_CSTRING("y")) = this->getBottomOffset(htmlElement,containingHTMLElementData->__Field(HX_CSTRING("height")),::Math_obj::round(staticPosition->__Field(HX_CSTRING("y"))));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",98)
			elementRenderer->getBounds()->__FieldRef(HX_CSTRING("y")) = ::Math_obj::round(staticPosition->__Field(HX_CSTRING("y")));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",103)
	return elementRenderer;
}


HX_DEFINE_DYNAMIC_FUNC3(BoxPositioner_obj,position,return )

int BoxPositioner_obj::getLeftOffset( ::cocktail::core::html::HTMLElement htmlElement,int staticPosition){
	HX_SOURCE_PUSH("BoxPositioner_obj::getLeftOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",114)
	return htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("left"));
}


HX_DEFINE_DYNAMIC_FUNC2(BoxPositioner_obj,getLeftOffset,return )

int BoxPositioner_obj::getRightOffset( ::cocktail::core::html::HTMLElement htmlElement,int containingHTMLElementWidth,int staticPosition){
	HX_SOURCE_PUSH("BoxPositioner_obj::getRightOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",122)
	return ((((containingHTMLElementWidth - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))) - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("right")));
}


HX_DEFINE_DYNAMIC_FUNC3(BoxPositioner_obj,getRightOffset,return )

int BoxPositioner_obj::getTopOffset( ::cocktail::core::html::HTMLElement htmlElement,int staticPosition){
	HX_SOURCE_PUSH("BoxPositioner_obj::getTopOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",131)
	return htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("top"));
}


HX_DEFINE_DYNAMIC_FUNC2(BoxPositioner_obj,getTopOffset,return )

int BoxPositioner_obj::getBottomOffset( ::cocktail::core::html::HTMLElement htmlElement,int containingHTMLElementHeight,int staticPosition){
	HX_SOURCE_PUSH("BoxPositioner_obj::getBottomOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/positioner/BoxPositioner.hx",139)
	return ((((containingHTMLElementHeight - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("height"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))) - htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("bottom")));
}


HX_DEFINE_DYNAMIC_FUNC3(BoxPositioner_obj,getBottomOffset,return )


BoxPositioner_obj::BoxPositioner_obj()
{
}

void BoxPositioner_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxPositioner);
	HX_MARK_END_CLASS();
}

Dynamic BoxPositioner_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position_dyn(); }
		break;
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

Dynamic BoxPositioner_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BoxPositioner_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("position"),
	HX_CSTRING("getLeftOffset"),
	HX_CSTRING("getRightOffset"),
	HX_CSTRING("getTopOffset"),
	HX_CSTRING("getBottomOffset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BoxPositioner_obj::__mClass;

void BoxPositioner_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.positioner.BoxPositioner"), hx::TCanCast< BoxPositioner_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BoxPositioner_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace positioner