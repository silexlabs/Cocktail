#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSConstants
#include <cocktail/core/css/CSSConstants.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSLengthValue
#include <cocktail/core/css/CSSLengthValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#include <cocktail/core/css/CSSTimeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_InitialStyleDeclaration
#include <cocktail/core/css/InitialStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#include <cocktail/core/css/TypedPropertyVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleParser
#include <cocktail/core/css/parsers/CSSStyleParser.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleSerializer
#include <cocktail/core/css/parsers/CSSStyleSerializer.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSStyleDeclaration_obj::__construct(::cocktail::core::css::CSSRule parentRule,Dynamic onStyleChange)
{
HX_STACK_PUSH("CSSStyleDeclaration::new","cocktail/core/css/CSSStyleDeclaration.hx",226);
{
	HX_STACK_LINE(227)
	this->_onStyleChange = onStyleChange;
	HX_STACK_LINE(228)
	this->parentRule = parentRule;
	HX_STACK_LINE(230)
	this->length = (int)0;
}
;
	return null();
}

CSSStyleDeclaration_obj::~CSSStyleDeclaration_obj() { }

Dynamic CSSStyleDeclaration_obj::__CreateEmpty() { return  new CSSStyleDeclaration_obj; }
hx::ObjectPtr< CSSStyleDeclaration_obj > CSSStyleDeclaration_obj::__new(::cocktail::core::css::CSSRule parentRule,Dynamic onStyleChange)
{  hx::ObjectPtr< CSSStyleDeclaration_obj > result = new CSSStyleDeclaration_obj();
	result->__construct(parentRule,onStyleChange);
	return result;}

Dynamic CSSStyleDeclaration_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSStyleDeclaration_obj > result = new CSSStyleDeclaration_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String CSSStyleDeclaration_obj::set_textDecoration( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_textDecoration","cocktail/core/css/CSSStyleDeclaration.hx",4886);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4887)
	this->setProperty((int)86,value,null());
	HX_STACK_LINE(4888)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_textDecoration,return )

::String CSSStyleDeclaration_obj::get_textDecoration( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_textDecoration","cocktail/core/css/CSSStyleDeclaration.hx",4881);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4881)
	return this->getPropertyValue((int)86);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_textDecoration,return )

::String CSSStyleDeclaration_obj::set_outlineStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_outlineStyle","cocktail/core/css/CSSStyleDeclaration.hx",4875);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4876)
	this->setProperty((int)83,value,null());
	HX_STACK_LINE(4877)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_outlineStyle,return )

::String CSSStyleDeclaration_obj::get_outlineStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_outlineStyle","cocktail/core/css/CSSStyleDeclaration.hx",4870);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4870)
	return this->getPropertyValue((int)83);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_outlineStyle,return )

::String CSSStyleDeclaration_obj::set_outlineColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_outlineColor","cocktail/core/css/CSSStyleDeclaration.hx",4864);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4865)
	this->setProperty((int)84,value,null());
	HX_STACK_LINE(4866)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_outlineColor,return )

::String CSSStyleDeclaration_obj::get_outlineColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_outlineColor","cocktail/core/css/CSSStyleDeclaration.hx",4859);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4859)
	return this->getPropertyValue((int)84);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_outlineColor,return )

::String CSSStyleDeclaration_obj::set_outlineWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_outlineWidth","cocktail/core/css/CSSStyleDeclaration.hx",4853);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4854)
	this->setProperty((int)82,value,null());
	HX_STACK_LINE(4855)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_outlineWidth,return )

::String CSSStyleDeclaration_obj::get_outlineWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_outlineWidth","cocktail/core/css/CSSStyleDeclaration.hx",4848);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4848)
	return this->getPropertyValue((int)82);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_outlineWidth,return )

::String CSSStyleDeclaration_obj::set_outline( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_outline","cocktail/core/css/CSSStyleDeclaration.hx",4842);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4843)
	this->setProperty((int)85,value,null());
	HX_STACK_LINE(4844)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_outline,return )

::String CSSStyleDeclaration_obj::get_outline( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_outline","cocktail/core/css/CSSStyleDeclaration.hx",4837);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4837)
	return this->getPropertyValue((int)85);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_outline,return )

::String CSSStyleDeclaration_obj::set_border( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_border","cocktail/core/css/CSSStyleDeclaration.hx",4831);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4832)
	this->setProperty((int)81,value,null());
	HX_STACK_LINE(4833)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_border,return )

::String CSSStyleDeclaration_obj::get_border( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_border","cocktail/core/css/CSSStyleDeclaration.hx",4826);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4826)
	return this->getPropertyValue((int)81);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_border,return )

::String CSSStyleDeclaration_obj::set_borderLeft( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderLeft","cocktail/core/css/CSSStyleDeclaration.hx",4820);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4821)
	this->setProperty((int)80,value,null());
	HX_STACK_LINE(4822)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderLeft,return )

::String CSSStyleDeclaration_obj::get_borderLeft( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderLeft","cocktail/core/css/CSSStyleDeclaration.hx",4815);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4815)
	return this->getPropertyValue((int)80);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderLeft,return )

::String CSSStyleDeclaration_obj::set_borderBottom( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderBottom","cocktail/core/css/CSSStyleDeclaration.hx",4809);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4810)
	this->setProperty((int)79,value,null());
	HX_STACK_LINE(4811)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderBottom,return )

::String CSSStyleDeclaration_obj::get_borderBottom( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderBottom","cocktail/core/css/CSSStyleDeclaration.hx",4804);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4804)
	return this->getPropertyValue((int)79);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderBottom,return )

::String CSSStyleDeclaration_obj::set_borderRight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderRight","cocktail/core/css/CSSStyleDeclaration.hx",4798);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4799)
	this->setProperty((int)78,value,null());
	HX_STACK_LINE(4800)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderRight,return )

::String CSSStyleDeclaration_obj::get_borderRight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderRight","cocktail/core/css/CSSStyleDeclaration.hx",4793);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4793)
	return this->getPropertyValue((int)78);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderRight,return )

::String CSSStyleDeclaration_obj::set_borderTop( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderTop","cocktail/core/css/CSSStyleDeclaration.hx",4787);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4788)
	this->setProperty((int)77,value,null());
	HX_STACK_LINE(4789)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderTop,return )

::String CSSStyleDeclaration_obj::get_borderTop( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderTop","cocktail/core/css/CSSStyleDeclaration.hx",4782);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4782)
	return this->getPropertyValue((int)77);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderTop,return )

::String CSSStyleDeclaration_obj::set_borderStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderStyle","cocktail/core/css/CSSStyleDeclaration.hx",4776);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4777)
	this->setProperty((int)76,value,null());
	HX_STACK_LINE(4778)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderStyle,return )

::String CSSStyleDeclaration_obj::get_borderStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderStyle","cocktail/core/css/CSSStyleDeclaration.hx",4771);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4771)
	return this->getPropertyValue((int)76);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderStyle,return )

::String CSSStyleDeclaration_obj::set_borderLeftStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderLeftStyle","cocktail/core/css/CSSStyleDeclaration.hx",4765);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4766)
	this->setProperty((int)75,value,null());
	HX_STACK_LINE(4767)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderLeftStyle,return )

::String CSSStyleDeclaration_obj::get_borderLeftStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderLeftStyle","cocktail/core/css/CSSStyleDeclaration.hx",4760);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4760)
	return this->getPropertyValue((int)75);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderLeftStyle,return )

::String CSSStyleDeclaration_obj::set_borderBottomStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderBottomStyle","cocktail/core/css/CSSStyleDeclaration.hx",4754);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4755)
	this->setProperty((int)74,value,null());
	HX_STACK_LINE(4756)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderBottomStyle,return )

::String CSSStyleDeclaration_obj::get_borderBottomStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderBottomStyle","cocktail/core/css/CSSStyleDeclaration.hx",4749);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4749)
	return this->getPropertyValue((int)74);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderBottomStyle,return )

::String CSSStyleDeclaration_obj::set_borderRightStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderRightStyle","cocktail/core/css/CSSStyleDeclaration.hx",4743);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4744)
	this->setProperty((int)73,value,null());
	HX_STACK_LINE(4745)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderRightStyle,return )

::String CSSStyleDeclaration_obj::get_borderRightStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderRightStyle","cocktail/core/css/CSSStyleDeclaration.hx",4738);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4738)
	return this->getPropertyValue((int)73);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderRightStyle,return )

::String CSSStyleDeclaration_obj::set_borderTopStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderTopStyle","cocktail/core/css/CSSStyleDeclaration.hx",4732);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4733)
	this->setProperty((int)72,value,null());
	HX_STACK_LINE(4734)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderTopStyle,return )

::String CSSStyleDeclaration_obj::get_borderTopStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderTopStyle","cocktail/core/css/CSSStyleDeclaration.hx",4727);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4727)
	return this->getPropertyValue((int)72);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderTopStyle,return )

::String CSSStyleDeclaration_obj::set_borderColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderColor","cocktail/core/css/CSSStyleDeclaration.hx",4721);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4722)
	this->setProperty((int)71,value,null());
	HX_STACK_LINE(4723)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderColor,return )

::String CSSStyleDeclaration_obj::get_borderColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderColor","cocktail/core/css/CSSStyleDeclaration.hx",4716);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4716)
	return this->getPropertyValue((int)71);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderColor,return )

::String CSSStyleDeclaration_obj::set_borderLeftColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderLeftColor","cocktail/core/css/CSSStyleDeclaration.hx",4710);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4711)
	this->setProperty((int)70,value,null());
	HX_STACK_LINE(4712)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderLeftColor,return )

::String CSSStyleDeclaration_obj::get_borderLeftColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderLeftColor","cocktail/core/css/CSSStyleDeclaration.hx",4705);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4705)
	return this->getPropertyValue((int)70);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderLeftColor,return )

::String CSSStyleDeclaration_obj::set_borderBottomColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderBottomColor","cocktail/core/css/CSSStyleDeclaration.hx",4699);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4700)
	this->setProperty((int)69,value,null());
	HX_STACK_LINE(4701)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderBottomColor,return )

::String CSSStyleDeclaration_obj::get_borderBottomColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderBottomColor","cocktail/core/css/CSSStyleDeclaration.hx",4694);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4694)
	return this->getPropertyValue((int)69);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderBottomColor,return )

::String CSSStyleDeclaration_obj::set_borderRightColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderRightColor","cocktail/core/css/CSSStyleDeclaration.hx",4688);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4689)
	this->setProperty((int)68,value,null());
	HX_STACK_LINE(4690)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderRightColor,return )

::String CSSStyleDeclaration_obj::get_borderRightColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderRightColor","cocktail/core/css/CSSStyleDeclaration.hx",4683);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4683)
	return this->getPropertyValue((int)68);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderRightColor,return )

::String CSSStyleDeclaration_obj::set_borderTopColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderTopColor","cocktail/core/css/CSSStyleDeclaration.hx",4677);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4678)
	this->setProperty((int)67,value,null());
	HX_STACK_LINE(4679)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderTopColor,return )

::String CSSStyleDeclaration_obj::get_borderTopColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderTopColor","cocktail/core/css/CSSStyleDeclaration.hx",4672);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4672)
	return this->getPropertyValue((int)67);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderTopColor,return )

::String CSSStyleDeclaration_obj::set_borderWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderWidth","cocktail/core/css/CSSStyleDeclaration.hx",4666);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4667)
	this->setProperty((int)66,value,null());
	HX_STACK_LINE(4668)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderWidth,return )

::String CSSStyleDeclaration_obj::get_borderWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderWidth","cocktail/core/css/CSSStyleDeclaration.hx",4661);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4661)
	return this->getPropertyValue((int)66);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderWidth,return )

::String CSSStyleDeclaration_obj::set_borderLeftWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderLeftWidth","cocktail/core/css/CSSStyleDeclaration.hx",4655);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4656)
	this->setProperty((int)65,value,null());
	HX_STACK_LINE(4657)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderLeftWidth,return )

::String CSSStyleDeclaration_obj::get_borderLeftWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderLeftWidth","cocktail/core/css/CSSStyleDeclaration.hx",4650);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4650)
	return this->getPropertyValue((int)65);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderLeftWidth,return )

::String CSSStyleDeclaration_obj::set_borderBottomWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderBottomWidth","cocktail/core/css/CSSStyleDeclaration.hx",4644);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4645)
	this->setProperty((int)64,value,null());
	HX_STACK_LINE(4646)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderBottomWidth,return )

::String CSSStyleDeclaration_obj::get_borderBottomWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderBottomWidth","cocktail/core/css/CSSStyleDeclaration.hx",4639);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4639)
	return this->getPropertyValue((int)64);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderBottomWidth,return )

::String CSSStyleDeclaration_obj::set_borderRightWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderRightWidth","cocktail/core/css/CSSStyleDeclaration.hx",4633);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4634)
	this->setProperty((int)63,value,null());
	HX_STACK_LINE(4635)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderRightWidth,return )

::String CSSStyleDeclaration_obj::get_borderRightWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderRightWidth","cocktail/core/css/CSSStyleDeclaration.hx",4628);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4628)
	return this->getPropertyValue((int)63);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderRightWidth,return )

::String CSSStyleDeclaration_obj::set_borderTopWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_borderTopWidth","cocktail/core/css/CSSStyleDeclaration.hx",4622);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4623)
	this->setProperty((int)62,value,null());
	HX_STACK_LINE(4624)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_borderTopWidth,return )

::String CSSStyleDeclaration_obj::get_borderTopWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_borderTopWidth","cocktail/core/css/CSSStyleDeclaration.hx",4617);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4617)
	return this->getPropertyValue((int)62);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_borderTopWidth,return )

::String CSSStyleDeclaration_obj::set_transformOrigin( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transformOrigin","cocktail/core/css/CSSStyleDeclaration.hx",4611);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4612)
	this->setProperty((int)60,value,null());
	HX_STACK_LINE(4613)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transformOrigin,return )

::String CSSStyleDeclaration_obj::get_transformOrigin( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transformOrigin","cocktail/core/css/CSSStyleDeclaration.hx",4606);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4606)
	return this->getPropertyValue((int)60);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transformOrigin,return )

::String CSSStyleDeclaration_obj::set_transform( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transform","cocktail/core/css/CSSStyleDeclaration.hx",4600);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4601)
	this->setProperty((int)61,value,null());
	HX_STACK_LINE(4602)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transform,return )

::String CSSStyleDeclaration_obj::get_transform( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transform","cocktail/core/css/CSSStyleDeclaration.hx",4595);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4595)
	return this->getPropertyValue((int)61);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transform,return )

::String CSSStyleDeclaration_obj::set_transitionTimingFunction( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transitionTimingFunction","cocktail/core/css/CSSStyleDeclaration.hx",4589);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4590)
	this->setProperty((int)58,value,null());
	HX_STACK_LINE(4591)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transitionTimingFunction,return )

::String CSSStyleDeclaration_obj::get_transitionTimingFunction( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transitionTimingFunction","cocktail/core/css/CSSStyleDeclaration.hx",4584);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4584)
	return this->getPropertyValue((int)58);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transitionTimingFunction,return )

::String CSSStyleDeclaration_obj::set_transitionDelay( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transitionDelay","cocktail/core/css/CSSStyleDeclaration.hx",4578);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4579)
	this->setProperty((int)56,value,null());
	HX_STACK_LINE(4580)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transitionDelay,return )

::String CSSStyleDeclaration_obj::get_transitionDelay( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transitionDelay","cocktail/core/css/CSSStyleDeclaration.hx",4573);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4573)
	return this->getPropertyValue((int)56);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transitionDelay,return )

::String CSSStyleDeclaration_obj::set_transitionDuration( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transitionDuration","cocktail/core/css/CSSStyleDeclaration.hx",4567);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4568)
	this->setProperty((int)55,value,null());
	HX_STACK_LINE(4569)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transitionDuration,return )

::String CSSStyleDeclaration_obj::get_transitionDuration( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transitionDuration","cocktail/core/css/CSSStyleDeclaration.hx",4562);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4562)
	return this->getPropertyValue((int)55);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transitionDuration,return )

::String CSSStyleDeclaration_obj::set_transitionProperty( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_transitionProperty","cocktail/core/css/CSSStyleDeclaration.hx",4556);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4557)
	this->setProperty((int)57,value,null());
	HX_STACK_LINE(4558)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_transitionProperty,return )

::String CSSStyleDeclaration_obj::get_transitionProperty( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_transitionProperty","cocktail/core/css/CSSStyleDeclaration.hx",4551);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4551)
	return this->getPropertyValue((int)57);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_transitionProperty,return )

::String CSSStyleDeclaration_obj::get_cursor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_cursor","cocktail/core/css/CSSStyleDeclaration.hx",4545);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4545)
	return this->getPropertyValue((int)54);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_cursor,return )

::String CSSStyleDeclaration_obj::set_cursor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_cursor","cocktail/core/css/CSSStyleDeclaration.hx",4539);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4540)
	this->setProperty((int)54,value,null());
	HX_STACK_LINE(4541)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_cursor,return )

::String CSSStyleDeclaration_obj::set_overflowY( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_overflowY","cocktail/core/css/CSSStyleDeclaration.hx",4533);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4534)
	this->setProperty((int)52,value,null());
	HX_STACK_LINE(4535)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_overflowY,return )

::String CSSStyleDeclaration_obj::get_overflowY( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_overflowY","cocktail/core/css/CSSStyleDeclaration.hx",4528);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4528)
	return this->getPropertyValue((int)52);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_overflowY,return )

::String CSSStyleDeclaration_obj::set_overflowX( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_overflowX","cocktail/core/css/CSSStyleDeclaration.hx",4522);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4523)
	this->setProperty((int)51,value,null());
	HX_STACK_LINE(4524)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_overflowX,return )

::String CSSStyleDeclaration_obj::get_overflowX( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_overflowX","cocktail/core/css/CSSStyleDeclaration.hx",4517);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4517)
	return this->getPropertyValue((int)51);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_overflowX,return )

::String CSSStyleDeclaration_obj::set_overflow( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_overflow","cocktail/core/css/CSSStyleDeclaration.hx",4511);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4512)
	this->setProperty((int)50,value,null());
	HX_STACK_LINE(4513)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_overflow,return )

::String CSSStyleDeclaration_obj::get_overflow( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_overflow","cocktail/core/css/CSSStyleDeclaration.hx",4506);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4506)
	return this->getPropertyValue((int)50);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_overflow,return )

::String CSSStyleDeclaration_obj::get_backgroundOrigin( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundOrigin","cocktail/core/css/CSSStyleDeclaration.hx",4501);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4501)
	return this->getPropertyValue((int)28);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundOrigin,return )

::String CSSStyleDeclaration_obj::set_backgroundOrigin( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundOrigin","cocktail/core/css/CSSStyleDeclaration.hx",4495);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4496)
	this->setProperty((int)28,value,null());
	HX_STACK_LINE(4497)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundOrigin,return )

::String CSSStyleDeclaration_obj::get_backgroundPosition( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundPosition","cocktail/core/css/CSSStyleDeclaration.hx",4490);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4490)
	return this->getPropertyValue((int)30);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundPosition,return )

::String CSSStyleDeclaration_obj::set_backgroundPosition( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundPosition","cocktail/core/css/CSSStyleDeclaration.hx",4484);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4485)
	this->setProperty((int)30,value,null());
	HX_STACK_LINE(4486)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundPosition,return )

::String CSSStyleDeclaration_obj::get_backgroundAttachment( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundAttachment","cocktail/core/css/CSSStyleDeclaration.hx",4479);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4479)
	return this->getPropertyValue((int)32);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundAttachment,return )

::String CSSStyleDeclaration_obj::set_backgroundAttachment( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundAttachment","cocktail/core/css/CSSStyleDeclaration.hx",4473);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4474)
	this->setProperty((int)32,value,null());
	HX_STACK_LINE(4475)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundAttachment,return )

::String CSSStyleDeclaration_obj::get_backgroundClip( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundClip","cocktail/core/css/CSSStyleDeclaration.hx",4468);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4468)
	return this->getPropertyValue((int)31);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundClip,return )

::String CSSStyleDeclaration_obj::set_backgroundClip( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundClip","cocktail/core/css/CSSStyleDeclaration.hx",4462);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4463)
	this->setProperty((int)31,value,null());
	HX_STACK_LINE(4464)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundClip,return )

::String CSSStyleDeclaration_obj::get_backgroundSize( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundSize","cocktail/core/css/CSSStyleDeclaration.hx",4457);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4457)
	return this->getPropertyValue((int)29);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundSize,return )

::String CSSStyleDeclaration_obj::set_backgroundSize( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundSize","cocktail/core/css/CSSStyleDeclaration.hx",4451);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4452)
	this->setProperty((int)29,value,null());
	HX_STACK_LINE(4453)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundSize,return )

::String CSSStyleDeclaration_obj::get_backgroundRepeat( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundRepeat","cocktail/core/css/CSSStyleDeclaration.hx",4446);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4446)
	return this->getPropertyValue((int)27);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundRepeat,return )

::String CSSStyleDeclaration_obj::set_backgroundRepeat( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundRepeat","cocktail/core/css/CSSStyleDeclaration.hx",4440);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4441)
	this->setProperty((int)27,value,null());
	HX_STACK_LINE(4442)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundRepeat,return )

::String CSSStyleDeclaration_obj::get_backgroundImage( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundImage","cocktail/core/css/CSSStyleDeclaration.hx",4435);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4435)
	return this->getPropertyValue((int)26);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundImage,return )

::String CSSStyleDeclaration_obj::set_backgroundImage( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundImage","cocktail/core/css/CSSStyleDeclaration.hx",4429);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4430)
	this->setProperty((int)26,value,null());
	HX_STACK_LINE(4431)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundImage,return )

::String CSSStyleDeclaration_obj::get_backgroundColor( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_backgroundColor","cocktail/core/css/CSSStyleDeclaration.hx",4424);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4424)
	return this->getPropertyValue((int)25);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_backgroundColor,return )

::String CSSStyleDeclaration_obj::set_backgroundColor( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_backgroundColor","cocktail/core/css/CSSStyleDeclaration.hx",4418);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4419)
	this->setProperty((int)25,value,null());
	HX_STACK_LINE(4420)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_backgroundColor,return )

::String CSSStyleDeclaration_obj::get_background( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_background","cocktail/core/css/CSSStyleDeclaration.hx",4413);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4413)
	return this->getPropertyValue((int)33);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_background,return )

::String CSSStyleDeclaration_obj::set_background( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_background","cocktail/core/css/CSSStyleDeclaration.hx",4407);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4408)
	this->setProperty((int)33,value,null());
	HX_STACK_LINE(4409)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_background,return )

::String CSSStyleDeclaration_obj::set_textAlign( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_textAlign","cocktail/core/css/CSSStyleDeclaration.hx",4401);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4402)
	this->setProperty((int)46,value,null());
	HX_STACK_LINE(4403)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_textAlign,return )

::String CSSStyleDeclaration_obj::get_textAlign( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_textAlign","cocktail/core/css/CSSStyleDeclaration.hx",4396);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4396)
	return this->getPropertyValue((int)46);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_textAlign,return )

::String CSSStyleDeclaration_obj::set_whiteSpace( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_whiteSpace","cocktail/core/css/CSSStyleDeclaration.hx",4390);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4391)
	this->setProperty((int)45,value,null());
	HX_STACK_LINE(4392)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_whiteSpace,return )

::String CSSStyleDeclaration_obj::get_whiteSpace( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_whiteSpace","cocktail/core/css/CSSStyleDeclaration.hx",4385);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4385)
	return this->getPropertyValue((int)45);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_whiteSpace,return )

::String CSSStyleDeclaration_obj::set_textIndent( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_textIndent","cocktail/core/css/CSSStyleDeclaration.hx",4379);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4380)
	this->setProperty((int)47,value,null());
	HX_STACK_LINE(4381)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_textIndent,return )

::String CSSStyleDeclaration_obj::get_textIndent( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_textIndent","cocktail/core/css/CSSStyleDeclaration.hx",4374);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4374)
	return this->getPropertyValue((int)47);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_textIndent,return )

::String CSSStyleDeclaration_obj::set_verticalAlign( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_verticalAlign","cocktail/core/css/CSSStyleDeclaration.hx",4368);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4369)
	this->setProperty((int)48,value,null());
	HX_STACK_LINE(4370)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_verticalAlign,return )

::String CSSStyleDeclaration_obj::get_verticalAlign( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_verticalAlign","cocktail/core/css/CSSStyleDeclaration.hx",4363);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4363)
	return this->getPropertyValue((int)48);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_verticalAlign,return )

::String CSSStyleDeclaration_obj::set_lineHeight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_lineHeight","cocktail/core/css/CSSStyleDeclaration.hx",4357);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4358)
	this->setProperty((int)41,value,null());
	HX_STACK_LINE(4359)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_lineHeight,return )

::String CSSStyleDeclaration_obj::get_lineHeight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_lineHeight","cocktail/core/css/CSSStyleDeclaration.hx",4352);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4352)
	return this->getPropertyValue((int)41);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_lineHeight,return )

::String CSSStyleDeclaration_obj::set_wordSpacing( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_wordSpacing","cocktail/core/css/CSSStyleDeclaration.hx",4346);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4347)
	this->setProperty((int)44,value,null());
	HX_STACK_LINE(4348)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_wordSpacing,return )

::String CSSStyleDeclaration_obj::get_wordSpacing( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_wordSpacing","cocktail/core/css/CSSStyleDeclaration.hx",4341);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4341)
	return this->getPropertyValue((int)44);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_wordSpacing,return )

::String CSSStyleDeclaration_obj::set_color( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_color","cocktail/core/css/CSSStyleDeclaration.hx",4335);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4336)
	this->setProperty((int)40,value,null());
	HX_STACK_LINE(4337)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_color,return )

::String CSSStyleDeclaration_obj::get_color( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_color","cocktail/core/css/CSSStyleDeclaration.hx",4330);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4330)
	return this->getPropertyValue((int)40);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_color,return )

::String CSSStyleDeclaration_obj::set_letterSpacing( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_letterSpacing","cocktail/core/css/CSSStyleDeclaration.hx",4324);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4325)
	this->setProperty((int)43,value,null());
	HX_STACK_LINE(4326)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_letterSpacing,return )

::String CSSStyleDeclaration_obj::get_letterSpacing( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_letterSpacing","cocktail/core/css/CSSStyleDeclaration.hx",4319);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4319)
	return this->getPropertyValue((int)43);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_letterSpacing,return )

::String CSSStyleDeclaration_obj::set_textTransform( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_textTransform","cocktail/core/css/CSSStyleDeclaration.hx",4313);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4314)
	this->setProperty((int)42,value,null());
	HX_STACK_LINE(4315)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_textTransform,return )

::String CSSStyleDeclaration_obj::get_textTransform( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_textTransform","cocktail/core/css/CSSStyleDeclaration.hx",4308);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4308)
	return this->getPropertyValue((int)42);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_textTransform,return )

::String CSSStyleDeclaration_obj::set_fontVariant( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_fontVariant","cocktail/core/css/CSSStyleDeclaration.hx",4302);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4303)
	this->setProperty((int)38,value,null());
	HX_STACK_LINE(4304)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_fontVariant,return )

::String CSSStyleDeclaration_obj::get_fontVariant( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_fontVariant","cocktail/core/css/CSSStyleDeclaration.hx",4297);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4297)
	return this->getPropertyValue((int)38);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_fontVariant,return )

::String CSSStyleDeclaration_obj::set_fontFamily( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_fontFamily","cocktail/core/css/CSSStyleDeclaration.hx",4290);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4291)
	this->setProperty((int)37,value,null());
	HX_STACK_LINE(4292)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_fontFamily,return )

::String CSSStyleDeclaration_obj::get_fontFamily( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_fontFamily","cocktail/core/css/CSSStyleDeclaration.hx",4285);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4285)
	return this->getPropertyValue((int)37);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_fontFamily,return )

::String CSSStyleDeclaration_obj::set_fontStyle( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_fontStyle","cocktail/core/css/CSSStyleDeclaration.hx",4279);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4280)
	this->setProperty((int)36,value,null());
	HX_STACK_LINE(4281)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_fontStyle,return )

::String CSSStyleDeclaration_obj::get_fontStyle( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_fontStyle","cocktail/core/css/CSSStyleDeclaration.hx",4274);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4274)
	return this->getPropertyValue((int)36);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_fontStyle,return )

::String CSSStyleDeclaration_obj::set_fontWeight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_fontWeight","cocktail/core/css/CSSStyleDeclaration.hx",4268);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4269)
	this->setProperty((int)35,value,null());
	HX_STACK_LINE(4270)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_fontWeight,return )

::String CSSStyleDeclaration_obj::get_fontWeight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_fontWeight","cocktail/core/css/CSSStyleDeclaration.hx",4263);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4263)
	return this->getPropertyValue((int)35);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_fontWeight,return )

::String CSSStyleDeclaration_obj::set_fontSize( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_fontSize","cocktail/core/css/CSSStyleDeclaration.hx",4257);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4258)
	this->setProperty((int)34,value,null());
	HX_STACK_LINE(4259)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_fontSize,return )

::String CSSStyleDeclaration_obj::get_fontSize( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_fontSize","cocktail/core/css/CSSStyleDeclaration.hx",4252);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4252)
	return this->getPropertyValue((int)34);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_fontSize,return )

::String CSSStyleDeclaration_obj::get_font( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_font","cocktail/core/css/CSSStyleDeclaration.hx",4247);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4247)
	return this->getPropertyValue((int)39);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_font,return )

::String CSSStyleDeclaration_obj::set_font( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_font","cocktail/core/css/CSSStyleDeclaration.hx",4241);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4242)
	this->setProperty((int)39,value,null());
	HX_STACK_LINE(4243)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_font,return )

::String CSSStyleDeclaration_obj::set_clear( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_clear","cocktail/core/css/CSSStyleDeclaration.hx",4235);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4236)
	this->setProperty((int)3,value,null());
	HX_STACK_LINE(4237)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_clear,return )

::String CSSStyleDeclaration_obj::get_clear( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_clear","cocktail/core/css/CSSStyleDeclaration.hx",4230);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4230)
	return this->getPropertyValue((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_clear,return )

::String CSSStyleDeclaration_obj::set_CSSFloat( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_CSSFloat","cocktail/core/css/CSSStyleDeclaration.hx",4224);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4225)
	this->setProperty((int)2,value,null());
	HX_STACK_LINE(4226)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_CSSFloat,return )

::String CSSStyleDeclaration_obj::get_CSSFloat( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_CSSFloat","cocktail/core/css/CSSStyleDeclaration.hx",4219);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4219)
	return this->getPropertyValue((int)2);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_CSSFloat,return )

::String CSSStyleDeclaration_obj::set_right( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_right","cocktail/core/css/CSSStyleDeclaration.hx",4213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4214)
	this->setProperty((int)23,value,null());
	HX_STACK_LINE(4215)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_right,return )

::String CSSStyleDeclaration_obj::get_right( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_right","cocktail/core/css/CSSStyleDeclaration.hx",4208);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4208)
	return this->getPropertyValue((int)23);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_right,return )

::String CSSStyleDeclaration_obj::set_bottom( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_bottom","cocktail/core/css/CSSStyleDeclaration.hx",4202);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4203)
	this->setProperty((int)24,value,null());
	HX_STACK_LINE(4204)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_bottom,return )

::String CSSStyleDeclaration_obj::get_bottom( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_bottom","cocktail/core/css/CSSStyleDeclaration.hx",4197);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4197)
	return this->getPropertyValue((int)24);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_bottom,return )

::String CSSStyleDeclaration_obj::set_left( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_left","cocktail/core/css/CSSStyleDeclaration.hx",4191);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4192)
	this->setProperty((int)22,value,null());
	HX_STACK_LINE(4193)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_left,return )

::String CSSStyleDeclaration_obj::get_left( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_left","cocktail/core/css/CSSStyleDeclaration.hx",4186);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4186)
	return this->getPropertyValue((int)22);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_left,return )

::String CSSStyleDeclaration_obj::set_top( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_top","cocktail/core/css/CSSStyleDeclaration.hx",4180);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4181)
	this->setProperty((int)21,value,null());
	HX_STACK_LINE(4182)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_top,return )

::String CSSStyleDeclaration_obj::get_top( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_top","cocktail/core/css/CSSStyleDeclaration.hx",4175);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4175)
	return this->getPropertyValue((int)21);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_top,return )

::String CSSStyleDeclaration_obj::set_maxWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_maxWidth","cocktail/core/css/CSSStyleDeclaration.hx",4169);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4170)
	this->setProperty((int)20,value,null());
	HX_STACK_LINE(4171)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_maxWidth,return )

::String CSSStyleDeclaration_obj::get_maxWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_maxWidth","cocktail/core/css/CSSStyleDeclaration.hx",4164);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4164)
	return this->getPropertyValue((int)20);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_maxWidth,return )

