#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleRule
#include <cocktail/core/css/CSSStyleRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSSelectorParser
#include <cocktail/core/css/parsers/CSSSelectorParser.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_SelectorSerializer
#include <cocktail/core/css/parsers/SelectorSerializer.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_StyleRuleParserState
#include <cocktail/core/css/parsers/StyleRuleParserState.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSStyleRule_obj::__construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{
HX_STACK_PUSH("CSSStyleRule::new","cocktail/core/css/CSSStyleRule.hx",52);
{
	HX_STACK_LINE(53)
	super::__construct(parentStyleSheet,parentRule);
	HX_STACK_LINE(54)
	this->style = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(hx::ObjectPtr<OBJ_>(this),null());
	HX_STACK_LINE(55)
	this->_selectorParser = ::cocktail::core::css::parsers::CSSSelectorParser_obj::__new();
	HX_STACK_LINE(57)
	this->selectors = Array_obj< ::cocktail::core::css::SelectorVO >::__new();
	HX_STACK_LINE(59)
	this->type = (int)1;
}
;
	return null();
}

CSSStyleRule_obj::~CSSStyleRule_obj() { }

Dynamic CSSStyleRule_obj::__CreateEmpty() { return  new CSSStyleRule_obj; }
hx::ObjectPtr< CSSStyleRule_obj > CSSStyleRule_obj::__new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{  hx::ObjectPtr< CSSStyleRule_obj > result = new CSSStyleRule_obj();
	result->__construct(parentStyleSheet,parentRule);
	return result;}

Dynamic CSSStyleRule_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSStyleRule_obj > result = new CSSStyleRule_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String CSSStyleRule_obj::set_selectorText( ::String value){
	HX_STACK_PUSH("CSSStyleRule::set_selectorText","cocktail/core/css/CSSStyleRule.hx",243);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(244)
	this->selectors = Array_obj< ::cocktail::core::css::SelectorVO >::__new();
	HX_STACK_LINE(245)
	this->_selectorParser->parseSelector(value,this->selectors);
	HX_STACK_LINE(246)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,set_selectorText,return )

::String CSSStyleRule_obj::get_selectorText( ){
	HX_STACK_PUSH("CSSStyleRule::get_selectorText","cocktail/core/css/CSSStyleRule.hx",237);
	HX_STACK_THIS(this);
	HX_STACK_LINE(237)
	return this->serializeSelectors(this->selectors);
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleRule_obj,get_selectorText,return )

::String CSSStyleRule_obj::get_cssText( ){
	HX_STACK_PUSH("CSSStyleRule::get_cssText","cocktail/core/css/CSSStyleRule.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_LINE(228)
	return this->serializeStyleRule();
}


::String CSSStyleRule_obj::set_cssText( ::String value){
	HX_STACK_PUSH("CSSStyleRule::set_cssText","cocktail/core/css/CSSStyleRule.hx",222);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(223)
	this->parse(value);
	HX_STACK_LINE(224)
	return value;
}


::String CSSStyleRule_obj::serializeSelectors( Array< ::cocktail::core::css::SelectorVO > selectors){
	HX_STACK_PUSH("CSSStyleRule::serializeSelectors","cocktail/core/css/CSSStyleRule.hx",184);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selectors,"selectors");
	HX_STACK_LINE(185)
	::String serializedSelectors = HX_CSTRING("");		HX_STACK_VAR(serializedSelectors,"serializedSelectors");
	HX_STACK_LINE(187)
	{
		HX_STACK_LINE(187)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = selectors->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(187)
		while(((_g1 < _g))){
			HX_STACK_LINE(187)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(189)
			::cocktail::core::css::SelectorVO selector = selectors->__get(i);		HX_STACK_VAR(selector,"selector");
			HX_STACK_LINE(190)
			hx::AddEq(serializedSelectors,::cocktail::core::css::parsers::SelectorSerializer_obj::serialize(selector));
			HX_STACK_LINE(192)
			if (((i < (selectors->length - (int)1)))){
				HX_STACK_LINE(193)
				hx::AddEq(serializedSelectors,HX_CSTRING(", "));
			}
		}
	}
	HX_STACK_LINE(198)
	return serializedSelectors;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,serializeSelectors,return )

