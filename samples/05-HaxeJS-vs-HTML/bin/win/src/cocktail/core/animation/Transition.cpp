#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_animation_Transition
#include <cocktail/core/animation/Transition.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSKeywordValue
#include <cocktail/core/css/CSSKeywordValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CoreStyle
#include <cocktail/core/css/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_geom_CubicBezier
#include <cocktail/core/geom/CubicBezier.h>
#endif
namespace cocktail{
namespace core{
namespace animation{

Void Transition_obj::__construct(int propertyIndex,::cocktail::core::css::CoreStyle target,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Float startValue,Float endValue,Dynamic onComplete,Dynamic onUpdate)
{
HX_STACK_PUSH("Transition::new","cocktail/core/animation/Transition.hx",112);
{
	HX_STACK_LINE(113)
	this->transitionDelay = transitionDelay;
	HX_STACK_LINE(114)
	this->transitionDuration = transitionDuration;
	HX_STACK_LINE(115)
	this->transitionTimingFunction = transitionTimingFunction;
	HX_STACK_LINE(116)
	this->startValue = startValue;
	HX_STACK_LINE(117)
	this->endValue = endValue;
	HX_STACK_LINE(118)
	this->target = target;
	HX_STACK_LINE(119)
	this->propertyIndex = propertyIndex;
	HX_STACK_LINE(120)
	this->onComplete = onComplete;
	HX_STACK_LINE(121)
	this->onUpdate = onUpdate;
	HX_STACK_LINE(122)
	this->_elapsedTime = (int)0;
	HX_STACK_LINE(123)
	this->_cubicBezier = ::cocktail::core::geom::CubicBezier_obj::__new();
}
;
	return null();
}

Transition_obj::~Transition_obj() { }

Dynamic Transition_obj::__CreateEmpty() { return  new Transition_obj; }
hx::ObjectPtr< Transition_obj > Transition_obj::__new(int propertyIndex,::cocktail::core::css::CoreStyle target,Float transitionDuration,Float transitionDelay,::cocktail::core::css::CSSPropertyValue transitionTimingFunction,Float startValue,Float endValue,Dynamic onComplete,Dynamic onUpdate)
{  hx::ObjectPtr< Transition_obj > result = new Transition_obj();
	result->__construct(propertyIndex,target,transitionDuration,transitionDelay,transitionTimingFunction,startValue,endValue,onComplete,onUpdate);
	return result;}

Dynamic Transition_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transition_obj > result = new Transition_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

Float Transition_obj::get_currentValue( ){
	HX_STACK_PUSH("Transition::get_currentValue","cocktail/core/animation/Transition.hx",194);
	HX_STACK_THIS(this);
	HX_STACK_LINE(198)
	Float transitionTime = (this->_elapsedTime - this->transitionDelay);		HX_STACK_VAR(transitionTime,"transitionTime");
	HX_STACK_LINE(201)
	if (((transitionTime < (int)0))){
		HX_STACK_LINE(202)
		return this->startValue;
	}
	HX_STACK_LINE(206)
	Float completePercent = (Float(transitionTime) / Float(this->transitionDuration));		HX_STACK_VAR(completePercent,"completePercent");
	HX_STACK_LINE(208)
	{
		::cocktail::core::css::CSSPropertyValue _switch_1 = (this->transitionTimingFunction);
		switch((_switch_1)->GetIndex()){
			case 4: {
				::cocktail::core::css::CSSKeywordValue value = _switch_1->__Param(0);
{
					HX_STACK_LINE(210)
					{
						::cocktail::core::css::CSSKeywordValue _switch_2 = (value);
						switch((_switch_2)->GetIndex()){
							case 49: {
								HX_STACK_LINE(215)
								this->_cubicBezier->init(0.25,0.1,0.25,1.0);
								HX_STACK_LINE(216)
								return ((((this->endValue - this->startValue)) * this->_cubicBezier->bezierY(completePercent)) + this->startValue);
							}
							;break;
							case 51: {
								HX_STACK_LINE(219)
								this->_cubicBezier->init(0.25,0.1,0.25,1.0);
								HX_STACK_LINE(220)
								return ((((this->endValue - this->startValue)) * this->_cubicBezier->bezierY(completePercent)) + this->startValue);
							}
							;break;
							case 52: {
								HX_STACK_LINE(223)
								this->_cubicBezier->init(0.25,0.1,0.25,1.0);
								HX_STACK_LINE(224)
								return ((((this->endValue - this->startValue)) * this->_cubicBezier->bezierY(completePercent)) + this->startValue);
							}
							;break;
							case 53: {
								HX_STACK_LINE(227)
								this->_cubicBezier->init(0.25,0.1,0.25,1.0);
								HX_STACK_LINE(228)
								return ((((this->endValue - this->startValue)) * this->_cubicBezier->bezierY(completePercent)) + this->startValue);
							}
							;break;
							case 54: {
								HX_STACK_LINE(231)
								return ((this->endValue - this->startValue) + this->startValue);
							}
							;break;
							case 55: {
								HX_STACK_LINE(234)
								return ((((this->endValue - this->startValue)) * (int)0) + this->startValue);
							}
							;break;
							case 50: {
								HX_STACK_LINE(238)
								return ((((this->endValue - this->startValue)) * completePercent) + this->startValue);
							}
							;break;
							default: {
								HX_STACK_LINE(241)
								hx::Throw (HX_CSTRING("Illegal keyword value for transition timing function style"));
							}
						}
					}
				}
			}
			;break;
			case 20: {
				Float y2 = _switch_1->__Param(3);
				Float x2 = _switch_1->__Param(2);
				Float y1 = _switch_1->__Param(1);
				Float x1 = _switch_1->__Param(0);
{
					HX_STACK_LINE(246)
					this->_cubicBezier->init(x1,y1,x2,y2);
					HX_STACK_LINE(247)
					return ((((this->endValue - this->startValue)) * this->_cubicBezier->bezierY(completePercent)) + this->startValue);
				}
			}
			;break;
			case 19: {
				::cocktail::core::css::CSSKeywordValue intervalChange = _switch_1->__Param(1);
				int intervalNumbers = _switch_1->__Param(0);
{
					HX_STACK_LINE(250)
					return ((((this->endValue - this->startValue)) * completePercent) + this->startValue);
				}
			}
			;break;
			default: {
				HX_STACK_LINE(253)
				hx::Throw (HX_CSTRING("Illegal value for transition timing function style"));
			}
		}
	}
	HX_STACK_LINE(208)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(Transition_obj,get_currentValue,return )

bool Transition_obj::get_complete( ){
	HX_STACK_PUSH("Transition::get_complete","cocktail/core/animation/Transition.hx",179);
	HX_STACK_THIS(this);
	HX_STACK_LINE(180)
	if (((this->_elapsedTime >= (this->transitionDelay + this->transitionDuration)))){
		HX_STACK_LINE(181)
		return true;
	}
	HX_STACK_LINE(185)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Transition_obj,get_complete,return )

Void Transition_obj::revert( ){
{
		HX_STACK_PUSH("Transition::revert","cocktail/core/animation/Transition.hx",157);
		HX_STACK_THIS(this);
		HX_STACK_LINE(160)
		this->_elapsedTime = ((this->transitionDuration + this->transitionDelay) - this->_elapsedTime);
		HX_STACK_LINE(163)
		Float oldEndValue = this->endValue;		HX_STACK_VAR(oldEndValue,"oldEndValue");
		HX_STACK_LINE(164)
		this->endValue = this->startValue;
		HX_STACK_LINE(165)
		this->startValue = oldEndValue;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transition_obj,revert,(void))

Void Transition_obj::dispose( ){
{
		HX_STACK_PUSH("Transition::dispose","cocktail/core/animation/Transition.hx",144);
		HX_STACK_THIS(this);
		HX_STACK_LINE(145)
		this->onComplete = null();
		HX_STACK_LINE(146)
		this->onUpdate = null();
		HX_STACK_LINE(147)
		this->transitionTimingFunction = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transition_obj,dispose,(void))

Void Transition_obj::updateTime( Float delta){
{
		HX_STACK_PUSH("Transition::updateTime","cocktail/core/animation/Transition.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_ARG(delta,"delta");
		HX_STACK_LINE(135)
		hx::AddEq(this->_elapsedTime,delta);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transition_obj,updateTime,(void))


Transition_obj::Transition_obj()
{
}

void Transition_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Transition);
	HX_MARK_MEMBER_NAME(complete,"complete");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_MARK_MEMBER_NAME(onUpdate,"onUpdate");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(currentValue,"currentValue");
	HX_MARK_MEMBER_NAME(propertyIndex,"propertyIndex");
	HX_MARK_MEMBER_NAME(_cubicBezier,"_cubicBezier");
	HX_MARK_MEMBER_NAME(_elapsedTime,"_elapsedTime");
	HX_MARK_MEMBER_NAME(endValue,"endValue");
	HX_MARK_MEMBER_NAME(startValue,"startValue");
	HX_MARK_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_MARK_MEMBER_NAME(transitionDelay,"transitionDelay");
	HX_MARK_END_CLASS();
}

void Transition_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(complete,"complete");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(transitionDuration,"transitionDuration");
	HX_VISIT_MEMBER_NAME(onUpdate,"onUpdate");
	HX_VISIT_MEMBER_NAME(onComplete,"onComplete");
	HX_VISIT_MEMBER_NAME(currentValue,"currentValue");
	HX_VISIT_MEMBER_NAME(propertyIndex,"propertyIndex");
	HX_VISIT_MEMBER_NAME(_cubicBezier,"_cubicBezier");
	HX_VISIT_MEMBER_NAME(_elapsedTime,"_elapsedTime");
	HX_VISIT_MEMBER_NAME(endValue,"endValue");
	HX_VISIT_MEMBER_NAME(startValue,"startValue");
	HX_VISIT_MEMBER_NAME(transitionTimingFunction,"transitionTimingFunction");
	HX_VISIT_MEMBER_NAME(transitionDelay,"transitionDelay");
}

Dynamic Transition_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"revert") ) { return revert_dyn(); }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { return inCallProp ? get_complete() : complete; }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { return onUpdate; }
		if (HX_FIELD_EQ(inName,"endValue") ) { return endValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"updateTime") ) { return updateTime_dyn(); }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return onComplete; }
		if (HX_FIELD_EQ(inName,"startValue") ) { return startValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_complete") ) { return get_complete_dyn(); }
		if (HX_FIELD_EQ(inName,"currentValue") ) { return inCallProp ? get_currentValue() : currentValue; }
		if (HX_FIELD_EQ(inName,"_cubicBezier") ) { return _cubicBezier; }
		if (HX_FIELD_EQ(inName,"_elapsedTime") ) { return _elapsedTime; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"propertyIndex") ) { return propertyIndex; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { return transitionDelay; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_currentValue") ) { return get_currentValue_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { return transitionDuration; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { return transitionTimingFunction; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Transition_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::cocktail::core::css::CoreStyle >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"complete") ) { complete=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onUpdate") ) { onUpdate=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endValue") ) { endValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"startValue") ) { startValue=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentValue") ) { currentValue=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cubicBezier") ) { _cubicBezier=inValue.Cast< ::cocktail::core::geom::CubicBezier >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_elapsedTime") ) { _elapsedTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"propertyIndex") ) { propertyIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"transitionDelay") ) { transitionDelay=inValue.Cast< Float >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"transitionDuration") ) { transitionDuration=inValue.Cast< Float >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"transitionTimingFunction") ) { transitionTimingFunction=inValue.Cast< ::cocktail::core::css::CSSPropertyValue >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Transition_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("complete"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("transitionDuration"));
	outFields->push(HX_CSTRING("currentValue"));
	outFields->push(HX_CSTRING("propertyIndex"));
	outFields->push(HX_CSTRING("_cubicBezier"));
	outFields->push(HX_CSTRING("_elapsedTime"));
	outFields->push(HX_CSTRING("endValue"));
	outFields->push(HX_CSTRING("startValue"));
	outFields->push(HX_CSTRING("transitionTimingFunction"));
	outFields->push(HX_CSTRING("transitionDelay"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_currentValue"),
	HX_CSTRING("get_complete"),
	HX_CSTRING("revert"),
	HX_CSTRING("dispose"),
	HX_CSTRING("updateTime"),
	HX_CSTRING("complete"),
	HX_CSTRING("target"),
	HX_CSTRING("transitionDuration"),
	HX_CSTRING("onUpdate"),
	HX_CSTRING("onComplete"),
	HX_CSTRING("currentValue"),
	HX_CSTRING("propertyIndex"),
	HX_CSTRING("_cubicBezier"),
	HX_CSTRING("_elapsedTime"),
	HX_CSTRING("endValue"),
	HX_CSTRING("startValue"),
	HX_CSTRING("transitionTimingFunction"),
	HX_CSTRING("transitionDelay"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Transition_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Transition_obj::__mClass,"__mClass");
};

Class Transition_obj::__mClass;

void Transition_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.animation.Transition"), hx::TCanCast< Transition_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Transition_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace animation
