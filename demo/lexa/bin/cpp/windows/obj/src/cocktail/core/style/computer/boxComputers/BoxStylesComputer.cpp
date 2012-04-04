#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_style_AbstractCoreStyle
#include <cocktail/core/style/AbstractCoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ConstrainedDimension
#include <cocktail/core/style/ConstrainedDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Dimension
#include <cocktail/core/style/Dimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Padding
#include <cocktail/core/style/Padding.h>
#endif
#ifndef INCLUDED_cocktail_core_style_PositionOffset
#include <cocktail/core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_boxComputers_BoxStylesComputer
#include <cocktail/core/style/computer/boxComputers/BoxStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace computer{
namespace boxComputers{

Void BoxStylesComputer_obj::__construct()
{
{
}
;
	return null();
}

BoxStylesComputer_obj::~BoxStylesComputer_obj() { }

Dynamic BoxStylesComputer_obj::__CreateEmpty() { return  new BoxStylesComputer_obj; }
hx::ObjectPtr< BoxStylesComputer_obj > BoxStylesComputer_obj::__new()
{  hx::ObjectPtr< BoxStylesComputer_obj > result = new BoxStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic BoxStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BoxStylesComputer_obj > result = new BoxStylesComputer_obj();
	result->__construct();
	return result;}

Void BoxStylesComputer_obj::measure( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measure")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",63)
		this->measureHorizontalPaddings(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",64)
		this->measureVerticalPaddings(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",70)
		this->measureDimensionsConstraints(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",74)
		this->measureWidthAndHorizontalMargins(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",75)
		this->measureHeightAndVerticalMargins(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",80)
		this->measurePositionOffsets(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measure,(void))

int BoxStylesComputer_obj::shrinkToFit( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData,int minimumWidth){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::shrinkToFit")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",100)
	return style->getComputedStyle()->__Field(HX_CSTRING("width"));
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,shrinkToFit,return )

int BoxStylesComputer_obj::applyContentHeight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic cotainingHTMLElementData,int childrenHeight){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::applyContentHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",113)
	return childrenHeight;
}


HX_DEFINE_DYNAMIC_FUNC3(BoxStylesComputer_obj,applyContentHeight,return )

Void BoxStylesComputer_obj::measureDimensionsConstraints( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureDimensionsConstraints")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",131)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("maxHeight")) = this->getComputedConstrainedDimension(style->getMaxHeight(),containingHTMLElementData->__Field(HX_CSTRING("height")),containingHTMLElementData->__Field(HX_CSTRING("isHeightAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),null());
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",134)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("minHeight")) = this->getComputedConstrainedDimension(style->getMinHeight(),containingHTMLElementData->__Field(HX_CSTRING("height")),containingHTMLElementData->__Field(HX_CSTRING("isHeightAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),true);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",137)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("maxWidth")) = this->getComputedConstrainedDimension(style->getMaxWidth(),containingHTMLElementData->__Field(HX_CSTRING("width")),containingHTMLElementData->__Field(HX_CSTRING("isWidthAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),null());
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",140)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("minWidth")) = this->getComputedConstrainedDimension(style->getMinWidth(),containingHTMLElementData->__Field(HX_CSTRING("width")),containingHTMLElementData->__Field(HX_CSTRING("isWidthAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureDimensionsConstraints,(void))

Void BoxStylesComputer_obj::measurePositionOffsets( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measurePositionOffsets")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",151)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("left")) = this->getComputedPositionOffset(style->getLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",154)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("right")) = this->getComputedPositionOffset(style->getRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",157)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("top")) = this->getComputedPositionOffset(style->getTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",160)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("bottom")) = this->getComputedPositionOffset(style->getBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measurePositionOffsets,(void))

Void BoxStylesComputer_obj::measureVerticalPaddings( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureVerticalPaddings")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",174)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingTop")) = this->getComputedPadding(style->getPaddingTop(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",177)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingBottom")) = this->getComputedPadding(style->getPaddingBottom(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureVerticalPaddings,(void))

Void BoxStylesComputer_obj::measureHorizontalPaddings( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureHorizontalPaddings")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",187)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingLeft")) = this->getComputedPadding(style->getPaddingLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",190)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("paddingRight")) = this->getComputedPadding(style->getPaddingRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureHorizontalPaddings,(void))