::String CSSStyleRule_obj::serializeStyleRule( ){
	HX_STACK_PUSH("CSSStyleRule::serializeStyleRule","cocktail/core/css/CSSStyleRule.hx",172);
	HX_STACK_THIS(this);
	HX_STACK_LINE(173)
	::String serializedStyleRule = this->serializeSelectors(this->selectors);		HX_STACK_VAR(serializedStyleRule,"serializedStyleRule");
	HX_STACK_LINE(175)
	hx::AddEq(serializedStyleRule,((HX_CSTRING("{") + this->style->get_cssText()) + HX_CSTRING("}")));
	HX_STACK_LINE(176)
	return serializedStyleRule;
}


HX_DEFINE_DYNAMIC_FUNC0(CSSStyleRule_obj,serializeStyleRule,return )

Void CSSStyleRule_obj::parse( ::String css){
{
		HX_STACK_PUSH("CSSStyleRule::parse","cocktail/core/css/CSSStyleRule.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_ARG(css,"css");
		HX_STACK_LINE(75)
		this->selectors = Array_obj< ::cocktail::core::css::SelectorVO >::__new();
		HX_STACK_LINE(77)
		::cocktail::core::css::parsers::StyleRuleParserState state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::IGNORE_SPACES_dyn();		HX_STACK_VAR(state,"state");
		HX_STACK_LINE(78)
		::cocktail::core::css::parsers::StyleRuleParserState next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::BEGIN_SELECTOR_dyn();		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(79)
		int start = (int)0;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(80)
		int position = (int)0;		HX_STACK_VAR(position,"position");
		HX_STACK_LINE(81)
		int c = css.cca(position);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(83)
		while((!(((c == (int)0))))){
			HX_STACK_LINE(85)
			{
				::cocktail::core::css::parsers::StyleRuleParserState _switch_1 = (state);
				switch((_switch_1)->GetIndex()){
					case 0: {
						HX_STACK_LINE(87)
						switch( (int)(c)){
							case (int)10: case (int)13: case (int)9: case (int)32: {
							}
							;break;
							default: {
								HX_STACK_LINE(96)
								state = next;
								HX_STACK_LINE(97)
								continue;
							}
						}
					}
					;break;
					case 1: {
						HX_STACK_LINE(101)
						state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::SELECTOR_dyn();
						HX_STACK_LINE(102)
						next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::END_SELECTOR_dyn();
						HX_STACK_LINE(103)
						start = position;
						HX_STACK_LINE(104)
						continue;
					}
					;break;
					case 3: {
						HX_STACK_LINE(106)
						if ((!(((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)42))))))){
							HX_STACK_LINE(108)
							switch( (int)(c)){
								case (int)123: {
									HX_STACK_LINE(112)
									state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::END_SELECTOR_dyn();
									HX_STACK_LINE(113)
									next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::BEGIN_STYLES_dyn();
									HX_STACK_LINE(114)
									continue;
								}
								;break;
								case (int)44: {
									HX_STACK_LINE(117)
									state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::END_SELECTOR_dyn();
									HX_STACK_LINE(118)
									next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::BEGIN_SELECTOR_dyn();
									HX_STACK_LINE(119)
									continue;
								}
								;break;
							}
						}
					}
					;break;
					case 2: {
						HX_STACK_LINE(124)
						::String selector = css.substr(start,(position - start));		HX_STACK_VAR(selector,"selector");
						HX_STACK_LINE(125)
						bool isValid = this->_selectorParser->parseSelector(selector,this->selectors);		HX_STACK_VAR(isValid,"isValid");
						HX_STACK_LINE(129)
						if (((isValid == false))){
							HX_STACK_LINE(131)
							this->selectors = Array_obj< ::cocktail::core::css::SelectorVO >::__new();
							HX_STACK_LINE(132)
							return null();
						}
						HX_STACK_LINE(134)
						state = next;
					}
					;break;
					case 4: {
						HX_STACK_LINE(137)
						state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::STYLES_dyn();
						HX_STACK_LINE(138)
						next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::END_STYLES_dyn();
						HX_STACK_LINE(139)
						start = position;
						HX_STACK_LINE(140)
						continue;
					}
					;break;
					case 5: {
						HX_STACK_LINE(142)
						if ((!(((bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)40)))) || bool((c == (int)41))))))){
							HX_STACK_LINE(144)
							switch( (int)(c)){
								case (int)125: {
									HX_STACK_LINE(148)
									state = next;
									HX_STACK_LINE(149)
									continue;
								}
								;break;
							}
						}
					}
					;break;
					case 6: {
						HX_STACK_LINE(154)
						::String styleDeclaration = css.substr(start,(position - start));		HX_STACK_VAR(styleDeclaration,"styleDeclaration");
						HX_STACK_LINE(155)
						this->style->set_cssText(styleDeclaration);
						HX_STACK_LINE(156)
						state = ::cocktail::core::css::parsers::StyleRuleParserState_obj::IGNORE_SPACES_dyn();
						HX_STACK_LINE(157)
						next = ::cocktail::core::css::parsers::StyleRuleParserState_obj::IGNORE_SPACES_dyn();
					}
					;break;
				}
			}
			HX_STACK_LINE(159)
			c = css.cca(++(position));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,parse,(void))