::String CSSStyleDeclaration_obj::set_minWidth( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_minWidth","cocktail/core/css/CSSStyleDeclaration.hx",4158);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4159)
	this->setProperty((int)19,value,null());
	HX_STACK_LINE(4160)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_minWidth,return )

::String CSSStyleDeclaration_obj::get_minWidth( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_minWidth","cocktail/core/css/CSSStyleDeclaration.hx",4153);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4153)
	return this->getPropertyValue((int)19);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_minWidth,return )

::String CSSStyleDeclaration_obj::set_maxHeight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_maxHeight","cocktail/core/css/CSSStyleDeclaration.hx",4147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4148)
	this->setProperty((int)18,value,null());
	HX_STACK_LINE(4149)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_maxHeight,return )

::String CSSStyleDeclaration_obj::get_maxHeight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_maxHeight","cocktail/core/css/CSSStyleDeclaration.hx",4142);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4142)
	return this->getPropertyValue((int)18);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_maxHeight,return )

::String CSSStyleDeclaration_obj::set_minHeight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_minHeight","cocktail/core/css/CSSStyleDeclaration.hx",4136);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4137)
	this->setProperty((int)17,value,null());
	HX_STACK_LINE(4138)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_minHeight,return )

::String CSSStyleDeclaration_obj::get_minHeight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_minHeight","cocktail/core/css/CSSStyleDeclaration.hx",4131);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4131)
	return this->getPropertyValue((int)17);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_minHeight,return )

::String CSSStyleDeclaration_obj::set_height( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_height","cocktail/core/css/CSSStyleDeclaration.hx",4125);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4126)
	this->setProperty((int)16,value,null());
	HX_STACK_LINE(4127)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_height,return )

::String CSSStyleDeclaration_obj::get_height( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_height","cocktail/core/css/CSSStyleDeclaration.hx",4120);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4120)
	return this->getPropertyValue((int)16);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_height,return )

::String CSSStyleDeclaration_obj::set_width( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_width","cocktail/core/css/CSSStyleDeclaration.hx",4114);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4115)
	this->setProperty((int)15,value,null());
	HX_STACK_LINE(4116)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_width,return )

::String CSSStyleDeclaration_obj::get_width( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_width","cocktail/core/css/CSSStyleDeclaration.hx",4109);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4109)
	return this->getPropertyValue((int)15);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_width,return )

::String CSSStyleDeclaration_obj::set_zIndex( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_zIndex","cocktail/core/css/CSSStyleDeclaration.hx",4103);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4104)
	this->setProperty((int)4,value,null());
	HX_STACK_LINE(4105)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_zIndex,return )

::String CSSStyleDeclaration_obj::get_zIndex( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_zIndex","cocktail/core/css/CSSStyleDeclaration.hx",4098);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4098)
	return this->getPropertyValue((int)4);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_zIndex,return )

::String CSSStyleDeclaration_obj::set_position( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_position","cocktail/core/css/CSSStyleDeclaration.hx",4092);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4093)
	this->setProperty((int)1,value,null());
	HX_STACK_LINE(4094)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_position,return )

::String CSSStyleDeclaration_obj::get_position( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_position","cocktail/core/css/CSSStyleDeclaration.hx",4087);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4087)
	return this->getPropertyValue((int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_position,return )

::String CSSStyleDeclaration_obj::set_display( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_display","cocktail/core/css/CSSStyleDeclaration.hx",4081);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4082)
	this->setProperty((int)0,value,null());
	HX_STACK_LINE(4083)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_display,return )

::String CSSStyleDeclaration_obj::get_display( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_display","cocktail/core/css/CSSStyleDeclaration.hx",4076);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4076)
	return this->getPropertyValue((int)0);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_display,return )

::String CSSStyleDeclaration_obj::set_paddingBottom( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_paddingBottom","cocktail/core/css/CSSStyleDeclaration.hx",4070);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4071)
	this->setProperty((int)14,value,null());
	HX_STACK_LINE(4072)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_paddingBottom,return )

::String CSSStyleDeclaration_obj::get_paddingBottom( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_paddingBottom","cocktail/core/css/CSSStyleDeclaration.hx",4065);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4065)
	return this->getPropertyValue((int)14);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_paddingBottom,return )

::String CSSStyleDeclaration_obj::set_paddingTop( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_paddingTop","cocktail/core/css/CSSStyleDeclaration.hx",4059);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4060)
	this->setProperty((int)13,value,null());
	HX_STACK_LINE(4061)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_paddingTop,return )

::String CSSStyleDeclaration_obj::get_paddingTop( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_paddingTop","cocktail/core/css/CSSStyleDeclaration.hx",4054);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4054)
	return this->getPropertyValue((int)13);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_paddingTop,return )

::String CSSStyleDeclaration_obj::set_paddingRight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_paddingRight","cocktail/core/css/CSSStyleDeclaration.hx",4048);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4049)
	this->setProperty((int)12,value,null());
	HX_STACK_LINE(4050)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_paddingRight,return )

::String CSSStyleDeclaration_obj::get_paddingRight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_paddingRight","cocktail/core/css/CSSStyleDeclaration.hx",4043);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4043)
	return this->getPropertyValue((int)12);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_paddingRight,return )

::String CSSStyleDeclaration_obj::set_paddingLeft( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_paddingLeft","cocktail/core/css/CSSStyleDeclaration.hx",4037);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4038)
	this->setProperty((int)11,value,null());
	HX_STACK_LINE(4039)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_paddingLeft,return )

::String CSSStyleDeclaration_obj::get_paddingLeft( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_paddingLeft","cocktail/core/css/CSSStyleDeclaration.hx",4032);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4032)
	return this->getPropertyValue((int)11);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_paddingLeft,return )

::String CSSStyleDeclaration_obj::set_padding( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_padding","cocktail/core/css/CSSStyleDeclaration.hx",4026);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4027)
	this->setProperty((int)10,value,null());
	HX_STACK_LINE(4028)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_padding,return )

::String CSSStyleDeclaration_obj::get_padding( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_padding","cocktail/core/css/CSSStyleDeclaration.hx",4021);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4021)
	return this->getPropertyValue((int)10);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_padding,return )

::String CSSStyleDeclaration_obj::set_marginBottom( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_marginBottom","cocktail/core/css/CSSStyleDeclaration.hx",4015);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4016)
	this->setProperty((int)9,value,null());
	HX_STACK_LINE(4017)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_marginBottom,return )

::String CSSStyleDeclaration_obj::get_marginBottom( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_marginBottom","cocktail/core/css/CSSStyleDeclaration.hx",4010);
	HX_STACK_THIS(this);
	HX_STACK_LINE(4010)
	return this->getPropertyValue((int)9);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_marginBottom,return )

::String CSSStyleDeclaration_obj::set_marginTop( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_marginTop","cocktail/core/css/CSSStyleDeclaration.hx",4004);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(4005)
	this->setProperty((int)8,value,null());
	HX_STACK_LINE(4006)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_marginTop,return )

::String CSSStyleDeclaration_obj::get_marginTop( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_marginTop","cocktail/core/css/CSSStyleDeclaration.hx",3999);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3999)
	return this->getPropertyValue((int)8);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_marginTop,return )

::String CSSStyleDeclaration_obj::set_marginRight( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_marginRight","cocktail/core/css/CSSStyleDeclaration.hx",3993);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3994)
	this->setProperty((int)7,value,null());
	HX_STACK_LINE(3995)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_marginRight,return )

::String CSSStyleDeclaration_obj::get_marginRight( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_marginRight","cocktail/core/css/CSSStyleDeclaration.hx",3988);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3988)
	return this->getPropertyValue((int)7);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_marginRight,return )

::String CSSStyleDeclaration_obj::set_marginLeft( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_marginLeft","cocktail/core/css/CSSStyleDeclaration.hx",3982);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3983)
	this->setProperty((int)6,value,null());
	HX_STACK_LINE(3984)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_marginLeft,return )

::String CSSStyleDeclaration_obj::get_marginLeft( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_marginLeft","cocktail/core/css/CSSStyleDeclaration.hx",3977);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3977)
	return this->getPropertyValue((int)6);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_marginLeft,return )

::String CSSStyleDeclaration_obj::set_margin( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_margin","cocktail/core/css/CSSStyleDeclaration.hx",3971);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3972)
	this->setProperty((int)5,value,null());
	HX_STACK_LINE(3973)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_margin,return )

::String CSSStyleDeclaration_obj::get_margin( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_margin","cocktail/core/css/CSSStyleDeclaration.hx",3966);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3966)
	return this->getPropertyValue((int)5);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_margin,return )

::String CSSStyleDeclaration_obj::set_visibility( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_visibility","cocktail/core/css/CSSStyleDeclaration.hx",3959);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3960)
	this->setProperty((int)49,value,null());
	HX_STACK_LINE(3961)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_visibility,return )

::String CSSStyleDeclaration_obj::get_visibility( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_visibility","cocktail/core/css/CSSStyleDeclaration.hx",3954);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3954)
	return this->getPropertyValue((int)49);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_visibility,return )

::String CSSStyleDeclaration_obj::set_opacity( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_opacity","cocktail/core/css/CSSStyleDeclaration.hx",3948);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3949)
	this->setProperty((int)53,value,null());
	HX_STACK_LINE(3950)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_opacity,return )

::String CSSStyleDeclaration_obj::get_opacity( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_opacity","cocktail/core/css/CSSStyleDeclaration.hx",3943);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3943)
	return this->getPropertyValue((int)53);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_opacity,return )

::String CSSStyleDeclaration_obj::set_cssText( ::String value){
	HX_STACK_PUSH("CSSStyleDeclaration::set_cssText","cocktail/core/css/CSSStyleDeclaration.hx",3921);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(3923)
	this->resetIndexedProperties();
	HX_STACK_LINE(3924)
	this->resetPropertiesPositions();
	HX_STACK_LINE(3925)
	this->length = (int)0;
	HX_STACK_LINE(3927)
	Array< ::cocktail::core::css::TypedPropertyVO > typedProperties = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseStyle(value);		HX_STACK_VAR(typedProperties,"typedProperties");
	HX_STACK_LINE(3928)
	int length = typedProperties->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(3929)
	{
		HX_STACK_LINE(3929)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3929)
		while(((_g < length))){
			HX_STACK_LINE(3929)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(3931)
			::cocktail::core::css::TypedPropertyVO typedProperty = typedProperties->__get(i);		HX_STACK_VAR(typedProperty,"typedProperty");
			HX_STACK_LINE(3932)
			this->applyProperty(typedProperty->index,typedProperty->typedValue,typedProperty->important);
		}
	}
	HX_STACK_LINE(3935)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,set_cssText,return )

::String CSSStyleDeclaration_obj::get_cssText( ){
	HX_STACK_PUSH("CSSStyleDeclaration::get_cssText","cocktail/core/css/CSSStyleDeclaration.hx",3916);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3916)
	return this->serializeStyleDeclaration();
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,get_cssText,return )

::String CSSStyleDeclaration_obj::serializeStyleDeclaration( ){
	HX_STACK_PUSH("CSSStyleDeclaration::serializeStyleDeclaration","cocktail/core/css/CSSStyleDeclaration.hx",3893);
	HX_STACK_THIS(this);
	HX_STACK_LINE(3894)
	::String serializedStyleDeclaration = HX_CSTRING("");		HX_STACK_VAR(serializedStyleDeclaration,"serializedStyleDeclaration");
	HX_STACK_LINE(3896)
	{
		HX_STACK_LINE(3896)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3896)
		while(((_g1 < _g))){
			HX_STACK_LINE(3896)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(3898)
			::cocktail::core::css::TypedPropertyVO property = this->_indexedProperties->__get(this->_propertiesPositions->__get(i));		HX_STACK_VAR(property,"property");
			HX_STACK_LINE(3900)
			hx::AddEq(serializedStyleDeclaration,((::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(property->index) + HX_CSTRING(":")) + ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(property->typedValue)));
			HX_STACK_LINE(3901)
			if (((property->important == true))){
				HX_STACK_LINE(3902)
				hx::AddEq(serializedStyleDeclaration,HX_CSTRING(" !important"));
			}
			HX_STACK_LINE(3905)
			hx::AddEq(serializedStyleDeclaration,HX_CSTRING(";"));
		}
	}
	HX_STACK_LINE(3908)
	return serializedStyleDeclaration;
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,serializeStyleDeclaration,return )

