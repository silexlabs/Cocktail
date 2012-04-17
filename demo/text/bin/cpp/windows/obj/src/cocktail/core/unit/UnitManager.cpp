#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
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
#ifndef INCLUDED_cocktail_core_style_BackgroundRepeatValue
#include <cocktail/core/style/BackgroundRepeatValue.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_BackgroundSizeDimension
#include <cocktail/core/style/BackgroundSizeDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CSSFloat
#include <cocktail/core/style/CSSFloat.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Clear
#include <cocktail/core/style/Clear.h>
#endif
#ifndef INCLUDED_cocktail_core_style_ConstrainedDimension
#include <cocktail/core/style/ConstrainedDimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Cursor
#include <cocktail/core/style/Cursor.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Dimension
#include <cocktail/core/style/Dimension.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Display
#include <cocktail/core/style/Display.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontSize
#include <cocktail/core/style/FontSize.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontStyle
#include <cocktail/core/style/FontStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontVariant
#include <cocktail/core/style/FontVariant.h>
#endif
#ifndef INCLUDED_cocktail_core_style_FontWeight
#include <cocktail/core/style/FontWeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LetterSpacing
#include <cocktail/core/style/LetterSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_style_LineHeight
#include <cocktail/core/style/LineHeight.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Margin
#include <cocktail/core/style/Margin.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Overflow
#include <cocktail/core/style/Overflow.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Padding
#include <cocktail/core/style/Padding.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Position
#include <cocktail/core/style/Position.h>
#endif
#ifndef INCLUDED_cocktail_core_style_PositionOffset
#include <cocktail/core/style/PositionOffset.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextAlign
#include <cocktail/core/style/TextAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextIndent
#include <cocktail/core/style/TextIndent.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextTransform
#include <cocktail/core/style/TextTransform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Transform
#include <cocktail/core/style/Transform.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformFunction
#include <cocktail/core/style/TransformFunction.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginX
#include <cocktail/core/style/TransformOriginX.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TransformOriginY
#include <cocktail/core/style/TransformOriginY.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Translation
#include <cocktail/core/style/Translation.h>
#endif
#ifndef INCLUDED_cocktail_core_style_VerticalAlign
#include <cocktail/core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_Visibility
#include <cocktail/core/style/Visibility.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WhiteSpace
#include <cocktail/core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WordSpacing
#include <cocktail/core/style/WordSpacing.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Angle
#include <cocktail/core/unit/Angle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ColorKeyword
#include <cocktail/core/unit/ColorKeyword.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeAbsoluteSize
#include <cocktail/core/unit/FontSizeAbsoluteSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_FontSizeRelativeSize
#include <cocktail/core/unit/FontSizeRelativeSize.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientAngle
#include <cocktail/core/unit/GradientAngle.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientCornerValue
#include <cocktail/core/unit/GradientCornerValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientSideValue
#include <cocktail/core/unit/GradientSideValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientStopValue
#include <cocktail/core/unit/GradientStopValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_GradientValue
#include <cocktail/core/unit/GradientValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_ImageValue
#include <cocktail/core/unit/ImageValue.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_Length
#include <cocktail/core/unit/Length.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
namespace cocktail{
namespace core{
namespace unit{

Void UnitManager_obj::__construct()
{
{
}
;
	return null();
}

UnitManager_obj::~UnitManager_obj() { }

Dynamic UnitManager_obj::__CreateEmpty() { return  new UnitManager_obj; }
hx::ObjectPtr< UnitManager_obj > UnitManager_obj::__new()
{  hx::ObjectPtr< UnitManager_obj > result = new UnitManager_obj();
	result->__construct();
	return result;}

Dynamic UnitManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UnitManager_obj > result = new UnitManager_obj();
	result->__construct();
	return result;}

Dynamic UnitManager_obj::boxStyleEnum( ::Enum enumType,::String string){
	HX_SOURCE_PUSH("UnitManager_obj::boxStyleEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",41)
	if (((string == HX_CSTRING("auto")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",42)
		return ::Type_obj::createEnum(enumType,HX_CSTRING("cssAuto"),null());
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",45)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	struct _Function_1_1{
		inline static Dynamic Block( Dynamic &parsed,::Enum &enumType){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",47)
			::String _switch_1 = (parsed->__Field(HX_CSTRING("unit")));
			if (  ( _switch_1==HX_CSTRING("%"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",48)
				return ::Type_obj::createEnum(enumType,HX_CSTRING("percent"),Array_obj< Dynamic >::__new().Add(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value")))));
			}
			else  {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",50)
				return ::Type_obj::createEnum(enumType,HX_CSTRING("length"),Array_obj< ::cocktail::core::unit::Length >::__new().Add(::cocktail::core::unit::UnitManager_obj::string2Length(parsed)));
			}
;
;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",47)
	return _Function_1_1::Block(parsed,enumType);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,boxStyleEnum,return )

::cocktail::core::style::ConstrainedDimension UnitManager_obj::constrainedDimensionEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::constrainedDimensionEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",58)
	if (((string == HX_CSTRING("none")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",59)
		return ::cocktail::core::style::ConstrainedDimension_obj::none_dyn();
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",61)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",62)
	::cocktail::core::style::ConstrainedDimension constrainedDimension;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",64)
	::String _switch_2 = (parsed->__Field(HX_CSTRING("unit")));
	if (  ( _switch_2==HX_CSTRING("%"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",66)
		constrainedDimension = ::cocktail::core::style::ConstrainedDimension_obj::percent(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",69)
		constrainedDimension = ::cocktail::core::style::ConstrainedDimension_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",73)
	return constrainedDimension;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,constrainedDimensionEnum,return )

::cocktail::core::style::Display UnitManager_obj::displayEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::displayEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",78)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",80)
	::cocktail::core::style::Display display;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",82)
	::String _switch_3 = (parsed);
	if (  ( _switch_3==HX_CSTRING("inline"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",84)
		display = ::cocktail::core::style::Display_obj::cssInline_dyn();
	}
	else if (  ( _switch_3==HX_CSTRING("block"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",87)
		display = ::cocktail::core::style::Display_obj::block_dyn();
	}
	else if (  ( _switch_3==HX_CSTRING("inline-block"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",90)
		display = ::cocktail::core::style::Display_obj::inlineBlock_dyn();
	}
	else if (  ( _switch_3==HX_CSTRING("none"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",93)
		display = ::cocktail::core::style::Display_obj::none_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",96)
		display = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",101)
	return display;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,displayEnum,return )

::cocktail::core::style::Overflow UnitManager_obj::overflowEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::overflowEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",106)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",108)
	::cocktail::core::style::Overflow overflow;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",110)
	::String _switch_4 = (parsed);
	if (  ( _switch_4==HX_CSTRING("visible"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",112)
		overflow = ::cocktail::core::style::Overflow_obj::visible_dyn();
	}
	else if (  ( _switch_4==HX_CSTRING("scroll"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",115)
		overflow = ::cocktail::core::style::Overflow_obj::scroll_dyn();
	}
	else if (  ( _switch_4==HX_CSTRING("auto"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",118)
		overflow = ::cocktail::core::style::Overflow_obj::cssAuto_dyn();
	}
	else if (  ( _switch_4==HX_CSTRING("hidden"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",121)
		overflow = ::cocktail::core::style::Overflow_obj::hidden_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",124)
		overflow = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",129)
	return overflow;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,overflowEnum,return )

::cocktail::core::style::VerticalAlign UnitManager_obj::verticalAlignEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::verticalAlignEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",134)
	string = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",136)
	::cocktail::core::style::VerticalAlign verticalAlign;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",138)
	::String _switch_5 = (string);
	if (  ( _switch_5==HX_CSTRING("baseline"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",140)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::baseline_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("bottom"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",143)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::bottom_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("super"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",146)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::cssSuper_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("middle"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",149)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::middle_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("top"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",152)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::top_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("textBottom"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",155)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::textBottom_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("textTop"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",158)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::textTop_dyn();
	}
	else if (  ( _switch_5==HX_CSTRING("sub"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",161)
		verticalAlign = ::cocktail::core::style::VerticalAlign_obj::sub_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",164)
		verticalAlign = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",169)
	if (((verticalAlign == null()))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",171)
		Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",173)
		::String _switch_6 = (parsed->__Field(HX_CSTRING("unit")));
		if (  ( _switch_6==HX_CSTRING("%"))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",175)
			verticalAlign = ::cocktail::core::style::VerticalAlign_obj::percent(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
		}
		else  {
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",178)
			verticalAlign = ::cocktail::core::style::VerticalAlign_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
		}
;
;
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",183)
	return verticalAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,verticalAlignEnum,return )

::cocktail::core::style::Clear UnitManager_obj::clearEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::clearEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",188)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",190)
	::cocktail::core::style::Clear clear;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",192)
	::String _switch_7 = (parsed);
	if (  ( _switch_7==HX_CSTRING("both"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",194)
		clear = ::cocktail::core::style::Clear_obj::both_dyn();
	}
	else if (  ( _switch_7==HX_CSTRING("left"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",197)
		clear = ::cocktail::core::style::Clear_obj::left_dyn();
	}
	else if (  ( _switch_7==HX_CSTRING("right"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",200)
		clear = ::cocktail::core::style::Clear_obj::right_dyn();
	}
	else if (  ( _switch_7==HX_CSTRING("none"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",203)
		clear = ::cocktail::core::style::Clear_obj::none_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",206)
		clear = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",211)
	return clear;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,clearEnum,return )

::cocktail::core::style::Position UnitManager_obj::positionEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::positionEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",216)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",218)
	::cocktail::core::style::Position position;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",220)
	::String _switch_8 = (parsed);
	if (  ( _switch_8==HX_CSTRING("static"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",222)
		position = ::cocktail::core::style::Position_obj::cssStatic_dyn();
	}
	else if (  ( _switch_8==HX_CSTRING("absolute"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",225)
		position = ::cocktail::core::style::Position_obj::absolute_dyn();
	}
	else if (  ( _switch_8==HX_CSTRING("relative"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",228)
		position = ::cocktail::core::style::Position_obj::relative_dyn();
	}
	else if (  ( _switch_8==HX_CSTRING("fixed"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",231)
		position = ::cocktail::core::style::Position_obj::fixed_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",234)
		position = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",239)
	return position;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,positionEnum,return )

::cocktail::core::style::WhiteSpace UnitManager_obj::whiteSpaceEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::whiteSpaceEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",244)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",246)
	::cocktail::core::style::WhiteSpace whiteSpace;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",248)
	::String _switch_9 = (parsed);
	if (  ( _switch_9==HX_CSTRING("normal"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",250)
		whiteSpace = ::cocktail::core::style::WhiteSpace_obj::normal_dyn();
	}
	else if (  ( _switch_9==HX_CSTRING("nowrap"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",253)
		whiteSpace = ::cocktail::core::style::WhiteSpace_obj::nowrap_dyn();
	}
	else if (  ( _switch_9==HX_CSTRING("pre"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",256)
		whiteSpace = ::cocktail::core::style::WhiteSpace_obj::pre_dyn();
	}
	else if (  ( _switch_9==HX_CSTRING("preLine"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",259)
		whiteSpace = ::cocktail::core::style::WhiteSpace_obj::preLine_dyn();
	}
	else if (  ( _switch_9==HX_CSTRING("preWrap"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",262)
		whiteSpace = ::cocktail::core::style::WhiteSpace_obj::preWrap_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",265)
		whiteSpace = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",270)
	return whiteSpace;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,whiteSpaceEnum,return )

::cocktail::core::style::TextAlign UnitManager_obj::textAlignEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::textAlignEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",275)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",277)
	::cocktail::core::style::TextAlign textAlign;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",279)
	::String _switch_10 = (parsed);
	if (  ( _switch_10==HX_CSTRING("left"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",281)
		textAlign = ::cocktail::core::style::TextAlign_obj::left_dyn();
	}
	else if (  ( _switch_10==HX_CSTRING("right"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",284)
		textAlign = ::cocktail::core::style::TextAlign_obj::right_dyn();
	}
	else if (  ( _switch_10==HX_CSTRING("center"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",287)
		textAlign = ::cocktail::core::style::TextAlign_obj::center_dyn();
	}
	else if (  ( _switch_10==HX_CSTRING("justify"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",290)
		textAlign = ::cocktail::core::style::TextAlign_obj::justify_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",293)
		textAlign = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",298)
	return textAlign;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,textAlignEnum,return )

::cocktail::core::style::FontWeight UnitManager_obj::fontWeightEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::fontWeightEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",303)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",305)
	::cocktail::core::style::FontWeight fontWeight;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",307)
	::String _switch_11 = (parsed);
	if (  ( _switch_11==HX_CSTRING("bold"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",309)
		fontWeight = ::cocktail::core::style::FontWeight_obj::bold_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("bolder"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",312)
		fontWeight = ::cocktail::core::style::FontWeight_obj::bolder_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("normal"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",315)
		fontWeight = ::cocktail::core::style::FontWeight_obj::normal_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("lighter"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",318)
		fontWeight = ::cocktail::core::style::FontWeight_obj::lighter_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("100"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",321)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css100_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("200"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",324)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css200_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("300"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",327)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css300_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("400"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",330)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css400_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("500"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",333)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css500_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("600"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",336)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css600_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("700"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",339)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css700_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("800"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",342)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css800_dyn();
	}
	else if (  ( _switch_11==HX_CSTRING("900"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",345)
		fontWeight = ::cocktail::core::style::FontWeight_obj::css900_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",348)
		fontWeight = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",353)
	return fontWeight;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,fontWeightEnum,return )

::cocktail::core::style::FontStyle UnitManager_obj::fontStyleEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::fontStyleEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",358)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",360)
	::cocktail::core::style::FontStyle fontStyle;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",362)
	::String _switch_12 = (parsed);
	if (  ( _switch_12==HX_CSTRING("italic"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",364)
		fontStyle = ::cocktail::core::style::FontStyle_obj::italic_dyn();
	}
	else if (  ( _switch_12==HX_CSTRING("normal"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",367)
		fontStyle = ::cocktail::core::style::FontStyle_obj::normal_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",370)
		fontStyle = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",375)
	return fontStyle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,fontStyleEnum,return )

::cocktail::core::style::FontVariant UnitManager_obj::fontVariantEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::fontVariantEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",380)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",382)
	::cocktail::core::style::FontVariant fontVariant;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",384)
	::String _switch_13 = (parsed);
	if (  ( _switch_13==HX_CSTRING("normal"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",386)
		fontVariant = ::cocktail::core::style::FontVariant_obj::normal_dyn();
	}
	else if (  ( _switch_13==HX_CSTRING("small-caps"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",389)
		fontVariant = ::cocktail::core::style::FontVariant_obj::smallCaps_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",392)
		fontVariant = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",397)
	return fontVariant;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,fontVariantEnum,return )

::cocktail::core::style::TextTransform UnitManager_obj::textTransformEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::textTransformEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",402)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",404)
	::cocktail::core::style::TextTransform textTransform;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",406)
	::String _switch_14 = (parsed);
	if (  ( _switch_14==HX_CSTRING("capitalize"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",408)
		textTransform = ::cocktail::core::style::TextTransform_obj::capitalize_dyn();
	}
	else if (  ( _switch_14==HX_CSTRING("lowercase"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",411)
		textTransform = ::cocktail::core::style::TextTransform_obj::lowercase_dyn();
	}
	else if (  ( _switch_14==HX_CSTRING("uppercase"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",414)
		textTransform = ::cocktail::core::style::TextTransform_obj::uppercase_dyn();
	}
	else if (  ( _switch_14==HX_CSTRING("none"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",417)
		textTransform = ::cocktail::core::style::TextTransform_obj::none_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",420)
		textTransform = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",425)
	return textTransform;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,textTransformEnum,return )

::cocktail::core::style::Visibility UnitManager_obj::visibilityEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::visibilityEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",431)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",433)
	::cocktail::core::style::Visibility visibility;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",435)
	::String _switch_15 = (parsed);
	if (  ( _switch_15==HX_CSTRING("hidden"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",437)
		visibility = ::cocktail::core::style::Visibility_obj::hidden_dyn();
	}
	else if (  ( _switch_15==HX_CSTRING("visible"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",440)
		visibility = ::cocktail::core::style::Visibility_obj::visible_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",443)
		visibility = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",448)
	return visibility;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,visibilityEnum,return )

::cocktail::core::style::Cursor UnitManager_obj::cursorEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::cursorEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",453)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",455)
	::cocktail::core::style::Cursor cursor;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",457)
	::String _switch_16 = (parsed);
	if (  ( _switch_16==HX_CSTRING("auto"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",459)
		cursor = ::cocktail::core::style::Cursor_obj::cssAuto_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("crosshair"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",462)
		cursor = ::cocktail::core::style::Cursor_obj::crosshair_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("pointer"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",465)
		cursor = ::cocktail::core::style::Cursor_obj::pointer_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("default"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",468)
		cursor = ::cocktail::core::style::Cursor_obj::cssDefault_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",471)
		cursor = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",476)
	return cursor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,cursorEnum,return )

::cocktail::core::style::WordSpacing UnitManager_obj::wordSpacingEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::wordSpacingEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",481)
	if (((string == HX_CSTRING("normal")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",482)
		return ::cocktail::core::style::WordSpacing_obj::normal_dyn();
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",484)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",486)
	::cocktail::core::style::WordSpacing wordSpacing;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",488)
	::String _switch_17 = (parsed->__Field(HX_CSTRING("unit")));
	if (  ( _switch_17==HX_CSTRING("%"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",490)
		wordSpacing = null();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",493)
		wordSpacing = ::cocktail::core::style::WordSpacing_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",497)
	return wordSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,wordSpacingEnum,return )

Array< ::cocktail::core::style::BackgroundImage > UnitManager_obj::backgroundImageEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundImageEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",507)
	if (((string == HX_CSTRING("none")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",508)
		return Array_obj< ::cocktail::core::style::BackgroundImage >::__new().Add(::cocktail::core::style::BackgroundImage_obj::none_dyn());
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",510)
	Array< ::String > array = ::cocktail::core::unit::UnitManager_obj::string2VList(string,HX_CSTRING(","));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",511)
	Array< ::cocktail::core::style::BackgroundImage > arrayBgImg = Array_obj< ::cocktail::core::style::BackgroundImage >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",512)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",512)
		int _g = (int)0;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",512)
		while(((_g < array->length))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",512)
			::String val = array->__get(_g);
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",512)
			++(_g);
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",514)
			if (((val == HX_CSTRING("none")))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",515)
				arrayBgImg->push(::cocktail::core::style::BackgroundImage_obj::none_dyn());
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",517)
				arrayBgImg->push(::cocktail::core::style::BackgroundImage_obj::image(::cocktail::core::unit::ImageValue_obj::url(::cocktail::core::unit::UnitManager_obj::string2URLData(val))));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",519)
	return arrayBgImg;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundImageEnum,return )

Dynamic UnitManager_obj::backgroundRepeatEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundRepeatEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",524)
	return Dynamic( Array_obj<Dynamic>::__new());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundRepeatEnum,return )

Array< ::cocktail::core::style::BackgroundOrigin > UnitManager_obj::backgroundOriginEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundOriginEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",530)
	return Array_obj< ::cocktail::core::style::BackgroundOrigin >::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundOriginEnum,return )

Array< ::cocktail::core::style::BackgroundSize > UnitManager_obj::backgroundSizeEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundSizeEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",536)
	return Array_obj< ::cocktail::core::style::BackgroundSize >::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundSizeEnum,return )

Dynamic UnitManager_obj::backgroundPositionEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundPositionEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",542)
	return Dynamic( Array_obj<Dynamic>::__new());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundPositionEnum,return )

Array< ::cocktail::core::style::BackgroundClip > UnitManager_obj::backgroundClipEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::backgroundClipEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",548)
	return Array_obj< ::cocktail::core::style::BackgroundClip >::__new();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,backgroundClipEnum,return )

Array< ::String > UnitManager_obj::fontFamilyEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::fontFamilyEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",557)
	return ::cocktail::core::unit::UnitManager_obj::string2Array(string);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,fontFamilyEnum,return )

::cocktail::core::style::LetterSpacing UnitManager_obj::letterSpacingEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::letterSpacingEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",563)
	if (((string == HX_CSTRING("normal")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",564)
		return ::cocktail::core::style::LetterSpacing_obj::normal_dyn();
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",566)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",568)
	::cocktail::core::style::LetterSpacing letterSpacing;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",570)
	::String _switch_18 = (parsed->__Field(HX_CSTRING("unit")));
	if (  ( _switch_18==HX_CSTRING("%"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",572)
		letterSpacing = null();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",575)
		letterSpacing = ::cocktail::core::style::LetterSpacing_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",579)
	return letterSpacing;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,letterSpacingEnum,return )

::cocktail::core::style::LineHeight UnitManager_obj::lineHeightEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::lineHeightEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",585)
	if (((string == HX_CSTRING("normal")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",586)
		return ::cocktail::core::style::LineHeight_obj::normal_dyn();
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",589)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",591)
	::cocktail::core::style::LineHeight lineHeight;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",593)
	::String _switch_19 = (parsed->__Field(HX_CSTRING("unit")));
	if (  ( _switch_19==HX_CSTRING("%"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",595)
		lineHeight = ::cocktail::core::style::LineHeight_obj::percentage(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",598)
		lineHeight = ::cocktail::core::style::LineHeight_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",602)
	return lineHeight;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,lineHeightEnum,return )

::cocktail::core::style::TextIndent UnitManager_obj::textIndentEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::textIndentEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",607)
	Dynamic parsed = ::cocktail::core::unit::UnitManager_obj::string2VUnit(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",609)
	::cocktail::core::style::TextIndent textIndent;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",611)
	::String _switch_20 = (parsed->__Field(HX_CSTRING("unit")));
	if (  ( _switch_20==HX_CSTRING("%"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",613)
		textIndent = ::cocktail::core::style::TextIndent_obj::percentage(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",616)
		textIndent = ::cocktail::core::style::TextIndent_obj::length(::cocktail::core::unit::UnitManager_obj::string2Length(parsed));
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",620)
	return textIndent;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,textIndentEnum,return )

::cocktail::core::style::CSSFloat UnitManager_obj::cssFloatEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::cssFloatEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",626)
	::String parsed = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",628)
	::cocktail::core::style::CSSFloat cssFloat;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",630)
	::String _switch_21 = (parsed);
	if (  ( _switch_21==HX_CSTRING("left"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",632)
		cssFloat = ::cocktail::core::style::CSSFloat_obj::left_dyn();
	}
	else if (  ( _switch_21==HX_CSTRING("right"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",635)
		cssFloat = ::cocktail::core::style::CSSFloat_obj::right_dyn();
	}
	else if (  ( _switch_21==HX_CSTRING("none"))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",638)
		cssFloat = ::cocktail::core::style::CSSFloat_obj::none_dyn();
	}
	else  {
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",641)
		cssFloat = null();
	}
;
;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",646)
	return cssFloat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,cssFloatEnum,return )

::cocktail::core::unit::CSSColor UnitManager_obj::colorEnum( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::colorEnum")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",655)
	string = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",657)
	if ((::StringTools_obj::startsWith(string,HX_CSTRING("#")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",658)
		return ::cocktail::core::unit::CSSColor_obj::hex(string.substr((int)1,null()));
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",660)
	if ((::StringTools_obj::startsWith(string,HX_CSTRING("rgba")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",661)
		Dynamic vcol = ::cocktail::core::unit::UnitManager_obj::string2RGBA(string);
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",662)
		return ::cocktail::core::unit::CSSColor_obj::rgba(vcol->__Field(HX_CSTRING("r")),vcol->__Field(HX_CSTRING("g")),vcol->__Field(HX_CSTRING("b")),vcol->__Field(HX_CSTRING("a")));
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",665)
	if ((::StringTools_obj::startsWith(string,HX_CSTRING("rgb")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",666)
		Dynamic vcol = ::cocktail::core::unit::UnitManager_obj::string2RGB(string);
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",667)
		return ::cocktail::core::unit::CSSColor_obj::rgb(vcol->__Field(HX_CSTRING("r")),vcol->__Field(HX_CSTRING("g")),vcol->__Field(HX_CSTRING("b")));
	}
	struct _Function_1_1{
		inline static ::cocktail::core::unit::CSSColor Block( ::String &string){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",670)
			::String _switch_22 = (string);
			if (  ( _switch_22==HX_CSTRING("transparent"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",672)
				return ::cocktail::core::unit::CSSColor_obj::transparent_dyn();
			}
			else if (  ( _switch_22==HX_CSTRING("aqua"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",673)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::aqua_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("black"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",674)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::black_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("blue"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",675)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::blue_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("fuchsia"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",676)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::fuchsia_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("gray"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",677)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::gray_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("green"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",678)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::green_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("lime"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",679)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::lime_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("maroon"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",680)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::maroon_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("navy"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",681)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::navy_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("olive"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",682)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::olive_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("orange"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",683)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::orange_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("purple"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",684)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::purple_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("red"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",685)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::red_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("silver"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",686)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::silver_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("teal"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",687)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::teal_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("white"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",688)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::white_dyn());
			}
			else if (  ( _switch_22==HX_CSTRING("yellow"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",689)
				return ::cocktail::core::unit::CSSColor_obj::keyword(::cocktail::core::unit::ColorKeyword_obj::yellow_dyn());
			}
			else  {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",690)
				return hx::Throw (((HX_CSTRING("unknown color \"") + string) + HX_CSTRING("\"")));
			}
;
;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",670)
	return _Function_1_1::Block(string);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,colorEnum,return )

Dynamic UnitManager_obj::string2RGBA( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::string2RGBA")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",704)
	string = string.substr((int)5,(string.length - (int)6));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",706)
	Array< ::String > rgba = string.split(HX_CSTRING(","));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",708)
	while(((rgba->length < (int)4))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",709)
		rgba->push(HX_CSTRING("0"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::String > &rgba){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("r") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)0))),false);
			__result->Add(HX_CSTRING("g") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)1))),false);
			__result->Add(HX_CSTRING("b") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)2))),false);
			__result->Add(HX_CSTRING("a") , ::Std_obj::parseFloat(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)3))),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",711)
	return _Function_1_1::Block(rgba);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2RGBA,return )

Dynamic UnitManager_obj::string2RGB( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::string2RGB")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",724)
	string = string.substr((int)4,(string.length - (int)5));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",726)
	Array< ::String > rgba = string.split(HX_CSTRING(","));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",728)
	while(((rgba->length < (int)3))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",729)
		rgba->push(HX_CSTRING("0"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::String > &rgba){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("r") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)0))),false);
			__result->Add(HX_CSTRING("g") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)1))),false);
			__result->Add(HX_CSTRING("b") , ::Std_obj::parseInt(::cocktail::core::unit::UnitManager_obj::trim(rgba->__get((int)2))),false);
			__result->Add(HX_CSTRING("a") , null(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",731)
	return _Function_1_1::Block(rgba);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2RGB,return )

::String UnitManager_obj::trim( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::trim")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",742)
	return ::StringTools_obj::ltrim(::StringTools_obj::rtrim(string));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,trim,return )

Dynamic UnitManager_obj::string2VUnit( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::string2VUnit")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",750)
	::EReg r = ::EReg_obj::__new(HX_CSTRING("([0-9]*)(.*)"),HX_CSTRING(""));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",751)
	r->match(string);
	struct _Function_1_1{
		inline static Dynamic Block( ::EReg &r){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("value") , r->matched((int)1),false);
			__result->Add(HX_CSTRING("unit") , ::cocktail::core::unit::UnitManager_obj::trim(r->matched((int)2)),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",753)
	return _Function_1_1::Block(r);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2VUnit,return )

::cocktail::core::unit::Length UnitManager_obj::string2Length( Dynamic parsed){
	HX_SOURCE_PUSH("UnitManager_obj::string2Length")
	struct _Function_1_1{
		inline static ::cocktail::core::unit::Length Block( Dynamic &parsed){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",763)
			::String _switch_23 = (parsed->__Field(HX_CSTRING("unit")));
			if (  ( _switch_23==HX_CSTRING("in"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",765)
				return ::cocktail::core::unit::Length_obj::cssIn(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("cm"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",767)
				return ::cocktail::core::unit::Length_obj::cm(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("em"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",769)
				return ::cocktail::core::unit::Length_obj::em(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("ex"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",771)
				return ::cocktail::core::unit::Length_obj::ex(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("mm"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",773)
				return ::cocktail::core::unit::Length_obj::mm(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("pc"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",775)
				return ::cocktail::core::unit::Length_obj::pc(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("pt"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",777)
				return ::cocktail::core::unit::Length_obj::pt(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING("px"))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",779)
				return ::cocktail::core::unit::Length_obj::px(::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value"))));
			}
			else if (  ( _switch_23==HX_CSTRING(""))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",783)
				int v = ::Std_obj::parseInt(parsed->__Field(HX_CSTRING("value")));
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",784)
				return (  (((v == (int)0))) ? ::cocktail::core::unit::Length(::cocktail::core::unit::Length_obj::px(v)) : ::cocktail::core::unit::Length(hx::Throw (((HX_CSTRING("Bad unit \"") + parsed->__Field(HX_CSTRING("unit"))) + HX_CSTRING("\"")))) );
			}
			else  {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",788)
				return hx::Throw (((HX_CSTRING("Bad unit \"") + parsed->__Field(HX_CSTRING("unit"))) + HX_CSTRING("\"")));
			}
;
;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",762)
	return _Function_1_1::Block(parsed);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2Length,return )

::String UnitManager_obj::string2URLData( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::string2URLData")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",799)
	string = ::cocktail::core::unit::UnitManager_obj::trim(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",801)
	string = ::cocktail::core::unit::UnitManager_obj::trim(string.substr((int)4,(string.length - (int)5)));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",803)
	if ((::StringTools_obj::startsWith(string,HX_CSTRING("\"")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",804)
		string = string.substr((int)1,null());
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",805)
	if ((::StringTools_obj::endsWith(string,HX_CSTRING("\"")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",806)
		string = string.substr((int)0,(string.length - (int)1));
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",807)
	return string;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2URLData,return )

Array< ::String > UnitManager_obj::string2VList( ::String string,Dynamic __o_sep){
::String sep = __o_sep.Default(HX_CSTRING(" "));
	HX_SOURCE_PUSH("UnitManager_obj::string2VList");
{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",816)
		if (((sep == HX_CSTRING(" ")))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",817)
			string = ::EReg_obj::__new(HX_CSTRING("[ ]{2,}"),HX_CSTRING("g"))->replace(string,HX_CSTRING(" "));
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",822)
			string = ::StringTools_obj::replace(string,HX_CSTRING(" "),HX_CSTRING(""));
		}
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",827)
		string = ::cocktail::core::unit::UnitManager_obj::trim(string);
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",829)
		Array< ::String > array = string.split(sep);
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",830)
		return array;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,string2VList,return )

Array< ::String > UnitManager_obj::string2Array( ::String string){
	HX_SOURCE_PUSH("UnitManager_obj::string2Array")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",838)
	::EReg r = ::EReg_obj::__new(HX_CSTRING("[ \"]*[,\"][ \"]*"),HX_CSTRING("g"));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",840)
	Array< ::String > res = r->split(string);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",842)
	if (((res->__get((int)0) == HX_CSTRING("")))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",842)
		res->shift();
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",843)
	return res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,string2Array,return )

int UnitManager_obj::getPixelFromLength( ::cocktail::core::unit::Length length,double emReference,double exReference){
	HX_SOURCE_PUSH("UnitManager_obj::getPixelFromLength")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",868)
	double lengthValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",870)
	{
::cocktail::core::unit::Length _switch_24 = (length);
		switch((_switch_24)->GetIndex()){
			case 0: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",872)
					lengthValue = value;
				}
			}
			;break;
			case 2: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",875)
					lengthValue = (double((value * ((double(((int)72 * ((double((int)1) / double(0.75))))) / double(2.54))))) / double((int)10));
				}
			}
			;break;
			case 1: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",878)
					lengthValue = (value * ((double(((int)72 * ((double((int)1) / double(0.75))))) / double(2.54))));
				}
			}
			;break;
			case 3: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",881)
					lengthValue = (double(value) / double(0.75));
				}
			}
			;break;
			case 5: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",884)
					lengthValue = (value * (((int)72 * ((double((int)1) / double(0.75))))));
				}
			}
			;break;
			case 4: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",887)
					lengthValue = (value * (((int)12 * ((double((int)1) / double(0.75))))));
				}
			}
			;break;
			case 6: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",890)
					lengthValue = (emReference * value);
				}
			}
			;break;
			case 7: {
				double value = _switch_24->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",893)
					lengthValue = (exReference * value);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",897)
	return ::Math_obj::round(lengthValue);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(UnitManager_obj,getPixelFromLength,return )

double UnitManager_obj::getFontSizeFromAbsoluteSizeValue( ::cocktail::core::unit::FontSizeAbsoluteSize absoluteSize){
	HX_SOURCE_PUSH("UnitManager_obj::getFontSizeFromAbsoluteSizeValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",906)
	double fontSize;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",908)
	int mediumFontSize = (int)16;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",910)
	{
::cocktail::core::unit::FontSizeAbsoluteSize _switch_25 = (absoluteSize);
		switch((_switch_25)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",912)
				fontSize = (int)9;
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",915)
				fontSize = (int)10;
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",918)
				fontSize = (int)13;
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",921)
				fontSize = (int)16;
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",924)
				fontSize = (int)18;
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",927)
				fontSize = (int)24;
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",930)
				fontSize = (int)32;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",934)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getFontSizeFromAbsoluteSizeValue,return )

double UnitManager_obj::getFontSizeFromRelativeSizeValue( ::cocktail::core::unit::FontSizeRelativeSize relativeSize,double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getFontSizeFromRelativeSizeValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",943)
	double fontSize;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",945)
	{
::cocktail::core::unit::FontSizeRelativeSize _switch_26 = (relativeSize);
		switch((_switch_26)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",947)
				fontSize = ::cocktail::core::unit::UnitManager_obj::getLargerFontSize(parentFontSize);
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",950)
				fontSize = ::cocktail::core::unit::UnitManager_obj::getSmallerFontSize(parentFontSize);
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",954)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getFontSizeFromRelativeSizeValue,return )

double UnitManager_obj::getPixelFromPercent( int percent,int reference){
	HX_SOURCE_PUSH("UnitManager_obj::getPixelFromPercent")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",964)
	return (reference * ((percent * 0.01)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getPixelFromPercent,return )

double UnitManager_obj::getPercentFromPixel( int pixel,int reference){
	HX_SOURCE_PUSH("UnitManager_obj::getPercentFromPixel")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",975)
	return ((double(reference) / double(pixel)) * (int)100);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UnitManager_obj,getPercentFromPixel,return )

Dynamic UnitManager_obj::getColorDataFromCSSColor( ::cocktail::core::unit::CSSColor value){
	HX_SOURCE_PUSH("UnitManager_obj::getColorDataFromCSSColor")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",984)
	int colorValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",985)
	double alphaValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",987)
	{
::cocktail::core::unit::CSSColor _switch_27 = (value);
		switch((_switch_27)->GetIndex()){
			case 0: {
				int blue = _switch_27->__Param(2);
				int green = _switch_27->__Param(1);
				int red = _switch_27->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",990)
					colorValue = red;
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",991)
					colorValue = (((int(colorValue) << int((int)8))) + green);
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",992)
					colorValue = (((int(colorValue) << int((int)8))) + blue);
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",993)
					alphaValue = 1.0;
				}
			}
			;break;
			case 1: {
				double alpha = _switch_27->__Param(3);
				int blue = _switch_27->__Param(2);
				int green = _switch_27->__Param(1);
				int red = _switch_27->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",996)
					colorValue = red;
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",997)
					colorValue = (((int(colorValue) << int((int)8))) + green);
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",998)
					colorValue = (((int(colorValue) << int((int)8))) + blue);
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",999)
					alphaValue = alpha;
				}
			}
			;break;
			case 2: {
				::String value1 = _switch_27->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1002)
					colorValue = ::Std_obj::parseInt(::StringTools_obj::replace(value1,HX_CSTRING("#"),HX_CSTRING("0x")));
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1003)
					alphaValue = 1.0;
				}
			}
			;break;
			case 3: {
				::cocktail::core::unit::ColorKeyword value1 = _switch_27->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1006)
					colorValue = ::cocktail::core::unit::UnitManager_obj::getColorDataFromColorKeyword(value1)->__Field(HX_CSTRING("color"));
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1007)
					alphaValue = 1.0;
				}
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1010)
				colorValue = (int)16777215;
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1011)
				alphaValue = 0.0;
			}
			;break;
		}
	}
	struct _Function_1_1{
		inline static Dynamic Block( int &colorValue,double &alphaValue){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("color") , colorValue,false);
			__result->Add(HX_CSTRING("alpha") , alphaValue,false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1014)
	Dynamic colorData = _Function_1_1::Block(colorValue,alphaValue);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1019)
	return colorData;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getColorDataFromCSSColor,return )

double UnitManager_obj::getRadFromAngle( ::cocktail::core::unit::Angle value){
	HX_SOURCE_PUSH("UnitManager_obj::getRadFromAngle")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1027)
	double angle;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1029)
	{
::cocktail::core::unit::Angle _switch_28 = (value);
		switch((_switch_28)->GetIndex()){
			case 0: {
				double value1 = _switch_28->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1031)
					angle = (value1 * ((double(::Math_obj::PI) / double((int)180))));
				}
			}
			;break;
			case 2: {
				double value1 = _switch_28->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1034)
					angle = value1;
				}
			}
			;break;
			case 3: {
				double value1 = _switch_28->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1037)
					angle = ((value1 * (int)360) * ((double(::Math_obj::PI) / double((int)180))));
				}
			}
			;break;
			case 1: {
				double value1 = _switch_28->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1040)
					angle = (value1 * ((double(::Math_obj::PI) / double((int)200))));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1044)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getRadFromAngle,return )

double UnitManager_obj::getDegreeFromAngle( ::cocktail::core::unit::Angle value){
	HX_SOURCE_PUSH("UnitManager_obj::getDegreeFromAngle")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1052)
	double angle;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1054)
	{
::cocktail::core::unit::Angle _switch_29 = (value);
		switch((_switch_29)->GetIndex()){
			case 0: {
				double value1 = _switch_29->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1056)
					angle = value1;
				}
			}
			;break;
			case 2: {
				double value1 = _switch_29->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1059)
					angle = (value1 * ((double((int)180) / double(::Math_obj::PI))));
				}
			}
			;break;
			case 3: {
				double value1 = _switch_29->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1062)
					angle = (value1 * (int)360);
				}
			}
			;break;
			case 1: {
				double value1 = _switch_29->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1065)
					angle = (value1 * 0.9);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1069)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getDegreeFromAngle,return )

Dynamic UnitManager_obj::getColorDataFromColorKeyword( ::cocktail::core::unit::ColorKeyword value){
	HX_SOURCE_PUSH("UnitManager_obj::getColorDataFromColorKeyword")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1081)
	::String hexColor;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1083)
	{
::cocktail::core::unit::ColorKeyword _switch_30 = (value);
		switch((_switch_30)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1085)
				hexColor = HX_CSTRING("#00FFFF");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1088)
				hexColor = HX_CSTRING("#000000");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1091)
				hexColor = HX_CSTRING("#0000FF");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1094)
				hexColor = HX_CSTRING("#FF00FF");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1097)
				hexColor = HX_CSTRING("#808080");
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1100)
				hexColor = HX_CSTRING("#008000");
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1103)
				hexColor = HX_CSTRING("#00FF00");
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1106)
				hexColor = HX_CSTRING("#800000");
			}
			;break;
			case 8: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1109)
				hexColor = HX_CSTRING("#000080");
			}
			;break;
			case 9: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1112)
				hexColor = HX_CSTRING("#808000");
			}
			;break;
			case 10: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1115)
				hexColor = HX_CSTRING("#FFA500");
			}
			;break;
			case 11: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1118)
				hexColor = HX_CSTRING("#800080");
			}
			;break;
			case 12: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1121)
				hexColor = HX_CSTRING("#FF0000");
			}
			;break;
			case 13: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1124)
				hexColor = HX_CSTRING("#C0C0C0");
			}
			;break;
			case 14: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1127)
				hexColor = HX_CSTRING("#008080");
			}
			;break;
			case 15: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1130)
				hexColor = HX_CSTRING("#FFFFFF");
			}
			;break;
			case 16: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1133)
				hexColor = HX_CSTRING("#FFFF00");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1138)
	return ::cocktail::core::unit::UnitManager_obj::getColorDataFromCSSColor(::cocktail::core::unit::CSSColor_obj::hex(hexColor));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getColorDataFromColorKeyword,return )

double UnitManager_obj::getLargerFontSize( double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getLargerFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1147)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)13).Add((int)16).Add((int)18).Add((int)24).Add((int)32);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1148)
	double fontSize = fontSizeTable->__get((fontSizeTable->length - (int)1));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1150)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1150)
		int _g1 = (int)0;
		int _g = fontSizeTable->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1150)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1150)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1152)
			if (((fontSizeTable->__get(i) > parentFontSize))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1154)
				fontSize = fontSizeTable->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1155)
				break;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1159)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getLargerFontSize,return )

double UnitManager_obj::getSmallerFontSize( double parentFontSize){
	HX_SOURCE_PUSH("UnitManager_obj::getSmallerFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1169)
	Array< int > fontSizeTable = Array_obj< int >::__new().Add((int)9).Add((int)10).Add((int)13).Add((int)16).Add((int)18).Add((int)24).Add((int)32);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1170)
	double fontSize = fontSizeTable->__get((int)0);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1172)
	int i = (fontSizeTable->length - (int)1);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1174)
	while(((i > (int)0))){
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1176)
		if (((fontSizeTable->__get(i) < parentFontSize))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1179)
			fontSize = fontSizeTable->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1181)
			break;
		}
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1184)
		(i)--;
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1187)
	return fontSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getSmallerFontSize,return )

::String UnitManager_obj::getCSSDisplay( ::cocktail::core::style::Display value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSDisplay")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1203)
	::String cssDisplayValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1205)
	{
::cocktail::core::style::Display _switch_31 = (value);
		switch((_switch_31)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1207)
				cssDisplayValue = HX_CSTRING("block");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1210)
				cssDisplayValue = HX_CSTRING("inline");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1213)
				cssDisplayValue = HX_CSTRING("inline-block");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1216)
				cssDisplayValue = HX_CSTRING("none");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1220)
	return cssDisplayValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSDisplay,return )

::String UnitManager_obj::getCSSFloatAsString( ::cocktail::core::style::CSSFloat value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFloatAsString")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1228)
	::String cssCSSFloat;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1230)
	{
::cocktail::core::style::CSSFloat _switch_32 = (value);
		switch((_switch_32)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1232)
				cssCSSFloat = HX_CSTRING("left");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1235)
				cssCSSFloat = HX_CSTRING("right");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1238)
				cssCSSFloat = HX_CSTRING("none");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1242)
	return cssCSSFloat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFloatAsString,return )

::String UnitManager_obj::getCSSClear( ::cocktail::core::style::Clear value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSClear")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1250)
	::String cssClearValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1252)
	{
::cocktail::core::style::Clear _switch_33 = (value);
		switch((_switch_33)->GetIndex()){
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1254)
				cssClearValue = HX_CSTRING("left");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1257)
				cssClearValue = HX_CSTRING("right");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1260)
				cssClearValue = HX_CSTRING("both");
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1263)
				cssClearValue = HX_CSTRING("none");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1267)
	return cssClearValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSClear,return )

::String UnitManager_obj::getCSSPosition( ::cocktail::core::style::Position value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSPosition")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1275)
	::String cssPositionValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1277)
	{
::cocktail::core::style::Position _switch_34 = (value);
		switch((_switch_34)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1279)
				cssPositionValue = HX_CSTRING("static");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1282)
				cssPositionValue = HX_CSTRING("relative");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1285)
				cssPositionValue = HX_CSTRING("absolute");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1288)
				cssPositionValue = HX_CSTRING("fixed");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1292)
	return cssPositionValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSPosition,return )

::String UnitManager_obj::getCSSOverflow( ::cocktail::core::style::Overflow value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSOverflow")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1304)
	::String cssOverflowValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1306)
	{
::cocktail::core::style::Overflow _switch_35 = (value);
		switch((_switch_35)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1308)
				cssOverflowValue = HX_CSTRING("visible");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1311)
				cssOverflowValue = HX_CSTRING("hidden");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1314)
				cssOverflowValue = HX_CSTRING("scroll");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1317)
				cssOverflowValue = HX_CSTRING("auto");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1321)
	return cssOverflowValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSOverflow,return )

::String UnitManager_obj::getCSSOpacity( double value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSOpacity")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1329)
	::String cssOpacityValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1330)
	cssOpacityValue = ::Std_obj::string(value);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1332)
	return cssOpacityValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSOpacity,return )

::String UnitManager_obj::getCSSVisibility( ::cocktail::core::style::Visibility value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSVisibility")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1340)
	::String cssVisibilityValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1342)
	{
::cocktail::core::style::Visibility _switch_36 = (value);
		switch((_switch_36)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1344)
				cssVisibilityValue = HX_CSTRING("visible");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1347)
				cssVisibilityValue = HX_CSTRING("hidden");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1351)
	return cssVisibilityValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSVisibility,return )

::String UnitManager_obj::getCSSTransform( ::cocktail::core::style::Transform value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTransform")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1359)
	::String cssTransformValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1361)
	{
::cocktail::core::style::Transform _switch_37 = (value);
		switch((_switch_37)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1363)
				cssTransformValue = HX_CSTRING("none");
			}
			;break;
			case 1: {
				Array< ::cocktail::core::style::TransformFunction > value1 = _switch_37->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1367)
					cssTransformValue = HX_CSTRING("");
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1368)
					{
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1368)
						int _g1 = (int)0;
						int _g = value1->length;
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1368)
						while(((_g1 < _g))){
							HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1368)
							int i = (_g1)++;
							HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1370)
							hx::AddEq(cssTransformValue,::cocktail::core::unit::UnitManager_obj::getCSSTransformFunction(value1->__get(i)));
							HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1371)
							if (((i < (value1->length - (int)1)))){
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1372)
								hx::AddEq(cssTransformValue,HX_CSTRING(" "));
							}
						}
					}
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1378)
	return cssTransformValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTransform,return )

::String UnitManager_obj::getCSSTransformFunction( ::cocktail::core::style::TransformFunction transformFunction){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTransformFunction")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1387)
	::String cssTransformFunction;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1389)
	{
::cocktail::core::style::TransformFunction _switch_38 = (transformFunction);
		switch((_switch_38)->GetIndex()){
			case 0: {
				Dynamic value = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1391)
					cssTransformFunction = ((((((((((((HX_CSTRING("matrix(") + value->__Field(HX_CSTRING("a"))) + HX_CSTRING(",")) + value->__Field(HX_CSTRING("b"))) + HX_CSTRING(",")) + value->__Field(HX_CSTRING("c"))) + HX_CSTRING(",")) + value->__Field(HX_CSTRING("d"))) + HX_CSTRING(",")) + value->__Field(HX_CSTRING("e"))) + HX_CSTRING(",")) + value->__Field(HX_CSTRING("f"))) + HX_CSTRING(")"));
				}
			}
			;break;
			case 7: {
				::cocktail::core::unit::Angle angle = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1394)
					cssTransformFunction = ((HX_CSTRING("rotate(") + ::cocktail::core::unit::UnitManager_obj::getCSSAngle(angle)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 4: {
				double sy = _switch_38->__Param(1);
				double sx = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1397)
					cssTransformFunction = ((((HX_CSTRING("scale(") + sx) + HX_CSTRING(",")) + sy) + HX_CSTRING(")"));
				}
			}
			;break;
			case 5: {
				double sx = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1400)
					cssTransformFunction = ((HX_CSTRING("scaleX(") + sx) + HX_CSTRING(")"));
				}
			}
			;break;
			case 6: {
				double sy = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1403)
					cssTransformFunction = ((HX_CSTRING("scaleY(") + sy) + HX_CSTRING(")"));
				}
			}
			;break;
			case 10: {
				::cocktail::core::unit::Angle skewY = _switch_38->__Param(1);
				::cocktail::core::unit::Angle skewX = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1406)
					cssTransformFunction = ((((HX_CSTRING("skew(") + ::cocktail::core::unit::UnitManager_obj::getCSSAngle(skewX)) + HX_CSTRING(",")) + ::cocktail::core::unit::UnitManager_obj::getCSSAngle(skewY)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 8: {
				::cocktail::core::unit::Angle skewX = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1409)
					cssTransformFunction = ((HX_CSTRING("skewX(") + ::cocktail::core::unit::UnitManager_obj::getCSSAngle(skewX)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 9: {
				::cocktail::core::unit::Angle skewY = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1412)
					cssTransformFunction = ((HX_CSTRING("skewY(") + ::cocktail::core::unit::UnitManager_obj::getCSSAngle(skewY)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 1: {
				::cocktail::core::style::Translation ty = _switch_38->__Param(1);
				::cocktail::core::style::Translation tx = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1415)
					cssTransformFunction = ((((HX_CSTRING("translate(") + ::cocktail::core::unit::UnitManager_obj::getCSSTranslation(tx)) + HX_CSTRING(",")) + ::cocktail::core::unit::UnitManager_obj::getCSSTranslation(ty)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 2: {
				::cocktail::core::style::Translation tx = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1418)
					cssTransformFunction = ((HX_CSTRING("translateX(") + ::cocktail::core::unit::UnitManager_obj::getCSSTranslation(tx)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 3: {
				::cocktail::core::style::Translation ty = _switch_38->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1421)
					cssTransformFunction = ((HX_CSTRING("translateY(") + ::cocktail::core::unit::UnitManager_obj::getCSSTranslation(ty)) + HX_CSTRING(")"));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1425)
	return cssTransformFunction;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTransformFunction,return )

::String UnitManager_obj::getCSSTranslation( ::cocktail::core::style::Translation translation){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTranslation")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1434)
	::String cssTranslation;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1436)
	{
::cocktail::core::style::Translation _switch_39 = (translation);
		switch((_switch_39)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value = _switch_39->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1438)
					cssTranslation = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value);
				}
			}
			;break;
			case 1: {
				int value = _switch_39->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1441)
					cssTranslation = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1445)
	return cssTranslation;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTranslation,return )

::String UnitManager_obj::getCSSTransformOrigin( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTransformOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1453)
	::String cssTransformOriginValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1456)
	{
::cocktail::core::style::TransformOriginX _switch_40 = (value->__Field(HX_CSTRING("x")));
		switch((_switch_40)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_40->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1458)
					cssTransformOriginValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_40->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1461)
					cssTransformOriginValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1464)
				cssTransformOriginValue = HX_CSTRING("left");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1467)
				cssTransformOriginValue = HX_CSTRING("center");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1470)
				cssTransformOriginValue = HX_CSTRING("right");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1475)
	hx::AddEq(cssTransformOriginValue,HX_CSTRING(" "));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1478)
	{
::cocktail::core::style::TransformOriginY _switch_41 = (value->__Field(HX_CSTRING("y")));
		switch((_switch_41)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_41->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1480)
					hx::AddEq(cssTransformOriginValue,::cocktail::core::unit::UnitManager_obj::getCSSLength(value1));
				}
			}
			;break;
			case 1: {
				int value1 = _switch_41->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1483)
					hx::AddEq(cssTransformOriginValue,::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1));
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1486)
				hx::AddEq(cssTransformOriginValue,HX_CSTRING("top"));
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1489)
				hx::AddEq(cssTransformOriginValue,HX_CSTRING("center"));
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1492)
				hx::AddEq(cssTransformOriginValue,HX_CSTRING("bottom"));
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1496)
	return cssTransformOriginValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTransformOrigin,return )

::String UnitManager_obj::getCSSMargin( ::cocktail::core::style::Margin value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSMargin")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1508)
	::String cssMarginValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1510)
	{
::cocktail::core::style::Margin _switch_42 = (value);
		switch((_switch_42)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_42->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1512)
					cssMarginValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percentValue = _switch_42->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1515)
					cssMarginValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percentValue);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1518)
				cssMarginValue = HX_CSTRING("auto");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1522)
	return cssMarginValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSMargin,return )

::String UnitManager_obj::getCSSPadding( ::cocktail::core::style::Padding value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSPadding")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1530)
	::String cssPaddingValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1532)
	{
::cocktail::core::style::Padding _switch_43 = (value);
		switch((_switch_43)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_43->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1534)
					cssPaddingValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percentValue = _switch_43->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1537)
					cssPaddingValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percentValue);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1541)
	return cssPaddingValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSPadding,return )

::String UnitManager_obj::getCSSDimension( ::cocktail::core::style::Dimension value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSDimension")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1549)
	::String cssDimensionValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1551)
	{
::cocktail::core::style::Dimension _switch_44 = (value);
		switch((_switch_44)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_44->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1553)
					cssDimensionValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percentValue = _switch_44->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1556)
					cssDimensionValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percentValue);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1559)
				cssDimensionValue = HX_CSTRING("auto");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1563)
	return cssDimensionValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSDimension,return )

::String UnitManager_obj::getCSSPositionOffset( ::cocktail::core::style::PositionOffset value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSPositionOffset")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1571)
	::String cssPositionOffsetValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1573)
	{
::cocktail::core::style::PositionOffset _switch_45 = (value);
		switch((_switch_45)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_45->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1575)
					cssPositionOffsetValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percentValue = _switch_45->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1579)
					cssPositionOffsetValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percentValue);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1582)
				cssPositionOffsetValue = HX_CSTRING("auto");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1586)
	return cssPositionOffsetValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSPositionOffset,return )

