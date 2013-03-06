#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_Event
#include <cocktail/core/event/Event.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchEvent
#include <cocktail/core/event/TouchEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_TouchList
#include <cocktail/core/event/TouchList.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_multitouch_MultiTouchManager
#include <cocktail/core/multitouch/MultiTouchManager.h>
#endif
namespace cocktail{
namespace core{
namespace multitouch{

Void MultiTouchManager_obj::__construct()
{
HX_STACK_PUSH("MultiTouchManager::new","cocktail/core/multitouch/MultiTouchManager.hx",40);
{
	HX_STACK_LINE(40)
	this->_touches = Dynamic( Array_obj<Dynamic>::__new() );
}
;
	return null();
}

MultiTouchManager_obj::~MultiTouchManager_obj() { }

Dynamic MultiTouchManager_obj::__CreateEmpty() { return  new MultiTouchManager_obj; }
hx::ObjectPtr< MultiTouchManager_obj > MultiTouchManager_obj::__new()
{  hx::ObjectPtr< MultiTouchManager_obj > result = new MultiTouchManager_obj();
	result->__construct();
	return result;}

Dynamic MultiTouchManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MultiTouchManager_obj > result = new MultiTouchManager_obj();
	result->__construct();
	return result;}

Dynamic MultiTouchManager_obj::getTouchByIdentifier( int identifier){
	HX_STACK_PUSH("MultiTouchManager::getTouchByIdentifier","cocktail/core/multitouch/MultiTouchManager.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_ARG(identifier,"identifier");
	HX_STACK_LINE(207)
	int length = this->_touches->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(208)
	{
		HX_STACK_LINE(208)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(208)
		while(((_g < length))){
			HX_STACK_LINE(208)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(210)
			Dynamic touch = this->_touches->__GetItem(i);		HX_STACK_VAR(touch,"touch");
			HX_STACK_LINE(211)
			if (((touch->__Field(HX_CSTRING("identifier"),true) == identifier))){
				HX_STACK_LINE(212)
				return touch;
			}
		}
	}
	HX_STACK_LINE(217)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MultiTouchManager_obj,getTouchByIdentifier,return )

::cocktail::core::event::TouchList MultiTouchManager_obj::getTouchesByTarget( ::cocktail::core::html::HTMLElement target){
	HX_STACK_PUSH("MultiTouchManager::getTouchesByTarget","cocktail/core/multitouch/MultiTouchManager.hx",184);
	HX_STACK_THIS(this);
	HX_STACK_ARG(target,"target");
	HX_STACK_LINE(185)
	Dynamic targetTouches = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(targetTouches,"targetTouches");
	HX_STACK_LINE(187)
	int length = this->_touches->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(188)
	{
		HX_STACK_LINE(188)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(188)
		while(((_g < length))){
			HX_STACK_LINE(188)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(190)
			Dynamic touch = this->_touches->__GetItem(i);		HX_STACK_VAR(touch,"touch");
			HX_STACK_LINE(191)
			if (((touch->__Field(HX_CSTRING("target"),true) == target))){
				HX_STACK_LINE(192)
				targetTouches->__Field(HX_CSTRING("push"),true)(touch);
			}
		}
	}
	HX_STACK_LINE(197)
	return ::cocktail::core::event::TouchList_obj::__new(targetTouches);
}


HX_DEFINE_DYNAMIC_FUNC1(MultiTouchManager_obj,getTouchesByTarget,return )

Void MultiTouchManager_obj::initTouchEvent( ::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::event::TouchList targetTouches,::cocktail::core::event::TouchList changedTouches){
{
		HX_STACK_PUSH("MultiTouchManager::initTouchEvent","cocktail/core/multitouch/MultiTouchManager.hx",174);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_ARG(targetTouches,"targetTouches");
		HX_STACK_ARG(changedTouches,"changedTouches");
		HX_STACK_LINE(174)
		touchEvent->initTouchEvent(touchEvent->type,true,true,null(),0.0,::cocktail::core::event::TouchList_obj::__new(this->_touches),targetTouches,changedTouches,false,false,false,false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MultiTouchManager_obj,initTouchEvent,(void))

Void MultiTouchManager_obj::updatePagePosition( Dynamic touch){
{
		HX_STACK_PUSH("MultiTouchManager::updatePagePosition","cocktail/core/multitouch/MultiTouchManager.hx",159);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touch,"touch");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MultiTouchManager_obj,updatePagePosition,(void))

Void MultiTouchManager_obj::updateStoredTouch( Dynamic storedTouch,Dynamic touch){
{
		HX_STACK_PUSH("MultiTouchManager::updateStoredTouch","cocktail/core/multitouch/MultiTouchManager.hx",145);
		HX_STACK_THIS(this);
		HX_STACK_ARG(storedTouch,"storedTouch");
		HX_STACK_ARG(touch,"touch");
		HX_STACK_LINE(146)
		storedTouch->__FieldRef(HX_CSTRING("clientX")) = touch->__Field(HX_CSTRING("clientX"),true);
		HX_STACK_LINE(147)
		storedTouch->__FieldRef(HX_CSTRING("clientY")) = touch->__Field(HX_CSTRING("clientY"),true);
		HX_STACK_LINE(148)
		storedTouch->__FieldRef(HX_CSTRING("screenX")) = touch->__Field(HX_CSTRING("screenX"),true);
		HX_STACK_LINE(149)
		storedTouch->__FieldRef(HX_CSTRING("screenY")) = touch->__Field(HX_CSTRING("screenY"),true);
		HX_STACK_LINE(151)
		this->updatePagePosition(storedTouch);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MultiTouchManager_obj,updateStoredTouch,(void))

Void MultiTouchManager_obj::updateTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent){
{
		HX_STACK_PUSH("MultiTouchManager::updateTouch","cocktail/core/multitouch/MultiTouchManager.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touch,"touch");
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_LINE(133)
		Dynamic storedTouch = this->getTouchByIdentifier(touch->__Field(HX_CSTRING("identifier"),true));		HX_STACK_VAR(storedTouch,"storedTouch");
		HX_STACK_LINE(134)
		this->updateStoredTouch(storedTouch,touch);
		HX_STACK_LINE(136)
		this->initTouchEvent(touchEvent,this->getTouchesByTarget(touch->__Field(HX_CSTRING("target"),true)),::cocktail::core::event::TouchList_obj::__new(Dynamic( Array_obj<Dynamic>::__new().Add(touch))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MultiTouchManager_obj,updateTouch,(void))

Void MultiTouchManager_obj::unregisterTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent){
{
		HX_STACK_PUSH("MultiTouchManager::unregisterTouch","cocktail/core/multitouch/MultiTouchManager.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touch,"touch");
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_LINE(109)
		Dynamic storedTouch = this->getTouchByIdentifier(touch->__Field(HX_CSTRING("identifier"),true));		HX_STACK_VAR(storedTouch,"storedTouch");
		HX_STACK_LINE(112)
		this->updateStoredTouch(storedTouch,touch);
		HX_STACK_LINE(117)
		this->initTouchEvent(touchEvent,this->getTouchesByTarget(touch->__Field(HX_CSTRING("target"),true)),::cocktail::core::event::TouchList_obj::__new(Dynamic( Array_obj<Dynamic>::__new().Add(touch))));
		HX_STACK_LINE(120)
		this->_touches->__Field(HX_CSTRING("remove"),true)(storedTouch);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MultiTouchManager_obj,unregisterTouch,(void))

Void MultiTouchManager_obj::registerTouch( Dynamic touch,::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::html::HTMLElement target){
{
		HX_STACK_PUSH("MultiTouchManager::registerTouch","cocktail/core/multitouch/MultiTouchManager.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touch,"touch");
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(88)
		touch->__FieldRef(HX_CSTRING("target")) = target;
		HX_STACK_LINE(89)
		this->updatePagePosition(touch);
		HX_STACK_LINE(92)
		this->_touches->__Field(HX_CSTRING("push"),true)(touch);
		HX_STACK_LINE(95)
		this->initTouchEvent(touchEvent,this->getTouchesByTarget(target),::cocktail::core::event::TouchList_obj::__new(Dynamic( Array_obj<Dynamic>::__new().Add(touch))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MultiTouchManager_obj,registerTouch,(void))

Void MultiTouchManager_obj::setUpTouchEvent( ::cocktail::core::event::TouchEvent touchEvent,::cocktail::core::html::HTMLElement target){
{
		HX_STACK_PUSH("MultiTouchManager::setUpTouchEvent","cocktail/core/multitouch/MultiTouchManager.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(touchEvent,"touchEvent");
		HX_STACK_ARG(target,"target");
		HX_STACK_LINE(59)
		Dynamic touch = touchEvent->touches->item((int)0);		HX_STACK_VAR(touch,"touch");
		HX_STACK_LINE(61)
		::String _switch_1 = (touchEvent->type);
		if (  ( _switch_1==HX_CSTRING("touchstart"))){
			HX_STACK_LINE(63)
			this->registerTouch(touch,touchEvent,target);
		}
		else if (  ( _switch_1==HX_CSTRING("touchend"))){
			HX_STACK_LINE(66)
			this->unregisterTouch(touch,touchEvent);
		}
		else if (  ( _switch_1==HX_CSTRING("touchmove"))){
			HX_STACK_LINE(69)
			this->updateTouch(touch,touchEvent);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MultiTouchManager_obj,setUpTouchEvent,(void))


MultiTouchManager_obj::MultiTouchManager_obj()
{
}

void MultiTouchManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MultiTouchManager);
	HX_MARK_MEMBER_NAME(_touches,"_touches");
	HX_MARK_END_CLASS();
}

void MultiTouchManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_touches,"_touches");
}

Dynamic MultiTouchManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_touches") ) { return _touches; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"updateTouch") ) { return updateTouch_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"registerTouch") ) { return registerTouch_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"initTouchEvent") ) { return initTouchEvent_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"unregisterTouch") ) { return unregisterTouch_dyn(); }
		if (HX_FIELD_EQ(inName,"setUpTouchEvent") ) { return setUpTouchEvent_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"updateStoredTouch") ) { return updateStoredTouch_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"getTouchesByTarget") ) { return getTouchesByTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"updatePagePosition") ) { return updatePagePosition_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getTouchByIdentifier") ) { return getTouchByIdentifier_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MultiTouchManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_touches") ) { _touches=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MultiTouchManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_touches"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getTouchByIdentifier"),
	HX_CSTRING("getTouchesByTarget"),
	HX_CSTRING("initTouchEvent"),
	HX_CSTRING("updatePagePosition"),
	HX_CSTRING("updateStoredTouch"),
	HX_CSTRING("updateTouch"),
	HX_CSTRING("unregisterTouch"),
	HX_CSTRING("registerTouch"),
	HX_CSTRING("setUpTouchEvent"),
	HX_CSTRING("_touches"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MultiTouchManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MultiTouchManager_obj::__mClass,"__mClass");
};

Class MultiTouchManager_obj::__mClass;

void MultiTouchManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.multitouch.MultiTouchManager"), hx::TCanCast< MultiTouchManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MultiTouchManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace multitouch
