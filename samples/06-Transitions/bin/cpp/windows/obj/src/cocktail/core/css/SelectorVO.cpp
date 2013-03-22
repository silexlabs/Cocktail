#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#include <cocktail/core/css/SelectorComponentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void SelectorVO_obj::__construct(Array< ::cocktail::core::css::SelectorComponentValue > components,::cocktail::core::css::PseudoElementSelectorValue pseudoElement,bool beginsWithClass,::String firstClass,bool beginsWithId,::String firstId,bool beginsWithType,::String firstType,bool isSimpleClassSelector,bool isSimpleIdSelector,bool isSimpleTypeSelector)
{
HX_STACK_PUSH("SelectorVO::new","cocktail/core/css/CSSData.hx",350);
{
	HX_STACK_LINE(351)
	this->components = components;
	HX_STACK_LINE(352)
	this->pseudoElement = pseudoElement;
	HX_STACK_LINE(353)
	this->beginsWithClass = beginsWithClass;
	HX_STACK_LINE(354)
	this->firstClass = firstClass;
	HX_STACK_LINE(355)
	this->beginsWithId = beginsWithId;
	HX_STACK_LINE(356)
	this->firstId = firstId;
	HX_STACK_LINE(357)
	this->beginsWithType = beginsWithType;
	HX_STACK_LINE(358)
	this->firstType = firstType;
	HX_STACK_LINE(359)
	this->isSimpleClassSelector = isSimpleClassSelector;
	HX_STACK_LINE(360)
	this->isSimpleIdSelector = isSimpleIdSelector;
	HX_STACK_LINE(361)
	this->isSimpleTypeSelector = isSimpleTypeSelector;
}
;
	return null();
}

SelectorVO_obj::~SelectorVO_obj() { }

Dynamic SelectorVO_obj::__CreateEmpty() { return  new SelectorVO_obj; }
hx::ObjectPtr< SelectorVO_obj > SelectorVO_obj::__new(Array< ::cocktail::core::css::SelectorComponentValue > components,::cocktail::core::css::PseudoElementSelectorValue pseudoElement,bool beginsWithClass,::String firstClass,bool beginsWithId,::String firstId,bool beginsWithType,::String firstType,bool isSimpleClassSelector,bool isSimpleIdSelector,bool isSimpleTypeSelector)
{  hx::ObjectPtr< SelectorVO_obj > result = new SelectorVO_obj();
	result->__construct(components,pseudoElement,beginsWithClass,firstClass,beginsWithId,firstId,beginsWithType,firstType,isSimpleClassSelector,isSimpleIdSelector,isSimpleTypeSelector);
	return result;}

Dynamic SelectorVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SelectorVO_obj > result = new SelectorVO_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return result;}


SelectorVO_obj::SelectorVO_obj()
{
}

void SelectorVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SelectorVO);
	HX_MARK_MEMBER_NAME(isSimpleTypeSelector,"isSimpleTypeSelector");
	HX_MARK_MEMBER_NAME(isSimpleIdSelector,"isSimpleIdSelector");
	HX_MARK_MEMBER_NAME(isSimpleClassSelector,"isSimpleClassSelector");
	HX_MARK_MEMBER_NAME(firstType,"firstType");
	HX_MARK_MEMBER_NAME(beginsWithType,"beginsWithType");
	HX_MARK_MEMBER_NAME(firstId,"firstId");
	HX_MARK_MEMBER_NAME(beginsWithId,"beginsWithId");
	HX_MARK_MEMBER_NAME(firstClass,"firstClass");
	HX_MARK_MEMBER_NAME(beginsWithClass,"beginsWithClass");
	HX_MARK_MEMBER_NAME(pseudoElement,"pseudoElement");
	HX_MARK_MEMBER_NAME(components,"components");
	HX_MARK_END_CLASS();
}

void SelectorVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(isSimpleTypeSelector,"isSimpleTypeSelector");
	HX_VISIT_MEMBER_NAME(isSimpleIdSelector,"isSimpleIdSelector");
	HX_VISIT_MEMBER_NAME(isSimpleClassSelector,"isSimpleClassSelector");
	HX_VISIT_MEMBER_NAME(firstType,"firstType");
	HX_VISIT_MEMBER_NAME(beginsWithType,"beginsWithType");
	HX_VISIT_MEMBER_NAME(firstId,"firstId");
	HX_VISIT_MEMBER_NAME(beginsWithId,"beginsWithId");
	HX_VISIT_MEMBER_NAME(firstClass,"firstClass");
	HX_VISIT_MEMBER_NAME(beginsWithClass,"beginsWithClass");
	HX_VISIT_MEMBER_NAME(pseudoElement,"pseudoElement");
	HX_VISIT_MEMBER_NAME(components,"components");
}

Dynamic SelectorVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"firstId") ) { return firstId; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"firstType") ) { return firstType; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstClass") ) { return firstClass; }
		if (HX_FIELD_EQ(inName,"components") ) { return components; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"beginsWithId") ) { return beginsWithId; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pseudoElement") ) { return pseudoElement; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"beginsWithType") ) { return beginsWithType; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"beginsWithClass") ) { return beginsWithClass; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isSimpleIdSelector") ) { return isSimpleIdSelector; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isSimpleTypeSelector") ) { return isSimpleTypeSelector; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"isSimpleClassSelector") ) { return isSimpleClassSelector; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SelectorVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"firstId") ) { firstId=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"firstType") ) { firstType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstClass") ) { firstClass=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"components") ) { components=inValue.Cast< Array< ::cocktail::core::css::SelectorComponentValue > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"beginsWithId") ) { beginsWithId=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pseudoElement") ) { pseudoElement=inValue.Cast< ::cocktail::core::css::PseudoElementSelectorValue >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"beginsWithType") ) { beginsWithType=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"beginsWithClass") ) { beginsWithClass=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"isSimpleIdSelector") ) { isSimpleIdSelector=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"isSimpleTypeSelector") ) { isSimpleTypeSelector=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"isSimpleClassSelector") ) { isSimpleClassSelector=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SelectorVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("isSimpleTypeSelector"));
	outFields->push(HX_CSTRING("isSimpleIdSelector"));
	outFields->push(HX_CSTRING("isSimpleClassSelector"));
	outFields->push(HX_CSTRING("firstType"));
	outFields->push(HX_CSTRING("beginsWithType"));
	outFields->push(HX_CSTRING("firstId"));
	outFields->push(HX_CSTRING("beginsWithId"));
	outFields->push(HX_CSTRING("firstClass"));
	outFields->push(HX_CSTRING("beginsWithClass"));
	outFields->push(HX_CSTRING("pseudoElement"));
	outFields->push(HX_CSTRING("components"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("isSimpleTypeSelector"),
	HX_CSTRING("isSimpleIdSelector"),
	HX_CSTRING("isSimpleClassSelector"),
	HX_CSTRING("firstType"),
	HX_CSTRING("beginsWithType"),
	HX_CSTRING("firstId"),
	HX_CSTRING("beginsWithId"),
	HX_CSTRING("firstClass"),
	HX_CSTRING("beginsWithClass"),
	HX_CSTRING("pseudoElement"),
	HX_CSTRING("components"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SelectorVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorVO_obj::__mClass,"__mClass");
};

Class SelectorVO_obj::__mClass;

void SelectorVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SelectorVO"), hx::TCanCast< SelectorVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SelectorVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