::String UnitManager_obj::getCSSConstrainedDimension( ::cocktail::core::style::ConstrainedDimension value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSConstrainedDimension")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1594)
	::String cssConstrainedValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1596)
	{
::cocktail::core::style::ConstrainedDimension _switch_46 = (value);
		switch((_switch_46)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_46->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1598)
					cssConstrainedValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percentValue = _switch_46->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1601)
					cssConstrainedValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percentValue);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1604)
				cssConstrainedValue = HX_CSTRING("none");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1608)
	return cssConstrainedValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSConstrainedDimension,return )

::String UnitManager_obj::getCSSVerticalAlign( ::cocktail::core::style::VerticalAlign value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSVerticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1617)
	::String cssVerticalAlignValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1619)
	{
::cocktail::core::style::VerticalAlign _switch_47 = (value);
		switch((_switch_47)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1621)
				cssVerticalAlignValue = HX_CSTRING("baseline");
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1624)
				cssVerticalAlignValue = HX_CSTRING("middle");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1627)
				cssVerticalAlignValue = HX_CSTRING("sub");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1630)
				cssVerticalAlignValue = HX_CSTRING("super");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1633)
				cssVerticalAlignValue = HX_CSTRING("text-top");
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1636)
				cssVerticalAlignValue = HX_CSTRING("text-bottom");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1639)
				cssVerticalAlignValue = HX_CSTRING("top");
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1642)
				cssVerticalAlignValue = HX_CSTRING("bottom");
			}
			;break;
			case 8: {
				int value1 = _switch_47->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1645)
					cssVerticalAlignValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 9: {
				::cocktail::core::unit::Length value1 = _switch_47->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1648)
					cssVerticalAlignValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1652)
	return cssVerticalAlignValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSVerticalAlign,return )

