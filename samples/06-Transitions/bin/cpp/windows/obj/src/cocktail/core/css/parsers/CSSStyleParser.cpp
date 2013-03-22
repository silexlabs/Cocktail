#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSAngleValue
#include <cocktail/core/css/CSSAngleValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorKeyword
#include <cocktail/core/css/CSSColorKeyword.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSColorValue
#include <cocktail/core/css/CSSColorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSConstants
#include <cocktail/core/css/CSSConstants.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSFrequencyValue
#include <cocktail/core/css/CSSFrequencyValue.h>
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
#ifndef INCLUDED_cocktail_core_css_CSSResolutionValue
#include <cocktail/core/css/CSSResolutionValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSTimeValue
#include <cocktail/core/css/CSSTimeValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#include <cocktail/core/css/TypedPropertyVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSStyleParser
#include <cocktail/core/css/parsers/CSSStyleParser.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_StyleDeclarationParserState
#include <cocktail/core/css/parsers/StyleDeclarationParserState.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_StyleValueParserState
#include <cocktail/core/css/parsers/StyleValueParserState.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

Void CSSStyleParser_obj::__construct()
{
HX_STACK_PUSH("CSSStyleParser::new","cocktail/core/css/parsers/CSSStyleParser.hx",46);
{
}
;
	return null();
}

CSSStyleParser_obj::~CSSStyleParser_obj() { }

Dynamic CSSStyleParser_obj::__CreateEmpty() { return  new CSSStyleParser_obj; }
hx::ObjectPtr< CSSStyleParser_obj > CSSStyleParser_obj::__new()
{  hx::ObjectPtr< CSSStyleParser_obj > result = new CSSStyleParser_obj();
	result->__construct();
	return result;}

Dynamic CSSStyleParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSStyleParser_obj > result = new CSSStyleParser_obj();
	result->__construct();
	return result;}

int CSSStyleParser_obj::_position;

Array< ::cocktail::core::css::TypedPropertyVO > CSSStyleParser_obj::_typedProperties;

Array< ::cocktail::core::css::TypedPropertyVO > CSSStyleParser_obj::parseStyle( ::String styles){
	HX_STACK_PUSH("CSSStyleParser::parseStyle","cocktail/core/css/parsers/CSSStyleParser.hx",61);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_LINE(63)
	::cocktail::core::css::parsers::CSSStyleParser_obj::_position = (int)0;
	HX_STACK_LINE(66)
	::cocktail::core::css::parsers::StyleDeclarationParserState state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(67)
	::cocktail::core::css::parsers::StyleDeclarationParserState next = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::BEGIN_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(70)
	if (((::cocktail::core::css::parsers::CSSStyleParser_obj::_typedProperties == null()))){
		HX_STACK_LINE(71)
		::cocktail::core::css::parsers::CSSStyleParser_obj::_typedProperties = Array_obj< ::cocktail::core::css::TypedPropertyVO >::__new();
	}
	HX_STACK_LINE(74)
	::cocktail::core::css::parsers::CSSStyleParser_obj::_typedProperties = ::cocktail::core::utils::Utils_obj::clear(::cocktail::core::css::parsers::CSSStyleParser_obj::_typedProperties);
	HX_STACK_LINE(77)
	Array< ::cocktail::core::css::TypedPropertyVO > typedProperties = ::cocktail::core::css::parsers::CSSStyleParser_obj::_typedProperties;		HX_STACK_VAR(typedProperties,"typedProperties");
	HX_STACK_LINE(79)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(81)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(82)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(85)
	::String styleName = null();		HX_STACK_VAR(styleName,"styleName");
	HX_STACK_LINE(87)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(89)
		{
			::cocktail::core::css::parsers::StyleDeclarationParserState _switch_1 = (state);
			switch((_switch_1)->GetIndex()){
				case 2: {
					HX_STACK_LINE(92)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(101)
							state = next;
							HX_STACK_LINE(102)
							continue;
						}
					}
				}
				;break;
				case 5: {
					HX_STACK_LINE(109)
					switch( (int)(c)){
						case (int)47: {
							HX_STACK_LINE(114)
							state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::BEGIN_COMMENT_dyn();
						}
						;break;
						default: {
							HX_STACK_LINE(120)
							start = position;
							HX_STACK_LINE(121)
							state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::STYLE_NAME_dyn();
							HX_STACK_LINE(122)
							continue;
						}
					}
				}
				;break;
				case 7: {
					HX_STACK_LINE(126)
					if (((c != (int)42))){
						HX_STACK_LINE(128)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::INVALID_STYLE_dyn();
					}
					else{
						HX_STACK_LINE(132)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::COMMENT_dyn();
					}
				}
				;break;
				case 6: {
					HX_STACK_LINE(137)
					if (((c == (int)42))){
						HX_STACK_LINE(139)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::END_COMMENT_dyn();
					}
				}
				;break;
				case 8: {
					HX_STACK_LINE(144)
					if (((c == (int)47))){
						HX_STACK_LINE(149)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(150)
						next = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::BEGIN_dyn();
					}
					else{
						HX_STACK_LINE(153)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::INVALID_STYLE_dyn();
					}
				}
				;break;
				case 0: {
					HX_STACK_LINE(158)
					if ((!(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))))){
						HX_STACK_LINE(160)
						switch( (int)(c)){
							case (int)58: {
								HX_STACK_LINE(166)
								styleName = styles.substr(start,(position - start));
								HX_STACK_LINE(167)
								state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::IGNORE_SPACES_dyn();
								HX_STACK_LINE(168)
								next = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::STYLE_VALUE_dyn();
								HX_STACK_LINE(169)
								continue;
							}
							;break;
							case (int)32: {
								HX_STACK_LINE(173)
								styleName = styles.substr(start,(position - start));
								HX_STACK_LINE(174)
								state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::IGNORE_SPACES_dyn();
								HX_STACK_LINE(175)
								next = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::STYLE_SEPARATOR_dyn();
								HX_STACK_LINE(176)
								continue;
							}
							;break;
							default: {
								HX_STACK_LINE(181)
								state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::INVALID_STYLE_dyn();
								HX_STACK_LINE(182)
								continue;
							}
						}
					}
				}
				;break;
				case 4: {
					HX_STACK_LINE(189)
					if (((c == (int)58))){
						HX_STACK_LINE(192)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::STYLE_VALUE_dyn();
					}
					else{
						HX_STACK_LINE(197)
						state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::INVALID_STYLE_dyn();
						HX_STACK_LINE(198)
						continue;
					}
				}
				;break;
				case 1: {
					HX_STACK_LINE(205)
					::cocktail::core::css::TypedPropertyVO typedProperty = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseStyleValue(styleName,styles,position);		HX_STACK_VAR(typedProperty,"typedProperty");
					HX_STACK_LINE(210)
					position = ::cocktail::core::css::parsers::CSSStyleParser_obj::_position;
					HX_STACK_LINE(212)
					if (((typedProperty != null()))){
						HX_STACK_LINE(213)
						typedProperties->push(typedProperty);
					}
					HX_STACK_LINE(217)
					state = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::IGNORE_SPACES_dyn();
					HX_STACK_LINE(218)
					next = ::cocktail::core::css::parsers::StyleDeclarationParserState_obj::BEGIN_dyn();
				}
				;break;
				case 3: {
					HX_STACK_LINE(225)
					return Array_obj< ::cocktail::core::css::TypedPropertyVO >::__new();
				}
				;break;
			}
		}
		HX_STACK_LINE(228)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(233)
	return typedProperties;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,parseStyle,return )