bool CSSStyleDeclaration_obj::isPositiveLength( ::cocktail::core::css::CSSLengthValue length){
	HX_STACK_PUSH("CSSStyleDeclaration::isPositiveLength","cocktail/core/css/CSSStyleDeclaration.hx",3855);
	HX_STACK_THIS(this);
	HX_STACK_ARG(length,"length");
	HX_STACK_LINE(3855)
	{
		::cocktail::core::css::CSSLengthValue _switch_1 = (length);
		switch((_switch_1)->GetIndex()){
			case 0: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3858)
					return (value >= (int)0);
				}
			}
			;break;
			case 6: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3861)
					return (value >= (int)0);
				}
			}
			;break;
			case 5: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3864)
					return (value >= (int)0);
				}
			}
			;break;
			case 4: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3867)
					return (value >= (int)0);
				}
			}
			;break;
			case 7: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3870)
					return (value >= (int)0);
				}
			}
			;break;
			case 3: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3873)
					return (value >= (int)0);
				}
			}
			;break;
			case 2: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3876)
					return (value >= (int)0);
				}
			}
			;break;
			case 1: {
				Float value = _switch_1->__Param(0);
{
					HX_STACK_LINE(3879)
					return (value >= (int)0);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(3855)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isPositiveLength,return )

bool CSSStyleDeclaration_obj::isValidPaddingProperty( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidPaddingProperty","cocktail/core/css/CSSStyleDeclaration.hx",3819);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3820)
	{
		::cocktail::core::css::CSSPropertyValue _switch_2 = (styleValue);
		switch((_switch_2)->GetIndex()){
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_2->__Param(0);
{
					HX_STACK_LINE(3822)
					if (((this->isPositiveLength(value) == true))){
						HX_STACK_LINE(3824)
						return true;
					}
				}
			}
			;break;
			case 0: {
				int value = _switch_2->__Param(0);
{
					HX_STACK_LINE(3828)
					if (((value == (int)0))){
						HX_STACK_LINE(3830)
						return true;
					}
				}
			}
			;break;
			case 2: {
				Float value = _switch_2->__Param(0);
{
					HX_STACK_LINE(3834)
					if (((value >= (int)0))){
						HX_STACK_LINE(3836)
						return true;
					}
				}
			}
			;break;
			case 16: {
				HX_STACK_LINE(3840)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(3846)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidPaddingProperty,return )

bool CSSStyleDeclaration_obj::isValidMarginProperty( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidMarginProperty","cocktail/core/css/CSSStyleDeclaration.hx",3782);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3783)
	{
		::cocktail::core::css::CSSPropertyValue _switch_3 = (styleValue);
		switch((_switch_3)->GetIndex()){
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_3->__Param(0);
{
					HX_STACK_LINE(3785)
					return true;
				}
			}
			;break;
			case 0: {
				int value = _switch_3->__Param(0);
{
					HX_STACK_LINE(3788)
					if (((value == (int)0))){
						HX_STACK_LINE(3790)
						return true;
					}
				}
			}
			;break;
			case 2: {
				Float value = _switch_3->__Param(0);
{
					HX_STACK_LINE(3794)
					return true;
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_3->__Param(0);
{
					HX_STACK_LINE(3797)
					{
						::cocktail::core::css::CSSKeywordValue _switch_4 = (value);
						switch((_switch_4)->GetIndex()){
							case 27: {
								HX_STACK_LINE(3800)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 16: {
				HX_STACK_LINE(3806)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(3812)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidMarginProperty,return )

bool CSSStyleDeclaration_obj::isValidOverflowValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidOverflowValue","cocktail/core/css/CSSStyleDeclaration.hx",3760);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3761)
	{
		::cocktail::core::css::CSSPropertyValue _switch_5 = (styleValue);
		switch((_switch_5)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_5->__Param(0);
{
					HX_STACK_LINE(3763)
					{
						::cocktail::core::css::CSSKeywordValue _switch_6 = (value);
						switch((_switch_6)->GetIndex()){
							case 36: case 38: case 37: case 27: {
								HX_STACK_LINE(3766)
								return true;
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
	HX_STACK_LINE(3775)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidOverflowValue,return )

bool CSSStyleDeclaration_obj::isValidOutlineStyleValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidOutlineStyleValue","cocktail/core/css/CSSStyleDeclaration.hx",3738);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3738)
	{
		::cocktail::core::css::CSSPropertyValue _switch_7 = (styleValue);
		switch((_switch_7)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(3741)
					{
						::cocktail::core::css::CSSKeywordValue _switch_8 = (value);
						switch((_switch_8)->GetIndex()){
							case 37: {
								HX_STACK_LINE(3744)
								return false;
							}
							;break;
							default: {
								HX_STACK_LINE(3747)
								return this->isValidBorderStyleValue(styleValue);
							}
						}
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(3751)
				return this->isValidBorderStyleValue(styleValue);
			}
		}
	}
	HX_STACK_LINE(3738)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidOutlineStyleValue,return )

bool CSSStyleDeclaration_obj::isValidOutlineColorValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidOutlineColorValue","cocktail/core/css/CSSStyleDeclaration.hx",3716);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3716)
	{
		::cocktail::core::css::CSSPropertyValue _switch_9 = (styleValue);
		switch((_switch_9)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_9->__Param(0);
{
					HX_STACK_LINE(3719)
					{
						::cocktail::core::css::CSSKeywordValue _switch_10 = (value);
						switch((_switch_10)->GetIndex()){
							case 83: {
								HX_STACK_LINE(3722)
								return true;
							}
							;break;
							default: {
								HX_STACK_LINE(3725)
								return this->isValidBorderColorValue(styleValue);
							}
						}
					}
				}
			}
			;break;
			default: {
				HX_STACK_LINE(3729)
				return this->isValidBorderColorValue(styleValue);
			}
		}
	}
	HX_STACK_LINE(3716)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidOutlineColorValue,return )

bool CSSStyleDeclaration_obj::isValidBorderStyleValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBorderStyleValue","cocktail/core/css/CSSStyleDeclaration.hx",3693);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3694)
	{
		::cocktail::core::css::CSSPropertyValue _switch_11 = (styleValue);
		switch((_switch_11)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_11->__Param(0);
{
					HX_STACK_LINE(3696)
					{
						::cocktail::core::css::CSSKeywordValue _switch_12 = (value);
						switch((_switch_12)->GetIndex()){
							case 18: case 37: case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: {
								HX_STACK_LINE(3699)
								return true;
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
	HX_STACK_LINE(3709)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBorderStyleValue,return )

bool CSSStyleDeclaration_obj::isValidBorderColorValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBorderColorValue","cocktail/core/css/CSSStyleDeclaration.hx",3677);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3678)
	{
		::cocktail::core::css::CSSPropertyValue _switch_13 = (styleValue);
		switch((_switch_13)->GetIndex()){
			case 12: {
				::cocktail::core::css::CSSColorValue value = _switch_13->__Param(0);
{
					HX_STACK_LINE(3680)
					return true;
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(3686)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBorderColorValue,return )

bool CSSStyleDeclaration_obj::isValidBorderWidthValue( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBorderWidthValue","cocktail/core/css/CSSStyleDeclaration.hx",3643);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3644)
	{
		::cocktail::core::css::CSSPropertyValue _switch_14 = (styleValue);
		switch((_switch_14)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_14->__Param(0);
{
					HX_STACK_LINE(3646)
					{
						::cocktail::core::css::CSSKeywordValue _switch_15 = (value);
						switch((_switch_15)->GetIndex()){
							case 73: case 61: case 74: {
								HX_STACK_LINE(3649)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_14->__Param(0);
{
					HX_STACK_LINE(3655)
					if (((this->isPositiveLength(value) == true))){
						HX_STACK_LINE(3657)
						return true;
					}
				}
			}
			;break;
			case 0: {
				int value = _switch_14->__Param(0);
{
					HX_STACK_LINE(3661)
					if (((value == (int)0))){
						HX_STACK_LINE(3663)
						return true;
					}
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(3670)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBorderWidthValue,return )

bool CSSStyleDeclaration_obj::isValidTransitionGroup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidTransitionGroup","cocktail/core/css/CSSStyleDeclaration.hx",3476);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(3479)
	bool hasTransitionProperty = false;		HX_STACK_VAR(hasTransitionProperty,"hasTransitionProperty");
	HX_STACK_LINE(3480)
	bool hasTransitionTimingFunction = false;		HX_STACK_VAR(hasTransitionTimingFunction,"hasTransitionTimingFunction");
	HX_STACK_LINE(3481)
	bool hasTransitionDelay = false;		HX_STACK_VAR(hasTransitionDelay,"hasTransitionDelay");
	HX_STACK_LINE(3482)
	bool hasTransitionDuration = false;		HX_STACK_VAR(hasTransitionDuration,"hasTransitionDuration");
	HX_STACK_LINE(3485)
	if (((bool((bool((styleValues->length == (int)2)) || bool((styleValues->length == (int)3)))) || bool((styleValues->length == (int)4))))){
		HX_STACK_LINE(3489)
		if ((this->isValidTransitionProperty(styleValues->__get((int)0)))){
			HX_STACK_LINE(3490)
			hasTransitionProperty = true;
		}
		else{
			HX_STACK_LINE(3493)
			if ((this->isValidTransitionDelayOrDuration(styleValues->__get((int)0)))){
				HX_STACK_LINE(3494)
				hasTransitionDuration = true;
			}
			else{
				HX_STACK_LINE(3497)
				if ((this->isValidTransitionTimingFunction(styleValues->__get((int)0)))){
					HX_STACK_LINE(3498)
					hasTransitionTimingFunction = true;
				}
				else{
					HX_STACK_LINE(3503)
					return false;
				}
			}
		}
		HX_STACK_LINE(3508)
		if ((this->isValidTransitionProperty(styleValues->__get((int)1)))){
			HX_STACK_LINE(3509)
			if (((hasTransitionProperty == true))){
				HX_STACK_LINE(3511)
				return false;
			}
		}
		else{
			HX_STACK_LINE(3515)
			if ((this->isValidTransitionDelayOrDuration(styleValues->__get((int)1)))){
				HX_STACK_LINE(3516)
				if (((hasTransitionDuration == true))){
					HX_STACK_LINE(3521)
					hasTransitionDelay = true;
				}
				else{
					HX_STACK_LINE(3525)
					hasTransitionDuration = true;
				}
			}
			else{
				HX_STACK_LINE(3529)
				if ((this->isValidTransitionTimingFunction(styleValues->__get((int)1)))){
					HX_STACK_LINE(3530)
					if (((hasTransitionTimingFunction == true))){
						HX_STACK_LINE(3532)
						return false;
					}
				}
				else{
					HX_STACK_LINE(3537)
					return false;
				}
			}
		}
		HX_STACK_LINE(3543)
		if (((styleValues->length == (int)2))){
			HX_STACK_LINE(3544)
			return true;
		}
		HX_STACK_LINE(3549)
		if ((this->isValidTransitionProperty(styleValues->__get((int)2)))){
			HX_STACK_LINE(3550)
			if (((hasTransitionProperty == true))){
				HX_STACK_LINE(3552)
				return false;
			}
		}
		else{
			HX_STACK_LINE(3556)
			if ((this->isValidTransitionDelayOrDuration(styleValues->__get((int)2)))){
				HX_STACK_LINE(3557)
				if (((hasTransitionDuration == true))){
					HX_STACK_LINE(3559)
					if (((hasTransitionDelay == true))){
						HX_STACK_LINE(3562)
						return false;
					}
					else{
						HX_STACK_LINE(3566)
						hasTransitionDelay = true;
					}
				}
				else{
					HX_STACK_LINE(3571)
					hasTransitionDuration = true;
				}
			}
			else{
				HX_STACK_LINE(3575)
				if ((this->isValidTransitionTimingFunction(styleValues->__get((int)2)))){
					HX_STACK_LINE(3576)
					if (((hasTransitionTimingFunction == true))){
						HX_STACK_LINE(3578)
						return false;
					}
				}
				else{
					HX_STACK_LINE(3583)
					return false;
				}
			}
		}
		HX_STACK_LINE(3589)
		if (((styleValues->length == (int)3))){
			HX_STACK_LINE(3590)
			return true;
		}
		HX_STACK_LINE(3595)
		if ((this->isValidTransitionProperty(styleValues->__get((int)3)))){
			HX_STACK_LINE(3596)
			if (((hasTransitionProperty == true))){
				HX_STACK_LINE(3598)
				return false;
			}
		}
		else{
			HX_STACK_LINE(3602)
			if ((this->isValidTransitionDelayOrDuration(styleValues->__get((int)3)))){
				HX_STACK_LINE(3603)
				if (((hasTransitionDuration == true))){
					HX_STACK_LINE(3605)
					if (((hasTransitionDelay == true))){
						HX_STACK_LINE(3608)
						return false;
					}
					else{
						HX_STACK_LINE(3612)
						hasTransitionDelay = true;
					}
				}
				else{
					HX_STACK_LINE(3617)
					hasTransitionDuration = true;
				}
			}
			else{
				HX_STACK_LINE(3621)
				if ((this->isValidTransitionTimingFunction(styleValues->__get((int)3)))){
					HX_STACK_LINE(3622)
					if (((hasTransitionTimingFunction == true))){
						HX_STACK_LINE(3624)
						return false;
					}
				}
				else{
					HX_STACK_LINE(3629)
					return false;
				}
			}
		}
		HX_STACK_LINE(3633)
		return true;
	}
	HX_STACK_LINE(3636)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidTransitionGroup,return )

bool CSSStyleDeclaration_obj::isValidFontGroup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidFontGroup","cocktail/core/css/CSSStyleDeclaration.hx",3286);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(3292)
	bool foundFontStyle = false;		HX_STACK_VAR(foundFontStyle,"foundFontStyle");
	HX_STACK_LINE(3293)
	bool foundFontVariant = false;		HX_STACK_VAR(foundFontVariant,"foundFontVariant");
	HX_STACK_LINE(3294)
	bool foundFontWeight = false;		HX_STACK_VAR(foundFontWeight,"foundFontWeight");
	HX_STACK_LINE(3295)
	bool foundFontSize = false;		HX_STACK_VAR(foundFontSize,"foundFontSize");
	HX_STACK_LINE(3296)
	bool foundFontNotation = false;		HX_STACK_VAR(foundFontNotation,"foundFontNotation");
	HX_STACK_LINE(3297)
	bool foundFontFamily = false;		HX_STACK_VAR(foundFontFamily,"foundFontFamily");
	HX_STACK_LINE(3299)
	int length = styleValues->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(3300)
	{
		HX_STACK_LINE(3300)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(3300)
		while(((_g < length))){
			HX_STACK_LINE(3300)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(3302)
			{
				::cocktail::core::css::CSSPropertyValue _switch_16 = (styleValues->__get(i));
				switch((_switch_16)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3304)
							{
								::cocktail::core::css::CSSKeywordValue _switch_17 = (value);
								switch((_switch_17)->GetIndex()){
									case 4: case 5: {
										HX_STACK_LINE(3308)
										if (((foundFontStyle == true))){
											HX_STACK_LINE(3309)
											return false;
										}
										HX_STACK_LINE(3313)
										foundFontStyle = true;
									}
									;break;
									case 6: {
										HX_STACK_LINE(3316)
										if (((foundFontVariant == true))){
											HX_STACK_LINE(3317)
											return false;
										}
										HX_STACK_LINE(3321)
										foundFontVariant = true;
									}
									;break;
									case 1: case 2: case 3: {
										HX_STACK_LINE(3324)
										if (((foundFontWeight == true))){
											HX_STACK_LINE(3325)
											return false;
										}
										HX_STACK_LINE(3329)
										foundFontWeight = true;
									}
									;break;
									case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: {
										HX_STACK_LINE(3333)
										if (((foundFontSize == true))){
											HX_STACK_LINE(3334)
											return false;
										}
										HX_STACK_LINE(3338)
										foundFontSize = true;
										HX_STACK_LINE(3339)
										foundFontStyle = true;
										HX_STACK_LINE(3340)
										foundFontVariant = true;
									}
									;break;
									case 0: {
										HX_STACK_LINE(3342)
										if (((foundFontStyle == true))){
											HX_STACK_LINE(3344)
											if (((foundFontVariant == true))){
												HX_STACK_LINE(3346)
												if (((foundFontWeight == true))){
													HX_STACK_LINE(3348)
													return false;
												}
												else{
													HX_STACK_LINE(3352)
													foundFontWeight = true;
												}
											}
											else{
												HX_STACK_LINE(3357)
												foundFontVariant = true;
											}
										}
										else{
											HX_STACK_LINE(3362)
											foundFontStyle = true;
										}
									}
									;break;
									default: {
										HX_STACK_LINE(3366)
										return false;
									}
								}
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3370)
							switch( (int)(value)){
								case (int)100: case (int)200: case (int)300: case (int)400: case (int)500: case (int)600: case (int)700: case (int)800: case (int)900: {
									HX_STACK_LINE(3375)
									if (((foundFontWeight == true))){
										HX_STACK_LINE(3376)
										return false;
									}
									HX_STACK_LINE(3380)
									foundFontWeight = true;
								}
								;break;
								default: {
									HX_STACK_LINE(3383)
									return false;
								}
							}
						}
					}
					;break;
					case 6: {
						::String value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3392)
							if (((foundFontSize == false))){
								HX_STACK_LINE(3393)
								return false;
							}
							HX_STACK_LINE(3397)
							foundFontFamily = true;
							HX_STACK_LINE(3398)
							foundFontNotation = true;
							HX_STACK_LINE(3399)
							foundFontSize = true;
							HX_STACK_LINE(3400)
							foundFontStyle = true;
							HX_STACK_LINE(3401)
							foundFontVariant = true;
							HX_STACK_LINE(3402)
							foundFontWeight = true;
						}
					}
					;break;
					case 3: {
						::String value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3408)
							if (((foundFontSize == false))){
								HX_STACK_LINE(3409)
								return false;
							}
							HX_STACK_LINE(3413)
							foundFontFamily = true;
							HX_STACK_LINE(3414)
							foundFontNotation = true;
							HX_STACK_LINE(3415)
							foundFontSize = true;
							HX_STACK_LINE(3416)
							foundFontStyle = true;
							HX_STACK_LINE(3417)
							foundFontVariant = true;
							HX_STACK_LINE(3418)
							foundFontWeight = true;
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3421)
							if (((foundFontSize == true))){
								HX_STACK_LINE(3422)
								return false;
							}
							HX_STACK_LINE(3426)
							foundFontNotation = true;
							HX_STACK_LINE(3427)
							foundFontSize = true;
							HX_STACK_LINE(3428)
							foundFontStyle = true;
							HX_STACK_LINE(3429)
							foundFontVariant = true;
							HX_STACK_LINE(3430)
							foundFontWeight = true;
						}
					}
					;break;
					case 2: {
						Float value = _switch_16->__Param(0);
{
							HX_STACK_LINE(3433)
							if (((foundFontSize == true))){
								HX_STACK_LINE(3434)
								return false;
							}
							HX_STACK_LINE(3438)
							foundFontNotation = true;
							HX_STACK_LINE(3439)
							foundFontSize = true;
							HX_STACK_LINE(3440)
							foundFontStyle = true;
							HX_STACK_LINE(3441)
							foundFontVariant = true;
							HX_STACK_LINE(3442)
							foundFontWeight = true;
						}
					}
					;break;
					case 14: {
						::cocktail::core::css::CSSPropertyValue lineHeight = _switch_16->__Param(1);
						::cocktail::core::css::CSSPropertyValue fontSize = _switch_16->__Param(0);
{
							HX_STACK_LINE(3445)
							if (((foundFontNotation == true))){
								HX_STACK_LINE(3446)
								return false;
							}
							HX_STACK_LINE(3450)
							foundFontNotation = true;
							HX_STACK_LINE(3451)
							foundFontSize = true;
							HX_STACK_LINE(3452)
							foundFontStyle = true;
							HX_STACK_LINE(3453)
							foundFontVariant = true;
							HX_STACK_LINE(3454)
							foundFontWeight = true;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(3456)
						return false;
					}
				}
			}
		}
	}
	HX_STACK_LINE(3463)
	if (((bool((foundFontFamily == false)) || bool((foundFontSize == false))))){
		HX_STACK_LINE(3464)
		return false;
	}
	HX_STACK_LINE(3468)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidFontGroup,return )

bool CSSStyleDeclaration_obj::isValidFontShorthand( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidFontShorthand","cocktail/core/css/CSSStyleDeclaration.hx",3225);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3226)
	{
		::cocktail::core::css::CSSPropertyValue _switch_18 = (styleValue);
		switch((_switch_18)->GetIndex()){
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > values = _switch_18->__Param(0);
{
					HX_STACK_LINE(3228)
					return this->isValidFontGroup(values);
				}
			}
			;break;
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > values = _switch_18->__Param(0);
{
					HX_STACK_LINE(3236)
					{
						::cocktail::core::css::CSSPropertyValue _switch_19 = (values->__get((int)0));
						switch((_switch_19)->GetIndex()){
							case 13: {
								Array< ::cocktail::core::css::CSSPropertyValue > groupValues = _switch_19->__Param(0);
{
									HX_STACK_LINE(3240)
									bool isValidFontGroup = this->isValidFontGroup(groupValues);		HX_STACK_VAR(isValidFontGroup,"isValidFontGroup");
									HX_STACK_LINE(3241)
									if (((isValidFontGroup == true))){
										HX_STACK_LINE(3243)
										int length = values->length;		HX_STACK_VAR(length,"length");
										HX_STACK_LINE(3244)
										int i = (int)1;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(3245)
										while(((i < length))){
											HX_STACK_LINE(3247)
											{
												::cocktail::core::css::CSSPropertyValue _switch_20 = (values->__get(i));
												switch((_switch_20)->GetIndex()){
													case 6: {
														::String value = _switch_20->__Param(0);
{
														}
													}
													;break;
													case 3: {
														::String value = _switch_20->__Param(0);
{
														}
													}
													;break;
													default: {
														HX_STACK_LINE(3253)
														return false;
													}
												}
											}
											HX_STACK_LINE(3257)
											(i)++;
										}
									}
									else{
										HX_STACK_LINE(3261)
										return false;
									}
								}
							}
							;break;
							default: {
								HX_STACK_LINE(3265)
								return false;
							}
						}
					}
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(3270)
				return true;
			}
			;break;
			default: {
				HX_STACK_LINE(3273)
				return false;
			}
		}
	}
	HX_STACK_LINE(3277)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidFontShorthand,return )

Void CSSStyleDeclaration_obj::setFontShorthandGoup( Array< ::cocktail::core::css::CSSPropertyValue > styleValues,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setFontShorthandGoup","cocktail/core/css/CSSStyleDeclaration.hx",3143);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleValues,"styleValues");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(3144)
		bool foundFontStyle = false;		HX_STACK_VAR(foundFontStyle,"foundFontStyle");
		HX_STACK_LINE(3145)
		bool foundFontVariant = false;		HX_STACK_VAR(foundFontVariant,"foundFontVariant");
		HX_STACK_LINE(3146)
		bool foundFontWeight = false;		HX_STACK_VAR(foundFontWeight,"foundFontWeight");
		HX_STACK_LINE(3148)
		int length = styleValues->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(3149)
		{
			HX_STACK_LINE(3149)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(3149)
			while(((_g < length))){
				HX_STACK_LINE(3149)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(3151)
				{
					::cocktail::core::css::CSSPropertyValue _switch_21 = (styleValues->__get(i));
					switch((_switch_21)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_21->__Param(0);
{
								HX_STACK_LINE(3153)
								{
									::cocktail::core::css::CSSKeywordValue _switch_22 = (value);
									switch((_switch_22)->GetIndex()){
										case 4: case 5: {
											HX_STACK_LINE(3157)
											this->setTypedProperty((int)36,styleValues->__get(i),important);
											HX_STACK_LINE(3158)
											foundFontStyle = true;
										}
										;break;
										case 6: {
											HX_STACK_LINE(3161)
											this->setTypedProperty((int)38,styleValues->__get(i),important);
											HX_STACK_LINE(3162)
											foundFontVariant = true;
										}
										;break;
										case 1: case 2: case 3: {
											HX_STACK_LINE(3165)
											this->setTypedProperty((int)35,styleValues->__get(i),important);
											HX_STACK_LINE(3166)
											foundFontWeight = true;
										}
										;break;
										case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: {
											HX_STACK_LINE(3168)
											this->setTypedProperty((int)34,styleValues->__get(i),important);
										}
										;break;
										case 0: {
											HX_STACK_LINE(3172)
											if (((foundFontStyle == true))){
												HX_STACK_LINE(3174)
												if (((foundFontVariant == true))){
													HX_STACK_LINE(3176)
													this->setTypedProperty((int)35,styleValues->__get(i),important);
												}
												else{
													HX_STACK_LINE(3180)
													this->setTypedProperty((int)38,styleValues->__get(i),important);
												}
											}
											else{
												HX_STACK_LINE(3185)
												this->setTypedProperty((int)36,styleValues->__get(i),important);
											}
										}
										;break;
										default: {
										}
									}
								}
							}
						}
						;break;
						case 0: {
							int value = _switch_21->__Param(0);
{
								HX_STACK_LINE(3192)
								switch( (int)(value)){
									case (int)100: case (int)200: case (int)300: case (int)400: case (int)500: case (int)600: case (int)700: case (int)800: case (int)900: {
										HX_STACK_LINE(3197)
										this->setTypedProperty((int)35,styleValues->__get(i),important);
										HX_STACK_LINE(3198)
										foundFontWeight = true;
									}
									;break;
									default: {
									}
								}
							}
						}
						;break;
						case 7: {
							::cocktail::core::css::CSSLengthValue value = _switch_21->__Param(0);
{
								HX_STACK_LINE(3204)
								this->setTypedProperty((int)34,styleValues->__get(i),important);
							}
						}
						;break;
						case 2: {
							Float value = _switch_21->__Param(0);
{
								HX_STACK_LINE(3207)
								this->setTypedProperty((int)34,styleValues->__get(i),important);
							}
						}
						;break;
						case 14: {
							::cocktail::core::css::CSSPropertyValue lineHeight = _switch_21->__Param(1);
							::cocktail::core::css::CSSPropertyValue fontSize = _switch_21->__Param(0);
{
								HX_STACK_LINE(3211)
								this->setTypedProperty((int)34,fontSize,important);
								HX_STACK_LINE(3212)
								this->setTypedProperty((int)41,lineHeight,important);
							}
						}
						;break;
						default: {
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CSSStyleDeclaration_obj,setFontShorthandGoup,(void))

bool CSSStyleDeclaration_obj::isValidTransitionShorthand( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidTransitionShorthand","cocktail/core/css/CSSStyleDeclaration.hx",3110);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3110)
	{
		::cocktail::core::css::CSSPropertyValue _switch_23 = (styleValue);
		switch((_switch_23)->GetIndex()){
			case 9: {
				::cocktail::core::css::CSSTimeValue value = _switch_23->__Param(0);
{
					HX_STACK_LINE(3113)
					return this->isValidTransitionDelayOrDuration(styleValue);
				}
			}
			;break;
			case 3: {
				::String value = _switch_23->__Param(0);
{
					HX_STACK_LINE(3116)
					return true;
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue keyword = _switch_23->__Param(0);
{
					HX_STACK_LINE(3120)
					bool isValid = this->isValidTransitionProperty(styleValue);		HX_STACK_VAR(isValid,"isValid");
					HX_STACK_LINE(3121)
					if (((isValid == true))){
						HX_STACK_LINE(3122)
						return true;
					}
					HX_STACK_LINE(3125)
					return this->isValidTransitionTimingFunction(styleValue);
				}
			}
			;break;
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_23->__Param(0);
{
					HX_STACK_LINE(3127)
					return this->isValidTransitionGroup(value);
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(3130)
				return true;
			}
			;break;
			default: {
				HX_STACK_LINE(3133)
				return this->isValidTransitionTimingFunction(styleValue);
			}
		}
	}
	HX_STACK_LINE(3110)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidTransitionShorthand,return )

bool CSSStyleDeclaration_obj::isValidBackgroundAttachment( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBackgroundAttachment","cocktail/core/css/CSSStyleDeclaration.hx",3087);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3088)
	{
		::cocktail::core::css::CSSPropertyValue _switch_24 = (styleValue);
		switch((_switch_24)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_24->__Param(0);
{
					HX_STACK_LINE(3090)
					{
						::cocktail::core::css::CSSKeywordValue _switch_25 = (value);
						switch((_switch_25)->GetIndex()){
							case 35: case 38: {
								HX_STACK_LINE(3093)
								return true;
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
	HX_STACK_LINE(3102)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBackgroundAttachment,return )

bool CSSStyleDeclaration_obj::isValidBackgroundRepeat( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBackgroundRepeat","cocktail/core/css/CSSStyleDeclaration.hx",3064);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(3065)
	{
		::cocktail::core::css::CSSPropertyValue _switch_26 = (styleValue);
		switch((_switch_26)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_26->__Param(0);
{
					HX_STACK_LINE(3067)
					{
						::cocktail::core::css::CSSKeywordValue _switch_27 = (value);
						switch((_switch_27)->GetIndex()){
							case 67: case 68: case 69: case 72: {
								HX_STACK_LINE(3070)
								return true;
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
	HX_STACK_LINE(3079)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBackgroundRepeat,return )

bool CSSStyleDeclaration_obj::isValidBackgroundShorthand( ::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBackgroundShorthand","cocktail/core/css/CSSStyleDeclaration.hx",2941);
	HX_STACK_THIS(this);
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(2942)
	{
		::cocktail::core::css::CSSPropertyValue _switch_28 = (styleValue);
		switch((_switch_28)->GetIndex()){
			case 5: {
				::String value = _switch_28->__Param(0);
{
					HX_STACK_LINE(2944)
					return true;
				}
			}
			;break;
			case 12: {
				::cocktail::core::css::CSSColorValue value = _switch_28->__Param(0);
{
					HX_STACK_LINE(2947)
					return true;
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_28->__Param(0);
{
					HX_STACK_LINE(2950)
					{
						::cocktail::core::css::CSSKeywordValue _switch_29 = (value);
						switch((_switch_29)->GetIndex()){
							case 67: case 68: case 69: case 72: case 35: case 38: case 11: case 13: case 12: case 22: case 25: case 18: {
								HX_STACK_LINE(2955)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 13: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_28->__Param(0);
{
					HX_STACK_LINE(2964)
					int length = value->length;		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(2969)
					bool foundBackgroundColor = false;		HX_STACK_VAR(foundBackgroundColor,"foundBackgroundColor");
					HX_STACK_LINE(2970)
					bool foundBackgroundImage = false;		HX_STACK_VAR(foundBackgroundImage,"foundBackgroundImage");
					HX_STACK_LINE(2971)
					bool foundBackgroundRepeat = false;		HX_STACK_VAR(foundBackgroundRepeat,"foundBackgroundRepeat");
					HX_STACK_LINE(2972)
					bool foundBackgroundAttachment = false;		HX_STACK_VAR(foundBackgroundAttachment,"foundBackgroundAttachment");
					HX_STACK_LINE(2975)
					bool foundFirstBackgroundPosition = false;		HX_STACK_VAR(foundFirstBackgroundPosition,"foundFirstBackgroundPosition");
					HX_STACK_LINE(2976)
					bool foundSecondBackgroundPosition = false;		HX_STACK_VAR(foundSecondBackgroundPosition,"foundSecondBackgroundPosition");
					HX_STACK_LINE(2978)
					{
						HX_STACK_LINE(2978)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(2978)
						while(((_g < length))){
							HX_STACK_LINE(2978)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(2980)
							{
								::cocktail::core::css::CSSPropertyValue _switch_30 = (value->__get(i));
								switch((_switch_30)->GetIndex()){
									case 12: {
										::cocktail::core::css::CSSColorValue value1 = _switch_30->__Param(0);
{
											HX_STACK_LINE(2985)
											if (((foundBackgroundColor == true))){
												HX_STACK_LINE(2986)
												return false;
											}
											HX_STACK_LINE(2989)
											foundBackgroundColor = true;
										}
									}
									;break;
									case 5: {
										::String value1 = _switch_30->__Param(0);
{
											HX_STACK_LINE(2992)
											if (((foundBackgroundImage == true))){
												HX_STACK_LINE(2993)
												return false;
											}
											HX_STACK_LINE(2996)
											foundBackgroundImage = true;
											HX_STACK_LINE(2999)
											foundBackgroundColor = true;
										}
									}
									;break;
									default: {
										HX_STACK_LINE(3001)
										if (((this->isValidBackgroundRepeat(value->__get(i)) == true))){
											HX_STACK_LINE(3004)
											if (((foundBackgroundRepeat == true))){
												HX_STACK_LINE(3005)
												return false;
											}
											HX_STACK_LINE(3009)
											foundBackgroundRepeat = true;
											HX_STACK_LINE(3010)
											foundBackgroundImage = true;
											HX_STACK_LINE(3011)
											foundBackgroundColor = true;
										}
										else{
											HX_STACK_LINE(3013)
											if (((this->isValidBackgroundAttachment(value->__get(i)) == true))){
												HX_STACK_LINE(3015)
												if (((foundBackgroundAttachment == true))){
													HX_STACK_LINE(3016)
													return false;
												}
												HX_STACK_LINE(3020)
												foundBackgroundAttachment = true;
												HX_STACK_LINE(3021)
												foundBackgroundColor = true;
												HX_STACK_LINE(3022)
												foundBackgroundRepeat = true;
												HX_STACK_LINE(3023)
												foundBackgroundImage = true;
											}
											else{
												HX_STACK_LINE(3025)
												if (((this->isValidBackgroundPosition(value->__get(i)) == true))){
													HX_STACK_LINE(3027)
													if (((foundSecondBackgroundPosition == true))){
														HX_STACK_LINE(3028)
														return false;
													}
													HX_STACK_LINE(3032)
													if (((foundFirstBackgroundPosition == true))){
														HX_STACK_LINE(3033)
														foundSecondBackgroundPosition = true;
													}
													else{
														HX_STACK_LINE(3037)
														foundFirstBackgroundPosition = true;
													}
													HX_STACK_LINE(3041)
													foundBackgroundAttachment = true;
													HX_STACK_LINE(3042)
													foundBackgroundColor = true;
													HX_STACK_LINE(3043)
													foundBackgroundRepeat = true;
													HX_STACK_LINE(3044)
													foundBackgroundImage = true;
												}
											}
										}
									}
								}
							}
						}
					}
					HX_STACK_LINE(3048)
					return true;
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(3050)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(3056)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBackgroundShorthand,return )

bool CSSStyleDeclaration_obj::isValidShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidShorthand","cocktail/core/css/CSSStyleDeclaration.hx",2473);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(2474)
	switch( (int)(propertyIndex)){
		case (int)5: {
			HX_STACK_LINE(2476)
			{
				::cocktail::core::css::CSSPropertyValue _switch_31 = (styleValue);
				switch((_switch_31)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_31->__Param(0);
{
							HX_STACK_LINE(2479)
							return this->isValidMarginProperty(styleValue);
						}
					}
					;break;
					case 2: {
						Float value = _switch_31->__Param(0);
{
							HX_STACK_LINE(2482)
							return this->isValidMarginProperty(styleValue);
						}
					}
					;break;
					case 0: {
						int value = _switch_31->__Param(0);
{
							HX_STACK_LINE(2485)
							return this->isValidMarginProperty(styleValue);
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_31->__Param(0);
{
							HX_STACK_LINE(2488)
							return this->isValidMarginProperty(styleValue);
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2491)
						return true;
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_31->__Param(0);
{
							HX_STACK_LINE(2494)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(2498)
									bool isValid = this->isValidMarginProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2499)
									if (((isValid == false))){
										HX_STACK_LINE(2500)
										return false;
									}
									HX_STACK_LINE(2503)
									return this->isValidMarginProperty(value->__get((int)1));
								}
								;break;
								case (int)3: {
									HX_STACK_LINE(2506)
									bool isValid = this->isValidMarginProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2507)
									if (((isValid == false))){
										HX_STACK_LINE(2508)
										return false;
									}
									HX_STACK_LINE(2511)
									isValid = this->isValidMarginProperty(value->__get((int)1));
									HX_STACK_LINE(2512)
									if (((isValid == false))){
										HX_STACK_LINE(2513)
										return false;
									}
									HX_STACK_LINE(2516)
									return this->isValidMarginProperty(value->__get((int)2));
								}
								;break;
								case (int)4: {
									HX_STACK_LINE(2519)
									bool isValid = this->isValidMarginProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2520)
									if (((isValid == false))){
										HX_STACK_LINE(2521)
										return false;
									}
									HX_STACK_LINE(2524)
									isValid = this->isValidMarginProperty(value->__get((int)1));
									HX_STACK_LINE(2525)
									if (((isValid == false))){
										HX_STACK_LINE(2526)
										return false;
									}
									HX_STACK_LINE(2529)
									isValid = this->isValidMarginProperty(value->__get((int)2));
									HX_STACK_LINE(2530)
									if (((isValid == false))){
										HX_STACK_LINE(2531)
										return false;
									}
									HX_STACK_LINE(2534)
									return this->isValidMarginProperty(value->__get((int)3));
								}
								;break;
							}
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(2541)
			{
				::cocktail::core::css::CSSPropertyValue _switch_32 = (styleValue);
				switch((_switch_32)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_32->__Param(0);
{
							HX_STACK_LINE(2544)
							return this->isValidPaddingProperty(styleValue);
						}
					}
					;break;
					case 2: {
						Float value = _switch_32->__Param(0);
{
							HX_STACK_LINE(2547)
							return this->isValidPaddingProperty(styleValue);
						}
					}
					;break;
					case 0: {
						int value = _switch_32->__Param(0);
{
							HX_STACK_LINE(2550)
							return this->isValidPaddingProperty(styleValue);
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2553)
						return true;
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_32->__Param(0);
{
							HX_STACK_LINE(2556)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(2560)
									bool isValid = this->isValidPaddingProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2561)
									if (((isValid == false))){
										HX_STACK_LINE(2562)
										return false;
									}
									HX_STACK_LINE(2565)
									return this->isValidPaddingProperty(value->__get((int)1));
								}
								;break;
								case (int)3: {
									HX_STACK_LINE(2568)
									bool isValid = this->isValidPaddingProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2569)
									if (((isValid == false))){
										HX_STACK_LINE(2570)
										return false;
									}
									HX_STACK_LINE(2573)
									isValid = this->isValidPaddingProperty(value->__get((int)1));
									HX_STACK_LINE(2574)
									if (((isValid == false))){
										HX_STACK_LINE(2575)
										return false;
									}
									HX_STACK_LINE(2578)
									return this->isValidPaddingProperty(value->__get((int)2));
								}
								;break;
								case (int)4: {
									HX_STACK_LINE(2581)
									bool isValid = this->isValidPaddingProperty(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(2582)
									if (((isValid == false))){
										HX_STACK_LINE(2583)
										return false;
									}
									HX_STACK_LINE(2586)
									isValid = this->isValidPaddingProperty(value->__get((int)1));
									HX_STACK_LINE(2587)
									if (((isValid == false))){
										HX_STACK_LINE(2588)
										return false;
									}
									HX_STACK_LINE(2591)
									isValid = this->isValidPaddingProperty(value->__get((int)2));
									HX_STACK_LINE(2592)
									if (((isValid == false))){
										HX_STACK_LINE(2593)
										return false;
									}
									HX_STACK_LINE(2596)
									return this->isValidPaddingProperty(value->__get((int)3));
								}
								;break;
							}
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)33: {
			HX_STACK_LINE(2605)
			return this->isValidBackgroundShorthand(styleValue);
		}
		;break;
		case (int)50: {
			HX_STACK_LINE(2608)
			{
				::cocktail::core::css::CSSPropertyValue _switch_33 = (styleValue);
				switch((_switch_33)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_33->__Param(0);
{
							HX_STACK_LINE(2611)
							return this->isValidOverflowValue(styleValue);
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2614)
						return true;
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_33->__Param(0);
{
							HX_STACK_LINE(2618)
							bool isValid = this->isValidOverflowValue(value->__get((int)0));		HX_STACK_VAR(isValid,"isValid");
							HX_STACK_LINE(2619)
							if (((isValid == false))){
								HX_STACK_LINE(2620)
								return false;
							}
							HX_STACK_LINE(2623)
							return this->isValidOverflowValue(value->__get((int)1));
						}
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)39: {
			HX_STACK_LINE(2629)
			return this->isValidFontShorthand(styleValue);
		}
		;break;
		case (int)59: {
			HX_STACK_LINE(2632)
			{
				::cocktail::core::css::CSSPropertyValue _switch_34 = (styleValue);
				switch((_switch_34)->GetIndex()){
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_34->__Param(0);
{
							HX_STACK_LINE(2636)
							int length = value->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(2637)
							{
								HX_STACK_LINE(2637)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(2637)
								while(((_g < length))){
									HX_STACK_LINE(2637)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(2639)
									if (((this->isValidTransitionShorthand(value->__get(i)) == false))){
										HX_STACK_LINE(2640)
										return false;
									}
								}
							}
							HX_STACK_LINE(2645)
							return true;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(2647)
						return this->isValidTransitionShorthand(styleValue);
					}
				}
			}
		}
		;break;
		case (int)66: {
			HX_STACK_LINE(2651)
			{
				::cocktail::core::css::CSSPropertyValue _switch_35 = (styleValue);
				switch((_switch_35)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_35->__Param(0);
{
							HX_STACK_LINE(2654)
							return this->isValidBorderWidthValue(styleValue);
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_35->__Param(0);
{
							HX_STACK_LINE(2657)
							return this->isValidBorderWidthValue(styleValue);
						}
					}
					;break;
					case 0: {
						int value = _switch_35->__Param(0);
{
							HX_STACK_LINE(2660)
							return this->isValidBorderWidthValue(styleValue);
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_35->__Param(0);
{
							HX_STACK_LINE(2663)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(2666)
									if (((bool((this->isValidBorderWidthValue(value->__get((int)0)) == true)) && bool((this->isValidBorderWidthValue(value->__get((int)1)) == true))))){
										HX_STACK_LINE(2669)
										return true;
									}
								}
								;break;
								case (int)3: {
									HX_STACK_LINE(2673)
									if (((bool((bool((this->isValidBorderWidthValue(value->__get((int)0)) == true)) && bool((this->isValidBorderWidthValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderWidthValue(value->__get((int)2)))))){
										HX_STACK_LINE(2676)
										return true;
									}
								}
								;break;
								case (int)4: {
									HX_STACK_LINE(2680)
									if (((bool((bool((bool((this->isValidBorderWidthValue(value->__get((int)0)) == true)) && bool((this->isValidBorderWidthValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderWidthValue(value->__get((int)2))))) && bool(this->isValidBorderWidthValue(value->__get((int)3)))))){
										HX_STACK_LINE(2684)
										return true;
									}
								}
								;break;
								default: {
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2691)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)71: {
			HX_STACK_LINE(2697)
			{
				::cocktail::core::css::CSSPropertyValue _switch_36 = (styleValue);
				switch((_switch_36)->GetIndex()){
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_36->__Param(0);
{
							HX_STACK_LINE(2700)
							return this->isValidBorderColorValue(styleValue);
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_36->__Param(0);
{
							HX_STACK_LINE(2703)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(2706)
									if (((bool((this->isValidBorderColorValue(value->__get((int)0)) == true)) && bool((this->isValidBorderColorValue(value->__get((int)1)) == true))))){
										HX_STACK_LINE(2709)
										return true;
									}
								}
								;break;
								case (int)3: {
									HX_STACK_LINE(2713)
									if (((bool((bool((this->isValidBorderColorValue(value->__get((int)0)) == true)) && bool((this->isValidBorderColorValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderColorValue(value->__get((int)2)))))){
										HX_STACK_LINE(2716)
										return true;
									}
								}
								;break;
								case (int)4: {
									HX_STACK_LINE(2720)
									if (((bool((bool((bool((this->isValidBorderColorValue(value->__get((int)0)) == true)) && bool((this->isValidBorderColorValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderColorValue(value->__get((int)2))))) && bool(this->isValidBorderColorValue(value->__get((int)3)))))){
										HX_STACK_LINE(2724)
										return true;
									}
								}
								;break;
								default: {
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2731)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)76: {
			HX_STACK_LINE(2737)
			{
				::cocktail::core::css::CSSPropertyValue _switch_37 = (styleValue);
				switch((_switch_37)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_37->__Param(0);
{
							HX_STACK_LINE(2740)
							return this->isValidBorderStyleValue(styleValue);
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_37->__Param(0);
{
							HX_STACK_LINE(2743)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(2746)
									if (((bool((this->isValidBorderStyleValue(value->__get((int)0)) == true)) && bool((this->isValidBorderStyleValue(value->__get((int)1)) == true))))){
										HX_STACK_LINE(2749)
										return true;
									}
								}
								;break;
								case (int)3: {
									HX_STACK_LINE(2753)
									if (((bool((bool((this->isValidBorderStyleValue(value->__get((int)0)) == true)) && bool((this->isValidBorderStyleValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderStyleValue(value->__get((int)2)))))){
										HX_STACK_LINE(2756)
										return true;
									}
								}
								;break;
								case (int)4: {
									HX_STACK_LINE(2760)
									if (((bool((bool((bool((this->isValidBorderStyleValue(value->__get((int)0)) == true)) && bool((this->isValidBorderStyleValue(value->__get((int)1)) == true)))) && bool(this->isValidBorderStyleValue(value->__get((int)2))))) && bool(this->isValidBorderStyleValue(value->__get((int)3)))))){
										HX_STACK_LINE(2764)
										return true;
									}
								}
								;break;
								default: {
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2771)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)77: case (int)78: case (int)79: case (int)80: case (int)81: {
			HX_STACK_LINE(2777)
			{
				::cocktail::core::css::CSSPropertyValue _switch_38 = (styleValue);
				switch((_switch_38)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_38->__Param(0);
{
							HX_STACK_LINE(2782)
							if (((bool((this->isValidBorderWidthValue(styleValue) == true)) || bool((this->isValidBorderStyleValue(styleValue) == true))))){
								HX_STACK_LINE(2784)
								return true;
							}
						}
					}
					;break;
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_38->__Param(0);
{
							HX_STACK_LINE(2788)
							return true;
						}
					}
					;break;
					case 0: {
						int value = _switch_38->__Param(0);
{
							HX_STACK_LINE(2791)
							if (((value == (int)0))){
								HX_STACK_LINE(2793)
								return true;
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_38->__Param(0);
{
							HX_STACK_LINE(2797)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(2799)
								return true;
							}
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_38->__Param(0);
{
							HX_STACK_LINE(2804)
							if (((bool((value->length != (int)2)) && bool((value->length != (int)3))))){
								HX_STACK_LINE(2805)
								return false;
							}
							HX_STACK_LINE(2809)
							bool foundBorderWidth = false;		HX_STACK_VAR(foundBorderWidth,"foundBorderWidth");
							HX_STACK_LINE(2810)
							bool foundBorderStyle = false;		HX_STACK_VAR(foundBorderStyle,"foundBorderStyle");
							HX_STACK_LINE(2811)
							bool foundBorderColor = false;		HX_STACK_VAR(foundBorderColor,"foundBorderColor");
							HX_STACK_LINE(2813)
							{
								HX_STACK_LINE(2813)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(2813)
								while(((_g1 < _g))){
									HX_STACK_LINE(2813)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(2815)
									if (((this->isValidBorderWidthValue(value->__get(i)) == true))){
										HX_STACK_LINE(2817)
										if (((foundBorderWidth == true))){
											HX_STACK_LINE(2818)
											return false;
										}
										HX_STACK_LINE(2822)
										foundBorderWidth = true;
									}
									else{
										HX_STACK_LINE(2824)
										if (((this->isValidBorderColorValue(value->__get(i)) == true))){
											HX_STACK_LINE(2826)
											if (((foundBorderColor == true))){
												HX_STACK_LINE(2827)
												return false;
											}
											HX_STACK_LINE(2830)
											foundBorderColor = true;
										}
										else{
											HX_STACK_LINE(2832)
											if (((this->isValidBorderStyleValue(value->__get(i)) == true))){
												HX_STACK_LINE(2834)
												if (((foundBorderStyle == true))){
													HX_STACK_LINE(2835)
													return false;
												}
												HX_STACK_LINE(2838)
												foundBorderStyle = true;
											}
											else{
												HX_STACK_LINE(2841)
												return false;
											}
										}
									}
								}
							}
							HX_STACK_LINE(2846)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2848)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)85: {
			HX_STACK_LINE(2854)
			{
				::cocktail::core::css::CSSPropertyValue _switch_39 = (styleValue);
				switch((_switch_39)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_39->__Param(0);
{
							HX_STACK_LINE(2857)
							if (((bool((bool((this->isValidBorderWidthValue(styleValue) == true)) || bool((this->isValidOutlineStyleValue(styleValue) == true)))) || bool((this->isValidOutlineColorValue(styleValue) == true))))){
								HX_STACK_LINE(2859)
								return true;
							}
						}
					}
					;break;
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_39->__Param(0);
{
							HX_STACK_LINE(2863)
							return true;
						}
					}
					;break;
					case 0: {
						int value = _switch_39->__Param(0);
{
							HX_STACK_LINE(2866)
							if (((value == (int)0))){
								HX_STACK_LINE(2868)
								return true;
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_39->__Param(0);
{
							HX_STACK_LINE(2872)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(2874)
								return true;
							}
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_39->__Param(0);
{
							HX_STACK_LINE(2879)
							if (((bool((value->length != (int)2)) && bool((value->length != (int)3))))){
								HX_STACK_LINE(2880)
								return false;
							}
							HX_STACK_LINE(2884)
							bool foundOutlineWidth = false;		HX_STACK_VAR(foundOutlineWidth,"foundOutlineWidth");
							HX_STACK_LINE(2885)
							bool foundOutlineStyle = false;		HX_STACK_VAR(foundOutlineStyle,"foundOutlineStyle");
							HX_STACK_LINE(2886)
							bool foundOutlineColor = false;		HX_STACK_VAR(foundOutlineColor,"foundOutlineColor");
							HX_STACK_LINE(2888)
							{
								HX_STACK_LINE(2888)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(2888)
								while(((_g1 < _g))){
									HX_STACK_LINE(2888)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(2890)
									if (((this->isValidBorderWidthValue(value->__get(i)) == true))){
										HX_STACK_LINE(2892)
										if (((foundOutlineWidth == true))){
											HX_STACK_LINE(2893)
											return false;
										}
										HX_STACK_LINE(2897)
										foundOutlineWidth = true;
									}
									else{
										HX_STACK_LINE(2899)
										if (((this->isValidOutlineColorValue(value->__get(i)) == true))){
											HX_STACK_LINE(2901)
											if (((foundOutlineColor == true))){
												HX_STACK_LINE(2902)
												return false;
											}
											HX_STACK_LINE(2905)
											foundOutlineColor = true;
										}
										else{
											HX_STACK_LINE(2907)
											if (((this->isValidOutlineStyleValue(value->__get(i)) == true))){
												HX_STACK_LINE(2909)
												if (((foundOutlineStyle == true))){
													HX_STACK_LINE(2910)
													return false;
												}
												HX_STACK_LINE(2913)
												foundOutlineStyle = true;
											}
											else{
												HX_STACK_LINE(2916)
												return false;
											}
										}
									}
								}
							}
							HX_STACK_LINE(2921)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(2923)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		default: {
		}
	}
	HX_STACK_LINE(2933)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSStyleDeclaration_obj,isValidShorthand,return )

Void CSSStyleDeclaration_obj::setTransitionShorthand( ::cocktail::core::css::CSSPropertyValue styleValue,bool useDelayForTime,Array< ::cocktail::core::css::CSSPropertyValue > transitionProperty,Array< ::cocktail::core::css::CSSPropertyValue > transitionDuration,Array< ::cocktail::core::css::CSSPropertyValue > transitionDelay,Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunction){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTransitionShorthand","cocktail/core/css/CSSStyleDeclaration.hx",2437);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleValue,"styleValue");
		HX_STACK_ARG(useDelayForTime,"useDelayForTime");
		HX_STACK_ARG(transitionProperty,"transitionProperty");
		HX_STACK_ARG(transitionDuration,"transitionDuration");
		HX_STACK_ARG(transitionDelay,"transitionDelay");
		HX_STACK_ARG(transitionTimingFunction,"transitionTimingFunction");
		HX_STACK_LINE(2437)
		{
			::cocktail::core::css::CSSPropertyValue _switch_40 = (styleValue);
			switch((_switch_40)->GetIndex()){
				case 3: {
					::String value = _switch_40->__Param(0);
{
						HX_STACK_LINE(2440)
						transitionProperty->push(styleValue);
					}
				}
				;break;
				case 9: {
					::cocktail::core::css::CSSTimeValue value = _switch_40->__Param(0);
{
						HX_STACK_LINE(2443)
						if (((useDelayForTime == false))){
							HX_STACK_LINE(2445)
							transitionDuration->push(styleValue);
						}
						else{
							HX_STACK_LINE(2449)
							transitionDelay->push(styleValue);
						}
					}
				}
				;break;
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_40->__Param(0);
{
						HX_STACK_LINE(2453)
						if (((this->isValidTransitionProperty(styleValue) == true))){
							HX_STACK_LINE(2455)
							transitionProperty->push(styleValue);
						}
						else{
							HX_STACK_LINE(2458)
							if (((this->isValidTransitionTimingFunction(styleValue) == true))){
								HX_STACK_LINE(2459)
								transitionTimingFunction->push(styleValue);
							}
						}
					}
				}
				;break;
				default: {
					HX_STACK_LINE(2463)
					transitionTimingFunction->push(styleValue);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(CSSStyleDeclaration_obj,setTransitionShorthand,(void))

Void CSSStyleDeclaration_obj::setTransitionGroupShorthand( Array< ::cocktail::core::css::CSSPropertyValue > styleValues,Array< ::cocktail::core::css::CSSPropertyValue > transitionProperty,Array< ::cocktail::core::css::CSSPropertyValue > transitionDuration,Array< ::cocktail::core::css::CSSPropertyValue > transitionDelay,Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunction){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTransitionGroupShorthand","cocktail/core/css/CSSStyleDeclaration.hx",2413);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleValues,"styleValues");
		HX_STACK_ARG(transitionProperty,"transitionProperty");
		HX_STACK_ARG(transitionDuration,"transitionDuration");
		HX_STACK_ARG(transitionDelay,"transitionDelay");
		HX_STACK_ARG(transitionTimingFunction,"transitionTimingFunction");
		HX_STACK_LINE(2417)
		bool hasTransitionDuration = false;		HX_STACK_VAR(hasTransitionDuration,"hasTransitionDuration");
		HX_STACK_LINE(2419)
		{
			HX_STACK_LINE(2419)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = styleValues->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(2419)
			while(((_g1 < _g))){
				HX_STACK_LINE(2419)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(2421)
				this->setTransitionShorthand(styleValues->__get(i),hasTransitionDuration,transitionProperty,transitionDuration,transitionDelay,transitionTimingFunction);
				HX_STACK_LINE(2424)
				if (((this->isValidTransitionDelayOrDuration(styleValues->__get(i)) == true))){
					HX_STACK_LINE(2425)
					hasTransitionDuration = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(CSSStyleDeclaration_obj,setTransitionGroupShorthand,(void))

Void CSSStyleDeclaration_obj::setTypedOutlineProperties( ::cocktail::core::css::CSSPropertyValue outlineWidth,::cocktail::core::css::CSSPropertyValue outlineColor,::cocktail::core::css::CSSPropertyValue outlineStyle,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTypedOutlineProperties","cocktail/core/css/CSSStyleDeclaration.hx",2385);
		HX_STACK_THIS(this);
		HX_STACK_ARG(outlineWidth,"outlineWidth");
		HX_STACK_ARG(outlineColor,"outlineColor");
		HX_STACK_ARG(outlineStyle,"outlineStyle");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(2386)
		if (((outlineWidth == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2388);
					{
						HX_STACK_LINE(2388)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2388)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2388)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2388)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2388)
						return _this->_indexedProperties->__get((int)82);
					}
					return null();
				}
			};
			HX_STACK_LINE(2387)
			outlineWidth = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2391)
		this->setTypedProperty((int)82,outlineWidth,important);
		HX_STACK_LINE(2393)
		if (((outlineColor == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2395);
					{
						HX_STACK_LINE(2395)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2395)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2395)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2395)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2395)
						return _this->_indexedProperties->__get((int)84);
					}
					return null();
				}
			};
			HX_STACK_LINE(2394)
			outlineColor = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2397)
		this->setTypedProperty((int)84,outlineColor,important);
		HX_STACK_LINE(2399)
		if (((outlineStyle == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2401);
					{
						HX_STACK_LINE(2401)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2401)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2401)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2401)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2401)
						return _this->_indexedProperties->__get((int)83);
					}
					return null();
				}
			};
			HX_STACK_LINE(2400)
			outlineStyle = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2404)
		this->setTypedProperty((int)83,outlineStyle,important);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(CSSStyleDeclaration_obj,setTypedOutlineProperties,(void))

Void CSSStyleDeclaration_obj::setTypedBorderProperties( int borderWidthPropertyIndex,::cocktail::core::css::CSSPropertyValue borderWidth,int borderColorPropertyIndex,::cocktail::core::css::CSSPropertyValue borderColor,int borderStylePropertyIndex,::cocktail::core::css::CSSPropertyValue borderStyle,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTypedBorderProperties","cocktail/core/css/CSSStyleDeclaration.hx",2357);
		HX_STACK_THIS(this);
		HX_STACK_ARG(borderWidthPropertyIndex,"borderWidthPropertyIndex");
		HX_STACK_ARG(borderWidth,"borderWidth");
		HX_STACK_ARG(borderColorPropertyIndex,"borderColorPropertyIndex");
		HX_STACK_ARG(borderColor,"borderColor");
		HX_STACK_ARG(borderStylePropertyIndex,"borderStylePropertyIndex");
		HX_STACK_ARG(borderStyle,"borderStyle");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(2358)
		if (((borderWidth == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2360);
					{
						HX_STACK_LINE(2360)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2360)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2360)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2360)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2360)
						return _this->_indexedProperties->__get((int)62);
					}
					return null();
				}
			};
			HX_STACK_LINE(2359)
			borderWidth = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2363)
		this->setTypedProperty(borderWidthPropertyIndex,borderWidth,important);
		HX_STACK_LINE(2365)
		if (((borderColor == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2367);
					{
						HX_STACK_LINE(2367)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2367)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2367)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2367)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2367)
						return _this->_indexedProperties->__get((int)67);
					}
					return null();
				}
			};
			HX_STACK_LINE(2366)
			borderColor = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2369)
		this->setTypedProperty(borderColorPropertyIndex,borderColor,important);
		HX_STACK_LINE(2371)
		if (((borderStyle == null()))){
			struct _Function_2_1{
				inline static ::cocktail::core::css::TypedPropertyVO Block( ){
					HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",2373);
					{
						HX_STACK_LINE(2373)
						::cocktail::core::css::InitialStyleDeclaration _this = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(2373)
						if (((_this->_indexedProperties == null()))){
							HX_STACK_LINE(2373)
							_this->resetIndexedProperties();
							HX_STACK_LINE(2373)
							_this->resetPropertiesPositions();
						}
						HX_STACK_LINE(2373)
						return _this->_indexedProperties->__get((int)72);
					}
					return null();
				}
			};
			HX_STACK_LINE(2372)
			borderStyle = (_Function_2_1::Block())->typedValue;
		}
		HX_STACK_LINE(2376)
		this->setTypedProperty(borderStylePropertyIndex,borderStyle,important);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(CSSStyleDeclaration_obj,setTypedBorderProperties,(void))

Void CSSStyleDeclaration_obj::setTypedBordersProperties( int propertyIndex,::cocktail::core::css::CSSPropertyValue borderWidth,::cocktail::core::css::CSSPropertyValue borderColor,::cocktail::core::css::CSSPropertyValue borderStyle,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTypedBordersProperties","cocktail/core/css/CSSStyleDeclaration.hx",2327);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(borderWidth,"borderWidth");
		HX_STACK_ARG(borderColor,"borderColor");
		HX_STACK_ARG(borderStyle,"borderStyle");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(2327)
		switch( (int)(propertyIndex)){
			case (int)77: {
				HX_STACK_LINE(2330)
				this->setTypedBorderProperties((int)62,borderWidth,(int)67,borderColor,(int)72,borderStyle,important);
			}
			;break;
			case (int)78: {
				HX_STACK_LINE(2333)
				this->setTypedBorderProperties((int)63,borderWidth,(int)68,borderColor,(int)73,borderStyle,important);
			}
			;break;
			case (int)79: {
				HX_STACK_LINE(2336)
				this->setTypedBorderProperties((int)64,borderWidth,(int)69,borderColor,(int)74,borderStyle,important);
			}
			;break;
			case (int)80: {
				HX_STACK_LINE(2339)
				this->setTypedBorderProperties((int)65,borderWidth,(int)70,borderColor,(int)75,borderStyle,important);
			}
			;break;
			case (int)81: {
				HX_STACK_LINE(2343)
				this->setTypedBorderProperties((int)62,borderWidth,(int)67,borderColor,(int)72,borderStyle,important);
				HX_STACK_LINE(2344)
				this->setTypedBorderProperties((int)63,borderWidth,(int)68,borderColor,(int)73,borderStyle,important);
				HX_STACK_LINE(2345)
				this->setTypedBorderProperties((int)64,borderWidth,(int)69,borderColor,(int)74,borderStyle,important);
				HX_STACK_LINE(2346)
				this->setTypedBorderProperties((int)65,borderWidth,(int)70,borderColor,(int)75,borderStyle,important);
			}
			;break;
			default: {
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(CSSStyleDeclaration_obj,setTypedBordersProperties,(void))

Void CSSStyleDeclaration_obj::setBorderShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setBorderShorthand","cocktail/core/css/CSSStyleDeclaration.hx",2293);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(styleValue,"styleValue");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(2293)
		{
			::cocktail::core::css::CSSPropertyValue _switch_41 = (styleValue);
			switch((_switch_41)->GetIndex()){
				case 4: {
					::cocktail::core::css::CSSKeywordValue value = _switch_41->__Param(0);
{
						HX_STACK_LINE(2296)
						if (((this->isValidBorderWidthValue(styleValue) == true))){
							HX_STACK_LINE(2298)
							this->setTypedBordersProperties(propertyIndex,styleValue,null(),null(),important);
						}
						else{
							HX_STACK_LINE(2301)
							if (((this->isValidBorderStyleValue(styleValue) == true))){
								HX_STACK_LINE(2302)
								this->setTypedBordersProperties(propertyIndex,null(),null(),styleValue,important);
							}
						}
					}
				}
				;break;
				case 0: {
					int value = _switch_41->__Param(0);
{
						HX_STACK_LINE(2306)
						this->setTypedBordersProperties(propertyIndex,styleValue,null(),null(),important);
					}
				}
				;break;
				case 7: {
					::cocktail::core::css::CSSLengthValue value = _switch_41->__Param(0);
{
						HX_STACK_LINE(2309)
						this->setTypedBordersProperties(propertyIndex,styleValue,null(),null(),important);
					}
				}
				;break;
				case 12: {
					::cocktail::core::css::CSSColorValue value = _switch_41->__Param(0);
{
						HX_STACK_LINE(2312)
						this->setTypedBordersProperties(propertyIndex,null(),styleValue,null(),important);
					}
				}
				;break;
				case 16: case 17: {
					HX_STACK_LINE(2315)
					this->setTypedBordersProperties(propertyIndex,styleValue,styleValue,styleValue,important);
				}
				;break;
				default: {
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,setBorderShorthand,(void))

Void CSSStyleDeclaration_obj::setShorthand( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setShorthand","cocktail/core/css/CSSStyleDeclaration.hx",1738);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(styleValue,"styleValue");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(1738)
		switch( (int)(propertyIndex)){
			case (int)5: {
				HX_STACK_LINE(1741)
				{
					::cocktail::core::css::CSSPropertyValue _switch_42 = (styleValue);
					switch((_switch_42)->GetIndex()){
						case 7: {
							::cocktail::core::css::CSSLengthValue value = _switch_42->__Param(0);
{
								HX_STACK_LINE(1745)
								this->setTypedProperty((int)6,styleValue,important);
								HX_STACK_LINE(1746)
								this->setTypedProperty((int)7,styleValue,important);
								HX_STACK_LINE(1747)
								this->setTypedProperty((int)8,styleValue,important);
								HX_STACK_LINE(1748)
								this->setTypedProperty((int)9,styleValue,important);
							}
						}
						;break;
						case 2: {
							Float value = _switch_42->__Param(0);
{
								HX_STACK_LINE(1751)
								this->setTypedProperty((int)6,styleValue,important);
								HX_STACK_LINE(1752)
								this->setTypedProperty((int)7,styleValue,important);
								HX_STACK_LINE(1753)
								this->setTypedProperty((int)8,styleValue,important);
								HX_STACK_LINE(1754)
								this->setTypedProperty((int)9,styleValue,important);
							}
						}
						;break;
						case 0: {
							int value = _switch_42->__Param(0);
{
								HX_STACK_LINE(1757)
								this->setTypedProperty((int)6,styleValue,important);
								HX_STACK_LINE(1758)
								this->setTypedProperty((int)7,styleValue,important);
								HX_STACK_LINE(1759)
								this->setTypedProperty((int)8,styleValue,important);
								HX_STACK_LINE(1760)
								this->setTypedProperty((int)9,styleValue,important);
							}
						}
						;break;
						case 16: case 17: {
							HX_STACK_LINE(1763)
							this->setTypedProperty((int)6,styleValue,important);
							HX_STACK_LINE(1764)
							this->setTypedProperty((int)7,styleValue,important);
							HX_STACK_LINE(1765)
							this->setTypedProperty((int)8,styleValue,important);
							HX_STACK_LINE(1766)
							this->setTypedProperty((int)9,styleValue,important);
						}
						;break;
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_42->__Param(0);
{
								HX_STACK_LINE(1768)
								if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
									HX_STACK_LINE(1771)
									this->setTypedProperty((int)6,styleValue,important);
									HX_STACK_LINE(1772)
									this->setTypedProperty((int)7,styleValue,important);
									HX_STACK_LINE(1773)
									this->setTypedProperty((int)8,styleValue,important);
									HX_STACK_LINE(1774)
									this->setTypedProperty((int)9,styleValue,important);
								}
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_42->__Param(0);
{
								HX_STACK_LINE(1777)
								switch( (int)(value->length)){
									case (int)2: {
										HX_STACK_LINE(1781)
										this->setTypedProperty((int)6,value->__get((int)1),important);
										HX_STACK_LINE(1782)
										this->setTypedProperty((int)7,value->__get((int)1),important);
										HX_STACK_LINE(1783)
										this->setTypedProperty((int)8,value->__get((int)0),important);
										HX_STACK_LINE(1784)
										this->setTypedProperty((int)9,value->__get((int)0),important);
									}
									;break;
									case (int)3: {
										HX_STACK_LINE(1787)
										this->setTypedProperty((int)6,value->__get((int)1),important);
										HX_STACK_LINE(1788)
										this->setTypedProperty((int)7,value->__get((int)1),important);
										HX_STACK_LINE(1789)
										this->setTypedProperty((int)8,value->__get((int)0),important);
										HX_STACK_LINE(1790)
										this->setTypedProperty((int)9,value->__get((int)2),important);
									}
									;break;
									case (int)4: {
										HX_STACK_LINE(1793)
										this->setTypedProperty((int)6,value->__get((int)3),important);
										HX_STACK_LINE(1794)
										this->setTypedProperty((int)7,value->__get((int)1),important);
										HX_STACK_LINE(1795)
										this->setTypedProperty((int)8,value->__get((int)0),important);
										HX_STACK_LINE(1796)
										this->setTypedProperty((int)9,value->__get((int)2),important);
									}
									;break;
								}
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(1803)
				{
					::cocktail::core::css::CSSPropertyValue _switch_43 = (styleValue);
					switch((_switch_43)->GetIndex()){
						case 7: {
							::cocktail::core::css::CSSLengthValue value = _switch_43->__Param(0);
{
								HX_STACK_LINE(1807)
								this->setTypedProperty((int)11,styleValue,important);
								HX_STACK_LINE(1808)
								this->setTypedProperty((int)12,styleValue,important);
								HX_STACK_LINE(1809)
								this->setTypedProperty((int)13,styleValue,important);
								HX_STACK_LINE(1810)
								this->setTypedProperty((int)14,styleValue,important);
							}
						}
						;break;
						case 2: {
							Float value = _switch_43->__Param(0);
{
								HX_STACK_LINE(1813)
								this->setTypedProperty((int)11,styleValue,important);
								HX_STACK_LINE(1814)
								this->setTypedProperty((int)12,styleValue,important);
								HX_STACK_LINE(1815)
								this->setTypedProperty((int)13,styleValue,important);
								HX_STACK_LINE(1816)
								this->setTypedProperty((int)14,styleValue,important);
							}
						}
						;break;
						case 0: {
							int value = _switch_43->__Param(0);
{
								HX_STACK_LINE(1819)
								this->setTypedProperty((int)11,styleValue,important);
								HX_STACK_LINE(1820)
								this->setTypedProperty((int)12,styleValue,important);
								HX_STACK_LINE(1821)
								this->setTypedProperty((int)13,styleValue,important);
								HX_STACK_LINE(1822)
								this->setTypedProperty((int)14,styleValue,important);
							}
						}
						;break;
						case 16: case 17: {
							HX_STACK_LINE(1825)
							this->setTypedProperty((int)11,styleValue,important);
							HX_STACK_LINE(1826)
							this->setTypedProperty((int)12,styleValue,important);
							HX_STACK_LINE(1827)
							this->setTypedProperty((int)13,styleValue,important);
							HX_STACK_LINE(1828)
							this->setTypedProperty((int)14,styleValue,important);
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_43->__Param(0);
{
								HX_STACK_LINE(1830)
								switch( (int)(value->length)){
									case (int)2: {
										HX_STACK_LINE(1834)
										this->setTypedProperty((int)11,value->__get((int)1),important);
										HX_STACK_LINE(1835)
										this->setTypedProperty((int)12,value->__get((int)1),important);
										HX_STACK_LINE(1836)
										this->setTypedProperty((int)13,value->__get((int)0),important);
										HX_STACK_LINE(1837)
										this->setTypedProperty((int)14,value->__get((int)0),important);
									}
									;break;
									case (int)3: {
										HX_STACK_LINE(1840)
										this->setTypedProperty((int)11,value->__get((int)1),important);
										HX_STACK_LINE(1841)
										this->setTypedProperty((int)12,value->__get((int)1),important);
										HX_STACK_LINE(1842)
										this->setTypedProperty((int)13,value->__get((int)0),important);
										HX_STACK_LINE(1843)
										this->setTypedProperty((int)14,value->__get((int)2),important);
									}
									;break;
									case (int)4: {
										HX_STACK_LINE(1846)
										this->setTypedProperty((int)11,value->__get((int)3),important);
										HX_STACK_LINE(1847)
										this->setTypedProperty((int)12,value->__get((int)1),important);
										HX_STACK_LINE(1848)
										this->setTypedProperty((int)13,value->__get((int)0),important);
										HX_STACK_LINE(1849)
										this->setTypedProperty((int)14,value->__get((int)2),important);
									}
									;break;
								}
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)50: {
				HX_STACK_LINE(1855)
				{
					::cocktail::core::css::CSSPropertyValue _switch_44 = (styleValue);
					switch((_switch_44)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_44->__Param(0);
{
								HX_STACK_LINE(1859)
								this->setTypedProperty((int)51,styleValue,important);
								HX_STACK_LINE(1860)
								this->setTypedProperty((int)52,styleValue,important);
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_44->__Param(0);
{
								HX_STACK_LINE(1863)
								this->setTypedProperty((int)51,value->__get((int)0),important);
								HX_STACK_LINE(1864)
								this->setTypedProperty((int)52,value->__get((int)1),important);
							}
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)33: {
				HX_STACK_LINE(1869)
				{
					::cocktail::core::css::CSSPropertyValue _switch_45 = (styleValue);
					switch((_switch_45)->GetIndex()){
						case 5: {
							::String value = _switch_45->__Param(0);
{
								HX_STACK_LINE(1872)
								this->setTypedProperty((int)26,styleValue,important);
							}
						}
						;break;
						case 12: {
							::cocktail::core::css::CSSColorValue value = _switch_45->__Param(0);
{
								HX_STACK_LINE(1875)
								this->setTypedProperty((int)25,styleValue,important);
							}
						}
						;break;
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_45->__Param(0);
{
								HX_STACK_LINE(1878)
								if (((this->isValidBackgroundRepeat(styleValue) == true))){
									HX_STACK_LINE(1880)
									this->setTypedProperty((int)27,styleValue,important);
								}
								else{
									HX_STACK_LINE(1883)
									if (((this->isValidBackgroundPosition(styleValue) == true))){
										HX_STACK_LINE(1884)
										this->setTypedProperty((int)30,styleValue,important);
									}
									else{
										HX_STACK_LINE(1887)
										if (((this->isValidBackgroundAttachment(styleValue) == true))){
											HX_STACK_LINE(1888)
											this->setTypedProperty((int)32,styleValue,important);
										}
										else{
											HX_STACK_LINE(1892)
											{
												::cocktail::core::css::CSSKeywordValue _switch_46 = (value);
												switch((_switch_46)->GetIndex()){
													case 18: {
														HX_STACK_LINE(1896)
														::cocktail::core::css::InitialStyleDeclaration initialStyleDeclaration = ::cocktail::core::css::InitialStyleDeclaration_obj::getInstance();		HX_STACK_VAR(initialStyleDeclaration,"initialStyleDeclaration");
														struct _Function_7_1{
															inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::InitialStyleDeclaration &initialStyleDeclaration){
																HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",1897);
																{
																	HX_STACK_LINE(1897)
																	if (((initialStyleDeclaration->_indexedProperties == null()))){
																		HX_STACK_LINE(1897)
																		initialStyleDeclaration->resetIndexedProperties();
																		HX_STACK_LINE(1897)
																		initialStyleDeclaration->resetPropertiesPositions();
																	}
																	HX_STACK_LINE(1897)
																	return initialStyleDeclaration->_indexedProperties->__get((int)32);
																}
																return null();
															}
														};
														HX_STACK_LINE(1897)
														this->setTypedProperty((int)32,(_Function_7_1::Block(initialStyleDeclaration))->typedValue,important);
														struct _Function_7_2{
															inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::InitialStyleDeclaration &initialStyleDeclaration){
																HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",1898);
																{
																	HX_STACK_LINE(1898)
																	if (((initialStyleDeclaration->_indexedProperties == null()))){
																		HX_STACK_LINE(1898)
																		initialStyleDeclaration->resetIndexedProperties();
																		HX_STACK_LINE(1898)
																		initialStyleDeclaration->resetPropertiesPositions();
																	}
																	HX_STACK_LINE(1898)
																	return initialStyleDeclaration->_indexedProperties->__get((int)30);
																}
																return null();
															}
														};
														HX_STACK_LINE(1898)
														this->setTypedProperty((int)30,(_Function_7_2::Block(initialStyleDeclaration))->typedValue,important);
														struct _Function_7_3{
															inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::InitialStyleDeclaration &initialStyleDeclaration){
																HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",1899);
																{
																	HX_STACK_LINE(1899)
																	if (((initialStyleDeclaration->_indexedProperties == null()))){
																		HX_STACK_LINE(1899)
																		initialStyleDeclaration->resetIndexedProperties();
																		HX_STACK_LINE(1899)
																		initialStyleDeclaration->resetPropertiesPositions();
																	}
																	HX_STACK_LINE(1899)
																	return initialStyleDeclaration->_indexedProperties->__get((int)25);
																}
																return null();
															}
														};
														HX_STACK_LINE(1899)
														this->setTypedProperty((int)25,(_Function_7_3::Block(initialStyleDeclaration))->typedValue,important);
														struct _Function_7_4{
															inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::InitialStyleDeclaration &initialStyleDeclaration){
																HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",1900);
																{
																	HX_STACK_LINE(1900)
																	if (((initialStyleDeclaration->_indexedProperties == null()))){
																		HX_STACK_LINE(1900)
																		initialStyleDeclaration->resetIndexedProperties();
																		HX_STACK_LINE(1900)
																		initialStyleDeclaration->resetPropertiesPositions();
																	}
																	HX_STACK_LINE(1900)
																	return initialStyleDeclaration->_indexedProperties->__get((int)27);
																}
																return null();
															}
														};
														HX_STACK_LINE(1900)
														this->setTypedProperty((int)27,(_Function_7_4::Block(initialStyleDeclaration))->typedValue,important);
														struct _Function_7_5{
															inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::InitialStyleDeclaration &initialStyleDeclaration){
																HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",1901);
																{
																	HX_STACK_LINE(1901)
																	if (((initialStyleDeclaration->_indexedProperties == null()))){
																		HX_STACK_LINE(1901)
																		initialStyleDeclaration->resetIndexedProperties();
																		HX_STACK_LINE(1901)
																		initialStyleDeclaration->resetPropertiesPositions();
																	}
																	HX_STACK_LINE(1901)
																	return initialStyleDeclaration->_indexedProperties->__get((int)26);
																}
																return null();
															}
														};
														HX_STACK_LINE(1901)
														this->setTypedProperty((int)26,(_Function_7_5::Block(initialStyleDeclaration))->typedValue,important);
													}
													;break;
													default: {
													}
												}
											}
										}
									}
								}
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_45->__Param(0);
{
								HX_STACK_LINE(1908)
								int length = value->length;		HX_STACK_VAR(length,"length");
								HX_STACK_LINE(1912)
								::cocktail::core::css::CSSPropertyValue firstBackgroundPosition = null();		HX_STACK_VAR(firstBackgroundPosition,"firstBackgroundPosition");
								HX_STACK_LINE(1914)
								{
									HX_STACK_LINE(1914)
									int _g = (int)0;		HX_STACK_VAR(_g,"_g");
									HX_STACK_LINE(1914)
									while(((_g < length))){
										HX_STACK_LINE(1914)
										int i = (_g)++;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(1916)
										{
											::cocktail::core::css::CSSPropertyValue _switch_47 = (value->__get(i));
											switch((_switch_47)->GetIndex()){
												case 12: {
													::cocktail::core::css::CSSColorValue color = _switch_47->__Param(0);
{
														HX_STACK_LINE(1918)
														this->setTypedProperty((int)25,value->__get(i),important);
													}
												}
												;break;
												case 5: {
													::String url = _switch_47->__Param(0);
{
														HX_STACK_LINE(1921)
														this->setTypedProperty((int)26,value->__get(i),important);
													}
												}
												;break;
												default: {
													HX_STACK_LINE(1924)
													if (((this->isValidBackgroundRepeat(value->__get(i)) == true))){
														HX_STACK_LINE(1926)
														this->setTypedProperty((int)27,value->__get(i),important);
													}
													else{
														HX_STACK_LINE(1929)
														if (((this->isValidBackgroundAttachment(value->__get(i)) == true))){
															HX_STACK_LINE(1930)
															this->setTypedProperty((int)32,value->__get(i),important);
														}
														else{
															HX_STACK_LINE(1933)
															if (((this->isValidBackgroundPosition(value->__get(i)) == true))){
																HX_STACK_LINE(1934)
																if (((firstBackgroundPosition == null()))){
																	HX_STACK_LINE(1937)
																	this->setTypedProperty((int)30,value->__get(i),important);
																	HX_STACK_LINE(1938)
																	firstBackgroundPosition = value->__get(i);
																}
																else{
																	HX_STACK_LINE(1943)
																	this->setTypedProperty((int)30,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(firstBackgroundPosition).Add(value->__get(i))),important);
																}
															}
														}
													}
												}
											}
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
			}
			;break;
			case (int)39: {
				HX_STACK_LINE(1953)
				{
					::cocktail::core::css::CSSPropertyValue _switch_48 = (styleValue);
					switch((_switch_48)->GetIndex()){
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > values = _switch_48->__Param(0);
{
								HX_STACK_LINE(1958)
								this->setFontShorthandGoup(values,important);
								HX_STACK_LINE(1960)
								this->setTypedProperty((int)37,values->__get((values->length - (int)1)),important);
							}
						}
						;break;
						case 15: {
							Array< ::cocktail::core::css::CSSPropertyValue > values = _switch_48->__Param(0);
{
								HX_STACK_LINE(1962)
								{
									::cocktail::core::css::CSSPropertyValue _switch_49 = (values->__get((int)0));
									switch((_switch_49)->GetIndex()){
										case 13: {
											Array< ::cocktail::core::css::CSSPropertyValue > groupValues = _switch_49->__Param(0);
{
												HX_STACK_LINE(1967)
												this->setFontShorthandGoup(groupValues,important);
												HX_STACK_LINE(1972)
												Array< ::cocktail::core::css::CSSPropertyValue > fontNames = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(fontNames,"fontNames");
												HX_STACK_LINE(1973)
												fontNames->push(groupValues->__get((groupValues->length - (int)1)));
												HX_STACK_LINE(1975)
												int length = values->length;		HX_STACK_VAR(length,"length");
												HX_STACK_LINE(1976)
												int i = (int)1;		HX_STACK_VAR(i,"i");
												HX_STACK_LINE(1977)
												while(((i < length))){
													HX_STACK_LINE(1979)
													fontNames->push(values->__get(i));
													HX_STACK_LINE(1980)
													(i)++;
												}
												HX_STACK_LINE(1984)
												this->setTypedProperty((int)37,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(fontNames),important);
											}
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
			}
			;break;
			case (int)59: {
				HX_STACK_LINE(1997)
				Array< ::cocktail::core::css::CSSPropertyValue > transitionPropertyValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(transitionPropertyValues,"transitionPropertyValues");
				HX_STACK_LINE(1998)
				Array< ::cocktail::core::css::CSSPropertyValue > transitionDurationValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(transitionDurationValues,"transitionDurationValues");
				HX_STACK_LINE(1999)
				Array< ::cocktail::core::css::CSSPropertyValue > transitionDelayValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(transitionDelayValues,"transitionDelayValues");
				HX_STACK_LINE(2000)
				Array< ::cocktail::core::css::CSSPropertyValue > transitionTimingFunctionValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(transitionTimingFunctionValues,"transitionTimingFunctionValues");
				HX_STACK_LINE(2002)
				{
					::cocktail::core::css::CSSPropertyValue _switch_50 = (styleValue);
					switch((_switch_50)->GetIndex()){
						case 15: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_50->__Param(0);
{
								HX_STACK_LINE(2005)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(2005)
								while(((_g1 < _g))){
									HX_STACK_LINE(2005)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(2007)
									{
										::cocktail::core::css::CSSPropertyValue _switch_51 = (value->__get(i));
										switch((_switch_51)->GetIndex()){
											case 13: {
												Array< ::cocktail::core::css::CSSPropertyValue > value1 = _switch_51->__Param(0);
{
													HX_STACK_LINE(2009)
													this->setTransitionGroupShorthand(value1,transitionPropertyValues,transitionDurationValues,transitionDelayValues,transitionTimingFunctionValues);
												}
											}
											;break;
											default: {
												HX_STACK_LINE(2013)
												this->setTransitionShorthand(value->__get(i),false,transitionPropertyValues,transitionDurationValues,transitionDelayValues,transitionTimingFunctionValues);
											}
										}
									}
								}
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_50->__Param(0);
{
								HX_STACK_LINE(2019)
								this->setTransitionGroupShorthand(value,transitionPropertyValues,transitionDurationValues,transitionDelayValues,transitionTimingFunctionValues);
							}
						}
						;break;
						default: {
							HX_STACK_LINE(2023)
							this->setTransitionShorthand(styleValue,false,transitionPropertyValues,transitionDurationValues,transitionDelayValues,transitionTimingFunctionValues);
						}
					}
				}
				HX_STACK_LINE(2028)
				if (((transitionPropertyValues->length > (int)0))){
					HX_STACK_LINE(2029)
					if (((transitionPropertyValues->length == (int)1))){
						HX_STACK_LINE(2031)
						this->setTypedProperty((int)57,transitionPropertyValues->__get((int)0),important);
					}
					else{
						HX_STACK_LINE(2035)
						this->setTypedProperty((int)57,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(transitionPropertyValues),important);
					}
				}
				HX_STACK_LINE(2040)
				if (((transitionDelayValues->length > (int)0))){
					HX_STACK_LINE(2041)
					if (((transitionDelayValues->length == (int)1))){
						HX_STACK_LINE(2043)
						this->setTypedProperty((int)56,transitionDelayValues->__get((int)0),important);
					}
					else{
						HX_STACK_LINE(2047)
						this->setTypedProperty((int)56,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(transitionDelayValues),important);
					}
				}
				HX_STACK_LINE(2052)
				if (((transitionDurationValues->length > (int)0))){
					HX_STACK_LINE(2053)
					if (((transitionDurationValues->length == (int)1))){
						HX_STACK_LINE(2055)
						this->setTypedProperty((int)55,transitionDurationValues->__get((int)0),important);
					}
					else{
						HX_STACK_LINE(2059)
						this->setTypedProperty((int)55,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(transitionDurationValues),important);
					}
				}
				HX_STACK_LINE(2064)
				if (((transitionTimingFunctionValues->length > (int)0))){
					HX_STACK_LINE(2065)
					if (((transitionTimingFunctionValues->length == (int)1))){
						HX_STACK_LINE(2067)
						this->setTypedProperty((int)58,transitionTimingFunctionValues->__get((int)0),important);
					}
					else{
						HX_STACK_LINE(2071)
						this->setTypedProperty((int)58,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(transitionTimingFunctionValues),important);
					}
				}
			}
			;break;
			case (int)66: {
				HX_STACK_LINE(2076)
				{
					::cocktail::core::css::CSSPropertyValue _switch_52 = (styleValue);
					switch((_switch_52)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_52->__Param(0);
{
								HX_STACK_LINE(2080)
								this->setTypedProperty((int)62,styleValue,important);
								HX_STACK_LINE(2081)
								this->setTypedProperty((int)63,styleValue,important);
								HX_STACK_LINE(2082)
								this->setTypedProperty((int)64,styleValue,important);
								HX_STACK_LINE(2083)
								this->setTypedProperty((int)65,styleValue,important);
							}
						}
						;break;
						case 7: {
							::cocktail::core::css::CSSLengthValue value = _switch_52->__Param(0);
{
								HX_STACK_LINE(2086)
								this->setTypedProperty((int)62,styleValue,important);
								HX_STACK_LINE(2087)
								this->setTypedProperty((int)63,styleValue,important);
								HX_STACK_LINE(2088)
								this->setTypedProperty((int)64,styleValue,important);
								HX_STACK_LINE(2089)
								this->setTypedProperty((int)65,styleValue,important);
							}
						}
						;break;
						case 0: {
							int value = _switch_52->__Param(0);
{
								HX_STACK_LINE(2092)
								this->setTypedProperty((int)62,styleValue,important);
								HX_STACK_LINE(2093)
								this->setTypedProperty((int)63,styleValue,important);
								HX_STACK_LINE(2094)
								this->setTypedProperty((int)64,styleValue,important);
								HX_STACK_LINE(2095)
								this->setTypedProperty((int)65,styleValue,important);
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_52->__Param(0);
{
								HX_STACK_LINE(2097)
								switch( (int)(value->length)){
									case (int)2: {
										HX_STACK_LINE(2101)
										this->setTypedProperty((int)62,value->__get((int)0),important);
										HX_STACK_LINE(2102)
										this->setTypedProperty((int)63,value->__get((int)1),important);
										HX_STACK_LINE(2103)
										this->setTypedProperty((int)64,value->__get((int)0),important);
										HX_STACK_LINE(2104)
										this->setTypedProperty((int)65,value->__get((int)1),important);
									}
									;break;
									case (int)3: {
										HX_STACK_LINE(2107)
										this->setTypedProperty((int)62,value->__get((int)0),important);
										HX_STACK_LINE(2108)
										this->setTypedProperty((int)63,value->__get((int)1),important);
										HX_STACK_LINE(2109)
										this->setTypedProperty((int)64,value->__get((int)3),important);
										HX_STACK_LINE(2110)
										this->setTypedProperty((int)65,value->__get((int)1),important);
									}
									;break;
									case (int)4: {
										HX_STACK_LINE(2113)
										this->setTypedProperty((int)62,value->__get((int)0),important);
										HX_STACK_LINE(2114)
										this->setTypedProperty((int)63,value->__get((int)1),important);
										HX_STACK_LINE(2115)
										this->setTypedProperty((int)64,value->__get((int)2),important);
										HX_STACK_LINE(2116)
										this->setTypedProperty((int)65,value->__get((int)3),important);
									}
									;break;
									default: {
									}
								}
							}
						}
						;break;
						case 16: case 17: {
							HX_STACK_LINE(2122)
							this->setTypedProperty((int)62,styleValue,important);
							HX_STACK_LINE(2123)
							this->setTypedProperty((int)63,styleValue,important);
							HX_STACK_LINE(2124)
							this->setTypedProperty((int)64,styleValue,important);
							HX_STACK_LINE(2125)
							this->setTypedProperty((int)65,styleValue,important);
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)71: {
				HX_STACK_LINE(2130)
				{
					::cocktail::core::css::CSSPropertyValue _switch_53 = (styleValue);
					switch((_switch_53)->GetIndex()){
						case 12: {
							::cocktail::core::css::CSSColorValue value = _switch_53->__Param(0);
{
								HX_STACK_LINE(2134)
								this->setTypedProperty((int)67,styleValue,important);
								HX_STACK_LINE(2135)
								this->setTypedProperty((int)68,styleValue,important);
								HX_STACK_LINE(2136)
								this->setTypedProperty((int)69,styleValue,important);
								HX_STACK_LINE(2137)
								this->setTypedProperty((int)70,styleValue,important);
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_53->__Param(0);
{
								HX_STACK_LINE(2139)
								switch( (int)(value->length)){
									case (int)2: {
										HX_STACK_LINE(2143)
										this->setTypedProperty((int)67,value->__get((int)0),important);
										HX_STACK_LINE(2144)
										this->setTypedProperty((int)68,value->__get((int)1),important);
										HX_STACK_LINE(2145)
										this->setTypedProperty((int)69,value->__get((int)0),important);
										HX_STACK_LINE(2146)
										this->setTypedProperty((int)70,value->__get((int)1),important);
									}
									;break;
									case (int)3: {
										HX_STACK_LINE(2149)
										this->setTypedProperty((int)67,value->__get((int)0),important);
										HX_STACK_LINE(2150)
										this->setTypedProperty((int)68,value->__get((int)1),important);
										HX_STACK_LINE(2151)
										this->setTypedProperty((int)69,value->__get((int)3),important);
										HX_STACK_LINE(2152)
										this->setTypedProperty((int)70,value->__get((int)1),important);
									}
									;break;
									case (int)4: {
										HX_STACK_LINE(2155)
										this->setTypedProperty((int)67,value->__get((int)0),important);
										HX_STACK_LINE(2156)
										this->setTypedProperty((int)68,value->__get((int)1),important);
										HX_STACK_LINE(2157)
										this->setTypedProperty((int)69,value->__get((int)2),important);
										HX_STACK_LINE(2158)
										this->setTypedProperty((int)70,value->__get((int)3),important);
									}
									;break;
									default: {
									}
								}
							}
						}
						;break;
						case 16: case 17: {
							HX_STACK_LINE(2164)
							this->setTypedProperty((int)62,styleValue,important);
							HX_STACK_LINE(2165)
							this->setTypedProperty((int)63,styleValue,important);
							HX_STACK_LINE(2166)
							this->setTypedProperty((int)64,styleValue,important);
							HX_STACK_LINE(2167)
							this->setTypedProperty((int)65,styleValue,important);
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)76: {
				HX_STACK_LINE(2172)
				{
					::cocktail::core::css::CSSPropertyValue _switch_54 = (styleValue);
					switch((_switch_54)->GetIndex()){
						case 4: {
							::cocktail::core::css::CSSKeywordValue value = _switch_54->__Param(0);
{
								HX_STACK_LINE(2176)
								this->setTypedProperty((int)72,styleValue,important);
								HX_STACK_LINE(2177)
								this->setTypedProperty((int)73,styleValue,important);
								HX_STACK_LINE(2178)
								this->setTypedProperty((int)74,styleValue,important);
								HX_STACK_LINE(2179)
								this->setTypedProperty((int)75,styleValue,important);
							}
						}
						;break;
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_54->__Param(0);
{
								HX_STACK_LINE(2181)
								switch( (int)(value->length)){
									case (int)2: {
										HX_STACK_LINE(2185)
										this->setTypedProperty((int)72,value->__get((int)0),important);
										HX_STACK_LINE(2186)
										this->setTypedProperty((int)73,value->__get((int)1),important);
										HX_STACK_LINE(2187)
										this->setTypedProperty((int)74,value->__get((int)0),important);
										HX_STACK_LINE(2188)
										this->setTypedProperty((int)75,value->__get((int)1),important);
									}
									;break;
									case (int)3: {
										HX_STACK_LINE(2191)
										this->setTypedProperty((int)72,value->__get((int)0),important);
										HX_STACK_LINE(2192)
										this->setTypedProperty((int)73,value->__get((int)1),important);
										HX_STACK_LINE(2193)
										this->setTypedProperty((int)74,value->__get((int)3),important);
										HX_STACK_LINE(2194)
										this->setTypedProperty((int)75,value->__get((int)1),important);
									}
									;break;
									case (int)4: {
										HX_STACK_LINE(2197)
										this->setTypedProperty((int)72,value->__get((int)0),important);
										HX_STACK_LINE(2198)
										this->setTypedProperty((int)73,value->__get((int)1),important);
										HX_STACK_LINE(2199)
										this->setTypedProperty((int)74,value->__get((int)2),important);
										HX_STACK_LINE(2200)
										this->setTypedProperty((int)75,value->__get((int)3),important);
									}
									;break;
									default: {
									}
								}
							}
						}
						;break;
						case 16: case 17: {
							HX_STACK_LINE(2206)
							this->setTypedProperty((int)72,styleValue,important);
							HX_STACK_LINE(2207)
							this->setTypedProperty((int)73,styleValue,important);
							HX_STACK_LINE(2208)
							this->setTypedProperty((int)74,styleValue,important);
							HX_STACK_LINE(2209)
							this->setTypedProperty((int)75,styleValue,important);
						}
						;break;
						default: {
						}
					}
				}
			}
			;break;
			case (int)77: case (int)79: case (int)80: case (int)78: case (int)81: {
				HX_STACK_LINE(2214)
				{
					::cocktail::core::css::CSSPropertyValue _switch_55 = (styleValue);
					switch((_switch_55)->GetIndex()){
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_55->__Param(0);
{
								HX_STACK_LINE(2220)
								::cocktail::core::css::CSSPropertyValue borderColor = null();		HX_STACK_VAR(borderColor,"borderColor");
								HX_STACK_LINE(2221)
								::cocktail::core::css::CSSPropertyValue borderWidth = null();		HX_STACK_VAR(borderWidth,"borderWidth");
								HX_STACK_LINE(2222)
								::cocktail::core::css::CSSPropertyValue borderStyle = null();		HX_STACK_VAR(borderStyle,"borderStyle");
								HX_STACK_LINE(2223)
								{
									HX_STACK_LINE(2223)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									int _g = value->length;		HX_STACK_VAR(_g,"_g");
									HX_STACK_LINE(2223)
									while(((_g1 < _g))){
										HX_STACK_LINE(2223)
										int i = (_g1)++;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(2225)
										if (((this->isValidBorderColorValue(value->__get(i)) == true))){
											HX_STACK_LINE(2226)
											borderColor = value->__get(i);
										}
										else{
											HX_STACK_LINE(2229)
											if (((this->isValidBorderWidthValue(value->__get(i)) == true))){
												HX_STACK_LINE(2230)
												borderWidth = value->__get(i);
											}
											else{
												HX_STACK_LINE(2233)
												if (((this->isValidBorderStyleValue(value->__get(i)) == true))){
													HX_STACK_LINE(2234)
													borderStyle = value->__get(i);
												}
											}
										}
									}
								}
								HX_STACK_LINE(2238)
								this->setTypedBordersProperties(propertyIndex,borderWidth,borderColor,borderStyle,important);
							}
						}
						;break;
						default: {
							HX_STACK_LINE(2240)
							this->setBorderShorthand(propertyIndex,styleValue,important);
						}
					}
				}
			}
			;break;
			case (int)85: {
				HX_STACK_LINE(2244)
				{
					::cocktail::core::css::CSSPropertyValue _switch_56 = (styleValue);
					switch((_switch_56)->GetIndex()){
						case 13: {
							Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_56->__Param(0);
{
								HX_STACK_LINE(2248)
								::cocktail::core::css::CSSPropertyValue outlineColor = null();		HX_STACK_VAR(outlineColor,"outlineColor");
								HX_STACK_LINE(2249)
								::cocktail::core::css::CSSPropertyValue outlineWidth = null();		HX_STACK_VAR(outlineWidth,"outlineWidth");
								HX_STACK_LINE(2250)
								::cocktail::core::css::CSSPropertyValue outlineStyle = null();		HX_STACK_VAR(outlineStyle,"outlineStyle");
								HX_STACK_LINE(2251)
								{
									HX_STACK_LINE(2251)
									int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
									int _g = value->length;		HX_STACK_VAR(_g,"_g");
									HX_STACK_LINE(2251)
									while(((_g1 < _g))){
										HX_STACK_LINE(2251)
										int i = (_g1)++;		HX_STACK_VAR(i,"i");
										HX_STACK_LINE(2253)
										if (((this->isValidOutlineColorValue(value->__get(i)) == true))){
											HX_STACK_LINE(2254)
											outlineColor = value->__get(i);
										}
										else{
											HX_STACK_LINE(2257)
											if (((this->isValidBorderWidthValue(value->__get(i)) == true))){
												HX_STACK_LINE(2258)
												outlineWidth = value->__get(i);
											}
											else{
												HX_STACK_LINE(2261)
												if (((this->isValidOutlineStyleValue(value->__get(i)) == true))){
													HX_STACK_LINE(2262)
													outlineStyle = value->__get(i);
												}
											}
										}
									}
								}
								HX_STACK_LINE(2266)
								this->setTypedOutlineProperties(outlineWidth,outlineColor,outlineStyle,important);
							}
						}
						;break;
						default: {
							HX_STACK_LINE(2268)
							if (((this->isValidOutlineColorValue(styleValue) == true))){
								HX_STACK_LINE(2270)
								this->setTypedOutlineProperties(null(),styleValue,null(),important);
							}
							else{
								HX_STACK_LINE(2273)
								if (((this->isValidOutlineStyleValue(styleValue) == true))){
									HX_STACK_LINE(2274)
									this->setTypedOutlineProperties(null(),null(),styleValue,important);
								}
								else{
									HX_STACK_LINE(2277)
									if (((this->isValidBorderWidthValue(styleValue) == true))){
										HX_STACK_LINE(2278)
										this->setTypedOutlineProperties(styleValue,null(),null(),important);
									}
								}
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
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,setShorthand,(void))

bool CSSStyleDeclaration_obj::isShorthand( int propertyIndex){
	HX_STACK_PUSH("CSSStyleDeclaration::isShorthand","cocktail/core/css/CSSStyleDeclaration.hx",1718);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(1718)
	switch( (int)(propertyIndex)){
		case (int)5: case (int)10: case (int)50: case (int)59: case (int)33: case (int)39: case (int)77: case (int)80: case (int)78: case (int)79: case (int)66: case (int)71: case (int)76: case (int)81: case (int)85: {
			HX_STACK_LINE(1721)
			return true;
		}
		;break;
		default: {
			HX_STACK_LINE(1728)
			return false;
		}
	}
	HX_STACK_LINE(1718)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isShorthand,return )

bool CSSStyleDeclaration_obj::isValidBackgroundSize( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBackgroundSize","cocktail/core/css/CSSStyleDeclaration.hx",1682);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(1683)
	{
		::cocktail::core::css::CSSPropertyValue _switch_57 = (property);
		switch((_switch_57)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_57->__Param(0);
{
					HX_STACK_LINE(1685)
					return (value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn());
				}
			}
			;break;
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_57->__Param(0);
{
					HX_STACK_LINE(1688)
					if ((this->isPositiveLength(value))){
						HX_STACK_LINE(1690)
						return true;
					}
				}
			}
			;break;
			case 0: {
				int value = _switch_57->__Param(0);
{
					HX_STACK_LINE(1694)
					return (value == (int)0);
				}
			}
			;break;
			case 2: {
				Float value = _switch_57->__Param(0);
{
					HX_STACK_LINE(1697)
					return true;
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(1700)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1706)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBackgroundSize,return )

bool CSSStyleDeclaration_obj::isValidBackgroundPosition( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidBackgroundPosition","cocktail/core/css/CSSStyleDeclaration.hx",1648);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(1649)
	{
		::cocktail::core::css::CSSPropertyValue _switch_58 = (property);
		switch((_switch_58)->GetIndex()){
			case 7: {
				::cocktail::core::css::CSSLengthValue value = _switch_58->__Param(0);
{
					HX_STACK_LINE(1651)
					return true;
				}
			}
			;break;
			case 0: {
				int value = _switch_58->__Param(0);
{
					HX_STACK_LINE(1654)
					return (value == (int)0);
				}
			}
			;break;
			case 2: {
				Float value = _switch_58->__Param(0);
{
					HX_STACK_LINE(1657)
					return true;
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_58->__Param(0);
{
					HX_STACK_LINE(1660)
					{
						::cocktail::core::css::CSSKeywordValue _switch_59 = (value);
						switch((_switch_59)->GetIndex()){
							case 11: case 13: case 12: case 25: case 22: {
								HX_STACK_LINE(1663)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(1669)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1675)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidBackgroundPosition,return )

bool CSSStyleDeclaration_obj::isValidTransitionDelayOrDuration( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidTransitionDelayOrDuration","cocktail/core/css/CSSStyleDeclaration.hx",1621);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(1622)
	{
		::cocktail::core::css::CSSPropertyValue _switch_60 = (property);
		switch((_switch_60)->GetIndex()){
			case 0: {
				int value = _switch_60->__Param(0);
{
					HX_STACK_LINE(1624)
					if (((value == (int)0))){
						HX_STACK_LINE(1626)
						return true;
					}
				}
			}
			;break;
			case 9: {
				::cocktail::core::css::CSSTimeValue value = _switch_60->__Param(0);
{
					HX_STACK_LINE(1630)
					return true;
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(1633)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1639)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidTransitionDelayOrDuration,return )

bool CSSStyleDeclaration_obj::isValidTransitionProperty( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidTransitionProperty","cocktail/core/css/CSSStyleDeclaration.hx",1589);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(1590)
	{
		::cocktail::core::css::CSSPropertyValue _switch_61 = (property);
		switch((_switch_61)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_61->__Param(0);
{
					HX_STACK_LINE(1592)
					{
						::cocktail::core::css::CSSKeywordValue _switch_62 = (value);
						switch((_switch_62)->GetIndex()){
							case 18: case 48: case 11: case 12: case 22: case 25: {
								HX_STACK_LINE(1597)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 3: {
				::String value = _switch_61->__Param(0);
{
					HX_STACK_LINE(1603)
					return true;
				}
			}
			;break;
			case 16: case 17: {
				HX_STACK_LINE(1606)
				return true;
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1612)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidTransitionProperty,return )

bool CSSStyleDeclaration_obj::isValidTransitionTimingFunction( ::cocktail::core::css::CSSPropertyValue property){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidTransitionTimingFunction","cocktail/core/css/CSSStyleDeclaration.hx",1559);
	HX_STACK_THIS(this);
	HX_STACK_ARG(property,"property");
	HX_STACK_LINE(1560)
	{
		::cocktail::core::css::CSSPropertyValue _switch_63 = (property);
		switch((_switch_63)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_63->__Param(0);
{
					HX_STACK_LINE(1562)
					{
						::cocktail::core::css::CSSKeywordValue _switch_64 = (value);
						switch((_switch_64)->GetIndex()){
							case 49: case 51: case 50: case 52: case 53: case 54: case 55: {
								HX_STACK_LINE(1565)
								return true;
							}
							;break;
							default: {
							}
						}
					}
				}
			}
			;break;
			case 19: {
				::cocktail::core::css::CSSKeywordValue intervalChange = _switch_63->__Param(1);
				int intervalNumbers = _switch_63->__Param(0);
{
					HX_STACK_LINE(1571)
					return true;
				}
			}
			;break;
			case 20: {
				Float y2 = _switch_63->__Param(3);
				Float x2 = _switch_63->__Param(2);
				Float y1 = _switch_63->__Param(1);
				Float x1 = _switch_63->__Param(0);
{
					HX_STACK_LINE(1574)
					return true;
				}
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(1580)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,isValidTransitionTimingFunction,return )

bool CSSStyleDeclaration_obj::isValidProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue){
	HX_STACK_PUSH("CSSStyleDeclaration::isValidProperty","cocktail/core/css/CSSStyleDeclaration.hx",554);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(styleValue,"styleValue");
	HX_STACK_LINE(555)
	switch( (int)(propertyIndex)){
		case (int)15: case (int)16: {
			HX_STACK_LINE(557)
			{
				::cocktail::core::css::CSSPropertyValue _switch_65 = (styleValue);
				switch((_switch_65)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_65->__Param(0);
{
							HX_STACK_LINE(560)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(562)
								return true;
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_65->__Param(0);
{
							HX_STACK_LINE(566)
							if (((value == (int)0))){
								HX_STACK_LINE(568)
								return true;
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_65->__Param(0);
{
							HX_STACK_LINE(572)
							if (((value >= (int)0))){
								HX_STACK_LINE(574)
								return true;
							}
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_65->__Param(0);
{
							HX_STACK_LINE(578)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
								HX_STACK_LINE(580)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(584)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)0: {
			HX_STACK_LINE(591)
			{
				::cocktail::core::css::CSSPropertyValue _switch_66 = (styleValue);
				switch((_switch_66)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_66->__Param(0);
{
							HX_STACK_LINE(594)
							{
								::cocktail::core::css::CSSKeywordValue _switch_67 = (value);
								switch((_switch_67)->GetIndex()){
									case 30: case 29: case 18: case 28: {
										HX_STACK_LINE(597)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(603)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)49: {
			HX_STACK_LINE(609)
			{
				::cocktail::core::css::CSSPropertyValue _switch_68 = (styleValue);
				switch((_switch_68)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_68->__Param(0);
{
							HX_STACK_LINE(612)
							{
								::cocktail::core::css::CSSKeywordValue _switch_69 = (value);
								switch((_switch_69)->GetIndex()){
									case 36: case 37: {
										HX_STACK_LINE(615)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(621)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(628)
			{
				::cocktail::core::css::CSSPropertyValue _switch_70 = (styleValue);
				switch((_switch_70)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_70->__Param(0);
{
							HX_STACK_LINE(631)
							{
								::cocktail::core::css::CSSKeywordValue _switch_71 = (value);
								switch((_switch_71)->GetIndex()){
									case 32: case 35: case 34: case 33: {
										HX_STACK_LINE(634)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(640)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)34: {
			HX_STACK_LINE(647)
			{
				::cocktail::core::css::CSSPropertyValue _switch_72 = (styleValue);
				switch((_switch_72)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_72->__Param(0);
{
							HX_STACK_LINE(650)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(652)
								return true;
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_72->__Param(0);
{
							HX_STACK_LINE(656)
							if (((value >= (int)0))){
								HX_STACK_LINE(658)
								return true;
							}
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_72->__Param(0);
{
							HX_STACK_LINE(662)
							{
								::cocktail::core::css::CSSKeywordValue _switch_73 = (value);
								switch((_switch_73)->GetIndex()){
									case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: {
										HX_STACK_LINE(665)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(671)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)8: case (int)6: case (int)9: case (int)7: {
			HX_STACK_LINE(679)
			return this->isValidMarginProperty(styleValue);
		}
		;break;
		case (int)13: case (int)14: case (int)11: case (int)12: {
			HX_STACK_LINE(682)
			return this->isValidPaddingProperty(styleValue);
		}
		;break;
		case (int)20: case (int)18: {
			HX_STACK_LINE(685)
			{
				::cocktail::core::css::CSSPropertyValue _switch_74 = (styleValue);
				switch((_switch_74)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_74->__Param(0);
{
							HX_STACK_LINE(688)
							{
								::cocktail::core::css::CSSKeywordValue _switch_75 = (value);
								switch((_switch_75)->GetIndex()){
									case 18: {
										HX_STACK_LINE(691)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_74->__Param(0);
{
							HX_STACK_LINE(697)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(699)
								return true;
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_74->__Param(0);
{
							HX_STACK_LINE(703)
							if (((value >= (int)0))){
								HX_STACK_LINE(705)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(709)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)53: {
			HX_STACK_LINE(717)
			{
				::cocktail::core::css::CSSPropertyValue _switch_76 = (styleValue);
				switch((_switch_76)->GetIndex()){
					case 1: {
						Float value = _switch_76->__Param(0);
{
							HX_STACK_LINE(720)
							return true;
						}
					}
					;break;
					case 0: {
						int value = _switch_76->__Param(0);
{
							HX_STACK_LINE(723)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(726)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)19: case (int)17: {
			HX_STACK_LINE(732)
			{
				::cocktail::core::css::CSSPropertyValue _switch_77 = (styleValue);
				switch((_switch_77)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_77->__Param(0);
{
							HX_STACK_LINE(735)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(737)
								return true;
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_77->__Param(0);
{
							HX_STACK_LINE(741)
							if (((value >= (int)0))){
								HX_STACK_LINE(743)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(747)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)22: case (int)23: case (int)21: case (int)24: {
			HX_STACK_LINE(753)
			{
				::cocktail::core::css::CSSPropertyValue _switch_78 = (styleValue);
				switch((_switch_78)->GetIndex()){
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_78->__Param(0);
{
							HX_STACK_LINE(756)
							return true;
						}
					}
					;break;
					case 2: {
						Float value = _switch_78->__Param(0);
{
							HX_STACK_LINE(759)
							return true;
						}
					}
					;break;
					case 0: {
						int value = _switch_78->__Param(0);
{
							HX_STACK_LINE(762)
							if (((value == (int)0))){
								HX_STACK_LINE(764)
								return true;
							}
						}
					}
					;break;
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_78->__Param(0);
{
							HX_STACK_LINE(768)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
								HX_STACK_LINE(770)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(774)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)36: {
			HX_STACK_LINE(780)
			{
				::cocktail::core::css::CSSPropertyValue _switch_79 = (styleValue);
				switch((_switch_79)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_79->__Param(0);
{
							HX_STACK_LINE(783)
							{
								::cocktail::core::css::CSSKeywordValue _switch_80 = (value);
								switch((_switch_80)->GetIndex()){
									case 4: case 5: case 0: {
										HX_STACK_LINE(786)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(792)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)61: {
			HX_STACK_LINE(800)
			{
				::cocktail::core::css::CSSPropertyValue _switch_81 = (styleValue);
				switch((_switch_81)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_81->__Param(0);
{
							HX_STACK_LINE(803)
							{
								::cocktail::core::css::CSSKeywordValue _switch_82 = (value);
								switch((_switch_82)->GetIndex()){
									case 18: {
										HX_STACK_LINE(806)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(812)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)51: case (int)52: {
			HX_STACK_LINE(819)
			{
				::cocktail::core::css::CSSPropertyValue _switch_83 = (styleValue);
				switch((_switch_83)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_83->__Param(0);
{
							HX_STACK_LINE(822)
							{
								::cocktail::core::css::CSSKeywordValue _switch_84 = (value);
								switch((_switch_84)->GetIndex()){
									case 36: case 38: case 37: case 27: {
										HX_STACK_LINE(825)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(831)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)37: {
			HX_STACK_LINE(837)
			{
				::cocktail::core::css::CSSPropertyValue _switch_85 = (styleValue);
				switch((_switch_85)->GetIndex()){
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > values = _switch_85->__Param(0);
{
							HX_STACK_LINE(842)
							int length = values->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(843)
							{
								HX_STACK_LINE(843)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(843)
								while(((_g < length))){
									HX_STACK_LINE(843)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(845)
									{
										::cocktail::core::css::CSSPropertyValue _switch_86 = (values->__get(i));
										switch((_switch_86)->GetIndex()){
											case 3: {
												::String value = _switch_86->__Param(0);
{
												}
											}
											;break;
											case 6: {
												::String value = _switch_86->__Param(0);
{
												}
											}
											;break;
											default: {
												HX_STACK_LINE(851)
												return false;
											}
										}
									}
								}
							}
							HX_STACK_LINE(856)
							return true;
						}
					}
					;break;
					case 3: {
						::String value = _switch_85->__Param(0);
{
							HX_STACK_LINE(858)
							return true;
						}
					}
					;break;
					case 6: {
						::String value = _switch_85->__Param(0);
{
							HX_STACK_LINE(861)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(864)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)2: case (int)3: {
			HX_STACK_LINE(870)
			{
				::cocktail::core::css::CSSPropertyValue _switch_87 = (styleValue);
				switch((_switch_87)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_87->__Param(0);
{
							HX_STACK_LINE(873)
							{
								::cocktail::core::css::CSSKeywordValue _switch_88 = (value);
								switch((_switch_88)->GetIndex()){
									case 11: case 12: case 31: case 18: {
										HX_STACK_LINE(876)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(882)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)45: {
			HX_STACK_LINE(888)
			{
				::cocktail::core::css::CSSPropertyValue _switch_89 = (styleValue);
				switch((_switch_89)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_89->__Param(0);
{
							HX_STACK_LINE(891)
							{
								::cocktail::core::css::CSSKeywordValue _switch_90 = (value);
								switch((_switch_90)->GetIndex()){
									case 0: case 8: case 10: case 7: case 9: {
										HX_STACK_LINE(894)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(900)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)42: {
			HX_STACK_LINE(906)
			{
				::cocktail::core::css::CSSPropertyValue _switch_91 = (styleValue);
				switch((_switch_91)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_91->__Param(0);
{
							HX_STACK_LINE(909)
							{
								::cocktail::core::css::CSSKeywordValue _switch_92 = (value);
								switch((_switch_92)->GetIndex()){
									case 18: case 16: case 17: case 15: {
										HX_STACK_LINE(912)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(918)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)35: {
			HX_STACK_LINE(924)
			{
				::cocktail::core::css::CSSPropertyValue _switch_93 = (styleValue);
				switch((_switch_93)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_93->__Param(0);
{
							HX_STACK_LINE(927)
							{
								::cocktail::core::css::CSSKeywordValue _switch_94 = (value);
								switch((_switch_94)->GetIndex()){
									case 0: case 1: case 2: case 3: {
										HX_STACK_LINE(930)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_93->__Param(0);
{
							HX_STACK_LINE(936)
							switch( (int)(value)){
								case (int)100: case (int)200: case (int)300: case (int)400: case (int)500: case (int)600: case (int)700: case (int)800: case (int)900: {
									HX_STACK_LINE(939)
									return true;
								}
								;break;
								default: {
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(945)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)38: {
			HX_STACK_LINE(952)
			{
				::cocktail::core::css::CSSPropertyValue _switch_95 = (styleValue);
				switch((_switch_95)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_95->__Param(0);
{
							HX_STACK_LINE(955)
							{
								::cocktail::core::css::CSSKeywordValue _switch_96 = (value);
								switch((_switch_96)->GetIndex()){
									case 0: case 6: {
										HX_STACK_LINE(958)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(964)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)46: {
			HX_STACK_LINE(970)
			{
				::cocktail::core::css::CSSPropertyValue _switch_97 = (styleValue);
				switch((_switch_97)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_97->__Param(0);
{
							HX_STACK_LINE(973)
							{
								::cocktail::core::css::CSSKeywordValue _switch_98 = (value);
								switch((_switch_98)->GetIndex()){
									case 11: case 12: case 13: case 14: {
										HX_STACK_LINE(976)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(982)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)48: {
			HX_STACK_LINE(989)
			{
				::cocktail::core::css::CSSPropertyValue _switch_99 = (styleValue);
				switch((_switch_99)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_99->__Param(0);
{
							HX_STACK_LINE(992)
							{
								::cocktail::core::css::CSSKeywordValue _switch_100 = (value);
								switch((_switch_100)->GetIndex()){
									case 19: case 20: case 21: case 26: case 23: case 24: case 22: case 25: {
										HX_STACK_LINE(995)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_99->__Param(0);
{
							HX_STACK_LINE(1001)
							return true;
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_99->__Param(0);
{
							HX_STACK_LINE(1004)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1007)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)54: {
			HX_STACK_LINE(1013)
			{
				::cocktail::core::css::CSSPropertyValue _switch_101 = (styleValue);
				switch((_switch_101)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_101->__Param(0);
{
							HX_STACK_LINE(1016)
							{
								::cocktail::core::css::CSSKeywordValue _switch_102 = (value);
								switch((_switch_102)->GetIndex()){
									case 27: case 44: case 45: case 46: case 47: {
										HX_STACK_LINE(1019)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 5: {
						::String value = _switch_101->__Param(0);
{
							HX_STACK_LINE(1025)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1028)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(1034)
			{
				::cocktail::core::css::CSSPropertyValue _switch_103 = (styleValue);
				switch((_switch_103)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_103->__Param(0);
{
							HX_STACK_LINE(1037)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()))){
								HX_STACK_LINE(1039)
								return true;
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_103->__Param(0);
{
							HX_STACK_LINE(1043)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1046)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)41: {
			HX_STACK_LINE(1052)
			{
				::cocktail::core::css::CSSPropertyValue _switch_104 = (styleValue);
				switch((_switch_104)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_104->__Param(0);
{
							HX_STACK_LINE(1055)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()))){
								HX_STACK_LINE(1057)
								return true;
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_104->__Param(0);
{
							HX_STACK_LINE(1061)
							if (((this->isPositiveLength(value) == true))){
								HX_STACK_LINE(1063)
								return true;
							}
						}
					}
					;break;
					case 1: {
						Float value = _switch_104->__Param(0);
{
							HX_STACK_LINE(1067)
							if (((value >= (int)0))){
								HX_STACK_LINE(1069)
								return true;
							}
						}
					}
					;break;
					case 0: {
						int value = _switch_104->__Param(0);
{
							HX_STACK_LINE(1073)
							if (((value >= (int)0))){
								HX_STACK_LINE(1075)
								return true;
							}
						}
					}
					;break;
					case 2: {
						Float value = _switch_104->__Param(0);
{
							HX_STACK_LINE(1079)
							if (((value >= (int)0))){
								HX_STACK_LINE(1081)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1085)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)47: {
			HX_STACK_LINE(1091)
			{
				::cocktail::core::css::CSSPropertyValue _switch_105 = (styleValue);
				switch((_switch_105)->GetIndex()){
					case 0: {
						int value = _switch_105->__Param(0);
{
							HX_STACK_LINE(1094)
							if (((value == (int)0))){
								HX_STACK_LINE(1096)
								return true;
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_105->__Param(0);
{
							HX_STACK_LINE(1100)
							return true;
						}
					}
					;break;
					case 2: {
						Float value = _switch_105->__Param(0);
{
							HX_STACK_LINE(1103)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1106)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)43: case (int)44: {
			HX_STACK_LINE(1112)
			{
				::cocktail::core::css::CSSPropertyValue _switch_106 = (styleValue);
				switch((_switch_106)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_106->__Param(0);
{
							HX_STACK_LINE(1115)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()))){
								HX_STACK_LINE(1117)
								return true;
							}
						}
					}
					;break;
					case 7: {
						::cocktail::core::css::CSSLengthValue value = _switch_106->__Param(0);
{
							HX_STACK_LINE(1121)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1124)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)40: case (int)25: {
			HX_STACK_LINE(1130)
			{
				::cocktail::core::css::CSSPropertyValue _switch_107 = (styleValue);
				switch((_switch_107)->GetIndex()){
					case 12: {
						::cocktail::core::css::CSSColorValue value = _switch_107->__Param(0);
{
							HX_STACK_LINE(1133)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1136)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)26: {
			HX_STACK_LINE(1142)
			{
				::cocktail::core::css::CSSPropertyValue _switch_108 = (styleValue);
				switch((_switch_108)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_108->__Param(0);
{
							HX_STACK_LINE(1146)
							if (((value == ::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()))){
								HX_STACK_LINE(1148)
								return true;
							}
						}
					}
					;break;
					case 5: {
						::String value = _switch_108->__Param(0);
{
							HX_STACK_LINE(1152)
							return true;
						}
					}
					;break;
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_108->__Param(0);
{
							HX_STACK_LINE(1156)
							bool isImageList = true;		HX_STACK_VAR(isImageList,"isImageList");
							HX_STACK_LINE(1157)
							{
								HX_STACK_LINE(1157)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1157)
								while(((_g1 < _g))){
									HX_STACK_LINE(1157)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1159)
									{
										::cocktail::core::css::CSSPropertyValue _switch_109 = (value->__get(i));
										switch((_switch_109)->GetIndex()){
											case 5: {
												::String value1 = _switch_109->__Param(0);
{
												}
											}
											;break;
											case 4: {
												::cocktail::core::css::CSSKeywordValue value1 = _switch_109->__Param(0);
{
													HX_STACK_LINE(1163)
													if (((value1 != ::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()))){
														HX_STACK_LINE(1165)
														isImageList = false;
													}
												}
											}
											;break;
											default: {
												HX_STACK_LINE(1169)
												isImageList = false;
											}
										}
									}
								}
							}
							HX_STACK_LINE(1174)
							if (((isImageList == true))){
								HX_STACK_LINE(1175)
								return true;
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1179)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)32: {
			HX_STACK_LINE(1185)
			{
				::cocktail::core::css::CSSPropertyValue _switch_110 = (styleValue);
				switch((_switch_110)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_110->__Param(0);
{
							HX_STACK_LINE(1188)
							{
								::cocktail::core::css::CSSKeywordValue _switch_111 = (value);
								switch((_switch_111)->GetIndex()){
									case 38: case 35: {
										HX_STACK_LINE(1191)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1197)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)30: {
			HX_STACK_LINE(1203)
			{
				::cocktail::core::css::CSSPropertyValue _switch_112 = (styleValue);
				switch((_switch_112)->GetIndex()){
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_112->__Param(0);
{
							HX_STACK_LINE(1206)
							switch( (int)(value->length)){
								case (int)2: {
									HX_STACK_LINE(1211)
									bool isValidHorizontalPosition = this->isValidBackgroundPosition(value->__get((int)0));		HX_STACK_VAR(isValidHorizontalPosition,"isValidHorizontalPosition");
									HX_STACK_LINE(1213)
									if (((isValidHorizontalPosition == false))){
										HX_STACK_LINE(1214)
										return false;
									}
									HX_STACK_LINE(1218)
									return this->isValidBackgroundPosition(value->__get((int)1));
								}
								;break;
							}
						}
					}
					;break;
					default: {
						HX_STACK_LINE(1221)
						return this->isValidBackgroundPosition(styleValue);
					}
				}
			}
		}
		;break;
		case (int)27: {
			HX_STACK_LINE(1227)
			{
				::cocktail::core::css::CSSPropertyValue _switch_113 = (styleValue);
				switch((_switch_113)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_113->__Param(0);
{
							HX_STACK_LINE(1230)
							{
								::cocktail::core::css::CSSKeywordValue _switch_114 = (value);
								switch((_switch_114)->GetIndex()){
									case 67: case 68: case 69: case 72: case 71: case 70: {
										HX_STACK_LINE(1233)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_113->__Param(0);
{
							HX_STACK_LINE(1239)
							if (((value->length == (int)2))){
								HX_STACK_LINE(1242)
								bool isFirstValueValid = false;		HX_STACK_VAR(isFirstValueValid,"isFirstValueValid");
								HX_STACK_LINE(1243)
								{
									::cocktail::core::css::CSSPropertyValue _switch_115 = (value->__get((int)0));
									switch((_switch_115)->GetIndex()){
										case 4: {
											::cocktail::core::css::CSSKeywordValue value1 = _switch_115->__Param(0);
{
												HX_STACK_LINE(1245)
												{
													::cocktail::core::css::CSSKeywordValue _switch_116 = (value1);
													switch((_switch_116)->GetIndex()){
														case 67: case 70: case 71: case 72: {
															HX_STACK_LINE(1248)
															isFirstValueValid = true;
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
								HX_STACK_LINE(1257)
								bool isSecondValueValid = false;		HX_STACK_VAR(isSecondValueValid,"isSecondValueValid");
								HX_STACK_LINE(1258)
								{
									::cocktail::core::css::CSSPropertyValue _switch_117 = (value->__get((int)1));
									switch((_switch_117)->GetIndex()){
										case 4: {
											::cocktail::core::css::CSSKeywordValue value1 = _switch_117->__Param(0);
{
												HX_STACK_LINE(1260)
												{
													::cocktail::core::css::CSSKeywordValue _switch_118 = (value1);
													switch((_switch_118)->GetIndex()){
														case 67: case 70: case 71: case 72: {
															HX_STACK_LINE(1263)
															isSecondValueValid = true;
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
								HX_STACK_LINE(1272)
								if (((bool((isFirstValueValid == true)) && bool((isSecondValueValid == true))))){
									HX_STACK_LINE(1273)
									return true;
								}
							}
						}
					}
					;break;
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_113->__Param(0);
{
							HX_STACK_LINE(1279)
							{
								HX_STACK_LINE(1279)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1279)
								while(((_g1 < _g))){
									HX_STACK_LINE(1279)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1281)
									if (((this->isValidProperty((int)27,value->__get(i)) == false))){
										HX_STACK_LINE(1282)
										return false;
									}
								}
							}
							HX_STACK_LINE(1286)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1288)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)29: {
			HX_STACK_LINE(1294)
			{
				::cocktail::core::css::CSSPropertyValue _switch_119 = (styleValue);
				switch((_switch_119)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_119->__Param(0);
{
							HX_STACK_LINE(1297)
							{
								::cocktail::core::css::CSSKeywordValue _switch_120 = (value);
								switch((_switch_120)->GetIndex()){
									case 43: case 42: case 27: {
										HX_STACK_LINE(1300)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_119->__Param(0);
{
							HX_STACK_LINE(1306)
							if (((value->length == (int)2))){
								HX_STACK_LINE(1309)
								bool isFirstValueValid = this->isValidBackgroundSize(value->__get((int)0));		HX_STACK_VAR(isFirstValueValid,"isFirstValueValid");
								HX_STACK_LINE(1311)
								if (((isFirstValueValid == false))){
									HX_STACK_LINE(1312)
									return false;
								}
								HX_STACK_LINE(1316)
								return this->isValidBackgroundSize(value->__get((int)1));
							}
						}
					}
					;break;
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_119->__Param(0);
{
							HX_STACK_LINE(1320)
							{
								HX_STACK_LINE(1320)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1320)
								while(((_g1 < _g))){
									HX_STACK_LINE(1320)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1322)
									if (((this->isValidProperty((int)29,value->__get(i)) == false))){
										HX_STACK_LINE(1323)
										return false;
									}
								}
							}
							HX_STACK_LINE(1327)
							return true;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(1329)
						return this->isValidBackgroundSize(styleValue);
					}
				}
			}
		}
		;break;
		case (int)31: case (int)28: {
			HX_STACK_LINE(1333)
			{
				::cocktail::core::css::CSSPropertyValue _switch_121 = (styleValue);
				switch((_switch_121)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_121->__Param(0);
{
							HX_STACK_LINE(1336)
							{
								::cocktail::core::css::CSSKeywordValue _switch_122 = (value);
								switch((_switch_122)->GetIndex()){
									case 39: case 40: case 41: {
										HX_STACK_LINE(1339)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_121->__Param(0);
{
							HX_STACK_LINE(1346)
							{
								HX_STACK_LINE(1346)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1346)
								while(((_g1 < _g))){
									HX_STACK_LINE(1346)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1348)
									if (((this->isValidProperty(propertyIndex,value->__get(i)) == false))){
										HX_STACK_LINE(1349)
										return false;
									}
								}
							}
							HX_STACK_LINE(1353)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1355)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
		case (int)57: {
			HX_STACK_LINE(1361)
			{
				::cocktail::core::css::CSSPropertyValue _switch_123 = (styleValue);
				switch((_switch_123)->GetIndex()){
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_123->__Param(0);
{
							HX_STACK_LINE(1365)
							int length = value->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(1366)
							{
								HX_STACK_LINE(1366)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1366)
								while(((_g < length))){
									HX_STACK_LINE(1366)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1368)
									bool isValid = this->isValidTransitionProperty(value->__get(i));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(1369)
									if (((isValid == false))){
										HX_STACK_LINE(1370)
										return false;
									}
								}
							}
							HX_STACK_LINE(1374)
							return true;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(1376)
						return this->isValidTransitionProperty(styleValue);
					}
				}
			}
		}
		;break;
		case (int)55: case (int)56: {
			HX_STACK_LINE(1380)
			{
				::cocktail::core::css::CSSPropertyValue _switch_124 = (styleValue);
				switch((_switch_124)->GetIndex()){
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_124->__Param(0);
{
							HX_STACK_LINE(1384)
							int length = value->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(1385)
							{
								HX_STACK_LINE(1385)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1385)
								while(((_g < length))){
									HX_STACK_LINE(1385)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1387)
									bool isValid = this->isValidTransitionDelayOrDuration(value->__get(i));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(1388)
									if (((isValid == false))){
										HX_STACK_LINE(1389)
										return false;
									}
								}
							}
							HX_STACK_LINE(1393)
							return true;
						}
					}
					;break;
					default: {
						HX_STACK_LINE(1395)
						return this->isValidTransitionDelayOrDuration(styleValue);
					}
				}
			}
		}
		;break;
		case (int)58: {
			HX_STACK_LINE(1399)
			{
				::cocktail::core::css::CSSPropertyValue _switch_125 = (styleValue);
				switch((_switch_125)->GetIndex()){
					case 15: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_125->__Param(0);
{
							HX_STACK_LINE(1403)
							int length = value->length;		HX_STACK_VAR(length,"length");
							HX_STACK_LINE(1404)
							{
								HX_STACK_LINE(1404)
								int _g = (int)0;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1404)
								while(((_g < length))){
									HX_STACK_LINE(1404)
									int i = (_g)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1406)
									bool isValid = this->isValidTransitionTimingFunction(value->__get(i));		HX_STACK_VAR(isValid,"isValid");
									HX_STACK_LINE(1407)
									if (((isValid == false))){
										HX_STACK_LINE(1408)
										return false;
									}
								}
							}
						}
					}
					;break;
					default: {
						HX_STACK_LINE(1413)
						return this->isValidTransitionTimingFunction(styleValue);
					}
				}
			}
		}
		;break;
		case (int)62: case (int)63: case (int)64: case (int)65: case (int)82: {
			HX_STACK_LINE(1417)
			{
				::cocktail::core::css::CSSPropertyValue _switch_126 = (styleValue);
				switch((_switch_126)->GetIndex()){
					case 16: case 17: {
						HX_STACK_LINE(1422)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1425)
						return this->isValidBorderWidthValue(styleValue);
					}
				}
			}
		}
		;break;
		case (int)67: case (int)68: case (int)69: case (int)70: {
			HX_STACK_LINE(1429)
			{
				::cocktail::core::css::CSSPropertyValue _switch_127 = (styleValue);
				switch((_switch_127)->GetIndex()){
					case 16: case 17: {
						HX_STACK_LINE(1433)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1436)
						return this->isValidBorderColorValue(styleValue);
					}
				}
			}
		}
		;break;
		case (int)72: case (int)73: case (int)74: case (int)75: {
			HX_STACK_LINE(1440)
			{
				::cocktail::core::css::CSSPropertyValue _switch_128 = (styleValue);
				switch((_switch_128)->GetIndex()){
					case 16: case 17: {
						HX_STACK_LINE(1444)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1447)
						return this->isValidBorderStyleValue(styleValue);
					}
				}
			}
		}
		;break;
		case (int)83: {
			HX_STACK_LINE(1451)
			{
				::cocktail::core::css::CSSPropertyValue _switch_129 = (styleValue);
				switch((_switch_129)->GetIndex()){
					case 16: case 17: {
						HX_STACK_LINE(1454)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1457)
						return this->isValidOutlineStyleValue(styleValue);
					}
				}
			}
		}
		;break;
		case (int)84: {
			HX_STACK_LINE(1461)
			{
				::cocktail::core::css::CSSPropertyValue _switch_130 = (styleValue);
				switch((_switch_130)->GetIndex()){
					case 16: case 17: {
						HX_STACK_LINE(1464)
						return true;
					}
					;break;
					default: {
						HX_STACK_LINE(1467)
						return this->isValidOutlineColorValue(styleValue);
					}
				}
			}
		}
		;break;
		case (int)86: {
			HX_STACK_LINE(1472)
			{
				::cocktail::core::css::CSSPropertyValue _switch_131 = (styleValue);
				switch((_switch_131)->GetIndex()){
					case 4: {
						::cocktail::core::css::CSSKeywordValue value = _switch_131->__Param(0);
{
							HX_STACK_LINE(1475)
							{
								::cocktail::core::css::CSSKeywordValue _switch_132 = (value);
								switch((_switch_132)->GetIndex()){
									case 18: case 84: case 85: case 86: case 87: {
										HX_STACK_LINE(1478)
										return true;
									}
									;break;
									default: {
									}
								}
							}
						}
					}
					;break;
					case 13: {
						Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_131->__Param(0);
{
							HX_STACK_LINE(1485)
							if (((bool((bool((value->length != (int)2)) && bool((value->length != (int)3)))) && bool((value->length != (int)4))))){
								HX_STACK_LINE(1486)
								return false;
							}
							HX_STACK_LINE(1490)
							bool foundUnderline = false;		HX_STACK_VAR(foundUnderline,"foundUnderline");
							HX_STACK_LINE(1491)
							bool foundOverline = false;		HX_STACK_VAR(foundOverline,"foundOverline");
							HX_STACK_LINE(1492)
							bool foundLineThrough = false;		HX_STACK_VAR(foundLineThrough,"foundLineThrough");
							HX_STACK_LINE(1493)
							bool foundBlink = false;		HX_STACK_VAR(foundBlink,"foundBlink");
							HX_STACK_LINE(1495)
							{
								HX_STACK_LINE(1495)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								int _g = value->length;		HX_STACK_VAR(_g,"_g");
								HX_STACK_LINE(1495)
								while(((_g1 < _g))){
									HX_STACK_LINE(1495)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(1497)
									{
										::cocktail::core::css::CSSPropertyValue _switch_133 = (value->__get(i));
										switch((_switch_133)->GetIndex()){
											case 4: {
												::cocktail::core::css::CSSKeywordValue value1 = _switch_133->__Param(0);
{
													HX_STACK_LINE(1499)
													{
														::cocktail::core::css::CSSKeywordValue _switch_134 = (value1);
														switch((_switch_134)->GetIndex()){
															case 84: {
																HX_STACK_LINE(1503)
																if (((foundUnderline == true))){
																	HX_STACK_LINE(1504)
																	return false;
																}
																HX_STACK_LINE(1509)
																foundUnderline = true;
															}
															;break;
															case 85: {
																HX_STACK_LINE(1512)
																if (((foundOverline == true))){
																	HX_STACK_LINE(1513)
																	return false;
																}
																HX_STACK_LINE(1516)
																foundOverline = true;
															}
															;break;
															case 86: {
																HX_STACK_LINE(1519)
																if (((foundLineThrough == true))){
																	HX_STACK_LINE(1520)
																	return false;
																}
																HX_STACK_LINE(1523)
																foundLineThrough = true;
															}
															;break;
															case 87: {
																HX_STACK_LINE(1526)
																if (((foundBlink == true))){
																	HX_STACK_LINE(1527)
																	return false;
																}
																HX_STACK_LINE(1530)
																foundBlink = true;
															}
															;break;
															default: {
																HX_STACK_LINE(1532)
																false;
															}
														}
													}
												}
											}
											;break;
											default: {
												HX_STACK_LINE(1536)
												false;
											}
										}
									}
								}
							}
							HX_STACK_LINE(1541)
							return true;
						}
					}
					;break;
					case 16: case 17: {
						HX_STACK_LINE(1543)
						return true;
					}
					;break;
					default: {
					}
				}
			}
		}
		;break;
	}
	HX_STACK_LINE(1550)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSStyleDeclaration_obj,isValidProperty,return )

Void CSSStyleDeclaration_obj::applyProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue styleValue,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::applyProperty","cocktail/core/css/CSSStyleDeclaration.hx",530);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(styleValue,"styleValue");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(530)
		if (((this->isShorthand(propertyIndex) == true))){
			HX_STACK_LINE(533)
			if (((this->isValidShorthand(propertyIndex,styleValue) == true))){
				HX_STACK_LINE(537)
				this->setShorthand(propertyIndex,styleValue,important);
			}
		}
		else{
			HX_STACK_LINE(542)
			if (((this->isValidProperty(propertyIndex,styleValue) == true))){
				HX_STACK_LINE(543)
				this->setTypedProperty(propertyIndex,styleValue,important);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,applyProperty,(void))

Void CSSStyleDeclaration_obj::setTypedPropertyInitial( int propertyIndex,::cocktail::core::css::CSSPropertyValue typedValue,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTypedPropertyInitial","cocktail/core/css/CSSStyleDeclaration.hx",497);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(typedValue,"typedValue");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(498)
		::cocktail::core::css::TypedPropertyVO newProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(newProperty,"newProperty");
		HX_STACK_LINE(499)
		newProperty->important = important;
		HX_STACK_LINE(500)
		newProperty->typedValue = typedValue;
		HX_STACK_LINE(501)
		newProperty->index = propertyIndex;
		HX_STACK_LINE(504)
		if (((this->_indexedProperties == null()))){
			HX_STACK_LINE(506)
			this->resetIndexedProperties();
			HX_STACK_LINE(507)
			this->resetPropertiesPositions();
		}
		HX_STACK_LINE(510)
		this->_propertiesPositions[this->length] = propertyIndex;
		HX_STACK_LINE(511)
		(this->length)++;
		HX_STACK_LINE(513)
		this->_indexedProperties[propertyIndex] = newProperty;
		HX_STACK_LINE(515)
		if (((this->_onStyleChange_dyn() != null()))){
			HX_STACK_LINE(516)
			this->_onStyleChange(propertyIndex);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,setTypedPropertyInitial,(void))

Void CSSStyleDeclaration_obj::setTypedProperty( int propertyIndex,::cocktail::core::css::CSSPropertyValue typedValue,bool important){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setTypedProperty","cocktail/core/css/CSSStyleDeclaration.hx",448);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(typedValue,"typedValue");
		HX_STACK_ARG(important,"important");
		HX_STACK_LINE(450)
		if (((this->_indexedProperties == null()))){
			HX_STACK_LINE(452)
			this->resetIndexedProperties();
			HX_STACK_LINE(453)
			this->resetPropertiesPositions();
		}
		struct _Function_1_1{
			inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration_obj *__this,int &propertyIndex){
				HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",457);
				{
					HX_STACK_LINE(457)
					if (((__this->_indexedProperties == null()))){
						HX_STACK_LINE(457)
						__this->resetIndexedProperties();
						HX_STACK_LINE(457)
						__this->resetPropertiesPositions();
					}
					HX_STACK_LINE(457)
					return __this->_indexedProperties->__get(propertyIndex);
				}
				return null();
			}
		};
		HX_STACK_LINE(457)
		::cocktail::core::css::TypedPropertyVO currentProperty = _Function_1_1::Block(this,propertyIndex);		HX_STACK_VAR(currentProperty,"currentProperty");
		HX_STACK_LINE(460)
		if (((currentProperty == null()))){
			HX_STACK_LINE(462)
			::cocktail::core::css::TypedPropertyVO newProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(newProperty,"newProperty");
			HX_STACK_LINE(463)
			newProperty->important = important;
			HX_STACK_LINE(464)
			newProperty->typedValue = typedValue;
			HX_STACK_LINE(465)
			newProperty->index = propertyIndex;
			HX_STACK_LINE(469)
			this->_propertiesPositions[this->length] = propertyIndex;
			HX_STACK_LINE(470)
			(this->length)++;
			HX_STACK_LINE(472)
			this->_indexedProperties[propertyIndex] = newProperty;
			HX_STACK_LINE(474)
			if (((this->_onStyleChange_dyn() != null()))){
				HX_STACK_LINE(475)
				this->_onStyleChange(propertyIndex);
			}
		}
		else{
			HX_STACK_LINE(480)
			if (((bool((currentProperty->typedValue != typedValue)) || bool((currentProperty->important != important))))){
				HX_STACK_LINE(482)
				currentProperty->typedValue = typedValue;
				HX_STACK_LINE(483)
				currentProperty->important = important;
				HX_STACK_LINE(484)
				if (((this->_onStyleChange_dyn() != null()))){
					HX_STACK_LINE(485)
					this->_onStyleChange(propertyIndex);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,setTypedProperty,(void))

::cocktail::core::css::TypedPropertyVO CSSStyleDeclaration_obj::getTypedProperty( int propertyIndex){
	HX_STACK_PUSH("CSSStyleDeclaration::getTypedProperty","cocktail/core/css/CSSStyleDeclaration.hx",432);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_LINE(434)
	if (((this->_indexedProperties == null()))){
		HX_STACK_LINE(436)
		this->resetIndexedProperties();
		HX_STACK_LINE(437)
		this->resetPropertiesPositions();
	}
	HX_STACK_LINE(440)
	return this->_indexedProperties->__get(propertyIndex);
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,getTypedProperty,return )

::String CSSStyleDeclaration_obj::getPropertyPriority( int propertyIndex){
	HX_STACK_PUSH("CSSStyleDeclaration::getPropertyPriority","cocktail/core/css/CSSStyleDeclaration.hx",410);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration_obj *__this,int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",411);
			{
				HX_STACK_LINE(411)
				if (((__this->_indexedProperties == null()))){
					HX_STACK_LINE(411)
					__this->resetIndexedProperties();
					HX_STACK_LINE(411)
					__this->resetPropertiesPositions();
				}
				HX_STACK_LINE(411)
				return __this->_indexedProperties->__get(propertyIndex);
			}
			return null();
		}
	};
	HX_STACK_LINE(411)
	::cocktail::core::css::TypedPropertyVO typedProperty = _Function_1_1::Block(this,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
	HX_STACK_LINE(412)
	if (((typedProperty != null()))){
		HX_STACK_LINE(413)
		if (((typedProperty->important == true))){
			HX_STACK_LINE(415)
			return HX_CSTRING("important");
		}
		else{
			HX_STACK_LINE(419)
			return HX_CSTRING("");
		}
	}
	HX_STACK_LINE(424)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,getPropertyPriority,return )

int CSSStyleDeclaration_obj::removeProperty( int index){
	HX_STACK_PUSH("CSSStyleDeclaration::removeProperty","cocktail/core/css/CSSStyleDeclaration.hx",379);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration_obj *__this,int &index){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",380);
			{
				HX_STACK_LINE(380)
				if (((__this->_indexedProperties == null()))){
					HX_STACK_LINE(380)
					__this->resetIndexedProperties();
					HX_STACK_LINE(380)
					__this->resetPropertiesPositions();
				}
				HX_STACK_LINE(380)
				return __this->_indexedProperties->__get(index);
			}
			return null();
		}
	};
	HX_STACK_LINE(380)
	::cocktail::core::css::TypedPropertyVO typedProperty = _Function_1_1::Block(this,index);		HX_STACK_VAR(typedProperty,"typedProperty");
	HX_STACK_LINE(381)
	if (((typedProperty != null()))){
		HX_STACK_LINE(385)
		this->decrementPropertiesPositions(index);
		HX_STACK_LINE(386)
		this->_propertiesPositions[this->length] = (int)-1;
		HX_STACK_LINE(387)
		(this->length)--;
		HX_STACK_LINE(389)
		this->_indexedProperties[index] = null();
		HX_STACK_LINE(392)
		if (((this->_onStyleChange_dyn() != null()))){
			HX_STACK_LINE(393)
			this->_onStyleChange(index);
		}
		HX_STACK_LINE(397)
		return index;
	}
	HX_STACK_LINE(400)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,removeProperty,return )

Void CSSStyleDeclaration_obj::setProperty( int index,::String value,::String priority){
{
		HX_STACK_PUSH("CSSStyleDeclaration::setProperty","cocktail/core/css/CSSStyleDeclaration.hx",348);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_ARG(value,"value");
		HX_STACK_ARG(priority,"priority");
		HX_STACK_LINE(350)
		if (((this->_indexedProperties == null()))){
			HX_STACK_LINE(352)
			this->resetIndexedProperties();
			HX_STACK_LINE(353)
			this->resetPropertiesPositions();
		}
		HX_STACK_LINE(356)
		if (((value == null()))){
			HX_STACK_LINE(357)
			this->removeProperty(index);
		}
		else{
			HX_STACK_LINE(364)
			::cocktail::core::css::TypedPropertyVO typedProperty = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseStyleValue(::cocktail::core::css::CSSConstants_obj::getPropertyNameFromIndex(index),value,(int)0);		HX_STACK_VAR(typedProperty,"typedProperty");
			HX_STACK_LINE(366)
			if (((typedProperty != null()))){
				HX_STACK_LINE(367)
				this->applyProperty(typedProperty->index,typedProperty->typedValue,typedProperty->important);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSStyleDeclaration_obj,setProperty,(void))

::String CSSStyleDeclaration_obj::getPropertyValue( int propertyIndex){
	HX_STACK_PUSH("CSSStyleDeclaration::getPropertyValue","cocktail/core/css/CSSStyleDeclaration.hx",332);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	struct _Function_1_1{
		inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration_obj *__this,int &propertyIndex){
			HX_STACK_PUSH("*::closure","cocktail/core/css/CSSStyleDeclaration.hx",333);
			{
				HX_STACK_LINE(333)
				if (((__this->_indexedProperties == null()))){
					HX_STACK_LINE(333)
					__this->resetIndexedProperties();
					HX_STACK_LINE(333)
					__this->resetPropertiesPositions();
				}
				HX_STACK_LINE(333)
				return __this->_indexedProperties->__get(propertyIndex);
			}
			return null();
		}
	};
	HX_STACK_LINE(333)
	::cocktail::core::css::TypedPropertyVO typedProperty = _Function_1_1::Block(this,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
	HX_STACK_LINE(334)
	if (((typedProperty != null()))){
		HX_STACK_LINE(335)
		return ::cocktail::core::css::parsers::CSSStyleSerializer_obj::serialize(typedProperty->typedValue);
	}
	HX_STACK_LINE(338)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,getPropertyValue,return )

int CSSStyleDeclaration_obj::item( int index){
	HX_STACK_PUSH("CSSStyleDeclaration::item","cocktail/core/css/CSSStyleDeclaration.hx",316);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(318)
	if (((index > (this->length - (int)1)))){
		HX_STACK_LINE(319)
		return (int)-1;
	}
	HX_STACK_LINE(323)
	return this->_propertiesPositions->__get(index);
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,item,return )

Void CSSStyleDeclaration_obj::decrementPropertiesPositions( int removedPropertyIndex){
{
		HX_STACK_PUSH("CSSStyleDeclaration::decrementPropertiesPositions","cocktail/core/css/CSSStyleDeclaration.hx",290);
		HX_STACK_THIS(this);
		HX_STACK_ARG(removedPropertyIndex,"removedPropertyIndex");
		HX_STACK_LINE(293)
		bool foundProperty = false;		HX_STACK_VAR(foundProperty,"foundProperty");
		HX_STACK_LINE(294)
		{
			HX_STACK_LINE(294)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(294)
			while(((_g1 < _g))){
				HX_STACK_LINE(294)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(296)
				if (((foundProperty == true))){
					HX_STACK_LINE(297)
					this->_propertiesPositions[i] = this->_propertiesPositions->__get((i - (int)1));
				}
				HX_STACK_LINE(300)
				if (((this->_propertiesPositions->__get(i) == removedPropertyIndex))){
					HX_STACK_LINE(301)
					foundProperty = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleDeclaration_obj,decrementPropertiesPositions,(void))

Void CSSStyleDeclaration_obj::resetPropertiesPositions( ){
{
		HX_STACK_PUSH("CSSStyleDeclaration::resetPropertiesPositions","cocktail/core/css/CSSStyleDeclaration.hx",271);
		HX_STACK_THIS(this);
		HX_STACK_LINE(272)
		if (((this->_propertiesPositions == null()))){
			HX_STACK_LINE(273)
			this->_propertiesPositions = Array_obj< int >::__new();
		}
		HX_STACK_LINE(277)
		{
			HX_STACK_LINE(277)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(277)
			while(((_g < (int)87))){
				HX_STACK_LINE(277)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(279)
				this->_propertiesPositions[i] = (int)-1;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,resetPropertiesPositions,(void))

Void CSSStyleDeclaration_obj::resetIndexedProperties( ){
{
		HX_STACK_PUSH("CSSStyleDeclaration::resetIndexedProperties","cocktail/core/css/CSSStyleDeclaration.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_LINE(254)
		if (((this->_indexedProperties == null()))){
			HX_STACK_LINE(255)
			this->_indexedProperties = Array_obj< ::cocktail::core::css::TypedPropertyVO >::__new();
		}
		HX_STACK_LINE(259)
		{
			HX_STACK_LINE(259)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(259)
			while(((_g < (int)87))){
				HX_STACK_LINE(259)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(261)
				this->_indexedProperties[i] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,resetIndexedProperties,(void))

Void CSSStyleDeclaration_obj::reset( ){
{
		HX_STACK_PUSH("CSSStyleDeclaration::reset","cocktail/core/css/CSSStyleDeclaration.hx",238);
		HX_STACK_THIS(this);
		HX_STACK_LINE(239)
		this->_onStyleChange = null();
		HX_STACK_LINE(240)
		this->parentRule = null();
		HX_STACK_LINE(241)
		this->length = (int)0;
		HX_STACK_LINE(243)
		this->resetIndexedProperties();
		HX_STACK_LINE(244)
		this->resetPropertiesPositions();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleDeclaration_obj,reset,(void))


CSSStyleDeclaration_obj::CSSStyleDeclaration_obj()
{
}

void CSSStyleDeclaration_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSStyleDeclaration);
	HX_MARK_MEMBER_NAME(_onStyleChange,"_onStyleChange");
	HX_MARK_MEMBER_NAME(_propertiesPositions,"_propertiesPositions");
	HX_MARK_MEMBER_NAME(_indexedProperties,"_indexedProperties");
	HX_MARK_MEMBER_NAME(parentRule,"parentRule");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(cssText,"cssText");
	HX_MARK_MEMBER_NAME(outlineStyle,"outlineStyle");
	HX_MARK_MEMBER_NAME(outlineColor,"outlineColor");
	HX_MARK_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_MARK_MEMBER_NAME(outline,"outline");
	HX_MARK_MEMBER_NAME(cursor,"cursor");
	HX_MARK_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(transitionDelay,"transitionDelay");
	HX_MARK_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_MARK_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_MARK_MEMBER_NAME(transitionProperty,"transitionProperty");
	HX_MARK_MEMBER_NAME(overflowY,"overflowY");
	HX_MARK_MEMBER_NAME(overflowX,"overflowX");
	HX_MARK_MEMBER_NAME(overflow,"overflow");
	HX_MARK_MEMBER_NAME(visibility,"visibility");
	HX_MARK_MEMBER_NAME(opacity,"opacity");
	HX_MARK_MEMBER_NAME(textDecoration,"textDecoration");
	HX_MARK_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_MARK_MEMBER_NAME(textIndent,"textIndent");
	HX_MARK_MEMBER_NAME(textAlign,"textAlign");
	HX_MARK_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_MARK_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_MARK_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_MARK_MEMBER_NAME(textTransform,"textTransform");
	HX_MARK_MEMBER_NAME(lineHeight,"lineHeight");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(fontVariant,"fontVariant");
	HX_MARK_MEMBER_NAME(fontFamily,"fontFamily");
	HX_MARK_MEMBER_NAME(fontStyle,"fontStyle");
	HX_MARK_MEMBER_NAME(fontWeight,"fontWeight");
	HX_MARK_MEMBER_NAME(fontSize,"fontSize");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_MEMBER_NAME(border,"border");
	HX_MARK_MEMBER_NAME(borderLeft,"borderLeft");
	HX_MARK_MEMBER_NAME(borderBottom,"borderBottom");
	HX_MARK_MEMBER_NAME(borderRight,"borderRight");
	HX_MARK_MEMBER_NAME(borderTop,"borderTop");
	HX_MARK_MEMBER_NAME(borderStyle,"borderStyle");
	HX_MARK_MEMBER_NAME(borderLeftStyle,"borderLeftStyle");
	HX_MARK_MEMBER_NAME(borderBottomStyle,"borderBottomStyle");
	HX_MARK_MEMBER_NAME(borderRightStyle,"borderRightStyle");
	HX_MARK_MEMBER_NAME(borderTopStyle,"borderTopStyle");
	HX_MARK_MEMBER_NAME(borderColor,"borderColor");
	HX_MARK_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_MARK_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_MARK_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_MARK_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_MARK_MEMBER_NAME(borderWidth,"borderWidth");
	HX_MARK_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_MARK_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_MARK_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_MARK_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_MARK_MEMBER_NAME(backgroundAttachment,"backgroundAttachment");
	HX_MARK_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_MARK_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_MARK_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_MARK_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_MARK_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_MARK_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_MARK_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(right,"right");
	HX_MARK_MEMBER_NAME(bottom,"bottom");
	HX_MARK_MEMBER_NAME(left,"left");
	HX_MARK_MEMBER_NAME(top,"top");
	HX_MARK_MEMBER_NAME(maxWidth,"maxWidth");
	HX_MARK_MEMBER_NAME(minWidth,"minWidth");
	HX_MARK_MEMBER_NAME(maxHeight,"maxHeight");
	HX_MARK_MEMBER_NAME(minHeight,"minHeight");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_MARK_MEMBER_NAME(paddingTop,"paddingTop");
	HX_MARK_MEMBER_NAME(paddingRight,"paddingRight");
	HX_MARK_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_MARK_MEMBER_NAME(padding,"padding");
	HX_MARK_MEMBER_NAME(marginBottom,"marginBottom");
	HX_MARK_MEMBER_NAME(marginTop,"marginTop");
	HX_MARK_MEMBER_NAME(marginRight,"marginRight");
	HX_MARK_MEMBER_NAME(marginLeft,"marginLeft");
	HX_MARK_MEMBER_NAME(margin,"margin");
	HX_MARK_MEMBER_NAME(zIndex,"zIndex");
	HX_MARK_MEMBER_NAME(clear,"clear");
	HX_MARK_MEMBER_NAME(cssFloat,"cssFloat");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_END_CLASS();
}

void CSSStyleDeclaration_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_onStyleChange,"_onStyleChange");
	HX_VISIT_MEMBER_NAME(_propertiesPositions,"_propertiesPositions");
	HX_VISIT_MEMBER_NAME(_indexedProperties,"_indexedProperties");
	HX_VISIT_MEMBER_NAME(parentRule,"parentRule");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(cssText,"cssText");
	HX_VISIT_MEMBER_NAME(outlineStyle,"outlineStyle");
	HX_VISIT_MEMBER_NAME(outlineColor,"outlineColor");
	HX_VISIT_MEMBER_NAME(outlineWidth,"outlineWidth");
	HX_VISIT_MEMBER_NAME(outline,"outline");
	HX_VISIT_MEMBER_NAME(cursor,"cursor");
	HX_VISIT_MEMBER_NAME(transformOrigin,"transformOrigin");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(transitionDelay,"transitionDelay");
	HX_VISIT_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_VISIT_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_VISIT_MEMBER_NAME(transitionProperty,"transitionProperty");
	HX_VISIT_MEMBER_NAME(overflowY,"overflowY");
	HX_VISIT_MEMBER_NAME(overflowX,"overflowX");
	HX_VISIT_MEMBER_NAME(overflow,"overflow");
	HX_VISIT_MEMBER_NAME(visibility,"visibility");
	HX_VISIT_MEMBER_NAME(opacity,"opacity");
	HX_VISIT_MEMBER_NAME(textDecoration,"textDecoration");
	HX_VISIT_MEMBER_NAME(verticalAlign,"verticalAlign");
	HX_VISIT_MEMBER_NAME(textIndent,"textIndent");
	HX_VISIT_MEMBER_NAME(textAlign,"textAlign");
	HX_VISIT_MEMBER_NAME(whiteSpace,"whiteSpace");
	HX_VISIT_MEMBER_NAME(wordSpacing,"wordSpacing");
	HX_VISIT_MEMBER_NAME(letterSpacing,"letterSpacing");
	HX_VISIT_MEMBER_NAME(textTransform,"textTransform");
	HX_VISIT_MEMBER_NAME(lineHeight,"lineHeight");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(fontVariant,"fontVariant");
	HX_VISIT_MEMBER_NAME(fontFamily,"fontFamily");
	HX_VISIT_MEMBER_NAME(fontStyle,"fontStyle");
	HX_VISIT_MEMBER_NAME(fontWeight,"fontWeight");
	HX_VISIT_MEMBER_NAME(fontSize,"fontSize");
	HX_VISIT_MEMBER_NAME(font,"font");
	HX_VISIT_MEMBER_NAME(border,"border");
	HX_VISIT_MEMBER_NAME(borderLeft,"borderLeft");
	HX_VISIT_MEMBER_NAME(borderBottom,"borderBottom");
	HX_VISIT_MEMBER_NAME(borderRight,"borderRight");
	HX_VISIT_MEMBER_NAME(borderTop,"borderTop");
	HX_VISIT_MEMBER_NAME(borderStyle,"borderStyle");
	HX_VISIT_MEMBER_NAME(borderLeftStyle,"borderLeftStyle");
	HX_VISIT_MEMBER_NAME(borderBottomStyle,"borderBottomStyle");
	HX_VISIT_MEMBER_NAME(borderRightStyle,"borderRightStyle");
	HX_VISIT_MEMBER_NAME(borderTopStyle,"borderTopStyle");
	HX_VISIT_MEMBER_NAME(borderColor,"borderColor");
	HX_VISIT_MEMBER_NAME(borderLeftColor,"borderLeftColor");
	HX_VISIT_MEMBER_NAME(borderBottomColor,"borderBottomColor");
	HX_VISIT_MEMBER_NAME(borderRightColor,"borderRightColor");
	HX_VISIT_MEMBER_NAME(borderTopColor,"borderTopColor");
	HX_VISIT_MEMBER_NAME(borderWidth,"borderWidth");
	HX_VISIT_MEMBER_NAME(borderLeftWidth,"borderLeftWidth");
	HX_VISIT_MEMBER_NAME(borderBottomWidth,"borderBottomWidth");
	HX_VISIT_MEMBER_NAME(borderRightWidth,"borderRightWidth");
	HX_VISIT_MEMBER_NAME(borderTopWidth,"borderTopWidth");
	HX_VISIT_MEMBER_NAME(backgroundAttachment,"backgroundAttachment");
	HX_VISIT_MEMBER_NAME(backgroundClip,"backgroundClip");
	HX_VISIT_MEMBER_NAME(backgroundPosition,"backgroundPosition");
	HX_VISIT_MEMBER_NAME(backgroundSize,"backgroundSize");
	HX_VISIT_MEMBER_NAME(backgroundOrigin,"backgroundOrigin");
	HX_VISIT_MEMBER_NAME(backgroundRepeat,"backgroundRepeat");
	HX_VISIT_MEMBER_NAME(backgroundImage,"backgroundImage");
	HX_VISIT_MEMBER_NAME(backgroundColor,"backgroundColor");
	HX_VISIT_MEMBER_NAME(background,"background");
	HX_VISIT_MEMBER_NAME(right,"right");
	HX_VISIT_MEMBER_NAME(bottom,"bottom");
	HX_VISIT_MEMBER_NAME(left,"left");
	HX_VISIT_MEMBER_NAME(top,"top");
	HX_VISIT_MEMBER_NAME(maxWidth,"maxWidth");
	HX_VISIT_MEMBER_NAME(minWidth,"minWidth");
	HX_VISIT_MEMBER_NAME(maxHeight,"maxHeight");
	HX_VISIT_MEMBER_NAME(minHeight,"minHeight");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(paddingBottom,"paddingBottom");
	HX_VISIT_MEMBER_NAME(paddingTop,"paddingTop");
	HX_VISIT_MEMBER_NAME(paddingRight,"paddingRight");
	HX_VISIT_MEMBER_NAME(paddingLeft,"paddingLeft");
	HX_VISIT_MEMBER_NAME(padding,"padding");
	HX_VISIT_MEMBER_NAME(marginBottom,"marginBottom");
	HX_VISIT_MEMBER_NAME(marginTop,"marginTop");
	HX_VISIT_MEMBER_NAME(marginRight,"marginRight");
	HX_VISIT_MEMBER_NAME(marginLeft,"marginLeft");
	HX_VISIT_MEMBER_NAME(margin,"margin");
	HX_VISIT_MEMBER_NAME(zIndex,"zIndex");
	HX_VISIT_MEMBER_NAME(clear,"clear");
	HX_VISIT_MEMBER_NAME(cssFloat,"cssFloat");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(display,"display");
}

Dynamic CSSStyleDeclaration_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return inCallProp ? get_top() : top; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"item") ) { return item_dyn(); }
		if (HX_FIELD_EQ(inName,"font") ) { return inCallProp ? get_font() : font; }
		if (HX_FIELD_EQ(inName,"left") ) { return inCallProp ? get_left() : left; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"reset") ) { return reset_dyn(); }
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? get_right() : right; }
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		if (HX_FIELD_EQ(inName,"clear") ) { return inCallProp ? get_clear() : clear; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return inCallProp ? get_cursor() : cursor; }
		if (HX_FIELD_EQ(inName,"border") ) { return inCallProp ? get_border() : border; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return inCallProp ? get_bottom() : bottom; }
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"margin") ) { return inCallProp ? get_margin() : margin; }
		if (HX_FIELD_EQ(inName,"zIndex") ) { return inCallProp ? get_zIndex() : zIndex; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"cssText") ) { return inCallProp ? get_cssText() : cssText; }
		if (HX_FIELD_EQ(inName,"outline") ) { return inCallProp ? get_outline() : outline; }
		if (HX_FIELD_EQ(inName,"opacity") ) { return inCallProp ? get_opacity() : opacity; }
		if (HX_FIELD_EQ(inName,"padding") ) { return inCallProp ? get_padding() : padding; }
		if (HX_FIELD_EQ(inName,"display") ) { return inCallProp ? get_display() : display; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_font") ) { return get_font_dyn(); }
		if (HX_FIELD_EQ(inName,"set_font") ) { return set_font_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"overflow") ) { return inCallProp ? get_overflow() : overflow; }
		if (HX_FIELD_EQ(inName,"fontSize") ) { return inCallProp ? get_fontSize() : fontSize; }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { return inCallProp ? get_maxWidth() : maxWidth; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { return inCallProp ? get_minWidth() : minWidth; }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { return inCallProp ? get_CSSFloat() : cssFloat; }
		if (HX_FIELD_EQ(inName,"position") ) { return inCallProp ? get_position() : position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_color") ) { return set_color_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"set_clear") ) { return set_clear_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clear") ) { return get_clear_dyn(); }
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? get_transform() : transform; }
		if (HX_FIELD_EQ(inName,"overflowY") ) { return inCallProp ? get_overflowY() : overflowY; }
		if (HX_FIELD_EQ(inName,"overflowX") ) { return inCallProp ? get_overflowX() : overflowX; }
		if (HX_FIELD_EQ(inName,"textAlign") ) { return inCallProp ? get_textAlign() : textAlign; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { return inCallProp ? get_fontStyle() : fontStyle; }
		if (HX_FIELD_EQ(inName,"borderTop") ) { return inCallProp ? get_borderTop() : borderTop; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { return inCallProp ? get_maxHeight() : maxHeight; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { return inCallProp ? get_minHeight() : minHeight; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { return inCallProp ? get_marginTop() : marginTop; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_border") ) { return set_border_dyn(); }
		if (HX_FIELD_EQ(inName,"get_border") ) { return get_border_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cursor") ) { return get_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cursor") ) { return set_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_zIndex") ) { return set_zIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zIndex") ) { return get_zIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"set_margin") ) { return set_margin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_margin") ) { return get_margin_dyn(); }
		if (HX_FIELD_EQ(inName,"parentRule") ) { return parentRule; }
		if (HX_FIELD_EQ(inName,"visibility") ) { return inCallProp ? get_visibility() : visibility; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { return inCallProp ? get_textIndent() : textIndent; }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { return inCallProp ? get_whiteSpace() : whiteSpace; }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { return inCallProp ? get_lineHeight() : lineHeight; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { return inCallProp ? get_fontFamily() : fontFamily; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { return inCallProp ? get_fontWeight() : fontWeight; }
		if (HX_FIELD_EQ(inName,"borderLeft") ) { return inCallProp ? get_borderLeft() : borderLeft; }
		if (HX_FIELD_EQ(inName,"background") ) { return inCallProp ? get_background() : background; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { return inCallProp ? get_paddingTop() : paddingTop; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { return inCallProp ? get_marginLeft() : marginLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_outline") ) { return set_outline_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outline") ) { return get_outline_dyn(); }
		if (HX_FIELD_EQ(inName,"set_display") ) { return set_display_dyn(); }
		if (HX_FIELD_EQ(inName,"get_display") ) { return get_display_dyn(); }
		if (HX_FIELD_EQ(inName,"set_padding") ) { return set_padding_dyn(); }
		if (HX_FIELD_EQ(inName,"get_padding") ) { return get_padding_dyn(); }
		if (HX_FIELD_EQ(inName,"set_opacity") ) { return set_opacity_dyn(); }
		if (HX_FIELD_EQ(inName,"get_opacity") ) { return get_opacity_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cssText") ) { return set_cssText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cssText") ) { return get_cssText_dyn(); }
		if (HX_FIELD_EQ(inName,"isShorthand") ) { return isShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"setProperty") ) { return setProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { return inCallProp ? get_wordSpacing() : wordSpacing; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { return inCallProp ? get_fontVariant() : fontVariant; }
		if (HX_FIELD_EQ(inName,"borderRight") ) { return inCallProp ? get_borderRight() : borderRight; }
		if (HX_FIELD_EQ(inName,"borderStyle") ) { return inCallProp ? get_borderStyle() : borderStyle; }
		if (HX_FIELD_EQ(inName,"borderColor") ) { return inCallProp ? get_borderColor() : borderColor; }
		if (HX_FIELD_EQ(inName,"borderWidth") ) { return inCallProp ? get_borderWidth() : borderWidth; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { return inCallProp ? get_paddingLeft() : paddingLeft; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { return inCallProp ? get_marginRight() : marginRight; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_overflow") ) { return set_overflow_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflow") ) { return get_overflow_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontSize") ) { return set_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontSize") ) { return get_fontSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_CSSFloat") ) { return set_CSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"get_CSSFloat") ) { return get_CSSFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxWidth") ) { return set_maxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxWidth") ) { return get_maxWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_minWidth") ) { return set_minWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minWidth") ) { return get_minWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_position") ) { return set_position_dyn(); }
		if (HX_FIELD_EQ(inName,"get_position") ) { return get_position_dyn(); }
		if (HX_FIELD_EQ(inName,"setShorthand") ) { return setShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"outlineStyle") ) { return inCallProp ? get_outlineStyle() : outlineStyle; }
		if (HX_FIELD_EQ(inName,"outlineColor") ) { return inCallProp ? get_outlineColor() : outlineColor; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { return inCallProp ? get_outlineWidth() : outlineWidth; }
		if (HX_FIELD_EQ(inName,"borderBottom") ) { return inCallProp ? get_borderBottom() : borderBottom; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { return inCallProp ? get_paddingRight() : paddingRight; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { return inCallProp ? get_marginBottom() : marginBottom; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_borderTop") ) { return set_borderTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTop") ) { return get_borderTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transform") ) { return set_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_overflowY") ) { return set_overflowY_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowY") ) { return get_overflowY_dyn(); }
		if (HX_FIELD_EQ(inName,"set_overflowX") ) { return set_overflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"get_overflowX") ) { return get_overflowX_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textAlign") ) { return set_textAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textAlign") ) { return get_textAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontStyle") ) { return set_fontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontStyle") ) { return get_fontStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_maxHeight") ) { return set_maxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_maxHeight") ) { return get_maxHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_minHeight") ) { return set_minHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_minHeight") ) { return get_minHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginTop") ) { return set_marginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginTop") ) { return get_marginTop_dyn(); }
		if (HX_FIELD_EQ(inName,"applyProperty") ) { return applyProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { return inCallProp ? get_verticalAlign() : verticalAlign; }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { return inCallProp ? get_letterSpacing() : letterSpacing; }
		if (HX_FIELD_EQ(inName,"textTransform") ) { return inCallProp ? get_textTransform() : textTransform; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { return inCallProp ? get_paddingBottom() : paddingBottom; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"set_borderLeft") ) { return set_borderLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeft") ) { return get_borderLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_background") ) { return get_background_dyn(); }
		if (HX_FIELD_EQ(inName,"set_background") ) { return set_background_dyn(); }
		if (HX_FIELD_EQ(inName,"set_whiteSpace") ) { return set_whiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"get_whiteSpace") ) { return get_whiteSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textIndent") ) { return set_textIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textIndent") ) { return get_textIndent_dyn(); }
		if (HX_FIELD_EQ(inName,"set_lineHeight") ) { return set_lineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_lineHeight") ) { return get_lineHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontFamily") ) { return set_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontFamily") ) { return get_fontFamily_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontWeight") ) { return set_fontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontWeight") ) { return get_fontWeight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingTop") ) { return set_paddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingTop") ) { return get_paddingTop_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginLeft") ) { return set_marginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginLeft") ) { return get_marginLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_visibility") ) { return set_visibility_dyn(); }
		if (HX_FIELD_EQ(inName,"get_visibility") ) { return get_visibility_dyn(); }
		if (HX_FIELD_EQ(inName,"removeProperty") ) { return removeProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"_onStyleChange") ) { return _onStyleChange; }
		if (HX_FIELD_EQ(inName,"textDecoration") ) { return inCallProp ? get_textDecoration() : textDecoration; }
		if (HX_FIELD_EQ(inName,"borderTopStyle") ) { return inCallProp ? get_borderTopStyle() : borderTopStyle; }
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { return inCallProp ? get_borderTopColor() : borderTopColor; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { return inCallProp ? get_borderTopWidth() : borderTopWidth; }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { return inCallProp ? get_backgroundClip() : backgroundClip; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { return inCallProp ? get_backgroundSize() : backgroundSize; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_borderRight") ) { return set_borderRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRight") ) { return get_borderRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderStyle") ) { return set_borderStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderStyle") ) { return get_borderStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderColor") ) { return set_borderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderColor") ) { return get_borderColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderWidth") ) { return set_borderWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderWidth") ) { return get_borderWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_wordSpacing") ) { return set_wordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"get_wordSpacing") ) { return get_wordSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fontVariant") ) { return set_fontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"get_fontVariant") ) { return get_fontVariant_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingLeft") ) { return set_paddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingLeft") ) { return get_paddingLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginRight") ) { return set_marginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginRight") ) { return get_marginRight_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidProperty") ) { return isValidProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { return inCallProp ? get_transformOrigin() : transformOrigin; }
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { return inCallProp ? get_transitionDelay() : transitionDelay; }
		if (HX_FIELD_EQ(inName,"borderLeftStyle") ) { return inCallProp ? get_borderLeftStyle() : borderLeftStyle; }
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { return inCallProp ? get_borderLeftColor() : borderLeftColor; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { return inCallProp ? get_borderLeftWidth() : borderLeftWidth; }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { return inCallProp ? get_backgroundImage() : backgroundImage; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { return inCallProp ? get_backgroundColor() : backgroundColor; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_outlineStyle") ) { return set_outlineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outlineStyle") ) { return get_outlineStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_outlineColor") ) { return set_outlineColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outlineColor") ) { return get_outlineColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_outlineWidth") ) { return set_outlineWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_outlineWidth") ) { return get_outlineWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderBottom") ) { return set_borderBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottom") ) { return get_borderBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingRight") ) { return set_paddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingRight") ) { return get_paddingRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_marginBottom") ) { return set_marginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_marginBottom") ) { return get_marginBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"isPositiveLength") ) { return isPositiveLength_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidFontGroup") ) { return isValidFontGroup_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidShorthand") ) { return isValidShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"setTypedProperty") ) { return setTypedProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"getTypedProperty") ) { return getTypedProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"getPropertyValue") ) { return getPropertyValue_dyn(); }
		if (HX_FIELD_EQ(inName,"borderRightStyle") ) { return inCallProp ? get_borderRightStyle() : borderRightStyle; }
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { return inCallProp ? get_borderRightColor() : borderRightColor; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { return inCallProp ? get_borderRightWidth() : borderRightWidth; }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { return inCallProp ? get_backgroundOrigin() : backgroundOrigin; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { return inCallProp ? get_backgroundRepeat() : backgroundRepeat; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"set_verticalAlign") ) { return set_verticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"get_verticalAlign") ) { return get_verticalAlign_dyn(); }
		if (HX_FIELD_EQ(inName,"set_letterSpacing") ) { return set_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"get_letterSpacing") ) { return get_letterSpacing_dyn(); }
		if (HX_FIELD_EQ(inName,"set_textTransform") ) { return set_textTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textTransform") ) { return get_textTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"set_paddingBottom") ) { return set_paddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_paddingBottom") ) { return get_paddingBottom_dyn(); }
		if (HX_FIELD_EQ(inName,"borderBottomStyle") ) { return inCallProp ? get_borderBottomStyle() : borderBottomStyle; }
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { return inCallProp ? get_borderBottomColor() : borderBottomColor; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { return inCallProp ? get_borderBottomWidth() : borderBottomWidth; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"set_textDecoration") ) { return set_textDecoration_dyn(); }
		if (HX_FIELD_EQ(inName,"get_textDecoration") ) { return get_textDecoration_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderTopStyle") ) { return set_borderTopStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopStyle") ) { return get_borderTopStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderTopColor") ) { return set_borderTopColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopColor") ) { return get_borderTopColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderTopWidth") ) { return set_borderTopWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderTopWidth") ) { return get_borderTopWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundClip") ) { return get_backgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundClip") ) { return set_backgroundClip_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundSize") ) { return get_backgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundSize") ) { return set_backgroundSize_dyn(); }
		if (HX_FIELD_EQ(inName,"setBorderShorthand") ) { return setBorderShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"_indexedProperties") ) { return _indexedProperties; }
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { return inCallProp ? get_transitionDuration() : transitionDuration; }
		if (HX_FIELD_EQ(inName,"transitionProperty") ) { return inCallProp ? get_transitionProperty() : transitionProperty; }
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { return inCallProp ? get_backgroundPosition() : backgroundPosition; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"set_borderLeftStyle") ) { return set_borderLeftStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeftStyle") ) { return get_borderLeftStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderLeftColor") ) { return set_borderLeftColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeftColor") ) { return get_borderLeftColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderLeftWidth") ) { return set_borderLeftWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderLeftWidth") ) { return get_borderLeftWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transformOrigin") ) { return set_transformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transformOrigin") ) { return get_transformOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transitionDelay") ) { return set_transitionDelay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionDelay") ) { return get_transitionDelay_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundImage") ) { return get_backgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundImage") ) { return set_backgroundImage_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundColor") ) { return get_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundColor") ) { return set_backgroundColor_dyn(); }
		if (HX_FIELD_EQ(inName,"getPropertyPriority") ) { return getPropertyPriority_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"set_borderRightStyle") ) { return set_borderRightStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRightStyle") ) { return get_borderRightStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderRightColor") ) { return set_borderRightColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRightColor") ) { return get_borderRightColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderRightWidth") ) { return set_borderRightWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderRightWidth") ) { return get_borderRightWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundOrigin") ) { return get_backgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundOrigin") ) { return set_backgroundOrigin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundRepeat") ) { return get_backgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundRepeat") ) { return set_backgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidOverflowValue") ) { return isValidOverflowValue_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidFontShorthand") ) { return isValidFontShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"setFontShorthandGoup") ) { return setFontShorthandGoup_dyn(); }
		if (HX_FIELD_EQ(inName,"_propertiesPositions") ) { return _propertiesPositions; }
		if (HX_FIELD_EQ(inName,"backgroundAttachment") ) { return inCallProp ? get_backgroundAttachment() : backgroundAttachment; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"set_borderBottomStyle") ) { return set_borderBottomStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottomStyle") ) { return get_borderBottomStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderBottomColor") ) { return set_borderBottomColor_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottomColor") ) { return get_borderBottomColor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_borderBottomWidth") ) { return set_borderBottomWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"get_borderBottomWidth") ) { return get_borderBottomWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidMarginProperty") ) { return isValidMarginProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBackgroundSize") ) { return isValidBackgroundSize_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"set_transitionDuration") ) { return set_transitionDuration_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionDuration") ) { return get_transitionDuration_dyn(); }
		if (HX_FIELD_EQ(inName,"set_transitionProperty") ) { return set_transitionProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionProperty") ) { return get_transitionProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_backgroundPosition") ) { return get_backgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundPosition") ) { return set_backgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidPaddingProperty") ) { return isValidPaddingProperty_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidTransitionGroup") ) { return isValidTransitionGroup_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransitionShorthand") ) { return setTransitionShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"resetIndexedProperties") ) { return resetIndexedProperties_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"isValidBorderStyleValue") ) { return isValidBorderStyleValue_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBorderColorValue") ) { return isValidBorderColorValue_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBorderWidthValue") ) { return isValidBorderWidthValue_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBackgroundRepeat") ) { return isValidBackgroundRepeat_dyn(); }
		if (HX_FIELD_EQ(inName,"setTypedPropertyInitial") ) { return setTypedPropertyInitial_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"get_backgroundAttachment") ) { return get_backgroundAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"set_backgroundAttachment") ) { return set_backgroundAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidOutlineStyleValue") ) { return isValidOutlineStyleValue_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidOutlineColorValue") ) { return isValidOutlineColorValue_dyn(); }
		if (HX_FIELD_EQ(inName,"setTypedBorderProperties") ) { return setTypedBorderProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"resetPropertiesPositions") ) { return resetPropertiesPositions_dyn(); }
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { return inCallProp ? get_transitionTimingFunction() : transitionTimingFunction; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"serializeStyleDeclaration") ) { return serializeStyleDeclaration_dyn(); }
		if (HX_FIELD_EQ(inName,"setTypedOutlineProperties") ) { return setTypedOutlineProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"setTypedBordersProperties") ) { return setTypedBordersProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBackgroundPosition") ) { return isValidBackgroundPosition_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidTransitionProperty") ) { return isValidTransitionProperty_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"isValidTransitionShorthand") ) { return isValidTransitionShorthand_dyn(); }
		if (HX_FIELD_EQ(inName,"isValidBackgroundShorthand") ) { return isValidBackgroundShorthand_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"isValidBackgroundAttachment") ) { return isValidBackgroundAttachment_dyn(); }
		if (HX_FIELD_EQ(inName,"setTransitionGroupShorthand") ) { return setTransitionGroupShorthand_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"set_transitionTimingFunction") ) { return set_transitionTimingFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transitionTimingFunction") ) { return get_transitionTimingFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"decrementPropertiesPositions") ) { return decrementPropertiesPositions_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"isValidTransitionTimingFunction") ) { return isValidTransitionTimingFunction_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"isValidTransitionDelayOrDuration") ) { return isValidTransitionDelayOrDuration_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSStyleDeclaration_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { if (inCallProp) return set_top(inValue);top=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { if (inCallProp) return set_font(inValue);font=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"left") ) { if (inCallProp) return set_left(inValue);left=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { if (inCallProp) return set_color(inValue);color=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { if (inCallProp) return set_right(inValue);right=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { if (inCallProp) return set_width(inValue);width=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clear") ) { if (inCallProp) return set_clear(inValue);clear=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cursor") ) { if (inCallProp) return set_cursor(inValue);cursor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"border") ) { if (inCallProp) return set_border(inValue);border=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { if (inCallProp) return set_bottom(inValue);bottom=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { if (inCallProp) return set_height(inValue);height=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"margin") ) { if (inCallProp) return set_margin(inValue);margin=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zIndex") ) { if (inCallProp) return set_zIndex(inValue);zIndex=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cssText") ) { if (inCallProp) return set_cssText(inValue);cssText=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outline") ) { if (inCallProp) return set_outline(inValue);outline=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opacity") ) { if (inCallProp) return set_opacity(inValue);opacity=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"padding") ) { if (inCallProp) return set_padding(inValue);padding=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"display") ) { if (inCallProp) return set_display(inValue);display=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"overflow") ) { if (inCallProp) return set_overflow(inValue);overflow=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontSize") ) { if (inCallProp) return set_fontSize(inValue);fontSize=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxWidth") ) { if (inCallProp) return set_maxWidth(inValue);maxWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minWidth") ) { if (inCallProp) return set_minWidth(inValue);minWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cssFloat") ) { if (inCallProp) return set_CSSFloat(inValue);cssFloat=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { if (inCallProp) return set_position(inValue);position=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { if (inCallProp) return set_transform(inValue);transform=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"overflowY") ) { if (inCallProp) return set_overflowY(inValue);overflowY=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"overflowX") ) { if (inCallProp) return set_overflowX(inValue);overflowX=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textAlign") ) { if (inCallProp) return set_textAlign(inValue);textAlign=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontStyle") ) { if (inCallProp) return set_fontStyle(inValue);fontStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTop") ) { if (inCallProp) return set_borderTop(inValue);borderTop=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxHeight") ) { if (inCallProp) return set_maxHeight(inValue);maxHeight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minHeight") ) { if (inCallProp) return set_minHeight(inValue);minHeight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginTop") ) { if (inCallProp) return set_marginTop(inValue);marginTop=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parentRule") ) { parentRule=inValue.Cast< ::cocktail::core::css::CSSRule >(); return inValue; }
		if (HX_FIELD_EQ(inName,"visibility") ) { if (inCallProp) return set_visibility(inValue);visibility=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textIndent") ) { if (inCallProp) return set_textIndent(inValue);textIndent=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"whiteSpace") ) { if (inCallProp) return set_whiteSpace(inValue);whiteSpace=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lineHeight") ) { if (inCallProp) return set_lineHeight(inValue);lineHeight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontFamily") ) { if (inCallProp) return set_fontFamily(inValue);fontFamily=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontWeight") ) { if (inCallProp) return set_fontWeight(inValue);fontWeight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeft") ) { if (inCallProp) return set_borderLeft(inValue);borderLeft=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"background") ) { if (inCallProp) return set_background(inValue);background=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingTop") ) { if (inCallProp) return set_paddingTop(inValue);paddingTop=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginLeft") ) { if (inCallProp) return set_marginLeft(inValue);marginLeft=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"wordSpacing") ) { if (inCallProp) return set_wordSpacing(inValue);wordSpacing=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fontVariant") ) { if (inCallProp) return set_fontVariant(inValue);fontVariant=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRight") ) { if (inCallProp) return set_borderRight(inValue);borderRight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderStyle") ) { if (inCallProp) return set_borderStyle(inValue);borderStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderColor") ) { if (inCallProp) return set_borderColor(inValue);borderColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderWidth") ) { if (inCallProp) return set_borderWidth(inValue);borderWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingLeft") ) { if (inCallProp) return set_paddingLeft(inValue);paddingLeft=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginRight") ) { if (inCallProp) return set_marginRight(inValue);marginRight=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"outlineStyle") ) { if (inCallProp) return set_outlineStyle(inValue);outlineStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineColor") ) { if (inCallProp) return set_outlineColor(inValue);outlineColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"outlineWidth") ) { if (inCallProp) return set_outlineWidth(inValue);outlineWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottom") ) { if (inCallProp) return set_borderBottom(inValue);borderBottom=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingRight") ) { if (inCallProp) return set_paddingRight(inValue);paddingRight=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"marginBottom") ) { if (inCallProp) return set_marginBottom(inValue);marginBottom=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"verticalAlign") ) { if (inCallProp) return set_verticalAlign(inValue);verticalAlign=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"letterSpacing") ) { if (inCallProp) return set_letterSpacing(inValue);letterSpacing=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textTransform") ) { if (inCallProp) return set_textTransform(inValue);textTransform=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"paddingBottom") ) { if (inCallProp) return set_paddingBottom(inValue);paddingBottom=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_onStyleChange") ) { _onStyleChange=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"textDecoration") ) { if (inCallProp) return set_textDecoration(inValue);textDecoration=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopStyle") ) { if (inCallProp) return set_borderTopStyle(inValue);borderTopStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopColor") ) { if (inCallProp) return set_borderTopColor(inValue);borderTopColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderTopWidth") ) { if (inCallProp) return set_borderTopWidth(inValue);borderTopWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundClip") ) { if (inCallProp) return set_backgroundClip(inValue);backgroundClip=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundSize") ) { if (inCallProp) return set_backgroundSize(inValue);backgroundSize=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"transformOrigin") ) { if (inCallProp) return set_transformOrigin(inValue);transformOrigin=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { if (inCallProp) return set_transitionDelay(inValue);transitionDelay=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftStyle") ) { if (inCallProp) return set_borderLeftStyle(inValue);borderLeftStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftColor") ) { if (inCallProp) return set_borderLeftColor(inValue);borderLeftColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderLeftWidth") ) { if (inCallProp) return set_borderLeftWidth(inValue);borderLeftWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundImage") ) { if (inCallProp) return set_backgroundImage(inValue);backgroundImage=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundColor") ) { if (inCallProp) return set_backgroundColor(inValue);backgroundColor=inValue.Cast< ::String >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"borderRightStyle") ) { if (inCallProp) return set_borderRightStyle(inValue);borderRightStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightColor") ) { if (inCallProp) return set_borderRightColor(inValue);borderRightColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderRightWidth") ) { if (inCallProp) return set_borderRightWidth(inValue);borderRightWidth=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundOrigin") ) { if (inCallProp) return set_backgroundOrigin(inValue);backgroundOrigin=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundRepeat") ) { if (inCallProp) return set_backgroundRepeat(inValue);backgroundRepeat=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"borderBottomStyle") ) { if (inCallProp) return set_borderBottomStyle(inValue);borderBottomStyle=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomColor") ) { if (inCallProp) return set_borderBottomColor(inValue);borderBottomColor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"borderBottomWidth") ) { if (inCallProp) return set_borderBottomWidth(inValue);borderBottomWidth=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_indexedProperties") ) { _indexedProperties=inValue.Cast< Array< ::cocktail::core::css::TypedPropertyVO > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { if (inCallProp) return set_transitionDuration(inValue);transitionDuration=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transitionProperty") ) { if (inCallProp) return set_transitionProperty(inValue);transitionProperty=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundPosition") ) { if (inCallProp) return set_backgroundPosition(inValue);backgroundPosition=inValue.Cast< ::String >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"_propertiesPositions") ) { _propertiesPositions=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundAttachment") ) { if (inCallProp) return set_backgroundAttachment(inValue);backgroundAttachment=inValue.Cast< ::String >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { if (inCallProp) return set_transitionTimingFunction(inValue);transitionTimingFunction=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSStyleDeclaration_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_propertiesPositions"));
	outFields->push(HX_CSTRING("_indexedProperties"));
	outFields->push(HX_CSTRING("parentRule"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("cssText"));
	outFields->push(HX_CSTRING("outlineStyle"));
	outFields->push(HX_CSTRING("outlineColor"));
	outFields->push(HX_CSTRING("outlineWidth"));
	outFields->push(HX_CSTRING("outline"));
	outFields->push(HX_CSTRING("cursor"));
	outFields->push(HX_CSTRING("transformOrigin"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("transitionDelay"));
	outFields->push(HX_CSTRING("transitionTimingFunction"));
	outFields->push(HX_CSTRING("transitionDuration"));
	outFields->push(HX_CSTRING("transitionProperty"));
	outFields->push(HX_CSTRING("overflowY"));
	outFields->push(HX_CSTRING("overflowX"));
	outFields->push(HX_CSTRING("overflow"));
	outFields->push(HX_CSTRING("visibility"));
	outFields->push(HX_CSTRING("opacity"));
	outFields->push(HX_CSTRING("textDecoration"));
	outFields->push(HX_CSTRING("verticalAlign"));
	outFields->push(HX_CSTRING("textIndent"));
	outFields->push(HX_CSTRING("textAlign"));
	outFields->push(HX_CSTRING("whiteSpace"));
	outFields->push(HX_CSTRING("wordSpacing"));
	outFields->push(HX_CSTRING("letterSpacing"));
	outFields->push(HX_CSTRING("textTransform"));
	outFields->push(HX_CSTRING("lineHeight"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("fontVariant"));
	outFields->push(HX_CSTRING("fontFamily"));
	outFields->push(HX_CSTRING("fontStyle"));
	outFields->push(HX_CSTRING("fontWeight"));
	outFields->push(HX_CSTRING("fontSize"));
	outFields->push(HX_CSTRING("font"));
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("borderLeft"));
	outFields->push(HX_CSTRING("borderBottom"));
	outFields->push(HX_CSTRING("borderRight"));
	outFields->push(HX_CSTRING("borderTop"));
	outFields->push(HX_CSTRING("borderStyle"));
	outFields->push(HX_CSTRING("borderLeftStyle"));
	outFields->push(HX_CSTRING("borderBottomStyle"));
	outFields->push(HX_CSTRING("borderRightStyle"));
	outFields->push(HX_CSTRING("borderTopStyle"));
	outFields->push(HX_CSTRING("borderColor"));
	outFields->push(HX_CSTRING("borderLeftColor"));
	outFields->push(HX_CSTRING("borderBottomColor"));
	outFields->push(HX_CSTRING("borderRightColor"));
	outFields->push(HX_CSTRING("borderTopColor"));
	outFields->push(HX_CSTRING("borderWidth"));
	outFields->push(HX_CSTRING("borderLeftWidth"));
	outFields->push(HX_CSTRING("borderBottomWidth"));
	outFields->push(HX_CSTRING("borderRightWidth"));
	outFields->push(HX_CSTRING("borderTopWidth"));
	outFields->push(HX_CSTRING("backgroundAttachment"));
	outFields->push(HX_CSTRING("backgroundClip"));
	outFields->push(HX_CSTRING("backgroundPosition"));
	outFields->push(HX_CSTRING("backgroundSize"));
	outFields->push(HX_CSTRING("backgroundOrigin"));
	outFields->push(HX_CSTRING("backgroundRepeat"));
	outFields->push(HX_CSTRING("backgroundImage"));
	outFields->push(HX_CSTRING("backgroundColor"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("bottom"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("maxWidth"));
	outFields->push(HX_CSTRING("minWidth"));
	outFields->push(HX_CSTRING("maxHeight"));
	outFields->push(HX_CSTRING("minHeight"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("paddingBottom"));
	outFields->push(HX_CSTRING("paddingTop"));
	outFields->push(HX_CSTRING("paddingRight"));
	outFields->push(HX_CSTRING("paddingLeft"));
	outFields->push(HX_CSTRING("padding"));
	outFields->push(HX_CSTRING("marginBottom"));
	outFields->push(HX_CSTRING("marginTop"));
	outFields->push(HX_CSTRING("marginRight"));
	outFields->push(HX_CSTRING("marginLeft"));
	outFields->push(HX_CSTRING("margin"));
	outFields->push(HX_CSTRING("zIndex"));
	outFields->push(HX_CSTRING("clear"));
	outFields->push(HX_CSTRING("cssFloat"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("display"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_textDecoration"),
	HX_CSTRING("get_textDecoration"),
	HX_CSTRING("set_outlineStyle"),
	HX_CSTRING("get_outlineStyle"),
	HX_CSTRING("set_outlineColor"),
	HX_CSTRING("get_outlineColor"),
	HX_CSTRING("set_outlineWidth"),
	HX_CSTRING("get_outlineWidth"),
	HX_CSTRING("set_outline"),
	HX_CSTRING("get_outline"),
	HX_CSTRING("set_border"),
	HX_CSTRING("get_border"),
	HX_CSTRING("set_borderLeft"),
	HX_CSTRING("get_borderLeft"),
	HX_CSTRING("set_borderBottom"),
	HX_CSTRING("get_borderBottom"),
	HX_CSTRING("set_borderRight"),
	HX_CSTRING("get_borderRight"),
	HX_CSTRING("set_borderTop"),
	HX_CSTRING("get_borderTop"),
	HX_CSTRING("set_borderStyle"),
	HX_CSTRING("get_borderStyle"),
	HX_CSTRING("set_borderLeftStyle"),
	HX_CSTRING("get_borderLeftStyle"),
	HX_CSTRING("set_borderBottomStyle"),
	HX_CSTRING("get_borderBottomStyle"),
	HX_CSTRING("set_borderRightStyle"),
	HX_CSTRING("get_borderRightStyle"),
	HX_CSTRING("set_borderTopStyle"),
	HX_CSTRING("get_borderTopStyle"),
	HX_CSTRING("set_borderColor"),
	HX_CSTRING("get_borderColor"),
	HX_CSTRING("set_borderLeftColor"),
	HX_CSTRING("get_borderLeftColor"),
	HX_CSTRING("set_borderBottomColor"),
	HX_CSTRING("get_borderBottomColor"),
	HX_CSTRING("set_borderRightColor"),
	HX_CSTRING("get_borderRightColor"),
	HX_CSTRING("set_borderTopColor"),
	HX_CSTRING("get_borderTopColor"),
	HX_CSTRING("set_borderWidth"),
	HX_CSTRING("get_borderWidth"),
	HX_CSTRING("set_borderLeftWidth"),
	HX_CSTRING("get_borderLeftWidth"),
	HX_CSTRING("set_borderBottomWidth"),
	HX_CSTRING("get_borderBottomWidth"),
	HX_CSTRING("set_borderRightWidth"),
	HX_CSTRING("get_borderRightWidth"),
	HX_CSTRING("set_borderTopWidth"),
	HX_CSTRING("get_borderTopWidth"),
	HX_CSTRING("set_transformOrigin"),
	HX_CSTRING("get_transformOrigin"),
	HX_CSTRING("set_transform"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("set_transitionTimingFunction"),
	HX_CSTRING("get_transitionTimingFunction"),
	HX_CSTRING("set_transitionDelay"),
	HX_CSTRING("get_transitionDelay"),
	HX_CSTRING("set_transitionDuration"),
	HX_CSTRING("get_transitionDuration"),
	HX_CSTRING("set_transitionProperty"),
	HX_CSTRING("get_transitionProperty"),
	HX_CSTRING("get_cursor"),
	HX_CSTRING("set_cursor"),
	HX_CSTRING("set_overflowY"),
	HX_CSTRING("get_overflowY"),
	HX_CSTRING("set_overflowX"),
	HX_CSTRING("get_overflowX"),
	HX_CSTRING("set_overflow"),
	HX_CSTRING("get_overflow"),
	HX_CSTRING("get_backgroundOrigin"),
	HX_CSTRING("set_backgroundOrigin"),
	HX_CSTRING("get_backgroundPosition"),
	HX_CSTRING("set_backgroundPosition"),
	HX_CSTRING("get_backgroundAttachment"),
	HX_CSTRING("set_backgroundAttachment"),
	HX_CSTRING("get_backgroundClip"),
	HX_CSTRING("set_backgroundClip"),
	HX_CSTRING("get_backgroundSize"),
	HX_CSTRING("set_backgroundSize"),
	HX_CSTRING("get_backgroundRepeat"),
	HX_CSTRING("set_backgroundRepeat"),
	HX_CSTRING("get_backgroundImage"),
	HX_CSTRING("set_backgroundImage"),
	HX_CSTRING("get_backgroundColor"),
	HX_CSTRING("set_backgroundColor"),
	HX_CSTRING("get_background"),
	HX_CSTRING("set_background"),
	HX_CSTRING("set_textAlign"),
	HX_CSTRING("get_textAlign"),
	HX_CSTRING("set_whiteSpace"),
	HX_CSTRING("get_whiteSpace"),
	HX_CSTRING("set_textIndent"),
	HX_CSTRING("get_textIndent"),
	HX_CSTRING("set_verticalAlign"),
	HX_CSTRING("get_verticalAlign"),
	HX_CSTRING("set_lineHeight"),
	HX_CSTRING("get_lineHeight"),
	HX_CSTRING("set_wordSpacing"),
	HX_CSTRING("get_wordSpacing"),
	HX_CSTRING("set_color"),
	HX_CSTRING("get_color"),
	HX_CSTRING("set_letterSpacing"),
	HX_CSTRING("get_letterSpacing"),
	HX_CSTRING("set_textTransform"),
	HX_CSTRING("get_textTransform"),
	HX_CSTRING("set_fontVariant"),
	HX_CSTRING("get_fontVariant"),
	HX_CSTRING("set_fontFamily"),
	HX_CSTRING("get_fontFamily"),
	HX_CSTRING("set_fontStyle"),
	HX_CSTRING("get_fontStyle"),
	HX_CSTRING("set_fontWeight"),
	HX_CSTRING("get_fontWeight"),
	HX_CSTRING("set_fontSize"),
	HX_CSTRING("get_fontSize"),
	HX_CSTRING("get_font"),
	HX_CSTRING("set_font"),
	HX_CSTRING("set_clear"),
	HX_CSTRING("get_clear"),
	HX_CSTRING("set_CSSFloat"),
	HX_CSTRING("get_CSSFloat"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_maxWidth"),
	HX_CSTRING("get_maxWidth"),
	HX_CSTRING("set_minWidth"),
	HX_CSTRING("get_minWidth"),
	HX_CSTRING("set_maxHeight"),
	HX_CSTRING("get_maxHeight"),
	HX_CSTRING("set_minHeight"),
	HX_CSTRING("get_minHeight"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_zIndex"),
	HX_CSTRING("get_zIndex"),
	HX_CSTRING("set_position"),
	HX_CSTRING("get_position"),
	HX_CSTRING("set_display"),
	HX_CSTRING("get_display"),
	HX_CSTRING("set_paddingBottom"),
	HX_CSTRING("get_paddingBottom"),
	HX_CSTRING("set_paddingTop"),
	HX_CSTRING("get_paddingTop"),
	HX_CSTRING("set_paddingRight"),
	HX_CSTRING("get_paddingRight"),
	HX_CSTRING("set_paddingLeft"),
	HX_CSTRING("get_paddingLeft"),
	HX_CSTRING("set_padding"),
	HX_CSTRING("get_padding"),
	HX_CSTRING("set_marginBottom"),
	HX_CSTRING("get_marginBottom"),
	HX_CSTRING("set_marginTop"),
	HX_CSTRING("get_marginTop"),
	HX_CSTRING("set_marginRight"),
	HX_CSTRING("get_marginRight"),
	HX_CSTRING("set_marginLeft"),
	HX_CSTRING("get_marginLeft"),
	HX_CSTRING("set_margin"),
	HX_CSTRING("get_margin"),
	HX_CSTRING("set_visibility"),
	HX_CSTRING("get_visibility"),
	HX_CSTRING("set_opacity"),
	HX_CSTRING("get_opacity"),
	HX_CSTRING("set_cssText"),
	HX_CSTRING("get_cssText"),
	HX_CSTRING("serializeStyleDeclaration"),
	HX_CSTRING("isPositiveLength"),
	HX_CSTRING("isValidPaddingProperty"),
	HX_CSTRING("isValidMarginProperty"),
	HX_CSTRING("isValidOverflowValue"),
	HX_CSTRING("isValidOutlineStyleValue"),
	HX_CSTRING("isValidOutlineColorValue"),
	HX_CSTRING("isValidBorderStyleValue"),
	HX_CSTRING("isValidBorderColorValue"),
	HX_CSTRING("isValidBorderWidthValue"),
	HX_CSTRING("isValidTransitionGroup"),
	HX_CSTRING("isValidFontGroup"),
	HX_CSTRING("isValidFontShorthand"),
	HX_CSTRING("setFontShorthandGoup"),
	HX_CSTRING("isValidTransitionShorthand"),
	HX_CSTRING("isValidBackgroundAttachment"),
	HX_CSTRING("isValidBackgroundRepeat"),
	HX_CSTRING("isValidBackgroundShorthand"),
	HX_CSTRING("isValidShorthand"),
	HX_CSTRING("setTransitionShorthand"),
	HX_CSTRING("setTransitionGroupShorthand"),
	HX_CSTRING("setTypedOutlineProperties"),
	HX_CSTRING("setTypedBorderProperties"),
	HX_CSTRING("setTypedBordersProperties"),
	HX_CSTRING("setBorderShorthand"),
	HX_CSTRING("setShorthand"),
	HX_CSTRING("isShorthand"),
	HX_CSTRING("isValidBackgroundSize"),
	HX_CSTRING("isValidBackgroundPosition"),
	HX_CSTRING("isValidTransitionDelayOrDuration"),
	HX_CSTRING("isValidTransitionProperty"),
	HX_CSTRING("isValidTransitionTimingFunction"),
	HX_CSTRING("isValidProperty"),
	HX_CSTRING("applyProperty"),
	HX_CSTRING("setTypedPropertyInitial"),
	HX_CSTRING("setTypedProperty"),
	HX_CSTRING("getTypedProperty"),
	HX_CSTRING("getPropertyPriority"),
	HX_CSTRING("removeProperty"),
	HX_CSTRING("setProperty"),
	HX_CSTRING("getPropertyValue"),
	HX_CSTRING("item"),
	HX_CSTRING("decrementPropertiesPositions"),
	HX_CSTRING("resetPropertiesPositions"),
	HX_CSTRING("resetIndexedProperties"),
	HX_CSTRING("reset"),
	HX_CSTRING("_onStyleChange"),
	HX_CSTRING("_propertiesPositions"),
	HX_CSTRING("_indexedProperties"),
	HX_CSTRING("parentRule"),
	HX_CSTRING("length"),
	HX_CSTRING("cssText"),
	HX_CSTRING("outlineStyle"),
	HX_CSTRING("outlineColor"),
	HX_CSTRING("outlineWidth"),
	HX_CSTRING("outline"),
	HX_CSTRING("cursor"),
	HX_CSTRING("transformOrigin"),
	HX_CSTRING("transform"),
	HX_CSTRING("transitionDelay"),
	HX_CSTRING("transitionTimingFunction"),
	HX_CSTRING("transitionDuration"),
	HX_CSTRING("transitionProperty"),
	HX_CSTRING("overflowY"),
	HX_CSTRING("overflowX"),
	HX_CSTRING("overflow"),
	HX_CSTRING("visibility"),
	HX_CSTRING("opacity"),
	HX_CSTRING("textDecoration"),
	HX_CSTRING("verticalAlign"),
	HX_CSTRING("textIndent"),
	HX_CSTRING("textAlign"),
	HX_CSTRING("whiteSpace"),
	HX_CSTRING("wordSpacing"),
	HX_CSTRING("letterSpacing"),
	HX_CSTRING("textTransform"),
	HX_CSTRING("lineHeight"),
	HX_CSTRING("color"),
	HX_CSTRING("fontVariant"),
	HX_CSTRING("fontFamily"),
	HX_CSTRING("fontStyle"),
	HX_CSTRING("fontWeight"),
	HX_CSTRING("fontSize"),
	HX_CSTRING("font"),
	HX_CSTRING("border"),
	HX_CSTRING("borderLeft"),
	HX_CSTRING("borderBottom"),
	HX_CSTRING("borderRight"),
	HX_CSTRING("borderTop"),
	HX_CSTRING("borderStyle"),
	HX_CSTRING("borderLeftStyle"),
	HX_CSTRING("borderBottomStyle"),
	HX_CSTRING("borderRightStyle"),
	HX_CSTRING("borderTopStyle"),
	HX_CSTRING("borderColor"),
	HX_CSTRING("borderLeftColor"),
	HX_CSTRING("borderBottomColor"),
	HX_CSTRING("borderRightColor"),
	HX_CSTRING("borderTopColor"),
	HX_CSTRING("borderWidth"),
	HX_CSTRING("borderLeftWidth"),
	HX_CSTRING("borderBottomWidth"),
	HX_CSTRING("borderRightWidth"),
	HX_CSTRING("borderTopWidth"),
	HX_CSTRING("backgroundAttachment"),
	HX_CSTRING("backgroundClip"),
	HX_CSTRING("backgroundPosition"),
	HX_CSTRING("backgroundSize"),
	HX_CSTRING("backgroundOrigin"),
	HX_CSTRING("backgroundRepeat"),
	HX_CSTRING("backgroundImage"),
	HX_CSTRING("backgroundColor"),
	HX_CSTRING("background"),
	HX_CSTRING("right"),
	HX_CSTRING("bottom"),
	HX_CSTRING("left"),
	HX_CSTRING("top"),
	HX_CSTRING("maxWidth"),
	HX_CSTRING("minWidth"),
	HX_CSTRING("maxHeight"),
	HX_CSTRING("minHeight"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("paddingBottom"),
	HX_CSTRING("paddingTop"),
	HX_CSTRING("paddingRight"),
	HX_CSTRING("paddingLeft"),
	HX_CSTRING("padding"),
	HX_CSTRING("marginBottom"),
	HX_CSTRING("marginTop"),
	HX_CSTRING("marginRight"),
	HX_CSTRING("marginLeft"),
	HX_CSTRING("margin"),
	HX_CSTRING("zIndex"),
	HX_CSTRING("clear"),
	HX_CSTRING("cssFloat"),
	HX_CSTRING("position"),
	HX_CSTRING("display"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSStyleDeclaration_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSStyleDeclaration_obj::__mClass,"__mClass");
};

Class CSSStyleDeclaration_obj::__mClass;

void CSSStyleDeclaration_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSStyleDeclaration"), hx::TCanCast< CSSStyleDeclaration_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSStyleDeclaration_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