::String UnitManager_obj::getCSSLineHeight( ::cocktail::core::style::LineHeight value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSLineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1661)
	::String cssLineHeightValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1663)
	{
::cocktail::core::style::LineHeight _switch_48 = (value);
		switch((_switch_48)->GetIndex()){
			case 2: {
				::cocktail::core::unit::Length unit = _switch_48->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1665)
					cssLineHeightValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1668)
				cssLineHeightValue = HX_CSTRING("normal");
			}
			;break;
			case 3: {
				int value1 = _switch_48->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1671)
					cssLineHeightValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 1: {
				double value1 = _switch_48->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1674)
					cssLineHeightValue = ::Std_obj::string(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1678)
	return cssLineHeightValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSLineHeight,return )

::String UnitManager_obj::getCSSFontSize( ::cocktail::core::style::FontSize value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFontSize")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1691)
	::String cssFontSizeValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1693)
	{
::cocktail::core::style::FontSize _switch_49 = (value);
		switch((_switch_49)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length unit = _switch_49->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1695)
					cssFontSizeValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
			case 1: {
				int percent = _switch_49->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1698)
					cssFontSizeValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(percent);
				}
			}
			;break;
			case 2: {
				::cocktail::core::unit::FontSizeAbsoluteSize value1 = _switch_49->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1701)
					{
::cocktail::core::unit::FontSizeAbsoluteSize _switch_50 = (value1);
						switch((_switch_50)->GetIndex()){
							case 0: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1704)
								cssFontSizeValue = HX_CSTRING("xx-small");
							}
							;break;
							case 1: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1707)
								cssFontSizeValue = HX_CSTRING("x-small");
							}
							;break;
							case 2: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1710)
								cssFontSizeValue = HX_CSTRING("small");
							}
							;break;
							case 3: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1713)
								cssFontSizeValue = HX_CSTRING("medium");
							}
							;break;
							case 4: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1716)
								cssFontSizeValue = HX_CSTRING("large");
							}
							;break;
							case 5: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1719)
								cssFontSizeValue = HX_CSTRING("x-large");
							}
							;break;
							case 6: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1722)
								cssFontSizeValue = HX_CSTRING("xx-large");
							}
							;break;
						}
					}
				}
			}
			;break;
			case 3: {
				::cocktail::core::unit::FontSizeRelativeSize value1 = _switch_49->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1726)
					{
::cocktail::core::unit::FontSizeRelativeSize _switch_51 = (value1);
						switch((_switch_51)->GetIndex()){
							case 0: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1729)
								cssFontSizeValue = HX_CSTRING("larger");
							}
							;break;
							case 1: {
								HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1732)
								cssFontSizeValue = HX_CSTRING("smaller");
							}
							;break;
						}
					}
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1737)
	return cssFontSizeValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFontSize,return )

