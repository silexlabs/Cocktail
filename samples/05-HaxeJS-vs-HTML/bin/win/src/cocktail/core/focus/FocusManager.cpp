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
#ifndef INCLUDED_cocktail_core_event_FocusEvent
#include <cocktail/core/event/FocusEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_event_UIEvent
#include <cocktail/core/event/UIEvent.h>
#endif
#ifndef INCLUDED_cocktail_core_focus_FocusManager
#include <cocktail/core/focus/FocusManager.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLBodyElement
#include <cocktail/core/html/HTMLBodyElement.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace focus{

Void FocusManager_obj::__construct()
{
HX_STACK_PUSH("FocusManager::new","cocktail/core/focus/FocusManager.hx",40);
{
}
;
	return null();
}

FocusManager_obj::~FocusManager_obj() { }

Dynamic FocusManager_obj::__CreateEmpty() { return  new FocusManager_obj; }
hx::ObjectPtr< FocusManager_obj > FocusManager_obj::__new()
{  hx::ObjectPtr< FocusManager_obj > result = new FocusManager_obj();
	result->__construct();
	return result;}

Dynamic FocusManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusManager_obj > result = new FocusManager_obj();
	result->__construct();
	return result;}

::cocktail::core::html::HTMLElement FocusManager_obj::setActiveElement( ::cocktail::core::html::HTMLElement newActiveElement,::cocktail::core::html::HTMLBodyElement body){
	HX_STACK_PUSH("FocusManager::setActiveElement","cocktail/core/focus/FocusManager.hx",249);
	HX_STACK_THIS(this);
	HX_STACK_ARG(newActiveElement,"newActiveElement");
	HX_STACK_ARG(body,"body");
	HX_STACK_LINE(251)
	if (((newActiveElement == null()))){
		HX_STACK_LINE(252)
		return this->activeElement;
	}
	HX_STACK_LINE(258)
	if (((this->activeElement == null()))){
		HX_STACK_LINE(259)
		return this->activeElement = newActiveElement;
	}
	HX_STACK_LINE(265)
	if (((newActiveElement != this->activeElement))){
		HX_STACK_LINE(272)
		::cocktail::core::event::FocusEvent focusOutEvent = ::cocktail::core::event::FocusEvent_obj::__new();		HX_STACK_VAR(focusOutEvent,"focusOutEvent");
		HX_STACK_LINE(273)
		focusOutEvent->initFocusEvent(HX_CSTRING("focusout"),true,false,null(),0.0,newActiveElement);
		HX_STACK_LINE(274)
		this->activeElement->dispatchEvent(focusOutEvent);
		HX_STACK_LINE(276)
		::cocktail::core::event::FocusEvent focusInEvent = ::cocktail::core::event::FocusEvent_obj::__new();		HX_STACK_VAR(focusInEvent,"focusInEvent");
		HX_STACK_LINE(277)
		focusInEvent->initFocusEvent(HX_CSTRING("focusin"),true,false,null(),0.0,this->activeElement);
		HX_STACK_LINE(278)
		newActiveElement->dispatchEvent(focusInEvent);
		HX_STACK_LINE(281)
		::cocktail::core::html::HTMLElement oldActiveElement = this->activeElement;		HX_STACK_VAR(oldActiveElement,"oldActiveElement");
		HX_STACK_LINE(285)
		oldActiveElement->invalidateStyleDeclaration(false);
		HX_STACK_LINE(289)
		if (((newActiveElement->isFocusable() == true))){
			HX_STACK_LINE(290)
			this->activeElement = newActiveElement;
		}
		else{
			HX_STACK_LINE(294)
			this->activeElement = body;
		}
		HX_STACK_LINE(302)
		this->activeElement->invalidateStyleDeclaration(false);
		HX_STACK_LINE(306)
		::cocktail::core::event::FocusEvent blurEvent = ::cocktail::core::event::FocusEvent_obj::__new();		HX_STACK_VAR(blurEvent,"blurEvent");
		HX_STACK_LINE(307)
		blurEvent->initFocusEvent(HX_CSTRING("blur"),false,false,null(),0.0,null());
		HX_STACK_LINE(308)
		oldActiveElement->dispatchEvent(blurEvent);
		HX_STACK_LINE(310)
		::cocktail::core::event::FocusEvent focusEvent = ::cocktail::core::event::FocusEvent_obj::__new();		HX_STACK_VAR(focusEvent,"focusEvent");
		HX_STACK_LINE(311)
		focusEvent->initFocusEvent(HX_CSTRING("focus"),false,false,null(),0.0,null());
		HX_STACK_LINE(312)
		newActiveElement->dispatchEvent(focusEvent);
		HX_STACK_LINE(314)
		if (((this->activeElement->onfocus_dyn() != null()))){
			HX_STACK_LINE(316)
			::cocktail::core::event::FocusEvent focusEvent1 = ::cocktail::core::event::FocusEvent_obj::__new();		HX_STACK_VAR(focusEvent1,"focusEvent1");
			HX_STACK_LINE(317)
			focusEvent1->initFocusEvent(HX_CSTRING("focus"),true,false,null(),0.0,null());
			HX_STACK_LINE(319)
			this->activeElement->onfocus(focusEvent1);
		}
	}
	HX_STACK_LINE(323)
	return this->activeElement;
}