bool CSSStyleRule_obj::isSelectorChar( int c){
	HX_STACK_PUSH("CSSStyleRule::isSelectorChar","cocktail/core/css/CSSStyleRule.hx",205);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(205)
	return (bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)46)))) || bool((c == (int)42)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,isSelectorChar,return )

bool CSSStyleRule_obj::isStyleChar( int c){
	HX_STACK_PUSH("CSSStyleRule::isStyleChar","cocktail/core/css/CSSStyleRule.hx",209);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(209)
	return (bool((bool((bool((bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))))) || bool((c == (int)58)))) || bool((c == (int)40)))) || bool((c == (int)41)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,isStyleChar,return )

bool CSSStyleRule_obj::isAsciiChar( int c){
	HX_STACK_PUSH("CSSStyleRule::isAsciiChar","cocktail/core/css/CSSStyleRule.hx",213);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(213)
	return (bool((bool((bool((c >= (int)97)) && bool((c <= (int)122)))) || bool((bool((c >= (int)65)) && bool((c <= (int)90)))))) || bool((bool((c >= (int)48)) && bool((c <= (int)57)))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(CSSStyleRule_obj,isAsciiChar,return )


CSSStyleRule_obj::CSSStyleRule_obj()
{
}

void CSSStyleRule_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSStyleRule);
	HX_MARK_MEMBER_NAME(_selectorParser,"_selectorParser");
	HX_MARK_MEMBER_NAME(style,"style");
	HX_MARK_MEMBER_NAME(selectors,"selectors");
	HX_MARK_MEMBER_NAME(selectorText,"selectorText");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CSSStyleRule_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_selectorParser,"_selectorParser");
	HX_VISIT_MEMBER_NAME(style,"style");
	HX_VISIT_MEMBER_NAME(selectors,"selectors");
	HX_VISIT_MEMBER_NAME(selectorText,"selectorText");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CSSStyleRule_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"parse") ) { return parse_dyn(); }
		if (HX_FIELD_EQ(inName,"style") ) { return style; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"selectors") ) { return selectors; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isStyleChar") ) { return isStyleChar_dyn(); }
		if (HX_FIELD_EQ(inName,"isAsciiChar") ) { return isAsciiChar_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cssText") ) { return get_cssText_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cssText") ) { return set_cssText_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"selectorText") ) { return inCallProp ? get_selectorText() : selectorText; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isSelectorChar") ) { return isSelectorChar_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_selectorParser") ) { return _selectorParser; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"set_selectorText") ) { return set_selectorText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_selectorText") ) { return get_selectorText_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"serializeSelectors") ) { return serializeSelectors_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeStyleRule") ) { return serializeStyleRule_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSStyleRule_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"style") ) { style=inValue.Cast< ::cocktail::core::css::CSSStyleDeclaration >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"selectors") ) { selectors=inValue.Cast< Array< ::cocktail::core::css::SelectorVO > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"selectorText") ) { if (inCallProp) return set_selectorText(inValue);selectorText=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_selectorParser") ) { _selectorParser=inValue.Cast< ::cocktail::core::css::parsers::CSSSelectorParser >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSStyleRule_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_selectorParser"));
	outFields->push(HX_CSTRING("style"));
	outFields->push(HX_CSTRING("selectors"));
	outFields->push(HX_CSTRING("selectorText"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("isSelectorChar"),
	HX_CSTRING("isStyleChar"),
	HX_CSTRING("isAsciiChar"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_selectorText"),
	HX_CSTRING("get_selectorText"),
	HX_CSTRING("get_cssText"),
	HX_CSTRING("set_cssText"),
	HX_CSTRING("serializeSelectors"),
	HX_CSTRING("serializeStyleRule"),
	HX_CSTRING("parse"),
	HX_CSTRING("_selectorParser"),
	HX_CSTRING("style"),
	HX_CSTRING("selectors"),
	HX_CSTRING("selectorText"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSStyleRule_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSStyleRule_obj::__mClass,"__mClass");
};

Class CSSStyleRule_obj::__mClass;

void CSSStyleRule_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSStyleRule"), hx::TCanCast< CSSStyleRule_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSStyleRule_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