::String UnitManager_obj::getCSSFontWeight( ::cocktail::core::style::FontWeight value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFontWeight")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1745)
	::String cssFontWeightValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1747)
	{
::cocktail::core::style::FontWeight _switch_52 = (value);
		switch((_switch_52)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1749)
				cssFontWeightValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1752)
				cssFontWeightValue = HX_CSTRING("bold");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1755)
				cssFontWeightValue = HX_CSTRING("bolder");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1758)
				cssFontWeightValue = HX_CSTRING("lighter");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1761)
				cssFontWeightValue = HX_CSTRING("100");
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1764)
				cssFontWeightValue = HX_CSTRING("200");
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1767)
				cssFontWeightValue = HX_CSTRING("300");
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1770)
				cssFontWeightValue = HX_CSTRING("400");
			}
			;break;
			case 8: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1773)
				cssFontWeightValue = HX_CSTRING("500");
			}
			;break;
			case 9: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1776)
				cssFontWeightValue = HX_CSTRING("600");
			}
			;break;
			case 10: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1779)
				cssFontWeightValue = HX_CSTRING("700");
			}
			;break;
			case 11: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1782)
				cssFontWeightValue = HX_CSTRING("800");
			}
			;break;
			case 12: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1785)
				cssFontWeightValue = HX_CSTRING("900");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1789)
	return cssFontWeightValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFontWeight,return )

