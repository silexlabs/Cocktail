#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
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
#ifndef INCLUDED_core_html_EmbeddedElement
#include <core/html/EmbeddedElement.h>
#endif
#ifndef INCLUDED_core_style_AbstractStyle
#include <core/style/AbstractStyle.h>
#endif
#ifndef INCLUDED_core_style_Dimension
#include <core/style/Dimension.h>
#endif
#ifndef INCLUDED_core_style_Margin
#include <core/style/Margin.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_BoxStylesComputer
#include <core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void EmbeddedBlockBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",32)
	super::__construct();
}
;
	return null();
}

EmbeddedBlockBoxStylesComputer_obj::~EmbeddedBlockBoxStylesComputer_obj() { }

Dynamic EmbeddedBlockBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedBlockBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > EmbeddedBlockBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > result = new EmbeddedBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedBlockBoxStylesComputer_obj > result = new EmbeddedBlockBoxStylesComputer_obj();
	result->__construct();
	return result;}

Void EmbeddedBlockBoxStylesComputer_obj::measureAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("EmbeddedBlockBoxStylesComputer_obj::measureAutoWidth")
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",43)
		this->setComputedWidth(style,this->getComputedAutoWidth(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",46)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",48)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedBlockBoxStylesComputer_obj,measureAutoWidth,(void))

int EmbeddedBlockBoxStylesComputer_obj::getComputedAutoWidth( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("EmbeddedBlockBoxStylesComputer_obj::getComputedAutoWidth")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",58)
	int ret = (int)0;
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",60)
	::core::html::EmbeddedElement embeddedHTMLElement = style->get_htmlElement();
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",63)
	if (((style->getHeight() == ::core::style::Dimension_obj::cssAuto_dyn()))){
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",64)
		if (((embeddedHTMLElement->get_intrinsicWidth() != null()))){
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",69)
			ret = embeddedHTMLElement->get_intrinsicWidth();
		}
		else{
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",73)
			if (((bool((embeddedHTMLElement->get_intrinsicHeight() != null())) && bool((embeddedHTMLElement->get_intrinsicRatio() != null()))))){
				HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",74)
				ret = ::Math_obj::round((embeddedHTMLElement->get_intrinsicHeight() * embeddedHTMLElement->get_intrinsicRatio()));
			}
			else{
				HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",77)
				if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
					HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",78)
					if (((containingHTMLElementData->__Field(HX_CSTRING("isWidthAuto")) == false))){
						HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",88)
						Dynamic computedStyle = style->getComputedStyle();
						HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",90)
						ret = ((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight")));
					}
					else{
						HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",93)
						ret = (int)0;
					}
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",103)
		int computedHeight = this->getComputedDimension(style->getHeight(),containingHTMLElementData->__Field(HX_CSTRING("height")),containingHTMLElementData->__Field(HX_CSTRING("isHeightAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",104)
		this->setComputedHeight(style,computedHeight);
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",107)
		if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",108)
			ret = ::Math_obj::round((computedHeight * embeddedHTMLElement->get_intrinsicRatio()));
		}
		else{
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",112)
			if (((embeddedHTMLElement->get_intrinsicWidth() != null()))){
				HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",113)
				ret = embeddedHTMLElement->get_intrinsicWidth();
			}
			else{
				HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",117)
				ret = (int)300;
			}
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",125)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedBlockBoxStylesComputer_obj,getComputedAutoWidth,return )

int EmbeddedBlockBoxStylesComputer_obj::getComputedAutoHeight( ::core::style::AbstractStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("EmbeddedBlockBoxStylesComputer_obj::getComputedAutoHeight")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",135)
	int ret = (int)0;
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",137)
	::core::html::EmbeddedElement embeddedHTMLElement = style->get_htmlElement();
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",140)
	if (((style->getWidth() == ::core::style::Dimension_obj::cssAuto_dyn()))){
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",141)
		if (((embeddedHTMLElement->get_intrinsicHeight() != null()))){
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",144)
			ret = embeddedHTMLElement->get_intrinsicHeight();
		}
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",152)
		int computedWidth = this->getComputedDimension(style->getWidth(),containingHTMLElementData->__Field(HX_CSTRING("width")),containingHTMLElementData->__Field(HX_CSTRING("isWidthAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",153)
		this->setComputedWidth(style,computedWidth);
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",156)
		if (((embeddedHTMLElement->get_intrinsicRatio() != null()))){
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",157)
			ret = ::Math_obj::round((double(style->getComputedStyle()->__Field(HX_CSTRING("width"))) / double(embeddedHTMLElement->get_intrinsicRatio())));
		}
		else{
			HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",161)
			ret = (int)150;
		}
	}
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",169)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedBlockBoxStylesComputer_obj,getComputedAutoHeight,return )

int EmbeddedBlockBoxStylesComputer_obj::getComputedAutoMargin( ::core::style::Margin marginStyleValue,::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("EmbeddedBlockBoxStylesComputer_obj::getComputedAutoMargin")
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",178)
	int computedMargin;
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",180)
	if (((isHorizontalMargin == false))){
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",181)
		computedMargin = (int)0;
	}
	else{
		HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",185)
		computedMargin = this->super::getComputedAutoMargin(marginStyleValue,opositeMargin,containingHTMLElementDimension,computedDimension,false,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
	}
	HX_SOURCE_POS("../../src/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.hx",191)
	return computedMargin;
}


HX_DEFINE_DYNAMIC_FUNC9(EmbeddedBlockBoxStylesComputer_obj,getComputedAutoMargin,return )


EmbeddedBlockBoxStylesComputer_obj::EmbeddedBlockBoxStylesComputer_obj()
{
}

void EmbeddedBlockBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedBlockBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoHeight") ) { return getComputedAutoHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EmbeddedBlockBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EmbeddedBlockBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("getComputedAutoWidth"),
	HX_CSTRING("getComputedAutoHeight"),
	HX_CSTRING("getComputedAutoMargin"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedBlockBoxStylesComputer_obj::__mClass;

void EmbeddedBlockBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("core.style.computer.boxComputers.EmbeddedBlockBoxStylesComputer"), hx::TCanCast< EmbeddedBlockBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedBlockBoxStylesComputer_obj::__boot()
{
}

} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