::cocktail::core::css::TypedPropertyVO CSSStyleParser_obj::parseStyleValue( ::String propertyName,::String styles,int position){
	HX_STACK_PUSH("CSSStyleParser::parseStyleValue","cocktail/core/css/parsers/CSSStyleParser.hx",248);
	HX_STACK_ARG(propertyName,"propertyName");
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(249)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(252)
	if (((c == (int)58))){
		HX_STACK_LINE(254)
		++(position);
		HX_STACK_LINE(255)
		c = styles.cca(position);
	}
	HX_STACK_LINE(261)
	::cocktail::core::css::parsers::StyleValueParserState state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(262)
	::cocktail::core::css::parsers::StyleValueParserState next = ::cocktail::core::css::parsers::StyleValueParserState_obj::BEGIN_VALUE_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(264)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(267)
	bool important = false;		HX_STACK_VAR(important,"important");
	HX_STACK_LINE(271)
	Array< ::cocktail::core::css::CSSPropertyValue > styleValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(styleValues,"styleValues");
	HX_STACK_LINE(275)
	Array< Array< ::cocktail::core::css::CSSPropertyValue > > styleValuesLists = Array_obj< Array< ::cocktail::core::css::CSSPropertyValue > >::__new();		HX_STACK_VAR(styleValuesLists,"styleValuesLists");
	HX_STACK_LINE(280)
	Array< ::cocktail::core::css::CSSPropertyValue > fontNotations = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(fontNotations,"fontNotations");
	HX_STACK_LINE(282)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(284)
		{
			::cocktail::core::css::parsers::StyleValueParserState _switch_2 = (state);
			int _switch_3 = (_switch_2)->GetIndex();{
				if (0==_switch_3) {
					HX_STACK_LINE(286)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(295)
							state = next;
							HX_STACK_LINE(296)
							continue;
						}
					}
				}
				else if (4==_switch_3) {
					HX_STACK_LINE(302)
					if (((c == (int)0))){
						HX_STACK_LINE(306)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::END_dyn();
						HX_STACK_LINE(307)
						continue;
					}
					else{
						HX_STACK_LINE(311)
						if (((bool((c == (int)47)) && bool((fontNotations->length > (int)0))))){
							HX_STACK_LINE(313)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
							HX_STACK_LINE(314)
							continue;
						}
						else{
							HX_STACK_LINE(320)
							if (((fontNotations->length == (int)1))){
								HX_STACK_LINE(322)
								fontNotations->push(styleValues->pop());
								HX_STACK_LINE(323)
								styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::FONT_SIZE_LINE_HEIGHT_GROUP(fontNotations->__get((int)0),fontNotations->__get((int)1)));
								HX_STACK_LINE(324)
								fontNotations = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();
							}
							HX_STACK_LINE(327)
							switch( (int)(c)){
								case (int)32: {
									HX_STACK_LINE(330)
									state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();
									HX_STACK_LINE(331)
									next = ::cocktail::core::css::parsers::StyleValueParserState_obj::BEGIN_VALUE_dyn();
								}
								;break;
								case (int)44: {
									HX_STACK_LINE(336)
									styleValuesLists->push(styleValues);
									HX_STACK_LINE(337)
									styleValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();
									HX_STACK_LINE(338)
									state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();
									HX_STACK_LINE(339)
									next = ::cocktail::core::css::parsers::StyleValueParserState_obj::BEGIN_VALUE_dyn();
								}
								;break;
								case (int)47: {
									HX_STACK_LINE(342)
									if (((propertyName == HX_CSTRING("font")))){
										HX_STACK_LINE(351)
										fontNotations->push(styleValues->pop());
										HX_STACK_LINE(353)
										state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();
										HX_STACK_LINE(354)
										next = ::cocktail::core::css::parsers::StyleValueParserState_obj::BEGIN_VALUE_dyn();
									}
									else{
										HX_STACK_LINE(358)
										state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
										HX_STACK_LINE(359)
										continue;
									}
								}
								;break;
								case (int)59: {
									HX_STACK_LINE(364)
									state = ::cocktail::core::css::parsers::StyleValueParserState_obj::END_dyn();
									HX_STACK_LINE(365)
									continue;
								}
								;break;
								default: {
									HX_STACK_LINE(368)
									state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
									HX_STACK_LINE(369)
									continue;
								}
							}
						}
					}
				}
				else if (1==_switch_3) {
					HX_STACK_LINE(377)
					switch( (int)(c)){
						case (int)44: {
							HX_STACK_LINE(381)
							styleValuesLists->push(styleValues);
							HX_STACK_LINE(382)
							styleValues = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();
							HX_STACK_LINE(383)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();
							HX_STACK_LINE(384)
							next = ::cocktail::core::css::parsers::StyleValueParserState_obj::BEGIN_VALUE_dyn();
							HX_STACK_LINE(386)
							c = styles.cca(++(position));
							HX_STACK_LINE(387)
							continue;
						}
						;break;
						case (int)59: {
							HX_STACK_LINE(390)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::END_dyn();
							HX_STACK_LINE(391)
							continue;
						}
						;break;
						case (int)45: case (int)43: case (int)46: {
							HX_STACK_LINE(394)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::NUMBER_INTEGER_DIMENSION_PERCENTAGE_dyn();
							HX_STACK_LINE(395)
							start = position;
							HX_STACK_LINE(396)
							continue;
						}
						;break;
						case (int)35: {
							HX_STACK_LINE(399)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::HEX_dyn();
							HX_STACK_LINE(400)
							start = position;
							HX_STACK_LINE(401)
							continue;
						}
						;break;
						case (int)33: {
							HX_STACK_LINE(404)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IMPORTANT_dyn();
							HX_STACK_LINE(405)
							start = position;
							HX_STACK_LINE(406)
							continue;
						}
						;break;
						case (int)34: case (int)39: {
							HX_STACK_LINE(409)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::STRING_dyn();
							HX_STACK_LINE(410)
							start = position;
							HX_STACK_LINE(411)
							continue;
						}
						;break;
					}
					HX_STACK_LINE(415)
					if (((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
						HX_STACK_LINE(417)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IDENT_FUNCTION_dyn();
						HX_STACK_LINE(418)
						start = position;
						HX_STACK_LINE(419)
						continue;
					}
					HX_STACK_LINE(423)
					if (((bool((c >= (int)48)) && bool((c <= (int)57))))){
						HX_STACK_LINE(425)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::NUMBER_INTEGER_DIMENSION_PERCENTAGE_dyn();
						HX_STACK_LINE(426)
						start = position;
						HX_STACK_LINE(427)
						continue;
					}
					HX_STACK_LINE(431)
					state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
					HX_STACK_LINE(432)
					continue;
				}
				else if (7==_switch_3) {
					HX_STACK_LINE(437)
					if (((c == (int)0))){
						HX_STACK_LINE(439)
						break;
					}
					else{
						HX_STACK_LINE(442)
						if (((c != (int)59))){
							HX_STACK_LINE(444)
							state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
							HX_STACK_LINE(445)
							continue;
						}
						else{
							HX_STACK_LINE(448)
							break;
						}
					}
				}
				else if (6==_switch_3) {
					HX_STACK_LINE(455)
					int endPosition = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseImportant(styles,++(position));		HX_STACK_VAR(endPosition,"endPosition");
					HX_STACK_LINE(460)
					if (((endPosition != (int)-1))){
						HX_STACK_LINE(462)
						position = endPosition;
						HX_STACK_LINE(463)
						c = styles.cca(position);
						HX_STACK_LINE(464)
						important = true;
						HX_STACK_LINE(465)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(466)
						next = ::cocktail::core::css::parsers::StyleValueParserState_obj::END_dyn();
						HX_STACK_LINE(467)
						continue;
					}
					else{
						HX_STACK_LINE(473)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
						HX_STACK_LINE(474)
						continue;
					}
				}
				else if (8==_switch_3) {
					HX_STACK_LINE(481)
					int endPosition = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseHexaColor(styles,++(position),styleValues);		HX_STACK_VAR(endPosition,"endPosition");
					HX_STACK_LINE(484)
					if (((endPosition != (int)-1))){
						HX_STACK_LINE(486)
						position = endPosition;
						HX_STACK_LINE(487)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::COMPONENT_OR_END_dyn();
					}
					else{
						HX_STACK_LINE(491)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
						HX_STACK_LINE(492)
						continue;
					}
				}
				else if (9==_switch_3) {
					HX_STACK_LINE(497)
					int endPosition = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseString(styles,position,styleValues);		HX_STACK_VAR(endPosition,"endPosition");
					HX_STACK_LINE(499)
					if (((endPosition != (int)-1))){
						HX_STACK_LINE(501)
						position = endPosition;
						HX_STACK_LINE(502)
						c = styles.cca(position);
						HX_STACK_LINE(504)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::COMPONENT_OR_END_dyn();
						HX_STACK_LINE(505)
						continue;
					}
					else{
						HX_STACK_LINE(509)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
						HX_STACK_LINE(510)
						continue;
					}
				}
				else if (2==_switch_3) {
					HX_STACK_LINE(514)
					int endPosition = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseIdentOrFunctionnalNotation(styles,position,styleValues);		HX_STACK_VAR(endPosition,"endPosition");
					HX_STACK_LINE(517)
					if (((endPosition != (int)-1))){
						HX_STACK_LINE(519)
						position = endPosition;
						HX_STACK_LINE(520)
						c = styles.cca(position);
						HX_STACK_LINE(522)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::COMPONENT_OR_END_dyn();
						HX_STACK_LINE(523)
						continue;
					}
					else{
						HX_STACK_LINE(527)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
						HX_STACK_LINE(528)
						continue;
					}
				}
				else if (3==_switch_3) {
					HX_STACK_LINE(534)
					int endPosition = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseIntegerNumberDimensionOrPercentage(styles,position,styleValues);		HX_STACK_VAR(endPosition,"endPosition");
					HX_STACK_LINE(536)
					if (((endPosition != (int)-1))){
						HX_STACK_LINE(539)
						position = endPosition;
						HX_STACK_LINE(540)
						c = styles.cca(position);
						HX_STACK_LINE(542)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::COMPONENT_OR_END_dyn();
						HX_STACK_LINE(543)
						continue;
					}
					else{
						HX_STACK_LINE(548)
						state = ::cocktail::core::css::parsers::StyleValueParserState_obj::INVALID_STYLE_VALUE_dyn();
						HX_STACK_LINE(549)
						continue;
					}
				}
				else if (5==_switch_3) {
					HX_STACK_LINE(556)
					if (((c == (int)59))){
						HX_STACK_LINE(561)
						::cocktail::core::css::parsers::CSSStyleParser_obj::_position = ++(position);
						HX_STACK_LINE(562)
						return null();
					}
				}
			}
		}
		HX_STACK_LINE(566)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(571)
	::cocktail::core::css::parsers::CSSStyleParser_obj::_position = position;
	HX_STACK_LINE(574)
	if (((fontNotations->length == (int)1))){
		HX_STACK_LINE(576)
		fontNotations->push(styleValues->pop());
		HX_STACK_LINE(577)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::FONT_SIZE_LINE_HEIGHT_GROUP(fontNotations->__get((int)0),fontNotations->__get((int)1)));
		HX_STACK_LINE(578)
		fontNotations = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();
	}
	HX_STACK_LINE(582)
	if (((styleValuesLists->length == (int)0))){
		HX_STACK_LINE(583)
		if (((styleValues->length == (int)1))){
			HX_STACK_LINE(587)
			::cocktail::core::css::TypedPropertyVO typedProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(typedProperty,"typedProperty");
			HX_STACK_LINE(588)
			typedProperty->important = important;
			HX_STACK_LINE(589)
			typedProperty->index = ::cocktail::core::css::CSSConstants_obj::getPropertyIndexFromName(propertyName);
			HX_STACK_LINE(590)
			typedProperty->typedValue = styleValues->__get((int)0);
			HX_STACK_LINE(591)
			return typedProperty;
		}
		else{
			HX_STACK_LINE(596)
			::cocktail::core::css::TypedPropertyVO typedProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(typedProperty,"typedProperty");
			HX_STACK_LINE(597)
			typedProperty->important = important;
			HX_STACK_LINE(598)
			typedProperty->index = ::cocktail::core::css::CSSConstants_obj::getPropertyIndexFromName(propertyName);
			HX_STACK_LINE(599)
			typedProperty->typedValue = ::cocktail::core::css::CSSPropertyValue_obj::GROUP(styleValues);
			HX_STACK_LINE(600)
			return typedProperty;
		}
	}
	else{
		HX_STACK_LINE(605)
		Array< ::cocktail::core::css::CSSPropertyValue > styleListProperty = Array_obj< ::cocktail::core::css::CSSPropertyValue >::__new();		HX_STACK_VAR(styleListProperty,"styleListProperty");
		HX_STACK_LINE(607)
		if (((styleValues->length > (int)0))){
			HX_STACK_LINE(608)
			styleValuesLists->push(styleValues);
		}
		HX_STACK_LINE(612)
		{
			HX_STACK_LINE(612)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = styleValuesLists->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(612)
			while(((_g1 < _g))){
				HX_STACK_LINE(612)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(614)
				if (((styleValuesLists->__get(i)->length == (int)1))){
					HX_STACK_LINE(615)
					styleListProperty->push(styleValuesLists->__get(i)->__get((int)0));
				}
				else{
					HX_STACK_LINE(619)
					styleListProperty->push(::cocktail::core::css::CSSPropertyValue_obj::GROUP(styleValuesLists->__get(i)));
				}
			}
		}
		HX_STACK_LINE(624)
		::cocktail::core::css::TypedPropertyVO typedProperty = ::cocktail::core::css::TypedPropertyVO_obj::__new();		HX_STACK_VAR(typedProperty,"typedProperty");
		HX_STACK_LINE(625)
		typedProperty->important = important;
		HX_STACK_LINE(626)
		typedProperty->index = ::cocktail::core::css::CSSConstants_obj::getPropertyIndexFromName(propertyName);
		HX_STACK_LINE(627)
		typedProperty->typedValue = ::cocktail::core::css::CSSPropertyValue_obj::CSS_LIST(styleListProperty);
		HX_STACK_LINE(629)
		return typedProperty;
	}
	HX_STACK_LINE(582)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSStyleParser_obj,parseStyleValue,return )

