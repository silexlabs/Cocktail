#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_AttributeSelectorValue
#include <cocktail/core/css/AttributeSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CombinatorValue
#include <cocktail/core/css/CombinatorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_LinkPseudoClassValue
#include <cocktail/core/css/LinkPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_MatchedPseudoClassesVO
#include <cocktail/core/css/MatchedPseudoClassesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoClassSelectorValue
#include <cocktail/core/css/PseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PseudoElementSelectorValue
#include <cocktail/core/css/PseudoElementSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorComponentValue
#include <cocktail/core/css/SelectorComponentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorManager
#include <cocktail/core/css/SelectorManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorSpecificityVO
#include <cocktail/core/css/SelectorSpecificityVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceItemValue
#include <cocktail/core/css/SimpleSelectorSequenceItemValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceStartValue
#include <cocktail/core/css/SimpleSelectorSequenceStartValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SimpleSelectorSequenceVO
#include <cocktail/core/css/SimpleSelectorSequenceVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassArgumentValue
#include <cocktail/core/css/StructuralPseudoClassArgumentValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StructuralPseudoClassSelectorValue
#include <cocktail/core/css/StructuralPseudoClassSelectorValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UIElementStatesValue
#include <cocktail/core/css/UIElementStatesValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_UserActionPseudoClassValue
#include <cocktail/core/css/UserActionPseudoClassValue.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventCallback
#include <cocktail/core/event/EventCallback.h>
#endif
#ifndef INCLUDED_cocktail_core_event_EventTarget
#include <cocktail/core/event/EventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void SelectorManager_obj::__construct()
{
HX_STACK_PUSH("SelectorManager::new","cocktail/core/css/SelectorManager.hx",35);
{
	HX_STACK_LINE(35)
	this->_selectorSpecificityVO = ::cocktail::core::css::SelectorSpecificityVO_obj::__new();
}
;
	return null();
}

SelectorManager_obj::~SelectorManager_obj() { }

Dynamic SelectorManager_obj::__CreateEmpty() { return  new SelectorManager_obj; }
hx::ObjectPtr< SelectorManager_obj > SelectorManager_obj::__new()
{  hx::ObjectPtr< SelectorManager_obj > result = new SelectorManager_obj();
	result->__construct();
	return result;}

Dynamic SelectorManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SelectorManager_obj > result = new SelectorManager_obj();
	result->__construct();
	return result;}

