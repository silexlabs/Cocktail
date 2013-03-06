#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_SelectorSpecificityVO
#include <cocktail/core/css/SelectorSpecificityVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void SelectorSpecificityVO_obj::__construct()
{
HX_STACK_PUSH("SelectorSpecificityVO::new","cocktail/core/css/CSSData.hx",274);
{
	HX_STACK_LINE(275)
	this->idSelectorsNumber = (int)0;
	HX_STACK_LINE(276)
	this->classAttributesAndPseudoClassesNumber = (int)0;
	HX_STACK_LINE(277)
	this->typeAndPseudoElementsNumber = (int)0;
}
;
	return null();
}

SelectorSpecificityVO_obj::~SelectorSpecificityVO_obj() { }

Dynamic SelectorSpecificityVO_obj::__CreateEmpty() { return  new SelectorSpecificityVO_obj; }
hx::ObjectPtr< SelectorSpecificityVO_obj > SelectorSpecificityVO_obj::__new()
{  hx::ObjectPtr< SelectorSpecificityVO_obj > result = new SelectorSpecificityVO_obj();
	result->__construct();
	return result;}

Dynamic SelectorSpecificityVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SelectorSpecificityVO_obj > result = new SelectorSpecificityVO_obj();
	result->__construct();
	return result;}


SelectorSpecificityVO_obj::SelectorSpecificityVO_obj()
{
}

void SelectorSpecificityVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SelectorSpecificityVO);
	HX_MARK_MEMBER_NAME(typeAndPseudoElementsNumber,"typeAndPseudoElementsNumber");
	HX_MARK_MEMBER_NAME(classAttributesAndPseudoClassesNumber,"classAttributesAndPseudoClassesNumber");
	HX_MARK_MEMBER_NAME(idSelectorsNumber,"idSelectorsNumber");
	HX_MARK_END_CLASS();
}

void SelectorSpecificityVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(typeAndPseudoElementsNumber,"typeAndPseudoElementsNumber");
	HX_VISIT_MEMBER_NAME(classAttributesAndPseudoClassesNumber,"classAttributesAndPseudoClassesNumber");
	HX_VISIT_MEMBER_NAME(idSelectorsNumber,"idSelectorsNumber");
}

Dynamic SelectorSpecificityVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"idSelectorsNumber") ) { return idSelectorsNumber; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"typeAndPseudoElementsNumber") ) { return typeAndPseudoElementsNumber; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"classAttributesAndPseudoClassesNumber") ) { return classAttributesAndPseudoClassesNumber; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SelectorSpecificityVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"idSelectorsNumber") ) { idSelectorsNumber=inValue.Cast< int >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"typeAndPseudoElementsNumber") ) { typeAndPseudoElementsNumber=inValue.Cast< int >(); return inValue; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"classAttributesAndPseudoClassesNumber") ) { classAttributesAndPseudoClassesNumber=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SelectorSpecificityVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("typeAndPseudoElementsNumber"));
	outFields->push(HX_CSTRING("classAttributesAndPseudoClassesNumber"));
	outFields->push(HX_CSTRING("idSelectorsNumber"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("typeAndPseudoElementsNumber"),
	HX_CSTRING("classAttributesAndPseudoClassesNumber"),
	HX_CSTRING("idSelectorsNumber"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SelectorSpecificityVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorSpecificityVO_obj::__mClass,"__mClass");
};

Class SelectorSpecificityVO_obj::__mClass;

void SelectorSpecificityVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SelectorSpecificityVO"), hx::TCanCast< SelectorSpecificityVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SelectorSpecificityVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