HX_DEFINE_DYNAMIC_FUNC2(FocusManager_obj,setActiveElement,return )

Void FocusManager_obj::doBuildTabList( ::cocktail::core::html::HTMLElement htmlElement,Array< ::cocktail::core::html::HTMLElement > orderedTabList,Array< ::cocktail::core::html::HTMLElement > indexedTabList){
{
		HX_STACK_PUSH("FocusManager::doBuildTabList","cocktail/core/focus/FocusManager.hx",177);
		HX_STACK_THIS(this);
		HX_STACK_ARG(htmlElement,"htmlElement");
		HX_STACK_ARG(orderedTabList,"orderedTabList");
		HX_STACK_ARG(indexedTabList,"indexedTabList");
		HX_STACK_LINE(179)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = htmlElement->childNodes->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(179)
		while(((_g1 < _g))){
			HX_STACK_LINE(179)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(182)
			if (((htmlElement->childNodes->__GetItem(i)->__Field(HX_CSTRING("get_nodeType"),true)() == (int)1))){
				HX_STACK_LINE(184)
				::cocktail::core::html::HTMLElement child = htmlElement->childNodes->__GetItem(i);		HX_STACK_VAR(child,"child");
				HX_STACK_LINE(188)
				if (((child->hasChildNodes() == true))){
					HX_STACK_LINE(189)
					this->doBuildTabList(child,orderedTabList,indexedTabList);
				}
				HX_STACK_LINE(193)
				if (((child->isFocusable() == true))){
					HX_STACK_LINE(194)
					if (((child->get_tabIndex() == (int)0))){
						HX_STACK_LINE(198)
						orderedTabList->push(child);
					}
					else{
						HX_STACK_LINE(202)
						if (((child->get_tabIndex() > (int)0))){
							HX_STACK_LINE(203)
							if (((indexedTabList->length == (int)0))){
								HX_STACK_LINE(210)
								indexedTabList->push(child);
							}
							else{
								HX_STACK_LINE(215)
								bool foundSpotFlag = false;		HX_STACK_VAR(foundSpotFlag,"foundSpotFlag");
								HX_STACK_LINE(216)
								{
									HX_STACK_LINE(216)
									int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
									int _g2 = indexedTabList->length;		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(216)
									while(((_g3 < _g2))){
										HX_STACK_LINE(216)
										int j = (_g3)++;		HX_STACK_VAR(j,"j");
										HX_STACK_LINE(218)
										if (((child->get_tabIndex() < indexedTabList->__get(j)->get_tabIndex()))){
											HX_STACK_LINE(220)
											indexedTabList->insert(j,child);
											HX_STACK_LINE(221)
											foundSpotFlag = true;
										}
									}
								}
								HX_STACK_LINE(227)
								if (((foundSpotFlag == false))){
									HX_STACK_LINE(228)
									indexedTabList->push(child);
								}
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FocusManager_obj,doBuildTabList,(void))

Array< ::cocktail::core::html::HTMLElement > FocusManager_obj::buildTabList( ::cocktail::core::html::HTMLElement rootElement){
	HX_STACK_PUSH("FocusManager::buildTabList","cocktail/core/focus/FocusManager.hx",152);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rootElement,"rootElement");
	HX_STACK_LINE(154)
	Array< ::cocktail::core::html::HTMLElement > orderedTabList = Array_obj< ::cocktail::core::html::HTMLElement >::__new();		HX_STACK_VAR(orderedTabList,"orderedTabList");
	HX_STACK_LINE(157)
	Array< ::cocktail::core::html::HTMLElement > indexedTabList = Array_obj< ::cocktail::core::html::HTMLElement >::__new();		HX_STACK_VAR(indexedTabList,"indexedTabList");
	HX_STACK_LINE(160)
	this->doBuildTabList(rootElement,orderedTabList,indexedTabList);
	HX_STACK_LINE(163)
	{
		HX_STACK_LINE(163)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = orderedTabList->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(163)
		while(((_g1 < _g))){
			HX_STACK_LINE(163)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(165)
			indexedTabList->push(orderedTabList->__get(i));
		}
	}
	HX_STACK_LINE(168)
	return indexedTabList;
}


HX_DEFINE_DYNAMIC_FUNC1(FocusManager_obj,buildTabList,return )

int FocusManager_obj::getElementTabListIndex( ::cocktail::core::html::HTMLElement element,Array< ::cocktail::core::html::HTMLElement > tabList){
	HX_STACK_PUSH("FocusManager::getElementTabListIndex","cocktail/core/focus/FocusManager.hx",131);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_ARG(tabList,"tabList");
	HX_STACK_LINE(132)
	{
		HX_STACK_LINE(132)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = tabList->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(132)
		while(((_g1 < _g))){
			HX_STACK_LINE(132)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(134)
			if (((tabList->__get(i) == element))){
				HX_STACK_LINE(135)
				return i;
			}
		}
	}
	HX_STACK_LINE(139)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(FocusManager_obj,getElementTabListIndex,return )

::cocktail::core::html::HTMLElement FocusManager_obj::getNextFocusedElement( bool reverse,::cocktail::core::html::HTMLElement rootElement,::cocktail::core::html::HTMLElement activeElement){
	HX_STACK_PUSH("FocusManager::getNextFocusedElement","cocktail/core/focus/FocusManager.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(reverse,"reverse");
	HX_STACK_ARG(rootElement,"rootElement");
	HX_STACK_ARG(activeElement,"activeElement");
	HX_STACK_LINE(64)
	Array< ::cocktail::core::html::HTMLElement > tabList = this->buildTabList(rootElement);		HX_STACK_VAR(tabList,"tabList");
	HX_STACK_LINE(69)
	int tabListIndex;		HX_STACK_VAR(tabListIndex,"tabListIndex");
	HX_STACK_LINE(74)
	if (((activeElement == rootElement))){
		HX_STACK_LINE(75)
		if (((reverse == false))){
			HX_STACK_LINE(79)
			tabListIndex = (int)0;
		}
		else{
			HX_STACK_LINE(83)
			tabListIndex = (tabList->length - (int)1);
		}
	}
	else{
		HX_STACK_LINE(91)
		tabListIndex = this->getElementTabListIndex(activeElement,tabList);
		HX_STACK_LINE(95)
		if (((reverse == false))){
			HX_STACK_LINE(96)
			(tabListIndex)++;
		}
		else{
			HX_STACK_LINE(100)
			(tabListIndex)--;
		}
	}
	HX_STACK_LINE(108)
	if (((tabListIndex == tabList->length))){
		HX_STACK_LINE(109)
		tabListIndex = (int)0;
	}
	else{
		HX_STACK_LINE(113)
		if (((tabListIndex == (int)-1))){
			HX_STACK_LINE(114)
			tabListIndex = (tabList->length - (int)1);
		}
	}
	HX_STACK_LINE(119)
	return tabList->__get(tabListIndex);
}


HX_DEFINE_DYNAMIC_FUNC3(FocusManager_obj,getNextFocusedElement,return )


FocusManager_obj::FocusManager_obj()
{
}

void FocusManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusManager);
	HX_MARK_MEMBER_NAME(activeElement,"activeElement");
	HX_MARK_END_CLASS();
}

void FocusManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(activeElement,"activeElement");
}

Dynamic FocusManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"buildTabList") ) { return buildTabList_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { return activeElement; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"doBuildTabList") ) { return doBuildTabList_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"setActiveElement") ) { return setActiveElement_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getNextFocusedElement") ) { return getNextFocusedElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getElementTabListIndex") ) { return getElementTabListIndex_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FocusManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"activeElement") ) { activeElement=inValue.Cast< ::cocktail::core::html::HTMLElement >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FocusManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("activeElement"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("setActiveElement"),
	HX_CSTRING("doBuildTabList"),
	HX_CSTRING("buildTabList"),
	HX_CSTRING("getElementTabListIndex"),
	HX_CSTRING("getNextFocusedElement"),
	HX_CSTRING("activeElement"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FocusManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FocusManager_obj::__mClass,"__mClass");
};

Class FocusManager_obj::__mClass;

void FocusManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.focus.FocusManager"), hx::TCanCast< FocusManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FocusManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace focus
