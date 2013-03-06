#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#include <cocktail/core/css/AttributeSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#include <cocktail/core/css/CombinatorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#include <cocktail/core/css/LinkPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#include <cocktail/core/css/SelectorComponentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#include <cocktail/core/css/UIElementStatesValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_AttributeSelectorParserState
#include <cocktail/core/css/parsers/AttributeSelectorParserState.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSSelectorParser
#include <cocktail/core/css/parsers/CSSSelectorParser.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_SelectorParserState
#include <cocktail/core/css/parsers/SelectorParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

Void CSSSelectorParser_obj::__construct()
{
HX_STACK_PUSH("CSSSelectorParser::new","cocktail/core/css/parsers/CSSSelectorParser.hx",26);
{
}
;
	return null();
}

CSSSelectorParser_obj::~CSSSelectorParser_obj() { }

Dynamic CSSSelectorParser_obj::__CreateEmpty() { return  new CSSSelectorParser_obj; }
hx::ObjectPtr< CSSSelectorParser_obj > CSSSelectorParser_obj::__new()
{  hx::ObjectPtr< CSSSelectorParser_obj > result = new CSSSelectorParser_obj();
	result->__construct();
	return result;}

Dynamic CSSSelectorParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSSelectorParser_obj > result = new CSSSelectorParser_obj();
	result->__construct();
	return result;}

