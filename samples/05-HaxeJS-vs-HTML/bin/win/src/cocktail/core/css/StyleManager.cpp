#include <hxcpp.h>

#ifndef INCLUDED_cocktail_core_css_CSSPropertyValue
#include <cocktail/core/css/CSSPropertyValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSRule
#include <cocktail/core/css/CSSRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleDeclaration
#include <cocktail/core/css/CSSStyleDeclaration.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleRule
#include <cocktail/core/css/CSSStyleRule.h>
#endif
#ifndef INCLUDED_cocktail_core_css_CSSStyleSheet
#include <cocktail/core/css/CSSStyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_MatchedPseudoClassesVO
#include <cocktail/core/css/MatchedPseudoClassesVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyOriginValue
#include <cocktail/core/css/PropertyOriginValue.h>
#endif
#ifndef INCLUDED_cocktail_core_css_PropertyVO
#include <cocktail/core/css/PropertyVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorManager
#include <cocktail/core/css/SelectorManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_SelectorVO
#include <cocktail/core/css/SelectorVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleDeclarationVO
#include <cocktail/core/css/StyleDeclarationVO.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleManager
#include <cocktail/core/css/StyleManager.h>
#endif
#ifndef INCLUDED_cocktail_core_css_StyleSheet
#include <cocktail/core/css/StyleSheet.h>
#endif
#ifndef INCLUDED_cocktail_core_css_TypedPropertyVO
#include <cocktail/core/css/TypedPropertyVO.h>
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
#ifndef INCLUDED_cocktail_core_utils_IPoolable
#include <cocktail/core/utils/IPoolable.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_ObjectPool
#include <cocktail/core/utils/ObjectPool.h>
#endif
#ifndef INCLUDED_cocktail_core_utils_Utils
#include <cocktail/core/utils/Utils.h>
#endif
namespace cocktail{
namespace core{
namespace css{

Void StyleManager_obj::__construct()
{
HX_STACK_PUSH("StyleManager::new","cocktail/core/css/StyleManager.hx",83);
{
	HX_STACK_LINE(84)
	this->_styleSheets = Array_obj< ::cocktail::core::css::CSSStyleSheet >::__new();
	HX_STACK_LINE(86)
	this->_matchingStyleDeclaration = Array_obj< ::cocktail::core::css::StyleDeclarationVO >::__new();
	HX_STACK_LINE(87)
	this->_mostSpecificMatchingProperties = Array_obj< ::cocktail::core::css::PropertyVO >::__new();
	HX_STACK_LINE(88)
	this->_matchingProperties = Array_obj< ::cocktail::core::css::PropertyVO >::__new();
	HX_STACK_LINE(89)
	this->_matchedProperties = Array_obj< int >::__new();
	HX_STACK_LINE(90)
	this->_userAgentDeclarations = Array_obj< ::cocktail::core::css::PropertyVO >::__new();
	HX_STACK_LINE(91)
	this->_authorNormalDeclarations = Array_obj< ::cocktail::core::css::PropertyVO >::__new();
	HX_STACK_LINE(92)
	this->_authorImportantDeclarations = Array_obj< ::cocktail::core::css::PropertyVO >::__new();
	HX_STACK_LINE(94)
	this->_selectorManager = ::cocktail::core::css::SelectorManager_obj::__new();
}
;
	return null();
}

StyleManager_obj::~StyleManager_obj() { }

Dynamic StyleManager_obj::__CreateEmpty() { return  new StyleManager_obj; }
hx::ObjectPtr< StyleManager_obj > StyleManager_obj::__new()
{  hx::ObjectPtr< StyleManager_obj > result = new StyleManager_obj();
	result->__construct();
	return result;}

Dynamic StyleManager_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StyleManager_obj > result = new StyleManager_obj();
	result->__construct();
	return result;}

Array< ::cocktail::core::css::PropertyVO > StyleManager_obj::getSortedMatchingPropertiesBySpecificity( Array< ::cocktail::core::css::PropertyVO > matchingProperties){
	HX_STACK_PUSH("StyleManager::getSortedMatchingPropertiesBySpecificity","cocktail/core/css/StyleManager.hx",507);
	HX_STACK_THIS(this);
	HX_STACK_ARG(matchingProperties,"matchingProperties");
	HX_STACK_LINE(508)
	this->_mostSpecificMatchingProperties = ::cocktail::core::utils::Utils_obj::clear(this->_mostSpecificMatchingProperties);
	HX_STACK_LINE(512)
	int currentHigherSpecificity = (int)0;		HX_STACK_VAR(currentHigherSpecificity,"currentHigherSpecificity");
	HX_STACK_LINE(515)
	int length = matchingProperties->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(516)
	{
		HX_STACK_LINE(516)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(516)
		while(((_g < length))){
			HX_STACK_LINE(516)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(518)
			::cocktail::core::css::PropertyVO property = matchingProperties->__get(i);		HX_STACK_VAR(property,"property");
			HX_STACK_LINE(521)
			int propertySpecificity = this->_selectorManager->getSelectorSpecifity(property->selector);		HX_STACK_VAR(propertySpecificity,"propertySpecificity");
			HX_STACK_LINE(525)
			if (((propertySpecificity > currentHigherSpecificity))){
				HX_STACK_LINE(527)
				currentHigherSpecificity = propertySpecificity;
				HX_STACK_LINE(530)
				int length1 = this->_mostSpecificMatchingProperties->length;		HX_STACK_VAR(length1,"length1");
				HX_STACK_LINE(531)
				{
					HX_STACK_LINE(531)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(531)
					while(((_g1 < length1))){
						HX_STACK_LINE(531)
						int j = (_g1)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(533)
						::cocktail::core::css::PropertyVO_obj::getPool()->release(this->_mostSpecificMatchingProperties->__get(j));
					}
				}
				HX_STACK_LINE(538)
				this->_mostSpecificMatchingProperties = ::cocktail::core::utils::Utils_obj::clear(this->_mostSpecificMatchingProperties);
			}
			HX_STACK_LINE(542)
			if (((propertySpecificity == currentHigherSpecificity))){
				HX_STACK_LINE(543)
				this->_mostSpecificMatchingProperties->push(property);
			}
		}
	}
	HX_STACK_LINE(548)
	return this->_mostSpecificMatchingProperties;
}


HX_DEFINE_DYNAMIC_FUNC1(StyleManager_obj,getSortedMatchingPropertiesBySpecificity,return )

Array< ::cocktail::core::css::PropertyVO > StyleManager_obj::getSortedMatchingPropertiesByPriority( Array< ::cocktail::core::css::PropertyVO > matchingProperties){
	HX_STACK_PUSH("StyleManager::getSortedMatchingPropertiesByPriority","cocktail/core/css/StyleManager.hx",437);
	HX_STACK_THIS(this);
	HX_STACK_ARG(matchingProperties,"matchingProperties");
	HX_STACK_LINE(438)
	this->_userAgentDeclarations = ::cocktail::core::utils::Utils_obj::clear(this->_userAgentDeclarations);
	HX_STACK_LINE(439)
	this->_authorNormalDeclarations = ::cocktail::core::utils::Utils_obj::clear(this->_authorNormalDeclarations);
	HX_STACK_LINE(440)
	this->_authorImportantDeclarations = ::cocktail::core::utils::Utils_obj::clear(this->_authorImportantDeclarations);
	HX_STACK_LINE(443)
	int length = matchingProperties->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(444)
	{
		HX_STACK_LINE(444)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(444)
		while(((_g < length))){
			HX_STACK_LINE(444)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(446)
			::cocktail::core::css::PropertyVO matchingProperty = matchingProperties->__get(i);		HX_STACK_VAR(matchingProperty,"matchingProperty");
			HX_STACK_LINE(447)
			{
				::cocktail::core::css::PropertyOriginValue _switch_1 = (matchingProperty->origin);
				switch((_switch_1)->GetIndex()){
					case 1: {
						HX_STACK_LINE(449)
						this->_userAgentDeclarations->push(matchingProperty);
					}
					;break;
					case 0: {
						HX_STACK_LINE(452)
						if (((matchingProperty->important == true))){
							HX_STACK_LINE(454)
							this->_authorImportantDeclarations->push(matchingProperty);
						}
						else{
							HX_STACK_LINE(458)
							this->_authorNormalDeclarations->push(matchingProperty);
						}
					}
					;break;
				}
			}
		}
	}
	HX_STACK_LINE(466)
	if (((this->_authorImportantDeclarations->length > (int)0))){
		HX_STACK_LINE(469)
		int length1 = this->_authorNormalDeclarations->length;		HX_STACK_VAR(length1,"length1");
		HX_STACK_LINE(470)
		{
			HX_STACK_LINE(470)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(470)
			while(((_g < length1))){
				HX_STACK_LINE(470)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(472)
				::cocktail::core::css::PropertyVO_obj::getPool()->release(this->_authorNormalDeclarations->__get(i));
			}
		}
		HX_STACK_LINE(474)
		length1 = this->_userAgentDeclarations->length;
		HX_STACK_LINE(475)
		{
			HX_STACK_LINE(475)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(475)
			while(((_g < length1))){
				HX_STACK_LINE(475)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(477)
				::cocktail::core::css::PropertyVO_obj::getPool()->release(this->_userAgentDeclarations->__get(i));
			}
		}
		HX_STACK_LINE(480)
		return this->_authorImportantDeclarations;
	}
	HX_STACK_LINE(485)
	if (((this->_authorNormalDeclarations->length > (int)0))){
		HX_STACK_LINE(487)
		length = this->_userAgentDeclarations->length;
		HX_STACK_LINE(488)
		{
			HX_STACK_LINE(488)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(488)
			while(((_g < length))){
				HX_STACK_LINE(488)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(490)
				::cocktail::core::css::PropertyVO_obj::getPool()->release(this->_userAgentDeclarations->__get(i));
			}
		}
		HX_STACK_LINE(493)
		return this->_authorNormalDeclarations;
	}
	HX_STACK_LINE(497)
	return this->_userAgentDeclarations;
}


HX_DEFINE_DYNAMIC_FUNC1(StyleManager_obj,getSortedMatchingPropertiesByPriority,return )

Void StyleManager_obj::applyMatchingProperty( int propertyIndex,Array< ::cocktail::core::css::StyleDeclarationVO > matchingStyleDeclarations,::cocktail::core::css::CSSStyleDeclaration nodeStyleDeclaration){
{
		HX_STACK_PUSH("StyleManager::applyMatchingProperty","cocktail/core/css/StyleManager.hx",351);
		HX_STACK_THIS(this);
		HX_STACK_ARG(propertyIndex,"propertyIndex");
		HX_STACK_ARG(matchingStyleDeclarations,"matchingStyleDeclarations");
		HX_STACK_ARG(nodeStyleDeclaration,"nodeStyleDeclaration");
		HX_STACK_LINE(354)
		this->_matchingProperties = ::cocktail::core::utils::Utils_obj::clear(this->_matchingProperties);
		HX_STACK_LINE(357)
		int matchingStyleDeclarationsLength = matchingStyleDeclarations->length;		HX_STACK_VAR(matchingStyleDeclarationsLength,"matchingStyleDeclarationsLength");
		HX_STACK_LINE(358)
		{
			HX_STACK_LINE(358)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(358)
			while(((_g < matchingStyleDeclarationsLength))){
				HX_STACK_LINE(358)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(360)
				::cocktail::core::css::CSSStyleDeclaration styleDeclaration = matchingStyleDeclarations->__get(i)->style;		HX_STACK_VAR(styleDeclaration,"styleDeclaration");
				HX_STACK_LINE(361)
				::cocktail::core::css::SelectorVO selector = matchingStyleDeclarations->__get(i)->selector;		HX_STACK_VAR(selector,"selector");
				struct _Function_3_1{
					inline static ::cocktail::core::css::TypedPropertyVO Block( ::cocktail::core::css::CSSStyleDeclaration &styleDeclaration,int &propertyIndex){
						HX_STACK_PUSH("*::closure","cocktail/core/css/StyleManager.hx",365);
						{
							HX_STACK_LINE(365)
							if (((styleDeclaration->_indexedProperties == null()))){
								HX_STACK_LINE(365)
								styleDeclaration->resetIndexedProperties();
								HX_STACK_LINE(365)
								styleDeclaration->resetPropertiesPositions();
							}
							HX_STACK_LINE(365)
							return styleDeclaration->_indexedProperties->__get(propertyIndex);
						}
						return null();
					}
				};
				HX_STACK_LINE(365)
				::cocktail::core::css::TypedPropertyVO typedProperty = _Function_3_1::Block(styleDeclaration,propertyIndex);		HX_STACK_VAR(typedProperty,"typedProperty");
				HX_STACK_LINE(366)
				if (((typedProperty != null()))){
					HX_STACK_LINE(368)
					::cocktail::core::css::PropertyVO matchingProperty = ::cocktail::core::css::PropertyVO_obj::getPool()->get();		HX_STACK_VAR(matchingProperty,"matchingProperty");
					HX_STACK_LINE(369)
					matchingProperty->selector = selector;
					HX_STACK_LINE(370)
					matchingProperty->typedValue = typedProperty->typedValue;
					HX_STACK_LINE(371)
					matchingProperty->origin = styleDeclaration->parentRule->parentStyleSheet->origin;
					HX_STACK_LINE(372)
					matchingProperty->important = typedProperty->important;
					HX_STACK_LINE(373)
					this->_matchingProperties->push(matchingProperty);
				}
			}
		}
		HX_STACK_LINE(378)
		if (((this->_matchingProperties->length == (int)1))){
			HX_STACK_LINE(380)
			::cocktail::core::css::PropertyVO matchingProperty = this->_matchingProperties->__get((int)0);		HX_STACK_VAR(matchingProperty,"matchingProperty");
			HX_STACK_LINE(381)
			nodeStyleDeclaration->setTypedProperty(propertyIndex,matchingProperty->typedValue,matchingProperty->important);
			HX_STACK_LINE(382)
			::cocktail::core::css::PropertyVO_obj::getPool()->release(matchingProperty);
			HX_STACK_LINE(383)
			return null();
		}
		HX_STACK_LINE(388)
		Array< ::cocktail::core::css::PropertyVO > tempMatchingProperties = this->getSortedMatchingPropertiesByPriority(this->_matchingProperties);		HX_STACK_VAR(tempMatchingProperties,"tempMatchingProperties");
		HX_STACK_LINE(392)
		if (((tempMatchingProperties->length == (int)1))){
			HX_STACK_LINE(394)
			::cocktail::core::css::PropertyVO matchingProperty = tempMatchingProperties->__get((int)0);		HX_STACK_VAR(matchingProperty,"matchingProperty");
			HX_STACK_LINE(395)
			nodeStyleDeclaration->setTypedProperty(propertyIndex,matchingProperty->typedValue,matchingProperty->important);
			HX_STACK_LINE(396)
			::cocktail::core::css::PropertyVO_obj::getPool()->release(matchingProperty);
			HX_STACK_LINE(397)
			return null();
		}
		HX_STACK_LINE(401)
		tempMatchingProperties = this->getSortedMatchingPropertiesBySpecificity(tempMatchingProperties);
		HX_STACK_LINE(403)
		if (((tempMatchingProperties->length == (int)1))){
			HX_STACK_LINE(405)
			::cocktail::core::css::PropertyVO matchingProperty = tempMatchingProperties->__get((int)0);		HX_STACK_VAR(matchingProperty,"matchingProperty");
			HX_STACK_LINE(406)
			nodeStyleDeclaration->setTypedProperty(propertyIndex,matchingProperty->typedValue,matchingProperty->important);
			HX_STACK_LINE(407)
			::cocktail::core::css::PropertyVO_obj::getPool()->release(matchingProperty);
			HX_STACK_LINE(408)
			return null();
		}
		HX_STACK_LINE(413)
		::cocktail::core::css::PropertyVO matchingProperty = tempMatchingProperties->__get((tempMatchingProperties->length - (int)1));		HX_STACK_VAR(matchingProperty,"matchingProperty");
		HX_STACK_LINE(414)
		nodeStyleDeclaration->setTypedProperty(propertyIndex,matchingProperty->typedValue,matchingProperty->important);
		HX_STACK_LINE(417)
		int length = tempMatchingProperties->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(418)
		{
			HX_STACK_LINE(418)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(418)
			while(((_g < length))){
				HX_STACK_LINE(418)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(420)
				::cocktail::core::css::PropertyVO_obj::getPool()->release(tempMatchingProperties->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(StyleManager_obj,applyMatchingProperty,(void))

Array< ::cocktail::core::css::StyleDeclarationVO > StyleManager_obj::getMatchingStyleDeclarations( ::cocktail::core::html::HTMLElement node,Array< ::cocktail::core::css::CSSStyleSheet > styleSheets,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("StyleManager::getMatchingStyleDeclarations","cocktail/core/css/StyleManager.hx",207);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(styleSheets,"styleSheets");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(209)
	int length = this->_matchingStyleDeclaration->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(210)
	{
		HX_STACK_LINE(210)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(210)
		while(((_g < length))){
			HX_STACK_LINE(210)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(212)
			::cocktail::core::css::StyleDeclarationVO_obj::getPool()->release(this->_matchingStyleDeclaration->__get(i));
		}
	}
	HX_STACK_LINE(214)
	this->_matchingStyleDeclaration = ::cocktail::core::utils::Utils_obj::clear(this->_matchingStyleDeclaration);
	HX_STACK_LINE(217)
	int styleSheetsLength = styleSheets->length;		HX_STACK_VAR(styleSheetsLength,"styleSheetsLength");
	HX_STACK_LINE(218)
	{
		HX_STACK_LINE(218)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(218)
		while(((_g < styleSheetsLength))){
			HX_STACK_LINE(218)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(220)
			::cocktail::core::css::CSSStyleSheet styleSheet = styleSheets->__get(i);		HX_STACK_VAR(styleSheet,"styleSheet");
			HX_STACK_LINE(223)
			Array< ::cocktail::core::css::CSSRule > cssRules = styleSheet->cssRules;		HX_STACK_VAR(cssRules,"cssRules");
			HX_STACK_LINE(224)
			int cssRulesLength = cssRules->length;		HX_STACK_VAR(cssRulesLength,"cssRulesLength");
			HX_STACK_LINE(225)
			{
				HX_STACK_LINE(225)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(225)
				while(((_g1 < cssRulesLength))){
					HX_STACK_LINE(225)
					int j = (_g1)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(227)
					::cocktail::core::css::CSSRule cssRule = cssRules->__get(j);		HX_STACK_VAR(cssRule,"cssRule");
					HX_STACK_LINE(228)
					switch( (int)(cssRule->type)){
						case (int)1: {
							HX_STACK_LINE(234)
							::cocktail::core::css::CSSStyleRule styleRule = cssRule;		HX_STACK_VAR(styleRule,"styleRule");
							HX_STACK_LINE(235)
							Array< ::cocktail::core::css::SelectorVO > selectors = styleRule->selectors;		HX_STACK_VAR(selectors,"selectors");
							HX_STACK_LINE(237)
							int selectorsLength = selectors->length;		HX_STACK_VAR(selectorsLength,"selectorsLength");
							HX_STACK_LINE(238)
							{
								HX_STACK_LINE(238)
								int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(238)
								while(((_g2 < selectorsLength))){
									HX_STACK_LINE(238)
									int k = (_g2)++;		HX_STACK_VAR(k,"k");
									HX_STACK_LINE(240)
									::cocktail::core::css::SelectorVO selector = selectors->__get(k);		HX_STACK_VAR(selector,"selector");
									HX_STACK_LINE(241)
									bool match = false;		HX_STACK_VAR(match,"match");
									HX_STACK_LINE(249)
									if (((selector->beginsWithClass == true))){
										HX_STACK_LINE(250)
										if (((matchedPseudoClasses->hasClasses == true))){
											HX_STACK_LINE(253)
											int classListLength = matchedPseudoClasses->nodeClassList->length;		HX_STACK_VAR(classListLength,"classListLength");
											HX_STACK_LINE(254)
											{
												HX_STACK_LINE(254)
												int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
												HX_STACK_LINE(254)
												while(((_g3 < classListLength))){
													HX_STACK_LINE(254)
													int l = (_g3)++;		HX_STACK_VAR(l,"l");
													HX_STACK_LINE(256)
													if (((matchedPseudoClasses->nodeClassList->__get(l) == selector->firstClass))){
														HX_STACK_LINE(257)
														if (((selector->isSimpleClassSelector == true))){
															HX_STACK_LINE(262)
															match = true;
															HX_STACK_LINE(263)
															break;
														}
														else{
															HX_STACK_LINE(268)
															match = (this->_selectorManager->matchSelector(node,selectors->__get(k),matchedPseudoClasses) == true);
															HX_STACK_LINE(269)
															break;
														}
													}
												}
											}
										}
									}
									else{
										HX_STACK_LINE(277)
										if (((selector->beginsWithId == true))){
											HX_STACK_LINE(278)
											if (((matchedPseudoClasses->hasId == true))){
												HX_STACK_LINE(280)
												if (((matchedPseudoClasses->nodeId == selector->firstId))){
													HX_STACK_LINE(282)
													if (((selector->isSimpleIdSelector == true))){
														HX_STACK_LINE(285)
														match = true;
													}
													else{
														HX_STACK_LINE(290)
														match = (this->_selectorManager->matchSelector(node,selectors->__get(k),matchedPseudoClasses) == true);
													}
												}
											}
										}
										else{
											HX_STACK_LINE(298)
											if (((selector->beginsWithType == true))){
												HX_STACK_LINE(299)
												if (((matchedPseudoClasses->nodeType == selector->firstType))){
													HX_STACK_LINE(301)
													if (((selector->isSimpleTypeSelector == true))){
														HX_STACK_LINE(304)
														match = true;
													}
													else{
														HX_STACK_LINE(309)
														match = (this->_selectorManager->matchSelector(node,selectors->__get(k),matchedPseudoClasses) == true);
													}
												}
											}
											else{
												HX_STACK_LINE(316)
												match = (this->_selectorManager->matchSelector(node,selectors->__get(k),matchedPseudoClasses) == true);
											}
										}
									}
									HX_STACK_LINE(320)
									if (((match == true))){
										HX_STACK_LINE(324)
										::cocktail::core::css::StyleDeclarationVO matchingStyleDeclaration = ::cocktail::core::css::StyleDeclarationVO_obj::getPool()->get();		HX_STACK_VAR(matchingStyleDeclaration,"matchingStyleDeclaration");
										HX_STACK_LINE(325)
										matchingStyleDeclaration->style = styleRule->style;
										HX_STACK_LINE(326)
										matchingStyleDeclaration->selector = selectors->__get(k);
										HX_STACK_LINE(327)
										this->_matchingStyleDeclaration->push(matchingStyleDeclaration);
										HX_STACK_LINE(332)
										break;
									}
								}
							}
						}
						;break;
						default: {
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(341)
	return this->_matchingStyleDeclaration;
}


HX_DEFINE_DYNAMIC_FUNC3(StyleManager_obj,getMatchingStyleDeclarations,return )

bool StyleManager_obj::alreadyMatched( int propertyIndex,Array< int > matchedProperties){
	HX_STACK_PUSH("StyleManager::alreadyMatched","cocktail/core/css/StyleManager.hx",188);
	HX_STACK_THIS(this);
	HX_STACK_ARG(propertyIndex,"propertyIndex");
	HX_STACK_ARG(matchedProperties,"matchedProperties");
	HX_STACK_LINE(189)
	int length = matchedProperties->length;		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(190)
	{
		HX_STACK_LINE(190)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(190)
		while(((_g < length))){
			HX_STACK_LINE(190)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(192)
			if (((matchedProperties->__get(i) == propertyIndex))){
				HX_STACK_LINE(193)
				return true;
			}
		}
	}
	HX_STACK_LINE(198)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(StyleManager_obj,alreadyMatched,return )

Void StyleManager_obj::applyStyleSheets( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::CSSStyleDeclaration nodeStyleDeclaration,Array< ::cocktail::core::css::CSSStyleSheet > styleSheets,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
{
		HX_STACK_PUSH("StyleManager::applyStyleSheets","cocktail/core/css/StyleManager.hx",156);
		HX_STACK_THIS(this);
		HX_STACK_ARG(node,"node");
		HX_STACK_ARG(nodeStyleDeclaration,"nodeStyleDeclaration");
		HX_STACK_ARG(styleSheets,"styleSheets");
		HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
		HX_STACK_LINE(158)
		Array< ::cocktail::core::css::StyleDeclarationVO > matchingStyleDeclarations = this->getMatchingStyleDeclarations(node,styleSheets,matchedPseudoClasses);		HX_STACK_VAR(matchingStyleDeclarations,"matchingStyleDeclarations");
		HX_STACK_LINE(162)
		this->_matchedProperties = ::cocktail::core::utils::Utils_obj::clear(this->_matchedProperties);
		HX_STACK_LINE(165)
		int length = matchingStyleDeclarations->length;		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(166)
		{
			HX_STACK_LINE(166)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(166)
			while(((_g < length))){
				HX_STACK_LINE(166)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(168)
				::cocktail::core::css::CSSStyleDeclaration cssStyleDeclaration = matchingStyleDeclarations->__get(i)->style;		HX_STACK_VAR(cssStyleDeclaration,"cssStyleDeclaration");
				HX_STACK_LINE(169)
				int styleLength = cssStyleDeclaration->length;		HX_STACK_VAR(styleLength,"styleLength");
				HX_STACK_LINE(170)
				{
					HX_STACK_LINE(170)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(170)
					while(((_g1 < styleLength))){
						HX_STACK_LINE(170)
						int j = (_g1)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(172)
						int propertyIndex = cssStyleDeclaration->item(j);		HX_STACK_VAR(propertyIndex,"propertyIndex");
						HX_STACK_LINE(174)
						if (((this->alreadyMatched(propertyIndex,this->_matchedProperties) == false))){
							HX_STACK_LINE(176)
							this->applyMatchingProperty(propertyIndex,matchingStyleDeclarations,nodeStyleDeclaration);
							HX_STACK_LINE(177)
							this->_matchedProperties->push(propertyIndex);
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(StyleManager_obj,applyStyleSheets,(void))

::cocktail::core::css::CSSStyleDeclaration StyleManager_obj::getStyleDeclaration( ::cocktail::core::html::HTMLElement node,::cocktail::core::css::MatchedPseudoClassesVO matchedPseudoClasses){
	HX_STACK_PUSH("StyleManager::getStyleDeclaration","cocktail/core/css/StyleManager.hx",128);
	HX_STACK_THIS(this);
	HX_STACK_ARG(node,"node");
	HX_STACK_ARG(matchedPseudoClasses,"matchedPseudoClasses");
	HX_STACK_LINE(129)
	::cocktail::core::css::CSSStyleDeclaration styleDeclaration = null();		HX_STACK_VAR(styleDeclaration,"styleDeclaration");
	HX_STACK_LINE(132)
	if (((node->styleManagerCSSDeclaration != null()))){
		HX_STACK_LINE(134)
		styleDeclaration = node->styleManagerCSSDeclaration;
		HX_STACK_LINE(135)
		styleDeclaration->reset();
	}
	else{
		HX_STACK_LINE(138)
		styleDeclaration = ::cocktail::core::css::CSSStyleDeclaration_obj::__new(null(),null());
	}
	HX_STACK_LINE(142)
	this->applyStyleSheets(node,styleDeclaration,this->_styleSheets,matchedPseudoClasses);
	HX_STACK_LINE(144)
	return styleDeclaration;
}


HX_DEFINE_DYNAMIC_FUNC2(StyleManager_obj,getStyleDeclaration,return )

Void StyleManager_obj::removeStyleSheet( ::cocktail::core::css::CSSStyleSheet styleSheet){
{
		HX_STACK_PUSH("StyleManager::removeStyleSheet","cocktail/core/css/StyleManager.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleSheet,"styleSheet");
		HX_STACK_LINE(114)
		this->_styleSheets->remove(styleSheet);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StyleManager_obj,removeStyleSheet,(void))

Void StyleManager_obj::addStyleSheet( ::cocktail::core::css::CSSStyleSheet styleSheet){
{
		HX_STACK_PUSH("StyleManager::addStyleSheet","cocktail/core/css/StyleManager.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_ARG(styleSheet,"styleSheet");
		HX_STACK_LINE(106)
		this->_styleSheets->push(styleSheet);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(StyleManager_obj,addStyleSheet,(void))


StyleManager_obj::StyleManager_obj()
{
}

void StyleManager_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StyleManager);
	HX_MARK_MEMBER_NAME(_authorImportantDeclarations,"_authorImportantDeclarations");
	HX_MARK_MEMBER_NAME(_authorNormalDeclarations,"_authorNormalDeclarations");
	HX_MARK_MEMBER_NAME(_userAgentDeclarations,"_userAgentDeclarations");
	HX_MARK_MEMBER_NAME(_mostSpecificMatchingProperties,"_mostSpecificMatchingProperties");
	HX_MARK_MEMBER_NAME(_matchingProperties,"_matchingProperties");
	HX_MARK_MEMBER_NAME(_matchingStyleDeclaration,"_matchingStyleDeclaration");
	HX_MARK_MEMBER_NAME(_matchedProperties,"_matchedProperties");
	HX_MARK_MEMBER_NAME(_selectorManager,"_selectorManager");
	HX_MARK_MEMBER_NAME(_styleSheets,"_styleSheets");
	HX_MARK_END_CLASS();
}

void StyleManager_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_authorImportantDeclarations,"_authorImportantDeclarations");
	HX_VISIT_MEMBER_NAME(_authorNormalDeclarations,"_authorNormalDeclarations");
	HX_VISIT_MEMBER_NAME(_userAgentDeclarations,"_userAgentDeclarations");
	HX_VISIT_MEMBER_NAME(_mostSpecificMatchingProperties,"_mostSpecificMatchingProperties");
	HX_VISIT_MEMBER_NAME(_matchingProperties,"_matchingProperties");
	HX_VISIT_MEMBER_NAME(_matchingStyleDeclaration,"_matchingStyleDeclaration");
	HX_VISIT_MEMBER_NAME(_matchedProperties,"_matchedProperties");
	HX_VISIT_MEMBER_NAME(_selectorManager,"_selectorManager");
	HX_VISIT_MEMBER_NAME(_styleSheets,"_styleSheets");
}

Dynamic StyleManager_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_styleSheets") ) { return _styleSheets; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"addStyleSheet") ) { return addStyleSheet_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"alreadyMatched") ) { return alreadyMatched_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"applyStyleSheets") ) { return applyStyleSheets_dyn(); }
		if (HX_FIELD_EQ(inName,"removeStyleSheet") ) { return removeStyleSheet_dyn(); }
		if (HX_FIELD_EQ(inName,"_selectorManager") ) { return _selectorManager; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_matchedProperties") ) { return _matchedProperties; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"getStyleDeclaration") ) { return getStyleDeclaration_dyn(); }
		if (HX_FIELD_EQ(inName,"_matchingProperties") ) { return _matchingProperties; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"applyMatchingProperty") ) { return applyMatchingProperty_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_userAgentDeclarations") ) { return _userAgentDeclarations; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_authorNormalDeclarations") ) { return _authorNormalDeclarations; }
		if (HX_FIELD_EQ(inName,"_matchingStyleDeclaration") ) { return _matchingStyleDeclaration; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"getMatchingStyleDeclarations") ) { return getMatchingStyleDeclarations_dyn(); }
		if (HX_FIELD_EQ(inName,"_authorImportantDeclarations") ) { return _authorImportantDeclarations; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_mostSpecificMatchingProperties") ) { return _mostSpecificMatchingProperties; }
		break;
	case 37:
		if (HX_FIELD_EQ(inName,"getSortedMatchingPropertiesByPriority") ) { return getSortedMatchingPropertiesByPriority_dyn(); }
		break;
	case 40:
		if (HX_FIELD_EQ(inName,"getSortedMatchingPropertiesBySpecificity") ) { return getSortedMatchingPropertiesBySpecificity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StyleManager_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"_styleSheets") ) { _styleSheets=inValue.Cast< Array< ::cocktail::core::css::CSSStyleSheet > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_selectorManager") ) { _selectorManager=inValue.Cast< ::cocktail::core::css::SelectorManager >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_matchedProperties") ) { _matchedProperties=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"_matchingProperties") ) { _matchingProperties=inValue.Cast< Array< ::cocktail::core::css::PropertyVO > >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"_userAgentDeclarations") ) { _userAgentDeclarations=inValue.Cast< Array< ::cocktail::core::css::PropertyVO > >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"_authorNormalDeclarations") ) { _authorNormalDeclarations=inValue.Cast< Array< ::cocktail::core::css::PropertyVO > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_matchingStyleDeclaration") ) { _matchingStyleDeclaration=inValue.Cast< Array< ::cocktail::core::css::StyleDeclarationVO > >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"_authorImportantDeclarations") ) { _authorImportantDeclarations=inValue.Cast< Array< ::cocktail::core::css::PropertyVO > >(); return inValue; }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"_mostSpecificMatchingProperties") ) { _mostSpecificMatchingProperties=inValue.Cast< Array< ::cocktail::core::css::PropertyVO > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void StyleManager_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_authorImportantDeclarations"));
	outFields->push(HX_CSTRING("_authorNormalDeclarations"));
	outFields->push(HX_CSTRING("_userAgentDeclarations"));
	outFields->push(HX_CSTRING("_mostSpecificMatchingProperties"));
	outFields->push(HX_CSTRING("_matchingProperties"));
	outFields->push(HX_CSTRING("_matchingStyleDeclaration"));
	outFields->push(HX_CSTRING("_matchedProperties"));
	outFields->push(HX_CSTRING("_selectorManager"));
	outFields->push(HX_CSTRING("_styleSheets"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getSortedMatchingPropertiesBySpecificity"),
	HX_CSTRING("getSortedMatchingPropertiesByPriority"),
	HX_CSTRING("applyMatchingProperty"),
	HX_CSTRING("getMatchingStyleDeclarations"),
	HX_CSTRING("alreadyMatched"),
	HX_CSTRING("applyStyleSheets"),
	HX_CSTRING("getStyleDeclaration"),
	HX_CSTRING("removeStyleSheet"),
	HX_CSTRING("addStyleSheet"),
	HX_CSTRING("_authorImportantDeclarations"),
	HX_CSTRING("_authorNormalDeclarations"),
	HX_CSTRING("_userAgentDeclarations"),
	HX_CSTRING("_mostSpecificMatchingProperties"),
	HX_CSTRING("_matchingProperties"),
	HX_CSTRING("_matchingStyleDeclaration"),
	HX_CSTRING("_matchedProperties"),
	HX_CSTRING("_selectorManager"),
	HX_CSTRING("_styleSheets"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StyleManager_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StyleManager_obj::__mClass,"__mClass");
};

Class StyleManager_obj::__mClass;

void StyleManager_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.css.StyleManager"), hx::TCanCast< StyleManager_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StyleManager_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace css