Void BoxStylesComputer_obj::measureWidthAndHorizontalMargins( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureWidthAndHorizontalMargins")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",201)
		if (((style->getWidth() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",203)
			this->measureAutoWidth(style,containingHTMLElementData);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",207)
			this->measureWidth(style,containingHTMLElementData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureWidthAndHorizontalMargins,(void))

Void BoxStylesComputer_obj::measureAutoWidth( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureAutoWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",225)
		this->setComputedWidth(style,(int)0);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",228)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",230)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",233)
		this->setComputedWidth(style,this->getComputedAutoWidth(style,containingHTMLElementData));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureAutoWidth,(void))

Void BoxStylesComputer_obj::measureWidth( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",245)
		this->setComputedWidth(style,this->getComputedWidth(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",248)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginLeft")) = this->getComputedMarginLeft(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",250)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginRight")) = this->getComputedMarginRight(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureWidth,(void))

Void BoxStylesComputer_obj::measureHeightAndVerticalMargins( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureHeightAndVerticalMargins")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",262)
		if (((style->getHeight() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",268)
			this->measureAutoHeight(style,containingHTMLElementData);
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",272)
			this->measureHeight(style,containingHTMLElementData);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureHeightAndVerticalMargins,(void))

Void BoxStylesComputer_obj::measureAutoHeight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureAutoHeight")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",291)
		this->setComputedHeight(style,this->getComputedAutoHeight(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",294)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",296)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureAutoHeight,(void))

Void BoxStylesComputer_obj::measureHeight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::measureHeight")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",310)
		this->setComputedHeight(style,this->getComputedHeight(style,containingHTMLElementData));
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",312)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginTop")) = this->getComputedMarginTop(style,containingHTMLElementData);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",314)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("marginBottom")) = this->getComputedMarginBottom(style,containingHTMLElementData);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,measureHeight,(void))

