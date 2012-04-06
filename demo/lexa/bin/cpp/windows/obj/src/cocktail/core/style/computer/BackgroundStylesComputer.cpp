#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundClip
#include <cocktail/core/style/BackgroundClip.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundImage
#include <cocktail/core/style/BackgroundImage.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundOrigin
#include <cocktail/core/style/BackgroundOrigin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundPositionX
#include <cocktail/core/style/BackgroundPositionX.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundPositionY
#include <cocktail/core/style/BackgroundPositionY.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSizeDimension
#include <cocktail/core/style/BackgroundSizeDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_computer_BackgroundStylesComputer
#include <cocktail/core/style/computer/BackgroundStylesComputer.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
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

Void BackgroundStylesComputer_obj::__construct()
{
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

Void BackgroundStylesComputer_obj::compute( ::cocktail::core::style::CoreStyle style){
{
		HX_SOURCE_PUSH("BackgroundStylesComputer_obj::compute")
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",63)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundColor")) = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getComputedBackgroundColor(style);
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",65)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundRepeat")) = style->getBackgroundRepeat();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",67)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundClip")) = style->getBackgroundClip();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",69)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundSize")) = style->getBackgroundSize();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",71)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundPosition")) = style->getBackgroundPosition();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",73)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundOrigin")) = style->getBackgroundOrigin();
		HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",75)
		style->getComputedStyle()->__FieldRef(HX_CSTRING("backgroundImage")) = style->getBackgroundImage();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundStylesComputer_obj,compute,(void))

Dynamic BackgroundStylesComputer_obj::computeIndividualBackground( ::cocktail::core::style::CoreStyle style,Dynamic backgroundBox,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,Dynamic backgroundPosition,::cocktail::core::style::BackgroundSize backgroundSize,::cocktail::core::style::BackgroundOrigin backgroundOrigin,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundRepeat,::cocktail::core::style::BackgroundImage backgroundImage){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::computeIndividualBackground")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",112)
	Dynamic backgroundPositioningArea = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getBackgroundPositioningArea(style,backgroundOrigin,backgroundBox);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",115)
	Dynamic computedBackgroundSize = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getComputedBackgroundSize(backgroundSize,backgroundPositioningArea,intrinsicWidth,intrinsicHeight,intrinsicRatio,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",119)
	Dynamic computedBackgroundPosition = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getComputedBackgroundPosition(backgroundPosition,backgroundPositioningArea,computedBackgroundSize,style->getFontMetricsData()->__Field(HX_CSTRING("fontSize")),style->getFontMetricsData()->__Field(HX_CSTRING("xHeight")));
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",123)
	Dynamic computedBackgroundClip = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getBackgroundPaintingArea(style,backgroundClip,backgroundBox);
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &backgroundRepeat,::cocktail::core::style::BackgroundImage &backgroundImage,Dynamic &computedBackgroundSize,Dynamic &backgroundPositioningArea,Dynamic &computedBackgroundClip,Dynamic &computedBackgroundPosition){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("backgroundOrigin") , backgroundPositioningArea,false);
			__result->Add(HX_CSTRING("backgroundClip") , computedBackgroundClip,false);
			__result->Add(HX_CSTRING("backgroundRepeat") , backgroundRepeat,false);
			__result->Add(HX_CSTRING("backgroundImage") , backgroundImage,false);
			__result->Add(HX_CSTRING("backgroundSize") , computedBackgroundSize,false);
			__result->Add(HX_CSTRING("backgroundPosition") , computedBackgroundPosition,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",125)
	Dynamic computedBackgroundStyle = _Function_1_1::Block(backgroundRepeat,backgroundImage,computedBackgroundSize,backgroundPositioningArea,computedBackgroundClip,computedBackgroundPosition);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",134)
	return computedBackgroundStyle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC11(BackgroundStylesComputer_obj,computeIndividualBackground,return )

Dynamic BackgroundStylesComputer_obj::getComputedBackgroundColor( ::cocktail::core::style::CoreStyle style){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getComputedBackgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",149)
	Dynamic computedColor;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",150)
	computedColor = ::cocktail::core::unit::UnitManager_obj::getColorDataFromCSSColor(style->getBackgroundColor());
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",152)
	return computedColor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BackgroundStylesComputer_obj,getComputedBackgroundColor,return )

Dynamic BackgroundStylesComputer_obj::getComputedBackgroundPosition( Dynamic backgroundPosition,Dynamic backgroundPositioningArea,Dynamic computedBackgroundSize,double emReference,double exReference){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getComputedBackgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",171)
	double computedBackgroundXPosition = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getComputedBackgroundXPosition(backgroundPosition->__Field(HX_CSTRING("x")),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("width"))),computedBackgroundSize->__Field(HX_CSTRING("width")),emReference,exReference);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",172)
	double computedBackgroundYPosition = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getComputedBackgroundYPosition(backgroundPosition->__Field(HX_CSTRING("y")),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("height"))),computedBackgroundSize->__Field(HX_CSTRING("height")),emReference,exReference);
	struct _Function_1_1{
		inline static Dynamic Block( double &computedBackgroundXPosition,double &computedBackgroundYPosition){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("x") , computedBackgroundXPosition,false);
			__result->Add(HX_CSTRING("y") , computedBackgroundYPosition,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",174)
	Dynamic computedBackgroundPosition = _Function_1_1::Block(computedBackgroundXPosition,computedBackgroundYPosition);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",178)
	return computedBackgroundPosition;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BackgroundStylesComputer_obj,getComputedBackgroundPosition,return )

int BackgroundStylesComputer_obj::getComputedBackgroundXPosition( ::cocktail::core::style::BackgroundPositionX backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getComputedBackgroundXPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",186)
	int computedBackgroundXPosition;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",188)
	{
::cocktail::core::style::BackgroundPositionX _switch_1 = (backgroundPosition);
		switch((_switch_1)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",190)
					computedBackgroundXPosition = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,emReference,exReference);
				}
			}
			;break;
			case 1: {
				int value = _switch_1->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",196)
					computedBackgroundXPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,(backgroundPositioningAreaDimension - imageDimension)));
				}
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",200)
				computedBackgroundXPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)50,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",204)
				computedBackgroundXPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)0,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",208)
				computedBackgroundXPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)100,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",212)
	return computedBackgroundXPosition;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BackgroundStylesComputer_obj,getComputedBackgroundXPosition,return )

