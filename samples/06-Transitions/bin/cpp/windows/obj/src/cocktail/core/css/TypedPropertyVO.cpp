#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#include <cocktail/core/css/TypedPropertyVO.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void TypedPropertyVO_obj::__construct()
{
HX_STACK_PUSH("TypedPropertyVO::new","cocktail/core/css/CSSData.hx",23);
{
}
;
	return null();
}

TypedPropertyVO_obj::~TypedPropertyVO_obj() { }

Dynamic TypedPropertyVO_obj::__CreateEmpty() { return  new TypedPropertyVO_obj; }
hx::ObjectPtr< TypedPropertyVO_obj > TypedPropertyVO_obj::__new()
{  hx::ObjectPtr< TypedPropertyVO_obj > result = new TypedPropertyVO_obj();
	result->__construct();
	return result;}

Dynamic TypedPropertyVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TypedPropertyVO_obj > result = new TypedPropertyVO_obj();
	result->__construct();
	return result;}


TypedPropertyVO_obj::TypedPropertyVO_obj()
{
}

void TypedPropertyVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TypedPropertyVO);
	HX_MARK_MEMBER_NAME(important,"important");
	HX_MARK_MEMBER_NAME(typedValue,"typedValue");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_END_CLASS();
}

void TypedPropertyVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(important,"important");
	HX_VISIT_MEMBER_NAME(typedValue,"typedValue");
	HX_VISIT_MEMBER_NAME(index,"index");
}

Dynamic TypedPropertyVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"important") ) { return important; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"typedValue") ) { return typedValue; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TypedPropertyVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"important") ) { important=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"typedValue") ) { typedValue=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TypedPropertyVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("important"));
	outFields->push(HX_CSTRING("typedValue"));
	outFields->push(HX_CSTRING("index"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("important"),
	HX_CSTRING("typedValue"),
	HX_CSTRING("index"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TypedPropertyVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TypedPropertyVO_obj::__mClass,"__mClass");
};

Class TypedPropertyVO_obj::__mClass;

void TypedPropertyVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.TypedPropertyVO"), hx::TCanCast< TypedPropertyVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TypedPropertyVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
