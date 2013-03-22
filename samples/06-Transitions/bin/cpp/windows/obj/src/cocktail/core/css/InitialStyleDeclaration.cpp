#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_config_Config
#include <cocktail/core/config/Config.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
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
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void InitialStyleDeclaration_obj::__construct()
{
HX_STACK_PUSH("InitialStyleDeclaration::new","cocktail/core/css/InitialStyleDeclaration.hx",64);
{
	HX_STACK_LINE(65)
	super::__construct(null(),null());
	HX_STACK_LINE(67)
	this->initSupportedCSSProperties();
	HX_STACK_LINE(68)
	this->initLengthCSSProperties();
	HX_STACK_LINE(69)
	this->initColorCSSProperties();
	HX_STACK_LINE(70)
	this->initProperties();
	HX_STACK_LINE(71)
	this->initComputedProperties();
}
;
	return null();
}

InitialStyleDeclaration_obj::~InitialStyleDeclaration_obj() { }

Dynamic InitialStyleDeclaration_obj::__CreateEmpty() { return  new InitialStyleDeclaration_obj; }
hx::ObjectPtr< InitialStyleDeclaration_obj > InitialStyleDeclaration_obj::__new()
{  hx::ObjectPtr< InitialStyleDeclaration_obj > result = new InitialStyleDeclaration_obj();
	result->__construct();
	return result;}

Dynamic InitialStyleDeclaration_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InitialStyleDeclaration_obj > result = new InitialStyleDeclaration_obj();
	result->__construct();
	return result;}