Void SelectorManager_obj::getSimpleSelectorSequenceItemSpecificity( ::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequenceItem,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity){
{
		HX_STACK_PUSH("SelectorManager::getSimpleSelectorSequenceItemSpecificity","cocktail/core/css/SelectorManager.hx",801);
		HX_STACK_THIS(this);
		HX_STACK_ARG(simpleSelectorSequenceItem,"simpleSelectorSequenceItem");
		HX_STACK_ARG(selectorSpecificity,"selectorSpecificity");
		HX_STACK_LINE(801)
		{
			::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_1 = (simpleSelectorSequenceItem);
			switch((_switch_1)->GetIndex()){
				case 0: {
					::cocktail::core::css::AttributeSelectorValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(804)
						(selectorSpecificity->classAttributesAndPseudoClassesNumber)++;
					}
				}
				;break;
				case 1: {
					::cocktail::core::css::PseudoClassSelectorValue value = _switch_1->__Param(0);
{
						HX_STACK_LINE(807)
						(selectorSpecificity->classAttributesAndPseudoClassesNumber)++;
					}
				}
				;break;
				case 2: {
					::String value = _switch_1->__Param(0);
{
						HX_STACK_LINE(810)
						(selectorSpecificity->classAttributesAndPseudoClassesNumber)++;
					}
				}
				;break;
				case 3: {
					::String value = _switch_1->__Param(0);
{
						HX_STACK_LINE(813)
						(selectorSpecificity->idSelectorsNumber)++;
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,getSimpleSelectorSequenceItemSpecificity,(void))

Void SelectorManager_obj::getSimpleSelectorSequenceStartSpecificity( ::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStart,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity){
{
		HX_STACK_PUSH("SelectorManager::getSimpleSelectorSequenceStartSpecificity","cocktail/core/css/SelectorManager.hx",787);
		HX_STACK_THIS(this);
		HX_STACK_ARG(simpleSelectorSequenceStart,"simpleSelectorSequenceStart");
		HX_STACK_ARG(selectorSpecificity,"selectorSpecificity");
		HX_STACK_LINE(787)
		{
			::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_2 = (simpleSelectorSequenceStart);
			switch((_switch_2)->GetIndex()){
				case 1: {
					::String value = _switch_2->__Param(0);
{
						HX_STACK_LINE(790)
						(selectorSpecificity->typeAndPseudoElementsNumber)++;
					}
				}
				;break;
				case 0: {
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,getSimpleSelectorSequenceStartSpecificity,(void))

Void SelectorManager_obj::getSimpleSelectorSequenceSpecificity( ::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence,::cocktail::core::css::SelectorSpecificityVO selectorSpecificity){
{
		HX_STACK_PUSH("SelectorManager::getSimpleSelectorSequenceSpecificity","cocktail/core/css/SelectorManager.hx",771);
		HX_STACK_THIS(this);
		HX_STACK_ARG(simpleSelectorSequence,"simpleSelectorSequence");
		HX_STACK_ARG(selectorSpecificity,"selectorSpecificity");
		HX_STACK_LINE(772)
		this->getSimpleSelectorSequenceStartSpecificity(simpleSelectorSequence->startValue,selectorSpecificity);
		HX_STACK_LINE(774)
		Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors = simpleSelectorSequence->simpleSelectors;		HX_STACK_VAR(simpleSelectors,"simpleSelectors");
		HX_STACK_LINE(775)
		int length = simpleSelectors->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(776)
		{
			HX_STACK_LINE(776)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(776)
			while(((_g < length))){
				HX_STACK_LINE(776)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(778)
				::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequenceItem = simpleSelectors->__get(i);		HX_STACK_VAR(simpleSelectorSequenceItem,"simpleSelectorSequenceItem");
				HX_STACK_LINE(779)
				this->getSimpleSelectorSequenceItemSpecificity(simpleSelectorSequenceItem,selectorSpecificity);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,getSimpleSelectorSequenceSpecificity,(void))

int SelectorManager_obj::getSelectorSpecifity( ::cocktail::core::css::SelectorVO selector){
	HX_STACK_PUSH("SelectorManager::getSelectorSpecifity","cocktail/core/css/SelectorManager.hx",724);
	HX_STACK_THIS(this);
	HX_STACK_ARG(selector,"selector");
	HX_STACK_LINE(729)
	this->_selectorSpecificityVO->classAttributesAndPseudoClassesNumber = (int)0;
	HX_STACK_LINE(730)
	this->_selectorSpecificityVO->idSelectorsNumber = (int)0;
	HX_STACK_LINE(731)
	this->_selectorSpecificityVO->typeAndPseudoElementsNumber = (int)0;
	HX_STACK_LINE(734)
	{
		::cocktail::core::css::PseudoElementSelectorValue _switch_3 = (selector->pseudoElement);
		switch((_switch_3)->GetIndex()){
			case 2: case 1: case 4: case 3: {
				HX_STACK_LINE(736)
				(this->_selectorSpecificityVO->typeAndPseudoElementsNumber)++;
			}
			;break;
			case 0: {
			}
			;break;
		}
	}
	HX_STACK_LINE(745)
	Array< ::cocktail::core::css::SelectorComponentValue > components = selector->components;		HX_STACK_VAR(components,"components");
	HX_STACK_LINE(746)
	int length = components->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(747)
	{
		HX_STACK_LINE(747)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(747)
		while(((_g < length))){
			HX_STACK_LINE(747)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(749)
			::cocktail::core::css::SelectorComponentValue component = components->__get(i);		HX_STACK_VAR(component,"component");
			HX_STACK_LINE(751)
			{
				::cocktail::core::css::SelectorComponentValue _switch_4 = (component);
				switch((_switch_4)->GetIndex()){
					case 1: {
						::cocktail::core::css::CombinatorValue value = _switch_4->__Param(0);
{
						}
					}
					;break;
					case 0: {
						::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_4->__Param(0);
{
							HX_STACK_LINE(755)
							this->getSimpleSelectorSequenceSpecificity(value,this->_selectorSpecificityVO);
						}
					}
					;break;
				}
			}
		}
	}
	HX_STACK_LINE(764)
	return (((this->_selectorSpecificityVO->idSelectorsNumber * (int)100) + (this->_selectorSpecificityVO->classAttributesAndPseudoClassesNumber * (int)10)) + this->_selectorSpecificityVO->typeAndPseudoElementsNumber);
}


HX_DEFINE_DYNAMIC_FUNC1(SelectorManager_obj,getSelectorSpecifity,return )

bool SelectorManager_obj::matchTargetPseudoClassSelector( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("SelectorManager::matchTargetPseudoClassSelector","cocktail/core/css/SelectorManager.hx",711);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(711)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(SelectorManager_obj,matchTargetPseudoClassSelector,return )

bool SelectorManager_obj::matchUserActionPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::UserActionPseudoClassValue userActionPseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClass){
	HX_STACK_PUSH("SelectorManager::matchUserActionPseudoClassSelector","cocktail/core/css/SelectorManager.hx",692);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(userActionPseudoClassSelector,"userActionPseudoClassSelector");
	HX_STACK_ARG(matchedPseudoClass,"matchedPseudoClass");
	HX_STACK_LINE(692)
	{
		::cocktail::core::css::UserActionPseudoClassValue _switch_5 = (userActionPseudoClassSelector);
		switch((_switch_5)->GetIndex()){
			case 0: {
				HX_STACK_LINE(695)
				return matchedPseudoClass->active;
			}
			;break;
			case 1: {
				HX_STACK_LINE(698)
				return matchedPseudoClass->hover;
			}
			;break;
			case 2: {
				HX_STACK_LINE(701)
				return matchedPseudoClass->focus;
			}
			;break;
		}
	}
	HX_STACK_LINE(692)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchUserActionPseudoClassSelector,return )

bool SelectorManager_obj::matchLinkPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::LinkPseudoClassValue linkPseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClass){
	HX_STACK_PUSH("SelectorManager::matchLinkPseudoClassSelector","cocktail/core/css/SelectorManager.hx",676);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(linkPseudoClassSelector,"linkPseudoClassSelector");
	HX_STACK_ARG(matchedPseudoClass,"matchedPseudoClass");
	HX_STACK_LINE(676)
	{
		::cocktail::core::css::LinkPseudoClassValue _switch_6 = (linkPseudoClassSelector);
		switch((_switch_6)->GetIndex()){
			case 0: {
				HX_STACK_LINE(679)
				return matchedPseudoClass->link;
			}
			;break;
			case 1: {
				HX_STACK_LINE(682)
				return false;
			}
			;break;
		}
	}
	HX_STACK_LINE(676)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchLinkPseudoClassSelector,return )

bool SelectorManager_obj::matchOnlyOfType( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("SelectorManager::matchOnlyOfType","cocktail/core/css/SelectorManager.hx",665);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(665)
	return (bool((this->matchLastOfType(node) == true)) && bool((this->matchFirstOfType(node) == true)));
}


HX_DEFINE_DYNAMIC_FUNC1(SelectorManager_obj,matchOnlyOfType,return )

bool SelectorManager_obj::matchLastOfType( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("SelectorManager::matchLastOfType","cocktail/core/css/SelectorManager.hx",642);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(643)
	::String type = node->tagName;		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(645)
	::cocktail::core::html::HTMLElement nextElementSibling = node->get_nextElementSibling();		HX_STACK_VAR(nextElementSibling,"nextElementSibling");
	HX_STACK_LINE(647)
	while(((nextElementSibling != null()))){
		HX_STACK_LINE(649)
		if (((nextElementSibling->tagName == type))){
			HX_STACK_LINE(650)
			return false;
		}
		HX_STACK_LINE(654)
		nextElementSibling = nextElementSibling->get_nextElementSibling();
	}
	HX_STACK_LINE(657)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(SelectorManager_obj,matchLastOfType,return )

bool SelectorManager_obj::matchFirstOfType( ::cocktail::core::html::HTMLElement node){
	HX_STACK_PUSH("SelectorManager::matchFirstOfType","cocktail/core/css/SelectorManager.hx",620);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_LINE(621)
	::String type = node->tagName;		HX_STACK_VAR(type,"type");
	HX_STACK_LINE(623)
	::cocktail::core::html::HTMLElement previousElementSibling = node->get_previousElementSibling();		HX_STACK_VAR(previousElementSibling,"previousElementSibling");
	HX_STACK_LINE(625)
	while(((previousElementSibling != null()))){
		HX_STACK_LINE(627)
		if (((previousElementSibling->tagName == type))){
			HX_STACK_LINE(628)
			return false;
		}
		HX_STACK_LINE(632)
		previousElementSibling = previousElementSibling->get_previousElementSibling();
	}
	HX_STACK_LINE(635)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(SelectorManager_obj,matchFirstOfType,return )

bool SelectorManager_obj::matchNthOfType( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value){
	HX_STACK_PUSH("SelectorManager::matchNthOfType","cocktail/core/css/SelectorManager.hx",610);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(610)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchNthOfType,return )

bool SelectorManager_obj::matchNthLastOfType( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value){
	HX_STACK_PUSH("SelectorManager::matchNthLastOfType","cocktail/core/css/SelectorManager.hx",605);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(605)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchNthLastOfType,return )

bool SelectorManager_obj::matchNthLastChild( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value){
	HX_STACK_PUSH("SelectorManager::matchNthLastChild","cocktail/core/css/SelectorManager.hx",600);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(600)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchNthLastChild,return )

bool SelectorManager_obj::matchNthChild( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassArgumentValue value){
	HX_STACK_PUSH("SelectorManager::matchNthChild","cocktail/core/css/SelectorManager.hx",595);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(595)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchNthChild,return )

bool SelectorManager_obj::matchStructuralPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::StructuralPseudoClassSelectorValue structuralPseudoClassSelector){
	HX_STACK_PUSH("SelectorManager::matchStructuralPseudoClassSelector","cocktail/core/css/SelectorManager.hx",530);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(structuralPseudoClassSelector,"structuralPseudoClassSelector");
	HX_STACK_LINE(530)
	{
		::cocktail::core::css::StructuralPseudoClassSelectorValue _switch_7 = (structuralPseudoClassSelector);
		switch((_switch_7)->GetIndex()){
			case 7: {
				HX_STACK_LINE(533)
				return node->hasChildNodes();
			}
			;break;
			case 1: {
				HX_STACK_LINE(541)
				if (((node->parentNode == null()))){
					HX_STACK_LINE(542)
					return false;
				}
				HX_STACK_LINE(546)
				return (node->get_previousElementSibling() == null());
			}
			;break;
			case 2: {
				HX_STACK_LINE(551)
				if (((node->parentNode == null()))){
					HX_STACK_LINE(552)
					return false;
				}
				HX_STACK_LINE(556)
				return (node->get_nextElementSibling() == null());
			}
			;break;
			case 5: {
				HX_STACK_LINE(561)
				if (((node->parentNode == null()))){
					HX_STACK_LINE(562)
					return false;
				}
				HX_STACK_LINE(566)
				return (node->parentNode->__Field(HX_CSTRING("childNodes"),true)->__Field(HX_CSTRING("length"),true) == (int)1);
			}
			;break;
			case 0: {
				HX_STACK_LINE(568)
				return (bool((node->tagName == HX_CSTRING("HTML"))) && bool((node->parentNode == null())));
			}
			;break;
			case 6: {
				HX_STACK_LINE(571)
				return this->matchOnlyOfType(node);
			}
			;break;
			case 3: {
				HX_STACK_LINE(574)
				return this->matchFirstOfType(node);
			}
			;break;
			case 4: {
				HX_STACK_LINE(577)
				return this->matchLastOfType(node);
			}
			;break;
			case 8: {
				::cocktail::core::css::StructuralPseudoClassArgumentValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(580)
					return this->matchNthChild(node,value);
				}
			}
			;break;
			case 9: {
				::cocktail::core::css::StructuralPseudoClassArgumentValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(583)
					return this->matchNthLastChild(node,value);
				}
			}
			;break;
			case 11: {
				::cocktail::core::css::StructuralPseudoClassArgumentValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(586)
					return this->matchNthLastOfType(node,value);
				}
			}
			;break;
			case 10: {
				::cocktail::core::css::StructuralPseudoClassArgumentValue value = _switch_7->__Param(0);
{
					HX_STACK_LINE(589)
					return this->matchNthOfType(node,value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(530)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchStructuralPseudoClassSelector,return )

bool SelectorManager_obj::matchLangPseudoClassSelector( ::cocktail::core::html::HTMLElement node,Array< ::String > lang){
	HX_STACK_PUSH("SelectorManager::matchLangPseudoClassSelector","cocktail/core/css/SelectorManager.hx",521);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(lang,"lang");
	HX_STACK_LINE(521)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchLangPseudoClassSelector,return )

bool SelectorManager_obj::matchNegationPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO negationSimpleSelectorSequence){
	HX_STACK_PUSH("SelectorManager::matchNegationPseudoClassSelector","cocktail/core/css/SelectorManager.hx",512);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(negationSimpleSelectorSequence,"negationSimpleSelectorSequence");
	HX_STACK_LINE(512)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchNegationPseudoClassSelector,return )

bool SelectorManager_obj::matchUIElementStatesSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::UIElementStatesValue uiElementState,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchUIElementStatesSelector","cocktail/core/css/SelectorManager.hx",493);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(uiElementState,"uiElementState");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(493)
	{
		::cocktail::core::css::UIElementStatesValue _switch_8 = (uiElementState);
		switch((_switch_8)->GetIndex()){
			case 2: {
				HX_STACK_LINE(496)
				return matchedPseudoClasses->checked;
			}
			;break;
			case 1: {
				HX_STACK_LINE(499)
				return matchedPseudoClasses->disabled;
			}
			;break;
			case 0: {
				HX_STACK_LINE(502)
				return matchedPseudoClasses->enabled;
			}
			;break;
		}
	}
	HX_STACK_LINE(493)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchUIElementStatesSelector,return )

bool SelectorManager_obj::matchPseudoClassSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::PseudoClassSelectorValue pseudoClassSelector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchPseudoClassSelector","cocktail/core/css/SelectorManager.hx",462);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(pseudoClassSelector,"pseudoClassSelector");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(462)
	{
		::cocktail::core::css::PseudoClassSelectorValue _switch_9 = (pseudoClassSelector);
		switch((_switch_9)->GetIndex()){
			case 0: {
				::cocktail::core::css::StructuralPseudoClassSelectorValue value = _switch_9->__Param(0);
{
					HX_STACK_LINE(465)
					return this->matchStructuralPseudoClassSelector(node,value);
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::LinkPseudoClassValue value = _switch_9->__Param(0);
{
					HX_STACK_LINE(468)
					return this->matchLinkPseudoClassSelector(node,value,matchedPseudoClasses);
				}
			}
			;break;
			case 4: {
				::cocktail::core::css::UserActionPseudoClassValue value = _switch_9->__Param(0);
{
					HX_STACK_LINE(471)
					return this->matchUserActionPseudoClassSelector(node,value,matchedPseudoClasses);
				}
			}
			;break;
			case 2: {
				HX_STACK_LINE(474)
				return this->matchTargetPseudoClassSelector(node);
			}
			;break;
			case 6: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_9->__Param(0);
{
					HX_STACK_LINE(477)
					return this->matchNegationPseudoClassSelector(node,value);
				}
			}
			;break;
			case 3: {
				Array< ::String > value = _switch_9->__Param(0);
{
					HX_STACK_LINE(480)
					return this->matchLangPseudoClassSelector(node,value);
				}
			}
			;break;
			case 5: {
				::cocktail::core::css::UIElementStatesValue value = _switch_9->__Param(0);
{
					HX_STACK_LINE(483)
					return this->matchUIElementStatesSelector(node,value,matchedPseudoClasses);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(462)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchPseudoClassSelector,return )

bool SelectorManager_obj::matchAttributeList( ::cocktail::core::html::HTMLElement node,::String name,::String value){
	HX_STACK_PUSH("SelectorManager::matchAttributeList","cocktail/core/css/SelectorManager.hx",437);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(438)
	::String attributeValue = node->getAttribute(name);		HX_STACK_VAR(attributeValue,"attributeValue");
	HX_STACK_LINE(440)
	if (((attributeValue == null()))){
		HX_STACK_LINE(441)
		return false;
	}
	HX_STACK_LINE(445)
	Array< ::String > attributeValueAsList = attributeValue.split(HX_CSTRING(" "));		HX_STACK_VAR(attributeValueAsList,"attributeValueAsList");
	HX_STACK_LINE(446)
	{
		HX_STACK_LINE(446)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = attributeValueAsList->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(446)
		while(((_g1 < _g))){
			HX_STACK_LINE(446)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(448)
			if (((attributeValueAsList->__get(i) == value))){
				HX_STACK_LINE(449)
				return true;
			}
		}
	}
	HX_STACK_LINE(454)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAttributeList,return )

bool SelectorManager_obj::matchAttributeBeginValue( ::cocktail::core::html::HTMLElement node,::String name,::String value){
	HX_STACK_PUSH("SelectorManager::matchAttributeBeginValue","cocktail/core/css/SelectorManager.hx",421);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(422)
	::String attributeValue = node->getAttribute(name);		HX_STACK_VAR(attributeValue,"attributeValue");
	HX_STACK_LINE(424)
	if (((attributeValue == null()))){
		HX_STACK_LINE(425)
		return false;
	}
	HX_STACK_LINE(429)
	return (attributeValue.indexOf(value,null()) == (int)0);
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAttributeBeginValue,return )

bool SelectorManager_obj::matchAttributeContainsValue( ::cocktail::core::html::HTMLElement node,::String name,::String value){
	HX_STACK_PUSH("SelectorManager::matchAttributeContainsValue","cocktail/core/css/SelectorManager.hx",405);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(406)
	::String attributeValue = node->getAttribute(name);		HX_STACK_VAR(attributeValue,"attributeValue");
	HX_STACK_LINE(408)
	if (((attributeValue == null()))){
		HX_STACK_LINE(409)
		return false;
	}
	HX_STACK_LINE(413)
	return (attributeValue.indexOf(value,null()) != (int)-1);
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAttributeContainsValue,return )

bool SelectorManager_obj::matchAttributeEndValue( ::cocktail::core::html::HTMLElement node,::String name,::String value){
	HX_STACK_PUSH("SelectorManager::matchAttributeEndValue","cocktail/core/css/SelectorManager.hx",390);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(391)
	::String attributeValue = node->getAttribute(name);		HX_STACK_VAR(attributeValue,"attributeValue");
	HX_STACK_LINE(393)
	if (((attributeValue == null()))){
		HX_STACK_LINE(394)
		return false;
	}
	HX_STACK_LINE(398)
	return (attributeValue.lastIndexOf(value,null()) == (attributeValue.length - value.length));
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAttributeEndValue,return )

bool SelectorManager_obj::matchAttributeBeginsHyphenList( ::cocktail::core::html::HTMLElement node,::String name,::String value){
	HX_STACK_PUSH("SelectorManager::matchAttributeBeginsHyphenList","cocktail/core/css/SelectorManager.hx",367);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(368)
	::String attributeValue = node->getAttribute(name);		HX_STACK_VAR(attributeValue,"attributeValue");
	HX_STACK_LINE(370)
	if (((attributeValue == null()))){
		HX_STACK_LINE(371)
		return false;
	}
	HX_STACK_LINE(376)
	if (((attributeValue == value))){
		HX_STACK_LINE(377)
		return true;
	}
	HX_STACK_LINE(382)
	::String hyphenValue = (value + HX_CSTRING("-"));		HX_STACK_VAR(hyphenValue,"hyphenValue");
	HX_STACK_LINE(383)
	return (attributeValue.substr((int)0,hyphenValue.length) == hyphenValue);
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAttributeBeginsHyphenList,return )

bool SelectorManager_obj::matchAttributeSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::AttributeSelectorValue attributeSelector){
	HX_STACK_PUSH("SelectorManager::matchAttributeSelector","cocktail/core/css/SelectorManager.hx",334);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(attributeSelector,"attributeSelector");
	HX_STACK_LINE(335)
	{
		::cocktail::core::css::AttributeSelectorValue _switch_10 = (attributeSelector);
		switch((_switch_10)->GetIndex()){
			case 0: {
				::String value = _switch_10->__Param(0);
{
					HX_STACK_LINE(337)
					return (node->getAttribute(value) != null());
				}
			}
			;break;
			case 1: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(340)
					return (node->getAttribute(name) == value);
				}
			}
			;break;
			case 2: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(343)
					return this->matchAttributeList(node,name,value);
				}
			}
			;break;
			case 3: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(346)
					return this->matchAttributeBeginValue(node,name,value);
				}
			}
			;break;
			case 5: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(349)
					return this->matchAttributeContainsValue(node,name,value);
				}
			}
			;break;
			case 4: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(352)
					return this->matchAttributeEndValue(node,name,value);
				}
			}
			;break;
			case 6: {
				::String value = _switch_10->__Param(1);
				::String name = _switch_10->__Param(0);
{
					HX_STACK_LINE(355)
					return this->matchAttributeBeginsHyphenList(node,name,value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(359)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchAttributeSelector,return )

bool SelectorManager_obj::matchSimpleSelectorSequence( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO simpleSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchSimpleSelectorSequence","cocktail/core/css/SelectorManager.hx",307);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(simpleSelectorSequence,"simpleSelectorSequence");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(309)
	if (((this->matchSimpleSelectorSequenceStart(node,simpleSelectorSequence->startValue) == false))){
		HX_STACK_LINE(310)
		return false;
	}
	HX_STACK_LINE(315)
	Array< ::cocktail::core::css::SimpleSelectorSequenceItemValue > simpleSelectors = simpleSelectorSequence->simpleSelectors;		HX_STACK_VAR(simpleSelectors,"simpleSelectors");
	HX_STACK_LINE(316)
	int length = simpleSelectors->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(317)
	{
		HX_STACK_LINE(317)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(317)
		while(((_g < length))){
			HX_STACK_LINE(317)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(319)
			::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequence1 = simpleSelectors->__get(i);		HX_STACK_VAR(simpleSelectorSequence1,"simpleSelectorSequence1");
			HX_STACK_LINE(320)
			if (((this->matchSimpleSelectorSequenceItem(node,simpleSelectorSequence1,matchedPseudoClasses) == false))){
				HX_STACK_LINE(321)
				return false;
			}
		}
	}
	HX_STACK_LINE(326)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchSimpleSelectorSequence,return )

bool SelectorManager_obj::matchSimpleSelectorSequenceItem( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceItemValue simpleSelectorSequenceItem,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchSimpleSelectorSequenceItem","cocktail/core/css/SelectorManager.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(simpleSelectorSequenceItem,"simpleSelectorSequenceItem");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(266)
	{
		::cocktail::core::css::SimpleSelectorSequenceItemValue _switch_11 = (simpleSelectorSequenceItem);
		switch((_switch_11)->GetIndex()){
			case 2: {
				::String value = _switch_11->__Param(0);
{
					HX_STACK_LINE(271)
					Array< ::String > classList = node->classList;		HX_STACK_VAR(classList,"classList");
					HX_STACK_LINE(274)
					if (((classList == null()))){
						HX_STACK_LINE(275)
						return false;
					}
					HX_STACK_LINE(279)
					int length = classList->length;		HX_STACK_VAR(length,"length");
					HX_STACK_LINE(280)
					{
						HX_STACK_LINE(280)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(280)
						while(((_g < length))){
							HX_STACK_LINE(280)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(282)
							if (((value == classList->__get(i)))){
								HX_STACK_LINE(283)
								return true;
							}
						}
					}
					HX_STACK_LINE(288)
					return false;
				}
			}
			;break;
			case 3: {
				::String value = _switch_11->__Param(0);
{
					HX_STACK_LINE(291)
					return (node->get_id() == value);
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::PseudoClassSelectorValue value = _switch_11->__Param(0);
{
					HX_STACK_LINE(294)
					return this->matchPseudoClassSelector(node,value,matchedPseudoClasses);
				}
			}
			;break;
			case 0: {
				::cocktail::core::css::AttributeSelectorValue value = _switch_11->__Param(0);
{
					HX_STACK_LINE(297)
					return this->matchAttributeSelector(node,value);
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(266)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchSimpleSelectorSequenceItem,return )

bool SelectorManager_obj::matchSimpleSelectorSequenceStart( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceStartValue simpleSelectorSequenceStart){
	HX_STACK_PUSH("SelectorManager::matchSimpleSelectorSequenceStart","cocktail/core/css/SelectorManager.hx",248);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(simpleSelectorSequenceStart,"simpleSelectorSequenceStart");
	HX_STACK_LINE(248)
	{
		::cocktail::core::css::SimpleSelectorSequenceStartValue _switch_12 = (simpleSelectorSequenceStart);
		switch((_switch_12)->GetIndex()){
			case 1: {
				::String value = _switch_12->__Param(0);
{
					HX_STACK_LINE(251)
					return (node->tagName == value);
				}
			}
			;break;
			case 0: {
				HX_STACK_LINE(254)
				return true;
			}
			;break;
		}
	}
	HX_STACK_LINE(248)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(SelectorManager_obj,matchSimpleSelectorSequenceStart,return )

bool SelectorManager_obj::matchChildCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchChildCombinator","cocktail/core/css/SelectorManager.hx",230);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(nextSelectorSequence,"nextSelectorSequence");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(230)
	return this->matchSimpleSelectorSequence(node->parentNode,nextSelectorSequence,matchedPseudoClasses);
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchChildCombinator,return )

bool SelectorManager_obj::matchDescendantCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchDescendantCombinator","cocktail/core/css/SelectorManager.hx",204);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(nextSelectorSequence,"nextSelectorSequence");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(205)
	::cocktail::core::html::HTMLElement parentNode = node->parentNode;		HX_STACK_VAR(parentNode,"parentNode");
	HX_STACK_LINE(209)
	while(((parentNode != null()))){
		HX_STACK_LINE(211)
		if (((this->matchSimpleSelectorSequence(parentNode,nextSelectorSequence,matchedPseudoClasses) == true))){
			HX_STACK_LINE(212)
			return true;
		}
		HX_STACK_LINE(216)
		parentNode = parentNode->parentNode;
	}
	HX_STACK_LINE(221)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchDescendantCombinator,return )

bool SelectorManager_obj::matchAdjacentSiblingCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchAdjacentSiblingCombinator","cocktail/core/css/SelectorManager.hx",187);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(nextSelectorSequence,"nextSelectorSequence");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(188)
	::cocktail::core::html::HTMLElement previousElementSibling = node->get_previousElementSibling();		HX_STACK_VAR(previousElementSibling,"previousElementSibling");
	HX_STACK_LINE(190)
	if (((previousElementSibling == null()))){
		HX_STACK_LINE(191)
		return false;
	}
	HX_STACK_LINE(195)
	return this->matchSimpleSelectorSequence(previousElementSibling,nextSelectorSequence,matchedPseudoClasses);
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchAdjacentSiblingCombinator,return )

bool SelectorManager_obj::matchGeneralSiblingCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchGeneralSiblingCombinator","cocktail/core/css/SelectorManager.hx",164);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(nextSelectorSequence,"nextSelectorSequence");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(165)
	::cocktail::core::html::HTMLElement previousElementSibling = node->get_previousElementSibling();		HX_STACK_VAR(previousElementSibling,"previousElementSibling");
	HX_STACK_LINE(167)
	while(((previousElementSibling != null()))){
		HX_STACK_LINE(169)
		if (((this->matchSimpleSelectorSequence(previousElementSibling,nextSelectorSequence,matchedPseudoClasses) == true))){
			HX_STACK_LINE(170)
			return true;
		}
		HX_STACK_LINE(174)
		previousElementSibling = previousElementSibling->get_previousElementSibling();
	}
	HX_STACK_LINE(177)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchGeneralSiblingCombinator,return )

bool SelectorManager_obj::matchCombinator( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::CombinatorValue combinator,::cocktail::core::css::SelectorComponentValue nextSelectorComponent,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchCombinator","cocktail/core/css/SelectorManager.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(combinator,"combinator");
	HX_STACK_ARG(nextSelectorComponent,"nextSelectorComponent");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(121)
	if (((node->parentNode == null()))){
		HX_STACK_LINE(122)
		return false;
	}
	HX_STACK_LINE(126)
	::cocktail::core::css::SimpleSelectorSequenceVO nextSelectorSequence = null();		HX_STACK_VAR(nextSelectorSequence,"nextSelectorSequence");
	HX_STACK_LINE(130)
	{
		::cocktail::core::css::SelectorComponentValue _switch_13 = (nextSelectorComponent);
		switch((_switch_13)->GetIndex()){
			case 0: {
				::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_13->__Param(0);
{
					HX_STACK_LINE(132)
					nextSelectorSequence = value;
				}
			}
			;break;
			case 1: {
				::cocktail::core::css::CombinatorValue value = _switch_13->__Param(0);
{
					HX_STACK_LINE(135)
					return false;
				}
			}
			;break;
		}
	}
	HX_STACK_LINE(139)
	{
		::cocktail::core::css::CombinatorValue _switch_14 = (combinator);
		switch((_switch_14)->GetIndex()){
			case 2: {
				HX_STACK_LINE(141)
				return this->matchAdjacentSiblingCombinator(node,nextSelectorSequence,matchedPseudoClasses);
			}
			;break;
			case 3: {
				HX_STACK_LINE(144)
				return this->matchGeneralSiblingCombinator(node,nextSelectorSequence,matchedPseudoClasses);
			}
			;break;
			case 1: {
				HX_STACK_LINE(147)
				return this->matchChildCombinator(node,nextSelectorSequence,matchedPseudoClasses);
			}
			;break;
			case 0: {
				HX_STACK_LINE(150)
				return this->matchDescendantCombinator(node,nextSelectorSequence,matchedPseudoClasses);
			}
			;break;
		}
	}
	HX_STACK_LINE(139)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC4(SelectorManager_obj,matchCombinator,return )

bool SelectorManager_obj::matchSelector( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::SelectorVO selector,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("SelectorManager::matchSelector","cocktail/core/css/SelectorManager.hx",48);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(selector,"selector");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(49)
	Array< ::cocktail::core::css::SelectorComponentValue > components = selector->components;		HX_STACK_VAR(components,"components");
	HX_STACK_LINE(55)
	bool lastWasCombinator = false;		HX_STACK_VAR(lastWasCombinator,"lastWasCombinator");
	HX_STACK_LINE(58)
	int length = components->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(59)
	{
		HX_STACK_LINE(59)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(59)
		while(((_g < length))){
			HX_STACK_LINE(59)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(61)
			::cocktail::core::css::SelectorComponentValue component = components->__get(i);		HX_STACK_VAR(component,"component");
			HX_STACK_LINE(64)
			bool matched = false;		HX_STACK_VAR(matched,"matched");
			HX_STACK_LINE(66)
			{
				::cocktail::core::css::SelectorComponentValue _switch_15 = (component);
				switch((_switch_15)->GetIndex()){
					case 1: {
						::cocktail::core::css::CombinatorValue value = _switch_15->__Param(0);
{
							HX_STACK_LINE(69)
							matched = this->matchCombinator(node,value,components->__get((i + (int)1)),matchedPseudoClasses);
							HX_STACK_LINE(70)
							lastWasCombinator = true;
							HX_STACK_LINE(75)
							if (((value == ::cocktail::core::css::CombinatorValue_obj::CHILD_dyn()))){
								HX_STACK_LINE(76)
								node = node->parentNode;
							}
						}
					}
					;break;
					case 0: {
						::cocktail::core::css::SimpleSelectorSequenceVO value = _switch_15->__Param(0);
{
							HX_STACK_LINE(80)
							if (((lastWasCombinator == true))){
								HX_STACK_LINE(87)
								matched = true;
								HX_STACK_LINE(88)
								lastWasCombinator = false;
							}
							else{
								HX_STACK_LINE(91)
								matched = this->matchSimpleSelectorSequence(node,value,matchedPseudoClasses);
							}
						}
					}
					;break;
				}
			}
			HX_STACK_LINE(98)
			if (((matched == false))){
				HX_STACK_LINE(99)
				return false;
			}
		}
	}
	HX_STACK_LINE(104)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC3(SelectorManager_obj,matchSelector,return )


SelectorManager_obj::SelectorManager_obj()
{
}

void SelectorManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SelectorManager);
	HX_MARK_MEMBER_NAME(_selectorSpecificityVO,"_selectorSpecificityVO");
	HX_MARK_END_CLASS();
}

void SelectorManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_selectorSpecificityVO,"_selectorSpecificityVO");
}

Dynamic SelectorManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"matchNthChild") ) { return matchNthChild_dyn(); }
		if (HX_FIELD_EQ(inName,"matchSelector") ) { return matchSelector_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"matchNthOfType") ) { return matchNthOfType_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"matchOnlyOfType") ) { return matchOnlyOfType_dyn(); }
		if (HX_FIELD_EQ(inName,"matchLastOfType") ) { return matchLastOfType_dyn(); }
		if (HX_FIELD_EQ(inName,"matchCombinator") ) { return matchCombinator_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"matchFirstOfType") ) { return matchFirstOfType_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"matchNthLastChild") ) { return matchNthLastChild_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"matchNthLastOfType") ) { return matchNthLastOfType_dyn(); }
		if (HX_FIELD_EQ(inName,"matchAttributeList") ) { return matchAttributeList_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"getSelectorSpecifity") ) { return getSelectorSpecifity_dyn(); }
		if (HX_FIELD_EQ(inName,"matchChildCombinator") ) { return matchChildCombinator_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"matchAttributeEndValue") ) { return matchAttributeEndValue_dyn(); }
		if (HX_FIELD_EQ(inName,"matchAttributeSelector") ) { return matchAttributeSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"_selectorSpecificityVO") ) { return _selectorSpecificityVO; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"matchPseudoClassSelector") ) { return matchPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchAttributeBeginValue") ) { return matchAttributeBeginValue_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"matchDescendantCombinator") ) { return matchDescendantCombinator_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"matchAttributeContainsValue") ) { return matchAttributeContainsValue_dyn(); }
		if (HX_FIELD_EQ(inName,"matchSimpleSelectorSequence") ) { return matchSimpleSelectorSequence_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"matchLinkPseudoClassSelector") ) { return matchLinkPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchLangPseudoClassSelector") ) { return matchLangPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchUIElementStatesSelector") ) { return matchUIElementStatesSelector_dyn(); }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"matchGeneralSiblingCombinator") ) { return matchGeneralSiblingCombinator_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"matchTargetPseudoClassSelector") ) { return matchTargetPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchAttributeBeginsHyphenList") ) { return matchAttributeBeginsHyphenList_dyn(); }
		if (HX_FIELD_EQ(inName,"matchAdjacentSiblingCombinator") ) { return matchAdjacentSiblingCombinator_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"matchSimpleSelectorSequenceItem") ) { return matchSimpleSelectorSequenceItem_dyn(); }
		break;
	case 32:
		if (HX_FIELD_EQ(inName,"matchNegationPseudoClassSelector") ) { return matchNegationPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchSimpleSelectorSequenceStart") ) { return matchSimpleSelectorSequenceStart_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"matchUserActionPseudoClassSelector") ) { return matchUserActionPseudoClassSelector_dyn(); }
		if (HX_FIELD_EQ(inName,"matchStructuralPseudoClassSelector") ) { return matchStructuralPseudoClassSelector_dyn(); }
		break;
	case 36:
		if (HX_FIELD_EQ(inName,"getSimpleSelectorSequenceSpecificity") ) { return getSimpleSelectorSequenceSpecificity_dyn(); }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"getSimpleSelectorSequenceItemSpecificity") ) { return getSimpleSelectorSequenceItemSpecificity_dyn(); }
		break;
	case 41:
		if (HX_FIELD_EQ(inName,"getSimpleSelectorSequenceStartSpecificity") ) { return getSimpleSelectorSequenceStartSpecificity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SelectorManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 22:
		if (HX_FIELD_EQ(inName,"_selectorSpecificityVO") ) { _selectorSpecificityVO=inValue.Cast< ::cocktail::core::css::SelectorSpecificityVO >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SelectorManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_selectorSpecificityVO"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getSimpleSelectorSequenceItemSpecificity"),
	HX_CSTRING("getSimpleSelectorSequenceStartSpecificity"),
	HX_CSTRING("getSimpleSelectorSequenceSpecificity"),
	HX_CSTRING("getSelectorSpecifity"),
	HX_CSTRING("matchTargetPseudoClassSelector"),
	HX_CSTRING("matchUserActionPseudoClassSelector"),
	HX_CSTRING("matchLinkPseudoClassSelector"),
	HX_CSTRING("matchOnlyOfType"),
	HX_CSTRING("matchLastOfType"),
	HX_CSTRING("matchFirstOfType"),
	HX_CSTRING("matchNthOfType"),
	HX_CSTRING("matchNthLastOfType"),
	HX_CSTRING("matchNthLastChild"),
	HX_CSTRING("matchNthChild"),
	HX_CSTRING("matchStructuralPseudoClassSelector"),
	HX_CSTRING("matchLangPseudoClassSelector"),
	HX_CSTRING("matchNegationPseudoClassSelector"),
	HX_CSTRING("matchUIElementStatesSelector"),
	HX_CSTRING("matchPseudoClassSelector"),
	HX_CSTRING("matchAttributeList"),
	HX_CSTRING("matchAttributeBeginValue"),
	HX_CSTRING("matchAttributeContainsValue"),
	HX_CSTRING("matchAttributeEndValue"),
	HX_CSTRING("matchAttributeBeginsHyphenList"),
	HX_CSTRING("matchAttributeSelector"),
	HX_CSTRING("matchSimpleSelectorSequence"),
	HX_CSTRING("matchSimpleSelectorSequenceItem"),
	HX_CSTRING("matchSimpleSelectorSequenceStart"),
	HX_CSTRING("matchChildCombinator"),
	HX_CSTRING("matchDescendantCombinator"),
	HX_CSTRING("matchAdjacentSiblingCombinator"),
	HX_CSTRING("matchGeneralSiblingCombinator"),
	HX_CSTRING("matchCombinator"),
	HX_CSTRING("matchSelector"),
	HX_CSTRING("_selectorSpecificityVO"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SelectorManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SelectorManager_obj::__mClass,"__mClass");
};

Class SelectorManager_obj::__mClass;

void SelectorManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.SelectorManager"), hx::TCanCast< SelectorManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SelectorManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
