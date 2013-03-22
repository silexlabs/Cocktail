#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_PendingAnimationVO
#include <cocktail/core/animation/PendingAnimationVO.h>
#endif
namespace cocktail{
namespace core{
namespace animation{

Void PendingAnimationVO_obj::__construct()
{
HX_STACK_PUSH("PendingAnimationVO::new","cocktail/core/animation/AnimationData.hx",28);
{
}
;
	return null();
}

PendingAnimationVO_obj::~PendingAnimationVO_obj() { }

Dynamic PendingAnimationVO_obj::__CreateEmpty() { return  new PendingAnimationVO_obj; }
hx::ObjectPtr< PendingAnimationVO_obj > PendingAnimationVO_obj::__new()
{  hx::ObjectPtr< PendingAnimationVO_obj > result = new PendingAnimationVO_obj();
	result->__construct();
	return result;}

Dynamic PendingAnimationVO_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PendingAnimationVO_obj > result = new PendingAnimationVO_obj();
	result->__construct();
	return result;}


PendingAnimationVO_obj::PendingAnimationVO_obj()
{
}

void PendingAnimationVO_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PendingAnimationVO);
	HX_MARK_MEMBER_NAME(startValue,"startValue");
	HX_MARK_MEMBER_NAME(propertyIndex,"propertyIndex");
	HX_MARK_END_CLASS();
}

void PendingAnimationVO_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(startValue,"startValue");
	HX_VISIT_MEMBER_NAME(propertyIndex,"propertyIndex");
}

Dynamic PendingAnimationVO_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"startValue") ) { return startValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"propertyIndex") ) { return propertyIndex; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PendingAnimationVO_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"startValue") ) { startValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"propertyIndex") ) { propertyIndex=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PendingAnimationVO_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("startValue"));
	outFields->push(HX_CSTRING("propertyIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("startValue"),
	HX_CSTRING("propertyIndex"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PendingAnimationVO_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PendingAnimationVO_obj::__mClass,"__mClass");
};

Class PendingAnimationVO_obj::__mClass;

void PendingAnimationVO_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.animation.PendingAnimationVO"), hx::TCanCast< PendingAnimationVO_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PendingAnimationVO_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace animation
