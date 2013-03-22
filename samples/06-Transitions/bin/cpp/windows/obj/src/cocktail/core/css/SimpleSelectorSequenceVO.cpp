#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void SimpleSelectorSequenceVO_obj::__construct(::cocktail::core::css::SimpleSelectorSequenceStartValue startValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors)
{
HX_STACK_PUSH("SimpleSelectorSequenceVO::new","cocktail/core/css/CSSData.hx",387);
{
	HX_STACK_LINE(388)
	this->startValue = startValue;
	HX_STACK_LINE(389)
	this->simpleSelectors = simpleSelectors;
}
;
	return null();
}

SimpleSelectorSequenceVO_obj::~SimpleSelectorSequenceVO_obj() { }

Dynamic SimpleSelectorSequenceVO_obj::__CreateEmpty() { return  new SimpleSelectorSequenceVO_obj; }
hx::ObjectPtr< SimpleSelectorSequenceVO_obj > SimpleSelectorSequenceVO_obj::__new(::cocktail::core::css::SimpleSelectorSequenceStartValue startValue,Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors)
{  hx::ObjectPtr< SimpleSelectorSequenceVO_obj > result = new SimpleSelectorSequenceVO_obj();
	result->__construct(startValue,simpleSelectors);
	return result;}

Dynamic SimpleSelectorSequenceVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SimpleSelectorSequenceVO_obj > result = new SimpleSelectorSequenceVO_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


SimpleSelectorSequenceVO_obj::SimpleSelectorSequenceVO_obj()
{
}

void SimpleSelectorSequenceVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SimpleSelectorSequenceVO);
	HX_MARK_MEMBER_NAME(simpleSelectors,"simpleSelectors");
	HX_MARK_MEMBER_NAME(startValue,"startValue");
	HX_MARK_END_CLASS();
}

void SimpleSelectorSequenceVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(simpleSelectors,"simpleSelectors");
	HX_VISIT_MEMBER_NAME(startValue,"startValue");
}

Dynamic SimpleSelectorSequenceVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"startValue") ) { return startValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"simpleSelectors") ) { return simpleSelectors; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SimpleSelectorSequenceVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"startValue") ) { startValue=inValue.Cast< ::cocktail::core::css::SimpleSelectorSequenceStartValue >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"simpleSelectors") ) { simpleSelectors=inValue.Cast< Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SimpleSelectorSequenceVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("simpleSelectors"));
	outFields->push(HX_CSTRING("startValue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("simpleSelectors"),
	HX_CSTRING("startValue"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SimpleSelectorSequenceVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SimpleSelectorSequenceVO_obj::__mClass,"__mClass");
};

Class SimpleSelectorSequenceVO_obj::__mClass;

void SimpleSelectorSequenceVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SimpleSelectorSequenceVO"), hx::TCanCast< SimpleSelectorSequenceVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SimpleSelectorSequenceVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
