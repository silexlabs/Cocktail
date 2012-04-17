#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_cocktail_core_style_BackgroundSize
#include <cocktail/core/style/BackgroundSize.h>
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
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
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
#ifndef INCLUDED_cocktail_core_style_adapter_Style
#include <cocktail/core/style/adapter/Style.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_CSSColor
#include <cocktail/core/unit/CSSColor.h>
#endif
#ifndef INCLUDED_cocktail_core_unit_UnitManager
#include <cocktail/core/unit/UnitManager.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace adapter{

Void Style_obj::__construct(::cocktail::core::style::CoreStyle coreStyle)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",118)
	this->_coreStyle = coreStyle;
}
;
	return null();
}

Style_obj::~Style_obj() { }

Dynamic Style_obj::__CreateEmpty() { return  new Style_obj; }
hx::ObjectPtr< Style_obj > Style_obj::__new(::cocktail::core::style::CoreStyle coreStyle)
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct(coreStyle);
	return result;}

Dynamic Style_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Style_obj > result = new Style_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Style_obj::get_opacity( ){
	HX_SOURCE_PUSH("Style_obj::get_opacity")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",127)
	return ::cocktail::core::unit::UnitManager_obj::getCSSOpacity(this->_coreStyle->getOpacity());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_opacity,return )