int CSSStyleParser_obj::parseImportant( ::String styles,int position){
	HX_STACK_PUSH("CSSStyleParser::parseImportant","cocktail/core/css/parsers/CSSStyleParser.hx",641);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_LINE(642)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(645)
	while(((c == (int)32))){
		HX_STACK_LINE(646)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(650)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(651)
	while(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
		HX_STACK_LINE(652)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(656)
	::String ident = styles.substr(start,(position - start));		HX_STACK_VAR(ident,"ident");
	HX_STACK_LINE(658)
	if (((ident == HX_CSTRING("important")))){
		HX_STACK_LINE(659)
		return position;
	}
	HX_STACK_LINE(663)
	return (int)-1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSStyleParser_obj,parseImportant,return )

int CSSStyleParser_obj::parseIntegerNumberDimensionOrPercentage( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseIntegerNumberDimensionOrPercentage","cocktail/core/css/parsers/CSSStyleParser.hx",673);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(674)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(675)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(678)
	if (((bool((c == (int)45)) || bool((c == (int)43))))){
		HX_STACK_LINE(679)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(685)
	bool isNumber = (c == (int)46);		HX_STACK_VAR(isNumber,"isNumber");
	HX_STACK_LINE(687)
	while(((bool((c >= (int)48)) && bool((c <= (int)57))))){
		HX_STACK_LINE(688)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(694)
	if (((bool((c == (int)0)) && bool((isNumber == false))))){
		HX_STACK_LINE(696)
		int integer = ::Std_obj::parseInt(styles.substr(start,(position - start)));		HX_STACK_VAR(integer,"integer");
		HX_STACK_LINE(697)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::INTEGER(integer));
		HX_STACK_LINE(698)
		return position;
	}
	HX_STACK_LINE(703)
	if (((c == (int)46))){
		HX_STACK_LINE(705)
		c = styles.cca(++(position));
		HX_STACK_LINE(706)
		isNumber = true;
		HX_STACK_LINE(708)
		while(((bool((c >= (int)48)) && bool((c <= (int)57))))){
			HX_STACK_LINE(709)
			c = styles.cca(++(position));
		}
	}
	HX_STACK_LINE(715)
	if (((c == (int)0))){
		HX_STACK_LINE(717)
		Float number = ::Std_obj::parseFloat(styles.substr(start,(position - start)));		HX_STACK_VAR(number,"number");
		HX_STACK_LINE(718)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::NUMBER(number));
		HX_STACK_LINE(719)
		return position;
	}
	HX_STACK_LINE(723)
	if (((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
		HX_STACK_LINE(725)
		Float numberOrInteger = ::Std_obj::parseFloat(styles.substr(start,(position - start)));		HX_STACK_VAR(numberOrInteger,"numberOrInteger");
		HX_STACK_LINE(726)
		position = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseDimension(numberOrInteger,styles,position,styleValues);
	}
	else{
		HX_STACK_LINE(729)
		switch( (int)(c)){
			case (int)37: {
				HX_STACK_LINE(735)
				Float numberOrInteger = ::Std_obj::parseFloat(styles.substr(start,(position - start)));		HX_STACK_VAR(numberOrInteger,"numberOrInteger");
				HX_STACK_LINE(736)
				styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::PERCENTAGE(numberOrInteger));
				HX_STACK_LINE(737)
				++(position);
			}
			;break;
			default: {
				HX_STACK_LINE(739)
				if ((isNumber)){
					HX_STACK_LINE(742)
					Float number = ::Std_obj::parseFloat(styles.substr(start,(position - start)));		HX_STACK_VAR(number,"number");
					HX_STACK_LINE(743)
					styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::NUMBER(number));
				}
				else{
					HX_STACK_LINE(747)
					int integer = ::Std_obj::parseInt(styles.substr(start,(position - start)));		HX_STACK_VAR(integer,"integer");
					HX_STACK_LINE(748)
					styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::INTEGER(integer));
				}
			}
		}
	}
	HX_STACK_LINE(754)
	return position;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSStyleParser_obj,parseIntegerNumberDimensionOrPercentage,return )

int CSSStyleParser_obj::parseDimension( Float numberOrInteger,::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseDimension","cocktail/core/css/parsers/CSSStyleParser.hx",761);
	HX_STACK_ARG(numberOrInteger,"numberOrInteger");
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(763)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(764)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(766)
	while(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
		HX_STACK_LINE(767)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(771)
	::String ident = styles.substr(start,(position - start));		HX_STACK_VAR(ident,"ident");
	HX_STACK_LINE(774)
	::String _switch_4 = (ident);
	if (  ( _switch_4==HX_CSTRING("px"))){
		HX_STACK_LINE(776)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::PX(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("em"))){
		HX_STACK_LINE(779)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::EM(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("ex"))){
		HX_STACK_LINE(782)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::EX(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("mm"))){
		HX_STACK_LINE(785)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::MM(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("in"))){
		HX_STACK_LINE(788)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::IN(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("cm"))){
		HX_STACK_LINE(791)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::CM(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("pc"))){
		HX_STACK_LINE(794)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::PC(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("pt"))){
		HX_STACK_LINE(797)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::LENGTH(::cocktail::core::css::CSSLengthValue_obj::PT(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("deg"))){
		HX_STACK_LINE(800)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::ANGLE(::cocktail::core::css::CSSAngleValue_obj::DEG(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("rad"))){
		HX_STACK_LINE(803)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::ANGLE(::cocktail::core::css::CSSAngleValue_obj::RAD(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("grad"))){
		HX_STACK_LINE(806)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::ANGLE(::cocktail::core::css::CSSAngleValue_obj::GRAD(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("turn"))){
		HX_STACK_LINE(809)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::ANGLE(::cocktail::core::css::CSSAngleValue_obj::TURN(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("s"))){
		HX_STACK_LINE(812)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::SECONDS(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("ms"))){
		HX_STACK_LINE(815)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::TIME(::cocktail::core::css::CSSTimeValue_obj::MILLISECONDS(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("Hz"))){
		HX_STACK_LINE(818)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::FREQUENCY(::cocktail::core::css::CSSFrequencyValue_obj::HERTZ(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("kHz"))){
		HX_STACK_LINE(821)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::FREQUENCY(::cocktail::core::css::CSSFrequencyValue_obj::KILO_HERTZ(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("dpi"))){
		HX_STACK_LINE(824)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::RESOLUTION(::cocktail::core::css::CSSResolutionValue_obj::DPI(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("dpcm"))){
		HX_STACK_LINE(827)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::RESOLUTION(::cocktail::core::css::CSSResolutionValue_obj::DPCM(numberOrInteger)));
	}
	else if (  ( _switch_4==HX_CSTRING("dppx"))){
		HX_STACK_LINE(830)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::RESOLUTION(::cocktail::core::css::CSSResolutionValue_obj::DPPX(numberOrInteger)));
	}
	else  {
		HX_STACK_LINE(835)
		return (int)-1;
	}
;
;
	HX_STACK_LINE(840)
	return position;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSStyleParser_obj,parseDimension,return )

int CSSStyleParser_obj::parseString( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseString","cocktail/core/css/parsers/CSSStyleParser.hx",844);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(845)
	int quote = styles.cca(position);		HX_STACK_VAR(quote,"quote");
	HX_STACK_LINE(847)
	int start = ++(position);		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(848)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(850)
	while(((c != quote))){
		HX_STACK_LINE(852)
		if (((c == (int)0))){
			HX_STACK_LINE(853)
			return (int)-1;
		}
		HX_STACK_LINE(856)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(859)
	::String stringValue = styles.substr(start,(position - start));		HX_STACK_VAR(stringValue,"stringValue");
	HX_STACK_LINE(861)
	styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::STRING(stringValue));
	HX_STACK_LINE(863)
	return ++(position);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSStyleParser_obj,parseString,return )

int CSSStyleParser_obj::parseIdentOrFunctionnalNotation( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseIdentOrFunctionnalNotation","cocktail/core/css/parsers/CSSStyleParser.hx",868);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(869)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(870)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(872)
	while(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45))))){
		HX_STACK_LINE(873)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(877)
	::String ident = styles.substr(start,(position - start));		HX_STACK_VAR(ident,"ident");
	HX_STACK_LINE(879)
	switch( (int)(c)){
		case (int)40: {
			HX_STACK_LINE(881)
			position = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseFunctionnalNotation(ident,styles,++(position),styleValues);
		}
		;break;
		default: {
			HX_STACK_LINE(884)
			::cocktail::core::css::parsers::CSSStyleParser_obj::parseIdent(ident,styleValues);
		}
	}
	HX_STACK_LINE(888)
	return position;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSStyleParser_obj,parseIdentOrFunctionnalNotation,return )

int CSSStyleParser_obj::parseHexaColor( ::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseHexaColor","cocktail/core/css/parsers/CSSStyleParser.hx",892);
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(893)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(894)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(896)
	while(((bool((bool((bool((c >= (int)97)) && bool((c <= (int)102)))) || bool((bool((c >= (int)65)) && bool((c <= (int)70)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57))))))){
		HX_STACK_LINE(897)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(901)
	::String hexa = styles.substr(start,(position - start));		HX_STACK_VAR(hexa,"hexa");
	HX_STACK_LINE(903)
	if (((bool((hexa.length == (int)3)) || bool((hexa.length == (int)6))))){
		HX_STACK_LINE(905)
		styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::HEX(hexa)));
		HX_STACK_LINE(906)
		return --(position);
	}
	HX_STACK_LINE(909)
	return (int)-1;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(CSSStyleParser_obj,parseHexaColor,return )

int CSSStyleParser_obj::parseFunctionnalNotation( ::String ident,::String styles,int position,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
	HX_STACK_PUSH("CSSStyleParser::parseFunctionnalNotation","cocktail/core/css/parsers/CSSStyleParser.hx",917);
	HX_STACK_ARG(ident,"ident");
	HX_STACK_ARG(styles,"styles");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(styleValues,"styleValues");
	HX_STACK_LINE(918)
	int c = styles.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(919)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(921)
	while(((c != (int)41))){
		HX_STACK_LINE(923)
		if (((c == (int)0))){
			HX_STACK_LINE(924)
			return (int)-1;
		}
		HX_STACK_LINE(927)
		c = styles.cca(++(position));
	}
	HX_STACK_LINE(932)
	::String cssFunction = styles.substr(start,(position - start));		HX_STACK_VAR(cssFunction,"cssFunction");
	HX_STACK_LINE(936)
	if (((ident == HX_CSTRING("url")))){
		HX_STACK_LINE(937)
		if (((bool((cssFunction.charAt((int)0) != HX_CSTRING("'"))) && bool((cssFunction.charAt((int)0) != HX_CSTRING("\"")))))){
			HX_STACK_LINE(939)
			cssFunction = ((HX_CSTRING("'") + cssFunction) + HX_CSTRING("'"));
		}
	}
	HX_STACK_LINE(945)
	::cocktail::core::css::TypedPropertyVO functionValues = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseStyleValue(HX_CSTRING(""),cssFunction,(int)0);		HX_STACK_VAR(functionValues,"functionValues");
	HX_STACK_LINE(947)
	::cocktail::core::css::CSSPropertyValue functionValue = ::cocktail::core::css::parsers::CSSStyleParser_obj::getFunctionalNotation(ident,functionValues->typedValue);		HX_STACK_VAR(functionValue,"functionValue");
	HX_STACK_LINE(949)
	if (((functionValue == null()))){
		HX_STACK_LINE(950)
		return (int)-1;
	}
	else{
		HX_STACK_LINE(955)
		styleValues->push(functionValue);
		HX_STACK_LINE(956)
		return ++(position);
	}
	HX_STACK_LINE(949)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(CSSStyleParser_obj,parseFunctionnalNotation,return )

::cocktail::core::css::CSSPropertyValue CSSStyleParser_obj::getFunctionalNotation( ::String name,::cocktail::core::css::CSSPropertyValue value){
	HX_STACK_PUSH("CSSStyleParser::getFunctionalNotation","cocktail/core/css/parsers/CSSStyleParser.hx",963);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(963)
	::String _switch_5 = (name);
	if (  ( _switch_5==HX_CSTRING("rgb"))){
		HX_STACK_LINE(966)
		return ::cocktail::core::css::parsers::CSSStyleParser_obj::parseRGBOrRGBA(value,false);
	}
	else if (  ( _switch_5==HX_CSTRING("rgba"))){
		HX_STACK_LINE(969)
		return ::cocktail::core::css::parsers::CSSStyleParser_obj::parseRGBOrRGBA(value,true);
	}
	else if (  ( _switch_5==HX_CSTRING("url"))){
		HX_STACK_LINE(972)
		{
			::cocktail::core::css::CSSPropertyValue _switch_6 = (value);
			switch((_switch_6)->GetIndex()){
				case 3: {
					::String value1 = _switch_6->__Param(0);
{
						HX_STACK_LINE(975)
						return ::cocktail::core::css::CSSPropertyValue_obj::URL(value1);
					}
				}
				;break;
				case 6: {
					::String value1 = _switch_6->__Param(0);
{
						HX_STACK_LINE(977)
						return ::cocktail::core::css::CSSPropertyValue_obj::URL(value1);
					}
				}
				;break;
				default: {
					HX_STACK_LINE(980)
					return null();
				}
			}
		}
	}
	else  {
		HX_STACK_LINE(984)
		return null();
	}
;
;
	HX_STACK_LINE(963)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSStyleParser_obj,getFunctionalNotation,return )

::cocktail::core::css::CSSPropertyValue CSSStyleParser_obj::parseRGBOrRGBA( ::cocktail::core::css::CSSPropertyValue property,bool isRGBA){
	HX_STACK_PUSH("CSSStyleParser::parseRGBOrRGBA","cocktail/core/css/parsers/CSSStyleParser.hx",990);
	HX_STACK_ARG(property,"property");
	HX_STACK_ARG(isRGBA,"isRGBA");
	HX_STACK_LINE(990)
	{
		::cocktail::core::css::CSSPropertyValue _switch_7 = (property);
		switch((_switch_7)->GetIndex()){
			case 15: {
				Array< ::cocktail::core::css::CSSPropertyValue > value = _switch_7->__Param(0);
{
					HX_STACK_LINE(995)
					if (((isRGBA == true))){
						HX_STACK_LINE(996)
						if (((value->length != (int)4))){
							HX_STACK_LINE(998)
							return null();
						}
					}
					else{
						HX_STACK_LINE(1003)
						if (((value->length != (int)3))){
							HX_STACK_LINE(1005)
							return null();
						}
					}
					HX_STACK_LINE(1011)
					bool isPercentRGB = false;		HX_STACK_VAR(isPercentRGB,"isPercentRGB");
					HX_STACK_LINE(1012)
					int red = (int)0;		HX_STACK_VAR(red,"red");
					HX_STACK_LINE(1013)
					int green = (int)0;		HX_STACK_VAR(green,"green");
					HX_STACK_LINE(1014)
					int blue = (int)0;		HX_STACK_VAR(blue,"blue");
					HX_STACK_LINE(1016)
					Float percentRed = 0.0;		HX_STACK_VAR(percentRed,"percentRed");
					HX_STACK_LINE(1017)
					Float percentGreen = 0.0;		HX_STACK_VAR(percentGreen,"percentGreen");
					HX_STACK_LINE(1018)
					Float percentBlue = 0.0;		HX_STACK_VAR(percentBlue,"percentBlue");
					HX_STACK_LINE(1020)
					{
						::cocktail::core::css::CSSPropertyValue _switch_8 = (value->__get((int)0));
						switch((_switch_8)->GetIndex()){
							case 0: {
								int value1 = _switch_8->__Param(0);
{
									HX_STACK_LINE(1022)
									red = value1;
								}
							}
							;break;
							case 2: {
								Float value1 = _switch_8->__Param(0);
{
									HX_STACK_LINE(1026)
									percentRed = value1;
									HX_STACK_LINE(1027)
									isPercentRGB = true;
								}
							}
							;break;
							default: {
								HX_STACK_LINE(1029)
								return null();
							}
						}
					}
					HX_STACK_LINE(1033)
					{
						::cocktail::core::css::CSSPropertyValue _switch_9 = (value->__get((int)1));
						switch((_switch_9)->GetIndex()){
							case 0: {
								int value1 = _switch_9->__Param(0);
{
									HX_STACK_LINE(1036)
									green = value1;
									HX_STACK_LINE(1037)
									if (((isPercentRGB == true))){
										HX_STACK_LINE(1038)
										return null();
									}
								}
							}
							;break;
							case 2: {
								Float value1 = _switch_9->__Param(0);
{
									HX_STACK_LINE(1043)
									percentGreen = value1;
									HX_STACK_LINE(1044)
									if (((isPercentRGB == false))){
										HX_STACK_LINE(1045)
										return null();
									}
								}
							}
							;break;
							default: {
								HX_STACK_LINE(1048)
								return null();
							}
						}
					}
					HX_STACK_LINE(1053)
					{
						::cocktail::core::css::CSSPropertyValue _switch_10 = (value->__get((int)2));
						switch((_switch_10)->GetIndex()){
							case 0: {
								int value1 = _switch_10->__Param(0);
{
									HX_STACK_LINE(1056)
									blue = value1;
									HX_STACK_LINE(1057)
									if (((isPercentRGB == true))){
										HX_STACK_LINE(1058)
										return null();
									}
								}
							}
							;break;
							case 2: {
								Float value1 = _switch_10->__Param(0);
{
									HX_STACK_LINE(1063)
									percentBlue = value1;
									HX_STACK_LINE(1064)
									if (((isPercentRGB == false))){
										HX_STACK_LINE(1065)
										return null();
									}
								}
							}
							;break;
							default: {
								HX_STACK_LINE(1068)
								return null();
							}
						}
					}
					HX_STACK_LINE(1072)
					if (((isRGBA == false))){
						HX_STACK_LINE(1073)
						if (((isPercentRGB == true))){
							HX_STACK_LINE(1075)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::RGB_PERCENTAGE(percentRed,percentGreen,percentBlue));
						}
						else{
							HX_STACK_LINE(1079)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::RGB(red,green,blue));
						}
					}
					else{
						HX_STACK_LINE(1085)
						Float alpha = 0.0;		HX_STACK_VAR(alpha,"alpha");
						HX_STACK_LINE(1087)
						{
							::cocktail::core::css::CSSPropertyValue _switch_11 = (value->__get((int)3));
							switch((_switch_11)->GetIndex()){
								case 1: {
									Float value1 = _switch_11->__Param(0);
{
										HX_STACK_LINE(1089)
										alpha = value1;
									}
								}
								;break;
								case 0: {
									int value1 = _switch_11->__Param(0);
{
										HX_STACK_LINE(1092)
										alpha = value1;
									}
								}
								;break;
								default: {
									HX_STACK_LINE(1095)
									return null();
								}
							}
						}
						HX_STACK_LINE(1099)
						if (((isPercentRGB == true))){
							HX_STACK_LINE(1100)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::RGBA_PERCENTAGE(percentRed,percentGreen,percentBlue,alpha));
						}
						else{
							HX_STACK_LINE(1104)
							return ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::RGBA(red,green,blue,alpha));
						}
					}
					HX_STACK_LINE(1110)
					return null();
				}
			}
			;break;
			default: {
				HX_STACK_LINE(1112)
				return null();
			}
		}
	}
	HX_STACK_LINE(990)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSStyleParser_obj,parseRGBOrRGBA,return )

Void CSSStyleParser_obj::parseIdent( ::String ident,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
{
		HX_STACK_PUSH("CSSStyleParser::parseIdent","cocktail/core/css/parsers/CSSStyleParser.hx",1121);
		HX_STACK_ARG(ident,"ident");
		HX_STACK_ARG(styleValues,"styleValues");
		HX_STACK_LINE(1123)
		ident = ident.toLowerCase();
		HX_STACK_LINE(1125)
		::String _switch_12 = (ident);
		if (  ( _switch_12==HX_CSTRING("inherit"))){
			HX_STACK_LINE(1127)
			styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::INHERIT_dyn());
		}
		else if (  ( _switch_12==HX_CSTRING("initial"))){
			HX_STACK_LINE(1130)
			styleValues->push(::cocktail::core::css::CSSPropertyValue_obj::INITIAL_dyn());
		}
		else  {
			HX_STACK_LINE(1133)
			::cocktail::core::css::parsers::CSSStyleParser_obj::parseKeyword(ident,styleValues);
		}
;
;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSStyleParser_obj,parseIdent,(void))

Void CSSStyleParser_obj::parseKeyword( ::String ident,Array< ::cocktail::core::css::CSSPropertyValue > styleValues){
{
		HX_STACK_PUSH("CSSStyleParser::parseKeyword","cocktail/core/css/parsers/CSSStyleParser.hx",1143);
		HX_STACK_ARG(ident,"ident");
		HX_STACK_ARG(styleValues,"styleValues");
		HX_STACK_LINE(1144)
		::cocktail::core::css::CSSPropertyValue cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(ident);		HX_STACK_VAR(cssPropertyValue,"cssPropertyValue");
		HX_STACK_LINE(1146)
		::String _switch_13 = (ident);
		if (  ( _switch_13==HX_CSTRING("normal"))){
			HX_STACK_LINE(1148)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NORMAL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("bold"))){
			HX_STACK_LINE(1151)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BOLD_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("bolder"))){
			HX_STACK_LINE(1154)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BOLDER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("lighter"))){
			HX_STACK_LINE(1157)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LIGHTER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("oblique"))){
			HX_STACK_LINE(1160)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::OBLIQUE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("italic"))){
			HX_STACK_LINE(1163)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ITALIC_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("small-caps"))){
			HX_STACK_LINE(1166)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SMALL_CAPS_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("pre"))){
			HX_STACK_LINE(1169)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PRE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("nowrap"))){
			HX_STACK_LINE(1172)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_WRAP_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("pre-wrap"))){
			HX_STACK_LINE(1175)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PRE_WRAP_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("pre-line"))){
			HX_STACK_LINE(1178)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PRE_LINE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("left"))){
			HX_STACK_LINE(1181)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LEFT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("right"))){
			HX_STACK_LINE(1184)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::RIGHT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("center"))){
			HX_STACK_LINE(1187)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CENTER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("justify"))){
			HX_STACK_LINE(1190)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::JUSTIFY_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("capitalize"))){
			HX_STACK_LINE(1193)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CAPITALIZE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("uppercase"))){
			HX_STACK_LINE(1196)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::UPPERCASE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("lowercase"))){
			HX_STACK_LINE(1199)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LOWERCASE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("none"))){
			HX_STACK_LINE(1202)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NONE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("baseline"))){
			HX_STACK_LINE(1205)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BASELINE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("sub"))){
			HX_STACK_LINE(1208)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SUB_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("super"))){
			HX_STACK_LINE(1211)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SUPER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("top"))){
			HX_STACK_LINE(1214)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::TOP_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("text-top"))){
			HX_STACK_LINE(1217)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::TEXT_TOP_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("middle"))){
			HX_STACK_LINE(1220)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MIDDLE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("bottom"))){
			HX_STACK_LINE(1223)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BOTTOM_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("text-bottom"))){
			HX_STACK_LINE(1226)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::TEXT_BOTTOM_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("auto"))){
			HX_STACK_LINE(1229)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::AUTO_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("block"))){
			HX_STACK_LINE(1232)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BLOCK_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("inline-block"))){
			HX_STACK_LINE(1235)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INLINE_BLOCK_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("inline"))){
			HX_STACK_LINE(1238)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INLINE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("both"))){
			HX_STACK_LINE(1241)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BOTH_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("static"))){
			HX_STACK_LINE(1244)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::STATIC_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("relative"))){
			HX_STACK_LINE(1247)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::RELATIVE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("absolute"))){
			HX_STACK_LINE(1250)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ABSOLUTE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("fixed"))){
			HX_STACK_LINE(1253)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::FIXED_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("visible"))){
			HX_STACK_LINE(1256)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::VISIBLE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("hidden"))){
			HX_STACK_LINE(1259)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::HIDDEN_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("scroll"))){
			HX_STACK_LINE(1262)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SCROLL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("border-box"))){
			HX_STACK_LINE(1265)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BORDER_BOX_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("padding-box"))){
			HX_STACK_LINE(1268)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::PADDING_BOX_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("content-box"))){
			HX_STACK_LINE(1271)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CONTENT_BOX_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("contain"))){
			HX_STACK_LINE(1274)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CONTAIN_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("cover"))){
			HX_STACK_LINE(1277)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::COVER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("crosshair"))){
			HX_STACK_LINE(1280)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::CROSSHAIR_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("default"))){
			HX_STACK_LINE(1283)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::DEFAULT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("pointer"))){
			HX_STACK_LINE(1286)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::POINTER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("text"))){
			HX_STACK_LINE(1289)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::TEXT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("all"))){
			HX_STACK_LINE(1292)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ALL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("ease"))){
			HX_STACK_LINE(1295)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("linear"))){
			HX_STACK_LINE(1298)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LINEAR_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("ease-in"))){
			HX_STACK_LINE(1301)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_IN_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("ease-out"))){
			HX_STACK_LINE(1304)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_OUT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("ease-in-out"))){
			HX_STACK_LINE(1307)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::EASE_IN_OUT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("step-start"))){
			HX_STACK_LINE(1310)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::STEP_START_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("step-end"))){
			HX_STACK_LINE(1313)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::STEP_END_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("start"))){
			HX_STACK_LINE(1316)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::START_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("end"))){
			HX_STACK_LINE(1319)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::END_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("x-small"))){
			HX_STACK_LINE(1322)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::X_SMALL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("xx-small"))){
			HX_STACK_LINE(1325)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::XX_SMALL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("x-large"))){
			HX_STACK_LINE(1328)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::X_LARGE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("xx-large"))){
			HX_STACK_LINE(1331)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::XX_LARGE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("medium"))){
			HX_STACK_LINE(1334)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::MEDIUM_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("smaller"))){
			HX_STACK_LINE(1337)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SMALLER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("larger"))){
			HX_STACK_LINE(1340)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LARGER_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("space"))){
			HX_STACK_LINE(1343)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SPACE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("round"))){
			HX_STACK_LINE(1346)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::ROUND_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("large"))){
			HX_STACK_LINE(1349)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LARGE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("small"))){
			HX_STACK_LINE(1352)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SMALL_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("repeat-x"))){
			HX_STACK_LINE(1355)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_X_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("repeat-y"))){
			HX_STACK_LINE(1358)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_Y_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("no-repeat"))){
			HX_STACK_LINE(1361)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::NO_REPEAT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("repeat"))){
			HX_STACK_LINE(1364)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::REPEAT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("thin"))){
			HX_STACK_LINE(1367)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::THIN_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("thick"))){
			HX_STACK_LINE(1370)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::THICK_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("dotted"))){
			HX_STACK_LINE(1373)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::DOTTED_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("dashed"))){
			HX_STACK_LINE(1376)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::DASHED_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("solid"))){
			HX_STACK_LINE(1379)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::SOLID_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("double"))){
			HX_STACK_LINE(1382)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::DOUBLE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("groove"))){
			HX_STACK_LINE(1385)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::GROOVE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("ridge"))){
			HX_STACK_LINE(1388)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::RIDGE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("inset"))){
			HX_STACK_LINE(1391)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INSET_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("outset"))){
			HX_STACK_LINE(1394)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::OUTSET_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("invert"))){
			HX_STACK_LINE(1397)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::INVERT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("underline"))){
			HX_STACK_LINE(1400)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::UNDERLINE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("overline"))){
			HX_STACK_LINE(1403)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::OVERLINE_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("line-through"))){
			HX_STACK_LINE(1406)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::LINE_THROUGH_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("blink"))){
			HX_STACK_LINE(1409)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::KEYWORD(::cocktail::core::css::CSSKeywordValue_obj::BLINK_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("transparent"))){
			HX_STACK_LINE(1412)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::TRANSPARENT_dyn());
		}
		else if (  ( _switch_13==HX_CSTRING("currentcolor"))){
			HX_STACK_LINE(1415)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::CURRENT_COLOR_dyn());
		}
		else  {
			HX_STACK_LINE(1418)
			cssPropertyValue = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseColorKeyword(ident);
		}
