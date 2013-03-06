#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void CSSRule_obj::__construct(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{
HX_STACK_PUSH("CSSRule::new","cocktail/core/css/CSSRule.hx",78);
{
	HX_STACK_LINE(79)
	this->parentStyleSheet = parentStyleSheet;
	HX_STACK_LINE(80)
	this->parentRule = parentRule;
}
;
	return null();
}

CSSRule_obj::~CSSRule_obj() { }

Dynamic CSSRule_obj::__CreateEmpty() { return  new CSSRule_obj; }
hx::ObjectPtr< CSSRule_obj > CSSRule_obj::__new(::cocktail::core::css::CSSStyleSheet parentStyleSheet,::cocktail::core::css::CSSRule parentRule)
{  hx::ObjectPtr< CSSRule_obj > result = new CSSRule_obj();
	result->__construct(parentStyleSheet,parentRule);
	return result;}

Dynamic CSSRule_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CSSRule_obj > result = new CSSRule_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String CSSRule_obj::set_cssText( ::String value){
	HX_STACK_PUSH("CSSRule::set_cssText","cocktail/core/css/CSSRule.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(93)
	return this->cssText = value;
}


HX_DEFINE_DYNAMIC_FUNC1(CSSRule_obj,set_cssText,return )

::String CSSRule_obj::get_cssText( ){
	HX_STACK_PUSH("CSSRule::get_cssText","cocktail/core/css/CSSRule.hx",88);
	HX_STACK_THIS(this);
	HX_STACK_LINE(88)
	return this->cssText;
}


HX_DEFINE_DYNAMIC_FUNC0(CSSRule_obj,get_cssText,return )

int CSSRule_obj::STYLE_RULE;

int CSSRule_obj::IMPORT_RULE;

int CSSRule_obj::MEDIA_RULE;

int CSSRule_obj::FONT_FACE_RULE;


CSSRule_obj::CSSRule_obj()
{
}

void CSSRule_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CSSRule);
	HX_MARK_MEMBER_NAME(parentStyleSheet,"parentStyleSheet");
	HX_MARK_MEMBER_NAME(parentRule,"parentRule");
	HX_MARK_MEMBER_NAME(cssText,"cssText");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_END_CLASS();
}

void CSSRule_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(parentStyleSheet,"parentStyleSheet");
	HX_VISIT_MEMBER_NAME(parentRule,"parentRule");
	HX_VISIT_MEMBER_NAME(cssText,"cssText");
	HX_VISIT_MEMBER_NAME(type,"type");
}

Dynamic CSSRule_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cssText") ) { return inCallProp ? get_cssText() : cssText; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"STYLE_RULE") ) { return STYLE_RULE; }
		if (HX_FIELD_EQ(inName,"MEDIA_RULE") ) { return MEDIA_RULE; }
		if (HX_FIELD_EQ(inName,"parentRule") ) { return parentRule; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"IMPORT_RULE") ) { return IMPORT_RULE; }
		if (HX_FIELD_EQ(inName,"set_cssText") ) { return set_cssText_dyn(); }
		if (HX_FIELD_EQ(inName,"get_cssText") ) { return get_cssText_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"FONT_FACE_RULE") ) { return FONT_FACE_RULE; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parentStyleSheet") ) { return parentStyleSheet; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CSSRule_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"cssText") ) { if (inCallProp) return set_cssText(inValue);cssText=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"STYLE_RULE") ) { STYLE_RULE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MEDIA_RULE") ) { MEDIA_RULE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parentRule") ) { parentRule=inValue.Cast< ::cocktail::core::css::CSSRule >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"IMPORT_RULE") ) { IMPORT_RULE=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"FONT_FACE_RULE") ) { FONT_FACE_RULE=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"parentStyleSheet") ) { parentStyleSheet=inValue.Cast< ::cocktail::core::css::CSSStyleSheet >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CSSRule_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("parentStyleSheet"));
	outFields->push(HX_CSTRING("parentRule"));
	outFields->push(HX_CSTRING("cssText"));
	outFields->push(HX_CSTRING("type"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("STYLE_RULE"),
	HX_CSTRING("IMPORT_RULE"),
	HX_CSTRING("MEDIA_RULE"),
	HX_CSTRING("FONT_FACE_RULE"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_cssText"),
	HX_CSTRING("get_cssText"),
	HX_CSTRING("parentStyleSheet"),
	HX_CSTRING("parentRule"),
	HX_CSTRING("cssText"),
	HX_CSTRING("type"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CSSRule_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(CSSRule_obj::STYLE_RULE,"STYLE_RULE");
	HX_MARK_MEMBER_NAME(CSSRule_obj::IMPORT_RULE,"IMPORT_RULE");
	HX_MARK_MEMBER_NAME(CSSRule_obj::MEDIA_RULE,"MEDIA_RULE");
	HX_MARK_MEMBER_NAME(CSSRule_obj::FONT_FACE_RULE,"FONT_FACE_RULE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CSSRule_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CSSRule_obj::STYLE_RULE,"STYLE_RULE");
	HX_VISIT_MEMBER_NAME(CSSRule_obj::IMPORT_RULE,"IMPORT_RULE");
	HX_VISIT_MEMBER_NAME(CSSRule_obj::MEDIA_RULE,"MEDIA_RULE");
	HX_VISIT_MEMBER_NAME(CSSRule_obj::FONT_FACE_RULE,"FONT_FACE_RULE");
};

Class CSSRule_obj::__mClass;

void CSSRule_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.CSSRule"), hx::TCanCast< CSSRule_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void CSSRule_obj::__boot()
{
	STYLE_RULE= (int)1;
	IMPORT_RULE= (int)3;
	MEDIA_RULE= (int)4;
	FONT_FACE_RULE= (int)5;
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