::String UnitManager_obj::getCSSFontStyle( ::cocktail::core::style::FontStyle value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFontStyle")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1797)
	::String cssFontStyleValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1799)
	{
::cocktail::core::style::FontStyle _switch_53 = (value);
		switch((_switch_53)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1801)
				cssFontStyleValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1804)
				cssFontStyleValue = HX_CSTRING("italic");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1808)
	return cssFontStyleValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFontStyle,return )

::String UnitManager_obj::getCSSFontVariant( ::cocktail::core::style::FontVariant value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFontVariant")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1816)
	::String cssFontVariantValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1818)
	{
::cocktail::core::style::FontVariant _switch_54 = (value);
		switch((_switch_54)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1820)
				cssFontVariantValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1823)
				cssFontVariantValue = HX_CSTRING("small-caps");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1827)
	return cssFontVariantValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFontVariant,return )

::String UnitManager_obj::getCSSFontFamily( Array< ::String > value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSFontFamily")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1835)
	::String cssFontFamilyValue = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1837)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1837)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1837)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1837)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1839)
			::String fontName = value->__get(i);
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1842)
			if (((fontName.indexOf(HX_CSTRING(" "),null()) != (int)-1))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1843)
				fontName = ((HX_CSTRING("'") + fontName) + HX_CSTRING("'"));
			}
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1847)
			hx::AddEq(cssFontFamilyValue,fontName);
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1849)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1850)
				hx::AddEq(cssFontFamilyValue,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1855)
	return cssFontFamilyValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSFontFamily,return )