;
;
		HX_STACK_LINE(1424)
		if (((cssPropertyValue == null()))){
			HX_STACK_LINE(1425)
			cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::IDENTIFIER(ident);
		}
		HX_STACK_LINE(1429)
		styleValues->push(cssPropertyValue);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(CSSStyleParser_obj,parseKeyword,(void))

::cocktail::core::css::CSSPropertyValue CSSStyleParser_obj::parseColorKeyword( ::String ident){
	HX_STACK_PUSH("CSSStyleParser::parseColorKeyword","cocktail/core/css/parsers/CSSStyleParser.hx",1436);
	HX_STACK_ARG(ident,"ident");
	HX_STACK_LINE(1437)
	::cocktail::core::css::CSSPropertyValue cssPropertyValue = null();		HX_STACK_VAR(cssPropertyValue,"cssPropertyValue");
	HX_STACK_LINE(1439)
	::String _switch_14 = (ident);
	if (  ( _switch_14==HX_CSTRING("aliceblue"))){
		HX_STACK_LINE(1441)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ALICE_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("antiquewhite"))){
		HX_STACK_LINE(1444)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ANTIQUE_WHITE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("aqua"))){
		HX_STACK_LINE(1447)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::AQUA_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("aquamarine"))){
		HX_STACK_LINE(1450)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::AQUAMARINE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("azure"))){
		HX_STACK_LINE(1453)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::AZURE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("beige"))){
		HX_STACK_LINE(1456)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BEIGE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("bisque"))){
		HX_STACK_LINE(1459)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BISQUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("dimgray"))){
		HX_STACK_LINE(1463)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DIM_GRAY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("dimgrey"))){
		HX_STACK_LINE(1466)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DIM_GREY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("blue"))){
		HX_STACK_LINE(1469)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("black"))){
		HX_STACK_LINE(1472)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BLACK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("blanchedalmond"))){
		HX_STACK_LINE(1475)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BLANCHE_DALMOND_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("blueviolet"))){
		HX_STACK_LINE(1478)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BLUE_VIOLET_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("brown"))){
		HX_STACK_LINE(1481)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::BROWN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("burlywood"))){
		HX_STACK_LINE(1484)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ALICE_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("cadetblue"))){
		HX_STACK_LINE(1487)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CADET_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("chartreuse"))){
		HX_STACK_LINE(1490)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CHARTREUSE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("chocolate"))){
		HX_STACK_LINE(1493)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CHOCOLATE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("coral"))){
		HX_STACK_LINE(1496)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CORAL_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("cornflowerblue"))){
		HX_STACK_LINE(1499)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CORNFLOWER_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("cornsilk"))){
		HX_STACK_LINE(1502)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CORNSILK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("crimson"))){
		HX_STACK_LINE(1505)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CRIMSON_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("cyan"))){
		HX_STACK_LINE(1508)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::CYAN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkblue"))){
		HX_STACK_LINE(1511)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkgoldenrod"))){
		HX_STACK_LINE(1514)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_GOLDEN_ROD_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkgray"))){
		HX_STACK_LINE(1517)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_GRAY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkgreen"))){
		HX_STACK_LINE(1520)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkgrey"))){
		HX_STACK_LINE(1523)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_GREY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkkhaki"))){
		HX_STACK_LINE(1526)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_KHAKI_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkmagenta"))){
		HX_STACK_LINE(1529)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_MAGENTA_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkolivegreen"))){
		HX_STACK_LINE(1532)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_OLIVE_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkorange"))){
		HX_STACK_LINE(1535)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_ORANGE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkorchid"))){
		HX_STACK_LINE(1538)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_ORCHID_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkred"))){
		HX_STACK_LINE(1541)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_RED_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darksalmon"))){
		HX_STACK_LINE(1544)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_SALMON_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkseagreen"))){
		HX_STACK_LINE(1547)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_SEA_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkslateblue"))){
		HX_STACK_LINE(1550)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_SLATE_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkslategray"))){
		HX_STACK_LINE(1553)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_SLATE_GRAY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkslategrey"))){
		HX_STACK_LINE(1556)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_SLATE_GREY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkturquoise"))){
		HX_STACK_LINE(1559)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_TURQUOISE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("darkviolet"))){
		HX_STACK_LINE(1562)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DARK_VIOLET_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("deeppink"))){
		HX_STACK_LINE(1565)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DEEP_PINK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("deepskyblue"))){
		HX_STACK_LINE(1568)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DEEP_SKY_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("dodgerblue"))){
		HX_STACK_LINE(1571)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::DODGER_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("firebrick"))){
		HX_STACK_LINE(1574)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::FIRE_BRICK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("floralwhite"))){
		HX_STACK_LINE(1577)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::FLORAL_WHITE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("forestgreen"))){
		HX_STACK_LINE(1580)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::FOREST_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("gainsboro"))){
		HX_STACK_LINE(1583)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GAINSBORO_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("ghostwhite"))){
		HX_STACK_LINE(1586)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GHOST_WHITE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("gold"))){
		HX_STACK_LINE(1589)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GOLD_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("goldenrod"))){
		HX_STACK_LINE(1592)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GOLDEN_ROD_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("greenyellow"))){
		HX_STACK_LINE(1595)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GREEN_YELLOW_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("honeydew"))){
		HX_STACK_LINE(1598)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::HONEY_DEW_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("hotpink"))){
		HX_STACK_LINE(1601)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::HOT_PINK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("indianred"))){
		HX_STACK_LINE(1604)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::INDIAN_RED_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("indigo"))){
		HX_STACK_LINE(1607)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::INDIGO_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("ivory"))){
		HX_STACK_LINE(1610)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::IVORY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("khaki"))){
		HX_STACK_LINE(1613)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::KHAKI_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lavender"))){
		HX_STACK_LINE(1616)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LAVENDER_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lavenderblush"))){
		HX_STACK_LINE(1619)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LAVENDER_BLUSH_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lawngreen"))){
		HX_STACK_LINE(1622)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LAWN_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lemonchiffon"))){
		HX_STACK_LINE(1625)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LEMON_CHIFFON_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightblue"))){
		HX_STACK_LINE(1628)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightcoral"))){
		HX_STACK_LINE(1631)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_CORAL_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightcyan"))){
		HX_STACK_LINE(1634)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_CYAN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightgoldenrodyellow"))){
		HX_STACK_LINE(1637)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_GOLDENROD_YELLOW_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightgray"))){
		HX_STACK_LINE(1640)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_GRAY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightgrey"))){
		HX_STACK_LINE(1643)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_GREY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightgreen"))){
		HX_STACK_LINE(1646)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightpink"))){
		HX_STACK_LINE(1649)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_PINK_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightsalmon"))){
		HX_STACK_LINE(1652)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_SALMON_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightseagreen"))){
		HX_STACK_LINE(1655)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_SEA_GREEN_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightskyblue"))){
		HX_STACK_LINE(1658)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_SKY_BLUE_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightslategray"))){
		HX_STACK_LINE(1661)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_SLATE_GRAY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightslategrey"))){
		HX_STACK_LINE(1664)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_SLATE_GREY_dyn()));
	}
	else if (  ( _switch_14==HX_CSTRING("lightsteelblue"))){
		HX_STACK_LINE(1667)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_STEEL_BLUE_dyn()));
	}
	else  {
		HX_STACK_LINE(1670)
		cssPropertyValue = ::cocktail::core::css::parsers::CSSStyleParser_obj::parseColorKeyword2(ident);
	}