::String Style_obj::set_opacity( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_opacity")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",134)
	this->_coreStyle->setOpacity(::Std_obj::parseFloat(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",135)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_opacity,return )

::String Style_obj::get_visibility( ){
	HX_SOURCE_PUSH("Style_obj::get_visibility")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",139)
	return ::cocktail::core::unit::UnitManager_obj::getCSSVisibility(this->_coreStyle->getVisibility());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_visibility,return )

::String Style_obj::set_visibility( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_visibility")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",145)
	this->_coreStyle->setVisibility(::cocktail::core::unit::UnitManager_obj::visibilityEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",146)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_visibility,return )

::String Style_obj::get_marginLeft( ){
	HX_SOURCE_PUSH("Style_obj::get_marginLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",150)
	return ::cocktail::core::unit::UnitManager_obj::getCSSMargin(this->_coreStyle->getMarginLeft());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_marginLeft,return )

::String Style_obj::set_marginLeft( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_marginLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",156)
	this->_coreStyle->setMarginLeft(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Margin >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",157)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_marginLeft,return )

::String Style_obj::get_marginRight( ){
	HX_SOURCE_PUSH("Style_obj::get_marginRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",161)
	return ::cocktail::core::unit::UnitManager_obj::getCSSMargin(this->_coreStyle->getMarginRight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_marginRight,return )

::String Style_obj::set_marginRight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_marginRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",167)
	this->_coreStyle->setMarginRight(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Margin >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",168)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_marginRight,return )

::String Style_obj::get_marginTop( ){
	HX_SOURCE_PUSH("Style_obj::get_marginTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",172)
	return ::cocktail::core::unit::UnitManager_obj::getCSSMargin(this->_coreStyle->getMarginTop());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_marginTop,return )

::String Style_obj::set_marginTop( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_marginTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",178)
	this->_coreStyle->setMarginTop(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Margin >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",179)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_marginTop,return )

::String Style_obj::get_marginBottom( ){
	HX_SOURCE_PUSH("Style_obj::get_marginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",183)
	return ::cocktail::core::unit::UnitManager_obj::getCSSMargin(this->_coreStyle->getMarginBottom());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_marginBottom,return )

::String Style_obj::set_marginBottom( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_marginBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",189)
	this->_coreStyle->setMarginBottom(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Margin >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",190)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_marginBottom,return )

::String Style_obj::get_paddingLeft( ){
	HX_SOURCE_PUSH("Style_obj::get_paddingLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",194)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPadding(this->_coreStyle->getPaddingLeft());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_paddingLeft,return )

::String Style_obj::set_paddingLeft( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_paddingLeft")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",200)
	this->_coreStyle->setPaddingLeft(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Padding >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",201)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_paddingLeft,return )

::String Style_obj::get_paddingRight( ){
	HX_SOURCE_PUSH("Style_obj::get_paddingRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",205)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPadding(this->_coreStyle->getPaddingRight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_paddingRight,return )

::String Style_obj::set_paddingRight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_paddingRight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",211)
	this->_coreStyle->setPaddingRight(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Padding >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",212)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_paddingRight,return )

::String Style_obj::get_paddingTop( ){
	HX_SOURCE_PUSH("Style_obj::get_paddingTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",216)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPadding(this->_coreStyle->getPaddingTop());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_paddingTop,return )

::String Style_obj::set_paddingTop( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_paddingTop")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",222)
	this->_coreStyle->setPaddingTop(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Padding >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",223)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_paddingTop,return )

::String Style_obj::get_paddingBottom( ){
	HX_SOURCE_PUSH("Style_obj::get_paddingBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",227)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPadding(this->_coreStyle->getPaddingBottom());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_paddingBottom,return )

::String Style_obj::set_paddingBottom( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_paddingBottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",233)
	this->_coreStyle->setPaddingBottom(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Padding >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",234)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_paddingBottom,return )

::String Style_obj::get_display( ){
	HX_SOURCE_PUSH("Style_obj::get_display")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",238)
	return ::cocktail::core::unit::UnitManager_obj::getCSSDisplay(this->_coreStyle->getDisplay());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_display,return )

::String Style_obj::set_display( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_display")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",244)
	this->_coreStyle->setDisplay(::cocktail::core::unit::UnitManager_obj::displayEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",245)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_display,return )

::String Style_obj::get_position( ){
	HX_SOURCE_PUSH("Style_obj::get_position")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",249)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPosition(this->_coreStyle->getPosition());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_position,return )

::String Style_obj::set_position( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_position")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",255)
	this->_coreStyle->setPosition(::cocktail::core::unit::UnitManager_obj::positionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",256)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_position,return )

::String Style_obj::get_width( ){
	HX_SOURCE_PUSH("Style_obj::get_width")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",260)
	return ::cocktail::core::unit::UnitManager_obj::getCSSDimension(this->_coreStyle->getWidth());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_width,return )

::String Style_obj::set_width( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_width")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",266)
	this->_coreStyle->setWidth(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Dimension >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",267)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_width,return )

::String Style_obj::get_height( ){
	HX_SOURCE_PUSH("Style_obj::get_height")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",271)
	return ::cocktail::core::unit::UnitManager_obj::getCSSDimension(this->_coreStyle->getHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_height,return )

::String Style_obj::set_height( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_height")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",277)
	this->_coreStyle->setHeight(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::Dimension >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",278)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_height,return )

::String Style_obj::get_minHeight( ){
	HX_SOURCE_PUSH("Style_obj::get_minHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",282)
	return ::cocktail::core::unit::UnitManager_obj::getCSSConstrainedDimension(this->_coreStyle->getMinHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_minHeight,return )

::String Style_obj::set_minHeight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_minHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",288)
	this->_coreStyle->setMinHeight(::cocktail::core::unit::UnitManager_obj::constrainedDimensionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",289)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_minHeight,return )

::String Style_obj::get_maxHeight( ){
	HX_SOURCE_PUSH("Style_obj::get_maxHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",293)
	return ::cocktail::core::unit::UnitManager_obj::getCSSConstrainedDimension(this->_coreStyle->getMaxHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_maxHeight,return )

::String Style_obj::set_maxHeight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_maxHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",299)
	this->_coreStyle->setMaxHeight(::cocktail::core::unit::UnitManager_obj::constrainedDimensionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",300)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_maxHeight,return )

::String Style_obj::get_minWidth( ){
	HX_SOURCE_PUSH("Style_obj::get_minWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",304)
	return ::cocktail::core::unit::UnitManager_obj::getCSSConstrainedDimension(this->_coreStyle->getMinWidth());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_minWidth,return )

::String Style_obj::set_minWidth( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_minWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",310)
	this->_coreStyle->setMinWidth(::cocktail::core::unit::UnitManager_obj::constrainedDimensionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",311)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_minWidth,return )

::String Style_obj::get_maxWidth( ){
	HX_SOURCE_PUSH("Style_obj::get_maxWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",315)
	return ::cocktail::core::unit::UnitManager_obj::getCSSConstrainedDimension(this->_coreStyle->getMaxWidth());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_maxWidth,return )

::String Style_obj::set_maxWidth( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_maxWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",321)
	this->_coreStyle->setMaxWidth(::cocktail::core::unit::UnitManager_obj::constrainedDimensionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",322)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_maxWidth,return )

::String Style_obj::get_top( ){
	HX_SOURCE_PUSH("Style_obj::get_top")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",326)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPositionOffset(this->_coreStyle->getTop());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_top,return )

::String Style_obj::set_top( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_top")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",332)
	this->_coreStyle->setTop(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::PositionOffset >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",333)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_top,return )

::String Style_obj::get_left( ){
	HX_SOURCE_PUSH("Style_obj::get_left")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",337)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPositionOffset(this->_coreStyle->getLeft());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_left,return )

::String Style_obj::set_left( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_left")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",343)
	this->_coreStyle->setLeft(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::PositionOffset >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",344)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_left,return )

::String Style_obj::get_bottom( ){
	HX_SOURCE_PUSH("Style_obj::get_bottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",348)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPositionOffset(this->_coreStyle->getBottom());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_bottom,return )

::String Style_obj::set_bottom( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_bottom")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",354)
	this->_coreStyle->setBottom(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::PositionOffset >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",355)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_bottom,return )

::String Style_obj::get_right( ){
	HX_SOURCE_PUSH("Style_obj::get_right")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",359)
	return ::cocktail::core::unit::UnitManager_obj::getCSSPositionOffset(this->_coreStyle->getRight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_right,return )

::String Style_obj::set_right( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_right")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",365)
	this->_coreStyle->setRight(::cocktail::core::unit::UnitManager_obj::boxStyleEnum(hx::ClassOf< ::cocktail::core::style::PositionOffset >(),value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",366)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_right,return )

::String Style_obj::get_CSSFloat( ){
	HX_SOURCE_PUSH("Style_obj::get_CSSFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",370)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFloatAsString(this->_coreStyle->getCSSFloat());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_CSSFloat,return )

::String Style_obj::set_CSSFloat( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_CSSFloat")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",376)
	this->_coreStyle->setCSSFloat(::cocktail::core::unit::UnitManager_obj::cssFloatEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",377)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_CSSFloat,return )

::String Style_obj::get_clear( ){
	HX_SOURCE_PUSH("Style_obj::get_clear")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",381)
	return ::cocktail::core::unit::UnitManager_obj::getCSSClear(this->_coreStyle->getClear());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_clear,return )

::String Style_obj::set_clear( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_clear")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",387)
	this->_coreStyle->setClear(::cocktail::core::unit::UnitManager_obj::clearEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",388)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_clear,return )

::String Style_obj::get_fontSize( ){
	HX_SOURCE_PUSH("Style_obj::get_fontSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",392)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFontSize(this->_coreStyle->getFontSize());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_fontSize,return )

::String Style_obj::set_fontSize( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_fontSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",397)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_fontSize,return )

::String Style_obj::get_fontWeight( ){
	HX_SOURCE_PUSH("Style_obj::get_fontWeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",402)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFontWeight(this->_coreStyle->getFontWeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_fontWeight,return )

::String Style_obj::set_fontWeight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_fontWeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",408)
	this->_coreStyle->setFontWeight(::cocktail::core::unit::UnitManager_obj::fontWeightEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",409)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_fontWeight,return )

::String Style_obj::get_fontStyle( ){
	HX_SOURCE_PUSH("Style_obj::get_fontStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",413)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFontStyle(this->_coreStyle->getFontStyle());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_fontStyle,return )

::String Style_obj::set_fontStyle( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_fontStyle")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",419)
	this->_coreStyle->setFontStyle(::cocktail::core::unit::UnitManager_obj::fontStyleEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",420)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_fontStyle,return )

::String Style_obj::get_fontFamily( ){
	HX_SOURCE_PUSH("Style_obj::get_fontFamily")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",424)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFontFamily(this->_coreStyle->getFontFamily());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_fontFamily,return )

::String Style_obj::set_fontFamily( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_fontFamily")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",430)
	this->_coreStyle->setFontFamily(::cocktail::core::unit::UnitManager_obj::fontFamilyEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",431)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_fontFamily,return )

::String Style_obj::get_fontVariant( ){
	HX_SOURCE_PUSH("Style_obj::get_fontVariant")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",435)
	return ::cocktail::core::unit::UnitManager_obj::getCSSFontVariant(this->_coreStyle->getFontVariant());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_fontVariant,return )

::String Style_obj::set_fontVariant( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_fontVariant")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",441)
	this->_coreStyle->setFontVariant(::cocktail::core::unit::UnitManager_obj::fontVariantEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",442)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_fontVariant,return )

::String Style_obj::get_textTransform( ){
	HX_SOURCE_PUSH("Style_obj::get_textTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",446)
	return ::cocktail::core::unit::UnitManager_obj::getCSSTextTransform(this->_coreStyle->getTextTransform());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_textTransform,return )

::String Style_obj::set_textTransform( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_textTransform")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",452)
	this->_coreStyle->setTextTransform(::cocktail::core::unit::UnitManager_obj::textTransformEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",453)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_textTransform,return )

::String Style_obj::get_letterSpacing( ){
	HX_SOURCE_PUSH("Style_obj::get_letterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",457)
	return ::cocktail::core::unit::UnitManager_obj::getCSSLetterSpacing(this->_coreStyle->getLetterSpacing());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_letterSpacing,return )

::String Style_obj::set_letterSpacing( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_letterSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",463)
	this->_coreStyle->setLetterSpacing(::cocktail::core::unit::UnitManager_obj::letterSpacingEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",464)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_letterSpacing,return )

::String Style_obj::get_color( ){
	HX_SOURCE_PUSH("Style_obj::get_color")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",468)
	return ::cocktail::core::unit::UnitManager_obj::getCSSColor(this->_coreStyle->getColor());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_color,return )

::String Style_obj::set_color( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_color")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",474)
	this->_coreStyle->setColor(::cocktail::core::unit::UnitManager_obj::colorEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",475)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_color,return )

::String Style_obj::get_wordSpacing( ){
	HX_SOURCE_PUSH("Style_obj::get_wordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",479)
	return ::cocktail::core::unit::UnitManager_obj::getCSSWordSpacing(this->_coreStyle->getWordSpacing());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_wordSpacing,return )

::String Style_obj::set_wordSpacing( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_wordSpacing")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",485)
	this->_coreStyle->setWordSpacing(::cocktail::core::unit::UnitManager_obj::wordSpacingEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",486)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_wordSpacing,return )

::String Style_obj::get_lineHeight( ){
	HX_SOURCE_PUSH("Style_obj::get_lineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",490)
	return ::cocktail::core::unit::UnitManager_obj::getCSSLineHeight(this->_coreStyle->getLineHeight());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_lineHeight,return )

::String Style_obj::set_lineHeight( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_lineHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",496)
	this->_coreStyle->setLineHeight(::cocktail::core::unit::UnitManager_obj::lineHeightEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",497)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_lineHeight,return )

::String Style_obj::get_verticalAlign( ){
	HX_SOURCE_PUSH("Style_obj::get_verticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",501)
	return ::cocktail::core::unit::UnitManager_obj::getCSSVerticalAlign(this->_coreStyle->getVerticalAlign());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_verticalAlign,return )

::String Style_obj::set_verticalAlign( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_verticalAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",507)
	this->_coreStyle->setVerticalAlign(::cocktail::core::unit::UnitManager_obj::verticalAlignEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",508)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_verticalAlign,return )

::String Style_obj::get_textIndent( ){
	HX_SOURCE_PUSH("Style_obj::get_textIndent")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",512)
	return ::cocktail::core::unit::UnitManager_obj::getCSSTextIndent(this->_coreStyle->getTextIndent());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_textIndent,return )

::String Style_obj::set_textIndent( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_textIndent")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",518)
	this->_coreStyle->setTextIndent(::cocktail::core::unit::UnitManager_obj::textIndentEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",519)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_textIndent,return )

::String Style_obj::get_whiteSpace( ){
	HX_SOURCE_PUSH("Style_obj::get_whiteSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",523)
	return ::cocktail::core::unit::UnitManager_obj::getCSSWhiteSpace(this->_coreStyle->getWhiteSpace());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_whiteSpace,return )

::String Style_obj::set_whiteSpace( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_whiteSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",529)
	this->_coreStyle->setWhiteSpace(::cocktail::core::unit::UnitManager_obj::whiteSpaceEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",530)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_whiteSpace,return )

::String Style_obj::get_textAlign( ){
	HX_SOURCE_PUSH("Style_obj::get_textAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",534)
	return ::cocktail::core::unit::UnitManager_obj::getCSSTextAlign(this->_coreStyle->getTextAlign());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_textAlign,return )

::String Style_obj::set_textAlign( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_textAlign")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",540)
	this->_coreStyle->setTextAlign(::cocktail::core::unit::UnitManager_obj::textAlignEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",541)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_textAlign,return )

::String Style_obj::set_backgroundColor( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",546)
	this->_coreStyle->setBackgroundColor(::cocktail::core::unit::UnitManager_obj::colorEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",547)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundColor,return )

::String Style_obj::get_backgroundColor( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundColor")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",551)
	return ::cocktail::core::unit::UnitManager_obj::getCSSColor(this->_coreStyle->getBackgroundColor());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundColor,return )

::String Style_obj::set_backgroundImage( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",557)
	this->_coreStyle->setBackgroundImage(::cocktail::core::unit::UnitManager_obj::backgroundImageEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",558)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundImage,return )

::String Style_obj::get_backgroundImage( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundImage")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",562)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundImage(this->_coreStyle->getBackgroundImage());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundImage,return )

::String Style_obj::set_backgroundRepeat( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundRepeat")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",568)
	this->_coreStyle->setBackgroundRepeat(::cocktail::core::unit::UnitManager_obj::backgroundRepeatEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",569)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundRepeat,return )

::String Style_obj::get_backgroundRepeat( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundRepeat")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",573)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundRepeat(this->_coreStyle->getBackgroundRepeat());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundRepeat,return )

::String Style_obj::set_backgroundSize( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",579)
	this->_coreStyle->setBackgroundSize(::cocktail::core::unit::UnitManager_obj::backgroundSizeEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",580)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundSize,return )

::String Style_obj::get_backgroundSize( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundSize")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",584)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundSize(this->_coreStyle->getBackgroundSize());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundSize,return )

::String Style_obj::set_backgroundClip( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundClip")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",590)
	this->_coreStyle->setBackgroundClip(::cocktail::core::unit::UnitManager_obj::backgroundClipEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",591)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundClip,return )

::String Style_obj::get_backgroundClip( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundClip")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",595)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundClip(this->_coreStyle->getBackgroundClip());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundClip,return )

::String Style_obj::set_backgroundPosition( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",601)
	this->_coreStyle->setBackgroundPosition(::cocktail::core::unit::UnitManager_obj::backgroundPositionEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",602)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundPosition,return )

::String Style_obj::get_backgroundPosition( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundPosition")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",606)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundPosition(this->_coreStyle->getBackgroundPosition());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundPosition,return )

::String Style_obj::set_backgroundOrigin( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_backgroundOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",612)
	this->_coreStyle->setBackgroundOrigin(::cocktail::core::unit::UnitManager_obj::backgroundOriginEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",613)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_backgroundOrigin,return )

::String Style_obj::get_backgroundOrigin( ){
	HX_SOURCE_PUSH("Style_obj::get_backgroundOrigin")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",617)
	return ::cocktail::core::unit::UnitManager_obj::getCSSBackgroundOrigin(this->_coreStyle->getBackgroundOrigin());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_backgroundOrigin,return )

::String Style_obj::get_overflowX( ){
	HX_SOURCE_PUSH("Style_obj::get_overflowX")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",622)
	return ::cocktail::core::unit::UnitManager_obj::getCSSOverflow(this->_coreStyle->getOverflowX());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_overflowX,return )

::String Style_obj::set_overflowX( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_overflowX")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",628)
	this->_coreStyle->setOverflowX(::cocktail::core::unit::UnitManager_obj::overflowEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",629)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_overflowX,return )

::String Style_obj::get_overflowY( ){
	HX_SOURCE_PUSH("Style_obj::get_overflowY")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",633)
	return ::cocktail::core::unit::UnitManager_obj::getCSSOverflow(this->_coreStyle->getOverflowY());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_overflowY,return )

::String Style_obj::set_overflowY( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_overflowY")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",639)
	this->_coreStyle->setOverflowY(::cocktail::core::unit::UnitManager_obj::overflowEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",640)
	return ::cocktail::core::unit::UnitManager_obj::getCSSOverflow(this->_coreStyle->getOverflowY());
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_overflowY,return )

::String Style_obj::set_cursor( ::String value){
	HX_SOURCE_PUSH("Style_obj::set_cursor")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",645)
	this->_coreStyle->setCursor(::cocktail::core::unit::UnitManager_obj::cursorEnum(value));
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",646)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Style_obj,set_cursor,return )

::String Style_obj::get_cursor( ){
	HX_SOURCE_PUSH("Style_obj::get_cursor")
	HX_SOURCE_POS("../../src/cocktail/core/style/adapter/Style.hx",650)
	return ::cocktail::core::unit::UnitManager_obj::getCSSCursor(this->_coreStyle->getCursor());
}


HX_DEFINE_DYNAMIC_FUNC0(Style_obj,get_cursor,return )


Style_obj::Style_obj()
{
}

void Style_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Style);
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(cssFloat,"cssFloat");
	HX_MARK_MEMBER_NAME(clear,"clear");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(marginTop,"marginTop");
	HX_MARK_MEMBER_NAME(marginBottom,"marginBottom");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(paddingTop,"paddingTop");
	HX_MARK_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(minHeight,"minHeight");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(minWidth,"minWidth");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_MARK_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_MARK_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_MARK_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_MARK_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_MARK_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_MEMBER_NAME(fontWeight,"fontWeight");
	HX_MARK_MEMBER_NAME(fontStyle,"fontStyle");
	HX_MARK_MEMBER_NAME(fontFamily,"fontFamily");
	HX_MARK_MEMBER_NAME(fontVariant,"fontVariant");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(lineHeight,"lineHeight");
	HX_MARK_MEMBER_NAME(textTransform,"textTransform");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_MARK_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_MARK_MEMBER_NAME(textAlign,"textAlign");
	HX_MARK_MEMBER_NAME(textIndent,"textIndent");
	HX_MARK_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_MARK_MEMBER_NAME(opacity,"opacity");
	HX_MARK_MEMBER_NAME(visibility,"visibility");
	HX_MARK_MEMBER_NAME(overflowX,"overflowX");
	HX_MARK_MEMBER_NAME(overflowY,"overflowY");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_MEMBER_NAME(_coreStyle,"_coreStyle");
	HX_MARK_END_CLASS();
}

Dynamic Style_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return get_top(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return get_left(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return get_clear(); }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		if (HX_FIELD_EQ(inName,"color") ) { return get_color(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"bottom") ) { return get_bottom(); }
		if (HX_FIELD_EQ(inName,"cursor") ) { return get_cursor(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return get_display(); }
		if (HX_FIELD_EQ(inName,"opacity") ) { return get_opacity(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return get_position(); }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return get_CSSFloat(); }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return get_minWidth(); }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return get_maxWidth(); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return get_fontSize(); }
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"marginTop") ) { return get_marginTop(); }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return get_minHeight(); }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return get_maxHeight(); }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return get_fontStyle(); }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return get_textAlign(); }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return get_overflowX(); }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return get_overflowY(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clear") ) { return get_clear_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clear") ) { return set_clear_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return get_marginLeft(); }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return get_paddingTop(); }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return get_fontWeight(); }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return get_fontFamily(); }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return get_lineHeight(); }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return get_whiteSpace(); }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return get_textIndent(); }
		if (HX_FIELD_EQ(inName,"visibility") ) { return get_visibility(); }
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { return _coreStyle; }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cursor") ) { return set_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cursor") ) { return get_cursor_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"marginRight") ) { return get_marginRight(); }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return get_paddingLeft(); }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return get_fontVariant(); }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return get_wordSpacing(); }
		if (HX_FIELD_EQ(inName,"get_opacity") ) { return get_opacity_dyn(); }
		if (HX_FIELD_EQ(inName,"set_opacity") ) { return set_opacity_dyn(); }
		if (HX_FIELD_EQ(inName,"get_display") ) { return get_display_dyn(); }
		if (HX_FIELD_EQ(inName,"set_display") ) { return set_display_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return get_marginBottom(); }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return get_paddingRight(); }
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return set_position_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minWidth") ) { return get_minWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_minWidth") ) { return set_minWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxWidth") ) { return get_maxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxWidth") ) { return set_maxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_CSSFloat") ) { return get_CSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"set_CSSFloat") ) { return set_CSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontSize") ) { return set_fontSize_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return get_paddingBottom(); }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return get_textTransform(); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return get_letterSpacing(); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return get_verticalAlign(); }
		if (HX_FIELD_EQ(inName,"get_marginTop") ) { return get_marginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginTop") ) { return set_marginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minHeight") ) { return get_minHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_minHeight") ) { return set_minHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxHeight") ) { return get_maxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxHeight") ) { return set_maxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontStyle") ) { return get_fontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontStyle") ) { return set_fontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textAlign") ) { return get_textAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textAlign") ) { return set_textAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowX") ) { return get_overflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_overflowX") ) { return set_overflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowY") ) { return get_overflowY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_overflowY") ) { return set_overflowY_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return get_backgroundSize(); }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return get_backgroundClip(); }
		if (HX_FIELD_EQ(inName,"get_visibility") ) { return get_visibility_dyn(); }
		if (HX_FIELD_EQ(inName,"set_visibility") ) { return set_visibility_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginLeft") ) { return get_marginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginLeft") ) { return set_marginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingTop") ) { return get_paddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingTop") ) { return set_paddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontWeight") ) { return get_fontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontWeight") ) { return set_fontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontFamily") ) { return set_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lineHeight") ) { return get_lineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_lineHeight") ) { return set_lineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textIndent") ) { return get_textIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textIndent") ) { return set_textIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_whiteSpace") ) { return get_whiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"set_whiteSpace") ) { return set_whiteSpace_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return get_backgroundColor(); }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return get_backgroundImage(); }
		if (HX_FIELD_EQ(inName,"get_marginRight") ) { return get_marginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginRight") ) { return set_marginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingLeft") ) { return get_paddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingLeft") ) { return set_paddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontVariant") ) { return get_fontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontVariant") ) { return set_fontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"get_wordSpacing") ) { return get_wordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_wordSpacing") ) { return set_wordSpacing_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return get_backgroundRepeat(); }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return get_backgroundOrigin(); }
		if (HX_FIELD_EQ(inName,"get_marginBottom") ) { return get_marginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginBottom") ) { return set_marginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingRight") ) { return get_paddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingRight") ) { return set_paddingRight_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_paddingBottom") ) { return get_paddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingBottom") ) { return set_paddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textTransform") ) { return get_textTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textTransform") ) { return set_textTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_letterSpacing") ) { return set_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"get_verticalAlign") ) { return get_verticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"set_verticalAlign") ) { return set_verticalAlign_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return get_backgroundPosition(); }
		if (HX_FIELD_EQ(inName,"set_backgroundSize") ) { return set_backgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundSize") ) { return get_backgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundClip") ) { return set_backgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundClip") ) { return get_backgroundClip_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"set_backgroundColor") ) { return set_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundColor") ) { return get_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundImage") ) { return set_backgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundImage") ) { return get_backgroundImage_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"set_backgroundRepeat") ) { return set_backgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundRepeat") ) { return get_backgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundOrigin") ) { return set_backgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundOrigin") ) { return get_backgroundOrigin_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"set_backgroundPosition") ) { return set_backgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundPosition") ) { return get_backgroundPosition_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Style_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return set_top(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"left") ) { return set_left(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return set_clear(inValue); }
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		if (HX_FIELD_EQ(inName,"right") ) { return set_right(inValue); }
		if (HX_FIELD_EQ(inName,"color") ) { return set_color(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
		if (HX_FIELD_EQ(inName,"bottom") ) { return set_bottom(inValue); }
		if (HX_FIELD_EQ(inName,"cursor") ) { return set_cursor(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return set_display(inValue); }
		if (HX_FIELD_EQ(inName,"opacity") ) { return set_opacity(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return set_position(inValue); }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return set_CSSFloat(inValue); }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return set_minWidth(inValue); }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return set_maxWidth(inValue); }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return set_fontSize(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"marginTop") ) { return set_marginTop(inValue); }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return set_minHeight(inValue); }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return set_maxHeight(inValue); }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return set_fontStyle(inValue); }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return set_textAlign(inValue); }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return set_overflowX(inValue); }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return set_overflowY(inValue); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return set_marginLeft(inValue); }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return set_paddingTop(inValue); }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return set_fontWeight(inValue); }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return set_fontFamily(inValue); }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return set_lineHeight(inValue); }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return set_whiteSpace(inValue); }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return set_textIndent(inValue); }
		if (HX_FIELD_EQ(inName,"visibility") ) { return set_visibility(inValue); }
		if (HX_FIELD_EQ(inName,"_coreStyle") ) { _coreStyle=inValue.Cast< ::cocktail::core::style::CoreStyle >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"marginRight") ) { return set_marginRight(inValue); }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return set_paddingLeft(inValue); }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return set_fontVariant(inValue); }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return set_wordSpacing(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return set_marginBottom(inValue); }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return set_paddingRight(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return set_paddingBottom(inValue); }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return set_textTransform(inValue); }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return set_letterSpacing(inValue); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return set_verticalAlign(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return set_backgroundSize(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return set_backgroundClip(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return set_backgroundColor(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return set_backgroundImage(inValue); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return set_backgroundRepeat(inValue); }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return set_backgroundOrigin(inValue); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return set_backgroundPosition(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void Style_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("cssFloat"));
	outFields->push(HX_CSTRING("clear"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("marginTop"));
	outFields->push(HX_CSTRING("marginBottom"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("paddingTop"));
	outFields->push(HX_CSTRING("paddingBottom"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("minHeight"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("minWidth"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("backgroundImage"));
	outFields->push(HX_CSTRING("backgroundRepeat"));
	outFields->push(HX_CSTRING("backgroundOrigin"));
	outFields->push(HX_CSTRING("backgroundSize"));
	outFields->push(HX_CSTRING("backgroundPosition"));
	outFields->push(HX_CSTRING("backgroundClip"));
	outFields->push(HX_CSTRING("fontSize"));
	outFields->push(HX_CSTRING("fontWeight"));
	outFields->push(HX_CSTRING("fontStyle"));
	outFields->push(HX_CSTRING("fontFamily"));
	outFields->push(HX_CSTRING("fontVariant"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("lineHeight"));
	outFields->push(HX_CSTRING("textTransform"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("wordSpacing"));
	outFields->push(HX_CSTRING("whiteSpace"));
	outFields->push(HX_CSTRING("textAlign"));
	outFields->push(HX_CSTRING("textIndent"));
	outFields->push(HX_CSTRING("verticalAlign"));
	outFields->push(HX_CSTRING("opacity"));
	outFields->push(HX_CSTRING("visibility"));
	outFields->push(HX_CSTRING("overflowX"));
	outFields->push(HX_CSTRING("overflowY"));
	outFields->push(HX_CSTRING("cursor"));
	outFields->push(HX_CSTRING("_coreStyle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("display"),
	HX_CSTRING("position"),
	HX_CSTRING("cssFloat"),
	HX_CSTRING("clear"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("marginTop"),
	HX_CSTRING("marginBottom"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("paddingTop"),
	HX_CSTRING("paddingBottom"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	HX_CSTRING("minHeight"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("minWidth"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("top"),
	HX_CSTRING("left"),
	HX_CSTRING("bottom"),
	HX_CSTRING("right"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("backgroundImage"),
	HX_CSTRING("backgroundRepeat"),
	HX_CSTRING("backgroundOrigin"),
	HX_CSTRING("backgroundSize"),
	HX_CSTRING("backgroundPosition"),
	HX_CSTRING("backgroundClip"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("fontWeight"),
	HX_CSTRING("fontStyle"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("fontVariant"),
	HX_CSTRING("color"),
	HX_CSTRING("lineHeight"),
	HX_CSTRING("textTransform"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("wordSpacing"),
	HX_CSTRING("whiteSpace"),
	HX_CSTRING("textAlign"),
	HX_CSTRING("textIndent"),
	HX_CSTRING("verticalAlign"),
	HX_CSTRING("opacity"),
	HX_CSTRING("visibility"),
	HX_CSTRING("overflowX"),
	HX_CSTRING("overflowY"),
	HX_CSTRING("cursor"),
	HX_CSTRING("_coreStyle"),
	HX_CSTRING("get_opacity"),
	HX_CSTRING("set_opacity"),
	HX_CSTRING("get_visibility"),
	HX_CSTRING("set_visibility"),
	HX_CSTRING("get_marginLeft"),
	HX_CSTRING("set_marginLeft"),
	HX_CSTRING("get_marginRight"),
	HX_CSTRING("set_marginRight"),
	HX_CSTRING("get_marginTop"),
	HX_CSTRING("set_marginTop"),
	HX_CSTRING("get_marginBottom"),
	HX_CSTRING("set_marginBottom"),
	HX_CSTRING("get_paddingLeft"),
	HX_CSTRING("set_paddingLeft"),
	HX_CSTRING("get_paddingRight"),
	HX_CSTRING("set_paddingRight"),
	HX_CSTRING("get_paddingTop"),
	HX_CSTRING("set_paddingTop"),
	HX_CSTRING("get_paddingBottom"),
	HX_CSTRING("set_paddingBottom"),
	HX_CSTRING("get_display"),
	HX_CSTRING("set_display"),
	HX_CSTRING("get_position"),
	HX_CSTRING("set_position"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_minHeight"),
	HX_CSTRING("set_minHeight"),
	HX_CSTRING("get_maxHeight"),
	HX_CSTRING("set_maxHeight"),
	HX_CSTRING("get_minWidth"),
	HX_CSTRING("set_minWidth"),
	HX_CSTRING("get_maxWidth"),
	HX_CSTRING("set_maxWidth"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_CSSFloat"),
	HX_CSTRING("set_CSSFloat"),
	HX_CSTRING("get_clear"),
	HX_CSTRING("set_clear"),
	HX_CSTRING("get_fontSize"),
	HX_CSTRING("set_fontSize"),
	HX_CSTRING("get_fontWeight"),
	HX_CSTRING("set_fontWeight"),
	HX_CSTRING("get_fontStyle"),
	HX_CSTRING("set_fontStyle"),
	HX_CSTRING("get_fontFamily"),
	HX_CSTRING("set_fontFamily"),
	HX_CSTRING("get_fontVariant"),
	HX_CSTRING("set_fontVariant"),
	HX_CSTRING("get_textTransform"),
	HX_CSTRING("set_textTransform"),
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("set_letterSpacing"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_color"),
	HX_CSTRING("get_wordSpacing"),
	HX_CSTRING("set_wordSpacing"),
	HX_CSTRING("get_lineHeight"),
	HX_CSTRING("set_lineHeight"),
	HX_CSTRING("get_verticalAlign"),
	HX_CSTRING("set_verticalAlign"),
	HX_CSTRING("get_textIndent"),
	HX_CSTRING("set_textIndent"),
	HX_CSTRING("get_whiteSpace"),
	HX_CSTRING("set_whiteSpace"),
	HX_CSTRING("get_textAlign"),
	HX_CSTRING("set_textAlign"),
	HX_CSTRING("set_backgroundColor"),
	HX_CSTRING("get_backgroundColor"),
	HX_CSTRING("set_backgroundImage"),
	HX_CSTRING("get_backgroundImage"),
	HX_CSTRING("set_backgroundRepeat"),
	HX_CSTRING("get_backgroundRepeat"),
	HX_CSTRING("set_backgroundSize"),
	HX_CSTRING("get_backgroundSize"),
	HX_CSTRING("set_backgroundClip"),
	HX_CSTRING("get_backgroundClip"),
	HX_CSTRING("set_backgroundPosition"),
	HX_CSTRING("get_backgroundPosition"),
	HX_CSTRING("set_backgroundOrigin"),
	HX_CSTRING("get_backgroundOrigin"),
	HX_CSTRING("get_overflowX"),
	HX_CSTRING("set_overflowX"),
	HX_CSTRING("get_overflowY"),
	HX_CSTRING("set_overflowY"),
	HX_CSTRING("set_cursor"),
	HX_CSTRING("get_cursor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class Style_obj::__mClass;

void Style_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.adapter.Style"), hx::TCanCast< Style_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Style_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace adapter