::String CSSSelectorParser_obj::getFirstType( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getFirstType","cocktail/core/css/parsers/CSSSelectorParser.hx",802);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(803)
	{
		::cocktail::core::css::SelectorComponentValue _switch_1 = (components->__get((int)0));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_1->__Param(0);
{
					HX_STACK_LINE(805)
					{
						::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_2 = (value->startValue);
						switch((_switch_2)->GetIndex()){
							case 1: {
								::String value1 = _switch_2->__Param(0);
{
									HX_STACK_LINE(808)
									return value1;
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
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_1->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(817)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstType,return )

::String CSSSelectorParser_obj::getFirstId( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getFirstId","cocktail/core/css/parsers/CSSSelectorParser.hx",770);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(771)
	{
		::cocktail::core::css::SelectorComponentValue _switch_3 = (components->__get((int)0));
		switch((_switch_3)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_3->__Param(0);
{
					HX_STACK_LINE(773)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(776)
						if (((value->simpleSelectors->length != (int)0))){
							HX_STACK_LINE(779)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_4 = (value->simpleSelectors->__get((int)0));
								switch((_switch_4)->GetIndex()){
									case 3: {
										::String value1 = _switch_4->__Param(0);
{
											HX_STACK_LINE(783)
											return value1;
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
			}
			;break;
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_3->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(794)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstId,return )

bool CSSSelectorParser_obj::getIsSimpleTypeSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleTypeSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",739);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(740)
	if (((components->length > (int)1))){
		HX_STACK_LINE(741)
		return false;
	}
	HX_STACK_LINE(745)
	{
		::cocktail::core::css::SelectorComponentValue _switch_5 = (components->__get((int)0));
		switch((_switch_5)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_5->__Param(0);
{
					HX_STACK_LINE(747)
					{
						::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_6 = (value->startValue);
						switch((_switch_6)->GetIndex()){
							case 1: {
								::String typeValue = _switch_6->__Param(0);
{
									HX_STACK_LINE(750)
									if (((value->simpleSelectors->length == (int)0))){
										HX_STACK_LINE(752)
										return true;
									}
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
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_5->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(762)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleTypeSelector,return )

bool CSSSelectorParser_obj::getIsSimpleIdSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleIdSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",706);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(707)
	if (((components->length > (int)1))){
		HX_STACK_LINE(708)
		return false;
	}
	HX_STACK_LINE(712)
	{
		::cocktail::core::css::SelectorComponentValue _switch_7 = (components->__get((int)0));
		switch((_switch_7)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_7->__Param(0);
{
					HX_STACK_LINE(714)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(717)
						if (((value->simpleSelectors->length == (int)1))){
							HX_STACK_LINE(719)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_8 = (value->simpleSelectors->__get((int)0));
								switch((_switch_8)->GetIndex()){
									case 3: {
										::String value1 = _switch_8->__Param(0);
{
											HX_STACK_LINE(722)
											return true;
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
			}
			;break;
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_7->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(732)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleIdSelector,return )

bool CSSSelectorParser_obj::getIsSimpleClassSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleClassSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",670);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(672)
	if (((components->length > (int)1))){
		HX_STACK_LINE(673)
		return false;
	}
	HX_STACK_LINE(677)
	{
		::cocktail::core::css::SelectorComponentValue _switch_9 = (components->__get((int)0));
		switch((_switch_9)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_9->__Param(0);
{
					HX_STACK_LINE(679)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(682)
						if (((value->simpleSelectors->length == (int)1))){
							HX_STACK_LINE(685)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_10 = (value->simpleSelectors->__get((int)0));
								switch((_switch_10)->GetIndex()){
									case 2: {
										::String value1 = _switch_10->__Param(0);
{
											HX_STACK_LINE(689)
											return true;
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
			}
			;break;
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_9->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(699)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleClassSelector,return )

::String CSSSelectorParser_obj::getFirstClass( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getFirstClass","cocktail/core/css/parsers/CSSSelectorParser.hx",639);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(640)
	{
		::cocktail::core::css::SelectorComponentValue _switch_11 = (components->__get((int)0));
		switch((_switch_11)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_11->__Param(0);
{
					HX_STACK_LINE(642)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(645)
						if (((value->simpleSelectors->length != (int)0))){
							HX_STACK_LINE(648)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_12 = (value->simpleSelectors->__get((int)0));
								switch((_switch_12)->GetIndex()){
									case 2: {
										::String value1 = _switch_12->__Param(0);
{
											HX_STACK_LINE(652)
											return value1;
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
			}
			;break;
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_11->__Param(0);
{
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(663)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstClass,return )

int CSSSelectorParser_obj::parseAttributeSelector( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues){
	HX_STACK_PUSH("CSSSelectorParser::parseAttributeSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",473);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
	HX_STACK_LINE(474)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(475)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(477)
	::String attribute = null();		HX_STACK_VAR(attribute,"attribute");
	HX_STACK_LINE(478)
	::String _operator = null();		HX_STACK_VAR(_operator,"operator");
	HX_STACK_LINE(479)
	::String value = null();		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(481)
	::cocktail::core::css::parsers::AttributeSelectorParserState state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(482)
	::cocktail::core::css::parsers::AttributeSelectorParserState next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::ATTRIBUTE_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(484)
	while((true)){
		HX_STACK_LINE(486)
		{
			::cocktail::core::css::parsers::AttributeSelectorParserState _switch_13 = (state);
			int _switch_14 = (_switch_13)->GetIndex();{
				if (0==_switch_14) {
					HX_STACK_LINE(488)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(497)
							state = next;
							HX_STACK_LINE(498)
							continue;
						}
					}
				}
				else if (2==_switch_14) {
					HX_STACK_LINE(501)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(504)
						attribute = selector.substr(start,(position - start));
						HX_STACK_LINE(506)
						if (((c == (int)93))){
							HX_STACK_LINE(507)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
						}
						else{
							HX_STACK_LINE(512)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();
							HX_STACK_LINE(513)
							next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::BEGIN_OPERATOR_dyn();
							HX_STACK_LINE(514)
							continue;
						}
					}
				}
				else if (3==_switch_14) {
					HX_STACK_LINE(519)
					start = position;
					HX_STACK_LINE(520)
					state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::OPERATOR_dyn();
				}
				else if (4==_switch_14) {
					HX_STACK_LINE(522)
					if ((!(((bool((bool((bool((bool((bool((c == (int)61)) || bool((c == (int)126)))) || bool((c == (int)94)))) || bool((c == (int)36)))) || bool((c == (int)42)))) || bool((c == (int)124))))))){
						HX_STACK_LINE(525)
						_operator = selector.substr(start,(position - start));
						HX_STACK_LINE(526)
						state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(527)
						next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_OPERATOR_dyn();
						HX_STACK_LINE(528)
						continue;
					}
				}
				else if (1==_switch_14) {
					HX_STACK_LINE(531)
					switch( (int)(c)){
						case (int)34: case (int)39: {
							HX_STACK_LINE(535)
							(position)++;
							HX_STACK_LINE(536)
							start = position;
							HX_STACK_LINE(537)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::STRING_VALUE_dyn();
						}
						;break;
						case (int)93: {
							HX_STACK_LINE(539)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
						}
						;break;
						default: {
							HX_STACK_LINE(542)
							if (((((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95)))) == true))){
								HX_STACK_LINE(546)
								start = position;
								HX_STACK_LINE(547)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IDENTIFIER_VALUE_dyn();
							}
							else{
								HX_STACK_LINE(550)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (6==_switch_14) {
					HX_STACK_LINE(555)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(557)
						switch( (int)(c)){
							case (int)34: case (int)39: {
								HX_STACK_LINE(561)
								value = selector.substr(start,(position - start));
								HX_STACK_LINE(562)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
							}
							;break;
							case (int)93: {
								HX_STACK_LINE(564)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
							;break;
							default: {
								HX_STACK_LINE(567)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (5==_switch_14) {
					HX_STACK_LINE(572)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(574)
						switch( (int)(c)){
							case (int)93: {
								HX_STACK_LINE(578)
								value = selector.substr(start,(position - start));
								HX_STACK_LINE(579)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
							}
							;break;
							default: {
								HX_STACK_LINE(581)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (8==_switch_14) {
					HX_STACK_LINE(586)
					break;
				}
				else if (7==_switch_14) {
					HX_STACK_LINE(589)
					break;
				}
			}
		}
		HX_STACK_LINE(593)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(596)
	if (((attribute != null()))){
		HX_STACK_LINE(597)
		if (((_operator != null()))){
			HX_STACK_LINE(599)
			::String _switch_15 = (_operator);
			if (  ( _switch_15==HX_CSTRING("="))){
				HX_STACK_LINE(602)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("^="))){
				HX_STACK_LINE(605)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("~="))){
				HX_STACK_LINE(608)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_LIST(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("$="))){
				HX_STACK_LINE(611)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_ENDS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("*="))){
				HX_STACK_LINE(614)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_CONTAINS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("|="))){
				HX_STACK_LINE(617)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(attribute,value)));
			}
		}
		else{
			HX_STACK_LINE(622)
			simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE(attribute)));
		}
	}
	HX_STACK_LINE(627)
	return position;
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parseAttributeSelector,return )

int CSSSelectorParser_obj::parsePseudoElement( ::String selector,int position,::cocktail::core::css::SelectorVO selectorData){
	HX_STACK_PUSH("CSSSelectorParser::parsePseudoElement","cocktail/core/css/parsers/CSSSelectorParser.hx",435);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(selectorData,"selectorData");
	HX_STACK_LINE(436)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(437)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(439)
	while((true)){
		HX_STACK_LINE(441)
		if ((!(((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45))))))){
			HX_STACK_LINE(442)
			break;
		}
		HX_STACK_LINE(445)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(448)
	::String pseudoElement = selector.substr(start,(position - start));		HX_STACK_VAR(pseudoElement,"pseudoElement");
	HX_STACK_LINE(449)
	::cocktail::core::css::PseudoElementSelectorValue typedPseudoElement = null();		HX_STACK_VAR(typedPseudoElement,"typedPseudoElement");
	HX_STACK_LINE(451)
	::String _switch_16 = (pseudoElement);
	if (  ( _switch_16==HX_CSTRING("first-line"))){
		HX_STACK_LINE(453)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::FIRST_LINE_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("first-letter"))){
		HX_STACK_LINE(456)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::FIRST_LETTER_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("before"))){
		HX_STACK_LINE(459)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::BEFORE_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("after"))){
		HX_STACK_LINE(462)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::AFTER_dyn();
	}
	HX_STACK_LINE(467)
	selectorData->pseudoElement = typedPseudoElement;
	HX_STACK_LINE(469)
	return --(position);
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parsePseudoElement,return )

int CSSSelectorParser_obj::parsePseudoClass( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues){
	HX_STACK_PUSH("CSSSelectorParser::parsePseudoClass","cocktail/core/css/parsers/CSSSelectorParser.hx",339);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
	HX_STACK_LINE(340)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(341)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(343)
	while((true)){
		HX_STACK_LINE(345)
		if ((!(((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45))))))){
			HX_STACK_LINE(346)
			break;
		}
		HX_STACK_LINE(349)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(352)
	::String pseudoClass = selector.substr(start,(position - start));		HX_STACK_VAR(pseudoClass,"pseudoClass");
	HX_STACK_LINE(354)
	::cocktail::core::css::PseudoClassSelectorValue typedPseudoClass = null();		HX_STACK_VAR(typedPseudoClass,"typedPseudoClass");
	HX_STACK_LINE(356)
	::String _switch_17 = (pseudoClass);
	if (  ( _switch_17==HX_CSTRING("first-child"))){
		HX_STACK_LINE(358)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::FIRST_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("last-child"))){
		HX_STACK_LINE(361)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::LAST_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("empty"))){
		HX_STACK_LINE(364)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::EMPTY_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("root"))){
		HX_STACK_LINE(367)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ROOT_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("first-of-type"))){
		HX_STACK_LINE(370)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::FIRST_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("last-of-type"))){
		HX_STACK_LINE(373)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::LAST_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("only-of-type"))){
		HX_STACK_LINE(376)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ONLY_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("only-child"))){
		HX_STACK_LINE(379)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ONLY_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("link"))){
		HX_STACK_LINE(382)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::LINK(::cocktail::core::css::LinkPseudoClassValue_obj::LINK_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("visited"))){
		HX_STACK_LINE(385)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::LINK(::cocktail::core::css::LinkPseudoClassValue_obj::VISITED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("active"))){
		HX_STACK_LINE(388)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::ACTIVE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("hover"))){
		HX_STACK_LINE(391)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::HOVER_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("focus"))){
		HX_STACK_LINE(394)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::FOCUS_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("target"))){
		HX_STACK_LINE(397)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::TARGET_dyn();
	}
	else if (  ( _switch_17==HX_CSTRING("nth-child"))){
	}
	else if (  ( _switch_17==HX_CSTRING("nth-last-child"))){
	}
	else if (  ( _switch_17==HX_CSTRING("nth-of-type"))){
	}
	else if (  ( _switch_17==HX_CSTRING("nth-last-of-type"))){
	}
	else if (  ( _switch_17==HX_CSTRING("not"))){
	}
	else if (  ( _switch_17==HX_CSTRING("lang"))){
	}
	else if (  ( _switch_17==HX_CSTRING("enabled"))){
		HX_STACK_LINE(418)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::ENABLED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("disabled"))){
		HX_STACK_LINE(421)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::DISABLED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("checked"))){
		HX_STACK_LINE(424)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::CHECKED_dyn());
	}
	HX_STACK_LINE(429)
	simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::PSEUDO_CLASS(typedPseudoClass));
	HX_STACK_LINE(431)
	return --(position);
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parsePseudoClass,return )

Void CSSSelectorParser_obj::flushSelectors( ::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStartValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues,Array< ::cocktail::core::css::SelectorComponentValue > components){
{
		HX_STACK_PUSH("CSSSelectorParser::flushSelectors","cocktail/core/css/parsers/CSSSelectorParser.hx",321);
		HX_STACK_THIS(this);
		HX_STACK_ARG(simpleSelectorSequenceStartValue,"simpleSelectorSequenceStartValue");
		HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
		HX_STACK_ARG(components,"components");
		HX_STACK_LINE(322)
		if (((bool((simpleSelectorSequenceStartValue == null())) && bool((simpleSelectorSequenceItemValues->length == (int)0))))){
			HX_STACK_LINE(323)
			return null();
		}
		HX_STACK_LINE(327)
		if (((simpleSelectorSequenceStartValue == null()))){
			HX_STACK_LINE(328)
			simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
		}
		HX_STACK_LINE(332)
		::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence = ::cocktail::core::css::SimpleSelectorSequenceVO_obj::__new(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues);		HX_STACK_VAR(simpleSelectorSequence,"simpleSelectorSequence");
		HX_STACK_LINE(333)
		components->push(::cocktail::core::css::SelectorComponentValue_obj::SIMPLE_SELECTOR_SEQUENCE(simpleSelectorSequence));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,flushSelectors,(void))

Void CSSSelectorParser_obj::parseSelector( ::String selector,Array< ::cocktail::core::css::SelectorVO > typedSelectors){
{
		HX_STACK_PUSH("CSSSelectorParser::parseSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(selector,"selector");
		HX_STACK_ARG(typedSelectors,"typedSelectors");
		HX_STACK_LINE(41)
		::cocktail::core::css::parsers::SelectorParserState state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
		HX_STACK_LINE(42)
		::cocktail::core::css::parsers::SelectorParserState next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(43)
		int start = (int)0;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(44)
		int position = (int)0;		HX_STACK_VAR(position,"position");
		HX_STACK_LINE(45)
		int c = selector.cca(position);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(47)
		::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStartValue = null();		HX_STACK_VAR(simpleSelectorSequenceStartValue,"simpleSelectorSequenceStartValue");
		HX_STACK_LINE(48)
		Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues = Array_obj< ::cocktail::core::css::SimpleSelectorSequenceItemValue >::__new();		HX_STACK_VAR(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
		HX_STACK_LINE(49)
		Array< ::cocktail::core::css::SelectorComponentValue > components = Array_obj< ::cocktail::core::css::SelectorComponentValue >::__new();		HX_STACK_VAR(components,"components");
		HX_STACK_LINE(51)
		::cocktail::core::css::SelectorVO selectorData = ::cocktail::core::css::SelectorVO_obj::__new(components,::cocktail::core::css::PseudoElementSelectorValue_obj::NONE_dyn(),false,null(),false,null(),false,null(),false,false,false);		HX_STACK_VAR(selectorData,"selectorData");
		HX_STACK_LINE(54)
		while((!(((c == (int)0))))){
			HX_STACK_LINE(56)
			{
				::cocktail::core::css::parsers::SelectorParserState _switch_18 = (state);
				switch((_switch_18)->GetIndex()){
					case 0: {
						HX_STACK_LINE(58)
						switch( (int)(c)){
							case (int)10: case (int)13: case (int)9: case (int)32: {
							}
							;break;
							default: {
								HX_STACK_LINE(67)
								state = next;
								HX_STACK_LINE(68)
								continue;
							}
						}
					}
					;break;
					case 1: {
						HX_STACK_LINE(71)
						if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
							HX_STACK_LINE(74)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
							HX_STACK_LINE(75)
							next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_TYPE_SELECTOR_dyn();
							HX_STACK_LINE(76)
							start = position;
						}
						else{
							HX_STACK_LINE(79)
							switch( (int)(c)){
								case (int)46: {
									HX_STACK_LINE(84)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(85)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_CLASS_SELECTOR_dyn();
									HX_STACK_LINE(86)
									start = (position + (int)1);
								}
								;break;
								case (int)35: {
									HX_STACK_LINE(89)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(90)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_ID_SELECTOR_dyn();
									HX_STACK_LINE(91)
									start = (position + (int)1);
								}
								;break;
								case (int)42: {
									HX_STACK_LINE(94)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(95)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_UNIVERSAL_SELECTOR_dyn();
									HX_STACK_LINE(96)
									start = position;
								}
								;break;
								case (int)58: {
									HX_STACK_LINE(99)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_PSEUDO_SELECTOR_dyn();
									HX_STACK_LINE(100)
									start = position;
								}
								;break;
								case (int)91: {
									HX_STACK_LINE(103)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_ATTRIBUTE_SELECTOR_dyn();
									HX_STACK_LINE(104)
									start = position;
								}
								;break;
								default: {
									HX_STACK_LINE(107)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
									HX_STACK_LINE(108)
									continue;
								}
							}
						}
					}
					;break;
					case 12: {
						HX_STACK_LINE(114)
						position = this->parseAttributeSelector(selector,position,simpleSelectorSequenceItemValues);
						HX_STACK_LINE(115)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(116)
						next = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
					}
					;break;
					case 9: {
						HX_STACK_LINE(118)
						if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
							HX_STACK_LINE(121)
							position = this->parsePseudoClass(selector,position,simpleSelectorSequenceItemValues);
							HX_STACK_LINE(122)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
							HX_STACK_LINE(123)
							next = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
						}
						else{
							HX_STACK_LINE(126)
							switch( (int)(c)){
								case (int)58: {
									HX_STACK_LINE(129)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::PSEUDO_ELEMENT_SELECTOR_dyn();
								}
								;break;
								default: {
									HX_STACK_LINE(133)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
									HX_STACK_LINE(134)
									continue;
								}
							}
						}
					}
					;break;
					case 11: {
						HX_STACK_LINE(139)
						position = this->parsePseudoElement(selector,position,selectorData);
						HX_STACK_LINE(140)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(141)
						next = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
					}
					;break;
					case 2: {
						HX_STACK_LINE(143)
						switch( (int)(c)){
							case (int)32: case (int)10: case (int)13: case (int)62: {
								HX_STACK_LINE(147)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_COMBINATOR_dyn();
								HX_STACK_LINE(148)
								continue;
							}
							;break;
							case (int)58: case (int)35: case (int)46: case (int)91: {
								HX_STACK_LINE(151)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(152)
								continue;
							}
							;break;
							default: {
								HX_STACK_LINE(155)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
								HX_STACK_LINE(156)
								continue;
							}
						}
					}
					;break;
					case 3: {
						HX_STACK_LINE(159)
						if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
							HX_STACK_LINE(161)
							switch( (int)(c)){
								case (int)32: case (int)10: case (int)13: case (int)62: case (int)58: case (int)35: case (int)46: case (int)91: {
									HX_STACK_LINE(165)
									state = next;
									HX_STACK_LINE(166)
									continue;
								}
								;break;
								default: {
									HX_STACK_LINE(169)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
									HX_STACK_LINE(170)
									continue;
								}
							}
						}
					}
					;break;
					case 4: {
						HX_STACK_LINE(175)
						::String type = selector.substr(start,(position - start));		HX_STACK_VAR(type,"type");
						HX_STACK_LINE(176)
						simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::TYPE(type.toUpperCase());
						HX_STACK_LINE(177)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(178)
						continue;
					}
					;break;
					case 5: {
						HX_STACK_LINE(181)
						::String className = selector.substr(start,(position - start));		HX_STACK_VAR(className,"className");
						HX_STACK_LINE(182)
						simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::CSS_CLASS(className));
						HX_STACK_LINE(183)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(184)
						continue;
					}
					;break;
					case 6: {
						HX_STACK_LINE(187)
						::String id = selector.substr(start,(position - start));		HX_STACK_VAR(id,"id");
						HX_STACK_LINE(188)
						simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ID(id));
						HX_STACK_LINE(189)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(190)
						continue;
					}
					;break;
					case 10: {
						HX_STACK_LINE(193)
						simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
						HX_STACK_LINE(194)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(195)
						continue;
					}
					;break;
					case 7: {
						HX_STACK_LINE(199)
						this->flushSelectors(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues,components);
						HX_STACK_LINE(201)
						simpleSelectorSequenceStartValue = null();
						HX_STACK_LINE(202)
						simpleSelectorSequenceItemValues = Array_obj< ::cocktail::core::css::SimpleSelectorSequenceItemValue >::__new();
						HX_STACK_LINE(204)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(205)
						next = ::cocktail::core::css::parsers::SelectorParserState_obj::COMBINATOR_dyn();
						HX_STACK_LINE(206)
						continue;
					}
					;break;
					case 8: {
						HX_STACK_LINE(208)
						if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
							HX_STACK_LINE(212)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
							HX_STACK_LINE(213)
							components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::DESCENDANT_dyn()));
							HX_STACK_LINE(214)
							continue;
						}
						else{
							HX_STACK_LINE(217)
							switch( (int)(c)){
								case (int)62: {
									HX_STACK_LINE(221)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
									HX_STACK_LINE(222)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(223)
									components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::CHILD_dyn()));
								}
								;break;
								case (int)43: {
									HX_STACK_LINE(226)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
									HX_STACK_LINE(227)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(228)
									components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::ADJACENT_SIBLING_dyn()));
								}
								;break;
								case (int)126: {
									HX_STACK_LINE(231)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
									HX_STACK_LINE(232)
									next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(233)
									components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::GENERAL_SIBLING_dyn()));
								}
								;break;
								case (int)58: case (int)35: case (int)46: case (int)91: case (int)42: {
									HX_STACK_LINE(236)
									state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
									HX_STACK_LINE(237)
									components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::DESCENDANT_dyn()));
									HX_STACK_LINE(238)
									continue;
								}
								;break;
							}
						}
					}
					;break;
					case 13: {
						HX_STACK_LINE(242)
						return null();
					}
					;break;
				}
			}
			HX_STACK_LINE(245)
			c = selector.cca(++(position));
		}
		HX_STACK_LINE(250)
		{
			::cocktail::core::css::parsers::SelectorParserState _switch_19 = (next);
			switch((_switch_19)->GetIndex()){
				case 4: {
					HX_STACK_LINE(253)
					::String type = selector.substr(start,(position - start));		HX_STACK_VAR(type,"type");
					HX_STACK_LINE(255)
					simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::TYPE(type.toUpperCase());
				}
				;break;
				case 10: {
					HX_STACK_LINE(257)
					simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
				}
				;break;
				case 5: {
					HX_STACK_LINE(261)
					::String className = selector.substr(start,(position - start));		HX_STACK_VAR(className,"className");
					HX_STACK_LINE(262)
					simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::CSS_CLASS(className));
					HX_STACK_LINE(263)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
				}
				;break;
				case 6: {
					HX_STACK_LINE(266)
					::String id = selector.substr(start,(position - start));		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(267)
					simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ID(id));
				}
				;break;
				default: {
				}
			}
		}
		HX_STACK_LINE(272)
		this->flushSelectors(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues,components);
		HX_STACK_LINE(277)
		selectorData->components->reverse();
		HX_STACK_LINE(280)
		::String firstClass = this->getFirstClass(selectorData->components);		HX_STACK_VAR(firstClass,"firstClass");
		HX_STACK_LINE(283)
		bool isSimpleClassSelector = false;		HX_STACK_VAR(isSimpleClassSelector,"isSimpleClassSelector");
		HX_STACK_LINE(284)
		if (((firstClass != null()))){
			HX_STACK_LINE(285)
			isSimpleClassSelector = this->getIsSimpleClassSelector(selectorData->components);
		}
		HX_STACK_LINE(290)
		::String firstId = this->getFirstId(selectorData->components);		HX_STACK_VAR(firstId,"firstId");
		HX_STACK_LINE(292)
		bool isSimpleIdSelector = false;		HX_STACK_VAR(isSimpleIdSelector,"isSimpleIdSelector");
		HX_STACK_LINE(293)
		if (((firstId != null()))){
			HX_STACK_LINE(294)
			isSimpleIdSelector = this->getIsSimpleIdSelector(selectorData->components);
		}
		HX_STACK_LINE(299)
		::String firstType = this->getFirstType(selectorData->components);		HX_STACK_VAR(firstType,"firstType");
		HX_STACK_LINE(301)
		bool isSimpleTypeSelector = false;		HX_STACK_VAR(isSimpleTypeSelector,"isSimpleTypeSelector");
		HX_STACK_LINE(302)
		if (((firstType != null()))){
			HX_STACK_LINE(303)
			isSimpleTypeSelector = this->getIsSimpleTypeSelector(selectorData->components);
		}
		HX_STACK_LINE(307)
		::cocktail::core::css::SelectorVO typedSelector = ::cocktail::core::css::SelectorVO_obj::__new(selectorData->components,selectorData->pseudoElement,(firstClass != null()),firstClass,(firstId != null()),firstId,(firstType != null()),firstType,isSimpleClassSelector,isSimpleIdSelector,isSimpleTypeSelector);		HX_STACK_VAR(typedSelector,"typedSelector");
		HX_STACK_LINE(313)
		typedSelectors->push(typedSelector);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(CSSSelectorParser_obj,parseSelector,(void))

bool CSSSelectorParser_obj::isOperatorChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isOperatorChar","cocktail/core/css/parsers/CSSSelectorParser.hx",823);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(823)
	return (bool((bool((bool((bool((bool((c == (int)61)) || bool((c == (int)126)))) || bool((c == (int)94)))) || bool((c == (int)36)))) || bool((c == (int)42)))) || bool((c == (int)124)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isOperatorChar,return )

bool CSSSelectorParser_obj::isAsciiChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isAsciiChar","cocktail/core/css/parsers/CSSSelectorParser.hx",827);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(827)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isAsciiChar,return )

bool CSSSelectorParser_obj::isSelectorChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isSelectorChar","cocktail/core/css/parsers/CSSSelectorParser.hx",831);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(831)
	return (bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isSelectorChar,return )

bool CSSSelectorParser_obj::isPseudoClassChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isPseudoClassChar","cocktail/core/css/parsers/CSSSelectorParser.hx",835);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(835)
	return (bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isPseudoClassChar,return )


CSSSelectorParser_obj::CSSSelectorParser_obj()
{
}

void CSSSelectorParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSSelectorParser);
	HX_MARK_END_CLASS();
}