;
;
	HX_STACK_LINE(1674)
	return cssPropertyValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,parseColorKeyword,return )

::cocktail::core::css::CSSPropertyValue CSSStyleParser_obj::parseColorKeyword2( ::String ident){
	HX_STACK_PUSH("CSSStyleParser::parseColorKeyword2","cocktail/core/css/parsers/CSSStyleParser.hx",1683);
	HX_STACK_ARG(ident,"ident");
	HX_STACK_LINE(1684)
	::cocktail::core::css::CSSPropertyValue cssPropertyValue = null();		HX_STACK_VAR(cssPropertyValue,"cssPropertyValue");
	HX_STACK_LINE(1686)
	::String _switch_15 = (ident);
	if (  ( _switch_15==HX_CSTRING("lightyellow"))){
		HX_STACK_LINE(1688)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIGHT_YELLOW_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("limegreen"))){
		HX_STACK_LINE(1691)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIME_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("linen"))){
		HX_STACK_LINE(1694)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LINEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("magenta"))){
		HX_STACK_LINE(1697)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MAGENTA_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("marron"))){
		HX_STACK_LINE(1700)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MAROON_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumaquamarine"))){
		HX_STACK_LINE(1703)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_AQUAMARINE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumblue"))){
		HX_STACK_LINE(1706)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumorchid"))){
		HX_STACK_LINE(1709)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_ORCHID_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumpurple"))){
		HX_STACK_LINE(1712)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_PURPLE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumseagreen"))){
		HX_STACK_LINE(1715)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_SEA_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumslateblue"))){
		HX_STACK_LINE(1718)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_SLATE_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mediumspringgreen"))){
		HX_STACK_LINE(1721)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MEDIUM_SPRING_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mintcream"))){
		HX_STACK_LINE(1724)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MINT_CREAM_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("mistyrose"))){
		HX_STACK_LINE(1727)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MISTY_ROSE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("moccasin"))){
		HX_STACK_LINE(1730)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MOCCASIN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("navajowhite"))){
		HX_STACK_LINE(1733)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::NAVAJO_WHITE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("oldlace"))){
		HX_STACK_LINE(1736)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::OLD_LACE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("olivedrab"))){
		HX_STACK_LINE(1739)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::OLIVE_DRAB_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("orangered"))){
		HX_STACK_LINE(1742)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ORANGE_RED_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("orchid"))){
		HX_STACK_LINE(1745)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ORCHID_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("palegoldenrod"))){
		HX_STACK_LINE(1748)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PALE_GOLDEN_ROD_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("palegreen"))){
		HX_STACK_LINE(1751)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PALE_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("paleturquoise"))){
		HX_STACK_LINE(1754)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PALE_TURQUOISE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("palevioletred"))){
		HX_STACK_LINE(1757)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PALE_VIOLET_RED_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("papayawhip"))){
		HX_STACK_LINE(1760)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PAPAYA_WHIP_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("peachpuff"))){
		HX_STACK_LINE(1763)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PEACH_PUFF_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("peru"))){
		HX_STACK_LINE(1766)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PERU_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("pink"))){
		HX_STACK_LINE(1769)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PINK_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("plum"))){
		HX_STACK_LINE(1772)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PLUM_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("powderblue"))){
		HX_STACK_LINE(1775)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::POWDER_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("rosybrown"))){
		HX_STACK_LINE(1778)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ROSY_BROWN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("royalblue"))){
		HX_STACK_LINE(1781)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ROYAL_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("saddlebrown"))){
		HX_STACK_LINE(1784)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SADDLE_BROWN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("salmon"))){
		HX_STACK_LINE(1787)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SALMON_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("sandybrown"))){
		HX_STACK_LINE(1790)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SANDY_BROWN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("seagreen"))){
		HX_STACK_LINE(1793)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SEA_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("sienna"))){
		HX_STACK_LINE(1796)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SIENNA_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("skyblue"))){
		HX_STACK_LINE(1799)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SKY_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("slateblue"))){
		HX_STACK_LINE(1802)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SLATE_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("slategray"))){
		HX_STACK_LINE(1805)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SLATE_GRAY_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("slategrey"))){
		HX_STACK_LINE(1808)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SLATE_GREY_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("snow"))){
		HX_STACK_LINE(1811)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SNOW_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("springgreen"))){
		HX_STACK_LINE(1814)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SPRING_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("steelblue"))){
		HX_STACK_LINE(1817)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::STEEL_BLUE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("tan"))){
		HX_STACK_LINE(1820)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::TAN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("thisle"))){
		HX_STACK_LINE(1823)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::THISLE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("tomato"))){
		HX_STACK_LINE(1826)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::TOMATO_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("turquoise"))){
		HX_STACK_LINE(1829)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::TURQUOISE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("violet"))){
		HX_STACK_LINE(1832)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::VIOLET_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("wheat"))){
		HX_STACK_LINE(1835)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::WHEAT_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("whitesmoke"))){
		HX_STACK_LINE(1838)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::WHITE_SMOKE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("yellowgreen"))){
		HX_STACK_LINE(1841)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::YELLOW_GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("silver"))){
		HX_STACK_LINE(1844)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::SILVER_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("gray"))){
		HX_STACK_LINE(1847)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GRAY_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("grey"))){
		HX_STACK_LINE(1850)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GREY_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("white"))){
		HX_STACK_LINE(1853)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::WHITE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("maroon"))){
		HX_STACK_LINE(1856)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::MAROON_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("red"))){
		HX_STACK_LINE(1859)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::RED_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("purple"))){
		HX_STACK_LINE(1862)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::PURPLE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("fuchsia"))){
		HX_STACK_LINE(1865)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::FUCHSIA_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("green"))){
		HX_STACK_LINE(1868)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::GREEN_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("lime"))){
		HX_STACK_LINE(1871)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::LIME_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("olive"))){
		HX_STACK_LINE(1874)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::OLIVE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("yellow"))){
		HX_STACK_LINE(1877)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::YELLOW_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("navy"))){
		HX_STACK_LINE(1880)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::NAVY_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("orange"))){
		HX_STACK_LINE(1883)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::ORANGE_dyn()));
	}
	else if (  ( _switch_15==HX_CSTRING("teal"))){
		HX_STACK_LINE(1886)
		cssPropertyValue = ::cocktail::core::css::CSSPropertyValue_obj::COLOR(::cocktail::core::css::CSSColorValue_obj::KEYWORD(::cocktail::core::css::CSSColorKeyword_obj::TEAL_dyn()));
	}
	HX_STACK_LINE(1890)
	return cssPropertyValue;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,parseColorKeyword2,return )

