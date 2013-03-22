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
	HX_STACK_PUSH("CSSSelectorParser::getFirstType","cocktail/core/css/parsers/CSSSelectorParser.hx",815);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(816)
	{
		::cocktail::core::css::SelectorComponentValue _switch_1 = (components->__get((int)0));
		switch((_switch_1)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_1->__Param(0);
{
					HX_STACK_LINE(818)
					{
						::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_2 = (value->startValue);
						switch((_switch_2)->GetIndex()){
							case 1: {
								::String value1 = _switch_2->__Param(0);
{
									HX_STACK_LINE(821)
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
	HX_STACK_LINE(830)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstType,return )

::String CSSSelectorParser_obj::getFirstId( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getFirstId","cocktail/core/css/parsers/CSSSelectorParser.hx",783);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(784)
	{
		::cocktail::core::css::SelectorComponentValue _switch_3 = (components->__get((int)0));
		switch((_switch_3)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_3->__Param(0);
{
					HX_STACK_LINE(786)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(789)
						if (((value->simpleSelectors->length != (int)0))){
							HX_STACK_LINE(792)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_4 = (value->simpleSelectors->__get((int)0));
								switch((_switch_4)->GetIndex()){
									case 3: {
										::String value1 = _switch_4->__Param(0);
{
											HX_STACK_LINE(796)
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
	HX_STACK_LINE(807)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstId,return )

bool CSSSelectorParser_obj::getIsSimpleTypeSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleTypeSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",752);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(753)
	if (((components->length > (int)1))){
		HX_STACK_LINE(754)
		return false;
	}
	HX_STACK_LINE(758)
	{
		::cocktail::core::css::SelectorComponentValue _switch_5 = (components->__get((int)0));
		switch((_switch_5)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_5->__Param(0);
{
					HX_STACK_LINE(760)
					{
						::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_6 = (value->startValue);
						switch((_switch_6)->GetIndex()){
							case 1: {
								::String typeValue = _switch_6->__Param(0);
{
									HX_STACK_LINE(763)
									if (((value->simpleSelectors->length == (int)0))){
										HX_STACK_LINE(765)
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
	HX_STACK_LINE(775)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleTypeSelector,return )

bool CSSSelectorParser_obj::getIsSimpleIdSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleIdSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",719);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(720)
	if (((components->length > (int)1))){
		HX_STACK_LINE(721)
		return false;
	}
	HX_STACK_LINE(725)
	{
		::cocktail::core::css::SelectorComponentValue _switch_7 = (components->__get((int)0));
		switch((_switch_7)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_7->__Param(0);
{
					HX_STACK_LINE(727)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(730)
						if (((value->simpleSelectors->length == (int)1))){
							HX_STACK_LINE(732)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_8 = (value->simpleSelectors->__get((int)0));
								switch((_switch_8)->GetIndex()){
									case 3: {
										::String value1 = _switch_8->__Param(0);
{
											HX_STACK_LINE(735)
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
	HX_STACK_LINE(745)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleIdSelector,return )

bool CSSSelectorParser_obj::getIsSimpleClassSelector( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getIsSimpleClassSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",683);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(685)
	if (((components->length > (int)1))){
		HX_STACK_LINE(686)
		return false;
	}
	HX_STACK_LINE(690)
	{
		::cocktail::core::css::SelectorComponentValue _switch_9 = (components->__get((int)0));
		switch((_switch_9)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_9->__Param(0);
{
					HX_STACK_LINE(692)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(695)
						if (((value->simpleSelectors->length == (int)1))){
							HX_STACK_LINE(698)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_10 = (value->simpleSelectors->__get((int)0));
								switch((_switch_10)->GetIndex()){
									case 2: {
										::String value1 = _switch_10->__Param(0);
{
											HX_STACK_LINE(702)
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
	HX_STACK_LINE(712)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getIsSimpleClassSelector,return )

::String CSSSelectorParser_obj::getFirstClass( Array< ::cocktail::core::css::SelectorComponentValue > components){
	HX_STACK_PUSH("CSSSelectorParser::getFirstClass","cocktail/core/css/parsers/CSSSelectorParser.hx",652);
	HX_STACK_THIS(this);
	HX_STACK_ARG(components,"components");
	HX_STACK_LINE(653)
	{
		::cocktail::core::css::SelectorComponentValue _switch_11 = (components->__get((int)0));
		switch((_switch_11)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_11->__Param(0);
{
					HX_STACK_LINE(655)
					if (((value->startValue == ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn()))){
						HX_STACK_LINE(658)
						if (((value->simpleSelectors->length != (int)0))){
							HX_STACK_LINE(661)
							{
								::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_12 = (value->simpleSelectors->__get((int)0));
								switch((_switch_12)->GetIndex()){
									case 2: {
										::String value1 = _switch_12->__Param(0);
{
											HX_STACK_LINE(665)
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
	HX_STACK_LINE(676)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,getFirstClass,return )

int CSSSelectorParser_obj::parseAttributeSelector( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues){
	HX_STACK_PUSH("CSSSelectorParser::parseAttributeSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",483);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
	HX_STACK_LINE(484)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(485)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(487)
	::String attribute = null();		HX_STACK_VAR(attribute,"attribute");
	HX_STACK_LINE(488)
	::String _operator = null();		HX_STACK_VAR(_operator,"operator");
	HX_STACK_LINE(489)
	::String value = null();		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(491)
	::cocktail::core::css::parsers::AttributeSelectorParserState state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(492)
	::cocktail::core::css::parsers::AttributeSelectorParserState next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::ATTRIBUTE_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(494)
	while((true)){
		HX_STACK_LINE(496)
		{
			::cocktail::core::css::parsers::AttributeSelectorParserState _switch_13 = (state);
			int _switch_14 = (_switch_13)->GetIndex();{
				if (0==_switch_14) {
					HX_STACK_LINE(498)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(507)
							state = next;
							HX_STACK_LINE(508)
							continue;
						}
					}
				}
				else if (2==_switch_14) {
					HX_STACK_LINE(511)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(514)
						attribute = selector.substr(start,(position - start));
						HX_STACK_LINE(516)
						if (((c == (int)93))){
							HX_STACK_LINE(518)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
							HX_STACK_LINE(519)
							continue;
						}
						else{
							HX_STACK_LINE(523)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();
							HX_STACK_LINE(524)
							next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::BEGIN_OPERATOR_dyn();
							HX_STACK_LINE(525)
							continue;
						}
					}
				}
				else if (3==_switch_14) {
					HX_STACK_LINE(530)
					start = position;
					HX_STACK_LINE(531)
					state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::OPERATOR_dyn();
				}
				else if (4==_switch_14) {
					HX_STACK_LINE(533)
					if ((!(((bool((bool((bool((bool((bool((c == (int)61)) || bool((c == (int)126)))) || bool((c == (int)94)))) || bool((c == (int)36)))) || bool((c == (int)42)))) || bool((c == (int)124))))))){
						HX_STACK_LINE(536)
						_operator = selector.substr(start,(position - start));
						HX_STACK_LINE(537)
						state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(538)
						next = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_OPERATOR_dyn();
						HX_STACK_LINE(539)
						continue;
					}
				}
				else if (1==_switch_14) {
					HX_STACK_LINE(542)
					switch( (int)(c)){
						case (int)34: case (int)39: {
							HX_STACK_LINE(546)
							(position)++;
							HX_STACK_LINE(547)
							start = position;
							HX_STACK_LINE(548)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::STRING_VALUE_dyn();
						}
						;break;
						case (int)93: {
							HX_STACK_LINE(551)
							state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
							HX_STACK_LINE(552)
							continue;
						}
						;break;
						default: {
							HX_STACK_LINE(554)
							if (((((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95)))) == true))){
								HX_STACK_LINE(558)
								start = position;
								HX_STACK_LINE(559)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::IDENTIFIER_VALUE_dyn();
							}
							else{
								HX_STACK_LINE(562)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (6==_switch_14) {
					HX_STACK_LINE(567)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(569)
						switch( (int)(c)){
							case (int)34: case (int)39: {
								HX_STACK_LINE(573)
								value = selector.substr(start,(position - start));
								HX_STACK_LINE(574)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
							}
							;break;
							case (int)93: {
								HX_STACK_LINE(576)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
							;break;
							default: {
								HX_STACK_LINE(579)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (5==_switch_14) {
					HX_STACK_LINE(584)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(586)
						switch( (int)(c)){
							case (int)93: {
								HX_STACK_LINE(590)
								value = selector.substr(start,(position - start));
								HX_STACK_LINE(591)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::END_SELECTOR_dyn();
								HX_STACK_LINE(592)
								continue;
							}
							;break;
							default: {
								HX_STACK_LINE(594)
								state = ::cocktail::core::css::parsers::AttributeSelectorParserState_obj::INVALID_SELECTOR_dyn();
							}
						}
					}
				}
				else if (8==_switch_14) {
					HX_STACK_LINE(599)
					break;
				}
				else if (7==_switch_14) {
					HX_STACK_LINE(602)
					break;
				}
			}
		}
		HX_STACK_LINE(606)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(609)
	if (((attribute != null()))){
		HX_STACK_LINE(610)
		if (((_operator != null()))){
			HX_STACK_LINE(612)
			::String _switch_15 = (_operator);
			if (  ( _switch_15==HX_CSTRING("="))){
				HX_STACK_LINE(615)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("^="))){
				HX_STACK_LINE(618)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("~="))){
				HX_STACK_LINE(621)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_LIST(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("$="))){
				HX_STACK_LINE(624)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_ENDS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("*="))){
				HX_STACK_LINE(627)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_CONTAINS(attribute,value)));
			}
			else if (  ( _switch_15==HX_CSTRING("|="))){
				HX_STACK_LINE(630)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE_VALUE_BEGINS_HYPHEN_LIST(attribute,value)));
			}
		}
		else{
			HX_STACK_LINE(635)
			simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ATTRIBUTE(::cocktail::core::css::AttributeSelectorValue_obj::ATTRIBUTE(attribute)));
		}
	}
	HX_STACK_LINE(640)
	return position;
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parseAttributeSelector,return )

int CSSSelectorParser_obj::parsePseudoElement( ::String selector,int position,::cocktail::core::css::SelectorVO selectorData){
	HX_STACK_PUSH("CSSSelectorParser::parsePseudoElement","cocktail/core/css/parsers/CSSSelectorParser.hx",445);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(selectorData,"selectorData");
	HX_STACK_LINE(446)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(447)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(449)
	while((true)){
		HX_STACK_LINE(451)
		if ((!(((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45))))))){
			HX_STACK_LINE(452)
			break;
		}
		HX_STACK_LINE(455)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(458)
	::String pseudoElement = selector.substr(start,(position - start));		HX_STACK_VAR(pseudoElement,"pseudoElement");
	HX_STACK_LINE(459)
	::cocktail::core::css::PseudoElementSelectorValue typedPseudoElement = null();		HX_STACK_VAR(typedPseudoElement,"typedPseudoElement");
	HX_STACK_LINE(461)
	::String _switch_16 = (pseudoElement);
	if (  ( _switch_16==HX_CSTRING("first-line"))){
		HX_STACK_LINE(463)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::FIRST_LINE_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("first-letter"))){
		HX_STACK_LINE(466)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::FIRST_LETTER_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("before"))){
		HX_STACK_LINE(469)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::BEFORE_dyn();
	}
	else if (  ( _switch_16==HX_CSTRING("after"))){
		HX_STACK_LINE(472)
		typedPseudoElement = ::cocktail::core::css::PseudoElementSelectorValue_obj::AFTER_dyn();
	}
	HX_STACK_LINE(477)
	selectorData->pseudoElement = typedPseudoElement;
	HX_STACK_LINE(479)
	return --(position);
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parsePseudoElement,return )

int CSSSelectorParser_obj::parsePseudoClass( ::String selector,int position,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues){
	HX_STACK_PUSH("CSSSelectorParser::parsePseudoClass","cocktail/core/css/parsers/CSSSelectorParser.hx",349);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(position,"position");
	HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
	HX_STACK_LINE(350)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(351)
	int start = position;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(353)
	while((true)){
		HX_STACK_LINE(355)
		if ((!(((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45))))))){
			HX_STACK_LINE(356)
			break;
		}
		HX_STACK_LINE(359)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(362)
	::String pseudoClass = selector.substr(start,(position - start));		HX_STACK_VAR(pseudoClass,"pseudoClass");
	HX_STACK_LINE(364)
	::cocktail::core::css::PseudoClassSelectorValue typedPseudoClass = null();		HX_STACK_VAR(typedPseudoClass,"typedPseudoClass");
	HX_STACK_LINE(366)
	::String _switch_17 = (pseudoClass);
	if (  ( _switch_17==HX_CSTRING("first-child"))){
		HX_STACK_LINE(368)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::FIRST_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("last-child"))){
		HX_STACK_LINE(371)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::LAST_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("empty"))){
		HX_STACK_LINE(374)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::EMPTY_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("root"))){
		HX_STACK_LINE(377)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ROOT_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("first-of-type"))){
		HX_STACK_LINE(380)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::FIRST_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("last-of-type"))){
		HX_STACK_LINE(383)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::LAST_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("only-of-type"))){
		HX_STACK_LINE(386)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ONLY_OF_TYPE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("only-child"))){
		HX_STACK_LINE(389)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::STRUCTURAL(::cocktail::core::css::StructuralPseudoClassSelectorValue_obj::ONLY_CHILD_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("link"))){
		HX_STACK_LINE(392)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::LINK(::cocktail::core::css::LinkPseudoClassValue_obj::LINK_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("visited"))){
		HX_STACK_LINE(395)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::LINK(::cocktail::core::css::LinkPseudoClassValue_obj::VISITED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("active"))){
		HX_STACK_LINE(398)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::ACTIVE_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("hover"))){
		HX_STACK_LINE(401)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::HOVER_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("focus"))){
		HX_STACK_LINE(404)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::USER_ACTION(::cocktail::core::css::UserActionPseudoClassValue_obj::FOCUS_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("target"))){
		HX_STACK_LINE(407)
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
		HX_STACK_LINE(428)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::ENABLED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("disabled"))){
		HX_STACK_LINE(431)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::DISABLED_dyn());
	}
	else if (  ( _switch_17==HX_CSTRING("checked"))){
		HX_STACK_LINE(434)
		typedPseudoClass = ::cocktail::core::css::PseudoClassSelectorValue_obj::UI_ELEMENT_STATES(::cocktail::core::css::UIElementStatesValue_obj::CHECKED_dyn());
	}
	HX_STACK_LINE(439)
	simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::PSEUDO_CLASS(typedPseudoClass));
	HX_STACK_LINE(441)
	return --(position);
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,parsePseudoClass,return )

Void CSSSelectorParser_obj::flushSelectors( ::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStartValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues,Array< ::cocktail::core::css::SelectorComponentValue > components){
{
		HX_STACK_PUSH("CSSSelectorParser::flushSelectors","cocktail/core/css/parsers/CSSSelectorParser.hx",331);
		HX_STACK_THIS(this);
		HX_STACK_ARG(simpleSelectorSequenceStartValue,"simpleSelectorSequenceStartValue");
		HX_STACK_ARG(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
		HX_STACK_ARG(components,"components");
		HX_STACK_LINE(332)
		if (((bool((simpleSelectorSequenceStartValue == null())) && bool((simpleSelectorSequenceItemValues->length == (int)0))))){
			HX_STACK_LINE(333)
			return null();
		}
		HX_STACK_LINE(337)
		if (((simpleSelectorSequenceStartValue == null()))){
			HX_STACK_LINE(338)
			simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
		}
		HX_STACK_LINE(342)
		::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence = ::cocktail::core::css::SimpleSelectorSequenceVO_obj::__new(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues);		HX_STACK_VAR(simpleSelectorSequence,"simpleSelectorSequence");
		HX_STACK_LINE(343)
		components->push(::cocktail::core::css::SelectorComponentValue_obj::SIMPLE_SELECTOR_SEQUENCE(simpleSelectorSequence));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CSSSelectorParser_obj,flushSelectors,(void))

bool CSSSelectorParser_obj::parseSelector( ::String selector,Array< ::cocktail::core::css::SelectorVO > typedSelectors){
	HX_STACK_PUSH("CSSSelectorParser::parseSelector","cocktail/core/css/parsers/CSSSelectorParser.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(typedSelectors,"typedSelectors");
	HX_STACK_LINE(43)
	::cocktail::core::css::parsers::SelectorParserState state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(44)
	::cocktail::core::css::parsers::SelectorParserState next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(45)
	int start = (int)0;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(46)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(47)
	int c = selector.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(49)
	::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStartValue = null();		HX_STACK_VAR(simpleSelectorSequenceStartValue,"simpleSelectorSequenceStartValue");
	HX_STACK_LINE(50)
	Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectorSequenceItemValues = Array_obj< ::cocktail::core::css::SimpleSelectorSequenceItemValue >::__new();		HX_STACK_VAR(simpleSelectorSequenceItemValues,"simpleSelectorSequenceItemValues");
	HX_STACK_LINE(51)
	Array< ::cocktail::core::css::SelectorComponentValue > components = Array_obj< ::cocktail::core::css::SelectorComponentValue >::__new();		HX_STACK_VAR(components,"components");
	HX_STACK_LINE(53)
	::cocktail::core::css::SelectorVO selectorData = ::cocktail::core::css::SelectorVO_obj::__new(components,::cocktail::core::css::PseudoElementSelectorValue_obj::NONE_dyn(),false,null(),false,null(),false,null(),false,false,false);		HX_STACK_VAR(selectorData,"selectorData");
	HX_STACK_LINE(56)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(58)
		{
			::cocktail::core::css::parsers::SelectorParserState _switch_18 = (state);
			switch((_switch_18)->GetIndex()){
				case 0: {
					HX_STACK_LINE(60)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(69)
							state = next;
							HX_STACK_LINE(70)
							continue;
						}
					}
				}
				;break;
				case 1: {
					HX_STACK_LINE(73)
					if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
						HX_STACK_LINE(76)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(77)
						next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_TYPE_SELECTOR_dyn();
						HX_STACK_LINE(78)
						start = position;
					}
					else{
						HX_STACK_LINE(81)
						switch( (int)(c)){
							case (int)46: {
								HX_STACK_LINE(86)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(87)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_CLASS_SELECTOR_dyn();
								HX_STACK_LINE(88)
								start = (position + (int)1);
							}
							;break;
							case (int)35: {
								HX_STACK_LINE(91)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(92)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_ID_SELECTOR_dyn();
								HX_STACK_LINE(93)
								start = (position + (int)1);
							}
							;break;
							case (int)42: {
								HX_STACK_LINE(96)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(97)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::END_UNIVERSAL_SELECTOR_dyn();
								HX_STACK_LINE(98)
								start = position;
							}
							;break;
							case (int)58: {
								HX_STACK_LINE(101)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_PSEUDO_SELECTOR_dyn();
								HX_STACK_LINE(102)
								start = position;
							}
							;break;
							case (int)91: {
								HX_STACK_LINE(105)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_ATTRIBUTE_SELECTOR_dyn();
								HX_STACK_LINE(106)
								start = position;
							}
							;break;
							default: {
								HX_STACK_LINE(109)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
								HX_STACK_LINE(110)
								continue;
							}
						}
					}
				}
				;break;
				case 12: {
					HX_STACK_LINE(116)
					position = this->parseAttributeSelector(selector,position,simpleSelectorSequenceItemValues);
					HX_STACK_LINE(117)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
					HX_STACK_LINE(118)
					next = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
				}
				;break;
				case 9: {
					HX_STACK_LINE(120)
					if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
						HX_STACK_LINE(123)
						position = this->parsePseudoClass(selector,position,simpleSelectorSequenceItemValues);
						HX_STACK_LINE(124)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(125)
						next = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
					}
					else{
						HX_STACK_LINE(128)
						switch( (int)(c)){
							case (int)58: {
								HX_STACK_LINE(131)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::PSEUDO_ELEMENT_SELECTOR_dyn();
							}
							;break;
							default: {
								HX_STACK_LINE(135)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
								HX_STACK_LINE(136)
								continue;
							}
						}
					}
				}
				;break;
				case 11: {
					HX_STACK_LINE(141)
					position = this->parsePseudoElement(selector,position,selectorData);
					HX_STACK_LINE(142)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
					HX_STACK_LINE(143)
					next = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
				}
				;break;
				case 2: {
					HX_STACK_LINE(145)
					switch( (int)(c)){
						case (int)32: case (int)10: case (int)13: case (int)62: {
							HX_STACK_LINE(149)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_COMBINATOR_dyn();
							HX_STACK_LINE(150)
							continue;
						}
						;break;
						case (int)58: case (int)35: case (int)46: case (int)91: {
							HX_STACK_LINE(153)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
							HX_STACK_LINE(154)
							continue;
						}
						;break;
						default: {
							HX_STACK_LINE(157)
							state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
							HX_STACK_LINE(158)
							continue;
						}
					}
				}
				;break;
				case 3: {
					HX_STACK_LINE(161)
					if ((!(((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))))){
						HX_STACK_LINE(163)
						switch( (int)(c)){
							case (int)32: case (int)10: case (int)13: case (int)62: case (int)58: case (int)35: case (int)46: case (int)91: {
								HX_STACK_LINE(167)
								state = next;
								HX_STACK_LINE(168)
								continue;
							}
							;break;
							default: {
								HX_STACK_LINE(171)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::INVALID_SELECTOR_dyn();
								HX_STACK_LINE(172)
								continue;
							}
						}
					}
				}
				;break;
				case 4: {
					HX_STACK_LINE(177)
					::String type = selector.substr(start,(position - start));		HX_STACK_VAR(type,"type");
					HX_STACK_LINE(178)
					simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::TYPE(type.toUpperCase());
					HX_STACK_LINE(179)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
					HX_STACK_LINE(180)
					continue;
				}
				;break;
				case 5: {
					HX_STACK_LINE(183)
					::String className = selector.substr(start,(position - start));		HX_STACK_VAR(className,"className");
					HX_STACK_LINE(184)
					simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::CSS_CLASS(className));
					HX_STACK_LINE(185)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
					HX_STACK_LINE(186)
					continue;
				}
				;break;
				case 6: {
					HX_STACK_LINE(189)
					::String id = selector.substr(start,(position - start));		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(190)
					simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ID(id));
					HX_STACK_LINE(191)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
					HX_STACK_LINE(192)
					continue;
				}
				;break;
				case 10: {
					HX_STACK_LINE(195)
					simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
					HX_STACK_LINE(196)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
					HX_STACK_LINE(197)
					continue;
				}
				;break;
				case 7: {
					HX_STACK_LINE(201)
					this->flushSelectors(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues,components);
					HX_STACK_LINE(203)
					simpleSelectorSequenceStartValue = null();
					HX_STACK_LINE(204)
					simpleSelectorSequenceItemValues = Array_obj< ::cocktail::core::css::SimpleSelectorSequenceItemValue >::__new();
					HX_STACK_LINE(206)
					state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
					HX_STACK_LINE(207)
					next = ::cocktail::core::css::parsers::SelectorParserState_obj::COMBINATOR_dyn();
					HX_STACK_LINE(208)
					continue;
				}
				;break;
				case 8: {
					HX_STACK_LINE(210)
					if (((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95))))){
						HX_STACK_LINE(214)
						state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
						HX_STACK_LINE(215)
						components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::DESCENDANT_dyn()));
						HX_STACK_LINE(216)
						continue;
					}
					else{
						HX_STACK_LINE(219)
						switch( (int)(c)){
							case (int)62: {
								HX_STACK_LINE(223)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
								HX_STACK_LINE(224)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(225)
								components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::CHILD_dyn()));
							}
							;break;
							case (int)43: {
								HX_STACK_LINE(228)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
								HX_STACK_LINE(229)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(230)
								components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::ADJACENT_SIBLING_dyn()));
							}
							;break;
							case (int)126: {
								HX_STACK_LINE(233)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::IGNORE_SPACES_dyn();
								HX_STACK_LINE(234)
								next = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(235)
								components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::GENERAL_SIBLING_dyn()));
							}
							;break;
							case (int)58: case (int)35: case (int)46: case (int)91: case (int)42: {
								HX_STACK_LINE(238)
								state = ::cocktail::core::css::parsers::SelectorParserState_obj::BEGIN_SIMPLE_SELECTOR_dyn();
								HX_STACK_LINE(239)
								components->push(::cocktail::core::css::SelectorComponentValue_obj::COMBINATOR(::cocktail::core::css::CombinatorValue_obj::DESCENDANT_dyn()));
								HX_STACK_LINE(240)
								continue;
							}
							;break;
						}
					}
				}
				;break;
				case 13: {
					HX_STACK_LINE(244)
					return false;
				}
				;break;
			}
		}
		HX_STACK_LINE(247)
		c = selector.cca(++(position));
	}
	HX_STACK_LINE(252)
	{
		::cocktail::core::css::parsers::SelectorParserState _switch_19 = (next);
		switch((_switch_19)->GetIndex()){
			case 4: {
				HX_STACK_LINE(255)
				::String type = selector.substr(start,(position - start));		HX_STACK_VAR(type,"type");
				HX_STACK_LINE(257)
				simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::TYPE(type.toUpperCase());
			}
			;break;
			case 10: {
				HX_STACK_LINE(259)
				simpleSelectorSequenceStartValue = ::cocktail::core::css::SimpleSelectorSequenceStartValue_obj::UNIVERSAL_dyn();
			}
			;break;
			case 5: {
				HX_STACK_LINE(263)
				::String className = selector.substr(start,(position - start));		HX_STACK_VAR(className,"className");
				HX_STACK_LINE(264)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::CSS_CLASS(className));
				HX_STACK_LINE(265)
				state = ::cocktail::core::css::parsers::SelectorParserState_obj::END_SIMPLE_SELECTOR_dyn();
			}
			;break;
			case 6: {
				HX_STACK_LINE(268)
				::String id = selector.substr(start,(position - start));		HX_STACK_VAR(id,"id");
				HX_STACK_LINE(269)
				simpleSelectorSequenceItemValues->push(::cocktail::core::css::SimpleSelectorSequenceItemValue_obj::ID(id));
			}
			;break;
			default: {
			}
		}
	}
	HX_STACK_LINE(274)
	this->flushSelectors(simpleSelectorSequenceStartValue,simpleSelectorSequenceItemValues,components);
	HX_STACK_LINE(278)
	if (((selectorData->components->length == (int)0))){
		HX_STACK_LINE(279)
		return false;
	}
	HX_STACK_LINE(286)
	selectorData->components->reverse();
	HX_STACK_LINE(289)
	::String firstClass = this->getFirstClass(selectorData->components);		HX_STACK_VAR(firstClass,"firstClass");
	HX_STACK_LINE(292)
	bool isSimpleClassSelector = false;		HX_STACK_VAR(isSimpleClassSelector,"isSimpleClassSelector");
	HX_STACK_LINE(293)
	if (((firstClass != null()))){
		HX_STACK_LINE(294)
		isSimpleClassSelector = this->getIsSimpleClassSelector(selectorData->components);
	}
	HX_STACK_LINE(299)
	::String firstId = this->getFirstId(selectorData->components);		HX_STACK_VAR(firstId,"firstId");
	HX_STACK_LINE(301)
	bool isSimpleIdSelector = false;		HX_STACK_VAR(isSimpleIdSelector,"isSimpleIdSelector");
	HX_STACK_LINE(302)
	if (((firstId != null()))){
		HX_STACK_LINE(303)
		isSimpleIdSelector = this->getIsSimpleIdSelector(selectorData->components);
	}
	HX_STACK_LINE(308)
	::String firstType = this->getFirstType(selectorData->components);		HX_STACK_VAR(firstType,"firstType");
	HX_STACK_LINE(310)
	bool isSimpleTypeSelector = false;		HX_STACK_VAR(isSimpleTypeSelector,"isSimpleTypeSelector");
	HX_STACK_LINE(311)
	if (((firstType != null()))){
		HX_STACK_LINE(312)
		isSimpleTypeSelector = this->getIsSimpleTypeSelector(selectorData->components);
	}
	HX_STACK_LINE(316)
	::cocktail::core::css::SelectorVO typedSelector = ::cocktail::core::css::SelectorVO_obj::__new(selectorData->components,selectorData->pseudoElement,(firstClass != null()),firstClass,(firstId != null()),firstId,(firstType != null()),firstType,isSimpleClassSelector,isSimpleIdSelector,isSimpleTypeSelector);		HX_STACK_VAR(typedSelector,"typedSelector");
	HX_STACK_LINE(322)
	typedSelectors->push(typedSelector);
	HX_STACK_LINE(323)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSSelectorParser_obj,parseSelector,return )

bool CSSSelectorParser_obj::isOperatorChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isOperatorChar","cocktail/core/css/parsers/CSSSelectorParser.hx",836);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(836)
	return (bool((bool((bool((bool((bool((c == (int)61)) || bool((c == (int)126)))) || bool((c == (int)94)))) || bool((c == (int)36)))) || bool((c == (int)42)))) || bool((c == (int)124)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isOperatorChar,return )

bool CSSSelectorParser_obj::isAsciiChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isAsciiChar","cocktail/core/css/parsers/CSSSelectorParser.hx",840);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(840)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isAsciiChar,return )

bool CSSSelectorParser_obj::isSelectorChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isSelectorChar","cocktail/core/css/parsers/CSSSelectorParser.hx",844);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(844)
	return (bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)45)))) || bool((c == (int)95)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSSelectorParser_obj,isSelectorChar,return )

bool CSSSelectorParser_obj::isPseudoClassChar( int c){
	HX_STACK_PUSH("CSSSelectorParser::isPseudoClassChar","cocktail/core/css/parsers/CSSSelectorParser.hx",848);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(848)
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
