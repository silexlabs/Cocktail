#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSMediaRule
#include <cocktail/core/css/CSSMediaRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleRule
#include <cocktail/core/css/CSSStyleRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSRulesParser
#include <cocktail/core/css/parsers/CSSRulesParser.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRuleParserState
#include <cocktail/core/css/parsers/StyleSheetRuleParserState.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_StyleSheetRulesParserState
#include <cocktail/core/css/parsers/StyleSheetRulesParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{
namespace parsers{

Void CSSRulesParser_obj::__construct()
{
HX_STACK_PUSH("CSSRulesParser::new","cocktail/core/css/parsers/CSSRulesParser.hx",29);
{
}
;
	return null();
}

CSSRulesParser_obj::~CSSRulesParser_obj() { }

Dynamic CSSRulesParser_obj::__CreateEmpty() { return  new CSSRulesParser_obj; }
hx::ObjectPtr< CSSRulesParser_obj > CSSRulesParser_obj::__new()
{  hx::ObjectPtr< CSSRulesParser_obj > result = new CSSRulesParser_obj();
	result->__construct();
	return result;}

Dynamic CSSRulesParser_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSRulesParser_obj > result = new CSSRulesParser_obj();
	result->__construct();
	return result;}

::cocktail::core::css::CSSRule CSSRulesParser_obj::parseRule( ::String rule,::cocktail::core::css::CSSStyleSheet parentSyleSheet){
	HX_STACK_PUSH("CSSRulesParser::parseRule","cocktail/core/css/parsers/CSSRulesParser.hx",153);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rule,"rule");
	HX_STACK_ARG(parentSyleSheet,"parentSyleSheet");
	HX_STACK_LINE(154)
	::cocktail::core::css::parsers::StyleSheetRuleParserState state = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(155)
	::cocktail::core::css::parsers::StyleSheetRuleParserState next = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::BEGIN_RULE_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(156)
	int start = (int)0;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(157)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(158)
	int c = rule.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(160)
	::cocktail::core::css::CSSRule cssRule = null();		HX_STACK_VAR(cssRule,"cssRule");
	HX_STACK_LINE(162)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(164)
		{
			::cocktail::core::css::parsers::StyleSheetRuleParserState _switch_1 = (state);
			switch((_switch_1)->GetIndex()){
				case 0: {
					HX_STACK_LINE(166)
					switch( (int)(c)){
						case (int)10: case (int)13: case (int)9: case (int)32: {
						}
						;break;
						default: {
							HX_STACK_LINE(175)
							state = next;
							HX_STACK_LINE(176)
							continue;
						}
					}
				}
				;break;
				case 1: {
					HX_STACK_LINE(179)
					switch( (int)(c)){
						case (int)64: {
							HX_STACK_LINE(184)
							state = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::BEGIN_AT_RULE_dyn();
							HX_STACK_LINE(185)
							start = position;
						}
						;break;
						default: {
							HX_STACK_LINE(188)
							state = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::RULE_dyn();
							HX_STACK_LINE(189)
							next = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::END_STYLE_RULE_dyn();
							HX_STACK_LINE(190)
							start = position;
							HX_STACK_LINE(191)
							continue;
						}
					}
				}
				;break;
				case 2: {
					HX_STACK_LINE(194)
					if ((!(((bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45))))))){
						HX_STACK_LINE(197)
						::String atRule = rule.substr(start,(position - start));		HX_STACK_VAR(atRule,"atRule");
						HX_STACK_LINE(199)
						::String _switch_2 = (atRule);
						if (  ( _switch_2==HX_CSTRING("@media"))){
							HX_STACK_LINE(202)
							state = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::RULE_dyn();
							HX_STACK_LINE(203)
							next = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::END_MEDIA_RULE_dyn();
							HX_STACK_LINE(204)
							continue;
						}
						else  {
							HX_STACK_LINE(207)
							state = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::IGNORE_SPACES_dyn();
							HX_STACK_LINE(208)
							next = ::cocktail::core::css::parsers::StyleSheetRuleParserState_obj::BEGIN_RULE_dyn();
						}
;
;
					}
				}
				;break;
				case 4: {
					HX_STACK_LINE(212)
					switch( (int)(c)){
						case (int)125: {
							HX_STACK_LINE(216)
							state = next;
							HX_STACK_LINE(217)
							continue;
						}
						;break;
					}
				}
				;break;
				case 3: {
					HX_STACK_LINE(222)
					::String rule1 = rule.substr(start,((position - start) + (int)1));		HX_STACK_VAR(rule1,"rule1");
					HX_STACK_LINE(224)
					::cocktail::core::css::CSSMediaRule cssMediaRule = ::cocktail::core::css::CSSMediaRule_obj::__new(parentSyleSheet,null());		HX_STACK_VAR(cssMediaRule,"cssMediaRule");
					HX_STACK_LINE(225)
					cssMediaRule->set_cssText(rule1);
					HX_STACK_LINE(227)
					return cssMediaRule;
				}
				;break;
				case 5: {
					HX_STACK_LINE(230)
					::String rule1 = rule.substr(start,((position - start) + (int)1));		HX_STACK_VAR(rule1,"rule1");
					HX_STACK_LINE(232)
					::cocktail::core::css::CSSStyleRule cssStyleRule = ::cocktail::core::css::CSSStyleRule_obj::__new(parentSyleSheet,null());		HX_STACK_VAR(cssStyleRule,"cssStyleRule");
					HX_STACK_LINE(233)
					cssStyleRule->set_cssText(rule1);
					HX_STACK_LINE(235)
					return cssStyleRule;
				}
				;break;
			}
		}
		HX_STACK_LINE(238)
		c = rule.cca(++(position));
	}
	HX_STACK_LINE(241)
	return cssRule;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSRulesParser_obj,parseRule,return )