int BoxStylesComputer_obj::constrainWidth( ::cocktail::core::style::AbstractCoreStyle style,int computedWidth){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::constrainWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",326)
	Dynamic computedStyle = style->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",332)
	if (((style->getMaxWidth() != ::cocktail::core::style::ConstrainedDimension_obj::none_dyn()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",333)
		if (((computedWidth > computedStyle->__Field(HX_CSTRING("maxWidth"))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",335)
			computedWidth = computedStyle->__Field(HX_CSTRING("maxWidth"));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",341)
	if (((computedWidth < computedStyle->__Field(HX_CSTRING("minWidth"))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",342)
		computedWidth = computedStyle->__Field(HX_CSTRING("minWidth"));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",346)
	return computedWidth;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,constrainWidth,return )

int BoxStylesComputer_obj::constrainHeight( ::cocktail::core::style::AbstractCoreStyle style,int computedHeight){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::constrainHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",354)
	Dynamic computedStyle = style->getComputedStyle();
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",357)
	if (((style->getMaxHeight() != ::cocktail::core::style::ConstrainedDimension_obj::none_dyn()))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",358)
		if (((computedHeight > computedStyle->__Field(HX_CSTRING("maxHeight"))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",360)
			computedHeight = computedStyle->__Field(HX_CSTRING("maxHeight"));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",366)
	if (((computedHeight < computedStyle->__Field(HX_CSTRING("minHeight"))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",367)
		computedHeight = computedStyle->__Field(HX_CSTRING("minHeight"));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",371)
	return computedHeight;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,constrainHeight,return )

Void BoxStylesComputer_obj::setComputedHeight( ::cocktail::core::style::AbstractCoreStyle style,int computedHeight){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::setComputedHeight")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",379)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("height")) = this->constrainHeight(style,computedHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,setComputedHeight,(void))

Void BoxStylesComputer_obj::setComputedWidth( ::cocktail::core::style::AbstractCoreStyle style,int computedWidth){
{
		HX_SOURCE_PUSH("BoxStylesComputer_obj::setComputedWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",388)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("width")) = this->constrainWidth(style,computedWidth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,setComputedWidth,(void))

int BoxStylesComputer_obj::getComputedWidth( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",405)
	return this->getComputedDimension(style->getWidth(),containingHTMLElementData->__Field(HX_CSTRING("width")),containingHTMLElementData->__Field(HX_CSTRING("isWidthAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedWidth,return )

int BoxStylesComputer_obj::getComputedAutoWidth( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedAutoWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",415)
	return ((((containingHTMLElementData->__Field(HX_CSTRING("width")) - style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingRight"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginRight")));
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedAutoWidth,return )

int BoxStylesComputer_obj::getComputedHeight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",427)
	return this->getComputedDimension(style->getHeight(),containingHTMLElementData->__Field(HX_CSTRING("height")),containingHTMLElementData->__Field(HX_CSTRING("isHeightAuto")),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedHeight,return )

int BoxStylesComputer_obj::getComputedAutoHeight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedAutoHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",437)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedAutoHeight,return )

int BoxStylesComputer_obj::getComputedMarginLeft( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedMarginLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",448)
	return this->getComputedMargin(style->getMarginLeft(),style->getMarginRight(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getComputedStyle()->__Field(HX_CSTRING("width")),(style->getWidth() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),(style->getComputedStyle()->__Field(HX_CSTRING("paddingRight")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),true);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedMarginLeft,return )

int BoxStylesComputer_obj::getComputedMarginRight( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedMarginRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",456)
	return this->getComputedMargin(style->getMarginRight(),style->getMarginLeft(),containingHTMLElementData->__Field(HX_CSTRING("width")),style->getComputedStyle()->__Field(HX_CSTRING("width")),(style->getWidth() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),(style->getComputedStyle()->__Field(HX_CSTRING("paddingRight")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),true);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedMarginRight,return )

int BoxStylesComputer_obj::getComputedMarginTop( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedMarginTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",464)
	return this->getComputedMargin(style->getMarginTop(),style->getMarginBottom(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getComputedStyle()->__Field(HX_CSTRING("height")),(style->getHeight() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),(style->getComputedStyle()->__Field(HX_CSTRING("paddingTop")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),false);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedMarginTop,return )

int BoxStylesComputer_obj::getComputedMarginBottom( ::cocktail::core::style::AbstractCoreStyle style,Dynamic containingHTMLElementData){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedMarginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",472)
	return this->getComputedMargin(style->getMarginBottom(),style->getMarginTop(),containingHTMLElementData->__Field(HX_CSTRING("height")),style->getComputedStyle()->__Field(HX_CSTRING("height")),(style->getHeight() == ::cocktail::core::style::Dimension_obj::cssAuto_dyn()),(style->getComputedStyle()->__Field(HX_CSTRING("paddingTop")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))),style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")),false);
}


HX_DEFINE_DYNAMIC_FUNC2(BoxStylesComputer_obj,getComputedMarginBottom,return )

int BoxStylesComputer_obj::getComputedMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedMargin")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",498)
	int computedMargin;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",501)
	{
::cocktail::core::style::Margin _switch_1 = (marginStyleValue);
		switch((_switch_1)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",505)
					computedMargin = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,fontSize,xHeight);
				}
			}
			;break;
			case 1: {
				int value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",509)
					if (((isDimensionAuto == true))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",513)
						computedMargin = (int)0;
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",517)
						computedMargin = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementDimension));
					}
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",523)
				computedMargin = this->getComputedAutoMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",527)
	return computedMargin;
}


HX_DEFINE_DYNAMIC_FUNC9(BoxStylesComputer_obj,getComputedMargin,return )

int BoxStylesComputer_obj::getComputedAutoMargin( ::cocktail::core::style::Margin marginStyleValue,::cocktail::core::style::Margin opositeMargin,int containingHTMLElementDimension,int computedDimension,bool isDimensionAuto,int computedPaddingsDimension,double fontSize,double xHeight,bool isHorizontalMargin){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedAutoMargin")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",535)
	int computedMargin;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",540)
	if (((bool((isHorizontalMargin == false)) || bool((isDimensionAuto == true))))){
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",541)
		computedMargin = (int)0;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",546)
		{
::cocktail::core::style::Margin _switch_2 = (opositeMargin);
			switch((_switch_2)->GetIndex()){
				case 2: {
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",551)
					computedMargin = ::Math_obj::round((double((((containingHTMLElementDimension - computedDimension) - computedPaddingsDimension))) / double((int)2)));
				}
				;break;
				default: {
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",556)
					int opositeComputedMargin = this->getComputedMargin(opositeMargin,marginStyleValue,containingHTMLElementDimension,computedDimension,isDimensionAuto,computedPaddingsDimension,fontSize,xHeight,isHorizontalMargin);
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",557)
					computedMargin = (((containingHTMLElementDimension - computedDimension) - computedPaddingsDimension) - opositeComputedMargin);
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",561)
	return computedMargin;
}


HX_DEFINE_DYNAMIC_FUNC9(BoxStylesComputer_obj,getComputedAutoMargin,return )

int BoxStylesComputer_obj::getComputedConstrainedDimension( ::cocktail::core::style::ConstrainedDimension constrainedDimension,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight,Dynamic __o_isMinConstraint){
bool isMinConstraint = __o_isMinConstraint.Default(false);
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedConstrainedDimension");
{
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",581)
		int computedConstraintDimension;
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",584)
		{
::cocktail::core::style::ConstrainedDimension _switch_3 = (constrainedDimension);
			switch((_switch_3)->GetIndex()){
				case 0: {
					::cocktail::core::unit::Length value = _switch_3->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",588)
						computedConstraintDimension = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,fontSize,xHeight);
					}
				}
				;break;
				case 1: {
					int value = _switch_3->__Param(0);
{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",592)
						if (((isContainingDimensionAuto == true))){
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",597)
							if (((isMinConstraint == true))){
								HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",599)
								computedConstraintDimension = (int)0;
							}
							else{
								HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",603)
								computedConstraintDimension = ::Math_obj::round(::Math_obj::POSITIVE_INFINITY);
							}
						}
						else{
							HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",608)
							computedConstraintDimension = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementDimension));
						}
					}
				}
				;break;
				case 2: {
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",614)
					if (((isMinConstraint == true))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",616)
						computedConstraintDimension = (int)0;
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",620)
						computedConstraintDimension = ::Math_obj::round(::Math_obj::POSITIVE_INFINITY);
					}
				}
				;break;
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",625)
		return computedConstraintDimension;
	}
}


HX_DEFINE_DYNAMIC_FUNC6(BoxStylesComputer_obj,getComputedConstrainedDimension,return )

int BoxStylesComputer_obj::getComputedPositionOffset( ::cocktail::core::style::PositionOffset positionOffsetStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedPositionOffset")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",643)
	int computedPositionOffset;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",645)
	{
::cocktail::core::style::PositionOffset _switch_4 = (positionOffsetStyleValue);
		switch((_switch_4)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",647)
					computedPositionOffset = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,fontSize,xHeight);
				}
			}
			;break;
			case 1: {
				int value = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",650)
					computedPositionOffset = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementDimension));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",653)
				computedPositionOffset = (int)0;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",657)
	return computedPositionOffset;
}


HX_DEFINE_DYNAMIC_FUNC4(BoxStylesComputer_obj,getComputedPositionOffset,return )

int BoxStylesComputer_obj::getComputedDimension( ::cocktail::core::style::Dimension dimensionStyleValue,int containingHTMLElementDimension,bool isContainingDimensionAuto,double fontSize,double xHeight){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedDimension")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",674)
	int computedDimensions;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",677)
	{
::cocktail::core::style::Dimension _switch_5 = (dimensionStyleValue);
		switch((_switch_5)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",681)
					computedDimensions = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,fontSize,xHeight);
				}
			}
			;break;
			case 1: {
				int value = _switch_5->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",685)
					computedDimensions = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementDimension));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",689)
				computedDimensions = (int)0;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",695)
	return computedDimensions;
}


HX_DEFINE_DYNAMIC_FUNC5(BoxStylesComputer_obj,getComputedDimension,return )

int BoxStylesComputer_obj::getComputedPadding( ::cocktail::core::style::Padding paddingStyleValue,int containingHTMLElementDimension,double fontSize,double xHeight){
	HX_SOURCE_PUSH("BoxStylesComputer_obj::getComputedPadding")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",711)
	int computedPaddingValue;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",714)
	{
::cocktail::core::style::Padding _switch_6 = (paddingStyleValue);
		switch((_switch_6)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",718)
					computedPaddingValue = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,fontSize,xHeight);
				}
			}
			;break;
			case 1: {
				int value = _switch_6->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",722)
					computedPaddingValue = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,containingHTMLElementDimension));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/boxComputers/BoxStylesComputer.hx",727)
	return computedPaddingValue;
}


HX_DEFINE_DYNAMIC_FUNC4(BoxStylesComputer_obj,getComputedPadding,return )


BoxStylesComputer_obj::BoxStylesComputer_obj()
{
}

void BoxStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BoxStylesComputer);
	HX_MARK_END_CLASS();
}

Dynamic BoxStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"measure") ) { return measure_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"shrinkToFit") ) { return shrinkToFit_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"measureWidth") ) { return measureWidth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"measureHeight") ) { return measureHeight_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"constrainWidth") ) { return constrainWidth_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"constrainHeight") ) { return constrainHeight_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"measureAutoWidth") ) { return measureAutoWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"setComputedWidth") ) { return setComputedWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedWidth") ) { return getComputedWidth_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"measureAutoHeight") ) { return measureAutoHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setComputedHeight") ) { return setComputedHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedHeight") ) { return getComputedHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMargin") ) { return getComputedMargin_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"applyContentHeight") ) { return applyContentHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedPadding") ) { return getComputedPadding_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getComputedAutoWidth") ) { return getComputedAutoWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginTop") ) { return getComputedMarginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedDimension") ) { return getComputedDimension_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getComputedAutoHeight") ) { return getComputedAutoHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginLeft") ) { return getComputedMarginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedAutoMargin") ) { return getComputedAutoMargin_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"measurePositionOffsets") ) { return measurePositionOffsets_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginRight") ) { return getComputedMarginRight_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"measureVerticalPaddings") ) { return measureVerticalPaddings_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedMarginBottom") ) { return getComputedMarginBottom_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"measureHorizontalPaddings") ) { return measureHorizontalPaddings_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedPositionOffset") ) { return getComputedPositionOffset_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"measureDimensionsConstraints") ) { return measureDimensionsConstraints_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"measureHeightAndVerticalMargins") ) { return measureHeightAndVerticalMargins_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedConstrainedDimension") ) { return getComputedConstrainedDimension_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"measureWidthAndHorizontalMargins") ) { return measureWidthAndHorizontalMargins_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BoxStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BoxStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("measure"),
	HX_CSTRING("shrinkToFit"),
	HX_CSTRING("applyContentHeight"),
	HX_CSTRING("measureDimensionsConstraints"),
	HX_CSTRING("measurePositionOffsets"),
	HX_CSTRING("measureVerticalPaddings"),
	HX_CSTRING("measureHorizontalPaddings"),
	HX_CSTRING("measureWidthAndHorizontalMargins"),
	HX_CSTRING("measureAutoWidth"),
	HX_CSTRING("measureWidth"),
	HX_CSTRING("measureHeightAndVerticalMargins"),
	HX_CSTRING("measureAutoHeight"),
	HX_CSTRING("measureHeight"),
	HX_CSTRING("constrainWidth"),
	HX_CSTRING("constrainHeight"),
	HX_CSTRING("setComputedHeight"),
	HX_CSTRING("setComputedWidth"),
	HX_CSTRING("getComputedWidth"),
	HX_CSTRING("getComputedAutoWidth"),
	HX_CSTRING("getComputedHeight"),
	HX_CSTRING("getComputedAutoHeight"),
	HX_CSTRING("getComputedMarginLeft"),
	HX_CSTRING("getComputedMarginRight"),
	HX_CSTRING("getComputedMarginTop"),
	HX_CSTRING("getComputedMarginBottom"),
	HX_CSTRING("getComputedMargin"),
	HX_CSTRING("getComputedAutoMargin"),
	HX_CSTRING("getComputedConstrainedDimension"),
	HX_CSTRING("getComputedPositionOffset"),
	HX_CSTRING("getComputedDimension"),
	HX_CSTRING("getComputedPadding"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BoxStylesComputer_obj::__mClass;

void BoxStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.boxComputers.BoxStylesComputer"), hx::TCanCast< BoxStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BoxStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
} // end namespace boxComputers