bool CSSStyleParser_obj::isHexaChar( int c){
	HX_STACK_PUSH("CSSStyleParser::isHexaChar","cocktail/core/css/parsers/CSSStyleParser.hx",1897);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(1897)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)102)))) || bool((bool((c >= (int)65)) && bool((c <= (int)70)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,isHexaChar,return )

bool CSSStyleParser_obj::isIdentChar( int c){
	HX_STACK_PUSH("CSSStyleParser::isIdentChar","cocktail/core/css/parsers/CSSStyleParser.hx",1901);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(1901)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((c == (int)45)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,isIdentChar,return )

bool CSSStyleParser_obj::isNumChar( int c){
	HX_STACK_PUSH("CSSStyleParser::isNumChar","cocktail/core/css/parsers/CSSStyleParser.hx",1905);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(1905)
	return (bool((c >= (int)48)) && bool((c <= (int)57)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleParser_obj,isNumChar,return )


CSSStyleParser_obj::CSSStyleParser_obj()
{
}

void CSSStyleParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSStyleParser);
	HX_MARK_END_CLASS();
}

void CSSStyleParser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CSSStyleParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { return _position; }
		if (HX_FIELD_EQ(inName,"isNumChar") ) { return isNumChar_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parseStyle") ) { return parseStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"parseIdent") ) { return parseIdent_dyn(); }
		if (HX_FIELD_EQ(inName,"isHexaChar") ) { return isHexaChar_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"parseString") ) { return parseString_dyn(); }
		if (HX_FIELD_EQ(inName,"isIdentChar") ) { return isIdentChar_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"parseKeyword") ) { return parseKeyword_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"parseImportant") ) { return parseImportant_dyn(); }
		if (HX_FIELD_EQ(inName,"parseDimension") ) { return parseDimension_dyn(); }
		if (HX_FIELD_EQ(inName,"parseHexaColor") ) { return parseHexaColor_dyn(); }
		if (HX_FIELD_EQ(inName,"parseRGBOrRGBA") ) { return parseRGBOrRGBA_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"parseStyleValue") ) { return parseStyleValue_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_typedProperties") ) { return _typedProperties; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"parseColorKeyword") ) { return parseColorKeyword_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"parseColorKeyword2") ) { return parseColorKeyword2_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getFunctionalNotation") ) { return getFunctionalNotation_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"parseFunctionnalNotation") ) { return parseFunctionnalNotation_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"parseIdentOrFunctionnalNotation") ) { return parseIdentOrFunctionnalNotation_dyn(); }
		break;
	case 39:
		if (HX_FIELD_EQ(inName,"parseIntegerNumberDimensionOrPercentage") ) { return parseIntegerNumberDimensionOrPercentage_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSStyleParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"_position") ) { _position=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_typedProperties") ) { _typedProperties=inValue.Cast< Array< ::cocktail::core::css::TypedPropertyVO > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSStyleParser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("_position"),
	HX_CSTRING("_typedProperties"),
	HX_CSTRING("parseStyle"),
	HX_CSTRING("parseStyleValue"),
	HX_CSTRING("parseImportant"),
	HX_CSTRING("parseIntegerNumberDimensionOrPercentage"),
	HX_CSTRING("parseDimension"),
	HX_CSTRING("parseString"),
	HX_CSTRING("parseIdentOrFunctionnalNotation"),
	HX_CSTRING("parseHexaColor"),
	HX_CSTRING("parseFunctionnalNotation"),
	HX_CSTRING("getFunctionalNotation"),
	HX_CSTRING("parseRGBOrRGBA"),
	HX_CSTRING("parseIdent"),
	HX_CSTRING("parseKeyword"),
	HX_CSTRING("parseColorKeyword"),
	HX_CSTRING("parseColorKeyword2"),
	HX_CSTRING("isHexaChar"),
	HX_CSTRING("isIdentChar"),
	HX_CSTRING("isNumChar"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSStyleParser_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(CSSStyleParser_obj::_position,"_position");
	HX_MARK_MEMBER_NAME(CSSStyleParser_obj::_typedProperties,"_typedProperties");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSStyleParser_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CSSStyleParser_obj::_position,"_position");
	HX_VISIT_MEMBER_NAME(CSSStyleParser_obj::_typedProperties,"_typedProperties");
};

Class CSSStyleParser_obj::__mClass;

void CSSStyleParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.CSSStyleParser"), hx::TCanCast< CSSStyleParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSStyleParser_obj::__boot()
{
	_position= (int)0;
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