int BackgroundStylesComputer_obj::getComputedBackgroundYPosition( ::cocktail::core::style::BackgroundPositionY backgroundPosition,int backgroundPositioningAreaDimension,int imageDimension,double emReference,double exReference){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getComputedBackgroundYPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",220)
	int computedBackgroundYPosition;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",222)
	{
::cocktail::core::style::BackgroundPositionY _switch_2 = (backgroundPosition);
		switch((_switch_2)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",224)
					computedBackgroundYPosition = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value,emReference,exReference);
				}
			}
			;break;
			case 1: {
				int value = _switch_2->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",227)
					computedBackgroundYPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value,(backgroundPositioningAreaDimension - imageDimension)));
				}
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",230)
				computedBackgroundYPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)50,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",233)
				computedBackgroundYPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)0,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",236)
				computedBackgroundYPosition = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)100,(backgroundPositioningAreaDimension - imageDimension)));
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",240)
	return computedBackgroundYPosition;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(BackgroundStylesComputer_obj,getComputedBackgroundYPosition,return )

Dynamic BackgroundStylesComputer_obj::getComputedBackgroundSize( ::cocktail::core::style::BackgroundSize backgroundSize,Dynamic backgroundPositioningArea,Dynamic intrinsicWidth,Dynamic intrinsicHeight,Dynamic intrinsicRatio,double emReference,double exReference){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getComputedBackgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",262)
	Dynamic computedBackgroundSize;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",264)
	{
::cocktail::core::style::BackgroundSize _switch_3 = (backgroundSize);
		switch((_switch_3)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",269)
				if (((intrinsicRatio != null()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",272)
					double ratio = (double(intrinsicRatio) / double(((double(backgroundPositioningArea->__Field(HX_CSTRING("width"))) / double(backgroundPositioningArea->__Field(HX_CSTRING("height")))))));
					struct _Function_3_1{
						inline static Dynamic Block( Dynamic &intrinsicHeight,Dynamic &intrinsicWidth,double &ratio){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("width") , ::Math_obj::round((intrinsicWidth * ratio)),false);
							__result->Add(HX_CSTRING("height") , ::Math_obj::round((intrinsicHeight * ratio)),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",274)
					computedBackgroundSize = _Function_3_1::Block(intrinsicHeight,intrinsicWidth,ratio);
				}
				else{
					struct _Function_3_1{
						inline static Dynamic Block( Dynamic &backgroundPositioningArea){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("width") , ::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("width"))),false);
							__result->Add(HX_CSTRING("height") , ::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("height"))),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",280)
					computedBackgroundSize = _Function_3_1::Block(backgroundPositioningArea);
				}
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",290)
				if (((intrinsicRatio != null()))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",293)
					double ratio = (double((double(backgroundPositioningArea->__Field(HX_CSTRING("width"))) / double(backgroundPositioningArea->__Field(HX_CSTRING("height"))))) / double(intrinsicRatio));
					struct _Function_3_1{
						inline static Dynamic Block( Dynamic &intrinsicHeight,Dynamic &intrinsicWidth,double &ratio){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("width") , ::Math_obj::round((intrinsicWidth * ratio)),false);
							__result->Add(HX_CSTRING("height") , ::Math_obj::round((intrinsicHeight * ratio)),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",295)
					computedBackgroundSize = _Function_3_1::Block(intrinsicHeight,intrinsicWidth,ratio);
				}
				else{
					struct _Function_3_1{
						inline static Dynamic Block( Dynamic &backgroundPositioningArea){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("width") , ::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("width"))),false);
							__result->Add(HX_CSTRING("height") , ::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("height"))),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",301)
					computedBackgroundSize = _Function_3_1::Block(backgroundPositioningArea);
				}
			}
			;break;
			case 2: {
				Dynamic value = _switch_3->__Param(0);
{
					struct _Function_2_1{
						inline static Dynamic Block( double &exReference,double &emReference,Dynamic &value,Dynamic &intrinsicWidth,Dynamic &intrinsicRatio,Dynamic &backgroundPositioningArea,Dynamic &intrinsicHeight){
							hx::Anon __result = hx::Anon_obj::Create();
							__result->Add(HX_CSTRING("width") , ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionData(value->__Field(HX_CSTRING("x")),value->__Field(HX_CSTRING("y")),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("width"))),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("height"))),intrinsicWidth,intrinsicHeight,intrinsicRatio,emReference,exReference),false);
							__result->Add(HX_CSTRING("height") , ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionData(value->__Field(HX_CSTRING("y")),value->__Field(HX_CSTRING("x")),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("height"))),::Math_obj::round(backgroundPositioningArea->__Field(HX_CSTRING("width"))),intrinsicHeight,intrinsicWidth,intrinsicRatio,emReference,exReference),false);
							return __result;
						}
					};
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",309)
					computedBackgroundSize = _Function_2_1::Block(exReference,emReference,value,intrinsicWidth,intrinsicRatio,backgroundPositioningArea,intrinsicHeight);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",318)
	return computedBackgroundSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(BackgroundStylesComputer_obj,getComputedBackgroundSize,return )

int BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionData( ::cocktail::core::style::BackgroundSizeDimension value,::cocktail::core::style::BackgroundSizeDimension opositeBackgroundSizeValue,int backgroundPositioningAreaDimension,int opositeBackgroundAreaDimension,Dynamic intrinsicDimension,Dynamic opositeIntrinsicDimension,Dynamic intrinsicRatio,double emReference,double exReference){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionData")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",339)
	int backgroundSizeStyleDimension;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",341)
	{
::cocktail::core::style::BackgroundSizeDimension _switch_4 = (value);
		switch((_switch_4)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",344)
					backgroundSizeStyleDimension = ::cocktail::core::unit::UnitManager_obj::getPixelFromLength(value1,emReference,exReference);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_4->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",348)
					backgroundSizeStyleDimension = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent(value1,backgroundPositioningAreaDimension));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",353)
				if (((bool((intrinsicDimension != null())) && bool((opositeBackgroundSizeValue == ::cocktail::core::style::BackgroundSizeDimension_obj::cssAuto_dyn()))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",356)
					backgroundSizeStyleDimension = intrinsicDimension;
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",361)
					if (((bool((opositeIntrinsicDimension != null())) && bool((intrinsicRatio != null()))))){
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",363)
						int opositeDimension = ::cocktail::core::style::computer::BackgroundStylesComputer_obj::getBackgroundSizeStyleDimensionData(opositeBackgroundSizeValue,value,opositeBackgroundAreaDimension,backgroundPositioningAreaDimension,opositeIntrinsicDimension,intrinsicDimension,intrinsicRatio,emReference,exReference);
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",367)
						backgroundSizeStyleDimension = ::Math_obj::round((opositeDimension * intrinsicRatio));
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",371)
						backgroundSizeStyleDimension = ::Math_obj::round(::cocktail::core::unit::UnitManager_obj::getPixelFromPercent((int)100,backgroundPositioningAreaDimension));
					}
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",376)
	return backgroundSizeStyleDimension;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(BackgroundStylesComputer_obj,getBackgroundSizeStyleDimensionData,return )

Dynamic BackgroundStylesComputer_obj::getBackgroundPositioningArea( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::BackgroundOrigin backgroundOrigin,Dynamic backgroundBox){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getBackgroundPositioningArea")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",397)
	Dynamic backgroundPositioningArea;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",399)
	double height;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",400)
	double width;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",401)
	double x;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",402)
	double y;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",404)
	{
::cocktail::core::style::BackgroundOrigin _switch_5 = (backgroundOrigin);
		switch((_switch_5)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",408)
				height = backgroundBox->__Field(HX_CSTRING("height"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",409)
				width = backgroundBox->__Field(HX_CSTRING("width"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",410)
				x = 0.0;
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",411)
				y = 0.0;
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",415)
				height = backgroundBox->__Field(HX_CSTRING("height"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",416)
				width = backgroundBox->__Field(HX_CSTRING("width"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",417)
				x = style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",418)
				y = style->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",422)
				height = ((((backgroundBox->__Field(HX_CSTRING("height")) - style->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginBottom"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",423)
				width = ((((backgroundBox->__Field(HX_CSTRING("width")) - style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginRight"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingRight")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",424)
				x = (style->getComputedStyle()->__Field(HX_CSTRING("marginLeft")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",425)
				y = (style->getComputedStyle()->__Field(HX_CSTRING("marginTop")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
			}
			;break;
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( double &width,double &y,double &height,double &x){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("height") , height,false);
			__result->Add(HX_CSTRING("width") , width,false);
			__result->Add(HX_CSTRING("x") , x,false);
			__result->Add(HX_CSTRING("y") , y,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",429)
	backgroundPositioningArea = _Function_1_1::Block(width,y,height,x);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",436)
	return backgroundPositioningArea;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(BackgroundStylesComputer_obj,getBackgroundPositioningArea,return )

Dynamic BackgroundStylesComputer_obj::getBackgroundPaintingArea( ::cocktail::core::style::CoreStyle style,::cocktail::core::style::BackgroundClip backgroundClip,Dynamic backgroundBox){
	HX_SOURCE_PUSH("BackgroundStylesComputer_obj::getBackgroundPaintingArea")
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",455)
	Dynamic backgroundPaintingArea;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",457)
	double height;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",458)
	double width;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",459)
	double x;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",460)
	double y;
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",462)
	{
::cocktail::core::style::BackgroundClip _switch_6 = (backgroundClip);
		switch((_switch_6)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",465)
				height = backgroundBox->__Field(HX_CSTRING("height"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",466)
				width = backgroundBox->__Field(HX_CSTRING("width"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",467)
				x = 0.0;
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",468)
				y = 0.0;
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",471)
				height = backgroundBox->__Field(HX_CSTRING("height"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",472)
				width = backgroundBox->__Field(HX_CSTRING("width"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",473)
				x = style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",474)
				y = style->getComputedStyle()->__Field(HX_CSTRING("marginTop"));
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",478)
				height = ((((backgroundBox->__Field(HX_CSTRING("height")) - style->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginBottom"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingBottom")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",479)
				width = ((((backgroundBox->__Field(HX_CSTRING("width")) - style->getComputedStyle()->__Field(HX_CSTRING("marginLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("marginRight"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"))) - style->getComputedStyle()->__Field(HX_CSTRING("paddingRight")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",480)
				x = (style->getComputedStyle()->__Field(HX_CSTRING("marginLeft")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingLeft")));
				HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",481)
				y = (style->getComputedStyle()->__Field(HX_CSTRING("marginTop")) + style->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
			}
			;break;
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( double &width,double &y,double &height,double &x){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("height") , height,false);
			__result->Add(HX_CSTRING("width") , width,false);
			__result->Add(HX_CSTRING("x") , x,false);
			__result->Add(HX_CSTRING("y") , y,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",485)
	backgroundPaintingArea = _Function_1_1::Block(width,y,height,x);
	HX_SOURCE_POS("../../src/cocktail/core/style/computer/BackgroundStylesComputer.hx",492)
	return backgroundPaintingArea;
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

Dynamic BackgroundStylesComputer_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"compute") ) { return compute_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getComputedBackgroundSize") ) { return getComputedBackgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getBackgroundPaintingArea") ) { return getBackgroundPaintingArea_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getComputedBackgroundColor") ) { return getComputedBackgroundColor_dyn(); }
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
	case 30:
		if (HX_FIELD_EQ(inName,"getComputedBackgroundXPosition") ) { return getComputedBackgroundXPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getComputedBackgroundYPosition") ) { return getComputedBackgroundYPosition_dyn(); }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"getBackgroundSizeStyleDimensionData") ) { return getBackgroundSizeStyleDimensionData_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BackgroundStylesComputer_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void BackgroundStylesComputer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("compute"),
	HX_CSTRING("computeIndividualBackground"),
	HX_CSTRING("getComputedBackgroundColor"),
	HX_CSTRING("getComputedBackgroundPosition"),
	HX_CSTRING("getComputedBackgroundXPosition"),
	HX_CSTRING("getComputedBackgroundYPosition"),
	HX_CSTRING("getComputedBackgroundSize"),
	HX_CSTRING("getBackgroundSizeStyleDimensionData"),
	HX_CSTRING("getBackgroundPositioningArea"),
	HX_CSTRING("getBackgroundPaintingArea"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class BackgroundStylesComputer_obj::__mClass;

void BackgroundStylesComputer_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.computer.BackgroundStylesComputer"), hx::TCanCast< BackgroundStylesComputer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BackgroundStylesComputer_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace computer
