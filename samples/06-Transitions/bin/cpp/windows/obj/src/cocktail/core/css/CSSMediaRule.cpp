#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSMediaRule
#include <cocktail/core/css/CSSMediaRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_MediaList
#include <cocktail/core/css/MediaList.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSMediaRule_obj::__construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{
HX_STACK_PUSH("CSSMediaRule::new","cocktail/core/css/CSSMediaRule.hx",36);
{
	HX_STACK_LINE(36)
	super::__construct(parentStyleSheet,parentRule);
}
;
	return null();
}

CSSMediaRule_obj::~CSSMediaRule_obj() { }

Dynamic CSSMediaRule_obj::__CreateEmpty() { return  new CSSMediaRule_obj; }
hx::ObjectPtr< CSSMediaRule_obj > CSSMediaRule_obj::__new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{  hx::ObjectPtr< CSSMediaRule_obj > result = new CSSMediaRule_obj();
	result->__construct(parentStyleSheet,parentRule);
	return result;}

Dynamic CSSMediaRule_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSMediaRule_obj > result = new CSSMediaRule_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void CSSMediaRule_obj::deleteRule( int index){
{
		HX_STACK_PUSH("CSSMediaRule::deleteRule","cocktail/core/css/CSSMediaRule.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_ARG(index,"index");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CSSMediaRule_obj,deleteRule,(void))

int CSSMediaRule_obj::insertRule( ::String rule,int index){
	HX_STACK_PUSH("CSSMediaRule::insertRule","cocktail/core/css/CSSMediaRule.hx",41);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rule,"rule");
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(41)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(CSSMediaRule_obj,insertRule,return )


CSSMediaRule_obj::CSSMediaRule_obj()
{
}

void CSSMediaRule_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSMediaRule);
	HX_MARK_MEMBER_NAME(cssRules,"cssRules");
	HX_MARK_MEMBER_NAME(media,"media");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CSSMediaRule_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(cssRules,"cssRules");
	HX_VISIT_MEMBER_NAME(media,"media");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic CSSMediaRule_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { return media; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cssRules") ) { return cssRules; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deleteRule") ) { return deleteRule_dyn(); }
		if (HX_FIELD_EQ(inName,"insertRule") ) { return insertRule_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSMediaRule_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"media") ) { media=inValue.Cast< ::cocktail::core::css::MediaList >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cssRules") ) { cssRules=inValue.Cast< Array< ::cocktail::core::css::CSSRule > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSMediaRule_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("cssRules"));
	outFields->push(HX_CSTRING("media"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("deleteRule"),
	HX_CSTRING("insertRule"),
	HX_CSTRING("cssRules"),
	HX_CSTRING("media"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSMediaRule_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSMediaRule_obj::__mClass,"__mClass");
};

Class CSSMediaRule_obj::__mClass;

void CSSMediaRule_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSMediaRule"), hx::TCanCast< CSSMediaRule_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSMediaRule_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