void CSSSelectorParser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CSSSelectorParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"getFirstId") ) { return getFirstId_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isAsciiChar") ) { return isAsciiChar_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getFirstType") ) { return getFirstType_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getFirstClass") ) { return getFirstClass_dyn(); }
		if (HX_FIELD_EQ(inName,"parseSelector") ) { return parseSelector_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isOperatorChar") ) { return isOperatorChar_dyn(); }
		if (HX_FIELD_EQ(inName,"isSelectorChar") ) { return isSelectorChar_dyn(); }
		if (HX_FIELD_EQ(inName,"flushSelectors") ) { return flushSelectors_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parsePseudoClass") ) { return parsePseudoClass_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"isPseudoClassChar") ) { return isPseudoClassChar_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"parsePseudoElement") ) { return parsePseudoElement_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getIsSimpleIdSelector") ) { return getIsSimpleIdSelector_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"parseAttributeSelector") ) { return parseAttributeSelector_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getIsSimpleTypeSelector") ) { return getIsSimpleTypeSelector_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getIsSimpleClassSelector") ) { return getIsSimpleClassSelector_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSSelectorParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSSelectorParser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isOperatorChar"),
	HX_CSTRING("isAsciiChar"),
	HX_CSTRING("isSelectorChar"),
	HX_CSTRING("isPseudoClassChar"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getFirstType"),
	HX_CSTRING("getFirstId"),
	HX_CSTRING("getIsSimpleTypeSelector"),
	HX_CSTRING("getIsSimpleIdSelector"),
	HX_CSTRING("getIsSimpleClassSelector"),
	HX_CSTRING("getFirstClass"),
	HX_CSTRING("parseAttributeSelector"),
	HX_CSTRING("parsePseudoElement"),
	HX_CSTRING("parsePseudoClass"),
	HX_CSTRING("flushSelectors"),
	HX_CSTRING("parseSelector"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSSelectorParser_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSSelectorParser_obj::__mClass,"__mClass");
};

Class CSSSelectorParser_obj::__mClass;

void CSSSelectorParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.CSSSelectorParser"), hx::TCanCast< CSSSelectorParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSSelectorParser_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
