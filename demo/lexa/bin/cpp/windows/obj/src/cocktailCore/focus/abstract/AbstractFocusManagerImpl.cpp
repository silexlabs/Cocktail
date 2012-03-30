#include <hxcpp.h>

#ifndef INCLUDED_cocktailCore_focus_abstract_AbstractFocusManagerImpl
#include <cocktailCore/focus/abstract/AbstractFocusManagerImpl.h>
#endif
#ifndef INCLUDED_core_dom_Element
#include <core/dom/Element.h>
#endif
#ifndef INCLUDED_core_dom_Node
#include <core/dom/Node.h>
#endif
#ifndef INCLUDED_core_event_Event
#include <core/event/Event.h>
#endif
#ifndef INCLUDED_core_event_IEventTarget
#include <core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_core_event_KeyboardEvent
#include <core/event/KeyboardEvent.h>
#endif
#ifndef INCLUDED_core_event_MouseEvent
#include <core/event/MouseEvent.h>
#endif
#ifndef INCLUDED_core_event_UIEvent
#include <core/event/UIEvent.h>
#endif
#ifndef INCLUDED_core_html_AbstractHTMLElement
#include <core/html/AbstractHTMLElement.h>
#endif
#ifndef INCLUDED_core_html_HTMLBodyElement
#include <core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_port_flash_player_HTMLElement
#include <port/flash_player/HTMLElement.h>
#endif
namespace cocktailCore{
namespace focus{
namespace abstract{

Void AbstractFocusManagerImpl_obj::__construct()
{
{
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",71)
	this->initKeyboardListeners();
}
;
	return null();
}

AbstractFocusManagerImpl_obj::~AbstractFocusManagerImpl_obj() { }

Dynamic AbstractFocusManagerImpl_obj::__CreateEmpty() { return  new AbstractFocusManagerImpl_obj; }
hx::ObjectPtr< AbstractFocusManagerImpl_obj > AbstractFocusManagerImpl_obj::__new()
{  hx::ObjectPtr< AbstractFocusManagerImpl_obj > result = new AbstractFocusManagerImpl_obj();
	result->__construct();
	return result;}

Dynamic AbstractFocusManagerImpl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AbstractFocusManagerImpl_obj > result = new AbstractFocusManagerImpl_obj();
	result->__construct();
	return result;}

Void AbstractFocusManagerImpl_obj::initKeyboardListeners( ){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::initKeyboardListeners")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFocusManagerImpl_obj,initKeyboardListeners,(void))

Void AbstractFocusManagerImpl_obj::invalidate( ){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::invalidate")
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",97)
		(this->_tabList == null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFocusManagerImpl_obj,invalidate,(void))

Void AbstractFocusManagerImpl_obj::onKeyDown( ::core::event::KeyboardEvent keyboardEvent){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::onKeyDown")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,onKeyDown,(void))

Void AbstractFocusManagerImpl_obj::onKeyUp( ::core::event::KeyboardEvent keyEventData){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::onKeyUp")
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",138)
		if (((this->_activeElement->get_onKeyUp() != null()))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",140)
			this->_activeElement->get_onKeyUp()(keyEventData).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,onKeyUp,(void))

Void AbstractFocusManagerImpl_obj::doTabFocus( bool reverse){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::doTabFocus")
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",158)
		if (((this->_tabList == null()))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",159)
			this->_tabList = this->buildTabList(this->_bodyElement);
		}
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",167)
		if (((this->getActiveElement() != this->_bodyElement))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",168)
			if (((reverse == false))){
				HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",170)
				if (((this->_tabListIndex == (this->_tabList->length - (int)1)))){
					HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",172)
					this->_tabListIndex = (int)0;
				}
				else{
					HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",176)
					(this->_tabListIndex)++;
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",181)
				if (((this->_tabListIndex == (int)0))){
					HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",183)
					this->_tabListIndex = (this->_tabList->length - (int)1);
				}
				else{
					HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",187)
					(this->_tabListIndex)--;
				}
			}
		}
		else{
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",196)
			if (((reverse == false))){
				HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",198)
				this->_tabListIndex = (int)0;
			}
			else{
				HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",202)
				this->_tabListIndex = (this->_tabList->length - (int)1);
			}
		}
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",208)
		this->setActiveElement(this->_tabList->__get(this->_tabListIndex));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,doTabFocus,(void))

Array< ::port::flash_player::HTMLElement > AbstractFocusManagerImpl_obj::buildTabList( ::port::flash_player::HTMLElement htmlElement){
	HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::buildTabList")
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",225)
	this->_tabListIndex = (int)0;
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",228)
	Array< ::port::flash_player::HTMLElement > orderedTabList = Array_obj< ::port::flash_player::HTMLElement >::__new();
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",231)
	Array< ::port::flash_player::HTMLElement > indexedTabList = Array_obj< ::port::flash_player::HTMLElement >::__new();
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",234)
	this->doBuildTabList(htmlElement,orderedTabList,indexedTabList);
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",237)
	{
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",237)
		int _g1 = (int)0;
		int _g = orderedTabList->length;
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",237)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",237)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",239)
			indexedTabList->push(orderedTabList->__get(i));
		}
	}
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",242)
	return indexedTabList;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,buildTabList,return )

Void AbstractFocusManagerImpl_obj::doBuildTabList( ::port::flash_player::HTMLElement htmlElement,Array< ::port::flash_player::HTMLElement > orderedTabList,Array< ::port::flash_player::HTMLElement > indexedTabList){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::doBuildTabList")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(AbstractFocusManagerImpl_obj,doBuildTabList,(void))

Void AbstractFocusManagerImpl_obj::simulateMouseClick( ::core::event::KeyboardEvent keyEventData){
{
		HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::simulateMouseClick")
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",326)
		if (((this->getActiveElement()->get_onMouseDown() != null()))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",330)
			::core::event::MouseEvent mouseEvent = ::core::event::MouseEvent_obj::__new(HX_CSTRING("mousedown"),this->_activeElement,0.0,0.0,0.0,0.0,0.0,false,false,false);
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",333)
			this->getActiveElement()->get_onMouseDown()(mouseEvent).Cast< Void >();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,simulateMouseClick,(void))

::port::flash_player::HTMLElement AbstractFocusManagerImpl_obj::setActiveElement( ::port::flash_player::HTMLElement value){
	HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::setActiveElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",351)
	if (((this->_activeElement != null()))){
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",352)
		if (((this->_activeElement->get_onBlur() != null()))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",354)
			this->_activeElement->get_onBlur()(::core::event::Event_obj::__new(HX_CSTRING("blur"),this->_activeElement)).Cast< Void >();
		}
	}
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",361)
	if (((value == null()))){
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",362)
		value = this->_bodyElement;
	}
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",368)
	if (((value != this->_activeElement))){
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",370)
		this->_activeElement = value;
		HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",371)
		if (((this->_activeElement->get_onFocus() != null()))){
			HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",372)
			this->_activeElement->get_onFocus()(::core::event::Event_obj::__new(HX_CSTRING("focus"),this->_activeElement)).Cast< Void >();
		}
	}
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",377)
	return this->_activeElement;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,setActiveElement,return )

::port::flash_player::HTMLElement AbstractFocusManagerImpl_obj::getActiveElement( ){
	HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::getActiveElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",381)
	return this->_activeElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFocusManagerImpl_obj,getActiveElement,return )

::core::html::HTMLBodyElement AbstractFocusManagerImpl_obj::setBodyElement( ::core::html::HTMLBodyElement value){
	HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::setBodyElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",391)
	this->_bodyElement = value;
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",392)
	this->setActiveElement(null());
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",394)
	this->invalidate();
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",397)
	return this->_bodyElement;
}


HX_DEFINE_DYNAMIC_FUNC1(AbstractFocusManagerImpl_obj,setBodyElement,return )

::core::html::HTMLBodyElement AbstractFocusManagerImpl_obj::getBodyElement( ){
	HX_SOURCE_PUSH("AbstractFocusManagerImpl_obj::getBodyElement")
	HX_SOURCE_POS("../../src/cocktailCore/focus/abstract/AbstractFocusManagerImpl.hx",401)
	return this->_bodyElement;
}


HX_DEFINE_DYNAMIC_FUNC0(AbstractFocusManagerImpl_obj,getBodyElement,return )


AbstractFocusManagerImpl_obj::AbstractFocusManagerImpl_obj()
{
}

void AbstractFocusManagerImpl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AbstractFocusManagerImpl);
	HX_MARK_MEMBER_NAME(_bodyElement,"_bodyElement");
	HX_MARK_MEMBER_NAME(bodyElement,"bodyElement");
	HX_MARK_MEMBER_NAME(_activeElement,"_activeElement");
	HX_MARK_MEMBER_NAME(activeElement,"activeElement");
	HX_MARK_MEMBER_NAME(_tabList,"_tabList");
	HX_MARK_MEMBER_NAME(_tabListIndex,"_tabListIndex");
	HX_MARK_END_CLASS();
}

Dynamic AbstractFocusManagerImpl_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"onKeyUp") ) { return onKeyUp_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_tabList") ) { return _tabList; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"onKeyDown") ) { return onKeyDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"invalidate") ) { return invalidate_dyn(); }
		if (HX_FIELD_EQ(inName,"doTabFocus") ) { return doTabFocus_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bodyElement") ) { return getBodyElement(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_bodyElement") ) { return _bodyElement; }
		if (HX_FIELD_EQ(inName,"buildTabList") ) { return buildTabList_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return getActiveElement(); }
		if (HX_FIELD_EQ(inName,"_tabListIndex") ) { return _tabListIndex; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_activeElement") ) { return _activeElement; }
		if (HX_FIELD_EQ(inName,"doBuildTabList") ) { return doBuildTabList_dyn(); }
		if (HX_FIELD_EQ(inName,"setBodyElement") ) { return setBodyElement_dyn(); }
		if (HX_FIELD_EQ(inName,"getBodyElement") ) { return getBodyElement_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setActiveElement") ) { return setActiveElement_dyn(); }
		if (HX_FIELD_EQ(inName,"getActiveElement") ) { return getActiveElement_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"simulateMouseClick") ) { return simulateMouseClick_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"initKeyboardListeners") ) { return initKeyboardListeners_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic AbstractFocusManagerImpl_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_tabList") ) { _tabList=inValue.Cast< Array< ::port::flash_player::HTMLElement > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bodyElement") ) { return setBodyElement(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_bodyElement") ) { _bodyElement=inValue.Cast< ::core::html::HTMLBodyElement >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return setActiveElement(inValue); }
		if (HX_FIELD_EQ(inName,"_tabListIndex") ) { _tabListIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"_activeElement") ) { _activeElement=inValue.Cast< ::port::flash_player::HTMLElement >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void AbstractFocusManagerImpl_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_bodyElement"));
	outFields->push(HX_CSTRING("bodyElement"));
	outFields->push(HX_CSTRING("_activeElement"));
	outFields->push(HX_CSTRING("activeElement"));
	outFields->push(HX_CSTRING("_tabList"));
	outFields->push(HX_CSTRING("_tabListIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_bodyElement"),
	HX_CSTRING("bodyElement"),
	HX_CSTRING("_activeElement"),
	HX_CSTRING("activeElement"),
	HX_CSTRING("_tabList"),
	HX_CSTRING("_tabListIndex"),
	HX_CSTRING("initKeyboardListeners"),
	HX_CSTRING("invalidate"),
	HX_CSTRING("onKeyDown"),
	HX_CSTRING("onKeyUp"),
	HX_CSTRING("doTabFocus"),
	HX_CSTRING("buildTabList"),
	HX_CSTRING("doBuildTabList"),
	HX_CSTRING("simulateMouseClick"),
	HX_CSTRING("setActiveElement"),
	HX_CSTRING("getActiveElement"),
	HX_CSTRING("setBodyElement"),
	HX_CSTRING("getBodyElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class AbstractFocusManagerImpl_obj::__mClass;

void AbstractFocusManagerImpl_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktailCore.focus.abstract.AbstractFocusManagerImpl"), hx::TCanCast< AbstractFocusManagerImpl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void AbstractFocusManagerImpl_obj::__boot()
{
}

} // end namespace cocktailCore
} // end namespace focus
} // end namespace abstract
