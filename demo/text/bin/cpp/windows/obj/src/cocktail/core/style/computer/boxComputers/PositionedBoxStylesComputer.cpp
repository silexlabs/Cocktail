#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
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
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_PositionedBoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void PositionedBoxStylesComputer_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",28)
	super::__construct();
}
;
	return null();
}

PositionedBoxStylesComputer_obj::~PositionedBoxStylesComputer_obj() { }

Dynamic PositionedBoxStylesComputer_obj::__CreateEmpty() { return  new PositionedBoxStylesComputer_obj; }
hx::ObjectPtr< PositionedBoxStylesComputer_obj > PositionedBoxStylesComputer_obj::__new()
{  hx::ObjectPtr< PositionedBoxStylesComputer_obj > result = new PositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic PositionedBoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PositionedBoxStylesComputer_obj > result = new PositionedBoxStylesComputer_obj();
	result->__construct();
	return result;}

int PositionedBoxStylesComputer_obj::shrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth){
	HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::shrinkToFit")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",42)
	int shrinkedWidth;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",45)
	if (((bool((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) || bool((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",47)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",49)
		shrinkedWidth = this->doShrinkToFit(style,containingHTMLElementData,minimumWidth);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",52)
		if (((bool((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",54)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedStaticLeft(style,containingHTMLElementData);
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",55)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - shrinkedWidth) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left")));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",58)
			if (((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",60)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",61)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - shrinkedWidth) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",64)
				if (((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",66)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",67)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - shrinkedWidth) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("right")));
				}
			}
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",72)
		shrinkedWidth = style->getComputedStyle()->__Field(HX_CSTRING("width"));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",77)
	shrinkedWidth = this->constrainWidth(style,shrinkedWidth);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",79)
	return shrinkedWidth;
}


HX_DEFINE_DYNAMIC_FUNC3(PositionedBoxStylesComputer_obj,shrinkToFit,return )

int PositionedBoxStylesComputer_obj::applyContentHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int childrenHeight){
	HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::applyContentHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",89)
	int height;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",92)
	if (((bool((style->getTop() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getBottom() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",94)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",95)
		height = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom")));
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",98)
		height = childrenHeight;
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",103)
	height = this->constrainHeight(style,height);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",105)
	return height;
}


HX_DEFINE_DYNAMIC_FUNC3(PositionedBoxStylesComputer_obj,applyContentHeight,return )

Void PositionedBoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::measurePositionOffsets")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,measurePositionOffsets,(void))

Void PositionedBoxStylesComputer_obj::measureAutoWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::measureAutoWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",132)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",135)
		if (((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",136)
			computedStyle->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",140)
			computedStyle->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",144)
		if (((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",145)
			computedStyle->__FieldRef(HX_CSTRING("marginRight")) = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",149)
			computedStyle->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",154)
		if (((bool((style->getLeft() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getRight() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",157)
			computedStyle->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",158)
			computedStyle->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",162)
			this->setComputedWidth(style,((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",168)
			this->setComputedWidth(style,(int)1000000);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,measureAutoWidth,(void))

Void PositionedBoxStylesComputer_obj::measureWidth( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::measureWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",179)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",182)
		this->setComputedWidth(style,this->getComputedWidth(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",185)
		if (((bool((style->getLeft() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getRight() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",188)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",189)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",192)
			if (((bool((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn())) && bool((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",196)
				int computedMargin = ::Math_obj::round((double(((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",198)
				if (((computedMargin >= (int)0))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",200)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = computedMargin;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",201)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = computedMargin;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",206)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",207)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = (((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right")));
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",212)
				if (((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",216)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",217)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("marginRight")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",220)
					if (((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",222)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",223)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left"))) - computedStyle->__Field(HX_CSTRING("right"))) - computedStyle->__Field(HX_CSTRING("marginLeft")));
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",228)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",229)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",236)
			if (((style->getMarginLeft() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",237)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",241)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",245)
			if (((style->getMarginRight() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",246)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",250)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",255)
			if (((bool((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",257)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedStaticLeft(style,containingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",258)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",261)
				if (((style->getLeft() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",263)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",264)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("right")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",267)
					if (((style->getRight() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",269)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",270)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("width")) - computedStyle->__Field(HX_CSTRING("marginLeft"))) - computedStyle->__Field(HX_CSTRING("marginRight"))) - computedStyle->__Field(HX_CSTRING("width"))) - computedStyle->__Field(HX_CSTRING("paddingLeft"))) - computedStyle->__Field(HX_CSTRING("paddingRight"))) - computedStyle->__Field(HX_CSTRING("left")));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,measureWidth,(void))

Void PositionedBoxStylesComputer_obj::measureAutoHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::measureAutoHeight")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",284)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",287)
		if (((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",288)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",292)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",296)
		if (((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",297)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",301)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",306)
		if (((bool((style->getTop() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getBottom() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",309)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",310)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",314)
			this->setComputedHeight(style,((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",317)
			if (((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",319)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",320)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",323)
				if (((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",326)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",327)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("bottom")));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,measureAutoHeight,(void))

Void PositionedBoxStylesComputer_obj::measureHeight( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::measureHeight")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",339)
		Dynamic computedStyle = style->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",342)
		this->setComputedHeight(style,this->getComputedHeight(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",345)
		if (((bool((style->getTop() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getBottom() != ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",348)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",349)
			style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",352)
			if (((bool((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn())) && bool((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",356)
				int computedMargin = ::Math_obj::round((double(((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))))) / double((int)2)));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",358)
				if (((computedMargin >= (int)0))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",360)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = computedMargin;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",361)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = computedMargin;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",366)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",367)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("top")));
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",372)
				if (((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",376)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",377)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("marginBottom")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",380)
					if (((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",382)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",383)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top"))) - computedStyle->__Field(HX_CSTRING("bottom"))) - computedStyle->__Field(HX_CSTRING("marginTop")));
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",388)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",389)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
					}
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",396)
			if (((style->getMarginTop() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",397)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",401)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",405)
			if (((style->getMarginBottom() == ::cocktail::core::style::Margin_obj::cssAuto_dyn()))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",406)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",410)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",415)
			if (((bool((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn())) && bool((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",417)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedStaticTop(style,containingHTMLElementData);
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",418)
				style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",421)
				if (((style->getBottom() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",424)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",425)
					style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("top")));
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",428)
					if (((style->getTop() == ::cocktail::core::style::PositionOffset_obj::cssAuto_dyn()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",431)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",432)
						style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = ((((((containingHTMLElementData->__Field(HX_CSTRING("height")) - computedStyle->__Field(HX_CSTRING("marginTop"))) - computedStyle->__Field(HX_CSTRING("marginBottom"))) - computedStyle->__Field(HX_CSTRING("height"))) - computedStyle->__Field(HX_CSTRING("paddingTop"))) - computedStyle->__Field(HX_CSTRING("paddingBottom"))) - computedStyle->__Field(HX_CSTRING("bottom")));
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,measureHeight,(void))

int PositionedBoxStylesComputer_obj::getComputedStaticLeft( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::getComputedStaticLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",446)
	return style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"));
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,getComputedStaticLeft,return )

int PositionedBoxStylesComputer_obj::getComputedStaticTop( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::getComputedStaticTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",455)
	return style->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
}


HX_DEFINE_DYNAMIC_FUNC2(PositionedBoxStylesComputer_obj,getComputedStaticTop,return )

int PositionedBoxStylesComputer_obj::doShrinkToFit( ::cocktail::core::style::CoreStyle style,Dynamic containingHTMLElementData,int minimumWidth){
	HX_SOURCE_PUSH("PositionedBoxStylesComputer_obj::doShrinkToFit")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/PositionedBoxStylesComputer.hx",463)
	return minimumWidth;
}


HX_DEFINE_DYNAMIC_FUNC3(PositionedBoxStylesComputer_obj,doShrinkToFit,return )


PositionedBoxStylesComputer_obj::PositionedBoxStylesComputer_obj()
{
}

void PositionedBoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PositionedBoxStylesComputer);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic PositionedBoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"shrinkToFit") ) { return shrinkToFit_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"measureWidth") ) { return measureWidth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"doShrinkToFit") ) { return doShrinkToFit_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"applyContentHeight") ) { return applyContentHeight_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedStaticTop") ) { return getComputedStaticTop_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedStaticLeft") ) { return getComputedStaticLeft_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic PositionedBoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void PositionedBoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("shrinkToFit"),
	HX_CSTRING("applyContentHeight"),
	HX_CSTRING("measurePositionOffsets"),
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("measureWidth"),
	HX_CSTRING("measureAutoHeight"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("getComputedStaticLeft"),
	HX_CSTRING("getComputedStaticTop"),
	HX_CSTRING("doShrinkToFit"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class PositionedBoxStylesComputer_obj::__mClass;

void PositionedBoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.PositionedBoxStylesComputer"), hx::TCanCast< PositionedBoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PositionedBoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