Void InitialStyleDeclaration_obj::pushComputedProperty( int index,::cocktail::core::css::CSSPropertyValue typedValue){
{
		HX_STACK_PUSH("InitialStyleDeclaration::pushComputedProperty","cocktail/core/css/InitialStyleDeclaration.hx",339);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_ARG(typedValue,"typedValue");
		HX_STACK_LINE(339)
		this->initialComputedStyleDeclaration->setTypedProperty(index,typedValue,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InitialStyleDeclaration_obj,pushComputedProperty,(void))

Void InitialStyleDeclaration_obj::initComputedProperties( ){
{
		HX_STACK_PUSH("InitialStyleDeclaration::initComputedProperties","cocktail/core/css/InitialStyleDeclaration.hx",240);
		HX_STACK_THIS(this);
		HX_STACK_LINE(241)
		this->initialComputedStyleDeclaration = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(null(),null());
		HX_STACK_LINE(243)
		this->pushComputedProperty((int)15,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(244)
		this->pushComputedProperty((int)16,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(246)
		this->pushComputedProperty((int)0,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INLINE_dyn()));
		HX_STACK_LINE(247)
		this->pushComputedProperty((int)1,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::STATIC_dyn()));
		HX_STACK_LINE(248)
		this->pushComputedProperty((int)2,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(249)
		this->pushComputedProperty((int)3,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(250)
		this->pushComputedProperty((int)4,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(251)
		this->pushComputedProperty((int)51,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(252)
		this->pushComputedProperty((int)52,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(253)
		this->pushComputedProperty((int)49,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(254)
		this->pushComputedProperty((int)53,::cocktail::core::css::CSSPropertyValue_obj::NUMBER(1.0));
		HX_STACK_LINE(256)
		this->pushComputedProperty((int)48,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BASELINE_dyn()));
		HX_STACK_LINE(257)
		this->pushComputedProperty((int)41,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(259)
		this->pushComputedProperty((int)20,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(260)
		this->pushComputedProperty((int)18,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(261)
		this->pushComputedProperty((int)19,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(262)
		this->pushComputedProperty((int)17,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(264)
		this->pushComputedProperty((int)6,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(265)
		this->pushComputedProperty((int)8,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(266)
		this->pushComputedProperty((int)7,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(267)
		this->pushComputedProperty((int)9,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(269)
		this->pushComputedProperty((int)11,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(270)
		this->pushComputedProperty((int)13,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(271)
		this->pushComputedProperty((int)12,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(272)
		this->pushComputedProperty((int)14,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH((int)0));
		HX_STACK_LINE(274)
		this->pushComputedProperty((int)62,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth));
		HX_STACK_LINE(275)
		this->pushComputedProperty((int)63,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth));
		HX_STACK_LINE(276)
		this->pushComputedProperty((int)64,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth));
		HX_STACK_LINE(277)
		this->pushComputedProperty((int)65,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth));
		HX_STACK_LINE(279)
		this->pushComputedProperty((int)67,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(280)
		this->pushComputedProperty((int)68,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(281)
		this->pushComputedProperty((int)69,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(282)
		this->pushComputedProperty((int)70,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(284)
		this->pushComputedProperty((int)72,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(285)
		this->pushComputedProperty((int)73,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(286)
		this->pushComputedProperty((int)74,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(287)
		this->pushComputedProperty((int)75,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(289)
		this->pushComputedProperty((int)82,::cocktail::core::css::CSSPropertyValue_obj::ABSOLUTE_LENGTH(::cocktail::core::config::Config_obj::getInstance()->mediumBorderWidth));
		HX_STACK_LINE(290)
		this->pushComputedProperty((int)83,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(291)
		this->pushComputedProperty((int)84,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INVERT_dyn()));
		HX_STACK_LINE(293)
		this->pushComputedProperty((int)22,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(294)
		this->pushComputedProperty((int)23,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(295)
		this->pushComputedProperty((int)21,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(296)
		this->pushComputedProperty((int)24,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(298)
		this->pushComputedProperty((int)36,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(299)
		this->pushComputedProperty((int)38,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(300)
		this->pushComputedProperty((int)35,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(301)
		this->pushComputedProperty((int)34,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(303)
		this->pushComputedProperty((int)43,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(304)
		this->pushComputedProperty((int)44,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(305)
		this->pushComputedProperty((int)47,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(306)
		this->pushComputedProperty((int)46,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LEFT_dyn()));
		HX_STACK_LINE(307)
		this->pushComputedProperty((int)45,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(308)
		this->pushComputedProperty((int)42,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(309)
		this->pushComputedProperty((int)86,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(311)
		this->pushComputedProperty((int)57,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ALL_dyn()));
		HX_STACK_LINE(312)
		this->pushComputedProperty((int)55,::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::SECONDS((int)0)));
		HX_STACK_LINE(313)
		this->pushComputedProperty((int)56,::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::SECONDS((int)0)));
		HX_STACK_LINE(314)
		this->pushComputedProperty((int)58,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_dyn()));
		HX_STACK_LINE(316)
		this->pushComputedProperty((int)61,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(317)
		this->pushComputedProperty((int)60,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE((int)50)).Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE((int)50))));
		HX_STACK_LINE(319)
		this->pushComputedProperty((int)25,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::TRANSPARENT_dyn()));
		HX_STACK_LINE(320)
		this->pushComputedProperty((int)26,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(321)
		this->pushComputedProperty((int)30,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(0.0)).Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(0.0))));
		HX_STACK_LINE(322)
		this->pushComputedProperty((int)29,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(323)
		this->pushComputedProperty((int)27,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn())).Add(::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn()))));
		HX_STACK_LINE(324)
		this->pushComputedProperty((int)31,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BORDER_BOX_dyn()));
		HX_STACK_LINE(325)
		this->pushComputedProperty((int)28,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PADDING_BOX_dyn()));
		HX_STACK_LINE(326)
		this->pushComputedProperty((int)32,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SCROLL_dyn()));
		HX_STACK_LINE(328)
		this->pushComputedProperty((int)54,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(330)
		this->pushProperty((int)37,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::STRING(::cocktail::core::config::Config_obj::getInstance()->defaultFont))));
		HX_STACK_LINE(331)
		this->pushProperty((int)40,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,initComputedProperties,(void))

Void InitialStyleDeclaration_obj::pushProperty( int index,::cocktail::core::css::CSSPropertyValue typedValue){
{
		HX_STACK_PUSH("InitialStyleDeclaration::pushProperty","cocktail/core/css/InitialStyleDeclaration.hx",231);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_ARG(typedValue,"typedValue");
		HX_STACK_LINE(231)
		this->setTypedPropertyInitial(index,typedValue,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InitialStyleDeclaration_obj,pushProperty,(void))

Void InitialStyleDeclaration_obj::initProperties( ){
{
		HX_STACK_PUSH("InitialStyleDeclaration::initProperties","cocktail/core/css/InitialStyleDeclaration.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_LINE(136)
		this->pushProperty((int)15,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(137)
		this->pushProperty((int)16,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(139)
		this->pushProperty((int)0,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INLINE_dyn()));
		HX_STACK_LINE(140)
		this->pushProperty((int)1,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::STATIC_dyn()));
		HX_STACK_LINE(141)
		this->pushProperty((int)2,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(142)
		this->pushProperty((int)3,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(143)
		this->pushProperty((int)4,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(144)
		this->pushProperty((int)51,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(145)
		this->pushProperty((int)52,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(146)
		this->pushProperty((int)49,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn()));
		HX_STACK_LINE(147)
		this->pushProperty((int)53,::cocktail::core::css::CSSPropertyValue_obj::NUMBER(1.0));
		HX_STACK_LINE(149)
		this->pushProperty((int)48,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BASELINE_dyn()));
		HX_STACK_LINE(150)
		this->pushProperty((int)41,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(152)
		this->pushProperty((int)20,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(153)
		this->pushProperty((int)18,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(154)
		this->pushProperty((int)19,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(155)
		this->pushProperty((int)17,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(157)
		this->pushProperty((int)6,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(158)
		this->pushProperty((int)8,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(159)
		this->pushProperty((int)7,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(160)
		this->pushProperty((int)9,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(162)
		this->pushProperty((int)11,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(163)
		this->pushProperty((int)13,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(164)
		this->pushProperty((int)12,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(165)
		this->pushProperty((int)14,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(167)
		this->pushProperty((int)62,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(168)
		this->pushProperty((int)63,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(169)
		this->pushProperty((int)64,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(170)
		this->pushProperty((int)65,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(172)
		this->pushProperty((int)67,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(173)
		this->pushProperty((int)68,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(174)
		this->pushProperty((int)69,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(175)
		this->pushProperty((int)70,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
		HX_STACK_LINE(177)
		this->pushProperty((int)72,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(178)
		this->pushProperty((int)73,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(179)
		this->pushProperty((int)74,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(180)
		this->pushProperty((int)75,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(182)
		this->pushProperty((int)82,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(183)
		this->pushProperty((int)83,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(184)
		this->pushProperty((int)84,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INVERT_dyn()));
		HX_STACK_LINE(186)
		this->pushProperty((int)22,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(187)
		this->pushProperty((int)23,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(188)
		this->pushProperty((int)21,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(189)
		this->pushProperty((int)24,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(191)
		this->pushProperty((int)36,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(192)
		this->pushProperty((int)38,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(193)
		this->pushProperty((int)35,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(194)
		this->pushProperty((int)34,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn()));
		HX_STACK_LINE(196)
		this->pushProperty((int)43,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(197)
		this->pushProperty((int)44,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(198)
		this->pushProperty((int)47,::cocktail::core::css::CSSPropertyValue_obj::INTEGER((int)0));
		HX_STACK_LINE(199)
		this->pushProperty((int)46,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LEFT_dyn()));
		HX_STACK_LINE(200)
		this->pushProperty((int)45,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn()));
		HX_STACK_LINE(201)
		this->pushProperty((int)42,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(202)
		this->pushProperty((int)86,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(204)
		this->pushProperty((int)57,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ALL_dyn()));
		HX_STACK_LINE(205)
		this->pushProperty((int)55,::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::SECONDS((int)0)));
		HX_STACK_LINE(206)
		this->pushProperty((int)56,::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::SECONDS((int)0)));
		HX_STACK_LINE(207)
		this->pushProperty((int)58,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_dyn()));
		HX_STACK_LINE(209)
		this->pushProperty((int)61,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(210)
		this->pushProperty((int)60,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE((int)50)).Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE((int)50))));
		HX_STACK_LINE(212)
		this->pushProperty((int)25,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::TRANSPARENT_dyn()));
		HX_STACK_LINE(213)
		this->pushProperty((int)26,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn()));
		HX_STACK_LINE(214)
		this->pushProperty((int)30,::cocktail::core::css::CSSPropertyValue_obj::GROUP(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(0.0)).Add(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(0.0))));
		HX_STACK_LINE(215)
		this->pushProperty((int)29,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(216)
		this->pushProperty((int)27,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn()));
		HX_STACK_LINE(217)
		this->pushProperty((int)31,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BORDER_BOX_dyn()));
		HX_STACK_LINE(218)
		this->pushProperty((int)28,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PADDING_BOX_dyn()));
		HX_STACK_LINE(219)
		this->pushProperty((int)32,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SCROLL_dyn()));
		HX_STACK_LINE(221)
		this->pushProperty((int)54,::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn()));
		HX_STACK_LINE(223)
		this->pushProperty((int)37,::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new().Add(::cocktail::core::css::CSSPropertyValue_obj::STRING(::cocktail::core::config::Config_obj::getInstance()->defaultFont))));
		HX_STACK_LINE(224)
		this->pushProperty((int)40,::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(::cocktail::core::config::Config_obj::getInstance()->defaultFontColor)));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,initProperties,(void))

Void InitialStyleDeclaration_obj::initSupportedCSSProperties( ){
{
		HX_STACK_PUSH("InitialStyleDeclaration::initSupportedCSSProperties","cocktail/core/css/InitialStyleDeclaration.hx",113);
		HX_STACK_THIS(this);
		HX_STACK_LINE(113)
		this->supportedCSSProperties = Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)51).Add((int)52).Add((int)49).Add((int)53).Add((int)48).Add((int)41).Add((int)15).Add((int)16).Add((int)19).Add((int)17).Add((int)20).Add((int)18).Add((int)6).Add((int)8).Add((int)7).Add((int)9).Add((int)11).Add((int)13).Add((int)12).Add((int)14).Add((int)22).Add((int)23).Add((int)21).Add((int)24).Add((int)37).Add((int)34).Add((int)36).Add((int)38).Add((int)35).Add((int)43).Add((int)44).Add((int)47).Add((int)46).Add((int)45).Add((int)42).Add((int)40).Add((int)57).Add((int)55).Add((int)56).Add((int)58).Add((int)61).Add((int)60).Add((int)25).Add((int)26).Add((int)30).Add((int)29).Add((int)27).Add((int)32).Add((int)28).Add((int)31).Add((int)54).Add((int)62).Add((int)63).Add((int)64).Add((int)65).Add((int)67).Add((int)68).Add((int)69).Add((int)70).Add((int)72).Add((int)73).Add((int)74).Add((int)75).Add((int)82).Add((int)83).Add((int)84).Add((int)86);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,initSupportedCSSProperties,(void))

Void InitialStyleDeclaration_obj::initColorCSSProperties( ){
{
		HX_STACK_PUSH("InitialStyleDeclaration::initColorCSSProperties","cocktail/core/css/InitialStyleDeclaration.hx",104);
		HX_STACK_THIS(this);
		HX_STACK_LINE(104)
		this->colorCSSProperties = Array_obj< int >::__new().Add((int)25).Add((int)40).Add((int)67).Add((int)69).Add((int)68).Add((int)70).Add((int)84);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,initColorCSSProperties,(void))

Void InitialStyleDeclaration_obj::initLengthCSSProperties( ){
{
		HX_STACK_PUSH("InitialStyleDeclaration::initLengthCSSProperties","cocktail/core/css/InitialStyleDeclaration.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_LINE(88)
		this->lengthCSSProperties = Array_obj< int >::__new().Add((int)15).Add((int)16).Add((int)21).Add((int)22).Add((int)24).Add((int)23).Add((int)17).Add((int)18).Add((int)19).Add((int)20).Add((int)48).Add((int)41).Add((int)6).Add((int)7).Add((int)8).Add((int)9).Add((int)11).Add((int)12).Add((int)13).Add((int)14).Add((int)22).Add((int)23).Add((int)21).Add((int)24).Add((int)43).Add((int)44).Add((int)47).Add((int)61).Add((int)60).Add((int)30).Add((int)29).Add((int)62).Add((int)63).Add((int)64).Add((int)65).Add((int)82);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,initLengthCSSProperties,(void))

::cocktail::core::css::InitialStyleDeclaration InitialStyleDeclaration_obj::_instance;

::cocktail::core::css::InitialStyleDeclaration InitialStyleDeclaration_obj::getInstance( ){
	HX_STACK_PUSH("InitialStyleDeclaration::getInstance","cocktail/core/css/InitialStyleDeclaration.hx",78);
	HX_STACK_LINE(79)
	if (((::cocktail::core::css::InitialStyleDeclaration_obj::_instance == null()))){
		HX_STACK_LINE(80)
		::cocktail::core::css::InitialStyleDeclaration_obj::_instance = ::cocktail::core::css::InitialStyleDeclaration_obj::__new();
	}
	HX_STACK_LINE(84)
	return ::cocktail::core::css::InitialStyleDeclaration_obj::_instance;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(InitialStyleDeclaration_obj,getInstance,return )


InitialStyleDeclaration_obj::InitialStyleDeclaration_obj()
{
}

void InitialStyleDeclaration_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InitialStyleDeclaration);
	HX_MARK_MEMBER_NAME(initialComputedStyleDeclaration,"initialComputedStyleDeclaration");
	HX_MARK_MEMBER_NAME(colorCSSProperties,"colorCSSProperties");
	HX_MARK_MEMBER_NAME(lengthCSSProperties,"lengthCSSProperties");
	HX_MARK_MEMBER_NAME(supportedCSSProperties,"supportedCSSProperties");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void InitialStyleDeclaration_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(initialComputedStyleDeclaration,"initialComputedStyleDeclaration");
	HX_VISIT_MEMBER_NAME(colorCSSProperties,"colorCSSProperties");
	HX_VISIT_MEMBER_NAME(lengthCSSProperties,"lengthCSSProperties");
	HX_VISIT_MEMBER_NAME(supportedCSSProperties,"supportedCSSProperties");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic InitialStyleDeclaration_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { return _instance; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getInstance") ) { return getInstance_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"pushProperty") ) { return pushProperty_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initProperties") ) { return initProperties_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"colorCSSProperties") ) { return colorCSSProperties; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"lengthCSSProperties") ) { return lengthCSSProperties; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"pushComputedProperty") ) { return pushComputedProperty_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"initComputedProperties") ) { return initComputedProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"initColorCSSProperties") ) { return initColorCSSProperties_dyn(); }
		if (HX_FIELD_EQ(inName,"supportedCSSProperties") ) { return supportedCSSProperties; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"initLengthCSSProperties") ) { return initLengthCSSProperties_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"initSupportedCSSProperties") ) { return initSupportedCSSProperties_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"initialComputedStyleDeclaration") ) { return initialComputedStyleDeclaration; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InitialStyleDeclaration_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_instance") ) { _instance=inValue.Cast< ::cocktail::core::css::InitialStyleDeclaration >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"colorCSSProperties") ) { colorCSSProperties=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"lengthCSSProperties") ) { lengthCSSProperties=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"supportedCSSProperties") ) { supportedCSSProperties=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"initialComputedStyleDeclaration") ) { initialComputedStyleDeclaration=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InitialStyleDeclaration_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("initialComputedStyleDeclaration"));
	outFields->push(HX_CSTRING("colorCSSProperties"));
	outFields->push(HX_CSTRING("lengthCSSProperties"));
	outFields->push(HX_CSTRING("supportedCSSProperties"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_instance"),
	HX_CSTRING("getInstance"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("pushComputedProperty"),
	HX_CSTRING("initComputedProperties"),
	HX_CSTRING("pushProperty"),
	HX_CSTRING("initProperties"),
	HX_CSTRING("initSupportedCSSProperties"),
	HX_CSTRING("initColorCSSProperties"),
	HX_CSTRING("initLengthCSSProperties"),
	HX_CSTRING("initialComputedStyleDeclaration"),
	HX_CSTRING("colorCSSProperties"),
	HX_CSTRING("lengthCSSProperties"),
	HX_CSTRING("supportedCSSProperties"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InitialStyleDeclaration_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(InitialStyleDeclaration_obj::_instance,"_instance");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InitialStyleDeclaration_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(InitialStyleDeclaration_obj::_instance,"_instance");
};

Class InitialStyleDeclaration_obj::__mClass;

void InitialStyleDeclaration_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.InitialStyleDeclaration"), hx::TCanCast< InitialStyleDeclaration_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void InitialStyleDeclaration_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