::String UnitManager_obj::getCSSTextAlign( ::cocktail::core::style::TextAlign value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTextAlign")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1867)
	::String cssTextAlignValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1869)
	{
::cocktail::core::style::TextAlign _switch_55 = (value);
		switch((_switch_55)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1871)
				cssTextAlignValue = HX_CSTRING("left");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1874)
				cssTextAlignValue = HX_CSTRING("right");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1877)
				cssTextAlignValue = HX_CSTRING("center");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1880)
				cssTextAlignValue = HX_CSTRING("justify");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1884)
	return cssTextAlignValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTextAlign,return )

::String UnitManager_obj::getCSSWhiteSpace( ::cocktail::core::style::WhiteSpace value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSWhiteSpace")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1892)
	::String cssWhiteSpaceValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1894)
	{
::cocktail::core::style::WhiteSpace _switch_56 = (value);
		switch((_switch_56)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1896)
				cssWhiteSpaceValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1899)
				cssWhiteSpaceValue = HX_CSTRING("pre");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1902)
				cssWhiteSpaceValue = HX_CSTRING("nowrap");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1905)
				cssWhiteSpaceValue = HX_CSTRING("pre-wrap");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1908)
				cssWhiteSpaceValue = HX_CSTRING("pre-line");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1912)
	return cssWhiteSpaceValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSWhiteSpace,return )

::String UnitManager_obj::getCSSTextTransform( ::cocktail::core::style::TextTransform value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTextTransform")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1920)
	::String cssTextTransformValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1922)
	{
::cocktail::core::style::TextTransform _switch_57 = (value);
		switch((_switch_57)->GetIndex()){
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1924)
				cssTextTransformValue = HX_CSTRING("none");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1927)
				cssTextTransformValue = HX_CSTRING("uppercase");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1930)
				cssTextTransformValue = HX_CSTRING("lowercase");
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1933)
				cssTextTransformValue = HX_CSTRING("capitalize");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1937)
	return cssTextTransformValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTextTransform,return )

::String UnitManager_obj::getCSSTextIndent( ::cocktail::core::style::TextIndent value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSTextIndent")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1945)
	::String cssTextIndentValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1947)
	{
::cocktail::core::style::TextIndent _switch_58 = (value);
		switch((_switch_58)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_58->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1949)
					cssTextIndentValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_58->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1952)
					cssTextIndentValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1956)
	return cssTextIndentValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSTextIndent,return )

::String UnitManager_obj::getCSSLetterSpacing( ::cocktail::core::style::LetterSpacing value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSLetterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1964)
	::String cssLetterSpacingValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1966)
	{
::cocktail::core::style::LetterSpacing _switch_59 = (value);
		switch((_switch_59)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1968)
				cssLetterSpacingValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				::cocktail::core::unit::Length unit = _switch_59->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1971)
					cssLetterSpacingValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1975)
	return cssLetterSpacingValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSLetterSpacing,return )

::String UnitManager_obj::getCSSWordSpacing( ::cocktail::core::style::WordSpacing value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSWordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1983)
	::String cssWordSpacingValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1985)
	{
::cocktail::core::style::WordSpacing _switch_60 = (value);
		switch((_switch_60)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1987)
				cssWordSpacingValue = HX_CSTRING("normal");
			}
			;break;
			case 1: {
				::cocktail::core::unit::Length unit = _switch_60->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1990)
					cssWordSpacingValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(unit);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",1994)
	return cssWordSpacingValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSWordSpacing,return )

::String UnitManager_obj::getCSSBackgroundColor( ::cocktail::core::unit::CSSColor value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2008)
	::String cssBackgroundColor;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2009)
	cssBackgroundColor = ::cocktail::core::unit::UnitManager_obj::getCSSColor(value);
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2011)
	return cssBackgroundColor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundColor,return )

::String UnitManager_obj::getCSSBackgroundOrigin( Array< ::cocktail::core::style::BackgroundOrigin > value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2019)
	::String cssBackgroundOrigin = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2021)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2021)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2021)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2021)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2023)
			{
::cocktail::core::style::BackgroundOrigin _switch_61 = (value->__get(i));
				switch((_switch_61)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2025)
						hx::AddEq(cssBackgroundOrigin,HX_CSTRING("border-box"));
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2028)
						hx::AddEq(cssBackgroundOrigin,HX_CSTRING("content-box"));
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2031)
						hx::AddEq(cssBackgroundOrigin,HX_CSTRING("padding-box"));
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2035)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2036)
				hx::AddEq(cssBackgroundOrigin,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2041)
	return cssBackgroundOrigin;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundOrigin,return )

::String UnitManager_obj::getCSSBackgroundClip( Array< ::cocktail::core::style::BackgroundClip > value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundClip")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2049)
	::String cssBackgroundClip = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2051)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2051)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2051)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2051)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2053)
			{
::cocktail::core::style::BackgroundClip _switch_62 = (value->__get(i));
				switch((_switch_62)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2055)
						hx::AddEq(cssBackgroundClip,HX_CSTRING("border-box"));
					}
					;break;
					case 2: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2058)
						hx::AddEq(cssBackgroundClip,HX_CSTRING("content-box"));
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2061)
						hx::AddEq(cssBackgroundClip,HX_CSTRING("padding-box"));
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2065)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2066)
				hx::AddEq(cssBackgroundClip,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2071)
	return cssBackgroundClip;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundClip,return )

::String UnitManager_obj::getCSSBackgroundImage( Array< ::cocktail::core::style::BackgroundImage > value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2079)
	::String cssBackgroundImage = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2081)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2081)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2081)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2081)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2083)
			{
::cocktail::core::style::BackgroundImage _switch_63 = (value->__get(i));
				switch((_switch_63)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2085)
						hx::AddEq(cssBackgroundImage,HX_CSTRING("none"));
					}
					;break;
					case 1: {
						::cocktail::core::unit::ImageValue value1 = _switch_63->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2088)
							hx::AddEq(cssBackgroundImage,::cocktail::core::unit::UnitManager_obj::getCSSImageValue(value1));
						}
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2092)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2093)
				hx::AddEq(cssBackgroundImage,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2099)
	return cssBackgroundImage;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundImage,return )

::String UnitManager_obj::getCSSBackgroundSize( Array< ::cocktail::core::style::BackgroundSize > value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2107)
	::String cssBackgroundSize = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2109)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2109)
		int _g1 = (int)0;
		int _g = value->length;
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2109)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2109)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2111)
			{
::cocktail::core::style::BackgroundSize _switch_64 = (value->__get(i));
				switch((_switch_64)->GetIndex()){
					case 0: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2113)
						hx::AddEq(cssBackgroundSize,HX_CSTRING("contain"));
					}
					;break;
					case 1: {
						HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2116)
						hx::AddEq(cssBackgroundSize,HX_CSTRING("cover"));
					}
					;break;
					case 2: {
						Dynamic value1 = _switch_64->__Param(0);
{
							HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2119)
							hx::AddEq(cssBackgroundSize,::cocktail::core::unit::UnitManager_obj::getCSSBackgroundSizeDimensions(value1));
						}
					}
					;break;
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2123)
			if (((i < (value->length - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2124)
				hx::AddEq(cssBackgroundSize,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2129)
	return cssBackgroundSize;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundSize,return )

::String UnitManager_obj::getCSSBackgroundSizeDimensions( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundSizeDimensions")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2134)
	::String cssBackgroundSizeDimensions = ((::cocktail::core::unit::UnitManager_obj::getCSSBackgroundSizeDimension(value->__Field(HX_CSTRING("x"))) + HX_CSTRING(" ")) + ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundSizeDimension(value->__Field(HX_CSTRING("y"))));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2135)
	return cssBackgroundSizeDimensions;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundSizeDimensions,return )

::String UnitManager_obj::getCSSBackgroundSizeDimension( ::cocktail::core::style::BackgroundSizeDimension value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundSizeDimension")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2140)
	::String cssBackgroundSizeDimension;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2142)
	{
::cocktail::core::style::BackgroundSizeDimension _switch_65 = (value);
		switch((_switch_65)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_65->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2144)
					cssBackgroundSizeDimension = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_65->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2147)
					cssBackgroundSizeDimension = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2150)
				cssBackgroundSizeDimension = HX_CSTRING("auto");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2154)
	return cssBackgroundSizeDimension;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundSizeDimension,return )

::String UnitManager_obj::getCSSBackgroundPosition( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2162)
	::String cssBackgroundPositionData = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2164)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2164)
		int _g1 = (int)0;
		int _g = value->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2164)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2164)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2166)
			hx::AddEq(cssBackgroundPositionData,((::cocktail::core::unit::UnitManager_obj::getCSSBackgroundPositionX(value->__GetItem(i)->__Field(HX_CSTRING("x"))) + HX_CSTRING(" ")) + ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundPositionY(value->__GetItem(i)->__Field(HX_CSTRING("y")))));
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2168)
			if (((i < (value->__Field(HX_CSTRING("length")) - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2169)
				hx::AddEq(cssBackgroundPositionData,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2174)
	return cssBackgroundPositionData;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundPosition,return )

::String UnitManager_obj::getCSSBackgroundPositionX( ::cocktail::core::style::BackgroundPositionX value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundPositionX")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2179)
	::String cssBackgroundPositionX;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2181)
	{
::cocktail::core::style::BackgroundPositionX _switch_66 = (value);
		switch((_switch_66)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_66->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2183)
					cssBackgroundPositionX = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_66->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2186)
					cssBackgroundPositionX = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2189)
				cssBackgroundPositionX = HX_CSTRING("center");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2192)
				cssBackgroundPositionX = HX_CSTRING("left");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2195)
				cssBackgroundPositionX = HX_CSTRING("right");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2199)
	return cssBackgroundPositionX;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundPositionX,return )

::String UnitManager_obj::getCSSBackgroundPositionY( ::cocktail::core::style::BackgroundPositionY value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundPositionY")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2204)
	::String cssBackgroundPositionY;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2206)
	{
::cocktail::core::style::BackgroundPositionY _switch_67 = (value);
		switch((_switch_67)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_67->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2208)
					cssBackgroundPositionY = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
			case 1: {
				int value1 = _switch_67->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2211)
					cssBackgroundPositionY = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2214)
				cssBackgroundPositionY = HX_CSTRING("bottom");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2217)
				cssBackgroundPositionY = HX_CSTRING("top");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2220)
				cssBackgroundPositionY = HX_CSTRING("center");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2224)
	return cssBackgroundPositionY;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundPositionY,return )

::String UnitManager_obj::getCSSBackgroundRepeat( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundRepeat")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2232)
	::String cssBackgroundRepeat = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2234)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2234)
		int _g1 = (int)0;
		int _g = value->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2234)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2234)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2236)
			hx::AddEq(cssBackgroundRepeat,((::cocktail::core::unit::UnitManager_obj::getCSSBackgroundRepeatValue(value->__GetItem(i)->__Field(HX_CSTRING("x"))) + HX_CSTRING(" ")) + ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundRepeatValue(value->__GetItem(i)->__Field(HX_CSTRING("y")))));
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2238)
			if (((i < (value->__Field(HX_CSTRING("length")) - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2239)
				hx::AddEq(cssBackgroundRepeat,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2244)
	return cssBackgroundRepeat;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundRepeat,return )

::String UnitManager_obj::getCSSBackgroundRepeatValue( ::cocktail::core::style::BackgroundRepeatValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSBackgroundRepeatValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2249)
	::String cssBackgroundRepeatValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2251)
	{
::cocktail::core::style::BackgroundRepeatValue _switch_68 = (value);
		switch((_switch_68)->GetIndex()){
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2253)
				cssBackgroundRepeatValue = HX_CSTRING("no-repeat");
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2256)
				cssBackgroundRepeatValue = HX_CSTRING("repeat");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2259)
				cssBackgroundRepeatValue = HX_CSTRING("round");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2262)
				cssBackgroundRepeatValue = HX_CSTRING("space");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2266)
	return cssBackgroundRepeatValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSBackgroundRepeatValue,return )

::String UnitManager_obj::getCSSCursor( ::cocktail::core::style::Cursor value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSCursor")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2278)
	::String cssCursorValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2280)
	{
::cocktail::core::style::Cursor _switch_69 = (value);
		switch((_switch_69)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2282)
				cssCursorValue = HX_CSTRING("auto");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2285)
				cssCursorValue = HX_CSTRING("crosshair");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2288)
				cssCursorValue = HX_CSTRING("default");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2291)
				cssCursorValue = HX_CSTRING("pointer");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2295)
	return cssCursorValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSCursor,return )

