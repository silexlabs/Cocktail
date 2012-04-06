#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_PositionOffset
#include <cocktail/core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedBlockBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedBlockBoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_EmbeddedPositionedBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void EmbeddedPositionedBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",26)
	super::__construct();
}
;
	return null();
}

EmbeddedPositionedBoxStylesComputer_obj::~EmbeddedPositionedBoxStylesComputer_obj() { }

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__CreateEmpty() { return  new EmbeddedPositionedBoxStylesComputer_obj; }
hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > EmbeddedPositionedBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > result = new EmbeddedPositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EmbeddedPositionedBoxStylesComputer_obj > result = new EmbeddedPositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Void EmbeddedPositionedBoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("EmbeddedPositionedBoxStylesComputer_obj::measurePositionOffsets")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",38)
		this->measureHorizontalPositionOffsets(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",40)
		this->measureVerticalPositionOffsets(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,measurePositionOffsets,(void))

Void EmbeddedPositionedBoxStylesComputer_obj::measureHorizontalPositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("EmbeddedPositionedBoxStylesComputer_obj::measureHorizontalPositionOffsets")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",48)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",51)
		if (((bool((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) || bool((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",54)
			if (((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",55)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",58)
			if (((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",59)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = (int)0;
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",64)
			if (((bool((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",66)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedStaticLeft(style,containingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",67)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",70)
				if (((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",72)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",73)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",76)
					if (((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",78)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",79)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight")));
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",86)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",87)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",90)
			if (((bool((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn())) && bool((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",92)
				int margin = ::Math_obj::round((double((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",96)
				int computedMargin = ::Math_obj::round((double(((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",98)
				if (((computedMargin >= (int)0))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",100)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = computedMargin;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",101)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = computedMargin;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",106)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",107)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = (((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right")));
				}
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",110)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",112)
				if (((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",113)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("marginRight")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",116)
					if (((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",117)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("marginLeft")));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,measureHorizontalPositionOffsets,(void))

Void EmbeddedPositionedBoxStylesComputer_obj::measureVerticalPositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("EmbeddedPositionedBoxStylesComputer_obj::measureVerticalPositionOffsets")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",129)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",131)
		if (((bool((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) || bool((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",133)
			if (((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",134)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",137)
			if (((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",138)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",142)
			if (((bool((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",144)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedStaticTop(style,containingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",145)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",148)
				if (((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",150)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",151)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",153)
					if (((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",155)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",156)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom")));
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",160)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",161)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",167)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",168)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",170)
			if (((bool((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn())) && bool((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",172)
				int margin = ::Math_obj::round((double((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",174)
				int computedMargin = ::Math_obj::round((double(((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",176)
				if (((computedMargin >= (int)0))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",178)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = computedMargin;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",179)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = computedMargin;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",183)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",184)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom")));
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",187)
				if (((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",188)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("marginBottom")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",191)
					if (((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",192)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("marginTop")));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,measureVerticalPositionOffsets,(void))

int EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticLeft( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",203)
	return style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"));
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,getComputedStaticLeft,return )

int EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticTop( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("EmbeddedPositionedBoxStylesComputer_obj::getComputedStaticTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/EmbeddedPositionedBoxStylesComputer.hx",212)
	return style->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
}


HX_DEFINE_DYNAMIC_FUNC2(EmbeddedPositionedBoxStylesComputer_obj,getComputedStaticTop,return )


EmbeddedPositionedBoxStylesComputer_obj::EmbeddedPositionedBoxStylesComputer_obj()
{
}

void EmbeddedPositionedBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(EmbeddedPositionedBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedStaticTop") ) { return getComputedStaticTop_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedStaticLeft") ) { return getComputedStaticLeft_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"measureVerticalPositionOffsets") ) { return measureVerticalPositionOffsets_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"measureHorizontalPositionOffsets") ) { return measureHorizontalPositionOffsets_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EmbeddedPositionedBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EmbeddedPositionedBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("measurePositionOffsets"),
	HX_CSTRING("measureHorizontalPositionOffsets"),
	HX_CSTRING("measureVerticalPositionOffsets"),
	HX_CSTRING("getComputedStaticLeft"),
	HX_CSTRING("getComputedStaticTop"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class EmbeddedPositionedBoxStylesComputer_obj::__mClass;

void EmbeddedPositionedBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.EmbeddedPositionedBoxStylesComputer"), hx::TCanCast< EmbeddedPositionedBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EmbeddedPositionedBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
