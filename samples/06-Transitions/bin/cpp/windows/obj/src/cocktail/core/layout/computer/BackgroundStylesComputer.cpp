#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UsedValuesVO
#include <cocktail/core/css/UsedValuesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_DimensionVO
#include <cocktail/core/geom/DimensionVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_PointVO
#include <cocktail/core/geom/PointVO.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_RectangleVO
#include <cocktail/core/geom/RectangleVO.h>
#endif
#ifndef INCLUDED_cocktail_core_layout_computer_BackgroundStylesComputer
#include <cocktail/core/layout/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
namespace cocktail{
namespace core{
namespace layout{
namespace computer{

Void BackgroundStylesComputer_obj::__construct()
{
HX_STACK_PUSH("BackgroundStylesComputer::new","cocktail/core/layout/computer/BackgroundStylesComputer.hx",47);
{
}
;
	return null();
}

BackgroundStylesComputer_obj::~BackgroundStylesComputer_obj() { }

Dynamic BackgroundStylesComputer_obj::__CreateEmpty() { return  new BackgroundStylesComputer_obj; }
hx::ObjectPtr< BackgroundStylesComputer_obj > BackgroundStylesComputer_obj::__new()
{  hx::ObjectPtr< BackgroundStylesComputer_obj > result = new BackgroundStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic BackgroundStylesComputer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BackgroundStylesComputer_obj > result = new BackgroundStylesComputer_obj();
	result->__construct();
	return result;}

Dynamic BackgroundStylesComputer_obj::computeIndividualBackground( ::cocktail::core::css::CoreStyle style,::cocktail::core::geom::RectangleVO backgroundBox,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::css::CSSPropertyValue backgroundRepeat,::cocktail::core::css::CSSPropertyValue backgroundImage){
	HX_STACK_PUSH("BackgroundStylesComputer::computeIndividualBackground","cocktail/core/layout/computer/BackgroundStylesComputer.hx",86);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(backgroundBox,"backgroundBox");
	HX_STACK_ARG(intrinsicWidth,"intrinsicWidth");
	HX_STACK_ARG(intrinsicHeight,"intrinsicHeight");
	HX_STACK_ARG(intrinsicRatio,"intrinsicRatio");
	HX_STACK_ARG(backgroundPosition,"backgroundPosition");
	HX_STACK_ARG(backgroundSize,"backgroundSize");
	HX_STACK_ARG(backgroundOrigin,"backgroundOrigin");
	HX_STACK_ARG(backgroundClip,"backgroundClip");
	HX_STACK_ARG(backgroundRepeat,"backgroundRepeat");
	HX_STACK_ARG(backgroundImage,"backgroundImage");
	HX_STACK_LINE(88)
	::cocktail::core::geom::RectangleVO backgroundPositioningArea = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundPositioningArea(style,backgroundOrigin,backgroundBox);		HX_STACK_VAR(backgroundPositioningArea,"backgroundPositioningArea");
	HX_STACK_LINE(91)
	::cocktail::core::geom::DimensionVO computedBackgroundSize = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getComputedBackgroundSize(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio);		HX_STACK_VAR(computedBackgroundSize,"computedBackgroundSize");
	HX_STACK_LINE(95)
	::cocktail::core::geom::PointVO computedBackgroundPosition = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getComputedBackgroundPosition(backgroundPosition,backgroundPositioningArea,computedBackgroundSize);		HX_STACK_VAR(computedBackgroundPosition,"computedBackgroundPosition");
	HX_STACK_LINE(99)
	::cocktail::core::geom::RectangleVO computedBackgroundClip = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundPaintingArea(style,backgroundClip,backgroundBox);		HX_STACK_VAR(computedBackgroundClip,"computedBackgroundClip");
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::css::CSSPropertyValue &backgroundRepeat,::cocktail::core::css::CSSPropertyValue &backgroundImage,::cocktail::core::geom::DimensionVO &computedBackgroundSize,::cocktail::core::geom::RectangleVO &backgroundPositioningArea,::cocktail::core::geom::RectangleVO &computedBackgroundClip,::cocktail::core::geom::PointVO &computedBackgroundPosition){
			HX_STACK_PUSH("*::closure","cocktail/core/layout/computer/BackgroundStylesComputer.hx",101);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("backgroundOrigin") , backgroundPositioningArea,false);
				__result->Add(HX_CSTRING("backgroundClip") , computedBackgroundClip,false);
				__result->Add(HX_CSTRING("backgroundRepeat") , backgroundRepeat,false);
				__result->Add(HX_CSTRING("backgroundImage") , backgroundImage,false);
				__result->Add(HX_CSTRING("backgroundSize") , computedBackgroundSize,false);
				__result->Add(HX_CSTRING("backgroundPosition") , computedBackgroundPosition,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(101)
	Dynamic computedBackgroundStyle = _Function_1_1::Block(backgroundRepeat,backgroundImage,computedBackgroundSize,backgroundPositioningArea,computedBackgroundClip,computedBackgroundPosition);		HX_STACK_VAR(computedBackgroundStyle,"computedBackgroundStyle");
	HX_STACK_LINE(110)
	return computedBackgroundStyle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC11(BackgroundStylesComputer_obj,computeIndividualBackground,return )

::cocktail::core::geom::PointVO BackgroundStylesComputer_obj::getComputedBackgroundPosition( ::cocktail::core::css::CSSPropertyValue backgroundPosition,::cocktail::core::geom::RectangleVO backgroundPositioningArea,::cocktail::core::geom::DimensionVO computedBackgroundSize){
	HX_STACK_PUSH("BackgroundStylesComputer::getComputedBackgroundPosition","cocktail/core/layout/computer/BackgroundStylesComputer.hx",132);
	HX_STACK_ARG(backgroundPosition,"backgroundPosition");
	HX_STACK_ARG(backgroundPositioningArea,"backgroundPositioningArea");
	HX_STACK_ARG(computedBackgroundSize,"computedBackgroundSize");
	HX_STACK_LINE(133)
	::cocktail::core::css::CSSPropertyValue backgroundPositionX = null();		HX_STACK_VAR(backgroundPositionX,"backgroundPositionX");
	HX_STACK_LINE(134)
	::cocktail::core::css::CSSPropertyValue backgroundPositionY = null();		HX_STACK_VAR(backgroundPositionY,"backgroundPositionY");
	HX_STACK_LINE(136)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (backgroundPosition);
		switch((_switch_1)->GetIndex()){
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_1->__Param(0);
{
					HX_STACK_LINE(139)
					backgroundPositionX = value->__get((int)0);
					HX_STACK_LINE(140)
					backgroundPositionY = value->__get((int)1);
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(144)
	Float computedBackgroundXPosition = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::doGetComputedBackgroundPosition(backgroundPositionX,backgroundPositioningArea->width,computedBackgroundSize->width);		HX_STACK_VAR(computedBackgroundXPosition,"computedBackgroundXPosition");
	HX_STACK_LINE(145)
	Float computedBackgroundYPosition = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::doGetComputedBackgroundPosition(backgroundPositionY,backgroundPositioningArea->height,computedBackgroundSize->height);		HX_STACK_VAR(computedBackgroundYPosition,"computedBackgroundYPosition");
	HX_STACK_LINE(147)
	::cocktail::core::geom::PointVO computedBackgroundPosition = ::cocktail::core::geom::PointVO_obj::__new(computedBackgroundXPosition,computedBackgroundYPosition);		HX_STACK_VAR(computedBackgroundPosition,"computedBackgroundPosition");
	HX_STACK_LINE(149)
	return computedBackgroundPosition;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(BackgroundStylesComputer_obj,getComputedBackgroundPosition,return )

Float BackgroundStylesComputer_obj::doGetComputedBackgroundPosition( ::cocktail::core::css::CSSPropertyValue backgroundPosition,Float backgroundPositioningAreaDimension,Float imageDimension){
	HX_STACK_PUSH("BackgroundStylesComputer::doGetComputedBackgroundPosition","cocktail/core/layout/computer/BackgroundStylesComputer.hx",156);
	HX_STACK_ARG(backgroundPosition,"backgroundPosition");
	HX_STACK_ARG(backgroundPositioningAreaDimension,"backgroundPositioningAreaDimension");
	HX_STACK_ARG(imageDimension,"imageDimension");
	HX_STACK_LINE(157)
	Float computedBackgroundPosition = 0.0;		HX_STACK_VAR(computedBackgroundPosition,"computedBackgroundPosition");
	HX_STACK_LINE(159)
	{
		::cocktail::core::css::CSSPropertyValue _switch_2 = (backgroundPosition);
		switch((_switch_2)->GetIndex()){
			case 18: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(161)
					computedBackgroundPosition = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(167)
					computedBackgroundPosition = (((backgroundPositioningAreaDimension - imageDimension)) * ((value * 0.01)));
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_2->__Param(0);
{
					HX_STACK_LINE(170)
					{
						::cocktail::core::css::CSSKeywordValue _switch_3 = (value);
						switch((_switch_3)->GetIndex()){
							case 13: {
								HX_STACK_LINE(174)
								computedBackgroundPosition = (((backgroundPositioningAreaDimension - imageDimension)) * 0.5);
							}
							;break;
							case 11: case 22: {
								HX_STACK_LINE(178)
								computedBackgroundPosition = (((backgroundPositioningAreaDimension - imageDimension)) * 0.);
							}
							;break;
							case 12: case 25: {
								HX_STACK_LINE(182)
								computedBackgroundPosition = (backgroundPositioningAreaDimension - imageDimension);
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(191)
	return computedBackgroundPosition;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(BackgroundStylesComputer_obj,doGetComputedBackgroundPosition,return )

::cocktail::core::geom::DimensionVO BackgroundStylesComputer_obj::getComputedBackgroundSize( ::cocktail::core::css::CSSPropertyValue backgroundSize,::cocktail::core::geom::RectangleVO backgroundPositioningArea,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio){
	HX_STACK_PUSH("BackgroundStylesComputer::getComputedBackgroundSize","cocktail/core/layout/computer/BackgroundStylesComputer.hx",210);
	HX_STACK_ARG(backgroundSize,"backgroundSize");
	HX_STACK_ARG(backgroundPositioningArea,"backgroundPositioningArea");
	HX_STACK_ARG(intrinsicWidth,"intrinsicWidth");
	HX_STACK_ARG(intrinsicHeight,"intrinsicHeight");
	HX_STACK_ARG(intrinsicRatio,"intrinsicRatio");
	HX_STACK_LINE(211)
	::cocktail::core::geom::DimensionVO computedBackgroundSize = ::cocktail::core::geom::DimensionVO_obj::__new(0.0,0.0);		HX_STACK_VAR(computedBackgroundSize,"computedBackgroundSize");
	HX_STACK_LINE(213)
	{
		::cocktail::core::css::CSSPropertyValue _switch_4 = (backgroundSize);
		switch((_switch_4)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_4->__Param(0);
{
					HX_STACK_LINE(215)
					{
						::cocktail::core::css::CSSKeywordValue _switch_5 = (value);
						switch((_switch_5)->GetIndex()){
							case 42: {
								HX_STACK_LINE(221)
								if (((intrinsicRatio != null()))){
									HX_STACK_LINE(224)
									Float ratio = (Float(backgroundPositioningArea->width) / Float(backgroundPositioningArea->height));		HX_STACK_VAR(ratio,"ratio");
									HX_STACK_LINE(228)
									if (((intrinsicRatio < ratio))){
										HX_STACK_LINE(230)
										computedBackgroundSize->height = backgroundPositioningArea->height;
										HX_STACK_LINE(231)
										computedBackgroundSize->width = (backgroundPositioningArea->height * intrinsicRatio);
									}
									else{
										HX_STACK_LINE(235)
										computedBackgroundSize->width = backgroundPositioningArea->width;
										HX_STACK_LINE(236)
										computedBackgroundSize->height = (Float(backgroundPositioningArea->width) / Float(intrinsicRatio));
									}
								}
								else{
									HX_STACK_LINE(241)
									computedBackgroundSize->width = backgroundPositioningArea->width;
									HX_STACK_LINE(242)
									computedBackgroundSize->height = backgroundPositioningArea->height;
								}
							}
							;break;
							case 43: {
								HX_STACK_LINE(248)
								if (((intrinsicRatio != null()))){
									HX_STACK_LINE(251)
									Float ratio = (Float(backgroundPositioningArea->width) / Float(backgroundPositioningArea->height));		HX_STACK_VAR(ratio,"ratio");
									HX_STACK_LINE(255)
									if (((intrinsicRatio > ratio))){
										HX_STACK_LINE(257)
										computedBackgroundSize->height = backgroundPositioningArea->height;
										HX_STACK_LINE(258)
										computedBackgroundSize->width = (backgroundPositioningArea->height * intrinsicRatio);
									}
									else{
										HX_STACK_LINE(262)
										computedBackgroundSize->width = backgroundPositioningArea->width;
										HX_STACK_LINE(263)
										computedBackgroundSize->height = (Float(backgroundPositioningArea->width) / Float(intrinsicRatio));
									}
								}
								else{
									HX_STACK_LINE(268)
									computedBackgroundSize->width = backgroundPositioningArea->width;
									HX_STACK_LINE(269)
									computedBackgroundSize->height = backgroundPositioningArea->height;
								}
							}
							;break;
							case 27: {
								HX_STACK_LINE(274)
								computedBackgroundSize->width = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundPositioningArea->width,backgroundPositioningArea->height,intrinsicWidth,intrinsicHeight,intrinsicRatio);
								HX_STACK_LINE(276)
								computedBackgroundSize->height = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundPositioningArea->height,backgroundPositioningArea->width,intrinsicHeight,intrinsicWidth,intrinsicRatio);
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 18: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(283)
					computedBackgroundSize->width = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(backgroundSize,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundPositioningArea->width,backgroundPositioningArea->height,intrinsicWidth,intrinsicHeight,intrinsicRatio);
					HX_STACK_LINE(285)
					computedBackgroundSize->height = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundSize,backgroundPositioningArea->height,backgroundPositioningArea->width,intrinsicHeight,intrinsicWidth,intrinsicRatio);
				}
			}
			;break;
			case 2: {
				Float value = _switch_4->__Param(0);
{
					HX_STACK_LINE(290)
					computedBackgroundSize->width = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(backgroundSize,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundPositioningArea->width,backgroundPositioningArea->height,intrinsicWidth,intrinsicHeight,intrinsicRatio);
					HX_STACK_LINE(292)
					computedBackgroundSize->height = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()),backgroundSize,backgroundPositioningArea->height,backgroundPositioningArea->width,intrinsicHeight,intrinsicWidth,intrinsicRatio);
				}
			}
			;break;
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_4->__Param(0);
{
					HX_STACK_LINE(297)
					computedBackgroundSize->width = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(value->__get((int)0),value->__get((int)1),backgroundPositioningArea->width,backgroundPositioningArea->height,intrinsicWidth,intrinsicHeight,intrinsicRatio);
					HX_STACK_LINE(299)
					computedBackgroundSize->height = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(value->__get((int)1),value->__get((int)0),backgroundPositioningArea->height,backgroundPositioningArea->width,intrinsicHeight,intrinsicWidth,intrinsicRatio);
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(305)
	return computedBackgroundSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BackgroundStylesComputer_obj,getComputedBackgroundSize,return )

Float BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO( ::cocktail::core::css::CSSPropertyValue backgroundSizeValue,::cocktail::core::css::CSSPropertyValue opositeBackgroundSizeValue,Float backgroundPositioningAreaDimension,Float opositeBackgroundAreaDimension,Dynamic intrinsicDimension,Dynamic opositeIntrinsicDimension,Dynamic intrinsicRatio){
	HX_STACK_PUSH("BackgroundStylesComputer::getBackgroundSizeStyleDimensionVO","cocktail/core/layout/computer/BackgroundStylesComputer.hx",322);
	HX_STACK_ARG(backgroundSizeValue,"backgroundSizeValue");
	HX_STACK_ARG(opositeBackgroundSizeValue,"opositeBackgroundSizeValue");
	HX_STACK_ARG(backgroundPositioningAreaDimension,"backgroundPositioningAreaDimension");
	HX_STACK_ARG(opositeBackgroundAreaDimension,"opositeBackgroundAreaDimension");
	HX_STACK_ARG(intrinsicDimension,"intrinsicDimension");
	HX_STACK_ARG(opositeIntrinsicDimension,"opositeIntrinsicDimension");
	HX_STACK_ARG(intrinsicRatio,"intrinsicRatio");
	HX_STACK_LINE(323)
	Float backgroundSizeStyleDimension = 0.0;		HX_STACK_VAR(backgroundSizeStyleDimension,"backgroundSizeStyleDimension");
	HX_STACK_LINE(325)
	{
		::cocktail::core::css::CSSPropertyValue _switch_6 = (backgroundSizeValue);
		switch((_switch_6)->GetIndex()){
			case 18: {
				Float value = _switch_6->__Param(0);
{
					HX_STACK_LINE(327)
					backgroundSizeStyleDimension = value;
				}
			}
			;break;
			case 2: {
				Float value = _switch_6->__Param(0);
{
					HX_STACK_LINE(331)
					backgroundSizeStyleDimension = (backgroundPositioningAreaDimension * ((value * 0.01)));
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_6->__Param(0);
{
					HX_STACK_LINE(336)
					if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
						HX_STACK_LINE(339)
						bool isOpositeAuto = false;		HX_STACK_VAR(isOpositeAuto,"isOpositeAuto");
						HX_STACK_LINE(340)
						{
							::cocktail::core::css::CSSPropertyValue _switch_7 = (opositeBackgroundSizeValue);
							switch((_switch_7)->GetIndex()){
								case 4: {
									::cocktail::core::css::CSSKeywordValue value1 = _switch_7->__Param(0);
{
										HX_STACK_LINE(342)
										if (((value1 == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
											HX_STACK_LINE(344)
											isOpositeAuto = true;
										}
									}
								}
								;break;
								default: {
								}
							}
						}
						HX_STACK_LINE(351)
						if (((bool((intrinsicDimension != null())) && bool((isOpositeAuto == true))))){
							HX_STACK_LINE(352)
							backgroundSizeStyleDimension = intrinsicDimension;
						}
						else{
							HX_STACK_LINE(357)
							if (((bool((opositeIntrinsicDimension != null())) && bool((intrinsicRatio != null()))))){
								HX_STACK_LINE(359)
								Float opositeDimension = ::cocktail::core::layout::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionVO(opositeBackgroundSizeValue,backgroundSizeValue,opositeBackgroundAreaDimension,backgroundPositioningAreaDimension,opositeIntrinsicDimension,intrinsicDimension,intrinsicRatio);		HX_STACK_VAR(opositeDimension,"opositeDimension");
								HX_STACK_LINE(363)
								backgroundSizeStyleDimension = (opositeDimension * intrinsicRatio);
							}
							else{
								HX_STACK_LINE(367)
								backgroundSizeStyleDimension = backgroundPositioningAreaDimension;
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(376)
	return backgroundSizeStyleDimension;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(BackgroundStylesComputer_obj,getBackgroundSizeStyleDimensionVO,return )

::cocktail::core::geom::RectangleVO BackgroundStylesComputer_obj::getBackgroundPositioningArea( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSPropertyValue backgroundOrigin,::cocktail::core::geom::RectangleVO backgroundBox){
	HX_STACK_PUSH("BackgroundStylesComputer::getBackgroundPositioningArea","cocktail/core/layout/computer/BackgroundStylesComputer.hx",396);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(backgroundOrigin,"backgroundOrigin");
	HX_STACK_ARG(backgroundBox,"backgroundBox");
	HX_STACK_LINE(397)
	Float height = 0.0;		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(398)
	Float width = 0.0;		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(399)
	Float x = 0.0;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(400)
	Float y = 0.0;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(402)
	{
		::cocktail::core::css::CSSPropertyValue _switch_8 = (backgroundOrigin);
		switch((_switch_8)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_8->__Param(0);
{
					HX_STACK_LINE(404)
					{
						::cocktail::core::css::CSSKeywordValue _switch_9 = (value);
						switch((_switch_9)->GetIndex()){
							case 39: {
								HX_STACK_LINE(408)
								height = backgroundBox->height;
								HX_STACK_LINE(409)
								width = backgroundBox->width;
								HX_STACK_LINE(410)
								x = 0.0;
								HX_STACK_LINE(411)
								y = 0.0;
							}
							;break;
							case 40: {
								HX_STACK_LINE(415)
								height = backgroundBox->height;
								HX_STACK_LINE(416)
								width = backgroundBox->width;
								HX_STACK_LINE(417)
								x = 0.0;
								HX_STACK_LINE(418)
								y = 0.0;
							}
							;break;
							case 41: {
								HX_STACK_LINE(422)
								height = ((((((backgroundBox->height - style->usedValues->marginTop) - style->usedValues->marginBottom) - style->usedValues->paddingTop) - style->usedValues->paddingBottom) - style->usedValues->borderTopWidth) - style->usedValues->borderBottomWidth);
								HX_STACK_LINE(423)
								width = ((((((backgroundBox->width - style->usedValues->marginLeft) - style->usedValues->marginRight) - style->usedValues->paddingLeft) - style->usedValues->paddingRight) - style->usedValues->borderLeftWidth) - style->usedValues->borderRightWidth);
								HX_STACK_LINE(424)
								x = 0.0;
								HX_STACK_LINE(425)
								y = 0.0;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(432)
	::cocktail::core::geom::RectangleVO rectangle = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(rectangle,"rectangle");
	HX_STACK_LINE(433)
	rectangle->x = x;
	HX_STACK_LINE(434)
	rectangle->y = y;
	HX_STACK_LINE(435)
	rectangle->width = width;
	HX_STACK_LINE(436)
	rectangle->height = height;
	HX_STACK_LINE(437)
	return rectangle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(BackgroundStylesComputer_obj,getBackgroundPositioningArea,return )

::cocktail::core::geom::RectangleVO BackgroundStylesComputer_obj::getBackgroundPaintingArea( ::cocktail::core::css::CoreStyle style,::cocktail::core::css::CSSPropertyValue backgroundClip,::cocktail::core::geom::RectangleVO backgroundBox){
	HX_STACK_PUSH("BackgroundStylesComputer::getBackgroundPaintingArea","cocktail/core/layout/computer/BackgroundStylesComputer.hx",455);
	HX_STACK_ARG(style,"style");
	HX_STACK_ARG(backgroundClip,"backgroundClip");
	HX_STACK_ARG(backgroundBox,"backgroundBox");
	HX_STACK_LINE(456)
	Float height = 0.0;		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(457)
	Float width = 0.0;		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(458)
	Float x = 0.0;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(459)
	Float y = 0.0;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(461)
	{
		::cocktail::core::css::CSSPropertyValue _switch_10 = (backgroundClip);
		switch((_switch_10)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_10->__Param(0);
{
					HX_STACK_LINE(463)
					{
						::cocktail::core::css::CSSKeywordValue _switch_11 = (value);
						switch((_switch_11)->GetIndex()){
							case 39: {
								HX_STACK_LINE(467)
								height = backgroundBox->height;
								HX_STACK_LINE(468)
								width = backgroundBox->width;
								HX_STACK_LINE(469)
								x = 0.0;
								HX_STACK_LINE(470)
								y = 0.0;
							}
							;break;
							case 40: {
								HX_STACK_LINE(473)
								height = backgroundBox->height;
								HX_STACK_LINE(474)
								width = backgroundBox->width;
								HX_STACK_LINE(475)
								x = style->usedValues->marginLeft;
								HX_STACK_LINE(476)
								y = style->usedValues->marginTop;
							}
							;break;
							case 41: {
								HX_STACK_LINE(480)
								height = ((((((backgroundBox->height - style->usedValues->marginTop) - style->usedValues->marginBottom) - style->usedValues->paddingTop) - style->usedValues->paddingBottom) - style->usedValues->borderTopWidth) - style->usedValues->borderBottomWidth);
								HX_STACK_LINE(481)
								width = ((((((backgroundBox->width - style->usedValues->marginLeft) - style->usedValues->marginRight) - style->usedValues->paddingLeft) - style->usedValues->paddingRight) - style->usedValues->borderLeftWidth) - style->usedValues->borderRightWidth);
								HX_STACK_LINE(482)
								x = ((style->usedValues->marginLeft + style->usedValues->paddingLeft) + style->usedValues->borderLeftWidth);
								HX_STACK_LINE(483)
								y = ((style->usedValues->marginTop + style->usedValues->paddingTop) + style->usedValues->borderTopWidth);
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(491)
	::cocktail::core::geom::RectangleVO rectangle = ::cocktail::core::geom::RectangleVO_obj::__new();		HX_STACK_VAR(rectangle,"rectangle");
	HX_STACK_LINE(492)
	rectangle->x = x;
	HX_STACK_LINE(493)
	rectangle->y = y;
	HX_STACK_LINE(494)
	rectangle->width = width;
	HX_STACK_LINE(495)
	rectangle->height = height;
	HX_STACK_LINE(497)
	return rectangle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(BackgroundStylesComputer_obj,getBackgroundPaintingArea,return )


BackgroundStylesComputer_obj::BackgroundStylesComputer_obj()
{
}

void BackgroundStylesComputer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BackgroundStylesComputer);
	HX_MARK_END_CLASS();
}

void BackgroundStylesComputer_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BackgroundStylesComputer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 25:
		if (HX_FIELD_EQ(inName,"getComputedBackgroundSize") ) { return getComputedBackgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundPaintingArea") ) { return getBackgroundPaintingArea_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"computeIndividualBackground") ) { return computeIndividualBackground_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getBackgroundPositioningArea") ) { return getBackgroundPositioningArea_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"getComputedBackgroundPosition") ) { return getComputedBackgroundPosition_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"doGetComputedBackgroundPosition") ) { return doGetComputedBackgroundPosition_dyn(); }
		break;
	case 33:
		if (HX_FIELD_EQ(inName,"getBackgroundSizeStyleDimensionVO") ) { return getBackgroundSizeStyleDimensionVO_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BackgroundStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BackgroundStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("computeIndividualBackground"),
	HX_CSTRING("getComputedBackgroundPosition"),
	HX_CSTRING("doGetComputedBackgroundPosition"),
	HX_CSTRING("getComputedBackgroundSize"),
	HX_CSTRING("getBackgroundSizeStyleDimensionVO"),
	HX_CSTRING("getBackgroundPositioningArea"),
	HX_CSTRING("getBackgroundPaintingArea"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BackgroundStylesComputer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BackgroundStylesComputer_obj::__mClass,"__mClass");
};

Class BackgroundStylesComputer_obj::__mClass;

void BackgroundStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.layout.computer.BackgroundStylesComputer"), hx::TCanCast< BackgroundStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BackgroundStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace layout
} // end namespace computer