::String UnitManager_obj::getCSSImageValue( ::cocktail::core::unit::ImageValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSImageValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2306)
	::String cssImageValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2308)
	{
::cocktail::core::unit::ImageValue _switch_70 = (value);
		switch((_switch_70)->GetIndex()){
			case 0: {
				::String value1 = _switch_70->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2310)
					cssImageValue = ((HX_CSTRING("url(\"") + value1) + HX_CSTRING("\")"));
				}
			}
			;break;
			case 1: {
				Dynamic value1 = _switch_70->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2313)
					cssImageValue = ((HX_CSTRING("image(") + ::cocktail::core::unit::UnitManager_obj::getCSSImageList(value1)) + HX_CSTRING(")"));
				}
			}
			;break;
			case 2: {
				::cocktail::core::unit::GradientValue value1 = _switch_70->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2316)
					cssImageValue = ::cocktail::core::unit::UnitManager_obj::getCSSGradientValue(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2320)
	return cssImageValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSImageValue,return )

::String UnitManager_obj::getCSSImageList( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSImageList")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2325)
	::String cssImageList = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2327)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2327)
		int _g1 = (int)0;
		int _g = value->__Field(HX_CSTRING("urls"))->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2327)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2327)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2329)
			hx::AddEq(cssImageList,((HX_CSTRING("\"") + value->__Field(HX_CSTRING("urls"))->__GetItem(i)) + HX_CSTRING("\"")));
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2331)
			if (((i < (value->__Field(HX_CSTRING("urls"))->__Field(HX_CSTRING("length")) - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2332)
				hx::AddEq(cssImageList,HX_CSTRING(","));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2336)
				hx::AddEq(cssImageList,(HX_CSTRING(",") + ::cocktail::core::unit::UnitManager_obj::getCSSColor(value->__Field(HX_CSTRING("fallbackColor")))));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2341)
	return cssImageList;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSImageList,return )

::String UnitManager_obj::getCSSGradientValue( ::cocktail::core::unit::GradientValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSGradientValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2346)
	::String cssGradientValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2348)
	{
::cocktail::core::unit::GradientValue _switch_71 = (value);
		switch((_switch_71)->GetIndex()){
			case 0: {
				Dynamic value1 = _switch_71->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2350)
					cssGradientValue = ((HX_CSTRING("linear-gradient(") + ::cocktail::core::unit::UnitManager_obj::getCSSLinearGradientValue(value1)) + HX_CSTRING(")"));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2354)
	return cssGradientValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSGradientValue,return )

::String UnitManager_obj::getCSSLinearGradientValue( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSLinearGradientValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2359)
	::String cssLinearGradientValue = ((::cocktail::core::unit::UnitManager_obj::getCSSGradientAngle(value->__Field(HX_CSTRING("angle"))) + HX_CSTRING(",")) + ::cocktail::core::unit::UnitManager_obj::getCSSColorStopsValue(value->__Field(HX_CSTRING("colorStops"))));
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2360)
	return cssLinearGradientValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSLinearGradientValue,return )

::String UnitManager_obj::getCSSColorStopsValue( Dynamic value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSColorStopsValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2365)
	::String cssColorStopsData = HX_CSTRING("");
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2367)
	{
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2367)
		int _g1 = (int)0;
		int _g = value->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2367)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2367)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2369)
			hx::AddEq(cssColorStopsData,((::cocktail::core::unit::UnitManager_obj::getCSSColor(value->__GetItem(i)->__Field(HX_CSTRING("color"))) + HX_CSTRING(" ")) + ::cocktail::core::unit::UnitManager_obj::getCSSColorStopValue(value->__GetItem(i)->__Field(HX_CSTRING("stop")))));
			HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2371)
			if (((i < (value->__Field(HX_CSTRING("length")) - (int)1)))){
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2372)
				hx::AddEq(cssColorStopsData,HX_CSTRING(","));
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2377)
	return cssColorStopsData;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSColorStopsValue,return )

::String UnitManager_obj::getCSSColorStopValue( ::cocktail::core::unit::GradientStopValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSColorStopValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2382)
	::String cssColorStopValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2384)
	{
::cocktail::core::unit::GradientStopValue _switch_72 = (value);
		switch((_switch_72)->GetIndex()){
			case 1: {
				int value1 = _switch_72->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2386)
					cssColorStopValue = ::cocktail::core::unit::UnitManager_obj::getCSSPercentValue(value1);
				}
			}
			;break;
			case 0: {
				::cocktail::core::unit::Length value1 = _switch_72->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2389)
					cssColorStopValue = ::cocktail::core::unit::UnitManager_obj::getCSSLength(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2393)
	return cssColorStopValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSColorStopValue,return )

::String UnitManager_obj::getCSSGradientAngle( ::cocktail::core::unit::GradientAngle value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSGradientAngle")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2398)
	::String cssGradientAngle;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2400)
	{
::cocktail::core::unit::GradientAngle _switch_73 = (value);
		switch((_switch_73)->GetIndex()){
			case 0: {
				::cocktail::core::unit::Angle value1 = _switch_73->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2402)
					cssGradientAngle = ::cocktail::core::unit::UnitManager_obj::getCSSAngle(value1);
				}
			}
			;break;
			case 2: {
				::cocktail::core::unit::GradientCornerValue value1 = _switch_73->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2405)
					cssGradientAngle = ::cocktail::core::unit::UnitManager_obj::getCSSCornerValue(value1);
				}
			}
			;break;
			case 1: {
				::cocktail::core::unit::GradientSideValue value1 = _switch_73->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2408)
					cssGradientAngle = ::cocktail::core::unit::UnitManager_obj::getCSSSideValue(value1);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2412)
	return cssGradientAngle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSGradientAngle,return )

::String UnitManager_obj::getCSSSideValue( ::cocktail::core::unit::GradientSideValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSSideValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2417)
	::String cssSideValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2419)
	{
::cocktail::core::unit::GradientSideValue _switch_74 = (value);
		switch((_switch_74)->GetIndex()){
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2421)
				cssSideValue = HX_CSTRING("bottom");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2424)
				cssSideValue = HX_CSTRING("left");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2427)
				cssSideValue = HX_CSTRING("right");
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2430)
				cssSideValue = HX_CSTRING("top");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2434)
	return cssSideValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSSideValue,return )

::String UnitManager_obj::getCSSCornerValue( ::cocktail::core::unit::GradientCornerValue value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSCornerValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2439)
	::String cssCornerValue;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2441)
	{
::cocktail::core::unit::GradientCornerValue _switch_75 = (value);
		switch((_switch_75)->GetIndex()){
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2443)
				cssCornerValue = HX_CSTRING("left bottom");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2446)
				cssCornerValue = HX_CSTRING("right bottom");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2449)
				cssCornerValue = HX_CSTRING("left top");
			}
			;break;
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2452)
				cssCornerValue = HX_CSTRING("right top");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2456)
	return cssCornerValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSCornerValue,return )

::String UnitManager_obj::getCSSColor( ::cocktail::core::unit::CSSColor value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSColor")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2461)
	::String cssColor;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2463)
	{
::cocktail::core::unit::CSSColor _switch_76 = (value);
		switch((_switch_76)->GetIndex()){
			case 2: {
				::String value1 = _switch_76->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2465)
					cssColor = value1;
				}
			}
			;break;
			case 0: {
				int blue = _switch_76->__Param(2);
				int green = _switch_76->__Param(1);
				int red = _switch_76->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2468)
					cssColor = ((((((HX_CSTRING("rgb(") + red) + HX_CSTRING(",")) + green) + HX_CSTRING(",")) + blue) + HX_CSTRING(")"));
				}
			}
			;break;
			case 1: {
				double alpha = _switch_76->__Param(3);
				int blue = _switch_76->__Param(2);
				int green = _switch_76->__Param(1);
				int red = _switch_76->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2471)
					cssColor = ((((((((HX_CSTRING("rgba(") + red) + HX_CSTRING(",")) + green) + HX_CSTRING(",")) + blue) + HX_CSTRING(",")) + alpha) + HX_CSTRING(")"));
				}
			}
			;break;
			case 3: {
				::cocktail::core::unit::ColorKeyword value1 = _switch_76->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2474)
					cssColor = ::cocktail::core::unit::UnitManager_obj::getColorFromKeyword(value1);
				}
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2477)
				cssColor = HX_CSTRING("transparent");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2481)
	return cssColor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSColor,return )

::String UnitManager_obj::getCSSLength( ::cocktail::core::unit::Length lengthValue){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSLength")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2486)
	::String cssLength;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2488)
	{
::cocktail::core::unit::Length _switch_77 = (lengthValue);
		switch((_switch_77)->GetIndex()){
			case 0: {
				double pixelValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2490)
					cssLength = (::Std_obj::string(pixelValue) + HX_CSTRING("px"));
				}
			}
			;break;
			case 3: {
				double pointValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2493)
					cssLength = (::Std_obj::string(pointValue) + HX_CSTRING("pt"));
				}
			}
			;break;
			case 2: {
				double milimetersValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2496)
					cssLength = (::Std_obj::string(milimetersValue) + HX_CSTRING("mm"));
				}
			}
			;break;
			case 4: {
				double picasValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2499)
					cssLength = (::Std_obj::string(picasValue) + HX_CSTRING("pc"));
				}
			}
			;break;
			case 1: {
				double centimetersValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2502)
					cssLength = (::Std_obj::string(centimetersValue) + HX_CSTRING("cm"));
				}
			}
			;break;
			case 5: {
				double inchesValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2505)
					cssLength = (::Std_obj::string(inchesValue) + HX_CSTRING("in"));
				}
			}
			;break;
			case 6: {
				double emValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2508)
					cssLength = (::Std_obj::string(emValue) + HX_CSTRING("em"));
				}
			}
			;break;
			case 7: {
				double exValue = _switch_77->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2511)
					cssLength = (::Std_obj::string(exValue) + HX_CSTRING("ex"));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2515)
	return cssLength;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSLength,return )

::String UnitManager_obj::getCSSPercentValue( int value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSPercentValue")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2519)
	return (::Std_obj::string(value) + HX_CSTRING("%"));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSPercentValue,return )

::String UnitManager_obj::getCSSAngle( ::cocktail::core::unit::Angle value){
	HX_SOURCE_PUSH("UnitManager_obj::getCSSAngle")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2525)
	::String cssAngle;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2527)
	{
::cocktail::core::unit::Angle _switch_78 = (value);
		switch((_switch_78)->GetIndex()){
			case 0: {
				double value1 = _switch_78->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2529)
					cssAngle = (::Std_obj::string(value1) + HX_CSTRING("deg"));
				}
			}
			;break;
			case 2: {
				double value1 = _switch_78->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2532)
					cssAngle = (::Std_obj::string(value1) + HX_CSTRING("rad"));
				}
			}
			;break;
			case 1: {
				double value1 = _switch_78->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2535)
					cssAngle = (::Std_obj::string(value1) + HX_CSTRING("grad"));
				}
			}
			;break;
			case 3: {
				double value1 = _switch_78->__Param(0);
{
					HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2538)
					cssAngle = (::Std_obj::string(value1) + HX_CSTRING("turn"));
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2542)
	return cssAngle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getCSSAngle,return )

::String UnitManager_obj::getColorFromKeyword( ::cocktail::core::unit::ColorKeyword value){
	HX_SOURCE_PUSH("UnitManager_obj::getColorFromKeyword")
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2547)
	::String cssColor;
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2549)
	{
::cocktail::core::unit::ColorKeyword _switch_79 = (value);
		switch((_switch_79)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2551)
				cssColor = HX_CSTRING("aqua");
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2554)
				cssColor = HX_CSTRING("black");
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2557)
				cssColor = HX_CSTRING("blue");
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2560)
				cssColor = HX_CSTRING("fuchsia");
			}
			;break;
			case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2563)
				cssColor = HX_CSTRING("gray");
			}
			;break;
			case 5: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2566)
				cssColor = HX_CSTRING("green");
			}
			;break;
			case 6: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2569)
				cssColor = HX_CSTRING("lime");
			}
			;break;
			case 7: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2572)
				cssColor = HX_CSTRING("maroon");
			}
			;break;
			case 8: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2575)
				cssColor = HX_CSTRING("navy");
			}
			;break;
			case 9: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2578)
				cssColor = HX_CSTRING("olive");
			}
			;break;
			case 10: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2581)
				cssColor = HX_CSTRING("orange");
			}
			;break;
			case 11: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2584)
				cssColor = HX_CSTRING("purple");
			}
			;break;
			case 12: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2587)
				cssColor = HX_CSTRING("red");
			}
			;break;
			case 13: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2590)
				cssColor = HX_CSTRING("silver");
			}
			;break;
			case 14: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2593)
				cssColor = HX_CSTRING("teal");
			}
			;break;
			case 15: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2596)
				cssColor = HX_CSTRING("white");
			}
			;break;
			case 16: {
				HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2599)
				cssColor = HX_CSTRING("yellow");
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/unit/UnitManager.hx",2603)
	return cssColor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UnitManager_obj,getColorFromKeyword,return )