Array< ::String > CSSRulesParser_obj::parseRules( ::String css){
	HX_STACK_PUSH("CSSRulesParser::parseRules","cocktail/core/css/parsers/CSSRulesParser.hx",46);
	HX_STACK_THIS(this);
	HX_STACK_ARG(css,"css");
	HX_STACK_LINE(47)
	::cocktail::core::css::parsers::StyleSheetRulesParserState state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
	HX_STACK_LINE(48)
	::cocktail::core::css::parsers::StyleSheetRulesParserState next = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::BEGIN_dyn();		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(49)
	int start = (int)0;		HX_STACK_VAR(start,"start");
	HX_STACK_LINE(50)
	int position = (int)0;		HX_STACK_VAR(position,"position");
	HX_STACK_LINE(51)
	int c = css.cca(position);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(53)
	bool ruleStarted = false;		HX_STACK_VAR(ruleStarted,"ruleStarted");
	HX_STACK_LINE(54)
	Array< ::String > rules = Array_obj< ::String >::__new();		HX_STACK_VAR(rules,"rules");
	HX_STACK_LINE(56)
	while((!(((c == (int)0))))){
		HX_STACK_LINE(58)
		{
			::cocktail::core::css::parsers::StyleSheetRulesParserState _switch_3 = (state);
			switch((_switch_3)->GetIndex()){
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
					switch( (int)(c)){
						case (int)47: {
							HX_STACK_LINE(76)
							state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::BEGIN_COMMENT_dyn();
						}
						;break;
						default: {
							HX_STACK_LINE(80)
							start = position;
							HX_STACK_LINE(81)
							state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::BEGIN_RULE_dyn();
							HX_STACK_LINE(82)
							continue;
						}
					}
				}
				;break;
				case 2: {
					HX_STACK_LINE(86)
					start = position;
					HX_STACK_LINE(87)
					state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::RULE_dyn();
					HX_STACK_LINE(88)
					ruleStarted = true;
					HX_STACK_LINE(89)
					continue;
				}
				;break;
				case 3: {
					HX_STACK_LINE(91)
					switch( (int)(c)){
						case (int)125: {
							HX_STACK_LINE(94)
							state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::END_RULE_dyn();
						}
						;break;
					}
				}
				;break;
				case 4: {
					HX_STACK_LINE(99)
					::String rule = css.substr(start,(position - start));		HX_STACK_VAR(rule,"rule");
					HX_STACK_LINE(100)
					rules->push(rule);
					HX_STACK_LINE(101)
					state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::IGNORE_SPACES_dyn();
					HX_STACK_LINE(102)
					next = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::BEGIN_dyn();
					HX_STACK_LINE(103)
					ruleStarted = false;
					HX_STACK_LINE(104)
					continue;
				}
				;break;
				case 6: {
					HX_STACK_LINE(106)
					if (((c != (int)42))){
						HX_STACK_LINE(110)
						return rules;
					}
					else{
						HX_STACK_LINE(114)
						state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::COMMENT_dyn();
					}
				}
				;break;
				case 5: {
					HX_STACK_LINE(118)
					if (((c == (int)42))){
						HX_STACK_LINE(120)
						state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::END_COMMENT_dyn();
					}
				}
				;break;
				case 7: {
					HX_STACK_LINE(124)
					if (((c == (int)47))){
						HX_STACK_LINE(127)
						state = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(128)
						next = ::cocktail::core::css::parsers::StyleSheetRulesParserState_obj::BEGIN_dyn();
					}
				}
				;break;
			}
		}
		HX_STACK_LINE(132)
		c = css.cca(++(position));
	}
	HX_STACK_LINE(135)
	if (((ruleStarted == true))){
		HX_STACK_LINE(137)
		::String rule = css.substr(start,(position - start));		HX_STACK_VAR(rule,"rule");
		HX_STACK_LINE(138)
		rules->push(rule);
	}
	HX_STACK_LINE(141)
	return rules;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSRulesParser_obj,parseRules,return )

bool CSSRulesParser_obj::isValidChar( int c){
	HX_STACK_PUSH("CSSRulesParser::isValidChar","cocktail/core/css/parsers/CSSRulesParser.hx",248);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(248)
	return (bool((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)95)))) || bool((c == (int)45)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSRulesParser_obj,isValidChar,return )


CSSRulesParser_obj::CSSRulesParser_obj()
{
}

void CSSRulesParser_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSRulesParser);
	HX_MARK_END_CLASS();
}

void CSSRulesParser_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic CSSRulesParser_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"parseRule") ) { return parseRule_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"parseRules") ) { return parseRules_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isValidChar") ) { return isValidChar_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSRulesParser_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSRulesParser_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isValidChar"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("parseRule"),
	HX_CSTRING("parseRules"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSRulesParser_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSRulesParser_obj::__mClass,"__mClass");
};

Class CSSRulesParser_obj::__mClass;

void CSSRulesParser_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.parsers.CSSRulesParser"), hx::TCanCast< CSSRulesParser_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSRulesParser_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
} // end namespace parsers
