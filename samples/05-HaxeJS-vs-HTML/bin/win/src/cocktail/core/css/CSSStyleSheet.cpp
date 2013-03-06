#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_parsers_CSSRulesParser
#include <cocktail/core/css/parsers/CSSRulesParser.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSStyleSheet_obj::__construct(::String stylesheet,::cocktail::core::css::PropertyOriginValue origin,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet,::cocktail::core::css::CSSRule ownerRule)
{
HX_STACK_PUSH("CSSStyleSheet::new","cocktail/core/css/CSSStyleSheet.hx",49);
{
	HX_STACK_LINE(50)
	super::__construct(stylesheet,ownerNode,href,parentStyleSheet);
	HX_STACK_LINE(51)
	this->cssRules = Array_obj< ::cocktail::core::css::CSSRule >::__new();
	HX_STACK_LINE(52)
	this->ownerRule = ownerRule;
	HX_STACK_LINE(53)
	this->origin = origin;
	HX_STACK_LINE(54)
	this->_cssRulesParser = ::cocktail::core::css::parsers::CSSRulesParser_obj::__new();
	HX_STACK_LINE(56)
	Array< ::String > rules = this->_cssRulesParser->parseRules(stylesheet);		HX_STACK_VAR(rules,"rules");
	HX_STACK_LINE(58)
	{
		HX_STACK_LINE(58)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = rules->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		while(((_g1 < _g))){
			HX_STACK_LINE(58)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(60)
			this->insertRule(rules->__get(i),(this->cssRules->length - (int)1));
		}
	}
}
;
	return null();
}

CSSStyleSheet_obj::~CSSStyleSheet_obj() { }

Dynamic CSSStyleSheet_obj::__CreateEmpty() { return  new CSSStyleSheet_obj; }
hx::ObjectPtr< CSSStyleSheet_obj > CSSStyleSheet_obj::__new(::String stylesheet,::cocktail::core::css::PropertyOriginValue origin,::cocktail::core::html::HTMLElement ownerNode,::String href,::cocktail::core::css::StyleSheet parentStyleSheet,::cocktail::core::css::CSSRule ownerRule)
{  hx::ObjectPtr< CSSStyleSheet_obj > result = new CSSStyleSheet_obj();
	result->__construct(stylesheet,origin,ownerNode,href,parentStyleSheet,ownerRule);
	return result;}

Dynamic CSSStyleSheet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSStyleSheet_obj > result = new CSSStyleSheet_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

Void CSSStyleSheet_obj::deleteRule( int index){
{
		HX_STACK_PUSH("CSSStyleSheet::deleteRule","cocktail/core/css/CSSStyleSheet.hx",84);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
		HX_STACK_LINE(84)
		this->cssRules->remove(this->cssRules->__get(index));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSStyleSheet_obj,deleteRule,(void))

int CSSStyleSheet_obj::insertRule( ::String rule,int index){
	HX_STACK_PUSH("CSSStyleSheet::insertRule","cocktail/core/css/CSSStyleSheet.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rule,"rule");
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(74)
	::cocktail::core::css::CSSRule cssRule = this->_cssRulesParser->parseRule(rule,hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(cssRule,"cssRule");
	HX_STACK_LINE(75)
	this->cssRules->insert(index,cssRule);
	HX_STACK_LINE(76)
	return index;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSStyleSheet_obj,insertRule,return )


CSSStyleSheet_obj::CSSStyleSheet_obj()
{
}

void CSSStyleSheet_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSStyleSheet);
	HX_MARK_MEMBER_NAME(origin,"origin");
	HX_MARK_MEMBER_NAME(_cssRulesParser,"_cssRulesParser");
	HX_MARK_MEMBER_NAME(cssRules,"cssRules");
	HX_MARK_MEMBER_NAME(ownerRule,"ownerRule");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CSSStyleSheet_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(origin,"origin");
	HX_VISIT_MEMBER_NAME(_cssRulesParser,"_cssRulesParser");
	HX_VISIT_MEMBER_NAME(cssRules,"cssRules");
	HX_VISIT_MEMBER_NAME(ownerRule,"ownerRule");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CSSStyleSheet_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { return origin; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cssRules") ) { return cssRules; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ownerRule") ) { return ownerRule; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deleteRule") ) { return deleteRule_dyn(); }
		if (HX_FIELD_EQ(inName,"insertRule") ) { return insertRule_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cssRulesParser") ) { return _cssRulesParser; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSStyleSheet_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"origin") ) { origin=inValue.Cast< ::cocktail::core::css::PropertyOriginValue >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cssRules") ) { cssRules=inValue.Cast< Array< ::cocktail::core::css::CSSRule > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"ownerRule") ) { ownerRule=inValue.Cast< ::cocktail::core::css::CSSRule >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_cssRulesParser") ) { _cssRulesParser=inValue.Cast< ::cocktail::core::css::parsers::CSSRulesParser >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSStyleSheet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("origin"));
	outFields->push(HX_CSTRING("_cssRulesParser"));
	outFields->push(HX_CSTRING("cssRules"));
	outFields->push(HX_CSTRING("ownerRule"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("deleteRule"),
	HX_CSTRING("insertRule"),
	HX_CSTRING("origin"),
	HX_CSTRING("_cssRulesParser"),
	HX_CSTRING("cssRules"),
	HX_CSTRING("ownerRule"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSStyleSheet_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSStyleSheet_obj::__mClass,"__mClass");
};

Class CSSStyleSheet_obj::__mClass;

void CSSStyleSheet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSStyleSheet"), hx::TCanCast< CSSStyleSheet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSStyleSheet_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
