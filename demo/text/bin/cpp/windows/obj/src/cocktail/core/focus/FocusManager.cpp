#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_focus_FocusManager
#include <cocktail/core/focus/FocusManager.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace focus{

Void FocusManager_obj::__construct()
{
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

::cocktail::core::html::HTMLElement FocusManager_obj::getNextFocusedElement( bool reverse,::cocktail::core::html::HTMLElement rootElement,::cocktail::core::html::HTMLElement activeElement){
	HX_SOURCE_PUSH("FocusManager_obj::getNextFocusedElement")
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",60)
	Array< ::cocktail::core::html::HTMLElement > tabList = this->buildTabList(rootElement);
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",65)
	int tabListIndex;
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",70)
	if (((activeElement == rootElement))){
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",71)
		if (((reverse == false))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",75)
			tabListIndex = (int)0;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",79)
			tabListIndex = (tabList->length - (int)1);
		}
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",87)
		tabListIndex = this->getElementTabListIndex(activeElement,tabList);
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",91)
		if (((reverse == false))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",92)
			(tabListIndex)++;
		}
		else{
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",96)
			(tabListIndex)--;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",104)
	if (((tabListIndex == tabList->length))){
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",105)
		tabListIndex = (int)0;
	}
	else{
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",109)
		if (((tabListIndex == (int)-1))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",110)
			tabListIndex = (tabList->length - (int)1);
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",115)
	return tabList->__get(tabListIndex);
}


HX_DEFINE_DYNAMIC_FUNC3(FocusManager_obj,getNextFocusedElement,return )

int FocusManager_obj::getElementTabListIndex( ::cocktail::core::html::HTMLElement element,Array< ::cocktail::core::html::HTMLElement > tabList){
	HX_SOURCE_PUSH("FocusManager_obj::getElementTabListIndex")
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",128)
	{
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",128)
		int _g1 = (int)0;
		int _g = tabList->length;
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",128)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",128)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",130)
			if (((tabList->__get(i) == element))){
				HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",131)
				return i;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",136)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(FocusManager_obj,getElementTabListIndex,return )

Array< ::cocktail::core::html::HTMLElement > FocusManager_obj::buildTabList( ::cocktail::core::html::HTMLElement rootElement){
	HX_SOURCE_PUSH("FocusManager_obj::buildTabList")
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",151)
	Array< ::cocktail::core::html::HTMLElement > orderedTabList = Array_obj< ::cocktail::core::html::HTMLElement >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",154)
	Array< ::cocktail::core::html::HTMLElement > indexedTabList = Array_obj< ::cocktail::core::html::HTMLElement >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",157)
	this->doBuildTabList(rootElement,orderedTabList,indexedTabList);
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",160)
	{
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",160)
		int _g1 = (int)0;
		int _g = orderedTabList->length;
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",160)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",160)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",162)
			indexedTabList->push(orderedTabList->__get(i));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",165)
	return indexedTabList;
}


HX_DEFINE_DYNAMIC_FUNC1(FocusManager_obj,buildTabList,return )

Void FocusManager_obj::doBuildTabList( ::cocktail::core::html::HTMLElement htmlElement,Array< ::cocktail::core::html::HTMLElement > orderedTabList,Array< ::cocktail::core::html::HTMLElement > indexedTabList){
{
		HX_SOURCE_PUSH("FocusManager_obj::doBuildTabList")
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",176)
		int _g1 = (int)0;
		int _g = htmlElement->get_childNodes()->length;
		HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",176)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",176)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",179)
			if (((htmlElement->get_childNodes()->__get(i)->get_nodeType() == (int)1))){
				HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",181)
				::cocktail::core::html::HTMLElement child = htmlElement->get_childNodes()->__get(i);
				HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",185)
				if (((child->hasChildNodes() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",186)
					this->doBuildTabList(child,orderedTabList,indexedTabList);
				}
				HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",191)
				if (((child->isFocusable() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",192)
					if (((bool((child->get_tabIndex() == (int)0)) || bool((child->get_tabIndex() == null()))))){
						HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",197)
						orderedTabList->push(child);
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",201)
						if (((child->get_tabIndex() > (int)0))){
							HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",202)
							if (((indexedTabList->length == (int)0))){
								HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",209)
								indexedTabList->push(child);
							}
							else{
								HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",214)
								bool foundSpotFlag = false;
								HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",215)
								{
									HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",215)
									int _g3 = (int)0;
									int _g2 = indexedTabList->length;
									HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",215)
									while(((_g3 < _g2))){
										HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",215)
										int j = (_g3)++;
										HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",217)
										if (((child->get_tabIndex() < indexedTabList->__get(j)->get_tabIndex()))){
											HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",219)
											indexedTabList->insert(j,child);
											HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",220)
											foundSpotFlag = true;
										}
									}
								}
								HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",226)
								if (((foundSpotFlag == false))){
									HX_SOURCE_POS("../../src/cocktail/core/focus/FocusManager.hx",227)
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


FocusManager_obj::FocusManager_obj()
{
}

void FocusManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FocusManager);
	HX_MARK_END_CLASS();
}

Dynamic FocusManager_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"buildTabList") ) { return buildTabList_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"doBuildTabList") ) { return doBuildTabList_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getNextFocusedElement") ) { return getNextFocusedElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"getElementTabListIndex") ) { return getElementTabListIndex_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic FocusManager_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void FocusManager_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getNextFocusedElement"),
	HX_CSTRING("getElementTabListIndex"),
	HX_CSTRING("buildTabList"),
	HX_CSTRING("doBuildTabList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class FocusManager_obj::__mClass;

void FocusManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.focus.FocusManager"), hx::TCanCast< FocusManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FocusManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace focus