UnitManager_obj::UnitManager_obj()
{
}

void UnitManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UnitManager);
	HX_MARK_END_CLASS();
}

Dynamic UnitManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"trim") ) { return trim_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"clearEnum") ) { return clearEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"colorEnum") ) { return colorEnum_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cursorEnum") ) { return cursorEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"string2RGB") ) { return string2RGB_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"displayEnum") ) { return displayEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"string2RGBA") ) { return string2RGBA_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSClear") ) { return getCSSClear_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSColor") ) { return getCSSColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSAngle") ) { return getCSSAngle_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"boxStyleEnum") ) { return boxStyleEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"overflowEnum") ) { return overflowEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"positionEnum") ) { return positionEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"cssFloatEnum") ) { return cssFloatEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"string2VUnit") ) { return string2VUnit_dyn(); }
		if (HX_FIELD_EQ(inName,"string2VList") ) { return string2VList_dyn(); }
		if (HX_FIELD_EQ(inName,"string2Array") ) { return string2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSMargin") ) { return getCSSMargin_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSCursor") ) { return getCSSCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSLength") ) { return getCSSLength_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"textAlignEnum") ) { return textAlignEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"fontStyleEnum") ) { return fontStyleEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"string2Length") ) { return string2Length_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSDisplay") ) { return getCSSDisplay_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSOpacity") ) { return getCSSOpacity_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSPadding") ) { return getCSSPadding_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"whiteSpaceEnum") ) { return whiteSpaceEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"fontWeightEnum") ) { return fontWeightEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"visibilityEnum") ) { return visibilityEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"fontFamilyEnum") ) { return fontFamilyEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"lineHeightEnum") ) { return lineHeightEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"textIndentEnum") ) { return textIndentEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"string2URLData") ) { return string2URLData_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSPosition") ) { return getCSSPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSOverflow") ) { return getCSSOverflow_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFontSize") ) { return getCSSFontSize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"fontVariantEnum") ) { return fontVariantEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"wordSpacingEnum") ) { return wordSpacingEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getRadFromAngle") ) { return getRadFromAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSTransform") ) { return getCSSTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSDimension") ) { return getCSSDimension_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFontStyle") ) { return getCSSFontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSTextAlign") ) { return getCSSTextAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSImageList") ) { return getCSSImageList_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSSideValue") ) { return getCSSSideValue_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getCSSVisibility") ) { return getCSSVisibility_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSLineHeight") ) { return getCSSLineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFontWeight") ) { return getCSSFontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFontFamily") ) { return getCSSFontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSWhiteSpace") ) { return getCSSWhiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSTextIndent") ) { return getCSSTextIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSImageValue") ) { return getCSSImageValue_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"verticalAlignEnum") ) { return verticalAlignEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"textTransformEnum") ) { return textTransformEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"letterSpacingEnum") ) { return letterSpacingEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getLargerFontSize") ) { return getLargerFontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSTranslation") ) { return getCSSTranslation_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFontVariant") ) { return getCSSFontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSWordSpacing") ) { return getCSSWordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSCornerValue") ) { return getCSSCornerValue_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundSizeEnum") ) { return backgroundSizeEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundClipEnum") ) { return backgroundClipEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixelFromLength") ) { return getPixelFromLength_dyn(); }
		if (HX_FIELD_EQ(inName,"getDegreeFromAngle") ) { return getDegreeFromAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"getSmallerFontSize") ) { return getSmallerFontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSPercentValue") ) { return getCSSPercentValue_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"backgroundImageEnum") ) { return backgroundImageEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getPixelFromPercent") ) { return getPixelFromPercent_dyn(); }
		if (HX_FIELD_EQ(inName,"getPercentFromPixel") ) { return getPercentFromPixel_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSFloatAsString") ) { return getCSSFloatAsString_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSVerticalAlign") ) { return getCSSVerticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSTextTransform") ) { return getCSSTextTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSLetterSpacing") ) { return getCSSLetterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSGradientValue") ) { return getCSSGradientValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSGradientAngle") ) { return getCSSGradientAngle_dyn(); }
		if (HX_FIELD_EQ(inName,"getColorFromKeyword") ) { return getColorFromKeyword_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"backgroundRepeatEnum") ) { return backgroundRepeatEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"backgroundOriginEnum") ) { return backgroundOriginEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSPositionOffset") ) { return getCSSPositionOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundClip") ) { return getCSSBackgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundSize") ) { return getCSSBackgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSColorStopValue") ) { return getCSSColorStopValue_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getCSSTransformOrigin") ) { return getCSSTransformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundColor") ) { return getCSSBackgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundImage") ) { return getCSSBackgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSColorStopsValue") ) { return getCSSColorStopsValue_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"backgroundPositionEnum") ) { return backgroundPositionEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundOrigin") ) { return getCSSBackgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundRepeat") ) { return getCSSBackgroundRepeat_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getCSSTransformFunction") ) { return getCSSTransformFunction_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"constrainedDimensionEnum") ) { return constrainedDimensionEnum_dyn(); }
		if (HX_FIELD_EQ(inName,"getColorDataFromCSSColor") ) { return getColorDataFromCSSColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundPosition") ) { return getCSSBackgroundPosition_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"getCSSBackgroundPositionX") ) { return getCSSBackgroundPositionX_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSBackgroundPositionY") ) { return getCSSBackgroundPositionY_dyn(); }
		if (HX_FIELD_EQ(inName,"getCSSLinearGradientValue") ) { return getCSSLinearGradientValue_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"getCSSConstrainedDimension") ) { return getCSSConstrainedDimension_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"getCSSBackgroundRepeatValue") ) { return getCSSBackgroundRepeatValue_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getColorDataFromColorKeyword") ) { return getColorDataFromColorKeyword_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"getCSSBackgroundSizeDimension") ) { return getCSSBackgroundSizeDimension_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"getCSSBackgroundSizeDimensions") ) { return getCSSBackgroundSizeDimensions_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"getFontSizeFromAbsoluteSizeValue") ) { return getFontSizeFromAbsoluteSizeValue_dyn(); }
		if (HX_FIELD_EQ(inName,"getFontSizeFromRelativeSizeValue") ) { return getFontSizeFromRelativeSizeValue_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic UnitManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void UnitManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("boxStyleEnum"),
	HX_CSTRING("constrainedDimensionEnum"),
	HX_CSTRING("displayEnum"),
	HX_CSTRING("overflowEnum"),
	HX_CSTRING("verticalAlignEnum"),
	HX_CSTRING("clearEnum"),
	HX_CSTRING("positionEnum"),
	HX_CSTRING("whiteSpaceEnum"),
	HX_CSTRING("textAlignEnum"),
	HX_CSTRING("fontWeightEnum"),
	HX_CSTRING("fontStyleEnum"),
	HX_CSTRING("fontVariantEnum"),
	HX_CSTRING("textTransformEnum"),
	HX_CSTRING("visibilityEnum"),
	HX_CSTRING("cursorEnum"),
	HX_CSTRING("wordSpacingEnum"),
	HX_CSTRING("backgroundImageEnum"),
	HX_CSTRING("backgroundRepeatEnum"),
	HX_CSTRING("backgroundOriginEnum"),
	HX_CSTRING("backgroundSizeEnum"),
	HX_CSTRING("backgroundPositionEnum"),
	HX_CSTRING("backgroundClipEnum"),
	HX_CSTRING("fontFamilyEnum"),
	HX_CSTRING("letterSpacingEnum"),
	HX_CSTRING("lineHeightEnum"),
	HX_CSTRING("textIndentEnum"),
	HX_CSTRING("cssFloatEnum"),
	HX_CSTRING("colorEnum"),
	HX_CSTRING("string2RGBA"),
	HX_CSTRING("string2RGB"),
	HX_CSTRING("trim"),
	HX_CSTRING("string2VUnit"),
	HX_CSTRING("string2Length"),
	HX_CSTRING("string2URLData"),
	HX_CSTRING("string2VList"),
	HX_CSTRING("string2Array"),
	HX_CSTRING("getPixelFromLength"),
	HX_CSTRING("getFontSizeFromAbsoluteSizeValue"),
	HX_CSTRING("getFontSizeFromRelativeSizeValue"),
	HX_CSTRING("getPixelFromPercent"),
	HX_CSTRING("getPercentFromPixel"),
	HX_CSTRING("getColorDataFromCSSColor"),
	HX_CSTRING("getRadFromAngle"),
	HX_CSTRING("getDegreeFromAngle"),
	HX_CSTRING("getColorDataFromColorKeyword"),
	HX_CSTRING("getLargerFontSize"),
	HX_CSTRING("getSmallerFontSize"),
	HX_CSTRING("getCSSDisplay"),
	HX_CSTRING("getCSSFloatAsString"),
	HX_CSTRING("getCSSClear"),
	HX_CSTRING("getCSSPosition"),
	HX_CSTRING("getCSSOverflow"),
	HX_CSTRING("getCSSOpacity"),
	HX_CSTRING("getCSSVisibility"),
	HX_CSTRING("getCSSTransform"),
	HX_CSTRING("getCSSTransformFunction"),
	HX_CSTRING("getCSSTranslation"),
	HX_CSTRING("getCSSTransformOrigin"),
	HX_CSTRING("getCSSMargin"),
	HX_CSTRING("getCSSPadding"),
	HX_CSTRING("getCSSDimension"),
	HX_CSTRING("getCSSPositionOffset"),
	HX_CSTRING("getCSSConstrainedDimension"),
	HX_CSTRING("getCSSVerticalAlign"),
	HX_CSTRING("getCSSLineHeight"),
	HX_CSTRING("getCSSFontSize"),
	HX_CSTRING("getCSSFontWeight"),
	HX_CSTRING("getCSSFontStyle"),
	HX_CSTRING("getCSSFontVariant"),
	HX_CSTRING("getCSSFontFamily"),
	HX_CSTRING("getCSSTextAlign"),
	HX_CSTRING("getCSSWhiteSpace"),
	HX_CSTRING("getCSSTextTransform"),
	HX_CSTRING("getCSSTextIndent"),
	HX_CSTRING("getCSSLetterSpacing"),
	HX_CSTRING("getCSSWordSpacing"),
	HX_CSTRING("getCSSBackgroundColor"),
	HX_CSTRING("getCSSBackgroundOrigin"),
	HX_CSTRING("getCSSBackgroundClip"),
	HX_CSTRING("getCSSBackgroundImage"),
	HX_CSTRING("getCSSBackgroundSize"),
	HX_CSTRING("getCSSBackgroundSizeDimensions"),
	HX_CSTRING("getCSSBackgroundSizeDimension"),
	HX_CSTRING("getCSSBackgroundPosition"),
	HX_CSTRING("getCSSBackgroundPositionX"),
	HX_CSTRING("getCSSBackgroundPositionY"),
	HX_CSTRING("getCSSBackgroundRepeat"),
	HX_CSTRING("getCSSBackgroundRepeatValue"),
	HX_CSTRING("getCSSCursor"),
	HX_CSTRING("getCSSImageValue"),
	HX_CSTRING("getCSSImageList"),
	HX_CSTRING("getCSSGradientValue"),
	HX_CSTRING("getCSSLinearGradientValue"),
	HX_CSTRING("getCSSColorStopsValue"),
	HX_CSTRING("getCSSColorStopValue"),
	HX_CSTRING("getCSSGradientAngle"),
	HX_CSTRING("getCSSSideValue"),
	HX_CSTRING("getCSSCornerValue"),
	HX_CSTRING("getCSSColor"),
	HX_CSTRING("getCSSLength"),
	HX_CSTRING("getCSSPercentValue"),
	HX_CSTRING("getCSSAngle"),
	HX_CSTRING("getColorFromKeyword"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class UnitManager_obj::__mClass;

void UnitManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.unit.UnitManager"), hx::TCanCast< UnitManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void UnitManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace unit
